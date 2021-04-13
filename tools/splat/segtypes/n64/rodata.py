from segtypes.n64.data import N64SegData

class N64SegRodata(N64SegData):    
    def get_linker_section(self) -> str:
        return ".rodata"

    def scan(self, rom_bytes: bytes):
        self.file_text = self.disassemble_data(rom_bytes)

    def split(self, rom_bytes: bytes):
        if self.file_text:
            path = self.out_path()
            
            if path:
                path.parent.mkdir(parents=True, exist_ok=True)

                with open(path, "w", newline="\n") as f:
                    f.write(self.file_text)
