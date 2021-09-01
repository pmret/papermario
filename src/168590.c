#include "common.h"

INCLUDE_ASM(s32, "168590", filemenu_info_draw_message_contents);

INCLUDE_ASM(s32, "168590", filemenu_info_init);

INCLUDE_ASM(s32, "168590", filemenu_info_handle_input);

void filemenu_info_update(void) {
}

void filemenu_info_cleanup(void) {
}

void func_80248170(s32 idx) {
    Window* window = &gWindows[idx];

    if (window->updateCounter == 8) {
        window->flags &= ~0x8;
        set_window_update(idx, 1);
    }
}

INCLUDE_ASM(s32, "168590", filemenu_draw_contents_file_create_header);

INCLUDE_ASM(s32, "168590", filemenu_draw_contents_choose_name);

INCLUDE_ASM(s32, "168590", filemenu_choose_name_init);

INCLUDE_ASM(s32, "168590", filemenu_choose_name_handle_input);

void filemenu_choose_name_update(void) {
}

INCLUDE_ASM(s32, "168590", filemenu_choose_name_cleanup);
