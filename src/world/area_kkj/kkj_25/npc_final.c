#include "kkj_25.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Npc3

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"
#include "world/common/npc/StarRod.inc.c"

#include "world/common/npc/Peach.h"
#include "world/common/npc/Twink.h"

s32 N(FlyingKammyHoverOffsets)[] = {
    1, 2, 3, 2, 1, -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcAux_Kammy_Broom) = {
    Label(0)
    UseBuf(Ref(N(FlyingKammyHoverOffsets)))
    Loop(10)
        BufRead1(LVar1)
        Call(GetNpcPos, NPC_Kammy_05, LVar2, LVar3, LVar4)
        Add(LVar3, LVar1)
        Call(SetNpcPos, NPC_Kammy_05, LVar2, LVar3, LVar4)
        Wait(3)
    EndLoop
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarRod) = {
    Call(SetNpcPos, NPC_StarRod, 270, 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bowser_03) = {
    Call(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_DefeatedIdle)
    Call(SetNpcPos, NPC_Bowser_03, 300, 0, 50)
    Return
    End
};

EvtScript N(EVS_NpcInit_Peach) = {
    Call(SetNpcCollisionSize, NPC_Peach_02, 48, 24)
    Call(SetNpcPos, NPC_Peach_02, 400, 0, 0)
    Call(SetNpcAnimation, NPC_Peach_02, ANIM_Peach1_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy_Broom) = {
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Kammy_Broom)))
    Call(SetNpcPos, NPC_Kammy_05, 525, 10, 0)
    Call(SetNpcAnimation, NPC_Kammy_05, ANIM_BattleKammy_Anim04)
    Call(InterpNpcYaw, NPC_Kammy_05, 270, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink_02) = {
    Call(SetNpcPos, NPC_Twink_02, 430, 30, 0)
    Return
    End
};

AnimID N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_DefeatedIdle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Peach)[] = {
    ANIM_Peach1_Idle,
    ANIM_Peach1_Walk,
    ANIM_Peach2_RaiseArms,
    ANIM_Peach2_GaspStill,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_Twink_Cringe,
    ANIM_LIST_END
};

NpcData N(NpcData_Bowser) = {
    .id = NPC_Bowser_03,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_03),
    .settings = &N(NpcSettings_Bowser),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

NpcData N(NpcData_Peach) = {
    .id = NPC_Peach_02,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Peach),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy_05,
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
};

NpcData N(NpcData_Twink) = {
    .id = NPC_Twink_02,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Twink_02),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

NpcData N(NpcData_StarRod) = {
    .id = NPC_StarRod,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_StarRod),
    .settings = &N(NpcSettings_StarRod),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = STAR_ROD_ANIMS,
};

#define NAME_SUFFIX

NpcGroupList N(FinaleNpcs) = {
    NPC_GROUP(N(NpcData_Bowser_Npc3), BTL_KPA2_FORMATION_03),
    NPC_GROUP(N(NpcData_Peach_Npc3)),
    NPC_GROUP(N(NpcData_Kammy_Npc3), BTL_KKJ_FORMATION_00),
    NPC_GROUP(N(NpcData_Twink_Npc3)),
    NPC_GROUP(N(NpcData_StarRod_Npc3)),
    {}
};
