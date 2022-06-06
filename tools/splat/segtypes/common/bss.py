from segtypes.common.data import CommonSegData
from segtypes.linker_entry import LinkerEntry
from util import options, log

from typing import List


class CommonSegBss(CommonSegData):
    def get_linker_section(self) -> str:
        return ".bss"

    def scan(self, rom_bytes: bytes):
        pass

    def split(self, rom_bytes: bytes):
        pass

    def get_linker_entries(self) -> "List[LinkerEntry]":

        if self.sibling:
            path = self.sibling.out_path()
        else:
            path = self.out_path()

        if path:
            return [LinkerEntry(self, [path], path, self.get_linker_section())]
        else:
            return []
