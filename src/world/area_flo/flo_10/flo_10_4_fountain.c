#include "flo_10.h"
#include "sprite/npc/Lily.h"
#include "sprite/player.h"

#include "world/common/complete/GiveReward.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_RaiseFountain) = {
    Call(MakeLerp, -50, 170, 385, EASING_LINEAR)
    Label(1)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g22, 0, LVar0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_GrowFountain) = {
    Call(MakeLerp, 0, 100, 90, EASING_QUADRATIC_IN)
    Label(1)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        SetF(LVar3, LVar0)
        DivF(LVar2, Float(333.0))
        DivF(LVar3, Float(100.0))
        AddF(LVar2, Float(0.703))
        Call(ScaleGroup, MODEL_g22, LVar2, LVar3, LVar2)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_TexPan_Rainbow) = {
    Call(EnableTexPanning, MODEL_o73, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_A)
        TEX_PAN_PARAMS_STEP( -150,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_EnableRainbow) = {
    Wait(60)
    Call(EnableModel, MODEL_o73, TRUE)
    Exec(N(EVS_TexPan_Rainbow))
    Return
    End
};

EvtScript N(EVS_RaiseLily) = {
    Wait(80)
    Call(EnableNpcShadow, NPC_Lily, FALSE)
    Call(GetNpcPos, NPC_Lily, LVar3, LVar4, LVar5)
    Call(MakeLerp, 10, 55, 108, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Set(LVar6, LVar4)
        Add(LVar6, LVar0)
        Add(LVar6, -10)
        Call(SetNpcPos, NPC_Lily, LVar3, LVar6, LVar5)
        Call(TranslateGroup, MODEL_g31, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_RaisePlayer) = {
    Call(DisablePlayerPhysics, TRUE)
    Wait(40)
    Call(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    Call(GetPlayerPos, LVar2, LVar0, LVar3)
    Call(MakeLerp, -50, 90, 60, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        DivF(LVar2, Float(1.2))
        DivF(LVar3, Float(1.2))
        Call(SetPlayerPos, LVar2, LVar0, LVar3)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 90, 270, 280, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetPlayerPos, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerPhysics, FALSE)
    Return
    End
};

EvtScript N(EVS_RaiseCamera) = {
    Wait(80)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.7))
    Call(SetCamPitch, CAM_DEFAULT, Float(25.0), Float(-22.0))
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_UnleashFountain) = {
    Call(DisablePartnerAI, 0)
    Exec(N(EVS_RaiseFountain))
    Exec(N(EVS_GrowFountain))
    Exec(N(EVS_EnableRainbow))
    Exec(N(EVS_RaiseLily))
    Exec(N(EVS_RaisePlayer))
    Exec(N(EVS_RaiseCamera))
    Return
    End
};

EvtScript N(EVS_LowerFountain) = {
    Call(MakeLerp, 170, 75, 150, EASING_LINEAR)
    Label(1)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g22, 0, LVar0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_ShrinkFountain) = {
    Call(MakeLerp, 100, 15, 150, EASING_QUADRATIC_IN)
    Label(1)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        SetF(LVar3, LVar0)
        DivF(LVar2, Float(333.0))
        DivF(LVar3, Float(100.0))
        AddF(LVar2, Float(0.703))
        Call(ScaleGroup, MODEL_g22, LVar2, LVar3, LVar2)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_FountainSlowing) = {
    Exec(N(EVS_LowerFountain))
    Exec(N(EVS_ShrinkFountain))
    Return
    End
};

EvtScript N(EVS_Scene_ReleaseFountain) = {
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnableGroup, MODEL_g22, TRUE)
    Call(TranslateGroup, MODEL_g22, 0, -50, 0)
    Call(ScaleGroup, MODEL_g22, 0, 0, 0)
    Call(EnableGroup, MODEL_g31, TRUE)
    ExecWait(N(EVS_UnleashFountain))
    Wait(20)
    Call(PlaySound, SOUND_LOOP_FLO_RELEASE_FOUNTAIN)
    Wait(360)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
    Call(SetPlayerJumpscale, Float(0.2))
    Call(PlayerJump1, -100, -10, -172, 75)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    ExecWait(N(EVS_FountainSlowing))
    Wait(60)
    Call(GotoMap, Ref("flo_24"), flo_24_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Scene_PostReleaseFountain) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, -100, -10, -172)
    Call(InterpPlayerYaw, 150, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Fallen)
    Call(SetNpcPos, NPC_PARTNER, -129, 9, -177)
    Call(EnablePartnerAI)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(EnableGroup, MODEL_water, TRUE)
    Call(EnableGroup, MODEL_g2, FALSE)
    Call(EnableGroup, MODEL_g12, FALSE)
    Call(EnableGroup, MODEL_g31, FALSE)
    Call(SetNpcPos, NPC_Lily, -57, -20, -105)
    Call(InterpNpcYaw, NPC_Lily, 90, 0)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, 450, Float(25.0), Float(-6.0))
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_GetUp)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10 * DT)
    ExecWait(N(EVS_PushFlowerSong))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Lily, ANIM_Lily_Talk, ANIM_Lily_Idle, 5, MSG_CH6_0082)
    Call(NpcFacePlayer, NPC_Lily, 1)
    Call(SpeakToPlayer, NPC_Lily, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0083)
    Call(SetNpcAnimation, NPC_Lily, ANIM_Lily_GiveItem)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Lily, ANIM_Lily_Idle)
    EVT_GIVE_KEY_REWARD(ITEM_MIRACLE_WATER)
    Call(SpeakToPlayer, NPC_Lily, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0084)
    Call(EndSpeech, NPC_Lily, ANIM_Lily_Talk, ANIM_Lily_Idle, 0)
    Call(SetNpcAnimation, NPC_Lily, ANIM_Lily_Idle)
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    ExecWait(N(EVS_PopSong))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupFountain) = {
    IfLt(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        Call(EnableGroup, MODEL_water, FALSE)
        Call(EnableGroup, MODEL_g12, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_water, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableGroup, MODEL_g2, FALSE)
        Call(EnableGroup, MODEL_g12, FALSE)
        Call(EnableGroup, MODEL_g31, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o83, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o86, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o87, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(EnableTexPanning, MODEL_o25, TRUE)
    Call(EnableTexPanning, MODEL_o40, TRUE)
    Call(EnableTexPanning, MODEL_o78, TRUE)
    Call(EnableTexPanning, MODEL_o77, TRUE)
    Call(EnableTexPanning, MODEL_o118, TRUE)
    Call(EnableTexPanning, MODEL_o119, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,-2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -100,   80,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(-1000, 2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_6)
        TEX_PAN_PARAMS_STEP(    0,-2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_8)
        TEX_PAN_PARAMS_STEP(    0,-1500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_9)
        TEX_PAN_PARAMS_STEP(    0,-1000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    IfGe(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        Exec(N(EVS_TexPan_Rainbow))
    EndIf
    Return
    End
};
