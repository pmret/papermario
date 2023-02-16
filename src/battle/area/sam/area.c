#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_sam

extern ActorBlueprint N(duplighost);
extern ActorBlueprint N(gulpit);
extern ActorBlueprint N(gulpit_rocks);
extern ActorBlueprint N(frost_piranha);
extern ActorBlueprint N(gray_magikoopa);
extern ActorBlueprint N(white_clubba);

extern Stage N(sam_01);
extern Stage N(sam_02);
extern Stage N(sam_02b);
extern Stage N(sam_02c);
extern Stage N(sam_02d);
extern Stage N(sam_03);


Vec3i N(pos_rocks_1)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_2)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_3)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_4)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_5)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_6)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_7)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i N(pos_rocks_8)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Formation N(formation_01) = {
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(gulpit), .home = { .index = 1 }, .priority = 20 },
    { .actor = &N(gulpit), .home = { .index = 2 }, .priority = 19 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_03) = {
    { .actor = &N(gulpit), .home = { .index = 0 }, .priority = 20 },
    { .actor = &N(gulpit), .home = { .index = 1 }, .priority = 19 },
    { .actor = &N(gulpit), .home = { .index = 2 }, .priority = 18 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_04) = {
    { .actor = &N(gulpit), .home = { .index = 0 }, .priority = 20 },
    { .actor = &N(gulpit), .home = { .index = 1 }, .priority = 19 },
    { .actor = &N(frost_piranha), .home = { .index = 2 }, .priority = 18 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_05) = {
    { .actor = &N(gulpit), .home = { .index = 0 }, .priority = 20 },
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 19 },
    { .actor = &N(gulpit), .home = { .index = 2 }, .priority = 18 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_06) = {
    { .actor = &N(gulpit), .home = { .index = 0 }, .priority = 20 },
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 19 },
    { .actor = &N(gulpit), .home = { .index = 2 }, .priority = 18 },
    { .actor = &N(frost_piranha), .home = { .index = 3 }, .priority = 17 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_07) = {
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(frost_piranha), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_08) = {
    { .actor = &N(frost_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(frost_piranha), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(frost_piranha), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_09) = {
    { .actor = &N(frost_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(gulpit), .home = { .index = 2 }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_0A) = {
    { .actor = &N(frost_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(gulpit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(frost_piranha), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_0B) = {
    { .actor = &N(frost_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(gulpit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(frost_piranha), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(gulpit), .home = { .index = 3 }, .priority = 7 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[0] }, .priority = 9 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[1] }, .priority = 8 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[2] }, .priority = 7, .var0 = 1 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[3] }, .priority = 6 },
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(formation_0C) = {
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0D) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_clubba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(frost_piranha), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0E) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(frost_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_clubba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(gray_magikoopa), .home = { .index = 3 }, .priority = 7 },
};

BattleList N(formationTable) = {
    BATTLE("バケバケx2", N(formation_01), &N(sam_01)),
    BATTLE("ゴックンx2", N(formation_02), &N(sam_01)),
    BATTLE("ゴックンx3", N(formation_03), &N(sam_01)),
    BATTLE("ゴックンx2,アイスパックン", N(formation_04), &N(sam_01)),
    BATTLE("ゴックン,アイスパックン,ゴックン", N(formation_05), &N(sam_01)),
    BATTLE("ゴックン,アイスパックン,ゴックン,アイスパックン", N(formation_06), &N(sam_01)),
    BATTLE("アイスパックンx２", N(formation_07), &N(sam_01)),
    BATTLE("アイスパックンx４", N(formation_08), &N(sam_01)),
    BATTLE("アイスパックンx２,ゴックン", N(formation_09), &N(sam_01)),
    BATTLE("アイスパックン,ゴックン,アイスパックン", N(formation_0A), &N(sam_01)),
    BATTLE("アイスパックン,ゴックン,アイスパックン,ゴックン", N(formation_0B), &N(sam_01)),
    BATTLE("ホワイトガボンx２", N(formation_0C), &N(sam_01)),
    BATTLE("ホワイトガボン,パックン,ガボン,パックン", N(formation_0D), &N(sam_01)),
    BATTLE("ホワイトガボン,パックン,ガボン,グレイカメック", N(formation_0E), &N(sam_01)),
    {},
};

StageList N(stageTable) = {
    { "sam_01", &N(sam_01) },
    { "sam_02", &N(sam_02) },
    { "sam_02b", &N(sam_02b) },
    { "sam_02c", &N(sam_02c) },
    { "sam_02d", &N(sam_02d) },
    { "sam_03", &N(sam_03) },
    {},
};
