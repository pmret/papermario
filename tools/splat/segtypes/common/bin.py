from pathlib import Path
from typing import Optional
from segtypes.common.segment import CommonSegment
from util import options
from util import log

class CommonSegBin(CommonSegment):
    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f"{self.name}.bin"

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        if self.rom_end == "auto":
            log.error(f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it")

        with open(path, "wb") as f:
            f.write(rom_bytes[self.rom_start : self.rom_end])
        self.log(f"Wrote {self.name} to {path}")
