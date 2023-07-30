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
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFaceNpc, NPC_Dryite_03, NPC_Dryite_04, 1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(N(GetRunToPos))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.5))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_WAIT(5)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_04) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(dro_01_ENTRY_3)
        EVT_CASE_OR_EQ(dro_01_ENTRY_4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_04)))
    EVT_RETURN
    EVT_END
};
