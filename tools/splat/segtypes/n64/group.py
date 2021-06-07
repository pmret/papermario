from collections import OrderedDict
from typing import List, Dict, Optional
import sys
from segtypes.n64.segment import N64Segment
from segtypes.segment import RomAddr, Segment
from util.symbols import Symbol

class N64SegGroup(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml)

        self.rodata_syms: Dict[int, List[Symbol]] = {}

        # TODO Note: These start/end vram options don't really do anything yet
        self.data_vram_start: Optional[int] = yaml.get("data_vram_start")
        self.data_vram_end: Optional[int] = yaml.get("data_vram_end")
        self.rodata_vram_start: Optional[int] = yaml.get("rodata_vram_start")
        self.rodata_vram_end: Optional[int] = yaml.get("rodata_vram_end")
        self.bss_vram_start: Optional[int] = yaml.get("bss_vram_start")
        self.bss_vram_end: Optional[int] = yaml.get("bss_vram_end")

        self.subsegments = self.parse_subsegments(yaml)

    @property
    def needs_symbols(self) -> bool:
        for seg in self.subsegments:
            if seg.needs_symbols:
                return True
        return False

    def handle_alls(self, segs, base_segs) -> bool:
        for i, elem in enumerate(segs):
            if elem.type.startswith("all_"):
                alls = []

                rep_type = f".{elem.type[4:]}"
                replace_class = Segment.get_class_for_type(rep_type)

                for base in base_segs.items():
                    rep = replace_class("auto", "auto", rep_type, base[0], "auto", extract=False)
                    rep.sibling = base[1]
                    rep.parent = self
                    alls.append(rep)

                del segs[i]
                segs[i:i] = alls
                return True
        return False

    def parse_subsegments(self, segment_yaml) -> List[Segment]:
        base_segments: OrderedDict[str, Segment] = OrderedDict()
        ret = []
        prev_start: RomAddr = -1

        if "subsegments" not in segment_yaml:
            print(f"Error: Group segment {self.name} is missing a 'subsegments' field")
            sys.exit(2)

        for i, subsection_yaml in enumerate(segment_yaml["subsegments"]):
            # rompos marker
            if isinstance(subsection_yaml, list) and len(subsection_yaml) == 1:
                continue

            typ = Segment.parse_segment_type(subsection_yaml)

            if typ.startswith("all_"):
                ret.append(Segment("auto", "auto", typ, "", "auto"))
                continue

            segment_class = Segment.get_class_for_type(typ)

            start = Segment.parse_segment_start(subsection_yaml)
            end = self.rom_end if i == len(segment_yaml["subsegments"]) - 1 else Segment.parse_segment_start(segment_yaml["subsegments"][i + 1])

            if isinstance(start, int) and isinstance(prev_start, int) and start < prev_start:
                print(f"Error: Code segment {self.name} contains subsegments which are out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})")
                sys.exit(1)

            segment: Segment = Segment.from_yaml(segment_class, subsection_yaml, start, end)
            segment.sibling = base_segments.get(segment.name, None)
            segment.parent = self

            if segment.rom_start != "auto":
                assert isinstance(segment.rom_start, int)
                segment.vram_start = self.rom_to_ram(segment.rom_start)

            # TODO: assumes section order - generalize and stuff
            if self.data_vram_start == None and "data" in segment.type:
                self.data_vram_start = segment.vram_start
            if self.rodata_vram_start == None and "rodata" in segment.type:
                self.data_vram_end = segment.vram_start
                self.rodata_vram_start = segment.vram_start
            if self.rodata_vram_end == None and "bss" in segment.type:
                self.rodata_vram_end = segment.vram_start
                self.bss_vram_start = segment.vram_start

            ret.append(segment)

            # todo change
            if typ in ["c", "asm", "hasm"]:
                base_segments[segment.name] = segment

            prev_start = start

        check = True

        while check:
            check = self.handle_alls(ret, base_segments)

        if self.rodata_vram_start != None and self.rodata_vram_end == None:
            assert self.vram_end is not None
            self.rodata_vram_end = self.vram_end

        return ret

    def get_linker_entries(self):
        # [item for sublist in t for item in sublist]
        return [entry for sub in self.subsegments for entry in sub.get_linker_entries() ]

    def scan(self, rom_bytes):
        for sub in self.subsegments:
            if sub.should_scan():
                sub.scan(rom_bytes)

    def split(self, rom_bytes):
        for sub in self.subsegments:
            if sub.should_split():
                sub.split(rom_bytes)

    def should_split(self) -> bool:
        return self.extract
    
    def should_scan(self) -> bool:
        return self.extract

    def cache(self):
        c = []

        for sub in self.subsegments:
            c.append(sub.cache())
        
        return c
