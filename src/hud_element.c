#include "common.h"
#include "hud_element.h"

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

extern s32 D_801512B4;

INCLUDE_ASM(s32, "hud_element", load_hud_element);

INCLUDE_ASM(s32, "hud_element", draw_rect_hud_element);

INCLUDE_ASM(s32, "hud_element", clear_hud_element_cache);

INCLUDE_ASM(s32, "hud_element", init_hud_element_list);

INCLUDE_ASM(s32, "hud_element", func_801413F8);

INCLUDE_ASM(HudElement*, "hud_element", create_hud_element, s32* iconIndex);

INCLUDE_ASM(s32, "hud_element", update_hud_elements);

INCLUDE_ASM(s32, "hud_element", hud_element_update);

INCLUDE_ASM(s32, "hud_element", render_hud_elements_backUI);

INCLUDE_ASM(s32, "hud_element", render_hud_elements_frontUI);

INCLUDE_ASM(s32, "hud_element", render_hud_element);

INCLUDE_ASM(s32, "hud_element", render_hud_elements_world);

INCLUDE_ASM(s32, "hud_element", func_80143C48);

void func_80144218(s32 arg0) {
    func_80143C48(arg0, 1, 3);
}

void func_80144238(s32 arg0) {
    func_80143C48(arg0, 0, 3);
}

void func_80144258(s32 arg0) {
    func_80143C48(arg0, 1, 1);
}

void func_80144278(s32 arg0) {
    func_80143C48(arg0, 0, 1);
}

INCLUDE_ASM(s32, "hud_element", draw_hud_element);

void draw_hud_element_clipped(s32 arg0) {
    draw_hud_element(arg0, 0);
}

void draw_hud_element_2(s32 arg0) {
    draw_hud_element(arg0, 1);
}

void draw_icon_2(s32 iconID) {
    draw_hud_element(iconID, 2);
}

void set_hud_element_script(s32 arg0, s32 *arg1) {
    HudElement* hudElement = gHudElementList[arg0 & ~0x800];

    if (arg1 == NULL) {
        arg1 = D_8014EFC8;
    }

    hudElement->updateTimer = 1;
    hudElement->widthScale = 1024;
    hudElement->heightScale = 1024;
    hudElement->readPos = arg1;
    hudElement->startReadPos = arg1;
    hudElement->ptrPropertyList = arg1;
    hudElement->screenPosOffset[0] = 0;
    hudElement->screenPosOffset[1] = 0;
    hudElement->worldPosOffset[0] = 0;
    hudElement->worldPosOffset[1] = 0;
    hudElement->flags &= ~4;
    hudElement->uniformScale = 1.0f;
    hudElement->flags &= ~0x930;
    load_hud_element(hudElement, arg1);

    while (hud_element_update(hudElement) != 0) {}
}

s32* get_hud_element_script(s32 arg0) {
    return gHudElementList[arg0 & ~0x800]->startReadPos;
}

HudElement* get_hud_element(s32 arg0) {
    return gHudElementList[arg0 & ~0x800];
}

void free_hud_element(s32 arg0) {
    if (gHudElementList[arg0 & ~0x800]->flags & 0x10000) {
        free_hud_element_transform(arg0 & ~0x800);
    }

    heap_free(gHudElementList[arg0 & ~0x800]);
    gHudElementList[arg0 & ~0x800] = NULL;
    D_801512B4--;
}

void set_hud_element_render_pos(s32 iconIndex, s32 posX, s32 posY) {
    HudElement* hudElement = gHudElementList[iconIndex & ~0x800];

    hudElement->renderPosX = posX;
    hudElement->renderPosY = posY;
}

void get_hud_element_render_pos(s32 iconIndex, s32* x, s32* y) {
    HudElement* hudElement = gHudElementList[iconIndex & ~0x800];

    *x = hudElement->renderPosX;
    *y = hudElement->renderPosY;
}

INCLUDE_ASM(s32, "hud_element", set_hud_element_render_depth);

void set_hud_element_flags(s32 iconIndex, s32 flags) {
    gHudElementList[iconIndex & ~0x800]->flags |= flags;
}

void clear_hud_element_flags(s32 iconIndex, s32 flags) {
    gHudElementList[iconIndex & ~0x800]->flags &= ~flags;
}

INCLUDE_ASM(s32, "hud_element", ALT_clear_hud_element_cache);

INCLUDE_ASM(void, "hud_element", set_hud_element_scale, s32 index, f32 scale);

void set_hud_element_size(s32 arg0, s8 arg1) {
    HudElement* hudElement = gHudElementList[arg0 & ~0x800];

    hudElement->widthScale = 0x400;
    hudElement->heightScale = 0x400;
    hudElement->tileSizePreset = arg1;
    hudElement->drawSizePreset = arg1;
    hudElement->uniformScale = 1.0f;
    hudElement->flags &= ~0x100;
    hudElement->flags &= ~0x810;
}

INCLUDE_ASM(s32, "hud_element", func_80144E4C);

void func_80144E74(s32 iconIndex, s32 arg1) {
    HudElement* hudElement = gHudElementList[iconIndex & ~0x800];

    hudElement->flags &= ~0xF000000;
    hudElement->flags |= arg1 << 24;
}

void set_hud_element_alpha(s32 iconIndex, s32 opacity) {
    HudElement* hudElement = gHudElementList[iconIndex & ~0x800];

    hudElement->flags |= 0x20;
    hudElement->opacity = opacity;

    if (opacity == 255) {
        hudElement->flags &= ~0x20;
    }
}

void set_hud_element_tint(s32 iconIndex, s32 tint1, s32 tint2, s32 tint3) {
    HudElement* hudElement = gHudElementList[iconIndex & ~0x800];

    hudElement->tint[0] = tint1;
    hudElement->tint[1] = tint2;
    hudElement->tint[2] = tint3;
}

INCLUDE_ASM(s32, "hud_element", create_hud_element_transform_A);

INCLUDE_ASM(s32, "hud_element", create_hud_element_transform_B);

INCLUDE_ASM(s32, "hud_element", create_hud_element_transform_C);

void free_hud_element_transform(s32 arg0) {
    HudElement* hudElement = gHudElementList[arg0 & ~0x800];
    s32* hudTransform = hudElement->hudTransform;

    if (!(hudElement->flags & 0x20000)) {
        func_8013A854(*hudTransform);
    }

    heap_free(hudElement->hudTransform);
    hudElement->hudTransform = NULL;
    hudElement->flags &= ~0x40030000;
}

INCLUDE_ASM(s32, "hud_element", set_hud_element_transform_pos);

INCLUDE_ASM(s32, "hud_element", set_hud_element_transform_scale);

INCLUDE_ASM(s32, "hud_element", set_hud_element_transform_rotation);

INCLUDE_ASM(s32, "hud_element", set_hud_element_transform_rotation_pivot);

INCLUDE_ASM(s32, "hud_element", copy_world_hud_element_ref_to_battle);

INCLUDE_ASM(s32, "hud_element", set_hud_element_nonworld_cache);
