#include "trd_05.h"
#include "effects.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_KoopaBros_SetTrap);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(SetMapChangeFadeRate)) {
    set_map_change_fade_rate(5);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_trd_04_1) = EVT_EXIT_DOUBLE_DOOR(trd_05_ENTRY_0, "trd_04", trd_04_ENTRY_1, COLLIDER_ttw, MODEL_doa2, MODEL_doa1);
EvtScript N(EVS_ExitDoors_trd_00_2) = EVT_EXIT_DOUBLE_DOOR(trd_05_ENTRY_1, "trd_00", trd_00_ENTRY_2, COLLIDER_ttse, MODEL_doa4, MODEL_doa6);
EvtScript N(EVS_ExitWalk_trd_00_3) = EVT_EXIT_WALK(60, trd_05_ENTRY_2, "trd_00", trd_00_ENTRY_3);
EvtScript N(EVS_ExitDoors_trd_04_3) = EVT_EXIT_DOUBLE_DOOR(trd_05_ENTRY_3, "trd_04", trd_04_ENTRY_3, COLLIDER_ttw2, MODEL_doa7, MODEL_doa8);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_04_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_00_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_00_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_04_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_05_ENTRY_0)
            EVT_SET(LVar2, MODEL_doa2)
            EVT_SET(LVar3, MODEL_doa1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_05_ENTRY_1)
            EVT_SET(LVar2, MODEL_doa4)
            EVT_SET(LVar3, MODEL_doa6)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_05_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(trd_05_ENTRY_3)
            EVT_SET(LVar2, MODEL_doa7)
            EVT_SET(LVar3, MODEL_doa8)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 300.0f, 0.0f, 0.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BombWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 29, 0, 1, 10, 30)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_VISIBLE)
    EVT_LOOP(10)
        EVT_CALL(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_VISIBLE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_TRD05_BombedWall, TRUE)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_suimen, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
        EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        EVT_ADD(LVar0, 100)
        EVT_SUB(LVar1, 100)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_TRD05_BombedWall, FALSE)
        EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BombWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_CALL(EnableModel, MODEL_o95, FALSE)
    EVT_CALL(EnableModel, MODEL_o96, FALSE)
    EVT_CALL(SetGroupVisibility, MODEL_kesu, MODEL_GROUP_HIDDEN)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPA_BROS_SET_TRAP)
        EVT_WAIT(10)
        EVT_CALL(N(SetMapChangeFadeRate))
        EVT_EXEC(N(EVS_KoopaBros_SetTrap))
    EVT_ELSE
        EVT_EXEC(N(EVS_EnterMap))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
