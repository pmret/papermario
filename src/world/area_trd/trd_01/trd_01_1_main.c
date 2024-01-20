#include "trd_01.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_UnlockDoors);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_EnterMap) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_01_ENTRY_0)
            Set(LVar2, MODEL_ew_doa)
            Set(LVar3, MODEL_ew_doa2)
            ExecWait(EnterDoubleDoor)
        CaseEq(trd_01_ENTRY_1)
            Set(LVar2, MODEL_e2_doa)
            Set(LVar3, MODEL_e2_doa2)
            ExecWait(EnterDoubleDoor)
        CaseEq(trd_01_ENTRY_2)
            Set(LVar2, MODEL_e3_doa)
            Set(LVar3, MODEL_e3_doa2)
            ExecWait(EnterDoubleDoor)
        CaseEq(trd_01_ENTRY_3)
            Set(LVar2, MODEL_e4_doa)
            Set(LVar3, MODEL_e4_doa2)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    ResumeGroup(EVT_GROUP_01)
    Return
    End
};

EvtScript N(EVS_ExitDoors_trd_00_1) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_0, "trd_00", trd_00_ENTRY_1, COLLIDER_ttw, MODEL_ew_doa, MODEL_ew_doa2);
EvtScript N(EVS_ExitDoors_trd_02_0) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_1, "trd_02", trd_02_ENTRY_0, COLLIDER_tte, MODEL_e2_doa, MODEL_e2_doa2);
EvtScript N(EVS_ExitDoors_trd_02_2) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_2, "trd_02", trd_02_ENTRY_2, COLLIDER_tte2, MODEL_e3_doa, MODEL_e3_doa2);
EvtScript N(EVS_ExitDoors_trd_09_0) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_3, "trd_09", trd_09_ENTRY_0, COLLIDER_tte3, MODEL_e4_doa, MODEL_e4_doa2);

