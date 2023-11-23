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
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_13_ENTRY_0)
            EVT_SET(LVar2, MODEL_door1)
            EVT_SET(LVar3, MODEL_door2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_Scene_MarioConfrontsBowser))
        EVT_CASE_EQ(kkj_13_ENTRY_1)
            EVT_SET(LVar2, MODEL_door4)
            EVT_SET(LVar3, MODEL_door3)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_13_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_BowserAttacks))
        EVT_CASE_EQ(kkj_13_ENTRY_3)
            EVT_EXEC(N(EVS_Scene_PeachCaptured))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_13)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GB_StoryProgress, STORY_INTRO)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(IntroNPCs)))
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(ChapterNPCs)))
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_13_ENTRY_2)
        EVT_CALL(EnableGroup, MODEL_g152, FALSE)
        EVT_CALL(EnableGroup, MODEL_g154, FALSE)
        EVT_CALL(EnableGroup, MODEL_g153, FALSE)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g133, FALSE)
        EVT_CALL(EnableGroup, MODEL_g147, FALSE)
        EVT_CALL(EnableGroup, MODEL_g153, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        EVT_IF_EQ(GF_KKJ13_BowserTaunts, FALSE)
            EVT_CALL(EnableGroup, MODEL_g153, TRUE)
            EVT_CALL(TranslateGroup, MODEL_g153, 780, 90, 0)
            EVT_CALL(RotateGroup, MODEL_g153, -60, 0, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetTexPanner, MODEL_o685, 0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetModelCustomGfx, MODEL_o685, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfx, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_candle_lights)), NULL)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_12_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_22_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
