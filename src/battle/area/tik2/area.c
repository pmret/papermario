#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik2

extern ActorBlueprint N(blooper);
extern ActorBlueprint N(electro_blooper);
extern ActorBlueprint N(super_blooper);

extern Stage N(tik_01);
extern Stage N(tik_02);
extern Stage N(tik_03);
extern Stage N(tik_04);
extern Stage N(tik_05);

Vec3i N(blooper_pos) = { 80, 45, -10 };

Formation N(Formation_00) = {
    ACTOR_BY_POS(N(blooper), N(blooper_pos), 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_POS(N(electro_blooper), N(blooper_pos), 10),
};

Formation N(Formation_02) = {
    ACTOR_BY_POS(N(super_blooper), N(blooper_pos), 10),
};

// ソ is encoded as 0x83 0x5C, so it needs another backslash to be interpreted as valid escape sequence
// TODO modify iconv instead of strings in this file
BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(tik_01), "ゲッソ\ー"),
    BATTLE(N(Formation_01), N(tik_01), "ビリビリゲッソ\ー"),
    BATTLE(N(Formation_02), N(tik_01), "ビッグゲッソ\ー　チビゲッソ\ー"),
    {},
};

StageList N(Stages) = {
    STAGE("tik_01", N(tik_01)),
    STAGE("tik_02", N(tik_02)),
    STAGE("tik_03", N(tik_03)),
    STAGE("tik_04", N(tik_04)),
    STAGE("tik_05", N(tik_05)),
    {},
};
