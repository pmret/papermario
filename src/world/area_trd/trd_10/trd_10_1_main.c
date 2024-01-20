#include "trd_10.h"
#include "sprite/player.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_InitFakeBowser);
extern EvtScript N(EVS_SetupFakeBowser);
extern NpcGroupList N(DefaultNPCs);

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

API_CALLABLE(N(SetMapChangeFadeRate)) {
    set_map_change_fade_rate(10);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_BossDefeated) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
            Set(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
            Call(GotoMap, Ref("trd_06"), trd_06_ENTRY_2)
            Wait(100)
            Return
        CaseEq(STORY_CH1_DEFEATED_KOOPA_BROS)
            Set(LVar0, 1)
            Call(GetEntryID, LVar1)
            IfEq(LVar1, trd_10_ENTRY_1)
                Set(LVar0, 0)
            EndIf
        CaseDefault
            Return
    EndSwitch
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, TRUE)
        Call(UseSettingsFrom, CAM_DEFAULT, -135, 85, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, -135, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(N(StarSpiritEffectFunc2), 0, 180, -135, 10, 0, -135, 85, 0, 30, 0)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, -135, 85, 0)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, -135, 85, 0)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, -135, 0, 0)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
    Else
        Call(N(StarSpiritEffectFunc5), 0, -135, 30, 0, 0)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, TRUE)
    Set(GB_StoryProgress, STORY_CH1_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_0, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_10_ENTRY_0)
            Set(LVar2, MODEL_o192)
            Set(LVar3, MODEL_o191)
            ExecWait(EnterDoubleDoor)
        CaseEq(trd_10_ENTRY_1)
            Call(DisablePartnerAI, 0)
            Call(SetNpcPos, NPC_PARTNER, -253, 0, 0)
            Call(SetNpcYaw, NPC_PARTNER, 90)
            Wait(3)
            Call(EnablePartnerAI)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ExitDoors_trd_09_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, trd_10_ENTRY_0)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_o192)
    Set(LVar3, MODEL_o191)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("trd_09"), trd_09_ENTRY_1)
    EndIf //@bug unmatched endif
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(N(SetMapChangeFadeRate))
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_InitFakeBowser))
    Exec(N(EVS_SetupFakeBowser))
    IfEq(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Exec(N(EVS_BossDefeated))
    EndIf
    Exec(N(EVS_BindExitTriggers))
    Exec(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Exec(N(EVS_EnterMap))
    EndIf
    Wait(1)
    Return
    End
};
