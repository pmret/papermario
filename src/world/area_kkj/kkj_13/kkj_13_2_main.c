#include "kkj_13.h"

#include "world/common/atomic/TexturePan.inc.c"

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

EvtScript N(EVS_ExitDoors_kkj_12_1) = EVT_EXIT_DOUBLE_DOOR(kkj_13_ENTRY_0, "kkj_12", kkj_12_ENTRY_1,
    COLLIDER_deilit1, MODEL_door1, MODEL_door2);
EvtScript N(EVS_ExitDoors_kkj_22_0) = EVT_EXIT_DOUBLE_DOOR(kkj_13_ENTRY_1, "kkj_22", kkj_22_ENTRY_0,
    COLLIDER_deilit2, MODEL_door4, MODEL_door3);

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_13_ENTRY_0)
            Set(LVar2, MODEL_door1)
            Set(LVar3, MODEL_door2)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_Scene_MarioConfrontsBowser))
        CaseEq(kkj_13_ENTRY_1)
            Set(LVar2, MODEL_door4)
            Set(LVar3, MODEL_door3)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_13_ENTRY_2)
            Exec(N(EVS_Scene_BowserAttacks))
        CaseEq(kkj_13_ENTRY_3)
            Exec(N(EVS_Scene_PeachCaptured))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_13)
    SetUP_CAMERA_DEFAULT()
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(MakeNpcs, FALSE, Ref(N(IntroNPCs)))
    EndIf
    IfGe(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        Call(MakeNpcs, FALSE, Ref(N(ChapterNPCs)))
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_13_ENTRY_2)
        Call(EnableGroup, MODEL_g152, FALSE)
        Call(EnableGroup, MODEL_g154, FALSE)
        Call(EnableGroup, MODEL_g153, FALSE)
    Else
        Call(EnableGroup, MODEL_g133, FALSE)
        Call(EnableGroup, MODEL_g147, FALSE)
        Call(EnableGroup, MODEL_g153, FALSE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        IfEq(GF_KKJ13_BowserTaunts, FALSE)
            Call(EnableGroup, MODEL_g153, TRUE)
            Call(TranslateGroup, MODEL_g153, 780, 90, 0)
            Call(RotateGroup, MODEL_g153, -60, 0, 1, 0)
        EndIf
    EndIf
    Call(SetTexPanner, MODEL_o685, 0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetModelCustomGfx, MODEL_o685, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfx, CUSTOM_GFX_0, Ref(N(setup_gfx_candle_lights)), NULL)
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_12_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_22_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
