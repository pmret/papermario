#!/usr/bin/env python3

import argparse
import os
import re
import subprocess
import sys
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from sty import fg

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))
root_dir = script_dir / ".."
asm_dir = root_dir / "ver/current/asm/nonmatchings/"
build_dir = root_dir / "ver/current/build/"
elf_path = build_dir / "papermario.elf"
map_file_path = build_dir / "papermario.map"
rom_path = root_dir / "ver/current/baserom.z64"

OBJDUMP = "mips-linux-gnu-objdump"


@dataclass
class Symbol:
    name: str
    rom_start: int
    ram: int
    current_file: Path
    prev_sym: str
    is_decompiled: bool
    rom_end: Optional[int] = None

    def size(self):
        assert self.rom_end is not None
        return self.rom_end - self.rom_start


@dataclass
class Bytes:
    normalized: str
    bytes: bytes


def read_rom() -> bytes:
    with open(rom_path, "rb") as f:
        return f.read()


def get_all_unmatched_functions():
    ret = set()
    for root, dirs, files in os.walk(asm_dir):
        for f in files:
            if f.endswith(".s"):
                ret.add(f[:-2])
    return ret


def get_func_sizes() -> Dict[str, int]:
    try:
        result = subprocess.run(["mips-linux-gnu-objdump", "-x", elf_path], stdout=subprocess.PIPE)
        nm_lines = result.stdout.decode().split("\n")
    except:
        print(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
        sys.exit(1)

    sizes: Dict[str, int] = {}

    for line in nm_lines:
        if " F " in line:
            components = line.split()
            size = int(components[4], 16)
            name = components[5]
            sizes[name] = size

    return sizes


def get_symbol_bytes(func: str) -> Optional[Bytes]:
    if func not in syms or syms[func].rom_end is None:
        return None
    sym = syms[func]
    bs = list(rom_bytes[sym.rom_start : sym.rom_end])

    # trim nops
    while len(bs) > 0 and bs[-1] == 0:
        bs.pop()

    insns = bs[0::4]

    ret = []
    for ins in insns:
        ret.append(ins >> 2)

    return Bytes(0, bytes(ret).decode("utf-8"), rom_bytes[sym.rom_start : sym.rom_end])


def parse_map() -> OrderedDict[str, Symbol]:
    ram_offset = None
    cur_file = "<no file>"
    syms: OrderedDict[str, Symbol] = OrderedDict()
    prev_sym = ""
    prev_line = ""
    cur_sect = ""
    sect_re = re.compile(r"\(\..*\)")
    with open(map_file_path) as f:
        for line in f:
            sect = sect_re.search(line)
            if sect:
                sect_str = sect.group(0)
                if sect_str in ["(.text*)", "(.data*)", "(.rodata*)", "(.bss*)"]:
                    cur_sect = sect_str

            if "load address" in line:
                if "noload" in line or "noload" in prev_line:
                    ram_offset = None
                    continue
                ram = int(line[16 : 16 + 18], 0)
                rom = int(line[59 : 59 + 18], 0)
                ram_offset = ram - rom
                continue
            prev_line = line

            if ram_offset is None or "=" in line or "*fill*" in line or " 0x" not in line:
                continue
            ram = int(line[16 : 16 + 18], 0)
            rom = ram - ram_offset
            fn = line.split()[-1]
            if "0x" in fn:
                ram_offset = None
            elif "/" in fn:
                cur_file = fn
            else:
                if cur_sect != "(.text*)":
                    continue
                new_sym = Symbol(
                    name=fn,
                    rom_start=rom,
                    ram=ram,
                    current_file=Path(cur_file),
                    prev_sym=prev_sym,
                    is_decompiled=not fn in unmatched_functions,
                )
                if fn in func_sizes:
                    new_sym.rom_end = rom + func_sizes[fn]
                syms[fn] = new_sym
                prev_sym = fn

    # Calc end offsets
    for sym in syms:
        prev_sym = syms[sym].prev_sym
        if prev_sym and not syms[prev_sym].rom_end:
            syms[prev_sym].rom_end = syms[sym].rom_start

    return syms


@dataclass
class Match:
    query_offset: int
    target_offset: int
    length: int

    def __str__(self):
        return f"{self.query_offset} {self.target_offset} {self.length}"


@dataclass
class Result:
    query: str
    target: str
    query_start: int
    target_start: int
    length: int

    @property
    def query_end(self):
        return self.query_start + self.length

    @property
    def target_end(self):
        return self.target_start + self.length


def get_pair_matches(query_hashes: list[str], sym_hashes: list[str]) -> list[Match]:
    ret = []

    matching_hashes = set(query_hashes).intersection(sym_hashes)
    for hash in matching_hashes:
        ret.append(Match(query_hashes.index(hash), sym_hashes.index(hash), 1))
    return ret


def get_hashes(bytes: Bytes, window_size: int) -> list[str]:
    ret = []
    for i in range(0, len(bytes.normalized) - window_size):
        ret.append(bytes.normalized[i : i + window_size])
    return ret


def group_matches(
    query: str,
    target: str,
    matches: list[Match],
    window_size: int,
    min: Optional[int],
    max: Optional[int],
    contains: Optional[int],
) -> list[Result]:
    ret = []

    matches.sort(key=lambda m: m.query_offset)

    match_groups: List[List[Match]] = []
    last_start = matches[0].query_offset
    for match in matches:
        if match.query_offset == last_start + 1:
            match_groups[-1].append(match)
        else:
            match_groups.append([match])
        last_start = match.query_offset

    for group in match_groups:
        query_start = group[0].query_offset
        target_start = group[0].target_offset
        length = len(group) + window_size

        if min is not None and query_start + length < min:
            continue
        if max is not None and query_start > max:
            continue
        if contains is not None and (query_start > contains or query_start + length < contains):
            continue

        ret.append(Result(query, target, query_start, target_start, length))

    return ret


def get_line_numbers(obj_file: Path) -> Dict[int, int]:
    ret = {}

    objdump_out = (
        subprocess.run(
            [OBJDUMP, "-WL", obj_file],
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
        )
        .stdout.decode("utf-8")
        .split("\n")
    )

    if not objdump_out:
        return {}

    for line in objdump_out[7:]:
        if not line:
            continue
        pieces = line.split()

        if len(pieces) < 3:
            continue

        fn = pieces[0]

        if fn == OBJDUMP or fn[0] == "<":
            continue

        starting_addr = int(pieces[2], 0)
        try:
            line_num = int(pieces[1])
            ret[starting_addr] = line_num
        except ValueError:
            continue
    return ret


def get_tu_offset(obj_file: Path, symbol: str) -> Optional[int]:
    objdump = "mips-linux-gnu-objdump"

    objdump_out = subprocess.run([objdump, "-t", obj_file], stdout=subprocess.PIPE).stdout.decode("utf-8").split("\n")

    if not objdump_out:
        return None

    for line in objdump_out[4:]:
        if not line:
            continue
        pieces = line.split()

        if pieces[-1] == symbol:
            return int(pieces[0], 16)
    return None


@dataclass
class CRange:
    start: Optional[int] = None
    end: Optional[int] = None
    start_exact = False
    end_exact = False

    def has_info(self):
        return self.start is not None or self.end is not None

    def __str__(self):
        start_str = "?"
        end_str = "?"

        if self.start is not None:
            if self.start_exact:
                start_str = f"{self.start}"
            else:
                start_str = f"~{self.start}"

        if self.end is not None:
            if self.end_exact:
                end_str = f"{self.end}"
            else:
                end_str = f"~{self.end}"

        return f"{start_str} - {end_str}"


def get_c_range(insn_start: int, insn_end: int, line_numbers: Dict[int, int]) -> CRange:
    range = CRange()

    if insn_start in line_numbers:
        range.start = line_numbers[insn_start]
        range.start_exact = True
    else:
        keys = list(line_numbers.keys())
        for i, key in enumerate(keys[:-1]):
            if keys[i + 1] > insn_start:
                range.start = line_numbers[keys[i]]
                break

    if insn_end in line_numbers:
        range.end = line_numbers[insn_end]
        range.end_exact = True
    else:
        keys = list(line_numbers.keys())
        for i, key in enumerate(keys):
            if key > insn_end:
                range.end = line_numbers[key]
                break

    return range


def get_matches(
    query: str,
    window_size: int,
    min: Optional[int],
    max: Optional[int],
    contains: Optional[int],
    show_disasm: bool,
):
    query_bytes: Optional[Bytes] = get_symbol_bytes(query)

    if query_bytes is None:
        sys.exit("Symbol '" + query + "' not found")

    query_hashes = get_hashes(query_bytes, window_size)

    ret: dict[str, float] = {}
    for symbol in syms:
        if query == symbol:
            continue

        sym_bytes: Optional[Bytes] = get_symbol_bytes(symbol)
        if not sym_bytes:
            continue

        if len(sym_bytes.bytes) / 4 < window_size:
            continue

        sym_hashes = get_hashes(sym_bytes, window_size)

        matches: list[Match] = get_pair_matches(query_hashes, sym_hashes)
        if not matches:
            continue

        results: list[Result] = group_matches(query, symbol, matches, window_size, min, max, contains)
        if not results:
            continue

        obj_file = syms[symbol].current_file

        line_numbers = {}
        tu_offset = None
        decompiled_str = ":"
        if syms[symbol].is_decompiled:
            line_numbers = get_line_numbers(obj_file)
            tu_offset = get_tu_offset(obj_file, symbol)
            decompiled_str = fg.green + " (decompiled)" + fg.rs + ":"

        print(symbol + decompiled_str)

        for result in results:
            c_range = None
            if tu_offset is not None and len(line_numbers) > 0:
                c_range = get_c_range(
                    tu_offset + (result.target_start * 4),
                    tu_offset + (result.target_end * 4),
                    line_numbers,
                )

            target_range_str = ""
            if c_range:
                target_range_str = fg.li_cyan + f" (line {c_range} in {obj_file.stem})" + fg.rs

            query_str = f"query [{result.query_start}-{result.query_end}]"
            target_str = (
                f"{symbol} [insn {result.target_start}-{result.target_end}] ({result.length} total){target_range_str}"
            )
            print(f"\t{query_str} matches {target_str}")

            if show_disasm:
                try:
                    import rabbitizer
                except ImportError:
                    print("rabbitizer not found, cannot show disassembly")
                    sys.exit(1)
                result_query_bytes = query_bytes.bytes[result.query_start * 4 : result.query_end * 4]
                result_target_bytes = sym_bytes.bytes[result.target_start * 4 : result.target_end * 4]

                for i in range(0, len(result_query_bytes), 4):
                    q_insn = rabbitizer.Instruction(int.from_bytes(result_query_bytes[i : i + 4], "big"))
                    t_insn = rabbitizer.Instruction(int.from_bytes(result_target_bytes[i : i + 4], "big"))

                    print(f"\t\t{q_insn.disassemble():35} | {t_insn.disassemble()}")

    return OrderedDict(sorted(ret.items(), key=lambda kv: kv[1], reverse=True))


def do_query(query, window_size, min, max, contains, show_disasm):
    get_matches(query, window_size, min, max, contains, show_disasm)


parser = argparse.ArgumentParser(
    description="Tool to find duplicate portions of code from one function in code across the codebase"
)
parser.add_argument("query", help="function")
parser.add_argument(
    "-w",
    "--window-size",
    help="number of bytes to compare",
    type=int,
    default=20,
    required=False,
)
parser.add_argument(
    "--min",
    help="lower bound of instruction for matches against query",
    type=int,
    required=False,
)
parser.add_argument(
    "--max",
    help="upper bound of instruction for matches against query",
    type=int,
    required=False,
)
parser.add_argument(
    "--contains",
    help="All matches must contain this number'th instruction from the query",
    type=int,
    required=False,
)
parser.add_argument(
    "--show-disasm",
    help="Show disassembly of matches",
    action="store_true",
    required=False,
)

args = parser.parse_args()

if __name__ == "__main__":
    rom_bytes = read_rom()
    unmatched_functions = get_all_unmatched_functions()
    func_sizes = get_func_sizes()
    syms = parse_map()

    do_query(
        args.query,
        args.window_size,
        args.min,
        args.max,
        args.contains,
        args.show_disasm,
    )
