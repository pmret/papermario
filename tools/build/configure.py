#!/usr/bin/env python3

from typing import List
from pathlib import Path
import sys
import ninja_syntax

SUPPORTED_VERSIONS = ["us", "jp"]
ROOT = Path(__file__).parent.parent.parent

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

class Configure:
    def __init__(self, version: str, cpp: str):
        self.version = version
        self.version_path = ROOT / f"ver/{version}"
        self.cpp = cpp
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
            True, # verbose
            False,
        )

    def write_ninja(self, ninja: ninja_syntax.Writer):
        import segtypes

        assert self.linker_entries is not None

        def build(entry, task: str):
            ninja.build(
                str(entry.object_path), # $out
                task,
                [str(p) for p in entry.src_paths], # $in
                variables={
                    "version": self.version,
                },
            )

        for entry in self.linker_entries:
            if isinstance(entry.segment, segtypes.n64.header.N64SegHeader):
                build(entry, "as")
            elif isinstance(entry.segment, segtypes.n64.code.Subsegment) and entry.segment.type in ["asm", "hasm", "data", "rodata", "bss"]:
                build(entry, "as")
            elif isinstance(entry.segment, segtypes.n64.code.CodeSubsegment) and entry.segment.type == "c":
                build(entry, "cc")
            elif isinstance(entry.segment, segtypes.n64.code.BinSubsegment) or isinstance(entry.segment, segtypes.n64.bin.N64SegBin):
                build(entry, "bin")
            else:
                print(f"configure: don't know how to build {entry.segment.__class__.__name__} '{entry.segment.name}'")

if __name__ == "__main__":
    from argparse import ArgumentParser

    parser = ArgumentParser(description="Paper Mario build.ninja generator")
    parser.add_argument("version", nargs="*", default=[], help="Version(s) to configure for. Most tools will operate on the first-provided only. Supported versions: " + ','.join(SUPPORTED_VERSIONS))
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

        for version in SUPPORTED_VERSIONS:
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

    # TODO: ninja prelude

    for version in versions:
        print(f"configure: configuring version {version}")

        configure = Configure(version, args.cpp)

        configure.split(not args.no_splat, False)
        configure.write_ninja(ninja)
