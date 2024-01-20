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
    Call(N(LetterDelivery_Init),
        NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle,
        ITEM_LETTER_TO_MERLON, ITEM_NONE,
        MSG_MAC_Plaza_0043, MSG_MAC_Plaza_0044, MSG_MAC_Plaza_0045, MSG_MAC_Plaza_0046,
        Ref(N(LetterList_Merlon)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Merlon) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
        Call(InterpNpcYaw, NPC_Merlon, 135, 0)
    EndIf
    Return
    End
};

s32 N(LetterList_MinhT)[] = {
    ITEM_LETTER_TO_MINH_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_MinhT) = {
    Call(N(LetterDelivery_Init),
        NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle,
        ITEM_LETTER_TO_MINH_T, ITEM_NONE,
        MSG_MAC_Plaza_0078, MSG_MAC_Plaza_0079, MSG_MAC_Plaza_007A, MSG_MAC_Plaza_007B,
        Ref(N(LetterList_MinhT)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_MinhT) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

s32 N(LetterList_Kolorado)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    Call(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_MAC_Plaza_00E0, MSG_MAC_Plaza_00E1, MSG_MAC_Plaza_00E2, MSG_MAC_Plaza_00E3,
        Ref(N(LetterList_Kolorado)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

s32 N(ItemList_Artifact)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactReward_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E8)
    EVT_GIVE_STAR_PIECE()
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E9)
    Set(GF_SBK_GaveArtifactToKolorado, TRUE)
    Return
    End
};

EvtScript N(EVS_ArtifactPrompt_Kolorado) = {
    IfEq(GF_SBK_GaveArtifactToKolorado, TRUE)
        Return
    EndIf
    Call(FindKeyItem, ITEM_ARTIFACT, LVar0)
    IfEq(LVar0, -1)
        Return
    EndIf
    IfEq(AF_MAC_44, FALSE)
        Set(AF_MAC_44, TRUE)
        IfEq(GF_SBK_KeptArtifactFromKolorado, FALSE)
            Set(GF_SBK_KeptArtifactFromKolorado, FALSE)
            Set(LVar0, MSG_MAC_Plaza_00E4)
        Else
            Set(LVar0, MSG_MAC_Plaza_00E5)
        EndIf
    Else
        Set(LVar0, MSG_MAC_Plaza_00E5)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    Set(LVar0, Ref(N(ItemList_Artifact)))
    Set(LVar1, 19)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseGe(1)
            ExecWait(N(EVS_ArtifactReward_Kolorado))
            BreakSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E6)
            Set(LVar0, Ref(N(ItemList_Artifact)))
            Set(LVar1, 19)
            ExecWait(N(EVS_ChooseKeyItem))
            Switch(LVar0)
                CaseGe(1)
                    ExecWait(N(EVS_ArtifactReward_Kolorado))
                CaseDefault
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00E7)
            EndSwitch
    EndSwitch
    Return
    End
};

EvtScript N(D_8024E6F8_80EF78) = {
    Loop(0)
        Call(PlaySoundAtNpc, LVar0, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(D_8024E740_80EFC0) = {
    Call(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -80, 30, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(D_8024E7F0_80F070) = {
    Call(MakeLerp, -80, 0, 30, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
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
    Call(GetPlayerActionState, LVar0)
    IfEq(LVar0, ACTION_STATE_SPIN_POUND)
        Goto(0)
    EndIf
    IfEq(LVar0, ACTION_STATE_TORNADO_POUND)
        Goto(0)
    EndIf
    Return
    Label(0)
    Call(GetPlayerActionState, LVar0)
    Call(DisablePlayerInput, TRUE)
    Wait(1)
    Call(DisablePlayerInput, FALSE)
    IfEq(LVar0, ACTION_STATE_SPIN_POUND)
        Goto(0)
    EndIf
    IfEq(LVar0, ACTION_STATE_TORNADO_POUND)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Add(GB_MAC01_Merlon_SpinJumpCount, 1)
    IfLt(GB_MAC01_Merlon_SpinJumpCount, 3)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(N(CheckPositionRelativeToPlane), -380, -245, -225, -408)
    IfEq(LVar0, ACTION_STATE_IDLE)
        Set(LVar2, -232)
        Set(LVar4, -331)
    Else
        Set(LVar2, -297)
        Set(LVar4, -393)
    EndIf
    Call(MakeItemEntity, ITEM_QUICK_CHANGE, LVar2, 220, LVar4, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_MAC01_Item_QuickChange)
    Wait(35)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Run)
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Merlon, LVar0, LVar1, LVar2, 10)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamType, CAM_DEFAULT, 0, FALSE)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, 15, -8)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PlayerFaceNpc, NPC_Merlon, FALSE)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 5, MSG_MAC_Plaza_0041)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0042)
    Set(GF_MAC01_QuickChangeDropped, TRUE)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupQuickChangeTrigger) = {
    IfEq(GF_MAC01_QuickChangeDropped, FALSE)
        BindTrigger(Ref(N(EVS_QuickChange_CheckForPound)), TRIGGER_FLOOR_TOUCH, COLLIDER_dr_yuka, 1, 0)
    Else
        Call(MakeItemEntity, ITEM_QUICK_CHANGE, -232, 20, -331, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC01_Item_QuickChange)
    EndIf
    Return
    End
};

