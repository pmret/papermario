from segtypes.common.data import CommonSegData


class CommonSegSbss(CommonSegData):
    def get_linker_section(self) -> str:
        return ".sbss"
