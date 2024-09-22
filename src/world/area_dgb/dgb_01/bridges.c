#include "dgb_01.h"
#include "ld_addrs.h"
#include "sprite/player.h"

API_CALLABLE(N(LoadSmashBridgesGraphics)) {
    DMA_COPY_SEGMENT(dgb_01_smash_bridges);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_TubbaSmashBridges) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 100)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(N(LoadSmashBridgesGraphics))
    Call(InitAnimatedModels)
    Wait(1)
    Call(InterruptUsePartner)
    Call(SetPlayerAnimation, ANIM_MarioW2_Shocked)
    Thread
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        Wait(5)
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    EndThread
    Wait(30)
    Thread
        Loop(12)
            Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            Wait(5)
        EndLoop
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 60, Float(1.0))
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 400, 420, 0)
    Call(SetPanTarget, CAM_DEFAULT, 400, 420, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-11.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(0.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(GB_ARN_Tubba_MapID, 1)
    Call(SetNpcVar, NPC_Tubba, 0, 1)
    Loop(0)
        Call(GetNpcVar, NPC_Tubba, 0, LVar0)
        IfEq(LVar0, 3)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -50)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(750.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(0.0), Float(3.0))
    Call(DisablePartnerAI, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Wait(1)
    Call(EnablePartnerAI)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
    Call(LoadAnimatedModel, 0, Ref(N(SmashBridgesSkeleton)))
    Call(PlayModelAnimation, 0, Ref(N(AS_SmashBridges)))
    Call(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    Call(SetAnimatedModelRenderMode, 0, RENDER_MODE_SURFACE_OPA)
    Thread
        Call(PlaySound, SOUND_DGB_COLLAPSE_1)
        Wait(60)
        Call(PlaySound, SOUND_DGB_COLLAPSE_2)
        Wait(25)
        Call(PlaySound, SOUND_DGB_COLLAPSE_3)
        Wait(70)
        Call(PlaySound, SOUND_DGB_COLLAPSE_4)
    EndThread
    Thread
        Wait(100)
        Call(PlaySound, SOUND_DGB_SMALL_THUD)
        Wait(50)
        Call(PlaySound, SOUND_DGB_SMALL_THUD)
        Wait(30)
        Call(PlaySound, SOUND_DGB_SMALL_THUD)
        Wait(70)
        Call(PlaySound, SOUND_DGB_SMALL_THUD)
        Wait(30)
        Call(PlaySound, SOUND_DGB_SMALL_THUD)
    EndThread
    Thread
        Call(DisablePlayerPhysics, TRUE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_g96, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g87, MODEL_GROUP_HIDDEN)
        Call(SetPlayerAnimation, ANIM_MarioW2_PanicHover)
        Call(SetPlayerJumpscale, Float(0.5))
        Call(PlayerJump1, 121, 210, 0, 60)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
        Wait(20)
        Call(SetPlayerAnimation, ANIM_Mario1_PanicRun)
        Call(SetPlayerSpeed, Float(8.0))
        Call(PlayerMoveTo, 412, -29, 0)
        Wait(10)
        Call(InterpPlayerYaw, 270, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Sub(LVar1, 210)
        Wait(1)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
        Call(NpcJump1, NPC_PARTNER, 151, LVar1, 0, 60)
        Wait(30)
        Call(EnablePartnerAI)
    EndThread
    Call(ShakeCam, CAM_DEFAULT, 0, 300, Float(1.0))
    Call(StopSound, SOUND_LOOP_DGB_COLLAPSE)
    Thread
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0D)
        Call(SetNpcSpeed, NPC_Tubba, Float(3.0))
        Call(NpcMoveTo, NPC_Tubba, 176, 0, 0)
    EndThread
    Thread
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.3))
        Wait(5)
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.15))
        Wait(8)
    EndThread
    Wait(20)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Set(GB_StoryProgress, STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
    Call(SetGroupVisibility, MODEL_g240, MODEL_GROUP_VISIBLE)
    Call(DeleteAnimatedModel, 0)
    Thread
        Wait(30)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0D)
        Call(SetNpcPos, NPC_Tubba, 137, 244, 35)
        Call(SetNpcSpeed, NPC_Tubba, Float(3.0))
        Call(NpcMoveTo, NPC_Tubba, 470, 0, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(3.0))
    EndThread
    Thread
        Loop(0)
            Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.3))
            Wait(5)
            Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.15))
            Wait(8)
        EndLoop
    EndThread
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 470, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Exec(N(EVS_ExitDoors_dgb_08_1))
    Return
    End
};

EvtScript N(EVS_SetupBridges) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetGroupVisibility, MODEL_g240, MODEL_GROUP_HIDDEN)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
        CaseEq(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetGroupVisibility, MODEL_g240, MODEL_GROUP_HIDDEN)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
            Exec(N(EVS_Scene_TubbaSmashBridges))
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetGroupVisibility, MODEL_g340, MODEL_GROUP_HIDDEN)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_before, COLLIDER_FLAGS_UPPER_MASK)
        CaseDefault
            Call(SetGroupVisibility, MODEL_g240, MODEL_GROUP_HIDDEN)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Return
    End
};