EvtScript N(EVS_MerlonShooAway) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            IfEq(GF_MAC01_Merlon_Shoo2, TRUE)
                Call(ShowMessageAtScreenPos, MSG_MAC_Plaza_001E, 160, 40)
                Call(DisablePlayerInput, FALSE)
                Return
            EndIf
            IfEq(GF_MAC01_Merlon_Shoo1, FALSE)
                Call(ShowMessageAtScreenPos, MSG_MAC_Plaza_001C, 160, 40)
                Set(GF_MAC01_Merlon_Shoo1, TRUE)
            Else
                Call(ShowMessageAtScreenPos, MSG_MAC_Plaza_001D, 160, 40)
                Set(GF_MAC01_Merlon_Shoo2, TRUE)
            EndIf
        CaseGe(STORY_CH0_MET_STAR_SPIRITS)
            IfEq(GF_MAC01_Merlon_Shoo3, FALSE)
                Call(ShowMessageAtScreenPos, MSG_MAC_Plaza_001F, 160, 40)
                Set(GF_MAC01_Merlon_Shoo3, TRUE)
            Else
                ExecWait(N(EVS_MerlonBargeOut))
            EndIf
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MerlonBargeOut) = {
    Call(ShowMessageAtScreenPos, MSG_MAC_Plaza_0020, 160, 40)
    Call(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_VISIBLE)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_deilitd, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, -80, 15, EASING_COS_FAST_OVERSHOOT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
    EndThread
    Thread
        Wait(1)
        Call(DisablePlayerPhysics, TRUE)
        Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
        Call(InterpPlayerYaw, 270, 0)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Hurt)
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump1, -222, 20, -158, 8 * DT)
        Wait(5 * DT)
        Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
        Call(N(KnockdownCreate), SPR_Mario1, 37) //TODO hardcoded player raster ID
        Call(N(KnockdownSetPos), -215, 20, -158)
        Wait(1)
        Call(SetPlayerPos, -215, 1000, -158)
        Call(MakeLerp, 0, 90, 10 * DT, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(N(KnockdownSetRot), LVar0, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(N(KnockdownSetPos), -215, 21, -158)
        Call(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(50 * DT)
    Call(SetNpcPos, NPC_Merlon, -241, 20, -270)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    Call(NpcMoveTo, NPC_Merlon, -168, -198, 20 * DT)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Call(GetAngleToPlayer, NPC_Merlon, LVar0)
    Call(InterpNpcYaw, NPC_Merlon, LVar0, 5)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0021)
    Call(N(KnockdownSetPos), -215, 20, -158)
    Call(MakeLerp, 90, 0, 15 * DT, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(N(KnockdownSetRot), LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerPos, -222, 20, -158)
    Call(N(KnockdownDestroy))
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(PlayerJump, LVar0, LVar1, LVar2, 15 * DT)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0022)
    Thread
        Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
        Call(NpcMoveTo, NPC_Merlon, -275, -305, 30 * DT)
        Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
        Call(SetNpcPos, NPC_Merlon, -337, 20, -360)
        Call(SetNpcYaw, NPC_Merlon, 135)
    EndThread
    Call(PlayerMoveTo, -168, -198, 20 * DT)
    Call(PlayerMoveTo, -275, -305, 30 * DT)
    Exec(N(D_8024E7F0_80F070))
    Wait(5 * DT)
    Call(SetNpcPos, NPC_PARTNER, -240, 20, -284)
    Call(N(func_802447E0_805060))
    Thread
        Set(LVarF, 53)
        Set(LVar0, 0)
        Call(N(func_802448A0_805120))
    EndThread
    Call(RotateGroup, MODEL_off_kabe, 180, 0, 1, 0)
    Set(MF_MusicMixTrigger1, TRUE)
    Call(DisablePlayerPhysics, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, -250, 20, -280)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30 * DT)
    Call(N(func_80244848_8050C8))
    Call(InterpNpcYaw, NPC_Merlon, 135, 5)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0023)
    Call(N(func_802447E0_805060))
    Wait(60 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    Thread
        Call(N(func_80244848_8050C8))
    EndThread
    Wait(10 * DT)
    Call(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0024)
    Call(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_MarioW2_NodYesTwice)
    Wait(50 * DT)
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Call(SetCamType, CAM_DEFAULT, 0, FALSE)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Call(SetCamPitch, CAM_DEFAULT, 15, -10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0025)
    Set(GB_StoryProgress, STORY_CH1_SPOKE_WITH_MERLIN)
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Thread
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        Call(AwaitPlayerLeave, -280, -300, 40)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EndThread
    Return
    End
};

