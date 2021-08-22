#!/bin/bash
set -e

# This script can be used when you want to test locally the amount of warnings produced by your changes before doing a PR.

rm -rf ver/*/build/src
ninja | grep warning | sort | uniq > tools/warnings_count/warnings_new.txt

python3 tools/warnings_count/compare_warnings.py tools/warnings_count/warnings.txt tools/warnings_count/warnings_new.txt
