#include "dgb_01.h"
#include "ld_addrs.h"

ApiStatus N(func_80240000_BFD880)(void) {
    dma_copy(C20F40_ROM_START, C20F40_ROM_END, C20F40_VRAM);
    return ApiStatus_DONE2;
}

EvtScript N(80243EF0) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 100)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(func_80240000_BFD880))
    EVT_CALL(InitAnimatedModels)
    EVT_WAIT(1)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000A)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
        EVT_WAIT(5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_LOOP(12)
            EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 60, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 400, 420, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 400, 420, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(GB_ARN_Tubba_MapID, 1)
    EVT_CALL(SetNpcVar, NPC_Tubba, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetNpcVar, NPC_Tubba, 0, LVar0)
        EVT_IF_EQ(LVar0, 3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -50)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(750.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(3.0))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(N(D_80252F4C_C107CC)))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(N(AS_SmashBridges)))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, 0, RENDER_MODE_SURFACE_OPA)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_95)
        EVT_WAIT(60)
        EVT_CALL(PlaySound, SOUND_96)
        EVT_WAIT(25)
        EVT_CALL(PlaySound, SOUND_98)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, SOUND_97)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(100)
        EVT_CALL(PlaySound, SOUND_A8)
        EVT_WAIT(50)
        EVT_CALL(PlaySound, SOUND_A8)
        EVT_WAIT(30)
        EVT_CALL(PlaySound, SOUND_A8)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, SOUND_A8)
        EVT_WAIT(30)
        EVT_CALL(PlaySound, SOUND_A8)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupEnabled, MODEL_g96, 0)
        EVT_CALL(SetGroupEnabled, MODEL_g87, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80013)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
        EVT_CALL(PlayerJump1, 121, 210, 0, 60)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001F)
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_RunPanic)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(8.0))
        EVT_CALL(PlayerMoveTo, 412, -29, 0)
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 210)
        EVT_WAIT(1)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump1, NPC_PARTNER, 151, LVar1, 0, 60)
        EVT_WAIT(30)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 300, EVT_FLOAT(1.0))
    EVT_CALL(StopSound, SOUND_8000005D)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0D)
        EVT_CALL(SetNpcSpeed, NPC_Tubba, EVT_FLOAT(3.0))
        EVT_CALL(NpcMoveTo, NPC_Tubba, 176, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.3))
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.15))
        EVT_WAIT(8)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_StoryProgress, STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
    EVT_CALL(SetGroupEnabled, MODEL_g240, 1)
    EVT_CALL(DeleteAnimatedModel, 0)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0D)
        EVT_CALL(SetNpcPos, NPC_Tubba, 137, 244, 35)
        EVT_CALL(SetNpcSpeed, NPC_Tubba, EVT_FLOAT(3.0))
        EVT_CALL(NpcMoveTo, NPC_Tubba, 470, 0, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.3))
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.15))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 470, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC(N(EVS_ExitDoors_dgb_08_1))
    EVT_RETURN
    EVT_END
};

EvtScript N(802449C4) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_WOKE_UP)
            EVT_CALL(SetGroupEnabled, MODEL_g240, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_EQ(STORY_CH3_TUBBA_WOKE_UP)
            EVT_CALL(SetGroupEnabled, MODEL_g240, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
            EVT_EXEC(N(80243EF0))
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SetGroupEnabled, MODEL_g340, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_before, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_DEFAULT
            EVT_CALL(SetGroupEnabled, MODEL_g240, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_after, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
