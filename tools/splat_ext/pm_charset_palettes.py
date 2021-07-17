from segtypes.n64.segment import N64Segment
from util.color import unpack_color
from util.iter import iter_in_groups
from util import options
import png

def parse_palette(data):
    palette = []

    for a, b in iter_in_groups(data, 2):
        palette.append(unpack_color([a, b]))

    return palette

class N64SegPm_charset_palettes(N64Segment):
    require_unique_name = False

    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start:self.rom_end]

        # pm_charset sibling
        self.sibling = next(filter(lambda s: s.type == "pm_charset" and s.name == self.name, self.parent.subsegments))

        self.palettes = []

        for i in range(0, self.size, 0x10):
            palette = parse_palette(data[i : i + 0x10])
            self.palettes.append(palette)

    def split(self, rom_bytes):
        fs_dir = options.get_asset_path() / self.dir / self.name / "palette"
        fs_dir.mkdir(parents=True, exist_ok=True)

        for i, palette in enumerate(self.palettes):
            raster = self.sibling.rasters[0]

            w = png.Writer(self.sibling.width, self.sibling.height, palette=palette)
            with open(fs_dir / f"{i:02X}.png", "wb") as f:
                w.write_array(f, raster)

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        fs_dir = options.get_asset_path() / self.dir / self.name / "palette"

        return [LinkerEntry(
            self,
            [fs_dir / f"{i:02X}.png" for i in range(self.yaml[3])],
            fs_dir.with_suffix(".dat"), ".data"),
        ]
