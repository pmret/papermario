Splat has various options for configuration, all of which are listed under the `options` section of the yaml file.

## Project configuration

### base_path

Path that all other configured paths are relative to.

#### Usage

```yaml
base_path: path/to/base/folder
```

#### Default

`.` *(Current directory)*


### target_path

Path to target binary.

#### Usage

```yaml
target_path: path/to/target/binary
```

### elf_path

Path to the final elf target

#### Default
Path to the binary that was used as the input to `create_config.py`


### platform

The target platform for the binary. Options are 
- `n64` (Nintendo 64)
- `psx` (PlayStation 1)
- `ps2` (PlayStation 2)
- `gc` (GameCube)

#### Usage
```yaml
platform: psx
```


### compiler

Compiler used to build the binary.

splat recognizes the following compilers, and it will adapt it behavior accordingly for them, but unknown compilers can be passed as well:
- GCC
- SN64
- IDO

#### Usage
```yaml
compiler: IDO
```

#### Default
`ido`


### endianness

Determines the endianness of the target binary. If not set, the endiannesss will be guessed from the selected platform.

Valid values:
- big
- little


### section_order

Determines the default section order of the target binary. This can be overridden per-segment.

Expects a list of strings.


### generated_c_preamble

String that is placed before the contents of newly-generated `.c` files.

#### Usage

```yaml
generated_c_preamble: #include "header.h"
```

#### Default

`#include "common.h"`


### generated_s_preamble

String that is placed before the contents of newly-generated assembly (`.s`) files.

#### Usage

```yaml
generated_s_preamble: .set fp=64
```


### o_as_suffix

Determines whether to replace the suffix of the file to `.o` or to append `.o` to the suffix of the file.


### gp_value

The value of the `$gp` register to correctly calculate offset to `%gp_rel` relocs.


### check_consecutive_segment_types

By default splat will check and error if there are any non consecutive segment types.
This option disables said feature.

#### Usage

```yaml
# Disable checking for non-consecutive segments
check_consecutive_segment_types: False
```


## Paths


### asset_path

Path to output split asset files.

#### Usage

```yaml
asset_path: path/to/assets/folder
```

#### Default

`assets`


### symbol_addrs_path

Determines the path to the symbol addresses file(s). A `symbol_addrs` file is to be updated/curated manually and contains addresses of symbols as well as optional metadata such as rom address, type, and more

It's possible to use more than one file by supplying a list instead of a string

#### Usage
```yaml
symbol_addrs_path: path/to/symbol_addrs
```

#### Default
`symbol_addrs.txt`



### reloc_addrs_paths



### build_path
Path that built files will be found. Used for generation of the linker script.

#### Usage
```yaml
build_path: path/to/build/folder
```

#### Default
`build`


### src_path
Path to split `.c` files.

#### Usage
```yaml
src_path: path/to/src/folder
```

#### Default
`src`


### asm_path
Path to output split assembly files.

#### Usage
```yaml
asm_path: path/to/asm/folder
```

#### Default
`asm`


### data_path

Determines the path to the asm data directory


### nonmatchings_path

Determines the path to the asm nonmatchings directory


### cache_path
Path to splat cache

#### Usage
```yaml
cache_path: path/to/splat/cache
```

#### Default
`.splat_cache`


### create_undefined_funcs_auto
If `True`, splat will generate an `undefined_funcs_auto.txt` file.

#### Usage
```yaml
create_undefined_funcs_auto: False
```

#### Default
`True`


### undefined_funcs_auto_path
Path to file containing automatically defined functions.

#### Usage
```yaml
undefined_funcs_auto_path: path/to/undefined_funcs_auto.txt
```

#### Default
`undefined_funcs_auto.txt`



### create_undefined_syms_auto
If `True`, splat will generate an `undefined_syms_auto.txt` file.

#### Usage
```yaml
create_undefined_syms_auto: False
```

#### Default
`True`


### undefined_syms_auto_path
Path to file containing automatically defined symbols.

#### Usage
```yaml
undefined_syms_auto_path: path/to/undefined_syms_auto.txt
```

#### Default
`undefined_syms_auto.txt`


### extensions_path
If you are using splat extension(s), this is the path they will be loaded from.

#### Usage
```yaml
extensions_path: path/to/extensions/folder
```

#### Default
`tools/splat_ext`


### lib_path

Determines the path to library files that are to be linked into the target binary


### elf_section_list_path
Path to file containing elf section list.

#### Usage
```yaml
elf_section_list_path: path/to/elf_sections
```

#### Default
`elf_sections.txt`


## Linker script


### subalign

Sub-alignment (in bytes) of sections.

#### Usage
```yaml
subalign: 4
```

#### Default
`16`


### auto_all_sections

TODO

### ld_script_path

Path to output ld script.

#### Usage

```yaml
ld_script_path: path/to/ld/script.ld
```

#### Default

`{basename}.ld`


### ld_symbol_header_path

Path to output a header containing linker symbols.

#### Usage
```yaml
ld_symbol_header_path: path/to/linker_symbol_header
```

### ld_discard_section

Determines whether to add a discard section to the linker script

### ld_section_labels

Determines the list of section labels that are to be added to the linker script

### ld_wildcard_sections

Determines whether to add wildcards for section linking in the linker script (.rodata* for example)

### ld_use_symbolic_vram_addreses

Determines whether to use `follows_vram` (segment option) and `vram_symbol` / `follows_classes` (vram_class options) to calculate vram addresses in the linker script.
Enabled by default. If disabled, this uses the plain integer values for vram addresses defined in the yaml.

