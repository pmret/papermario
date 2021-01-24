class N64Symbol:

    @staticmethod
    def get_default_name(vram):
        return f"D_{vram:X}"

    def __init__(self, vram, rom=None, name=None, segment=None, length=4):
        self.vram = vram
        self.rom = rom
        self.name = name if name else self.get_default_name(vram)
        self.segment = segment
        self.length = length
