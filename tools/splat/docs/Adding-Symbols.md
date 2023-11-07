Symbols (i.e. labelling a function or variable) are controlled by the `symbols_addrs.txt` file.

The format for defining symbols is:

```ini
symbol = address; // option1:value1 option2:value2
```
e.g.
```ini
osInitialize = 0x801378C0; // type:func
```

:information_source: The file used can be overridden via the `symbol_addrs_path` setting in the global `options` section of the splat yaml. This option can also accept a list of paths, allowing for symbols to be organized in multiple files.

## symbol

This is the name of the symbol and can be any valid C variable name, e.g. `myCoolFunction` or `gReticulatedSplineCounter`

## address

This is the VRAM address expressed in hexadecimal, e.g. `0x80001050`

## options

An optional `key:pair` list of settings, note that each option should be separated by whitespace, but there should be no whitespace between the key:value pairs themselves.

### `type`

Override splat's automatic type detection, possible values are:
- `func`: Functions
- `jtbl`: Jumptables
- `jtbl_label`: Jumptables labels (inside functions)
- `label`: Branch labels (inside functions)
- `s8`, `u8`: To specify data/rodata to be disassembled as `.byte`s
- `s16`, `u16`: To specify data/rodata to be disassembled as `.short`s
- `s32`, `u32`: To specify data/rodata to be disassembled as `.word`s (the default)
- `s64`, `u64`: :man_shrugging:
- `f32`, `Vec3f`: To specify data/rodata to be disassembled as `.float`s
- `f64`: To specify data/rodata to be disassembled as `.double`s
- `asciz`, `char*`, `char`: C strings (disassembled as `.asciz`)
- Any custom type starting with a capital letter (will default to `.word`s)

Any other type will produce an error.

**Example:**
```ini
minFrameSize = 0x80241D08; // type:s32
```

### `size`

The size of the function or the size of the data depending on the type of the symbol. It specifies a size in bytes. e.g. `size:0x10`.

**Example:**
```ini
RawHuffmanTable = 0x8022E0E0; // type:symbol size:0x100
```

### `rom`

The ROM offset for the symbol, useful (potentially mandatory) for symbols in overlays where multiple symbols could share the same VRAM address.

**Example:**
```ini
create_particle_effect = 0x802D5F4C; // type:func rom:0x6E75FC
```

### `segment`

Allows specifying to which specific segment this symbol belongs to, useful to disambiguate symbols from segments that share the same VRAM address. This name must be the same as the name of a segment listed in the yaml.

**Example:**
```ini
sMenuTexture = 0x06004040; // segment:menu_assets
```

### `name_end`

Emits a symbol after the end of the data of the current symbol. Useful to reference the end of an assembly symbol, like RSP data.

**Example:**
```ini
rspbootTextStart = 0x80084690; // name_end:rspbootTextEnd
```

### `defined`

Forces the symbol to be defined - i.e. prevent it from appearing in `undefined_syms_auto.txt` should splat not encounter the symbol during the symbol detection phase.

**Example:**
```ini
__osDpDeviceBusy = 0x8014B3D0; // defined:true
```

### `extract`

TBD

### `ignore`

Prevents an address from being symbolized and referenced. Useful to get a finer control over the disassembled output.

**Example:**
```ini
D_A0000000 = 0xA0000000; // ignore:true
```

It can also be combined with the `size` attribute to avoid a range of addresses of being symbolized.

**Example:**
```ini
D_80000000 = 0x80000000; // ignore:true size:0x10
```

### `force_migration` and `force_not_migration`

Grants a finer control over the automatic rodata migration to functions. This may be required because of the migration heuristic failing to migrate (or to not migrate) a symbol, producing a disordered rodata section. Forcing the migration of a rodata symbol to a function will only work if that function references said rodata symbol. Forcing the not-migration of a rodata symbol always works.

This attribute is ignored if the `migrate_rodata_to_functions` option is disabled.

**Example:**
```ini
jtbl_800B13D0 = 0x800B13D0; // type:jtbl force_migration:True
STR_800B32A8 = 0x800C9520; // type:asciz force_not_migration:True
```

### `allow_addend` and `dont_allow_addend`

Allows this symbol to reference (or not reference) other symbols with an addend.

This attribute overrides the global `allow_data_addends` option.

**Example:**
```ini
aspMainTextStart = 0x80084760; // dont_allow_addend:True
```
