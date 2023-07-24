import argparse
from pathlib import Path
import sys

sys.path.append(str(Path(__file__).parent.parent))
sys.path.append(str(Path(__file__).parent.parent / "splat"))

from splat_ext.pm_effect_loads import effects_from_yaml


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Builds effect table, function declarations, macros, and enum"
    )
    parser.add_argument("in_yaml")
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()

    effect_enum_text = "enum EffectID {\n"
    effect_table_text = "EffectTableEntry gEffectTable[] = {\n"
    fx_decls_text = '#include "effects/effect_macros.h"\n\n'
    main_decls_text = '#include "effects/effect_macros.h"\n\n'
    macro_defs = ""

    effects = effects_from_yaml(args.in_yaml)

    for i, effect in enumerate(effects):
        enum_name = effect.name.upper()
        if not enum_name.startswith("EFFECT_"):
            enum_name = "EFFECT_" + enum_name

        effect_enum_text += f"    {enum_name} = 0x{i:02X},\n"
        if not effect.empty:
            effect_table_text += (
                f"    FX_ENTRY({effect.name}, effect_gfx_{effect.gfx}),\n"
            )
            fx_decls_text += effect.get_macro_call("fx_" + effect.name) + ";\n"
            main_decls_text += effect.get_macro_call(effect.name + "_main") + ";\n"
            macro_defs += effect.get_macro_def() + "\n"
        else:
            effect_table_text += "    {},\n"

    args.out_dir.mkdir(parents=True, exist_ok=True)

    with open(args.out_dir / "effect_macros.h", "w") as f:
        f.write(macro_defs)

    with open(args.out_dir / "effect_table.c", "w") as f:
        f.write(main_decls_text + "\n" + effect_table_text + "};\n")

    with open(args.out_dir / "effect_defs.h", "w") as f:
        f.write(effect_enum_text + "};\n\n" + fx_decls_text)
