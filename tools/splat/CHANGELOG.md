# splat Release Notes

## 0.5
* n64splat name changed to splat
  * Some refactoring was done to support other platforms besides n64 in the future 
    * New `platform` option, which defaults to `n64`
  * This will cause breaking changes in custom segments, so please refer to one of the changes in one of the n64 base segments for details
* Support for custom artifact paths 
  * New `undefined_syms_auto_path` option
  * New `undefined_funcs_auto_path` option
  * New `cache_path` option
  * (All path-like options' names now end with `_path`)

## 0.6: The Symbol Update
Internally, there's a new Symbol class which stores information about a symbol and is stored in a couple places during disassembly. Many things should be improved, such as reconciling symbols within overlays, things being named functions vs data symbols, and more.

**Breaking change**: The format to symbol_addrs.txt has been updated. After specifying the name and address of a symbol (`symbol = addr;`), optional properties of symbols can be set via inline comment, space delimited, in any order. The properties are of the format `name:value`
  * `type:` supports `func` mostly right now but will support `label` and `data` later on. Internally, `jtbl` is used as well, for jump tables. Splat uses type information during disassembly to disambiguate symbols with the same addresses.
  * `rom:` is for the hex rom address of the symbol, beginning with `0x`. If available, this information is extremely valuable for use in disambiguating symbols.
  * `size:` specifies the size of the symbol, which splat will use to generate offsets during disassembly. Uses the same format as `rom:`

**function example**: `FuncNameHere = 0x80023423; // type:func rom:0x10023`

**data example**: `gSomeDataVar = 0x80024233; // type:data size:0x100`

### 0.6.1: `assets_dir` option

This release adds a new `assets_dir` option in `splat.yaml`s that allows you to override the default `img`, `bin`, and other directories that segments output to.

Want to interdisperse split assets with your sourcecode? `assets_dir: src`!
Want to have all assets live in a single directory? `assets_dir: assets`!

### 0.6.2: Subsections
I've begun a refactor of the code "files" code, which makes everything cleaner and easier to extend.
There's also a new option, `create_new_c_files`, which disables the creation of nonexistent c files. This behavior is on by default, but if you want to disable it for any reason, you now have the option to do so.

I am also working on adding bss support as well. It should almost be all set, aside from the changes needed in the linker script.

**Breaking change**: The `files` field in `code` segments should now be renamed to `subsections`.

### 0.6.3: More refactoring
**Breaking Change**: The command line args to split.py have changed. Currently, only the config path is now a required argument to splat. The old `rom` and `outdir` parameters are now optional (`--rom`, `--outdir`). Now, you can add rom and out directory paths in the yaml.

The `out_dir` option specifies a directory relative to the config file. If your config file is in a subdirectory of the main repo, you can set `out_dir: ../`, for example.

The `target_path` option spcifies a path to the binary file to split, relative to the `out_dir`. If your `baserom.z64` is in the top-level of the repo, you can set `target_path: baserom.z64`, for example.

### 0.6.5: Bugfixes, rodata migration, and made options static

If you wrote a custom extension, options should be imported and statically referenced
`from util import options`

see options.py for more info on how to now get and set options