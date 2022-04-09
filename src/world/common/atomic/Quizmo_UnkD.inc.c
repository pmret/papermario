#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(Quizmo_UnkD)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_StageEffect)->data)->unk_34 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
