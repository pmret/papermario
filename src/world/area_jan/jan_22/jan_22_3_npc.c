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
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseBasketElevator) = {
    EVT_CALL(GetPartnerInUse, LVar9)
    EVT_IF_EQ(LVar9, PARTNER_KOOPER)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar9, PARTNER_BOMBETTE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar9, PARTNER_LAKILESTER)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsPlayerWithin, 200, 0, 25, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_WAIT(7)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_ADD(LVar5, -5)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar3, LVar4, LVar5, 10)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(EVS_TetherCamToBasketPlayer), LVar7)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
    EVT_CALL(MakeLerp, 0, 170, 60, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar6, LVar4)
        EVT_ADD(LVar6, LVar0)
        EVT_CALL(SetPlayerPos, LVar3, LVar6, LVar5)
        EVT_CALL(GetPartnerInUse, LVar8)
        EVT_IF_EQ(LVar8, PARTNER_NONE)
            EVT_ADD(LVar6, 5)
            EVT_ADD(LVar5, -5)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar3, LVar6, LVar5)
            EVT_ADD(LVar6, -5)
            EVT_ADD(LVar5, 5)
        EVT_END_IF
        EVT_SETF(LVar2, EVT_FLOAT(200.0))
        EVT_SUBF(LVar2, LVar0)
        EVT_DIVF(LVar2, EVT_FLOAT(200.0))
        EVT_CALL(ScaleModel, MODEL_o147, 1, LVar2, 1)
        EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o124, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar7)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
        EVT_CALL(MakeLerp, 170, 0, 60, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, EVT_FLOAT(200.0))
            EVT_SUBF(LVar2, LVar0)
            EVT_DIVF(LVar2, EVT_FLOAT(200.0))
            EVT_CALL(ScaleModel, MODEL_o147, 1, LVar2, 1)
            EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
            EVT_CALL(TranslateModel, MODEL_o124, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump, 270, 205, 15, 20)
        EVT_CALL(HidePlayerShadow, FALSE)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 285, 15, 0)
    EVT_END_THREAD
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_WAIT(10)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, 260, 205, 15, 15)
    EVT_END_IF
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(5)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBasketElevator) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseBasketElevator)), TRIGGER_FLOOR_TOUCH, COLLIDER_o124, 1, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o124, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ScaleModel, MODEL_o147, 1, EVT_FLOAT(0.15625), 1)
        EVT_CALL(TranslateModel, MODEL_o146, 0, 178, 0)
        EVT_CALL(TranslateModel, MODEL_o124, 0, 178, 0)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o124, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ScaleModel, MODEL_o147, 1, 1, 1)
        EVT_CALL(TranslateModel, MODEL_o146, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o124, 0, 0, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GatherRavensNearRaphael) = {
    EVT_CALL(SetNpcPos, NPC_Raven_01, 177, 0, -10)
    EVT_CALL(SetNpcPos, NPC_Raven_02, 127, 0, 5)
    EVT_CALL(SetNpcPos, NPC_Raven_03, 152, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Raven_04, 102, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Raven_05, 77, 0, -10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Ravens_LeapIntoTree) = {
    EVT_CHILD_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Flail)
        EVT_CALL(NpcJump0, NPC_Raven_02, 271, 325, -17, 30 * DT)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_WAIT(3 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Flail)
        EVT_CALL(NpcJump0, NPC_Raven_05, 400, 215, -23, 30 * DT)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_WAIT(6 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_01, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Flail)
        EVT_CALL(NpcJump0, NPC_Raven_01, 208, 335, -17, 30 * DT)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_WAIT(9 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Flail)
        EVT_CALL(NpcJump0, NPC_Raven_03, 327, 200, -8, 30 * DT)
    EVT_END_CHILD_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Flail)
    EVT_CALL(NpcJump0, NPC_Raven_04, 222, 284, -13, 15 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RaphaelRaven) = {
    EVT_CALL(GetNpcPos, NPC_RaphaelRaven, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_RaphaelRaven, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00C7)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00C8)
    EVT_CALL(SetNpcVar, NPC_Raven_01, 0, RAVEN_SCENE_LEAP_INTO_ACTION)
    EVT_CALL(BindNpcInteract, NPC_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_RaphaelRaven) = {
    EVT_LABEL(0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RaphaelRaven)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RaphaelRaven) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_RaphaelRaven)))
        EVT_CASE_EQ(STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            EVT_CALL(SetNpcPos, NPC_SELF, 125, 0, -40)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RaphaelRaven)))
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Raven) = {
    EVT_IF_EQ(GF_JAN22_Met_Raven, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Raven_01, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00D2)
        EVT_SET(GF_JAN22_Met_Raven, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Raven_01, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00D3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven_HopAndWalkAway) = {
    EVT_WAIT(45)
    EVT_CALL(NpcJump0, LVar0, 30, 0, -15, 10)
    EVT_CALL(SetNpcAnimation, LVar0, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, LVar0, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, LVar0, -120, 0, 0)
    EVT_CALL(SetNpcPos, LVar0, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BuildingEffects) = {
    EVT_CALL(PlaySoundAt, SOUND_LOOP_JAN_CONSTRUCTION, SOUND_SPACE_DEFAULT, 270, 130, 0)
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(1.0))
        EVT_WAIT(30 * DT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 8, EVT_FLOAT(1.0))
        EVT_CALL(RandInt, 4, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 290, 155, 0, 240, 0, 0, LVar0)
        EVT_WAIT(10 * DT)
        EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, 275, 150, 0, 240, 0, 0, 3)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(1.0))
        EVT_WAIT(4 * DT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(1.0))
        EVT_WAIT(4 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageRavens) = {
    EVT_LABEL(0)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o304, COLLIDER_FLAGS_UPPER_MASK)
    EVT_LABEL(1)
        EVT_CALL(NpcFacePlayer, NPC_Raven_01, 0)
        EVT_CALL(NpcFacePlayer, NPC_Raven_02, 0)
        EVT_CALL(NpcFacePlayer, NPC_Raven_03, 0)
        EVT_CALL(NpcFacePlayer, NPC_Raven_04, 0)
        EVT_CALL(NpcFacePlayer, NPC_Raven_05, 0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, RAVEN_SCENE_AWAITING_COMMAND)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o304, COLLIDER_FLAGS_UPPER_MASK)
    EVT_LABEL(2)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(RAVEN_SCENE_LEAP_INTO_ACTION)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(InterpNpcYaw, NPC_Raven_01, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_Raven_02, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_Raven_03, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_Raven_04, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_Raven_05, 90, 0)
                EVT_WAIT(10 * DT)
                EVT_EXEC_GET_TID(N(EVS_Ravens_LeapIntoTree), LVar9)
                EVT_WAIT(40 * DT)
                EVT_KILL_THREAD(LVar9)
                EVT_WAIT(10 * DT)
                EVT_CALL(SetNpcPos, NPC_Raven_01, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcPos, NPC_Raven_02, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcPos, NPC_Raven_03, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcPos, NPC_Raven_04, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcPos, NPC_Raven_05, NPC_DISPOSE_LOCATION)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 300, 250, 150)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 250, 150)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                // repeat the action with a time delay across the sudden camera cut
                EVT_EXEC(N(EVS_GatherRavensNearRaphael))
                EVT_WAIT(10 * DT)
                EVT_EXEC_WAIT(N(EVS_Ravens_LeapIntoTree))
                EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
                EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
                EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
                EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_04, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(1.0))
                EVT_THREAD
                    EVT_CALL(SetNpcJumpscale, NPC_Raven_01, EVT_FLOAT(3.0))
                    EVT_CALL(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Raven_01, LVar0, LVar1, LVar2, 5 * DT)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(SetNpcJumpscale, NPC_Raven_02, EVT_FLOAT(3.0))
                    EVT_CALL(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Raven_02, LVar0, LVar1, LVar2, 5 * DT)
                    EVT_CALL(InterpNpcYaw, NPC_Raven_02, 270, 0)
                EVT_END_THREAD
                EVT_WAIT(3 * DT)
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
                EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, 180)
                EVT_CALL(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, TRUE)
                EVT_CALL(InterpNpcYaw, NPC_Raven_03, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_Raven_05, 270, 0)
                EVT_CALL(SetNpcYaw, NPC_RaphaelRaven, 90)
                EVT_CALL(GetNpcPos, NPC_RaphaelRaven, LVar0, LVar1, LVar2)
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_ADD(LVar2, 80)
                EVT_CALL(SetPlayerPos, 145, 0, LVar2)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(SetNpcPos, NPC_PARTNER, 115, 0, LVar2)
                EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
                EVT_WAIT(80 * DT)
                EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, 0)
                EVT_CALL(SetSelfVar, 0, RAVEN_SCENE_CONSTRUCTION_WORK)
            EVT_CASE_EQ(RAVEN_SCENE_CONSTRUCTION_WORK)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 165, 0, 0)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 165, 0, 0)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_WAIT(20 * DT)
                EVT_CALL(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, FALSE)
                EVT_CALL(NpcMoveTo, NPC_Raven_04, 260, -20, 0)
                EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, 90)
                EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
                EVT_CALL(NpcJump0, NPC_Raven_04, 300, 300, -14, 20 * DT)
                EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, 0)
                EVT_EXEC_GET_TID(N(EVS_BuildingEffects), LVarA)
                EVT_WAIT(30 * DT)
                EVT_CALL(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00CA)
                EVT_WAIT(50 * DT)
                EVT_CALL(SetNpcVar, NPC_Kolorado_02, 0, 10)
                EVT_WAIT(140 * DT)
                EVT_LABEL(11)
                    EVT_CALL(GetNpcVar, NPC_Kolorado_02, 0, LVar0)
                    EVT_IF_NE(LVar0, 0)
                        EVT_WAIT(1)
                        EVT_GOTO(11)
                    EVT_END_IF
                EVT_WAIT(40 * DT)
                EVT_CALL(StopSound, SOUND_LOOP_JAN_CONSTRUCTION)
                EVT_KILL_THREAD(LVarA)
                EVT_CALL(SetSelfVar, 0, RAVEN_SCENE_FINISH_WORK)
            EVT_CASE_EQ(RAVEN_SCENE_FINISH_WORK)
                EVT_WAIT(20 * DT)
                EVT_CALL(SetGroupVisibility, MODEL_g39, MODEL_GROUP_VISIBLE)
                EVT_CALL(SetGroupVisibility, MODEL_g52, MODEL_GROUP_VISIBLE)
                EVT_CALL(SetGroupVisibility, MODEL_g58, MODEL_GROUP_VISIBLE)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g29, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g39, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g86, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
                EVT_CALL(SetNpcPos, NPC_Raven_01, 255, 205, -25)
                EVT_CALL(SetNpcPos, NPC_Raven_02, 200, 185, 0)
                EVT_CALL(SetNpcPos, NPC_Raven_03, 338, 212, -20)
                EVT_CALL(SetNpcPos, NPC_Raven_04, 267, 314, -12)
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 60)
                EVT_CALL(NpcJump0, NPC_Raven_05, LVar0, 0, 40, 20 * DT)
                EVT_WAIT(10 * DT)
                EVT_CALL(SpeakToPlayer, NPC_Raven_05, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00CC)
                EVT_WAIT(15 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
                EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
                EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
                EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 300, 250, 150)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 250, 150)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_WAIT(15 * DT)
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                EVT_CALL(SetNpcPos, NPC_Raven_05, 350, 0, 100)
                EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Flail)
                EVT_CALL(NpcJump0, NPC_Raven_05, 400, 215, -23, 20 * DT)
                EVT_CALL(SpeakToPlayer, NPC_Raven_05, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00CD)
                EVT_THREAD
                    EVT_CALL(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
                    EVT_CALL(MakeLerp, 170, 0, 60, EASING_CUBIC_OUT)
                    EVT_LOOP(0)
                        EVT_CALL(UpdateLerp)
                        EVT_SET(LVar3, LVar0)
                        EVT_ADD(LVar3, 9)
                        EVT_CALL(SetNpcPos, NPC_Raven_02, 200, LVar3, 0)
                        EVT_SETF(LVar2, EVT_FLOAT(200.0))
                        EVT_SUBF(LVar2, LVar0)
                        EVT_DIVF(LVar2, EVT_FLOAT(200.0))
                        EVT_CALL(ScaleModel, MODEL_o147, 1, LVar2, 1)
                        EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
                        EVT_CALL(TranslateModel, MODEL_o124, 0, LVar0, 0)
                        EVT_WAIT(1)
                        EVT_IF_EQ(LVar1, 0)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                    EVT_CALL(SetSelfVar, 0, RAVEN_SCENE_LOWERED_BASKET)
                EVT_END_THREAD
                EVT_WAIT(20 * DT)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 165, 0, 0)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 165, 0, 0)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_WAIT(10 * DT)
                EVT_CALL(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00CE)
                EVT_LOOP(0)
                    EVT_WAIT(1)
                    EVT_CALL(GetSelfVar, 0, LVar0)
                    EVT_IF_EQ(LVar0, RAVEN_SCENE_LOWERED_BASKET)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_Raven_05, 150, 0, 20, 15 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
                EVT_THREAD
                    EVT_CALL(NpcMoveTo, NPC_Raven_05, 65, 25, 30 * DT)
                    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
                    EVT_CALL(InterpNpcYaw, NPC_Raven_05, 90, 0)
                EVT_END_THREAD
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_Raven_04, 150, 0, 20, 15 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
                EVT_THREAD
                    EVT_CALL(NpcMoveTo, NPC_Raven_04, 80, -10, 25 * DT)
                    EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
                    EVT_CALL(InterpNpcYaw, NPC_Raven_04, 90, 0)
                EVT_END_THREAD
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_LEAP_A, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_Raven_03, 150, 0, 20, 15 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
                EVT_THREAD
                    EVT_CALL(NpcMoveTo, NPC_Raven_03, 95, 25, 20 * DT)
                    EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
                    EVT_CALL(InterpNpcYaw, NPC_Raven_03, 90, 0)
                EVT_END_THREAD
                EVT_CALL(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_LEAP_B, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_Raven_02, 150, 0, 20, 15 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
                EVT_CALL(NpcMoveTo, NPC_Raven_02, 110, -10, 15 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
                EVT_CALL(InterpNpcYaw, NPC_Raven_02, 90, 0)
                EVT_CALL(SetNpcVar, NPC_Kolorado_02, 0, 20)
                EVT_CALL(SetSelfVar, 0, RAVEN_SCENE_HEADNG_OUT)
            EVT_CASE_EQ(RAVEN_SCENE_HEADNG_OUT)
                EVT_CALL(GetNpcVar, NPC_Kolorado_02, 0, LVar0)
                EVT_IF_EQ(LVar0, -1)
                    EVT_CALL(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00D0)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
                    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0 / DT))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_GIVE_KEY_REWARD(ITEM_ULTRA_STONE)
                    EVT_WAIT(20 * DT)
                    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
                    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-11.5))
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.5 / DT))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                    EVT_CALL(SpeakToPlayer, NPC_RaphaelRaven, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00D1)
                    EVT_SET(LVar0, NPC_Raven_02)
                    EVT_EXEC(N(EVS_Raven_HopAndWalkAway))
                    EVT_THREAD
                        EVT_WAIT(10 * DT)
                        EVT_SET(LVar0, NPC_Raven_03)
                        EVT_EXEC(N(EVS_Raven_HopAndWalkAway))
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_WAIT(20 * DT)
                        EVT_SET(LVar0, NPC_Raven_04)
                        EVT_EXEC(N(EVS_Raven_HopAndWalkAway))
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_WAIT(30 * DT)
                        EVT_SET(LVar0, NPC_Raven_05)
                        EVT_EXEC(N(EVS_Raven_HopAndWalkAway))
                    EVT_END_THREAD
                    EVT_CALL(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_Walk)
                    EVT_CALL(SetNpcSpeed, NPC_RaphaelRaven, EVT_FLOAT(3.0 / DT))
                    EVT_CALL(NpcMoveTo, NPC_RaphaelRaven, -120, 0, 0)
                    EVT_CALL(SetNpcPos, NPC_RaphaelRaven, NPC_DISPOSE_LOCATION)
                    EVT_WAIT(40 * DT)
                    EVT_CALL(BindNpcInteract, NPC_Raven_01, EVT_PTR(N(EVS_NpcInteract_Raven)))
                    EVT_CALL(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                    EVT_CALL(N(EnableCameraLeadingPlayer))
                    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
                    EVT_SET(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                    EVT_CALL(DisablePlayerInput, FALSE)
                    EVT_RETURN
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_GOTO(2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_ManageRavens)))
        EVT_CASE_EQ(STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_ManageRavens)))
            EVT_EXEC(N(EVS_GatherRavensNearRaphael))
        EVT_CASE_RANGE(STORY_CH5_ZIP_LINE_READY, STORY_CH5_OPENED_ESCAPE_ROUTE)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Raven)))
            EVT_CALL(SetNpcPos, NPC_Raven_01, 260, 205, -25)
            EVT_CALL(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_GOTO(30)
        EVT_CASE_DEFAULT
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o346, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(RemoveNpc, NPC_Raven_01)
            EVT_LABEL(30)
            EVT_CALL(RemoveNpc, NPC_Raven_02)
            EVT_CALL(RemoveNpc, NPC_Raven_03)
            EVT_CALL(RemoveNpc, NPC_Raven_04)
            EVT_CALL(RemoveNpc, NPC_Raven_05)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Vec3f N(RaphaelWalkPath)[] = {
    { -190.0,     0.0, -200.0 },
    { -185.0,     0.0,  -95.0 },
    { -180.0,     0.0,   10.0 },
};

EvtScript N(EVS_Scene_RaphaelComingThrough) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_RaphaelRaven, -200, 0, -170)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerPos, -190, 0, -200)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -190, 0, -210)
    EVT_EXEC_WAIT(N(EVS_MoveBushes))
    EVT_CALL(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_RaphaelRaven, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_RaphaelRaven, -180, -30, 0)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_RaphaelRaven, 125, -40, 0)
        EVT_CALL(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_Idle)
        EVT_CALL(SetNpcFlagBits, NPC_RaphaelRaven, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(InterpNpcYaw, NPC_RaphaelRaven, 270, 0)
    EVT_END_THREAD
    EVT_WAIT(15 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Run)
    EVT_CALL(LoadPath, 45 * DT, EVT_PTR(N(RaphaelWalkPath)), ARRAY_COUNT(N(RaphaelWalkPath)), EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_Raven_01, -200, 0, -190)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Raven_01, EVT_FLOAT(6.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Raven_01, -150, -10, 0)
        EVT_CALL(NpcMoveTo, NPC_Raven_01, 177, -10, 0)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(SetNpcPos, NPC_Raven_02, -200, 0, -230)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Raven_02, EVT_FLOAT(6.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Raven_02, -150, -10, 0)
        EVT_CALL(NpcMoveTo, NPC_Raven_02, 152, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcPos, NPC_Raven_03, -200, 0, -230)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Raven_03, EVT_FLOAT(6.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Raven_03, -150, -10, 0)
        EVT_CALL(NpcMoveTo, NPC_Raven_03, 127, 5, 0)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(45 * DT)
        EVT_CALL(SetNpcPos, NPC_Raven_04, -200, 0, -230)
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Raven_04, EVT_FLOAT(6.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Raven_04, -150, -10, 0)
        EVT_CALL(NpcMoveTo, NPC_Raven_04, 102, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcPos, NPC_Raven_05, -200, 0, -230)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Raven_05, EVT_FLOAT(6.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Raven_05, -150, -10, 0)
    EVT_CALL(NpcMoveTo, NPC_Raven_05, 77, -10, 0)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    EVT_SET(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024511C_B8929C) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 150)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
    EVT_CALL(SetSelfVar, 0, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado_HeldCaptive) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -440)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00BC, 320, 60)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, 150)
                EVT_CALL(GetPartnerInUse, LVar0)
                EVT_IF_NE(LVar0, PARTNER_NONE)
                    EVT_CALL(InterruptUsePartner)
                EVT_END_IF
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(func_802D2C14, 1)
                EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(RemoveNpc, NPC_SpearGuy)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00C0, 0, 60)
                EVT_CALL(InterpPlayerYaw, 270, 4)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0 / DT))
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_SET(LVar3, LVar0)
                EVT_ADD(LVar3, -50)
                EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
                EVT_ADD(LVar0, LVar3)
                EVT_DIV(LVar0, 2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.5))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(N(DisableCameraLeadingPlayer))
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_WAIT(10 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C1)
                EVT_CALL(SetSelfVar, 0, 2)
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_SET_GROUP(EVT_GROUP_00)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
            EVT_CALL(func_802D2C14, 1)
            EVT_WAIT(10 * DT)
            EVT_IF_EQ(GF_JAN01_SavedKolorado, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Idle, 0, MSG_CH5_00BE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Idle, 0, MSG_CH5_00BF)
            EVT_END_IF
            EVT_CALL(SetSelfVar, 0, 2)
            EVT_CALL(func_802D2C14, 0)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_SET_GROUP(EVT_GROUP_0B)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(2)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_THREAD
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_IF_LT(LVar0, 70)
                    EVT_SET(LVar0, 70)
                EVT_ELSE
                    EVT_SET(LVar0, 300)
                EVT_END_IF
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.5 / DT))
                EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
            EVT_END_THREAD
            EVT_EXEC_GET_TID(N(D_8024511C_B8929C), LVar9)
            EVT_WAIT(35)
            EVT_CALL(N(EnableCameraLeadingPlayer))
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
            EVT_KILL_THREAD(LVar9)
            EVT_CALL(SetSelfVar, 0, 3)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(3)
    EVT_END_SWITCH
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado_Before) = {
    EVT_LABEL(0)
    EVT_IF_NE(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar0, 85)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00C5, 0, 60)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar0, -250)
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C6)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, -470, 0, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado_After) = {
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, -100, 0, 60)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
            EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
            EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00CB)
            EVT_CALL(SetSelfVar, 0, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(20)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00CF)
            EVT_THREAD
                EVT_LABEL(20)
                EVT_CALL(PlayerFaceNpc, NPC_Kolorado_02, FALSE)
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_EQ(LVar0, 20)
                    EVT_WAIT(1)
                    EVT_GOTO(20)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
            EVT_CALL(NpcMoveTo, NPC_SELF, 190, 60, 0)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_SELF, 200, 0, 0, 20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
            EVT_CALL(SetSelfVar, 0, 21)
            EVT_CALL(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(MakeLerp, 0, 170, 60, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SET(LVar6, LVar4)
                EVT_ADD(LVar6, LVar0)
                EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar6, LVar5)
                EVT_SETF(LVar2, EVT_FLOAT(200.0))
                EVT_SUBF(LVar2, LVar0)
                EVT_DIVF(LVar2, EVT_FLOAT(200.0))
                EVT_CALL(ScaleModel, MODEL_o147, 1, LVar2, 1)
                EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o124, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_WAIT(40 * DT)
            EVT_CALL(PlaySoundAtModel, MODEL_o123, SOUND_JAN_BASKET_ELEVATOR, 0)
            EVT_CALL(MakeLerp, 170, 0, 60, EASING_CUBIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SETF(LVar2, EVT_FLOAT(200.0))
                EVT_SUBF(LVar2, LVar0)
                EVT_DIVF(LVar2, EVT_FLOAT(200.0))
                EVT_CALL(ScaleModel, MODEL_o147, 1, LVar2, 1)
                EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o124, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetSelfVar, 0, -1)
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_IF_NE(LVar0, -1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado_Before) = {
    EVT_CALL(GetAngleToPlayer, NPC_SELF, LVar0)
    EVT_IF_LT(LVar0, 180)
        EVT_SET(LVar1, 27)
    EVT_ELSE
        EVT_SET(LVar1, -27)
    EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
    EVT_SUB(LVarA, LVar2)
    EVT_IF_LT(LVarA, 0)
        EVT_MUL(LVarA, -1)
    EVT_END_IF
    EVT_IF_LT(LVarA, 20)
        EVT_ADD(LVar2, LVar1)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, LVar2, LVar4, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Kolorado_02, 3)
    EVT_END_IF
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C2)
    EVT_CALL(InterpPlayerYaw, 90, 3)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 3)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 1, 8)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 200, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_00C3)
    EVT_WAIT(10 * DT)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 300, 15, EVT_FLOAT(-6.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00C4)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, 500, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, -300, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 4)
    EVT_SET(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Kolorado_HeldCaptive) = {
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
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(5 * DT)
        EVT_SET(AF_JAN_0A, TRUE)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SpearGuy, ANIM_SpearGuy_Anim0D)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00BD)
        EVT_SET(AF_JAN_0A, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SpearGuy, ANIM_SpearGuy_Anim10)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado_HeldCaptive) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado_HeldCaptive)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Kolorado_HeldCaptive)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado_WaitingToExplore) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SetNpcPos, NPC_SELF, 750, 0, 30)
            EVT_CALL(SetSelfVar, 0, 0)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado_Before)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado_Before)))
        EVT_CASE_RANGE(STORY_CH5_RAPHAEL_MOVED_ROOT, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado_After)))
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SyncZiplineDummyNPC1) = {
    EVT_LOOP(0)
        EVT_CALL(GetModelCenter, MODEL_o112)
        EVT_CALL(SetNpcPos, NPC_ZiplineDummy1, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SyncZiplineDummyNPC2) = {
    EVT_LOOP(0)
        EVT_CALL(GetModelCenter, MODEL_o131)
        EVT_CALL(SetNpcPos, NPC_ZiplineDummy2, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ZiplineDummy) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(0.3), 1, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_SpearGuy) = {
    EVT_CHILD_THREAD
        EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar1, LVar2)
        EVT_SET(LVar4, LVar3)
        EVT_ADD(LVar3, -200)
        EVT_ADD(LVar4, 200)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar0)
                EVT_CASE_RANGE(LVar3, LVar4)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 0)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 0)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 1)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 1)
            EVT_END_SWITCH
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(AF_JAN_0A, FALSE)
    EVT_SET(LVar9, 0)
    EVT_SET(LVar8, 2)
    EVT_LOOP(0)
        EVT_IF_EQ(LVar9, 0)
            EVT_THREAD
                EVT_WAIT(40)
                EVT_CALL(ShowSweat, NPC_Kolorado_01, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
            EVT_END_THREAD
            EVT_CALL(ShowSweat, NPC_Kolorado_01, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
            EVT_SET(LVar9, 3)
        EVT_ELSE
            EVT_SUB(LVar9, 1)
        EVT_END_IF
        EVT_CALL(InterpNpcYaw, NPC_Kolorado_01, 270, 2)
        EVT_WAIT(2)
        EVT_LABEL(1)
        EVT_IF_EQ(AF_JAN_0A, FALSE)
            EVT_CALL(InterpNpcYaw, NPC_Kolorado_01, 90, 2)
            EVT_IF_EQ(LVar8, 0)
                EVT_CALL(PlaySoundAtNpc, NPC_Kolorado_01, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
                EVT_SET(LVar8, 2)
            EVT_END_IF
            EVT_SUB(LVar8, 1)
        EVT_ELSE
            EVT_SET(LVar8, 2)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_SpearGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcYaw, NPC_Kolorado_01, 90)
            EVT_CALL(SetNpcAnimation, NPC_Kolorado_01, ANIM_Kolorado_Idle)
            EVT_THREAD
                EVT_WAIT(30 * DT)
                EVT_CALL(GetNpcPos, NPC_Kolorado_01, LVar3, LVar1, LVar2)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_SET(LVar4, LVar0)
                EVT_IF_LT(LVar3, LVar0)
                    EVT_CALL(InterpPlayerYaw, 270, 0)
                    EVT_ADD(LVar4, -30)
                EVT_ELSE
                    EVT_CALL(InterpPlayerYaw, 90, 0)
                    EVT_ADD(LVar4, 30)
                EVT_END_IF
                EVT_ADD(LVar0, LVar4)
                EVT_DIV(LVar0, 2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.5))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
                EVT_CALL(N(DisableCameraLeadingPlayer))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(SetNpcFlagBits, NPC_Kolorado_01, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_Kolorado_01, ANIM_Kolorado_Run)
                EVT_CALL(SetNpcSpeed, NPC_Kolorado_01, EVT_FLOAT(2.5 / DT))
                EVT_CALL(NpcMoveTo, NPC_Kolorado_01, LVar4, LVar2, 0)
                EVT_CALL(SetNpcAnimation, NPC_Kolorado_01, ANIM_Kolorado_Idle)
                EVT_CALL(NpcFacePlayer, NPC_Kolorado_01, 0)
                EVT_CALL(SetNpcVar, NPC_Kolorado_01, 0, 1)
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_SpearGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpearGuy_Anim10)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SpearGuy)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_SpearGuy)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Misstar_Bobbing) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Misstar_CarryingParty) = {
    EVT_SET(AF_JAN22_MisstarReleasedParty, FALSE)
    EVT_SET(AF_JAN22_MisstarReleasedKolorado, FALSE)
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar4, LVar2, LVar3)
        EVT_ADD(LVar4, 10)
        EVT_SUB(LVar3, 5)
        EVT_CALL(SetNpcPos, NPC_Kolorado_02, LVar4, LVar2, LVar3)
        EVT_IF_EQ(AF_JAN22_MisstarReleasedParty, FALSE)
            EVT_SUB(LVar4, 20)
            EVT_ADD(LVar3, 10)
            EVT_CALL(SetPlayerPos, LVar4, LVar2, LVar3)
            EVT_ADD(LVar2, 20)
            EVT_ADD(LVar3, -5)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar4, LVar2, LVar3)
        EVT_END_IF
        EVT_IF_EQ(AF_JAN22_MisstarReleasedKolorado, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PartnerFaceMisstar) = {
    EVT_LABEL(0)
        EVT_CALL(PlayerFaceNpc, NPC_Misstar, TRUE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Misstar, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

Vec3f N(MisstarDescentPath)[] = {
    {  990.0,   210.0, -120.0 },
    {  925.0,   115.0,  -80.0 },
    {  860.0,    65.0,  -40.0 },
    {  725.0,    10.0,    0.0 },
};

EvtScript N(EVS_Scene_Misstar) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_EXEC(N(EVS_Misstar_CarryingParty))
    EVT_WAIT(30 * DT)
    EVT_CALL(LoadPath, 45 * DT, EVT_PTR(N(MisstarDescentPath)), ARRAY_COUNT(N(MisstarDescentPath)), EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.4))
    EVT_SET(AF_JAN22_MisstarReleasedParty, TRUE)
    EVT_CALL(NpcJump0, NPC_SELF, 625, 20, 0, 25 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(1.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 700, 0, 0)
    EVT_END_THREAD
    EVT_SET(AF_JAN22_MisstarReleasedKolorado, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(NpcJump0, NPC_SELF, 675, 40, 0, 20 * DT)
    EVT_EXEC_GET_TID(N(EVS_Misstar_Bobbing), LVar9)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 325)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_00D4)
    EVT_CALL(NpcFaceNpc, NPC_SELF, NPC_Kolorado_02, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 517, MSG_CH5_00D5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Idle)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar3, LVar2)
        EVT_IF_EQ(LVar3, LVar1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 517)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 270, 1)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 5, MSG_CH5_00D6)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 90, 10)
    EVT_EXEC_GET_TID(N(EVS_PartnerFaceMisstar), LVar8)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_SELF, 760, 35, 0, 20 * DT)
    EVT_KILL_THREAD(LVar8)
    EVT_WAIT(5 * DT)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 4)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 512, MSG_CH5_00D7)
    EVT_CALL(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Leap)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6 * DT)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6 * DT)
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Idle)
    EVT_EXEC_GET_TID(N(EVS_Misstar_Bobbing), LVar9)
    EVT_CALL(N(UpgradeStarPowerCh5))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0195, 160, 40)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 512, MSG_CH5_00D8)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 5 * 360)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(90 * DT)
#if VERSION_PAL
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(ResetCam, CAM_DEFAULT, 3)
#endif
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_KILL_THREAD(LVar9)
    EVT_SET(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_00D9)
    EVT_WAIT(5 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kolorado_02, 270, 4)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_WalkSad)
    EVT_CALL(SetNpcSpeed, NPC_Kolorado_02, EVT_FLOAT(1.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Kolorado_02, 530, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_Kolorado_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Kolorado_02, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_IdleSad)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 700, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 700, 0, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_Misstar)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
