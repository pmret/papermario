#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_kmr_part_2

extern ActorBlueprint N(red_goomba_1);
extern ActorBlueprint N(red_goomba_2);
extern ActorBlueprint N(blue_goomba_1);
extern ActorBlueprint N(blue_goomba_2);
extern ActorBlueprint N(goomba_king);
extern ActorBlueprint N(goomnut_tree);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);

Vec3i N(BlueMinibossPos) = { 14, 0, -10 };
Vec3i N(RedMinibossPos)  = { 54, 0,  32 };

Formation N(Formation_00) = {
    ACTOR_BY_POS(N(blue_goomba_1), N(BlueMinibossPos), 10),
    ACTOR_BY_POS(N(red_goomba_1),  N(RedMinibossPos),  10),
};

Vec3i N(KingBossPos) = {  10, 0,  10 };
Vec3i N(RedBossPos)  = {  70, 0,  30 };
Vec3i N(BlueBossPos) = { 125, 0,  20 };
Vec3i N(TreeBossPos) = { -40, 0, -45 };

Formation N(Formation_01) = {
    ACTOR_BY_POS(N(goomba_king),   N(KingBossPos), 10),
    ACTOR_BY_POS(N(red_goomba_2),  N(RedBossPos),  10),
    ACTOR_BY_POS(N(blue_goomba_2), N(BlueBossPos), 10),
    ACTOR_BY_POS(N(goomnut_tree),  N(TreeBossPos), 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(kmr_03), "クリレッド,クリブルー"),
    BATTLE(N(Formation_01), N(kmr_06), "クリキング,クリレッド,クリブルー"),
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
