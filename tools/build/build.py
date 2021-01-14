import re
import sys
from glob import glob
import ninja_syntax
from argparse import ArgumentParser
import asyncio
from subprocess import PIPE

c_files = glob("src/**/*.c", recursive=True)

INCLUDE_ASM_RE = re.compile(r"_INCLUDE_ASM\([^,]+, ([^,]+), ([^,)]+)") # note _ prefix
CPPFLAGS = "-Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32"

def obj(path: str):
    return "$builddir/" + path + ".o"

async def shell(cmd: str):
    async with task_sem:
        proc = await asyncio.create_subprocess_shell(cmd, stdout=PIPE, stderr=PIPE)
        stdout, stderr = await proc.communicate()

    assert proc.returncode == 0, f"{cmd} failed: {stderr}"

    return stdout.decode("utf-8"), stderr.decode("utf-8")

async def build_c_file(c_file: str, rule: str, dsl_rule: str):
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
    n.build(obj(c_file), dsl_rule if uses_dsl else rule, c_file, implicit=s_deps)

async def task(coro):
    global num_tasks, num_tasks_done

    await coro

    num_tasks_done += 1
    print(f"\r{(num_tasks_done / num_tasks) * 100:.0f}%", end="")

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
    task_sem = asyncio.Semaphore(8) # TODO: args.j

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

    # build all the things! concurrently!
    tasks = [
        *(task(build_c_file(c_file, "cc", "cc_dsl")) for c_file in c_files),
    ]
    num_tasks = len(tasks)
    num_tasks_done = 0
    await asyncio.gather(*tasks)
    print(" done")

if __name__ == "__main__":
    asyncio.run(main())
