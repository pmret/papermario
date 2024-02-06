#!/usr/bin/env python3

import argparse
import git
import os
import subprocess
import sys
from colour import Color


def set_version(version):
    global script_dir, root_dir, asm_dir, build_dir, elf_path
    script_dir = os.path.dirname(os.path.realpath(__file__))
    root_dir = os.path.join(script_dir, "ver", version)
    asm_dir = os.path.join(root_dir, "asm", "nonmatchings")
    build_dir = os.path.join(root_dir, "build")
    elf_path = os.path.join(build_dir, "papermario.elf")


def load_latest_progress(version):
    from urllib.request import urlopen

    if version == "current":
        from pathlib import Path

        version = Path("ver/current").resolve().parts[-1]

    csv = urlopen(f"https://papermar.io/reports/progress_{version}.csv").read().decode("utf-8")
    latest = csv.split("\n")[-2]

    (
        version,
        timestamp,
        git_hash,
        all_funcs,
        nonmatching_funcs,
        matching_funcs,
        total_size,
        nonmatching_size,
        matching_size,
    ) = latest.split(",")

    return (
        int(all_funcs),
        int(nonmatching_funcs),
        int(matching_funcs),
        int(total_size),
        int(nonmatching_size),
        int(matching_size),
    )


def get_func_info():
    try:
        result = subprocess.run(["mips-linux-gnu-objdump", "-x", elf_path], stdout=subprocess.PIPE)
        nm_lines = result.stdout.decode().split("\n")
    except:
        print(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
        sys.exit(1)

    sizes = {}
    vrams = {}

    for line in nm_lines:
        if " F " in line and "*ABS*" not in line:
            components = line.split()
            size = int(components[4], 16)
            name = components[5]
            sizes[name] = size
            vrams[name] = int(components[0], 16)

    return sizes, vrams


def get_nonmatching_funcs():
    funcs = set()

    for root, dirs, files in os.walk(asm_dir):
        for f in files:
            if f.endswith(".s"):
                funcs.add(f[:-2])

    return funcs


def get_funcs_sizes(sizes, matchings, nonmatchings, restrict_to=None):
    msize = 0
    nmsize = 0

    if restrict_to:
        matchings = matchings.intersection(restrict_to)
        nonmatchings = nonmatchings.intersection(restrict_to)

    for func in matchings:
        msize += sizes[func]

    for func in nonmatchings:
        if func not in sizes:
            pass
            # print(func)
        else:
            nmsize += sizes[func]

    return msize, nmsize


def lerp(a, b, alpha):
    return a + (b - a) * alpha


def get_funcs_in_vram_range(vrams, vram_min, vram_max):
    funcs = set()
    for func in vrams:
        if vrams[func] >= vram_min and vrams[func] <= vram_max:
            funcs.add(func)
    return funcs


def do_section_progress(
    section_name,
    vrams,
    sizes,
    total_size,
    matchings,
    nonmatchings,
    section_vram_start,
    section_vram_end,
):
    funcs = get_funcs_in_vram_range(vrams, section_vram_start, section_vram_end)
    matching_size, nonmatching_size = get_funcs_sizes(sizes, matchings, nonmatchings, restrict_to=funcs)
    section_total_size = matching_size + nonmatching_size
    progress_ratio = (matching_size / section_total_size) * 100
    matching_ratio = (matching_size / total_size) * 100
    total_ratio = (section_total_size / total_size) * 100
    print(f"\t{section_name}: {matching_size} matching bytes / {section_total_size} total ({progress_ratio:.2f}%)")
    print(f"\t\t(matched {matching_ratio:.2f}% of {total_ratio:.2f}% total rom for {section_name})")


def main(args):
    set_version(args.version)

    sizes, vrams = get_func_info()
    total_size = sum(sizes.values())
    # TODO hack for now since non-us roms aren't mapped out
    if args.version not in ("us", "ique"):
        total_size = 3718612
    all_funcs = set(sizes.keys())

    nonmatching_funcs = get_nonmatching_funcs()
    matching_funcs = all_funcs - nonmatching_funcs

    matching_size, nonmatching_size = get_funcs_sizes(sizes, matching_funcs, nonmatching_funcs)

    if len(all_funcs) == 0:
        funcs_matching_ratio = 0.0
        matching_ratio = 0.0
    else:
        funcs_matching_ratio = (len(matching_funcs) / len(all_funcs)) * 100
        matching_ratio = (matching_size / total_size) * 100

    (
        old_all_funcs,
        old_nonmatching_funcs,
        old_matching_funcs,
        old_total_size,
        old_nonmatching_size,
        old_matching_size,
    ) = load_latest_progress(args.version)

    if old_total_size == 0:
        old_matching_ratio = 0.0
    else:
        old_matching_ratio = (old_matching_size / old_total_size) * 100

    ratio_delta = matching_ratio - old_matching_ratio
    funcs_delta = len(matching_funcs) - old_matching_funcs

    if args.csv:
        version = 1
        git_object = git.Repo().head.object
        timestamp = str(git_object.committed_date)
        git_hash = git_object.hexsha
        csv_list = [
            str(version),
            timestamp,
            git_hash,
            str(len(all_funcs)),
            str(len(nonmatching_funcs)),
            str(len(matching_funcs)),
            str(total_size),
            str(nonmatching_size),
            str(matching_size),
        ]
        print(",".join(csv_list))
    elif args.shield_json:
        import json

        # https://shields.io/endpoint
        color = Color("#50ca22", hue=lerp(0, 105 / 255, matching_ratio / 100))
        print(
            json.dumps(
                {
                    "schemaVersion": 1,
                    "label": f"progress ({args.version})",
                    "message": f"{matching_ratio:.2f}%",
                    "color": color.hex,
                }
            )
        )
    elif args.pr_comment:
        if funcs_delta > 0 or ratio_delta > 0:
            if funcs_delta == 0 or funcs_delta == 1:
                s = ""
            else:
                s = "s"

            print(
                f"{'🚀' * funcs_delta} This PR matches {funcs_delta} function{s} (+{ ratio_delta:.2f}%) on `{args.version}`."
            )
    else:
        if matching_size + nonmatching_size != total_size:
            print(f"Warning: category/total size mismatch on version {args.version}!\n")
            print("Matching size: " + str(matching_size))
            print("Nonmatching size: " + str(nonmatching_size))
            print("Sum: " + str(matching_size + nonmatching_size) + " (should be " + str(total_size) + ")")
        print(f"{len(matching_funcs)} matched functions / {len(all_funcs)} total ({funcs_matching_ratio:.2f}%)")
        print(f"{matching_size} matching bytes / {total_size} total ({matching_ratio:.2f}%)")

        do_section_progress(
            "effects",
            vrams,
            sizes,
            total_size,
            matching_funcs,
            nonmatching_funcs,
            0xE0000000,
            0xE1000000,
        )
        do_section_progress(
            "map",
            vrams,
            sizes,
            total_size,
            matching_funcs,
            nonmatching_funcs,
            0x80240000,
            0x80250000,
        )

        if funcs_delta > 0 or ratio_delta > 0:
            if funcs_delta == 0 or funcs_delta == 1:
                s = ""
            else:
                s = "s"

            print(
                f"This local build matches {funcs_delta} function{s} (+{ ratio_delta:.2f}%) over latest '{args.version}'."
            )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Reports progress for the project")
    parser.add_argument("version", default="current", nargs="?")
    parser.add_argument("--csv", action="store_true")
    parser.add_argument("--shield-json", action="store_true")
    parser.add_argument("--pr-comment", action="store_true")
    args = parser.parse_args()

    main(args)
