#include "trd_04.h"
#include "effects.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_UnlockLowerRightDoors);
extern EvtScript N(EVS_UnlockUpperLeftDoors);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(NpcGroupBefore);
extern NpcGroupList N(NpcGroupAfter);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitDoors_trd_03_1) = EVT_EXIT_DOUBLE_DOOR(trd_04_ENTRY_0, "trd_03", trd_03_ENTRY_1,
    COLLIDER_ttw2, MODEL_o6, MODEL_o7);

EvtScript N(EVS_ExitDoors_trd_05_0) = EVT_EXIT_DOUBLE_DOOR(trd_04_ENTRY_1, "trd_05", trd_05_ENTRY_0,
    COLLIDER_tte2, MODEL_o9, MODEL_o8);

EvtScript N(EVS_ExitDoors_trd_03_3) = EVT_EXIT_DOUBLE_DOOR(trd_04_ENTRY_2, "trd_03", trd_03_ENTRY_3,
    COLLIDER_ttw3, MODEL_o13, MODEL_o12);

EvtScript N(EVS_ExitDoors_trd_05_3) = EVT_EXIT_DOUBLE_DOOR(trd_04_ENTRY_3, "trd_05", trd_05_ENTRY_3,
    COLLIDER_tte3, MODEL_o10, MODEL_o11);

EvtScript N(EVS_ExitWalk_trd_07_0) = EVT_EXIT_WALK(60, trd_04_ENTRY_4, "trd_07", trd_07_ENTRY_0);

EvtScript N(EVS_ExitDoors_trd_06_1) = EVT_EXIT_DOUBLE_DOOR(trd_04_ENTRY_5, "trd_06", trd_06_ENTRY_1,
    COLLIDER_tte, MODEL_o29, MODEL_o28);

s32 N(KeyList)[] = {
    ITEM_KOOPA_FORTRESS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_03_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    EVT_IF_EQ(GF_TRD04_UnlockedLowerDoor, FALSE)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockLowerRightDoors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_TRD04_UnlockedUpperDoor, FALSE)
        EVT_IF_EQ(GF_TRD04_UnlockedLowerDoor, TRUE)
            EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockUpperLeftDoors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList)), 0, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_03_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw3, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_05_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tte3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_06_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
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
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_04_ENTRY_0)
            EVT_SET(LVar2, MODEL_o6)
            EVT_SET(LVar3, MODEL_o7)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_04_ENTRY_1)
            EVT_SET(LVar2, MODEL_o9)
            EVT_SET(LVar3, MODEL_o8)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_04_ENTRY_2)
            EVT_SET(LVar2, MODEL_o13)
            EVT_SET(LVar3, MODEL_o12)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_04_ENTRY_3)
            EVT_SET(LVar2, MODEL_o10)
            EVT_SET(LVar3, MODEL_o11)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_04_ENTRY_4)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(trd_04_ENTRY_5)
            EVT_SET(LVar2, MODEL_o29)
            EVT_SET(LVar3, MODEL_o28)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_LowerStairs) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_SET(GB_StoryProgress, STORY_CH1_LOWERED_FIRST_STAIRS)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 320 * DT, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(EnableModel, MODEL_o6, FALSE)
    EVT_CALL(EnableModel, MODEL_o7, FALSE)
    EVT_CALL(EnableModel, MODEL_bero2, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(540.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -6)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -30, -60)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerPos, -185, 0, -36)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -163, 0, -12)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(PlaySound, SOUND_LOOP_TRD_04_LOWER_STAIRS)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_LOOP(5)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 150)
            EVT_PLAY_EFFECT(EFFECT_DUST, 0, LVar0, LVar1, LVar2, 40)
            EVT_CALL(RandInt, 20 * DT, LVar0)
            EVT_ADD(LVar0, 20 * DT)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(7)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(RandInt, 200, LVar4)
            EVT_SUB(LVar4, 100)
            EVT_CALL(RandInt, 100, LVar5)
            EVT_SUB(LVar5, 100)
            EVT_ADD(LVar1, LVar4)
            EVT_ADD(LVar2, 200)
            EVT_ADD(LVar3, LVar5)
            EVT_PLAY_EFFECT(EFFECT_SHATTERING_STONES, 0, LVar1, LVar2, LVar3)
            EVT_CALL(RandInt, 30 * DT, LVar0)
            EVT_ADD(LVar0, 30 * DT)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(15 * DT)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(12 * DT)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(18 * DT)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(29 * DT)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_WAIT(13 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_WAIT(15 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_WAIT(17 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_WAIT(18 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_WAIT(17 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(MakeLerp, 187, 0, 300 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_k_sokumen, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_k_dan, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_k_kusari, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UpdateColliderTransform, COLLIDER_o86)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o87)
    EVT_CALL(StopSound, SOUND_LOOP_TRD_04_LOWER_STAIRS)
    EVT_CALL(PlaySound, SOUND_TRD_04_STAIRS_LOWERED)
    EVT_WAIT(50 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -169, 130)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -6)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnableModel, MODEL_o6, TRUE)
    EVT_CALL(EnableModel, MODEL_o7, TRUE)
    EVT_CALL(EnableModel, MODEL_bero2, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
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
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(SetRenderMode, MODEL_suimen, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_LOWERED_FIRST_STAIRS)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(NpcGroupBefore)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(NpcGroupAfter)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(AF_TRD04_LowerStairs, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o86, MODEL_k_dan)
    EVT_CALL(ParentColliderToModel, COLLIDER_o87, MODEL_k_dan)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_LOWERED_FIRST_STAIRS)
        EVT_CALL(TranslateModel, MODEL_k_sokumen, 0, 187, 0)
        EVT_CALL(TranslateModel, MODEL_k_dan, 0, 187, 0)
        EVT_CALL(TranslateModel, MODEL_k_kusari, 0, 187, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o86)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o87)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_LowerStairs)), TRIGGER_AREA_FLAG_SET, AF_TRD04_LowerStairs, 1, 0)
    EVT_END_IF
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_o34, FALSE)
    EVT_CALL(EnableModel, MODEL_dai, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dai, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_CALL(EnableTexPanning, MODEL_suimen, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
