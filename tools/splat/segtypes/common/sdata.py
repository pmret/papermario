from segtypes.common.data import CommonSegData


class CommonSegSdata(CommonSegData):
    def get_linker_section(self) -> str:
        return ".sdata"
