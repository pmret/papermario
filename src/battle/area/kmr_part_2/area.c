#include "area.h"

extern ActorBlueprint A(red_goomba_1);
extern ActorBlueprint A(red_goomba_2);
extern ActorBlueprint A(blue_goomba_1);
extern ActorBlueprint A(blue_goomba_2);
extern ActorBlueprint A(goomba_king);
extern ActorBlueprint A(goomnut_tree);

extern Stage A(kmr_02);
extern Stage A(kmr_03);
extern Stage A(kmr_04);
extern Stage A(kmr_05);
extern Stage A(kmr_06);

Vec3i A(BlueMinibossPos) = { 14, 0, -10 };
Vec3i A(RedMinibossPos)  = { 54, 0,  32 };

Formation A(Formation_00) = {
    ACTOR_BY_POS(A(blue_goomba_1), A(BlueMinibossPos), 10),
    ACTOR_BY_POS(A(red_goomba_1),  A(RedMinibossPos),  10),
};

Vec3i A(KingBossPos) = {  10, 0,  10 };
Vec3i A(RedBossPos)  = {  70, 0,  30 };
Vec3i A(BlueBossPos) = { 125, 0,  20 };
Vec3i A(TreeBossPos) = { -40, 0, -45 };

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(goomba_king),   A(KingBossPos), 10),
    ACTOR_BY_POS(A(red_goomba_2),  A(RedBossPos),  10),
    ACTOR_BY_POS(A(blue_goomba_2), A(BlueBossPos), 10),
    ACTOR_BY_POS(A(goomnut_tree),  A(TreeBossPos), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kmr_03), "クリレッド,クリブルー"),
    BATTLE(A(Formation_01), A(kmr_06), "クリキング,クリレッド,クリブルー"),
    {},
};

StageList A(Stages) = {
    STAGE("kmr_02", A(kmr_02)),
    STAGE("kmr_03", A(kmr_03)),
    STAGE("kmr_04", A(kmr_04)),
    STAGE("kmr_05", A(kmr_05)),
    STAGE("kmr_06", A(kmr_06)),
    {},
};
