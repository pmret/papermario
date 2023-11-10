#!/usr/bin/env python3

from functools import lru_cache
import os
import shutil
from typing import List, Dict, Set, Union
from pathlib import Path
import subprocess
import sys
import ninja_syntax
from glob import glob

# Configuration:
VERSIONS = ["us", "jp", "ique", "pal"]
DO_SHA1_CHECK = True

# Paths:
ROOT = Path(__file__).parent.parent.parent
if ROOT.is_absolute():
    ROOT = ROOT.relative_to(Path.cwd())

BUILD_TOOLS = Path("tools/build")
YAY0_COMPRESS_TOOL = f"{BUILD_TOOLS}/yay0/Yay0compress"
CRC_TOOL = f"{BUILD_TOOLS}/rom/n64crc"

PIGMENT = "pigment64"
PIGMENT_REQ_VERSION = "0.3.0"


def exec_shell(command: List[str]) -> str:
    ret = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return ret.stdout


def write_ninja_rules(
    ninja: ninja_syntax.Writer,
    cpp: str,
    extra_cppflags: str,
    extra_cflags: str,
    use_ccache: bool,
    shift: bool,
    debug: bool,
):
    # platform-specific

    ccache = ""

    if use_ccache:
        ccache = "ccache "
        try:
            subprocess.call(["ccache"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        except FileNotFoundError:
            ccache = ""

    cross = "mips-linux-gnu-"
    cc = f"{BUILD_TOOLS}/cc/gcc/gcc"
    cc_modern = f"{cross}gcc"
    cc_ido = f"{BUILD_TOOLS}/cc/ido5.3/cc"
    cc_272_dir = f"{BUILD_TOOLS}/cc/gcc2.7.2/"
    cc_272 = f"{cc_272_dir}/gcc"
    cc_egcs_dir = f"{BUILD_TOOLS}/cc/egcs/"
    cc_egcs = f"{cc_egcs_dir}/gcc"
    cxx = f"{BUILD_TOOLS}/cc/gcc/g++"

    ICONV = "iconv --from UTF-8 --to $encoding"

    CPPFLAGS_COMMON = (
        "-Iver/$version/include -Iver/$version/build/include -Iinclude -Isrc -Iassets/$version -D_LANGUAGE_C -D_FINALROM "
        "-DVERSION=$version -DF3DEX_GBI_2 -D_MIPS_SZLONG=32"
    )

    CPPFLAGS_272 = CPPFLAGS_COMMON + " -nostdinc"

    CPPFLAGS_EGCS = CPPFLAGS_COMMON + " -D__USE_ISOC99 -DBBPLAYER -nostdinc"

    CPPFLAGS = "-w " + CPPFLAGS_COMMON + " -nostdinc"

    cflags = f"-c -G0 -O2 -gdwarf-2 -x c -B {BUILD_TOOLS}/cc/gcc/ {extra_cflags}"

    cflags_modern = f"-c -G0 -O2 -gdwarf-2 -fno-builtin-bcopy -fno-tree-loop-distribute-patterns -funsigned-char -mgp32 -mfp32 -mabi=32 -mfix4300 -march=vr4300 -mno-gpopt -fno-toplevel-reorder -mno-abicalls -fno-pic -fno-exceptions -fno-stack-protector -fno-zero-initialized-in-bss -Wno-builtin-declaration-mismatch -x c {extra_cflags}"

    cflags_272 = f"-c -G0 -mgp32 -mfp32 -mips3 {extra_cflags}"
    cflags_272 = cflags_272.replace("-ggdb3", "-g1")

    cflags_egcs = f"-c -fno-PIC -mno-abicalls -mcpu=4300 -G 0 -x c -B {cc_egcs_dir} {extra_cflags}"

    ninja.variable("python", sys.executable)

    ld_args = f"-T ver/$version/build/undefined_syms.txt -T ver/$version/undefined_syms_auto.txt -T ver/$version/undefined_funcs_auto.txt -Map $mapfile --no-check-sections -T $in -o $out"

    if shift:
        # For the shiftable build, we link twice to resolve some addresses that gnu ld can't figure out all in one go.
        ninja.rule(
            "ld",
            description="link($version) $out",
            command=f"{cross}ld $$(tools/build/ld/multilink_calc.py $version hardcode) {ld_args} && \
                      {cross}ld $$(tools/build/ld/multilink_calc.py $version calc) {ld_args}",
        )
    else:
        ninja.rule(
            "ld",
            description="link($version) $out",
            command=f"{cross}ld {ld_args}",
        )

    ninja.rule(
        "shape_ld",
        description="link($version) shape $out",
        command=f"{cross}ld -T src/map_shape.ld $in -o $out",
    )

    ninja.rule(
        "shape_objcopy",
        description="objcopy($version) shape $out",
        command=f"{cross}objcopy $in $out -O binary",
    )

    Z64_DEBUG = ""
    if debug:
        Z64_DEBUG = " -gS -R .data -R .note -R .eh_frame -R .gnu.attributes -R .comment -R .options"
    ninja.rule(
        "z64",
        description="rom $out",
        command=f"{cross}objcopy $in $out -O binary{Z64_DEBUG} && {BUILD_TOOLS}/rom/n64crc $out",
    )

    ninja.rule(
        "z64_ique",
        description="rom $out",
        command=f"{cross}objcopy $in $out -O binary{Z64_DEBUG}",
    )

    ninja.rule(
        "sha1sum",
        description="check $in",
        command="sha1sum -c $in && touch $out" if DO_SHA1_CHECK else "touch $out",
    )

    ninja.rule("cpp", description="cpp $in", command=f"{cpp} $in {extra_cppflags} -P -o $out")

    ninja.rule(
        "cc",
        description="gcc $in",
        command=f"bash -o pipefail -c '{cpp} {CPPFLAGS} {extra_cppflags} -DOLD_GCC $cppflags -MD -MF $out.d $in -o - | {ICONV} | {ccache}{cc} {cflags} $cflags - -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule(
        "cc_modern",
        description="gcc $in",
        command=f"bash -o pipefail -c '{cpp} {CPPFLAGS} {extra_cppflags} $cppflags -MD -MF $out.d $in -o - | {ICONV} | {ccache}{cc_modern} {cflags_modern} $cflags - -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule(
        "cc_ido",
        description="ido $in",
        command=f"{ccache}{cc_ido} -w {CPPFLAGS_COMMON} {extra_cppflags} $cppflags -c -mips1 -O0 -G0 -non_shared -Xfullwarn -Xcpluscomm -o $out $in",
    )

    ninja.rule(
        "cc_272",
        description="cc_272 $in",
        command=f"bash -o pipefail -c 'COMPILER_PATH={cc_272_dir} {cc_272} {CPPFLAGS_272} {extra_cppflags} $cppflags {cflags_272} $cflags $in -o $out && mips-linux-gnu-objcopy -N $in $out'",
    )

    ninja.rule(
        "cc_egcs",
        description="cc_egcs $in",
        command=f"bash -o pipefail -c '{cc_egcs} {CPPFLAGS_EGCS} {extra_cppflags} $cppflags {cflags_egcs} $cflags $in -o $out && mips-linux-gnu-objcopy -N $in $out && python3 ./tools/patch_64bit_compile.py $out'",
    )

    ninja.rule(
        "cxx",
        description="cxx $in",
        command=f"bash -o pipefail -c '{cpp} {CPPFLAGS} {extra_cppflags} $cppflags -MD -MF $out.d $in -o - | {ICONV} | {ccache}{cxx} {cflags} $cflags - -o $out'",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule(
        "dead_cc_fix",
        description="dead_cc_fix $in",
        command=f"mips-linux-gnu-objcopy --redefine-sym sqrtf=dead_sqrtf $in $out",
    )

    ninja.rule(
        "bin",
        description="bin $in",
        command=f"{cross}ld -r -b binary $in -o $out",
    )

    ninja.rule(
        "cp",
        description="cp $in $out",
        command=f"cp $in $out",
    )

    ninja.rule(
        "as",
        description="as $in",
        command=f"{cpp} {CPPFLAGS} {extra_cppflags} $cppflags $in -o  - | {cross}as -EB -march=vr4300 -mtune=vr4300 -Iinclude -o $out",
    )

    ninja.rule(
        "img",
        description="img($img_type) $in",
        command=f"$python {BUILD_TOOLS}/img/build.py $img_type $in $out $img_flags",
    )

    ninja.rule(
        "pigment",
        description="img($img_type) $in",
        command=f"{PIGMENT} to-bin $img_flags -f $img_type -o $out $in",
    )

    ninja.rule(
        "img_header",
        description="img_header $in",
        command=f'$python {BUILD_TOOLS}/img/header.py $in $out "$c_name"',
    )

    ninja.rule(
        "bin_inc_c",
        description="bin_inc_c $out",
        command=f'$python {BUILD_TOOLS}/bin_inc_c.py $in $out "$c_name"',
    )

    ninja.rule(
        "pal_inc_c",
        description="pal_inc_c $out",
        command=f'$python {BUILD_TOOLS}/pal_inc_c.py $in $out "$c_name"',
    )

    ninja.rule(
        "yay0",
        description="yay0 $in",
        command=f"{BUILD_TOOLS}/yay0/Yay0compress $in $out",
    )

    ninja.rule(
        "npc_sprite",
        description="sprite $sprite_name",
        command=f"$python {BUILD_TOOLS}/sprite/npc_sprite.py $out $sprite_name $asset_stack",
    )

    ninja.rule(
        "sprites",
        description="sprites $out $header_out",
        command=f"$python {BUILD_TOOLS}/sprite/sprites.py $out $header_out $build_dir $asset_stack",
    )

    ninja.rule(
        "sprite_header",
        description="sprite_header $sprite_name",
        command=f"$python {BUILD_TOOLS}/sprite/header.py $out $sprite_name $sprite_id $asset_stack",
    )

    ninja.rule(
        "msg",
        description="msg $in",
        command=f"$python {BUILD_TOOLS}/msg/parse_compile.py $in $out",
    )

    ninja.rule(
        "icons",
        command=f"$python {BUILD_TOOLS}/icons.py $out $list_path $header_path $asset_stack",
    )

    ninja.rule(
        "move_data",
        command=f"$python {BUILD_TOOLS}/move_data.py $out $in",
    )

    ninja.rule(
        "item_data",
        command=f"$python {BUILD_TOOLS}/item_data.py $out $in",
    )

    ninja.rule(
        "actor_types",
        command=f"$python {BUILD_TOOLS}/actor_types.py $out $in",
    )

    ninja.rule(
        "world_map",
        command=f"$python {BUILD_TOOLS}/world_map.py $in $out",
    )

    ninja.rule(
        "recipes",
        command=f"$python {BUILD_TOOLS}/recipes.py $in $out",
    )

    ninja.rule(
        "msg_combine",
        description="msg_combine $out",
        command=f"$python {BUILD_TOOLS}/msg/combine.py $out $in",
    )

    ninja.rule(
        "mapfs",
        description="mapfs $out",
        command=f"$python {BUILD_TOOLS}/mapfs/combine.py $version $out $in",
    )

    ninja.rule(
        "tex",
        description="tex $out",
        command=f"$python {BUILD_TOOLS}/mapfs/tex.py $out $tex_name $asset_stack",
    )

    ninja.rule(
        "pack_title_data",
        description="pack_title_data $out",
        command=f"$python {BUILD_TOOLS}/mapfs/pack_title_data.py $out $in",
    )

    ninja.rule("map_header", command=f"$python {BUILD_TOOLS}/mapfs/map_header.py $in > $out")

    ninja.rule("charset", command=f"$python {BUILD_TOOLS}/pm_charset.py $out $in")

    ninja.rule(
        "charset_palettes",
        command=f"$python {BUILD_TOOLS}/pm_charset_palettes.py $out $in",
    )

    ninja.rule(
        "sprite_shading_profiles",
        command=f"$python {BUILD_TOOLS}/sprite/sprite_shading_profiles.py $in $out $header_path",
    )

    ninja.rule("imgfx_data", command=f"$python {BUILD_TOOLS}/imgfx/imgfx_data.py $in $out")

    ninja.rule("shape", command=f"$python {BUILD_TOOLS}/mapfs/shape.py $in $out")

    ninja.rule("effect_data", command=f"$python {BUILD_TOOLS}/effects.py $in_yaml $out_dir")

    ninja.rule("pm_sbn", command=f"$python {BUILD_TOOLS}/audio/sbn.py $out $asset_stack")

    with Path("tools/permuter_settings.toml").open("w") as f:
        f.write(f"compiler_command = \"{cc} {CPPFLAGS.replace('$version', 'pal')} {cflags} -DPERMUTER -fforce-addr\"\n")
        f.write(f'assembler_command = "{cross}as -EB -march=vr4300 -mtune=vr4300 -Iinclude"\n')
        f.write(f'compiler_type = "gcc"\n')
        f.write(
            """
[preserve_macros]
"gs?[DS]P.*" = "void"
OVERRIDE_FLAG_CHECK = "int"
OS_K0_TO_PHYSICAL = "int"
"G_.*" = "int"
"TEXEL.*" = "int"
PRIMITIVE = "int"

[decompme.compilers]
"tools/build/cc/gcc/gcc" = "gcc2.8.1"
"""
        )


def write_ninja_for_tools(ninja: ninja_syntax.Writer):
    ninja.rule(
        "cc_tool",
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

    def split(self, assets: bool, code: bool, shift: bool, debug: bool):
        import split

        modes = ["ld"]
        if assets:
            modes.extend(
                [
                    "bin",
                    "rodatabin",
                    "textbin",
                    "yay0",
                    "img",
                    "vtx",
                    "vtx_common",
                    "gfx",
                    "gfx_common",
                    "pm_map_data",
                    "pm_icons",
                    "pm_msg",
                    "pm_sprites",
                    "pm_charset",
                    "pm_charset_palettes",
                    "pm_effect_loads",
                    "pm_effect_shims",
                    "pm_sprite_shading_profiles",
                    "pm_imgfx_data",
                    "pm_sbn",
                ]
            )
        if code:
            modes.extend(["code", "c", "data", "rodata"])

        splat_files = [str(self.version_path / "splat.yaml")]
        if debug:
            splat_files += [str(self.version_path / "splat-debug.yaml")]

        if shift:
            splat_files += [str(self.version_path / "splat-shift.yaml")]

        split.main(
            splat_files,
            modes,
            verbose=False,
        )
        self.linker_entries = split.linker_writer.entries
        self.asset_stack: List[str] = split.config["asset_stack"]

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

            if path is not None:
                if path.is_dir():
                    out.extend(glob(str(path) + "/**/*", recursive=True))
                else:
                    out.append(str(path))

        return out

    # Given a directory relative to assets/, return a list of all assets in the directory
    # for all layers of the asset stack
    def get_asset_list(self, asset_dir: str) -> List[str]:
        ret: Dict[Path, Path] = {}

        for stack_dir in self.asset_stack:
            path_stem = f"assets/{stack_dir}/{asset_dir}"

            for p in Path(path_stem).glob("**/*"):
                glob_part = p.relative_to(path_stem)
                if glob_part not in ret:
                    ret[glob_part] = p

        return [str(v) for v in ret.values()]

    @lru_cache(maxsize=None)
    def resolve_asset_path(self, path: Path) -> Path:
        # Remove nonsense
        path = Path(os.path.normpath(path))

        parts = list(path.parts)

        if parts[0] != "assets":
            return path

        for asset_dir in self.asset_stack:
            parts[1] = asset_dir
            new_path = Path("/".join(parts))
            if new_path.exists():
                return new_path

        return path

    def write_ninja(
        self,
        ninja: ninja_syntax.Writer,
        skip_outputs: Set[str],
        non_matching: bool,
        modern_gcc: bool,
        c_maps: bool = False,
    ):
        import segtypes
        import segtypes.common.asm
        import segtypes.common.bin
        import segtypes.common.c
        import segtypes.common.data
        import segtypes.common.group
        import segtypes.common.rodatabin
        import segtypes.common.textbin
        import segtypes.n64.header
        import segtypes.n64.img
        import segtypes.n64.palette
        import segtypes.n64.yay0

        assert self.linker_entries is not None

        built_objects = set()
        generated_code = []

        def build(
            object_paths: Union[Path, List[Path]],
            src_paths: List[Path],
            task: str,
            variables: Dict[str, str] = {},
            implicit_outputs: List[str] = [],
            asset_deps: List[str] = [],
        ):
            if not isinstance(object_paths, list):
                object_paths = [object_paths]

            object_strs = [str(obj) for obj in object_paths]
            needs_build = False

            for object_path in object_paths:
                if object_path.suffixes[-1] == ".o":
                    built_objects.add(str(object_path))
                elif object_path.suffix.endswith(".h") or object_path.suffix.endswith(".c"):
                    generated_code.append(str(object_path))

                # don't rebuild objects if we've already seen all of them
                if not str(object_path) in skip_outputs:
                    needs_build = True

            for i_output in implicit_outputs:
                if i_output.endswith(".h"):
                    generated_code.append(i_output)

            if needs_build:
                skip_outputs.update(object_strs)

                implicit = []
                order_only = []

                if task == "yay0":
                    implicit.append(YAY0_COMPRESS_TOOL)
                elif task in ["cc", "cxx", "cc_modern"]:
                    order_only.append("generated_code_" + self.version)

                inputs = self.resolve_src_paths(src_paths)
                for dir in asset_deps:
                    inputs.extend(self.get_asset_list(dir))
                ninja.build(
                    outputs=object_strs,  # $out
                    rule=task,
                    inputs=inputs,  # $in
                    implicit=implicit,
                    order_only=order_only,
                    variables={"version": self.version, **variables},
                    implicit_outputs=implicit_outputs,
                )

        # Effect data includes
        effect_yaml = ROOT / "src/effects.yaml"
        effect_data_outdir = ROOT / "assets" / version / "effects"
        effect_macros_path = effect_data_outdir / "effect_macros.h"
        effect_defs_path = effect_data_outdir / "effect_defs.h"
        effect_table_path = effect_data_outdir / "effect_table.c"

        build(
            [effect_macros_path, effect_defs_path, effect_table_path],
            [effect_yaml],
            "effect_data",
            variables={
                "in_yaml": str(effect_yaml),
                "out_dir": str(effect_data_outdir),
            },
        )

        build(
            self.build_path() / "include/world_map.inc.c",
            [Path("src/world_map.xml")],
            "world_map",
        )

        build(
            self.build_path() / "include/recipes.inc.c",
            [Path("src/recipes.yaml")],
            "recipes",
        )

        build(
            [
                self.build_path() / "include/move_data.inc.c",
                self.build_path() / "include/move_enum.h",
            ],
            [Path("src/move_table.yaml")],
            "move_data",
        )

        build(
            [
                self.build_path() / "include/item_data.inc.c",
                self.build_path() / "include/item_enum.h",
            ],
            [
                Path("src/item_table.yaml"),
                Path("src/item_entity_scripts.yaml"),
                Path("src/item_hud_scripts.yaml"),
            ],
            "item_data",
        )

        build(
            [
                self.build_path() / "include/battle/actor_types.inc.c",
                self.build_path() / "include/battle/actor_types.h",
            ],
            [
                Path("src/battle/actors.yaml"),
            ],
            "actor_types",
        )

        # Build objects
        for entry in self.linker_entries:
            seg = entry.segment

            if seg.type == "linker" or seg.type == "linker_offset":
                continue

            assert entry.object_path is not None

            if isinstance(seg, segtypes.n64.header.N64SegHeader):
                build(entry.object_path, entry.src_paths, "as")
            elif isinstance(seg, segtypes.common.asm.CommonSegAsm) or (
                isinstance(seg, segtypes.common.data.CommonSegData) and not seg.type[0] == "."
            ):
                build(entry.object_path, entry.src_paths, "as")
            elif seg.type in ["pm_effect_loads", "pm_effect_shims"]:
                build(entry.object_path, entry.src_paths, "as")
            elif isinstance(seg, segtypes.common.c.CommonSegC) or (
                isinstance(seg, segtypes.common.data.CommonSegData) and seg.type[0] == "."
            ):
                cflags = None
                if isinstance(seg.yaml, dict):
                    cflags = seg.yaml.get("cflags")
                elif len(seg.yaml) >= 4:
                    cflags = seg.yaml[3]

                # default cflags where not specified
                if cflags is None:
                    if "nusys" in entry.src_paths[0].parts:
                        cflags = ""
                    elif "os" in entry.src_paths[0].parts:  # libultra
                        cflags = ""
                    else:  # papermario
                        cflags = "-fforce-addr"

                # c
                task = "cc"
                if entry.src_paths[0].suffixes[-1] == ".cpp":
                    task = "cxx"

                if modern_gcc:
                    task = "cc_modern"

                if seg.name.endswith("osFlash"):
                    task = "cc_ido"
                elif "gcc_272" in cflags:
                    task = "cc_272"
                    cflags = cflags.replace("gcc_272", "")
                elif "egcs" in cflags:
                    task = "cc_egcs"
                    cflags = cflags.replace("egcs", "")

                encoding = "CP932"  # similar to SHIFT-JIS, but includes backslash and tilde
                if version == "ique":
                    encoding = "EUC-JP"

                # Dead cod
                if isinstance(seg.parent.yaml, dict) and seg.parent.yaml.get("dead_code", False):
                    obj_path = str(entry.object_path)
                    init_obj_path = Path(obj_path + ".dead")
                    build(
                        init_obj_path,
                        entry.src_paths,
                        task,
                        variables={
                            "cflags": cflags,
                            "cppflags": f"-DVERSION_{self.version.upper()}",
                            "encoding": encoding,
                        },
                    )
                    build(
                        entry.object_path,
                        [init_obj_path],
                        "dead_cc_fix",
                    )
                # Not dead cod
                else:
                    if non_matching or seg.get_most_parent().name not in [
                        "main",
                        "engine1",
                        "engine2",
                    ]:
                        cflags += " -fno-common"
                    build(
                        entry.object_path,
                        entry.src_paths,
                        task,
                        variables={
                            "cflags": cflags,
                            "cppflags": f"-DVERSION_{self.version.upper()}",
                            "encoding": encoding,
                        },
                    )

                # images embedded inside data aren't linked, but they do need to be built into .inc.c files
                if isinstance(seg, segtypes.common.group.CommonSegGroup):
                    for seg in seg.subsegments:
                        if isinstance(seg, segtypes.n64.img.N64SegImg):
                            flags = ""
                            if seg.n64img.flip_h:
                                flags += "--flip-x "
                            if seg.n64img.flip_v:
                                flags += "--flip-y "

                            src_paths = [seg.out_path().relative_to(ROOT)]
                            inc_dir = self.build_path() / "include" / seg.dir
                            bin_path = self.build_path() / seg.dir / (seg.name + ".png.bin")

                            build(
                                bin_path,
                                src_paths,
                                "pigment",
                                variables={
                                    "img_type": seg.type,
                                    "img_flags": flags,
                                },
                            )

                            assert seg.vram_start is not None, "img with vram_start unset: " + seg.name

                            c_sym = seg.create_symbol(
                                addr=seg.vram_start,
                                in_segment=True,
                                type="data",
                                define=True,
                            )
                            name = c_sym.name
                            if "namespaced" in seg.args:
                                name = f"N({name[7:]})"
                            vars = {"c_name": name}
                            build(
                                inc_dir / (seg.name + ".png.h"),
                                src_paths,
                                "img_header",
                                vars,
                            )
                            build(
                                inc_dir / (seg.name + ".png.inc.c"),
                                [bin_path],
                                "bin_inc_c",
                                vars,
                            )
                        elif isinstance(seg, segtypes.n64.palette.N64SegPalette):
                            src_paths = [seg.out_path().relative_to(ROOT)]
                            inc_dir = self.build_path() / "include" / seg.dir
                            bin_path = self.build_path() / seg.dir / (seg.name + ".pal.bin")

                            build(
                                bin_path,
                                src_paths,
                                "pigment",
                                variables={
                                    "img_type": seg.type,
                                    "img_flags": "",
                                },
                            )

                            assert seg.vram_start is not None
                            c_sym = seg.create_symbol(
                                addr=seg.vram_start,
                                in_segment=True,
                                type="data",
                                define=True,
                            )
                            vars = {"c_name": c_sym.name}
                            build(
                                inc_dir / (seg.name + ".pal.inc.c"),
                                [bin_path],
                                "pal_inc_c",
                                vars,
                            )
            elif (
                isinstance(seg, segtypes.common.bin.CommonSegBin)
                or isinstance(seg, segtypes.common.textbin.CommonSegTextbin)
                or isinstance(seg, segtypes.common.rodatabin.CommonSegRodatabin)
            ):
                build(entry.object_path, entry.src_paths, "bin")
            elif isinstance(seg, segtypes.n64.yay0.N64SegYay0):
                compressed_path = entry.object_path.with_suffix("")  # remove .o
                build(compressed_path, entry.src_paths, "yay0")
                build(entry.object_path, [compressed_path], "bin")
            elif isinstance(seg, segtypes.n64.img.N64SegImg):
                flags = ""
                if seg.n64img.flip_h:
                    flags += "--flip-x "
                if seg.n64img.flip_v:
                    flags += "--flip-y "

                bin_path = entry.object_path.with_suffix(".bin")
                inc_dir = self.build_path() / "include" / seg.dir

                build(
                    bin_path,
                    entry.src_paths,
                    "pigment",
                    variables={
                        "img_type": seg.type,
                        "img_flags": flags,
                    },
                )
                build(entry.object_path, [bin_path], "bin")

                # c_sym = seg.create_symbol(
                #     addr=seg.vram_start, in_segment=True, type="data", define=True
                # )
                # vars = {"c_name": c_sym.name}
                build(inc_dir / (seg.name + ".png.h"), entry.src_paths, "img_header")
            elif isinstance(seg, segtypes.n64.palette.N64SegPalette):
                bin_path = entry.object_path.with_suffix(".bin")

                build(
                    bin_path,
                    entry.src_paths,
                    "pigment",
                    variables={
                        "img_type": seg.type,
                        "img_flags": "",
                    },
                )
                build(entry.object_path, [bin_path], "bin")
            elif seg.type == "pm_sprites":
                assert entry.object_path is not None

                sprite_yay0s = []

                npc_obj_path = entry.object_path.parent / "npc"

                # NPC sprite headers
                for sprite_id, sprite_dir in enumerate(entry.src_paths[1:], 1):
                    sprite_name = sprite_dir.name

                    bin_path = npc_obj_path / (sprite_name + ".bin")
                    yay0_path = bin_path.with_suffix(".Yay0")
                    sprite_yay0s.append(yay0_path)

                    build(
                        bin_path,
                        [sprite_dir],
                        "npc_sprite",
                        variables={
                            "sprite_name": sprite_name,
                            "asset_stack": ",".join(self.asset_stack),
                        },
                        asset_deps=[str(sprite_dir)],
                    )
                    build(yay0_path, [bin_path], "yay0")

                    # NPC sprite header
                    build(
                        self.build_path() / "include/sprite/npc" / (sprite_name + ".h"),
                        [sprite_dir, yay0_path],
                        "sprite_header",
                        variables={
                            "sprite_name": sprite_name,
                            "sprite_id": str(sprite_id),
                            "asset_stack": ",".join(self.asset_stack),
                        },
                    )

                # Sprites .bin
                sprite_player_header_path = str(self.build_path() / "include/sprite/player.h")

                build(
                    entry.object_path.with_suffix(".bin"),
                    [entry.src_paths[0], *sprite_yay0s],
                    "sprites",
                    variables={
                        "header_out": sprite_player_header_path,
                        "build_dir": str(self.build_path() / "assets" / self.version / "sprite"),
                        "asset_stack": ",".join(self.asset_stack),
                    },
                    implicit_outputs=[sprite_player_header_path],
                    asset_deps=["sprite/player"],
                )

                # Sprites .o
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")

            elif seg.type == "pm_msg":
                msg_bins = []

                for section_idx, msg_path in enumerate(entry.src_paths):
                    bin_path = entry.object_path.with_suffix("") / f"{section_idx:02X}.bin"
                    msg_bins.append(bin_path)
                    build(bin_path, [msg_path], "msg")

                build(
                    [
                        entry.object_path.with_suffix(".bin"),
                        self.build_path() / "include" / "message_ids.h",
                    ],
                    msg_bins,
                    "msg_combine",
                )
                build(entry.object_path, [entry.object_path.with_suffix(".bin")], "bin")

            elif seg.type == "pm_icons":
                # make icons.bin
                header_path = str(self.build_path() / "include" / "icon_offsets.h")
                build(
                    entry.object_path.with_suffix(""),
                    entry.src_paths,
                    "icons",
                    variables={
                        "list_path": entry.src_paths[0],
                        "header_path": header_path,
                        "asset_stack": ",".join(self.asset_stack),
                    },
                    implicit_outputs=[header_path],
                    asset_deps=["icon"],
                )
                # make icons.bin.o
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")

            elif seg.type == "pm_map_data":
                # flat list of (uncompressed path, compressed? path) pairs
                bin_yay0s: List[Path] = []
                src_dir = Path("assets/x") / seg.name

                for path in entry.src_paths:
                    name = path.stem
                    out_dir = entry.object_path.with_suffix("").with_suffix("")
                    bin_path = out_dir / f"{name}.bin"

                    if name.startswith("party_"):
                        compress = True
                        build(
                            bin_path,
                            [path],
                            "img",
                            variables={
                                "img_type": "party",
                                "img_flags": "",
                            },
                        )
                    elif name == "title_data":
                        compress = True

                        logotype_path = out_dir / "title_logotype.bin"
                        copyright_path = out_dir / "title_copyright.bin"
                        copyright_pal_path = out_dir / "title_copyright.pal"  # jp only
                        press_start_path = out_dir / "title_press_start.bin"

                        build(
                            logotype_path,
                            [src_dir / "title/logotype.png"],
                            "pigment",
                            variables={
                                "img_type": "rgba32",
                                "img_flags": "",
                            },
                        )
                        build(
                            press_start_path,
                            [src_dir / "title/press_start.png"],
                            "pigment",
                            variables={
                                "img_type": "ia8",
                                "img_flags": "",
                            },
                        )

                        if self.version == "jp":
                            build(
                                copyright_path,
                                [src_dir / "title/copyright.png"],
                                "pigment",
                                variables={
                                    "img_type": "ci4",
                                    "img_flags": "",
                                },
                            )
                            build(
                                copyright_pal_path,
                                [src_dir / "title/copyright.png"],
                                "pigment",
                                variables={
                                    "img_type": "palette",
                                    "img_flags": "",
                                },
                            )
                            imgs = [
                                logotype_path,
                                copyright_path,
                                press_start_path,
                                copyright_pal_path,
                            ]
                        else:
                            build(
                                copyright_path,
                                [src_dir / "title/copyright.png"],
                                "pigment",
                                variables={
                                    "img_type": "ia8",
                                    "img_flags": "",
                                },
                            )
                            imgs = [logotype_path, copyright_path, press_start_path]

                        build(bin_path, imgs, "pack_title_data")
                    elif name.endswith("_bg"):
                        compress = True
                        build(
                            bin_path,
                            [path],
                            "img",
                            variables={
                                "img_type": "bg",
                                "img_flags": "",
                            },
                        )
                    elif name.endswith("_tex"):
                        compress = False
                        tex_dir = path.parent / name
                        build(
                            bin_path,
                            [tex_dir, path.parent / (name + ".json")],
                            "tex",
                            variables={
                                "tex_name": name,
                                "asset_stack": ",".join(self.asset_stack),
                            },
                            asset_deps=[f"mapfs/tex/{name}"],
                        )
                    elif name.endswith("_shape_built"):
                        base_name = name[:-6]
                        raw_bin_path = self.resolve_asset_path(f"assets/x/mapfs/geom/{base_name}.bin")
                        bin_path = bin_path.parent / "geom" / (base_name + ".bin")

                        if c_maps:
                            # raw bin -> c -> o -> elf -> objcopy -> final bin file
                            c_file_path = (bin_path.parent / "geom" / base_name).with_suffix(".c")
                            o_path = bin_path.parent / "geom" / (base_name + ".o")
                            elf_path = bin_path.parent / "geom" / (base_name + ".elf")

                            build(c_file_path, [raw_bin_path], "shape")
                            build(
                                o_path,
                                [c_file_path],
                                "cc" if not modern_gcc else "cc_modern",
                                variables={
                                    "cflags": "",
                                    "cppflags": f"-DVERSION_{self.version.upper()}",
                                    "encoding": "CP932",  # similar to SHIFT-JIS, but includes backslash and tilde
                                },
                            )
                            build(elf_path, [o_path], "shape_ld")
                            build(bin_path, [elf_path], "shape_objcopy")
                        else:
                            build(bin_path, [raw_bin_path], "cp")

                        compress = True
                        out_dir = out_dir / "geom"
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
                    build(
                        out_path,
                        [src_path],
                        "pigment",
                        variables={
                            "img_type": "ci4",
                            "img_flags": "",
                        },
                    )
                    rasters.append(out_path)

                build(entry.object_path.with_suffix(""), rasters, "charset")
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
            elif seg.type == "pm_charset_palettes":
                palettes = []

                for src_path in entry.src_paths:
                    out_path = self.build_path() / seg.dir / seg.name / "palette" / (src_path.stem + ".bin")
                    build(
                        out_path,
                        [src_path],
                        "pigment",
                        variables={
                            "img_type": "palette",
                            "img_flags": "",
                        },
                    )
                    palettes.append(out_path)

                build(entry.object_path.with_suffix(""), palettes, "charset_palettes")
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
            elif seg.type == "pm_sprite_shading_profiles":
                header_path = str(self.build_path() / "include/sprite/sprite_shading_profiles.h")
                build(
                    entry.object_path.with_suffix(""),
                    entry.src_paths,
                    "sprite_shading_profiles",
                    implicit_outputs=[header_path],
                    variables={
                        "header_path": header_path,
                    },
                )
                build(entry.object_path, [entry.object_path.with_suffix("")], "bin")
            elif seg.type == "pm_sbn":
                sbn_path = entry.object_path.with_suffix("")
                build(
                    sbn_path,
                    entry.src_paths,
                    "pm_sbn",
                    variables={
                        "asset_stack": ",".join(self.asset_stack),
                    },
                    asset_deps=entry.src_paths,
                )
                build(entry.object_path, [sbn_path], "bin")
            elif seg.type == "linker" or seg.type == "linker_offset":
                pass
            elif seg.type == "pm_imgfx_data":
                c_file_path = Path(f"assets/{self.version}") / "imgfx" / (seg.name + ".c")
                build(c_file_path, entry.src_paths, "imgfx_data")

                build(
                    entry.object_path,
                    [c_file_path],
                    "cc" if not modern_gcc else "cc_modern",
                    variables={
                        "cflags": "",
                        "cppflags": f"-DVERSION_{self.version.upper()}",
                        "encoding": "CP932",  # similar to SHIFT-JIS, but includes backslash and tilde
                    },
                )
            else:
                raise Exception(f"don't know how to build {seg.__class__.__name__} '{seg.name}'")

        # Run undefined_syms through cpp
        ninja.build(
            str(self.undefined_syms_path()),
            "cpp",
            str(self.version_path / "undefined_syms.txt"),
        )

        # Build elf, z64, ok
        additional_objects = [str(self.undefined_syms_path())]

        ninja.build(
            str(self.elf_path()),
            "ld",
            str(self.linker_script_path()),
            implicit=[str(obj) for obj in built_objects] + additional_objects,
            variables={"version": self.version, "mapfile": str(self.map_path())},
        )

        if self.version == "ique":
            ninja.build(
                str(self.rom_path()),
                "z64_ique",
                str(self.elf_path()),
                variables={"version": self.version},
            )
        else:
            ninja.build(
                str(self.rom_path()),
                "z64",
                str(self.elf_path()),
                implicit=[CRC_TOOL],
                variables={"version": self.version},
            )

        if not non_matching:
            ninja.build(
                str(self.rom_ok_path()),
                "sha1sum",
                f"ver/{self.version}/checksum.sha1",
                implicit=[str(self.rom_path())],
            )

        ninja.build("generated_code_" + self.version, "phony", generated_code)

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
    parser.add_argument(
        "version",
        nargs="*",
        default=[],
        choices=[*VERSIONS, []],
        help="Version(s) to configure for. Most tools will operate on the first-provided only. Supported versions: "
        + ",".join(VERSIONS),
    )
    parser.add_argument("--cpp", help="GNU C preprocessor command")
    parser.add_argument(
        "-c",
        "--clean",
        action="store_true",
        help="Delete assets and previously-built files",
    )
    parser.add_argument("--splat", default="tools/splat", help="Path to splat tool to use")
    parser.add_argument("--split-code", action="store_true", help="Re-split code segments to asm files")
    parser.add_argument(
        "--no-split-assets",
        action="store_true",
        help="Don't split assets from the baserom(s)",
    )
    parser.add_argument("-d", "--debug", action="store_true", help="Generate debugging information")
    parser.add_argument(
        "-n",
        "--non-matching",
        action="store_true",
        help="Compile nonmatching code. Combine with --debug for more detailed debug info",
    )
    parser.add_argument(
        "--shift",
        action="store_true",
        help="Build a shiftable version of the game (non-matching)",
    )
    parser.add_argument(
        "--modern-gcc",
        action="store_true",
        help="Use modern GCC instead of the original compiler",
    )
    parser.add_argument("--ccache", action="store_true", help="Use ccache")
    parser.add_argument(
        "--c-maps",
        action="store_true",
        help="Convert map binaries to C as part of the build process",
    )
    args = parser.parse_args()

    exec_shell(["make", "-C", str(ROOT / args.splat)])

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if (
        args.cpp is None
        and sys.platform == "darwin"
        and "Free Software Foundation" not in exec_shell(["cpp", "--version"])
    ):
        gcc_cpps = ("cpp-14", "cpp-13", "cpp-12", "cpp-11")
        for ver in gcc_cpps:
            try:
                if "Free Software Foundation" in exec_shell([ver, "--version"]):
                    args.cpp = ver
                    break
            except FileNotFoundError:
                pass
        if args.cpp is None:
            print("error: system C preprocessor is not GNU!")
            print("This is a known issue on macOS - only clang's cpp is installed by default.")
            print("Use 'brew' to obtain GNU cpp, then run this script again with the --cpp option, e.g.")
            print(f"    ./configure --cpp {gcc_cpps[0]}")
            exit(1)

    try:
        version = exec_shell([PIGMENT, "--version"]).split(" ")[1].strip()

        if version < PIGMENT_REQ_VERSION:
            print(f"error: {PIGMENT} version {PIGMENT_REQ_VERSION} or newer is required, system version is {version}\n")
            exit(1)
    except (FileNotFoundError, PermissionError):
        print(f"error: {PIGMENT} is not installed\n")
        print("To build and install it, obtain cargo:\n\tcurl https://sh.rustup.rs -sSf | sh")
        print(f"and then run:\n\tcargo install {PIGMENT}")
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
            shutil.rmtree(ROOT / f"assets/{version}", ignore_errors=True)
            shutil.rmtree(ROOT / f"ver/{version}/assets", ignore_errors=True)
            shutil.rmtree(ROOT / f"ver/{version}/build", ignore_errors=True)
            try:
                os.remove(ROOT / f"ver/{version}/.splat_cache")
            except OSError:
                pass

    extra_cflags = ""
    extra_cppflags = ""
    if args.non_matching:
        extra_cppflags += " -DNON_MATCHING"

        if args.debug:
            extra_cflags += " -ggdb3"  # we can generate more accurate debug info in non-matching mode
            extra_cppflags += " -DDEBUG"  # e.g. affects ASSERT macro
    elif args.debug:
        # g1 doesn't affect codegen
        extra_cflags += " -ggdb3"

    if args.shift:
        extra_cppflags += " -DSHIFT"

    extra_cflags += " -Wmissing-braces -Wimplicit -Wredundant-decls -Wstrict-prototypes -Wno-redundant-decls"

    # add splat to python import path
    sys.path.insert(0, str((ROOT / args.splat).resolve()))

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    non_matching = args.non_matching or args.modern_gcc or args.shift

    write_ninja_rules(
        ninja,
        args.cpp or "cpp",
        extra_cppflags,
        extra_cflags,
        args.ccache,
        args.shift,
        args.debug,
    )
    write_ninja_for_tools(ninja)

    skip_files: Set[str] = set()
    all_rom_oks: List[str] = []
    first_configure = None

    for version in versions:
        print(f"configure: configuring version {version}")

        configure = Configure(version)

        if not first_configure:
            first_configure = configure

        # include tools/splat_ext in the python path
        sys.path.append(str((ROOT / "tools/splat_ext").resolve()))

        configure.split(not args.no_split_assets, args.split_code, args.shift, args.debug)
        configure.write_ninja(ninja, skip_files, non_matching, args.modern_gcc, args.c_maps)

        all_rom_oks.append(str(configure.rom_ok_path()))

    assert first_configure
    first_configure.make_current(ninja)

    if non_matching:
        ninja.build("all", "phony", [str(first_configure.rom_path())])
    else:
        ninja.build("all", "phony", all_rom_oks)
    ninja.default("all")