EvtScript N(D_80250D14_811594) = {
    Call(AwaitPlayerApproach, -130, -110, 150)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
    Call(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
    Call(NpcMoveTo, NPC_Merlon, 0, 0, 0)
    Call(NpcMoveTo, NPC_Merlon, 410, 0, 0)
    Call(SetNpcPos, NPC_Merlon, 410, 0, 0)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
    Call(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
    Return
    End
};

EvtScript N(EVS_Scene_KoopaBrosUnmasked) = {
    Call(SetNpcVar, NPC_Merlon, 0, 0)
    Call(func_802CF56C, 2)
    Thread
        Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
        Call(SetNpcSpeed, NPC_Merlon, Float(4.0 / DT))
        Call(NpcMoveTo, NPC_Merlon, 410, 0, 0)
        Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
        Call(InterpNpcYaw, NPC_Merlon, 90, 0)
    EndThread
    Call(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_0029)
    Call(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_002A)
    Loop(0)
        Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
        IfGe(LVar0, 410)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetCamProperties, CAM_DEFAULT, Float(4.0), 410, 0, 0, 320, 15, -6)
    Thread
        Wait(5 * DT)
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, 460, 0, 0)
        Call(PlayerFaceNpc, NPC_Merlon, FALSE)
    EndThread
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_002B)
    Call(SetPanTarget, CAM_DEFAULT, 480, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Wait(5 * DT)
        Call(PlayerFaceNpc, NPC_DarkToad_01, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Dismiss, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_002C)
    Call(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Dismiss, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_002D)
    Call(SetPanTarget, CAM_DEFAULT, 410, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Wait(5 * DT)
        Call(PlayerFaceNpc, NPC_Merlon, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_002E)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PlaySoundAtNpc, NPC_Merlon, SOUND_MERLON_GATHER, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Gather1)
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 12, LVar0, LVar1, LVar2, 1, 50)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_RaiseArms)
    Wait(5 * DT)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, 1, 20)
    Add(LVar1, 180)
    Call(PlayerFaceNpc, NPC_DarkToad_01, FALSE)
    Call(SetCamProperties, CAM_DEFAULT, Float(4.0 / DT), 480, 0, 0, 320, 15, -6)
    Call(PushSong, SONG_KOOPA_BROS_THEME, 0)
    Thread
        Set(MF_KoopaBrosSceneLock, FALSE)
        Wait(5)
        Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Hurt, ANIM_KoopaBros_Red_Hurt, 5, MSG_MAC_Plaza_002F)
        Set(MF_KoopaBrosSceneLock, TRUE)
    EndThread
    Thread
        Call(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_DarkToad_01, LVar3, LVar4, LVar5)
        Add(LVar5, 5)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        PlayEffect(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        Call(SetNpcAnimation, NPC_DarkToad_01, ANIM_DarkToad_Red_Hurt)
        Wait(5 * DT)
        Call(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_DarkToad_01, LVar3, LVar4, LVar5)
        Call(SetNpcPos, NPC_DarkToad_01, LVar3, NPC_DISPOSE_POS_Y, LVar2)
        Call(SetNpcPos, NPC_KoopaBros_01, LVar3, LVar4, LVar5)
        Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(1.0))
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Hurt)
        Call(NpcJump0, NPC_KoopaBros_01, LVar3, LVar4, LVar5, 10 * DT)
    EndThread
    Thread
        Wait(10 * DT)
        Call(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_DarkToad_02, LVar3, LVar4, LVar5)
        Add(LVar5, 5)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        PlayEffect(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        Call(SetNpcAnimation, NPC_DarkToad_02, ANIM_DarkToad_Black_Hurt)
        Wait(5 * DT)
        Call(PlaySoundAtNpc, NPC_DarkToad_02, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_DarkToad_02, LVar3, LVar4, LVar5)
        Call(SetNpcPos, NPC_DarkToad_02, LVar3, NPC_DISPOSE_POS_Y, LVar2)
        Call(SetNpcPos, NPC_KoopaBros_02, LVar3, LVar4, LVar5)
        Call(SetNpcJumpscale, NPC_KoopaBros_02, Float(1.0))
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Hurt)
        Call(NpcJump0, NPC_KoopaBros_02, LVar3, LVar4, LVar5, 10 * DT)
    EndThread
    Thread
        Wait(20 * DT)
        Call(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_DarkToad_03, LVar3, LVar4, LVar5)
        Add(LVar5, 5)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
        PlayEffect(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
        Call(SetNpcAnimation, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Hurt)
        Wait(5 * DT)
        Call(PlaySoundAtNpc, NPC_DarkToad_03, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_DarkToad_03, LVar3, LVar4, LVar5)
        Call(SetNpcPos, NPC_DarkToad_03, LVar3, NPC_DISPOSE_POS_Y, LVar2)
        Call(SetNpcPos, NPC_KoopaBros_03, LVar3, LVar4, LVar5)
        Call(SetNpcJumpscale, NPC_KoopaBros_03, Float(1.0))
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Hurt)
        Call(NpcJump0, NPC_KoopaBros_03, LVar3, LVar4, LVar5, 10 * DT)
    EndThread
    Wait(30 * DT)
    Call(PlaySoundAtNpc, NPC_DarkToad_01, SOUND_MERLON_STRIKE, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_DarkToad_04, LVar3, LVar4, LVar5)
    Add(LVar5, 5)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 2, 20)
    PlayEffect(EFFECT_SHIMMER_BURST, 1, LVar3, LVar4, LVar5, 1, 30)
    Call(SetNpcAnimation, NPC_DarkToad_04, ANIM_DarkToad_Green_Hurt)
    Wait(5 * DT)
    Call(PlaySoundAtNpc, NPC_DarkToad_04, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_DarkToad_04, LVar3, LVar4, LVar5)
    Call(SetNpcPos, NPC_DarkToad_04, LVar3, NPC_DISPOSE_POS_Y, LVar2)
    Call(SetNpcPos, NPC_KoopaBros_04, LVar3, LVar4, LVar5)
    Call(SetNpcJumpscale, NPC_KoopaBros_04, Float(1.0))
    Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Hurt)
    Call(NpcJump0, NPC_KoopaBros_04, LVar3, LVar4, LVar5, 10 * DT)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Loop(0)
        IfEq(MF_KoopaBrosSceneLock, TRUE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Idle)
    Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Idle)
    Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Idle)
    Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Idle)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0030)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_MAC_Plaza_0031)
    Call(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 5, MSG_MAC_Plaza_0032)
    Call(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
    Call(InterpNpcYaw, NPC_KoopaBros_02, 90, 0)
    Call(InterpNpcYaw, NPC_KoopaBros_03, 90, 0)
    Call(InterpNpcYaw, NPC_KoopaBros_04, 90, 0)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Red_Run)
    Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Black_Run)
    Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Run)
    Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Run)
    Wait(15 * DT)
    Call(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
    Thread
        Call(SetNpcSpeed, NPC_KoopaBros_01, Float(8.0 / DT))
        Call(NpcMoveTo, NPC_KoopaBros_01, 700, 0, 0)
    EndThread
    Thread
        Call(SetNpcSpeed, NPC_KoopaBros_02, Float(8.0 / DT))
        Call(NpcMoveTo, NPC_KoopaBros_02, 700, 0, 0)
    EndThread
    Thread
        Call(SetNpcSpeed, NPC_KoopaBros_03, Float(8.0 / DT))
        Call(NpcMoveTo, NPC_KoopaBros_03, 700, 0, 0)
    EndThread
    Wait(1)
    Call(SetNpcSpeed, NPC_KoopaBros_04, Float(8.0 / DT))
    Call(NpcMoveTo, NPC_KoopaBros_04, 700, 0, 0)
    Wait(10 * DT)
    Call(PopSong)
    Call(SetPanTarget, CAM_DEFAULT, 410, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Wait(3)
        Call(PlayerFaceNpc, NPC_Merlon, FALSE)
    EndThread
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0033)
    Call(SetNpcSpeed, NPC_Merlon, Float(3.0 / DT))
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -50)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    Call(NpcMoveTo, NPC_Merlon, LVar3, LVar2, 0)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    Call(NpcMoveTo, NPC_Merlon, LVar0, LVar2, 0)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0034)
    Thread
        Wait(10 * DT)
