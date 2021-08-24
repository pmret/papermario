#!/usr/bin/env python3

import argparse


def countFileLines(filename: str) -> int:
    with open(filename) as f:
        return len(f.readlines())


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('currentwarnings', help="Name of file which contains the current warnings of the repo.")
    parser.add_argument('newwarnings', help="Name of file which contains the *new* warnings of the repo.")
    parser.add_argument("--pr-message", action="store_true")
    args = parser.parse_args()

    currentLines = countFileLines(args.currentwarnings)
    newLines = countFileLines(args.newwarnings)
    if newLines > currentLines:
        if args.pr_message:
            delta = newLines - currentLines
            print(f"⚠️ This PR introduces {delta} warnings:")
        else:
            print()
            print("There are more warnings now. Go fix them!")
            print("\tCurrent warnings: " + str(currentLines))
            print("\tNew warnings: " + str(newLines))
            print()

        with open(args.newwarnings) as new:
            new = new.readlines()
            with open(args.currentwarnings) as current:
                current = current.readlines()
                for newLine in new:
                    if newLine not in current:
                        print("- " + newLine.strip())
    elif newLines < currentLines:
        delta = currentLines - newLines

        if args.pr_message:
            print(f"✅ This PR fixes {delta} warnings!")
        else:
            print(f"{delta} warnings fixed.")


if __name__ == "__main__":
    main()
