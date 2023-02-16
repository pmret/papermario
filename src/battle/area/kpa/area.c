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

Formation N(Formation_00) = {
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_01) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_02) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_03) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_04) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_05) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_06) = {
    { .actor = &N(bony_beetle), .home = { .index = 0 }, .priority = 10, .var0 = 1, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_07) = {
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_08) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_09) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(dry_bones), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_0A) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(ember), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(ember), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(ember), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_0B) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_0C) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_0D) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_0E) = {
    { .actor = &N(dry_bones), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(bony_beetle), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_0F) = {
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_10) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_11) = {
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_12) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_13) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_14) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 9, },
};

Formation N(Formation_15) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_16) = {
    { .actor = &N(hammer_bro), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 9, },
};

Formation N(Formation_17) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
};

Formation N(Formation_18) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_19) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_1A) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(koopatrol), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_1B) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_1C) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(hammer_bro), .home = { .index = 3 }, .priority = 7, },
};

Vec3i N(Formation_1D_pos1) = { 5, 0, -20 };

Vec3i N(Formation_1D_pos2) = { 45, 0, -10 };

Vec3i N(Formation_1D_pos3) = { 85, 0, 0 };

Vec3i N(Formation_1D_pos4) = { 125, 0, 5 };

Formation N(Formation_1D) = {
    { .actor = &N(koopatrol), .home = { .vec = &N(Formation_1D_pos1) }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .vec = &N(Formation_1D_pos2) }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .vec = &N(Formation_1D_pos3) }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .vec = &N(Formation_1D_pos4) }, .priority = 7, },
};

Formation N(Formation_1E) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_1F) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_20) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_21) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_22) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_23) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_24) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_25) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 7, },
};

Formation N(Formation_26) = {
    { .actor = &N(koopatrol), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_27) = {
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_28) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_29) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_2A) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 7, },
};

