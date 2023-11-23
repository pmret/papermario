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
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("mac_04"), mac_04_ENTRY_5, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
};

EvtScript N(EVS_UpdateClockPendulum) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, -8, 8, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 8, -8, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kkj_18_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_o9)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_IF_EQ(AB_KKJ_CompletedBakeStep, CAKE_TYPE_NONE)
        EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_6)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kkj_19"), kkj_19_ENTRY_0)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_NE(AF_KKJ_FinishedBakingCake, FALSE)
        EVT_CALL(SetPlayerPos, -227, 0, -35)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -227, 0, -35)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o9, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerPos, -187, 0, -35)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -187, 0, -35)
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_SET(LVar2, MODEL_o9)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC(N(EVS_UpdateClockPendulum))
    EVT_CALL(SetTexPanner, MODEL_o56, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetModelCustomGfx, MODEL_o56, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfx, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_candle_lights)), NULL)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits);
