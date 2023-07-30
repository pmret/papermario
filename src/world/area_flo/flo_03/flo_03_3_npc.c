#include "flo_03.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Dayzee) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Petunia) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

#include "world/common/complete/GiveReward.inc.c"

Vec3i N(BurrowLocations_Mole_01)[] = {
    { -100, 0, 210 },
    { -160, 0, 285 },
    {  -35, 0, 305 },
};

Vec3i N(BurrowLocations_Mole_02)[] = {
    { -190, 0,  80 },
    { -130, 0,   0 },
    {  -70, 0, -60 },
};

Vec3i N(BurrowLocations_Mole_03)[] = {
    {  75, 0,  -15 },
    {  35, 0, -100 },
    { 130, 0,    0 },
};

Vec3i N(BurrowLocations_Mole_04)[] = {
    { 115, 0,  180 },
    {  85, 0,  290 },
    { 145, 0,  140 },
};

EvtScript N(EVS_Scene_SunReturns) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcYaw, NPC_Petunia, 90)
    EVT_CALL(GetNpcPos, NPC_Petunia, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -27, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Petunia, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_00C8)
    EVT_CALL(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Dance)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_18"), flo_18_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(HideBehindTree)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posZ, yaw, angle;
    f64 dist;

    // get a point 46 units away from the tree on the side opposite the player
    yaw = clamp_angle(atan2(-210.0f, -183.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z) + 180.0f);
    posX = -210.0f;
    posZ = -183.0f;
    add_vec2D_polar(&posX, &posZ, 46.0f, yaw);

    // run or walk to target position, based on the distance from current position
    dist = dist2D(npc->pos.x, npc->pos.z, posX, posZ);
    if (dist > 2.0) {
        f32 curAngle = clamp_angle(atan2(-210.0f, -183.0f, npc->pos.x, npc->pos.z));
        f32 targetAngle = clamp_angle(atan2(-210.0f, -183.0f, posX, posZ));
        f32 deltaAngle = curAngle - targetAngle;
        if (abs(deltaAngle) > 20) {
            angle = deltaAngle;
            if (angle >= 180.0f) {
                angle -= 360.0f;
            }
            if (angle <= -180.0f) {
                angle += 360.0f;
            }
            if (deltaAngle == angle) {
                posX = -210.0f;
                posZ = -183.0f;
                if (deltaAngle >= 0.0f) {
                    yaw = clamp_angle(curAngle - 20.0f);
                } else {
                    yaw = clamp_angle(curAngle + 20.0f);
                }
                add_vec2D_polar(&posX, &posZ, 46.0f, yaw);
            }
        }
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_RUN];
        npc->yaw = atan2(npc->pos.x, npc->pos.z, posX, posZ);
        npc_move_heading(npc, 2.0f, npc->yaw);
    } else if (dist > 0.2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, posX, posZ);
        npc->pos.x = posX;
        npc->pos.z = posZ;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_WALK];
    } else {
        npc->pos.x = posX;
        npc->pos.z = posZ;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAI_Dayzee) = {
    EVT_CALL(N(HideBehindTree))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Dayzee) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_FLO03_Defeated_Dayzee, TRUE)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCamBetween) = {
    EVT_CALL(GetPlayerPos, LVar3, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, LVar4, LVar0, LVar1, LVar2, 300, EVT_FLOAT(20.0), EVT_FLOAT(-9.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Petunia) = {
    EVT_EXEC_WAIT(N(EVS_PushFlowerSong))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_SET(MV_PauseBurrowing, TRUE)
            EVT_SET(LVar4, EVT_FLOAT(3.5 / DT))
            EVT_EXEC_WAIT(N(EVS_FocusCamBetween))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0050)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Petunia_Angry)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
            EVT_WAIT(20 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0051)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim12)
            EVT_CALL(SetNpcYaw, NPC_MontyMole_01, 270)
            EVT_CALL(GetNpcPos, NPC_MontyMole_01, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.0))
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_WAIT(20 * DT)
            EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_BURROW_SURFACE, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim16)
            EVT_WAIT(10 * DT)
            EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_263, SOUND_SPACE_MODE_0)
            EVT_CALL(ShowEmote, NPC_MontyMole_01, EMOTE_QUESTION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
            EVT_CALL(GetNpcPos, NPC_MontyMole_02, LVar0, LVar1, LVar2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0052)
            EVT_CALL(SetNpcYaw, NPC_MontyMole_02, 90)
            EVT_CALL(SetNpcPos, NPC_MontyMole_02, NPC_DISPOSE_LOCATION)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim00)
            EVT_WAIT(20 * DT)
            EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_BURROW_SURFACE, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcPos, NPC_MontyMole_02, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
            EVT_WAIT(20 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0053)
            EVT_CALL(SetNpcYaw, NPC_MontyMole_03, 270)
            EVT_CALL(GetNpcPos, NPC_MontyMole_03, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_WAIT(20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0054)
            EVT_CALL(SetNpcYaw, NPC_MontyMole_04, 270)
            EVT_CALL(GetNpcPos, NPC_MontyMole_04, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim06)
            EVT_WAIT(20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim07)
            EVT_WAIT(20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim08)
            EVT_WAIT(20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0055)
            EVT_CALL(SetNpcPos, NPC_Dayzee, -233, 0, -217)
            EVT_CALL(GetNpcPos, NPC_Dayzee, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(SetNpcAnimation, NPC_Dayzee, ANIM_Dayzee_Anim0D)
            EVT_CALL(PlaySoundAtNpc, NPC_Dayzee, SOUND_262, SOUND_SPACE_MODE_0)
            EVT_CALL(ShowEmote, NPC_Dayzee, EMOTE_EXCLAMATION, 45, 30, EMOTER_NPC, 0, 0, 0, 0)
            EVT_WAIT(15 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0056)
            EVT_SET(LVar4, EVT_FLOAT(90.0))
            EVT_EXEC_WAIT(N(EVS_FocusCamBetween))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0057)
            EVT_CALL(SetEnemyFlagBits, NPC_Dayzee, ENEMY_FLAG_PASSIVE, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_01, ENEMY_FLAG_PASSIVE, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_02, ENEMY_FLAG_PASSIVE, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_03, ENEMY_FLAG_PASSIVE, 0)
            EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_04, ENEMY_FLAG_PASSIVE, 0)
            EVT_CALL(BindNpcAI, NPC_Dayzee, EVT_PTR(N(EVS_NpcAI_Dayzee)))
            EVT_SET(MV_PauseBurrowing, FALSE)
            EVT_SET(MV_NextBurrowTriggerRadius, 60)
            EVT_SET(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
        EVT_CASE_EQ(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_IF_EQ(GF_FLO03_DefeatedAll_MontyMoles, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0, MSG_CH6_0058)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Petunia_Angry)
            EVT_ELSE
                EVT_SET(LVar4, EVT_FLOAT(3.5 / DT))
                EVT_EXEC_WAIT(N(EVS_FocusCamBetween))
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_HappyTalk, ANIM_Petunia_Dance, 0, MSG_CH6_0059)
                EVT_CALL(EndSpeech, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Petunia_GiveItem)
                EVT_WAIT(20 * DT)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Petunia_Idle)
                EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_BEAN)
                EVT_WAIT(20 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005A)
                EVT_CALL(EndSpeech, NPC_SELF, ANIM_Petunia_AngryTalk, ANIM_Petunia_Angry, 0)
                EVT_SET(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005B)
        EVT_CASE_LT(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005C)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AB_FLO_PetuniaDialogue, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005D)
                EVT_SET(AB_FLO_PetuniaDialogue, 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Petunia_Talk, ANIM_Petunia_Idle, 0, MSG_CH6_005E)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(8.0 / DT))
    EVT_EXEC_WAIT(N(EVS_PopSong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Petunia) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Petunia)))
    EVT_IF_EQ(GF_FLO03_DefeatedAll_MontyMoles, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Angry)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Idle)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dayzee) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Dayzee)))
    EVT_CALL(EnableNpcShadow, NPC_Dayzee, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_CALL(SetNpcPos, NPC_Dayzee, NPC_DISPOSE_LOCATION)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_FLO03_Defeated_Dayzee, FALSE)
                EVT_CALL(SetEnemyFlagBits, NPC_Dayzee, ENEMY_FLAG_PASSIVE, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Dayzee)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_Dayzee, NPC_DISPOSE_LOCATION)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMoles) = {
    EVT_SET(MV_PauseBurrowing, FALSE)
    EVT_SET(MV_NextBurrowTime_Mole_01, 0)
    EVT_SET(MV_NextBurrowTime_Mole_02, 0)
    EVT_SET(MV_NextBurrowTime_Mole_03, 0)
    EVT_SET(MV_NextBurrowTime_Mole_04, 0)
    EVT_SET(MV_NextBurrowTriggerRadius, 100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_MontyMole) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            // record defeat
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(NPC_MontyMole_01)
                    EVT_SET(GF_FLO03_Defeated_MontyMoleA, TRUE)
                EVT_CASE_EQ(NPC_MontyMole_02)
                    EVT_SET(GF_FLO03_Defeated_MontyMoleB, TRUE)
                EVT_CASE_EQ(NPC_MontyMole_03)
                    EVT_SET(GF_FLO03_Defeated_MontyMoleC, TRUE)
                EVT_CASE_EQ(NPC_MontyMole_04)
                    EVT_SET(GF_FLO03_Defeated_MontyMoleD, TRUE)
            EVT_END_SWITCH
            // count number of defeated moles
            EVT_SET(LVar0, 0)
            EVT_ADD(LVar0, GF_FLO03_Defeated_MontyMoleA)
            EVT_ADD(LVar0, GF_FLO03_Defeated_MontyMoleB)
            EVT_ADD(LVar0, GF_FLO03_Defeated_MontyMoleC)
            EVT_ADD(LVar0, GF_FLO03_Defeated_MontyMoleD)
            // end the mole-hunting minigame if all 4 are defeated
            EVT_IF_NE(LVar0, 4)
                EVT_CALL(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Angry)
            EVT_ELSE
                EVT_CALL(SetNpcAnimation, NPC_Petunia, ANIM_Petunia_Idle)
                EVT_SET(GF_FLO03_DefeatedAll_MontyMoles, TRUE)
                EVT_EXEC_WAIT(N(EVS_SetupMusic))
            EVT_END_IF
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Dark_Anim01)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Dark_Anim01)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_MontyMole) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
        EVT_CALL(GetOwnerEncounterTrigger, LVar0)
        EVT_IF_NE(LVar0, ENCOUNTER_TRIGGER_NONE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Dark_Anim05)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MontyMole_01) = {
    #define LV_ShouldBurrow LVar3
    EVT_LOOP(0)
        EVT_IF_EQ(MV_NextBurrowTime_Mole_01, 0)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_01, TRUE)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(LV_ShouldBurrow, TRUE)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, NPC_MontyMole_01, LVar0, LVar1, LVar2)
            EVT_CALL(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EVT_END_IF
        EVT_CALL(GetPartnerInUse, LVar9)
        EVT_IF_EQ(LVar9, PARTNER_BOW)
            EVT_SET(LVar3, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MV_PauseBurrowing, TRUE)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(LV_ShouldBurrow, TRUE)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_01, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_01, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_01, 1)
                EVT_WAIT(1)
                EVT_SET(AF_FLO_IsUnderground_Mole_01, TRUE)
                EVT_IF_NE(MV_NextBurrowTime_Mole_01, 0)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        EVT_SET(LVar1, 4)
                    EVT_ELSE
                        EVT_SET(LVar1, 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_262, SOUND_SPACE_MODE_0)
                    EVT_CALL(ShowEmote, NPC_MontyMole_01, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    EVT_WAIT(LVar1)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_BURROW_DIG, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim11)
                EVT_WAIT(20)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleA, FALSE)
                    EVT_CALL(SetNpcPos, NPC_MontyMole_01, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_01, TRUE)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleA, FALSE)
                    EVT_CALL(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_01)) - 1, LVar0)
                    EVT_ADD(LVar0, 1)
                    EVT_USE_BUF(EVT_PTR(N(BurrowLocations_Mole_01)))
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, NPC_MontyMole_01, LVar1, LVar2, LVar3)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_01, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_SET(AF_FLO_IsUnderground_Mole_01, FALSE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_01, 1)
                EVT_WAIT(1)
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_01, SOUND_BURROW_SURFACE, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim10)
                EVT_WAIT(10)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
                EVT_CALL(RandInt, 30, LVar0)
                EVT_ADD(LVar0, 60)
                EVT_SET(MV_NextBurrowTime_Mole_01, LVar0)
            EVT_ELSE
                EVT_IF_GT(MV_NextBurrowTime_Mole_01, 0)
                    EVT_SUB(MV_NextBurrowTime_Mole_01, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MontyMole_02) = {
     #define LV_ShouldBurrow LVar3
    EVT_LOOP(0)
        EVT_IF_EQ(MV_NextBurrowTime_Mole_02, 0)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_02, TRUE)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(LV_ShouldBurrow, TRUE)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, NPC_MontyMole_02, LVar0, LVar1, LVar2)
            EVT_CALL(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EVT_END_IF
        EVT_CALL(GetPartnerInUse, LVar9)
        EVT_IF_EQ(LVar9, PARTNER_BOW)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MV_PauseBurrowing, TRUE)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(LV_ShouldBurrow, TRUE)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_02, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_02, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_02, 1)
                EVT_WAIT(1)
                EVT_SET(AF_FLO_IsUnderground_Mole_02, TRUE)
                EVT_IF_NE(MV_NextBurrowTime_Mole_02, 0)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        EVT_SET(LVar1, 4)
                    EVT_ELSE
                        EVT_SET(LVar1, 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_262, SOUND_SPACE_MODE_0)
                    EVT_CALL(ShowEmote, NPC_MontyMole_02, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    EVT_WAIT(LVar1)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_BURROW_DIG, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim11)
                EVT_WAIT(20)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleB, FALSE)
                    EVT_CALL(SetNpcPos, NPC_MontyMole_02, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_02, TRUE)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleB, FALSE)
                    EVT_CALL(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_02)) - 1, LVar0)
                    EVT_ADD(LVar0, 1)
                    EVT_USE_BUF(EVT_PTR(N(BurrowLocations_Mole_02)))
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, NPC_MontyMole_02, LVar1, LVar2, LVar3)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_02, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_SET(AF_FLO_IsUnderground_Mole_02, FALSE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_02, 1)
                EVT_WAIT(1)
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_02, SOUND_BURROW_SURFACE, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
                EVT_WAIT(10)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
                EVT_CALL(RandInt, 35, LVar0)
                EVT_ADD(LVar0, 55)
                EVT_SET(MV_NextBurrowTime_Mole_02, LVar0)
            EVT_ELSE
                EVT_IF_GT(MV_NextBurrowTime_Mole_02, 0)
                    EVT_SUB(MV_NextBurrowTime_Mole_02, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MontyMole_03) = {
    #define LV_ShouldBurrow LVar3
    EVT_LOOP(0)
        EVT_IF_EQ(MV_NextBurrowTime_Mole_03, 0)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_03, TRUE)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(LV_ShouldBurrow, TRUE)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, NPC_MontyMole_03, LVar0, LVar1, LVar2)
            EVT_CALL(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EVT_END_IF
        EVT_CALL(GetPartnerInUse, LVar9)
        EVT_IF_EQ(LVar9, PARTNER_BOW)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MV_PauseBurrowing, TRUE)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(LV_ShouldBurrow, TRUE)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_03, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_03, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_03, 1)
                EVT_WAIT(1)
                EVT_SET(AF_FLO_IsUnderground_Mole_03, TRUE)
                EVT_IF_NE(MV_NextBurrowTime_Mole_03, 0)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        EVT_SET(LVar1, 4)
                    EVT_ELSE
                        EVT_SET(LVar1, 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_03, SOUND_262, SOUND_SPACE_MODE_0)
                    EVT_CALL(ShowEmote, NPC_MontyMole_03, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    EVT_WAIT(LVar1)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_03, SOUND_BURROW_DIG, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim11)
                EVT_WAIT(20)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleC, FALSE)
                    EVT_CALL(SetNpcPos, NPC_MontyMole_03, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_03, TRUE)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleC, FALSE)
                    EVT_CALL(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_03)) - 1, LVar0)
                    EVT_ADD(LVar0, 1)
                    EVT_USE_BUF(EVT_PTR(N(BurrowLocations_Mole_03)))
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, NPC_MontyMole_03, LVar1, LVar2, LVar3)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_03, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_SET(AF_FLO_IsUnderground_Mole_03, FALSE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_03, 1)
                EVT_WAIT(1)
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_03, SOUND_BURROW_SURFACE, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim10)
                EVT_WAIT(10)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
                EVT_CALL(RandInt, 40, LVar0)
                EVT_ADD(LVar0, 50)
                EVT_SET(MV_NextBurrowTime_Mole_03, LVar0)
            EVT_ELSE
                EVT_IF_GT(MV_NextBurrowTime_Mole_03, 0)
                    EVT_SUB(MV_NextBurrowTime_Mole_03, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MontyMole_04) = {
    #define LV_ShouldBurrow LVar3
    EVT_LOOP(0)
        EVT_IF_EQ(MV_NextBurrowTime_Mole_04, 0)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_04, TRUE)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(LV_ShouldBurrow, TRUE)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, NPC_MontyMole_04, LVar0, LVar1, LVar2)
            EVT_CALL(IsPlayerWithin, LVar0, LVar2, MV_NextBurrowTriggerRadius, LV_ShouldBurrow)
        EVT_END_IF
        EVT_CALL(GetPartnerInUse, LVar9)
        EVT_IF_EQ(LVar9, PARTNER_BOW)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MV_PauseBurrowing, TRUE)
            EVT_SET(LV_ShouldBurrow, FALSE)
        EVT_END_IF
        EVT_IF_EQ(LV_ShouldBurrow, TRUE)
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_04, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_04, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_04, 1)
                EVT_WAIT(1)
                EVT_SET(AF_FLO_IsUnderground_Mole_04, TRUE)
                EVT_IF_NE(MV_NextBurrowTime_Mole_04, 0)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                        EVT_SET(LVar1, 4)
                    EVT_ELSE
                        EVT_SET(LVar1, 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_04, SOUND_262, SOUND_SPACE_MODE_0)
                    EVT_CALL(ShowEmote, NPC_MontyMole_04, EMOTE_EXCLAMATION, 0, LVar1, EMOTER_NPC, 0, 0, 0, 0)
                    EVT_WAIT(LVar1)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_04, SOUND_BURROW_DIG, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim11)
                EVT_WAIT(20)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleD, FALSE)
                    EVT_CALL(SetNpcPos, NPC_MontyMole_04, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AF_FLO_IsUnderground_Mole_04, TRUE)
                EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleD, FALSE)
                    EVT_CALL(RandInt, ARRAY_COUNT(N(BurrowLocations_Mole_04)) - 1, LVar0)
                    EVT_ADD(LVar0, 1)
                    EVT_USE_BUF(EVT_PTR(N(BurrowLocations_Mole_04)))
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, NPC_MontyMole_04, LVar1, LVar2, LVar3)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_MontyMole_04, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_SET(AF_FLO_IsUnderground_Mole_04, FALSE)
                EVT_CALL(NpcFacePlayer, NPC_MontyMole_04, 1)
                EVT_WAIT(1)
                EVT_CALL(PlaySoundAtNpc, NPC_MontyMole_04, SOUND_BURROW_SURFACE, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim10)
                EVT_WAIT(10)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
                EVT_CALL(RandInt, 45, LVar0)
                EVT_ADD(LVar0, 45)
                EVT_SET(MV_NextBurrowTime_Mole_04, LVar0)
            EVT_ELSE
                EVT_IF_GT(MV_NextBurrowTime_Mole_04, 0)
                    EVT_SUB(MV_NextBurrowTime_Mole_04, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MontyMole_01) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MontyMole)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_MontyMole)))
    EVT_CALL(EnableNpcShadow, NPC_MontyMole_01, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_01)))
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim10)
        EVT_CASE_EQ(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleA, FALSE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_01)))
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_01, ANIM_MontyMole_Dark_Anim10)
                EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_01, ENEMY_FLAG_PASSIVE, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_MontyMole_01, NPC_DISPOSE_LOCATION)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_MontyMole_01, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MontyMole_02) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MontyMole)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_MontyMole)))
    EVT_CALL(EnableNpcShadow, NPC_MontyMole_02, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_02)))
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
        EVT_CASE_EQ(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleB, FALSE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_02)))
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_02, ANIM_MontyMole_Dark_Anim10)
                EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_02, ENEMY_FLAG_PASSIVE, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_MontyMole_02, NPC_DISPOSE_LOCATION)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_MontyMole_02, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MontyMole_03) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MontyMole)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_MontyMole)))
    EVT_CALL(EnableNpcShadow, NPC_MontyMole_03, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_03)))
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim10)
        EVT_CASE_EQ(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleC, FALSE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_03)))
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_03, ANIM_MontyMole_Dark_Anim10)
                EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_03, ENEMY_FLAG_PASSIVE, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_MontyMole_03, NPC_DISPOSE_LOCATION)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_MontyMole_03, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MontyMole_04) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MontyMole)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_MontyMole)))
    EVT_CALL(EnableNpcShadow, NPC_MontyMole_04, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_04)))
            EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim10)
        EVT_CASE_EQ(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
            EVT_IF_EQ(GF_FLO03_Defeated_MontyMoleD, FALSE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MontyMole_04)))
                EVT_CALL(SetNpcAnimation, NPC_MontyMole_04, ANIM_MontyMole_Dark_Anim10)
                EVT_CALL(SetEnemyFlagBits, NPC_MontyMole_04, ENEMY_FLAG_PASSIVE, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_MontyMole_04, NPC_DISPOSE_LOCATION)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_MontyMole_04, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Petunia) = {
    .id = NPC_Petunia,
    .pos = { -30.0f, 0.0f, 100.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Petunia),
    .settings = &N(NpcSettings_Petunia),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Petunia_Idle,
        .walk   = ANIM_Petunia_Idle,
        .run    = ANIM_Petunia_Idle,
        .chase  = ANIM_Petunia_Idle,
        .anim_4 = ANIM_Petunia_Idle,
        .anim_5 = ANIM_Petunia_Idle,
        .death  = ANIM_Petunia_Idle,
        .hit    = ANIM_Petunia_Idle,
        .anim_8 = ANIM_Petunia_Idle,
        .anim_9 = ANIM_Petunia_Idle,
        .anim_A = ANIM_Petunia_Idle,
        .anim_B = ANIM_Petunia_Idle,
        .anim_C = ANIM_Petunia_Idle,
        .anim_D = ANIM_Petunia_Idle,
        .anim_E = ANIM_Petunia_Idle,
        .anim_F = ANIM_Petunia_Idle,
    },
    .tattle = MSG_NpcTattle_Petunia,
};

