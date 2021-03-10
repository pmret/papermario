#ifndef _BATTLE_BATTLE_H_
#define _BATTLE_BATTLE_H_

#include "common.h"

#define ACTOR_TYPE_red_goomba 0x00
#define ACTOR_TYPE_red_paragoomba 0x01
#define ACTOR_TYPE_gloomba 0x02
#define ACTOR_TYPE_paragloomba 0x03
#define ACTOR_TYPE_spiked_gloomba 0x04
#define ACTOR_TYPE_dark_koopa 0x05
#define ACTOR_TYPE_dark_paratroopa 0x06
#define ACTOR_TYPE_goomba 0x07
#define ACTOR_TYPE_paragoomba 0x08
#define ACTOR_TYPE_spiked_goomba 0x09
#define ACTOR_TYPE_fuzzy 0x0A
#define ACTOR_TYPE_koopa_troopa 0x0B
#define ACTOR_TYPE_paratroopa 0x0C
#define ACTOR_TYPE_bob_omb 0x0D
#define ACTOR_TYPE_bob_omb_dup 0x0E
#define ACTOR_TYPE_bullet_bill 0x0F
#define ACTOR_TYPE_bill_blaster 0x10
#define ACTOR_TYPE_cleft 0x11
#define ACTOR_TYPE_monty_mole 0x12
#define ACTOR_TYPE_bandit 0x13
#define ACTOR_TYPE_pokey 0x14
#define ACTOR_TYPE_pokey_mummy 0x15
#define ACTOR_TYPE_swooper 0x16
#define ACTOR_TYPE_buzzy_beetle 0x17
#define ACTOR_TYPE_stone_chomp 0x18
#define ACTOR_TYPE_piranha_plant 0x19
#define ACTOR_TYPE_forest_fuzzy 0x1A
#define ACTOR_TYPE_hyper_goomba 0x1B
#define ACTOR_TYPE_hyper_paragoomba 0x1C
#define ACTOR_TYPE_hyper_cleft 0x1D
#define ACTOR_TYPE_clubba 0x1E
#define ACTOR_TYPE_shy_guy 0x1F
#define ACTOR_TYPE_groove_guy 0x20
#define ACTOR_TYPE_sky_guy 0x21
#define ACTOR_TYPE_medi_guy 0x22
#define ACTOR_TYPE_pyro_guy 0x23
#define ACTOR_TYPE_spy_guy 0x24
#define ACTOR_TYPE_fuzzipede 0x25
#define ACTOR_TYPE_hurt_plant 0x26
#define ACTOR_TYPE_m_bush 0x27
#define ACTOR_TYPE_aqua_fuzzy 0x28
#define ACTOR_TYPE_jungle_fuzzy 0x29
#define ACTOR_TYPE_spear_guy 0x2A
#define ACTOR_TYPE_lava_bubble 0x2B
#define ACTOR_TYPE_spike_top 0x2C
#define ACTOR_TYPE_putrid_piranha 0x2D
#define ACTOR_TYPE_lakitu 0x2E
#define ACTOR_TYPE_spiny 0x2F
#define ACTOR_TYPE_monty_mole_boss 0x30
#define ACTOR_TYPE_bzzap 0x31
#define ACTOR_TYPE_crazee_dayzee 0x32
#define ACTOR_TYPE_amazy_dayzee 0x33
#define ACTOR_TYPE_ruff_puff 0x34
#define ACTOR_TYPE_spike 0x35
#define ACTOR_TYPE_gulpit 0x36
#define ACTOR_TYPE_gulpit_rocks 0x37
#define ACTOR_TYPE_white_clubba 0x38
#define ACTOR_TYPE_frost_piranha 0x39
#define ACTOR_TYPE_swoopula 0x3A
#define ACTOR_TYPE_duplighost 0x3B
#define ACTOR_TYPE_ghost_goombario 0x3C
#define ACTOR_TYPE_ghost_kooper 0x3D
#define ACTOR_TYPE_ghost_bombette 0x3E
#define ACTOR_TYPE_ghost_parakarry 0x3F
#define ACTOR_TYPE_ghost_bow 0x40
#define ACTOR_TYPE_ghost_watt 0x41
#define ACTOR_TYPE_ghost_sushie 0x42
#define ACTOR_TYPE_ghost_lakilester 0x43
#define ACTOR_TYPE_albino_dino 0x44
#define ACTOR_TYPE_ember 0x45
#define ACTOR_TYPE_bony_beetle 0x46
#define ACTOR_TYPE_dry_bones 0x47
#define ACTOR_TYPE_dry_bones2 0x48
#define ACTOR_TYPE_bombshell_blaster 0x49
#define ACTOR_TYPE_bombshell_bill 0x4A
#define ACTOR_TYPE_hammer_bros 0x4B
#define ACTOR_TYPE_koopatrol 0x4C
#define ACTOR_TYPE_magikoopa 0x4D
#define ACTOR_TYPE_flying_magikoopa 0x4E
#define ACTOR_TYPE_magiclone 0x4F
#define ACTOR_TYPE_flying_magiclone 0x50
#define ACTOR_TYPE_red_magikoopa 0x51
#define ACTOR_TYPE_flying_red_magikoopa 0x52
#define ACTOR_TYPE_green_magikoopa 0x53
#define ACTOR_TYPE_flying_green_magikoopa 0x54
#define ACTOR_TYPE_yellow_magikoopa 0x55
#define ACTOR_TYPE_flying_yellow_magikoopa 0x56
#define ACTOR_TYPE_gray_magikoopa 0x57
#define ACTOR_TYPE_flying_gray_magikoopa 0x58
#define ACTOR_TYPE_white_magikoopa 0x59
#define ACTOR_TYPE_flying_white_magikoopa 0x5A
#define ACTOR_TYPE_monty_hole 0x6B
#define ACTOR_TYPE_player 0x6E
#define ACTOR_TYPE_goombario 0x6F
#define ACTOR_TYPE_kooper 0x70
#define ACTOR_TYPE_bombette 0x71
#define ACTOR_TYPE_parakarry 0x72
#define ACTOR_TYPE_bow 0x73
#define ACTOR_TYPE_watt 0x74
#define ACTOR_TYPE_sushie 0x75
#define ACTOR_TYPE_lakilester 0x76
#define ACTOR_TYPE_twink 0x77
#define ACTOR_TYPE_the_master_1 0x7A
#define ACTOR_TYPE_the_master_2 0x7B
#define ACTOR_TYPE_the_master_3 0x7C
#define ACTOR_TYPE_chan 0x7D
#define ACTOR_TYPE_lee 0x7E
#define ACTOR_TYPE_lee_goombario 0x7F
#define ACTOR_TYPE_lee_kooper 0x80
#define ACTOR_TYPE_lee_bombette 0x81
#define ACTOR_TYPE_lee_parakarry 0x82
#define ACTOR_TYPE_lee_bow 0x83
#define ACTOR_TYPE_lee_watt 0x84
#define ACTOR_TYPE_lee_sushie 0x85
#define ACTOR_TYPE_lee_lakilester 0x86
#define ACTOR_TYPE_kammy_koopa 0x87
#define ACTOR_TYPE_jr_troopa1 0x88
#define ACTOR_TYPE_jr_troopa2 0x89
#define ACTOR_TYPE_jr_troopa3 0x8A
#define ACTOR_TYPE_jr_troopa4 0x8B
#define ACTOR_TYPE_jr_troopa5 0x8C
#define ACTOR_TYPE_jr_troopa6 0x8D
#define ACTOR_TYPE_jr_troopa_dup1 0x8E
#define ACTOR_TYPE_jr_troopa_dup2 0x8F
#define ACTOR_TYPE_blue_goomba_boss 0x90
#define ACTOR_TYPE_red_goomba_boss 0x91
#define ACTOR_TYPE_goomba_king 0x92
#define ACTOR_TYPE_goomnut_tree 0x93
#define ACTOR_TYPE_goombario_tutor1 0x94
#define ACTOR_TYPE_magikoopa_boss 0x95
#define ACTOR_TYPE_flying_magikoopa_boss 0x96
#define ACTOR_TYPE_magikoopa_dup1 0x97
#define ACTOR_TYPE_magikoopa_dup2 0x98
#define ACTOR_TYPE_fake_bowser 0x99
#define ACTOR_TYPE_koopa_bros 0x9A
#define ACTOR_TYPE_green_ninjakoopa 0x9B
#define ACTOR_TYPE_red_ninjakoopa 0x9C
#define ACTOR_TYPE_blue_ninjakoopa 0x9D
#define ACTOR_TYPE_yellow_ninjakoopa 0x9E
#define ACTOR_TYPE_goombario_tutor2 0x9F
#define ACTOR_TYPE_buzzar 0xA0
#define ACTOR_TYPE_tutankoopa 0xA1
#define ACTOR_TYPE_chomp 0xA2
#define ACTOR_TYPE_tubba_blubba_invincible 0xA3
#define ACTOR_TYPE_tubba_blubba 0xA4
#define ACTOR_TYPE_tubba_heart 0xA5
#define ACTOR_TYPE_stilt_guy 0xA6
#define ACTOR_TYPE_shy_stack 0xA7
#define ACTOR_TYPE_shy_squad 0xA8
#define ACTOR_TYPE_general_guy 0xA9
#define ACTOR_TYPE_toy_tank 0xAA
#define ACTOR_TYPE_light_bulb 0xAB
#define ACTOR_TYPE_signal_guy 0xAC
#define ACTOR_TYPE_shy_squad_dup 0xAD
#define ACTOR_TYPE_shy_guy_dup 0xAE
#define ACTOR_TYPE_anti_guy 0xAF
#define ACTOR_TYPE_anti_guy_dup 0xB0
#define ACTOR_TYPE_big_lantern_ghost 0xB1
#define ACTOR_TYPE_goomba_king_dup 0xB2
#define ACTOR_TYPE_lava_piranha_phase_1 0xB3
#define ACTOR_TYPE_lava_piranha_phase_2 0xB4
#define ACTOR_TYPE_lava_bud_phase_1 0xB5
#define ACTOR_TYPE_lava_bud_phase_2 0xB6
#define ACTOR_TYPE_petit_piranha 0xB7
#define ACTOR_TYPE_petit_piranha_bomb 0xB8
#define ACTOR_TYPE_kent_c_koopa 0xB9
#define ACTOR_TYPE_huff_n_puff 0xBA
#define ACTOR_TYPE_tuff_puff 0xBB
#define ACTOR_TYPE_monstar 0xBC
#define ACTOR_TYPE_crystal_king 0xBD
#define ACTOR_TYPE_crystal_clone 0xBE
#define ACTOR_TYPE_crystal_bit 0xBF
#define ACTOR_TYPE_intro_bowser 0xC0
#define ACTOR_TYPE_bowser_phase_1 0xC1
#define ACTOR_TYPE_bowser_dup1 0xC2
#define ACTOR_TYPE_bowser_phase_2 0xC3
#define ACTOR_TYPE_bowser_dup2 0xC4
#define ACTOR_TYPE_bowser_phase_3 0xC5
#define ACTOR_TYPE_bowser_dup3 0xC6
#define ACTOR_TYPE_blooper 0xC7
#define ACTOR_TYPE_electro_blooper1 0xC8
#define ACTOR_TYPE_electro_blooper2 0xC9
#define ACTOR_TYPE_super_blooper1 0xCA
#define ACTOR_TYPE_super_blooper2 0xCB
#define ACTOR_TYPE_blooper_baby 0xCC
#define ACTOR_TYPE_lakilester_dup 0xCD
#define ACTOR_TYPE_slot_machine_start 0xCE
#define ACTOR_TYPE_slot_machine_stop 0xCF
#define ACTOR_TYPE_whacka 0xD0
#define ACTOR_TYPE_slot_machine_start_dup1 0xD1
#define ACTOR_TYPE_slot_machine_start_dup2 0xD2
#define ACTOR_TYPE_slot_machine_start_dup3 0xD3
#define ACTOR_TYPE_COUNT 0xD4

