#include "mac_01.h"
#include "effects.h"
#include "hud_element.h"
#include "sprite/player.h"

extern IconHudScriptPair gItemHudScripts[];
extern EvtScript N(EVS_MerlonBargeOut);

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"

NpcSettings N(NpcSettings_Ninji) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Twink.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/Bubulb.inc.c"

NpcSettings N(NpcSettings_Parakarry) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#define KNOCK_DOWN_MAP_VAR MV_KnockdownWorker
#include "world/common/complete/KnockDownPlayer.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

#include "world/common/todo/GetPlayerCoins.inc.c"

s32 N(LetterList_Merlon)[] = {
    ITEM_LETTER_TO_MERLON,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Merlon) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle,
        ITEM_LETTER_TO_MERLON, ITEM_NONE,
        MSG_MAC_Plaza_0043, MSG_MAC_Plaza_0044, MSG_MAC_Plaza_0045, MSG_MAC_Plaza_0046,
        EVT_PTR(N(LetterList_Merlon)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Merlon) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
        EVT_CALL(InterpNpcYaw, NPC_Merlon, 135, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(LetterList_MinhT)[] = {
    ITEM_LETTER_TO_MINH_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_MinhT) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle,
        ITEM_LETTER_TO_MINH_T, ITEM_NONE,
        MSG_MAC_Plaza_0078, MSG_MAC_Plaza_0079, MSG_MAC_Plaza_007A, MSG_MAC_Plaza_007B,
        EVT_PTR(N(LetterList_MinhT)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_MinhT) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(LetterList_Kolorado)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_MAC_Plaza_00E0, MSG_MAC_Plaza_00E1, MSG_MAC_Plaza_00E2, MSG_MAC_Plaza_00E3,
        EVT_PTR(N(LetterList_Kolorado)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Artifact)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactReward_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E8)
    EVT_GIVE_STAR_PIECE()
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E9)
    EVT_SET(GF_SBK_GaveArtifactToKolorado, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ArtifactPrompt_Kolorado) = {
    EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_ARTIFACT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_MAC_44, FALSE)
        EVT_SET(AF_MAC_44, TRUE)
        EVT_IF_EQ(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00E4)
        EVT_ELSE
            EVT_SET(LVar0, MSG_MAC_Plaza_00E5)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Plaza_00E5)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Artifact)))
    EVT_SET(LVar1, 19)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_GE(1)
            EVT_EXEC_WAIT(N(EVS_ArtifactReward_Kolorado))
            EVT_BREAK_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E6)
            EVT_SET(LVar0, EVT_PTR(N(ItemList_Artifact)))
            EVT_SET(LVar1, 19)
            EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
            EVT_SWITCH(LVar0)
                EVT_CASE_GE(1)
                    EVT_EXEC_WAIT(N(EVS_ArtifactReward_Kolorado))
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E7)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E6F8_80EF78) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E740_80EFC0) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -80, 30, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E7F0_80F070) = {
    EVT_CALL(MakeLerp, -80, 0, 30, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

#include "npc/read_fortune.inc.c"

#include "world/common/util/CheckPositionRelativeToPlane.inc.c"

API_CALLABLE(N(func_802447E0_805060)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 10;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80244848_8050C8)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802448A0_805120)) {
    s32 alpha;

    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 32;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = 255 - script->functionTemp[0];
    }

    mdl_set_shroud_tint_params(0, 0, 0, alpha);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 3) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_NONE, TRUE);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_QuickChange_CheckForPound) = {
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ACTION_STATE_TORNADO_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ACTION_STATE_TORNADO_POUND)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_ADD(GB_MAC01_Merlon_SpinJumpCount, 1)
    EVT_IF_LT(GB_MAC01_Merlon_SpinJumpCount, 3)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(CheckPositionRelativeToPlane), -380, -245, -225, -408)
    EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
        EVT_SET(LVar2, -232)
        EVT_SET(LVar4, -331)
    EVT_ELSE
        EVT_SET(LVar2, -297)
        EVT_SET(LVar4, -393)
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_QUICK_CHANGE, LVar2, 220, LVar4, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_MAC01_Item_QuickChange)
    EVT_WAIT(35)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Run)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Merlon, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 5, MSG_MAC_Plaza_0041)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0042)
    EVT_SET(GF_MAC01_QuickChangeDropped, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupQuickChangeTrigger) = {
    EVT_IF_EQ(GF_MAC01_QuickChangeDropped, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_QuickChange_CheckForPound)), TRIGGER_FLOOR_TOUCH, COLLIDER_dr_yuka, 1, 0)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_QUICK_CHANGE, -232, 20, -331, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC01_Item_QuickChange)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MerlonShooAway) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_IF_EQ(GF_MAC01_Merlon_Shoo2, TRUE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001E, 160, 40)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_RETURN
            EVT_END_IF
            EVT_IF_EQ(GF_MAC01_Merlon_Shoo1, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001C, 160, 40)
                EVT_SET(GF_MAC01_Merlon_Shoo1, TRUE)
            EVT_ELSE
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001D, 160, 40)
                EVT_SET(GF_MAC01_Merlon_Shoo2, TRUE)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH0_MET_STAR_SPIRITS)
            EVT_IF_EQ(GF_MAC01_Merlon_Shoo3, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_001F, 160, 40)
                EVT_SET(GF_MAC01_Merlon_Shoo3, TRUE)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_MerlonBargeOut))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MerlonBargeOut) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_0020, 160, 40)
    EVT_CALL(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_VISIBLE)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, -80, 15, EASING_COS_FAST_OVERSHOOT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Hurt)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump1, -222, 20, -158, 8 * DT)
        EVT_WAIT(5 * DT)
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
        EVT_CALL(N(KnockdownCreate), SPR_Mario1, 37) //TODO hardcoded player raster ID
        EVT_CALL(N(KnockdownSetPos), -215, 20, -158)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerPos, -215, 1000, -158)
        EVT_CALL(MakeLerp, 0, 90, 10 * DT, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(KnockdownSetRot), LVar0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(N(KnockdownSetPos), -215, 21, -158)
        EVT_CALL(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(50 * DT)
    EVT_CALL(SetNpcPos, NPC_Merlon, -241, 20, -270)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, -168, -198, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(GetAngleToPlayer, NPC_Merlon, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Merlon, LVar0, 5)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0021)
    EVT_CALL(N(KnockdownSetPos), -215, 20, -158)
    EVT_CALL(MakeLerp, 90, 0, 15 * DT, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(KnockdownSetRot), LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, -222, 20, -158)
    EVT_CALL(N(KnockdownDestroy))
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 15 * DT)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0022)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
        EVT_CALL(NpcMoveTo, NPC_Merlon, -275, -305, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
        EVT_CALL(SetNpcPos, NPC_Merlon, -337, 20, -360)
        EVT_CALL(SetNpcYaw, NPC_Merlon, 135)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -168, -198, 20 * DT)
    EVT_CALL(PlayerMoveTo, -275, -305, 30 * DT)
    EVT_EXEC(N(D_8024E7F0_80F070))
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -240, 20, -284)
    EVT_CALL(N(func_802447E0_805060))
    EVT_THREAD
        EVT_SET(LVarF, 53)
        EVT_SET(LVar0, 0)
        EVT_CALL(N(func_802448A0_805120))
    EVT_END_THREAD
    EVT_CALL(RotateGroup, MODEL_off_kabe, 180, 0, 1, 0)
    EVT_SET(MF_MusicMixTrigger1, TRUE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 20, -280)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(N(func_80244848_8050C8))
    EVT_CALL(InterpNpcYaw, NPC_Merlon, 135, 5)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0023)
    EVT_CALL(N(func_802447E0_805060))
    EVT_WAIT(60 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_THREAD
        EVT_CALL(N(func_80244848_8050C8))
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0024)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_NodYesTwice)
    EVT_WAIT(50 * DT)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0025)
    EVT_SET(GB_StoryProgress, STORY_CH1_SPOKE_WITH_MERLIN)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_THREAD
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(AwaitPlayerLeave, -280, -300, 40)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250D14_811594) = {
    EVT_CALL(AwaitPlayerApproach, -130, -110, 150)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
    EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(NpcMoveTo, NPC_Merlon, 0, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_Merlon, 410, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Merlon, 410, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_KoopaBrosUnmasked) = {
    EVT_CALL(SetNpcVar, NPC_Merlon, 0, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(4.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Merlon, 410, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Merlon, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_0029)
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_002A)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar0, 410)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), 410, 0, 0, 320, 15, -6)
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, 460, 0, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_002B)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 480, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_DarkToad_01, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Dismiss, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_002C)
    EVT_CALL(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Dismiss, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_002D)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 410, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_002E)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_Merlon, SOUND_MERLON_GATHER, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Gather1)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 12, LVar0, LVar1, LVar2, 1, 50)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_RaiseArms)
    EVT_WAIT(5 * DT)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, 1, 20)
    EVT_ADD(LVar1, 180)
    EVT_CALL(PlayerFaceNpc, NPC_DarkToad_01, FALSE)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), 480, 0, 0, 320, 15, -6)
    EVT_CALL(PushSong, SONG_KOOPA_BROS_THEME, 0)
    EVT_THREAD
        EVT_SET(MF_KoopaBrosSceneLock, FALSE)
        EVT_WAIT(5)
        EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Hurt, ANIM_KoopaBros_Red_Hurt, 5, MSG_MAC_Plaza_002F)
        EVT_SET(MF_KoopaBrosSceneLock, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_DarkToad_01, LVar3, LVar4, LVar5)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        EVT_CALL(SetNpcAnimation, NPC_DarkToad_01, ANIM_DarkToad_Red_Hurt)
        EVT_WAIT(5 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_DarkToad_01, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcPos, NPC_DarkToad_01, LVar3, NPC_DISPOSE_POS_Y, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_01, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Hurt)
        EVT_CALL(NpcJump0, NPC_KoopaBros_01, LVar3, LVar4, LVar5, 10 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_DarkToad_02, LVar3, LVar4, LVar5)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        EVT_CALL(SetNpcAnimation, NPC_DarkToad_02, ANIM_DarkToad_Black_Hurt)
        EVT_WAIT(5 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_02, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_DarkToad_02, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcPos, NPC_DarkToad_02, LVar3, NPC_DISPOSE_POS_Y, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_02, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Hurt)
        EVT_CALL(NpcJump0, NPC_KoopaBros_02, LVar3, LVar4, LVar5, 10 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_DarkToad_03, LVar3, LVar4, LVar5)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        EVT_CALL(SetNpcAnimation, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Hurt)
        EVT_WAIT(5 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_03, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_DarkToad_03, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcPos, NPC_DarkToad_03, LVar3, NPC_DISPOSE_POS_Y, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_03, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_03, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Hurt)
        EVT_CALL(NpcJump0, NPC_KoopaBros_03, LVar3, LVar4, LVar5, 10 * DT)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_DarkToad_04, LVar3, LVar4, LVar5)
    EVT_ADD(LVar5, 5)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
    EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
    EVT_CALL(SetNpcAnimation, NPC_DarkToad_04, ANIM_DarkToad_Green_Hurt)
    EVT_WAIT(5 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_DarkToad_04, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_DarkToad_04, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcPos, NPC_DarkToad_04, LVar3, NPC_DISPOSE_POS_Y, LVar2)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_04, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_04, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Hurt)
    EVT_CALL(NpcJump0, NPC_KoopaBros_04, LVar3, LVar4, LVar5, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_LOOP(0)
        EVT_IF_EQ(MF_KoopaBrosSceneLock, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0030)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_MAC_Plaza_0031)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 5, MSG_MAC_Plaza_0032)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_02, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_03, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_04, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Run)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Run)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Run)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Run)
    EVT_WAIT(15 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(8.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, 700, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_02, EVT_FLOAT(8.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, 700, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_03, EVT_FLOAT(8.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_03, 700, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros_04, EVT_FLOAT(8.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_04, 700, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(PopSong)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 410, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0033)
    EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(3.0 / DT))
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, LVar3, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0034)
    EVT_THREAD
        EVT_WAIT(10 * DT)
#if VERSION_PAL
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.6669921875))
#else
        EVT_CALL(ResetCam, CAM_DEFAULT, 2)
