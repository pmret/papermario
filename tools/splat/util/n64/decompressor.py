from abc import ABC, abstractmethod
from typing import Literal


class Decompressor(ABC):
    @abstractmethod
    def decompress(
        self, in_bytes, byte_order: Literal["little", "big"] = "big"
    ) -> bytearray:
        pass
