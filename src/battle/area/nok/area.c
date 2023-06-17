#include "area.h"

extern ActorBlueprint A(goomba);
extern ActorBlueprint A(spiked_goomba);
extern ActorBlueprint A(paragoomba);
extern ActorBlueprint A(koopa_troopa);
extern ActorBlueprint A(paratroopa);
extern ActorBlueprint A(fuzzy);
extern ActorBlueprint A(kent_c_koopa);

extern Stage A(nok_01);
extern Stage A(nok_02);
extern Stage A(nok_03);
extern Stage A(nok_04);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_C, 9),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_C, 9),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_C, 8),
};

Formation A(Formation_0F) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_C, 8),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_D, 7),
};

Formation A(Formation_11) = {
    ACTOR_BY_IDX(A(paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(paratroopa), BTL_POS_AIR_C, 9),
};

Formation A(Formation_12) = {
    ACTOR_BY_IDX(A(paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_13) = {
    ACTOR_BY_IDX(A(paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_14) = {
    ACTOR_BY_IDX(A(paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_15) = {
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_16) = {
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_17) = {
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_18) = {
    ACTOR_BY_IDX(A(kent_c_koopa), BTL_POS_GROUND_B, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(nok_02), "クリボーx２"),
    BATTLE(A(Formation_01), A(nok_02), "クリボー,トゲクリボー"),
    BATTLE(A(Formation_02), A(nok_02), "パタクリボーx２"),
    BATTLE(A(Formation_03), A(nok_02), "トゲクリボー、パタクリボー"),
    BATTLE(A(Formation_04), A(nok_02), "トゲクリボーx２"),
    BATTLE(A(Formation_05), A(nok_02), "トゲクリボー、クリボーx2"),
    BATTLE(A(Formation_06), A(nok_02), "トゲクリボーx３"),
    BATTLE(A(Formation_07), A(nok_02), "トゲクリボーx４"),
    BATTLE(A(Formation_08), A(nok_02), "ノコノコ、クリボー"),
    BATTLE(A(Formation_09), A(nok_02), "ノコノコx２"),
    BATTLE(A(Formation_0A), A(nok_02), "ノコノコx３"),
    BATTLE(A(Formation_0B), A(nok_02), "ノコノコ、トゲクリボー"),
    BATTLE(A(Formation_0C), A(nok_02), "ノコノコx2、トゲクリ"),
    BATTLE(A(Formation_0D), A(nok_02), "ノコノコ、トゲクリボーx2"),
    BATTLE(A(Formation_0E), A(nok_02), "ノコノコ、パタクリボーx2"),
    BATTLE(A(Formation_0F), A(nok_02), "ノコノコ、トゲクリボー,パタクリボー"),
    BATTLE(A(Formation_10), A(nok_02), "ノコノコx2、トゲクリボー,パタクリボー"),
    BATTLE(A(Formation_11), A(nok_02), "パタパタx2"),
    BATTLE(A(Formation_12), A(nok_02), "パタパタ、ノコノコ"),
    BATTLE(A(Formation_13), A(nok_02), "パタパタ、ノコノコ、トゲクリボー"),
    BATTLE(A(Formation_14), A(nok_02), "パタパタ、ノコノコ、トゲクリボーx2"),
    BATTLE(A(Formation_15), A(nok_02), "チョロボン"),
    BATTLE(A(Formation_16), A(nok_02), "チョロボンx2"),
    BATTLE(A(Formation_17), A(nok_02), "チョロボンx4"),
    BATTLE(A(Formation_18), A(nok_02), "ゼニノコー"),
    {},
};

StageList A(Stages) = {
    STAGE("nok_01", A(nok_01)),
    STAGE("nok_02", A(nok_02)),
    STAGE("nok_03", A(nok_03)),
    STAGE("nok_04", A(nok_04)),
    {},
};
