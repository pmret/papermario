from typing import List, Optional
from segtypes.common.linker_section import dotless_type
from segtypes.common.segment import CommonSegment
from segtypes.segment import RomAddr, Segment
from util import log


class CommonSegGroup(CommonSegment):
    def __init__(
        self,
        rom_start,
        rom_end,
        type,
        name,
        vram_start,
        extract,
        given_subalign,
        exclusive_ram_id,
        given_dir,
        symbol_name_format,
        symbol_name_format_no_rom,
        args,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            extract,
            given_subalign,
            exclusive_ram_id=exclusive_ram_id,
            given_dir=given_dir,
            symbol_name_format=symbol_name_format,
            symbol_name_format_no_rom=symbol_name_format_no_rom,
            args=args,
            yaml=yaml,
        )

        self.subsegments: List[Segment] = self.parse_subsegments(yaml)

    def get_next_seg_start(self, i, subsegment_yamls):
        return (
            self.rom_end
            if i == len(subsegment_yamls) - 1
            else Segment.parse_segment_start(subsegment_yamls[i + 1])
        )

    def parse_subsegments(self, yaml) -> List[Segment]:
        ret: List[Segment] = []

        if not yaml or "subsegments" not in yaml:
            return ret

        prev_start: RomAddr = -1

        for i, subsection_yaml in enumerate(yaml["subsegments"]):
            # End of previous segment
            if isinstance(subsection_yaml, list) and len(subsection_yaml) == 1:
                continue

            typ = Segment.parse_segment_type(subsection_yaml)
            start = Segment.parse_segment_start(subsection_yaml)

            segment_class = Segment.get_class_for_type(typ)

            end = self.get_next_seg_start(i, yaml["subsegments"])

            if (
                isinstance(start, int)
                and isinstance(prev_start, int)
                and start < prev_start
            ):
                log.error(
                    f"Error: Group segment {self.name} contains subsegments which are out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})"
                )

            vram = None
            if start != "auto":
                assert isinstance(start, int)
                vram = self.get_most_parent().rom_to_ram(start)

            segment: Segment = Segment.from_yaml(
                segment_class, subsection_yaml, start, end, vram
            )
            segment.parent = self

            ret.append(segment)
            prev_start = start

        return ret

    @property
    def needs_symbols(self) -> bool:
        for seg in self.subsegments:
            if seg.needs_symbols:
                return True
        return False

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

    def get_subsegment_for_ram(self, addr) -> Optional[Segment]:
        for sub in self.subsegments:
            if sub.contains_vram(addr):
                return sub
        return None
