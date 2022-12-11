import n64img.image

from segtypes.n64.ci import N64SegCi


class N64SegCi8(N64SegCi):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs, img_cls=n64img.image.CI8)
