#include "kzn_19.h"
#include "sprite/player.h"

#include "../common/SmokeTexPanners.inc.c"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

EvtScript N(EVS_TrySpawningStarCard) = {
    // determine if card should be spawned
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH5_KOLORADO_IN_TREASURE_ROOM)
            Set(LVar0, FALSE)
            IfEq(MV_BossDefeated, FALSE)
                Return
            EndIf
            Set(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        CaseEq(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(GetEntryID, LVar0)
            IfEq(LVar0, kzn_19_ENTRY_3)
                Return
            EndIf
            Set(LVar0, TRUE)
        CaseDefault
            Return
    EndSwitch
    IfEq(LVar0, FALSE)
        // card appearing scene
        Call(DisablePlayerInput, TRUE)
        Call(UseSettingsFrom, CAM_DEFAULT, 185, 110, -30)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.44))
        Call(SetPanTarget, CAM_DEFAULT, 185, 55, -30)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(N(StarSpiritEffectFunc2), 4, 180, 304, 15, -54, 185, 110, -30, 55, 25)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 185, 110, -30)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 185, 110, -30)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 185, 25, -30)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
    Else
        // just make the card spawn
        Call(N(StarSpiritEffectFunc5), 4, 185, 55, -30, 25)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    // wait for pickup
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, TRUE)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_4, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kzn_18_1) = EVT_EXIT_WALK(60, kzn_19_ENTRY_0, "kzn_18", kzn_18_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_18_2) = EVT_EXIT_WALK(60, kzn_19_ENTRY_1, "kzn_18", kzn_18_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_20_0) = EVT_EXIT_WALK(60, kzn_19_ENTRY_2, "kzn_20", kzn_20_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_18_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_18_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_StartTexPanners_Lava) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_yougan1_1, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_toro, TRUE)
    Call(EnableTexPanning, MODEL_poko, TRUE)
    Call(SetTexPanner, MODEL_poko1, TEX_PANNER_E)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  200,    0,  400, -100)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(  300, -500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        Set(LVar0, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
            Add(LVar0, 0x8000)
            Wait(6)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
            Add(LVar0, 0x8000)
            Wait(4)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_UpdateLavaWaves) = {
    SetGroup(EVT_GROUP_00)
    Loop(0)
        Call(MakeLerp, 0, 180, 40, EASING_COS_IN)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SubF(LVar0, Float(0.9))
            Call(ScaleModel, MODEL_yougan1_1, 1, LVar0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 180, 0, 40, EASING_SIN_OUT)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SubF(LVar0, Float(0.9))
            Call(ScaleModel, MODEL_yougan1_1, 1, LVar0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_19)
    SetUP_CAMERA_DEFAULT()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kzn_19_ENTRY_3)
        Call(MakeNpcs, TRUE, Ref(N(EscapeNPCs)))
    Else
        Call(MakeNpcs, TRUE, Ref(N(BossNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kzn_19_ENTRY_3)
        Thread
            ExecWait(N(EVS_Misstar_Escape))
            Exec(N(EVS_BindExitTriggers))
        EndThread
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(EnableGroup, MODEL_ato, FALSE)
            Call(EnableGroup, MODEL_naka, FALSE)
            Call(EnableGroup, MODEL_g93, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
        CaseEq(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(EnableGroup, MODEL_mae, FALSE)
            Call(EnableGroup, MODEL_g93, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
        CaseGt(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(EnableGroup, MODEL_mae, FALSE)
            Call(EnableGroup, MODEL_naka, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Exec(N(EVS_StartTexPanners_Lava))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_UpdateLavaWaves))
    Exec(N(EVS_UpdateEruption))
    Exec(N(EVS_TrySpawningStarCard))
    Return
    End
};
