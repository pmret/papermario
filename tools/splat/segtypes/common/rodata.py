from segtypes.common.data import CommonSegData

class CommonSegRodata(CommonSegData):
    def get_linker_section(self) -> str:
        return ".rodata"
