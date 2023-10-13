#include "jan_04.h"
#include "sprite/player.h"

#include "world/common/npc/Sushie.inc.c"
#include "world/common/npc/Bubulb.inc.c"
#include "world/common/npc/YoshiKid.inc.c"

EvtScript N(EVS_ShakeTree_Sushie) = {
    EVT_CALL(GetNpcVar, NPC_Sushie, 0, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_JAN_08, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(AF_JAN_08, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Sushie, NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_IF_EQ(GF_JAN04_SushieTreeHitCounterB, FALSE)
        EVT_IF_EQ(GF_JAN04_SushieTreeHitCounterA, FALSE)
            EVT_CALL(SetNpcJumpscale, NPC_Sushie, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAtNpc, NPC_Sushie, SOUND_SUSHIE_FLOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Sushie, 90, 140, -85, 20 * DT)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 90, 140, -85)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 90, 140, -85)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 280)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, 16, EVT_FLOAT(-6.0))
#if VERSION_PAL
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(SpeakToPlayer, NPC_Sushie, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A1)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_SET(GF_JAN04_SushieTreeHitCounterA, TRUE)
            EVT_WAIT(10 * DT)
            EVT_SET(AF_JAN_08, FALSE)
        EVT_ELSE
            EVT_CALL(SetNpcJumpscale, NPC_Sushie, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAtNpc, NPC_Sushie, SOUND_SUSHIE_FLOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Sushie, -10, 112, -80, 15 * DT)
            EVT_SET(GF_JAN04_SushieTreeHitCounterA, FALSE)
            EVT_SET(GF_JAN04_SushieTreeHitCounterB, TRUE)
            EVT_WAIT(10 * DT)
            EVT_SET(AF_JAN_08, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetNpcJumpscale, NPC_Sushie, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Sushie, SOUND_SUSHIE_FLOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Sushie, 50, 0, 0, 20 * DT)
        EVT_SET(GF_JAN04_SushieTreeHitCounterA, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_Sushie, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Sushie, ANIM_WorldSushie_Hurt)
        EVT_CALL(SetNpcVar, NPC_Sushie, 0, 10)
        EVT_UNBIND
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_Sushie, NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Sushie_ScoldPlayerLeaving) = {
    EVT_LABEL(1)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(AwaitPlayerLeave, 0, 0, 170)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(SetSelfVar, 0, 2)
                EVT_SET(LVar0, GF_JAN04_SushieTreeHitCounterA)
                EVT_SET(LVar1, GF_JAN04_SushieTreeHitCounterB)
                EVT_ADD(LVar0, LVar1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00A2, 160, 40)
                EVT_ELSE
                    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00A3, 160, 40)
                EVT_END_IF
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(SetSelfVar, 0, 1)
            EVT_CASE_EQ(1)
                EVT_CALL(AwaitPlayerApproach, 0, 0, 130)
                EVT_CALL(SetSelfVar, 0, 0)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Sushie_ShoutAtChildren) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_009E, 320, 60)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(AwaitPlayerApproach, 0, 0, 130)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_009F, 160, 40)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LookAround)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 30, 140, -60)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 16, EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Hurt, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A0)
#if VERSION_PAL
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(ResetCam, CAM_DEFAULT, 3)
#endif
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_SushieTree) = {
    .pos = { 30.0f, 0.0f, -110.0f },
    .radius = 0.0f
};

#include "world/common/util/ChangeNpcToPartner.inc.c"

EvtScript N(EVS_NpcIdle_Sushie) = {
    EVT_SET(LVar0, GF_JAN04_SushieTreeHitCounterA)
    EVT_SET(LVar1, GF_JAN04_SushieTreeHitCounterB)
    EVT_ADD(LVar0, LVar1)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(EVS_Sushie_ShoutAtChildren))
    EVT_ELSE
        EVT_CALL(SetSelfVar, 0, 1)
    EVT_END_IF
    EVT_SET(AF_JAN_08, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Sushie)), TRIGGER_WALL_HAMMER, COLLIDER_o34, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Sushie)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_SushieTree)), 1, 0)
    EVT_EXEC_GET_TID(N(EVS_Sushie_ScoldPlayerLeaving), LVar9)
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 10)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PlayerMoveTo, 10, 0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Idle)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT), 20, 301, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A4)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Sad)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Idle)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A6)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_00A7)
    EVT_CALL(CloseMessage)
    EVT_CALL(N(ChangeNpcToPartner), NPC_Sushie, PARTNER_SUSHIE)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(EVS_PushNewPartnerSong))
    EVT_WAIT(15 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018F, 160, 40)
    EVT_EXEC(N(EVS_PopSong))
    EVT_WAIT(10 * DT)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_SET(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sushie) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_04_ENTRY_3)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Sad)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
        EVT_IF_EQ(GF_JAN04_SushieTreeHitCounterB, FALSE)
            EVT_IF_EQ(GF_JAN04_SushieTreeHitCounterA, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, 55, 150, -95)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, 90, 140, -85)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(GF_JAN04_SushieTreeHitCounterA, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, -10, 112, -80)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, 50, 0, 0)
                EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Sushie)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_RAPHAEL_LEFT_NEST)
            EVT_IF_EQ(GF_JAN04_Met_Bubulb, FALSE)
                EVT_WAIT(30)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Yellow_PopUp)
                EVT_WAIT(10)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
                EVT_WAIT(35)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Yellow_Idle)
                EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 26)
                EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00A8)
                EVT_SET(GF_JAN04_Met_Bubulb, TRUE)
                EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_JAN_Bubulb_Revealed)
                EVT_RETURN
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00A9)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_TRADED_VASE_FOR_SEED)
            EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00AA)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00AB)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH5_00AC)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
        EVT_IF_EQ(GF_JAN04_Met_Bubulb, FALSE)
            EVT_CALL(SetNpcCollisionSize, NPC_SELF, 25, 25)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Yellow_BuriedIdle)
            EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Hidden)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Sushie,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Sushie),
        .settings = &N(NpcSettings_Sushie),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = SUSHIE_ANIMS,
    },
    {
        .id = NPC_Bubulb,
        .pos = { -230.0f, 0.0f, -320.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bubulb),
        .settings = &N(NpcSettings_Bubulb),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = BUBULB_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_JAN_Bubulb_Revealed,
    },
};

NpcData N(NpcData_YoshiKids)[] = {
    {
        .id = NPC_YoshiKid_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreenYoshiKid,
    },
    {
        .id = NPC_YoshiKid_02,
        .pos = { 45.0f, 0.0f, -70.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_RedYoshiKid,
    },
    {
        .id = NPC_YoshiKid_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_BlueYoshiKid,
    },
    {
        .id = NPC_YoshiKid_04,
        .pos = { 20.0f, 0.0f, -70.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_YellowYoshiKid,
    },
    {
        .id = NPC_YoshiKid_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_YoshiKid),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_PurpleYoshiKid,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    NPC_GROUP(N(NpcData_YoshiKids)),
    {}
};
