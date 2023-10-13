#include "kmr_03.h"
#include "sprite/player.h"

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/todo/CheckPartnerFlags1000.inc.c"

API_CALLABLE(N(func_802401B0_8C8140)) {
    Npc* npc = get_npc_unsafe(NPC_Goompa);

    script->varTable[1] = get_xz_dist_to_player(npc->pos.x, npc->pos.z) / npc->moveSpeed * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/util/CheckPositionRelativeToPlane.inc.c"

NpcSettings N(NpcSettings_Goompa) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

EvtScript N(EVS_NpcAux_Goompa) = {
    EVT_LABEL(1)
    EVT_IF_EQ(AF_KMR_08, TRUE)
        EVT_LABEL(100)
        EVT_CALL(AwaitPlayerLeave, 294, 123, 170)
        EVT_CALL(EnableNpcAI, NPC_Goompa, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SetNpcSpeed, NPC_Goompa, EVT_FLOAT(4.0))
        EVT_CALL(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Run)
        EVT_CALL(N(func_802401B0_8C8140))
        EVT_CALL(GetAngleToPlayer, NPC_Goompa, LVar2)
        EVT_LOOP(LVar1)
            EVT_CALL(GetNpcPos, NPC_Goompa, LVar7, LVar8, LVar9)
            EVT_CALL(AddVectorPolar, LVar7, LVar9, EVT_FLOAT(4.0), LVar2)
            EVT_CALL(SetNpcPos, NPC_Goompa, LVar7, LVar8, LVar9)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlayerFaceNpc, NPC_Goompa, 3)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 243, 243, 0)
        EVT_CALL(SetNpcVar, NPC_Goompa, 0, 1)
        EVT_CALL(EnableNpcAI, NPC_Goompa, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Goompa) = {
    EVT_LABEL(1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH0_FELL_OFF_CLIFF)
            EVT_LABEL(89)
            EVT_CALL(N(CheckPositionRelativeToPlane), -118, 86, -70, -15)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(89)
            EVT_END_IF
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcAux, NPC_Goompa, 0)
            EVT_CALL(PlaySoundAtNpc, NPC_Goompa, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
            EVT_CALL(ShowEmote, NPC_Goompa, EMOTE_EXCLAMATION, 45, 15, EMOTER_NPC, 0, 0, 0, 0)
            EVT_WAIT(15 * DT)
            EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
            EVT_WAIT(10 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A6)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -220, 20, -72)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -20, 0, 68)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_THREAD
                EVT_WAIT(20 * DT)
                EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
                EVT_CALL(PlayerMoveTo, -38, 68, 0)
            EVT_END_THREAD
            EVT_CALL(GetNpcPos, NPC_Goompa, LVar7, LVar8, LVar9)
            EVT_CALL(SetNpcSpeed, NPC_Goompa, EVT_FLOAT(4.0 / DT))
            EVT_CALL(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Run)
            EVT_CALL(NpcMoveTo, NPC_Goompa, 0, 70, 0)
            EVT_CALL(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Idle)
            EVT_CALL(InterpNpcYaw, NPC_Goompa, 276, 20 * DT)
            EVT_WAIT(30 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A7)
            EVT_WAIT(5 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(30 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A8)
            EVT_CALL(N(ChangeNpcToPartner), 0, 5)
            EVT_SET(GB_StoryProgress, STORY_CH0_GOOMPA_JOINED_PARTY)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -220, 20, -72)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Goompa) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Injured)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Idle)
    EVT_ADD(MV_Unk_00, 1)
    EVT_IF_LT(MV_Unk_00, 3)
        EVT_CALL(GetOwnerEncounterTrigger, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
                EVT_CALL(SetNpcVar, NPC_Goompa, 0, 1)
                EVT_IF_EQ(AF_KMR_06, TRUE)
                EVT_ELSE
                    EVT_SET(AF_KMR_06, TRUE)
                    EVT_SET(AF_KMR_07, FALSE)
                EVT_END_IF
            EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
                EVT_CALL(SetNpcVar, NPC_Goompa, 0, 1)
                EVT_IF_EQ(AF_KMR_07, TRUE)
                EVT_ELSE
                    EVT_SET(AF_KMR_06, FALSE)
                    EVT_SET(AF_KMR_07, TRUE)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Run)
    EVT_ELSE
        EVT_WAIT(10)
        EVT_CALL(GetNpcPos, NPC_Goompa, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcPos, NPC_Goompa, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Goompa)))
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Goompa)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goompa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Goompa)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Goompa)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Goompa)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_GE(STORY_CH0_GOOMPA_JOINED_PARTY)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_GoombaFamily) = {
    .id = NPC_Goompa,
    .pos = { -50.0f, 0.0f, 80.0f },
    .yaw = 45,
    .init = &N(EVS_NpcInit_Goompa),
    .settings = &N(NpcSettings_Goompa),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Goompa_Idle,
        .walk   = ANIM_Goompa_Walk,
        .run    = ANIM_Goompa_Run,
        .chase  = ANIM_Goompa_Run,
        .anim_4 = ANIM_Goompa_Idle,
        .anim_5 = ANIM_Goompa_Idle,
        .death  = ANIM_Goompa_Still,
        .hit    = ANIM_Goompa_Still,
        .anim_8 = ANIM_Goompa_Run,
        .anim_9 = ANIM_Goompa_Run,
        .anim_A = ANIM_Goompa_Run,
        .anim_B = ANIM_Goompa_Run,
        .anim_C = ANIM_Goompa_Run,
        .anim_D = ANIM_Goompa_Run,
        .anim_E = ANIM_Goompa_Run,
        .anim_F = ANIM_Goompa_Run,
    },
    .tattle = MSG_NpcTattle_Goompa,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GoombaFamily), BTL_KMR_1_FORMATION_02),
    {}
};
