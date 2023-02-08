from typing import List, Optional

from util import log

from segtypes.common.segment import CommonSegment
from segtypes.segment import Segment


class CommonSegGroup(CommonSegment):
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
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
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

        prev_start: Optional[int] = -1
        last_rom_end = 0

        for i, subsection_yaml in enumerate(yaml["subsegments"]):
            # endpos marker
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
            if start is not None:
                assert isinstance(start, int)
                vram = self.get_most_parent().rom_to_ram(start)

            if segment_class.is_noload():
                # Pretend bss's rom address is after the last actual rom segment
                start = last_rom_end
                # and it has a rom size of zero
                end = last_rom_end

            segment: Segment = Segment.from_yaml(
                segment_class, subsection_yaml, start, end, vram
            )
            segment.parent = self
            if segment.special_vram_segment:
                self.special_vram_segment = True

            ret.append(segment)
            prev_start = start
            if end is not None:
                last_rom_end = end

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

    def get_subsegment_for_ram(self, addr: int) -> Optional[Segment]:
        for sub in self.subsegments:
            if sub.contains_vram(addr):
                return sub
        return None

    def get_next_subsegment_for_ram(self, addr: int) -> Optional[Segment]:
        """
        Returns the first subsegment which comes after the specified address,
        or None in case this address belongs to the last subsegment of this group
        """

        for sub in self.subsegments:
            if sub.vram_start is None:
                continue
            assert isinstance(sub.vram_start, int)
            if sub.vram_start > addr:
                return sub
        return None
