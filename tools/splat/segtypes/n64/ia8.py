import n64img.image

from segtypes.n64.img import N64SegImg


class N64SegIa8(N64SegImg):
    def __init__(self, *args, **kwargs):
        kwargs["img_cls"] = n64img.image.IA8
        super().__init__(*args, **kwargs)
