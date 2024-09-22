#include "kkj_25.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Npc1

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"

#include "world/common/npc/Peach.h"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcIdle_Bowser) = {
    Call(SetSelfVar, 0, 0)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Thread
        Call(GetNpcPos, NPC_Bowser_01, LVar0, LVar1, LVar2)
        Add(LVar0, -75)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 1000)
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Call(ModifyGlobalOverrideFlags, 1, GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE)
    Call(StopSound, SOUND_LRAW_KPA_ARENA_TURN_ON)
    Call(StartBossBattle, SONG_BOWSER_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Bowser) = {
    #define NAME_SUFFIX
    Call(PlaySound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    Exec(N(EVS_Scene_PeachBreaksFree))
    Return
    End
    #define NAME_SUFFIX _Npc1
};

EvtScript N(EVS_NpcInit_Bowser) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bowser)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Bowser)))
    Call(SetNpcPos, NPC_Bowser_01, 350, 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kammy_Broom) = {
    Call(SetSelfVar, 0, 0)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_2000)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_TINT, 0, 0, 0, 0)
    Call(HidePlayerShadow, TRUE)
    Call(DisablePartnerAI, 0)
    Wait(1)
    Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    Call(ModifyGlobalOverrideFlags, 1, GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE)
    Call(StopSound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    Call(StartBossBattle, SONG_BOWSER_BATTLE)
    Call(EnablePartnerAI)
    Return
    End
};

API_CALLABLE(N(func_80240020_B06A20)) {
    increment_status_bar_disabled();
    set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, 255.0f);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcDefeat_Kammy_Broom) = {
    Call(GetBattleOutcome, LVar0)
    Call(N(func_80240020_B06A20))
    Set(GF_KKJ25_Defeated_Kammy, TRUE)
    // reload the map in the 'midpoint' configuration
    Call(GotoMap, Ref("kkj_25"), kkj_25_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcAux_Kammy_Broom) = {
    Set(LVar3, 1)
    Loop(0)
        Loop(5)
            Call(GetNpcPos, NPC_Kammy_01, LVar0, LVar1, LVar2)
            Add(LVar1, LVar3)
            Call(SetNpcPos, NPC_Kammy_01, LVar0, LVar1, LVar2)
            Wait(2)
        EndLoop
        Mul(LVar3, -1)
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy_Broom) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kammy_Broom)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Kammy_Broom)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Kammy_Broom)))
    Call(SetNpcPos, NPC_Kammy_01, 460, 10, 0)
    Call(SetNpcYaw, NPC_Kammy_01, 270)
    Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim04)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy) = {
    Call(SetNpcPos, NPC_Kammy_02, 300, -100, 0)
    Call(SetNpcAnimation, NPC_Kammy_02, ANIM_BattleKammy_Anim02)
    Return
    End
};

EvtScript N(EVS_NpcInit_BattleKooper_01) = {
    Call(SetNpcPos, NPC_Peach_01, 400, 0, -30)
    Call(SetNpcYaw, NPC_Peach_01, 270)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach2_TiedIdle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink) = {
    Call(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Idle)
    Call(EnableNpcShadow, NPC_Twink_01, FALSE)
    Call(SetNpcPos, NPC_Twink_01, 300, -100, 0)
    Return
    End
};

AnimID N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_RearUpLaugh,
    ANIM_WorldBowser_Tantrum,
    ANIM_WorldBowser_Jump,
    ANIM_WorldBowser_Land,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Peach)[] = {
    ANIM_Peach2_TiedStill,
    ANIM_Peach1_Idle,
    ANIM_Peach1_Walk,
    ANIM_Peach2_RaiseArms,
    ANIM_Peach2_GaspStill,
    ANIM_Peach2_TiedIdle,
    ANIM_Peach3_TiedTalk,
    ANIM_Peach3_TiedShout,
    ANIM_Peach3_TiedLaugh,
    ANIM_Peach2_TalkIdle,
    ANIM_Peach3_Pray,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_BattleKammy_Anim00,
    ANIM_BattleKammy_Anim01,
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    ANIM_BattleKammy_Anim07,
    ANIM_BattleKammy_Anim08,
    ANIM_BattleKammy_Anim02,
    ANIM_BattleKammy_Anim0C,
    ANIM_BattleKammy_Anim03,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Sad,
    ANIM_Twink_Back,
    ANIM_Twink_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Bowser) = {
    .id = NPC_Bowser_01,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser),
    .settings = &N(NpcSettings_Bowser),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

NpcData N(NpcData_Peach) = {
    .id = NPC_Peach_01,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_BattleKooper_01),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

NpcData N(NpcData_Kammy)[] = {
    {
        .id = NPC_Kammy_01,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Kammy_Broom),
        .settings = &N(NpcSettings_Kammy_Flying),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_BattleKammy_Anim00,
            .walk   = ANIM_BattleKammy_Anim00,
            .run    = ANIM_BattleKammy_Anim00,
            .chase  = ANIM_BattleKammy_Anim00,
            .anim_4 = ANIM_BattleKammy_Anim00,
            .anim_5 = ANIM_BattleKammy_Anim00,
            .death  = ANIM_BattleKammy_Anim00,
            .hit    = ANIM_BattleKammy_Anim00,
            .anim_8 = ANIM_BattleKammy_Anim00,
            .anim_9 = ANIM_BattleKammy_Anim00,
            .anim_A = ANIM_BattleKammy_Anim00,
            .anim_B = ANIM_BattleKammy_Anim00,
            .anim_C = ANIM_BattleKammy_Anim00,
            .anim_D = ANIM_BattleKammy_Anim00,
            .anim_E = ANIM_BattleKammy_Anim00,
            .anim_F = ANIM_BattleKammy_Anim00,
        },
        .extraAnimations = N(ExtraAnims_Kammy),
    },
    {
        .id = NPC_Kammy_02,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Kammy),
        .settings = &N(NpcSettings_Kammy_Flying),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_BattleKammy_Anim00,
            .walk   = ANIM_BattleKammy_Anim00,
            .run    = ANIM_BattleKammy_Anim00,
            .chase  = ANIM_BattleKammy_Anim00,
            .anim_4 = ANIM_BattleKammy_Anim00,
            .anim_5 = ANIM_BattleKammy_Anim00,
            .death  = ANIM_BattleKammy_Anim00,
            .hit    = ANIM_BattleKammy_Anim00,
            .anim_8 = ANIM_BattleKammy_Anim00,
            .anim_9 = ANIM_BattleKammy_Anim00,
            .anim_A = ANIM_BattleKammy_Anim00,
            .anim_B = ANIM_BattleKammy_Anim00,
            .anim_C = ANIM_BattleKammy_Anim00,
            .anim_D = ANIM_BattleKammy_Anim00,
            .anim_E = ANIM_BattleKammy_Anim00,
            .anim_F = ANIM_BattleKammy_Anim00,
        },
        .extraAnimations = N(ExtraAnims_Kammy),
    },
};

NpcData N(NpcData_Twink) = {
    .id = NPC_Twink_01,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

#define NAME_SUFFIX

NpcGroupList N(InitialNpcs) = {
    NPC_GROUP(N(NpcData_Bowser_Npc1), BTL_KPA2_FORMATION_03),
    NPC_GROUP(N(NpcData_Peach_Npc1)),
    NPC_GROUP(N(NpcData_Kammy_Npc1), BTL_KKJ_FORMATION_00),
    NPC_GROUP(N(NpcData_Twink_Npc1)),
    {}
};
