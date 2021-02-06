#!/usr/bin/env python3

import re
import os, sys
from glob import glob
import ninja_syntax
from argparse import ArgumentParser
import asyncio
from subprocess import PIPE
import subprocess
import hashlib

sys.path.append(os.path.dirname(__file__) + "/tools/splat")
import split

INCLUDE_ASM_RE = re.compile(r"___INCLUDE_ASM\([^,]+, ([^,]+), ([^,)]+)") # note _ prefix

CFG = {}
with open("build.cfg", "r") as f:
    for line in f.readlines():
        if line.strip() != "":
            key, value = [part.strip() for part in line.split("=", 1)]
            CFG[key] = value

TARGET = CFG.get("target", "papermario")
BUILD_DIR = "build"
ASSET_DIRS = CFG.get("asset_dirs", "assets").split(" ")

NPC_SPRITES = CFG.get("npc_sprites", "").split(" ")
MAPS = CFG.get("maps", "").split(" ")
TEXTURE_ARCHIVES = CFG.get("texture_archives", "").split(" ")
BACKGROUNDS = CFG.get("backgrounds", "").split(" ")
PARTY_IMAGES = CFG.get("party_images", "").split(" ")

ASSETS = sum([[f"{map_name}_shape", f"{map_name}_hit"] for map_name in MAPS], []) + TEXTURE_ARCHIVES + BACKGROUNDS + ["title_data"] + PARTY_IMAGES

def obj(path: str):
    if not path.startswith("$builddir/"):
        path = "$builddir/" + path
    path = re.sub(r"/assets/", "/", path)
    return path + ".o"

def read_splat(splat_config: str):
    import argparse
    import yaml
    from segtypes.n64.code import N64SegCode

    # Load config
    with open(splat_config) as f:
        config = yaml.safe_load(f.read())

    options = config.get("options")
    assert options.get("ld_o_replace_extension", True) == False

    # Initialize segments
    all_segments = split.initialize_segments(options, splat_config, config["segments"])

    objects = set()
    segments = {}

    for segment in all_segments:
        for subdir, path, obj_type, start in segment.get_ld_files():
            if path.endswith(".c") or path.endswith(".s") or path.endswith(".data") or path.endswith(".rodata"):
                path = subdir + "/" + path
            else:
                assert subdir == "assets", subdir + " " + path

            objects.add(path)
            segments[path] = segment

        if isinstance(segment, N64SegCode):
            for split_file in segment.files:
                if split_file["subtype"] in ["i4", "i8", "ia4", "ia8", "ia16", "rgba16", "rgba32", "ci4", "ci8", "palette"]:
                    path = os.path.join(
                        #segment.get_subdir(split_file["subtype"]),
                        split_file["name"] + "." + segment.get_ext(split_file["subtype"])
                    )

                    if path in segments:
                        segments[path] = split_file

    # note: `objects` lacks .o extensions
    return objects, segments

async def shell(cmd: str):
    async with task_sem:
        proc = await asyncio.create_subprocess_shell(cmd, stdout=PIPE, stderr=PIPE)
        stdout, stderr = await proc.communicate()

    assert proc.returncode == 0, f"{cmd} failed: {stderr}"

    return stdout.decode("utf-8"), stderr.decode("utf-8")

async def task(coro):
    global num_tasks, num_tasks_done

    await coro

    num_tasks_done += 1
    print(f"\rConfiguring build... {(num_tasks_done / num_tasks) * 100:.0f}%", end="")

async def build_c_file(c_file: str, generated_headers, ccache, cppflags):
    # preprocess c_file, but simply put an _ in front of INCLUDE_ASM and SCRIPT
    stdout, stderr = await shell(f"{cpp} {cppflags} '-DINCLUDE_ASM(...)=___INCLUDE_ASM(__VA_ARGS__)' '-DSCRIPT(...)=___SCRIPT(__VA_ARGS__)' {c_file} -o - | grep -E '___SCRIPT|___INCLUDE_ASM' || true")

    # search for macro usage (note _ prefix)
    uses_dsl = "___SCRIPT(" in stdout

    s_deps = []
    for line in stdout.splitlines():
        if line.startswith("___INCLUDE_ASM"):
            match = INCLUDE_ASM_RE.match(line)
            if match:
                s_deps.append("asm/nonmatchings/" + eval(match[1]) + "/" + match[2] + ".s")

    # add build task to ninja
    n.build(obj(c_file), "cc_dsl" if uses_dsl else "cc", c_file, implicit=s_deps, order_only=generated_headers)

