#include "area.h"

extern ActorBlueprint A(bony_beetle);
extern ActorBlueprint A(dry_bones);
extern ActorBlueprint A(magikoopa);
extern ActorBlueprint A(magikoopa_flying);
extern ActorBlueprint A(ember);
extern ActorBlueprint A(koopatrol);
extern ActorBlueprint A(hammer_bro);

extern Stage A(kpa_01);
extern Stage A(kpa_01b);
extern Stage A(kpa_02);
extern Stage A(kpa_03);
extern Stage A(kpa_04);
extern Stage A(kpa_04b);
extern Stage A(kpa_04c);
extern Stage A(kpa_05);
extern Stage A(kpa_07);
extern Stage A(kpa_08);
extern Stage A(kpa_09);
extern Stage A(kpa_11);
extern Stage A(kpa_13);
extern Stage A(kpa_14);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 10, 1),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_A, 10, 1),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_A, 10, 1),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_A, 10, 1),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_A, 10, 1),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_A, 10, 1),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_A, 10, 1),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0F) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_11) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_12) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_13) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_14) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 9),
};

Formation A(Formation_15) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 8),
};

Formation A(Formation_16) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_D, 9),
};

Formation A(Formation_17) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_18) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_19) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_1A) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_1B) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_1C) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_D, 7),
};

Vec3i A(Formation_1D_pos1) = { 5, 0, -20 };

Vec3i A(Formation_1D_pos2) = { 45, 0, -10 };

Vec3i A(Formation_1D_pos3) = { 85, 0, 0 };

Vec3i A(Formation_1D_pos4) = { 125, 0, 5 };

Formation A(Formation_1D) = {
    ACTOR_BY_POS(A(koopatrol), A(Formation_1D_pos1), 10),
    ACTOR_BY_POS(A(koopatrol), A(Formation_1D_pos2), 9),
    ACTOR_BY_POS(A(koopatrol), A(Formation_1D_pos3), 8),
    ACTOR_BY_POS(A(magikoopa), A(Formation_1D_pos4), 7),
};

Formation A(Formation_1E) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_1F) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_20) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_21) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_22) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_23) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_24) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_25) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_D, 7),
};

Formation A(Formation_26) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_27) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_28) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_29) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 8),
};

Formation A(Formation_2A) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_D, 7),
};

Formation A(Formation_2B) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_2C) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_2D) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_2E) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_2F) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 8),
};

Formation A(Formation_30) = {
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_31) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 9),
};

Formation A(Formation_32) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 8),
};

Formation A(Formation_33) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_34) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_35) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_36) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dry_bones), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_37) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_C, 9),
};

