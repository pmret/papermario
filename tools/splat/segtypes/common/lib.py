from segtypes.n64.segment import N64Segment
from segtypes.linker_entry import LinkerEntry

from util import options, log


class CommonSegLib(N64Segment):
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

        if isinstance(yaml, dict):
            log.error("Error: 'dict' not currently supported for 'lib' segment")
            return
        if len(args) < 1:
            log.error(f"Error: {self.name} is missing object file")
            return

        self.extract = False

        if len(args) > 1:
            self.object, self.section = args[0], args[1]
        else:
            self.object, self.section = args[0], ".text"

    def get_linker_section(self) -> str:
        return self.section

    def get_linker_entries(self):
        path = options.get_lib_path() / self.name

        object_path = f"{path}.a:{self.object}.o"

        return [LinkerEntry(self, [path], object_path, self.get_linker_section())]
