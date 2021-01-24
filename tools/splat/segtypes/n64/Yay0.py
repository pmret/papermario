import os
from segtypes.n64.segment import N64Segment
from util.n64 import Yay0decompress

class N64SegYay0(N64Segment):
    def split(self, rom_bytes, base_path):
        out_dir = self.create_parent_dir(base_path + "/bin", self.name)

        path = os.path.join(out_dir, os.path.basename(self.name) + ".bin")
        with open(path, "wb") as f:
            self.log(f"Decompressing {self.name}...")
            compressed_bytes = rom_bytes[self.rom_start : self.rom_end]
            decompressed_bytes = Yay0decompress.decompress_yay0(compressed_bytes)
            f.write(decompressed_bytes)
        self.log(f"Wrote {self.name} to {path}")


    def get_ld_files(self):
        return [("bin", f"{self.name}.Yay0", ".data", self.rom_start)]


    @staticmethod
    def get_default_name(addr):
        return "Yay0/{:X}".format(addr)
