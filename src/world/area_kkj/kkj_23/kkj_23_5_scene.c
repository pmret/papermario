#include "kkj_23.h"
#include "effects.h"
#include "sprite/player.h"

void peach_force_disguise_action(s32);

API_CALLABLE(N(SetLightningBoltColor)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 r = evt_get_variable(script, *args++);
    s32 g = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);

    effect->data.lightningBolt->outerColor.r = r;
    effect->data.lightningBolt->outerColor.g = g;
    effect->data.lightningBolt->outerColor.b = b;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ForceDisguiseLoss)) {
    peach_force_disguise_action(FALSE);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ApproachPeach) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_01, 5)
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Koopatrol_02, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_02, 5)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_02, 0, 0)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_02, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(1)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Carried)
    EVT_SUB(LVar0, 15)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway) = {
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 10)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 684, -52, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, 716, -48, 0)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenAndCloseTowerDoors) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_LARGE_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o9, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o10, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, 80, 0, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o9, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o10, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_LARGE_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RemoveDisguise) = {
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 45)
    EVT_LOOP(10)
        EVT_CALL(InterpPlayerYaw, LVar0, 0)
        EVT_ADD(LVar0, LVar1)
        EVT_ADD(LVar1, 4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtPlayer, SOUND_DARK_TOAD_DISPEL, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(ForceDisguiseLoss))
    EVT_LOOP(10)
        EVT_CALL(InterpPlayerYaw, LVar0, 0)
        EVT_ADD(LVar0, LVar1)
        EVT_SUB(LVar1, 4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_KammyUnmasksPeach) = {
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LE(LVar0, 140)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 1, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Koopatrol_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcPos, NPC_Kammy, -50, 0, -50)
    EVT_EXEC(N(EVS_OpenAndCloseTowerDoors))
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Kammy, 30, -50, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 270, 5)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, 140)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(func_802D1270, 190, LVar2, EVT_FLOAT(4.0 / DT))
        EVT_CALL(func_802D1270, 195, -80, EVT_FLOAT(4.0 / DT))
        EVT_CALL(func_802D1270, 190, -80, EVT_FLOAT(4.0 / DT))
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, 190)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, -10, -130, 20 * DT)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(4.0 / DT))
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 210, -10, -130, 0, 0, EASING_LINEAR)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 5)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, 210)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 5)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, -50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -50)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_014F)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_Kammy, MSG_Peach_0150)
    EVT_CALL(SetNpcVar, NPC_Kammy, 0, 1)
    EVT_THREAD
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_Kammy, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    EVT_CALL(NpcMoveTo, NPC_Kammy, 270, -50, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_CALL(SetNpcVar, NPC_Kammy, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 230, 0, -50)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0151)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 10 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0152)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(NpcMoveTo, NPC_Kammy, 280, -50, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Kammy, EMOTE_EXCLAMATION, -45, 15, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 5)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0153)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim05)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim05, 5, MSG_Peach_0154)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_KAMMY_SUMMON_MAGIC, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_ADD(LVar1, 40)
    EVT_ADD(LVar2, 27)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 50)
    EVT_WAIT(60 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 5)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 180)
    EVT_CALL(PlaySoundAtPlayer, SOUND_BOWSER_LIGHTNING, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 5, 20)
    EVT_CALL(N(SetLightningBoltColor), LVarF, 255, 0, 255)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar0, LVar1, LVar2, 1, 30)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_EXEC_WAIT(N(EVS_RemoveDisguise))
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_GaspStill, ANIM_Peach2_GaspStill, 5, MSG_Peach_0155)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim05, 5, MSG_Peach_0156)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    EVT_CALL(NpcMoveTo, NPC_Kammy, 260, -50, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0157)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFacePlayer, NPC_Kammy, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, 240)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(EVS_ApproachPeach))
    EVT_EXEC_WAIT(N(EVS_PickUpPeach))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_0158)
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 460, -10, -130, 0, 0, EASING_LINEAR)
    EVT_WAIT(60 * DT)
    EVT_CALL(FadeOutMusic, 0, 1000 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter6))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
