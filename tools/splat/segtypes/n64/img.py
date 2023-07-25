from pathlib import Path
from typing import Dict, List, Tuple, Type, Optional, Union

from n64img.image import Image
from util import log, options

from segtypes.n64.segment import N64Segment


class N64SegImg(N64Segment):
    @staticmethod
    def parse_dimensions(yaml: Union[Dict, List]) -> Tuple[int, int]:
        if isinstance(yaml, dict):
            return yaml["width"], yaml["height"]
        else:
            if len(yaml) < 5:
                log.error(f"Error: {yaml} is missing width and height parameters")
            return yaml[3], yaml[4]

    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
        img_cls: Type[Image],
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

        if rom_start is None:
            log.error(f"Error: {type} segment {name} rom start could not be determined")

        self.n64img: Image = img_cls(b"", 0, 0)

        if isinstance(yaml, dict):
            self.n64img.flip_h = bool(yaml.get("flip_x", False))
            self.n64img.flip_v = bool(yaml.get("flip_y", False))

        self.width, self.height = self.parse_dimensions(yaml)

        self.n64img.width = self.width
        self.n64img.height = self.height

        self.check_len()

    def check_len(self) -> None:
        expected_len = int(self.n64img.size())
        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)
        assert isinstance(self.subalign, int)
        actual_len = self.rom_end - self.rom_start
        if actual_len > expected_len and actual_len - expected_len > self.subalign:
            log.error(
                f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)"
            )

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.png"

    def should_split(self) -> bool:
        return options.opts.is_mode_active("img")

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        if self.n64img.data == b"":
            self.n64img.data = rom_bytes[self.rom_start : self.rom_end]
        self.n64img.write(path)

        self.log(f"Wrote {self.name} to {path}")

    @staticmethod
    def estimate_size(yaml: Union[Dict, List]) -> int:
        width, height = N64SegImg.parse_dimensions(yaml)
        typ = N64Segment.parse_segment_type(yaml)

        if typ == "ci4" or typ == "i4" or typ == "ia4":
            return width * height // 2
        elif typ in ("ia16", "rgba16"):
            return width * height * 2
        elif typ == "rgba32":
            return width * height * 4
        else:
            return width * height
