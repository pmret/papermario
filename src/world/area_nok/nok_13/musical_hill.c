#include "nok_13.h"

#include "world/common/util/MonitorPlayerOrbiting.inc.c"

API_CALLABLE(N(GetAngleToPlayer)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, atan2(-364.0f, -135.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_RotateHillTowardPlayer) = {
    Label(0)
        Call(N(GetAngleToPlayer), LVar0)
        Add(LVar0, 180)
        Call(RotateModel, MODEL_o363, LVar0, 0, -1, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PlaySong) = {
    Call(SetMusic, 0, LVar0, 0, VOL_LEVEL_FULL)
    Return
    End
};

void N(musical_hill_orbit_listener)(PlayerOrbitState* orbit, s32 event) {
    Evt* script;

    switch (event) {
        case PLAYER_ORBIT_BEGIN:
            script = start_script(&N(EVS_PlaySong), EVT_PRIORITY_1, 0);
            script->varTable[0] = SONG_CANDY_CANES;
            break;
        case PLAYER_ORBIT_COMPLETE_ROTATION:
            make_item_entity_nodelay(ITEM_HEART, orbit->pos.x, orbit->pos.y, orbit->pos.z,
                ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0);
            break;
        case PLAYER_ORBIT_CHANGE_DIRECTION:
        case PLAYER_ORBIT_LEFT_REGION:
            script = start_script(&N(EVS_PlaySong), EVT_PRIORITY_1, 0);
            script->varTable[0] = SONG_PLEASANT_PATH;
            break;
    }

    return;
}

PlayerOrbitTarget N(RunAroundTarget) = {
    .pos = { -364, 190, -135 },
    .startRadius = 50,
    .orbitRadius = 100,
    .eventListener = N(musical_hill_orbit_listener),
};

EvtScript N(EVS_SetupMusicalHill) = {
    Exec(N(EVS_RotateHillTowardPlayer))
    Call(N(MonitorPlayerOrbiting), Ref(N(RunAroundTarget)))
    Return
    End
};
