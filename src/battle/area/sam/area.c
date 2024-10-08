#include "area.h"

extern ActorBlueprint A(duplighost);
extern ActorBlueprint A(gulpit);
extern ActorBlueprint A(gulpit_rocks);
extern ActorBlueprint A(frost_piranha);
extern ActorBlueprint A(gray_magikoopa);
extern ActorBlueprint A(white_clubba);

extern Stage A(sam_01);
extern Stage A(sam_02);
extern Stage A(sam_02b);
extern Stage A(sam_02c);
extern Stage A(sam_02d);
extern Stage A(sam_03);

Vec3i A(pos_rocks_1)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_2)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_3)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_4)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_5)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_6)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_7)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Vec3i A(pos_rocks_8)[] = {
    { -35, 0, -52 },
    { -20, 0, -50 },
    { -17, 0, -40 },
    { -7, 0, -48 },
    { -28, 0, -46 },
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_B, 20),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_C, 19),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_1)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_1)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_1)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_1)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_1)[4], 5, 1),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_C, 18),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_2)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_2)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_2)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_2)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_2)[4], 5, 1),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_C, 18),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_3)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_3)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_3)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_3)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_3)[4], 5, 1),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_C, 18),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_4)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_4)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_4)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_4)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_4)[4], 5, 1),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_A, 20),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 19),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_C, 18),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_D, 17),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_5)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_5)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_5)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_5)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_5)[4], 5, 1),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_C, 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_6)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_6)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_6)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_6)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_6)[4], 5, 1),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_7)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_7)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_7)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_7)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_7)[4], 5, 1),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(gulpit), BTL_POS_GROUND_D, 7),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_8)[0], 9),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_8)[1], 8),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_8)[2], 7, 1),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_8)[3], 6),
    ACTOR_BY_POS(A(gulpit_rocks), A(pos_rocks_8)[4], 5, 1),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(gray_magikoopa), BTL_POS_GROUND_D, 7),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_01), A(sam_01), "バケバケx2"),
    BATTLE(A(Formation_02), A(sam_01), "ゴックンx2"),
    BATTLE(A(Formation_03), A(sam_01), "ゴックンx3"),
    BATTLE(A(Formation_04), A(sam_01), "ゴックンx2,アイスパックン"),
    BATTLE(A(Formation_05), A(sam_01), "ゴックン,アイスパックン,ゴックン"),
    BATTLE(A(Formation_06), A(sam_01), "ゴックン,アイスパックン,ゴックン,アイスパックン"),
    BATTLE(A(Formation_07), A(sam_01), "アイスパックンx２"),
    BATTLE(A(Formation_08), A(sam_01), "アイスパックンx４"),
    BATTLE(A(Formation_09), A(sam_01), "アイスパックンx２,ゴックン"),
    BATTLE(A(Formation_0A), A(sam_01), "アイスパックン,ゴックン,アイスパックン"),
    BATTLE(A(Formation_0B), A(sam_01), "アイスパックン,ゴックン,アイスパックン,ゴックン"),
    BATTLE(A(Formation_0C), A(sam_01), "ホワイトガボンx２"),
    BATTLE(A(Formation_0D), A(sam_01), "ホワイトガボン,パックン,ガボン,パックン"),
    BATTLE(A(Formation_0E), A(sam_01), "ホワイトガボン,パックン,ガボン,グレイカメック"),
    {},
};

StageList A(Stages) = {
    STAGE("sam_01", A(sam_01)),
    STAGE("sam_02", A(sam_02)),
    STAGE("sam_02b", A(sam_02b)),
    STAGE("sam_02c", A(sam_02c)),
    STAGE("sam_02d", A(sam_02d)),
    STAGE("sam_03", A(sam_03)),
    {},
};