#if VERSION_PAL
        Call(ResetCam, CAM_DEFAULT, Float(1.6669921875))
#else
        Call(ResetCam, CAM_DEFAULT, 2)
#endif
    EndThread
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Add(LVar0, -150)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
    Call(NpcMoveTo, NPC_Merlon, LVar0, LVar2, 0)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Call(InterpNpcYaw, NPC_Merlon, 133, 0)
    Call(SetNpcPos, NPC_Merlon, -337, 20, -360)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
    Set(AF_MAC_0E, FALSE)
    Set(AF_MAC_0F, FALSE)
    Set(AF_MAC_10, FALSE)
    Set(AF_MAC_11, FALSE)
    Set(AF_MAC_12, FALSE)
    Set(AF_MAC_13, FALSE)
    Set(AF_MAC_14, FALSE)
    Call(RemoveEncounter, NPC_KoopaBros_01)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Merlon) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            IfEq(GF_MAC01_Merlon_HintFromDarkToads, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0026)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0027)
                Set(GB_StoryProgress, STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
                ChildThread
                    Loop(0)
                        Call(PlayerFaceNpc, NPC_Merlon, FALSE)
                        Wait(1)
                    EndLoop
                EndChildThread
                Call(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                Call(SetNpcSpeed, NPC_Merlon, Float(4.0 / DT))
                Call(NpcMoveTo, NPC_Merlon, -350, -280, 0)
                Call(NpcMoveTo, NPC_Merlon, -230, -270, 0)
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                Call(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                Call(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
                Call(MakeLerp, 0, -80, 15, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                Call(NpcMoveTo, NPC_Merlon, -163, -217, 0)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
                Call(MakeLerp, -80, 0, 15, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
                Call(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
                Call(SetNpcPos, NPC_SELF, -150, 10, -160)
                Call(SetNpcYaw, NPC_Merlon, 90)
                Exec(N(D_80250D14_811594))
            EndIf
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0028)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0035)
        CaseEq(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_004C)
        CaseGe(STORY_CH3_GOT_SUPER_BOOTS)
            IfEq(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                Set(LVar0, MSG_MAC_Plaza_003E)
                IfGe(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
                    IfLt(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
                        Set(LVar0, MSG_MAC_Plaza_003D)
                    EndIf
                EndIf
                Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, LVar0)
                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(GetNpcPos, NPC_Merlon, LVar3, LVar4, LVar5)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                AddF(LVar0, LVar3)
                AddF(LVar1, LVar4)
                AddF(LVar2, LVar5)
                DivF(LVar0, Float(2.0))
                DivF(LVar1, Float(2.0))
                DivF(LVar2, Float(2.0))
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003F)
                Thread
                    Loop(0)
                        Call(PlayerFaceNpc, NPC_Merlon, FALSE)
                        IfEq(GF_MAC01_Merlon_HeardAboutDream, TRUE)
                            BreakLoop
                        EndIf
                        Wait(1)
                    EndLoop
                EndThread
                Call(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                Call(SetNpcSpeed, NPC_Merlon, Float(3.0))
                Call(NpcMoveTo, NPC_Merlon, -170, -225, 0)
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                Call(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_VISIBLE)
                ExecWait(N(D_8024E740_80EFC0))
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Walk)
                Call(SetNpcSpeed, NPC_Merlon, Float(3.0))
                Call(NpcMoveTo, NPC_Merlon, -265, -300, 0)
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
                ExecWait(N(D_8024E7F0_80F070))
                Call(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_HIDDEN)
                Set(GF_MAC01_Merlon_HeardAboutDream, TRUE)
                Call(InterpNpcYaw, NPC_Merlon, 133, 0)
                Call(SetNpcPos, NPC_Merlon, -337, 20, -360)
                Call(SetNpcFlagBits, NPC_Merlon, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 0)
                Return
            Else
                IfEq(GF_MAC01_QuickChangeDropped, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_0040)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_003B)
                EndIf
            EndIf
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 16, MSG_MAC_Plaza_003B)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_Merlon))
    ExecWait(N(EVS_LetterReward_Merlon))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Merlon) = {
    Call(InterpNpcYaw, NPC_SELF, 133, 1)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            Call(SetNpcPos, NPC_SELF, 410, 0, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
        CaseRange(STORY_CH6_RETURNED_TO_TOAD_TOWN, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
        CaseGe(STORY_CH3_GOT_SUPER_BOOTS)
            IfEq(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                Call(SetNpcPos, NPC_Merlon, -135, 20, -250)
                Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Think)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o335, COLLIDER_FLAGS_UPPER_MASK)
            Else
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
            EndIf
        CaseDefault
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o336, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Merlon)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_DarkToad_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Call(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_004D)
            Call(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_004E)
            Call(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Talk, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_004F)
            Call(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Talk, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_0050)
        CaseLt(STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            Call(AdjustCam, CAM_DEFAULT, Float(4.0 / DT), 0, 300, Float(15.0), Float(-7.5))
            Call(SpeakToPlayer, NPC_DarkToad_01, ANIM_DarkToad_Red_Talk, ANIM_DarkToad_Red_Idle, 0, MSG_MAC_Plaza_0051)
            Call(SpeakToPlayer, NPC_DarkToad_02, ANIM_DarkToad_Black_Talk, ANIM_DarkToad_Black_Idle, 0, MSG_MAC_Plaza_0052)
            Call(SpeakToPlayer, NPC_DarkToad_03, ANIM_DarkToad_Yellow_Talk, ANIM_DarkToad_Yellow_Idle, 0, MSG_MAC_Plaza_0053)
            Call(SpeakToPlayer, NPC_DarkToad_04, ANIM_DarkToad_Green_Talk, ANIM_DarkToad_Green_Idle, 0, MSG_MAC_Plaza_0054)
            Set(GF_MAC01_Merlon_HintFromDarkToads, TRUE)
#if VERSION_PAL
            Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
#else
            Call(ResetCam, CAM_DEFAULT, 5)
#endif
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_DarkToad_01) = {
    Loop(0)
        IfGe(GB_StoryProgress, STORY_CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
            Set(LVar0, 0)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Switch(LVar1)
                CaseGe(460)
                    Add(LVar0, 1)
            EndSwitch
            Switch(LVar3)
                CaseRange(-50, 70)
                    Add(LVar0, 1)
            EndSwitch
            IfEq(LVar0, 2)
                BreakLoop
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Loop(0)
        Call(PartnerCanUseAbility, LVar0)
        IfEq(LVar0, FALSE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_Scene_KoopaBrosUnmasked))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_DarkToad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_DarkToad_01)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_DarkToad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_DarkToad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_DarkToad_01)))
    Return
    End
};

