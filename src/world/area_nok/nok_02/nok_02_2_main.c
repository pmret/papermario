#include "nok_02.h"

#include "world/common/entity/Pipe.inc.c"

#define NAME_SUFFIX _Unused
#include "world/common/complete/GiveReward.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_ExitWalk_nok_01_1) = {
    EVT_CALL(UseExitHeading, 60, nok_02_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_01"), nok_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_nok_03_0) = {
    EVT_IF_EQ(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        EVT_SET(GF_KootFavor_LeftKoopaVillage, TRUE)
    EVT_END_IF
    EVT_CALL(UseExitHeading, 60, nok_02_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_03"), nok_03_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Flowers) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o312, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o460, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o461, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o462, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o454, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o455, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o456, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o457, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o458, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o459, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o314, TEX_PANNER_0)
    EVT_LABEL(10)
        EVT_LOOP(12)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(12)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0x4000, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(nok_02_ENTRY_2)
            EVT_IF_EQ(GF_NOK02_WarpPipe, FALSE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                EVT_WAIT(30)
                EVT_CALL(PlaySound, SOUND_GROW)
                EVT_SET(GF_NOK02_WarpPipe, TRUE)
                EVT_WAIT(30)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC_WAIT(N(EVS_Pipe_EnterVertical))
        EVT_CASE_EQ(nok_02_ENTRY_4)
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, nok_02_ENTRY_3)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
        EVT_EXEC_WAIT(N(EVS_MakeEntities))
        EVT_EXEC(N(EVS_TexPan_Flowers))
        EVT_EXEC(N(EVS_Scene_Epilogue))
        EVT_CALL(FadeInMusic, 0, SONG_KOOPA_VILLAGE, 0, 3000, 0, 127)
        EVT_WAIT(1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_NOK_0F, FALSE)
    EVT_SET(AF_NOK_10, FALSE)
    EVT_SET(AF_NOK_12, FALSE)
    EVT_SET(GF_NOK02_Bush1_KoopaLeaf, FALSE)
    EVT_SET(AF_NOK_13, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_SET(GF_NOK02_RecoveredShellA, TRUE)
        EVT_SET(GF_NOK02_RecoveredShellB, TRUE)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(CrisisNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NormalNPCs)))
    EVT_END_IF
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_TexPan_Flowers))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Setup_Bookshelf)), TRIGGER_WALL_PRESS_A, COLLIDER_o236, 1, 0)
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_SetupDemo))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
