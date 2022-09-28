from segtypes.common.rodata import CommonSegRodata


class CommonSegRdata(CommonSegRodata):
    def get_linker_section(self) -> str:
        return ".rdata"
