#include "dro_01.h"

API_CALLABLE(N(GetRunToPos)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);
    s32 rand;
    f32 npcAngle;
    f32 angle;

    angle = atan2(183.0f, -75.0f, playerStatus->pos.x, playerStatus->pos.z);
    npcAngle = atan2(183.0f, -75.0f, npc->pos.x, npc->pos.z);
    angle = get_clamped_angle_diff(npcAngle, angle);
    rand = rand_int(10) + 30;
    if (angle < 0.0f) {
        npcAngle += rand;
    } else {
        npcAngle -= rand;
    }
    rand = rand_int(20) + 30;
    script->varTable[0] = 183.0f + (sin_deg(npcAngle) * rand);
    script->varTable[1] = -75.0f - (cos_deg(npcAngle) * rand);

    return ApiStatus_DONE2;
}

// run away from, the player, orbiting around the hint-giving dryite
EvtScript N(EVS_NpcInteract_Dryite_04) = {
    ChildThread
        Loop(0)
            Call(NpcFaceNpc, NPC_Dryite_03, NPC_Dryite_04, 1)
        EndLoop
    EndChildThread
    Call(N(GetRunToPos))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(3.5))
    Call(NpcMoveTo, NPC_SELF, LVar0, LVar1, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Idle)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Wait(5)
    Call(GetNpcYaw, NPC_SELF, LVar0)
    Add(LVar0, 180)
    Call(InterpNpcYaw, NPC_SELF, LVar0, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite_04) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(dro_01_ENTRY_3)
        CaseOrEq(dro_01_ENTRY_4)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            Return
        EndCaseGroup
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite_04)))
    Return
    End
};
