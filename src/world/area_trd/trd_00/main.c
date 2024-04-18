#include "trd_00.h"
#include "sprite/player.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_nok_15_1) = EVT_EXIT_WALK(60, trd_00_ENTRY_0, "nok_15", nok_15_ENTRY_1);
EvtScript N(EVS_ExitDoors_trd_01_0) = EVT_EXIT_DOUBLE_DOOR(trd_00_ENTRY_1, "trd_01", trd_01_ENTRY_0, COLLIDER_tt2, MODEL_o62, MODEL_doa);
EvtScript N(EVS_ExitDoors_trd_05_1) = EVT_EXIT_DOUBLE_DOOR(trd_00_ENTRY_2, "trd_05", trd_05_ENTRY_1, COLLIDER_tt3, MODEL_o70, MODEL_o69);
EvtScript N(EVS_ExitWalk_trd_05_2) = EVT_EXIT_WALK(60, trd_00_ENTRY_3, "trd_05", trd_05_ENTRY_2);
EvtScript N(EVS_ExitWalk_nok_15_2) = EVT_EXIT_WALK(60, trd_00_ENTRY_4, "nok_15", nok_15_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_15_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_05_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_trd_05_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili5, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_15_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilit, 1, 0)
    Return
    End
};

EvtScript N(D_80240B34_99A7A4) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos,NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, -730, 0, 400)
        Call(SetPanTarget, CAM_DEFAULT, 20, 0, 400)
        Call(SetCamDistance, CAM_DEFAULT, -1000)
        Call(SetCamPitch, CAM_DEFAULT, 18, Float(-20.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, -480, 0, 400)
        Call(SetCamDistance, CAM_DEFAULT, -1300)
        Call(SetCamPitch, CAM_DEFAULT, 18, Float(-11.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(5)
        Call(ResetCam, CAM_DEFAULT, Float(4.0))
    EndThread
    Wait(82)
    Call(SetPlayerPos, -1041, 0, 204)
    Call(SetPlayerAnimation, ANIM_Mario1_Walk)
    Call(SetNpcPos, NPC_PARTNER, -1041, 0, 204)
    Call(DisablePlayerPhysics, FALSE)
    Call(PlayerMoveTo, -900, 200, 30)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(GetLoadType, LVar1)
    IfEq(LVar1, 1)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_00_ENTRY_0)
            IfLt(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS)
                Set(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS)
                ExecWait(N(D_80240B34_99A7A4))
                Exec(N(EVS_BindExitTriggers))
            Else
                Set(LVar0, Ref(N(EVS_BindExitTriggers)))
                Exec(EnterWalk)
            EndIf
        CaseEq(trd_00_ENTRY_1)
            Set(LVar2, MODEL_o62)
            Set(LVar3, MODEL_doa)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_00_ENTRY_2)
            Set(LVar2, MODEL_o70)
            Set(LVar3, MODEL_o69)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_00_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(trd_00_ENTRY_4)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(trd_00_ENTRY_5)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    ResumeGroup(EVT_GROUP_01)
    Return
    End
};

EvtScript N(EVS_TexPan_WaterEdge) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_ue, TEX_PANNER_1)
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
    SetUP_CAMERA_NO_LEAD()
    Set(GF_MAP_KoopaBrosFortress, TRUE)
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_00_ENTRY_0)
        CaseOrEq(trd_00_ENTRY_1)
        CaseOrEq(trd_00_ENTRY_4)
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_TexPan_WaterEdge))
    Exec(N(EVS_SetupMusic))
    Wait(1)
    IfEq(GF_TRD05_BombedWall, FALSE)
        Call(SetGroupVisibility, MODEL_g21, MODEL_GROUP_HIDDEN)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt5, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_ana, MODEL_GROUP_HIDDEN)
    EndIf
    Exec(N(EVS_EnterMap))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, trd_00_ENTRY_5)
        Wait(65)
    Else
        Wait(1)
    EndIf
    Call(EnableTexPanning, MODEL_o125, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
