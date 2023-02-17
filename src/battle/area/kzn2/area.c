#include "common.h"
#include "battle/battle.h"
#include "ld_addrs.h"

#define NAMESPACE b_area_kzn2

extern ActorBlueprint N(lava_piranha);
extern ActorBlueprint N(petit_piranha);

extern Stage N(kzn_01);
extern Stage N(kzn_01b);
extern Stage N(kzn_02);
extern Stage N(kzn_04);
extern Stage N(kzn_04b);
extern Stage N(kzn_04c);
extern Stage N(kzn_05);

Vec3i N(lava_piranha_pos) = { 60, 60, 0 };

Formation N(Formation_00) = {
    { .actor = &N(lava_piranha), .home = { .vec = &N(lava_piranha_pos) }, .priority = 60, },
};

Vec3i N(petit_piranha_pos1) = { 40, 60, 0 };

Vec3i N(petit_piranha_pos2) = { 80, 60, 0 };

Formation N(Formation_01) = {
    { .actor = &N(petit_piranha), .home = { .vec = &N(petit_piranha_pos1) }, .priority = 10, },
    { .actor = &N(petit_piranha), .home = { .vec = &N(petit_piranha_pos2) }, .priority = 10, },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kzn_05), "ファイアパックン"),
    BATTLE(N(Formation_01), &N(kzn_05), "プチパックン"),
    {},
};

StageList N(Stages) = {
    { "kzn_01", &N(kzn_01) },
    { "kzn_01b", &N(kzn_01b) },
    { "kzn_02", &N(kzn_02) },
    { "kzn_04", &N(kzn_04) },
    { "kzn_04b", &N(kzn_04b) },
    { "kzn_04c", &N(kzn_04c) },
    { "kzn_05", &N(kzn_05) },
    {},
};

#define PIRANHA_DMA_ENTRY(name) \
    { world_model_anim_kzn_##name##_ROM_START,\
      world_model_anim_kzn_##name##_ROM_END,\
      world_model_anim_kzn_##name##_VRAM }

DmaTable N(dmaTable)[] = {
    PIRANHA_DMA_ENTRY(00),
    PIRANHA_DMA_ENTRY(01),
    PIRANHA_DMA_ENTRY(02),
    PIRANHA_DMA_ENTRY(03),
    PIRANHA_DMA_ENTRY(04),
    PIRANHA_DMA_ENTRY(05),
    PIRANHA_DMA_ENTRY(06),
    PIRANHA_DMA_ENTRY(07),
    PIRANHA_DMA_ENTRY(08),
    PIRANHA_DMA_ENTRY(09),
    PIRANHA_DMA_ENTRY(0A),
    PIRANHA_DMA_ENTRY(0B),
    PIRANHA_DMA_ENTRY(0C),
    PIRANHA_DMA_ENTRY(0D),
    PIRANHA_DMA_ENTRY(0E),
    PIRANHA_DMA_ENTRY(0F),
    PIRANHA_DMA_ENTRY(10),
    PIRANHA_DMA_ENTRY(11),
    PIRANHA_DMA_ENTRY(12),
    PIRANHA_DMA_ENTRY(13),
    PIRANHA_DMA_ENTRY(14),
    PIRANHA_DMA_ENTRY(15),
    PIRANHA_DMA_ENTRY(16),
    PIRANHA_DMA_ENTRY(17),
    PIRANHA_DMA_ENTRY(18),
    PIRANHA_DMA_ENTRY(19),
    PIRANHA_DMA_ENTRY(1A),
    PIRANHA_DMA_ENTRY(1B),
    PIRANHA_DMA_ENTRY(1C),
    PIRANHA_DMA_ENTRY(1D),
    PIRANHA_DMA_ENTRY(1E),
    PIRANHA_DMA_ENTRY(1F),
    PIRANHA_DMA_ENTRY(20),
    PIRANHA_DMA_ENTRY(21),
    PIRANHA_DMA_ENTRY(22),
    PIRANHA_DMA_ENTRY(23),
    PIRANHA_DMA_ENTRY(24),
};
