#include "jan_22.h"
#include "sprite/player.h"

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/enemy/SpearGuy_Patrol.inc.c"
#include "world/common/npc/RaphaelRaven.inc.c"
#include "world/common/npc/Raven.inc.c"
#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Dummy.inc.c"

#include "world/common/complete/GiveReward.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

enum {
    RAVEN_SCENE_AWAITING_COMMAND    = 0,
    RAVEN_SCENE_LEAP_INTO_ACTION    = 10,
    RAVEN_SCENE_CONSTRUCTION_WORK   = 11,
    RAVEN_SCENE_FINISH_WORK         = 20,
    RAVEN_SCENE_LOWERED_BASKET      = 22,
    RAVEN_SCENE_HEADNG_OUT          = 25,
};

API_CALLABLE(N(UpgradeStarPowerCh5)) {
    PlayerData* playerData = &gPlayerData;

    set_max_star_power(5);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TetherCamToBasketPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UseBasketElevator) = {
    Call(GetPartnerInUse, LVar9)
    IfEq(LVar9, PARTNER_KOOPER)
        Return
    EndIf
    IfEq(LVar9, PARTNER_BOMBETTE)
        Return
    EndIf
    IfEq(LVar9, PARTNER_LAKILESTER)
        Return
    EndIf
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(IsPlayerWithin, 200, 0, 25, LVar0)
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(HidePlayerShadow, TRUE)
    Wait(7)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(GetPartnerInUse, LVar0)
    IfEq(LVar0, 0)
        Add(LVar5, -5)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
        Call(NpcJump0, NPC_PARTNER, LVar3, LVar4, LVar5, 10)
        Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    EndIf
    ExecGetTID(N(EVS_TetherCamToBasketPlayer), LVar7)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
    Call(MakeLerp, 0, 170, 60, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Set(LVar6, LVar4)
        Add(LVar6, LVar0)
        Call(SetPlayerPos, LVar3, LVar6, LVar5)
        Call(GetPartnerInUse, LVar8)
        IfEq(LVar8, PARTNER_NONE)
            Add(LVar6, 5)
            Add(LVar5, -5)
            Call(SetNpcPos, NPC_PARTNER, LVar3, LVar6, LVar5)
            Add(LVar6, -5)
            Add(LVar5, 5)
        EndIf
        SetF(LVar2, Float(200.0))
        SubF(LVar2, LVar0)
        DivF(LVar2, Float(200.0))
        Call(ScaleModel, MODEL_o147, 1, LVar2, 1)
        Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o124, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar7)
    Call(DisablePlayerPhysics, FALSE)
    Wait(5)
    Thread
        Wait(15)
        Call(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
        Call(MakeLerp, 170, 0, 60, EASING_CUBIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, Float(200.0))
            SubF(LVar2, LVar0)
            DivF(LVar2, Float(200.0))
            Call(ScaleModel, MODEL_o147, 1, LVar2, 1)
            Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
            Call(TranslateModel, MODEL_o124, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump, 270, 205, 15, 20)
        Call(HidePlayerShadow, FALSE)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, 285, 15, 0)
    EndThread
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, TRUE)
        Wait(10)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
        Call(NpcJump0, NPC_PARTNER, 260, 205, 15, 15)
    EndIf
    Call(EnableNpcShadow, NPC_PARTNER, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(EnablePartnerAI)
    Wait(5)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupBasketElevator) = {
    BindTrigger(Ref(N(EVS_UseBasketElevator)), TRIGGER_FLOOR_TOUCH, COLLIDER_o124, 1, 0)
    IfLt(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o124, COLLIDER_FLAGS_UPPER_MASK)
        Call(ScaleModel, MODEL_o147, 1, Float(0.15625), 1)
        Call(TranslateModel, MODEL_o146, 0, 178, 0)
        Call(TranslateModel, MODEL_o124, 0, 178, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o124, COLLIDER_FLAGS_UPPER_MASK)
        Call(ScaleModel, MODEL_o147, 1, 1, 1)
        Call(TranslateModel, MODEL_o146, 0, 0, 0)
        Call(TranslateModel, MODEL_o124, 0, 0, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_GatherRavensNearRaphael) = {
    Call(SetNpcPos, NPC_Raven_01, 177, 0, -10)
    Call(SetNpcPos, NPC_Raven_02, 127, 0, 5)
    Call(SetNpcPos, NPC_Raven_03, 152, 0, 0)
    Call(SetNpcPos, NPC_Raven_04, 102, 0, 0)
    Call(SetNpcPos, NPC_Raven_05, 77, 0, -10)
    Return
    End
};

EvtScript N(EVS_Ravens_LeapIntoTree) = {
    ChildThread
        Call(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
        Call(SetNpcFlagBits, NPC_Raven_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Flail)
        Call(NpcJump0, NPC_Raven_02, 271, 325, -17, 30 * DT)
    EndChildThread
    ChildThread
        Wait(3 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
        Call(SetNpcFlagBits, NPC_Raven_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Flail)
        Call(NpcJump0, NPC_Raven_05, 400, 215, -23, 30 * DT)
    EndChildThread
    ChildThread
        Wait(6 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_01, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
        Call(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Flail)
        Call(NpcJump0, NPC_Raven_01, 208, 335, -17, 30 * DT)
    EndChildThread
    ChildThread
        Wait(9 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
        Call(SetNpcFlagBits, NPC_Raven_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Flail)
        Call(NpcJump0, NPC_Raven_03, 327, 200, -8, 30 * DT)
    EndChildThread
    Wait(30 * DT)
    Call(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
    Call(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Flail)
    Call(NpcJump0, NPC_Raven_04, 222, 284, -13, 15 * DT)
    Return
    End
};

EvtScript N(EVS_NpcInteract_RaphaelRaven) = {
    Call(GetNpcPos, NPC_RaphaelRaven, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(N(DisableCameraLeadingPlayer))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SetNpcFlagBits, NPC_RaphaelRaven, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00C7)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00C8)
    Call(SetNpcVar, NPC_Raven_01, 0, RAVEN_SCENE_LEAP_INTO_ACTION)
    Call(BindNpcInteract, NPC_SELF, 0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_RaphaelRaven) = {
    Label(0)
    IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
        Wait(1)
        Goto(0)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RaphaelRaven)))
    Return
    End
};

EvtScript N(EVS_NpcInit_RaphaelRaven) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH5_RAPHAEL_MOVED_ROOT)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_RaphaelRaven)))
        CaseEq(STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            Call(SetNpcPos, NPC_SELF, 125, 0, -40)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RaphaelRaven)))
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Raven) = {
    IfEq(GF_JAN22_Met_Raven, FALSE)
        Call(SpeakToPlayer, NPC_Raven_01, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00D2)
        Set(GF_JAN22_Met_Raven, TRUE)
    Else
        Call(SpeakToPlayer, NPC_Raven_01, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00D3)
    EndIf
    Return
    End
};

