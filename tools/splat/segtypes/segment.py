import importlib
import importlib.util
from pathlib import Path

from typing import Dict, List, Optional, Set, Type, TYPE_CHECKING, Union

from intervaltree import Interval, IntervalTree
from util import vram_classes

from util.vram_classes import VramClass
from util import log, options, symbols
from util.symbols import Symbol, to_cname

# circular import
if TYPE_CHECKING:
    from segtypes.linker_entry import LinkerEntry


def parse_segment_vram(segment: Union[dict, list]) -> Optional[int]:
    if isinstance(segment, dict) and "vram" in segment:
        return int(segment["vram"])
    else:
        return None


def parse_segment_vram_symbol(segment: Union[dict, list]) -> Optional[str]:
    if isinstance(segment, dict) and "vram_symbol" in segment:
        return str(segment["vram_symbol"])
    else:
        return None


def parse_segment_vram_class(segment: Union[dict, list]) -> Optional[VramClass]:
    if isinstance(segment, dict) and "vram_class" in segment:
        return vram_classes.resolve(segment["vram_class"])
    return None


def parse_segment_follows_vram(segment: Union[dict, list]) -> Optional[str]:
    if isinstance(segment, dict):
        return segment.get("follows_vram", None)
    return None


def parse_segment_align(segment: Union[dict, list]) -> Optional[int]:
    if isinstance(segment, dict) and "align" in segment:
        return int(segment["align"])
    return None


def parse_segment_subalign(segment: Union[dict, list]) -> int:
    default = options.opts.subalign
    if isinstance(segment, dict):
        subalign = segment.get("subalign", default)
        if subalign != None:
            subalign = int(subalign)
        return subalign
    return default


def parse_segment_section_order(segment: Union[dict, list]) -> List[str]:
    default = options.opts.section_order
    if isinstance(segment, dict):
        return segment.get("section_order", default)
    return default


