#include "mac_01.h"

typedef struct BulletinBoardEntry {
    /* 0x00 */ s32 newsMessage;
    /* 0x04 */ s32 gossipMessage;
    /* 0x08 */ s32 requiredProgress;
} BulletinBoardEntry; // size = 0xC

extern BulletinBoardEntry D_802485E8_808E68[26];

ApiStatus GetBulletinMessages(Evt* script, s32 isInitialCall) {
    s32 idx = evt_get_variable(script, GameByte(349));

    script->varTable[0] = D_802485E8_808E68[idx].newsMessage;
    script->varTable[1] = D_802485E8_808E68[idx].gossipMessage;
    return ApiStatus_DONE2;
}

ApiStatus SelectBulletinMessages(Evt* script, s32 isInitialCall) {
    s32 temp_a0 = evt_get_variable(script, GameByte(0));
    BulletinBoardEntry* it;
    s32 i;

    it = &D_802485E8_808E68[ARRAY_COUNT(D_802485E8_808E68) - 1];

    for (i = ARRAY_COUNT(D_802485E8_808E68) - 1; i >= 0; i--, it--) {
        if (temp_a0 >= it->requiredProgress) {
            break;
        }
    }
    evt_set_variable(script, GameByte(349), i);
    return ApiStatus_DONE2;
}
