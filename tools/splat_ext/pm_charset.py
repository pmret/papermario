from splat.segtypes.segment import Segment
from splat.util import options
import png  # type: ignore


def parse_ci4(data, width, height):
    raster = bytearray()

    for i in range(width * height // 2):
        raster.append(data[i] >> 4)
        raster.append(data[i] & 0xF)

    return raster


def get_palette_idx(charset_name, char_id):
    pal_id = 0
    if charset_name == "standard":
        if char_id == 0x98:
            pal_id = 0x10
        elif char_id == 0x99:
            pal_id = 0x11
        elif char_id == 0x9A:
            pal_id = 0x15
        elif char_id == 0x9B:
            pal_id = 0x15
        elif char_id == 0x9C:
            pal_id = 0x15
        elif char_id == 0x9D:
            pal_id = 0x13
        elif char_id == 0x9E:
            pal_id = 0x13
        elif char_id == 0x9F:
            pal_id = 0x13
        elif char_id == 0xA0:
            pal_id = 0x13
        elif char_id == 0xA1:
            pal_id = 0x12
    elif charset_name == "buttons":
        if char_id == 0x00:
            pal_id = 0x10
        elif char_id == 0x01:
            pal_id = 0x11
        elif char_id == 0x02:
            pal_id = 0x12
        elif char_id == 0x03:
            pal_id = 0x13
        elif char_id == 0x04:
            pal_id = 0x13
        elif char_id == 0x05:
            pal_id = 0x13
        elif char_id == 0x06:
            pal_id = 0x13
        elif char_id == 0x07:
            pal_id = 0x14
        elif char_id == 0x08:
            pal_id = 0x14
        elif char_id == 0x09:
            pal_id = 0x14
    return pal_id


class N64SegPm_charset(Segment):
    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]

        # start, type, name, WIDTH, HEIGHT, NUM_RASTERS, palette
        self.width = self.yaml[3]
        self.height = self.yaml[4]
        if len(self.yaml) > 6:
            self.palette = self.yaml[6]
        else:
            self.palette = self.name

        # pm_charset_palettes sibling
        self.sibling = next(
            filter(
                lambda s: s.type == "pm_charset_palettes" and s.name == self.palette,
                self.parent.subsegments,
            )
        )

        self.rasters = []

        step = self.width * self.height // 2
        # align step to 8
        step = (step + 7) & ~7

        for i in range(0, self.size, step):
            raster = parse_ci4(data[i:], self.width, self.height)
            self.rasters.append(raster)

    def split(self, rom_bytes):
        fs_dir = options.opts.asset_path / self.dir / self.name
        fs_dir.mkdir(parents=True, exist_ok=True)

        for i, raster in enumerate(self.rasters):
            pal_idx = get_palette_idx(self.name, i)
            palette = self.sibling.palettes[pal_idx]

            w = png.Writer(self.width, self.height, palette=palette)
            with open(fs_dir / f"{i:02X}.png", "wb") as f:
                w.write_array(f, raster)

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        # start, type, name, WIDTH, HEIGHT
        self.width = self.yaml[3]
        self.height = self.yaml[4]

        fs_dir = options.opts.asset_path / self.dir / self.name

        return [
            LinkerEntry(
                self,
                [fs_dir / f"{i:02X}.png" for i in range(self.yaml[5])],
                fs_dir.with_suffix(".dat"),
                ".data",
                ".data",
            ),
        ]
