from segtypes.n64.group import N64SegGroup
from typing import Optional
from segtypes.segment import Segment
from util import symbols
from util.symbols import Symbol

# code group
class N64SegCode(N64SegGroup):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml)

        self.reported_file_split = False
        self.labels_to_add = set()
        self.jtbl_glabels_to_add = set()
        self.jtbl_jumps = {}
        self.jumptables = {}

    @property
    def needs_symbols(self) -> bool:
        return True

    def check_rodata_sym(self, func_addr: int, sym: Symbol):
        if self.rodata_vram_start != None and self.rodata_vram_end != None:
            if self.rodata_vram_start <= sym.vram_start < self.rodata_vram_end:
                if func_addr not in self.rodata_syms:
                    self.rodata_syms[func_addr] = []
                self.rodata_syms[func_addr].append(sym)

    def get_subsegment_for_ram(self, addr) -> Optional[Segment]:
        for sub in self.subsegments:
            if sub.contains_vram(addr):
                return sub
        return None

    def retrieve_symbol(self, d, k, t):
        if k not in d:
            return None

        if t:
            items = [s for s in d[k] if s.type == t or s.type == "unknown"]
        else:
            items = d[k]

        if len(items) > 1:
            pass #print(f"Trying to retrieve {k:X} from symbol dict but there are {len(items)} entries to pick from - picking the first")
        if len(items) == 0:
            return None
        return items[0]

    def get_symbol(self, addr, type=None, create=False, define=False, reference=False, offsets=False, local_only=False, dead=True):
        ret = None
        rom = None

        in_segment = self.contains_vram(addr)

        if in_segment:
            # If the vram address is within this segment, we can calculate the symbol's rom address
            rom = self.ram_to_rom(addr)
            ret = self.retrieve_symbol(self.seg_symbols, addr, type)
        elif not local_only:
            ret = self.retrieve_symbol(self.ext_symbols, addr, type)

        # Search for symbol ranges
        if not ret and offsets:
            ret = symbols.retrieve_from_ranges(addr, rom)

        # Reject dead symbols unless we allow them
        if not dead and ret and ret.dead:
            ret = None

        # Create the symbol if it doesn't exist
        if not ret and create:
            ret = Symbol(addr, rom=rom, type=type)
            symbols.all_symbols.append(ret)

            if in_segment:
                if self.is_overlay:
                    ret.set_in_overlay()
                if addr not in self.seg_symbols:
                    self.seg_symbols[addr] = []
                self.seg_symbols[addr].append(ret)
            elif not local_only:
                if addr not in self.ext_symbols:
                    self.ext_symbols[addr] = []
                self.ext_symbols[addr].append(ret)

        if ret:
            if define:
                ret.defined = True
            if reference:
                ret.referenced = True

        return ret

