from util import compiler, log, options, palettes, symbols


def init(target_bytes: bytes):
    symbols.spim_context.fillDefaultBannedSymbols()

    if options.opts.libultra_symbols:
        symbols.spim_context.globalSegment.fillLibultraSymbols()
    if options.opts.hardware_regs:
        symbols.spim_context.globalSegment.fillHardwareRegs(True)
