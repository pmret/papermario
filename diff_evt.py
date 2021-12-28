#!/usr/bin/env python3

import argparse
import queue
import time
import subprocess
import sys

from diff import Display, debounced_fs_watch
from colorama import Fore, Back, Style

sys.path.append("tools")
from tools.update_evts import parse_symbol_addrs
from tools.disasm_script import ScriptDisassembler, get_constants

parser = argparse.ArgumentParser(
    description="Diff EVT macros."
)

parser.add_argument(
    "start",
    help="Symbol name or ROM address to start diffing from.",
)

parser.add_argument(
    "-w",
    "--watch",
    action="store_true",
    help="Watch for file changes and update the diff automatically."
)

parser.add_argument(
    "-m",
    "--make",
    action="store_true",
    help="Run ninja automatically."
)

parser.add_argument(
    "-o",
    action="store_true",
    help="Ignored for compatibility with diff.py."
)

class EvtDisplay(Display):
    def __init__(self, start):
        self.config = None
        self.base_lines = None
        self.mydump = None
        self.emsg = None
        self.last_refresh_key = None
        self.last_diff_output = None

        self.start = start

    def run_diff(self):
        if self.emsg is not None:
            return (self.emsg, self.emsg)

        symbols = parse_symbol_addrs()

        if self.start in symbols:
            start = symbols[self.start].rom_addr
        else:
            try:
                start = int(self.start, base=0)
            except ValueError:
                print("Start symbol name is not known or is an invalid address.")
                exit(2)

        with open("ver/current/build/papermario.z64", "rb") as f:
            f.seek(start)
            current = ScriptDisassembler(f, romstart=start, prelude=False).disassemble()

        with open("ver/current/baserom.z64", "rb") as f:
            f.seek(start)
            target = ScriptDisassembler(f, romstart=start, prelude=False).disassemble()

        current = current.splitlines()
        target = target.splitlines()

        score = 0
        output = ""

        for i in range(max(len(current), len(target))):
            if i >= len(current):
                current.append("")
            if i >= len(target):
                target.append("")

            current_line = current[i][4:]
            target_line = target[i][4:]

            output += Style.RESET_ALL

            if current_line != target_line:
                output += Fore.RED
                score += 10
            else:
                output += Style.DIM

            output += f"{target_line:<60} {current_line:<60}\n"

        output = f"{'TARGET':<60} {f'CURRENT ({score})':<60}\n" + output

        refresh_key = (current, target)
        return (output, refresh_key)

class FakeConfig():
    def __init__(self, args):
        self.make = args.make
        self.source_extensions = ["c", "h"]

def run_ninja():
    return subprocess.run(
        ["ninja", "ver/current/build/papermario.z64"],
        stderr=subprocess.PIPE,
        stdout=subprocess.PIPE,
    )

def main():
    args = parser.parse_args()
    get_constants()

    display = EvtDisplay(args.start)

    if args.watch:
        if not args.make:
            yn = input(
                "Warning: watch-mode (-w) enabled without auto-ninja (-m). "
                "You will have to run ninja manually. Ok? (Y/n) "
            )
            if yn.lower() == "n":
                return
        if args.make:
            watch_sources = ["src", "include"]
        else:
            watch_sources = ["ver/current/build/papermario.z64"]
        q = queue.Queue()
        debounced_fs_watch(watch_sources, q, FakeConfig(args), FakeConfig(args))
        display.run_async(q)
        last_build = 0.0
        try:
            while True:
                t = q.get()
                if t is None:
                    break
                if t < last_build:
                    continue
                last_build = time.time()
                if args.make:
                    display.progress("Building...")
                    ret = run_ninja()
                    if ret.returncode != 0:
                        display.update(
                            ret.stderr.decode("utf-8-sig", "replace")
                            or ret.stdout.decode("utf-8-sig", "replace"),
                            error=True,
                        )
                        continue
                display.update(last_build, error=False)
        except KeyboardInterrupt:
            display.terminate()
    else:
        display.run_sync()

if __name__ == "__main__":
    main()
