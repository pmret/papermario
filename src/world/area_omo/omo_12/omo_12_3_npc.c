#include "omo_12.h"
#include "sprite/player.h"

#include "world/common/npc/BigLanternGhost.inc.c"

NpcSettings N(NpcSettings_Watt) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/atomic/CreateDarkness.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

API_CALLABLE(N(SetLightOriginAndPower)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 alpha = evt_get_variable(script, *args++);

    set_screen_overlay_center_worldpos(SCREEN_LAYER_BACK, 1, x, y, z);
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, alpha);
    set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, 255.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetLightOff)) {
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, 0.0f);
    set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, 0.0f);
    return ApiStatus_DONE2;
}

MAP_STATIC_PAD(1, unk);

enum {
    LIGHT_FROM_DEFAULT      = 0,
    LIGHT_FROM_GHOST        = 1,
    LIGHT_FROM_WATT         = 2,
    LIGHT_FROM_LANTERN      = 3,
    LIGHT_FROM_FLICK_OFF    = 4,
    LIGHT_FROM_HIDDEN       = 5,
    LIGHT_FROM_NO_CHANGE    = 6,
};

EvtScript N(EVS_ManageLanternLight) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_LABEL(0)
        EVT_SWITCH(AB_OMO12_LightSource)
            EVT_CASE_EQ(LIGHT_FROM_DEFAULT)
            EVT_CASE_EQ(LIGHT_FROM_GHOST)
                EVT_CALL(GetNpcPos, NPC_BigLanternGhost, LVar0, LVar1, LVar2)
                EVT_SET(LVar3, AB_OMO12_LightPowerMod)
                EVT_ADD(LVar3, 128)
                EVT_CALL(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar3)
            EVT_CASE_EQ(LIGHT_FROM_WATT)
                EVT_CALL(GetNpcPos, NPC_Watt, LVar0, LVar1, LVar2)
                EVT_SET(LVar3, AB_OMO12_LightPowerMod)
                EVT_ADD(LVar3, 128)
                EVT_CALL(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar3)
            EVT_CASE_EQ(LIGHT_FROM_LANTERN)
                EVT_CALL(GetNpcPos, NPC_LaternTop, LVar0, LVar1, LVar2)
                EVT_SET(LVar3, AB_OMO12_LightPowerMod)
                EVT_ADD(LVar3, 128)
                EVT_CALL(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar3)
            EVT_CASE_EQ(LIGHT_FROM_FLICK_OFF)
                EVT_CALL(N(SetLightOff))
                EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_DEFAULT)
            EVT_CASE_EQ(LIGHT_FROM_HIDDEN)
                EVT_SET(LVar3, AB_OMO12_LightPowerMod)
                EVT_ADD(LVar3, 128)
                EVT_CALL(N(SetLightOriginAndPower), NPC_DISPOSE_LOCATION, LVar3)
                EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_DEFAULT)
            EVT_CASE_EQ(LIGHT_FROM_NO_CHANGE)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupLightSource) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_HIDDEN)
            EVT_SET(AB_OMO12_LightPowerMod, 127)
            EVT_EXEC(N(EVS_ManageLanternLight))
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_LANTERN)
            EVT_SET(AB_OMO12_LightPowerMod, 102)
            EVT_EXEC(N(EVS_ManageLanternLight))
        EVT_CASE_GE(STORY_CH4_WATT_JOINED_PARTY)
            EVT_EXEC_WAIT(N(EVS_CreateDarkness))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterScene) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerPos, 70, 20, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH4_004E, 160, 40)
    EVT_CALL(SetNpcPos, NPC_BigLanternGhost, -150, 0, 20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -150, 0, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -150, 0, 20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_BigLanternGhost, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, 32)
    EVT_ADD(LVar3, 10)
    // turn on lantern light
    EVT_CALL(MakeLerp, 255, 100, 60 * DT, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetLightOriginAndPower), LVar2, LVar3, LVar4, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01, 0, MSG_CH4_004F)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 0, 20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.7 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_GHOST)
    EVT_SET(AB_OMO12_LightPowerMod, -28)
    EVT_CALL(SetNpcAnimation, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim06)
    EVT_CALL(SetNpcSpeed, NPC_BigLanternGhost, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_BigLanternGhost, 0, 20, 0)
    EVT_CALL(SetNpcAnimation, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim01)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01, 0, MSG_CH4_0050)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim0F)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Shocked)
    EVT_WAIT(15 * DT)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_FLICK_OFF)
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_BigLanternGhost, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseWattTutorial) = {
    EVT_LOOP(0)
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_WATT)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Celebrate, ANIM_WorldWatt_Idle, 5, MSG_CH4_005C)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3f N(WattRightFlightPath)[] = {
    {    0.0,     0.0,    0.0 },
    {   25.0,    -5.0,    0.0 },
    {   60.0,    30.0,    0.0 },
};

