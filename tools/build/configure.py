#!/usr/bin/env python3

from typing import List, Dict, Set, Union
from pathlib import Path
import sys
import ninja_syntax
from glob import glob

VERSIONS = ["us", "jp"]
ROOT = Path(__file__).parent.parent.parent
BUILD_TOOLS = ROOT / "tools" / "build" # directory where this file is (TODO: use relative_to)
YAY0_COMPRESS_TOOL = f"{BUILD_TOOLS}/yay0/Yay0compress"
CRC_TOOL = f"{BUILD_TOOLS}/rom/n64crc"

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

    ninja.variable("python", sys.executable)

    ninja.rule("ld",
        description="link($version) $out",
        command=f"{cross}ld -T ver/$version/undefined_syms.txt -T ver/$version/undefined_syms_auto.txt -T ver/$version/undefined_funcs_auto.txt  -T ver/$version/dead_syms.txt -Map $mapfile --no-check-sections -T $in -o $out",
    )

    ninja.rule("z64",
        description="rom $out",
        command=f"{cross}objcopy $in $out -O binary && {BUILD_TOOLS}/rom/n64crc $out",
    )

    ninja.rule("sha1sum",
        description="check $in",
        command=f"sha1sum -c $in && touch $out",
    )

    ninja.rule("cc",
        description="cc($version) $in",
        command=f"bash -o pipefail -c '{cpp} -w -Iver/$version/build/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -MD -MF $out.d $in -o - | {iconv} | {BUILD_TOOLS}/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow -o - | {BUILD_TOOLS}/{os_dir}/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule("cc_dsl",
        description="cc_dsl($version) $in",
        command=f"bash -o pipefail -c '{cpp} -w -Iver/$version/build/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -MD -MF $out.d $in -o - | $python {BUILD_TOOLS}/cc_dsl/compile_script.py | {iconv} | {BUILD_TOOLS}/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow -o - | {BUILD_TOOLS}/{os_dir}/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
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

    ninja.rule("img",
        description="img($img_type) $in",
        command=f"$python {BUILD_TOOLS}/img/build.py $img_type $in $out $img_flags",
    )

    ninja.rule("img_header",
        description="img_header $in",
        command=f"$python {BUILD_TOOLS}/img/header.py $in $out",
    )

    ninja.rule("yay0",
        description="yay0 $in",
        command=f"{BUILD_TOOLS}/yay0/Yay0compress $in $out",
    )

    ninja.rule("sprite",
        description="sprite $sprite_name",
        command=f"$python {BUILD_TOOLS}/sprites/sprite.py $out $sprite_dir",
    )

    ninja.rule("sprite_combine",
        description="sprite_combine $in",
        command=f"$python {BUILD_TOOLS}/sprites/combine.py $out $in",
    )

    ninja.rule("sprite_header",
        description="sprite_header $sprite_name",
        command=f"$python {BUILD_TOOLS}/sprites/header.py $out $sprite_dir $sprite_id",
    )

    ninja.rule("msg",
        description="msg $in",
        command=f"$python {BUILD_TOOLS}/msg/parse_compile.py $in $out",
    )

    ninja.rule("msg_combine",
        description="msg_combine $out",
        command=f"$python {BUILD_TOOLS}/msg/combine.py $out $in",
    )

    ninja.rule("mapfs",
        description="mapfs $out",
        command=f"$python {BUILD_TOOLS}/mapfs/combine.py $out $in",
    )

def write_ninja_for_tools(ninja: ninja_syntax.Writer):
    ninja.rule("cc_tool",
        description="cc_tool $in",
        command=f"cc -w $in -O3 -o $out",
    )

    ninja.build(YAY0_COMPRESS_TOOL, "cc_tool", f"{BUILD_TOOLS}/yay0/Yay0compress.c")
    ninja.build(CRC_TOOL, "cc_tool", f"{BUILD_TOOLS}/rom/n64crc.c")

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
            modes.extend(["code", "c", "data", "rodata"])

        self.linker_entries = split.main(
            str(self.version_path / "splat.yaml"),
            None,
            str(self.version_path / "baserom.z64"),
            modes,
            verbose=False,
        ).entries

    def build_path(self) -> Path:
        return Path(f"ver/{self.version}/build")

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

    def resolve_src_paths(self, src_paths: List[Path]) -> List[str]:
        out = []

        for path in src_paths:
            if path.parents[0] == "assets":
                # TODO resolve asset
                pass

            if path.is_dir():
                out.extend(glob(str(path) + "/**/*", recursive=True))
            else:
                out.append(str(path))

        return out

    def write_ninja(self, ninja: ninja_syntax.Writer, skip_outputs: Set[str]):
        import segtypes

        assert self.linker_entries is not None

        built_objects = set()
        generated_headers = []

        def build(object_paths: Union[Path, List[Path]], src_paths: List[Path], task: str, variables: Dict[str, str] = {}):
            if not isinstance(object_paths, list):
                object_paths = [object_paths]

            object_strs = [str(obj) for obj in object_paths]
            needs_build = False

            for object_path in object_paths:
                if object_path.suffixes[-1] == ".o":
                    built_objects.add(str(object_path))
                elif object_path.suffixes[-1] == ".h":
                    generated_headers.append(str(object_path))

                # don't rebuild objects if we've already seen all of them
                if not str(object_path) in skip_outputs:
                    needs_build = True

            if needs_build:
                skip_outputs.update(object_strs)

                implicit = []
                order_only = []

                if task == "yay0":
                    implicit.append(YAY0_COMPRESS_TOOL)
                elif task == "cc" or task == "cc_dsl":
                    order_only.append("generated_headers_" + self.version)

                ninja.build(
                    object_strs, # $out
                    task,
                    self.resolve_src_paths(src_paths), # $in
                    variables={ "version": self.version, **variables },
                    implicit=implicit,
                    order_only=order_only,
                )

        # Build objects
        for entry in self.linker_entries:
            subseg = entry.segment_or_subsegment

            if isinstance(subseg, segtypes.n64.header.N64SegHeader):
                build(entry.object_path, entry.src_paths, "as")
            elif isinstance(subseg, segtypes.n64.code.Subsegment) and subseg.type in ["asm", "hasm", "data", "rodata", "bss"]:
                build(entry.object_path, entry.src_paths, "as")
            elif (isinstance(subseg, segtypes.n64.code.CodeSubsegment) and subseg.type == "c") or (isinstance(subseg, segtypes.n64.code.Subsegment) and subseg.type.startswith(".")):
                build(entry.object_path, entry.src_paths, "cc_dsl") # TODO: don't use dsl for everything
            elif isinstance(subseg, segtypes.n64.code.BinSubsegment) or isinstance(subseg, segtypes.n64.bin.N64SegBin):
                build(entry.object_path, entry.src_paths, "bin")
            elif isinstance(subseg, segtypes.n64.Yay0.N64SegYay0):
                compressed_path = entry.object_path.with_suffix("") # remove .o
                build(compressed_path, entry.src_paths, "yay0")
                build(entry.object_path, [compressed_path], "bin")
            elif isinstance(subseg, segtypes.n64.img.N64SegImg):
                flags = ""
                if subseg.flip_horizontal:
                    flags += "--flip-x "
                if subseg.flip_vertical:
                    flags += "--flip-y "

                build(entry.object_path.with_suffix(".bin"), entry.src_paths, "img", variables={
                    "img_type": subseg.type,
                    "img_flags": flags,
                })
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")

                build(self.build_path() / "include" / subseg.dir / (subseg.name + ".png.h"), entry.src_paths, "img_header")
            elif isinstance(subseg, segtypes.n64.palette.N64SegPalette):
                build(entry.object_path.with_suffix(".bin"), entry.src_paths, "img", variables={
                    "img_type": subseg.type,
                    "img_flags": "",
                })
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")
            elif isinstance(subseg, segtypes.n64.code.ImageSubsegment):
                build(entry.object_path.with_suffix(".bin"), entry.src_paths, "img", variables={
                    "img_type": subseg.type,
                    "img_flags": "",
                })
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")

                if subseg.type != "palette":
                    build(self.build_path() / "include" / subseg.dir / (subseg.name + ".png.h"), entry.src_paths, "img_header")
            elif subseg.type == "PaperMarioNpcSprites":
                sprite_yay0s = []

                for sprite_id, sprite_dir in enumerate(entry.src_paths, 1):
                    sprite_name = sprite_dir.name

                    bin_path = entry.object_path.with_suffix("") / (sprite_name + ".bin")
                    yay0_path = bin_path.with_suffix(".Yay0")
                    sprite_yay0s.append(yay0_path)

                    variables = {
                        "sprite_id": sprite_id,
                        "sprite_name": sprite_name,
                        "sprite_dir": str(sprite_dir),
                    }

                    build(bin_path, [sprite_dir], "sprite", variables=variables)
                    build(yay0_path, [bin_path], "yay0")
                    build(
                        self.build_path() / "include" / subseg.dir / subseg.name / (sprite_name + ".h"),
                        [sprite_dir],
                        "sprite_header",
                        variables=variables,
                    )

                build(entry.object_path.with_suffix(".bin"), sprite_yay0s, "sprite_combine")
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")
            elif subseg.type == "PaperMarioMessages":
                msg_bins = []

                for section_idx, msg_path in enumerate(entry.src_paths):
                    bin_path = entry.object_path.with_suffix("") / f"{section_idx:02X}.bin"
                    msg_bins.append(bin_path)
                    build(bin_path, [msg_path], "msg")

                build([
                    entry.object_path.with_suffix(".bin"),
                    self.build_path() / "include" / "message_ids.h",
                ], msg_bins, "msg_combine")
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")
            elif subseg.type == "PaperMarioMapFS":
                bin_yay0s: List[Path] = [] # flat list of (uncompressed path, compressed? path) pairs

                for path in entry.src_paths:
                    name = path.stem
                    bin_path = entry.object_path.with_suffix("").with_suffix("") / f"{name}.bin"

                    if name.startswith("party_"):
                        compress = True
                        build(bin_path, [path], "img", variables={
                            "img_type": "party",
                            "img_flags": "",
                        })
                    elif name.endswith("_bg"):
                        compress = True
                        build(bin_path, [path], "img", variables={
                            "img_type": "bg",
                            "img_flags": "",
                        })
                    elif name.endswith("_tex"):
                        compress = False
                        bin_path = path
                    else:
                        compress = True
                        bin_path = path

                    if compress:
                        yay0_path = bin_path.with_suffix(".Yay0")
                        build(yay0_path, [bin_path], "yay0")
                    else:
                        yay0_path = bin_path

                    bin_yay0s.append(bin_path)
                    bin_yay0s.append(yay0_path)

                # combine
                build(entry.object_path.with_suffix(""), bin_yay0s, "mapfs")
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
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

        ninja.build("generated_headers_" + self.version, "phony", generated_headers)

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
    parser.add_argument("--clean", action="store_true", help="Delete assets and previously-built files")
    parser.add_argument("--splat", default="tools/splat", help="Path to splat tool to use")
    parser.add_argument("--split-code", action="store_true", help="Re-split code segments to asm files")
    parser.add_argument("--no-split-assets", action="store_true", help="Don't split assets from the baserom(s)")
    args = parser.parse_args()

    exec_shell(["make", "-C", str(ROOT / args.splat)])

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
        print("configure: cleaning...")

        exec_shell(["ninja", "-t", "clean"])

        for version in versions:
            rm_recursive(ROOT / f"assets/{version}")
            rm_recursive(ROOT / f"ver/{version}/assets")
            rm_recursive(ROOT / f"ver/{version}/build")
            rm_recursive(ROOT / f"ver/{version}/.splat_cache")

    # add splat to python import path
    sys.path.append(str((ROOT / args.splat).resolve()))

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    write_ninja_rules(ninja, args.cpp or "cpp")
    write_ninja_for_tools(ninja)

    skip_files = set()
    all_rom_oks: List[str] = []
    first_configure = None

    for version in versions:
        print(f"configure: configuring version {version}")

        configure = Configure(version)

        if not first_configure:
            first_configure = configure

        configure.split(not args.no_split_assets, args.split_code)
        configure.write_ninja(ninja, skip_files)

        all_rom_oks.append(str(configure.rom_ok_path()))

    first_configure.make_current(ninja)

    ninja.build("all", "phony", all_rom_oks)
    ninja.default("all")
