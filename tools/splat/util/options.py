from typing import Dict, List, Optional
from pathlib import Path
from util import log

opts = {}

def initialize(config: Dict, config_path: str, base_path=None, target_path=None):
    global opts
    opts = dict(config.get("options", {}))

    if base_path:
        opts["base_path"] = Path(base_path)
    else:
        if not "base_path" in opts:
            log.error("Error: Base output dir not specified as a command line arg or via the config yaml (base_path)")

        opts["base_path"] = Path(config_path).parent / opts["base_path"]

    if not target_path:
        if "target_path" not in opts:
            log.error("Error: Target binary path not specified as a command line arg or via the config yaml (target_path)")

def set(opt, val):
    opts[opt] = val

def get(opt, default=None):
    return opts.get(opt, default)

def get_platform() -> str:
    return opts.get("platform", "n64")

def get_compiler() -> str:
    return opts.get("compiler", "IDO")

def get_header_encoding() -> str:
    return opts.get("header_encoding", "ASCII")

def get_subalign() -> int:
    return opts.get("subalign", 16)

def get_generated_c_premble() -> str:
    return opts.get("generated_c_preamble", '#include "common.h"')

def mode_active(mode):
    return mode in opts["modes"] or "all" in opts["modes"]

def get_base_path() -> Path:
    return Path(opts["base_path"])

def get_asset_path() -> Path:
    return Path(get_base_path() / opts.get("asset_path", "assets")).relative_to(get_base_path())

def get_target_path() -> Path:
    return get_base_path() / opts["target_path"]

def get_src_path() -> Path:
    return get_base_path() / opts.get("src_path", "src")

def get_asm_path() -> Path:
    return get_base_path() / opts.get("asm_path", "asm")

def get_cache_path():
    return get_base_path() / opts.get("cache_path", ".splat_cache")

def get_create_undefined_funcs_auto() -> bool:
    return opts.get("create_undefined_funcs_auto", True)

def get_undefined_funcs_auto_path():
    return get_base_path() / opts.get("undefined_funcs_auto_path", "undefined_funcs_auto.txt")

def get_create_undefined_syms_auto() -> bool:
    return opts.get("create_undefined_syms_auto", True)

def get_undefined_syms_auto_path():
    return get_base_path() / opts.get("undefined_syms_auto_path", "undefined_syms_auto.txt")

def get_symbol_addrs_path():
    return get_base_path() / opts.get("symbol_addrs_path", "symbol_addrs.txt")

def get_build_path():
    # TODO maybe can just return build_path...
    return Path(get_base_path() / opts.get("build_path", "build")).relative_to(get_base_path())

def get_ld_script_path():
    return get_base_path() / opts.get("ld_script_path", f"{opts.get('basename')}.ld")

def get_linker_symbol_header_path() -> Optional[Path]:
    if "linker_symbol_header_path" in opts:
        return get_base_path() / str(opts["linker_symbol_header_path"])
    else:
        return None

def get_extensions_path():
    ext_opt = opts.get("extensions_path")
    if not ext_opt:
        return None

    return get_base_path() / ext_opt
