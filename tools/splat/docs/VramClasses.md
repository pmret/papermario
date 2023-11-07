# vram classes

Version 0.19.0 introduced `vram_classes`, a new top-level yaml section that can be used to help reduce duplicated data in your yaml and more clearly organize its memory layout.

## Introduction
Before vram classes, you might have had something like this in your yaml:

```yaml
- type: code
  start: 0x4269D0
  vram: 0x802A9000
  vram_symbol: battle_move_end
  subsegments: ...
- type: code
  start: 0x4273B0
  vram: 0x802A9000  # notice same `vram` and `vram_symbol` for both segments
  vram_symbol: battle_move_end
  subsegments: ...
```

Having to duplicate the vram address and vram_symbol properties for potentially dozens of hundreds of overlay segments is tedious and pollutes your yaml with repeated information that can become out of sync. Enter vram_classes!

```yaml
- type: code
  start: 0x4269D0
  vram_class: maps
  subsegments: ...
- type: code
  start: 0x4273B0
  vram_class: maps
  subsegments: ...
```

Here, we are telling splat that both of these segments use the `maps` vram class. We are now effectively pointing both segments to the same source of information. Now let's look at how vram classes are defined:

## Format

```yaml
options:
  ...
  ld_use_symbolic_vram_addresses: True
  ...
vram_classes:
  - { name: maps, vram: 0x802A9000, vram_symbol: battle_move_end }
```

`vram_classes` is a top-level yaml section that contains a list of vram classes. You can either define them in dict form (as seen above) or list form. However, for list form, only `name` and `vram` are supported (`[maps, 0x802A9000]`). If you want to specify other options, please use the dict form. The fields supported are as follows:

- `name` (required): The name of the class

- `vram` (required): The vram address to be used during disasembly. If `ld_use_symbolic_vram_addresses` is disabled or no `vram_symbol` or `follows_classes` properties are provided, this address will be used in the linker script.

The following properties are optional and only take effect if `ld_use_symbolic_vram_addresses` is enabled:

- `vram_symbol`: The name of the symbol to use in the linker script for this class.

- `follows_classes`: A list of vram class names that this class must come after in memory. If we added `follows_classes: [apples, bananas]` to our above vram_class, this would make all `maps` segments start at the end of all `apples` and `bananas` segments.

The internal linker script symbol name that is chosen for `follows_classes` is the name of the class followed by `_CLASS_VRAM`. You can override this by also specifying `vram_symbol`.