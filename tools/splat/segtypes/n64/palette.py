from typing import TYPE_CHECKING, Optional
from pathlib import Path
from segtypes.n64.segment import N64Segment
from util import options
from util.color import unpack_color
from util.iter import iter_in_groups
from util import log
import png

if TYPE_CHECKING:
    from segtypes.n64.ci8 import N64SegCi8 as Raster

class N64SegPalette(N64Segment):
    require_unique_name = False

    def __init__(self, segment, rom_start, rom_end):
        super().__init__(segment, rom_start, rom_end)

        self.raster: 'Optional[Raster]' = None

        # palette segments must be named as one of the following:
        #  1) same as the relevant raster segment name (max. 1 palette)
        #  2) relevant raster segment name + "." + unique palette name
        #  3) unique, referencing the relevant raster segment using `raster_name`
        self.raster_name = segment.get(
            "raster_name",
            self.name.split(".")[0]
        ) if type(segment) is dict else self.name.split(".")[0]

        if self.extract:
            if self.rom_end == "auto":
                log.error(f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it")

            if self.max_length() and isinstance(self.rom_end, int):
                expected_len = int(self.max_length())
                actual_len = self.rom_end - self.rom_start
                if actual_len > expected_len and actual_len - expected_len > self.subalign:
                    log.error(f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)")

    def should_split(self):
        return self.extract and (super().should_split() or options.mode_active("img"))
 
    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f"{self.name}.png"

    def split(self, rom_bytes):
        if self.raster is None:
            # TODO: output with no raster
            log.error(f"orphaned palette segment: {self.name} lacks ci4/ci8 sibling")
            return

        w = png.Writer(self.raster.width, self.raster.height, palette=self.parse_palette(rom_bytes))
        image = self.raster.__class__.parse_image(
            rom_bytes[self.raster.rom_start:self.raster.rom_end],
            self.raster.width,
            self.raster.height,
            self.raster.flip_horizontal,
            self.raster.flip_vertical
        )

        with open(self.out_path(), "wb") as f:
            w.write_array(f, image)

        self.raster.extract = False

    def parse_palette(self, rom_bytes):
        data = rom_bytes[self.rom_start:self.rom_end]
        palette = []

        for a, b in iter_in_groups(data, 2):
            palette.append(unpack_color([a, b]))

        return palette

    def max_length(self):
        return 256 * 2

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        return [LinkerEntry(
            self,
            [options.get_asset_path() / self.dir / f"{self.name}.png"],
            options.get_asset_path() / self.dir / f"{self.name}.pal",
            self.get_linker_section()
        )]
