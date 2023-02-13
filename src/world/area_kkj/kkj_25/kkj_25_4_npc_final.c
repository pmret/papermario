#include "kkj_25.h"

#define NAME_SUFFIX _Npc3

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/complete/Kammy_Flying.inc.c"
#include "world/common/npc/StarRod.inc.c"

#include "world/common/npc/Peach.h"
#include "world/common/npc/Twink.h"

s32 N(FlyingKammyHoverOffsets)[] = {
    1, 2, 3, 2, 1, -1, -2, -3, -2, -1, 
};

EvtScript N(EVS_NpcAux_Kammy_Broom) = {
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(FlyingKammyHoverOffsets)))
    EVT_LOOP(10)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(GetNpcPos, NPC_Kammy_05, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, LVar1)
        EVT_CALL(SetNpcPos, NPC_Kammy_05, LVar2, LVar3, LVar4)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarRod) = {
    EVT_CALL(SetNpcPos, NPC_StarRod, 270, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_03) = {
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_DefeatedIdle)
    EVT_CALL(SetNpcPos, NPC_Bowser_03, 300, 0, 50)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Peach) = {
    EVT_CALL(SetNpcCollisionSize, NPC_Peach_02, 48, 24)
    EVT_CALL(SetNpcPos, NPC_Peach_02, 400, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Peach_02, ANIM_Peach_A0001)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kammy_Broom) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Kammy_Broom)))
    EVT_CALL(SetNpcPos, NPC_Kammy_05, 525, 10, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy_05, ANIM_BattleKammy_Anim04)
    EVT_CALL(InterpNpcYaw, NPC_Kammy_05, 270, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink_02) = {
    EVT_CALL(SetNpcPos, NPC_Twink_02, 430, 30, 0)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_DefeatedIdle,
    -1
};

s32 N(ExtraAnims_Peach)[] = {
    ANIM_Peach_A0001,
    ANIM_Peach_A0002,
    ANIM_Peach_C0000,
    ANIM_Peach_C0006,
    -1
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    -1
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_Twink_Cringe,
    -1
};

StaticNpc N(NpcData_Bowser) = {
    .id = NPC_Bowser_03,
    .settings = &N(NpcSettings_Bowser),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Bowser_03),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

StaticNpc N(NpcData_Peach) = {
    .id = NPC_Peach_02,
    .settings = &N(NpcSettings_Dummy),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Peach),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

StaticNpc N(NpcData_Kammy) = {
    .id = NPC_Kammy_05,
    .settings = &N(NpcSettings_Kammy_Flying),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Kammy_Broom),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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

StaticNpc N(NpcData_Twink) = {
    .id = NPC_Twink_02,
    .settings = &N(NpcSettings_Dummy),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Twink_02),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

StaticNpc N(NpcData_StarRod) = {
    .id = NPC_StarRod,
    .settings = &N(NpcSettings_StarRod),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_StarRod),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