Vec3f N(WattLeftFlightPath)[] = {
    {    0.0,     0.0,    0.0 },
    {  -25.0,    -5.0,    0.0 },
    {  -60.0,    30.0,    0.0 },
};

BombTrigger N(BombPos_Lantern_Unused) = {
    .pos = { 0.0f, 0.0f, 20.0f },
    .radius = 0.0f
};

EvtScript N(EVS_Scene_ReleaseWatt) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(GetNpcPos, NPC_LaternTop, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0 / DT), LVar0, LVar1, LVar2, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
    EVT_SET(LVarA, 0)
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_PARTNER)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
            EVT_CALL(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Hurt)
            EVT_SET(LVarA, -1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(NpcFacePlayer, NPC_Watt, 0)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(GetOwnerEncounterTrigger, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CASE_DEFAULT
                EVT_CALL(GetEncounterTriggerHitTier, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_WAIT(25 * DT)
                    EVT_CALL(DisablePlayerInput, FALSE)
                    EVT_RETURN
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_OMO_LANTERN_BREAK)
    EVT_SET(AF_OMO_10, FALSE)
    EVT_LOOP(8)
        EVT_CALL(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(3)
        EVT_CALL(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_LaternTop, ANIM_BigLanternGhost_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_LaternBottom, ANIM_BigLanternGhost_Anim04)
    EVT_THREAD
        EVT_LABEL(10)
            EVT_CALL(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_LaternBottom, NPC_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(2)
            EVT_CALL(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_LaternBottom, NPC_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(2)
            EVT_IF_EQ(AF_OMO_10, FALSE)
                EVT_GOTO(10)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(GetAngleToPlayer, NPC_LaternTop, LVar0)
    EVT_IF_LT(LVar0, 180)
        EVT_SET(LVar1, 27)
        EVT_SET(LVar2, 50)
    EVT_ELSE
        EVT_SET(LVar1, -27)
        EVT_SET(LVar2, -50)
    EVT_END_IF
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, LVar1, 0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_LaternTop, 3)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_LaternTop, 0)
        EVT_CALL(GetNpcPos, NPC_LaternTop, LVar0, 20, LVar2)
        EVT_CALL(NpcJump0, NPC_LaternTop, LVar0, 20, LVar2, 20 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(6 * DT)
        EVT_CALL(GetNpcPos, NPC_LaternTop, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Watt, LVar0, 6, LVar2)
        EVT_LOOP(7)
            EVT_CALL(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
            EVT_CALL(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_WATT)
    EVT_SET(AB_OMO12_LightPowerMod, 72)
    EVT_WAIT(40 * DT)
    EVT_SET(AF_OMO_10, TRUE)
    EVT_CALL(SetNpcPos, NPC_LaternTop, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_LaternBottom, NPC_DISPOSE_LOCATION)
    EVT_WAIT(25)
    EVT_CALL(GetPlayerPos, LVar3, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Watt, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_IF_EQ(LVarA, -1)
        EVT_CALL(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Strain, ANIM_WorldWatt_Hurt, 0, MSG_CH4_0058)
        EVT_THREAD
            EVT_WAIT(10 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Pray)
            EVT_WAIT(15 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_CALL(EndSpeech, NPC_Watt, ANIM_WorldWatt_Strain, ANIM_WorldWatt_Hurt, 0)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Celebrate, ANIM_WorldWatt_Idle, 0, MSG_CH4_0057)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_END_IF
    EVT_CALL(func_802D2C14, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Idle)
    EVT_CALL(PlaySoundAtNpc, NPC_Watt, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Watt, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH4_0059)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_TouchNose)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(EndSpeech, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetAngleToPlayer, NPC_Watt, LVar0)
    EVT_IF_LT(LVar0, 180)
        EVT_SET(LVar1, -25)
    EVT_ELSE
        EVT_SET(LVar1, 25)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_ADD(LVar1, LVar2)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar1, LVar4, 0)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 3)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_Watt, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetNpcPos, NPC_Watt, LVar7, LVar8, LVar9)
    EVT_CALL(GetAngleToPlayer, NPC_Watt, LVar0)
    EVT_IF_LT(LVar0, 180)
        EVT_CALL(LoadPath, 15 * DT, EVT_PTR(N(WattRightFlightPath)), ARRAY_COUNT(N(WattRightFlightPath)), EASING_LINEAR)
        EVT_SET(LVar4, 12)
    EVT_ELSE
        EVT_CALL(LoadPath, 15 * DT, EVT_PTR(N(WattLeftFlightPath)), ARRAY_COUNT(N(WattLeftFlightPath)), EASING_LINEAR)
        EVT_SET(LVar4, -12)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar4)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LABEL(30)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar7)
        EVT_ADD(LVar2, LVar8)
        EVT_ADD(LVar3, LVar9)
        EVT_CALL(SetNpcPos, NPC_Watt, LVar1, LVar2, LVar3)
        EVT_CALL(PlayerFaceNpc, NPC_Watt, FALSE)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(30)
        EVT_END_IF
    EVT_CALL(NpcFacePlayer, NPC_Watt, 3)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH4_005A)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(EndSpeech, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0)
    EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_NO_CHANGE)
    EVT_WAIT(1)
    EVT_CALL(N(ChangeNpcToPartner), NPC_Watt, PARTNER_WATT)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(EVS_PushPartnerSong))
    EVT_WAIT(15 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018E, 160, 40)
    EVT_EXEC(N(EVS_PopSong))
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
        EVT_CALL(MakeLerp, 200, 255, 45 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetLightOriginAndPower), LVar2, LVar3, LVar4, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 8)
        EVT_CALL(N(SetLightOriginAndPower), LVar2, LVar3, LVar4, LVar0)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(CloseMessage)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_CreateDarkness))
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH4_005B)
    EVT_CALL(EnablePartnerAI)
    EVT_EXEC(N(EVS_UseWattTutorial))
    EVT_CALL(N(EnableCameraLeadingPlayer))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_SET(GB_StoryProgress, STORY_CH4_WATT_JOINED_PARTY)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_LaternTop)
    EVT_CALL(RemoveNpc, NPC_LaternBottom)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_BigLanternGhost) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_BigLanternGhost) = {
    EVT_WAIT(1)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_DEFAULT)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, 100)
            EVT_THREAD
                EVT_SET(MF_LanternGhost_DoneSpeaking, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim08, ANIM_BigLanternGhost_Anim08, 0, MSG_CH4_0054)
                EVT_SET(MF_LanternGhost_DoneSpeaking, TRUE)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(15)
                EVT_CALL(SetNpcJumpscale, NPC_LaternTop, EVT_FLOAT(1.0))
                EVT_CALL(SetNpcPos, NPC_LaternTop, 0, 0, 20)
                EVT_CALL(NpcJump0, NPC_LaternTop, 0, 0, 20, 10)
                EVT_CALL(SetNpcPos, NPC_LaternBottom, 0, 0, 20)
            EVT_END_THREAD
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim07)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(10.0))
            EVT_CALL(NpcMoveTo, NPC_SELF, 400, 0, 0)
            EVT_LABEL(0)
                EVT_IF_EQ(MF_LanternGhost_DoneSpeaking, FALSE)
                    EVT_WAIT(1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_CALL(GetNpcPos, NPC_LaternTop, LVar3, LVar4, LVar5)
            EVT_SUBF(LVar3, LVar0)
            EVT_SUBF(LVar4, LVar1)
            EVT_SUBF(LVar5, LVar2)
            EVT_DIVF(LVar3, EVT_FLOAT(60.0))
            EVT_DIVF(LVar4, EVT_FLOAT(60.0))
            EVT_DIVF(LVar5, EVT_FLOAT(60.0))
            EVT_SETF(LVar6, EVT_FLOAT(2.167))
            EVT_SETF(LVar7, EVT_FLOAT(100.0))
            EVT_LOOP(60)
                EVT_ADDF(LVar0, LVar3)
                EVT_ADDF(LVar1, LVar4)
                EVT_ADDF(LVar2, LVar5)
                EVT_ADDF(LVar7, LVar6)
                EVT_CALL(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_SET(AB_OMO12_LightSource, LIGHT_FROM_LANTERN)
            EVT_SET(AB_OMO12_LightPowerMod, 102)
            EVT_WAIT(1)
            EVT_CALL(SetNpcVar, NPC_LaternTop, 0, 1)
            EVT_SET(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BigLanternGhost) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_BigLanternGhost)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_BigLanternGhost)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_LanternTop) = {
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 10)
        EVT_WAIT(6)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, -9)
        EVT_WAIT(6)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 8)
        EVT_WAIT(5)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, -7)
        EVT_WAIT(5)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 6)
        EVT_WAIT(4)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, -5)
        EVT_WAIT(4)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 4)
        EVT_WAIT(3)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, -3)
        EVT_WAIT(3)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 2)
        EVT_WAIT(2)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_BigLanternGhost_Anim02, ANIM_BigLanternGhost_Anim02, 5, MSG_CH4_0055)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_LanternTop) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(AwaitPlayerLeave, LVar0, LVar2, 100)
                EVT_CALL(PartnerCanUseAbility, LVar0)
                EVT_IF_NE(LVar0, TRUE)
                    EVT_CALL(DisablePlayerInput, TRUE)
                    EVT_THREAD
                        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 16)
                        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8)
                        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 4)
                    EVT_END_THREAD
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_BigLanternGhost_Anim02, ANIM_BigLanternGhost_Anim02, 0, MSG_CH4_0056)
                    EVT_CALL(DisablePlayerInput, FALSE)
                EVT_END_IF
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(SetSelfVar, 0, 2)
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(AwaitPlayerApproach, LVar0, LVar2, 60)
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_EQ(LVar0, 2)
                    EVT_CALL(SetSelfVar, 0, 1)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LanternTop) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 20)
            EVT_CALL(SetSelfVar, 0, 2)
        EVT_CASE_GE(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_LanternTop)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_LanternTop)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LanternBottom) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 20)
        EVT_CASE_GE(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_Scene_ReleaseWatt)))
    EVT_CALL(SetNpcFlagBits, NPC_LaternBottom, NPC_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Watt) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
        EVT_CASE_GE(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_LanternGhost)[] = {
    ANIM_BigLanternGhost_Anim01,
    ANIM_BigLanternGhost_Anim06,
    ANIM_BigLanternGhost_Anim07,
    ANIM_BigLanternGhost_Anim08,
    ANIM_BigLanternGhost_Anim0F,
    ANIM_BigLanternGhost_Anim05,
    ANIM_BigLanternGhost_Anim02,
    ANIM_BigLanternGhost_Anim03,
    ANIM_BigLanternGhost_Anim04,
    ANIM_LIST_END
};

