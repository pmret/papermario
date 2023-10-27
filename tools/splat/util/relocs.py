from dataclasses import dataclass
from typing import Dict

import spimdisasm

from util import log, options, symbols, progress_bar


@dataclass
class Reloc:
    rom_address: int
    reloc_type: str
    symbol_name: str

    addend: int = 0


all_relocs: Dict[int, Reloc] = {}


def add_reloc(reloc: Reloc):
    all_relocs[reloc.rom_address] = reloc


def initialize():
    global all_relocs

    all_relocs = {}

    for path in options.opts.reloc_addrs_paths:
        if not path.exists():
            continue

        with path.open() as f:
            sym_addrs_lines = f.readlines()

        prog_bar = progress_bar.get_progress_bar(sym_addrs_lines)
        prog_bar.set_description(f"Loading relocs ({path.stem})")
        line: str
        for line_num, line in enumerate(prog_bar):
            line = line.strip()
            # Allow comments
            line = line.split("//")[0]
            line = line.strip()

            if line == "":
                continue

            rom_addr = None
            reloc_type = None
            symbol_name = None
            addend = None

            for info in line.split(" "):
                if ":" not in info:
                    continue

                if info.count(":") > 1:
                    log.parsing_error_preamble(path, line_num, line)
                    log.write(f"Too many ':'s in '{info}'")
                    log.error("")

                attr_name, attr_val = info.split(":")
                if attr_name == "":
                    log.parsing_error_preamble(path, line_num, line)
                    log.write(
                        f"Missing attribute name in '{info}', is there extra whitespace?"
                    )
                    log.error("")
                if attr_val == "":
                    log.parsing_error_preamble(path, line_num, line)
                    log.write(
                        f"Missing attribute value in '{info}', is there extra whitespace?"
                    )
                    log.error("")

                # Non-Boolean attributes
                try:
                    if attr_name == "rom":
                        rom_addr = int(attr_val, 0)
                        continue
                    if attr_name == "reloc":
                        reloc_type = attr_val
                        continue
                    if attr_name == "symbol":
                        symbol_name = attr_val
                        continue
                    if attr_name == "addend":
                        addend = int(attr_val, 0)
                        continue
                except:
                    log.parsing_error_preamble(path, line_num, line)
                    log.write(f"value of attribute '{attr_name}' could not be read:")
                    log.write("")
                    raise

            if rom_addr is None:
                log.parsing_error_preamble(path, line_num, line)
                log.error(f"Missing required 'rom' attribute for reloc")
            if reloc_type is None:
                log.parsing_error_preamble(path, line_num, line)
                log.error(f"Missing required 'reloc' attribute for reloc")
            if symbol_name is None:
                log.parsing_error_preamble(path, line_num, line)
                log.error(f"Missing required 'symbol' attribute for reloc")

            reloc = Reloc(rom_addr, reloc_type, symbol_name)
            if addend is not None:
                reloc.addend = addend

            if reloc.rom_address in all_relocs:
                log.parsing_error_preamble(path, line_num, line)
                log.error(
                    f"Duplicated 'rom' address for reloc: 0x{reloc.rom_address:X}"
                )
            add_reloc(reloc)


def initialize_spim_context():
    for rom_address, reloc in all_relocs.items():
        reloc_type = spimdisasm.common.RelocType.fromStr(reloc.reloc_type)

        if reloc_type is None:
            log.error(
                f"Reloc type '{reloc.reloc_type}' is not valid. Rom address: 0x{rom_address:X}"
            )

        symbols.spim_context.addGlobalReloc(
            rom_address, reloc_type, reloc.symbol_name, addend=reloc.addend
        )
