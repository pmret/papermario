from segtypes.n64.ia4 import N64SegIa4
from util import iter


class N64SegIa16(N64SegIa4):
    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        data = rom_bytes[self.rom_start : self.rom_end]

        w = self.__class__.get_writer(self.width, self.height)
        with open(path, "wb") as f:
            w.write_array(f, data)

        self.log(f"Wrote {self.name} to {path}")

    def max_length(self):
        return self.width * self.height * 2
