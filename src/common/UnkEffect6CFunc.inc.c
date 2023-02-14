#include "battle/battle.h"
#include "effects.h"

API_CALLABLE(N(UnkEffect6CFunc)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, (s32) fx_tattle_window(0, 106.0f, 144.0f, 0, 1.0f, 0));
    return ApiStatus_DONE2;
}
