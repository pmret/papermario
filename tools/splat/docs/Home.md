### What is splat?

**splat** is a binary splitting tool, written in Python. Its goal is to support the successful disassembly and then rebuilding of binary data.

It is the spiritual successor to [n64split](https://github.com/queueRAM/sm64tools/blob/master/n64split.c), originally written to handle N64 ROMs, it now has limited support for PSX and PS2 binaries.

MIPS code disassembly is handled via [spimdisasm](https://github.com/Decompollaborate/spimdisasm/).

There are a number of asset types built-in (e.g. various image formats, N64 Vtx data, etc), and it is designed to be simple to extend by writing your own custom types that can do anything you want as part of the **splat** pipeline.


### How does it work?

**splat** takes a [yaml](https://en.wikipedia.org/wiki/YAML) configuration file which tells it *where* and *how* to split a given file. Symbols can be mapped to addresses (and their types provided) via an optional "symbol_addrs" file.

**splat** runs two distinct phases: scan and split.

The _scan_ phase makes a first pass over the data and performs the initial disassembly of code and data. During the _split_ phase, information gathered during the _scan_ phase is used and files & data are written out to disk.

After scanning and splitting, **splat** will output a linker script that can be used as part of re-building the input file.


### Sounds great, how do I get started?

Have a look at the [Quickstart](https://github.com/ethteck/splat/wiki/Quickstart), or check out the [Examples](https://github.com/ethteck/splat/wiki/Examples) page to see projects that are using **splat**.
