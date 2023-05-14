from pathlib import Path
from typing import Type, Optional

from n64img.image import Image
from util import log, options

from segtypes.n64.segment import N64Segment


class N64SegImg(N64Segment):
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

        self.n64img: Image = img_cls(None, 0, 0)

        if isinstance(yaml, dict):
            if self.extract:
                self.width = yaml["width"]
                self.height = yaml["height"]

            self.n64img.flip_h = bool(yaml.get("flip_x", False))
            self.n64img.flip_v = bool(yaml.get("flip_y", False))
        else:
            if self.extract:
                if len(yaml) < 5:
                    log.error(
                        f"Error: {self.name} is missing width and height parameters"
                    )
                self.width = yaml[3]
                self.height = yaml[4]

        self.n64img.width = self.width
        self.n64img.height = self.height

        self.check_len()

    def check_len(self) -> None:
        if self.extract:
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
        return self.extract and options.opts.is_mode_active("img")

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        if self.n64img.data is None:
            self.n64img.data = rom_bytes[self.rom_start : self.rom_end]
        self.n64img.write(path)

        self.log(f"Wrote {self.name} to {path}")
