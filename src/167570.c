#include "common.h"
#include "filemenu.h"

extern MenuWindowBP D_8024A0CC[2];

void filemenu_yesno_draw_options_contents(MenuPanel* tab, s32 posX, s32 posY) {
    s32 xOffset1;
    s32 yOffset1;
    s32 xOffset2;
    s32 yOffset2;
    s32 cursorGoalXOffset;
    s32 cursorGoalYOffset;

    switch (tab->page) {
        case 0:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 1:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 2:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 3:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 4:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_YES), posX + xOffset1, posY + yOffset1, 0xFF, 0, 0);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_NO), posX + xOffset2, posY + yOffset2, 0xFF, 0, 0);

    if (filemenu_8024C098 == 1) {
        if (tab->selected == 0) {
            cursorGoalXOffset = xOffset1 - 10;
            cursorGoalYOffset = yOffset1 + 8;
        } else {
            cursorGoalXOffset = xOffset2 - 10;
            cursorGoalYOffset = yOffset2 + 8;
        }
        filemenu_set_cursor_goal_pos(0x32, posX + cursorGoalXOffset, posY + cursorGoalYOffset);
    }
}

void filemenu_yesno_draw_prompt_contents(MenuPanel* tab, s32 posX, s32 posY) {
    s32 xOffset;
    s32 i;

    switch (tab->page) {
        case 0:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE), posX + 10, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), posX + 60, posY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, posX + 98, posY + 6, 0, 0, 0xFF, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), posX + 99, posY + 4, 0xFF, 0, 0);
            break;
        case 3:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), posX + 10, posY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, posX + 48, posY + 6, 0, 0, 0xFF, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_WILL_BE_DELETED), posX + 49, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK_TO_COPY_TO_THIS_FILE), posX + 10, posY + 18, 0xFF, 0, 0);
            break;
        case 1:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OVERRIDE_TO_NEW_DATA), posX + 10, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_SAVE_OK), posX + 10, posY + 18, 0xFF, 0, 0);
            break;
        case 2:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_NAME_IS), posX + 10, posY + 6, 0xFF, 0, 0);

            for (i = ARRAY_COUNT(filemenu_8024C110) - 1; i >= 0; i--) {
                if (filemenu_8024C110[i] != 0xF7) {
                    break;
                }
            }

            xOffset = (147 - (i * 11)) / 2;
            filemenu_draw_file_name(&filemenu_8024C110, i + 1, posX + xOffset, posY + 22, 0xFF, 0, 8, 0xB);
            xOffset += (i + 1) * 11;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_20), posX + xOffset, posY + 22, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK), posX + 70, posY + 38, 0xFF, 0, 0);
            break;
        case 4:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_START_GAME_WITH), posX + 10, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), posX + 127, posY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, posX + 165, posY + 6, 0, 0, 0xFF, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), posX + 162, posY + 4, 0xFF, 0, 0);
            break;
    }
}

void filemenu_yesno_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A0CC); i++) {
        D_8024A0CC[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024A0CC, ARRAY_COUNT(D_8024A0CC));
    tab->initialized = TRUE;
}

static const f32 padding = 0.0f;

INCLUDE_ASM(s32, "167570", filemenu_yesno_handle_input);

void filemenu_yesno_update(void) {
}

void filemenu_yesno_cleanup(void) {
}
