from segtypes.common.c import CommonSegC


class CommonSegCpp(CommonSegC):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.file_extension = "cpp"
