from pathlib import Path
from typing import Optional
from segtypes.n64.segment import N64Segment
from util import options
from util import log

class N64SegImg(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml)

        if isinstance(yaml, dict):
            if self.extract:
                self.width = yaml["width"]
                self.height = yaml["height"]

            self.flip_horizontal = bool(yaml.get("flip_x", False))
            self.flip_vertical = bool(yaml.get("flip_y", False))

            if yaml.get("flip"):
                self.warn(f"'flip' parameter for img segments is deprecated; use flip_x and flip_y instead")
                flip = yaml.get("flip")

                self.flip_vertical = flip == "both" or flip.startswith("v") or flip == "y"
                self.flip_horizontal = flip == "both" or flip.startswith("h") or flip == "x"
        else:
            if self.extract:
                if len(yaml) < 5:
                    log.error(f"Error: {self.name} is missing width and height parameters")
                self.width = yaml[3]
                self.height = yaml[4]

            self.flip_horizontal = False
            self.flip_vertical = False

        if self.extract and self.max_length() is not None:
            expected_len = int(self.max_length())
            actual_len = self.rom_end - self.rom_start
            if actual_len > expected_len and actual_len - expected_len > self.subalign:
                log.error(f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)")

    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f"{self.name}.png"

    def should_split(self) -> bool:
        return self.extract and options.mode_active("img")

    def max_length(self) -> Optional[int]:
        return None
