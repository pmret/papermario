#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(Quizmo_UnkH)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_VannaTEffect)->data)->unk_1C = 2;
    return ApiStatus_DONE2;
}
