#ifndef _FILEMENU_H_
#define _FILEMENU_H_

#include "common.h"

extern MenuPanel* filemenu_menus[4];

extern BSS s32 filemenu_iterFileIdx;
extern BSS s32 filemenu_pressedButtons;
extern BSS s32 filemenu_8024C088;
extern BSS s32 filemenu_heldButtons;
extern BSS s32 filemenu_8024C090;
extern BSS s32 filemenu_loadedFileIdx;
extern BSS s8 filemenu_8024C098;
extern BSS s32 filemenu_8024C09C;
extern BSS s32 filemenu_cursorHudElemID[1];
extern BSS s32 filemenu_8024C0A4[3];
extern BSS s32 filemenu_hudElemIDs[20];
extern BSS s32 filemenu_8024C100[4];
extern BSS u8 filemenu_8024C110[8];

#define WINDOW_UPDATE_FUNC(name) void (name)( \
    s32 windowIdx,\
    s32* flags,\
    s32* posX, s32* posY, s32* posZ,\
    f32* scaleX, f32* scaleY,\
    f32* rotX, f32* rotY, f32* rotZ,\
    s32* darkening,\
    s32* opacity);\

WINDOW_UPDATE_FUNC(filemenu_update_show_name_input);
WINDOW_UPDATE_FUNC(filemenu_update_show_options_left);
WINDOW_UPDATE_FUNC(filemenu_update_show_options_right);
WINDOW_UPDATE_FUNC(filemenu_update_show_options_bottom);
WINDOW_UPDATE_FUNC(filemenu_update_show_with_rotation);

WINDOW_UPDATE_FUNC(filemenu_update_hidden_name_input);
WINDOW_UPDATE_FUNC(filemenu_update_hidden_options_left);
WINDOW_UPDATE_FUNC(filemenu_update_hidden_options_right);
WINDOW_UPDATE_FUNC(filemenu_update_hidden_title);
WINDOW_UPDATE_FUNC(filemenu_update_hidden_options_bottom);
WINDOW_UPDATE_FUNC(filemenu_update_hidden_with_rotation);

WINDOW_UPDATE_FUNC(filemenu_update_select_file);
WINDOW_UPDATE_FUNC(filemenu_update_deselect_file);

WINDOW_UPDATE_FUNC(filemenu_update_show_name_confirm);
WINDOW_UPDATE_FUNC(filemenu_update_hidden_name_confirm);

WINDOW_UPDATE_FUNC(main_menu_window_update);

void filemenu_draw_file_name(u8*, s32, s32, s32, s32, s32, s32, s32);

#endif
