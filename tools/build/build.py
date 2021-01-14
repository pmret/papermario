import re
import os, sys
from glob import glob
import ninja_syntax
from argparse import ArgumentParser
import asyncio
from subprocess import PIPE

tools_dir = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
sys.path.append(tools_dir + "/n64splat")

INCLUDE_ASM_RE = re.compile(r"_INCLUDE_ASM\([^,]+, ([^,]+), ([^,)]+)") # note _ prefix
CPPFLAGS = "-Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32"

def obj(path: str):
    if not path.startswith("$builddir/"):
        path = "$builddir/" + path
    return path + ".o"

def read_splat(splat_config: str):
    import argparse
    import yaml
    from pathlib import PurePath

    from split import initialize_segments

    # Load config
    with open(splat_config) as f:
        config = yaml.safe_load(f.read())

    options = config.get("options")
    assert options.get("ld_o_replace_extension", True) == False

    # Initialize segments
    all_segments = initialize_segments(options, splat_config, config["segments"])

    objects = set()
    segments = {}

    for segment in all_segments:
        for subdir, path, obj_type, start in segment.get_ld_files():
            path = subdir + "/" + path

            objects.add(path)
            segments[path] = segment

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
    print(f"\r{(num_tasks_done / num_tasks) * 100:.0f}%", end="")

async def build_c_file(c_file: str):
    # preprocess c_file, but simply put an _ in front of INCLUDE_ASM and SCRIPT
    stdout, stderr = await shell(f"{cpp} {CPPFLAGS} '-DINCLUDE_ASM(...)=_INCLUDE_ASM(__VA_ARGS__)' '-DSCRIPT(...)=_SCRIPT(__VA_ARGS__)' {c_file} -o -")

    # search for macro usage (note _ prefix)
    uses_dsl = "_SCRIPT(" in stdout

    s_deps = []
    for line in stdout.splitlines():
        if line.startswith("_INCLUDE_ASM"):
            match = INCLUDE_ASM_RE.match(line)
            if match:
                s_deps.append("asm/nonmatchings/" + eval(match[1]) + "/" + match[2] + ".s")

    # add build task to ninja
    n.build(obj(c_file), "cc_dsl" if uses_dsl else "cc", c_file, implicit=s_deps)

def build_yay0_file(bin_file: str):
    yay0_file = f"$builddir/{os.path.splitext(bin_file)[0]}.Yay0"
    n.build(yay0_file, "yay0compress", bin_file, implicit=["tools/Yay0compress"])
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

    n.build(out, "img", path + ".png", variables={
        "img_type": img_type,
        "img_flags": flags,
    })
    build_bin_object(out)

async def main():
    global n, cpp, task_sem, num_tasks, num_tasks_done

    parser = ArgumentParser(description="Generates build.ninja")
    parser.add_argument("--cpp", help="C preprocessor command")
    args = parser.parse_args()

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if args.cpp is None and sys.platform == "darwin" and "Free Software Foundation" not in await shell("cpp --version")[0]:
        print("error: use 'brew' to obtain GNU cpp and run again with '--cpp cpp-10'")
        exit(1)

    cpp = args.cpp or "cpp"
    task_sem = asyncio.Semaphore(8)

    n = ninja_syntax.Writer(open("build.ninja", "w"), width=120)

    n.variable("builddir", "build")
    n.variable("cross", "mips-linux-gnu-")
    n.variable("python", sys.executable)
    n.variable("os", "mac" if sys.platform == "darwin" else "linux")
    n.variable("iconv", "tools/iconv.py UTF-8 SHIFT-JIS" if sys.platform == "darwin" else "iconv --from UTF-8 --to SHIFT-JIS")
    n.variable("cppflags", f"{CPPFLAGS} -Wcomment")
    n.variable("cflags", "-O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow")
    n.newline()

    n.rule("cc",
        command=f"{cpp} $cppflags $in -o - | $iconv | tools/$os/cc1 $cflags -o - | tools/$os/mips-nintendo-nu64-as -EB -G 0 - -o $out",
        description="cc $in",
        depfile="$out.d",
        deps="gcc")
    n.rule("cc_dsl",
        command=f"{cpp} $cppflags $in -o - | $python tools/compile_dsl_macros.py | $iconv | tools/$os/cc1 $cflags -o - | tools/$os/mips-nintendo-nu64-as -EB -G 0 - -o $out",
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

    n.rule("img",
        command="$python tools/convert_image.py $img_type $in $out $img_flags",
        description="image $in")
    n.newline()

    objects, segments = read_splat("tools/splat.yaml") # no .o extension!
    c_files = (f for f in objects if f.endswith(".c")) # glob("src/**/*.c", recursive=True)

    # TODO: build elf

    for f in objects:
        segment = segments[f]

        if f.endswith(".c"):
            continue # these are handled later
        elif f.endswith(".Yay0"):
            build_yay0_file(os.path.splitext(f)[0] + ".bin")
        elif f.endswith(".bin"):
            build_bin_object(f)
        elif f.endswith(".data"):
            n.build(obj(f), "as", "asm/" + f + ".s")
        elif f.endswith(".rodata"):
            n.build(obj(f), "as", "asm/" + f[2:] + ".s")
        elif f.endswith(".s"):
            n.build(obj(f), "as", f)
        elif f.endswith(".png"):
            build_image(f, segment)
        else:
            print("warning: dont know what to do with object " + f)
    n.newline()

    # build slow tasks concurrently
    n.comment("c")
    tasks = [
        *(task(build_c_file(f)) for f in c_files),
    ]
    num_tasks = len(tasks)
    num_tasks_done = 0
    await asyncio.gather(*tasks)
    print("")

if __name__ == "__main__":
    asyncio.run(main())
