#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa

extern ActorBlueprint N(bony_beetle);
extern ActorBlueprint N(dry_bones);
extern ActorBlueprint N(magikoopa);
extern ActorBlueprint N(magikoopa_flying);
extern ActorBlueprint N(ember);
extern ActorBlueprint N(koopatrol);
extern ActorBlueprint N(hammer_bro);

extern Stage N(kpa_01);
extern Stage N(kpa_01b);
extern Stage N(kpa_02);
extern Stage N(kpa_03);
extern Stage N(kpa_04);
extern Stage N(kpa_04b);
extern Stage N(kpa_04c);
extern Stage N(kpa_05);
extern Stage N(kpa_07);
extern Stage N(kpa_08);
extern Stage N(kpa_09);
extern Stage N(kpa_11);
extern Stage N(kpa_13);
extern Stage N(kpa_14);

Formation N(formation_00) = {
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_01) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_02) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_03) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_04) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_05) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_06) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_07) = {
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_08) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_09) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(dry_bones), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_0A) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(ember), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(ember), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(ember), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_0B) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_0C) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_0D) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_0E) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(bony_beetle), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_0F) = {
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_10) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_11) = {
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_12) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_13) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_14) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 9, },
};

Formation N(formation_15) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_16) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 9, },
};

Formation N(formation_17) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
};

Formation N(formation_18) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_19) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_1A) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(koopatrol), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_1B) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_1C) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(hammer_bro), .home = { .index = 3 }, .priority = 7, },
};

Vec3i N(formation_1D_pos1) = { 5, 0, -20 };

Vec3i N(formation_1D_pos2) = { 45, 0, -10 };

Vec3i N(formation_1D_pos3) = { 85, 0, 0 };

Vec3i N(formation_1D_pos4) = { 125, 0, 5 };

Formation N(formation_1D) = {
    { .actor = &N(koopatrol), .home = { .vec = &N(formation_1D_pos1) }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .vec = &N(formation_1D_pos2) }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .vec = &N(formation_1D_pos3) }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .vec = &N(formation_1D_pos4) }, .priority = 7, },
};

Formation N(formation_1E) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_1F) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_20) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_21) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_22) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_23) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_24) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_25) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 7, },
};

Formation N(formation_26) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_27) = {
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_28) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_29) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_2A) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 7, },
};

Formation N(formation_2B) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(koopatrol), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_2C) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_2D) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_2E) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_2F) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_30) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(koopatrol), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_31) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 9, },
};

Formation N(formation_32) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_33) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_34) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_35) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_36) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_37) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 9, },
};

Formation N(formation_38) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 7, },
};

