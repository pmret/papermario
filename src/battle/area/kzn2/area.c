#include "area.h"
#include "ld_addrs.h"

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
