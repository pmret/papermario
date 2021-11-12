#include "common.h"

#define NAMESPACE b_area_trd_part_2

#define NAMESPACE dup2_b_area_trd_part_2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_trd_part_2

#define NAMESPACE dup2_b_area_trd_part_2
#include "world/common/UnkFunc27.inc.c"
#define NAMESPACE b_area_trd_part_2

#define NAMESPACE dup2_b_area_trd_part_2
#include "world/common/UnkFunc26.inc.c"
#define NAMESPACE b_area_trd_part_2

ApiStatus func_80218350_4B1540(Evt* script, s32 isInitialCall) {
    bgm_set_battle_song(8, 0);
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

ApiStatus func_8021837C_4B156C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(evt_get_variable(script, *args++));

    play_movement_dust_effects(2, actor->state.goalPos.x - 15.0f, actor->state.goalPos.y, actor->state.goalPos.z, actor->state.angle);
    return ApiStatus_DONE2;
}
