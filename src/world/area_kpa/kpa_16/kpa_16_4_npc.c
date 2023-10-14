#include "kpa_16.h"

#include "world/common/enemy/Koopatrol.h"
#include "world/common/enemy/Magikoopa.h"

API_CALLABLE(N(SetScreenBlackFadeAmount)) {
    Bytecode* args = script->ptrReadPos;
    f32 amount = evt_get_variable(script, *args++);

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, amount);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MuteAmbience)) {
    snd_ambient_mute(0, TRUE);
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetFloorCollider.inc.c"

NpcSettings N(NpcSettings_Dummy) = {
    .height = 40,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPATROL,
};

EvtScript N(EVS_Scene_LavaShutoff) = {
    EVT_LABEL(0)
    EVT_IF_EQ(AF_KPA16_HitSwitch, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 330, 230, -150)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 330, 170, -150)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(N(MuteAmbience))
        EVT_SETF(LVar2, 1)
        EVT_CALL(MakeLerp, 0, -20, 100 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_ADDF(LVar2, EVT_FLOAT(-0.01))
            EVT_CALL(TranslateModel, MODEL_o1283, 0, LVar0, 0)
            EVT_CALL(TranslateModel, MODEL_o1282, 0, LVar0, 0)
            EVT_CALL(ScaleModel, MODEL_o1282, LVar2, 1, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(50 * DT)
    EVT_CALL(MakeLerp, 0, 255, 50 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetScreenBlackFadeAmount), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o782, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o929, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o930, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o776, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o952, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o954, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o952, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_TexPan_Steam))
    EVT_CALL(EnableGroup, MODEL_before, FALSE)
    EVT_CALL(EnableGroup, MODEL_after, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o782, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o954, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_KPA16_ShutOffLava, TRUE)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(MakeLerp, 255, 0, 50 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetScreenBlackFadeAmount), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(60 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH8_001B)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH8_001C)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH8_001D)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH8_001E)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH8_001F)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH8_0020)
        EVT_CASE_EQ(PARTNER_SUSHIE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH8_0021)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH8_0022)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ChargeAtPlayer) = {
    EVT_CHILD_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, 650, -145, 0)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_03, EVT_FLOAT(3.5 / DT))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_03, 650, -165, 0)
    EVT_END_CHILD_THREAD
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 650, -120, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Guards) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_NE(LVar0, COLLIDER_o785)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, 230)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_GT(LVar0, 710)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtNpc, NPC_Koopatrol_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Koopatrol_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_Koopatrol_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Koopatrol_01, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Koopatrol_02, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, NPC_Koopatrol_03, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(15 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_02, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_03, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Magikoopa, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 555, 230, -150)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 555, 230, -150)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, 680, -145, 0)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(4.0 / DT))
        EVT_LABEL(10)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 550, -165, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 510, -165, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 535, -165, 0)
        EVT_CALL(SetSelfVar, 0, 2)
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 270, 0)
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06, ANIM_WorldKoopatrol_Anim06, 1, MSG_CH8_0017)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcJumpscale, NPC_Koopatrol_03, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_Koopatrol_03, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Koopatrol_03, LVar0, LVar1, LVar2, 20 * DT)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06, ANIM_WorldKoopatrol_Anim06, 0, MSG_CH8_0018)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_LABEL(15)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_WAIT(1)
        EVT_GOTO(15)
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_02, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_03, 270, 0)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_Magikoopa, ANIM_Magikoopa_Anim02, ANIM_Magikoopa_Anim01, 0, MSG_CH8_0019)
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Koopatrol_03, 90, 0)
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_CH8_001A)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06)
    EVT_EXEC(N(EVS_ChargeAtPlayer))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_EQ(GF_KPA16_Defeated_SwitchGuards, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_02, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_03, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Magikoopa, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Guards) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_KPA16_Defeated_SwitchGuards, TRUE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o958, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Guards) = {
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_EXEC(N(EVS_Scene_LavaShutoff))
    EVT_END_IF
    EVT_IF_EQ(GF_KPA16_Defeated_SwitchGuards, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Guards)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Guards)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_Magikoopa)
        EVT_CALL(RemoveNpc, NPC_Koopatrol_02)
        EVT_CALL(RemoveNpc, NPC_Koopatrol_03)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Guards)[] = {
    {
        .id = NPC_Koopatrol_01,
        .pos = { 585.0f, 230.0f, -145.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Guards),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = KOOPATROL_DROPS,
        .animations = KOOPATROL_ANIMS,
    },
    {
        .id = NPC_Koopatrol_02,
        .pos = { 525.0f, 230.0f, -165.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = KOOPATROL_DROPS,
        .animations = KOOPATROL_ANIMS,
    },
    {
        .id = NPC_Koopatrol_03,
        .pos = { 550.0f, 230.0f, -120.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = KOOPATROL_DROPS,
        .animations = KOOPATROL_ANIMS,
    },
    {
        .id = NPC_Magikoopa,
        .pos = { 505.0f, 230.0f, -120.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = MAGINO_DROPS,
        .animations = MAGIKOOPA_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Guards), BTL_KPA_FORMATION_1D, BTL_KPA_STAGE_02),
    {}
};
