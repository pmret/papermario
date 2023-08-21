#include "sam_03.h"

#include "world/common/npc/JrTroopa.inc.c"

API_CALLABLE(N(GetAngleToPlayer)) {
    Npc* npc = get_npc_unsafe(NPC_JrTroopa);

    script->varTable[0] = atan2(npc->pos.x, npc->pos.z, gPlayerStatus.pos.x, gPlayerStatus.pos.z);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_JR_TROOPA)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(11)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 400)
            EVT_GOTO(11)
        EVT_END_IF
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    EVT_CALL(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH7_00D8)
    EVT_CALL(SetNpcJumpscale, NPC_JrTroopa, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_JrTroopa, 520, 0, -68, 20 * DT)
    EVT_CALL(PlayerFaceNpc, NPC_JrTroopa, FALSE)
    EVT_WAIT(15 * DT)
    EVT_CALL(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(225.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_Idle, 0, MSG_CH7_00D9)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH7_00DA)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_JrTroopa, LVar3, LVar4, LVar5)
    EVT_CALL(GetDist2D, LVar6, LVar0, LVar2, LVar3, LVar5)
    EVT_MULF(LVar6, EVT_FLOAT(0.7))
    EVT_CALL(N(GetAngleToPlayer))
    EVT_CALL(AddVectorPolar, LVar3, LVar5, LVar6, LVar0)
    EVT_CALL(SetNpcSpeed, NPC_JrTroopa, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Charge)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_JrTroopa, LVar3, LVar5, 0)
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_JrTroopa) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH7_00DF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_JrTroopaHitbox) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Hurt, ANIM_JrTroopa_Collapse, 5, MSG_CH7_00DF)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_JrTroopa) = {
    EVT_CALL(ClearDefeatedEnemies)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_JR_TROOPA)
            EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Defeated)
            EVT_CALL(SetNpcAnimation, NPC_JrTroopa_Hitbox, ANIM_JrTroopa_Defeated)
            EVT_CALL(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_THREAD
                EVT_WAIT(5 * DT)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH7_00DF)
            EVT_CALL(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_JrTroopa_Hitbox, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcCollisionSize, NPC_JrTroopa, 26, 24)
            EVT_CALL(SetNpcCollisionSize, NPC_JrTroopa_Hitbox, 26, 24)
            EVT_CALL(SetNpcFlagBits, NPC_JrTroopa_Hitbox, NPC_FLAG_INVISIBLE, TRUE)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_JrTroopa)))
            EVT_CALL(BindNpcHit, NPC_JrTroopa_Hitbox, EVT_PTR(N(EVS_NpcHit_JrTroopaHitbox)))
            EVT_EXEC(N(EVS_SetupMusic))
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_JrTroopa)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_DEFEATED_JR_TROOPA)
            EVT_CALL(SetNpcPos, NPC_JrTroopa, 600, 0, -65)
        EVT_CASE_GE(STORY_CH7_DEFEATED_JR_TROOPA)
            EVT_CALL(SetNpcPos, NPC_JrTroopa, 399, 6, -100)
            EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Collapse)
            EVT_CALL(EnableModel, MODEL_o44, TRUE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o44, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopaHitbox) = {
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

// first Jr Troopa is for interacting with player, the second is 'hostile' and can respond to being hit
NpcData N(NpcData_JrTroopa)[] = {
    {
        .id = NPC_JrTroopa,
        .pos = { 261.0f, 0.0f, -76.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_JrTroopa),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
    {
        .id = NPC_JrTroopa_Hitbox,
        .pos = { 261.0f, 0.0f, -76.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_JrTroopaHitbox),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa), BTL_KMR_3_FORMATION_06),
    {}
};
