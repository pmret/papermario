#include "mac_01.h"

EvtScript N(EVS_ExitWalk_mac_00_1) = EVT_EXIT_WALK(60, mac_01_ENTRY_0, "mac_00", mac_00_ENTRY_1);

EvtScript N(D_802469AC_80722C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, mac_01_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_StartedChapter1, FALSE)
        EVT_SET(GF_StartedChapter1, TRUE)
        EVT_CALL(FadeOutMusic, 0, 1500)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_1, TRANSITION_6)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("nok_11"), nok_11_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80246A70_8072F0)[] = {
    158, 159, -1 
};

s32 N(D_80246A7C_8072FC)[] = {
    161, 162, -1 
};

EvtScript N(D_80246A88_807308) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, 5)
    EVT_SET(LVar2, EVT_PTR(N(D_80246A70_8072F0)))
    EVT_SET(LVar3, EVT_PTR(N(D_80246A7C_8072FC)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH0_WAKE_UP, STORY_CH8_REACHED_PEACHS_CASTLE)
            EVT_CALL(GotoMap, EVT_PTR("osr_01"), osr_01_ENTRY_0)
        EVT_CASE_DEFAULT
            EVT_CALL(GotoMap, EVT_PTR("osr_00"), osr_00_ENTRY_0)
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_mac_02_2) = EVT_EXIT_WALK(60, mac_01_ENTRY_3, "mac_02", mac_02_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80246A88_807308)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitn, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_RETURN
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(D_802469AC_80722C)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_80259AD0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitf, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246C94_807514) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mac_01_ENTRY_2)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(RotateGroup, MODEL_east_gate, 80, 0, 1, 0)
            EVT_CALL(RotateGroup, MODEL_west_gate, 80, 0, -1, 0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC_WAIT(EnterWalk)
            EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, MODEL_east_gate, LVar0, 0, 1, 0)
                EVT_CALL(RotateGroup, MODEL_west_gate, LVar0, 0, -1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitn, SOUND_LARGE_DOOR_CLOSE, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(mac_01_ENTRY_4)
            EVT_EXEC(N(D_80261880_822100))
        EVT_CASE_EQ(mac_01_ENTRY_5)
            EVT_EXEC_WAIT(N(EVS_8025A004))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 90, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SET(AF_MAC_0E, FALSE)
    EVT_SET(AF_MAC_0F, FALSE)
    EVT_SET(AF_MAC_10, FALSE)
    EVT_SET(AF_MAC_11, FALSE)
    EVT_SET(AF_MAC_12, FALSE)
    EVT_SET(AF_MAC_13, FALSE)
    EVT_SET(AF_MAC_14, FALSE)
    EVT_SET(AF_MAC_15, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_EPILOGUE)
        EVT_EXEC(N(EVS_80248070))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_jutan1, FALSE)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(IntroNPCs)))
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup2)))
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup3)))
        EVT_CASE_EQ(STORY_CH1_DEFEATED_JR_TROOPA)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup4)))
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup5)))
        EVT_CASE_EQ(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup6)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup7)))
    EVT_END_SWITCH
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_8025A2F0))
    EVT_EXEC(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_80247D18))
    EVT_EXEC(N(EVS_SetupBulletinBoard))
    EVT_EXEC(N(EVS_80248428))
    EVT_EXEC(N(D_80246770_806FF0))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_CALL(UseAdvancedDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_EXEC(N(D_80246C94_807514))
    EVT_WAIT(1)
    EVT_CALL(EnableTexPanning, MODEL_hikari, TRUE)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LABEL(0)
            EVT_ADD(LVar0, -100)
            EVT_ADD(LVar1, -200)
            EVT_IF_LT(LVar0, 0)
                EVT_ADD(LVar0, 0x10000)
            EVT_END_IF
            EVT_IF_LT(LVar1, 0)
                EVT_ADD(LVar0, 0x10000)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX, LVar1, LVar1)
            EVT_WAIT(1)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_8024F27C)), TRIGGER_WALL_PRESS_A, COLLIDER_o335, 1, 0)
    EVT_EXEC(N(EVS_8025023C))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_RETURN
    EVT_END
};
