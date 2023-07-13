#! /usr/bin/env python3

import argparse
import hashlib
import importlib
import pickle
from typing import Any, Dict, List, Optional, Set, Tuple, Union
from disassembler import disassembler_instance
import tqdm
import yaml
from colorama import Fore, Style
from intervaltree import Interval, IntervalTree

from segtypes.linker_entry import (
    LinkerWriter,
    get_segment_vram_end_symbol_name,
    to_cname,
)
from segtypes.segment import Segment
from util import log, options, palettes, symbols, relocs

VERSION = "0.14.0"

parser = argparse.ArgumentParser(
    description="Split a rom given a rom, a config, and output directory"
)
parser.add_argument("config", help="path to a compatible config .yaml file", nargs="+")
parser.add_argument("--modes", nargs="+", default="all")
parser.add_argument("--verbose", action="store_true", help="Enable debug logging")
parser.add_argument(
    "--use-cache", action="store_true", help="Only split changed segments in config"
)
parser.add_argument(
    "--skip-version-check",
    action="store_true",
    help="Skips the disassembler's version check",
)

linker_writer: LinkerWriter
config: Dict[str, Any]

segment_roms: IntervalTree = IntervalTree()
segment_rams: IntervalTree = IntervalTree()


def fmt_size(size):
    if size > 1000000:
        return str(size // 1000000) + " MB"
    elif size > 1000:
        return str(size // 1000) + " KB"
    else:
        return str(size) + " B"


def initialize_segments(config_segments: Union[dict, list]) -> List[Segment]:
    global segment_roms
    global segment_rams

    segment_roms = IntervalTree()
    segment_rams = IntervalTree()

    segments_by_name: Dict[str, Segment] = {}
    ret = []

    last_rom_end = 0

    for i, seg_yaml in enumerate(config_segments):
        # end marker
        if isinstance(seg_yaml, list) and len(seg_yaml) == 1:
            continue

        seg_type = Segment.parse_segment_type(seg_yaml)

        segment_class = Segment.get_class_for_type(seg_type)

        this_start = Segment.parse_segment_start(seg_yaml)

        if i == len(config_segments) - 1 and Segment.parse_segment_file_path(seg_yaml):
            next_start: Optional[int] = 0
        else:
            next_start = Segment.parse_segment_start(config_segments[i + 1])

        if segment_class.is_noload():
            # Pretend bss's rom address is after the last actual rom segment
            this_start = last_rom_end
            # and it has a rom size of zero
            next_start = last_rom_end

        segment: Segment = Segment.from_yaml(
            segment_class, seg_yaml, this_start, next_start
        )

        if segment.require_unique_name:
            if segment.name in segments_by_name:
                log.error(f"segment name '{segment.name}' is not unique")

            segments_by_name[segment.name] = segment

        ret.append(segment)
        if (
            isinstance(segment.rom_start, int)
            and isinstance(segment.rom_end, int)
            and segment.rom_start != segment.rom_end
        ):
            segment_roms.addi(segment.rom_start, segment.rom_end, segment)
        if (
            isinstance(segment.vram_start, int)
            and isinstance(segment.vram_end, int)
            and segment.vram_start != segment.vram_end
        ):
            segment_rams.addi(segment.vram_start, segment.vram_end, segment)

        if next_start is not None:
            last_rom_end = next_start

    for segment in ret:
        if segment.given_follows_vram:
            if segment.given_follows_vram not in segments_by_name:
                log.error(
                    f"segment '{segment.given_follows_vram}', the 'follows_vram' value for segment '{segment.name}', does not exist"
                )
            segment.vram_of_symbol = get_segment_vram_end_symbol_name(
                segments_by_name[segment.given_follows_vram]
            )

    return ret


def assign_symbols_to_segments():
    for symbol in symbols.all_symbols:
        if symbol.segment:
            continue

        if symbol.rom:
            cands: Set[Interval] = segment_roms[symbol.rom]
            if len(cands) > 1:
                log.error("multiple segments rom overlap symbol", symbol)
            elif len(cands) == 0:
                log.error("no segment rom overlaps symbol", symbol)
            else:
                cand: Interval = cands.pop()
                seg: Segment = cand.data
                seg.add_symbol(symbol)
        else:
            cands = segment_rams[symbol.vram_start]
            segs: List[Segment] = [cand.data for cand in cands]
            for seg in segs:
                if not seg.get_exclusive_ram_id():
                    seg.add_symbol(symbol)


def do_statistics(seg_sizes, rom_bytes, seg_split, seg_cached):
    unk_size = seg_sizes.get("unk", 0)
    rest_size = 0
    total_size = len(rom_bytes)

    for typ in seg_sizes:
        if typ != "unk":
            rest_size += seg_sizes[typ]

    known_ratio = rest_size / total_size
    unk_ratio = unk_size / total_size

    log.write(f"Split {fmt_size(rest_size)} ({known_ratio:.2%}) in defined segments")
    for typ in seg_sizes:
        if typ != "unk":
            tmp_size = seg_sizes[typ]
            tmp_ratio = tmp_size / total_size
            log.write(
                f"{typ:>20}: {fmt_size(tmp_size):>8} ({tmp_ratio:.2%}) {Fore.GREEN}{seg_split[typ]} split{Style.RESET_ALL}, {Style.DIM}{seg_cached[typ]} cached"
            )
    log.write(
        f"{'unknown':>20}: {fmt_size(unk_size):>8} ({unk_ratio:.2%}) from unknown bin files"
    )


def merge_configs(main_config, additional_config):
    # Merge rules are simple
    # For each key in the dictionary
    # - If list then append to list
    # - If a dictionary then repeat merge on sub dictionary entries
    # - Else assume string or number and replace entry

    for curkey in additional_config:
        if curkey not in main_config:
            main_config[curkey] = additional_config[curkey]
        elif type(main_config[curkey]) != type(additional_config[curkey]):
            log.error(f"Type for key {curkey} in configs does not match")
        else:
            # keys exist and match, see if a list to append
            if type(main_config[curkey]) == list:
                main_config[curkey] += additional_config[curkey]
            elif type(main_config[curkey]) == dict:
                # need to merge sub areas
                main_config[curkey] = merge_configs(
                    main_config[curkey], additional_config[curkey]
                )
            else:
                # not a list or dictionary, must be a number or string, overwrite
                main_config[curkey] = additional_config[curkey]

    return main_config


def brief_seg_name(seg: Segment, limit: int, ellipsis="…") -> str:
    s = seg.name.strip()
    if len(s) > limit:
        return s[:limit].strip() + ellipsis
    return s


def main(config_path, modes, verbose, use_cache=True, skip_version_check=False):
    global config

    # Load config
    config = {}
    for entry in config_path:
        with open(entry) as f:
            additional_config = yaml.load(f.read(), Loader=yaml.SafeLoader)
        config = merge_configs(config, additional_config)

    options.initialize(config, config_path, modes, verbose)

    disassembler_instance.create_disassembler_instance(options.opts.platform)
    disassembler_instance.get_instance().check_version(skip_version_check, VERSION)

    with options.opts.target_path.open("rb") as f2:
        rom_bytes = f2.read()

    if "sha1" in config:
        sha1 = hashlib.sha1(rom_bytes).hexdigest()
        e_sha1 = config["sha1"].lower()
        if e_sha1 != sha1:
            log.error(f"sha1 mismatch: expected {e_sha1}, was {sha1}")

    # Create main output dir
    options.opts.base_path.mkdir(parents=True, exist_ok=True)

    processed_segments: List[Segment] = []

    seg_sizes: Dict[str, int] = {}
    seg_split: Dict[str, int] = {}
    seg_cached: Dict[str, int] = {}

    # Load cache
    if use_cache:
        try:
            with options.opts.cache_path.open("rb") as f3:
                cache = pickle.load(f3)

            if verbose:
                log.write(f"Loaded cache ({len(cache.keys())} items)")
        except Exception:
            cache = {}
    else:
        cache = {}

    # invalidate entire cache if options change
    if use_cache and cache.get("__options__") != config.get("options"):
        if verbose:
            log.write("Options changed, invalidating cache")

        cache = {
            "__options__": config.get("options"),
        }

    disassembler_instance.get_instance().configure(options.opts)

    platform_module = importlib.import_module(f"platforms.{options.opts.platform}")
    platform_init = getattr(platform_module, "init")
    platform_init(rom_bytes)

    # Initialize segments
    all_segments = initialize_segments(config["segments"])

    # Load and process symbols
    symbols.initialize(all_segments)
    relocs.initialize()

    # Assign symbols to segments
    assign_symbols_to_segments()

    if options.opts.is_mode_active("code"):
        symbols.initialize_spim_context(all_segments)
        relocs.initialize_spim_context()

    # Resolve raster/palette siblings
    if options.opts.is_mode_active("img"):
        palettes.initialize(all_segments)

    # Scan
    scan_bar = tqdm.tqdm(all_segments, total=len(all_segments))
    for segment in scan_bar:
        assert isinstance(segment, Segment)
        scan_bar.set_description(f"Scanning {brief_seg_name(segment, 20)}")
        typ = segment.type
        if segment.type == "bin" and segment.is_name_default():
            typ = "unk"

        if typ not in seg_sizes:
            seg_sizes[typ] = 0
            seg_split[typ] = 0
            seg_cached[typ] = 0
        seg_sizes[typ] += 0 if segment.size is None else segment.size

        if segment.should_scan():
            # Check cache but don't write anything
            if use_cache:
                if segment.cache() == cache.get(segment.unique_id()):
                    continue

            segment.did_run = True
            segment.scan(rom_bytes)

            processed_segments.append(segment)

            seg_split[typ] += 1

    symbols.mark_c_funcs_as_defined()

    # Split
    split_bar = tqdm.tqdm(
        all_segments,
        total=len(all_segments),
    )
    for segment in split_bar:
        split_bar.set_description(f"Splitting {brief_seg_name(segment, 20)}")

        if use_cache:
            cached = segment.cache()

            if cached == cache.get(segment.unique_id()):
                # Cache hit
                if segment.type not in seg_cached:
                    seg_cached[segment.type] = 0
                seg_cached[segment.type] += 1
                continue
            else:
                # Cache miss; split
                cache[segment.unique_id()] = cached

        if segment.should_split():
            segment_bytes = rom_bytes
            if segment.file_path:
                with open(segment.file_path, "rb") as segment_input_file:
                    segment_bytes = segment_input_file.read()
            segment.split(segment_bytes)

    if (
        options.opts.is_mode_active("ld") and options.opts.platform != "gc"
    ):  # TODO move this to platform initialization when it gets implemented
        # Calculate list of segments for which we need to find the largest so we can safely place the symbol after it
        max_vram_end_syms: Dict[str, List[Segment]] = {}
        for sym in symbols.appears_after_overlays_syms:
            max_vram_end_syms[sym.name] = [
                seg
                for seg in all_segments
                if isinstance(seg.vram_start, int)
                and seg.vram_start == sym.appears_after_overlays_addr
            ]
        max_vram_end_sym_names: Set[str] = set(max_vram_end_syms.keys())

        max_vram_end_insertion_points: Dict[
            Segment, List[Tuple[str, List[Segment]]]
        ] = {}
        # Find the last segment whose vram_of_symbol is one of the max_vram_end_syms
        for segment in reversed(all_segments):
            vram_of_sym = segment.vram_of_symbol
            if vram_of_sym is not None and vram_of_sym in max_vram_end_sym_names:
                if segment not in max_vram_end_insertion_points:
                    max_vram_end_insertion_points[segment] = []
                max_vram_end_insertion_points[segment].append(
                    (vram_of_sym, max_vram_end_syms[vram_of_sym])
                )
                max_vram_end_sym_names.remove(vram_of_sym)

        global linker_writer
        linker_writer = LinkerWriter()
        linker_bar = tqdm.tqdm(
            all_segments,
            total=len(all_segments),
        )

        for segment in linker_bar:
            linker_bar.set_description(f"Linker script {brief_seg_name(segment, 20)}")
            linker_writer.add(segment, max_vram_end_insertion_points.get(segment, []))
        linker_writer.save_linker_script()
        linker_writer.save_symbol_header()

        # write elf_sections.txt - this only lists the generated sections in the elf, not subsections
        # that the elf combines into one section
        if options.opts.elf_section_list_path:
            section_list = ""
            for segment in all_segments:
                section_list += "." + to_cname(segment.name) + "\n"
            with open(options.opts.elf_section_list_path, "w", newline="\n") as f:
                f.write(section_list)

    # Write undefined_funcs_auto.txt
    if options.opts.create_undefined_funcs_auto:
        to_write = [
            s
            for s in symbols.all_symbols
            if s.referenced and not s.defined and not s.dead and s.type == "func"
        ]
        to_write.sort(key=lambda x: x.vram_start)

        with open(options.opts.undefined_funcs_auto_path, "w", newline="\n") as f:
            for symbol in to_write:
                f.write(f"{symbol.name} = 0x{symbol.vram_start:X};\n")

    # write undefined_syms_auto.txt
    if options.opts.create_undefined_syms_auto:
        to_write = [
            s
            for s in symbols.all_symbols
            if s.referenced
            and not s.defined
            and not s.dead
            and s.type not in {"func", "label", "jtbl_label"}
        ]
        to_write.sort(key=lambda x: x.vram_start)

        with open(options.opts.undefined_syms_auto_path, "w", newline="\n") as f:
            for symbol in to_write:
                f.write(f"{symbol.name} = 0x{symbol.vram_start:X};\n")

    # print warnings during split
    for segment in all_segments:
        if len(segment.warnings) > 0:
            log.write(
                f"{Style.DIM}0x{segment.rom_start:06X}{Style.RESET_ALL} {segment.type} {Style.BRIGHT}{segment.name}{Style.RESET_ALL}:"
            )

            for warn in segment.warnings:
                log.write("warning: " + warn, status="warn")

            log.write("")  # empty line

    # Statistics
    do_statistics(seg_sizes, rom_bytes, seg_split, seg_cached)

    # Save cache
    if cache != {} and use_cache:
        if verbose:
            log.write("Writing cache")
        with open(options.opts.cache_path, "wb") as f4:
            pickle.dump(cache, f4)

    if options.opts.dump_symbols and options.opts.is_mode_active("code"):
        from pathlib import Path

        splat_hidden_folder = Path(".splat/")
        splat_hidden_folder.mkdir(exist_ok=True)

        with open(splat_hidden_folder / "splat_symbols.csv", "w") as f:
            f.write(
                "vram_start,given_name,name,type,given_size,size,rom,defined,user_declared,referenced,dead,extract\n"
            )
            for s in sorted(symbols.all_symbols, key=lambda x: x.vram_start):
                f.write(f"{s.vram_start:X},{s.given_name},{s.name},{s.type},")
                if s.given_size is not None:
                    f.write(f"0x{s.given_size:X},")
                else:
                    f.write("None,")
                f.write(f"{s.size},")
                if s.rom is not None:
                    f.write(f"0x{s.rom:X},")
                else:
                    f.write("None,")
                f.write(
                    f"{s.defined},{s.user_declared},{s.referenced},{s.dead},{s.extract}\n"
                )

        symbols.spim_context.saveContextToFile(splat_hidden_folder / "spim_context.csv")


if __name__ == "__main__":
    args = parser.parse_args()
    main(args.config, args.modes, args.verbose, args.use_cache, args.skip_version_check)