#endif
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -150)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    EVT_CALL(NpcMoveTo, NPC_Merlon, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Merlon, 133, 0)
    EVT_CALL(SetNpcPos, NPC_Merlon, -337, 20, -360)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
    EVT_SET(AF_MAC_0E, FALSE)
    EVT_SET(AF_MAC_0F, FALSE)
    EVT_SET(AF_MAC_10, FALSE)
    EVT_SET(AF_MAC_11, FALSE)
    EVT_SET(AF_MAC_12, FALSE)
    EVT_SET(AF_MAC_13, FALSE)
    EVT_SET(AF_MAC_14, FALSE)
    EVT_CALL(RemoveEncounter, NPC_KoopaBros_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Merlon) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_IF_EQ(GF_MAC01_Merlon_HintFromDarkToads, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0026)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0027)
                EVT_SET(GB_StoryProgress, STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
                EVT_CHILD_THREAD
                    EVT_LOOP(0)
                        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CHILD_THREAD
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(4.0 / DT))
                EVT_CALL(NpcMoveTo, NPC_Merlon, -350, -280, 0)
                EVT_CALL(NpcMoveTo, NPC_Merlon, -230, -270, 0)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
                EVT_CALL(MakeLerp, 0, -80, 15, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(NpcMoveTo, NPC_Merlon, -163, -217, 0)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(MakeLerp, -80, 0, 15, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
                EVT_CALL(SetNpcPos, NPC_SELF, -150, 10, -160)
                EVT_CALL(SetNpcYaw, NPC_Merlon, 90)
                EVT_EXEC(N(D_80250D14_811594))
            EVT_END_IF
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0028)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0035)
        EVT_CASE_EQ(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_004C)
        EVT_CASE_GE(STORY_CH3_GOT_SUPER_BOOTS)
            EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_003E)
                EVT_IF_GE(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
                        EVT_SET(LVar0, MSG_MAC_Plaza_003D)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, LVar0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(GetNpcPos, NPC_Merlon, LVar3, LVar4, LVar5)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_ADDF(LVar0, LVar3)
                EVT_ADDF(LVar1, LVar4)
                EVT_ADDF(LVar2, LVar5)
                EVT_DIVF(LVar0, EVT_FLOAT(2.0))
                EVT_DIVF(LVar1, EVT_FLOAT(2.0))
                EVT_DIVF(LVar2, EVT_FLOAT(2.0))
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003F)
                EVT_THREAD
                    EVT_LOOP(0)
                        EVT_CALL(PlayerFaceNpc, NPC_Merlon, FALSE)
                        EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, TRUE)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_Merlon, -170, -225, 0)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                EVT_CALL(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_VISIBLE)
                EVT_EXEC_WAIT(N(D_8024E740_80EFC0))
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                EVT_CALL(SetNpcSpeed, NPC_Merlon, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_Merlon, -265, -300, 0)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                EVT_EXEC_WAIT(N(D_8024E7F0_80F070))
                EVT_CALL(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_HIDDEN)
                EVT_SET(GF_MAC01_Merlon_HeardAboutDream, TRUE)
                EVT_CALL(InterpNpcYaw, NPC_Merlon, 133, 0)
                EVT_CALL(SetNpcPos, NPC_Merlon, -337, 20, -360)
                EVT_CALL(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                EVT_RETURN
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_QuickChangeDropped, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0040)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_003B)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_003B)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Merlon))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Merlon))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Merlon) = {
    EVT_CALL(InterpNpcYaw, NPC_SELF, 133, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_CALL(SetNpcPos, NPC_SELF, 410, 0, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_RANGE(STORY_CH6_RETURNED_TO_TOAD_TOWN, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_GE(STORY_CH3_GOT_SUPER_BOOTS)
            EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                EVT_CALL(SetNpcPos, NPC_Merlon, -135, 20, -250)
                EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Think)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
            EVT_ELSE
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Merlon)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_DarkToad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_004D)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_004E)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Talk, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_004F)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Talk, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_0050)
        EVT_CASE_LT(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), 0, 300, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_0051)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_0052)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Talk, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_0053)
            EVT_CALL(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Talk, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_0054)
            EVT_SET(GF_MAC01_Merlon_HintFromDarkToads, TRUE)
