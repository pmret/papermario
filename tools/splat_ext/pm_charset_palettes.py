from splat.segtypes.segment import Segment
from splat.segtypes.n64.palette import N64SegPalette
from splat.util import options
import png  # type: ignore


class N64SegPm_charset_palettes(Segment):
    require_unique_name = False

    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]

        # pm_charset siblings
        self.siblings = []
        for s in self.parent.subsegments:
            if s.type == "pm_charset":
                if len(s.yaml) > 6:
                    charset_pal = s.yaml[6]
                else:
                    charset_pal = s.name
                if self.name == charset_pal:
                    self.siblings.append(s)

        self.palettes = []

        for i in range(0, self.size, 0x10):
            palette = N64SegPalette.parse_palette_bytes(data[i : i + 0x10])
            self.palettes.append(palette)

    def split(self, rom_bytes):
        fs_dir = options.opts.asset_path / self.dir / self.name / "palette"
        fs_dir.mkdir(parents=True, exist_ok=True)

        for i, palette in enumerate(self.palettes):
            raster = self.siblings[0].rasters[0]

            w = png.Writer(self.siblings[0].width, self.siblings[0].height, palette=palette)
            with open(fs_dir / f"{i:02X}.png", "wb") as f:
                w.write_array(f, raster)

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        fs_dir = options.opts.asset_path / self.dir / self.name / "palette"

        return [
            LinkerEntry(
                self,
                [fs_dir / f"{i:02X}.png" for i in range(self.yaml[3])],
                fs_dir.with_suffix(".dat"),
                ".data",
                ".data",
            ),
        ]
