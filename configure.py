#!/usr/bin/env python3

import re
import os, sys
from glob import glob
import ninja_syntax
from argparse import ArgumentParser
import asyncio
from subprocess import PIPE
import subprocess

sys.path.append(os.path.dirname(__file__) + "/tools/splat")
import split
from segtypes.n64.code import Subsegment

INCLUDE_ASM_RE = re.compile(r"___INCLUDE_ASM\([^,]+, ([^,]+), ([^,)]+)") # note _ prefix
SUPPORTED_VERSIONS = ["us", "jp"]
TARGET = "papermario"

def obj(path: str):
    if not path.startswith("ver/"):
        path = f"ver/{version}/build/{path}"
    path = re.sub(r"/assets/", "/build/", path) # XXX what about other asset dirs?
    return path + ".o"

def read_splat(splat_config: str, version: str):
    import argparse
    import yaml
    from segtypes.n64.code import N64SegCode
    from util import options

    # Load config
    with open(splat_config) as f:
        config = yaml.safe_load(f.read())

    options.initialize(config)
    assert options.get("ld_o_replace_extension", True) == False

    # Initialize segments
    all_segments = split.initialize_segments(splat_config, config["segments"])

    objects = set()
    segments = {}

    for segment in all_segments:
        for subdir, path, obj_type, start in segment.get_ld_files():
            # src workaround
            if subdir.startswith("../../"):
                subdir = subdir[6:]
            if path.endswith(".c") or path.endswith(".s") or path.endswith(".data") or path.endswith(".rodata"):
                path = subdir + "/" + path
            else:
                assert subdir == "assets", subdir + " " + path
                subdir = "ver/" + version + "/assets"

            objects.add(path)
            segments[path] = segment

        if isinstance(segment, N64SegCode):
            for split_file in segment.subsegments:
                if split_file.type in ["i4", "i8", "ia4", "ia8", "ia16", "rgba16", "rgba32", "ci4", "ci8", "palette"]:
                    path = os.path.join(
                        #segment.get_subdir(split_file["subtype"]),
                        split_file.name + "." + split_file.get_ext()
                    )

                    if path in segments:
                        segments[path] = split_file

    # note: `objects` lacks .o extensions
    return objects, segments

def rm_recursive(path):
    from pathlib import Path

    path = Path(path)

    if path.exists():
        if path.is_dir():
            for f in path.iterdir():
                rm_recursive(f)

            path.rmdir()
        else:
            path.unlink()

async def shell(cmd: str):
    async with task_sem:
        proc = await asyncio.create_subprocess_shell(cmd, stdout=PIPE, stderr=PIPE)
        stdout, stderr = await proc.communicate()

    assert proc.returncode == 0, f"{cmd} failed: {stderr}"

    return stdout.decode("utf-8"), stderr.decode("utf-8")

async def shell_status(cmd: str):
    async with task_sem:
        proc = await asyncio.create_subprocess_shell(cmd, stdout=PIPE, stderr=PIPE)
        stdout, stderr = await proc.communicate()

    return proc.returncode

def build_yay0_file(bin_file: str):
    yay0_file = f"ver/{version}/build/{os.path.splitext(bin_file)[0]}.Yay0"
    n.build(yay0_file, "yay0compress", find_asset(bin_file), implicit="tools/Yay0compress")
    build_bin_object(yay0_file)

def build_bin_object(bin_file: str):
    n.build(obj(bin_file), "bin", bin_file)

def build_image(f: str, segment):
    path, img_type, png = f.rsplit(".", 2)
    out = f"ver/{version}/build/" + path + "." + img_type + ".png"

    flags = ""
    if img_type != "palette" and not isinstance(segment, dict):
        if segment.flip_horizontal:
            flags += "--flip-x"
        if segment.flip_vertical:
            flags += "--flip-y"

    n.build(out, "img", find_asset(path + ".png"), implicit="tools/img/build.py", variables={
        "img_type": img_type,
        "img_flags": flags,
    })
    build_bin_object(out)

