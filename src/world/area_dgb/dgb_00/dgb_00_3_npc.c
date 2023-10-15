#include "dgb_00.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(PlaySentinelSounds)) {
    Npc* npc = get_npc_unsafe(get_enemy(NPC_Sentinel)->npcID);

    sfx_adjust_env_sound_pos(SOUND_LRAW_SENTINEL_ALARM, SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}

#include "world/common/npc/Boo.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Sentinel.h"

EvtScript N(EVS_SetDoorRots) = {
    EVT_SET(LVar3, 0)
    EVT_SUB(LVar3, LVar2)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliwt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deiliwt, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_d2, LVar0, 0, LVar2, 0)
        EVT_CALL(RotateModel, MODEL_d1, LVar0, 0, LVar3, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseDoors) = {
    EVT_SET(LVar3, 0)
    EVT_SUB(LVar3, LVar2)
    EVT_CALL(MakeLerp, 80, 0, 12, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_d2, LVar0, 0, LVar2, 0)
        EVT_CALL(RotateModel, MODEL_d1, LVar0, 0, LVar3, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deiliwt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deiliwt, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBoo1) = {
    EVT_CALL(GetNpcPos, NPC_Boo_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_Boo_01, LVar0, LVar2, 46 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBoo2) = {
    EVT_CALL(GetNpcPos, NPC_Boo_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_Boo_02, LVar0, LVar2, 50 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBoo3) = {
    EVT_CALL(GetNpcPos, NPC_Boo_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_Boo_03, LVar0, LVar2, 53 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBoo4) = {
    EVT_CALL(GetNpcPos, NPC_Boo_04, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_Boo_04, LVar0, LVar2, 46 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBoo5) = {
    EVT_CALL(GetNpcPos, NPC_Boo_05, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_Boo_05, LVar0, LVar2, 50 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBoo6) = {
    EVT_CALL(GetNpcPos, NPC_Boo_06, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_Boo_06, LVar0, LVar2, 53 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AdvanceBooPhalanx) = {
    EVT_EXEC(N(EVS_AdvanceBoo1))
    EVT_EXEC(N(EVS_AdvanceBoo2))
    EVT_EXEC(N(EVS_AdvanceBoo3))
    EVT_EXEC(N(EVS_AdvanceBoo4))
    EVT_EXEC(N(EVS_AdvanceBoo5))
    EVT_EXEC(N(EVS_AdvanceBoo6))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BraceDoor1) = {
    EVT_CALL(SetNpcJumpscale, NPC_Boo_01, EVT_FLOAT(-0.2))
    EVT_CALL(NpcJump0, NPC_Boo_01, 257, 30, -90, 5 * DT)
    EVT_CALL(EnableNpcShadow, NPC_Boo_01, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BraceDoor2) = {
    EVT_CALL(SetNpcJumpscale, NPC_Boo_02, EVT_FLOAT(-0.3))
    EVT_CALL(NpcJump0, NPC_Boo_02, 272, 112, -81, 12 * DT)
    EVT_CALL(EnableNpcShadow, NPC_Boo_02, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Boo_02, ANIM_Boo_Tan_Flail)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BraceDoor3) = {
    EVT_CALL(SetNpcJumpscale, NPC_Boo_03, EVT_FLOAT(-0.4))
    EVT_CALL(NpcJump0, NPC_Boo_03, 237, 120, -118, 10 * DT)
    EVT_CALL(EnableNpcShadow, NPC_Boo_03, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Flail)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BraceDoor4) = {
    EVT_CALL(SetNpcJumpscale, NPC_Boo_04, EVT_FLOAT(-0.3))
    EVT_CALL(NpcJump0, NPC_Boo_04, 280, 60, -79, 8 * DT)
    EVT_CALL(EnableNpcShadow, NPC_Boo_04, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Boo_04, ANIM_Boo_Tan_Flail)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BraceDoor5) = {
    EVT_CALL(SetNpcJumpscale, NPC_Boo_05, EVT_FLOAT(-0.4))
    EVT_CALL(NpcJump0, NPC_Boo_05, 250, 81, -97, 9 * DT)
    EVT_CALL(EnableNpcShadow, NPC_Boo_05, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Flail)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BraceDoor6) = {
    EVT_CALL(SetNpcJumpscale, NPC_Boo_06, EVT_FLOAT(-0.5))
    EVT_CALL(NpcJump0, NPC_Boo_06, 227, 43, -123, 15 * DT)
    EVT_CALL(EnableNpcShadow, NPC_Boo_06, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Boo_06, ANIM_Boo_Tan_Flail)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BoosBraceDoor) = {
    EVT_EXEC(N(EVS_BraceDoor2))
    EVT_EXEC(N(EVS_BraceDoor3))
    EVT_EXEC(N(EVS_BraceDoor4))
    EVT_EXEC(N(EVS_BraceDoor5))
    EVT_EXEC(N(EVS_BraceDoor6))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LeaderBooShivering) = {
    EVT_CALL(GetNpcPos, NPC_Boo_01, LVar0, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, LVarA)
        EVT_ADD(LVarA, 2)
        EVT_SET(LVarB, 0)
        EVT_LABEL(10)
        EVT_SET(LVar3, LVar0)
        EVT_ADD(LVar3, 1)
        EVT_CALL(SetNpcPos, NPC_Boo_01, LVar3, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_SET(LVar3, LVar0)
        EVT_ADD(LVar3, -1)
        EVT_CALL(SetNpcPos, NPC_Boo_01, LVar3, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVarB, 1)
        EVT_IF_LT(LVarB, LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(RandInt, 10, LVarA)
        EVT_ADD(LVarA, 10)
        EVT_WAIT(LVarA)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TubbaTaunting) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 50 * DT, LVar0)
        EVT_ADD(LVar0, 80 * DT)
        EVT_WAIT(LVar0)
        EVT_IF_EQ(MV_PreventTaunting, FALSE)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_00EF, 160, 40)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BoosApproachManor) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, 350, 10, -150)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 350, 10, -150)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 175)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -75)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcPos, NPC_Boo_01, -60, 10, -70)
    EVT_CALL(SetNpcPos, NPC_Boo_02, -100, 10, -110)
    EVT_CALL(SetNpcPos, NPC_Boo_03, -140, 10, -150)
    EVT_CALL(SetNpcPos, NPC_Boo_04, -100, 10, -30)
    EVT_CALL(SetNpcPos, NPC_Boo_05, -140, 10, -70)
    EVT_CALL(SetNpcPos, NPC_Boo_06, -180, 10, -100)
    EVT_EXEC_WAIT(N(EVS_AdvanceBooPhalanx))
    EVT_WAIT(60 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Boo_01, 270, 1)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00DB)
    EVT_CALL(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00DC)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_00DD)
    EVT_CALL(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
    EVT_CALL(InterpNpcYaw, NPC_Boo_01, 90, 1)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_00DE, 160, 40)
    EVT_CALL(SetPlayerPos, 350, 10, -150)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 350, 10, -150)
    EVT_SET(LVar2, 1)
    EVT_EXEC_WAIT(N(EVS_SetDoorRots))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_EscapeFromTubba) = {
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(8.0 / DT))
    EVT_CALL(PlayerMoveTo, 184, -44, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_04, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_05, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_06, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Boo_01, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_02, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_03, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_04, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_05, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Boo_06, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(50 * DT)
    EVT_SET(LVar2, 1)
    EVT_EXEC(N(EVS_CloseDoors))
    EVT_EXEC(N(EVS_BoosBraceDoor))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(6.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-15.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_GET_TID(N(EVS_LeaderBooShivering), LVarA)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00DF)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00E0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_00E1)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00E2)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00E3)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00E4)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00E5)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00E6)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(6.0 / DT))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
    EVT_WAIT(5 * DT)
    EVT_CALL(PlaySoundAt, SOUND_TUBBA_POUNDING, SOUND_SPACE_DEFAULT, 240, 10, -125)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_00E7, 160, 40)
    EVT_EXEC_WAIT(N(EVS_BraceDoor1))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 5, MSG_CH3_00E8)
    EVT_CALL(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    EVT_EXEC(N(EVS_TubbaTaunting))
    EVT_SET(GB_StoryProgress, STORY_CH3_ESCAPED_TUBBAS_MANOR)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetBoosBracingDoor) = {
    EVT_CALL(SetNpcPos, NPC_Boo_01, 246, 30, -110)
    EVT_CALL(SetNpcPos, NPC_Boo_02, 276, 120, -80)
    EVT_CALL(SetNpcPos, NPC_Boo_03, 216, 120, -140)
    EVT_CALL(SetNpcPos, NPC_Boo_04, 276, 60, -80)
    EVT_CALL(SetNpcPos, NPC_Boo_05, 246, 90, -110)
    EVT_CALL(SetNpcPos, NPC_Boo_06, 216, 60, -130)
    EVT_CALL(InterpNpcYaw, NPC_Boo_01, 70, 1)
    EVT_CALL(InterpNpcYaw, NPC_Boo_02, 99, 1)
    EVT_CALL(InterpNpcYaw, NPC_Boo_03, 93, 1)
    EVT_CALL(InterpNpcYaw, NPC_Boo_04, 74, 1)
    EVT_CALL(InterpNpcYaw, NPC_Boo_05, 78, 1)
    EVT_CALL(InterpNpcYaw, NPC_Boo_06, 81, 1)
    EVT_CALL(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Boo_02, ANIM_Boo_Tan_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Boo_03, ANIM_Boo_Tan_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Boo_04, ANIM_Boo_Tan_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Boo_06, ANIM_Boo_Tan_Flail)
    EVT_CALL(EnableNpcShadow, NPC_Boo_01, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_02, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_03, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_04, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_05, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo_06, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_01) = {
    EVT_SET(MV_PreventTaunting, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Boo_01, ANIM_Boo_Tan_Flail, ANIM_Boo_Tan_Flail, 5, MSG_CH3_00E9)
    EVT_CALL(SetNpcAnimation, NPC_Boo_01, ANIM_Boo_Tan_Flail)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00EA)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00EB)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00EC)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00ED)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00EE)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_SET(MV_PreventTaunting, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Boo_01) = {
    .id = NPC_Boo_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_01),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_BraveBoo,
};

