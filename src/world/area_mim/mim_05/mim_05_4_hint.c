#include "mim_05.h"

EvtScript N(EVS_FlickerTexPanner) = {
    EVT_USE_ARRAY(LVar0)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarA, ArrayVar(0))
        EVT_CASE_EQ(1)
            EVT_SET(LVarA, ArrayVar(1))
        EVT_CASE_EQ(2)
            EVT_SET(LVarA, ArrayVar(2))
        EVT_CASE_EQ(4)
            EVT_SET(LVarA, ArrayVar(4))
        EVT_CASE_EQ(5)
            EVT_SET(LVarA, ArrayVar(5))
    EVT_END_SWITCH
    EVT_IF_EQ(LVarA, 1)
        EVT_CALL(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, -300, 0, -10)
        EVT_CALL(SetTexPanOffset, LVar1, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(SetTexPanOffset, LVar1, 0, 0, -0x8000)
    EVT_END_IF
    EVT_SET(LVar9, 1)
    EVT_SUB(LVar9, LVarA)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(ArrayVar(0), LVar9)
        EVT_CASE_EQ(1)
            EVT_SET(ArrayVar(1), LVar9)
        EVT_CASE_EQ(2)
            EVT_SET(ArrayVar(2), LVar9)
        EVT_CASE_EQ(4)
            EVT_SET(ArrayVar(4), LVar9)
        EVT_CASE_EQ(5)
            EVT_SET(ArrayVar(5), LVar9)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateMushroomSet) = {
    EVT_CALL(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, -300, 0, -10)
    EVT_EXEC(N(EVS_FlickerTexPanner))
    EVT_WAIT(30)
    EVT_LOOP(4)
        EVT_EXEC(N(EVS_FlickerTexPanner))
        EVT_WAIT(3)
        EVT_EXEC(N(EVS_FlickerTexPanner))
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_FlickerTexPanner))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectMushrooms_West) = {
    EVT_SET(LVar1, TEX_PANNER_2)
    EVT_EXEC(N(EVS_AnimateMushroomSet))
    EVT_WAIT(10)
    EVT_SET(LVar1, TEX_PANNER_4)
    EVT_EXEC(N(EVS_AnimateMushroomSet))
    EVT_WAIT(10)
    EVT_SET(LVar1, TEX_PANNER_5)
    EVT_EXEC(N(EVS_AnimateMushroomSet))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectMushrooms_South) = {
    EVT_CALL(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, -20, 0, 300)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(20)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectMushrooms_North) = {
    EVT_CALL(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, 20, 0, -300)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(20)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectMushrooms_East) = {
    EVT_CALL(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, 300, 0, 10)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(50)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupExitHint) = {
    EVT_CALL(SetTexPanner, MODEL_o402, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o510, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o511, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o403, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o500, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o501, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o404, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o498, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o499, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o505, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o509, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o507, TEX_PANNER_4)
    EVT_CALL(SetTexPanner, MODEL_o508, TEX_PANNER_4)
    EVT_CALL(SetTexPanner, MODEL_o405, TEX_PANNER_5)
    EVT_CALL(SetTexPanner, MODEL_o502, TEX_PANNER_5)
    EVT_CALL(SetTexPanner, MODEL_o503, TEX_PANNER_5)
    EVT_CALL(SetTexPanner, MODEL_o504, TEX_PANNER_5)
    EVT_MALLOC_ARRAY(6, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), 0)
    EVT_SET(ArrayVar(1), 0)
    EVT_SET(ArrayVar(2), 0)
    EVT_SET(ArrayVar(4), 0)
    EVT_SET(ArrayVar(5), 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectMushrooms_South)), TRIGGER_WALL_PRESS_A, COLLIDER_o402, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectMushrooms_North)), TRIGGER_WALL_PRESS_A, COLLIDER_o403, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectMushrooms_West)),  TRIGGER_WALL_PRESS_A, COLLIDER_o405, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectMushrooms_East)),  TRIGGER_WALL_PRESS_A, COLLIDER_o404, 1, 0)
    EVT_RETURN
    EVT_END
};