#if VERSION_PAL
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
#else
            EVT_CALL(ResetCam, CAM_DEFAULT, 5)
#endif
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_DarkToad_01) = {
    EVT_LOOP(0)
        EVT_IF_GE(GB_StoryProgress, STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            EVT_SET(LVar0, 0)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_SWITCH(LVar1)
                EVT_CASE_GE(460)
                    EVT_ADD(LVar0, 1)
            EVT_END_SWITCH
            EVT_SWITCH(LVar3)
                EVT_CASE_RANGE(-50, 70)
                    EVT_ADD(LVar0, 1)
            EVT_END_SWITCH
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(PartnerCanUseAbility, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_Scene_KoopaBrosUnmasked))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DarkToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_DarkToad_01)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_DarkToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DarkToad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_DarkToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MerlonAndNinji) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Ninji, -278, 20, -376)
    EVT_CALL(SetNpcYaw, NPC_Ninji, 0)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, -276, -305, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0047)
    EVT_CALL(NpcFacePlayer, NPC_Ninji, 5)
    EVT_WAIT(15 * DT)
    EVT_CALL(GetNpcPos, NPC_Ninji, LVar0, LVar1, LVar2)
#if VERSION_PAL
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), LVar0, LVar1, LVar2, 250, 15, -9)
#else
    EVT_CALL(SetCamProperties, CAM_DEFAULT, 4, LVar0, LVar1, LVar2, 250, 15, -9)
