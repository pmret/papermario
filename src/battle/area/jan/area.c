#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan

extern ActorBlueprint N(spear_guy);
extern ActorBlueprint N(jungle_fuzzy);
extern ActorBlueprint N(medi_guy);
extern ActorBlueprint N(spike_top);
extern ActorBlueprint N(hurt_plant);
extern ActorBlueprint N(m_bush);

extern Stage N(jan_00);
extern Stage N(jan_01);
extern Stage N(jan_01b);
extern Stage N(jan_02);
extern Stage N(jan_03);
extern Stage N(jan_03b);
extern Stage N(jan_04);
extern Stage N(jan_04b);

Formation N(formation_00) = {
    { .actor = &N(spear_guy), .home = { .index = 1 }, .priority = 10, .var0 = 0 },
    { .actor = &N(spear_guy), .home = { .index = 2 }, .priority = 9,  .var0 = 1 },
};

Formation N(formation_01) = {
    { .actor = &N(spear_guy), .home = { .index = 0 }, .priority = 10, .var0 = 0 },
    { .actor = &N(spear_guy), .home = { .index = 1 }, .priority = 9,  .var0 = 1 },
    { .actor = &N(spear_guy), .home = { .index = 2 }, .priority = 8,  .var0 = 1 },
};

Formation N(formation_02) = {
    { .actor = &N(spear_guy),    .home = { .index = 1 }, .priority = 10, .var0 = 0 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_03) = {
    { .actor = &N(spear_guy),    .home = { .index = 0 }, .priority = 10, .var0 = 0 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_04) = {
    { .actor = &N(spear_guy),    .home = { .index = 0 }, .priority = 10, .var0 = 0 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_05) = {
    { .actor = &N(spear_guy),    .home = { .index = 0 }, .priority = 10, .var0 = 0 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spear_guy),    .home = { .index = 2 }, .priority = 8,  .var0 = 1 },
};

Formation N(formation_06) = {
    { .actor = &N(spear_guy),    .home = { .index = 0 }, .priority = 10, .var0 = 0 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spear_guy),    .home = { .index = 2 }, .priority = 8,  .var0 = 1 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_07) = {
    { .actor = &N(spear_guy), .home = { .index = 0 }, .priority = 10, .var0 = 0 },
    { .actor = &N(medi_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_08) = {
    { .actor = &N(hurt_plant), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(hurt_plant), .home = { .index = 2 }, .priority = 10 },
};

Formation N(formation_09) = {
    { .actor = &N(hurt_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hurt_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hurt_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0A) = {
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0B) = {
    { .actor = &N(jungle_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0C) = {
    { .actor = &N(jungle_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0D) = {
    { .actor = &N(jungle_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spear_guy),    .home = { .index = 1 }, .priority = 9, .var0 = 1 },
    { .actor = &N(jungle_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0E) = {
    { .actor = &N(m_bush), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(m_bush), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0F) = {
    { .actor = &N(m_bush), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(m_bush), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(m_bush), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_10) = {
    { .actor = &N(m_bush), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(m_bush), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(m_bush), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(m_bush), .home = { .index = 3 }, .priority = 7 },
};

BattleList N(formationTable) = {
    BATTLE("ヤリダンサーx2", N(formation_00), &N(jan_01)),
    BATTLE("ヤリダンサーx3", N(formation_01), &N(jan_01)),
    BATTLE("ヤリダンサー,トロピカル", N(formation_02), &N(jan_01)),
    BATTLE("ヤリダンサー,トロピカルx３", N(formation_03), &N(jan_01)),
    BATTLE("ヤリダンサー,トロピカルx２", N(formation_04), &N(jan_01)),
    BATTLE("ヤリダンサー,トロピカル,ヤリダンサー", N(formation_05), &N(jan_01)),
    BATTLE("ヤリダンサー,トロピカル,ヤリダンサー,トロピカル", N(formation_06), &N(jan_01)),
    BATTLE("ヤリダンサー,かいふくヘイホー,トゲメット", N(formation_07), &N(jan_01)),
    BATTLE("ピロリンそうだましx2", N(formation_08), &N(jan_01)),
    BATTLE("ピロリンそうだましx3", N(formation_09), &N(jan_01)),
    BATTLE("トロピカルx2", N(formation_0A), &N(jan_01)),
    BATTLE("トロピカルx3", N(formation_0B), &N(jan_01)),
    BATTLE("トロピカルx4", N(formation_0C), &N(jan_01)),
    BATTLE("トロピカル,ヤリダンサー,トロピカル", N(formation_0D), &N(jan_01)),
    BATTLE("ぎたいそうx2", N(formation_0E), &N(jan_01)),
    BATTLE("ぎたいそうx3", N(formation_0F), &N(jan_01)),
    BATTLE("ぎたいそうx4", N(formation_10), &N(jan_01)),
    {},
};

StageList N(stageTable) = {
    { "jan_00", &N(jan_00) },
    { "jan_01", &N(jan_01) },
    { "jan_01b", &N(jan_01b) },
    { "jan_02", &N(jan_02) },
    { "jan_03", &N(jan_03) },
    { "jan_03b", &N(jan_03b) },
    { "jan_04", &N(jan_04) },
    { "jan_04b", &N(jan_04b) },
    {},
};
