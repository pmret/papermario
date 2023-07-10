from typing import Optional, TYPE_CHECKING

from util import log

from segtypes.n64.img import N64SegImg

if TYPE_CHECKING:
    from segtypes.n64.palette import N64SegPalette


# Base class for CI4/CI8
class N64SegCi(N64SegImg):
    def parse_palette_name(self, yaml, args) -> str:
        ret = self.name
        if isinstance(yaml, dict):
            if "palette" in yaml:
                ret = yaml["palette"]
        elif len(args) > 2:
            ret = args[2]

        return ret

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.palette: "Optional[N64SegPalette]" = None
        self.palette_name = self.parse_palette_name(self.yaml, self.args)

    def scan(self, rom_bytes: bytes) -> None:
        self.n64img.data = rom_bytes[self.rom_start : self.rom_end]

    def split(self, rom_bytes):
        if self.palette is None:
            # TODO: output with blank palette
            log.error(
                f"no palette sibling segment exists\n(hint: add a segment with type 'palette' and name '{self.name}')"
            )
        assert self.palette is not None
        self.palette.extract = False
        self.n64img.palette = self.palette.parse_palette(rom_bytes)

        super().split(rom_bytes)
