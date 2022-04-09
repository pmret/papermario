#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(Quizmo_UnkC)(Evt* script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(Quizmo_Audienceffect)->flags |= 0x10;
        N(Quizmo_VannaTEffect)->flags |= 0x10;
    }

    effectPtr = N(Quizmo_StageEffect)->data;
    effectPtr->unk_18 -= 10;
    effectPtr->unk_20 -= 10;
    effectPtr->unk_24.s -= 10;
    effectPtr->unk_28 -= 10;
    effectPtr->unk_1C -= 10;

    if (effectPtr->unk_18 <= 0) {
        effectPtr->unk_18 = 0;
        remove_effect(N(Quizmo_StageEffect));
        free_generic_entity(N(Quizmo_Worker));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
