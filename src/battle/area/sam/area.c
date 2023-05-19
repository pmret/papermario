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

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_B, 20),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_C, 19),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_1)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_1)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_1)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_1)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_C, 18),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_2)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_2)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_2)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_2)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_C, 18),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_3)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_3)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_3)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_3)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_C, 18),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_4)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_4)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_4)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_4)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_C, 18),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_D, 17),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_5)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_5)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_5)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_5)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_C, 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_6)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_6)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_6)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_6)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_7)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_7)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_7)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_7)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(gulpit), BTL_POS_GROUND_D, 7),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_8)[0], 9),
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_8)[1], 8),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[2] }, .priority = 7, .var0 = 1 },
    ACTOR_BY_POS(N(gulpit_rocks), N(pos_rocks_8)[3], 6),
    { .actor = &N(gulpit_rocks), .home = { .vec = &N(pos_rocks_8)[4] }, .priority = 5, .var0 = 1 },
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(gray_magikoopa), BTL_POS_GROUND_D, 7),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), N(sam_01), "バケバケx2"),
    BATTLE(N(Formation_02), N(sam_01), "ゴックンx2"),
    BATTLE(N(Formation_03), N(sam_01), "ゴックンx3"),
    BATTLE(N(Formation_04), N(sam_01), "ゴックンx2,アイスパックン"),
    BATTLE(N(Formation_05), N(sam_01), "ゴックン,アイスパックン,ゴックン"),
    BATTLE(N(Formation_06), N(sam_01), "ゴックン,アイスパックン,ゴックン,アイスパックン"),
    BATTLE(N(Formation_07), N(sam_01), "アイスパックンx２"),
    BATTLE(N(Formation_08), N(sam_01), "アイスパックンx４"),
    BATTLE(N(Formation_09), N(sam_01), "アイスパックンx２,ゴックン"),
    BATTLE(N(Formation_0A), N(sam_01), "アイスパックン,ゴックン,アイスパックン"),
    BATTLE(N(Formation_0B), N(sam_01), "アイスパックン,ゴックン,アイスパックン,ゴックン"),
    BATTLE(N(Formation_0C), N(sam_01), "ホワイトガボンx２"),
    BATTLE(N(Formation_0D), N(sam_01), "ホワイトガボン,パックン,ガボン,パックン"),
    BATTLE(N(Formation_0E), N(sam_01), "ホワイトガボン,パックン,ガボン,グレイカメック"),
    {},
};

StageList N(Stages) = {
    STAGE("sam_01", N(sam_01)),
    STAGE("sam_02", N(sam_02)),
    STAGE("sam_02b", N(sam_02b)),
    STAGE("sam_02c", N(sam_02c)),
    STAGE("sam_02d", N(sam_02d)),
    STAGE("sam_03", N(sam_03)),
    {},
};