NpcData N(NpcData_Dayzee) = {
    .id = NPC_Dayzee,
    .pos = { -233.0f, 0.0f, -217.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Dayzee),
    .settings = &N(NpcSettings_Dayzee),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Dayzee_Anim01,
        .walk   = ANIM_Dayzee_Anim02,
        .run    = ANIM_Dayzee_Anim03,
        .chase  = ANIM_Dayzee_Anim03,
        .anim_4 = ANIM_Dayzee_Anim01,
        .anim_5 = ANIM_Dayzee_Anim01,
        .death  = ANIM_Dayzee_Anim08,
        .hit    = ANIM_Dayzee_Anim08,
        .anim_8 = ANIM_Dayzee_Anim06,
        .anim_9 = ANIM_Dayzee_Anim07,
        .anim_A = ANIM_Dayzee_Anim01,
        .anim_B = ANIM_Dayzee_Anim01,
        .anim_C = ANIM_Dayzee_Anim01,
        .anim_D = ANIM_Dayzee_Anim01,
        .anim_E = ANIM_Dayzee_Anim01,
        .anim_F = ANIM_Dayzee_Anim01,
    },
};

NpcData N(NpcData_MontyMole_01) = {
    .id = NPC_MontyMole_01,
    .pos = { -100.0f, 0.0f, 210.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_MontyMole_01),
    .settings = &N(NpcSettings_Dayzee),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcData N(NpcData_MontyMole_02) = {
    .id = NPC_MontyMole_02,
    .pos = { -130.0f, 0.0f, 0.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_MontyMole_02),
    .settings = &N(NpcSettings_Dayzee),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcData N(NpcData_MontyMole_03) = {
    .id = NPC_MontyMole_03,
    .pos = { 75.0f, 0.0f, 20.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_MontyMole_03),
    .settings = &N(NpcSettings_Dayzee),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcData N(NpcData_MontyMole_04) = {
    .id = NPC_MontyMole_04,
    .pos = { 71.0f, 0.0f, 200.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_MontyMole_04),
    .settings = &N(NpcSettings_Dayzee),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_MontyMole_Dark_Anim01,
        .walk   = ANIM_MontyMole_Dark_Anim02,
        .run    = ANIM_MontyMole_Dark_Anim03,
        .chase  = ANIM_MontyMole_Dark_Anim03,
        .anim_4 = ANIM_MontyMole_Dark_Anim01,
        .anim_5 = ANIM_MontyMole_Dark_Anim01,
        .death  = ANIM_MontyMole_Dark_Anim05,
        .hit    = ANIM_MontyMole_Dark_Anim05,
        .anim_8 = ANIM_MontyMole_Dark_Anim00,
        .anim_9 = ANIM_MontyMole_Dark_Anim00,
        .anim_A = ANIM_MontyMole_Dark_Anim00,
        .anim_B = ANIM_MontyMole_Dark_Anim00,
        .anim_C = ANIM_MontyMole_Dark_Anim00,
        .anim_D = ANIM_MontyMole_Dark_Anim00,
        .anim_E = ANIM_MontyMole_Dark_Anim00,
        .anim_F = ANIM_MontyMole_Dark_Anim00,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Petunia)),
    NPC_GROUP(N(NpcData_Dayzee), BTL_FLO_FORMATION_0F, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_01), BTL_FLO2_FORMATION_02, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_02), BTL_FLO2_FORMATION_01, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_03), BTL_FLO2_FORMATION_03, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_04), BTL_FLO2_FORMATION_04, BTL_FLO2_STAGE_01),
    {}
};