#endif
    EVT_CALL(SpeakToPlayer, NPC_Ninji, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_MAC_Plaza_0048)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0049)
#if VERSION_PAL
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
#else
    EVT_CALL(ResetCam, CAM_DEFAULT, 5)
#endif
    EVT_CALL(SpeakToPlayer, NPC_Ninji, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_MAC_Plaza_004A)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Ninji, ANIM_Ninji_Walk)
        EVT_CALL(NpcMoveTo, NPC_Ninji, -230, -260, 0)
        EVT_CALL(NpcMoveTo, NPC_Ninji, -185, -194, 0)
        EVT_CALL(SetNpcPos, NPC_Ninji, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(25 * DT)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5 * DT)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_004B)
    EVT_SET(GB_StoryProgress, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Merlon) = {
    .defaultAnim = ANIM_Merlon_Idle,
    .height = 36,
    .radius = 32,
    .level = ACTOR_LEVEL_NONE,
};

NpcData N(NpcData_Merlon) = {
    .id = NPC_Merlon,
    .pos = { -337.0f, 20.0f, -360.0f },
    .yaw = 30,
    .init = &N(EVS_NpcInit_Merlon),
    .settings = &N(NpcSettings_Merlon),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Merlon_Idle,
    },
    .tattle = MSG_NpcTattle_Merlon,
};

