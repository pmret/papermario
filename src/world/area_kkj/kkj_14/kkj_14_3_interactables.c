#include "kkj_14.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/todo/GetPeachDisguise.inc.c"

EvtScript N(EVS_Inspect_Fireplace) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
                EVT_IF_EQ(AF_KKJ_14, FALSE)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0039)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_003A)
                    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_003B)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
                    EVT_SET(AF_KKJ_14, TRUE)
                    EVT_CALL(EnablePartnerAI)
                EVT_ELSE
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017B, 160, 40)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017B, 160, 40)
            EVT_END_IF
        EVT_CASE_RANGE(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017B, 160, 40)
        EVT_CASE_DEFAULT
            EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0043, 160, 40)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Dresses) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
                EVT_IF_EQ(AF_KKJ_15, FALSE)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_003C)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_003D)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
                    EVT_SET(AF_KKJ_15, TRUE)
                    EVT_CALL(EnablePartnerAI)
                EVT_ELSE
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017C, 160, 40)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017C, 160, 40)
            EVT_END_IF
        EVT_CASE_RANGE(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017C, 160, 40)
        EVT_CASE_DEFAULT
            EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0044, 160, 40)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Vanity) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH1_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(N(GetPeachDisguise), LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(InterpPlayerYaw, 45, 10)
                EVT_WAIT(10)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 5)
                EVT_ADD(LVar1, 35)
                EVT_ADD(LVar2, -10)
                EVT_LOOP(6)
                    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0)
                    EVT_WAIT(15)
                EVT_END_LOOP
            EVT_ELSE
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0044)
                EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0045)
                EVT_CALL(EnablePartnerAI)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0045, 160, 40)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Photo) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
                EVT_IF_EQ(AF_KKJ_17, FALSE)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_003E)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_003F)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
                    EVT_SET(AF_KKJ_17, TRUE)
                    EVT_CALL(EnablePartnerAI)
                EVT_ELSE
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017D, 160, 40)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017D, 160, 40)
            EVT_END_IF
        EVT_CASE_RANGE(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017D, 160, 40)
        EVT_CASE_DEFAULT
            EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0046, 160, 40)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Bed) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
                EVT_IF_EQ(AF_KKJ_18, FALSE)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0040)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0041)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
                    EVT_SET(AF_KKJ_18, TRUE)
                    EVT_CALL(EnablePartnerAI)
                EVT_ELSE
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017E, 160, 40)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017E, 160, 40)
            EVT_END_IF
        EVT_CASE_RANGE(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017E, 160, 40)
        EVT_CASE_DEFAULT
            EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0047, 160, 40)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Flowers) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
                EVT_IF_EQ(AF_KKJ_19, FALSE)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0042)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0043)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
                    EVT_SET(AF_KKJ_19, TRUE)
                    EVT_CALL(EnablePartnerAI)
                EVT_ELSE
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017F, 160, 40)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017F, 160, 40)
            EVT_END_IF
        EVT_CASE_RANGE(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_017F, 160, 40)
        EVT_CASE_DEFAULT
            EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0048, 160, 40)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(FireplaceAlpha) = 255;

API_CALLABLE(N(SetFireplaceAlpha)) {
    Bytecode* args = script->ptrReadPos;

    N(FireplaceAlpha) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(setup_gfx_fireplace)(void) {
    gDPSetCycleType(gMainGfxPos++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_INTERFERENCE, PM_CC_3E);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(FireplaceAlpha));
}

