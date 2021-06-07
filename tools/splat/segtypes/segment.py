import importlib
from typing import Dict, TYPE_CHECKING, Union, Optional, List
from pathlib import Path

import yaml
from util import log
from util import options
from util.symbols import Symbol
import sys

# circular import
if TYPE_CHECKING:
    from segtypes.linker_entry import LinkerEntry

RomAddr = Union[int, str]


def parse_segment_vram(segment: Union[dict, list]) -> Optional[int]:
    if isinstance(segment, dict) and "vram" in segment:
        return int(segment["vram"])
    else:
        return None


def parse_segment_subalign(segment: Union[dict, list]) -> int:
    default = options.get_subalign()
    if isinstance(segment, dict):
        return int(segment.get("subalign", default))
    return default


class Segment:
    require_unique_name = True

    @staticmethod
    def get_class_for_type(seg_type):
        # so .data loads SegData, for example
        if seg_type.startswith("."):
            seg_type = seg_type[1:]

        segment_class = Segment.get_base_segment_class(seg_type)
        if segment_class == None:
            # Look in extensions
            segment_class = Segment.get_extension_segment_class(seg_type)
        return segment_class

    @staticmethod
    def get_base_segment_class(seg_type):
        platform = options.get_platform()

        try:
            segmodule = importlib.import_module(f"segtypes.{platform}.{seg_type}")
        except ModuleNotFoundError:
            return None

        return getattr(segmodule, f"{platform.upper()}Seg{seg_type[0].upper()}{seg_type[1:]}")

    @staticmethod
    def get_extension_segment_class(seg_type):
        platform = options.get_platform()

        ext_path = options.get_extensions_path()
        if not ext_path:
            log.error(f"could not load presumed extended segment type '{seg_type}' because no extensions path is configured")

        try:
            ext_spec = importlib.util.spec_from_file_location(f"{platform}.segtypes.{seg_type}", ext_path / f"{seg_type}.py")
            ext_mod = importlib.util.module_from_spec(ext_spec)
            ext_spec.loader.exec_module(ext_mod)
        except Exception as err:
            log.write(err, status="error")
            log.error(f"could not load segment type '{seg_type}'\n(hint: confirm your extension directory is configured correctly)")

        return getattr(ext_mod, f"{platform.upper()}Seg{seg_type[0].upper()}{seg_type[1:]}")

    @staticmethod
    def parse_segment_start(segment: Union[dict, list]) -> RomAddr:
        if isinstance(segment, dict):
            s = segment.get("start", "auto")
        else:
            s = segment[0]

        if s == "auto":
            return "auto"
        else:
            return int(s)

    @staticmethod
    def parse_segment_type(segment: Union[dict, list]) -> str:
        if isinstance(segment, dict):
            return str(segment["type"])
        else:
            return str(segment[1])
        
    def parse_segment_name(self, rom_start, segment: Union[dict, list]) -> str:
        if isinstance(segment, dict) and "name" in segment:
            return str(segment["name"])
        elif isinstance(segment, dict) and "dir" in segment:
            return str(segment["dir"])
        elif isinstance(segment, list) and len(segment) >= 3:
            return str(segment[2])
        else:
            return str(self.get_default_name(rom_start))

    def __init__(self, rom_start, rom_end, type, name, vram_start, extract = True, 
                 given_subalign = options.get_subalign(), given_is_overlay: Optional[bool] = False, given_dir: Path = Path(), args = [], yaml: yaml = {}):
        self.rom_start = rom_start
        self.rom_end = rom_end
        self.type = type
        self.name = name
        self.vram_start = vram_start
        self.extract = extract

        self.given_subalign = given_subalign
        self.given_is_overlay = given_is_overlay
        self.given_dir = given_dir
        self.given_seg_symbols: Dict[int, Symbol] = {} # Symbols known to be in this segment
        self.given_ext_symbols: Dict[int, Symbol] = {} # Symbols not in this segment but also not from other overlapping ram address ranges

        self.parent:Optional[Segment] = None
        self.sibling:Optional[Segment] = None

        self.args:List[str] = args
        self.yaml = yaml

        if "skip" in self.args:
            self.extract = False

        if self.rom_start == "auto":
            self.extract = False
        
        if self.type.startswith("."):
            self.extract = False

        self.warnings: List[str] = []
        self.did_run = False

        if isinstance(self.rom_start, int) and isinstance(self.rom_end, int):
            if self.rom_start > self.rom_end:
                print(f"Error: segments out of order - ({self.name} starts at 0x{self.rom_start:X}, but next segment starts at 0x{self.rom_end:X})")
                sys.exit(1)

    @classmethod
    def from_yaml(cls, segment: Union[dict, list], rom_start: RomAddr, rom_end: RomAddr):
        type = Segment.parse_segment_type(segment)
        name = cls.parse_segment_name(cls, rom_start, segment)
        vram_start = parse_segment_vram(segment)
        extract = bool(segment.get("extract", True)) if isinstance(segment, dict) else True
        given_subalign = parse_segment_subalign(segment)
        given_is_overlay:Optional[bool] = segment.get("overlay", False) if isinstance(segment, dict) else False
        given_dir = Path(segment.get("dir", "")) if isinstance(segment, dict) else Path()
        args:List[str] = [] if isinstance(segment, dict) else segment[3:]

        return cls(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, segment)
    
    @property
    def needs_symbols(self) -> bool:
        return False

    @property
    def dir(self) -> Path:
        if self.parent:
            return self.parent.dir / self.given_dir
        else:
            return self.given_dir
    
    @property
    def subalign(self) -> int:
        if self.parent:
            return self.parent.subalign
        else:
            return self.given_subalign
    
    @property
    def is_overlay(self) -> bool:
        if self.parent:
            return self.parent.is_overlay
        if self.given_is_overlay is not None:
            return self.given_is_overlay
        return False

    @property
    def seg_symbols(self) -> Dict[int, Symbol]:
        if self.parent:
            return self.parent.seg_symbols
        else:
            return self.given_seg_symbols

    @property
    def ext_symbols(self) -> Dict[int, Symbol]:
        if self.parent:
            return self.parent.ext_symbols
        else:
            return self.given_ext_symbols

    @property
    def size(self) -> Optional[int]:
        if isinstance(self.rom_start, int) and isinstance(self.rom_end, int):
            return self.rom_end - self.rom_start
        else:
            return None

    @property
    def vram_end(self) -> Optional[int]:
        if self.vram_start is not None and self.size is not None:
            return self.vram_start + self.size
        else:
            return None

    def contains_vram(self, vram: int) -> bool:
        if self.vram_start is not None and self.vram_end is not None:
            return vram >= self.vram_start and vram < self.vram_end
        else:
            return False

    def contains_rom(self, rom: int) -> bool:
        if isinstance(self.rom_start, int) and isinstance(self.rom_end, int):
            return rom >= self.rom_start and rom < self.rom_end
        else:
            return False

    def rom_to_ram(self, rom_addr: int) -> Optional[int]:
        if not self.contains_rom(rom_addr) and rom_addr != self.rom_end:
            return None

        if self.vram_start is not None and isinstance(self.rom_start, int):
            return self.vram_start + rom_addr - self.rom_start
        else:
            return None

    def ram_to_rom(self, ram_addr: int) -> Optional[int]:
        if not self.contains_vram(ram_addr) and ram_addr != self.vram_end:
            return None

        if self.vram_start is not None and isinstance(self.rom_start, int):
            return self.rom_start + ram_addr - self.vram_start
        else:
            return None

    def should_scan(self) -> bool:
        return self.should_split()
    
    def should_split(self) -> bool:
        return self.extract and options.mode_active(self.type)
    
    def scan(self, rom_bytes: bytes):
        pass

    def split(self, rom_bytes: bytes):
        pass

    def cache(self):
        return (self.yaml, self.rom_end)

    def get_linker_section(self) -> str:
        return ".data"

    def out_path(self) -> Optional[Path]:
        return None

    def get_linker_entries(self) -> "List[LinkerEntry]":
        from segtypes.linker_entry import LinkerEntry

        path = self.out_path()

        if path:
            return [LinkerEntry(self, [path], path, self.get_linker_section())]
        else:
            return []

    def log(self, msg):
        if options.get("verbose", False):
            log.write(f"{self.type} {self.name}: {msg}")

    def warn(self, msg: str):
        self.warnings.append(msg)

    def max_length(self):
        return None

    def is_name_default(self):
        return self.name == self.get_default_name(self.rom_start)

    def unique_id(self):
        if self.parent:
            s = self.parent.unique_id() + "_"
        else:
            s = ""

        return s + self.type + "_" + self.name

    def status(self):
        if len(self.warnings) > 0:
            return "warn"
        elif self.did_run:
            return "ok"
        else:
            return "skip"

    @staticmethod
    def get_default_name(addr) -> str:
        return f"{addr:X}"
