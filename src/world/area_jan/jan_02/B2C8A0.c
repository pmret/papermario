#include "jan_02.h"

#define CHUCK_QUIZMO_NPC_ID 5

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_802414EC_B2D95C);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 D_80248760_jan_02[];

ApiStatus func_80241578_B2D9E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80248760_jan_02[i] = ptr[i];
        }
        D_80248760_jan_02[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80248760_jan_02[i] = i + 16;
            D_80248760_jan_02[112] = 0;
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

#include "world/common/todo/SwitchToPartner.inc.c"
