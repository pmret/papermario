#include "common.h"
#include "filemenu.h"

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_title);

void filemenu_draw_contents_stereo(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (gGameStatusPtr->unk_AB == 1) {
        set_hud_element_render_pos(filemenu_hudElemIDs[18], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[18]);
    } else {
        set_hud_element_render_pos(filemenu_hudElemIDs[19], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[19]);
    }
}

void filemenu_draw_contents_mono(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (gGameStatusPtr->unk_AB == 0) {
        set_hud_element_render_pos(filemenu_hudElemIDs[16], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[16]);
    } else {
        set_hud_element_render_pos(filemenu_hudElemIDs[17], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[17]);
    }
}

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_option_left);

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_option_center);

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_option_right);

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_file_info);

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_file_title);

void filemenu_draw_contents_file_0_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_1_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_2_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_3_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(3, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_0_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_1_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_2_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_3_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(3, menu, baseX, baseY, width, height, opacity, darkening);
}

INCLUDE_ASM(s32, "165490", filemenu_main_init);

INCLUDE_ASM(s32, "165490", filemenu_main_handle_input);

INCLUDE_ASM(s32, "165490", filemenu_main_update);

void filemenu_main_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        free_hud_element(filemenu_hudElemIDs[i]);
    }
}
