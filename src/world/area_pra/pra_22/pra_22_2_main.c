#include "pra_22.h"
#include "sprite/player.h"

#include "world/common/todo/UnkFunc11.inc.c"

API_CALLABLE(N(PreventFalling)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z, hitDepth;

    playerStatus->pos.x = script->varTable[0];
    x = playerStatus->pos.x;
    y = playerStatus->pos.y + 10.0f;
    z = playerStatus->pos.z;
    hitDepth = 300.0f;
    npc_raycast_down_around(0, &x, &y, &z, &hitDepth, 270.0f, playerStatus->colliderDiameter);

    playerStatus->pos.x = x;
    playerStatus->pos.z = z;
    script->varTable[10] = FALSE;
    if (playerStatus->pos.y != y) {
        playerStatus->pos.y = 0.0f;
        script->varTable[3]++;
        if (script->varTable[3] >= 30) {
            // player may now fall
            script->varTable[10] = TRUE;
        }
    }
    return ApiStatus_DONE2;
}

s32 N(DoorModelsL)[] = { MODEL_o1001, -1 };
s32 N(DoorModelsR)[] = { MODEL_o1002, -1 };

EvtScript N(EVS_ExitDoors_pra_20_4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_22_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittssw)
    EVT_SET(LVar2, MODEL_o1085)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_20"), pra_20_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_37_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_22_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittsse)
    EVT_SET(LVar2, EVT_PTR(N(DoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(DoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_37"), pra_37_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_20_4)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_37_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsse, 1, 0)
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
        EVT_CASE_EQ(pra_22_ENTRY_0)
            EVT_SET(LVar2, MODEL_o1085)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(pra_22_ENTRY_1)
            EVT_SET(LVar2, EVT_PTR(N(DoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(DoorModelsR)))
            EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushRightStatue_Impl) = {
    EVT_LOOP(30)
        EVT_CALL(GetPartnerInUse, LVarA)
        EVT_IF_NE(LVarA, PARTNER_NONE)
            EVT_SET(LVar8, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(N(UnkFunc11), LVar9)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar8, -1)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPartnerInUse, LVarA)
    EVT_IF_NE(LVarA, PARTNER_NONE)
        EVT_SET(LVar8, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_GE(LVar6, LVar7)
            EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_ELSE
            EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_END_IF
        EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, LVar0)
        EVT_SET(LVar2, LVar7)
        EVT_SUB(LVar2, LVar6)
        EVT_ADD(LVar1, LVar2)
        EVT_CALL(MakeLerp, LVar0, LVar1, 100, EASING_LINEAR)
        EVT_SET(LVar3, 0)
        EVT_LOOP(0)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(PreventFalling))
            EVT_IF_EQ(LVarA, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarA, 1)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_TouchedLava)
            EVT_WAIT(15)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_WAIT(1)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_FALLING)
            EVT_WAIT(1)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar6, LVar7, 100, EASING_LINEAR)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1064, SOUND_80000010, SOUND_SPACE_MODE_0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1005, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o1006, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o1007, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o1008, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o1009, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1064)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_80000010)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushStatue) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, 337)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 50)
        EVT_SET(LVar8, 2)
    EVT_END_IF
    EVT_IF_GE(LVar0, 413)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, -50)
        EVT_SET(LVar8, 1)
    EVT_ELSE
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar9, COLLIDER_o1064)
    EVT_EXEC_WAIT(N(EVS_PushRightStatue_Impl))
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GB_StoryProgress, STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
        EVT_SET(GB_PRA_TwinStatueState, LVar8)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushStatue)), TRIGGER_WALL_PUSH, COLLIDER_o1064, 1, 0)
        EVT_SET(LVar0, 0)
    EVT_ELSE
        EVT_SWITCH(GB_PRA_TwinStatueState)
            EVT_CASE_EQ(0)
                EVT_SET(LVar0, -50)
            EVT_CASE_EQ(1)
                EVT_SET(LVar0, -50)
            EVT_CASE_EQ(2)
                EVT_SET(LVar0, 50)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ParentColliderToModel, COLLIDER_o1064, MODEL_o1005)
    EVT_CALL(TranslateModel, MODEL_o1005, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o1006, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o1007, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o1008, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o1009, LVar0, 0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o1064)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
