from typing import Dict, Tuple
from segtypes.common.group import CommonSegGroup
from util.symbols import Symbol

# code group
class CommonSegCode(CommonSegGroup):
    def __init__(
        self,
        rom_start,
        rom_end,
        type,
        name,
        vram_start,
        extract,
        given_subalign,
        given_is_overlay,
        given_dir,
        args,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            extract,
            given_subalign,
            given_is_overlay,
            given_dir,
            args,
            yaml,
        )

        self.reported_file_split = False
        self.labels_to_add = set()
        self.jtbl_glabels_to_add = set()
        self.jtbl_jumps = {}
        self.jumptables: Dict[int, Tuple[int, int]] = {}

    @property
    def needs_symbols(self) -> bool:
        return True

    # Prepare symbol for migration to the function
    def check_rodata_sym(self, func_addr: int, sym: Symbol):
        if self.section_boundaries[".rodata"].is_complete():
            if (
                self.section_boundaries[".rodata"].start
                <= sym.vram_start
                < self.section_boundaries[".rodata"].end
            ):
                if func_addr not in self.rodata_syms:
                    self.rodata_syms[func_addr] = []
                self.rodata_syms[func_addr].append(sym)