EvtScript N(EVS_Raven_HopAndWalkAway) = {
    Wait(45)
    Call(NpcJump0, LVar0, 30, 0, -15, 10)
    Call(SetNpcAnimation, LVar0, ANIM_Raven_Walk)
    Call(SetNpcSpeed, LVar0, Float(3.0 / DT))
    Call(NpcMoveTo, LVar0, -120, 0, 0)
    Call(SetNpcPos, LVar0, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_BuildingEffects) = {
    Call(PlaySoundAt, SOUND_LOOP_JAN_CONSTRUCTION, SOUND_SPACE_DEFAULT, 270, 130, 0)
    Loop(0)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(1.0))
        Wait(30 * DT)
        Call(ShakeCam, CAM_DEFAULT, 0, 8, Float(1.0))
        Call(RandInt, 4, LVar0)
        Add(LVar0, 1)
        PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 290, 155, 0, 240, 0, 0, LVar0)
        Wait(10 * DT)
        PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 275, 150, 0, 240, 0, 0, 3)
        Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(1.0))
        Wait(4 * DT)
        Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(1.0))
        Wait(4 * DT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ManageRavens) = {
    Label(0)
        IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            Wait(1)
            Goto(0)
        EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o304, COLLIDER_FLAGS_UPPER_MASK)
    Label(1)
        Call(NpcFacePlayer, NPC_Raven_01, 0)
        Call(NpcFacePlayer, NPC_Raven_02, 0)
        Call(NpcFacePlayer, NPC_Raven_03, 0)
        Call(NpcFacePlayer, NPC_Raven_04, 0)
        Call(NpcFacePlayer, NPC_Raven_05, 0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, RAVEN_SCENE_AWAITING_COMMAND)
            Wait(1)
            Goto(1)
        EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o304, COLLIDER_FLAGS_UPPER_MASK)
    Label(2)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(RAVEN_SCENE_LEAP_INTO_ACTION)
                Call(DisablePlayerInput, TRUE)
                Call(InterpNpcYaw, NPC_Raven_01, 90, 0)
                Call(InterpNpcYaw, NPC_Raven_02, 90, 0)
                Call(InterpNpcYaw, NPC_Raven_03, 90, 0)
                Call(InterpNpcYaw, NPC_Raven_04, 90, 0)
                Call(InterpNpcYaw, NPC_Raven_05, 90, 0)
                Wait(10 * DT)
                ExecGetTID(N(EVS_Ravens_LeapIntoTree), LVar9)
                Wait(40 * DT)
                KillThread(LVar9)
                Wait(10 * DT)
                Call(SetNpcPos, NPC_Raven_01, NPC_DISPOSE_LOCATION)
                Call(SetNpcPos, NPC_Raven_02, NPC_DISPOSE_LOCATION)
                Call(SetNpcPos, NPC_Raven_03, NPC_DISPOSE_LOCATION)
                Call(SetNpcPos, NPC_Raven_04, NPC_DISPOSE_LOCATION)
                Call(SetNpcPos, NPC_Raven_05, NPC_DISPOSE_LOCATION)
                Call(UseSettingsFrom, CAM_DEFAULT, 300, 250, 150)
                Call(SetPanTarget, CAM_DEFAULT, 300, 250, 150)
                Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                // repeat the action with a time delay across the sudden camera cut
                Exec(N(EVS_GatherRavensNearRaphael))
                Wait(10 * DT)
                ExecWait(N(EVS_Ravens_LeapIntoTree))
                Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
                Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
                Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
                Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
                Call(PlaySoundAtNpc, NPC_Raven_04, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
                Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(1.0))
                Thread
                    Call(SetNpcJumpscale, NPC_Raven_01, Float(3.0))
                    Call(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
                    Call(NpcJump0, NPC_Raven_01, LVar0, LVar1, LVar2, 5 * DT)
                EndThread
                Thread
                    Call(SetNpcJumpscale, NPC_Raven_02, Float(3.0))
                    Call(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
                    Call(NpcJump0, NPC_Raven_02, LVar0, LVar1, LVar2, 5 * DT)
                    Call(InterpNpcYaw, NPC_Raven_02, 270, 0)
                EndThread
                Wait(3 * DT)
                Call(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
                Call(SetNpcRotation, NPC_Raven_04, 0, 0, 180)
                Call(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, TRUE)
                Call(InterpNpcYaw, NPC_Raven_03, 270, 0)
                Call(InterpNpcYaw, NPC_Raven_05, 270, 0)
                Call(SetNpcYaw, NPC_RaphaelRaven, 90)
                Call(GetNpcPos, NPC_RaphaelRaven, LVar0, LVar1, LVar2)
                Call(GetPlayerPos, LVar3, LVar4, LVar5)
                Add(LVar2, 80)
                Call(SetPlayerPos, 145, 0, LVar2)
                Call(InterpPlayerYaw, 90, 0)
                Call(SetNpcPos, NPC_PARTNER, 115, 0, LVar2)
                Call(SetNpcYaw, NPC_PARTNER, 90)
                Wait(80 * DT)
                Call(SetNpcRotation, NPC_Raven_04, 0, 0, 0)
                Call(SetSelfVar, 0, RAVEN_SCENE_CONSTRUCTION_WORK)
            CaseEq(RAVEN_SCENE_CONSTRUCTION_WORK)
                Call(UseSettingsFrom, CAM_DEFAULT, 165, 0, 0)
                Call(SetPanTarget, CAM_DEFAULT, 165, 0, 0)
                Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.5))
                Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Wait(20 * DT)
                Call(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, FALSE)
                Call(NpcMoveTo, NPC_Raven_04, 260, -20, 0)
                Call(SetNpcRotation, NPC_Raven_04, 0, 0, 90)
                Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
                Call(NpcJump0, NPC_Raven_04, 300, 300, -14, 20 * DT)
                Call(SetNpcRotation, NPC_Raven_04, 0, 0, 0)
                ExecGetTID(N(EVS_BuildingEffects), LVarA)
                Wait(30 * DT)
                Call(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00CA)
                Wait(50 * DT)
                Call(SetNpcVar, NPC_Kolorado_02, 0, 10)
                Wait(140 * DT)
                Label(11)
                    Call(GetNpcVar, NPC_Kolorado_02, 0, LVar0)
                    IfNe(LVar0, 0)
                        Wait(1)
                        Goto(11)
                    EndIf
                Wait(40 * DT)
                Call(StopSound, SOUND_LOOP_JAN_CONSTRUCTION)
                KillThread(LVarA)
                Call(SetSelfVar, 0, RAVEN_SCENE_FINISH_WORK)
            CaseEq(RAVEN_SCENE_FINISH_WORK)
                Wait(20 * DT)
                Call(SetGroupVisibility, MODEL_g39, MODEL_GROUP_VISIBLE)
                Call(SetGroupVisibility, MODEL_g52, MODEL_GROUP_VISIBLE)
                Call(SetGroupVisibility, MODEL_g58, MODEL_GROUP_VISIBLE)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g29, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g39, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g86, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
                Call(SetNpcPos, NPC_Raven_01, 255, 205, -25)
                Call(SetNpcPos, NPC_Raven_02, 200, 185, 0)
                Call(SetNpcPos, NPC_Raven_03, 338, 212, -20)
                Call(SetNpcPos, NPC_Raven_04, 267, 314, -12)
                Call(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar0, 60)
                Call(NpcJump0, NPC_Raven_05, LVar0, 0, 40, 20 * DT)
                Wait(10 * DT)
                Call(SpeakToPlayer, NPC_Raven_05, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00CC)
                Wait(15 * DT)
                Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
                Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
                Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
                Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
                Call(UseSettingsFrom, CAM_DEFAULT, 300, 250, 150)
                Call(SetPanTarget, CAM_DEFAULT, 300, 250, 150)
                Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Wait(15 * DT)
                Call(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                Call(SetNpcPos, NPC_Raven_05, 350, 0, 100)
                Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Flail)
                Call(NpcJump0, NPC_Raven_05, 400, 215, -23, 20 * DT)
                Call(SpeakToPlayer, NPC_Raven_05, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00CD)
                Thread
                    Call(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
                    Call(MakeLerp, 170, 0, 60, EASING_CUBIC_OUT)
                    Loop(0)
                        Call(UpdateLerp)
                        Set(LVar3, LVar0)
                        Add(LVar3, 9)
                        Call(SetNpcPos, NPC_Raven_02, 200, LVar3, 0)
                        SetF(LVar2, Float(200.0))
                        SubF(LVar2, LVar0)
                        DivF(LVar2, Float(200.0))
                        Call(ScaleModel, MODEL_o147, 1, LVar2, 1)
                        Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
                        Call(TranslateModel, MODEL_o124, 0, LVar0, 0)
                        Wait(1)
                        IfEq(LVar1, 0)
                            BreakLoop
                        EndIf
                    EndLoop
                    Call(SetSelfVar, 0, RAVEN_SCENE_LOWERED_BASKET)
                EndThread
                Wait(20 * DT)
                Call(UseSettingsFrom, CAM_DEFAULT, 165, 0, 0)
                Call(SetPanTarget, CAM_DEFAULT, 165, 0, 0)
                Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.5))
                Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Wait(10 * DT)
                Call(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00CE)
                Loop(0)
                    Wait(1)
                    Call(GetSelfVar, 0, LVar0)
                    IfEq(LVar0, RAVEN_SCENE_LOWERED_BASKET)
                        BreakLoop
                    EndIf
                EndLoop
                Call(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_Raven_05, 150, 0, 20, 15 * DT)
                Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
                Thread
                    Call(NpcMoveTo, NPC_Raven_05, 65, 25, 30 * DT)
                    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
                    Call(InterpNpcYaw, NPC_Raven_05, 90, 0)
                EndThread
                Call(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_Raven_04, 150, 0, 20, 15 * DT)
                Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
                Thread
                    Call(NpcMoveTo, NPC_Raven_04, 80, -10, 25 * DT)
                    Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
                    Call(InterpNpcYaw, NPC_Raven_04, 90, 0)
                EndThread
                Call(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_Raven_03, 150, 0, 20, 15 * DT)
                Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
                Thread
                    Call(NpcMoveTo, NPC_Raven_03, 95, 25, 20 * DT)
                    Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
                    Call(InterpNpcYaw, NPC_Raven_03, 90, 0)
                EndThread
                Call(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_Raven_02, 150, 0, 20, 15 * DT)
                Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
                Call(NpcMoveTo, NPC_Raven_02, 110, -10, 15 * DT)
                Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
                Call(InterpNpcYaw, NPC_Raven_02, 90, 0)
                Call(SetNpcVar, NPC_Kolorado_02, 0, 20)
                Call(SetSelfVar, 0, RAVEN_SCENE_HEADNG_OUT)
            CaseEq(RAVEN_SCENE_HEADNG_OUT)
                Call(GetNpcVar, NPC_Kolorado_02, 0, LVar0)
                IfEq(LVar0, -1)
                    Call(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00D0)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetCamDistance, CAM_DEFAULT, 350)
                    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
                    Call(SetCamSpeed, CAM_DEFAULT, Float(10.0 / DT))
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_GIVE_KEY_REWARD(ITEM_ULTRA_STONE)
                    Wait(20 * DT)
                    Call(SetCamDistance, CAM_DEFAULT, 400)
                    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-11.5))
                    Call(SetCamSpeed, CAM_DEFAULT, Float(3.5 / DT))
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    Call(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00D1)
                    Set(LVar0, NPC_Raven_02)
                    Exec(N(EVS_Raven_HopAndWalkAway))
                    Thread
                        Wait(10 * DT)
                        Set(LVar0, NPC_Raven_03)
                        Exec(N(EVS_Raven_HopAndWalkAway))
                    EndThread
                    Thread
                        Wait(20 * DT)
                        Set(LVar0, NPC_Raven_04)
                        Exec(N(EVS_Raven_HopAndWalkAway))
                    EndThread
                    Thread
                        Wait(30 * DT)
                        Set(LVar0, NPC_Raven_05)
                        Exec(N(EVS_Raven_HopAndWalkAway))
                    EndThread
                    Call(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_Walk)
                    Call(SetNpcSpeed, NPC_RaphaelRaven, Float(3.0 / DT))
                    Call(NpcMoveTo, NPC_RaphaelRaven, -120, 0, 0)
                    Call(SetNpcPos, NPC_RaphaelRaven, NPC_DISPOSE_LOCATION)
                    Wait(40 * DT)
                    Call(BindNpcInteract, NPC_Raven_01, Ref(N(EVS_NpcInteract_Raven)))
                    Call(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                    Call(N(EnableCameraLeadingPlayer))
                    Call(ResetCam, CAM_DEFAULT, Float(1.5 / DT))
                    Set(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                    Call(DisablePlayerInput, FALSE)
                    Return
                EndIf
        EndSwitch
        Wait(1)
    Goto(2)
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH5_RAPHAEL_MOVED_ROOT)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_ManageRavens)))
        CaseEq(STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_ManageRavens)))
            Exec(N(EVS_GatherRavensNearRaphael))
        CaseRange(STORY_CH5_ZIP_LINE_READY, STORY_CH5_OPENED_ESCAPE_ROUTE)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Raven)))
            Call(SetNpcPos, NPC_Raven_01, 260, 205, -25)
            Call(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Goto(30)
        CaseDefault
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o346, COLLIDER_FLAGS_UPPER_MASK)
            Call(RemoveNpc, NPC_Raven_01)
            Label(30)
            Call(RemoveNpc, NPC_Raven_02)
            Call(RemoveNpc, NPC_Raven_03)
            Call(RemoveNpc, NPC_Raven_04)
            Call(RemoveNpc, NPC_Raven_05)
    EndSwitch
    Return
    End
};