EvtScript N(EVS_Scene_MerlonAndNinji) = {
    IfNe(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_Ninji, -278, 20, -376)
    Call(SetNpcYaw, NPC_Ninji, 0)
    Wait(40)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -276, -305, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0047)
    Call(NpcFacePlayer, NPC_Ninji, 5)
    Wait(15 * DT)
    Call(GetNpcPos, NPC_Ninji, LVar0, LVar1, LVar2)
#if VERSION_PAL
    Call(SetCamProperties, CAM_DEFAULT, Float(4.0 / DT), LVar0, LVar1, LVar2, 250, 15, -9)
#else
    Call(SetCamProperties, CAM_DEFAULT, 4, LVar0, LVar1, LVar2, 250, 15, -9)
#endif
    Call(SpeakToPlayer, NPC_Ninji, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_MAC_Plaza_0048)
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0049)
#if VERSION_PAL
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
#else
    Call(ResetCam, CAM_DEFAULT, 5)
#endif
    Call(SpeakToPlayer, NPC_Ninji, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_MAC_Plaza_004A)
    Thread
        Call(SetNpcAnimation, NPC_Ninji, ANIM_Ninji_Walk)
        Call(NpcMoveTo, NPC_Ninji, -230, -260, 0)
        Call(NpcMoveTo, NPC_Ninji, -185, -194, 0)
        Call(SetNpcPos, NPC_Ninji, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(25 * DT)
        Call(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 8)
            Call(RotateModel, MODEL_door, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Wait(5 * DT)
        Loop(10)
            Add(LVar0, -8)
            Call(RotateModel, MODEL_door, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilitud, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_004B)
    Set(GB_StoryProgress, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
    Call(DisablePlayerInput, FALSE)
    Return
    End
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
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
    Call(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Plaza_007D)
    Set(GB_StoryProgress, STORY_CH0_RETURNED_TO_TOAD_TOWN)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_007C)
        CaseLt(STORY_CH1_SPOKE_WITH_MERLIN)
            Set(LVar0, MSG_MAC_Plaza_007D)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_007E)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Plaza_007F)
            Else
                Set(LVar0, MSG_MAC_Plaza_0080)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_0081)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_MailbagStolen, FALSE)
                Set(LVar0, MSG_MAC_Plaza_0082)
            Else
                IfEq(GF_MAC01_MailbagReturned, FALSE)
                    Set(LVar0, MSG_MAC_Plaza_0083)
                Else
                    Set(LVar0, MSG_MAC_Plaza_0084)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Plaza_0085)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_0086)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Plaza_0087)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_0088)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Plaza_0089)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_008A)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_008B)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0046)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    IfEq(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Call(SetNpcPos, NPC_SELF, -25, 0, -500)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_04)))
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_04)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_008C)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Plaza_008D)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_008E)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Plaza_008F)
            Else
                Set(LVar0, MSG_MAC_Plaza_0090)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_0091)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_MailbagStolen, FALSE)
                Set(LVar0, MSG_MAC_Plaza_0092)
            Else
                IfEq(GF_MAC01_MailbagReturned, FALSE)
                    Set(LVar0, MSG_MAC_Plaza_0093)
                Else
                    Set(LVar0, MSG_MAC_Plaza_0094)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Plaza_0095)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_0096)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Plaza_0097)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_0098)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Plaza_0099)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_009A)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_009B)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0047)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad_05) = {
    Return
    End
};

