#!/usr/bin/env bash
# This script is copied into the pre-commit git hooks folder.
# It ensures that a commit is aborted if you try to accidentally commit game assets.
# install_deps.sh will install this for you.

(git check-ignore assets/us -q && git check-ignore assets/jp -q && git check-ignore assets/ique -q && git check-ignore assets/pal -q) || (>&2 echo -e 'ERROR: You appear to be committing dumped assets!\nSee the following document for how to modify assets legally:\nhttps://github.com/pmret/papermario/wiki/Asset-overrides' && exit 1)
