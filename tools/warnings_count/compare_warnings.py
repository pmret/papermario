#!/usr/bin/env python3

import argparse
import os
from pathlib import Path
import sys

import requests

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))
root_dir = script_dir / "../.."


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--pr-message", action="store_true")
    args = parser.parse_args()

    # Download the latest warnings.txt
    response = requests.get("https://papermar.io/reports/warnings.txt")
    current_warnings = response.content.decode("utf-8").strip().split("\n")

    # Write the current warnings to a file
    with open(script_dir / "warnings.txt", "w") as f:
        for line in current_warnings:
            f.write(line + "\n")

    # Get the new warnings from the build log
    if not (root_dir / "build_log.txt").exists():
        print("build_log.txt not found. Exiting.")
        sys.exit(1)

    with open(root_dir / "build_log.txt") as f:
        new_warnings = [line for line in f.readlines() if "warning" in line]

    # Write the new warnings to a file
    with open(script_dir / "warnings_new.txt", "w") as f:
        f.writelines(new_warnings)

    num_current_warnings = len(current_warnings)
    num_new_warnings = len(new_warnings)
    if num_new_warnings > num_current_warnings:
        stderr = False
        if args.pr_message:
            delta = num_new_warnings - num_current_warnings

            if delta == 1:
                print(f"⚠️ This PR introduces a warning:")
            else:
                print(f"⚠️ This PR introduces {delta} warnings:")

            if delta > 100:
                stderr = True
                print("See log for details.")
        else:
            print()
            print("There are more warnings now. Go fix them!")
            print("\tCurrent warnings: " + str(num_current_warnings))
            print("\tNew warnings: " + str(num_new_warnings))
            print()

        for newLine in new_warnings:
            if "warning: previous declaration of" in newLine:
                continue

            if newLine not in current_warnings:
                if stderr:
                    print(newLine.strip(), file=sys.stderr)
                else:
                    print("- " + newLine.strip())
    elif num_new_warnings < num_current_warnings:
        delta = num_current_warnings - num_new_warnings

        if args.pr_message:
            print(f"✅ This PR fixes {delta} warnings!")
        else:
            print(f"{delta} warnings fixed.")


if __name__ == "__main__":
    main()
