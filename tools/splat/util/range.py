from dataclasses import dataclass
from typing import Optional


@dataclass
class Range:
    start: Optional[int] = None
    end: Optional[int] = None

    def has_start(self):
        return self.start is not None

    def has_end(self):
        return self.end is not None

    def is_complete(self):
        return self.has_start() and self.has_end()
