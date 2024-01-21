#include "kkj_25.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Npc2

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

#include "world/common/npc/Peach.h"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcIdle_Bowser) = {
    Label(0)
    Call(SetSelfVar, 0, 0)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Thread
        Call(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
        Add(LVar0, -75)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
        Call(SetCamDistance, CAM_DEFAULT, 1000)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(StartBossBattle, SONG_FINAL_BOWSER_BATTLE)
    Goto(0)
    Return
    End
};

#include "world/common/todo/UnkFunc1.inc.c"

EvtScript N(EVS_NpcDefeat_Bowser) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    Call(N(UnkFunc1))
    Set(GF_KKJ25_Defeated_Bowser, TRUE)
    // reload the map in the 'final' configuration
    Call(GotoMap, Ref("kkj_25"), kkj_25_ENTRY_2)
    Wait(100)
    Return
    End
};

s32 N(FlyingKammyHoverOffsets)[] = {
    1, 2, 3, 2, 1, -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcAux_Kammy_Broom) = {
    Label(0)
        UseBuf(Ref(N(FlyingKammyHoverOffsets)))
        Loop(10)
            BufRead1(LVar1)
            Call(GetNpcPos, NPC_Kammy_03, LVar2, LVar3, LVar4)
            Add(LVar3, LVar1)
            Call(SetNpcPos, NPC_Kammy_03, LVar2, LVar3, LVar4)
            Wait(3)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Peach) = {
    Call(SetNpcPos, NPC_Peach_01, 475, 0, 0)
    Call(SetNpcAnimation, NPC_Peach_01, ANIM_Peach1_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bowser) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bowser)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Bowser)))
    Call(SetNpcScale, NPC_Bowser_02, Float(1.5), Float(1.5), Float(1.5))
    Call(SetNpcPos, NPC_Bowser_02, 200, 0, 0)
    Call(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy_Broom) = {
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Kammy_Broom)))
    Call(SetNpcPos, NPC_Kammy_03, 540, 10, -50)
    Call(SetNpcAnimation, NPC_Kammy_03, ANIM_BattleKammy_Anim0C)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy) = {
    Call(SetNpcPos, NPC_Kammy_04, 550, 0, -40)
    Call(SetNpcAnimation, NPC_Kammy_04, ANIM_BattleKammy_Anim03)
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink) = {
    Call(InterpNpcYaw, NPC_Peach_01, 270, 0)
    Call(SetNpcPos, NPC_Twink_01, 510, 30, 0)
    Call(InterpNpcYaw, NPC_Twink_01, 270, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    Call(SetNpcImgFXParams, NPC_Eldstar, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Eldstar, FALSE)
    Call(SetNpcPos, NPC_Eldstar, 100, 45, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Mamar) = {
    Call(SetNpcImgFXParams, NPC_Mamar, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Mamar, FALSE)
    Call(SetNpcPos, NPC_Mamar, 46, 45, -27)
    Return
    End
};

EvtScript N(EVS_NpcInit_Skolar) = {
    Call(SetNpcImgFXParams, NPC_Skolar, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Skolar, FALSE)
    Call(SetNpcPos, NPC_Skolar, 33, 45, -95)
    Return
    End
};

EvtScript N(EVS_NpcInit_Muskular) = {
    Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Muskular, FALSE)
    Call(SetNpcPos, NPC_Muskular, 71, 45, -132)
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    Call(SetNpcImgFXParams, NPC_Misstar, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Misstar, FALSE)
    Call(SetNpcPos, NPC_Misstar, 131, 45, -132)
    Return
    End
};

EvtScript N(EVS_NpcInit_Klevar) = {
    Call(SetNpcImgFXParams, NPC_Klevar, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Klevar, FALSE)
    Call(SetNpcPos, NPC_Klevar, 169, 45, -95)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    Call(SetNpcImgFXParams, NPC_Kalmar, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Kalmar, FALSE)
    Call(SetNpcPos, NPC_Kalmar, 156, 45, -27)
    Return
    End
};

AnimID N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_RearUpLaugh,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Peach)[] = {
    ANIM_Peach1_Idle,
    ANIM_Peach1_Walk,
    ANIM_Peach2_RaiseArms,
    ANIM_Peach2_GaspStill,
    ANIM_Peach2_TiedIdle,
    ANIM_Peach3_TiedTalk,
    ANIM_Peach2_TalkIdle,
    ANIM_Peach3_Pray,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    ANIM_BattleKammy_Anim0C,
    ANIM_BattleKammy_Anim03,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    ANIM_LIST_END
};

NpcData N(NpcData_Bowser) = {
    .id = NPC_Bowser_02,
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
    .init = &N(EVS_NpcInit_Peach),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

NpcData N(NpcData_Kammy)[] = {
    {
        .id = NPC_Kammy_03,
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
        .id = NPC_Kammy_04,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Kammy),
        .settings = &N(NpcSettings_Kammy_Flying),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

NpcData N(NpcData_Eldstar) = {
    .id = NPC_Eldstar,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Eldstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = ELDSTAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Eldstar),
};

NpcData N(NpcData_Mamar) = {
    .id = NPC_Mamar,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Mamar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = MAMAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Mamar),
};

NpcData N(NpcData_Skolar) = {
    .id = NPC_Skolar,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Skolar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SKOLAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Skolar),
};

NpcData N(NpcData_Muskular) = {
    .id = NPC_Muskular,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Muskular),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = MUSKULAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Muskular),
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Misstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Misstar),
};

NpcData N(NpcData_Klevar) = {
    .id = NPC_Klevar,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Klevar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KLEVAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Klevar),
};

NpcData N(NpcData_Kalmar) = {
    .id = NPC_Kalmar,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Kalmar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KALMAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Kalmar),
};

#define NAME_SUFFIX

NpcGroupList N(MidpointNpcs) = {
    NPC_GROUP(N(NpcData_Bowser_Npc2), BTL_KPA2_FORMATION_04),
    NPC_GROUP(N(NpcData_Peach_Npc2)),
    NPC_GROUP(N(NpcData_Kammy_Npc2), BTL_KKJ_FORMATION_00),
    NPC_GROUP(N(NpcData_Twink_Npc2)),
    NPC_GROUP(N(NpcData_Eldstar_Npc2)),
    NPC_GROUP(N(NpcData_Mamar_Npc2)),
    NPC_GROUP(N(NpcData_Skolar_Npc2)),
    NPC_GROUP(N(NpcData_Muskular_Npc2)),
    NPC_GROUP(N(NpcData_Misstar_Npc2)),
    NPC_GROUP(N(NpcData_Klevar_Npc2)),
    NPC_GROUP(N(NpcData_Kalmar_Npc2)),
    {}
};
