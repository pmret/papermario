#include "common.h"

INCLUDE_ASM(s32, "18C790", func_8025DEB0);

INCLUDE_ASM(s32, "18C790", func_8025DEC4);

INCLUDE_ASM(s32, "18C790", func_8025E030);

INCLUDE_ASM(s32, "18C790", func_8025E044);

INCLUDE_ASM(s32, "18C790", func_8025E108);

INCLUDE_ASM(s32, "18C790", func_8025E14C);

INCLUDE_ASM(s32, "18C790", btl_state_update_celebration);

INCLUDE_ASM(s32, "18C790", btl_draw_upgrade_windows);

INCLUDE_ASM(s32, "18C790", btl_state_draw_celebration);

INCLUDE_ASM(s32, "18C790", func_80260948);

void func_80260A20(s64 posX, s32 posY) {
    draw_msg(0x1D00AB, posX + 11, posY + 6, 0xFF, 0xF, 0);
}
