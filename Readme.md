# Generate the .bin files by splitting the rom
Place Paper Mario (U) (named baserom.z64) in the root directory, build `n64split`, and run:
```
./splitrom.sh
```
You'll need to build binutils manually with two targets: mips-sgi-irix5 and mips-linux-gnu - we don't have proper instructions yet, but see the Dockerfile for an example.
