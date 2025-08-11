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
    Call(SetNpcVar, NPC_Eldstar, 0, 0)
    Call(GetNpcPos, NPC_Eldstar, LVar2, LVar3, LVar4)
    Loop(0)
        Call(MakeLerp, 0, 15, 20, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(LVar5, LVar3)
            Add(LVar5, LVar0)
            Call(GetNpcPos, NPC_Eldstar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Eldstar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Mamar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Mamar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Skolar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Skolar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Muskular, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Misstar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Misstar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Klevar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Klevar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Kalmar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Kalmar, LVar2, LVar5, LVar4)
            Label(10)
            Wait(2)
            Call(GetNpcVar, NPC_Eldstar, 0, LVar6)
            IfNe(LVar6, 0)
                Goto(10)
            EndIf
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 15, 0, 20, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(LVar5, LVar3)
            Add(LVar5, LVar0)
            Call(GetNpcPos, NPC_Eldstar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Eldstar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Mamar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Mamar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Skolar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Skolar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Muskular, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Misstar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Misstar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Klevar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Klevar, LVar2, LVar5, LVar4)
            Call(GetNpcPos, NPC_Kalmar, LVar2, LVar0, LVar4)
            Call(SetNpcPos, NPC_Kalmar, LVar2, LVar5, LVar4)
            Label(11)
            Wait(2)
            Call(GetNpcVar, NPC_Eldstar, 0, LVar6)
            IfNe(LVar6, 0)
                Goto(11)
            EndIf
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_RecieveStarBeam) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar2, 85)
            Call(GetPartnerInUse, LVar0)
            IfNe(LVar0, PARTNER_NONE)
                Call(InterruptUsePartner)
                Wait(15)
            EndIf
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, true)
    Thread
        Call(func_802D2C14, 1)
        Wait(30 * DT)
        Call(PlayerMoveTo, 0, 80, 10)
        Call(PlayerFaceNpc, NPC_Eldstar, false)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 136, 80)
    Call(SetPanTarget, CAM_DEFAULT, 0, 136, 80)
    Call(SetCamDistance, CAM_DEFAULT, Float(510.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-2.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 0, 220, -275)
    Call(SetCamDistance, CAM_DEFAULT, Float(1.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(-4.5), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_HOS_0069)
    Call(func_802D2C14, 0)
    Wait(30 * DT)
    Call(SetSelfVar, 0, 1)
    Call(SetPanTarget, CAM_DEFAULT, 0, 136, 80)
    Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-2.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(MakeLerp, 0, 360, 25, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Mamar, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Skolar, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Misstar, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Kalmar, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(GetPlayerPos, LVar6, LVar7, LVar8)
    Thread
        Call(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_TOUCHES_GROUND, false)
        Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
        Call(SetNpcJumpscale, NPC_Eldstar, Float(3.2))
        Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Eldstar, LVar0, LVar1, LVar2, 5)
        Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
        Add(LVar7, 20)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, LVar6, LVar7, LVar8)
        PlayEffect(EFFECT_SPARKLES, 0, LVar6, LVar7, LVar8, 10)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_TOUCHES_GROUND, false)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Leap)
        Call(SetNpcJumpscale, NPC_Mamar, Float(3.2))
        Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Mamar, LVar0, LVar1, LVar2, 5)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_TOUCHES_GROUND, false)
        Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Leap)
        Call(SetNpcJumpscale, NPC_Skolar, Float(3.2))
        Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Skolar, LVar0, LVar1, LVar2, 5)
        Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Idle)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_TOUCHES_GROUND, false)
        Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
        Call(SetNpcJumpscale, NPC_Muskular, Float(3.2))
        Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Muskular, LVar0, LVar1, LVar2, 5)
        Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_TOUCHES_GROUND, false)
        Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Leap)
        Call(SetNpcJumpscale, NPC_Misstar, Float(3.2))
        Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Misstar, LVar0, LVar1, LVar2, 5)
        Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Idle)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_TOUCHES_GROUND, false)
        Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Leap)
        Call(SetNpcJumpscale, NPC_Klevar, Float(3.2))
        Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Klevar, LVar0, LVar1, LVar2, 5)
        Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Idle)
    EndThread
    Call(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_TOUCHES_GROUND, false)
    Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Leap)
    Call(SetNpcJumpscale, NPC_Kalmar, Float(3.2))
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Kalmar, LVar0, LVar1, LVar2, 5)
    Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    Thread
        PlayEffect(EFFECT_RADIAL_SHIMMER, 2, 0, 154, 85, Float(2.8), 100)
        Call(PlaySound, SOUND_RELEASE_ENERGY)
        Wait(115)
        Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
        Add(LVar7, 20)
        PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar6, LVar7, LVar8, Float(0.3), 30)
    EndThread
    Wait(40)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
    PlayEffect(EFFECT_SPARKLES, 0, 10, 154, 88, 10)
    Wait(6)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
    PlayEffect(EFFECT_SPARKLES, 0, 10, 154, 88, 15)
    Wait(6)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, -10, 154, 88)
    PlayEffect(EFFECT_SPARKLES, 0, -10, 154, 88, 20)
    Wait(6)
    Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
    PlayEffect(EFFECT_SPARKLES, 0, 10, 154, 88, 25)
    Wait(6)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Loop(3)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 0, 154, 88)
        PlayEffect(EFFECT_SPARKLES, 0, 0, 154, 88, 30)
        Wait(6)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, -10, 154, 88)
        PlayEffect(EFFECT_SPARKLES, 0, -10, 154, 88, 30)
        Wait(6)
        Call(PlaySoundAt, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT, 10, 154, 88)
        PlayEffect(EFFECT_SPARKLES, 0, 10, 154, 88, 30)
        Wait(6)
    EndLoop
    Call(N(UnlockStarBeam))
    Call(SetSelfVar, 0, 0)
    Wait(30 * DT)
    Call(ShowMessageAtScreenPos, MSG_Menus_0198, 160, 40)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(30 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 0, 220, -275)
    Call(SetCamDistance, CAM_DEFAULT, Float(1.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(-4.5), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_HOS_006A)
    Wait(30 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 0, 136, 80)
    Call(SetCamDistance, CAM_DEFAULT, Float(510.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamPitch, CAM_DEFAULT, Float(8.0), Float(-7.9))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Set(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
    ExecWait(N(EVS_Starship_Summon))
    Call(SetPanTarget, CAM_DEFAULT, 0, 220, -275)
    Call(SetCamDistance, CAM_DEFAULT, Float(1.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(-4.5), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_HOS_006B)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Back)
    Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Back)
    Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Back)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o616, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetZoneEnabled, ZONE_o622, false)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5))
    Call(EnableModel, MODEL_o362, false)
    Call(EnableModel, MODEL_o397, false)
    Wait(15 * DT)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarSpirit) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(hos_05_ENTRY_0, hos_05_ENTRY_1)
            Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Back)
            Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Back)
            Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Back)
            Switch(GB_StoryProgress)
                CaseEq(STORY_CH8_REACHED_STAR_HAVEN)
                    Exec(N(EVS_StarSpirit_HoverBobbing))
                    Call(GetSelfNpcID, LVar0)
                    IfEq(LVar0, NPC_Eldstar)
                        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_RecieveStarBeam)))
                    EndIf
                CaseGe(STORY_CH8_STAR_SHIP_ACTIVATED)
                    Exec(N(EVS_StarSpirit_HoverBobbing))
                CaseDefault
                    Call(RemoveNpc, NPC_SELF)
            EndSwitch
    EndSwitch
    Return
    End
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
