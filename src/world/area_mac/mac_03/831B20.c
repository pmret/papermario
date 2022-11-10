#include "mac_03.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 23

#include "common/CosInterpMinMax.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241770_832F70);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 mac_03_D_80251400[];

ApiStatus func_802417FC_832FFC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_03_D_80251400[i] = ptr[i];
        }
        mac_03_D_80251400[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_03_D_80251400[i] = i + 16;
            mac_03_D_80251400[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

ApiStatus func_80241B84_833384(Evt* script, s32 isInitialCall) {
    s32 gb29 = evt_get_variable(script, GameByte(29));

    if (gb29 == 0) {
        script->varTable[0] = -1;
    } else {
        script->varTable[0] = evt_get_variable(script, gb29 + GameByte(29));
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241BD8_8333D8);
