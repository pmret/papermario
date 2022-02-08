#include "common.h"
#include "filemenu.h"

extern MenuWindowBP D_8024A0CC[2];

INCLUDE_ASM(s32, "167570", filemenu_yesno_draw_options_contents);

INCLUDE_ASM(s32, "167570", filemenu_yesno_draw_prompt_contents);

void filemenu_yesno_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A0CC); i++) {
        D_8024A0CC[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024A0CC, ARRAY_COUNT(D_8024A0CC));
    tab->initialized = TRUE;
}

INCLUDE_ASM(s32, "167570", filemenu_yesno_handle_input);

void filemenu_yesno_update(void) {
}

void filemenu_yesno_cleanup(void) {
}
