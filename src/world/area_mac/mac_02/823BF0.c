#include "mac_02.h"

#define CHUCK_QUIZMO_NPC_ID 12

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);
extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
extern s32 D_8024EA10;
extern s32 D_8024EA14;

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// needs data migration, matching otherwise
#ifdef NON_MATCHING
s32 mac_02_ItemChoice_SelectedItemID = 0;

ApiStatus func_80242A80_825D40(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    if (isInitialCall) {
        mac_02_ItemChoice_HasSelectedItem = 0;
    }
    if (mac_02_ItemChoice_HasSelectedItem != 0) {
        mac_02_ItemChoice_HasSelectedItem = 0;
        evt_set_variable(script, args[0], mac_02_ItemChoice_SelectedItemID);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242A80_825D40);
#endif

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 mac_02_D_8024E570[];

ApiStatus func_80242B0C_825DCC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_02_D_8024E570[i] = ptr[i];
        }
        mac_02_D_8024E570[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_02_D_8024E570[i] = i + 16;
            mac_02_D_8024E570[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 mac_02_D_8024E738[];
extern s32 mac_02_D_8024E8A8[];

ApiStatus func_80242BA8_825E68(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_02_D_8024E738[i] = ptr[i];
        }
        mac_02_D_8024E738[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            mac_02_D_8024E738[i] = i + 128;
            mac_02_D_8024E738[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

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
    s32 i;

    for (i = 0; i < 91; i++) {
        mac_02_D_8024E8A8[i] = i + 128;
    }
    mac_02_D_8024E8A8[i] = 0;

    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"
