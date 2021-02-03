class Symbol:

    @property
    def default_name(self):
        suffix = f"_{self.vram_start:X}"

        if self.in_overlay:
            suffix += f"_{self.rom:X}"

        if self.type == "func":
            prefix = "func"
        elif self.type =="jtbl":
            prefix = "jtbl"
        else:
            prefix = "D"

        return prefix + suffix

    @property
    def rom_end(self):
        return None if not self.rom else self.rom + self.size

    @property
    def vram_end(self):
        return self.vram_start + self.size

    def set_in_overlay(self):
        self.in_overlay = True

    @property
    def name(self):
        return self.given_name if self.given_name else self.default_name

    def contains_vram(self, offset):
        return offset >= self.vram_start and offset < self.vram_end

    def __init__(self, vram, given_name=None, rom=None, type="unknown", in_overlay=False, size=4):
        self.defined = False
        self.referenced = False
        self.vram_start = vram
        self.rom = rom
        self.type = type
        self.in_overlay = in_overlay
        self.size = size
        self.given_name = given_name
        self.access_mnemonic = None
