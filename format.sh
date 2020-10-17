#!/bin/bash

COMPILER_OPTS="-std=gnu89 -Iinclude -Isrc -D_LANGUAGE_C"

shopt -s globstar

FILES="src/**/*.c include/*.h"
if (( $# > 0 )); then
    # only process .c and .h files
    FILES=$(echo "$@" | sed 's/ /\n/g' | grep '\.[ch]$')
fi

if [[ -z $FILES ]]; then
    echo "no .c or .h files specified"
    exit
fi

# format
astyle ${FILES} \
    --formatted --suffix=none \
    --lineend=linux \
    --convert-tabs \
    --max-code-length=120 \
    --min-conditional-indent=0 \
    --style=attach \
    --align-pointer=type --align-reference=name \
    --indent-switches \
    --indent-labels \
    --pad-oper --pad-comma --pad-header --unpad-paren \
    --attach-return-type \

# add newline at eof
find ${FILES} -exec sed -i -e '$a\' {} \;

# lint
C_FILES=$(echo "$FILES" | grep '\.c$')
if [[ ! -z $C_FILES ]]; then
    clang-tidy -p . ${C_FILES} -- ${COMPILER_OPTS}
fi