### ld_partial_linking

Change linker script generation to allow partially linking segments. Requires both `ld_partial_scripts_path` and `ld_partial_build_segments_path` to be set.

### ld_partial_scripts_path

Folder were each intermediary linker script will be written to.

### ld_partial_build_segments_path

Folder where the built partially linked segments will be placed by the build system.

### ld_dependencies

Generate a dependency file for every linker script generated. Dependency files will have the same path and name as the corresponding linker script, but changing the extension to `.d`. Requires `elf_path` to be set.

### ld_legacy_generation

Legacy linker script generation does not impose the section_order specified in the yaml options or per-segment options.

### segment_end_before_align

If enabled, the end symbol for each segment will be placed before the alignment directive for the segment

### segment_symbols_style

Controls the style of the auto-generated segment symbols in the linker script.

Possible values:
- splat
- makerom


### ld_rom_start

Specifies the starting offset for rom address symbols in the linker script.


### ld_fill_value

Allows to specify the value of the `FILL` statement generated on every segment of the linker script.

It must be either an integer, which will be used as the parameter for the `FILL` statement, or `null`, which tells splat to not emit `FILL` statements.

This behavior can be customized per segment too. See [ld_fill_value](Segments.md#ld_fill_value) on the Segments section.

Defaults to 0.


## C file options

### create_c_files

Determines whether to create new c files if they don't exist

### auto_decompile_empty_functions

Determines whether to "auto-decompile" empty functions

### do_c_func_detection

Determines whether to detect matched/unmatched functions in existing c files so we can avoid creating `.s` files for already-decompiled functions.

### c_newline

Determines the newline char(s) to be used in c files


## (Dis)assembly-related options

### symbol_name_format

Determine the format that symbols should be named by default

### symbol_name_format_no_rom

Same as `symbol_name_format` but for symbols with no rom address

### find_file_boundaries

Determines whether to detect and hint to the user about likely file splits when disassembling.

This setting can also be set on a per segment basis, if you'd like to enable or disable detection for specific segments. This could be useful when you are confident you identified all subsegments in a segment, yet `splat` still hints that subsegments could be split.  

### pair_rodata_to_text

Determines whether to detect and hint to the user about possible rodata sections corresponding to a text section

### migrate_rodata_to_functions

Determines whether to attempt to automatically migrate rodata into functions

### asm_inc_header

Determines the header to be used in every asm file that's included from c files

### asm_function_macro

Determines the macro used to declare functions in asm files

### asm_function_alt_macro

Determines the macro used to declare symbols in the middle of functions in asm files (which may be alternative entries)

### asm_jtbl_label_macro

Determines the macro used to declare jumptable labels in asm files

### asm_data_macro

Determines the macro used to declare data symbols in asm files

### asm_end_label

Determines the macro used at the end of a function, such as endlabel or .end

### asm_emit_size_directive

Toggles the .size directive emitted by the disassembler

### include_macro_inc

Determines including the macro.inc file on non-migrated rodata variables

### mnemonic_ljust

Determines the number of characters to left align before the instruction

### rom_address_padding

Determines whether to pad the rom address

### mips_abi_gpr

Determines which ABI names to use for general purpose registers

### mips_abi_float_regs

Determines which ABI names to use for floating point registers.

Valid values:
- numeric
- o32
- n32
- n64

`o32`` is highly recommended, as it provides logically named registers for floating point instructions.
For more info, see https://gist.github.com/EllipticEllipsis/27eef11205c7a59d8ea85632bc49224d

### add_set_gp_64

Determines whether to add ".set gp=64" to asm/hasm files

### create_asm_dependencies

Generate `.asmproc.d` dependency files for each C file which still reference functions in assembly files

### string_encoding

Global option for rodata string encoding. This can be overriden per segment

### data_string_encoding

Global option for data string encoding. This can be overriden per segment

### rodata_string_guesser_level

Global option for the rodata string guesser. 0 disables the guesser completely.

### data_string_guesser_level

Global option for the data string guesser. 0 disables the guesser completely.

### allow_data_addends

Global option for allowing data symbols using addends on symbol references. It can be overriden per symbol

### disasm_unknown

Tells the disassembler to try disassembling functions with unknown instructions instead of falling back to disassembling as raw data

### detect_redundant_function_end

Tries to detect redundant and unreferenced functions ends and merge them together. This option is ignored if the compiler is not set to IDO.

### disassemble_all

Don't skip disassembling already matched functions and migrated sections


## N64-specific options

### header_encoding

Used to specify what encoding should be used used when parsing the N64 ROM header.

#### Default

`ASCII`


### gfx_ucode

Determines the type gfx ucode (used by gfx segments)

Valid options are:
- f3d
- f3db
- f3dex
- f3dexb
- f3dex2

### libultra_symbols

Use named libultra symbols by default. Those will need to be added to a linker script manually by the user

### ique_symbols

Use named libultra symbols by default. Those will need to be added to a linker script manually by the user

### hardware_regs

Use named hardware register symbols by default. Those will need to be added to a linker script manually by the user


## Gamecube-specific options

### filesystem_path

Path where the iso's filesystem will be extracted to

## Compiler-specific options

### use_legacy_include_asm
If `True`, generate c files using the longer `INCLUDE_ASM` macro. This is defaulted to `True` to by-default support projects using the longer macro.

#### Usage
```yaml
use_legacy_include_asm: False
```

#### Default
`True`
