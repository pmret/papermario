# Segments

The configuration file for **splat** consists of a number of well-defined segments.

Most segments can be defined as a either a dictionary or a list, however the list syntax is only suitable for simple cases as it does not allow for specifying many of the options a segment type has to offer.

Splat segments' behavior generally falls under two categories: extraction and linking. Some segments will only do extraction, some will only do linking, some both, and some neither. Generally, segments will describe both extraction and linking behavior. Additionally, a segment type whose name starts with a dot (.) will only focus on linking.

## `asm`

**Description:**

Segments designated Assembly, `asm`, will be disassembled via [spimdisasm](https://github.com/Decompollaborate/spimdisasm) and enriched with Symbols based on the contents of the `symbol_addrs` configuration.

**Example:**

```yaml
# as list
- [0xABC, asm, filepath1]
- [0xABC, asm, dir1/filepath2]  # this will create filepath2.s inside a directory named dir1

# as dictionary
- name: filepath
  type: asm
  start: 0xABC
```

### `hasm`

**Description:**

Hand-written Assembly, `hasm`, similar to `asm` except it will not overwrite any existing files. Useful when assembly has been manually edited.

**Example:**

```yaml
# as list
- [0xABC, hasm, filepath]

# as dictionary
- name: filepath
  type: hasm
  start: 0xABC
```

## `bin`

**Description:**

The `bin`(ary) segment type is for raw data, or data where the type is yet to be determined, data will be written out as raw `.bin` files.

**Example:**

```yaml
# as list
- [0xABC, bin, filepath]

# as dictionary
- name: filepath
  type: bin
  start: 0xABC
```

## `code`

**Description:**

The 'code' segment type, `code` is a group that can have many `subsegments`. Useful to group sections of code together (e.g. all files part of the same overlay).

**Example:**

```yaml
# must be a dictionary
- name:  main
  type:  code
  start: 0x00001000
  vram:  0x80125900
  subsegments:
    - [0x1000, asm, entrypoint]
    - [0x1050, c, main]
```

## `c`

**Description:**

The C code segments have two behaviors:

- If the target `.c` file does not exist, a new file will be generated with macros to include the original assembly (macros differ for IDO vs GCC compiler).
- Otherwise the target `.c` file is scanned to determine what assembly needs to be extracted from the ROM.

Assembly that is extracted due to a `c` segment will be written to a `nonmatchings` folder, with one function per file.

**Example:**

```yaml
# as list
- [0xABC, c, filepath]

# as dictionary
- name: filepath
  type: c
  start: 0xABC
```

## `header`

**Description:**

This is platform specific; parses the data and interprets as a header for e.g. N64 or PS1 elf.

**Example:**

```yaml
# as list
- [0xABC, header, filepath]

# as dictionary
- name: filepath
  type: header
  start: 0xABC
```

## `data`

**Description:**

Data located in the ROM. Extracted as assembly; integer, float and string types will be attempted to be inferred by the disassembler.

**Example:**

```yaml
# as list
- [0xABC, data, filepath]

# as dictionary
- name: filepath
  type: data
  start: 0xABC
```

This will created `filepath.data.s` within the `asm` folder.

## `.data`

**Description:**

Data located in the ROM that is linked from a C file. Use the `.data` segment to tell the linker to pull the `.data` section from the compiled object of corresponding `c` segment.

**Example:**

```yaml
# as list
- [0xABC, .data, filepath]

# as dictionary
- name: filepath
  type: .data
  start: 0xABC
```

**NOTE:** `splat` will not generate any `.data.s` files for these `.` (dot) sections.

## `rodata`

**Description:**

Read-only data located in the ROM, e.g. floats, strings and jump tables. Extracted as assembly; integer, float and string types will be attempted to be inferred by the disassembler.

**Example:**

```yaml
# as list
- [0xABC, rodata, filepath]

# as dictionary
- name: filepath
  type: rodata
  start: 0xABC
```

This will created `filepath.rodata.s` within the `asm` folder.

## `.rodata`

**Description:**

Read-only data located in the ROM, linked to a C file. Use the `.rodata` segment to tell the linker to pull the `.rodata` section from the compiled object of corresponding `c` segment.

**Example:**

```yaml
# as list
- [0xABC, .rodata, filepath]

# as dictionary
- name: filepath
  type: .rodata
  start: 0xABC
```

**NOTE:** `splat` will not generate any `.rodata.s` files for these `.` (dot) sections.

## `bss`

**Description:**

`bss` is where variables are placed that have been declared but are not given an initial value. These sections are usually discarded from the final binary (although PSX binaries seem to include them!).

Note that the `bss_size` option needs to be set at segment level for `bss` segments to work correctly.

**Example:**

```yaml
- { start: 0x7D1AD0, type: bss, name: filepath, vram: 0x803C0420 }
```

## `.bss`

**Description:**

Links the `.bss` section of the associated `c` file.

**Example:**

```yaml
- { start: 0x7D1AD0, type: .bss, name: filepath, vram: 0x803C0420 }
```

## Images

**Description:**

**splat** supports most of the [N64 image formats](https://n64squid.com/homebrew/n64-sdk/textures/image-formats/):

- `i`, i.e. `i4` and `i8`
- `ia`, i.e. `ia4`, `ia8`, and `ia16`
- `ci`, i.e. `ci4` and `ci8`
- `rgb`, i.e. `rgba32` and `rgba16`

These segments will parse the image data and dump out a `png` file.

**Note:** Using the dictionary syntax allows for richer configuration.

**Example:**

```yaml
# as list
- [0xABC, i4, filename, width, height]
# as a dictionary
- name: filename
  type: i4
  start: 0xABC
  width: 64
  height: 64
  flip_x: yes
  flip_y: no
```

## General segment options

All splat's segments can be passed extra options for finer configuration. Note that those extra options require to rewrite the entry using the dictionary yaml notation instead of the list one.

### `linker_section_order`

**Description:**

Allows overriding the section order used for linker script generation.

Useful when a section of a file is not between the other sections of the same type in the ROM, for example a file having its data section between other files's rodata.

Take in mind this option may need the [`check_consecutive_segment_types`](Configuration.md#check_consecutive_segment_types) yaml option to be turned off.

**Example:**

```yaml
- [0x400, data, file1]
# data ends

# rodata starts
- [0x800, rodata, file2]
- { start: 0xA00, type: data, name: file3, linker_section_order: .rodata }
- [0xC00, rodata, file4]
```

This will created `file3.data.s` within the `asm` folder, but won't be reordered in the generated linker script to be placed on the data section.

### `linker_section`

**Description:**

Allows to override the `.section` directive that will be used when generating the disassembly of the corresponding section, without needing to write an extension segment. This also affects the section name that will be used during link time.

Useful for sections with special names, like an executable section named `.start`

**Example:**

```yaml
- { start: 0x1000, type: asm, name: snmain, linker_section: .start }
- [0x1070, rdata, libc]
- [0x10A0, rdata, main_030]
```

### `ld_fill_value`

Allows to specify the value of the `FILL` statement generated for this specific top-level segment of the linker script, ignoring the global configuration.

It must be either an integer, which will be used as the parameter for the `FILL` statement, or `null`, which tells splat to not emit a `FILL` statement for this segment.

If not set, then the global configuration is used. See [ld_fill_value](Configuration.md#ld_fill_value) on the Configuration section.

Defaults to the value of the global option.
