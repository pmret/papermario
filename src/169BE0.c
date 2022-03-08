#include "common.h"

extern Message* gFileMenuMessages[35];

INCLUDE_ASM(s32, "169BE0", filemenu_draw_char);

INCLUDE_ASM(s32, "169BE0", filemenu_draw_message);

// data migration
#ifdef NON_MATCHING
Message* filemenu_get_menu_message(s32 idx) {
    return gFileMenuMessages[idx];
}
#else
INCLUDE_ASM(s32, "169BE0", filemenu_get_menu_message);
#endif

void filemenu_draw_file_name(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        u32 temp = arg0[i];

        if (temp != 0xF7) {
            filemenu_draw_message(temp, arg2 + (i * arg7), arg3, arg4, arg5, arg6);
        }
    }
}
