import n64img.image

from segtypes.n64.img import N64SegImg


class N64SegI1(N64SegImg):
    def __init__(self, *args, **kwargs):
        kwargs["img_cls"] = n64img.image.I1
        super().__init__(*args, **kwargs)
