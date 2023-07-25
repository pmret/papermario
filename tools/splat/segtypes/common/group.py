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

        for i, subsegment_yaml in enumerate(yaml["subsegments"]):
            # endpos marker
            if isinstance(subsegment_yaml, list) and len(subsegment_yaml) == 1:
                continue

            typ = Segment.parse_segment_type(subsegment_yaml)
            start = Segment.parse_segment_start(subsegment_yaml)

            segment_class = Segment.get_class_for_type(typ)

            end = self.get_next_seg_start(i, yaml["subsegments"])

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
                    f"Error: Group segment {self.name} contains subsegments which are out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})"
                )

            vram = None
            if start is not None:
                most_parent = self.get_most_parent()
                if (
                    most_parent.vram_start is not None
                    and most_parent.rom_start is not None
                ):
                    vram = most_parent.vram_start + start - most_parent.rom_start

            if segment_class.is_noload():
                # Pretend bss's rom address is after the last actual rom segment
                start = last_rom_end
                # and it has a rom size of zero
                end = last_rom_end

            segment: Segment = Segment.from_yaml(
                segment_class, subsegment_yaml, start, end, vram
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
