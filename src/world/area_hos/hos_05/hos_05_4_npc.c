#include "hos_05.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(UnlockStarBeam)) {
    gPlayerData.starBeamLevel = 1;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.starPower = gPlayerData.maxStarPower * SP_PER_BAR;
    sync_status_bar();
    return ApiStatus_DONE2;
}

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Bowser.inc.c"

#include "world/common/enemy/Kammy_Flying.inc.c"

#include "world/common/npc/StarRod.inc.c"

EvtScript N(EVS_StarSpirit_HoverBobbing) = {
    EVT_CALL(SetNpcVar, NPC_Eldstar, 0, 0)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar2, LVar3, LVar4)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, 15, 20, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar5, LVar3)
            EVT_ADD(LVar5, LVar0)
            EVT_CALL(GetNpcPos, NPC_Eldstar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Eldstar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Mamar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Mamar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Skolar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Skolar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Muskular, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Misstar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Misstar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Klevar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Klevar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Kalmar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Kalmar, LVar2, LVar5, LVar4)
            EVT_LABEL(10)
            EVT_WAIT(2)
            EVT_CALL(GetNpcVar, NPC_Eldstar, 0, LVar6)
            EVT_IF_NE(LVar6, 0)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 15, 0, 20, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar5, LVar3)
            EVT_ADD(LVar5, LVar0)
            EVT_CALL(GetNpcPos, NPC_Eldstar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Eldstar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Mamar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Mamar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Skolar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Skolar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Muskular, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Misstar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Misstar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Klevar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Klevar, LVar2, LVar5, LVar4)
            EVT_CALL(GetNpcPos, NPC_Kalmar, LVar2, LVar0, LVar4)
            EVT_CALL(SetNpcPos, NPC_Kalmar, LVar2, LVar5, LVar4)
            EVT_LABEL(11)
            EVT_WAIT(2)
            EVT_CALL(GetNpcVar, NPC_Eldstar, 0, LVar6)
            EVT_IF_NE(LVar6, 0)
                EVT_GOTO(11)
            EVT_END_IF
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RecieveStarBeam) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar2, 85)
            EVT_CALL(GetPartnerInUse, LVar0)
            EVT_IF_NE(LVar0, PARTNER_NONE)
                EVT_CALL(InterruptUsePartner)
                EVT_WAIT(15)
            EVT_END_IF
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(func_802D2C14, 1)
        EVT_WAIT(30 * DT)
        EVT_CALL(PlayerMoveTo, 0, 80, 10)
        EVT_CALL(PlayerFaceNpc, NPC_Eldstar, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 136, 80)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 136, 80)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(510.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-2.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 220, -275)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-4.5), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_HOS_0069)
    EVT_CALL(func_802D2C14, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 136, 80)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-2.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 25, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Mamar, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Skolar, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Misstar, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Kalmar, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetPlayerPos, LVar6, LVar7, LVar8)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Eldstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Eldstar, LVar0, LVar1, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
        EVT_ADD(LVar7, 20)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, LVar6, LVar7, LVar8)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar6, LVar7, LVar8, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Mamar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Mamar, LVar0, LVar1, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Skolar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Skolar, LVar0, LVar1, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Muskular, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Muskular, LVar0, LVar1, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Misstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Misstar, LVar0, LVar1, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Klevar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Klevar, LVar0, LVar1, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Idle)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_TOUCHES_GROUND, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Leap)
    EVT_CALL(SetNpcJumpscale, NPC_Kalmar, EVT_FLOAT(3.2))
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Kalmar, LVar0, LVar1, LVar2, 5)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 2, 0, 154, 85, EVT_FLOAT(2.8), 100)
        EVT_CALL(PlaySound, SOUND_RELEASE_ENERGY)
        EVT_WAIT(115)
        EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
        EVT_ADD(LVar7, 20)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar6, LVar7, LVar8, EVT_FLOAT(0.3), 30)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 10, 154, 88, 10)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 10, 154, 88, 15)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, -10, 154, 88)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, -10, 154, 88, 20)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 10, 154, 88, 25)
    EVT_WAIT(6)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_LOOP(3)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 0, 154, 88)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 0, 154, 88, 30)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, -10, 154, 88)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, -10, 154, 88, 30)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 10, 154, 88, 30)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_CALL(N(UnlockStarBeam))
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0198, 160, 40)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 220, -275)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-4.5), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_HOS_006A)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 136, 80)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(510.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(8.0), EVT_FLOAT(-7.9))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_SET(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
    EVT_EXEC_WAIT(N(EVS_Starship_Summon))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 220, -275)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-4.5), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_HOS_006B)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Back)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Back)
    EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Back)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o616, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetZoneEnabled, ZONE_o622, FALSE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(EnableModel, MODEL_o362, FALSE)
    EVT_CALL(EnableModel, MODEL_o397, FALSE)
    EVT_WAIT(15 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarSpirit) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(hos_05_ENTRY_0, hos_05_ENTRY_1)
            EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Back)
            EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Back)
            EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Back)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_EQ(STORY_CH8_REACHED_STAR_HAVEN)
                    EVT_EXEC(N(EVS_StarSpirit_HoverBobbing))
                    EVT_CALL(GetSelfNpcID, LVar0)
                    EVT_IF_EQ(LVar0, NPC_Eldstar)
                        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_RecieveStarBeam)))
                    EVT_END_IF
                EVT_CASE_GE(STORY_CH8_STAR_SHIP_ACTIVATED)
                    EVT_EXEC(N(EVS_StarSpirit_HoverBobbing))
                EVT_CASE_DEFAULT
                    EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Panic,
    ANIM_WorldEldstar_Wave,
    ANIM_WorldEldstar_Angry,
    ANIM_WorldEldstar_Hurt,
    ANIM_WorldEldstar_Back,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    ANIM_WorldMamar_Panic,
    ANIM_WorldMamar_Angry,
    ANIM_WorldMamar_Hurt,
    ANIM_WorldMamar_Back,
    ANIM_WorldMamar_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    ANIM_WorldSkolar_IdleSad,
    ANIM_WorldSkolar_Panic,
    ANIM_WorldSkolar_Hurt,
    ANIM_WorldSkolar_Talk,
    ANIM_WorldSkolar_Back,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    ANIM_WorldMuskular_Panic,
    ANIM_WorldMuskular_Hurt,
    ANIM_WorldMuskular_Happy,
    ANIM_WorldMuskular_Back,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Still,
    ANIM_WorldMisstar_Idle,
    ANIM_WorldMisstar_Panic,
    ANIM_WorldMisstar_Hurt,
    ANIM_WorldMisstar_Happy,
    ANIM_WorldMisstar_Back,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    ANIM_WorldKlevar_Panic,
    ANIM_WorldKlevar_Hurt,
    ANIM_WorldKlevar_TalkHappy,
    ANIM_WorldKlevar_Back,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    ANIM_WorldKalmar_Panic,
    ANIM_WorldKalmar_Hurt,
    ANIM_WorldKalmar_TalkHappy,
    ANIM_WorldKalmar_Back,
    ANIM_LIST_END
};

