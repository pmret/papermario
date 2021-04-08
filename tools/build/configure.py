#!/usr/bin/env python3

from typing import List, Dict, Set
from pathlib import Path
import sys
import ninja_syntax

VERSIONS = ["us", "jp"]
ROOT = Path(__file__).parent.parent.parent

YAY0_COMPRESS_TOOL = "tools/build/yay0/Yay0compress"
CRC_TOOL = "tools/build/rom/n64crc"

def rm_recursive(path: Path):
    if path.exists():
        if path.is_dir():
            for f in path.iterdir():
                rm_recursive(f)

            path.rmdir()
        else:
            path.unlink()

def exec_shell(command: List[str]) -> str:
    import subprocess

    ret = subprocess.run(command, stdout=subprocess.PIPE, text=True)
    return ret.stdout

def write_ninja_rules(ninja: ninja_syntax.Writer, cpp: str):
    # platform-specific
    if sys.platform  == "darwin":
        os_dir = "mac"
        iconv = "tools/iconv.py UTF-8 SHIFT-JIS"
    elif sys.platform == "linux":
        from os import uname

        if uname()[4] == "aarch64":
            os_dir = "arm"
        else:
            os_dir = "linux"

        iconv = "iconv --from UTF-8 --to SHIFT-JIS"
    else:
        raise Exception(f"unsupported platform {sys.platform}")

    cross = "mips-linux-gnu-"

    ninja.rule("cc",
        description="cc($version) $in",
        command=f"bash -o pipefail -c '{cpp} -Iver/$version/build/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -MD -MF $out.d $in -o - | {iconv} | tools/build/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow -o - | tools/build/{os_dir}/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule("cc_dsl",
        description="cc_dsl($version) $in",
        command=f"bash -o pipefail -c '{cpp} -Iver/$version/build/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -MD -MF $out.d $in -o - | $python tools/build/cc_dsl/compile_script.py | {iconv} | tools/build/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow -o - | tools/build/{os_dir}/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule("bin",
        description="bin $in",
        command=f"{cross}ld -r -b binary $in -o $out",
    )

    ninja.rule("as",
        description="as $in",
        command=f"{cross}as -EB -march=vr4300 -mtune=vr4300 -Iinclude $in -o $out",
    )

    ninja.rule("ld",
        description="link($version) $out",
        command=f"{cross}ld -T ver/$version/undefined_syms.txt -T ver/$version/undefined_syms_auto.txt -T ver/$version/undefined_funcs_auto.txt  -T ver/$version/dead_syms.txt -Map $mapfile --no-check-sections -T $in -o $out",
    )

    ninja.rule("z64",
        description="rom $out",
        command=f"{cross}objcopy $in $out -O binary && tools/build/rom/n64crc $out",
    )

    ninja.rule("sha1sum",
        description="check",
        command=f"sha1sum -c $in && touch $out",
    )

def write_ninja_for_tools(ninja: ninja_syntax.Writer):
    ninja.rule("cc_tool",
        description="cc_tool $in",
        command=f"cc $in -O3 -o $out",
    )

    ninja.build(YAY0_COMPRESS_TOOL, "cc_tool", "tools/build/yay0/Yay0compress.c")
    ninja.build(CRC_TOOL, "cc_tool", "tools/build/rom/n64crc.c")