Vec3f N(RaphaelWalkPath)[] = {
    { -190.0,     0.0, -200.0 },
    { -185.0,     0.0,  -95.0 },
    { -180.0,     0.0,   10.0 },
};

EvtScript N(EVS_Scene_RaphaelComingThrough) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_RaphaelRaven, -200, 0, -170)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerPos, -190, 0, -200)
    Call(SetNpcPos, NPC_PARTNER, -190, 0, -210)
    ExecWait(N(EVS_MoveBushes))
    Call(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_Walk)
    Call(SetNpcSpeed, NPC_RaphaelRaven, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_RaphaelRaven, -180, -30, 0)
    Thread
        Call(NpcMoveTo, NPC_RaphaelRaven, 125, -40, 0)
        Call(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_Idle)
        Call(SetNpcFlagBits, NPC_RaphaelRaven, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(InterpNpcYaw, NPC_RaphaelRaven, 270, 0)
    EndThread
    Wait(15 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Run)
    Call(LoadPath, 45 * DT, Ref(N(RaphaelWalkPath)), ARRAY_COUNT(N(RaphaelWalkPath)), EASING_LINEAR)
    Label(0)
    Call(GetNextPathPos)
    Call(SetPlayerPos, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Thread
        Call(SetNpcPos, NPC_Raven_01, -200, 0, -190)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
        Call(SetNpcSpeed, NPC_Raven_01, Float(6.0 / DT))
        Call(NpcMoveTo, NPC_Raven_01, -150, -10, 0)
        Call(NpcMoveTo, NPC_Raven_01, 177, -10, 0)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
    EndThread
    Thread
        Wait(15 * DT)
        Call(SetNpcPos, NPC_Raven_02, -200, 0, -230)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
        Call(SetNpcSpeed, NPC_Raven_02, Float(6.0 / DT))
        Call(NpcMoveTo, NPC_Raven_02, -150, -10, 0)
        Call(NpcMoveTo, NPC_Raven_02, 152, 0, 0)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
    EndThread
    Thread
        Wait(30 * DT)
        Call(SetNpcPos, NPC_Raven_03, -200, 0, -230)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
        Call(SetNpcSpeed, NPC_Raven_03, Float(6.0 / DT))
        Call(NpcMoveTo, NPC_Raven_03, -150, -10, 0)
        Call(NpcMoveTo, NPC_Raven_03, 127, 5, 0)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
    EndThread
    Thread
        Wait(45 * DT)
        Call(SetNpcPos, NPC_Raven_04, -200, 0, -230)
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
        Call(SetNpcSpeed, NPC_Raven_04, Float(6.0 / DT))
        Call(NpcMoveTo, NPC_Raven_04, -150, -10, 0)
        Call(NpcMoveTo, NPC_Raven_04, 102, 0, 0)
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
    EndThread
    Wait(60 * DT)
    Call(SetNpcPos, NPC_Raven_05, -200, 0, -230)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
    Call(SetNpcSpeed, NPC_Raven_05, Float(6.0 / DT))
    Call(NpcMoveTo, NPC_Raven_05, -150, -10, 0)
    Call(NpcMoveTo, NPC_Raven_05, 77, -10, 0)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    Set(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(D_8024511C_B8929C) = {
    ChildThread
        Loop(0)
            Call(PlayerFaceNpc, NPC_SELF, FALSE)
            Wait(1)
        EndLoop
    EndChildThread
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 150)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0))
    Call(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
    Call(SetSelfVar, 0, 3)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado_HeldCaptive) = {
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar0, -440)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH5_00BC, 320, 60)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25 * DT)
    Call(DisablePlayerInput, FALSE)
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfGt(LVar0, 150)
                Call(GetPartnerInUse, LVar0)
                IfNe(LVar0, PARTNER_NONE)
                    Call(InterruptUsePartner)
                EndIf
                Call(DisablePlayerInput, TRUE)
                Call(func_802D2C14, 1)
                Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(RemoveNpc, NPC_SpearGuy)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(ShowMessageAtScreenPos, MSG_CH5_00C0, 0, 60)
                Call(InterpPlayerYaw, 270, 4)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                Call(SetNpcSpeed, NPC_SELF, Float(5.0 / DT))
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Set(LVar3, LVar0)
                Add(LVar3, -50)
                Call(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
                Add(LVar0, LVar3)
                Div(LVar0, 2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamDistance, CAM_DEFAULT, 300)
                Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.5))
                Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(N(DisableCameraLeadingPlayer))
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Wait(10 * DT)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C1)
                Call(SetSelfVar, 0, 2)
                Call(func_802D2C14, 0)
                Call(DisablePlayerInput, FALSE)
            EndIf
        CaseEq(1)
            SetGroup(EVT_GROUP_00)
            Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
            Call(func_802D2C14, 1)
            Wait(10 * DT)
            IfEq(GF_JAN01_SavedKolorado, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Idle, 0, MSG_CH5_00BE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Idle, 0, MSG_CH5_00BF)
            EndIf
            Call(SetSelfVar, 0, 2)
            Call(func_802D2C14, 0)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            SetGroup(EVT_GROUP_0B)
            Call(DisablePlayerInput, FALSE)
        CaseEq(2)
            Call(DisablePlayerInput, TRUE)
            Thread
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                IfLt(LVar0, 70)
                    Set(LVar0, 70)
                Else
                    Set(LVar0, 300)
                EndIf
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
                Call(SetNpcSpeed, NPC_SELF, Float(4.5 / DT))
                Call(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Set(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
            EndThread
            ExecGetTID(N(D_8024511C_B8929C), LVar9)
            Wait(35)
            Call(N(EnableCameraLeadingPlayer))
            Call(ResetCam, CAM_DEFAULT, Float(5.0))
            KillThread(LVar9)
            Call(SetSelfVar, 0, 3)
            Call(DisablePlayerInput, FALSE)
        CaseEq(3)
    EndSwitch
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
        Wait(1)
        Goto(0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado_Before) = {
    Label(0)
    IfNe(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        Wait(1)
        Goto(0)
    EndIf
    Label(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar0, 85)
        Wait(1)
        Goto(1)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH5_00C5, 0, 60)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(DisablePlayerInput, FALSE)
    Label(2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar0, -250)
        Wait(1)
        Goto(2)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C6)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(5.0))
    Call(NpcMoveTo, NPC_SELF, -470, 0, 0)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado_After) = {
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(10)
            Call(DisablePlayerInput, TRUE)
            Call(SetNpcPos, NPC_SELF, -100, 0, 60)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
            Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
            Call(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
            Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00CB)
            Call(SetSelfVar, 0, 0)
            Call(DisablePlayerInput, FALSE)
        CaseEq(20)
            Call(DisablePlayerInput, TRUE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00CF)
            Thread
                Label(20)
                Call(PlayerFaceNpc, NPC_Kolorado_02, FALSE)
                Call(GetSelfVar, 0, LVar0)
                IfEq(LVar0, 20)
                    Wait(1)
                    Goto(20)
                EndIf
            EndThread
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
            Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
            Call(NpcMoveTo, NPC_SELF, 190, 60, 0)
            Call(SetNpcJumpscale, NPC_SELF, Float(0.5))
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_SELF, 200, 0, 0, 20 * DT)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
            Call(SetSelfVar, 0, 21)
            Call(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
            Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            Call(MakeLerp, 0, 170, 60, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Set(LVar6, LVar4)
                Add(LVar6, LVar0)
                Call(SetNpcPos, NPC_SELF, LVar3, LVar6, LVar5)
                SetF(LVar2, Float(200.0))
                SubF(LVar2, LVar0)
                DivF(LVar2, Float(200.0))
                Call(ScaleModel, MODEL_o147, 1, LVar2, 1)
                Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o124, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Wait(40 * DT)
            Call(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
            Call(MakeLerp, 170, 0, 60, EASING_CUBIC_OUT)
            Loop(0)
                Call(UpdateLerp)
                SetF(LVar2, Float(200.0))
                SubF(LVar2, LVar0)
                DivF(LVar2, Float(200.0))
                Call(ScaleModel, MODEL_o147, 1, LVar2, 1)
                Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o124, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetSelfVar, 0, -1)
            Call(DisablePlayerInput, FALSE)
    EndSwitch
    IfNe(LVar0, -1)
        Wait(1)
        Goto(0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado_Before) = {
    Call(GetAngleToPlayer, NPC_SELF, LVar0)
    IfLt(LVar0, 180)
        Set(LVar1, 27)
    Else
        Set(LVar1, -27)
    EndIf
    Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Call(GetPlayerPos, LVarA, LVarB, LVarC)
    Sub(LVarA, LVar2)
    IfLt(LVarA, 0)
        Mul(LVarA, -1)
    EndIf
    IfLt(LVarA, 20)
        Add(LVar2, LVar1)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, LVar2, LVar4, 0)
        Call(PlayerFaceNpc, NPC_Kolorado_02, 3)
    EndIf
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C2)
    Call(InterpPlayerYaw, 90, 3)
    Call(InterpNpcYaw, NPC_SELF, 90, 3)
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 1, 8)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 200, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-11.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_00C3)
    Wait(10 * DT)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, 300, 15, Float(-6.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C4)
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(5.0 / DT))
    Call(NpcMoveTo, NPC_SELF, 500, 0, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcPos, NPC_SELF, -300, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(InterpNpcYaw, NPC_SELF, 90, 4)
    Set(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
    ExecWait(N(EVS_SetupMusic))
    Return
    End
};

EvtScript N(EVS_NpcHit_Kolorado_HeldCaptive) = {
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
    IfNe(LVar1, 0)
        Call(DisablePlayerInput, TRUE)
        Wait(5 * DT)
        Set(AF_JAN_0A, TRUE)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_SpearGuy, ANIM_SpearGuy_Anim0D)
        Call(NpcFacePlayer, NPC_SELF, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00BD)
        Set(AF_JAN_0A, FALSE)
        Call(SetNpcAnimation, NPC_SpearGuy, ANIM_SpearGuy_Anim10)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado_HeldCaptive) = {
    Call(SetSelfVar, 0, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado_HeldCaptive)))
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Kolorado_HeldCaptive)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado_WaitingToExplore) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SetNpcPos, NPC_SELF, 750, 0, 30)
            Call(SetSelfVar, 0, 0)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado_Before)))
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado_Before)))
        CaseRange(STORY_CH5_RAPHAEL_MOVED_ROOT, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado_After)))
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseDefault
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SyncZiplineDummyNPC1) = {
    Loop(0)
        Call(GetModelCenter, MODEL_o112)
        Call(SetNpcPos, NPC_ZiplineDummy1, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SyncZiplineDummyNPC2) = {
    Loop(0)
        Call(GetModelCenter, MODEL_o131)
        Call(SetNpcPos, NPC_ZiplineDummy2, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_ZiplineDummy) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcScale, NPC_SELF, Float(0.3), 1, Float(0.3))
    Return
    End
};

