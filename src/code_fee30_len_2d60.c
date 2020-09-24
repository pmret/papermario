#include "common.h"

INCLUDE_ASM("code_fee30_len_2d60", func_802DBD40);

INCLUDE_ASM("code_fee30_len_2d60", func_802DBD8C);

INCLUDE_ASM("code_fee30_len_2d60", func_802DBDBC);

INCLUDE_ASM("code_fee30_len_2d60", func_802DBE78);

INCLUDE_ASM("code_fee30_len_2d60", func_802DBFC0);

INCLUDE_ASM("code_fee30_len_2d60", func_802DC008);

INCLUDE_ASM("code_fee30_len_2d60", spr_appendMDL_component);

INCLUDE_ASM("code_fee30_len_2d60", spr_transform_point);

INCLUDE_ASM("code_fee30_len_2d60", spr_draw_component);

s32 _spr_sign_extend_12bit(u16 val) {
    s32 temp = val & 0xFFF;

    if (temp & 0x800) {
        return temp | ~0xFFF;
    } else {
        return temp;
    }
}

s32 _spr_sign_extend_16bit(u16 val) {
    s32 temp = val & 0xFFFF;

    if (temp & 0x8000) {
        return temp | ~0xFFFF;
    } else {
        return temp;
    }
}

INCLUDE_ASM("code_fee30_len_2d60", update_component);

INCLUDE_ASM("code_fee30_len_2d60", func_802DD634);

INCLUDE_ASM("code_fee30_len_2d60", func_802DD6DC);

INCLUDE_ASM("code_fee30_len_2d60", func_802DD7B0);

INCLUDE_ASM("code_fee30_len_2d60", func_802DD820);

INCLUDE_ASM("code_fee30_len_2d60", set_anim_timescale);

INCLUDE_ASM("code_fee30_len_2d60", func_802DD89C);

INCLUDE_ASM("code_fee30_len_2d60", func_802DD8F8);

INCLUDE_ASM("code_fee30_len_2d60", func_802DDA60);

INCLUDE_ASM("code_fee30_len_2d60", func_802DDA84);

INCLUDE_ASM("code_fee30_len_2d60", func_802DDA8C);

INCLUDE_ASM("code_fee30_len_2d60", render_sprite);

INCLUDE_ASM("code_fee30_len_2d60", func_802DDEC4);

INCLUDE_ASM("code_fee30_len_2d60", func_802DDEE4);

INCLUDE_ASM("code_fee30_len_2d60", func_802DDFF8);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE044);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE0C0);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE0EC);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE2AC);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE3D8);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE5C8);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE5E8);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE748);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE780);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE894);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE8DC);

INCLUDE_ASM("code_fee30_len_2d60", func_802DE9D8);

INCLUDE_ASM("code_fee30_len_2d60", func_802DEA40);

INCLUDE_ASM("code_fee30_len_2d60", func_802DEA6C);
