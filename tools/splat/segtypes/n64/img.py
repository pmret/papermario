from pathlib import Path
from typing import Optional
from segtypes.n64.segment import N64Segment
from util import options

class N64SegImg(N64Segment):
    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f"{self.name}.png"

    def should_split(self) -> bool:
        return self.extract and options.mode_active("img")