class Segment:
    require_unique_name = True

    @staticmethod
    def get_class_for_type(seg_type) -> Type["Segment"]:
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
        platform = options.opts.platform
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
        platform = options.opts.platform

        ext_path = options.opts.extensions_path
        if not ext_path:
            log.error(
                f"could not load presumed extended segment type '{seg_type}' because no extensions path is configured"
            )
        assert ext_path is not None

        try:
            ext_spec = importlib.util.spec_from_file_location(
                f"{platform}.segtypes.{seg_type}", ext_path / f"{seg_type}.py"
            )
            assert ext_spec is not None
            ext_mod = importlib.util.module_from_spec(ext_spec)
            assert ext_spec.loader is not None
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
    def parse_segment_start(segment: Union[dict, list]) -> Optional[int]:
        if isinstance(segment, dict):
            s = segment.get("start", "auto")
        else:
            s = segment[0]

        if s == "auto":
            return None
        elif s == "...":
            return None
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

    @staticmethod
    def parse_segment_symbol_name_format(segment: Union[dict, list]) -> str:
        if isinstance(segment, dict) and "symbol_name_format" in segment:
            return str(segment["symbol_name_format"])
        else:
            return options.opts.symbol_name_format

    @staticmethod
    def parse_segment_symbol_name_format_no_rom(segment: Union[dict, list]) -> str:
        if isinstance(segment, dict) and "symbol_name_format_no_rom" in segment:
            return str(segment["symbol_name_format_no_rom"])
        else:
            return options.opts.symbol_name_format_no_rom

    @staticmethod
    def parse_segment_file_path(segment: Union[dict, list]) -> Optional[Path]:
        if isinstance(segment, dict) and "path" in segment:
            return Path(segment["path"])
        return None

    @staticmethod
    def parse_segment_bss_contains_common(segment: Union[dict, list]) -> bool:
        if isinstance(segment, dict) and "bss_contains_common" in segment:
            return bool(segment["bss_contains_common"])
        else:
            return False

    @staticmethod
    def parse_linker_section_order(yaml: Union[dict, list]) -> Optional[str]:
        if isinstance(yaml, dict) and "linker_section_order" in yaml:
            return str(yaml["linker_section_order"])
        return None

    @staticmethod
    def parse_linker_section(yaml: Union[dict, list]) -> Optional[str]:
        if isinstance(yaml, dict) and "linker_section" in yaml:
            return str(yaml["linker_section"])
        return None

    @staticmethod
    def parse_ld_fill_value(
        yaml: Union[dict, list], default: Optional[int]
    ) -> Optional[int]:
        if isinstance(yaml, dict) and "ld_fill_value" in yaml:
            return yaml["ld_fill_value"]
        return default

    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
    ):
        self.rom_start = rom_start
        self.rom_end = rom_end
        self.type = type
        self.name = name
        self.vram_start: Optional[int] = vram_start

        self.align: Optional[int] = None
        self.given_subalign: int = options.opts.subalign
        self.exclusive_ram_id: Optional[str] = None
        self.given_dir: Path = Path()

        # Default to global options.
        self.given_find_file_boundaries: Optional[bool] = None

        # Symbols known to be in this segment
        self.given_seg_symbols: Dict[int, List[Symbol]] = {}

        # Ranges for faster symbol lookup
        self.symbol_ranges_ram: IntervalTree = IntervalTree()
        self.symbol_ranges_rom: IntervalTree = IntervalTree()

        self.given_section_order: List[str] = options.opts.section_order

        self.vram_class: Optional[VramClass] = None
        self.given_follows_vram: Optional[str] = None
        self.given_vram_symbol: Optional[str] = None

        self.given_symbol_name_format: str = options.opts.symbol_name_format
        self.given_symbol_name_format_no_rom: str = (
            options.opts.symbol_name_format_no_rom
        )

        self.parent: Optional[Segment] = None
        self.sibling: Optional[Segment] = None
        self.data_sibling: Optional[Segment] = None
        self.rodata_sibling: Optional[Segment] = None
        self.file_path: Optional[Path] = None

        self.args: List[str] = args
        self.yaml = yaml

        self.extract: bool = True
        self.has_linker_entry: bool = True
        if self.rom_start is None:
            self.extract = False
        elif self.type.startswith("."):
            self.extract = False

        self.warnings: List[str] = []
        self.did_run = False
        self.bss_contains_common = Segment.parse_segment_bss_contains_common(yaml)

        # For segments which are not in the usual VRAM segment space, like N64's IPL3 which lives in 0xA4...
        self.special_vram_segment: bool = False

        self.linker_section_order: Optional[str] = self.parse_linker_section_order(yaml)
        self.linker_section: Optional[str] = self.parse_linker_section(yaml)

        # If not defined on the segment then default to the global option
        self.ld_fill_value: Optional[int] = self.parse_ld_fill_value(
            yaml, options.opts.ld_fill_value
        )

        if self.rom_start is not None and self.rom_end is not None:
            if self.rom_start > self.rom_end:
                log.error(
                    f"Error: segments out of order - ({self.name} starts at 0x{self.rom_start:X}, but next segment starts at 0x{self.rom_end:X})"
                )

    @staticmethod
    def from_yaml(
        cls: Type["Segment"],
        yaml: Union[dict, list],
        rom_start: Optional[int],
        rom_end: Optional[int],
        vram=None,
    ):
        type = Segment.parse_segment_type(yaml)
        name = Segment.parse_segment_name(cls, rom_start, yaml)

        vram_class = parse_segment_vram_class(yaml)

        if vram is not None:
            vram_start = vram
        elif vram_class:
            vram_start = vram_class.vram
        else:
            vram_start = parse_segment_vram(yaml)

        args: List[str] = [] if isinstance(yaml, dict) else yaml[3:]

        ret = cls(
            rom_start=rom_start,
            rom_end=rom_end,
            type=type,
            name=name,
            vram_start=vram_start,
            args=args,
            yaml=yaml,
        )
        ret.given_section_order = parse_segment_section_order(yaml)
        ret.given_subalign = parse_segment_subalign(yaml)

        if isinstance(yaml, dict):
            ret.extract = bool(yaml.get("extract", ret.extract))
            ret.exclusive_ram_id = yaml.get("exclusive_ram_id")
            ret.given_dir = Path(yaml.get("dir", ""))
            ret.has_linker_entry = bool(yaml.get("linker_entry", True))
            ret.given_find_file_boundaries = yaml.get("find_file_boundaries", None)

        ret.given_symbol_name_format = Segment.parse_segment_symbol_name_format(yaml)
        ret.given_symbol_name_format_no_rom = (
            Segment.parse_segment_symbol_name_format_no_rom(yaml)
        )
        ret.file_path = Segment.parse_segment_file_path(yaml)

        ret.bss_contains_common = Segment.parse_segment_bss_contains_common(yaml)

        ret.given_follows_vram = parse_segment_follows_vram(yaml)
        ret.given_vram_symbol = parse_segment_vram_symbol(yaml)

        if vram_class:
            ret.vram_class = vram_class
            if ret.given_follows_vram:
                log.error(
                    f"Error: segment {ret.name} has both a vram class and a follows_vram property"
                )
            if ret.given_vram_symbol:
                log.error(
                    f"Error: segment {ret.name} has both a vram class and a vram_symbol property"
                )

        if not ret.align:
            ret.align = parse_segment_align(yaml)
        return ret

    # For executable segments (.text); like c, asm or hasm
    @staticmethod
    def is_text() -> bool:
        return False

    # For read-write segments (.data); like data
    @staticmethod
    def is_data() -> bool:
        return False

    # For readonly segments (.rodata); like rodata or rdata
    @staticmethod
    def is_rodata() -> bool:
        return False

    # For segments which does not take space in ROM; like bss
    @staticmethod
    def is_noload() -> bool:
        return False

    @staticmethod
    def estimate_size(yaml: Union[Dict, List]) -> Optional[int]:
        return None

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
    def show_file_boundaries(self) -> bool:
        # If the segment has explicitly set `find_file_boundaries`, use it.
        if self.given_find_file_boundaries is not None:
            return self.given_find_file_boundaries

        # If the segment has no parent, use options as default.
        if not self.parent:
            return options.opts.find_file_boundaries

        return self.parent.show_file_boundaries

    @property
    def symbol_name_format(self) -> str:
        return self.given_symbol_name_format

    @property
    def symbol_name_format_no_rom(self) -> str:
        return self.given_symbol_name_format_no_rom

    @property
    def subalign(self) -> int:
        if self.parent:
            return self.parent.subalign
        else:
            return self.given_subalign

    @property
    def vram_symbol(self) -> Optional[str]:
        if self.vram_class and self.vram_class.vram_symbol:
            return self.vram_class.vram_symbol
        elif self.given_vram_symbol:
            return self.given_vram_symbol
        else:
            return None

    def get_exclusive_ram_id(self) -> Optional[str]:
        if self.parent:
            return self.parent.get_exclusive_ram_id()
        return self.exclusive_ram_id

    def add_symbol(self, symbol: Symbol):
        if symbol.vram_start not in self.given_seg_symbols:
            self.given_seg_symbols[symbol.vram_start] = []
        self.given_seg_symbols[symbol.vram_start].append(symbol)

        # For larger symbols, add their ranges to interval trees for faster lookup
        if symbol.size > 4:
            self.symbol_ranges_ram.addi(symbol.vram_start, symbol.vram_end, symbol)
            if symbol.rom is not None:
                self.symbol_ranges_rom.addi(symbol.rom, symbol.rom_end, symbol)

    @property
    def seg_symbols(self) -> Dict[int, List[Symbol]]:
        if self.parent:
            return self.parent.seg_symbols
        else:
            return self.given_seg_symbols

    @property
    def size(self) -> Optional[int]:
        if self.rom_start is not None and self.rom_end is not None:
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

    def get_cname(self) -> str:
        name = self.name
        if self.parent:
            name = self.parent.name + "_" + name

        return to_cname(name)

    def contains_vram(self, vram: int) -> bool:
        if self.vram_start is not None and self.vram_end is not None:
            return vram >= self.vram_start and vram < self.vram_end
        else:
            return False

    def contains_rom(self, rom: int) -> bool:
        if self.rom_start is not None and self.rom_end is not None:
            return rom >= self.rom_start and rom < self.rom_end
        else:
            return False

    def rom_to_ram(self, rom_addr: int) -> Optional[int]:
        if self.vram_start is not None and self.rom_start is not None:
            return self.vram_start + rom_addr - self.rom_start
        else:
            return None

    def ram_to_rom(self, ram_addr: int) -> Optional[int]:
        if not self.contains_vram(ram_addr) and ram_addr != self.vram_end:
            return None

        if self.vram_start is not None and self.rom_start is not None:
            return self.rom_start + ram_addr - self.vram_start
        else:
            return None

    def should_scan(self) -> bool:
        return self.should_split()

    def should_split(self) -> bool:
        return self.extract and options.opts.is_mode_active(self.type)

    def scan(self, rom_bytes: bytes):
        pass

    def split(self, rom_bytes: bytes):
        pass

    def cache(self):
        return (self.yaml, self.rom_end)

    def get_linker_section(self) -> str:
        return ".data"

    def get_linker_section_order(self) -> str:
        """
        Used to override the linking _order_ of a specific section

        Useful for files that may have non-conventional orderings (like putting .data with the other .rodata sections)
        """
        if self.linker_section_order is not None:
            return self.linker_section_order
        return self.get_linker_section()

    def get_linker_section_linksection(self) -> str:
        """
        The actual section that will be used when linking
        """
        if self.linker_section is not None:
            return self.linker_section
        return self.get_linker_section()

    def get_section_flags(self) -> Optional[str]:
        """
        Allows specifying flags for a section.

        This can be useful when creating a custom section, since sections not recognized by the linker will not be linked properly.

        GNU as docs about the section directive and flags: https://sourceware.org/binutils/docs/as/Section.html#ELF-Version

        Example:

        ```
        def get_section_flags(self) -> Optional[str]:
            # Tells the linker to allocate this section
            return "a"
        ```
        """
        return None

    def out_path(self) -> Optional[Path]:
        return None

    def get_most_parent(self) -> "Segment":
        seg = self

        while seg.parent:
            seg = seg.parent

        return seg

    def get_linker_entries(self) -> "List[LinkerEntry]":
        from segtypes.linker_entry import LinkerEntry

        if not self.has_linker_entry:
            return []

        path = self.out_path()

        if path:
            return [
                LinkerEntry(
                    self,
                    [path],
                    path,
                    self.get_linker_section_order(),
                    self.get_linker_section_linksection(),
                    self.is_noload(),
                )
            ]
        else:
            return []

    def log(self, msg):
        if options.opts.verbose:
            log.write(f"{self.type} {self.name}: {msg}")

    def warn(self, msg: str):
        self.warnings.append(msg)

    @staticmethod
    def get_default_name(addr) -> str:
        return f"{addr:X}"

    def is_name_default(self):
        return self.name == self.get_default_name(self.rom_start)

    def unique_id(self):
        if self.parent:
            s = self.parent.unique_id() + "_"
        else:
            s = ""

        return s + self.type + "_" + self.name

    @staticmethod
    def visible_ram(seg1: "Segment", seg2: "Segment") -> bool:
        if seg1.get_most_parent() == seg2.get_most_parent():
            return True
        if seg1.get_exclusive_ram_id() is None or seg2.get_exclusive_ram_id() is None:
            return True
        return seg1.get_exclusive_ram_id() != seg2.get_exclusive_ram_id()

    def retrieve_symbol(
        self, syms: Dict[int, List[Symbol]], addr: int
    ) -> Optional[Symbol]:
        if addr not in syms:
            return None

        items = syms[addr]

        # Filter out symbols that are in different top-level segments with the same unique_ram_id
        items = [
            i
            for i in items
            if i.segment is None or Segment.visible_ram(self, i.segment)
        ]

        if len(items) > 1:
            # print(f"Trying to retrieve {addr:X} from symbol dict but there are {len(items)} entries to pick from - picking the first")
            pass
        if len(items) == 0:
            return None
        return items[0]

    def retrieve_sym_type(
        self, syms: Dict[int, List[Symbol]], addr: int, type: str
    ) -> Optional[symbols.Symbol]:
        if addr not in syms:
            return None

        items = syms[addr]

        items = [
            i
            for i in items
            if i.segment is None
            or Segment.visible_ram(self, i.segment)
            and (type == i.type)
        ]

        if len(items) == 0:
            return None

        return items[0]

    def get_symbol(
        self,
        addr: int,
        in_segment: bool = False,
        type: Optional[str] = None,
        create: bool = False,
        define: bool = False,
        reference: bool = False,
        search_ranges: bool = False,
        local_only: bool = False,
    ) -> Optional[Symbol]:
        ret: Optional[Symbol] = None
        rom: Optional[int] = None

        most_parent = self.get_most_parent()

        if in_segment:
            # If the vram address is within this segment, we can calculate the symbol's rom address
            rom = most_parent.ram_to_rom(addr)
            ret = most_parent.retrieve_symbol(most_parent.seg_symbols, addr)

            if not ret and search_ranges:
                # Search ranges first, starting with rom
                if rom is not None:
                    cands: Set[Interval] = most_parent.symbol_ranges_rom[rom]
                    if cands:
                        ret = cands.pop().data
                # and then vram if we can't find a rom match
                if not ret:
                    cands = most_parent.symbol_ranges_ram[addr]
                    if cands:
                        ret = cands.pop().data
        elif not local_only:
            ret = most_parent.retrieve_symbol(symbols.all_symbols_dict, addr)

            if not ret and search_ranges:
                cands = symbols.all_symbols_ranges[addr]
                if cands:
                    ret = cands.pop().data

        # Create the symbol if it doesn't exist
        if not ret and create:
            ret = Symbol(addr, rom=rom, type=type)
            symbols.add_symbol(ret)

            if in_segment:
                ret.segment = most_parent
                if addr not in most_parent.seg_symbols:
                    most_parent.seg_symbols[addr] = []
                most_parent.seg_symbols[addr].append(ret)

        if ret:
            if define:
                ret.defined = True
            if reference:
                ret.referenced = True
            if ret.type is None:
                ret.type = type
            if ret.rom is None:
                ret.rom = rom
            if in_segment:
                if ret.segment is None:
                    ret.segment = most_parent

        return ret

    def create_symbol(
        self,
        addr: int,
        in_segment: bool,
        type: Optional[str] = None,
        define: bool = False,
        reference: bool = False,
        search_ranges: bool = False,
        local_only: bool = False,
    ) -> Symbol:
        ret = self.get_symbol(
            addr,
            in_segment=in_segment,
            type=type,
            create=True,
            define=define,
            reference=reference,
            search_ranges=search_ranges,
            local_only=local_only,
        )
        assert ret is not None

        return ret

    def get_func_for_addr(self, addr) -> Optional[Symbol]:
        for syms in self.seg_symbols.values():
            for sym in syms:
                if sym.type == "func" and sym.contains_vram(addr):
                    return sym

        return None