Formation N(Formation_2B) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(koopatrol), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_2C) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_2D) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_2E) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bony_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bony_beetle), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_2F) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_30) = {
    { .actor = &N(magikoopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(koopatrol), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_31) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_32) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_33) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(magikoopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_34) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_35) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_36) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(dry_bones), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dry_bones), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_37) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(magikoopa_flying), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_38) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(magikoopa_flying), .home = { .index = 7 }, .priority = 7, },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kpa_01), "ホネメットx２"),
    BATTLE(N(Formation_01), &N(kpa_01), "ホネメットx３"),
    BATTLE(N(Formation_02), &N(kpa_01), "ホネメット,カロンx２"),
    BATTLE(N(Formation_03), &N(kpa_01), "ホネメットx２,カロン"),
    BATTLE(N(Formation_04), &N(kpa_01), "ホネメットx２,カメック"),
    BATTLE(N(Formation_05), &N(kpa_01), "ホネメットx３,カメック"),
    BATTLE(N(Formation_06), &N(kpa_01), "ホネメット,カロン,ホネメット,カメック"),
    BATTLE(N(Formation_07), &N(kpa_01), "カロンx２"),
    BATTLE(N(Formation_08), &N(kpa_01), "カロンx３"),
    BATTLE(N(Formation_09), &N(kpa_01), "カロンx４"),
    BATTLE(N(Formation_0A), &N(kpa_01), "カロン,エルモスx３"),
    BATTLE(N(Formation_0B), &N(kpa_01), "カロンx２,カメック"),
    BATTLE(N(Formation_0C), &N(kpa_01), "カロン,トゲノコx２"),
    BATTLE(N(Formation_0D), &N(kpa_01), "カロンx２,ホネメット"),
    BATTLE(N(Formation_0E), &N(kpa_01), "カロンx２,ホネメットx２"),
    BATTLE(N(Formation_0F), &N(kpa_01), "ハンマーブロスx２"),
    BATTLE(N(Formation_10), &N(kpa_01), "ハンマーブロスx３"),
    BATTLE(N(Formation_11), &N(kpa_01), "ハンマーブロス,トゲノコ"),
    BATTLE(N(Formation_12), &N(kpa_01), "ハンマーブロスx２,トゲノコ"),
    BATTLE(N(Formation_13), &N(kpa_01), "ハンマーブロス,トゲノコx２"),
    BATTLE(N(Formation_14), &N(kpa_01), "ハンマーブロス,カロン,ハンンマーブロス,カメック"),
    BATTLE(N(Formation_15), &N(kpa_01), "ハンマーブロスx２,くうちゅうカメック"),
    BATTLE(N(Formation_16), &N(kpa_01), "ハンマーブロスx３,くうちゅうカメック"),
    BATTLE(N(Formation_17), &N(kpa_01), "トゲノコ"),
    BATTLE(N(Formation_18), &N(kpa_01), "トゲノコx２"),
    BATTLE(N(Formation_19), &N(kpa_01), "トゲノコx３"),
    BATTLE(N(Formation_1A), &N(kpa_01), "トゲノコx４"),
    BATTLE(N(Formation_1B), &N(kpa_01), "トゲノコ,ハンマーブロス"),
    BATTLE(N(Formation_1C), &N(kpa_01), "トゲノコ,ハンマーブロス,トゲノコ,ハンマーブロス"),
    BATTLE(N(Formation_1D), &N(kpa_01), "トゲノコx３,カメック"),
    BATTLE(N(Formation_1E), &N(kpa_01), "トゲノコx２,カメックx２"),
    BATTLE(N(Formation_20), &N(kpa_01), "トゲノコ,ホネメット"),
    BATTLE(N(Formation_21), &N(kpa_01), "トゲノコx２,ホネメット"),
    BATTLE(N(Formation_22), &N(kpa_01), "トゲノコ,ホネメットx２"),
    BATTLE(N(Formation_23), &N(kpa_01), "トゲノコ,ホネメット,トゲノコ"),
    BATTLE(N(Formation_24), &N(kpa_01), "トゲノコ,カロンx２"),
    BATTLE(N(Formation_25), &N(kpa_01), "トゲノコx２,カメック,くうちゅうカメック"),
    BATTLE(N(Formation_26), &N(kpa_01), "トゲノコ,カメック,トゲノコ,カメック"),
    BATTLE(N(Formation_27), &N(kpa_01), "カメックx２"),
    BATTLE(N(Formation_28), &N(kpa_01), "カメックx３"),
    BATTLE(N(Formation_29), &N(kpa_01), "カメック,くうちゅうカメックx２"),
    BATTLE(N(Formation_2A), &N(kpa_01), "カメックx２,くうちゅうカメックx２"),
    BATTLE(N(Formation_2B), &N(kpa_01), "カメック,トゲノコx３"),
    BATTLE(N(Formation_2C), &N(kpa_01), "カメックx２,カロン"),
    BATTLE(N(Formation_2D), &N(kpa_01), "カメック,ホネメット,カメック"),
    BATTLE(N(Formation_2E), &N(kpa_01), "カメック,ホネメットx２,カメック"),
    BATTLE(N(Formation_2F), &N(kpa_01), "カメックx２,くうちゅうカメック"),
    BATTLE(N(Formation_30), &N(kpa_01), "カメック,トゲノコ,カメック,トゲノコ"),
    BATTLE(N(Formation_31), &N(kpa_01), "くうちゅうカメックx２"),
    BATTLE(N(Formation_32), &N(kpa_01), "くうちゅうカメックx３"),
    BATTLE(N(Formation_33), &N(kpa_01), "くうちゅうカメック,カメック,くうちゅうカメック,カメック"),
    BATTLE(N(Formation_34), &N(kpa_01), "くうちゅうカメック,トゲノコx２"),
    BATTLE(N(Formation_35), &N(kpa_01), "くうちゅうカメック,ハンマーブロス"),
    BATTLE(N(Formation_36), &N(kpa_01), "くうちゅうカメック,カロンx２"),
    BATTLE(N(Formation_37), &N(kpa_01), "くうちゅうカメック,トゲノコ,くうちゅうカメック"),
    BATTLE(N(Formation_38), &N(kpa_01), "くうちゅうカメック,ハンマーブロスx２,くうちゅうカメック"),
    {},
};

StageList N(Stages) = {
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