NpcData N(NpcData_DarkToads)[] = {
    {
        .id = NPC_DarkToad_01,
        .pos = { 505.0f, 0.0f, 5.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_DarkToad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_DarkToad_Red_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadA,
    },
    {
        .id = NPC_DarkToad_02,
        .pos = { 530.0f, 0.0f, -35.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_DarkToad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_DarkToad_Black_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadB,
    },
    {
        .id = NPC_DarkToad_03,
        .pos = { 540.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_DarkToad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_DarkToad_Yellow_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadC,
    },
    {
        .id = NPC_DarkToad_04,
        .pos = { 550.0f, 0.0f, 35.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_DarkToad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_DarkToad_Green_Idle,
        },
        .tattle = MSG_NpcTattle_DarkToadD,
    },
};

AnimID N(ExtraAnims_KoopaBros)[] = {
    ANIM_KoopaBros_Black_Run,
    ANIM_KoopaBros_Black_Idle,
    ANIM_KoopaBros_Black_Hurt,
    ANIM_KoopaBros_Black_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Black_Idle,
            .walk   = ANIM_KoopaBros_Black_Walk,
            .run    = ANIM_KoopaBros_Black_Run,
            .chase  = ANIM_KoopaBros_Black_Run,
            .anim_4 = ANIM_KoopaBros_Black_Idle,
            .anim_5 = ANIM_KoopaBros_Black_Idle,
            .death  = ANIM_KoopaBros_Black_HurtStill,
            .hit    = ANIM_KoopaBros_Black_HurtStill,
            .anim_8 = ANIM_KoopaBros_Black_Run,
            .anim_9 = ANIM_KoopaBros_Black_Run,
            .anim_A = ANIM_KoopaBros_Black_Run,
            .anim_B = ANIM_KoopaBros_Black_Run,
            .anim_C = ANIM_KoopaBros_Black_Run,
            .anim_D = ANIM_KoopaBros_Black_Run,
            .anim_E = ANIM_KoopaBros_Black_Run,
            .anim_F = ANIM_KoopaBros_Black_Run,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBros_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Red_Idle,
            .walk   = ANIM_KoopaBros_Red_Walk,
            .run    = ANIM_KoopaBros_Red_Run,
            .chase  = ANIM_KoopaBros_Red_Run,
            .anim_4 = ANIM_KoopaBros_Red_Idle,
            .anim_5 = ANIM_KoopaBros_Red_Idle,
            .death  = ANIM_KoopaBros_Red_HurtStill,
            .hit    = ANIM_KoopaBros_Red_HurtStill,
            .anim_8 = ANIM_KoopaBros_Red_Run,
            .anim_9 = ANIM_KoopaBros_Red_Run,
            .anim_A = ANIM_KoopaBros_Red_Run,
            .anim_B = ANIM_KoopaBros_Red_Run,
            .anim_C = ANIM_KoopaBros_Red_Run,
            .anim_D = ANIM_KoopaBros_Red_Run,
            .anim_E = ANIM_KoopaBros_Red_Run,
            .anim_F = ANIM_KoopaBros_Red_Run,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBros_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Yellow_Idle,
            .walk   = ANIM_KoopaBros_Yellow_Walk,
            .run    = ANIM_KoopaBros_Yellow_Run,
            .chase  = ANIM_KoopaBros_Yellow_Run,
            .anim_4 = ANIM_KoopaBros_Yellow_Idle,
            .anim_5 = ANIM_KoopaBros_Yellow_Idle,
            .death  = ANIM_KoopaBros_Yellow_HurtStill,
            .hit    = ANIM_KoopaBros_Yellow_HurtStill,
            .anim_8 = ANIM_KoopaBros_Yellow_Run,
            .anim_9 = ANIM_KoopaBros_Yellow_Run,
            .anim_A = ANIM_KoopaBros_Yellow_Run,
            .anim_B = ANIM_KoopaBros_Yellow_Run,
            .anim_C = ANIM_KoopaBros_Yellow_Run,
            .anim_D = ANIM_KoopaBros_Yellow_Run,
            .anim_E = ANIM_KoopaBros_Yellow_Run,
            .anim_F = ANIM_KoopaBros_Yellow_Run,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBros_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Green_Idle,
            .walk   = ANIM_KoopaBros_Green_Walk,
            .run    = ANIM_KoopaBros_Green_Run,
            .chase  = ANIM_KoopaBros_Green_Run,
            .anim_4 = ANIM_KoopaBros_Green_Idle,
            .anim_5 = ANIM_KoopaBros_Green_Idle,
            .death  = ANIM_KoopaBros_Green_HurtStill,
            .hit    = ANIM_KoopaBros_Green_HurtStill,
            .anim_8 = ANIM_KoopaBros_Green_Run,
            .anim_9 = ANIM_KoopaBros_Green_Run,
            .anim_A = ANIM_KoopaBros_Green_Run,
            .anim_B = ANIM_KoopaBros_Green_Run,
            .anim_C = ANIM_KoopaBros_Green_Run,
            .anim_D = ANIM_KoopaBros_Green_Run,
            .anim_E = ANIM_KoopaBros_Green_Run,
            .anim_F = ANIM_KoopaBros_Green_Run,
        },
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
};

NpcData N(NpcData_Ninji) = {
    .id = NPC_Ninji,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .settings = &N(NpcSettings_Ninji),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Ninji_Idle,
        .walk   = ANIM_Ninji_Walk,
        .run    = ANIM_Ninji_Idle,
        .chase  = ANIM_Ninji_Idle,
        .anim_4 = ANIM_Ninji_Idle,
        .anim_5 = ANIM_Ninji_Idle,
        .death  = ANIM_Ninji_Idle,
        .hit    = ANIM_Ninji_Idle,
        .anim_8 = ANIM_Ninji_Idle,
        .anim_9 = ANIM_Ninji_Idle,
        .anim_A = ANIM_Ninji_Idle,
        .anim_B = ANIM_Ninji_Idle,
        .anim_C = ANIM_Ninji_Idle,
        .anim_D = ANIM_Ninji_Idle,
        .anim_E = ANIM_Ninji_Idle,
        .anim_F = ANIM_Ninji_Idle,
    },
    .tattle = MSG_NpcTattle_MAC_PowerHungryToadKid,
};

BSS PopupMenu D_80262C38;
BSS s32 D_80262F68;
BSS s32 D_80262F6C[13];

#include "npc/rowf_and_rhuff.inc.c"
#include "npc/post_office.inc.c"
#include "npc/flower_gate.inc.c"

EvtScript N(EVS_NpcIdle_Toad_04) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Plaza_007D)
    EVT_SET(GB_StoryProgress, STORY_CH0_RETURNED_TO_TOAD_TOWN)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_007C)
        EVT_CASE_LT(STORY_CH1_SPOKE_WITH_MERLIN)
            EVT_SET(LVar0, MSG_MAC_Plaza_007D)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_007E)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_007F)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_0080)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0081)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_0082)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Plaza_0083)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Plaza_0084)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Plaza_0085)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0086)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Plaza_0087)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0088)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Plaza_0089)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_008A)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_008B)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0046)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(SetNpcPos, NPC_SELF, -25, 0, -500)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_04)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_008C)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Plaza_008D)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_008E)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_008F)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_0090)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0091)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_0092)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Plaza_0093)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Plaza_0094)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Plaza_0095)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0096)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Plaza_0097)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0098)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Plaza_0099)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_009A)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_009B)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0047)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_05) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025AA78_81B2F8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_Toad_05, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_0048)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, 0, 580, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_05)))
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -50, 0, 580)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_05)))
        EVT_BIND_TRIGGER(EVT_PTR(N(D_8025AA78_81B2F8)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilis, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_009C)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Plaza_009D)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_009E)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_009F)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_00A0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00A1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_00A2)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Plaza_00A3)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Plaza_00A4)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00A5)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00A6)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00A7)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00A8)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Plaza_00A9)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00AA)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00AB)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0049)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_06, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_06) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_06)))
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -110, 20, -380)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_06)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_07) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00AC)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00AD)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00AE)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_00AF)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_00B0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00B1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_00B2)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Plaza_00B3)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Plaza_00B4)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00B5)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00B6)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00B7)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00B8)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Plaza_00B9)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00BA)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00BB)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_004A)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_07) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025B110_81B990) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_Toad_07, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_Outro_004B)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, 600, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_07) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_07)))
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, 530, 0, -50)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_07)))
        EVT_BIND_TRIGGER(EVT_PTR(N(D_8025B110_81B990)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilie, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_08) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00BC)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00BD)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00BE)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_00BF)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_00C0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_ShyGuysTramplingGarden, FALSE)
            EVT_ELSE
                EVT_SET(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
                EVT_ADD(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LVar0, MSG_MAC_Plaza_00C2)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Plaza_00C3)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C4)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C5)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C6)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C7)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C8)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00C9)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00CA)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_004C)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_08, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_08) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_08)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_09) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00CB)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00CC)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00CD)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_00CE)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_00CF)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D0)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Plaza_00D1)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Plaza_00D2)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Plaza_00D3)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D4)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D5)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D6)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D7)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D8)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_00D9)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_00DA)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_004D)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_09, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_09) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_09)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025B760_81BFE0) = {
    EVT_CALL(GetNpcPos, NPC_PostOfficeShyGuy, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_CALCULATOR, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(80)
        EVT_CALL(GetNpcPos, NPC_PostOfficeShyGuy, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025B854_81C0D4) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar2, 200)
            EVT_IF_LT(LVar0, 50)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_PostOfficeShyGuy, -313, 0, 330)
    EVT_CALL(SetNpcAnimation, NPC_PostOfficeShyGuy, ANIM_ShyGuy_Red_Anim04)
    EVT_WAIT(21)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0007)
    EVT_EXEC(N(D_8025B760_81BFE0))
    EVT_SET(LVar0, 6)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVarA)
    EVT_CALL(NpcMoveTo, NPC_PostOfficeShyGuy, -45, 330, 30)
    EVT_CALL(NpcMoveTo, NPC_PostOfficeShyGuy, -45, 710, 30)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_PostOfficeShyGuy, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC01_CalculatorStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_MAC01_CalculatorStolen, TRUE)
    EVT_EXEC(N(D_8025B854_81C0D4))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadHouseKeeper_A) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Plaza_001A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadHouseKeeper_B) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_0044)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_IF_EQ(AF_MAC_43, FALSE)
        EVT_SET(LVar0, MSG_MAC_Plaza_0015)
        EVT_SET(LVar8, MSG_MAC_Plaza_0016)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Plaza_001B)
        EVT_SET(LVar8, MSG_MAC_Plaza_001B)
    EVT_END_IF
    EVT_SET(LVar1, MSG_MAC_Plaza_0017)
    EVT_SET(LVar2, MSG_MAC_Plaza_0018)
    EVT_SET(LVar3, MSG_MAC_Plaza_0019)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(PlayerMoveTo, 535, -155, 20)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 116)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 99, -58)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 495, 130)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 507, -19)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 20)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 580, -210, 20)
    EVT_CALL(InterpPlayerYaw, 263, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(63)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(SetPlayerPos, 568, 20, -186)
    EVT_CALL(PlayerMoveTo, 525, -168, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_SELF, 370, 20, -150)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper_B)))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_ChasedShyGuyFromToadHouse, FALSE)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper_A)))
            EVT_CASE_DEFAULT
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_END_IF
    EVT_SET(AF_MAC_43, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_02) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 572, 36, -226)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_WAIT(3)
        EVT_IF_EQ(MF_InsideToadHouse, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_END_IF
        EVT_CALL(NpcJump0, NPC_SELF, 539, 36, -242, 8)
        EVT_WAIT(2)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_WAIT(3)
        EVT_IF_EQ(MF_InsideToadHouse, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_END_IF
        EVT_CALL(NpcJump0, NPC_SELF, 572, 36, -226, 8)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy_02) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 36, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, 550, 20, -161, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit2u, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit2u, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_SET(LVar0, -1)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVarA)
    EVT_CALL(NpcMoveTo, NPC_SELF, 420, -118, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(BindNpcInteract, NPC_ToadHouseToad, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_SET(LVar1, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 0)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(CheckPositionRelativeToPlane), 450, -190, 500, -103)
    EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_NONE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    EVT_SET(GF_MAC01_ChasedShyGuyFromToadHouse, TRUE)
    EVT_SET(AF_MAC_43, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_02)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    EVT_IF_EQ(GF_MAC01_ChasedShyGuyFromToadHouse, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_02)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy_02)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath_TwinkArrive)[] = {
    {  -80.0,   106.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {    0.0,     0.0,    0.0 },
};

Vec3f N(FlightPath_TwinkDepart)[] = {
    {    0.0,     0.0,    0.0 },
    {  -50.0,    30.0,    0.0 },
    {  -70.0,   106.0,    0.0 },
};

EvtScript N(EVS_NpcIdle_Twink) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 560)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 500, -20, 0)
    EVT_CALL(WaitForPlayerMoveToComplete)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Plaza_00DB, 160, 40)
    EVT_LOOP(2)
        EVT_CALL(InterpPlayerYaw, 90, 7)
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpPlayerYaw, 270, 7)
        EVT_WAIT(10 * DT)
    EVT_END_LOOP
    EVT_WAIT(30 * DT)
    EVT_CALL(GetPlayerPos, LVar4, LVar5, LVar6)
    EVT_SUBF(LVar4, EVT_FLOAT(50.0))
    EVT_ADDF(LVar5, EVT_FLOAT(40.0))
    EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
    EVT_CALL(LoadPath, 35 * DT, EVT_PTR(N(FlightPath_TwinkArrive)), ARRAY_COUNT(N(FlightPath_TwinkArrive)), EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0/ DT), -10, -300, 15, -9)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DC)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DD)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Chuckle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), -40, -200, 15, -15)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DE)
    EVT_WAIT(5 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 35 * DT, EVT_PTR(N(FlightPath_TwinkDepart)), ARRAY_COUNT(N(FlightPath_TwinkDepart)), EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_ADD(LVar3, LVar6)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(GB_StoryProgress, STORY_CH1_RETURNED_TO_TOAD_TOWN)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Twink)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00DF)
    EVT_EXEC_WAIT(N(EVS_ArtifactPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_RETURNED_TO_TOAD_TOWN, STORY_CH7_BEGAN_PEACH_MISSION)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_ELSE
                EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Toad)[] = {
    ANIM_Toad_Red_Still,
    ANIM_Toad_Red_Idle,
    ANIM_Toad_Red_Walk,
    ANIM_Toad_Red_Run,
    ANIM_Toad_Red_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bubulb)[] = {
    ANIM_Bubulb_Pink_Idle,
    ANIM_Bubulb_Pink_EmbedIdle,
    ANIM_Bubulb_Pink_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_Toad_04,
        .pos = { -94.0f, 0.0f, -117.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_RunsHisMouth,
    },
    {
        .id = NPC_Toad_05,
        .pos = { -145.0f, 0.0f, -25.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_05),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_KnowsTheGossip,
    },
    {
        .id = NPC_Toad_06,
        .pos = { 40.0f, 0.0f, -300.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 40, 0, -300 },
                    { -40, 0, -300 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_06),
        .settings = &N(NpcSettings_Toad_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_PrincessFan,
    },
    {
        .id = NPC_Toad_07,
        .pos = { -440.0f, 0.0f, -20.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -440, 0, -20 },
                    { 350, 0, -20 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_07),
        .settings = &N(NpcSettings_Toad_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_KnowsTheRumors,
    },
    {
        .id = NPC_Toad_08,
        .pos = { 400.0f, 20.0f, 260.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 400, 20, 260 },
                    { 490, 20, 260 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_08),
        .settings = &N(NpcSettings_Toad_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_CrushingOnMinhT,
    },
    {
        .id = NPC_Toad_09,
        .pos = { -380.0f, 20.0f, -100.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_09),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_SeeksTheSouth,
    },
    {
        .id = NPC_ToadHouseToad,
        .pos = { 488.0f, 20.0f, -174.0f },
        .yaw = 30,
        .init = &N(EVS_NpcInit_ToadHouseKeeper),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
        .tattle = MSG_NpcTattle_MAC_ToadHouseToad,
    },
    {
        .id = NPC_Bubulb,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bubulb),
        .settings = &N(NpcSettings_Bubulb),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_PINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Bubulb),
        .tattle = MSG_NpcTattle_MAC_FlowerGateBubulb,
    },
    {
        .id = NPC_MinhT,
        .pos = { 150.0f, 20.0f, 485.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MinhT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_MinhT_Idle,
        },
        .tattle = MSG_NpcTattle_MinhT,
    },
    {
        .id = NPC_Postmaster,
        .pos = { 312.0f, 30.0f, -438.0f },
        .yaw = 300,
        .init = &N(EVS_NpcInit_Postmaster),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Postmaster_Idle,
        },
        .tattle = MSG_NpcTattle_Postmaster,
    },
};

