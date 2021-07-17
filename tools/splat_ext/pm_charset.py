from segtypes.n64.segment import N64Segment
from util import options
import png

def parse_ci4(data, width, height):
    raster = bytearray()

    for i in range(width * height // 2):
        raster.append(data[i] >> 4)
        raster.append(data[i] & 0xF)

    return raster

def next_8(n):
    if n % 8 != 0:
        return next_8(n + 1)
    else:
        return n

class N64SegPm_charset(N64Segment):
    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start:self.rom_end]

        # start, type, name, WIDTH, HEIGHT, NUM_RASTERS
        self.width = self.yaml[3]
        self.height = self.yaml[4]

        # pm_charset_palettes sibling
        self.sibling = next(filter(lambda s: s.type == "pm_charset_palettes" and s.name == self.name, self.parent.subsegments))

        self.rasters = []

        for i in range(0, self.size, next_8(self.width * self.height // 2)):
            raster = parse_ci4(data[i:], self.width, self.height)
            self.rasters.append(raster)

    def split(self, rom_bytes):
        fs_dir = options.get_asset_path() / self.dir / self.name
        fs_dir.mkdir(parents=True, exist_ok=True)

        for i, raster in enumerate(self.rasters):
            palette = self.sibling.palettes[0]

            w = png.Writer(self.width, self.height, palette=palette)
            with open(fs_dir / f"{i:02X}.png", "wb") as f:
                w.write_array(f, raster)

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        # start, type, name, WIDTH, HEIGHT
        self.width = self.yaml[3]
        self.height = self.yaml[4]

        fs_dir = options.get_asset_path() / self.dir / self.name

        return [LinkerEntry(
            self,
            [fs_dir / f"{i:02X}.png" for i in range(self.yaml[5])],
            fs_dir.with_suffix(".dat"), ".data"),
        ]
