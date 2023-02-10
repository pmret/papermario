#include "nok_15.h"
#include "effects.h"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_nok_14_1) = EVT_EXIT_WALK_NOK(60, nok_15_ENTRY_0, "nok_14", nok_14_ENTRY_1);
EvtScript N(EVS_ExitWalk_trd_00_0) = EVT_EXIT_WALK_NOK(60, nok_15_ENTRY_1, "trd_00", trd_00_ENTRY_0);
EvtScript N(EVS_ExitWalk_trd_00_4) = EVT_EXIT_WALK_NOK(60, nok_15_ENTRY_2, "trd_00", trd_00_ENTRY_4);

BombTrigger N(BombPos_Wall) = {
    .pos = { -26.0f, 0.0f, -531.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 60, 61, 1, 10, 30)
    EVT_SET(GF_NOK15_BombedWall, TRUE)
    EVT_CALL(EnableModel, MODEL_bomb_ato, TRUE)
    EVT_CALL(EnableModel, MODEL_bomb_1, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_suimen1, TEX_PANNER_1)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LABEL(10)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SUB(LVar1, 400)
            EVT_ADD(LVar1, 1000)
            EVT_WAIT(1)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_kabemizu1, TEX_PANNER_2)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(20)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar1, LVar2)
        EVT_SUB(LVar0, 100)
        EVT_ADD(LVar1, 800)
        EVT_SUB(LVar2, 400)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_nok_15_4) = {
    EVT_CALL(GotoMap, EVT_PTR("nok_15"), nok_15_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_nok_15_3) = {
    EVT_CALL(GotoMap, EVT_PTR("nok_15"), nok_15_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_ExitPipe) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_00_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_SET(LVar0, nok_15_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_o680)
    EVT_SET(LVar2, EVT_PTR(N(EVS_GotoMap_nok_15_4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, nok_15_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_o679)
    EVT_SET(LVar2, EVT_PTR(N(EVS_GotoMap_nok_15_3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_IF_EQ(GF_NOK15_BombedWall, FALSE)
        EVT_CALL(EnableModel, MODEL_bomb_ato, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_bomb_1, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_LE(LVar0, nok_15_ENTRY_2)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(N(EVS_Pipe_EnterVertical))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
