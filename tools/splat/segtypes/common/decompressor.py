from typing import Optional, Any

from util import log, options
from util.n64.decompressor import Decompressor

from segtypes.n64.segment import N64Segment


class CommonSegDecompressor(N64Segment):
    decompressor: Decompressor
    compression_type = ""  # "Mio0" -> filename.Mio0.o

    def split(self, rom_bytes):
        if self.decompressor is None:
            log.error("Decompressor is not a standalone segment type")

        out_dir = options.opts.asset_path / self.dir
        out_dir.mkdir(parents=True, exist_ok=True)

        if self.rom_end is None:
            log.error(
                f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
            )

        out_path = out_dir / f"{self.name}.bin"
        with open(out_path, "wb") as f:
            assert isinstance(self.rom_start, int)
            assert isinstance(self.rom_end, int)

            self.log(f"Decompressing {self.name}")
            compressed_bytes = rom_bytes[self.rom_start : self.rom_end]
            decompressed_bytes = self.decompressor.decompress(compressed_bytes)
            f.write(decompressed_bytes)
        self.log(f"Wrote {self.name} to {out_path}")

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        return [
            LinkerEntry(
                self,
                [options.opts.asset_path / self.dir / f"{self.name}.bin"],
                options.opts.asset_path
                / self.dir
                / f"{self.name}.{self.compression_type}",
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                self.is_noload(),
            )
        ]
