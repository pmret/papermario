"""
N64 f3dex display list splitter
Dumps out Gfx[] as a .inc.c file.
"""

from pathlib import Path
from pygfxd import *
from util import log
from util.log import error

from util import options
from segtypes.common.codesubsegment import CommonSegCodeSubsegment


class N64SegGfx(CommonSegCodeSubsegment):
    def __init__(
        self,
        rom_start,
        rom_end,
        type,
        name,
        vram_start,
        extract,
        given_subalign,
        exclusive_ram_id,
        given_dir,
        symbol_name_format,
        symbol_name_format_no_rom,
        args,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            extract,
            given_subalign,
            exclusive_ram_id=exclusive_ram_id,
            given_dir=given_dir,
            symbol_name_format=symbol_name_format,
            symbol_name_format_no_rom=symbol_name_format_no_rom,
            args=args,
            yaml=yaml,
        )
        self.file_text = None

    def get_linker_section(self) -> str:
        return ".data"

    def out_path(self) -> Path:
        return options.get_asset_path() / self.dir / f"{self.name}.gfx.inc.c"

    def scan(self, rom_bytes: bytes):
        self.file_text = self.disassemble_data(rom_bytes)

    def get_gfxd_target(self):
        opt = options.get_gfx_ucode()

        if opt == "f3d":
            return gfxd_f3d  # type: ignore
        elif opt == "f3db":
            return gfxd_f3db  # type: ignore
        elif opt == "f3dex":
            return gfxd_f3dex  # type: ignore
        elif opt == "f3dexb":
            return gfxd_f3dexb  # type: ignore
        elif opt == "f3dex2":
            return gfxd_f3dex2  # type: ignore
        else:
            log.error(f"Unknown target {opt}")

    def tlut_handler(self, addr, idx, count):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def timg_handler(self, addr, fmt, size, width, height, pal):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def cimg_handler(self, addr, fmt, size, width):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def zimg_handler(self, addr):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def dl_handler(self, addr):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def mtx_handler(self, addr):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def lookat_handler(self, addr, count):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def light_handler(self, addr, count):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def vtx_handler(self, addr, count):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def vp_handler(self, addr):
        sym = self.create_symbol(
            addr=addr, in_segment=True, type="data", reference=True
        )
        gfxd_printf(sym.name)
        return 1

    def macro_fn(self):
        gfxd_puts("    ")
        gfxd_macro_dflt()
        gfxd_puts(",\n")
        return 0

    def disassemble_data(self, rom_bytes):
        gfx_data = rom_bytes[self.rom_start : self.rom_end]
        segment_length = len(gfx_data)
        if (segment_length) % 8 != 0:
            error(
                f"Error: gfx segment {self.name} length ({segment_length}) is not a multiple of 8!"
            )

        out_str = options.get_generated_c_premble() + "\n\n"

        sym = self.create_symbol(
            addr=self.vram_start, in_segment=True, type="data", define=True
        )

        gfxd_input_buffer(gfx_data)

        # TODO terrible guess at the size we'll need - improve this
        outb = bytes([0] * segment_length * 100)
        outbuf = gfxd_output_buffer(outb, len(outb))

        gfxd_target(self.get_gfxd_target())
        gfxd_endian(
            GfxdEndian.big if options.get_endianess() == "big" else GfxdEndian.little, 4
        )

        # Callbacks
        gfxd_macro_fn(self.macro_fn)

        gfxd_tlut_callback(self.tlut_handler)
        gfxd_timg_callback(self.timg_handler)
        gfxd_cimg_callback(self.cimg_handler)
        gfxd_zimg_callback(self.zimg_handler)
        gfxd_dl_callback(self.dl_handler)
        gfxd_mtx_callback(self.mtx_handler)
        gfxd_lookat_callback(self.lookat_handler)
        gfxd_light_callback(self.light_handler)
        # gfxd_seg_callback ?
        gfxd_vtx_callback(self.vtx_handler)
        gfxd_vp_callback(self.vp_handler)
        # gfxd_uctext_callback ?
        # gfxd_ucdata_callback ?
        # gfxd_dram_callback ?

        gfxd_execute()
        out_str += "Gfx " + sym.name + "[] = {\n"
        out_str += gfxd_buffer_to_string(outbuf)
        out_str += "};\n"
        return out_str

    def split(self, rom_bytes: bytes):
        if self.file_text and self.out_path():
            self.out_path().parent.mkdir(parents=True, exist_ok=True)

            with open(self.out_path(), "w", newline="\n") as f:
                f.write(self.file_text)

    def should_scan(self) -> bool:
        return (
            options.mode_active("gfx")
            and self.rom_start != "auto"
            and self.rom_end != "auto"
        )

    def should_split(self) -> bool:
        return self.extract and options.mode_active("gfx")
