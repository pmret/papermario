#include "common.h"

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80058DD0);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80058E84);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80058F88);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059008);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_8005904C);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059310);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_800598A0);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059AB8);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059BD4);

void func_80059C80(void) {
}

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059C88);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059C9C);

void func_80059D48(void) {
}

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059D50);

INCLUDE_ASM(s32, "code_341d0_len_20d0", render_effects);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_80059F94);

INCLUDE_ASM(s32, "code_341d0_len_20d0", func_8005A2BC);

INCLUDE_ASM(s32, "code_341d0_len_20d0", remove_effect);

INCLUDE_ASM(s32, "code_341d0_len_20d0", remove_all_effects);

INCLUDE_ASM(s32, "code_341d0_len_20d0", play_effect);

void load_map_script_lib(void) {
    dma_copy(&mapScriptLibStart, &mapScriptLibEnd, &mapScriptLibVram);
}

INCLUDE_ASM(s32, "code_341d0_len_20d0", load_map_by_IDs);

INCLUDE_ASM(s32, "code_341d0_len_20d0", get_current_map_config);

INCLUDE_ASM(s32, "code_341d0_len_20d0", get_current_map_header);

INCLUDE_ASM(s32, "code_341d0_len_20d0", get_map_IDs_by_name);

INCLUDE_ASM(void*, "code_341d0_len_20d0", load_asset_by_name, char* name, s32* decompressedSize);

INCLUDE_ASM(s32, "code_341d0_len_20d0", get_asset_offset);