EvtScript N(EVS_TexPan_Fireplace) = {
    EVT_CALL(EnableTexPanning, MODEL_o42, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o157, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, -110)
        EVT_ADD(LVar1, 50)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar2, 40)
        EVT_ADD(LVar3, 130)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_AUX, LVar2, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RevealButton) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o128, SOUND_KKJ_REVEAL_BUTTON, 0)
    EVT_CALL(MakeLerp, 0, 180, 15, EASING_LINEAR)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateGroup, MODEL_g39, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(EnableModel, MODEL_o146, TRUE)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g39, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_o141, FALSE)
    EVT_CALL(EnableModel, MODEL_o143, FALSE)
    EVT_SET(GF_KKJ14_RevealedButton, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenHiddenPassage) = {
    EVT_CALL(EnableModel, MODEL_o35, FALSE)
    EVT_CALL(EnableModel, MODEL_o42, FALSE)
    EVT_CALL(EnableGroup, MODEL_g27, TRUE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        EVT_SET(LVar0, 120 * DT)
    EVT_ELSE
        EVT_SET(LVar0, 60 * DT)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o129, SOUND_KKJ_EXTINGUISH_FIRE, 0)
    EVT_CALL(MakeLerp, 255, 0, LVar0, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetFireplaceAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_o157, FALSE)
    EVT_CALL(SetModelFlags, MODEL_o157, 16, FALSE)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(PlaySoundAt, SOUND_KKJ_DROP_INTO_ASHES, SOUND_SPACE_DEFAULT, -125, 10, -120)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, -125, 10, -120, EVT_FLOAT(2.0), 30)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -180, 30 * DT, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o39, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o129, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_KKJ14_OpenedPassage, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_HiddenButton) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
        EVT_EXEC_WAIT(N(EVS_RevealButton))
    EVT_ELSE
        EVT_CALL(FacePlayerTowardPoint, -29, -148, 5)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach3_ReachForButtonHigh)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach3_PressButtonHigh)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o128, SOUND_KKJ_PRESS_BUTTON, 0)
        EVT_END_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 10)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach3_AfterPressButtonHigh)
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
        EVT_CALL(InterpPlayerYaw, 225, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_EXEC_WAIT(N(EVS_OpenHiddenPassage))
        EVT_UNBIND
    EVT_END_IF
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_HiddenButton_FirstTime) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
        EVT_IF_EQ(AF_KKJ_04, FALSE)
            EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 5, MSG_Peach_0046)
            EVT_SET(AF_KKJ_04, TRUE)
        EVT_END_IF
        EVT_EXEC_WAIT(N(EVS_RevealButton))
    EVT_ELSE
        EVT_CALL(FacePlayerTowardPoint, -29, -148, 5)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach3_ReachForButtonHigh)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach3_PressButtonHigh)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o128, SOUND_KKJ_PRESS_BUTTON, 0)
        EVT_END_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 10)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach3_AfterPressButtonHigh)
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
        EVT_CALL(InterpPlayerYaw, 225, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 225, 0)
        EVT_IF_EQ(AF_KKJ_05, FALSE)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -120, 25, 0)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_END_IF
        EVT_EXEC_WAIT(N(EVS_OpenHiddenPassage))
        EVT_IF_EQ(AF_KKJ_05, FALSE)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Delighted)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ShoutJoy, ANIM_Twink_ShoutJoy, 5, MSG_Peach_0047)
            EVT_SET(AF_KKJ_05, TRUE)
        EVT_END_IF
        EVT_UNBIND
    EVT_END_IF
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupInteractables) = {
    EVT_IF_EQ(GF_KKJ14_RevealedButton, FALSE)
        EVT_CALL(EnableModel, MODEL_o146, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o141, FALSE)
        EVT_CALL(EnableModel, MODEL_o143, FALSE)
        EVT_CALL(RotateGroup, MODEL_g39, 180, 1, 0, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_KKJ14_OpenedPassage, FALSE)
        EVT_CALL(EnableGroup, MODEL_g27, FALSE)
        EVT_EXEC(N(EVS_TexPan_Fireplace))
        EVT_CALL(SetModelCustomGfx, MODEL_o157, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
        EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_fireplace)), NULL)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH0_WAKE_UP)
            EVT_CASE_LT(STORY_CH2_BEGAN_PEACH_MISSION)
                EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_HiddenButton_FirstTime)), TRIGGER_WALL_PRESS_A, COLLIDER_o128, 1, 0)
            EVT_CASE_LT(STORY_CH8_REACHED_PEACHS_CASTLE)
                EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_HiddenButton)), TRIGGER_WALL_PRESS_A, COLLIDER_o128, 1, 0)
            EVT_CASE_DEFAULT
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o129, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(RotateModel, MODEL_o39, -180, 1, 0, 0)
        EVT_CALL(EnableGroup, MODEL_g45, FALSE)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Fireplace)), TRIGGER_WALL_PRESS_A, COLLIDER_o129, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Dresses)), TRIGGER_WALL_PRESS_A, COLLIDER_o143, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Vanity)), TRIGGER_WALL_PRESS_A, COLLIDER_o142, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Photo)), TRIGGER_WALL_PRESS_A, COLLIDER_o141, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Bed)), TRIGGER_WALL_PRESS_A, COLLIDER_o25, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Flowers)), TRIGGER_WALL_PRESS_A, COLLIDER_o135, 1, 0)
    EVT_RETURN
    EVT_END
};
