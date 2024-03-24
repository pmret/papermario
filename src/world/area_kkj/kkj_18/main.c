#include "kkj_18.h"

#include "world/common/atomic/TexturePan.inc.c"
#include "../common/RestoreFromPeachState.inc.c"

Gfx N(setup_gfx_candle_lights)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetPrimColor(0, 0, 75, 31, 19, 255),
    gsDPSetEnvColor(255, 118, 77, 0),
    gsDPSetCombineMode(PM_CC_CANDLE_1, PM_CC_CANDLE_2),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

EvtScript N(EVS_EndPeachChapter4) = {
    Set(LVar0, GB_KKJ_LastPartner)
    Call(N(RestoreFromPeachState))
    Call(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    Call(GotoMapSpecial, Ref("mac_04"), mac_04_ENTRY_5, TRANSITION_END_PEACH_INTERLUDE)
    Wait(100)
};

EvtScript N(EVS_UpdateClockPendulum) = {
    Loop(0)
        Call(MakeLerp, -8, 8, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 8, -8, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_ExitDoor_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kkj_18_ENTRY_0)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_o9)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    IfEq(AB_KKJ_CompletedBakeStep, CAKE_TYPE_NONE)
        Call(GotoMap, Ref("kkj_11"), kkj_11_ENTRY_6)
    Else
        Call(GotoMap, Ref("kkj_19"), kkj_19_ENTRY_0)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(DisablePlayerInput, TRUE)
    IfNe(AF_KKJ_FinishedBakingCake, FALSE)
        Call(SetPlayerPos, -227, 0, -35)
        Call(SetNpcPos, NPC_PARTNER, -227, 0, -35)
        Wait(30)
        Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
        Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o9, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetPlayerPos, -187, 0, -35)
        Call(SetNpcPos, NPC_PARTNER, -187, 0, -35)
    EndIf
    Set(LVar0, 0)
    Set(LVar2, MODEL_o9)
    Set(LVar3, DOOR_SWING_OUT)
    ExecWait(EnterSingleDoor)
    Call(DisablePlayerInput, FALSE)
    BindTrigger(Ref(N(EVS_ExitDoor_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndIf
    Exec(N(EVS_UpdateClockPendulum))
    Call(SetTexPanner, MODEL_o56, TEX_PANNER_0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetModelCustomGfx, MODEL_o56, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfx, CUSTOM_GFX_0, Ref(N(setup_gfx_candle_lights)), NULL)
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};

MAP_RODATA_PAD(1, exits);
