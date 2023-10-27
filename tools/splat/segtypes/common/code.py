import typing
from collections import OrderedDict
from typing import Dict, List, Optional, Tuple, Set

from util import log, options
from util.range import Range
from util.symbols import Symbol

from segtypes.common.group import CommonSegGroup
from segtypes.segment import Segment, parse_segment_align


def dotless_type(type: str) -> str:
    return type[1:] if type[0] == "." else type


# code group
class CommonSegCode(CommonSegGroup):
    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
    ):
        self.bss_size: int = yaml.get("bss_size", 0) if isinstance(yaml, dict) else 0

        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

        self.reported_file_split = False
        self.jtbl_glabels_to_add: Set[int] = set()
        self.jumptables: Dict[int, Tuple[int, int]] = {}
        self.rodata_syms: Dict[int, List[Symbol]] = {}

        self.align = parse_segment_align(yaml)
        if self.align is None:
            self.align = 0x10

    @property
    def needs_symbols(self) -> bool:
        return True

    @property
    def vram_end(self) -> Optional[int]:
        if self.vram_start is not None and self.size is not None:
            return self.vram_start + self.size + self.bss_size
        else:
            return None

    def check_rodata_sym_impl(self, func_addr: int, sym: Symbol, rodata_section: Range):
        if rodata_section.is_complete():
            assert rodata_section.start is not None
            assert rodata_section.end is not None

            rodata_start: int = rodata_section.start
            rodata_end: int = rodata_section.end
            if rodata_start <= sym.vram_start < rodata_end:
                if func_addr not in self.rodata_syms:
                    self.rodata_syms[func_addr] = []
                self.rodata_syms[func_addr].append(sym)

    # Prepare symbol for migration to the function
    def check_rodata_sym(self, func_addr: int, sym: Symbol):
        rodata_section = self.section_boundaries.get(".rodata")
        if rodata_section is not None:
            self.check_rodata_sym_impl(func_addr, sym, rodata_section)
        rodata_section = self.section_boundaries.get(".rdata")
        if rodata_section is not None:
            self.check_rodata_sym_impl(func_addr, sym, rodata_section)

    def handle_alls(self, segs: List[Segment], base_segs) -> bool:
        for i, elem in enumerate(segs):
            if elem.type.startswith("all_"):
                alls = []

                rep_type = f"{elem.type[4:]}"
                replace_class = Segment.get_class_for_type(rep_type)

                for base in base_segs.items():
                    if isinstance(elem.rom_start, int) and isinstance(
                        self.rom_start, int
                    ):
                        # Shoddy rom to ram
                        assert self.vram_start is not None, self.vram_start
                        vram_start = elem.rom_start - self.rom_start + self.vram_start
                    else:
                        vram_start = None
                    rep: Segment = replace_class(
                        rom_start=elem.rom_start,
                        rom_end=elem.rom_end,
                        type=rep_type,
                        name=base[0],
                        vram_start=vram_start,
                        args=[],
                        yaml={},
                    )
                    rep.extract = False
                    rep.given_subalign = self.given_subalign
                    rep.exclusive_ram_id = self.get_exclusive_ram_id()
                    rep.given_dir = self.given_dir
                    rep.given_symbol_name_format = self.symbol_name_format
                    rep.given_symbol_name_format_no_rom = self.symbol_name_format_no_rom
                    rep.sibling = base[1]
                    rep.parent = self
                    if rep.special_vram_segment:
                        self.special_vram_segment = True
                    alls.append(rep)

                # Insert alls into segs at i
                del segs[i]
                segs[i:i] = alls
                return True
        return False

    # Find places we should automatically add "all_data" / "all_rodata" / "all_bss"
    def find_inserts(
        self, found_sections: typing.OrderedDict[str, Range]
    ) -> "OrderedDict[str, int]":
        inserts: OrderedDict[str, int] = OrderedDict()

        section_order = self.section_order.copy()
        section_order.remove(".text")

        for i, section in enumerate(section_order):
            if section not in options.opts.auto_all_sections:
                continue

            if not found_sections[section].has_start():
                search_done = False
                for j in range(i - 1, -1, -1):
                    end = found_sections[section_order[j]].end
                    if end is not None:
                        inserts[section] = end
                        search_done = True
                        break
                if not search_done:
                    inserts[section] = -1
                    pass

        return inserts

    def parse_subsegments(self, segment_yaml) -> List[Segment]:
        if "subsegments" not in segment_yaml:
            if not self.parent:
                raise Exception(
                    f"No subsegments provided in top-level code segment {self.name}"
                )
            return []

        base_segments: OrderedDict[str, Segment] = OrderedDict()
        ret = []
        prev_start: Optional[int] = -1
        prev_vram: Optional[int] = -1
        inserts: OrderedDict[
            str, int
        ] = (
            OrderedDict()
        )  # Used to manually add "all_" types for sections not otherwise defined in the yaml

        self.section_boundaries = OrderedDict(
            (s_name, Range()) for s_name in options.opts.section_order
        )

        found_sections = OrderedDict(
            (s_name, Range()) for s_name in self.section_boundaries
        )  # Stores yaml index where a section was first found
        found_sections.pop(".text")

        # Mark any manually added dot types
        cur_section = None

        for i, subsegment_yaml in enumerate(segment_yaml["subsegments"]):
            # endpos marker
            if isinstance(subsegment_yaml, list) and len(subsegment_yaml) == 1:
                continue

            typ = Segment.parse_segment_type(subsegment_yaml)
            if typ.startswith("all_"):
                typ = typ[4:]
            if not typ.startswith("."):
                typ = f".{typ}"

            if typ in found_sections:
                if cur_section is None:
                    # Starting point
                    found_sections[typ].start = i
                    cur_section = typ
                else:
                    if cur_section != typ:
                        # We're changing sections

                        if options.opts.check_consecutive_segment_types:
                            if found_sections[cur_section].has_end():
                                log.error(
                                    f"Section {cur_section} end encountered but was already ended earlier!"
                                )
                            if found_sections[typ].has_start():
                                log.error(
                                    f"Section {typ} start encounted but has already started earlier!"
                                )

                        # End the current section
                        found_sections[cur_section].end = i

                        # Start the next section
                        found_sections[typ].start = i
                        cur_section = typ

        if cur_section is not None:
            found_sections[cur_section].end = -1

        inserts = self.find_inserts(found_sections)

        last_rom_end = None

        for i, subsegment_yaml in enumerate(segment_yaml["subsegments"]):
            # endpos marker
            if isinstance(subsegment_yaml, list) and len(subsegment_yaml) == 1:
                continue

            typ = Segment.parse_segment_type(subsegment_yaml)
            start = Segment.parse_segment_start(subsegment_yaml)

            # Add dummy segments to be expanded later
            if typ.startswith("all_"):
                dummy_seg = Segment(
                    rom_start=start,
                    rom_end=None,
                    type=typ,
                    name="",
                    vram_start=None,
                    args=[],
                    yaml={},
                )
                dummy_seg.given_subalign = self.given_subalign
                dummy_seg.exclusive_ram_id = self.exclusive_ram_id
                dummy_seg.given_dir = self.given_dir
                dummy_seg.given_symbol_name_format = self.symbol_name_format
                dummy_seg.given_symbol_name_format_no_rom = (
                    self.symbol_name_format_no_rom
                )
                ret.append(dummy_seg)
                continue

            segment_class = Segment.get_class_for_type(typ)

            end = self.get_next_seg_start(i, segment_yaml["subsegments"])

            if start is None:
                # Attempt to infer the start address
                if i == 0:
                    # The start address of this segment is the start address of the group
                    start = self.rom_start
                else:
                    # The start address is the end address of the previous segment
                    start = last_rom_end

            if start is not None and end is None:
                est_size = segment_class.estimate_size(subsegment_yaml)
                if est_size is not None:
                    end = start + est_size

            if start is not None and prev_start is not None and start < prev_start:
                log.error(
                    f"Error: Group segment '{self.name}' contains subsegments which are out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})"
                )

            vram = None
            if start is not None:
                assert isinstance(start, int)
                vram = self.get_most_parent().rom_to_ram(start)

            if segment_class.is_noload():
                # Pretend bss's rom address is after the last actual rom segment
                start = last_rom_end
                # and it has a rom size of zero
                end = last_rom_end

            segment: Segment = Segment.from_yaml(
                segment_class, subsegment_yaml, start, end, vram
            )

            if (
                segment.vram_start is not None
                and prev_vram is not None
                and segment.vram_start < prev_vram
            ):
                log.error(
                    f"Error: Group segment '{self.name}' contains subsegments which are out of ascending vram order (0x{prev_vram:X} followed by 0x{segment.vram_start:X}).\n"
                    + f"Detected when processing file '{segment.name}' of type '{segment.type}'"
                )

            segment.sibling = base_segments.get(segment.name, None)

            if segment.sibling is not None:
                if self.section_order.index(".text") < self.section_order.index(
                    ".rodata"
                ):
                    if segment.is_rodata():
                        segment.sibling.rodata_sibling = segment
                else:
                    if segment.is_text() and segment.sibling.is_rodata():
                        segment.rodata_sibling = segment.sibling
                        segment.sibling.sibling = segment

                if self.section_order.index(".text") < self.section_order.index(
                    ".data"
                ):
                    if segment.is_data():
                        segment.sibling.data_sibling = segment
                else:
                    if segment.is_text() and segment.sibling.is_data():
                        segment.data_sibling = segment.sibling
                        segment.sibling.sibling = segment

            segment.parent = self
            if segment.special_vram_segment:
                self.special_vram_segment = True

            for i, section in enumerate(self.section_order):
                if not self.section_boundaries[section].has_start() and dotless_type(
                    section
                ) == dotless_type(segment.type):
                    if i > 0:
                        prev_section = self.section_order[i - 1]
                        self.section_boundaries[prev_section].end = segment.vram_start
                    self.section_boundaries[section].start = segment.vram_start

            segment.bss_contains_common = self.bss_contains_common
            ret.append(segment)

            if segment.is_text():
                base_segments[segment.name] = segment

            if self.section_order.index(".rodata") < self.section_order.index(".text"):
                if segment.is_rodata() and segment.sibling is None:
                    base_segments[segment.name] = segment

            prev_start = start
            prev_vram = segment.vram_start
            if end is not None:
                last_rom_end = end

        # Add the automatic all_ sections
        orig_len = len(ret)
        for section in reversed(inserts):
            idx = inserts[section]

            if idx == -1:
                idx = orig_len

            # bss hack TODO maybe rethink
            if (
                section == "bss"
                and self.vram_start is not None
                and self.rom_end is not None
                and self.rom_start is not None
            ):
                rom_start = self.rom_end
                vram_start = self.vram_start + self.rom_end - self.rom_start
            else:
                rom_start = None
                vram_start = None

            new_seg = Segment(
                rom_start=rom_start,
                rom_end=None,
                type="all_" + section,
                name="",
                vram_start=vram_start,
                args=[],
                yaml={},
            )
            new_seg.given_subalign = self.given_subalign
            new_seg.exclusive_ram_id = self.exclusive_ram_id
            new_seg.given_dir = self.given_dir
            new_seg.given_symbol_name_format = self.symbol_name_format
            new_seg.given_symbol_name_format_no_rom = self.symbol_name_format_no_rom
            ret.insert(idx, new_seg)

        check = True
        while check:
            check = self.handle_alls(ret, base_segments)

        # TODO why is this necessary?
        rodata_section = self.section_boundaries.get(
            ".rodata"
        ) or self.section_boundaries.get(".rdata")
        if (
            rodata_section is not None
            and rodata_section.has_start()
            and not rodata_section.has_end()
        ):
            assert self.vram_end is not None
            rodata_section.end = self.vram_end

        return ret

    def scan(self, rom_bytes):
        # Always scan code first
        for sub in self.subsegments:
            if sub.is_text() and sub.should_scan():
                sub.scan(rom_bytes)

        # Scan everyone else
        for sub in self.subsegments:
            if not sub.is_text() and sub.should_scan():
                sub.scan(rom_bytes)