EvtScript N(D_8025AA78_81B2F8) = {
    Call(DisablePlayerInput, TRUE)
    Call(NpcFacePlayer, NPC_Toad_05, 0)
    Wait(5)
    Call(SpeakToPlayer, NPC_Toad_05, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_0048)
    Wait(10)
    Call(SetPlayerSpeed, Float(4.0))
    Call(PlayerMoveTo, 0, 580, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_05)))
    IfGe(GB_StoryProgress, STORY_EPILOGUE)
        Call(SetNpcPos, NPC_SELF, -50, 0, 580)
        Call(SetNpcYaw, NPC_SELF, 90)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_05)))
        BindTrigger(Ref(N(D_8025AA78_81B2F8)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilis, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_009C)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Plaza_009D)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_009E)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Plaza_009F)
            Else
                Set(LVar0, MSG_MAC_Plaza_00A0)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00A1)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_MailbagStolen, FALSE)
                Set(LVar0, MSG_MAC_Plaza_00A2)
            Else
                IfEq(GF_MAC01_MailbagReturned, FALSE)
                    Set(LVar0, MSG_MAC_Plaza_00A3)
                Else
                    Set(LVar0, MSG_MAC_Plaza_00A4)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Plaza_00A5)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00A6)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Plaza_00A7)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00A8)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Plaza_00A9)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00AA)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_00AB)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0049)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_06, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad_06) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_06)))
    IfGe(GB_StoryProgress, STORY_EPILOGUE)
        Call(SetNpcPos, NPC_SELF, -110, 20, -380)
        Call(SetNpcYaw, NPC_SELF, 90)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_06)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_07) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_00AC)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Plaza_00AD)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00AE)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Plaza_00AF)
            Else
                Set(LVar0, MSG_MAC_Plaza_00B0)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00B1)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_MailbagStolen, FALSE)
                Set(LVar0, MSG_MAC_Plaza_00B2)
            Else
                IfEq(GF_MAC01_MailbagReturned, FALSE)
                    Set(LVar0, MSG_MAC_Plaza_00B3)
                Else
                    Set(LVar0, MSG_MAC_Plaza_00B4)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Plaza_00B5)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00B6)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Plaza_00B7)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00B8)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Plaza_00B9)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00BA)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_00BB)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_004A)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad_07) = {
    Return
    End
};