typedef struct ActorDesc {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 type;
    /* 0x06 */ u8 level;
    /* 0x07 */ u8 maxHP;
    /* 0x08 */ s16 partCount;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ struct ActorPartDesc** partsData;
    /* 0x10 */ Bytecode* script;
    /* 0x14 */ s32* statusTable;
    /* 0x18 */ u8 escapeChance;
    /* 0x19 */ u8 airLiftChance;
    /* 0x1A */ u8 spookChance;
    /* 0x1B */ u8 baseStatusChance;
    /* 0x1C */ u8 upAndAwayChance;
    /* 0x1D */ u8 spinSmashReq;
    /* 0x1E */ u8 powerBounceChance;
    /* 0x1F */ u8 coinReward;
    /* 0x20 */ Vec2b size;
    /* 0x22 */ Vec2b hpBarOffset;
    /* 0x24 */ Vec2b statusIconOffset;
    /* 0x26 */ Vec2b statusMessageOffset;
} ActorDesc; // size = 0x28

typedef struct Stage {
    /* 0x00 */ const char* texture;
    /* 0x04 */ const char* shape;
    /* 0x08 */ const char* hit;
    /* 0x0C */ Bytecode* preBattle;
    /* 0x10 */ Bytecode* postBattle;
    /* 0x14 */ const char* bg;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
} Stage; // size = 0x28

