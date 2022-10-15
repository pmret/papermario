#include "nok_13.h"

#include "world/common/util/MonitorPlayerOrbiting.inc.c"

ApiStatus func_80241360_A01960(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;

    evt_set_variable(script, a0, atan2(-364.0f, -135.0f, gPlayerStatus.position.x, gPlayerStatus.position.z));
    return ApiStatus_DONE2;
}

extern EvtScript D_80242134_A02734;

void N(musical_hill_orbit_listener)(PlayerOrbitState* orbit, s32 event) {
    Evt* script;

    switch (event) {
        case PLAYER_ORBIT_BEGIN:
            script = start_script(&D_80242134_A02734, EVT_PRIORITY_1, 0);
            script->varTable[0] = 0x84;
            break;
        case PLAYER_ORBIT_COMPLETE_ROTATION:
            make_item_entity_nodelay(ITEM_HEART, orbit->pos.x, orbit->pos.y, orbit->pos.z,
                ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0);
            break;
        case PLAYER_ORBIT_CHANGE_DIRECTION:
        case PLAYER_ORBIT_LEFT_REGION:
            script = start_script(&D_80242134_A02734, EVT_PRIORITY_1, 0);
            script->varTable[0] = 0x11;
            break;
    }

    return;
}
