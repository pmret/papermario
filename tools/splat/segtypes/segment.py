from pathlib import Path, PurePath
from util import log
import re
import sys

default_subalign = 16


def parse_segment_start(segment):
    return segment[0] if "start" not in segment else segment["start"]


def parse_segment_type(segment):
    if type(segment) is dict:
        return segment["type"]
    else:
        return segment[1]


def parse_segment_name(segment, segment_class):
    if type(segment) is dict and "name" in segment:
        return segment["name"]
    elif type(segment) is list and len(segment) >= 3 and type(segment[2]) is str:
        return segment[2]
    else:
        return segment_class.get_default_name(parse_segment_start(segment))


def parse_segment_vram(segment):
    if type(segment) is dict:
        return segment.get("vram", 0)
    else:
        if len(segment) >= 3 and type(segment[-1]) is int:
            return segment[-1]
        else:
            return 0


def parse_segment_subalign(segment):
    if type(segment) is dict:
        return segment.get("subalign", default_subalign)
    return default_subalign


class Segment:
    require_unique_name = True

    def __init__(self, segment, next_segment, options):
        self.rom_start = parse_segment_start(segment)
        self.rom_end = parse_segment_start(next_segment)
        self.type = parse_segment_type(segment)
        self.name = parse_segment_name(segment, self.__class__)
        self.vram_start = parse_segment_vram(segment)
        self.ld_name_override = segment.get("ld_name", None) if type(segment) is dict else None
        self.options = options
        self.config = segment
        self.subalign = parse_segment_subalign(segment)

        self.errors = []
        self.warnings = []
        self.did_run = False

        if self.rom_start > self.rom_end:
            print(f"Error: segments out of order - ({self.name} starts at 0x{self.rom_start:X}, but next segment starts at 0x{self.rom_end:X})")
            sys.exit(1)
        elif self.max_length():
            expected_len = int(self.max_length())
            actual_len = self.rom_end - self.rom_start
            if actual_len > expected_len:
                print(f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)")
                sys.exit(1)

    @property
    def size(self):
        return self.rom_end - self.rom_start

    @property
    def vram_end(self):
        return self.vram_start + self.size

    def contains_vram(self, vram):
        return vram >= self.vram_start and vram < self.vram_end

    def contains_rom(self, rom):
        return rom >= self.rom_start and rom < self.rom_end

    def rom_to_ram(self, rom_addr):
        if rom_addr < self.rom_start or rom_addr > self.rom_end:
            return None

        return self.vram_start + rom_addr - self.rom_start

    def ram_to_rom(self, ram_addr):
        if ram_addr < self.vram_start or ram_addr > self.vram_end:
            return None

        return self.rom_start + ram_addr - self.vram_start

    @staticmethod
    def create_split_dir(base_path, subdir):
        out_dir = Path(base_path, subdir)
        out_dir.mkdir(parents=True, exist_ok=True)
        return out_dir

    @staticmethod
    def create_parent_dir(base_path, filename):
        out_dir = Path(base_path, filename).parent
        out_dir.mkdir(parents=True, exist_ok=True)
        return out_dir

    def should_run(self):
        return self.type in self.options["modes"] or "all" in self.options["modes"]

    def split(self, rom_bytes, base_path):
        pass

    def postsplit(self, segments):
        pass

    def cache(self):
        return (self.config, self.rom_end)

    def get_ld_section(self):
        replace_ext = self.options.get("ld_o_replace_extension", True)
        sect_name = self.ld_name_override if self.ld_name_override else self.get_ld_section_name()
        vram_or_rom = self.rom_start if self.vram_start == 0 else self.vram_start
        subalign_str = "" if self.subalign == default_subalign else f"SUBALIGN({self.subalign})"

        s = (
            f"SPLAT_BEGIN_SEG({sect_name}, 0x{self.rom_start:X}, 0x{vram_or_rom:X}, {subalign_str})\n"
        )

        i = 0
        do_next = False
        for subdir, path, obj_type, start in self.get_ld_files():
            # Hack for non-0x10 alignment START
            if start % 0x10 != 0 and i != 0 or do_next:
                tmp_sect_name = path.replace(".", "_")
                tmp_sect_name = tmp_sect_name.replace("/", "_")
                tmp_vram = start - self.rom_start + self.vram_start
                s += (
                    "}\n"
                    f"SPLAT_BEGIN_SEG({tmp_sect_name}, 0x{start:X}, 0x{tmp_vram:X}, {subalign_str})\n"
                )
                do_next = False

            if start % 0x10 != 0 and i != 0:
                do_next = True
            # Hack for non-0x10 alignment END

            path_cname = re.sub(r"[^0-9a-zA-Z_]", "_", path)
            s += f"    {path_cname} = .;\n"

            if subdir == self.options.get("assets_dir"):
                path = PurePath(path)
            else:
                path = PurePath(subdir) / PurePath(path)

            # Remove leading ..s
            while path.parts[0] == "..":
                path = path.relative_to("..")

            path = path.with_suffix(".o" if replace_ext else path.suffix + ".o")

            s += f"    BUILD_DIR/{path}({obj_type});\n"
            i += 1

        s += (
            f"SPLAT_END_SEG({sect_name}, 0x{self.rom_end:X})\n"
        )

        return s

    def get_ld_section_name(self):
        return f"data_{self.rom_start:X}"

    # returns list of (basedir, filename, obj_type)
    def get_ld_files(self):
        return []

    def log(self, msg):
        if self.options.get("verbose", False):
            log.write(f"{self.type} {self.name}: {msg}")

    def warn(self, msg):
        self.warnings.append(msg)

    def error(self, msg):
        self.errors.append(msg)

    def max_length(self):
        return None

    def is_name_default(self):
        return self.name == self.get_default_name(self.rom_start)

    def unique_id(self):
        return self.type + "_" + self.name

    def status(self):
        if len(self.errors) > 0:
            return "error"
        elif len(self.warnings) > 0:
            return "warn"
        elif self.did_run:
            return "ok"
        else:
            return "skip"

    @staticmethod
    def get_default_name(addr):
        return "{:X}".format(addr)
