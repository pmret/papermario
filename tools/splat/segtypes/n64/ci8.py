from typing import TYPE_CHECKING, Optional
from segtypes.n64.rgba16 import N64SegRgba16
import png
from util import log
from util import options
from util import iter

if TYPE_CHECKING:
    from segtypes.n64.palette import N64SegPalette as Palette

class N64SegCi8(N64SegRgba16):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml)

        self.palette: 'Optional[Palette]' = None
        self.palette_name = self.name

    def split(self, rom_bytes):
        path = options.get_asset_path() / self.dir / (self.name + ".png")
        path.parent.mkdir(parents=True, exist_ok=True)

        data = rom_bytes[self.rom_start:self.rom_end]

        if self.palette is None:
            # TODO: output with blank palette
            log.error(f"no palette sibling segment exists\n(hint: add a segment with type 'palette' and name '{self.name}')")
            return

        w = png.Writer(self.width, self.height, palette=self.palette.parse_palette(rom_bytes))
        image = self.__class__.parse_image(data, self.width, self.height, self.flip_horizontal, self.flip_vertical)

        with open(self.out_path(), "wb") as f:
            w.write_array(f, image)
        
        self.palette.extract = False

    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        # hot path
        if not flip_h and not flip_v:
            return data
        
        flipped_data = bytearray()

        for x, y, i in iter.iter_image_indexes(width, height, 1, 1, flip_h, flip_v):
            flipped_data.append(data[i])

        return flipped_data

    def max_length(self):
        return self.width * self.height

    def cache(self):
        return (self.yaml, self.rom_end, 1)
