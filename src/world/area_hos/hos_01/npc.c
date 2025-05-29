#include "hos_01.h"
#include "effects.h"

#include "world/common/todo/SwitchToPartner.inc.c"

API_CALLABLE(N(DrawAppearSparkles)) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_sparkles(type, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}

#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_MuteMusicOnPlayerApproach) = {
    Set(LVarA, 0)
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar1, 245)
            Call(IsPlayerWithin, -30, -165, 180, LVar3)
            IfEq(LVar3, 1)
                Goto(10)
            EndIf
        EndIf
        Wait(1)
        Goto(0)
        Label(10)
        Set(LVarA, 1)
        Call(FadeOutMusic, 0, 2000)
        Wait(60)
        Label(20)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfLt(LVar1, 245)
                Call(IsPlayerWithin, -30, -165, 180, LVar3)
                IfEq(LVar3, 0)
                    Goto(30)
                EndIf
            EndIf
            Wait(1)
            Goto(20)
        Label(30)
        Call(SetMusic, 0, SONG_SHOOTING_STAR_SUMMIT, 0, VOL_LEVEL_FULL)
        Wait(30)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Scene_StarSpiritsPlea) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -35, 250, -145)
    Call(SetPanTarget, CAM_DEFAULT, -35, 250, -145)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-5.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(func_802D2C14, 2)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar2, 30)
        Call(SetNpcJumpscale, NPC_PARTNER, 0)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 15 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EndThread
    Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0000)
    Wait(10 * DT)
    Wait(1)
    Call(PlayerFaceNpc, NPC_Eldstar, TRUE)
    Call(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcJumpscale, NPC_Eldstar, 0)
    Call(NpcJump0, NPC_Eldstar, 21, 260, -277, 30 * DT)
    Call(EnableModel, MODEL_1, TRUE)
    Call(PlaySound, SOUND_MULTIPLE_STAR_SPIRITS_APPEAR)
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    Call(EnableModel, MODEL_2, TRUE)
    Call(EnableModel, MODEL_3, TRUE)
    Call(EnableModel, MODEL_4, TRUE)
    Call(EnableModel, MODEL_5, TRUE)
    Call(EnableModel, MODEL_6, TRUE)
    Call(EnableModel, MODEL_7, TRUE)
    SetF(MV_AlphaAmt_Others, Float(-80.0))
    Loop(20 * DT)
#if VERSION_PAL
        AddF(MV_AlphaAmt_Others, Float(7.203))
#else
        AddF(MV_AlphaAmt_Others, Float(6.0))
#endif
        Wait(1)
    EndLoop
#if VERSION_PAL
    SetF(MV_AlphaAmt_Others, Float(40.0))
#endif
    Call(EnableNpcShadow, NPC_Mamar, TRUE)
    Call(EnableNpcShadow, NPC_Skolar, TRUE)
    Call(EnableNpcShadow, NPC_Muskular, TRUE)
    Call(EnableNpcShadow, NPC_Misstar, TRUE)
    Call(EnableNpcShadow, NPC_Klevar, TRUE)
    Call(EnableNpcShadow, NPC_Kalmar, TRUE)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0001)
    Call(SetCamDistance, CAM_DEFAULT, 270)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.8 / DT))
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-6.5))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0002)
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-6.9))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0003)
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-7.3))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldMamar_Idle, 0, MSG_HOS_0004)
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-7.7))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 0, MSG_HOS_0005)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-7.7))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_HOS_0006)
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-7.3))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, 0, MSG_HOS_0007)
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-6.9))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 0, MSG_HOS_0008)
    Set(AB_HOS_StatcAmt_Kalmar, 200)
    Wait(30 * DT)
    Set(AB_HOS_StatcAmt_Kalmar, 0)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 0, MSG_HOS_0009)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, -300)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-6.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_000A)
    Set(AB_HOS_StatcAmt_Eldstar,  200)
    Set(AB_HOS_StatcAmt_Mamar,    200)
    Set(AB_HOS_StatcAmt_Skolar,   200)
    Set(AB_HOS_StatcAmt_Muskular, 200)
    Set(AB_HOS_StatcAmt_Misstar,  200)
    Set(AB_HOS_StatcAmt_Klevar,   200)
    Set(AB_HOS_StatcAmt_Kalmar,   200)
    Wait(30 * DT)
    Set(AB_HOS_StatcAmt_Eldstar,  0)
    Set(AB_HOS_StatcAmt_Mamar,    0)
    Set(AB_HOS_StatcAmt_Skolar,   0)
    Set(AB_HOS_StatcAmt_Muskular, 0)
    Set(AB_HOS_StatcAmt_Misstar,  0)
    Set(AB_HOS_StatcAmt_Klevar,   0)
    Set(AB_HOS_StatcAmt_Kalmar,   0)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_000B)
    Call(EnableNpcShadow, NPC_Eldstar, FALSE)
    Call(EnableNpcShadow, NPC_Mamar, FALSE)
    Call(EnableNpcShadow, NPC_Skolar, FALSE)
    Call(EnableNpcShadow, NPC_Muskular, FALSE)
    Call(EnableNpcShadow, NPC_Misstar, FALSE)
    Call(EnableNpcShadow, NPC_Klevar, FALSE)
    Call(EnableNpcShadow, NPC_Kalmar, FALSE)
    Call(FullyRestoreHPandFP)
    Set(AB_HOS_StatcAmt_Eldstar,  100)
    Set(AB_HOS_StatcAmt_Mamar,    100)
    Set(AB_HOS_StatcAmt_Skolar,   100)
    Set(AB_HOS_StatcAmt_Muskular, 100)
    Set(AB_HOS_StatcAmt_Misstar,  100)
    Set(AB_HOS_StatcAmt_Klevar,   100)
    Set(AB_HOS_StatcAmt_Kalmar,   100)
    SetF(MV_AlphaAmt_Eldstar, Float(40.0))
    SetF(MV_AlphaAmt_Others, Float(40.0))
    Loop(20 * DT)
        AddF(MV_AlphaAmt_Eldstar, Float(-6.0 / DT))
        AddF(MV_AlphaAmt_Others, Float(-6.0 / DT))
        Wait(1)
    EndLoop
