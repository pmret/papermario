#include "trd_03.h"
#include "effects.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_GreenKoopaBros);
extern EvtScript N(EVS_InitializePlatforms);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(GetHiddenDoorPushDirection)) {
    Bytecode* args = script->ptrReadPos;
    s32 pushDir = 0;

    if ((gCollisionStatus.pushingAgainstWall == COLLIDER_o84) && (gGameStatusPtr->stickX[0] < 0)) {
        pushDir = 1;
    }
    if ((gCollisionStatus.pushingAgainstWall == COLLIDER_o85) && (gGameStatusPtr->stickX[0] > 0)) {
        pushDir = 2;
    }

    evt_set_variable(script, *args++, pushDir);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetFrameCounter)) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->frameCounter);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_trd_02_1) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_0, "trd_02", trd_02_ENTRY_1, COLLIDER_ttw, MODEL_d1, MODEL_d2);
EvtScript N(EVS_ExitDoors_trd_04_0) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_1, "trd_04", trd_04_ENTRY_0, COLLIDER_tte, MODEL_d3, MODEL_d4);
EvtScript N(EVS_ExitDoors_trd_02_3) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_2, "trd_02", trd_02_ENTRY_3, COLLIDER_ttwo, MODEL_o33, MODEL_o34);
EvtScript N(EVS_ExitDoors_trd_04_2) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_3, "trd_04", trd_04_ENTRY_2, COLLIDER_tteo, MODEL_o31, MODEL_o32);
EvtScript N(EVS_ExitDoors_trd_02_4) = EVT_EXIT_WALK(40, trd_03_ENTRY_4, "trd_02", trd_02_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_04_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttwo, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_04_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tteo, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_02_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_03_ENTRY_0)
            EVT_SET(LVar2, MODEL_d1)
            EVT_SET(LVar3, MODEL_d2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_03_ENTRY_1)
            EVT_SET(LVar2, MODEL_d3)
            EVT_SET(LVar3, MODEL_d4)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_03_ENTRY_2)
            EVT_SET(LVar2, MODEL_o33)
            EVT_SET(LVar3, MODEL_o34)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_03_ENTRY_3)
            EVT_SET(LVar2, MODEL_o31)
            EVT_SET(LVar3, MODEL_o32)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_03_ENTRY_4)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_MiddleCell) = {
    .pos = { -160.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

BombTrigger N(BombPos_RightCell) = {
    .pos = { 360.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BombWall_MiddleCell) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 40, 10, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_nk2, TRUE)
    EVT_LOOP(10)
        EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_VISIBLE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_TRD03_BombedCenterCell, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BombWall_RightCell) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 43, 10, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_nk3, TRUE)
    EVT_LOOP(10)
        EVT_CALL(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_VISIBLE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_TRD03_BombedRightCell, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HiddenDoor) = {
    EVT_SET(LVarB, 0)
    EVT_SETF(LVarC, EVT_FLOAT(0.0))
    EVT_SET(LVarD, 0)
    EVT_SET(LVarE, 0)
    EVT_CALL(CloneModel, MODEL_rou2, CLONED_MODEL(0))
    EVT_CALL(EnableModel, CLONED_MODEL(0), FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o84, CLONED_MODEL(0))
    EVT_CALL(CloneModel, MODEL_rou2, CLONED_MODEL(1))
    EVT_CALL(EnableModel, CLONED_MODEL(1), FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o85, CLONED_MODEL(1))
    EVT_LABEL(0)
        EVT_IF_EQ(LVarD, 0)
            EVT_CALL(N(GetHiddenDoorPushDirection), LVar0)
            EVT_SWITCH(LVar0)
                // pushing left on COLLIDER_o84
                EVT_CASE_EQ(1)
                    EVT_CALL(N(GetFrameCounter), LVar1)
                    EVT_SUB(LVar1, LVarA)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_ADD(LVarB, 1)
                        EVT_SUBF(LVarC, EVT_FLOAT(0.1))
                    EVT_ELSE
                        EVT_SET(LVarB, 0)
                    EVT_END_IF
                    EVT_IF_GT(LVarB, 15)
                        EVT_SET(LVarB, 0)
                        EVT_SET(LVarD, 8)
                    EVT_END_IF
                    EVT_IF_LT(LVarC, -3)
                        EVT_SET(LVarD, 8)
                    EVT_END_IF
                // pushing right on COLLIDER_o85
                EVT_CASE_EQ(2)
                    EVT_SET(LVarD, -8)
                // not pushing
                EVT_CASE_DEFAULT
                    EVT_SET(LVarB, 0)
                    EVT_IF_LT(LVarC, 0)
                        EVT_ADDF(LVarC, EVT_FLOAT(0.2))
                        EVT_IF_GT(LVarC, 0)
                            EVT_SETF(LVarC, EVT_FLOAT(0.0))
                        EVT_END_IF
                    EVT_ELSE
                        EVT_SUBF(LVarC, EVT_FLOAT(0.2))
                        EVT_IF_LT(LVarC, 0)
                            EVT_SETF(LVarC, EVT_FLOAT(0.0))
                        EVT_END_IF
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o84, 0x7FFFFFFF)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o85, 0x7FFFFFFF)
            EVT_CALL(TranslateModel, CLONED_MODEL(0), LVarC, 0, 0)
            EVT_CALL(TranslateModel, CLONED_MODEL(1), LVarC, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o84)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o85)
        EVT_ELSE
            EVT_SETF(LVarC, EVT_FLOAT(0.0))
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o84, 0x7FFFFFFF)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, 0x7FFFFFFF)
            EVT_IF_GT(LVarD, 0)
                EVT_SUB(LVarD, 1)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_SETF(LVar3, LVarD)
                EVT_MULF(LVar3, EVT_FLOAT(1.8))
                EVT_SUBF(LVar0, LVar3)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ELSE
                EVT_ADD(LVarD, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(GetFrameCounter), LVarA)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        EVT_EXEC(N(EVS_Scene_GreenKoopaBros))
    EVT_ELSE
        EVT_EXEC(N(EVS_EnterMap))
    EVT_END_IF
    EVT_IF_EQ(GF_TRD02_BombedWall, FALSE)
        EVT_CALL(EnableModel, MODEL_nk1, FALSE)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_ana1, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_TRD03_BombedCenterCell, FALSE)
        EVT_CALL(EnableModel, MODEL_nk2, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BombWall_MiddleCell)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_MiddleCell)), 1, 0)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_TRD03_BombedRightCell, FALSE)
        EVT_CALL(EnableModel, MODEL_nk3, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BombWall_RightCell)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_RightCell)), 1, 0)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit3, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        EVT_CALL(TranslateModel, MODEL_0ri, 0, 100, -1)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_InitializePlatforms))
    EVT_EXEC(N(EVS_HiddenDoor))
    EVT_RETURN
    EVT_END
};