NpcData N(NpcData_Boo_02) = {
    .id = NPC_Boo_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_02),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_03) = {
    .id = NPC_Boo_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_03),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_04) = {
    .id = NPC_Boo_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_04),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_05) = {
    .id = NPC_Boo_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_05),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

NpcData N(NpcData_Boo_06) = {
    .id = NPC_Boo_06,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_06),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

EvtScript N(EVS_Scene_ThrownOutBySentinel) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 320, 10, -160)
    EVT_CALL(PlaySound, SOUND_LRAW_SENTINEL_ALARM)
    EVT_THREAD
        EVT_LOOP(180)
            EVT_CALL(GetNpcPos, NPC_Sentinel, LVar0, LVar1, LVar2)
            EVT_CALL(N(PlaySentinelSounds))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerPos, 320, 50, -160)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Flail)
    EVT_CALL(SetNpcPos, NPC_Sentinel, 320, 70, -158)
    EVT_CALL(InterpNpcYaw, NPC_Sentinel, 270, 0)
    EVT_CALL(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim08)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 175, 0, -35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 175, 0, -35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(540.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_SET(LVar2, 1)
        EVT_EXEC(N(EVS_SetDoorRots))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, 0)
        EVT_CALL(PlayerJump1, 175, 50, -35, 40)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_WAIT(1)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
        EVT_WAIT(85)
        EVT_CALL(func_802CF56C, 2)
        EVT_WAIT(1)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Sentinel, 175, -33, 40)
    EVT_WAIT(20)
    EVT_CALL(SetNpcPos, NPC_Sentinel, 175, 85, -33)
    EVT_CALL(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim09)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_Sentinel, SOUND_SENTINEL_PICKUP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim02)
    EVT_CALL(SetNpcPos, NPC_Sentinel, 175, 70, -33)
    EVT_THREAD
        EVT_WAIT(40)
        EVT_CALL(SetNpcAnimation, NPC_Sentinel, ANIM_Sentinel_Anim03)
        EVT_CALL(NpcMoveTo, NPC_Sentinel, 270, -120, 30)
        EVT_CALL(StopSound, SOUND_LRAW_SENTINEL_ALARM)
        EVT_CALL(SetNpcPos, NPC_Sentinel, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_SET(LVar2, 1)
        EVT_EXEC(N(EVS_CloseDoors))
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, 0)
    EVT_CALL(PlayerJump1, 175, 0, -35, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_Sentinel, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Collapse)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, EMOTE_FRUSTRATION, 0, 175, 0, -35, 20, -20, 30, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(65)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_END_SWITCH
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D6)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D7)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D8)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D9)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00DA)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH3_00D6)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetUp)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_DustOff)
    EVT_WAIT(7)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_DeepExhale)
    EVT_WAIT(25)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 45, 0)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerJump1, LVar0, 0, LVar2, 10)
    EVT_CALL(PlayerJump1, LVar0, 0, LVar2, 10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sentinel) = {
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Sentinel) = {
    .id = NPC_Sentinel,
    .pos = { 0.0f, 0.0f, -1000.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Sentinel),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

NpcGroupList N(BooNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    NPC_GROUP(N(NpcData_Boo_06)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel)),
    {}
};
