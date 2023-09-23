#include "osr_02.h"
#include "effects.h"

API_CALLABLE(N(SetAvailableDisguise)) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoor_kpa_121_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_SET(LVar0, osr_02_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_o570)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kpa_121"), kpa_121_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kkj_10_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, osr_02_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tt2)
    EVT_SET(LVar2, MODEL_d2)
    EVT_SET(LVar3, MODEL_d1)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_10"), kkj_10_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KeepPeachFromBowsersCastle) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 1)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0180)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_KeepPeachFromBowsersCastle)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_121_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_02_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
            EVT_SET(LVar2, MODEL_o570)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(osr_02_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_d2)
            EVT_SET(LVar3, MODEL_d1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(osr_02_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_ReturnStarRod))
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_IF_GT(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        EVT_SET(GF_MAP_PeachsCastle, TRUE)
    EVT_END_IF
    EVT_CALL(SetSpriteShading, SHADING_OSR_02)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_CALL(N(SetAvailableDisguise), PEACH_DISGUISE_CLUBBA)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(PeachNPCs)))
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_02_ENTRY_2)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_KKJ25_Defeated_Bowser, FALSE)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(-269.16895), EVT_FLOAT(50.0), EVT_FLOAT(100.22), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(-2.6025392), EVT_FLOAT(50.0), EVT_FLOAT(161.583), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(182.146), EVT_FLOAT(50.0), EVT_FLOAT(158.033), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(346.938), EVT_FLOAT(50.0), EVT_FLOAT(31.861), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(291.045), EVT_FLOAT(86.206), EVT_FLOAT(-191.08205), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(-105.39165), EVT_FLOAT(70.0), EVT_FLOAT(-203.115235), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(-52.5), EVT_FLOAT(70.0), EVT_FLOAT(-233.73735), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(52.5), EVT_FLOAT(70.0), EVT_FLOAT(-233.73735), 1, LVar0)
        EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_PINK, EVT_FLOAT(108.229), EVT_FLOAT(70.0), EVT_FLOAT(-200.6), 1, LVar0)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g116, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        EVT_SET(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
