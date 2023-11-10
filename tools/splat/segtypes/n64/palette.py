from itertools import zip_longest
from pathlib import Path
from typing import Dict, List, Optional, Tuple, TYPE_CHECKING, Union

from util import log, options
from util.color import unpack_color

from segtypes.n64.segment import N64Segment
from util.symbols import to_cname

if TYPE_CHECKING:
    from segtypes.n64.ci import N64SegCi as Raster


def iter_in_groups(iterable, n, fillvalue=None):
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)


VALID_SIZES = [0x20, 0x40, 0x80, 0x100, 0x200]


class N64SegPalette(N64Segment):
    require_unique_name = False

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.raster: "Optional[Raster]" = None

        # palette segments must be named as one of the following:
        #  1) same as the relevant raster segment name (max. 1 palette)
        #  2) relevant raster segment name + "." + unique palette name
        #  3) unique, referencing the relevant raster segment using `raster_name`
        self.raster_name = (
            self.yaml.get("raster_name", self.name.split(".")[0])
            if isinstance(self.yaml, dict)
            else self.name.split(".")[0]
        )

        if self.extract:
            if self.rom_end is None:
                log.error(
                    f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
                )

            if not isinstance(self.yaml, dict) or "size" not in self.yaml:
                assert self.rom_end is not None
                assert self.rom_start is not None
                actual_len = self.rom_end - self.rom_start

                hint_msg = "(hint: add a 'bin' segment after it or specify the size in the segment)"

                if actual_len > VALID_SIZES[-1]:
                    log.error(
                        f"Error: {self.name} (0x{actual_len:X} bytes) is too long, max 0x{VALID_SIZES[-1]:X})\n{hint_msg}"
                    )

                if actual_len not in VALID_SIZES:
                    log.error(
                        f"Error: {self.name} (0x{actual_len:X} bytes) is not a valid palette size ({', '.join(hex(s) for s in VALID_SIZES)})\n{hint_msg}"
                    )

    def get_cname(self) -> str:
        return super().get_cname() + "_pal"

    def split(self, rom_bytes):
        if self.raster is None:
            # TODO: output with no raster
            log.error(f"orphaned palette segment: {self.name} lacks ci4/ci8 sibling")

        assert self.raster is not None
        self.raster.n64img.palette = self.parse_palette(rom_bytes)  # type: ignore

        self.raster.n64img.write(self.out_path())
        self.raster.extract = False

    def parse_palette(self, rom_bytes) -> List[Tuple[int, int, int, int]]:
        data = rom_bytes[self.rom_start : self.rom_end]
        palette = []

        for a, b in iter_in_groups(data, 2):
            palette.append(unpack_color([a, b]))

        return palette

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.png"

    def should_split(self) -> bool:
        return self.extract and options.opts.is_mode_active("img")

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        return [
            LinkerEntry(
                self,
                [options.opts.asset_path / self.dir / f"{self.name}.png"],
                options.opts.asset_path / self.dir / f"{self.name}.pal",
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                self.is_noload(),
            )
        ]

    @staticmethod
    def estimate_size(yaml: Union[Dict, List]) -> int:
        if isinstance(yaml, dict):
            if "size" in yaml:
                return int(yaml["size"])
        return 0x20
