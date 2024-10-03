#include "pra_32.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/enemy/CrystalKing.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_AnimateCam_CrystalKing) = {
    Set(MV_CamDistance, 400)
    Thread
        Call(MakeLerp, 400, 300, 200 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_CamDistance, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(MakeLerp, 200, 100, 200 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_CrystalKing_01, 588, LVar0, 116)
        Set(LVar5, LVar0)
        Add(LVar5, -30)
        IfGe(LVar5, 100)
            Call(SetPanTarget, CAM_DEFAULT, 588, LVar5, 116)
            Call(SetCamDistance, CAM_DEFAULT, MV_CamDistance)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        EndIf
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_CrystalKingAppears) = {
    Call(EnableNpcShadow, NPC_CrystalKing_01, FALSE)
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Wait(1)
    IfLt(LVar0, 377)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(SetMusicTrack, 0, SONG_CRYSTAL_KING_THEME, 0, 8)
    Call(ShowMessageAtScreenPos, MSG_CH7_016A, 160, 40)
    Call(SetNpcPos, NPC_CrystalKing_01, 588, 200, 116)
    Call(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Add(LVar1, -30)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Call(SetPlayerPos, 475, 100, 116)
    Call(DisablePartnerAI, 0)
    Call(PartnerIsFlying, LVar4)
    IfEq(LVar4, FALSE)
        Call(SetNpcPos, NPC_PARTNER, 452, 116, 120)
    Else
        Call(SetNpcPos, NPC_PARTNER, 452, 100, 120)
    EndIf
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        PlayEffect(EFFECT_MISC_PARTICLES, 0, LVar0, LVar1, LVar2, 50, 50, 1, 40, 50)
        Wait(20 * DT)
        PlayEffect(EFFECT_MISC_PARTICLES, 0, LVar0, LVar1, LVar2, 50, 50, 1, 40, 50)
        Wait(20 * DT)
        PlayEffect(EFFECT_MISC_PARTICLES, 0, LVar0, LVar1, LVar2, 50, 50, 1, 40, 50)
        Wait(20 * DT)
        PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 50, 50, 1, 20, 40)
        Wait(20 * DT)
        PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 50, 50, 1, 20, 40)
        Wait(20 * DT)
        PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 50, 50, 1, 20, 40)
        Wait(20 * DT)
        PlayEffect(EFFECT_BIG_SNOWFLAKES, 0, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SPARKLES, 2, LVar0, LVar1, LVar2, 10)
        Wait(20 * DT)
        PlayEffect(EFFECT_BIG_SNOWFLAKES, 0, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 7)
    EndThread
    Call(MakeLerp, 0, 255, 120 * DT, EASING_LINEAR)
    Label(5)
    Call(UpdateLerp)
    Call(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(5)
    EndIf
    Call(EnableNpcShadow, NPC_CrystalKing_01, TRUE)
    Wait(30 * DT)
    ExecWait(N(EVS_AnimateCam_CrystalKing))
    Wait(20 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_CrystalKing_01, LVar3, LVar4, LVar5)
    Call(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar2)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_CrystalKing_01, ANIM_CrystalKing_Anim09, ANIM_CrystalKing_Anim09, 0, MSG_CH7_016B)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(SetPlayerAnimation, ANIM_Mario1_Run)
    Call(SetPlayerSpeed, Float(2.5 / DT))
    Thread
        Wait(10 * DT)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1309, 0)
        Call(PlayerMoveTo, 564, 116, 0)
    EndThread
    Call(StartBossBattle, SONG_CRYSTAL_KING_BATTLE)
    Return
    End
};

EvtScript N(EVS_Scene_BossDefeated) = {
    Thread
        Wait(2)
        Call(FadeOutMusic, 0, 500)
    EndThread
    Call(SetEncounterStatusFlags, ENCOUNTER_FLAG_THUMBS_UP, TRUE)
    Call(SetPlayerPos, 475, 100, 116)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_CrystalKing_01, ANIM_CrystalKing_Anim09, ANIM_CrystalKing_Anim09, 0, MSG_CH7_016C)
    Thread
        Call(SetNpcRotationPivot, NPC_CrystalKing_01, 30)
        Call(MakeLerp, 0, 19 * 360, 210 * DT, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_CrystalKing_01, 0, 0, LVar0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 100, 200, 210 * DT, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVarA, LVar0)
            MulF(LVarA, Float(0.01))
            Call(SetNpcScale, NPC_CrystalKing_01, LVarA, LVarA, 1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(MakeLerp, 255, 122, 30 * DT, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Thread
        Call(PlaySoundAtNpc, NPC_CrystalKing_01, SOUND_CRYSTAL_KING_DISAPPEAR, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, 1, 130)
    EndThread
    Wait(30 * DT)
    Call(MakeLerp, 120, 0, 30 * DT, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 40)
    Call(SetNpcPos, NPC_CrystalKing_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Wait(75 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1309, SURFACE_TYPE_SNOW)
    Wait(25)
    Call(DisablePlayerInput, FALSE)
    Call(EnablePartnerAI)
    Exec(N(EVS_SpawnStarCard))
    Set(GB_StoryProgress, STORY_CH7_DEFEATED_CRYSTAL_KING)
    Return
    End
};

EvtScript N(EVS_NpcInit_CrystalKing) = {
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_Scene_BossDefeated)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_DEFEATED_CRYSTAL_KING)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_CrystalKingAppears)))
        CaseEq(STORY_CH7_DEFEATED_CRYSTAL_KING)
            Exec(N(EVS_RespawnStarCard))
        CaseGt(STORY_CH7_DEFEATED_CRYSTAL_KING)
    EndSwitch
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Call(SetNpcYaw, NPC_CrystalKing_01, 270)
    Return
    End
};

EvtScript N(EVS_NpcInit_CrystalKing_Aux) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    Return
    End
};

NpcData N(NpcData_CrystalKing_01)[] = {
    {
        .id = NPC_CrystalKing_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_CrystalKing_Aux),
        .settings = &N(NpcSettings_CrystalKing),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = CRYSTAL_KING_ANIMS,
    },
    {
        .id = NPC_CrystalKing_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_CrystalKing),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = CRYSTAL_KING_ANIMS,
    },
    {
        .id = NPC_Kalmar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kalmar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
    {
        .id = NPC_CrystalKing_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_CrystalKing),
        .settings = &N(NpcSettings_CrystalKing),
        .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = CRYSTAL_KING_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_CrystalKing_01), BTL_PRA2_FORMATION_00),
    {}
};