NpcData N(NpcData_Parakarry) = {
    .id = NPC_Parakarry,
    .pos = { 145.0f, 20.0f, -472.0f },
    .yaw = 120,
    .init = &N(EVS_NpcInit_Parakarry),
    .settings = &N(NpcSettings_Parakarry),
    .flags = COMMON_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldParakarry_Idle,
        .walk   = ANIM_WorldParakarry_Walk,
        .run    = ANIM_WorldParakarry_Run,
        .chase  = ANIM_WorldParakarry_Run,
        .anim_4 = ANIM_WorldParakarry_Idle,
        .anim_5 = ANIM_WorldParakarry_Idle,
        .death  = ANIM_WorldParakarry_Still,
        .hit    = ANIM_WorldParakarry_Still,
        .anim_8 = ANIM_WorldParakarry_Idle,
        .anim_9 = ANIM_WorldParakarry_Idle,
        .anim_A = ANIM_WorldParakarry_Idle,
        .anim_B = ANIM_WorldParakarry_Idle,
        .anim_C = ANIM_WorldParakarry_Idle,
        .anim_D = ANIM_WorldParakarry_Idle,
        .anim_E = ANIM_WorldParakarry_Idle,
        .anim_F = ANIM_WorldParakarry_Idle,
    },
    .extraAnimations = N(ExtraAnims_Parakarry),
    .tattle = MSG_NpcTattle_MAC_Parakarry,
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Twink) = {
    .id = NPC_Twink,
    .pos = { -350.0f, 20.0f, -100.0f },
    .yaw = 274,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_Twink),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

