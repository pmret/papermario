#include "nok_13.h"

#include "world/common/util/MonitorPlayerOrbiting.inc.c"

API_CALLABLE(N(GetAngleToPlayer)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, atan2(-364.0f, -135.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_RotateHillTowardPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(N(GetAngleToPlayer), LVar0)
        EVT_ADD(LVar0, 180)
        EVT_CALL(RotateModel, MODEL_o363, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlaySong) = {
    EVT_CALL(SetMusicTrack, 0, LVar0, 0, 8)
    EVT_RETURN
    EVT_END
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
    EVT_EXEC(N(EVS_RotateHillTowardPlayer))
    EVT_CALL(N(MonitorPlayerOrbiting), EVT_PTR(N(RunAroundTarget)))
    EVT_RETURN
    EVT_END
};