EvtScript N(D_8025B110_81B990) = {
    Call(DisablePlayerInput, TRUE)
    Call(NpcFacePlayer, NPC_Toad_07, 0)
    Wait(5)
    Call(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_Outro_004B)
    Wait(10)
    Call(SetPlayerSpeed, Float(4.0))
    Call(PlayerMoveTo, 600, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_07) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_07)))
    IfGe(GB_StoryProgress, STORY_EPILOGUE)
        Call(SetNpcPos, NPC_SELF, 530, 0, -50)
        Call(SetNpcYaw, NPC_SELF, 270)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_07)))
        BindTrigger(Ref(N(D_8025B110_81B990)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilie, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_08) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_00BC)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Plaza_00BD)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00BE)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Plaza_00BF)
            Else
                Set(LVar0, MSG_MAC_Plaza_00C0)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00C1)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_ShyGuysTramplingGarden, FALSE)
            Else
                Set(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
                Add(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
                IfLt(LVar0, 2)
                    Set(LVar0, MSG_MAC_Plaza_00C2)
                Else
                    Set(LVar0, MSG_MAC_Plaza_00C3)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Plaza_00C4)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00C5)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Plaza_00C6)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00C7)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Plaza_00C8)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00C9)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_00CA)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_004C)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_08, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_08) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_08)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_09) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_00CB)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Plaza_00CC)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00CD)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Plaza_00CE)
            Else
                Set(LVar0, MSG_MAC_Plaza_00CF)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00D0)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, FALSE)
                Set(LVar0, MSG_MAC_Plaza_00D1)
            Else
                IfEq(GF_MAC00_DictionaryReturned, FALSE)
                    Set(LVar0, MSG_MAC_Plaza_00D2)
                Else
                    Set(LVar0, MSG_MAC_Plaza_00D3)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Plaza_00D4)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00D5)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Plaza_00D6)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Plaza_00D7)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Plaza_00D8)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_00D9)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_00DA)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_004D)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_09, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_09) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_09)))
    Return
    End
};

