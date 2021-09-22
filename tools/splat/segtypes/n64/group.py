from collections import OrderedDict
from typing import List, Dict
import sys
from util.range import Range
from util import log, options
from segtypes.n64.segment import N64Segment
from segtypes.segment import RomAddr, Segment
from util.symbols import Symbol

class N64SegGroup(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml)

        self.rodata_syms: Dict[int, List[Symbol]] = {}

        # TODO: move this to N64SegCode
        if isinstance(yaml, dict):
            # TODO Note: These start/end vram options don't really do anything yet
            data_vram = Range(yaml.get("data_vram_start"), yaml.get("data_vram_end"))
            rodata_vram = Range(yaml.get("rodata_vram_start"), yaml.get("rodata_vram_end"))
            bss_vram = Range(yaml.get("bss_vram_start"), yaml.get("bss_vram_end"))
        else:
            data_vram = Range()
            rodata_vram = Range()
            bss_vram = Range()

        self.section_boundaries = {
            "data": data_vram,
            "rodata": rodata_vram,
            "bss": bss_vram,
        }

        self.subsegments = self.parse_subsegments(yaml)

    @property
    def needs_symbols(self) -> bool:
        for seg in self.subsegments:
            if seg.needs_symbols:
                return True
        return False

    def handle_alls(self, segs: List[Segment], base_segs) -> bool:
        for i, elem in enumerate(segs):
            if elem.type.startswith("all_"):
                alls = []

                rep_type = f".{elem.type[4:]}"
                replace_class = Segment.get_class_for_type(rep_type)

                for base in base_segs.items():
                    if isinstance(elem.rom_start, int):
                        # Shoddy rom to ram
                        vram_start = elem.rom_start - self.rom_start + self.vram_start
                    else:
                        vram_start = "auto"
                    rep = replace_class(elem.rom_start, elem.rom_end, rep_type, base[0], vram_start, False, self.given_subalign, self.given_is_overlay, self.given_dir, [], {})
                    rep.sibling = base[1]
                    rep.parent = self
                    alls.append(rep)

                # Insert alls into segs at i
                del segs[i]
                segs[i:i] = alls
                return True
        return False

    def find_inserts(self, found_sections: Dict[str, Range], section_order) -> "OrderedDict[str, int]":
        inserts = OrderedDict()

        for i, section in enumerate(section_order):
            if not found_sections[section].has_start():
                search_done = False
                for j in range(i - 1, -1, -1):
                    if found_sections[section_order[j]].has_end():
                        inserts[section] = found_sections[section_order[j]].end
                        search_done = True
                        break
                if not search_done:
                    inserts[section] = -1
                    pass

        return inserts

    def get_next_seg_start(self, i, subsegment_yamls):
        return self.rom_end if i == len(subsegment_yamls) - 1 else Segment.parse_segment_start(subsegment_yamls[i + 1])

    def parse_subsegments(self, segment_yaml) -> List[Segment]:
        base_segments: OrderedDict[str, Segment] = OrderedDict()
        ret = []
        prev_start: RomAddr = -1
        inserts: OrderedDict[str, int] = OrderedDict() # Used to manually add "all_" types for sections not otherwise defined in the yaml

        sections = ["data", "rodata", "bss"]
        found_sections = {"data": Range(), "rodata": Range(), "bss": Range()} # Stores yaml index where a section was first found

        if "subsegments" not in segment_yaml:
            return []

        # Mark any manually added dot types
        if options.get("auto_all_sections"):
            cur_section = None

            for i, subsection_yaml in enumerate(segment_yaml["subsegments"]):
                # rompos marker
                if isinstance(subsection_yaml, list) and len(subsection_yaml) == 1:
                    if cur_section is not None:
                        # End the current section
                        found_sections[cur_section].end = i
                        cur_section = None
                    continue

                typ = Segment.parse_segment_type(subsection_yaml)
                if typ.startswith("all_"):
                    typ = typ[4:]
                elif typ.startswith("."):
                    typ = typ[1:]
                if typ in found_sections:
                    if cur_section is None:
                        # Starting point
                        found_sections[typ].start = i
                        cur_section = typ
                    else:
                        if cur_section != typ:
                            # We're changing sections
                            if found_sections[cur_section].has_end():
                                log.error(f"Section {cur_section} end encountered but was already ended earlier!")
                            if found_sections[typ].has_start():
                                log.error(f"Section {typ} start encounted but has already started earlier!")

                            # End the current section
                            found_sections[cur_section].end = i

                            # Start the next section
                            found_sections[typ].start = i
                            cur_section = typ

            if cur_section is not None:
                found_sections[cur_section].end = len(segment_yaml["subsegments"])

            inserts = self.find_inserts(found_sections, sections)

        for i, subsection_yaml in enumerate(segment_yaml["subsegments"]):
            # rompos marker
            if isinstance(subsection_yaml, list) and len(subsection_yaml) == 1:
                continue

            typ = Segment.parse_segment_type(subsection_yaml)
            start = Segment.parse_segment_start(subsection_yaml)

            # Add dummy segments to be expanded later
            if typ.startswith("all_"):
                ret.append(Segment(start, "auto", typ, "", "auto"))
                continue

            segment_class = Segment.get_class_for_type(typ)

            end = self.get_next_seg_start(i, segment_yaml["subsegments"])

            if isinstance(start, int) and isinstance(prev_start, int) and start < prev_start:
                log.error(f"Error: Code segment {self.name} contains subsegments which are out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})")

            vram = None
            if start != "auto":
                assert isinstance(start, int)
                vram = self.get_most_parent().rom_to_ram(start)

            segment: Segment = Segment.from_yaml(segment_class, subsection_yaml, start, end, vram)
            segment.sibling = base_segments.get(segment.name, None)
            segment.parent = self

            # TODO: assumes section order - generalize and stuff
            if not self.section_boundaries["data"].has_start() and "data" in segment.type:
                self.section_boundaries["data"].start = segment.vram_start
            if not self.section_boundaries["rodata"].has_start() and "rodata" in segment.type:
                self.section_boundaries["data"].end = segment.vram_start
                self.section_boundaries["rodata"].start = segment.vram_start
            if not self.section_boundaries["rodata"].has_end() and "bss" in segment.type:
                self.section_boundaries["rodata"].end = segment.vram_start
                self.section_boundaries["bss"].start = segment.vram_start

            ret.append(segment)

            # todo change
            if typ in ["c", "asm", "hasm"]:
                base_segments[segment.name] = segment

            prev_start = start

        # Add the automatic all_ sections
        orig_len = len(ret)
        for section in reversed(inserts):
            idx = inserts[section]

            if idx == -1:
                idx = orig_len

            # bss hack TODO maybe rethink
            if section == "bss" and self.vram_start is not None:
                rom_start = self.rom_end
                vram_start = self.vram_start + self.rom_end - self.rom_start
            else:
                rom_start = "auto"
                vram_start = "auto"

            ret.insert(idx, (Segment(rom_start, "auto", "all_" + section, "", vram_start)))

        check = True
        while check:
            check = self.handle_alls(ret, base_segments)

        if self.section_boundaries["rodata"].has_start() and not self.section_boundaries["rodata"].has_end():
            assert self.vram_end is not None
            self.section_boundaries["rodata"].end = self.vram_end

        return ret

    def get_linker_entries(self):
        return [entry for sub in self.subsegments for entry in sub.get_linker_entries()]

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

    def get_most_parent(self):
        seg = self

        while seg.parent:
            seg = seg.parent

        return seg