NpcData N(NpcData_BigLanternGhost) = {
    .id = NPC_BigLanternGhost,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_BigLanternGhost),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BigLanternGhost),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = NO_DROPS,
    .animations = BIG_LANTERN_GHOST_ANIMS,
    .extraAnimations = N(ExtraAnims_LanternGhost),
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcData N(NpcData_Watt) = {
    .id = NPC_Watt,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Watt),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Watt),
    .flags = COMMON_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldWatt_Idle,
        .walk   = ANIM_WorldWatt_Idle,
        .run    = ANIM_WorldWatt_Idle,
        .chase  = ANIM_WorldWatt_Idle,
        .anim_4 = ANIM_WorldWatt_Idle,
        .anim_5 = ANIM_WorldWatt_Idle,
        .death  = ANIM_WorldWatt_Idle,
        .hit    = ANIM_WorldWatt_Idle,
        .anim_8 = ANIM_WorldWatt_Idle,
        .anim_9 = ANIM_WorldWatt_Idle,
        .anim_A = ANIM_WorldWatt_Idle,
        .anim_B = ANIM_WorldWatt_Idle,
        .anim_C = ANIM_WorldWatt_Idle,
        .anim_D = ANIM_WorldWatt_Idle,
        .anim_E = ANIM_WorldWatt_Idle,
        .anim_F = ANIM_WorldWatt_Idle,
    },
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcData N(NpcData_LanternTop) = {
    .id = NPC_LaternTop,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_LanternTop),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Watt),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = BIG_LANTERN_GHOST_ANIMS,
    .extraAnimations = N(ExtraAnims_LanternGhost),
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcData N(NpcData_LanternBottom) = {
    .id = NPC_LaternBottom,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_LanternBottom),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Watt),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT,
    .drops = NO_DROPS,
    .animations = BIG_LANTERN_GHOST_ANIMS,
    .extraAnimations = N(ExtraAnims_LanternGhost),
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BigLanternGhost), BTL_OMO3_FORMATION_00),
    NPC_GROUP(N(NpcData_Watt)),
    NPC_GROUP(N(NpcData_LanternTop)),
    NPC_GROUP(N(NpcData_LanternBottom)),
    {}
};