EvtScript N(EVS_NpcIdle_SpearGuy) = {
    ChildThread
        Call(GetNpcPos, NPC_SELF, LVar3, LVar1, LVar2)
        Set(LVar4, LVar3)
        Add(LVar3, -200)
        Add(LVar4, 200)
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Switch(LVar0)
                CaseRange(LVar3, LVar4)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 0)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 0)
                CaseDefault
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 1)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 1)
            EndSwitch
            Wait(1)
        EndLoop
    EndChildThread
    Set(AF_JAN_0A, FALSE)
    Set(LVar9, 0)
    Set(LVar8, 2)
    Loop(0)
        IfEq(LVar9, 0)
            Thread
                Wait(40)
                Call(ShowSweat, NPC_Kolorado_01, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
            EndThread
            Call(ShowSweat, NPC_Kolorado_01, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
            Set(LVar9, 3)
        Else
            Sub(LVar9, 1)
        EndIf
        Call(InterpNpcYaw, NPC_Kolorado_01, 270, 2)
        Wait(2)
        Label(1)
        IfEq(AF_JAN_0A, FALSE)
            Call(InterpNpcYaw, NPC_Kolorado_01, 90, 2)
            IfEq(LVar8, 0)
                Call(PlaySoundAtNpc, NPC_Kolorado_01, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
                Set(LVar8, 2)
            EndIf
            Sub(LVar8, 1)
        Else
            Set(LVar8, 2)
            Wait(1)
            Goto(1)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_SpearGuy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DisablePlayerInput, TRUE)
            Call(SetNpcYaw, NPC_Kolorado_01, 90)
            Call(SetNpcAnimation, NPC_Kolorado_01, ANIM_Kolorado_Idle)
            Thread
                Wait(30 * DT)
                Call(GetNpcPos, NPC_Kolorado_01, LVar3, LVar1, LVar2)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Set(LVar4, LVar0)
                IfLt(LVar3, LVar0)
                    Call(InterpPlayerYaw, 270, 0)
                    Add(LVar4, -30)
                Else
                    Call(InterpPlayerYaw, 90, 0)
                    Add(LVar4, 30)
                EndIf
                Add(LVar0, LVar4)
                Div(LVar0, 2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamDistance, CAM_DEFAULT, 300)
                Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.5))
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
                Call(N(DisableCameraLeadingPlayer))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(SetNpcFlagBits, NPC_Kolorado_01, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcAnimation, NPC_Kolorado_01, ANIM_Kolorado_Run)
                Call(SetNpcSpeed, NPC_Kolorado_01, Float(2.5 / DT))
                Call(NpcMoveTo, NPC_Kolorado_01, LVar4, LVar2, 0)
                Call(SetNpcAnimation, NPC_Kolorado_01, ANIM_Kolorado_Idle)
                Call(NpcFacePlayer, NPC_Kolorado_01, 0)
                Call(SetNpcVar, NPC_Kolorado_01, 0, 1)
            EndThread
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_SpearGuy) = {
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
        Call(SetNpcAnimation, NPC_SELF, ANIM_SpearGuy_Anim10)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SpearGuy)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_SpearGuy)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_Misstar_Bobbing) = {
    Loop(0)
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Misstar_CarryingParty) = {
    Set(AF_JAN22_MisstarReleasedParty, FALSE)
    Set(AF_JAN22_MisstarReleasedKolorado, FALSE)
    Label(0)
        Call(GetNpcPos, NPC_Misstar, LVar4, LVar2, LVar3)
        Add(LVar4, 10)
        Sub(LVar3, 5)
        Call(SetNpcPos, NPC_Kolorado_02, LVar4, LVar2, LVar3)
        IfEq(AF_JAN22_MisstarReleasedParty, FALSE)
            Sub(LVar4, 20)
            Add(LVar3, 10)
            Call(SetPlayerPos, LVar4, LVar2, LVar3)
            Add(LVar2, 20)
            Add(LVar3, -5)
            Call(SetNpcPos, NPC_PARTNER, LVar4, LVar2, LVar3)
        EndIf
        IfEq(AF_JAN22_MisstarReleasedKolorado, FALSE)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_PartnerFaceMisstar) = {
    Label(0)
        Call(PlayerFaceNpc, NPC_Misstar, TRUE)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Misstar, 1)
        Wait(1)
        Goto(0)
    Return
    End
};

