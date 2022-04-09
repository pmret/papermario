#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(Quizmo_UnkB)(Evt* script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(Quizmo_StageEffect) = fx_quizmo_stage(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)));
        N(Quizmo_Audienceffect) = fx_quizmo_audience(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)));
        N(Quizmo_VannaTEffect) = fx_quizmo_assistant(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)), 1.0f, 0);

        effectPtr = N(Quizmo_StageEffect)->data;
        effectPtr->unk_18 = 0;
        effectPtr->unk_20 = 0;
        effectPtr->unk_24.s = 0;
        effectPtr->unk_28 = 0;
        effectPtr->unk_1C = 0;
    }

    effectPtr = N(Quizmo_StageEffect)->data;

    effectPtr->unk_20 += 10;
    effectPtr->unk_28 += 10;
    effectPtr->unk_24.s += 10;
    effectPtr->unk_18 += 10;
    effectPtr->unk_1C += 10;
    if (effectPtr->unk_18 >= 255) {
        effectPtr->unk_18 = 255;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
