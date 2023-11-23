#include "kkj_14.h"

#include "world/common/atomic/TexturePan.inc.c"
#include "../common/RestoreFromPeachState.inc.c"

API_CALLABLE(N(EnableParasol)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_HAS_PARASOL;
    return ApiStatus_DONE2;
}

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

EvtScript N(EVS_EndPeachChapter7) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("pra_01"), pra_01_ENTRY_4, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
};

EvtScript N(EVS_ExitDoor_GrandHall) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(AF_KKJ_13, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_14_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_o4)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_IF_EQ(GB_StoryProgress, STORY_INTRO)
        EVT_CALL(GotoMap, EVT_PTR("kkj_01"), kkj_01_ENTRY_4)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_4)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_Balcony) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(AF_KKJ_13, FALSE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_DOOR)
    EVT_SET(LVar0, kkj_14_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o83)
    EVT_SET(LVar3, MODEL_o85)
    EVT_SET(LVar4, MODEL_o84)
    EVT_SET(LVar5, MODEL_o86)
    EVT_EXEC(ExitSplitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_26"), kkj_26_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_SecretPassage) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(AF_KKJ_13, FALSE)
    EVT_CALL(UseExitHeading, 60, kkj_14_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_KKJ14_SkipSecretPassage, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kkj_27"), kkj_27_ENTRY_0)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kkj_15"), kkj_15_ENTRY_1)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowMessage_CantOpen) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_DoesntOpen, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_INTRO)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_Balcony)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_SecretPassage)), TRIGGER_FLOOR_ABOVE, COLLIDER_o119, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_GrandHall)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_14_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_SET(LVar2, MODEL_o4)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_DOOR)
            EVT_SET(LVar2, MODEL_o83)
            EVT_SET(LVar3, MODEL_o85)
            EVT_SET(LVar4, MODEL_o84)
            EVT_SET(LVar5, MODEL_o86)
            EVT_EXEC_WAIT(EnterSplitDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kkj_14_ENTRY_3)
            EVT_EXEC(N(EVS_Scene_Chapter0))
        EVT_CASE_EQ(kkj_14_ENTRY_4)
            EVT_EXEC(N(EVS_Scene_Chapter1))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_5)
            EVT_EXEC(N(EVS_Scene_Chapter2))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_6)
            EVT_EXEC(N(EVS_Scene_Chapter3))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_7)
            EVT_EXEC(N(EVS_Scene_Chapter4))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_8)
            EVT_EXEC(N(EVS_Scene_Chapter5))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_9)
            EVT_EXEC(N(EVS_Scene_Chapter6))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_14_ENTRY_A)
            EVT_EXEC(N(EVS_Scene_Chapter7))
        EVT_CASE_EQ(kkj_14_ENTRY_B)
            EVT_EXEC(N(EVS_Scene_TossedBackInRoom))
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_GE(LVar0, kkj_14_ENTRY_3)
        EVT_IF_NE(LVar0, kkj_14_ENTRY_B)
            EVT_SET(GF_KKJ14_RevealedButton, FALSE)
            EVT_SET(GF_KKJ14_OpenedPassage, FALSE)
        EVT_END_IF
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(kkj_14_ENTRY_3)
                EVT_SET(GB_StoryProgress, STORY_CH0_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, FALSE)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter0NPCs)))
            EVT_CASE_EQ(kkj_14_ENTRY_4)
                EVT_SET(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, FALSE)
            EVT_CASE_EQ(kkj_14_ENTRY_5)
                EVT_SET(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, FALSE)
                EVT_SET(AF_KKJ_06, FALSE)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter2NPCs)))
            EVT_CASE_EQ(kkj_14_ENTRY_6)
                EVT_SET(GB_StoryProgress, STORY_CH3_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, FALSE)
            EVT_CASE_EQ(kkj_14_ENTRY_7)
                EVT_SET(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, TRUE)
            EVT_CASE_EQ(kkj_14_ENTRY_8)
                EVT_SET(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, TRUE)
            EVT_CASE_EQ(kkj_14_ENTRY_9)
                EVT_CALL(N(EnableParasol))
                EVT_SET(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
                EVT_SET(GB_KKJ_CaughtCount, 0)
                EVT_SET(GF_KKJ14_SkipSecretPassage, TRUE)
            EVT_CASE_EQ(kkj_14_ENTRY_A)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter7NPCs)))
            EVT_CASE_EQ(kkj_14_ENTRY_B)
                EVT_ADD(GB_KKJ_CaughtCount, 1)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(TossBackNPCs)))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupInteractables))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kkj_14_ENTRY_5)
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(SetTexPanner, MODEL_o154, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetModelCustomGfx, MODEL_o154, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfx, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_candle_lights)), NULL)
    EVT_RETURN
    EVT_END
};
