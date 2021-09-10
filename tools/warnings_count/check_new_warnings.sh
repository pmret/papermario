#!/bin/bash
set -e
set -o pipefail

# This script can be used when you want to test locally the amount of warnings produced by your changes before doing a PR.

pyflags=""
rebuild=false

if [[ $1 == "--jenkins" ]]
  then
    pyflags="--pr-message"
    rebuild=false
  else
    rebuild=true
fi

if $rebuild
then
    echo "Rebuilding to collect warnings..."
    rm -rf ver/*/build/src
    ninja | grep warning | sort > tools/warnings_count/warnings_new.txt
else
    cat build_log.txt | grep warning | sort > tools/warnings_count/warnings_new.txt
fi

curl -L https://papermar.io/reports/warnings.txt > tools/warnings_count/warnings.txt

python3 tools/warnings_count/compare_warnings.py tools/warnings_count/warnings.txt tools/warnings_count/warnings_new.txt $pyflags
