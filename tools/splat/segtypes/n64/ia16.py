from segtypes.n64.img import N64SegImg
import n64img.image


class N64SegIa16(N64SegImg):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs, img_cls=n64img.image.IA16)