Vec3f N(MisstarDescentPath)[] = {
    {  990.0,   210.0, -120.0 },
    {  925.0,   115.0,  -80.0 },
    {  860.0,    65.0,  -40.0 },
    {  725.0,    10.0,    0.0 },
};

EvtScript N(EVS_Scene_Misstar) = {
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Exec(N(EVS_Misstar_CarryingParty))
    Wait(30 * DT)
    Call(LoadPath, 45 * DT, Ref(N(MisstarDescentPath)), ARRAY_COUNT(N(MisstarDescentPath)), EASING_LINEAR)
    Label(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Call(DisablePlayerPhysics, FALSE)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.4))
    Set(AF_JAN22_MisstarReleasedParty, TRUE)
    Call(NpcJump0, NPC_SELF, 625, 20, 0, 25 * DT)
    Thread
        Call(SetNpcSpeed, NPC_PARTNER, Float(1.0 / DT))
        Call(NpcMoveTo, NPC_PARTNER, 700, 0, 0)
    EndThread
    Set(AF_JAN22_MisstarReleasedKolorado, TRUE)
    Call(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_GRAVITY, TRUE)
    Call(NpcJump0, NPC_SELF, 675, 40, 0, 20 * DT)
    ExecGetTID(N(EVS_Misstar_Bobbing), LVar9)
    Wait(20 * DT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 325)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-11.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_00D4)
    Call(NpcFaceNpc, NPC_SELF, NPC_Kolorado_02, 1)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 517, MSG_CH5_00D5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Idle)
    Loop(0)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar3, LVar2)
        IfEq(LVar3, LVar1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(EndSpeech, NPC_SELF, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 517)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_Kolorado_02, 270, 1)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 5, MSG_CH5_00D6)
    Wait(10 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(InterpNpcYaw, NPC_Kolorado_02, 90, 10)
    ExecGetTID(N(EVS_PartnerFaceMisstar), LVar8)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.5))
    Call(NpcJump0, NPC_SELF, 760, 35, 0, 20 * DT)
    KillThread(LVar8)
    Wait(5 * DT)
    Call(NpcFacePlayer, NPC_SELF, 4)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 512, MSG_CH5_00D7)
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar9)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Leap)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar1)
    Add(LVar1, 50)
    Add(LVar2, 10)
    Add(LVar3, 30)
    Loop(5)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        Wait(6 * DT)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        Wait(6 * DT)
    EndLoop
    Wait(20 * DT)
    Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Idle)
    ExecGetTID(N(EVS_Misstar_Bobbing), LVar9)
    Call(N(UpgradeStarPowerCh5))
    Call(ShowMessageAtScreenPos, MSG_Menus_0195, 160, 40)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 512, MSG_CH5_00D8)
    Wait(10 * DT)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Thread
        Loop(25)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            Wait(4 * DT)
        EndLoop
    EndThread
    Thread
        Set(LVar2, 0)
        Set(LVar3, 5 * 360)
        Call(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 180)
        Call(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(90 * DT)
#if VERSION_PAL
    Call(ResetCam, CAM_DEFAULT, Float(3 / DT))
#else
    Call(ResetCam, CAM_DEFAULT, 3)
#endif
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    KillThread(LVar9)
    Set(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_00D9)
    Wait(5 * DT)
    Call(InterpNpcYaw, NPC_Kolorado_02, 270, 4)
    Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_WalkSad)
    Call(SetNpcSpeed, NPC_Kolorado_02, Float(1.0 / DT))
    Call(NpcMoveTo, NPC_Kolorado_02, 530, 0, 0)
    Call(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, NPC_Kolorado_02, NPC_DISPOSE_LOCATION)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    IfEq(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Kolorado_02, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Call(InterpPlayerYaw, 270, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_IdleSad)
        Call(UseSettingsFrom, CAM_DEFAULT, 700, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, 700, 0, 0)
        Call(SetCamDistance, CAM_DEFAULT, 500)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_Misstar)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Kolorado)[] = {
    {
        .id = NPC_Kolorado_01,
        .pos = { -100.0f, 0.0f, 10.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado_HeldCaptive),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_Kolorado_02,
        .pos = { -100.0f, 0.0f, 10.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado_WaitingToExplore),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy1,
        .pos = { -100.0f, 0.0f, 10.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ZiplineDummy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy2,
        .pos = { -100.0f, 0.0f, 10.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ZiplineDummy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

NpcData N(NpcData_SpearGuy) = {
    .id = NPC_SpearGuy,
    .pos = { -70.0f, 0.0f, 10.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 3,
            .points  = {
                { 368, 0, 190 },
                { 411, 0, 190 },
                { 396, 0, 239 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -70, 0, 10 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_SpearGuy),
    .settings = &N(NpcSettings_SpearGuy_Patrol),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = SPEAR_GUY_ANIMS,
};

NpcData N(NpcData_RaphaelRaven)[] = {
    {
        .id = NPC_RaphaelRaven,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RaphaelRaven),
        .settings = &N(NpcSettings_RaphaelRaven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAPHAEL_RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RaphaelRaven,
    },
    {
        .id = NPC_Raven_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenA,
    },
    {
        .id = NPC_Raven_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
    },
    {
        .id = NPC_Raven_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenC,
    },
    {
        .id = NPC_Raven_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenD,
    },
    {
        .id = NPC_Raven_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenE,
    },
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { 1075.0f, 120.0f, 130.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Misstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_SpearGuy), BTL_JAN_FORMATION_00, BTL_JAN_STAGE_07),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};

NpcGroupList N(RavenNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_RaphaelRaven)),
    {}
};