EvtScript N(D_8025B760_81BFE0) = {
    Call(GetNpcPos, NPC_PostOfficeShyGuy, LVar2, LVar3, LVar4)
    Add(LVar3, 20)
    Call(MakeItemEntity, ITEM_CALCULATOR, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(1)
    Loop(80)
        Call(GetNpcPos, NPC_PostOfficeShyGuy, LVar2, LVar3, LVar4)
        Add(LVar3, 20)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(RemoveItemEntity, LVar9)
    Return
    End
};

EvtScript N(D_8025B854_81C0D4) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar2, 200)
            IfLt(LVar0, 50)
                BreakLoop
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_PostOfficeShyGuy, -313, 0, 330)
    Call(SetNpcAnimation, NPC_PostOfficeShyGuy, ANIM_ShyGuy_Red_Anim04)
    Wait(21)
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0007)
    Exec(N(D_8025B760_81BFE0))
    Set(LVar0, 6)
    Call(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(D_8024E6F8_80EF78), LVarA)
    Call(NpcMoveTo, NPC_PostOfficeShyGuy, -45, 330, 30)
    Call(NpcMoveTo, NPC_PostOfficeShyGuy, -45, 710, 30)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_PostOfficeShyGuy, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_01) = {
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfGt(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
        Return
    EndIf
    IfNe(GF_MAC01_CalculatorStolen, FALSE)
        Return
    EndIf
    Set(GF_MAC01_CalculatorStolen, TRUE)
    Exec(N(D_8025B854_81C0D4))
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadHouseKeeper_A) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Plaza_001A)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadHouseKeeper_B) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_0044)
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    IfEq(AF_MAC_43, FALSE)
        Set(LVar0, MSG_MAC_Plaza_0015)
        Set(LVar8, MSG_MAC_Plaza_0016)
    Else
        Set(LVar0, MSG_MAC_Plaza_001B)
        Set(LVar8, MSG_MAC_Plaza_001B)
    EndIf
    Set(LVar1, MSG_MAC_Plaza_0017)
    Set(LVar2, MSG_MAC_Plaza_0018)
    Set(LVar3, MSG_MAC_Plaza_0019)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Call(PlayerMoveTo, 535, -155, 20)
    Thread
        Wait(5)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamDistance, CAM_DEFAULT, 116)
        Call(SetCamPitch, CAM_DEFAULT, 99, -58)
        Call(SetCamPosA, CAM_DEFAULT, 495, 130)
        Call(SetCamPosB, CAM_DEFAULT, 507, -19)
        Call(SetCamPosC, CAM_DEFAULT, 0, 20)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(PlayerMoveTo, 580, -210, 20)
    Call(InterpPlayerYaw, 263, 1)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Thread
        Wait(60)
        Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EndThread
    Wait(20)
    Thread
        Wait(63)
        Call(N(ToadHouse_CamSetFOV), 0, 25)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Exec(N(EVS_SetupMusic))
    Call(HidePlayerShadow, FALSE)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerSpeed, Float(3.0))
    Call(SetPlayerPos, 568, 20, -186)
    Call(PlayerMoveTo, 525, -168, 20)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    IfGe(GB_StoryProgress, STORY_EPILOGUE)
        Call(SetNpcPos, NPC_SELF, 370, 20, -150)
        Call(SetNpcYaw, NPC_SELF, 270)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper_B)))
        Return
    EndIf
    IfEq(GF_MAC01_ChasedShyGuyFromToadHouse, FALSE)
        Switch(GB_StoryProgress)
            CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper_A)))
            CaseDefault
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
        EndSwitch
    Else
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    EndIf
    Set(AF_MAC_43, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_ShyGuy_02) = {
    Call(SetNpcPos, NPC_SELF, 572, 36, -226)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Loop(0)
        Call(InterpNpcYaw, NPC_SELF, 270, 1)
        Wait(3)
        IfEq(MF_InsideToadHouse, TRUE)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EndIf
        Call(NpcJump0, NPC_SELF, 539, 36, -242, 8)
        Wait(2)
        Call(InterpNpcYaw, NPC_SELF, 90, 1)
        Wait(3)
        IfEq(MF_InsideToadHouse, TRUE)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EndIf
        Call(NpcJump0, NPC_SELF, 572, 36, -226, 8)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcAI_ShyGuy_02) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, 36, LVar2, 10)
    Call(SetNpcSpeed, NPC_SELF, Float(8.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 550, 20, -161, 0)
    Thread
        Wait(10)
        Call(PlaySoundAtCollider, COLLIDER_deilit2u, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 8)
            Call(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Loop(10)
            Add(LVar0, -8)
            Call(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilit2u, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Set(LVar0, -1)
    Call(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(D_8024E6F8_80EF78), LVarA)
    Call(NpcMoveTo, NPC_SELF, 420, -118, 0)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(BindNpcInteract, NPC_ToadHouseToad, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcHit_ShyGuy_02) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_PARTNER)
            Set(LVar1, 1)
        CaseDefault
            Set(LVar1, 0)
    EndSwitch
    IfEq(LVar1, 0)
        Return
    EndIf
    Call(N(CheckPositionRelativeToPlane), 450, -190, 500, -103)
    IfEq(LVar0, ENCOUNTER_TRIGGER_NONE)
        Return
    EndIf
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    Set(GF_MAC01_ChasedShyGuyFromToadHouse, TRUE)
    Set(AF_MAC_43, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_02)))
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    IfEq(GF_MAC01_ChasedShyGuyFromToadHouse, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy_02)))
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_ShyGuy_02)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
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
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 560)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 500, -20, 0)
    Call(WaitForPlayerMoveToComplete)
    Call(InterpPlayerYaw, 270, 0)
    Call(ShowMessageAtScreenPos, MSG_MAC_Plaza_00DB, 160, 40)
    Loop(2)
        Call(InterpPlayerYaw, 90, 7)
        Wait(10 * DT)
        Call(InterpPlayerYaw, 270, 7)
        Wait(10 * DT)
    EndLoop
    Wait(30 * DT)
    Call(GetPlayerPos, LVar4, LVar5, LVar6)
    SubF(LVar4, Float(50.0))
    AddF(LVar5, Float(40.0))
    Call(InterpNpcYaw, NPC_Twink, 90, 0)
    Call(LoadPath, 35 * DT, Ref(N(FlightPath_TwinkArrive)), ARRAY_COUNT(N(FlightPath_TwinkArrive)), EASING_COS_IN_OUT)
    Loop(0)
        Call(GetNextPathPos)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0/ DT), -10, -300, 15, -9)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DC)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(15 * DT)
    Call(SetNpcJumpscale, NPC_Twink, Float(1.0))
    Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 10 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DD)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Chuckle)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), -40, -200, 15, -15)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Plaza_00DE)
    Wait(5 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(InterpNpcYaw, NPC_Twink, 270, 0)
    Call(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    Call(LoadPath, 35 * DT, Ref(N(FlightPath_TwinkDepart)), ARRAY_COUNT(N(FlightPath_TwinkDepart)), EASING_QUADRATIC_IN)
    Loop(0)
        Call(GetNextPathPos)
        Add(LVar1, LVar4)
        Add(LVar2, LVar5)
        Add(LVar3, LVar6)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    Exec(N(EVS_SetupMusic))
    Set(GB_StoryProgress, STORY_CH1_RETURNED_TO_TOAD_TOWN)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink) = {
    IfEq(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Twink)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_MAC_Plaza_00DF)
    ExecWait(N(EVS_ArtifactPrompt_Kolorado))
    ExecWait(N(EVS_LetterPrompt_Kolorado))
    ExecWait(N(EVS_LetterReward_Kolorado))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_RETURNED_TO_TOAD_TOWN, STORY_CH7_BEGAN_PEACH_MISSION)
            IfEq(GF_NOK11_Defeated_KentC, FALSE)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
            Else
                Call(RemoveNpc, NPC_SELF)
            EndIf
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
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

