from segtypes.n64.rgba16 import N64SegRgba16
import png
import os
from util import options


class N64SegCi8(N64SegRgba16):
    def __init__(self, segment, next_segment):
        super().__init__(segment, next_segment)

        self.path = None

    def split(self, rom_bytes, base_path):
        out_dir = self.create_parent_dir(base_path + "/" + options.get("assets_dir", "img"), self.name)
        self.path = os.path.join(out_dir, os.path.basename(self.name) + ".png")

        data = rom_bytes[self.rom_start: self.rom_end]

        self.image = self.parse_image(data, self.width, self.height)

    def postsplit(self, segments):
        palettes = [seg for seg in segments if seg.type ==
                    "palette" and seg.image_name == self.name]

        if len(palettes) == 0:
            self.error(f"no palette sibling segment exists\n(hint: add a segment with type 'palette' and name '{self.name}')")
            return

        seen_paths = []

        for pal_seg in palettes:
            if pal_seg.path in seen_paths:
                self.error(f"palette name '{pal_seg.name}' is not unique")
                return
            seen_paths.append(pal_seg.path)

            w = png.Writer(self.width, self.height, palette=pal_seg.palette)

            with open(pal_seg.path, "wb") as f:
                w.write_array(f, self.image)
                self.log(f"Wrote {pal_seg.name} to {pal_seg.path}")

        # canonical version of image (not palette!) data
        if self.path not in seen_paths:
            w = png.Writer(self.width, self.height,
                           palette=palettes[0].palette)

            with open(self.path, "wb") as f:
                w.write_array(f, self.image)
                self.log(
                    f"No unnamed palette for {self.name}; wrote image data to {self.path}")

    @staticmethod
    def parse_image(data, width, height):
        return data

    def max_length(self):
        return self.width * self.height
