#include "common.h"

INCLUDE_ASM(s32, "168590", filemenu_info_draw_message_contents);

INCLUDE_ASM(s32, "168590", filemenu_info_init);

INCLUDE_ASM(s32, "168590", filemenu_info_handle_input);

void filemenu_info_update(void) {
}

void filemenu_info_cleanup(void) {
}

void func_80248170(s32 arg0) {
    UIPanel* panel = &gUIPanels[arg0];

    if (panel->unk_1C == 0x8) {
        panel->flags &= ~0x8;
        set_window_update(arg0, 1);
    }
}

INCLUDE_ASM(s32, "168590", filemenu_draw_contents_file_create_header);

INCLUDE_ASM(s32, "168590", filemenu_draw_contents_choose_name);

INCLUDE_ASM(s32, "168590", filemenu_choose_name_init);

INCLUDE_ASM(s32, "168590", filemenu_choose_name_handle_input);

void filemenu_choose_name_update(void) {
}

INCLUDE_ASM(s32, "168590", filemenu_choose_name_cleanup);