/// Zero-terminated.
typedef struct StageListRow {
    /* 0x00 */ const char* id; ///< Map ID.
    /* 0x04 */ Stage* stage;
} StageList[]; // size = 0x08 * n

typedef struct FormationRow {
    /* 0x00 */ ActorDesc* actor;
    /* 0x04 */ s32 position; ///< Home position. May also be a `Vector3*`.
    /* 0x08 */ s32 priority; ///< Actors with higher priority values take their turn first.
    /* 0x0C */ s32 var0;
    /* 0x10 */ s32 var1;
    /* 0x14 */ s32 var2;
    /* 0x18 */ s32 var3;
} Formation[]; // size = 0x1C * n

/// Zero-terminated.
typedef struct Battle {
    /* 0x00 */ const char* name; ///< Debug SJIS name.
    /* 0x04 */ s32 formationSize;
    /* 0x08 */ Formation* formation;
    /* 0x0C */ Stage* stage;
    /* 0x10 */ s32 unk_10;
} BattleList[]; // size = 0x14 * n

#define BATTLE(name, formation, stage) { name, ARRAY_COUNT(formation), formation, stage }

// TODO: enum for home position (0..3 are floor, 4..7 are air, etc.)

typedef struct {
    Element element;
    s32 defense;
} DefenseTableEntry;

typedef DefenseTableEntry DefenseTable[];

typedef struct ActorPartDesc {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s8 index;
    /* 0x05 */ Vec3b posOffset;
    /* 0x08 */ Vec2b targetOffset;
    /* 0x0A */ s16 opacity;
    /* 0x0C */ s32* idleAnimations;
    /* 0x10 */ s32* defenseTable;
    /* 0x14 */ s32 eventFlags;
    /* 0x18 */ s32 elementImmunityFlags;
    /* 0x1C */ char unk_1C[8];
} ActorPartDesc; // size = 0x24

typedef struct ActorSounds {
    /* 0x00 */ SoundID walk[2];
    /* 0x08 */ SoundID fly[2];
    /* 0x10 */ SoundID jump;
    /* 0x14 */ SoundID hurt;
    /* 0x18 */ s16 delay[2]; ///< Number of frames to wait between walk/fly sounds. Negative values are in distance.
} ActorSounds; // size = 0x20

typedef struct ActorOffsets {
    /* 0x00 */ Vec3b tattleCam;
    /* 0x03 */ s8 shadow;
} ActorOffsets; // size = 0x04

#endif
