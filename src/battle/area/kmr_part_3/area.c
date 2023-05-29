#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3

extern ActorBlueprint N(jr_troopa);
extern ActorBlueprint N(egg_jr_troopa);
extern ActorBlueprint N(para_jr_troopa);
extern ActorBlueprint N(spiked_para_jr_troopa);
extern ActorBlueprint N(mage_jr_troopa);
extern ActorBlueprint N(final_jr_troopa);
extern ActorBlueprint N(paragoomba1);
extern ActorBlueprint N(paragoomba2);
extern ActorBlueprint N(spiked_goomba);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);
extern Stage N(nok_01);
extern Stage N(mim_01);
extern Stage N(sam_01);
extern Stage N(mac_01);
extern Stage N(kpa_01);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(spiked_goomba), BTL_POS_GROUND_C, 0),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(paragoomba2), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(paragoomba1), BTL_POS_AIR_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(jr_troopa), BTL_POS_GROUND_C, 0),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(egg_jr_troopa), BTL_POS_GROUND_C, 0),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(para_jr_troopa), BTL_POS_GROUND_C, 0),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(spiked_para_jr_troopa), BTL_POS_GROUND_B, 0),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(mage_jr_troopa), BTL_POS_GROUND_C, 0),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(final_jr_troopa), BTL_POS_GROUND_C, 0),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(kmr_03), "トゲクリボー（レクチャー）"),
    BATTLE(N(Formation_01), N(kmr_03), "パタクリボー（レクチャー）"),
    BATTLE(N(Formation_02), N(kmr_05), "コワッパ１"),
    BATTLE(N(Formation_03), N(nok_01), "コワッパ２"),
    BATTLE(N(Formation_04), N(mim_01), "コワッパ４"),
    BATTLE(N(Formation_05), N(mac_01), "コワッパ５"),
    BATTLE(N(Formation_06), N(sam_01), "コワッパ６"),
    BATTLE(N(Formation_07), N(kpa_01), "コワッパ７"),
    {},
};

StageList N(Stages) = {
    STAGE("kmr_02", N(kmr_02)),
    STAGE("kmr_03", N(kmr_03)),
    STAGE("kmr_04", N(kmr_04)),
    STAGE("kmr_05", N(kmr_05)),
    STAGE("kmr_06", N(kmr_06)),
    {},
};
