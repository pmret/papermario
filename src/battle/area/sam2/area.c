#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_sam2

extern ActorBlueprint N(monstar);
extern ActorBlueprint N(paragoomba);
extern ActorBlueprint N(gray_magikoopa);

extern Stage N(sam_01);
extern Stage N(sam_02);
extern Stage N(sam_02b);
extern Stage N(sam_02c);
extern Stage N(sam_02d);
extern Stage N(sam_03);

Vec3i N(80223490) = { 75, 16, 5 };

Formation N(Formation_01) = {
    { .actor = &N(monstar), .home = { .vec = &N(80223490) }, .priority = 10 },
};

Formation N(Formation_02) = {
    { .actor = &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(gray_magikoopa), .home = { .index = 2 }, .priority = 9 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), &N(sam_03), "かいぶつ"),
    BATTLE(N(Formation_02), &N(sam_01), "パタクリ,グレイカメック（チェックよう）"),
    {},
};

StageList N(Stages) = {
    { "sam_01", &N(sam_01) },
    { "sam_02", &N(sam_02) },
    { "sam_02b", &N(sam_02b) },
    { "sam_02c", &N(sam_02c) },
    { "sam_02d", &N(sam_02d) },
    { "sam_03", &N(sam_03) },
    {},
};