EvtScript N(EVS_Scene_RaiseStairs) = {
    Call(DisablePlayerInput, TRUE)
    Set(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
    SetGroup(EVT_GROUP_00)
    Wait(1)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Wait(20 * DT)
    Set(LVar0, 0)
    Set(LVar1, 220)
    Set(LVar2, 255)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, 18, 12)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.4 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o162, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    Call(PlaySound, SOUND_LOOP_TRD_FLOWING_WATER)
    ChildThread
        SetGroup(EVT_GROUP_00)
        Wait(4 * DT)
        Call(EnableModel, MODEL_sui1, TRUE)
        Call(EnableModel, MODEL_sui2, TRUE)
        Call(EnableTexPanning, MODEL_sui1, TRUE)
        Call(EnableTexPanning, MODEL_sui2, TRUE)
        Call(EnableTexPanning, MODEL_o145, TRUE)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Set(LVar3, 0)
        Set(LVar4, 0)
        Set(LVar5, 0)
        Set(LVar6, 0)
        Set(LVar7, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, LVar1)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX,  LVar2, LVar3)
            Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar4, LVar5)
            Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX,  LVar6, LVar7)
            Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, LVar8, LVar9)
            Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX,  LVarA, LVarB)
            Add(LVar0, -600)
            Add(LVar1, -600)
            Add(LVar2, -300)
            Add(LVar3, -300)
            Add(LVar4, 140)
            Add(LVar5, -600)
            Add(LVar6, -30)
            Add(LVar7, -600)
            Add(LVar8, 100)
            Add(LVar9, -600)
            Add(LVarA, -100)
            Add(LVarB, -300)
            Wait(1)
        EndLoop
    EndChildThread
    Thread
        Call(PlaySound, SOUND_LOOP_TRD_RAISE_STAIRS)
        Call(ShakeCam, CAM_DEFAULT, 0, 10 * DT, Float(4.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 20 * DT, Float(0.7))
        Call(ShakeCam, CAM_DEFAULT, 0, 250 * DT, Float(1.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 30 * DT, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 10 * DT, Float(1.2))
        Call(StopSound, SOUND_LOOP_TRD_RAISE_STAIRS)
    EndThread
    Thread
        Wait(50 * DT)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 500, LVar2)
    EndThread
    Thread
        Call(GetNpcPos, NPC_KoopaTroopa_02, LVar4, LVar5, LVar6)
        Call(SetNpcPos, NPC_KoopaTroopa_02, LVar4, -27, LVar6)
        Wait(100 * DT)
        Call(MakeLerp, -27, 300, 210 * DT, EASING_QUADRATIC_OUT)
        Loop(210 * DT)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_KoopaTroopa_02, LVar4, LVar0, LVar6)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(20 * DT)
        Call(PlaySoundAtNpc, NPC_KoopaTroopa_02, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_KoopaTroopa_02, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        Wait(120 * DT)
        Call(SetNpcAnimation, NPC_KoopaTroopa_02, ANIM_KoopaTroopa_ShellExit)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_KoopaTroopa_02, ANIM_KoopaTroopa_Panic)
        Call(PlaySoundAtNpc, NPC_KoopaTroopa_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_KoopaTroopa_02, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
        Loop(4)
            Call(InterpNpcYaw, NPC_KoopaTroopa_02, 270, 0)
            Wait(20 * DT)
            Call(InterpNpcYaw, NPC_KoopaTroopa_02, 90, 0)
            Wait(15 * DT)
        EndLoop
    EndThread
    Thread
        Wait(210 * DT)
        Set(NPC_KoopaTroopa_02_DonePanic, TRUE)
    EndThread
    Thread
        Call(GetNpcPos, NPC_KoopaTroopa_03, LVar4, LVar5, LVar6)
        Call(SetNpcPos, NPC_KoopaTroopa_03, LVar4, -27, LVar6)
        Wait(85 * DT)
        Call(MakeLerp, -27, 350, 215 * DT, EASING_QUADRATIC_OUT)
        Loop(215 * DT)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_KoopaTroopa_03, LVar4, LVar0, LVar6)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(25 * DT)
        Call(ShowEmote, NPC_KoopaTroopa_03, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        Wait(120 * DT)
        Call(SetNpcAnimation, NPC_KoopaTroopa_03, ANIM_KoopaTroopa_ShellExit)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_KoopaTroopa_03, ANIM_KoopaTroopa_Panic)
        Call(PlaySoundAtNpc, NPC_KoopaTroopa_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_KoopaTroopa_03, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
        Loop(4)
            Call(InterpNpcYaw, NPC_KoopaTroopa_03, 270, 0)
            Wait(20 * DT)
            Call(InterpNpcYaw, NPC_KoopaTroopa_03, 90, 0)
            Wait(15 * DT)
        EndLoop
    EndThread
    Thread
        Wait(180 * DT)
        Set(NPC_KoopaTroopa_03_DonePanic, TRUE)
    EndThread
    Call(MakeLerp, -450, 0, 300 * DT, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_dan, 0, LVar0, 0)
    Call(TranslateModel, MODEL_k_soku, 0, LVar0, 0)
    Call(TranslateModel, MODEL_k_kusari, 0, LVar0, 0)
    Call(UpdateColliderTransform, COLLIDER_o158)
    Set(LVar2, LVar0)
    Add(LVar2, 400)
    IfGe(LVar2, -20)
        IfEq(LFlag0, FALSE)
            Set(LFlag0, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(EnableModel, MODEL_o145, TRUE)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 375)
    IfGe(LVar2, -20)
        IfEq(LFlag1, FALSE)
            Set(LFlag1, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(TranslateModel, MODEL_o145, 50, 0, 0)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 350)
    IfGe(LVar2, -20)
        IfEq(LFlag2, FALSE)
            Set(LFlag2, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(TranslateModel, MODEL_o145, 100, 0, 0)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 325)
    IfGe(LVar2, -20)
        IfEq(LFlag3, FALSE)
            Set(LFlag3, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(TranslateModel, MODEL_o145, 150, 0, 0)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 299)
    IfGe(LVar2, -20)
        IfEq(LFlag4, FALSE)
            Set(LFlag4, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(TranslateModel, MODEL_o145, 200, 0, 0)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 273)
    IfGe(LVar2, -20)
        IfEq(LFlag5, FALSE)
            Set(LFlag5, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(TranslateModel, MODEL_o145, 250, 0, 0)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 245)
    IfGe(LVar2, -20)
        IfEq(LFlag6, FALSE)
            Set(LFlag6, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(TranslateModel, MODEL_o145, 300, 0, 0)
        EndIf
    EndIf
    Set(LVar2, LVar0)
    Add(LVar2, 220)
    IfGe(LVar2, -20)
        IfEq(LFlag7, FALSE)
            Set(LFlag7, TRUE)
            Call(PlaySound, SOUND_TRD_WATER_SPLASH)
            Call(EnableModel, MODEL_o145, FALSE)
        EndIf
    EndIf
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Thread
        Wait(28 * DT)
        Call(EnableModel, MODEL_sui1, FALSE)
        Call(EnableModel, MODEL_sui2, FALSE)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 220, 255)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(ResetCam, CAM_DEFAULT, Float(1.5 / DT))
    Call(StopSound, SOUND_LOOP_TRD_FLOWING_WATER)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Unbind
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_suimenn, TEX_PANNER_1)
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

s32 N(KeyList)[] = {
    ITEM_KOOPA_FORTRESS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_TexPan_Water))
    BindTrigger(Ref(N(EVS_ExitDoors_trd_00_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    IfEq(GF_TRD01_UnlockedDoor, FALSE)
        BindPadlock(Ref(N(EVS_UnlockDoors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_trd_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_trd_02_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte3, 1, 0)
    Exec(N(EVS_SetupMusic))
    Set(AF_TRD01_RaiseStairs, FALSE)
    Call(ParentColliderToModel, COLLIDER_o158, MODEL_dan)
    IfLt(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        Set(LVar0, -450)
        Call(TranslateModel, MODEL_dan, 0, LVar0, 0)
        Call(TranslateModel, MODEL_k_soku, 0, LVar0, 0)
        Call(TranslateModel, MODEL_k_kusari, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o158)
        BindTrigger(Ref(N(EVS_Scene_RaiseStairs)), TRIGGER_AREA_FLAG_SET, AF_TRD01_RaiseStairs, 0, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o162, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    EndIf
    Call(EnableModel, MODEL_sui1, FALSE)
    Call(EnableModel, MODEL_sui2, FALSE)
    Call(EnableModel, MODEL_o145, FALSE)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Call(EnableTexPanning, MODEL_suimenn, TRUE)
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
