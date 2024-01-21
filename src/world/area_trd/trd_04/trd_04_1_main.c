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
    BindTrigger(Ref(N(EVS_ExitDoors_trd_03_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    IfEq(GF_TRD04_UnlockedLowerDoor, FALSE)
        BindPadlock(Ref(N(EVS_UnlockLowerRightDoors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_trd_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EndIf
    IfEq(GF_TRD04_UnlockedUpperDoor, FALSE)
        IfEq(GF_TRD04_UnlockedLowerDoor, TRUE)
            BindPadlock(Ref(N(EVS_UnlockUpperLeftDoors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
        EndIf
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_trd_03_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw3, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_trd_05_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tte3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_trd_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_06_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_04_ENTRY_0)
            Set(LVar2, MODEL_o6)
            Set(LVar3, MODEL_o7)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_04_ENTRY_1)
            Set(LVar2, MODEL_o9)
            Set(LVar3, MODEL_o8)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_04_ENTRY_2)
            Set(LVar2, MODEL_o13)
            Set(LVar3, MODEL_o12)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_04_ENTRY_3)
            Set(LVar2, MODEL_o10)
            Set(LVar3, MODEL_o11)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_04_ENTRY_4)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(trd_04_ENTRY_5)
            Set(LVar2, MODEL_o29)
            Set(LVar3, MODEL_o28)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    ResumeGroup(EVT_GROUP_01)
    Return
    End
};

EvtScript N(EVS_Scene_LowerStairs) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Set(GB_StoryProgress, STORY_CH1_LOWERED_FIRST_STAIRS)
    Call(DisablePlayerInput, TRUE)
    Wait(30 * DT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10 * DT, Float(0.7))
        Call(ShakeCam, CAM_DEFAULT, 0, 320 * DT, Float(1.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 10 * DT, Float(0.7))
        Call(ShakeCam, CAM_DEFAULT, 0, 10 * DT, Float(0.4))
    EndThread
    Wait(30 * DT)
    Call(EnableModel, MODEL_o6, FALSE)
    Call(EnableModel, MODEL_o7, FALSE)
    Call(EnableModel, MODEL_bero2, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, -50, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(540.0))
    Call(SetCamPitch, CAM_DEFAULT, 15, -6)
    Call(SetCamPosA, CAM_DEFAULT, -30, -60)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetPlayerPos, -185, 0, -36)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetNpcPos, NPC_PARTNER, -163, 0, -12)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(PlaySound, SOUND_LOOP_TRD_04_LOWER_STAIRS)
    Wait(20 * DT)
    Thread
        Loop(5)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 150)
            PlayEffect(EFFECT_DUST, 0, LVar0, LVar1, LVar2, 40)
            Call(RandInt, 20 * DT, LVar0)
            Add(LVar0, 20 * DT)
            Wait(LVar0)
        EndLoop
    EndThread
    Thread
        Loop(7)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Call(RandInt, 200, LVar4)
            Sub(LVar4, 100)
            Call(RandInt, 100, LVar5)
            Sub(LVar5, 100)
            Add(LVar1, LVar4)
            Add(LVar2, 200)
            Add(LVar3, LVar5)
            PlayEffect(EFFECT_SHATTERING_STONES, 0, LVar1, LVar2, LVar3)
            Call(RandInt, 30 * DT, LVar0)
            Add(LVar0, 30 * DT)
            Wait(LVar0)
        EndLoop
    EndThread
    Thread
        Call(InterpPlayerYaw, 270, 0)
        Wait(10 * DT)
        Call(InterpPlayerYaw, 90, 0)
        Wait(15 * DT)
        Call(InterpPlayerYaw, 270, 0)
        Wait(12 * DT)
        Call(InterpPlayerYaw, 90, 0)
        Wait(18 * DT)
        Call(InterpPlayerYaw, 270, 0)
        Wait(29 * DT)
        Call(InterpPlayerYaw, 90, 0)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Wait(13 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
        Wait(15 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Wait(17 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
        Wait(18 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Wait(17 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    Wait(20 * DT)
    Call(MakeLerp, 187, 0, 300 * DT, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_k_sokumen, 0, LVar0, 0)
    Call(TranslateModel, MODEL_k_dan, 0, LVar0, 0)
    Call(TranslateModel, MODEL_k_kusari, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(UpdateColliderTransform, COLLIDER_o86)
    Call(UpdateColliderTransform, COLLIDER_o87)
    Call(StopSound, SOUND_LOOP_TRD_04_LOWER_STAIRS)
    Call(PlaySound, SOUND_TRD_04_STAIRS_LOWERED)
    Wait(50 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPosA, CAM_DEFAULT, -169, 130)
    Call(SetCamPitch, CAM_DEFAULT, 18, -6)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(2)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(EnableModel, MODEL_o6, TRUE)
    Call(EnableModel, MODEL_o7, TRUE)
    Call(EnableModel, MODEL_bero2, TRUE)
    Call(DisablePlayerInput, FALSE)
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_suimen, TEX_PANNER_1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        Add(LVar0, 100)
        Sub(LVar1, 100)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(SetRenderMode, MODEL_suimen, RENDER_MODE_SURFACE_XLU_LAYER2)
    IfLt(GB_StoryProgress, STORY_CH1_LOWERED_FIRST_STAIRS)
        Call(MakeNpcs, TRUE, Ref(N(NpcGroupBefore)))
    Else
        Call(MakeNpcs, TRUE, Ref(N(NpcGroupAfter)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Set(AF_TRD04_LowerStairs, FALSE)
    Call(ParentColliderToModel, COLLIDER_o86, MODEL_k_dan)
    Call(ParentColliderToModel, COLLIDER_o87, MODEL_k_dan)
    IfLt(GB_StoryProgress, STORY_CH1_LOWERED_FIRST_STAIRS)
        Call(TranslateModel, MODEL_k_sokumen, 0, 187, 0)
        Call(TranslateModel, MODEL_k_dan, 0, 187, 0)
        Call(TranslateModel, MODEL_k_kusari, 0, 187, 0)
        Call(UpdateColliderTransform, COLLIDER_o86)
        Call(UpdateColliderTransform, COLLIDER_o87)
        BindTrigger(Ref(N(EVS_Scene_LowerStairs)), TRIGGER_AREA_FLAG_SET, AF_TRD04_LowerStairs, 1, 0)
    EndIf
    Exec(N(EVS_TexPan_Water))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o34, FALSE)
    Call(EnableModel, MODEL_dai, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dai, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Call(EnableTexPanning, MODEL_suimen, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
