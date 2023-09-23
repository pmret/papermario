#include "area.h"
#include "ld_addrs.h"
#include "actor/boss_common.h"

extern ActorBlueprint A(lava_piranha);
extern ActorBlueprint A(petit_piranha);

extern Stage A(kzn_01);
extern Stage A(kzn_01b);
extern Stage A(kzn_02);
extern Stage A(kzn_04);
extern Stage A(kzn_04b);
extern Stage A(kzn_04c);
extern Stage A(kzn_05);

Vec3i A(lava_piranha_pos) = { 60, 60, 0 };

Formation A(Formation_00) = {
    ACTOR_BY_POS(A(lava_piranha), A(lava_piranha_pos), 60),
};

Vec3i A(petit_piranha_pos1) = { 40, 60, 0 };
Vec3i A(petit_piranha_pos2) = { 80, 60, 0 };

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(petit_piranha), A(petit_piranha_pos1), 10),
    ACTOR_BY_POS(A(petit_piranha), A(petit_piranha_pos2), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kzn_05), "ファイアパックン"),
    BATTLE(A(Formation_01), A(kzn_05), "プチパックン"),
    {},
};

StageList A(Stages) = {
    STAGE("kzn_01",  A(kzn_01)),
    STAGE("kzn_01b", A(kzn_01b)),
    STAGE("kzn_02",  A(kzn_02)),
    STAGE("kzn_04",  A(kzn_04)),
    STAGE("kzn_04b", A(kzn_04b)),
    STAGE("kzn_04c", A(kzn_04c)),
    STAGE("kzn_05",  A(kzn_05)),
    {},
};

#define PIRANHA_DMA_ENTRY(name) \
    { world_model_anim_kzn_##name##_ROM_START,\
      world_model_anim_kzn_##name##_ROM_END,\
      world_model_anim_kzn_##name##_VRAM }

DmaTable A(dmaTable)[] = {
    [VINE_ANIM_BOSS_IDLE]                   PIRANHA_DMA_ENTRY(00),
    [VINE_ANIM_BOSS_TWITCH]                 PIRANHA_DMA_ENTRY(01),
    [VINE_ANIM_BOSS_ATTACK]                 PIRANHA_DMA_ENTRY(02),
    [VINE_ANIM_BOSS_POST_ATTACK]            PIRANHA_DMA_ENTRY(03),
    [VINE_ANIM_BOSS_STUNNED_HEAVY_HIT]      PIRANHA_DMA_ENTRY(04),
    [VINE_ANIM_BOSS_STUNNED_LIGHT_HIT]      PIRANHA_DMA_ENTRY(05),
    [VINE_ANIM_BOSS_HEAVY_HIT]              PIRANHA_DMA_ENTRY(06),
    [VINE_ANIM_BOSS_LIGHT_HIT]              PIRANHA_DMA_ENTRY(07),
    [VINE_ANIM_BOSS_STUNNED_DEATH_BEGIN]    PIRANHA_DMA_ENTRY(08),
    [VINE_ANIM_BOSS_DEATH_BEGIN]            PIRANHA_DMA_ENTRY(09),
    [VINE_ANIM_BOSS_DEATH_MIDDLE]           PIRANHA_DMA_ENTRY(0A),
    [VINE_ANIM_BOSS_DEATH_COLLAPSE]         PIRANHA_DMA_ENTRY(0B),
    [VINE_ANIM_BOSS_EMERGE]                 PIRANHA_DMA_ENTRY(0C),
    [VINE_ANIM_BOSS_STUN]                   PIRANHA_DMA_ENTRY(0D),
    [VINE_ANIM_BOSS_RECOVER]                PIRANHA_DMA_ENTRY(0E),
    [VINE_ANIM_BOSS_DUP_EMERGE]             PIRANHA_DMA_ENTRY(0F),
    [VINE_ANIM_BOSS_SINK_AWAY]              PIRANHA_DMA_ENTRY(10),
    [VINE_ANIM_BOSS_TALK]                   PIRANHA_DMA_ENTRY(11),
    [VINE_ANIM_BUD_ATTACK]                  PIRANHA_DMA_ENTRY(12),
    [VINE_ANIM_BUD_STUNNED_HEAVY_HIT]       PIRANHA_DMA_ENTRY(13),
    [VINE_ANIM_BUD_STUNNED_LIGHT_HIT]       PIRANHA_DMA_ENTRY(14),
    [VINE_ANIM_BUD_HEAVY_HIT]               PIRANHA_DMA_ENTRY(15),
    [VINE_ANIM_BUD_LIGHT_HIT]               PIRANHA_DMA_ENTRY(16),
    [VINE_ANIM_BUD_STUNNED_DEATH_BEGIN]     PIRANHA_DMA_ENTRY(17),
    [VINE_ANIM_BUD_DEATH_BEGIN]             PIRANHA_DMA_ENTRY(18),
    [VINE_ANIM_BUD_DEATH_MIDDLE]            PIRANHA_DMA_ENTRY(19),
    [VINE_ANIM_BUD_DEATH_COLLAPSE]          PIRANHA_DMA_ENTRY(1A),
    [VINE_ANIM_BUD_STUN]                    PIRANHA_DMA_ENTRY(1B),
    [VINE_ANIM_BUD_EMERGE]                  PIRANHA_DMA_ENTRY(1C),
    [VINE_ANIM_BUD_RECOVER]                 PIRANHA_DMA_ENTRY(1D),
    [VINE_ANIM_BUD_TWITCH]                  PIRANHA_DMA_ENTRY(1E),
    [VINE_ANIM_BUD_IDLE]                    PIRANHA_DMA_ENTRY(1F),
    [VINE_ANIM_BUD_DUP_EMERGE]              PIRANHA_DMA_ENTRY(20),
    [VINE_ANIM_BUD_SINK_AWAY]               PIRANHA_DMA_ENTRY(21),
    [VINE_ANIM_EXTRA_IDLE]                  PIRANHA_DMA_ENTRY(22),
    [VINE_ANIM_EXTRA_DEATH]                 PIRANHA_DMA_ENTRY(23),
    [VINE_ANIM_EXTRA_EMERGE]                PIRANHA_DMA_ENTRY(24),
};
