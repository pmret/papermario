#include "common.h"

s32 D_8014EFC0[] = { 0x00000000, };
s32 D_8014EFC4[] = { 0x00011000, };
s32 D_8014EFC8[] = { 0x00000000, };
s32 D_8014EFCC[] = { 0x00080008, 0x00200010, 0x00100080, 0x00180018, 0x01200020, 0x00200200, 0x00300030, 0x04800040,
                     0x00400800, 0x00080010, 0x00400010, 0x00080040, 0x00100018, 0x00C00010, 0x00200100, 0x00400020,
                     0x04000020, 0x00100100, 0x000C000C, 0x00480030, 0x00180240, 0x00200008, 0x00800018, 0x00080060,
                     0x00400010, 0x02000010, 0x00400200, 0x00C00020, 0x0C000028, 0x00280320, 0x00180010, 0x00C00020,
                     0x00280280, 0x00280010, 0x01400028, 0x001801E0, 0x00200018, 0x01800014, 0x00200000, 0x00220020,
                     0x00000028, 0x002803C8, 0x00000000, 0xED000000, 0x005003C0, 0xE7000000, 0x00000000, 0xE3000A11,
                     0x00002CF0, 0xE2001E01, 0x00000000, 0xDF000000, 0x00000000, 0xED000000, 0x005003C0, 0xE7000000,
                     0x00000000, 0xE3000A11, 0x00002CF0, 0xE2001E01, 0x00000000, 0xDF000000, 0x00000000,
                   };
s32 D_8014F0C8[] = { 0xFFF40000, 0x00000000, 0x08000800, 0x000000FF, 0x00330000, 0x00000000, 0x00000800, 0x000000FF,
                     0x0033003F, 0x00000000, 0x00000000, 0x000000FF, 0xFFF4003F, 0x00000000, 0x08000000, 0x000000FF,
                     0xFFFFFF00, 0xFFFFFF00,
                   };
s32 D_8014F110[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };


INCLUDE_ASM(s32, "d5a50_len_5fd0", func_8013F350);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_8013F704);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80141100);

INCLUDE_ASM(s32, "d5a50_len_5fd0", init_menu_icon_list);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_801413F8);

INCLUDE_ASM(MenuIcon*, "d5a50_len_5fd0", create_icon, s32* iconIndex);

INCLUDE_ASM(s32, "d5a50_len_5fd0", update_menu_icons);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80141704);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80142210);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_8014271C);

INCLUDE_ASM(s32, "d5a50_len_5fd0", render_menu_icon);

INCLUDE_ASM(s32, "d5a50_len_5fd0", render_menu_icons);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80143C48);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144218);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144238);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144258);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144278);

INCLUDE_ASM(s32, "d5a50_len_5fd0", draw_menu_icon);

INCLUDE_ASM(s32, "d5a50_len_5fd0", draw_icon_0);

INCLUDE_ASM(s32, "d5a50_len_5fd0", draw_icon_1);

INCLUDE_ASM(s32, "d5a50_len_5fd0", draw_icon_2);

INCLUDE_ASM(s32, "d5a50_len_5fd0", set_menu_icon_script);

INCLUDE_ASM(s32, "d5a50_len_5fd0", get_menu_icon_script);

INCLUDE_ASM(s32, "d5a50_len_5fd0", get_menu_icon);

INCLUDE_ASM(s32, "d5a50_len_5fd0", free_icon, MenuIcon* iconIndex);

INCLUDE_ASM(void, "d5a50_len_5fd0", set_icon_render_pos, MenuIcon* iconIndex, s32 posX, s32 posY);

INCLUDE_ASM(s32, "d5a50_len_5fd0", get_icon_render_pos);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_801449DC);

INCLUDE_ASM(s32, "d5a50_len_5fd0", set_icon_flags);

INCLUDE_ASM(s32, "d5a50_len_5fd0", clear_icon_flags);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144A5C);

INCLUDE_ASM(void, "d5a50_len_5fd0", set_hud_element_scale, s32 index, f32 scale);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144DF4);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144E4C);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144E74);

INCLUDE_ASM(s32, "d5a50_len_5fd0", icon_set_opacity);

INCLUDE_ASM(s32, "d5a50_len_5fd0", icon_set_tint);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144F28);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80144FD8);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80145070);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80145108);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80145184);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_801451D4);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80145224);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_80145274);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_801452B4);

INCLUDE_ASM(s32, "d5a50_len_5fd0", func_801452E8);
