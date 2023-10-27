from util import options, symbols


def init(target_bytes: bytes):
    symbols.spim_context.fillDefaultBannedSymbols()

    if options.opts.libultra_symbols:
        symbols.spim_context.globalSegment.fillLibultraSymbols()
    if options.opts.ique_symbols:
        symbols.spim_context.globalSegment.fillIQueSymbols()
    if options.opts.hardware_regs:
        symbols.spim_context.globalSegment.fillHardwareRegs(True)
