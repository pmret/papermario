rm -rf papermario/asm
rm -rf papermario/bin
rm -rf papermario/bgm
./n64splitter/bin/n64split -v -o papermario -c PAPER_MARIO.u.yaml baserom.z64