#if VERSION_PAL
    SetF(MapVar(0), Float(-80.0))
    SetF(MapVar(1), Float(-80.0))
#endif
    Set(MF_SpiritsGone, TRUE)
    Set(AB_HOS_StatcAmt_Eldstar,  0)
    Set(AB_HOS_StatcAmt_Mamar,    0)
    Set(AB_HOS_StatcAmt_Skolar,   0)
    Set(AB_HOS_StatcAmt_Muskular, 0)
    Set(AB_HOS_StatcAmt_Misstar,  0)
    Set(AB_HOS_StatcAmt_Klevar,   0)
    Set(AB_HOS_StatcAmt_Kalmar,   0)
    Call(EnableModel, MODEL_1, FALSE)
    Call(EnableModel, MODEL_2, FALSE)
    Call(EnableModel, MODEL_3, FALSE)
    Call(EnableModel, MODEL_4, FALSE)
    Call(EnableModel, MODEL_5, FALSE)
    Call(EnableModel, MODEL_6, FALSE)
    Call(EnableModel, MODEL_7, FALSE)
    Call(DisablePartnerAI, 0)
    Wait(10 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(N(SwitchToPartner), PARTNER_GOOMBARIO)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Add(LVar2, 30)
    Call(SetNpcSpeed, NPC_PARTNER, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_000C)
    Call(EnablePartnerAI)
    Thread
        Set(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
        Call(ResetCam, CAM_DEFAULT, Float(1.5 / DT))
    EndThread
    Call(FadeOutMusic, 0, 3000 * DT)
    Wait(10 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Eldstar) = {
    Exec(N(EVS_Scene_StarSpiritsPlea))
    Return
    End
};

EvtScript N(EVS_NpcAux_Eldstar) = {
    Set(AB_HOS_StatcAmt_Eldstar,  0)
    Set(AB_HOS_StatcAmt_Mamar,    0)
    Set(AB_HOS_StatcAmt_Skolar,   0)
    Set(AB_HOS_StatcAmt_Muskular, 0)
    Set(AB_HOS_StatcAmt_Misstar,  0)
    Set(AB_HOS_StatcAmt_Klevar,   0)
    Set(AB_HOS_StatcAmt_Kalmar,   0)
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Eldstar, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Eldstar, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Eldstar, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Mamar, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Mamar, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Mamar, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Skolar, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Skolar, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Skolar, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Muskular, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Muskular, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Muskular, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Misstar, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Misstar, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Misstar, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Klevar, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Klevar, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Klevar, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            IfEq(AB_HOS_StatcAmt_Kalmar, 0)
                Call(RandInt, 45, LVar1)
                Add(LVar1, 105)
                Set(AB_HOS_StatcAmt_Kalmar, 200)
                Wait(10)
                Set(AB_HOS_StatcAmt_Kalmar, 0)
                Wait(LVar1)
            Else
                Wait(1)
            EndIf
        EndLoop
    EndThread
    Loop(0)
        SetF(LVar0, 0)
        SetF(LVar1, 0)
        Loop(20)
            AddF(LVar0, Float(4.0))
            AddF(LVar1, Float(4.0))
            SetF(LVar2, LVar0)
            AddF(LVar2, MV_AlphaAmt_Eldstar)
            SetF(LVar3, LVar1)
            AddF(LVar3, MV_AlphaAmt_Others)
            IfLt(LVar2, 0)
                SetF(LVar2, Float(0.0))
            EndIf
            IfLt(LVar3, 0)
                SetF(LVar3, Float(0.0))
            EndIf
            Call(SetNpcImgFXParams, NPC_Eldstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Eldstar,  1, LVar2)
            Call(SetNpcImgFXParams, NPC_Mamar,    IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Mamar,    1, LVar3)
            Call(SetNpcImgFXParams, NPC_Skolar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Skolar,   1, LVar3)
            Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Muskular, 1, LVar3)
            Call(SetNpcImgFXParams, NPC_Misstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Misstar,  1, LVar3)
            Call(SetNpcImgFXParams, NPC_Klevar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Klevar,   1, LVar3)
            Call(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Kalmar,   1, LVar3)
            Wait(1)
        EndLoop
        Loop(20)
            AddF(LVar0, Float(-4.0))
            AddF(LVar1, Float(-4.0))
            SetF(LVar2, LVar0)
            AddF(LVar2, MV_AlphaAmt_Eldstar)
            SetF(LVar3, LVar1)
            AddF(LVar3, MV_AlphaAmt_Others)
            IfLt(LVar2, 0)
                SetF(LVar2, Float(0.0))
            EndIf
            IfLt(LVar3, 0)
                SetF(LVar3, Float(0.0))
            EndIf
            Call(SetNpcImgFXParams, NPC_Eldstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Eldstar,  1, LVar2)
            Call(SetNpcImgFXParams, NPC_Mamar,    IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Mamar,    1, LVar3)
            Call(SetNpcImgFXParams, NPC_Skolar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Skolar,   1, LVar3)
            Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Muskular, 1, LVar3)
            Call(SetNpcImgFXParams, NPC_Misstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Misstar,  1, LVar3)
            Call(SetNpcImgFXParams, NPC_Klevar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Klevar,   1, LVar3)
            Call(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Kalmar,   1, LVar3)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Eldstar)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    IfLt(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
        Exec(N(EVS_MuteMusicOnPlayerApproach))
    EndIf
    IfGe(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
        Call(SetNpcPos, NPC_Eldstar,  NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Mamar,    NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Skolar,   NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Muskular, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Misstar,  NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Klevar,   NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Kalmar,   NPC_DISPOSE_LOCATION)
        Return
    EndIf
    Call(EnableNpcShadow, NPC_Mamar,    FALSE)
    Call(EnableNpcShadow, NPC_Skolar,   FALSE)
    Call(EnableNpcShadow, NPC_Muskular, FALSE)
    Call(EnableNpcShadow, NPC_Misstar,  FALSE)
    Call(EnableNpcShadow, NPC_Klevar,   FALSE)
    Call(EnableNpcShadow, NPC_Kalmar,   FALSE)
    Set(MV_AlphaAmt_Eldstar, 40)
    Set(MV_AlphaAmt_Others, -80)
    Return
    End
};

NpcData N(NpcData_StarSpirits)[] = {
    {
        .id = NPC_Eldstar,
        .pos = { -30.0f, 260.0f, -170.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .tattle = MSG_NpcTattle_Eldstar,
    },
    {
        .id = NPC_Mamar,
        .pos = { 100.0f, 260.0f, -215.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
    },
    {
        .id = NPC_Skolar,
        .pos = { -145.0f, 260.0f, -225.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
    {
        .id = NPC_Muskular,
        .pos = { 20.0f, 260.0f, -45.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_Misstar,
        .pos = { -155.0f, 260.0f, -125.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
    },
    {
        .id = NPC_Klevar,
        .pos = { 90.0f, 260.0f, -110.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
    },
    {
        .id = NPC_Kalmar,
        .pos = { -75.0f, 260.0f, -290.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_StarSpirits)),
    {}
};