BattleList N(formationTable) = {
    BATTLE("ホネメットx２", N(formation_00), &N(kpa_01)),
    BATTLE("ホネメットx３", N(formation_01), &N(kpa_01)),
    BATTLE("ホネメット,カロンx２", N(formation_02), &N(kpa_01)),
    BATTLE("ホネメットx２,カロン", N(formation_03), &N(kpa_01)),
    BATTLE("ホネメットx２,カメック", N(formation_04), &N(kpa_01)),
    BATTLE("ホネメットx３,カメック", N(formation_05), &N(kpa_01)),
    BATTLE("ホネメット,カロン,ホネメット,カメック", N(formation_06), &N(kpa_01)),
    BATTLE("カロンx２", N(formation_07), &N(kpa_01)),
    BATTLE("カロンx３", N(formation_08), &N(kpa_01)),
    BATTLE("カロンx４", N(formation_09), &N(kpa_01)),
    BATTLE("カロン,エルモスx３", N(formation_0A), &N(kpa_01)),
    BATTLE("カロンx２,カメック", N(formation_0B), &N(kpa_01)),
    BATTLE("カロン,トゲノコx２", N(formation_0C), &N(kpa_01)),
    BATTLE("カロンx２,ホネメット", N(formation_0D), &N(kpa_01)),
    BATTLE("カロンx２,ホネメットx２", N(formation_0E), &N(kpa_01)),
    BATTLE("ハンマーブロスx２", N(formation_0F), &N(kpa_01)),
    BATTLE("ハンマーブロスx３", N(formation_10), &N(kpa_01)),
    BATTLE("ハンマーブロス,トゲノコ", N(formation_11), &N(kpa_01)),
    BATTLE("ハンマーブロスx２,トゲノコ", N(formation_12), &N(kpa_01)),
    BATTLE("ハンマーブロス,トゲノコx２", N(formation_13), &N(kpa_01)),
    BATTLE("ハンマーブロス,カロン,ハンンマーブロス,カメック", N(formation_14), &N(kpa_01)),
    BATTLE("ハンマーブロスx２,くうちゅうカメック", N(formation_15), &N(kpa_01)),
    BATTLE("ハンマーブロスx３,くうちゅうカメック", N(formation_16), &N(kpa_01)),
    BATTLE("トゲノコ", N(formation_17), &N(kpa_01)),
    BATTLE("トゲノコx２", N(formation_18), &N(kpa_01)),
    BATTLE("トゲノコx３", N(formation_19), &N(kpa_01)),
    BATTLE("トゲノコx４", N(formation_1A), &N(kpa_01)),
    BATTLE("トゲノコ,ハンマーブロス", N(formation_1B), &N(kpa_01)),
    BATTLE("トゲノコ,ハンマーブロス,トゲノコ,ハンマーブロス", N(formation_1C), &N(kpa_01)),
    BATTLE("トゲノコx３,カメック", N(formation_1D), &N(kpa_01)),
    BATTLE("トゲノコx２,カメックx２", N(formation_1E), &N(kpa_01)),
    BATTLE("トゲノコ,ホネメット", N(formation_20), &N(kpa_01)),
    BATTLE("トゲノコx２,ホネメット", N(formation_21), &N(kpa_01)),
    BATTLE("トゲノコ,ホネメットx２", N(formation_22), &N(kpa_01)),
    BATTLE("トゲノコ,ホネメット,トゲノコ", N(formation_23), &N(kpa_01)),
    BATTLE("トゲノコ,カロンx２", N(formation_24), &N(kpa_01)),
    BATTLE("トゲノコx２,カメック,くうちゅうカメック", N(formation_25), &N(kpa_01)),
    BATTLE("トゲノコ,カメック,トゲノコ,カメック", N(formation_26), &N(kpa_01)),
    BATTLE("カメックx２", N(formation_27), &N(kpa_01)),
    BATTLE("カメックx３", N(formation_28), &N(kpa_01)),
    BATTLE("カメック,くうちゅうカメックx２", N(formation_29), &N(kpa_01)),
    BATTLE("カメックx２,くうちゅうカメックx２", N(formation_2A), &N(kpa_01)),
    BATTLE("カメック,トゲノコx３", N(formation_2B), &N(kpa_01)),
    BATTLE("カメックx２,カロン", N(formation_2C), &N(kpa_01)),
    BATTLE("カメック,ホネメット,カメック", N(formation_2D), &N(kpa_01)),
    BATTLE("カメック,ホネメットx２,カメック", N(formation_2E), &N(kpa_01)),
    BATTLE("カメックx２,くうちゅうカメック", N(formation_2F), &N(kpa_01)),
    BATTLE("カメック,トゲノコ,カメック,トゲノコ", N(formation_30), &N(kpa_01)),
    BATTLE("くうちゅうカメックx２", N(formation_31), &N(kpa_01)),
    BATTLE("くうちゅうカメックx３", N(formation_32), &N(kpa_01)),
    BATTLE("くうちゅうカメック,カメック,くうちゅうカメック,カメック", N(formation_33), &N(kpa_01)),
    BATTLE("くうちゅうカメック,トゲノコx２", N(formation_34), &N(kpa_01)),
    BATTLE("くうちゅうカメック,ハンマーブロス", N(formation_35), &N(kpa_01)),
    BATTLE("くうちゅうカメック,カロンx２", N(formation_36), &N(kpa_01)),
    BATTLE("くうちゅうカメック,トゲノコ,くうちゅうカメック", N(formation_37), &N(kpa_01)),
    BATTLE("くうちゅうカメック,ハンマーブロスx２,くうちゅうカメック", N(formation_38), &N(kpa_01)),
    {},
};

StageList N(stageTable) = {
    { "kpa_01", &N(kpa_01) },
    { "kpa_01b", &N(kpa_01b) },
    { "kpa_02", &N(kpa_02) },
    { "kpa_03", &N(kpa_03) },
    { "kpa_04", &N(kpa_04) },
    { "kpa_04b", &N(kpa_04b) },
    { "kpa_04c", &N(kpa_04c) },
    { "kpa_05", &N(kpa_05) },
    { "kpa_07", &N(kpa_07) },
    { "kpa_08", &N(kpa_08) },
    { "kpa_09", &N(kpa_09) },
    { "kpa_11", &N(kpa_11) },
    { "kpa_13", &N(kpa_13) },
    { "kpa_14", &N(kpa_14) },
    {},
};
