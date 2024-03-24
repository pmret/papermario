#include "machi.h"

API_CALLABLE(N(MisstarFlyAway)) {
    Npc* npc = get_npc_unsafe(NPC_Misstar);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            npc->moveToPos.x = npc->pos.x + 500.0f;
            npc->moveToPos.y = npc->pos.y + 120.0f;
            npc->moveToPos.z = npc->pos.z - 500.0f;
            npc->duration = 20;
            npc->moveToPos.x = (npc->moveToPos.x - npc->pos.x) / npc->duration;
            npc->moveToPos.y = (npc->moveToPos.y - npc->pos.y) / npc->duration;
            npc->moveToPos.z = (npc->moveToPos.z - npc->pos.z) / npc->duration;
            npc->duration = 100;
            npc->moveToPos.x /= 10.0f;
            npc->moveToPos.y /= 10.0f;
            npc->moveToPos.z /= 10.0f;
            enable_npc_blur(npc);
            script->functionTemp[0] = 1;
            break;
        case 1:
            npc->pos.x += npc->moveToPos.x;
            npc->pos.y += npc->moveToPos.y;
            npc->pos.z += npc->moveToPos.z;
            npc->moveToPos.x = npc->moveToPos.x * 1.05;
            npc->moveToPos.y = npc->moveToPos.y * 1.05;
            npc->moveToPos.z = npc->moveToPos.z * 1.05;
            npc->duration--;
            if (npc->duration == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAuxAI_Misstar) = {
    Return
    End
};

EvtScript N(EVS_NpcAux_Misstar) = {
    Label(0)
        SetF(LVar0, Float(40.0))
        Loop(20)
            AddF(LVar0, Float(4.0))
            Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
        EndLoop
        Loop(20)
            AddF(LVar0, Float(-4.0))
            Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Misstar_Bobbing) = {
    Label(0)
        Loop(10)
            Loop(10)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Sub(LVar1, 1)
                Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            Loop(10)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 1)
                Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcAI_Misstar) = {
    ExecGetTID(N(EVS_Misstar_Bobbing), LVarA)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(AwaitPlayerApproach, LVar0, LVar2, 60)
    Call(N(MisstarFlyAway))
    KillThread(LVarA)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

NpcSettings N(NpcSettings_Misstar) = {
    .defaultAnim = ANIM_WorldMisstar_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Misstar),
    .ai = &N(EVS_NpcAI_Misstar),
    .aux = &N(EVS_NpcAux_Misstar),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { 320.0f, 30.0f, -290.0f },
    .yaw = 100,
    .settings = &N(NpcSettings_Misstar),
    .flags = ENEMY_FLAG_PASSIVE,
    .animations = {},
};