class Configure:
    def __init__(self, version: str):
        self.version = version
        self.version_path = ROOT / f"ver/{version}"
        self.linker_entries = None

    def split(self, assets: bool, code: bool):
        import split

        modes = ["ld"]
        if assets:
            modes.extend(["bin", "Yay0", "PaperMarioMapFS", "PaperMarioMessages", "img", "PaperMarioNpcSprites"])
        if code:
            modes.extend(["code"])

        self.linker_entries = split.main(
            str(self.version_path / "splat.yaml"),
            None,
            str(self.version_path / "baserom.z64"),
            modes,
            verbose=True,
        ).entries

    def elf_path(self) -> Path:
        # TODO: read basename and build_path from splat.yaml
        return Path(f"ver/{self.version}/build/papermario.elf")

    def rom_path(self) -> Path:
        return self.elf_path().with_suffix(".z64")

    def rom_ok_path(self) -> Path:
        return self.elf_path().with_suffix(".ok")

    def linker_script_path(self) -> Path:
        # TODO: read from splat.yaml
        return Path(f"ver/{self.version}/papermario.ld")

    def map_path(self) -> Path:
        return self.elf_path().with_suffix(".map")

    def write_ninja(self, ninja: ninja_syntax.Writer, skip_objects: Set[str]) -> Set[str]:
        import segtypes

        assert self.linker_entries is not None

        built_objects = set()

        def build(entry, task: str, variables: Dict[str, str] = {}):
            if str(entry.object_path) in skip_objects:

                pass
            else:
                built_objects.add(str(entry.object_path))

                ninja.build(
                    str(entry.object_path), # $out
                    task,
                    [str(p) for p in entry.src_paths], # $in
                    variables={ "version": self.version, **variables },
                    implicit=[YAY0_COMPRESS_TOOL],
                )

        # Build objects
        for entry in self.linker_entries:
            subseg = entry.segment_or_subsegment

            if isinstance(subseg, segtypes.n64.header.N64SegHeader):
                build(entry, "as")
            elif isinstance(subseg, segtypes.n64.code.Subsegment) and subseg.type in ["asm", "hasm", "data", "rodata", "bss"]:
                build(entry, "as")
            elif (isinstance(subseg, segtypes.n64.code.CodeSubsegment) and subseg.type == "c") or (isinstance(subseg, segtypes.n64.code.Subsegment) and subseg.type.startswith(".")):
                build(entry, "cc_dsl") # TODO: don't use dsl for everything
            elif isinstance(subseg, segtypes.n64.code.BinSubsegment) or isinstance(subseg, segtypes.n64.bin.N64SegBin):
                build(entry, "bin")
            elif isinstance(subseg, segtypes.n64.Yay0.N64SegYay0):
                build(entry, "yay0")
            else:
                raise Exception(f"don't know how to build {subseg.__class__.__name__} '{subseg.name}'")

        # Build elf, z64, ok
        ninja.build(
            str(self.elf_path()),
            "ld",
            str(self.linker_script_path()),
            implicit=[str(obj) for obj in built_objects],
            variables={ "version": self.version, "mapfile": str(self.map_path()) },
        )
        ninja.build(
            str(self.rom_path()),
            "z64",
            str(self.elf_path()),
            implicit=[CRC_TOOL],
        )
        ninja.build(
            str(self.rom_ok_path()),
            "sha1sum",
            f"ver/{self.version}/checksum.sha1",
            implicit=[str(self.rom_path())],
        )

        return built_objects

    def make_current(self, ninja: ninja_syntax.Writer):
        current = Path("ver/current")

        try:
            current.unlink()
        except Exception:
            pass

        current.symlink_to(self.version)

        ninja.build("ver/current/build/papermario.z64", "phony", str(self.rom_path()))

if __name__ == "__main__":
    from argparse import ArgumentParser

    parser = ArgumentParser(description="Paper Mario build.ninja generator")
    parser.add_argument("version", nargs="*", default=[], help="Version(s) to configure for. Most tools will operate on the first-provided only. Supported versions: " + ','.join(VERSIONS))
    parser.add_argument("--cpp", help="GNU C preprocessor command")
    parser.add_argument("--no-splat", action="store_true", help="Don't split assets from the baserom(s)")
    parser.add_argument("--clean", action="store_true", help="Delete assets and previously-built files")
    parser.add_argument("--splat", default="tools/splat", help="Path to splat tool to use")
    args = parser.parse_args()

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if args.cpp is None and sys.platform == "darwin" and "Free Software Foundation" not in shell("cpp --version"):
        print("error: system C preprocessor is not GNU!")
        print("This is a known issue on macOS - only clang's cpp is installed by default.")
        print("Use 'brew' to obtain GNU cpp, then run this script again with the --cpp option, e.g.")
        print("    ./configure.py --cpp cpp-10")
        exit(1)

    # default version behaviour is to only do those that exist
    if len(args.version) > 0:
        versions = args.version
    else:
        versions = []

        for version in VERSIONS:
            rom = ROOT / f"ver/{version}/baserom.z64"

            print(f"configure: looking for baserom {rom}", end="")

            if rom.exists():
                print("...found")
                versions.append(version)
            else:
                print("...missing")

        if len(versions) == 0:
            print("error: no baseroms found")
            exit(1)

    if args.clean:
        exec_shell(["ninja", "-t", "clean"])

        for version in versions:
            rm_recursive(ROOT / f"ver/{version}/assets")
            rm_recursive(ROOT / f"ver/{version}/build")
            rm_recursive(ROOT / f"ver/{version}/.splat_cache")

    # add splat to python import path
    sys.path.append(str((ROOT / args.splat).resolve()))

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    write_ninja_rules(ninja, args.cpp or "cpp")
    write_ninja_for_tools(ninja)

    built_objects = set() # tracks non-version-specific objects that have been set to be built
    all_rom_oks: List[str] = []

    for version in versions:
        print(f"configure: configuring version {version}")

        configure = Configure(version)

        configure.split(not args.no_splat, False)
        built_objects.update(configure.write_ninja(ninja, built_objects))

        all_rom_oks.append(str(configure.rom_ok_path()))

    configure.make_current(ninja)

    ninja.build("all", "phony", all_rom_oks)
    ninja.default("all")
