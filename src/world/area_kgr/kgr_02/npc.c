#include "kgr_02.h"
#include "sprite/player.h"

API_CALLABLE(N(AwaitPartnerWatt)) {
    if (gPartnerStatus.actingPartner == PARTNER_WATT) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(AwaitPartnerNotWatt)) {
    if (gPartnerStatus.actingPartner != PARTNER_WATT) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

s32 N(D_80240970_8AADC0) = 0;

EvtScript N(EVS_Dummy) = {
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Flotsam_Bobbing) = {
    Loop(0)
        Call(MakeLerp, 0, -10, 25, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, LVar2, 0, LVar0, 0)
            Call(TranslateModel, LVar3, 0, LVar0, 0)
            Call(TranslateModel, LVar4, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -10, 0, 30, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, LVar2, 0, LVar0, 0)
            Call(TranslateModel, LVar3, 0, LVar0, 0)
            Call(TranslateModel, LVar4, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupFlotsam) = {
    Set(LVar2, MODEL_hako1)
    Set(LVar3, MODEL_bin2)
    Set(LVar4, MODEL_hako4)
    ExecGetTID(N(EVS_Flotsam_Bobbing), LVarA)
    Wait(5)
    Set(LVar2, MODEL_bin1)
    Set(LVar3, MODEL_hako6)
    Set(LVar4, MODEL_hako5)
    ExecGetTID(N(EVS_Flotsam_Bobbing), LVarB)
    Wait(5)
    Set(LVar2, MODEL_hako2)
    Set(LVar3, MODEL_hako3)
    Set(LVar4, MODEL_bin4)
    ExecGetTID(N(EVS_Flotsam_Bobbing), LVarC)
    Wait(5)
    Set(LVar2, MODEL_fune_s)
    Set(LVar3, MODEL_fune_u)
    Set(LVar4, MODEL_bin3)
    ExecGetTID(N(EVS_Flotsam_Bobbing), LVarD)
    Call(SetNpcVar, NPC_Fuzzipede, 2, 0)
    Loop(0)
        Call(GetNpcVar, NPC_Fuzzipede, 2, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    KillThread(LVarC)
    KillThread(LVarD)
    Return
    End
};

EvtScript N(EVS_Fuzzipede_ReactToLight) = {
    Set(LVarA, 0)
    Set(LVarB, 0)
    Call(WaitForPlayerInputEnabled)
    Loop(0)
        IfEq(LVarA, 0)
            Call(N(AwaitPartnerWatt))
            IfEq(LVarB, 0)
                Call(DisablePlayerInput, TRUE)
                Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLt(LVar0, 0)
                    Add(LVar0, 80)
                Else
                    Add(LVar0, -80)
                EndIf
                Call(NpcJump0, NPC_SELF, LVar0, 0, 0, 20)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, MSG_MAC_Port_009B)
                Call(SetSelfVar, 0, 1)
                Set(LVarB, 1)
                Call(DisablePlayerInput, FALSE)
            EndIf
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP, 0)
            Set(LVarA, 1)
        Else
            Call(N(AwaitPartnerNotWatt))
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP, 1)
            Set(LVarA, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Fuzzipede_JumpAround) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, -100, 80, -80, 20)
        Wait(10)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 100, 80, -80, 20)
        Wait(10)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 30, 40, -80, 20)
        Wait(10)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 135, 15, -100, 20)
        Wait(10)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZIPEDE_MOTION, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 30, 0, 0, 20)
        Wait(10)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcAI_Fuzzipede) = {
    Exec(N(EVS_SetupFlotsam))
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    ExecGetTID(N(EVS_Fuzzipede_JumpAround), LVarA)
    Call(SetSelfVar, 3, LVarA)
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000, 0)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcHit_Fuzzipede) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetSelfVar, 3, LVar0)
    KillThread(LVar0)
    Call(SetSelfVar, 1, 1)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Fuzzipede) = {
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(SetPlayerPos, -40, 0, 0)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    Call(SetNpcPos, NPC_SELF, 30, 0, 0)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(UseSettingsFrom, CAM_DEFAULT, -5, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -5, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04, 0, MSG_MAC_Port_009D)
    Wait(10)
    Call(ShowMessageAtScreenPos, MSG_MAC_Port_009E, -300, 100)
    Wait(10)
    Call(FadeOutMusic, 0, 1000)
    Call(SetSelfVar, 2, 1)
    Thread
        Call(PlaySound, SOUND_WHALE_FILL)
        Set(LVar0, 0)
        Loop(150)
            Add(LVar0, 1)
            Call(TranslateGroup, MODEL_mizu, 0, LVar0, 0)
            Call(TranslateModel, MODEL_hako1, 0, LVar0, 0)
            Call(TranslateModel, MODEL_hako2, 0, LVar0, 0)
            Call(TranslateModel, MODEL_hako3, 0, LVar0, 0)
            Call(TranslateModel, MODEL_hako6, 0, LVar0, 0)
            Call(TranslateModel, MODEL_bin1, 0, LVar0, 0)
            Call(TranslateModel, MODEL_bin2, 0, LVar0, 0)
            Call(TranslateModel, MODEL_bin3, 0, LVar0, 0)
            Call(TranslateModel, MODEL_bin4, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 0)
        Loop(75)
            Add(LVar0, 1)
            Call(TranslateGroup, MODEL_fune, 0, LVar0, 0)
            Call(TranslateModel, MODEL_hako4, 0, LVar0, 0)
            Call(TranslateModel, MODEL_hako5, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(20)
        Call(HidePlayerShadow, TRUE)
        Call(EnableNpcShadow, NPC_PARTNER, FALSE)
        Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
        Call(GetPlayerPos, LVar1, LVar0, LVar3)
        Loop(150)
            Add(LVar0, 1)
            Call(SetPlayerPos, LVar1, LVar0, LVar3)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(20)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(GetNpcPos, NPC_Fuzzipede, LVar1, LVar0, LVar3)
        Loop(150)
            Add(LVar0, 1)
            Call(SetNpcPos, NPC_SELF, LVar1, LVar0, LVar3)
            Wait(1)
        EndLoop
    EndThread
    ChildThread
        Loop(0)
            Call(InterpNpcYaw, NPC_Fuzzipede, 90, 7)
            Wait(10)
            Call(InterpNpcYaw, NPC_Fuzzipede, 270, 7)
            Wait(10)
        EndLoop
    EndChildThread
    Wait(120)
    Call(GotoMap, Ref("mac_05"), mac_05_ENTRY_2)
    Wait(100)
    Call(InterruptUsePartner)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_Fuzzipede) = {
    Call(SetNpcPos, NPC_SELF, 100, 80, -80)
    Exec(N(EVS_Fuzzipede_ReactToLight))
    Return
    End
};

NpcSettings N(NpcSettings_Fuzzipede) = {
    .defaultAnim = ANIM_Fuzzipede_Anim04,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Fuzzipede),
    .ai = &N(EVS_NpcAI_Fuzzipede),
    .onHit = &N(EVS_NpcHit_Fuzzipede),
    .onDefeat = &N(EVS_NpcDefeat_Fuzzipede),
    .unk_24 = 100,
};

NpcData N(NpcData_Fuzzipede) = {
    .id = NPC_Fuzzipede,
    .pos = { 333.0f, -10.0f, -130.0f },
    .yaw = 90,
    .settings = &N(NpcSettings_Fuzzipede),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Fuzzipede_Anim04,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzipede), BTL_KGR_FORMATION_00, BTL_KGR_STAGE_00),
    {}
};
