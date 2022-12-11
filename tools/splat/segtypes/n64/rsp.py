import rabbitizer

from segtypes.common.hasm import CommonSegHasm


class N64SegRsp(CommonSegHasm):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.instr_category = rabbitizer.InstrCategory.RSP
