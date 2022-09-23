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

WINDOW_UPDATE_FUNC(filemenu_update_show_title);

void filemenu_draw_file_name(u8*, s32, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_title(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_stereo(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_mono(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_option_left(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_option_center(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_option_right(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_0_info(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_0_title(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_1_info(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_1_title(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_2_info(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_2_title(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_3_info(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_3_title(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_yesno_draw_options_contents(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_yesno_draw_prompt_contents(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_info_draw_message_contents(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_file_create_header(MenuPanel*, s32, s32, s32, s32, s32, s32);
void filemenu_draw_contents_choose_name(MenuPanel*, s32, s32, s32, s32, s32, s32);

void filemenu_main_init(MenuPanel*);
void filemenu_main_handle_input(MenuPanel*);
void filemenu_main_update(MenuPanel*);
void filemenu_main_cleanup(MenuPanel*);
void filemenu_yesno_init(MenuPanel*);
void filemenu_yesno_handle_input(MenuPanel*);
void filemenu_yesno_update(MenuPanel*);
void filemenu_yesno_cleanup(MenuPanel*);
void filemenu_info_init(MenuPanel*);
void filemenu_info_handle_input(MenuPanel*);
void filemenu_info_update(MenuPanel*);
void filemenu_info_cleanup(MenuPanel*);
void filemenu_choose_name_init(MenuPanel*);
void filemenu_choose_name_handle_input(MenuPanel*);
void filemenu_choose_name_update(MenuPanel*);
void filemenu_choose_name_cleanup(MenuPanel*);

extern WindowStyleCustom D_8024BB08;
extern WindowStyleCustom D_8024BAD0;
extern WindowStyleCustom D_8024BB40;
extern WindowStyleCustom D_8024BB78;
extern WindowStyleCustom D_8024BBB0;
extern WindowStyleCustom D_8024BC58;
extern WindowStyleCustom D_8024BD38;
extern WindowStyleCustom D_8024BC90;
extern WindowStyleCustom D_8024BD70;
extern WindowStyleCustom D_8024BBE8;
extern WindowStyleCustom D_8024BCC8;
extern WindowStyleCustom D_8024BC20;
extern WindowStyleCustom D_8024BD00;
extern WindowStyleCustom D_8024BE88;
extern WindowStyleCustom D_8024BEF8;
extern WindowStyleCustom D_8024BF30;
extern WindowStyleCustom D_8024BEC0;

#endif
