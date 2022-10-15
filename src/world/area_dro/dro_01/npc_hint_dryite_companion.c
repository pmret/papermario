#include "dro_01.h"

API_CALLABLE(N(GetRunToPos)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);
    s32 rand;
    f32 temp_f22;
    f32 temp_f24;

    temp_f24 = atan2(183.0f, -75.0f, playerStatus->position.x, playerStatus->position.z);
    temp_f22 = atan2(183.0f, -75.0f, npc->pos.x, npc->pos.z);
    temp_f24 = get_clamped_angle_diff(temp_f22, temp_f24);
    rand = rand_int(10) + 30;
    if (temp_f24 < 0.0f) {
        temp_f22 += rand;
    } else {
        temp_f22 -= rand;
    }
    rand = rand_int(20) + 30;
    script->varTable[0] = 183.0f + (sin_deg(temp_f22) * rand);
    script->varTable[1] = -75.0f - (cos_deg(temp_f22) * rand);

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
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.5))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
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
