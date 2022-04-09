#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(Quizmo_UnkF)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_VannaTEffect)->data)->unk_1C = 0;
    return ApiStatus_DONE2;
}
