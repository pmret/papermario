#include "obk_02.h"

#include "world/common/npc/Boo.inc.c"

enum {
    TRAFFIC_BOO_INIT    = 0,
    TRAFFIC_BOO_WAIT    = 1,
    TRAFFIC_BOO_MOVE    = 2,
};

s16 N(TrafficBooAlphas)[] = {
    50, 60, 200, 240
};

API_CALLABLE(N(TrafficBooInit)) {
    script->functionTemp[1] = TRAFFIC_BOO_INIT;
    return ApiStatus_DONE2;
}

ApiStatus N(UpdateTrafficBooMotion)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    switch (script->functionTemp[1]) {
        case TRAFFIC_BOO_INIT:
            // choose random wait time
            npc->duration = rand_int(180) + 30;
            // choose random position offset
            npc->pos.z = -300.0f;
            npc->pos.y = rand_int(50) + 80.0f;
            // choose random speed
            npc->moveSpeed = (2.0f * rand_float()) + 2.0f;
            // chose random direction
            if (rand_int(100) < 50) {
                npc->pos.x = 270.0f;
                npc->yaw = 270.0f;
            } else {
                npc->pos.x = -270.0f;
                npc->yaw = 90.0f;
            }
            // wait before moving
            script->functionTemp[1] = TRAFFIC_BOO_WAIT;
            break;
        case TRAFFIC_BOO_WAIT:
            npc->duration--;
            if (npc->duration == 0) {
                // begin moving
                script->functionTemp[1] = TRAFFIC_BOO_MOVE;
            }
            break;
        case TRAFFIC_BOO_MOVE:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->pos.x < -280.0f || npc->pos.x > 280.0f) {
                script->functionTemp[1] = TRAFFIC_BOO_INIT;
            }
            break;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateTrafficBooAlpha)) {
    s32 alpha = script->varTable[0];
    s32 nextChangeTime = script->varTable[1];
    s32 targetAlpha;

    if (nextChangeTime == 0) {
        // choose a new target alpha and schedule a time for the next update
        script->functionTemp[2] = N(TrafficBooAlphas)[rand_int(ARRAY_COUNT(N(TrafficBooAlphas)) - 1)];
        nextChangeTime = rand_int(50) + 30;
    }
    nextChangeTime--;

    targetAlpha = script->functionTemp[2];
    if (alpha < targetAlpha) {
        alpha += 10;
        if (targetAlpha < alpha) {
            alpha = targetAlpha;
        }
    }
    if (targetAlpha < alpha) {
        alpha -= 10;
        if (alpha < targetAlpha) {
            alpha = targetAlpha;
        }
    }

    script->varTable[0] = alpha;
    script->varTable[1] = nextChangeTime;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_TrafficBoo) = {
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_CALL(N(TrafficBooInit))
    EVT_LOOP(0)
        EVT_CALL(N(UpdateTrafficBooMotion))
        EVT_CALL(N(UpdateTrafficBooAlpha))
        EVT_CALL(func_802CFD30, -1, 7, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcRenderMode, NPC_SELF, RENDER_MODE_SURFACE_XLU_LAYER1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrafficBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrafficBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Boos)[] = {
    {
        .id = NPC_Boo_01,
        .settings = &N(NpcSettings_Boo),
        .pos = { 523.0f, -139.0f, 193.0f },
        .yaw = 0,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_TrafficBoo1),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_02,
        .settings = &N(NpcSettings_Boo),
        .pos = { 473.0f, -122.0f, 247.0f },
        .yaw = 0,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_TrafficBoo2),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Boos)),
    {}
};
