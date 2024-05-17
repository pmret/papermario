
#include "sprite/npc/Buzzar.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"
#include "sprite/player.h"

#define NAMESPACE A(buzzar)

API_CALLABLE(b_area_iwa_buzzar_StartRumbleWithParams) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);

    start_rumble(var0, var1);

    return ApiStatus_DONE2;
}
