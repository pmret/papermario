from abc import ABC, abstractmethod


class Decompressor(ABC):
    @abstractmethod
    def decompress(self, in_bytes, byte_order="big") -> bytearray:
        pass