def build_yay0_file(bin_file: str):
    yay0_file = f"$builddir/{os.path.splitext(bin_file)[0]}.Yay0"
    n.build(yay0_file, "yay0compress", find_asset(bin_file), implicit="tools/Yay0compress")
    build_bin_object(yay0_file)

def build_bin_object(bin_file: str):
    n.build(obj(bin_file), "bin", bin_file)

def build_image(f: str, segment):
    path, img_type, png = f.rsplit(".", 2)
    out = "$builddir/" + path + "." + img_type + ".png"

    flags = ""
    if img_type != "palette":
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
    for d in ASSET_DIRS:
        if os.path.exists(d + "/" + path):
            return d

    print("unable to find asset: " + path)
    exit(1)

def find_asset(path):
    return find_asset_dir(path) + "/" + path

async def main():
    global n, cpp, task_sem, num_tasks, num_tasks_done

    task_sem = asyncio.Semaphore(8)

    parser = ArgumentParser(description="Paper Mario build.ninja generator")
    parser.add_argument("--cpp", help="GNU C preprocessor command")
    parser.add_argument("--baserom", default="baserom.z64", help="Path to unmodified Paper Mario (U) z64 ROM")
    parser.add_argument("--cflags", default="", help="Extra cc/cpp flags")
    parser.add_argument("--no-splat", action="store_true", help="Don't split the baserom")
    args = parser.parse_args()

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if args.cpp is None and sys.platform == "darwin" and "Free Software Foundation" not in (await shell("cpp --version"))[0]:
        print("error: system C preprocessor is not GNU!")
        print("This is a known issue on macOS - only clang's cpp is installed by default.")
        print("Use 'brew' to obtain GNU cpp, then run this script again with the --cpp option, e.g.")
        print("    ./configure.py --cpp cpp-10")
        exit(1)

    # verify baserom exists and is clean
    try:
        with open(args.baserom, "rb") as f:
            h = hashlib.sha1()
            h.update(f.read())

            if h.hexdigest() != "3837f44cda784b466c9a2d99df70d77c322b97a0":
                print(f"error: baserom '{args.baserom}' is modified, refusing to split it!")
                print("The baserom must be an unmodified Paper Mario (U) z64 ROM.")
                exit(1)
    except IOError:
        print(f"error: baserom '{args.baserom}' does not exist!")
        print(f"Please make sure an unmodified Paper Mario (U) z64 ROM exists at '{args.baserom}'.")

        if args.baserom == "baserom.z64": # the default
            print("Or run this script again with the --baserom option:")
            print("    ./configure.py --baserom /path/to/papermario.z64")
            exit(1)

    cpp = args.cpp or "cpp"
    ccache = "ccache" if cmd_exists("ccache") else ""

    if not args.no_splat:
        # compile splat dependencies
        await shell("make -C tools/splat")

        # split assets
        print("Splitting segments from baserom", end="")
        split.main(
            args.baserom,
            "tools/splat.yaml",
            ".",
            [ "ld", "bin", "Yay0", "PaperMarioMapFS", "PaperMarioMessages", "img", "PaperMarioNpcSprites" ],
            False,
            False,
        )

        print("")

    print("Configuring build...", end="")

    # generate build.ninja
    n = ninja_syntax.Writer(open("build.ninja", "w"), width=120)

    cppflags = f"-I{BUILD_DIR}/include -Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 " + args.cflags
    cflags = "-O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow " + args.cflags
    iconv = "tools/iconv.py UTF-8 SHIFT-JIS" if sys.platform == "darwin" else "iconv --from UTF-8 --to SHIFT-JIS"
    cross = "mips-linux-gnu-"

    n.variable("builddir", BUILD_DIR)
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

    n.variable("os", os_dir)
    n.variable("iconv", iconv)
    n.variable("cppflags", f"{cppflags} -Wcomment")
    n.variable("cflags", cflags)
    n.newline()

    n.rule("cc",
        command=f"bash -o pipefail -c '{cpp} $cppflags -MD -MF $out.d $in -o - | $iconv | tools/$os/cc1 $cflags -o - | tools/$os/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        description="cc $in",
        depfile="$out.d",
        deps="gcc")
    n.rule("cc_dsl",
        command=f"bash -o pipefail -c '{cpp} $cppflags -MD -MF $out.d $in -o - | $python tools/compile_dsl_macros.py | $iconv | tools/$os/cc1 $cflags -o - | tools/$os/mips-nintendo-nu64-as -EB -G 0 - -o $out'",
        description="cc (with dsl) $in",
        depfile="$out.d",
        deps="gcc")
    n.newline()

    with open("tools/permuter_settings.toml", "w") as f:
        f.write(f"compiler_command = \"{cpp} {cppflags} -D SCRIPT(...)={{}} | {iconv} | tools/{os_dir}/cc1 {cflags} -o - | tools/{os_dir}/mips-nintendo-nu64-as -EB -G 0 -\"\n")
        f.write(f"assembler_command = \"{cross}as -march=vr4300 -mabi=32\"\n")

    n.rule("cpp",
        command=f"{cpp} -P -DBUILD_DIR=$builddir $in -o $out",
        description="cc (with dsl) $in",
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
        command="${cross}as -EB -march=vr4300 -mtune=vr4300 -Iinclude $in -o $out",
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

    # $msg_combine_headers
    n.rule("msg_combine",
        command="$python tools/msg/combine.py $out $in --headers $msg_combine_headers",
        description="combine messages")
    n.rule("msg",
        command="$python tools/msg/parse_compile.py $in $out",
        description="msg $in")
    n.newline()

    n.rule("assets",
        command="$python tools/build_assets_bin.py $out $in",
        description="combine assets")
    n.newline()

    n.rule("link",
        command="${cross}ld -T undefined_syms.txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -Map $builddir/$target.map --no-check-sections -T $in -o $out",
        description="link $out")
    n.newline()

    n.rule("rom",
        command="${cross}objcopy $in $out -O binary && tools/n64crc $out",
        description="rom $in")
    n.newline()

    objects, segments = read_splat("tools/splat.yaml") # no .o extensions!
    c_files = (f for f in objects if f.endswith(".c")) # glob("src/**/*.c", recursive=True)

    n.rule("checksums",
        command=f"(sha1sum -c checksum.sha1 && bash $out.bash > $out) || sha1sum -c $out --quiet",
        description="compare",
        rspfile="$out.bash",
        rspfile_content=f"sha1sum {' '.join([obj(o) for o in objects])}")
    n.newline()

    n.rule("cc_modern_exe", command="cc $in -O3 -o $out")
    n.newline()

    n.comment("target")
    n.build("$builddir/$target.ld", "cpp", "$target.ld")
    n.build("$builddir/$target.elf", "link", "$builddir/$target.ld", implicit=[obj(o) for o in objects], implicit_outputs="$builddir/$target.map")
    n.build("$target.z64", "rom", "$builddir/$target.elf", implicit="tools/n64crc")
    n.build("$builddir/expected.sha1", "checksums", implicit="$target.z64")
    n.newline()

    n.default("$builddir/expected.sha1")
    n.newline()

    # generated headers
    n.comment("generated headers")
    generated_headers = []

    def add_generated_header(h: str):
        generated_headers.append(h)

        he = re.sub(r"\$builddir", BUILD_DIR, h)

        if not os.path.exists(he):
            # mkdir -p
            os.makedirs(os.path.dirname(he), exist_ok=True)

            # touch it so cpp doesn't complain if its #included
            open(he, "w").close()

            # mark it as really old so ninja builds it
            os.utime(he, (0, 0))

        return h

    n.build(add_generated_header("$builddir/include/ld_addrs.h"), "ld_addrs_h", "$builddir/$target.ld")

    # messages
    msg_files = []
    for d in ASSET_DIRS:
        msg_files.extend(glob(d + "/**/*.msg", recursive=True))
    for msg_file in msg_files:
        n.build(
            f"$builddir/{msg_file}.bin",
            "msg",
            msg_file,
            implicit="tools/msg/parse_compile.py",
        )
    n.build(
        "$builddir/msg.bin",
        "msg_combine",
        [f"$builddir/{msg_file}.bin" for msg_file in msg_files],
        implicit="tools/msg/combine.py",
        implicit_outputs=[add_generated_header(f"$builddir/include/{msg_file.split('/', 1)[1]}.h") for msg_file in msg_files],
        variables={ "msg_combine_headers": [f"{msg_file}.h" for msg_file in msg_files] }
    )
    n.build("$builddir/msg.o", "bin", "$builddir/msg.bin")

    # sprites
    npc_sprite_yay0s = []
    for sprite_id, sprite_name in enumerate(NPC_SPRITES, 1):
        asset_dir = find_asset_dir(f"sprite/npc/{sprite_name}")
        sources = glob(f"{asset_dir}/npc/{sprite_name}/**/*.*", recursive=True)
        variables = {
            "sprite_name": sprite_name,
            "sprite_dir": f"{asset_dir}/sprite/npc/{sprite_name}",
            "sprite_id": sprite_id,
        }

        # generated header
        n.build(
            add_generated_header(f"$builddir/include/sprite/npc/{sprite_name}.h"),
            "sprite_animations_h",
            implicit=sources + ["tools/gen_sprite_animations_h.py"],
            variables=variables,
        )

        # sprite bin/yay0
        n.build(
            f"$builddir/sprite/npc/{sprite_name}",
            "npc_sprite",
            implicit=sources + ["tools/compile_npc_sprite.py"],
            variables=variables,
        )
        yay0 = f"$builddir/sprite/npc/{sprite_name}.Yay0"
        npc_sprite_yay0s.append(yay0)
        n.build(
            yay0,
            "yay0compress",
            f"$builddir/sprite/npc/{sprite_name}",
            implicit=["tools/Yay0compress"],
        )

    n.newline()

    # fast tasks
    n.comment("data")
    for f in objects:
        segment = segments[f]

        if f.endswith(".c"):
            continue # these are handled later
        elif f.endswith(".Yay0"):
            build_yay0_file(os.path.splitext(f)[0] + ".bin")
        elif f.endswith(".bin"):
            build_bin_object(find_asset(f))
        elif f.endswith(".data"):
            n.build(obj(f), "as", "asm/" + f + ".s")
        elif f.endswith(".rodata"):
            n.build(obj(f), "as", "asm/" + f[2:] + ".s")
        elif f.endswith(".s"):
            n.build(obj(f), "as", f)
        elif f.endswith(".png"):
            if isinstance(segment, dict):
                # image within a code section
                out = "$builddir/" + f + ".bin"
                infile = find_asset(re.sub(r"\.pal\.png", ".png", f))

                n.build(out, "img", infile, implicit="tools/img/build.py", variables={
                    "img_type": segment["subtype"],
                    "img_flags": "",
                })

                if ".pal.png" not in f:
                    n.build(add_generated_header("$builddir/include/" + f + ".h"), "img_header", infile, implicit="tools/img/header.py")

                n.build("$builddir/" + f + ".o", "bin", out)
            else:
                build_image(f, segment)
        elif f == "sprite/npc":
            # combine sprites
            n.build(f"$builddir/{f}.bin", "npc_sprites", npc_sprite_yay0s, implicit="tools/compile_npc_sprites.py")
            n.build(obj(f), "bin", f"$builddir/{f}.bin")
        elif segment.type == "PaperMarioMessages":
            continue # done already above
        elif segment.type == "PaperMarioMapFS":
            asset_files = [] # even indexes: uncompressed; odd indexes: compressed

            for asset_name in ASSETS:
                if asset_name.endswith("_tex"): # uncompressed
                    asset_files.append(find_asset(f"{asset_name}.bin"))
                    asset_files.append(find_asset(f"{asset_name}.bin"))
                else: # uncompressed
                    source_file = find_asset(f"{asset_name}.bin")
                    asset_file = f"$builddir/assets/{asset_name}.Yay0"

                    asset_files.append(source_file)
                    asset_files.append(asset_file)
                    n.build(asset_file, "yay0compress", source_file, implicit="tools/Yay0compress")

            n.build("$builddir/assets.bin", "assets", asset_files)
            n.build(obj(f), "bin", "$builddir/assets.bin")
        else:
            print("warning: dont know what to do with object " + f)
    n.newline()

    n.build("generated_headers", "phony", generated_headers)
    n.newline()

    # slow tasks generated concurrently
    n.comment("c")
    tasks = [task(build_c_file(f, "generated_headers", ccache, cppflags)) for f in c_files]
    num_tasks = len(tasks)
    num_tasks_done = 0
    await asyncio.gather(*tasks)
    print("")
    n.newline()

    # c tools that need to be compiled
    n.build("tools/Yay0compress", "cc_modern_exe", "tools/Yay0compress.c")
    n.build("tools/n64crc", "cc_modern_exe", "tools/n64crc.c")
    n.newline()

    print("")
    print("Build configuration complete! Now run")
    print("    ninja")
    print(f"to compile '{TARGET}.z64'.")

if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    loop.run_until_complete(main())
