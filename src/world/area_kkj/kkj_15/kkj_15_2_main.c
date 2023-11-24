#include "kkj_15.h"

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

EvtScript N(EVS_EndPeachChapter0) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_10"), kmr_10_ENTRY_0, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
}; //@bug script not properly terminated

EvtScript N(EVS_EndPeachChapter1) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("trd_00"), trd_00_ENTRY_5, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
}; //@bug script not properly terminated

EvtScript N(EVS_EndPeachChapter3) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("arn_07"), arn_07_ENTRY_3, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoor_kkj_11_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kkj_15_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o2)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_11_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_15_ENTRY_0)
            EVT_SET(LVar2, MODEL_o2)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_15_ENTRY_1)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
                    EVT_EXEC(N(EVS_EnterRotatingWall))
                    EVT_EXEC(N(EVS_SetupChapter1))
                EVT_CASE_EQ(STORY_CH2_BEGAN_PEACH_MISSION)
                    EVT_EXEC(N(EVS_EnterRotatingWall))
                    EVT_EXEC(N(EVS_SetupChapter2))
                EVT_CASE_EQ(STORY_CH3_BEGAN_PEACH_MISSION)
                    EVT_EXEC(N(EVS_Scene_Chapter3))
                EVT_CASE_DEFAULT
                    EVT_EXEC(N(EVS_EnterRotatingWall))
                    EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_SWITCH
        EVT_CASE_EQ(kkj_15_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_Chapter0_BowserAndKammy))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_15_ENTRY_2)
            EVT_SET(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
    EVT_END_SWITCH
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter0NPCs)))
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter1NPCs)))
        EVT_CASE_EQ(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter3NPCs)))
    EVT_END_SWITCH
    EVT_IF_NE(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        EVT_CALL(EnableModel, MODEL_o76, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o76, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g25, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetTexPanner, MODEL_o151, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetModelCustomGfx, MODEL_o151, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfx, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_candle_lights)), NULL)
    EVT_CALL(SetTexPanner, MODEL_o152, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetModelCustomGfx, MODEL_o152, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfx, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_candle_lights)), NULL)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_15_ENTRY_1)
        EVT_IF_EQ(GB_StoryProgress, STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(StopSound, SOUND_KKJ_ROTATING_WALL)
        EVT_ELSE
            EVT_CALL(PlaySoundAt, SOUND_KKJ_ROTATING_WALL, SOUND_SPACE_DEFAULT, 50, 5, -200)
        EVT_END_IF
        EVT_WAIT(10)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
