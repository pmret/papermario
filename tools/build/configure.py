#!/usr/bin/env python3

from typing import List, Dict, Set, Union
from pathlib import Path
import subprocess
import sys
import ninja_syntax
from glob import glob

# Configuration:
VERSIONS = ["us", "jp"]
DO_SHA1_CHECK = True
DO_FIRST_OK = True

# Paths:
ROOT = Path(__file__).parent.parent.parent
BUILD_TOOLS = (ROOT / "tools" / "build").relative_to(ROOT)
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
    ret = subprocess.run(command, stdout=subprocess.PIPE, text=True)
    return ret.stdout

def write_ninja_rules(ninja: ninja_syntax.Writer, cpp: str, cppflags: str, extra_cflags: str):
    # platform-specific
    if sys.platform  == "darwin":
        iconv = "tools/iconv.py UTF-8 SHIFT-JIS"
    elif sys.platform == "linux":
        iconv = "iconv --from UTF-8 --to SHIFT-JIS"
    else:
        raise Exception(f"unsupported platform {sys.platform}")

    ccache = "ccache "

    try:
        subprocess.call(["ccache"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except FileNotFoundError:
        ccache = ""

    cross = "mips-linux-gnu-"
    cc = f"{ccache}{BUILD_TOOLS}/cc/gcc/gcc"
    cxx = f"{ccache}{BUILD_TOOLS}/cc/gcc/g++"
    compile_script = f"$python {BUILD_TOOLS}/cc_dsl/compile_script.py"

    CPPFLAGS = "-w -Iver/$version/build/include -Iinclude -Isrc -Iassets/$version -D_LANGUAGE_C -D_FINALROM -DVERSION=$version " \
                "-ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32"

    cflags = f"-c -G0 -O2 -fno-common -Wuninitialized -Wmissing-braces -Wimplicit -Wredundant-decls -Wstrict-prototypes -B {BUILD_TOOLS}/cc/gcc/ {extra_cflags}"

    ninja.variable("python", sys.executable)

    ninja.rule("ld",
        description="link($version) $out",
        command=f"{cross}ld -T ver/$version/build/undefined_syms.txt -T ver/$version/undefined_syms_auto.txt -T ver/$version/undefined_funcs_auto.txt -Map $mapfile --no-check-sections -T $in -o $out",
    )

    ninja.rule("z64",
        description="rom $out",
        command=f"{cross}objcopy $in $out -O binary && {BUILD_TOOLS}/rom/n64crc $out",
    )

    ninja.rule("sha1sum",
        description="check $in",
        command="sha1sum -c $in && touch $out" + ("&& bash tools/build/first_ok.sh" if DO_FIRST_OK else "") if DO_SHA1_CHECK else "touch $out",
    )

    ninja.rule("cpp",
        description="cpp $in",
        command=f"{cpp} $in {cppflags} -P -o $out"
    )

    ninja.rule("cc",
        description="cc $in",
        command=f"bash -o pipefail -c '{cpp} {CPPFLAGS} {cppflags} -MD -MF $out.d $in -o - | {iconv} > $out.i && {cc} {cflags} $cflags $out.i -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule("cc_dsl",
        description="cc $in $cflags",
        command=f"bash -o pipefail -c '{cpp} {CPPFLAGS} {cppflags} -MD -MF $out.d $in -o - | {compile_script} | {iconv} > $out.i && {cc} {cflags} $cflags $out.i -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule("cxx",
        description="cxx $in",
        command=f"bash -o pipefail -c '{cpp} {CPPFLAGS} {cppflags} -MD -MF $out.d $in -o - | {iconv} > $out.i && {cxx} {cflags} $cflags $out.i -o $out'",
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

    ninja.rule("bin_inc_c",
        description="bin_inc_c $out",
        command=f"$python {BUILD_TOOLS}/bin_inc_c.py $in $out",
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
        command=f"$python {BUILD_TOOLS}/mapfs/combine.py $version $out $in",
    )

    ninja.rule("pack_title_data",
        description="pack_title_data $out",
        command=f"$python {BUILD_TOOLS}/mapfs/pack_title_data.py $out $in",
    )

    ninja.rule("map_header", command=f"$python {BUILD_TOOLS}/mapfs/map_header.py $in > $out")

    ninja.rule("pm_charset", command=f"$python {BUILD_TOOLS}/pm_charset.py $out $in")

    ninja.rule("pm_charset_palettes", command=f"$python {BUILD_TOOLS}/pm_charset_palettes.py $out $in")

    with Path("tools/permuter_settings.toml").open("w") as f:
        f.write(f"compiler_command = \"{cc} {CPPFLAGS.replace('$version', 'us')} {cflags} -DPERMUTER -fforce-addr\"\n")
        f.write(f"assembler_command = \"{cross}as -EB -march=vr4300 -mtune=vr4300 -Iinclude\"\n")
        f.write(
"""
[preserve_macros]
"gs?[DS]P.*" = "void"
OVERRIDE_FLAG_CHECK = "int"
OS_K0_TO_PHYSICAL = "int"
"G_.*" = "int"
"TEXEL.*" = "int"
PRIMITIVE = "int"
""")

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
            modes.extend(["bin", "Yay0", "img", "vtx", "pm_map_data", "pm_msg", "pm_npc_sprites", "pm_charset",
                          "pm_charset_palettes", "pm_effect_loads", "pm_effect_shims"])
        if code:
            modes.extend(["code", "c", "data", "rodata"])

        split.main(
            str(self.version_path / "splat.yaml"),
            None,
            str(self.version_path / "baserom.z64"),
            modes,
            verbose=False,
        )
        self.linker_entries = split.linker_writer.entries[:]
        self.asset_stack = split.config["asset_stack"]

    def build_path(self) -> Path:
        return Path(f"ver/{self.version}/build")

    def undefined_syms_path(self) -> Path:
        return self.build_path() / "undefined_syms.txt"

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
            path = self.resolve_asset_path(path)

            if path.is_dir():
                out.extend(glob(str(path) + "/**/*", recursive=True))
            else:
                out.append(str(path))

        return out

    def resolve_asset_path(self, path: Path) -> Path:
        parts = list(path.parts)

        if parts[0] == "assets":
            for d in self.asset_stack:
                parts[1] = d
                new_path = Path("/".join(parts))
                if new_path.exists():
                    return new_path

        # ¯\_(ツ)_/¯
        return path

    def write_ninja(self, ninja: ninja_syntax.Writer, skip_outputs: Set[str]):
        import segtypes
        import segtypes.n64.data
        import segtypes.n64.Yay0

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
                elif object_path.suffixes[-1] == ".h" or task == "bin_inc_c":
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
                elif task in ["cc", "cc_dsl", "cxx"]:
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
            seg = entry.segment

            if isinstance(seg, segtypes.n64.header.N64SegHeader):
                build(entry.object_path, entry.src_paths, "as")
            elif isinstance(seg, segtypes.n64.asm.N64SegAsm) or (isinstance(seg, segtypes.n64.data.N64SegData) and not seg.type[0] == "."):
                build(entry.object_path, entry.src_paths, "as")
            elif isinstance(seg, segtypes.n64.c.N64SegC) or (isinstance(seg, segtypes.n64.data.N64SegData) and seg.type[0] == "."):
                cflags = None
                if isinstance(seg.yaml, dict):
                    cflags = seg.yaml.get("cflags")
                elif len(seg.yaml) >= 4:
                    cflags = seg.yaml[3]

                # default cflags where not specified
                if cflags is None:
                    if "nusys" in entry.src_paths[0].parts:
                        cflags = ""
                    elif "os" in entry.src_paths[0].parts: # libultra
                        cflags = ""
                    else: # papermario
                        cflags = "-fforce-addr"

                # check for dsl
                task = "cc"
                if entry.src_paths[0].suffixes[-1] == ".cpp":
                    task = "cxx"
                with entry.src_paths[0].open() as f:
                    s = f.read()
                    if "SCRIPT(" in s or "#pragma SCRIPT" in s or "#include \"world/common/foliage.inc.c\"" in s:
                        task = "cc_dsl"

                build(entry.object_path, entry.src_paths, task, variables={"cflags": cflags})

                # images embedded inside data aren't linked, but they do need to be built into .inc.c files
                if isinstance(seg, segtypes.n64.group.N64SegGroup):
                    for seg in seg.subsegments:
                        if isinstance(seg, segtypes.n64.img.N64SegImg):
                            flags = ""
                            if seg.flip_horizontal:
                                flags += "--flip-x "
                            if seg.flip_vertical:
                                flags += "--flip-y "

                            src_paths = [seg.out_path()]
                            inc_dir = self.build_path() / "include" / seg.dir
                            bin_path = self.build_path() / seg.dir / (seg.name + ".png.bin")

                            build(bin_path, src_paths, "img", variables={
                                "img_type": seg.type,
                                "img_flags": flags,
                            })

                            build(inc_dir / (seg.name + ".png.h"), src_paths, "img_header")
                            build(inc_dir / (seg.name + ".png.inc.c"), [bin_path], "bin_inc_c")
                        elif isinstance(seg, segtypes.n64.palette.N64SegPalette):
                            src_paths = [seg.out_path()]
                            inc_dir = self.build_path() / "include" / seg.dir
                            bin_path = self.build_path() / seg.dir / (seg.name + ".pal.bin")

                            build(bin_path, src_paths, "img", variables={
                                "img_type": seg.type,
                                "img_flags": "",
                            })
                            build(inc_dir / (seg.name + ".pal.inc.c"), [bin_path], "bin_inc_c")
            elif isinstance(seg, segtypes.n64.bin.N64SegBin):
                build(entry.object_path, entry.src_paths, "bin")
            elif isinstance(seg, segtypes.n64.Yay0.N64SegYay0):
                compressed_path = entry.object_path.with_suffix("") # remove .o
                build(compressed_path, entry.src_paths, "yay0")
                build(entry.object_path, [compressed_path], "bin")
            elif isinstance(seg, segtypes.n64.img.N64SegImg):
                flags = ""
                if seg.flip_horizontal:
                    flags += "--flip-x "
                if seg.flip_vertical:
                    flags += "--flip-y "

                bin_path = entry.object_path.with_suffix(".bin")
                inc_dir = self.build_path() / "include" / seg.dir

                build(bin_path, entry.src_paths, "img", variables={
                    "img_type": seg.type,
                    "img_flags": flags,
                })
                build(entry.object_path, [bin_path], "bin")

                build(inc_dir / (seg.name + ".png.h"), entry.src_paths, "img_header")
            elif isinstance(seg, segtypes.n64.palette.N64SegPalette):
                bin_path = entry.object_path.with_suffix(".bin")

                build(bin_path, entry.src_paths, "img", variables={
                    "img_type": seg.type,
                    "img_flags": "",
                })
                build(entry.object_path, [bin_path], "bin")
            elif seg.type == "pm_npc_sprites":
                sprite_yay0s = []

                for sprite_id, sprite_dir in enumerate(entry.src_paths, 1):
                    sprite_name = sprite_dir.name

                    bin_path = entry.object_path.with_suffix("") / (sprite_name + ".bin")
                    yay0_path = bin_path.with_suffix(".Yay0")
                    sprite_yay0s.append(yay0_path)

                    variables = {
                        "sprite_id": sprite_id,
                        "sprite_name": sprite_name,
                        "sprite_dir": str(self.resolve_asset_path(sprite_dir)),
                    }

                    build(bin_path, [sprite_dir], "sprite", variables=variables)
                    build(yay0_path, [bin_path], "yay0")
                    build(
                        self.build_path() / "include" / seg.dir / seg.name / (sprite_name + ".h"),
                        [sprite_dir],
                        "sprite_header",
                        variables=variables,
                    )

                build(entry.object_path.with_suffix(".bin"), sprite_yay0s, "sprite_combine")
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")
            elif seg.type == "pm_msg":
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
            elif seg.type == "pm_map_data":
                bin_yay0s: List[Path] = [] # flat list of (uncompressed path, compressed? path) pairs
                src_dir = Path("assets/x") / seg.name

                for path in entry.src_paths:
                    name = path.stem
                    out_dir = entry.object_path.with_suffix("").with_suffix("")
                    bin_path = out_dir / f"{name}.bin"

                    if name.startswith("party_"):
                        compress = True
                        build(bin_path, [path], "img", variables={
                            "img_type": "party",
                            "img_flags": "",
                        })
                    elif name == "title_data":
                        compress = True

                        logotype_path = out_dir / "title_logotype.bin"
                        copyright_path = out_dir / "title_copyright.bin"
                        copyright_pal_path = out_dir / "title_copyright.pal" # jp only
                        press_start_path = out_dir / "title_press_start.bin"

                        build(logotype_path, [src_dir / "title/logotype.png"], "img", variables={
                            "img_type": "rgba32",
                            "img_flags": "",
                        })
                        build(press_start_path, [src_dir / "title/press_start.png"], "img", variables={
                            "img_type": "ia8",
                            "img_flags": "",
                        })

                        if self.version == "jp":
                            build(copyright_path, [src_dir / "title/copyright.png"], "img", variables={
                                "img_type": "ci4",
                                "img_flags": "",
                            })
                            build(copyright_pal_path, [src_dir / "title/copyright.png"], "img", variables={
                                "img_type": "palette",
                                "img_flags": "",
                            })
                            imgs = [logotype_path, copyright_path, press_start_path, copyright_pal_path]
                        else:
                            build(copyright_path, [src_dir / "title/copyright.png"], "img", variables={
                                "img_type": "ia8",
                                "img_flags": "",
                            })
                            imgs = [logotype_path, copyright_path, press_start_path]

                        build(bin_path, imgs, "pack_title_data")
                    elif name.endswith("_bg"):
                        compress = True
                        bin_path = self.build_path() / bin_path
                        build(bin_path, [path], "img", variables={
                            "img_type": "bg",
                            "img_flags": "",
                        })
                    elif name.endswith("_tex"):
                        compress = False
                        bin_path = path
                    elif name.endswith("_shape"):
                        map_name = "_".join(name.split("_")[:-1])

                        # Handle map XML files, if they exist (TODO: have splat output these)
                        map_xml = self.resolve_asset_path(Path(f"assets/{self.version}") / seg.dir / seg.name / (map_name + ".xml"))
                        if map_xml.exists():
                            # Build a header file for this map
                            build(
                                self.build_path() / "include" / seg.dir / seg.name / (map_name + ".h"),
                                [map_xml],
                                "map_header",
                            )

                            # NOTE: we don't build the map xml into a _shape or _hit file (yet); the Star Rod Map Editor
                            # is able to build the xml nonmatchingly into assets/star_rod_build/mapfs/*.bin for people
                            # who want that (i.e. modders). 'star_rod_build' should be added to asset_stack also.

                        compress = True
                        bin_path = path
                    else:
                        compress = True
                        bin_path = path

                    if compress:
                        yay0_path = out_dir / f"{name}.Yay0"
                        build(yay0_path, [bin_path], "yay0")
                    else:
                        yay0_path = bin_path

                    bin_yay0s.append(bin_path)
                    bin_yay0s.append(yay0_path)

                # combine
                build(entry.object_path.with_suffix(""), bin_yay0s, "mapfs")
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
            elif seg.type == "pm_charset":
                rasters = []

                for src_path in entry.src_paths:
                    out_path = self.build_path() / seg.dir / seg.name / (src_path.stem + ".bin")
                    build(out_path, [src_path], "img", variables={
                        "img_type": "ci4",
                        "img_flags": "",
                    })
                    rasters.append(out_path)

                build(entry.object_path.with_suffix(""), rasters, "pm_charset")
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
            elif seg.type == "pm_charset_palettes":
                palettes = []

                for src_path in entry.src_paths:
                    out_path = self.build_path() / seg.dir / seg.name / "palette" / (src_path.stem + ".bin")
                    build(out_path, [src_path], "img", variables={
                        "img_type": "palette",
                        "img_flags": "",
                    })
                    palettes.append(out_path)

                build(entry.object_path.with_suffix(""), palettes, "pm_charset_palettes")
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
            elif seg.type in ["pm_effect_loads", "pm_effect_shims"]:
                build(entry.object_path, entry.src_paths, "as")
            elif seg.type == "linker" or seg.type == "linker_offset":
                pass
            else:
                raise Exception(f"don't know how to build {seg.__class__.__name__} '{seg.name}'")

        # Run undefined_syms through cpp
        ninja.build(
            str(self.undefined_syms_path()),
            "cpp",
            str(self.version_path / "undefined_syms.txt")
        )

        # Build elf, z64, ok
        ninja.build(
            str(self.elf_path()),
            "ld",
            str(self.linker_script_path()),
            implicit=[str(obj) for obj in built_objects] + [str(self.undefined_syms_path())],
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
    parser.add_argument("-d", "--debug", action="store_true", help="Generate debugging information")
    parser.add_argument("-n", "--non-matching", action="store_true", help="Compile nonmatching code. Combine with --debug for more detailed debug info")
    args = parser.parse_args()

    exec_shell(["make", "-C", str(ROOT / args.splat)])

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if args.cpp is None and sys.platform == "darwin" and "Free Software Foundation" not in exec_shell(["cpp", "--version"]):
        if "Free Software Foundation" in exec_shell(["cpp-11", "--version"]):
            args.cpp = "cpp-11"
        else:
            print("error: system C preprocessor is not GNU!")
            print("This is a known issue on macOS - only clang's cpp is installed by default.")
            print("Use 'brew' to obtain GNU cpp, then run this script again with the --cpp option, e.g.")
            print("    ./configure --cpp cpp-11")
            exit(1)

    # default version behaviour is to only do those that exist
    if len(args.version) > 0:
        versions = args.version
    else:
        versions = []

        for version in VERSIONS:
            rom = ROOT / f"ver/{version}/baserom.z64"

            print(f"configure: looking for baserom {rom.relative_to(ROOT)}", end="")

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

    cflags = ""
    cppflags = ""
    if args.non_matching:
        cppflags += " -DNON_MATCHING"

        if args.debug:
            cflags += " -ggdb3" # we can generate more accurate debug info in non-matching mode
            cppflags += " -DDEBUG" # e.g. affects ASSERT macro
    elif args.debug:
        # g1 doesn't affect codegen
        cflags += " -g1"

    # add splat to python import path
    sys.path.append(str((ROOT / args.splat).resolve()))

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    write_ninja_rules(ninja, args.cpp or "cpp", cppflags, cflags)
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
