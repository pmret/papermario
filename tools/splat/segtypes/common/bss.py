from segtypes.common.data import CommonSegData
from util import log

class CommonSegBss(CommonSegData):
    def get_linker_section(self) -> str:
        return ".bss"

    def scan(self, rom_bytes: bytes):
        pass

    def split(self, rom_bytes: bytes):
        pass

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        if self.sibling:
            path = self.sibling.out_path()
        else:
            log.error("Unlinked bss sections currently unsupported")

        return [LinkerEntry(self, [path], path, self.get_linker_section())]
