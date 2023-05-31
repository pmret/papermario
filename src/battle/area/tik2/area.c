#include "area.h"

extern ActorBlueprint A(blooper);
extern ActorBlueprint A(electro_blooper);
extern ActorBlueprint A(super_blooper);

extern Stage A(tik_01);
extern Stage A(tik_02);
extern Stage A(tik_03);
extern Stage A(tik_04);
extern Stage A(tik_05);

Vec3i A(BlooperPos) = { 80, 45, -10 };

Formation A(Formation_00) = {
    ACTOR_BY_POS(A(blooper), A(BlooperPos), 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(electro_blooper), A(BlooperPos), 10),
};

Formation A(Formation_02) = {
    ACTOR_BY_POS(A(super_blooper), A(BlooperPos), 10),
};

// ソ is encoded as 0x83 0x5C, so it needs another backslash to be interpreted as valid escape sequence
// TODO modify iconv instead of strings in this file
BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(tik_01), "ゲッソ\ー"),
    BATTLE(A(Formation_01), A(tik_01), "ビリビリゲッソ\ー"),
    BATTLE(A(Formation_02), A(tik_01), "ビッグゲッソ\ー　チビゲッソ\ー"),
    {},
};

StageList A(Stages) = {
    STAGE("tik_01", A(tik_01)),
    STAGE("tik_02", A(tik_02)),
    STAGE("tik_03", A(tik_03)),
    STAGE("tik_04", A(tik_04)),
    STAGE("tik_05", A(tik_05)),
    {},
};
