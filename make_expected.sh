#!/usr/bin/env sh

rm -rf ver/*/expected

mkdir -p ver/us/expected/ver/us
cp -r ver/us/build ver/us/expected/ver/us

mkdir -p ver/jp/expected/ver/jp
cp -r ver/jp/build ver/jp/expected/ver/jp

mkdir -p ver/ique/expected/ver/ique
cp -r ver/ique/build ver/ique/expected/ver/ique

mkdir -p ver/pal/expected/ver/pal
cp -r ver/pal/build ver/pal/expected/ver/pal
