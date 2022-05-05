from segtypes.common.data import CommonSegData


class CommonSegRdata(CommonSegData):
    def get_linker_section(self) -> str:
        return ".rdata"
