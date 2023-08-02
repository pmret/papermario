#include "hos_00.h"

#include "world/common/npc/Twink.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/enemy/FlyingMagikoopa.h"

NpcSettings N(NpcSettings_FlyingMagikoopa) = {
    .height = 34,
    .radius = 24,
    .level = 26,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_Scene_Wishing) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 305, -10, -50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 305, -10, -50)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(9.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Disappointed, 0, MSG_HOS_006C)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ToadKid, ANIM_ToadKid_Red_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Toadette, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_HOS_006D)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle, 0, MSG_HOS_006E)
    EVT_WAIT(50)
    EVT_CALL(GotoMap, EVT_PTR("osr_01"), osr_01_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_FlyingMagikoopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(GetPlayerPos, LVar3, LVar1, LVar2)
            EVT_CALL(SetPlayerPos, LVar3, LVar1, -45)
            EVT_ADD(LVar3, 40)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar3, LVar1, -45)
            EVT_CALL(GetNpcPos, NPC_Twink, LVar3, LVar1, LVar2)
            EVT_ADD(LVar3, -25)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar3, LVar1, -45)
            EVT_EXEC(N(EVS_Scene_TwinkDeparts))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_FlyingMagikoopa) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FlyingMagikoopa) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_FlyingMagikoopa)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_FlyingMagikoopa)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetCurrentPartner)) {
    gPlayerData.curPartner = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Twink) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnablePartner, PARTNER_TWINK)
    EVT_CALL(N(SetCurrentPartner), PARTNER_TWINK)
    EVT_CALL(StartBattle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Twink) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Twink) = {
    EVT_CALL(SetSelfVar, 0, 2)
    EVT_CALL(DisablePartner, PARTNER_TWINK)
    EVT_CALL(N(SetCurrentPartner), PARTNER_GOOMBARIO)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Twink)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Twink)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Twink)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Twink) = {
    .id = NPC_Twink,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_Twink),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
};

NpcData N(NpcData_FlyingMagikoopa) = {
    .id = NPC_FlyingMagikoopa,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_FlyingMagikoopa),
    .settings = &N(NpcSettings_FlyingMagikoopa),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = FLYING_MAGIKOOPA_ANIMS,
};

NpcData N(NpcData_Wishing)[] = {
    {
        .id = NPC_Toadette,
        .pos = { 280.0f, -10.0f, -50.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
    },
    {
        .id = NPC_ToadKid,
        .pos = { 330.0f, -10.0f, -40.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE,
        .drops = NO_DROPS,
        .animations = TOAD_KID_RED_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Twink), BTL_HOS_FORMATION_00),
    NPC_GROUP(N(NpcData_FlyingMagikoopa), BTL_HOS_FORMATION_03),
    {}
};

NpcGroupList N(WishingNPCs) = {
    NPC_GROUP(N(NpcData_Wishing)),
    {}
};
