#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_nok

extern ActorBlueprint N(goomba);
extern ActorBlueprint N(spiked_goomba);
extern ActorBlueprint N(paragoomba);
extern ActorBlueprint N(koopa_troopa);
extern ActorBlueprint N(paratroopa);
extern ActorBlueprint N(fuzzy);
extern ActorBlueprint N(kent_c_koopa);

extern Stage N(nok_01);
extern Stage N(nok_02);
extern Stage N(nok_03);
extern Stage N(nok_04);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_C, 9),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_C, 9),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_C, 8),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(paragoomba), BTL_POS_AIR_D, 7),
};

Formation N(Formation_11) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_C, 9),
};

Formation N(Formation_12) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_13) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_14) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_15) = {
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_16) = {
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_17) = {
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_18) = {
    ACTOR_BY_IDX(N(kent_c_koopa), BTL_POS_GROUND_B, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(nok_02), "クリボーx２"),
    BATTLE(N(Formation_01), &N(nok_02), "クリボー,トゲクリボー"),
    BATTLE(N(Formation_02), &N(nok_02), "パタクリボーx２"),
    BATTLE(N(Formation_03), &N(nok_02), "トゲクリボー、パタクリボー"),
    BATTLE(N(Formation_04), &N(nok_02), "トゲクリボーx２"),
    BATTLE(N(Formation_05), &N(nok_02), "トゲクリボー、クリボーx2"),
    BATTLE(N(Formation_06), &N(nok_02), "トゲクリボーx３"),
    BATTLE(N(Formation_07), &N(nok_02), "トゲクリボーx４"),
    BATTLE(N(Formation_08), &N(nok_02), "ノコノコ、クリボー"),
    BATTLE(N(Formation_09), &N(nok_02), "ノコノコx２"),
    BATTLE(N(Formation_0A), &N(nok_02), "ノコノコx３"),
    BATTLE(N(Formation_0B), &N(nok_02), "ノコノコ、トゲクリボー"),
    BATTLE(N(Formation_0C), &N(nok_02), "ノコノコx2、トゲクリ"),
    BATTLE(N(Formation_0D), &N(nok_02), "ノコノコ、トゲクリボーx2"),
    BATTLE(N(Formation_0E), &N(nok_02), "ノコノコ、パタクリボーx2"),
    BATTLE(N(Formation_0F), &N(nok_02), "ノコノコ、トゲクリボー,パタクリボー"),
    BATTLE(N(Formation_10), &N(nok_02), "ノコノコx2、トゲクリボー,パタクリボー"),
    BATTLE(N(Formation_11), &N(nok_02), "パタパタx2"),
    BATTLE(N(Formation_12), &N(nok_02), "パタパタ、ノコノコ"),
    BATTLE(N(Formation_13), &N(nok_02), "パタパタ、ノコノコ、トゲクリボー"),
    BATTLE(N(Formation_14), &N(nok_02), "パタパタ、ノコノコ、トゲクリボーx2"),
    BATTLE(N(Formation_15), &N(nok_02), "チョロボン"),
    BATTLE(N(Formation_16), &N(nok_02), "チョロボンx2"),
    BATTLE(N(Formation_17), &N(nok_02), "チョロボンx4"),
    BATTLE(N(Formation_18), &N(nok_02), "ゼニノコー"),
    {},
};

StageList N(Stages) = {
    { "nok_01", &N(nok_01) },
    { "nok_02", &N(nok_02) },
    { "nok_03", &N(nok_03) },
    { "nok_04", &N(nok_04) },
    {},
};
