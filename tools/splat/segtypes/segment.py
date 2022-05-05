import importlib
import importlib.util

from typing import Dict, TYPE_CHECKING, Type, Union, Optional, List
from pathlib import Path

from util import log
from util import options
from util import symbols
from util.symbols import Symbol

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


def parse_segment_section_order(segment: Union[dict, list]) -> List[str]:
    default = options.get_section_order()
    if isinstance(segment, dict):
        return segment.get("section_order", default)
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
        is_platform_seg = False

        # heirarchy is platform -> common -> fail
        try:
            segmodule = importlib.import_module(f"segtypes.{platform}.{seg_type}")
            is_platform_seg = True
        except ModuleNotFoundError:
            try:
                segmodule = importlib.import_module(f"segtypes.common.{seg_type}")
            except ModuleNotFoundError:
                return None

        seg_prefix = platform.capitalize() if is_platform_seg else "Common"
        return getattr(segmodule, f"{seg_prefix}Seg{seg_type.capitalize()}")

    @staticmethod
    def get_extension_segment_class(seg_type):
        platform = options.get_platform()

        ext_path = options.get_extensions_path()
        if not ext_path:
            log.error(
                f"could not load presumed extended segment type '{seg_type}' because no extensions path is configured"
            )

        try:
            ext_spec = importlib.util.spec_from_file_location(
                f"{platform}.segtypes.{seg_type}", ext_path / f"{seg_type}.py"
            )
            ext_mod = importlib.util.module_from_spec(ext_spec)
            ext_spec.loader.exec_module(ext_mod)
        except Exception as err:
            log.write(err, status="error")
            log.error(
                f"could not load segment type '{seg_type}'\n(hint: confirm your extension directory is configured correctly)"
            )

        return getattr(
            ext_mod, f"{platform.upper()}Seg{seg_type[0].upper()}{seg_type[1:]}"
        )

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

    @staticmethod
    def parse_segment_name(cls, rom_start, segment: Union[dict, list]) -> str:
        if isinstance(segment, dict) and "name" in segment:
            return str(segment["name"])
        elif isinstance(segment, dict) and "dir" in segment:
            return str(segment["dir"])
        elif isinstance(segment, list) and len(segment) >= 3:
            return str(segment[2])
        else:
            return str(cls.get_default_name(rom_start))

    def __init__(
        self,
        rom_start,
        rom_end,
        type,
        name,
        vram_start,
        extract=True,
        given_subalign=options.get_subalign(),
        given_is_overlay: Optional[bool] = False,
        given_dir: Path = Path(),
        args=[],
        yaml={},
    ):
        self.rom_start = rom_start
        self.rom_end = rom_end
        self.type = type
        self.name = name
        self.vram_start = vram_start
        self.extract = extract

        self.given_subalign = given_subalign
        self.given_is_overlay = given_is_overlay
        self.given_dir = given_dir
        self.given_seg_symbols: Dict[
            int, List[Symbol]
        ] = {}  # Symbols known to be in this segment
        self.given_ext_symbols: Dict[
            int, List[Symbol]
        ] = (
            {}
        )  # Symbols not in this segment but also not from other overlapping ram address ranges
        self.given_section_order: List[str] = options.get_section_order()

        self.parent: Optional[Segment] = None
        self.sibling: Optional[Segment] = None

        self.args: List[str] = args
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
                log.error(
                    f"Error: segments out of order - ({self.name} starts at 0x{self.rom_start:X}, but next segment starts at 0x{self.rom_end:X})"
                )

    @staticmethod
    def from_yaml(
        cls: Type["Segment"],
        yaml: Union[dict, list],
        rom_start: RomAddr,
        rom_end: RomAddr,
        vram=None,
    ):
        type = Segment.parse_segment_type(yaml)
        name = Segment.parse_segment_name(cls, rom_start, yaml)
        vram_start = vram if vram is not None else parse_segment_vram(yaml)
        extract = bool(yaml.get("extract", True)) if isinstance(yaml, dict) else True
        given_subalign = parse_segment_subalign(yaml)
        given_is_overlay: Optional[bool] = (
            yaml.get("overlay", False) if isinstance(yaml, dict) else False
        )
        given_dir = Path(yaml.get("dir", "")) if isinstance(yaml, dict) else Path()
        args: List[str] = [] if isinstance(yaml, dict) else yaml[3:]

        ret = cls(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            extract,
            given_subalign,
            given_is_overlay,
            given_dir,
            args,
            yaml,
        )
        cls.given_section_order = parse_segment_section_order(yaml)
        return ret

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
    def seg_symbols(self) -> Dict[int, List[Symbol]]:
        if self.parent:
            return self.parent.seg_symbols
        else:
            return self.given_seg_symbols

    @property
    def ext_symbols(self) -> Dict[int, List[Symbol]]:
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

    @property
    def section_order(self) -> List[str]:
        return self.given_section_order

    @property
    def rodata_follows_data(self) -> bool:
        if ".rodata" not in self.section_order or ".data" not in self.section_order:
            return False
        return (
            self.section_order.index(".rodata") - self.section_order.index(".data") == 1
        )

    @property
    def text_follows_rodata(self) -> bool:
        if ".text" not in self.section_order or ".rodata" not in self.section_order:
            return False
        return (
            self.section_order.index(".text") - self.section_order.index(".rodata") == 1
        )

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

    def get_most_parent(self) -> "Segment":
        seg = self

        while seg.parent:
            seg = seg.parent

        return seg

    def get_linker_entries(self) -> "List[LinkerEntry]":
        from segtypes.linker_entry import LinkerEntry

        path = self.out_path()

        if path:
            return [LinkerEntry(self, [path], path, self.get_linker_section())]
        else:
            return []

    def log(self, msg):
        if options.verbose():
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

    def retrieve_symbol(self, d, k, t):
        if k not in d:
            return None

        if t:
            items = [s for s in d[k] if s.type == t or s.type == "unknown"]
        else:
            items = d[k]

        if len(items) > 1:
            pass  # print(f"Trying to retrieve {k:X} from symbol dict but there are {len(items)} entries to pick from - picking the first")
        if len(items) == 0:
            return None
        return items[0]

    def get_symbol(
        self,
        addr,
        type=None,
        create=False,
        define=False,
        reference=False,
        offsets=False,
        local_only=False,
        dead=True,
    ) -> Optional[Symbol]:
        ret = None
        rom = None

        in_segment = self.contains_vram(addr)

        if in_segment:
            # If the vram address is within this segment, we can calculate the symbol's rom address
            rom = self.ram_to_rom(addr)
            ret = self.retrieve_symbol(self.seg_symbols, addr, type)
        elif not local_only:
            ret = self.retrieve_symbol(self.ext_symbols, addr, type)

        # Search for symbol ranges
        if not ret and offsets:
            ret = symbols.retrieve_from_ranges(addr, rom)

        # Reject dead symbols unless we allow them
        if not dead and ret and ret.dead:
            ret = None

        # Create the symbol if it doesn't exist
        if not ret and create:
            ret = Symbol(addr, rom=rom, type=type)
            symbols.all_symbols.append(ret)

            if in_segment:
                if self.is_overlay:
                    ret.in_overlay = True
                if addr not in self.seg_symbols:
                    self.seg_symbols[addr] = []
                self.seg_symbols[addr].append(ret)
            elif not local_only:
                if addr not in self.ext_symbols:
                    self.ext_symbols[addr] = []
                self.ext_symbols[addr].append(ret)

        if ret:
            if define:
                ret.defined = True
            if reference:
                ret.referenced = True

        return ret

    def create_symbol(
        self,
        addr,
        type=None,
        define=False,
        reference=False,
        offsets=False,
        local_only=False,
        dead=True,
    ) -> Symbol:
        ret = self.get_symbol(
            addr,
            type=type,
            create=True,
            define=define,
            reference=reference,
            offsets=offsets,
            local_only=local_only,
            dead=dead,
        )
        assert ret is not None

        return ret

    def get_func_for_addr(self, addr) -> Optional[Symbol]:
        for syms in self.seg_symbols.values():
            for sym in syms:
                if sym.type == "func" and sym.contains_vram(addr):
                    return sym

        return None
