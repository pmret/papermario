from segtypes.n64.data import N64SegData

class N64SegRodata(N64SegData):    
    def get_linker_section(self) -> str:
        return ".rodata"