NpcData N(NpcData_StarSpirits)[] = {
    {
        .id = NPC_Mamar,
        .pos = { 220.0f, 220.0f, -170.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Mamar),
    },
    {
        .id = NPC_Skolar,
        .pos = { -275.0f, 220.0f, 60.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Skolar),
    },
    {
        .id = NPC_Muskular,
        .pos = { 125.0f, 220.0f, 250.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Muskular),
    },
    {
        .id = NPC_Misstar,
        .pos = { -125.0f, 220.0f, 250.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Misstar),
    },
    {
        .id = NPC_Klevar,
        .pos = { 275.0f, 220.0f, 60.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Klevar),
    },
    {
        .id = NPC_Kalmar,
        .pos = { -220.0f, 220.0f, -170.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Kalmar),
    },
    {
        .id = NPC_Eldstar,
        .pos = { 0.0f, 220.0f, -275.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
};

AnimID N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_ClownCarStill,
    ANIM_WorldBowser_ClownCarIdle,
    ANIM_WorldBowser_ClownCarOpenMouth,
    ANIM_WorldBowser_ClownCarBrandish,
    ANIM_WorldBowser_ClownCarStarRod,
    ANIM_WorldBowser_ClownCarCloseMouth,
    ANIM_WorldBowser_ClownCarFireBreath,
    ANIM_WorldBowser_ClownCarTalk,
    ANIM_WorldBowser_ClownCarLaugh,
    ANIM_WorldBowser_ClownCarPropeller,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim09,
    ANIM_WorldKammy_Anim0B,
    ANIM_WorldKammy_Anim0D,
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim11,
    ANIM_WorldKammy_Anim12,
    ANIM_WorldKammy_Anim17,
    ANIM_LIST_END
};

NpcData N(NpcData_Thieves)[] = {
    {
        .id = NPC_Bowser_Body,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Bowser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOWSER_ANIMS,
        .extraAnimations = N(ExtraAnims_Bowser),
    },
    {
        .id = NPC_Bowser_Prop,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Bowser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOWSER_ANIMS,
        .extraAnimations = N(ExtraAnims_Bowser),
    },
    {
        .id = NPC_Kammy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Kammy_Flying),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KAMMY_ANIMS,
        .extraAnimations = N(ExtraAnims_Kammy),
    },
    {
        .id = NPC_StarRod,
        .pos = { 0.0f, 174.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarRod),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = STAR_ROD_ANIMS,
    },
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_Thieves)),
    NPC_GROUP(N(NpcData_StarSpirits)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_StarSpirits)),
    {}
};
