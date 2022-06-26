#include "mac_02.h"

#define CHUCK_QUIZMO_NPC_ID 12

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);
extern s32 D_80248778_82BA38;
extern s32 D_8024877C_82BA3C;
extern s32 D_8024EA10;
extern s32 D_8024EA14;

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// needs data migration, matching otherwise
#ifdef NON_MATCHING
extern s32 D_80248778_82BA38;
s32 D_8024877C_82BA3C = 0;

ApiStatus func_80242A80_825D40(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    if (isInitialCall) {
        D_80248778_82BA38 = 0;
    }
    if (D_80248778_82BA38 != 0) {
        D_80248778_82BA38 = 0;
        evt_set_variable(script, args[0], D_8024877C_82BA3C);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242A80_825D40);
#endif

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242AD4_825D94);

extern s32 D_8024E570[];

ApiStatus func_80242B0C_825DCC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024E570[i] = ptr[i];
        }
        D_8024E570[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
          D_8024E570[i] = i + 16;
            D_8024E570[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242BA8_825E68);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242C44_825F04);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242DBC_82607C);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242F60_826220);

ApiStatus func_80243040_826300(Evt* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_count());

    return ApiStatus_DONE2;
}

ApiStatus func_80243088_826348(Evt* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_empty_count());

    return ApiStatus_DONE2;
}

ApiStatus func_802430D0_826390(Evt* script, s32 isInitialCall) {
    s32 i = 90;
    s32* ptr = &D_8024EA10;
    s32 val = 218;

    while (i >= 0) {
        *ptr-- = val;
        val--;
        i--;
    }

    D_8024EA14 = 0;

    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

#include "world/common/UnkMusicFunc.inc.c"