Formation A(Formation_38) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_D, 7),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kpa_01), "ホネメットx２"),
    BATTLE(A(Formation_01), A(kpa_01), "ホネメットx３"),
    BATTLE(A(Formation_02), A(kpa_01), "ホネメット,カロンx２"),
    BATTLE(A(Formation_03), A(kpa_01), "ホネメットx２,カロン"),
    BATTLE(A(Formation_04), A(kpa_01), "ホネメットx２,カメック"),
    BATTLE(A(Formation_05), A(kpa_01), "ホネメットx３,カメック"),
    BATTLE(A(Formation_06), A(kpa_01), "ホネメット,カロン,ホネメット,カメック"),
    BATTLE(A(Formation_07), A(kpa_01), "カロンx２"),
    BATTLE(A(Formation_08), A(kpa_01), "カロンx３"),
    BATTLE(A(Formation_09), A(kpa_01), "カロンx４"),
    BATTLE(A(Formation_0A), A(kpa_01), "カロン,エルモスx３"),
    BATTLE(A(Formation_0B), A(kpa_01), "カロンx２,カメック"),
    BATTLE(A(Formation_0C), A(kpa_01), "カロン,トゲノコx２"),
    BATTLE(A(Formation_0D), A(kpa_01), "カロンx２,ホネメット"),
    BATTLE(A(Formation_0E), A(kpa_01), "カロンx２,ホネメットx２"),
    BATTLE(A(Formation_0F), A(kpa_01), "ハンマーブロスx２"),
    BATTLE(A(Formation_10), A(kpa_01), "ハンマーブロスx３"),
    BATTLE(A(Formation_11), A(kpa_01), "ハンマーブロス,トゲノコ"),
    BATTLE(A(Formation_12), A(kpa_01), "ハンマーブロスx２,トゲノコ"),
    BATTLE(A(Formation_13), A(kpa_01), "ハンマーブロス,トゲノコx２"),
    BATTLE(A(Formation_14), A(kpa_01), "ハンマーブロス,カロン,ハンンマーブロス,カメック"),
    BATTLE(A(Formation_15), A(kpa_01), "ハンマーブロスx２,くうちゅうカメック"),
    BATTLE(A(Formation_16), A(kpa_01), "ハンマーブロスx３,くうちゅうカメック"),
    BATTLE(A(Formation_17), A(kpa_01), "トゲノコ"),
    BATTLE(A(Formation_18), A(kpa_01), "トゲノコx２"),
    BATTLE(A(Formation_19), A(kpa_01), "トゲノコx３"),
    BATTLE(A(Formation_1A), A(kpa_01), "トゲノコx４"),
    BATTLE(A(Formation_1B), A(kpa_01), "トゲノコ,ハンマーブロス"),
    BATTLE(A(Formation_1C), A(kpa_01), "トゲノコ,ハンマーブロス,トゲノコ,ハンマーブロス"),
    BATTLE(A(Formation_1D), A(kpa_01), "トゲノコx３,カメック"),
    BATTLE(A(Formation_1E), A(kpa_01), "トゲノコx２,カメックx２"),
    BATTLE(A(Formation_20), A(kpa_01), "トゲノコ,ホネメット"),
    BATTLE(A(Formation_21), A(kpa_01), "トゲノコx２,ホネメット"),
    BATTLE(A(Formation_22), A(kpa_01), "トゲノコ,ホネメットx２"),
    BATTLE(A(Formation_23), A(kpa_01), "トゲノコ,ホネメット,トゲノコ"),
    BATTLE(A(Formation_24), A(kpa_01), "トゲノコ,カロンx２"),
    BATTLE(A(Formation_25), A(kpa_01), "トゲノコx２,カメック,くうちゅうカメック"),
    BATTLE(A(Formation_26), A(kpa_01), "トゲノコ,カメック,トゲノコ,カメック"),
    BATTLE(A(Formation_27), A(kpa_01), "カメックx２"),
    BATTLE(A(Formation_28), A(kpa_01), "カメックx３"),
    BATTLE(A(Formation_29), A(kpa_01), "カメック,くうちゅうカメックx２"),
    BATTLE(A(Formation_2A), A(kpa_01), "カメックx２,くうちゅうカメックx２"),
    BATTLE(A(Formation_2B), A(kpa_01), "カメック,トゲノコx３"),
    BATTLE(A(Formation_2C), A(kpa_01), "カメックx２,カロン"),
    BATTLE(A(Formation_2D), A(kpa_01), "カメック,ホネメット,カメック"),
    BATTLE(A(Formation_2E), A(kpa_01), "カメック,ホネメットx２,カメック"),
    BATTLE(A(Formation_2F), A(kpa_01), "カメックx２,くうちゅうカメック"),
    BATTLE(A(Formation_30), A(kpa_01), "カメック,トゲノコ,カメック,トゲノコ"),
    BATTLE(A(Formation_31), A(kpa_01), "くうちゅうカメックx２"),
    BATTLE(A(Formation_32), A(kpa_01), "くうちゅうカメックx３"),
    BATTLE(A(Formation_33), A(kpa_01), "くうちゅうカメック,カメック,くうちゅうカメック,カメック"),
    BATTLE(A(Formation_34), A(kpa_01), "くうちゅうカメック,トゲノコx２"),
    BATTLE(A(Formation_35), A(kpa_01), "くうちゅうカメック,ハンマーブロス"),
    BATTLE(A(Formation_36), A(kpa_01), "くうちゅうカメック,カロンx２"),
    BATTLE(A(Formation_37), A(kpa_01), "くうちゅうカメック,トゲノコ,くうちゅうカメック"),
    BATTLE(A(Formation_38), A(kpa_01), "くうちゅうカメック,ハンマーブロスx２,くうちゅうカメック"),
    {},
};

StageList A(Stages) = {
    STAGE("kpa_01", A(kpa_01)),
    STAGE("kpa_01b", A(kpa_01b)),
    STAGE("kpa_02", A(kpa_02)),
    STAGE("kpa_03", A(kpa_03)),
    STAGE("kpa_04", A(kpa_04)),
    STAGE("kpa_04b", A(kpa_04b)),
    STAGE("kpa_04c", A(kpa_04c)),
    STAGE("kpa_05", A(kpa_05)),
    STAGE("kpa_07", A(kpa_07)),
    STAGE("kpa_08", A(kpa_08)),
    STAGE("kpa_09", A(kpa_09)),
    STAGE("kpa_11", A(kpa_11)),
    STAGE("kpa_13", A(kpa_13)),
    STAGE("kpa_14", A(kpa_14)),
    {},
};
