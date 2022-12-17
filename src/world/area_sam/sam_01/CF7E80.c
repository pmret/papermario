#include "sam_01.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 14

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024053C_CF80AC);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 D_8024DBC0[114];
BSS s32 D_8024DD88[92];

ApiStatus func_802405C8_CF8138(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024DBC0[i] = ptr[i];
        }
        D_8024DBC0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_8024DBC0[i] = i + 16;
            D_8024DBC0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240664_CF81D4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024DD88[i] = ptr[i];
        }
        D_8024DD88[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_8024DD88[i] = i + 128;
            D_8024DD88[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

#include "common/GetItemEntityPosition.inc.c"

#include "world/common/todo/GetLeftRightPoints.inc.c"

#define NAMESPACE dup_sam_01
#include "world/common/todo/StashVars.inc.c"
#define NAMESPACE sam_01

#define NAMESPACE dup_sam_01
#include "world/common/todo/GetItemName.inc.c"
#define NAMESPACE sam_01

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"
