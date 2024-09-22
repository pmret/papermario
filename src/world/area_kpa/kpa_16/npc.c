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
    Label(0)
    IfEq(AF_KPA16_HitSwitch, FALSE)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Loop(0)
        Wait(1)
        Call(GetPlayerActionState, LVar0)
        IfEq(LVar0, ACTION_STATE_IDLE)
            BreakLoop
        EndIf
    EndLoop
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(SetPanTarget, CAM_DEFAULT, 330, 230, -150)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Call(SetPanTarget, CAM_DEFAULT, 330, 170, -150)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(N(MuteAmbience))
        SetF(LVar2, 1)
        Call(MakeLerp, 0, -20, 100 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            AddF(LVar2, Float(-0.01))
            Call(TranslateModel, MODEL_o1283, 0, LVar0, 0)
            Call(TranslateModel, MODEL_o1282, 0, LVar0, 0)
            Call(ScaleModel, MODEL_o1282, LVar2, 1, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(50 * DT)
    Call(MakeLerp, 0, 255, 50 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetScreenBlackFadeAmount), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o782, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o929, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o930, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o776, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o952, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o954, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o952, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_TexPan_Steam))
    Call(EnableGroup, MODEL_before, FALSE)
    Call(EnableGroup, MODEL_after, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o782, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o954, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_KPA16_ShutOffLava, TRUE)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(MakeLerp, 255, 0, 50 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetScreenBlackFadeAmount), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(60 * DT)
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH8_001B)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH8_001C)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH8_001D)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH8_001E)
        CaseEq(PARTNER_BOW)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH8_001F)
        CaseEq(PARTNER_WATT)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH8_0020)
        CaseEq(PARTNER_SUSHIE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH8_0021)
        CaseEq(PARTNER_LAKILESTER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH8_0022)
    EndSwitch
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ChargeAtPlayer) = {
    ChildThread
        Wait(15 * DT)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Koopatrol_01, 650, -145, 0)
    EndChildThread
    ChildThread
        Wait(10 * DT)
        Call(SetNpcSpeed, NPC_Koopatrol_03, Float(3.5 / DT))
        Call(NpcMoveTo, NPC_Koopatrol_03, 650, -165, 0)
    EndChildThread
    Wait(5 * DT)
    Call(SetNpcSpeed, NPC_Koopatrol_02, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_Koopatrol_02, 650, -120, 0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Guards) = {
    Label(0)
        Wait(1)
        Call(N(GetFloorCollider), LVar0)
        IfNe(LVar0, COLLIDER_o785)
            Goto(0)
        EndIf
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar1, 230)
            Goto(0)
        EndIf
        IfGt(LVar0, 710)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(PlaySoundAtNpc, NPC_Koopatrol_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Koopatrol_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Koopatrol_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Koopatrol_01, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Koopatrol_02, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
    Call(ShowEmote, NPC_Koopatrol_03, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
    Wait(15 * DT)
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 0)
    Call(InterpNpcYaw, NPC_Koopatrol_02, 90, 0)
    Call(InterpNpcYaw, NPC_Koopatrol_03, 90, 0)
    Call(InterpNpcYaw, NPC_Magikoopa, 90, 0)
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
    Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
    Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 555, 230, -150)
    Call(SetPanTarget, CAM_DEFAULT, 555, 230, -150)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, 680, -145, 0)
        Call(InterpPlayerYaw, 270, 0)
    EndThread
    Call(SetSelfVar, 0, 0)
    Thread
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(4.0 / DT))
        Label(10)
        Call(NpcMoveTo, NPC_Koopatrol_02, 550, -165, 0)
        Wait(5 * DT)
        Call(NpcMoveTo, NPC_Koopatrol_02, 510, -165, 0)
        Wait(5 * DT)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Goto(10)
        EndIf
        Call(NpcMoveTo, NPC_Koopatrol_02, 535, -165, 0)
        Call(SetSelfVar, 0, 2)
    EndThread
    Call(InterpNpcYaw, NPC_Koopatrol_01, 270, 0)
    Call(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06, ANIM_WorldKoopatrol_Anim06, 1, MSG_CH8_0017)
    Thread
        Wait(5)
        Call(SetNpcJumpscale, NPC_Koopatrol_03, Float(1.0))
        Call(GetNpcPos, NPC_Koopatrol_03, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Koopatrol_03, LVar0, LVar1, LVar2, 20 * DT)
    EndThread
    Call(SpeakToPlayer, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06, ANIM_WorldKoopatrol_Anim06, 0, MSG_CH8_0018)
    Call(SetSelfVar, 0, 1)
    Label(15)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 1)
        Wait(1)
        Goto(15)
    EndIf
    Call(InterpNpcYaw, NPC_Koopatrol_02, 270, 0)
    Call(InterpNpcYaw, NPC_Koopatrol_03, 270, 0)
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
    Call(SpeakToPlayer, NPC_Magikoopa, ANIM_Magikoopa_Anim02, ANIM_Magikoopa_Anim01, 0, MSG_CH8_0019)
    Thread
        Wait(15 * DT)
        Call(InterpNpcYaw, NPC_Koopatrol_03, 90, 0)
        Wait(10 * DT)
        Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 0)
    EndThread
    Call(SpeakToPlayer, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_CH8_001A)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
    Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
    Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06)
    Exec(N(EVS_ChargeAtPlayer))
    Call(DisablePlayerInput, FALSE)
    Thread
        Loop(0)
            Wait(1)
            IfEq(GF_KPA16_Defeated_SwitchGuards, TRUE)
                BreakLoop
            EndIf
        EndLoop
        Wait(30 * DT)
        Call(SetNpcPos, NPC_Koopatrol_01, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Koopatrol_02, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Koopatrol_03, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_Magikoopa, NPC_DISPOSE_LOCATION)
    EndThread
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Guards) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_KPA16_Defeated_SwitchGuards, TRUE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o958, COLLIDER_FLAGS_UPPER_MASK)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Guards) = {
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Exec(N(EVS_Scene_LavaShutoff))
    EndIf
    IfEq(GF_KPA16_Defeated_SwitchGuards, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Guards)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Guards)))
    Else
        Call(RemoveNpc, NPC_Magikoopa)
        Call(RemoveNpc, NPC_Koopatrol_02)
        Call(RemoveNpc, NPC_Koopatrol_03)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
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
