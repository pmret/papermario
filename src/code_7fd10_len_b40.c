#include "common.h"

extern s16 D_8010CD00;

void func_800E6860(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    if ((D_8010EBB0[0] != 0) && (D_8010EBB0[3] == 9)) {
        Npc* partner = get_npc_unsafe(NpcId_PARTNER);

        func_802DDEE4(0, -1, 7, 0, 0, 0, playerStatus->unk_0E, 0);
        func_8003D624(partner, 7, playerStatus->unk_0E, 0, 0, 0, 0);
        playerStatus->unk_0F = 0;
    }
}

INCLUDE_ASM(s32, "code_7fd10_len_b40", func_800E6904);

INCLUDE_ASM(s32, "code_7fd10_len_b40", can_pause);

void func_800E6B68(void) {
    D_8010CD00 = 0;
}

INCLUDE_ASM(s32, "code_7fd10_len_b40", setup_partner_popup);

INCLUDE_ASM(s32, "code_7fd10_len_b40", setup_item_popup);

INCLUDE_ASM(s32, "code_7fd10_len_b40", check_input_open_menus);

INCLUDE_ASM(s32, "code_7fd10_len_b40", check_input_status_menu);