def cmd_exists(cmd):
    return subprocess.call("type " + cmd, shell=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE) == 0

def find_asset_dir(path):
    global ASSET_DIRS
    for d in ASSET_DIRS:
        if os.path.exists(d + "/" + path):
            return d

    print("Unable to find asset: " + path)
    print("The asset dump may be incomplete. Try:")
    print("    ./configure.py --clean")
    exit(1)

def find_asset(path):
    return find_asset_dir(path) + "/" + path

async def main():
    global n, cpp, task_sem, num_tasks, num_tasks_done, ASSET_DIRS, version

    task_sem = asyncio.Semaphore(8)

    parser = ArgumentParser(description="Paper Mario build.ninja generator")
    parser.add_argument("version", nargs="*", default=[], help="Version(s) to configure for. Most tools will operate on the first-provided only. Supported versions: " + ','.join(SUPPORTED_VERSIONS))
    parser.add_argument("--cpp", help="GNU C preprocessor command")
    parser.add_argument("--cflags", default="", help="Extra cc/cpp flags")
    parser.add_argument("--no-splat", action="store_true", help="Don't split assets from the baserom(s)")
    parser.add_argument("--clean", action="store_true", help="Delete assets and previously-built files")
    parser.add_argument("--depend-on-s", action="store_true", help="Configure dependencies on .s files for c files that include them")
    args = parser.parse_args()
    versions = args.version

    # default version behaviour is to only do those that exist
    if len(versions) == 0:
        for version in SUPPORTED_VERSIONS:
            rom = f"ver/{version}/baserom.z64"
            if os.path.exists(rom):
                versions.append(version)

        if len(versions) == 0:
            print("error: no baserom.z64 files could be found in the ver/*/ directories.")
            exit(1)

    print("Configuring for versions: " + ', '.join(versions))
    print("")

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if args.cpp is None and sys.platform == "darwin" and "Free Software Foundation" not in (await shell("cpp --version"))[0]:
        print("error: system C preprocessor is not GNU!")
        print("This is a known issue on macOS - only clang's cpp is installed by default.")
        print("Use 'brew' to obtain GNU cpp, then run this script again with the --cpp option, e.g.")
        print("    ./configure.py --cpp cpp-10")
        exit(1)

    cpp = args.cpp or "cpp"

    if args.clean:
        print("Cleaning...")
        await shell("ninja -t clean")
        rm_recursive(f".splat_cache")

        for version in versions:
            rm_recursive(f"ver/{version}/assets")
            rm_recursive(f"ver/{version}/build")
            rm_recursive(f"ver/{version}/.splat_cache")

    if not args.no_splat:
        # compile splat dependencies
        await shell("make -C tools/splat")

        has_any_rom = False
        for version in versions:
            rom = f"ver/{version}/baserom.z64"
            has_rom = False

            try:
                with open(rom, "rb") as f:
                    has_rom = True
                    has_any_rom = True
            except IOError:
                print(f"error: could not find baserom file '{rom}'!")
                if len(versions) >= 2:
                    print(f"You can avoid building version '{version}' by specifying versions on the command-line:")
                    print(f"    ./configure.py {' '.join(ver for ver in versions if ver != version)}")
                exit(1)

            if has_rom:
                print(f"Splitting assets from {rom}", end="")
                split.main(
                    f"ver/{version}/splat.yaml",
                    f"ver/{version}",
                    rom,
                    [ "ld", "bin", "Yay0", "PaperMarioMapFS", "PaperMarioMessages", "img", "PaperMarioNpcSprites" ],
                    False,
                    False,
                )
                print("")

    print("Configuring build...")

    n = ninja_syntax.Writer(open("build.ninja", "w"), width=120)

    cflags = " " + args.cflags
    iconv = "tools/iconv.py UTF-8 SHIFT-JIS" if sys.platform == "darwin" else "iconv --from UTF-8 --to SHIFT-JIS"
    cross = "mips-linux-gnu-"

    n.variable("target", TARGET)
    n.variable("cross", cross)
    n.variable("python", sys.executable)

    if sys.platform  == "darwin":
        os_dir = "mac"
    elif sys.platform == "linux":
        if os.uname()[4] == "aarch64":
            os_dir = "arm"
        else:
            os_dir = "linux"
    else:
        print(f"Unsupported platform {sys.platform}")
        sys.exit(1)

    # $version
    n.rule("cc",
        command=f"bash -o pipefail -c '{cpp} -Iver/$version/build/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 {args.cflags} -MD -MF $out.d $in -o - | {iconv} | tools/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow {args.cflags} -o - | tools/{os_dir}/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        description="cc $in",
        depfile="$out.d",
        deps="gcc")
    n.rule("cc_dsl",
        command=f"bash -o pipefail -c '{cpp} -Iver/$version/build/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 {args.cflags} -MD -MF $out.d $in -o - | $python tools/compile_dsl_macros.py | {iconv} | tools/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow {args.cflags} -o - | tools/{os_dir}/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        description="dsl $in",
        depfile="$out.d",
        deps="gcc")
    n.newline()
    # KMC gcc crashes if the argument string is too long, so preprocess input separately to minimize arguments
    # KMC gcc doesn't support input on stdin, so a temp file has to be made for the preprocessor output
    n.rule("cc_kmc",
        command=f"bash -o pipefail -c '{cpp} -Iver/$version/build/include -Iinclude -Iinclude/PR -Isrc -D _LANGUAGE_C -D _FINALROM -D VERSION=$version -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 {args.cflags} -MD -MF $out.d $in -o $out.i && export WINEPATH=tools/kmc/BIN && wine exew32 gcc -O3 -c -G0 -mgp32 -mfp32 -mips3 $out.i -o $out' && {cross}strip $out -N $in",
        description="kmc $in",
        depfile="$out.d",
        deps="gcc")
    n.newline()

    with open("tools/permuter_settings.toml", "w") as f:
        version = versions[0]
        f.write(f"compiler_command = \"{cpp} -Iver/{version}/build/include -Iinclude -Isrc -DPERMUTER -D _LANGUAGE_C -D _FINALROM -D VERSION={version} -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 {args.cflags} -D SCRIPT(...)={{}} | {iconv} | tools/{os_dir}/cc1 -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow {args.cflags} -o - | tools/{os_dir}/mips-nintendo-nu64-as -EB -G 0 -\"\n")
        f.write(f"assembler_command = \"{cross}as -march=vr4300 -mabi=32\"\n")
        f.write("\n")
        f.write("[preserve_macros]\n")
        f.write("\"g[DS]P.*\" = \"void\"\n")

    # $version
    n.rule("cpp",
        command=f"{cpp} -P -DBUILD_DIR=ver/$version/build $in -o $out",
        description="cpp $in",
        depfile="$out.d",
        deps="gcc")
    n.newline()

    n.rule("yay0compress",
        command=f"tools/Yay0compress $in $out",
        description="compress $in")
    n.newline()

    n.rule("bin",
        command="${cross}ld -r -b binary $in -o $out",
        description="bin $in")
    n.newline()

    n.rule("as",
        command="${cross}as -EB -O0 -G0 -mtune=vr4300 -march=vr4300 -mabi=32 -Iinclude $in -o $out",
        description="assemble $in")
    n.newline()

    # $img_type, $img_flags
    n.rule("img",
        command="$python tools/img/build.py $img_type $in $out $img_flags",
        description="image $in")
    n.rule("img_header",
        command="$python tools/img/header.py $in $out",
        description="image_header $in")
    n.newline()

    # $sprite_id, $sprite_dir, $sprite_name
    n.rule("sprite_animations_h",
        command="$python tools/gen_sprite_animations_h.py $out $sprite_dir $sprite_id",
        description="sprite_animations_h $sprite_name ($sprite_id)")
    n.rule("npc_sprite",
        command="$python tools/compile_npc_sprite.py $out $sprite_dir",
        description="npc_sprite $sprite_name ($sprite_id)")
    n.rule("npc_sprites",
        command="$python tools/compile_npc_sprites.py $out $in",
        description="package npc sprites")
    n.newline()

    n.rule("ld_addrs_h",
        command="grep -E \"[^\. ]+ =\" $in -o | sed 's/^/extern void* /; s/ =/;/' > $out",
        description="ld_addrs_h $in")
    n.newline()

    n.rule("msg_combine",
        command="$python tools/msg/combine.py $out $in",
        description="combine messages")
    n.rule("msg",
        command="$python tools/msg/parse_compile.py $in $out",
        description="msg $in")
    n.newline()

    n.rule("assets",
        command="$python tools/build_assets_bin.py $out $in",
        description="combine assets")
    n.newline()

    # $version
    n.rule("link",
        command="${cross}ld -T ver/$version/undefined_syms.txt -T ver/$version/undefined_syms_auto.txt -T ver/$version/undefined_funcs_auto.txt  -T ver/$version/dead_syms.txt -Map ver/$version/build/$target.map --no-check-sections -T $in -o $out",
        description="link $out")
    n.newline()

    n.rule("rom",
        command="${cross}objcopy $in $out -O binary && tools/n64crc $out",
        description="rom $in")
    n.newline()

    # $version
    n.rule("checksum",
        command=f"sha1sum -c ver/$version/checksum.sha1 && touch $out",
        description="compare")
    n.newline()

    n.rule("cc_modern_exe", command="cc $in -O3 -o $out")
    n.newline()

    for version in versions:
        objects, segments = read_splat(f"ver/{version}/splat.yaml", version) # no .o extensions!
        #c_files = (f for f in objects if f.endswith(".c"))

        n.build(f"ver/{version}/build/$target.ld", "cpp", f"ver/{version}/$target.ld", variables={ "version": version })
        n.build(f"ver/{version}/build/$target.elf", "link", f"ver/{version}/build/$target.ld", implicit=[obj(o) for o in objects], implicit_outputs=f"ver/{version}/$target.map", variables={ "version": version })
        n.build(f"ver/{version}/build/$target.z64", "rom", f"ver/{version}/build/$target.elf", implicit="tools/n64crc")
        n.build(f"ver/{version}/build/ok", "checksum", implicit=f"ver/{version}/build/$target.z64", variables={ "version": version })
        n.build(version, "phony", f"ver/{version}/build/ok")
        n.build(f"$target.{version}.z64", "phony", f"ver/{version}/build/$target.z64")

        CFG = {}
        with open(f"ver/{version}/build.cfg", "r") as f:
            for line in f.readlines():
                if line.strip() != "":
                    key, value = [part.strip() for part in line.split("=", 1)]
                    CFG[key] = value

        ASSET_DIRS = CFG.get("asset_dirs", "assets").split(" ")

        NPC_SPRITES = CFG.get("npc_sprites", "").split(" ")
        MAPS = CFG.get("maps", "").split(" ")
        TEXTURE_ARCHIVES = CFG.get("texture_archives", "").split(" ")
        BACKGROUNDS = CFG.get("backgrounds", "").split(" ")
        PARTY_IMAGES = CFG.get("party_images", "").split(" ")

        ASSETS = sum([[f"{map_name}_shape", f"{map_name}_hit"] for map_name in MAPS], []) + TEXTURE_ARCHIVES + BACKGROUNDS + ["title_data"] + PARTY_IMAGES

        generated_headers = []

        def add_generated_header(h: str):
            generated_headers.append(h)

            if not os.path.exists(h):
                # mkdir -p
                os.makedirs(os.path.dirname(h), exist_ok=True)

                # touch it so cpp doesn't complain if its #included
                open(h, "w").close()

                # mark it as really old so ninja builds it
                os.utime(h, (0, 0))

            return h

        n.build(add_generated_header(f"ver/{version}/build/include/ld_addrs.h"), "ld_addrs_h", f"ver/{version}/build/$target.ld")

        # messages
        msg_files = set()
        for d in ASSET_DIRS:
            for f in glob(d + "/msg/**/*.msg", recursive=True):
                msg_files.add(find_asset(f[len(d)+1:]))
        msg_files = list(msg_files)
        for msg_file in msg_files:
            n.build(
                f"ver/{version}/build/{msg_file.split('/', 1)[1]}.bin",
                "msg",
                msg_file,
                implicit="tools/msg/parse_compile.py",
            )
        msg_bins = [f"ver/{version}/build/{msg_file.split('/', 1)[1]}.bin" for msg_file in msg_files]
        n.build(
            [f"ver/{version}/build/msg.bin", add_generated_header(f"ver/{version}/build/include/message_ids.h")],
            "msg_combine",
            msg_bins,
            implicit="tools/msg/combine.py",
        )
        n.build(f"ver/{version}/build/msg.o", "bin", f"ver/{version}/build/msg.bin")

        # sprites
        npc_sprite_yay0s = []
        for sprite_id, sprite_name in enumerate(NPC_SPRITES, 1):
            if len(sprite_name) == 0 or sprite_name == "_":
                continue

            asset_dir = find_asset_dir(f"sprite/npc/{sprite_name}")
            sources = glob(f"{asset_dir}/sprite/npc/{sprite_name}/**/*.*", recursive=True)
            variables = {
                "sprite_name": sprite_name,
                "sprite_dir": f"{asset_dir}/sprite/npc/{sprite_name}",
                "sprite_id": sprite_id,
            }

            # generated header
            n.build(
                add_generated_header(f"ver/{version}/build/include/sprite/npc/{sprite_name}.h"),
                "sprite_animations_h",
                implicit=sources + ["tools/gen_sprite_animations_h.py"],
                variables=variables,
            )

            # sprite bin/yay0
            n.build(
                f"ver/{version}/build/sprite/npc/{sprite_name}",
                "npc_sprite",
                implicit=sources + ["tools/compile_npc_sprite.py"],
                variables=variables,
            )
            yay0 = f"ver/{version}/build/sprite/npc/{sprite_name}.Yay0"
            npc_sprite_yay0s.append(yay0)
            n.build(
                yay0,
                "yay0compress",
                f"ver/{version}/build/sprite/npc/{sprite_name}",
                implicit=["tools/Yay0compress"],
            )

        n.newline()

        # fast tasks
        for f in objects:
            segment = segments[f]

            if f.endswith(".c"):
                continue # these are handled later
            elif f.endswith(".Yay0"):
                build_yay0_file(os.path.splitext(f)[0] + ".bin")
            elif f.endswith(".bin"):
                build_bin_object(find_asset(f))
            elif f.endswith(".data"):
                n.build(obj(f), "as", f"ver/{version}/asm/" + f + ".s")
            elif f.endswith(".rodata"):
                n.build(obj(f), "as", f"ver/{version}/asm/" + f[2:] + ".s")
            elif f.endswith(".s"):
                n.build(obj(f), "as", f"ver/{version}/" + f)
            elif f.endswith(".png"):
                if isinstance(segment, Subsegment):
                    # image within a code section
                    out = f"ver/{version}/build/{f}.bin"
                    infile = find_asset(re.sub(r"\.pal\.png", ".png", f))

                    n.build(out, "img", infile, implicit="tools/img/build.py", variables={
                        "img_type": segment.type,
                        "img_flags": "",
                    })

                    if ".pal.png" not in f:
                        n.build(add_generated_header(f"ver/{version}/build/include/" + f + ".h"), "img_header", infile, implicit="tools/img/header.py")

                    n.build(f"ver/{version}/build/{f}.o", "bin", out)
                else:
                    build_image(f, segment)
            elif f == "sprite/npc":
                # combine sprites
                n.build(f"ver/{version}/build/{f}.bin", "npc_sprites", npc_sprite_yay0s, implicit="tools/compile_npc_sprites.py")
                n.build(obj(f), "bin", f"ver/{version}/build/{f}.bin")
            elif segment.type == "PaperMarioMessages":
                continue # done already above
            elif segment.type == "PaperMarioMapFS":
                asset_files = [] # even indexes: uncompressed; odd indexes: compressed

                for asset_name in ASSETS:
                    if asset_name.endswith("_tex"): # uncompressed
                        asset_files.append(find_asset(f"map/{asset_name}.bin"))
                        asset_files.append(find_asset(f"map/{asset_name}.bin"))
                    elif asset_name.startswith("party_"):
                        source_file = f"ver/{version}/build/{asset_name}.bin"
                        asset_file = f"ver/{version}/build/{asset_name}.Yay0"

                        n.build(source_file, "img", find_asset(f"party/{asset_name}.png"), implicit="tools/img/build.py", variables={
                            "img_type": "party",
                            "img_flags": "",
                        })

                        asset_files.append(source_file)
                        asset_files.append(asset_file)
                        n.build(asset_file, "yay0compress", source_file, implicit="tools/Yay0compress")
                    elif asset_name.endswith("_bg"):
                        source_file = f"ver/{version}/build/{asset_name}.bin"
                        asset_file = f"ver/{version}/build/{asset_name}.Yay0"

                        n.build(source_file, "img", find_asset(f"map/{asset_name}.png"), implicit="tools/img/build.py", variables={
                            "img_type": "bg",
                            "img_flags": "",
                        })

                        asset_files.append(source_file)
                        asset_files.append(asset_file)
                        n.build(asset_file, "yay0compress", source_file, implicit="tools/Yay0compress")
                    elif asset_name.endswith("_shape") or asset_name.endswith("_hit"):
                        source_file = find_asset(f"map/{asset_name}.bin")
                        asset_file = f"ver/{version}/build/assets/{asset_name}.Yay0"

                        asset_files.append(source_file)
                        asset_files.append(asset_file)
                        n.build(asset_file, "yay0compress", source_file, implicit="tools/Yay0compress")
                    else:
                        source_file = find_asset(f"{asset_name}.bin")
                        asset_file = f"ver/{version}/build/assets/{asset_name}.Yay0"

                        asset_files.append(source_file)
                        asset_files.append(asset_file)
                        n.build(asset_file, "yay0compress", source_file, implicit="tools/Yay0compress")

                n.build(f"ver/{version}/build/assets.bin", "assets", asset_files)
                n.build(obj(f), "bin", f"ver/{version}/build/assets.bin")
            else:
                print("warning: dont know what to do with object " + f)
        n.newline()

        n.build("generated_headers_" + version, "phony", generated_headers)
        n.newline()

    for c_file in glob("src/**/*.c", recursive=True):
        if c_file.endswith(".inc.c"):
            continue

        status = await shell_status(f"grep -q SCRIPT\( {c_file}")

        for version in versions:
            s_glob = "ver/" + version + "/" + re.sub("src/", "asm/nonmatchings/", c_file)[:-2] + "/*.s"
            rule = "cc_kmc" if c_file.startswith("src/ultra/") else ("cc_dsl" if status == 0 else "cc")
            n.build(
                obj(c_file),
                rule,
                c_file,
                implicit = None if not args.depend_on_s else glob(s_glob),
                order_only="generated_headers_" + version,
                variables={ "version": version }
            )

    print("")

    # c tools that need to be compiled
    n.build("tools/Yay0compress", "cc_modern_exe", "tools/Yay0compress.c")
    n.build("tools/n64crc", "cc_modern_exe", "tools/n64crc.c")
    n.newline()

    n.build("all", "phony", versions)
    n.default("all")

    # update ver/current to versions[0]
    try:
        os.remove("ver/current")
    except Exception:
        pass
    os.symlink(versions[0], "ver/current")
    n.build("ver/current/build/papermario.z64", "phony", "ver/" + versions[0] + "/build/papermario.z64")

    print("Build configuration complete! Now run")
    print("    ninja")
    print("to compile " + ', '.join(f'\'{TARGET}.{version}.z64\'' for version in versions) + ".")

if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    loop.run_until_complete(main())
