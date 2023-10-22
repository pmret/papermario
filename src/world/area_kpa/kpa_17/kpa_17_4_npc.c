#include "kpa_17.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_Scene_FallIntoCell) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 1042, 30, -496)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 1042, 30, -496)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(60)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_ELSE
        EVT_CALL(func_802CF56C, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtPlayer, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_SUB(LVar1, 16)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LE(LVar1, 30)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_CALL(PlaySoundAtPlayer, SOUND_PLAYER_COLLAPSE, SOUND_SPACE_DEFAULT)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump1, 1030, 30, -496, 10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT(1)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(5)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(1)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_0007, 1000, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(func_802CF56C, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlastWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 8, 8, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_g296, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_KPA17_BombedWall, TRUE)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(80 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH8_0016)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_SWITCH(GF_KPA17_BombedWall)
        EVT_CASE_EQ(0)
            EVT_SWITCH(AB_KPA17_Toad1_Dialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH8_0009)
                    EVT_SET(AB_KPA17_Toad1_Dialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH8_000A)
                    EVT_SET(AB_KPA17_Toad1_Dialogue, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH8_000B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_SWITCH(GF_KPA17_BombedWall)
        EVT_CASE_EQ(0)
            EVT_SWITCH(AB_KPA17_Toad2_Dialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_000C)
                    EVT_SET(AB_KPA17_Toad2_Dialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_000D)
                    EVT_SET(AB_KPA17_Toad2_Dialogue, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_000E)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard) = {
    EVT_SWITCH(GF_KPA17_BombedWall)
        EVT_CASE_EQ(0)
            EVT_SWITCH(AB_KPA17_Toad3_Dialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_000F)
                    EVT_SET(AB_KPA17_Toad3_Dialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_0010)
                    EVT_SET(AB_KPA17_Toad3_Dialogue, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_0011)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadMinister) = {
    EVT_SWITCH(GF_KPA17_BombedWall)
        EVT_CASE_EQ(0)
            EVT_SWITCH(AB_KPA17_Toad4_Dialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0012)
                    EVT_SET(AB_KPA17_Toad4_Dialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0013)
                    EVT_SET(AB_KPA17_Toad4_Dialogue, 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0014)
                    EVT_SET(AB_KPA17_Toad4_Dialogue, 1)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_CH8_0015)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_CALL(SetNpcPos, NPC_SELF, 813, 30, -394)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_CALL(SetNpcPos, NPC_SELF, 870, 30, -465)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard)))
    EVT_CALL(SetNpcPos, NPC_SELF, 930, 30, -400)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadMinister) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadMinister)))
    EVT_CALL(SetNpcPos, NPC_SELF, 1100, 30, -450)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadA,
    },
    {
        .id = NPC_Toad_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadB,
    },
    {
        .id = NPC_ToadGuard,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ToadGuard),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierA,
    },
    {
        .id = NPC_ToadMinister,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ToadMinister),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_MINISTER_ANIMS,
        .tattle = MSG_NpcTattle_KPA_ToadMinister,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Prisoners)),
    {}
};
