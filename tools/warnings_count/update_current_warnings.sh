#!/bin/bash
set -e

# This script should only be used when we need to modify the accepted amount of warnings.

rm -rf ver/*/build/src
ninja | grep warning | sort | uniq > tools/warnings_count/warnings.txt
