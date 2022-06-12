# splat Release Notes

## 0.9.0: The Big Update
### Introducing [spimdisasm](https://github.com/Decompollaborate/spimdisasm)!
* Thanks to [AngheloAlf](https://github.com/AngheloAlf), we now have a much better MIPS disassembler in splat! spimdisasm has much better hi/lo matching, much lower ram usage, and plenty of other goodies.

We plan to roll this out in phases. Currently, it only handles actual code disassembly. Later on, we will probably migrate our current data assembly code to use spimdisasm as well.

**NOTICE**: This integration has been tested on a variety of games and configurations. However, with any giant change to the platform like this, there are bound to be things we didn't catch. Please be patient with us as we handle these remaining issues. Though from what we've seen already, the slight bugs one may come across are totally worth the much improved disassembly.

### gfx segment type
* A new `gfx` segment type is available, which creates a c file containing a disassembled display list according to the segment's start and end offsets. Thanks to [Glank](https://github.com/glankk) and [Tharo](https://github.com/thar0/) for their work on [libgfxd](https://github.com/glankk/libgfxd) and [pygfxd](https://github.com/thar0/pygfxd/), respectively, for helping make this a possibility in splat.

### API breaking changes
* Some `Segment()` arguments have changed, which may cause extensions to break. Please see the `__init__` function for `Segment` for more details.

### symbol_addrs.txt changes
* symbol_addrs now supports the `segment:` attribute, which allows specifying the symbol's top-level segment. This can be helpful for symbol resolution when overlays use overlapping vram ranges. See `exclusive_ram_id` below for more information.

### Global options changes

The new `symbol_name_format` option allows specification of how symbols will be named. This can be set as a global option and also changed per-segment. `symbol_norom_name_format` is used when the symbol does not have a rom address (BSS).

 The following substitutions are allowed:

`$ROM` - the rom address of the symbol, hex-formatted and padded to 6 characters (ABCF10, 000030, 123456) (note: only for `symbol_name_format`, usage in `symbol_norom_name_format` will cause an error)

`$VRAM` - the vram address of the symbol, hex-formatted and padded to 8 characters (00030010, 00020015, ABCDEF10)

`$SEG` - the name of the top-level segment in which the symbol resides

The default values for these options are as follows

`symbol_name_format` : `$VRAM_$ROM`

`symbol_noram_name_format` : `$VRAM_$SEG`

The appropriate prefix string will still automatically be applied depending on the type of the symbol: `D_` for data, `jtbl_` for jump tables, and `func_` for functions. This functionality may be customizable in the future.

----
The `auto_all_section` option now should be a list of section names (`[".data", ".rodata", ".bss"]` by default) indicating the sections that should be linked from .o files built from source files (.c or asm/hasm .s files), when no subsegment explicitly indicates linking this type of section.

For example, if any subsegment of a code segment is of segment type `data` or `.data`, the `.data` section from all `c`/`asm`/`hasm` subsegments will not be linked unless explicitly indicated with a relevant `.data` subsegment.

Previously, this option was a bool, and it enabled this feature for all sections specified in `section_order`. Now, the desired sections must be specified manually. The default value for this option retains previous behavior.

----
The new `mips_abi_float_regs` option allows for changing the format of float registers for MIPS disassembly. The default value does not change any prior behavior, but `o32` is heavily encouraged and may become the default option in the future. For more information, see this [great writeup](https://gist.github.com/EllipticEllipsis/27eef11205c7a59d8ea85632bc49224d).

----
The new `gfx_ucode` option allows for specifying the target for the graphics macro format, which is used in the gfx segment type. The default is `f3dex2`.


### Segment options changes

The new `exclusive_ram_id` segment option allows specifying an identifer that will prevent the segment from seeing any symbols from other segments with the same identifer. This is useful when multiple segments are mapped to the same vram address at runtime and should never be able to refer to each other's symbols. Setting all of these segments to have the same value for this option will prevent their symbols from clashing / meshing unexpectedly.

----

The `overlay` setting on segments has been removed. Please see `symbol_name_format` above for info on how to influence the names of symbols, which can be applied at the segment level as well as the global level.

----
## 0.8.0: Arbitrary Section Order
* You can now use the option `section_order` to define the binary section order for your target binary. By default, this is `[".text", ".data", ".rodata", ".bss"]`. See options.py for more details
* Documented all options in options.py
* Support for SN64 games (thanks Wiseguy!)
* More consistent handling of paths (thanks Mkst!)
* Various other cleanup and fixes across the board

### 0.7.10: WIP PSX support
* WIP PSX support has been added, thanks to @mkst! (https://github.com/ethteck/splat/pull/99)
  * Many segments have moved to a "common" package
  * Endianness of the input binary is now a configurable option
* Linker hack restored but is now optional and off by default

### 0.7.9
* Finally removed the dumb linker section alignment hack
* Added version number to output on execution

### 0.7.8

* Fixed a bug relating to a linker section alignment hack (thanks Wiseguy!)
* Fixed a bug in linker_entry.py's clean_up_path that should make this function more versatile (thanks Wiseguy!)

### 0.7.7

* Disassembly now reads the `size` property of a function in symbol_addrs.txt to disassemble `size / 4` number of instructions. Feel free to specify the size of your functions in your symbol_addrs file if splat's disassembly is chopping a function too short or making a function too long.

### 0.7.6

* Fixed a bug involving detection of defined functions in c files for GLOBAL_ASM-using projects
* Added options to disable the creation of undefined_funcs/syms_auto.txt files
* Added a Vtx segment type for creating c files containg model vertex data in the n64 libultra Vtx format
* Added a `cpp` segment type which is identical to `c` but looks for a file with the extension ".cpp" instead of ".c".

### 0.7.5: all_ types and auto_all_sections

If you have a group segment with multiple c files and want splat to automatically create linker entries at a given position for each code object (c, asm, hasm) in the segment, you can use an `all_` type for that section. For example, you can add `[auto, all_bss]` as the last subsegment in a segment. This will direct splat to create a linker entry for each code object in the segment. This saves a lot of time when it comes to manually adding .bss subsegments for bss support, for example. The same thing can be done for data and rodata sections, but note this should probably be done later into a project when all data / rodata is migrated to c files, as the `all_` types lose the rom positioning information that's necessary for splat to do proper disassembly.

The `auto_all_sections` option, when set to true, will automatically add `all_` types into every group. This is only done for a section in a group if no other manual declarations for that section exist. For example, if you have 30 c files in a group and a .data later on for one of them, `auto_all_sections` will not interfere with your `.data` subsegment. If you remove this, however, splat will use `auto_all_sections` to implicitly `.data` subsegments for all of your code objects behind the scenes. This feature is again particualrly helpful for bss support, as it will create bss linker entries for every file in your project (assuming you don't have any manual .bss subsegments), which eliminates the need to create dummy .bss subsegments just for the sake of configuring the linker script.

### 0.7.2

* Data disassembly changes:
  * String detection has been improved. Please send me false positives / negatives as you see them and I can try to improve it further!
  * Symbols in a data segment pointed to by other symbols will now properly be split out as their own symbols

### 0.7.1

* Image segment changes:
  * Added `flip_x` and `flip_y` boolean parameters to replace `flip`.
    * `flip` is deprecated and will produce a warning when used.
    * Fixed flipping of `ci4` and `ci8` images.
  * Fixed `extract: false` (and `start: auto`) behaviour.

## 0.7.0: The Path Update

* Significantly better performance, especially when using the cache feature (`--use-cache` CLI arg).
* BREAKING: Some cli args for splat have been renamed. Please consult the usage output (-h or no args) for more information.
  * `--new` has been renamed to `--use-cache`
  * `--modes` arg changes:
    * Image modes have been combined into the `img` mode
    * Code and ASM modes have been combined into the `code` mode
* BREAKING: The `name` attribute of a segment now should no longer be a subdirectory but rather a meaningful name for the segment which will be used as the name of the linker section. If your `name` was previously a directory, please change it into a `dir`.
* BREAKING: `subsections` has been renamed to `subsegments`
* New `dir` segment attribute specifies a subdirectory into which files will be saved. You can combine `dir` ("foo") with a subsection file name containing a subdirectory ("bar/out"), and the paths will be joined (foo/bar/out.c)
  * If the `dir` attribute is specified but the `name` isn't, the `name` becomes `dir` with directory separation slashes replaced with underscores (foo/bar/baz -> foo_bar_baz)
* BREAKING: Many configuration options have been renamed. `_dir` options have been changed to the suffix `_path`.
* BREAKING: Assets (non-code, like `bin` and images) are now placed in the directory `asset_path` (defaults to `assets`).
* Linker symbol header generation. Set the `linker_symbol_header_path` option to use.
  * `typedef u8[] Addr;` is recommended in your `common.h` header.
* You can now provide `auto` as the `start` attribute for a segment, e.g. `[auto, c, my_file]`. This causes the segment to not be extracted, but linked. This feature is intended for modding.
* Providing just a ROM address but no type or name for a segment is now valid anywhere in `segments` or `subsegments` rather than just at the end of the ROM. It specifies the end of the previous segment for types that need it (`palette`, `bin`, `Yay0`) and causes the linker to simply write padding until that address.
* The linker script file is left untouched if the contents have not changed since the previous split.
* You can now group together segments with `type: group` (similar to `code`). Note that any ASM or C segments must live under a `type: code` segment, not a basic `group`.

### 0.6.5: Bugfixes, rodata migration, and made options static

If you wrote a custom extension, options should be imported and statically referenced
`from util import options`

see options.py for more info on how to now get and set options

BREAKING: vram can only be specified on a segment if the segment is defined as a dict in the config

### 0.6.3: More refactoring
**Breaking Change**: The command line args to split.py have changed. Currently, only the config path is now a required argument to splat. The old `rom` and `outdir` parameters are now optional (`--rom`, `--outdir`). Now, you can add rom and out directory paths in the yaml.

The `out_dir` option specifies a directory relative to the config file. If your config file is in a subdirectory of the main repo, you can set `out_dir: ../`, for example.

The `target_path` option spcifies a path to the binary file to split, relative to the `out_dir`. If your `baserom.z64` is in the top-level of the repo, you can set `target_path: baserom.z64`, for example.

### 0.6.2: subsegments
I've begun a refactor of the code "files" code, which makes everything cleaner and easier to extend.
There's also a new option, `create_new_c_files`, which disables the creation of nonexistent c files. This behavior is on by default, but if you want to disable it for any reason, you now have the option to do so.

I am also working on adding bss support as well. It should almost be all set, aside from the changes needed in the linker script.

**Breaking change**: The `files` field in `code` segments should now be renamed to `subsegments`.

### 0.6.1: `assets_dir` option

This release adds a new `assets_dir` option in `splat.yaml`s that allows you to override the default `img`, `bin`, and other directories that segments output to.

Want to interdisperse split assets with your sourcecode? `assets_dir: src`!
Want to have all assets live in a single directory? `assets_dir: assets`!

## 0.6: The Symbol Update
Internally, there's a new Symbol class which stores information about a symbol and is stored in a couple places during disassembly. Many things should be improved, such as reconciling symbols within overlays, things being named functions vs data symbols, and more.

**Breaking change**: The format to symbol_addrs.txt has been updated. After specifying the name and address of a symbol (`symbol = addr;`), optional properties of symbols can be set via inline comment, space delimited, in any order. The properties are of the format `name:value`
  * `type:` supports `func` mostly right now but will support `label` and `data` later on. Internally, `jtbl` is used as well, for jump tables. Splat uses type information during disassembly to disambiguate symbols with the same addresses.
  * `rom:` is for the hex rom address of the symbol, beginning with `0x`. If available, this information is extremely valuable for use in disambiguating symbols.
  * `size:` specifies the size of the symbol, which splat will use to generate offsets during disassembly. Uses the same format as `rom:`

**function example**: `FuncNameHere = 0x80023423; // type:func rom:0x10023`

**data example**: `gSomeDataVar = 0x80024233; // type:data size:0x100`

## 0.5 The Rename Update
* n64splat name changed to splat
  * Some refactoring was done to support other platforms besides n64 in the future 
    * New `platform` option, which defaults to `n64`
  * This will cause breaking changes in custom segments, so please refer to one of the changes in one of the n64 base segments for details
* Support for custom artifact paths 
  * New `undefined_syms_auto_path` option
  * New `undefined_funcs_auto_path` option
  * New `cache_path` option
  * (All path-like options' names now end with `_path`)