NpcData N(NpcData_ShyGuys)[] = {
    {
        .id = NPC_PostOfficeShyGuy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ToadHouseShyGuy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_02),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_GardenShyGuy1,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GardenShyGuy1),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_GardenShyGuy2,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GardenShyGuy2),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

AnimID N(ExtraAnims_Kolorado)[] = {
    ANIM_Kolorado_Still,
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { 520.0f, 0.0f, -25.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .extraAnimations = N(ExtraAnims_Kolorado),
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { -440.0f, 20.0f, -140.0f },
    .yaw = 30,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_01 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_RowfAndRhuff)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(Chapter0NPCs) = {
    NPC_GROUP(N(NpcData_Parakarry)),
    NPC_GROUP(N(NpcData_KoopaBros)),
    NPC_GROUP(N(NpcData_DarkToads)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_RowfAndRhuff)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};

NpcGroupList N(Chapter1NPCs) = {
    NPC_GROUP(N(NpcData_Parakarry)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_RowfAndRhuff)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};

NpcGroupList N(TwinkMeetingNPCs) = {
    NPC_GROUP(N(NpcData_Twink)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_RowfAndRhuff)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};

NpcGroupList N(Chapter4NPCs) = {
    NPC_GROUP(N(NpcData_ShyGuys)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_RowfAndRhuff)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};

NpcGroupList N(NinjiMeetingNPCs) = {
    NPC_GROUP(N(NpcData_Ninji)),
    NPC_GROUP(N(NpcData_Merlon)),
    NPC_GROUP(N(NpcData_RowfAndRhuff)),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};

