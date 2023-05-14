from disassembler import disassembler
from util.options import SplatOpts
from typing import Set


class NullDisassembler(disassembler.Disassembler):
    def configure(self, opts: SplatOpts):
        pass

    def check_version(self, skip_version_check: bool, splat_version: str):
        pass

    def known_types(self) -> Set[str]:
        return set()
