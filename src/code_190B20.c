#include "common.h"
#include "battle/battle.h"
#include "message_ids.h"

s32 D_80280FC0[] = {
    0x000A005A, 0x00000032, 0x0003000B, 0x00000032, 0x0001002D, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x00010031, 0x00000032, 0x00010031, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x00010032, 0x00000032, 0x00010032, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x0003000A, 0x00000032, 0x0003000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000050, 0x0003000A, 0x00000014, 0x0003000B, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

MessageID bActorNames[ACTOR_TYPE_COUNT] = {
    /* 0x00 */ MSG_actor_red_goomba,
    /* 0x01 */ MSG_actor_red_paragoomba,
    /* 0x02 */ MSG_actor_gloomba,
    /* 0x03 */ MSG_actor_paragloomba,
    /* 0x04 */ MSG_actor_spiked_gloomba,
    /* 0x05 */ MSG_actor_dark_koopa,
    /* 0x06 */ MSG_actor_dark_paratroopa,
    /* 0x07 */ MSG_actor_goomba,
    /* 0x08 */ MSG_actor_paragoomba,
    /* 0x09 */ MSG_actor_spiked_goomba,
    /* 0x0A */ MSG_actor_fuzzy,
    /* 0x0B */ MSG_actor_koopa_troopa,
    /* 0x0C */ MSG_actor_paratroopa,
    /* 0x0D */ MSG_actor_bob_omb,
    /* 0x0E */ MSG_actor_bob_omb,
    /* 0x0F */ MSG_actor_bullet_bill,
    /* 0x10 */ MSG_actor_bill_blaster,
    /* 0x11 */ MSG_actor_cleft,
    /* 0x12 */ MSG_actor_monty_mole,
    /* 0x13 */ MSG_actor_bandit,
    /* 0x14 */ MSG_actor_pokey,
    /* 0x15 */ MSG_actor_pokey_mummy,
    /* 0x16 */ MSG_actor_swooper,
    /* 0x17 */ MSG_actor_buzzy_beetle,
    /* 0x18 */ MSG_actor_stone_chomp,
    /* 0x19 */ MSG_actor_piranha_plant,
    /* 0x1A */ MSG_actor_forest_fuzzy,
    /* 0x1B */ MSG_actor_hyper_goomba,
    /* 0x1C */ MSG_actor_hyper_paragoomba,
    /* 0x1D */ MSG_actor_hyper_cleft,
    /* 0x1E */ MSG_actor_clubba,
    /* 0x1F */ MSG_actor_shy_guy,
    /* 0x20 */ MSG_actor_groove_guy,
    /* 0x21 */ MSG_actor_sky_guy,
    /* 0x22 */ MSG_actor_medi_guy,
    /* 0x23 */ MSG_actor_pyro_guy,
    /* 0x24 */ MSG_actor_spy_guy,
    /* 0x25 */ MSG_actor_fuzzipede,
    /* 0x26 */ MSG_actor_hurt_plant,
    /* 0x27 */ MSG_actor_m_bush,
    /* 0x28 */ MSG_actor_aqua_fuzzy,
    /* 0x29 */ MSG_actor_jungle_fuzzy,
    /* 0x2A */ MSG_actor_spear_guy,
    /* 0x2B */ MSG_actor_lava_bubble,
    /* 0x2C */ MSG_actor_spike_top,
    /* 0x2D */ MSG_actor_putrid_piranha,
    /* 0x2E */ MSG_actor_lakitu,
    /* 0x2F */ MSG_actor_spiny,
    /* 0x30 */ MSG_actor_monty_mole_boss,
    /* 0x31 */ MSG_actor_bzzap,
    /* 0x32 */ MSG_actor_crazee_dayzee,
    /* 0x33 */ MSG_actor_amazy_dayzee,
    /* 0x34 */ MSG_actor_ruff_puff,
    /* 0x35 */ MSG_actor_spike,
    /* 0x36 */ MSG_actor_gulpit,
    /* 0x37 */ MSG_actor_gulpit_rocks,
    /* 0x38 */ MSG_actor_white_clubba,
    /* 0x39 */ MSG_actor_frost_piranha,
    /* 0x3A */ MSG_actor_swoopula,
    /* 0x3B */ MSG_actor_duplighost,
    /* 0x3C */ MSG_actor_ghost_goombario,
    /* 0x3D */ MSG_actor_ghost_kooper,
    /* 0x3E */ MSG_actor_ghost_bombette,
    /* 0x3F */ MSG_actor_ghost_parakarry,
    /* 0x40 */ MSG_actor_ghost_bow,
    /* 0x41 */ MSG_actor_ghost_watt,
    /* 0x42 */ MSG_actor_ghost_sushie,
    /* 0x43 */ MSG_actor_ghost_lakilester,
    /* 0x44 */ MSG_actor_albino_dino,
    /* 0x45 */ MSG_actor_ember,
    /* 0x46 */ MSG_actor_bony_beetle,
    /* 0x47 */ MSG_actor_dry_bones,
    /* 0x48 */ MSG_actor_dry_bones,
    /* 0x49 */ MSG_actor_bombshell_blaster,
    /* 0x4A */ MSG_actor_bombshell_bill,
    /* 0x4B */ MSG_actor_hammer_bros,
    /* 0x4C */ MSG_actor_koopatrol,
    /* 0x4D */ MSG_actor_magikoopa,
    /* 0x4E */ MSG_actor_magikoopa,
    /* 0x4F */ MSG_actor_magikoopa,
    /* 0x50 */ MSG_actor_magikoopa,
    /* 0x51 */ MSG_actor_red_magikoopa,
    /* 0x52 */ MSG_actor_red_magikoopa,
    /* 0x53 */ MSG_actor_green_magikoopa,
    /* 0x54 */ MSG_actor_green_magikoopa,
    /* 0x55 */ MSG_actor_yellow_magikoopa,
    /* 0x56 */ MSG_actor_yellow_magikoopa,
    /* 0x57 */ MSG_actor_gray_magikoopa,
    /* 0x58 */ MSG_actor_gray_magikoopa,
    /* 0x59 */ MSG_actor_white_magikoopa,
    /* 0x5A */ MSG_actor_white_magikoopa,
    /* 0x5B */ MSG_actor_the_master,
    /* 0x5C */ MSG_actor_the_master,
    /* 0x5D */ MSG_actor_the_master,
    /* 0x5E */ MSG_actor_the_master,
    /* 0x5F */ MSG_actor_the_master,
    /* 0x60 */ MSG_actor_the_master,
    /* 0x61 */ MSG_actor_the_master,
    /* 0x62 */ MSG_actor_the_master,
    /* 0x63 */ MSG_actor_the_master,
    /* 0x64 */ MSG_actor_the_master,
    /* 0x65 */ MSG_actor_the_master,
    /* 0x66 */ MSG_actor_the_master,
    /* 0x67 */ MSG_actor_the_master,
    /* 0x68 */ MSG_actor_the_master,
    /* 0x69 */ MSG_actor_the_master,
    /* 0x6A */ MSG_actor_the_master,
    /* 0x6B */ MSG_actor_the_master,
    /* 0x6C */ MSG_actor_the_master,
    /* 0x6D */ MSG_actor_the_master,
    /* 0x6E */ MSG_actor_the_master,
    /* 0x6F */ MSG_actor_the_master,
    /* 0x70 */ MSG_actor_the_master,
    /* 0x71 */ MSG_actor_the_master,
    /* 0x72 */ MSG_actor_the_master,
    /* 0x73 */ MSG_actor_the_master,
    /* 0x74 */ MSG_actor_the_master,
    /* 0x75 */ MSG_actor_the_master,
    /* 0x76 */ MSG_actor_the_master,
    /* 0x77 */ MSG_party_twink,
    /* 0x78 */ MSG_actor_the_master,
    /* 0x79 */ MSG_actor_the_master,
    /* 0x7A */ MSG_actor_the_master,
    /* 0x7B */ MSG_actor_the_master,
    /* 0x7C */ MSG_actor_the_master,
    /* 0x7D */ MSG_actor_chan,
    /* 0x7E */ MSG_actor_lee,
    /* 0x7F */ MSG_party_goombario,
    /* 0x80 */ MSG_party_kooper,
    /* 0x81 */ MSG_party_bombette,
    /* 0x82 */ MSG_party_parakarry,
    /* 0x83 */ MSG_party_bow,
    /* 0x84 */ MSG_party_watt,
    /* 0x85 */ MSG_party_sushie,
    /* 0x86 */ MSG_party_lakilester,
    /* 0x87 */ MSG_actor_kammy_koopa,
    /* 0x88 */ MSG_actor_jr_troopa,
    /* 0x89 */ MSG_actor_jr_troopa,
    /* 0x8A */ MSG_actor_jr_troopa,
    /* 0x8B */ MSG_actor_jr_troopa,
    /* 0x8C */ MSG_actor_jr_troopa,
    /* 0x8D */ MSG_actor_jr_troopa,
    /* 0x8E */ MSG_actor_jr_troopa,
    /* 0x8F */ MSG_actor_jr_troopa,
    /* 0x90 */ MSG_actor_blue_goomba_boss,
    /* 0x91 */ MSG_actor_red_goomba_boss,
    /* 0x92 */ MSG_actor_goomba_king,
    /* 0x93 */ MSG_actor_goomnut_tree,
    /* 0x94 */ MSG_party_goombario,
    /* 0x95 */ MSG_actor_magikoopa,
    /* 0x96 */ MSG_actor_magikoopa,
    /* 0x97 */ MSG_actor_magikoopa,
    /* 0x98 */ MSG_actor_magikoopa,
    /* 0x99 */ MSG_actor_fake_bowser,
    /* 0x9A */ MSG_actor_koopa_bros,
    /* 0x9B */ MSG_actor_green_ninjakoopa,
    /* 0x9C */ MSG_actor_red_ninjakoopa,
    /* 0x9D */ MSG_actor_blue_ninjakoopa,
    /* 0x9E */ MSG_actor_yellow_ninjakoopa,
    /* 0x9F */ MSG_party_goombario,
    /* 0xA0 */ MSG_actor_buzzar,
    /* 0xA1 */ MSG_actor_tutankoopa,
    /* 0xA2 */ MSG_actor_chomp,
    /* 0xA3 */ MSG_actor_tubba_blubba,
    /* 0xA4 */ MSG_actor_tubba_blubba,
    /* 0xA5 */ MSG_actor_tubba_heart,
    /* 0xA6 */ MSG_actor_stilt_guy,
    /* 0xA7 */ MSG_actor_shy_stack,
    /* 0xA8 */ MSG_actor_shy_squad,
    /* 0xA9 */ MSG_actor_general_guy_dup,
    /* 0xAA */ MSG_actor_general_guy,
    /* 0xAB */ MSG_actor_bulb,
    /* 0xAC */ MSG_actor_shy_guy,
    /* 0xAD */ MSG_actor_shy_squad_dup,
    /* 0xAE */ MSG_actor_shy_guy,
    /* 0xAF */ MSG_actor_anti_guy,
    /* 0xB0 */ MSG_actor_anti_guy,
    /* 0xB1 */ MSG_actor_big_lantern_ghost,
    /* 0xB2 */ MSG_actor_goomba_king,
    /* 0xB3 */ MSG_actor_lava_piranha,
    /* 0xB4 */ MSG_actor_lava_piranha,
    /* 0xB5 */ MSG_actor_lava_bud,
    /* 0xB6 */ MSG_actor_lava_bud,
    /* 0xB7 */ MSG_actor_petit_piranha,
    /* 0xB8 */ MSG_actor_lava_piranha,
    /* 0xB9 */ MSG_actor_kent_c_koopa,
    /* 0xBA */ MSG_actor_huff_n_puff,
    /* 0xBB */ MSG_actor_tuff_puff,
    /* 0xBC */ MSG_actor_monstar,
    /* 0xBD */ MSG_actor_crystal_king,
    /* 0xBE */ MSG_actor_crystal_king,
    /* 0xBF */ MSG_actor_crystal_bit,
    /* 0xC0 */ MSG_actor_bowser,
    /* 0xC1 */ MSG_actor_bowser,
    /* 0xC2 */ MSG_actor_bowser,
    /* 0xC3 */ MSG_actor_bowser,
    /* 0xC4 */ MSG_actor_bowser,
    /* 0xC5 */ MSG_actor_bowser,
    /* 0xC6 */ MSG_actor_bowser,
    /* 0xC7 */ MSG_actor_blooper,
    /* 0xC8 */ MSG_actor_electro_blooper,
    /* 0xC9 */ MSG_actor_electro_blooper,
    /* 0xCA */ MSG_actor_super_blooper,
    /* 0xCB */ MSG_actor_super_blooper,
    /* 0xCC */ MSG_actor_blooper_baby,
    /* 0xCD */ MSG_actor_ghost_lakilester,
    /* 0xCE */ MSG_actor_slot_machine_start,
    /* 0xCF */ MSG_actor_slot_machine_stop,
    /* 0xD0 */ MSG_actor_whacka,
    /* 0xD1 */ MSG_actor_slot_machine_start,
    /* 0xD2 */ MSG_actor_slot_machine_start,
    /* 0xD3 */ MSG_actor_slot_machine_start,
};

s32 D_80281454[] = { 0x78, 0x93, 0x99, 0xB2, -1 };

ActorSounds bActorSoundTable[ACTOR_TYPE_COUNT] = {
    /* 0x00 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x01 */ { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x02 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x03 */ { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x04 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x05 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x06 */ { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x07 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x08 */ { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x09 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x0A */ { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x0B */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x0C */ { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x0D */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x0E */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x0F */ { .walk = { 0x02C9, 0x02C9 }, .fly = { 0x02C9, 0x02C9 }, .jump = 0x02C9, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x10 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x11 */ { .walk = { 0x20D0, 0x20D0 }, .fly = { 0x20D0, 0x20D0 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x12 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x13 */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x20C1, 0x20C1 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x14 */ { .walk = { 0x0343, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x15 */ { .walk = { 0x0343, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x16 */ { .walk = { 0x0351, 0x0351 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x17 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x18 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x19 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x1A */ { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x1B */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x1C */ { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x1D */ { .walk = { 0x20D0, 0x20D0 }, .fly = { 0x20D0, 0x20D0 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x1E */ { .walk = { 0x20C4, 0x20C4 }, .fly = { 0x20C4, 0x20C4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x1F */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x20 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x21 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x22 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0380, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x23 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x24 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x25 */ { .walk = { 0x20D9, 0x20D9 }, .fly = { 0x20D9, 0x20D9 }, .jump = 0x20D9, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x26 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x27 */ { .walk = { 0x20C6, 0x20C6 }, .fly = { 0x20C6, 0x20C6 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x28 */ { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x29 */ { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x2A */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x2B */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x2C */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x2D */ { .walk = { 0x03CE, 0x03CE }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x2E */ { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    /* 0x2F */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x30 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x31 */ { .walk = { 0x0357, 0x0000 }, .fly = { 0x0357, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x32 */ { .walk = { 0x02D6, 0x02D6 }, .fly = { 0x02D6, 0x02D6 }, .jump = 0x02D5, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x33 */ { .walk = { 0x02D6, 0x02D6 }, .fly = { 0x02D6, 0x02D6 }, .jump = 0x02D5, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x34 */ { .walk = { 0x0295, 0x0000 }, .fly = { 0x0295, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x35 */ { .walk = { 0x0295, 0x0000 }, .fly = { 0x0295, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x36 */ { .walk = { 0x20C4, 0x20C4 }, .fly = { 0x20C4, 0x20C4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x37 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x38 */ { .walk = { 0x20C4, 0x20C4 }, .fly = { 0x20C4, 0x20C4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x39 */ { .walk = { 0x03CE, 0x03CE }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x3A */ { .walk = { 0x0351, 0x0351 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x3B */ { .walk = { 0x02CA, 0x02CA }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x3C */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x3D */ { .walk = { 0x0100, 0x0100 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x3E */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x3F */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x40 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x41 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x42 */ { .walk = { 0x029A, 0x029A }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x43 */ { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    /* 0x44 */ { .walk = { 0x030B, 0x02FD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x45 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x46 */ { .walk = { 0x20CD, 0x20CD }, .fly = { 0x20CD, 0x20CD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x47 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x48 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x49 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x4A */ { .walk = { 0x02C9, 0x02C9 }, .fly = { 0x02C9, 0x02C9 }, .jump = 0x02C9, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x4B */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x4C */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x4D */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x4E */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x4F */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x50 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x51 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x52 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x53 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x54 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x55 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x56 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x57 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x58 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x59 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x5A */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x5B */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x5C */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x5D */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x5E */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x5F */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x60 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x61 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x62 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x63 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x64 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x65 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x66 */ { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    /* 0x67 */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x68 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x69 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x6A */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x6B */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x6C */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x6D */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x6E */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x6F */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x70 */ { .walk = { 0x0100, 0x0100 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x71 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x72 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x73 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x74 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x75 */ { .walk = { 0x029A, 0x029A }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x76 */ { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    /* 0x77 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { -5, -5 } },
    /* 0x78 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x79 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x7A */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x7B */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x7C */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x7D */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x7E */ { .walk = { 0x02CA, 0x02CA }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x7F */ { .walk = { 0x20DD, 0x20DD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x80 */ { .walk = { 0x0100, 0x0100 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x81 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x82 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x83 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x84 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x85 */ { .walk = { 0x029A, 0x029A }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x86 */ { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    /* 0x87 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x88 */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x89 */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x8A */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x8B */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x8C */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x8D */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x8E */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x8F */ { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x90 */ { .walk = { 0x03AC, 0x03AC }, .fly = { 0x0000, 0x0000 }, .jump = 0x010F, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x91 */ { .walk = { 0x03AC, 0x03AC }, .fly = { 0x0000, 0x0000 }, .jump = 0x010F, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x92 */ { .walk = { 0x20EC, 0x20EC }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 22, 30 } },
    /* 0x93 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x94 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x95 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x96 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x97 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x98 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0x99 */ { .walk = { 0x03EA, 0x03EA }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x9A */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x9B */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x9C */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x9D */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x9E */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0x9F */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xA0 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x20EF, 0x20EF }, .jump = 0x0000, .hurt = 0x0000, .delay = { -14, -14 } },
    /* 0xA1 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { -3, -3 } },
    /* 0xA2 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xA3 */ { .walk = { 0x20F6, 0x20F6 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xA4 */ { .walk = { 0x20F6, 0x20F6 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xA5 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x20C8, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xA6 */ { .walk = { 0x2066, 0x2066 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xA7 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 10, 10 } },
    /* 0xA8 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xA9 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xAA */ { .walk = { 0x037E, 0x037E }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xAB */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xAC */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xAD */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xAE */ { .walk = { 0x20BA, 0x20BA }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xAF */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xB0 */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xB1 */ { .walk = { 0x037D, 0x037D }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB2 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB3 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB4 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB5 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB6 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB7 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB8 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xB9 */ { .walk = { 0x20EC, 0x20EC }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xBA */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x03D1, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xBB */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xBC */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xBD */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xBE */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xBF */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC0 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC1 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC2 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC3 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC4 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC5 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC6 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xC7 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    /* 0xC8 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    /* 0xC9 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    /* 0xCA */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    /* 0xCB */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    /* 0xCC */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xCD */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xCE */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xCF */ { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    /* 0xD0 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xD1 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xD2 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    /* 0xD3 */ { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
};

MessageID bActorTattles[ACTOR_TYPE_COUNT] = {
    /* 0x00 */ NULL,
    /* 0x01 */ NULL,
    /* 0x02 */ MSG_actor_gloomba_tattle,
    /* 0x03 */ MSG_actor_paragloomba_tattle,
    /* 0x04 */ MSG_actor_spiked_gloomba_tattle,
    /* 0x05 */ MSG_actor_dark_koopa_tattle,
    /* 0x06 */ MSG_actor_dark_paratroopa_tattle,
    /* 0x07 */ MSG_actor_goomba_tattle,
    /* 0x08 */ MSG_actor_paragoomba_tattle,
    /* 0x09 */ MSG_actor_spiked_goomba_tattle,
    /* 0x0A */ MSG_actor_fuzzy_tattle,
    /* 0x0B */ MSG_actor_koopa_troopa_tattle,
    /* 0x0C */ MSG_actor_paratroopa_tattle,
    /* 0x0D */ MSG_actor_bob_omb_tattle,
    /* 0x0E */ MSG_actor_bob_omb_tattle,
    /* 0x0F */ MSG_actor_bullet_bill_tattle,
    /* 0x10 */ MSG_actor_bill_blaster_tattle,
    /* 0x11 */ MSG_actor_cleft_tattle,
    /* 0x12 */ MSG_actor_monty_mole_tattle,
    /* 0x13 */ MSG_actor_bandit_tattle,
    /* 0x14 */ MSG_actor_pokey_tattle,
    /* 0x15 */ MSG_actor_pokey_mummy_tattle,
    /* 0x16 */ MSG_actor_swooper_tattle,
    /* 0x17 */ MSG_actor_buzzy_beetle_tattle,
    /* 0x18 */ MSG_actor_stone_chomp_tattle,
    /* 0x19 */ MSG_actor_piranha_plant_tattle,
    /* 0x1A */ MSG_actor_forest_fuzzy_tattle,
    /* 0x1B */ MSG_actor_hyper_goomba_tattle,
    /* 0x1C */ MSG_actor_hyper_paragoomba_tattle,
    /* 0x1D */ MSG_actor_hyper_cleft_tattle,
    /* 0x1E */ MSG_actor_clubba_tattle,
    /* 0x1F */ MSG_actor_shy_guy_tattle,
    /* 0x20 */ MSG_actor_groove_guy_tattle,
    /* 0x21 */ MSG_actor_sky_guy_tattle,
    /* 0x22 */ MSG_actor_medi_guy_tattle,
    /* 0x23 */ MSG_actor_pyro_guy_tattle,
    /* 0x24 */ MSG_actor_spy_guy_tattle,
    /* 0x25 */ NULL,
    /* 0x26 */ MSG_actor_hurt_plant_tattle,
    /* 0x27 */ MSG_actor_m_bush_tattle,
    /* 0x28 */ NULL,
    /* 0x29 */ MSG_actor_jungle_fuzzy_tattle,
    /* 0x2A */ MSG_actor_spear_guy_tattle,
    /* 0x2B */ MSG_actor_lava_bubble_tattle,
    /* 0x2C */ MSG_actor_spike_top_tattle,
    /* 0x2D */ MSG_actor_putrid_piranha_tattle,
    /* 0x2E */ MSG_actor_lakitu_tattle,
    /* 0x2F */ MSG_actor_spiny_tattle,
    /* 0x30 */ MSG_actor_monty_mole_boss_tattle,
    /* 0x31 */ MSG_actor_bzzap_tattle,
    /* 0x32 */ MSG_actor_crazee_dayzee_tattle,
    /* 0x33 */ MSG_actor_amazy_dayzee_tattle,
    /* 0x34 */ MSG_actor_ruff_puff_tattle,
    /* 0x35 */ MSG_actor_spike_tattle,
    /* 0x36 */ MSG_actor_gulpit_tattle,
    /* 0x37 */ MSG_actor_gulpit_rocks_tattle,
    /* 0x38 */ MSG_actor_white_clubba_tattle,
    /* 0x39 */ MSG_actor_frost_piranha_tattle,
    /* 0x3A */ MSG_actor_swoopula_tattle,
    /* 0x3B */ MSG_actor_duplighost_tattle,
    /* 0x3C */ MSG_actor_ghost_goombario_tattle,
    /* 0x3D */ MSG_actor_ghost_kooper_tattle,
    /* 0x3E */ MSG_actor_ghost_bombette_tattle,
    /* 0x3F */ MSG_actor_ghost_parakarry_tattle,
    /* 0x40 */ MSG_actor_ghost_bow_tattle,
    /* 0x41 */ MSG_actor_ghost_watt_tattle,
    /* 0x42 */ MSG_actor_ghost_sushie_tattle,
    /* 0x43 */ MSG_actor_ghost_lakilester_tattle,
    /* 0x44 */ MSG_actor_albino_dino_tattle,
    /* 0x45 */ MSG_actor_ember_tattle,
    /* 0x46 */ MSG_actor_bony_beetle_tattle,
    /* 0x47 */ MSG_actor_dry_bones_tattle,
    /* 0x48 */ MSG_actor_dry_bones_tattle,
    /* 0x49 */ MSG_actor_bombshell_blaster_tattle,
    /* 0x4A */ MSG_actor_bombshell_bill_tattle,
    /* 0x4B */ MSG_actor_hammer_bros_tattle,
    /* 0x4C */ MSG_actor_koopatrol_tattle,
    /* 0x4D */ MSG_actor_magikoopa_tattle,
    /* 0x4E */ MSG_actor_magikoopa_dup_tattle,
    /* 0x4F */ MSG_actor_magiclone_tattle,
    /* 0x50 */ MSG_actor_magiclone_dup_tattle,
    /* 0x51 */ MSG_actor_red_magikoopa_tattle,
    /* 0x52 */ MSG_actor_flying_red_magikoopa_tattle,
    /* 0x53 */ MSG_actor_green_magikoopa_tattle,
    /* 0x54 */ MSG_actor_flying_green_magikoopa_tattle,
    /* 0x55 */ MSG_actor_yellow_magikoopa_tattle,
    /* 0x56 */ MSG_actor_flying_yellow_magikoopa_tattle,
    /* 0x57 */ MSG_actor_gray_magikoopa_tattle,
    /* 0x58 */ MSG_actor_flying_gray_magikoopa_tattle,
    /* 0x59 */ MSG_actor_flying_white_magikoopa_tattle,
    /* 0x5A */ MSG_actor_white_magikoopa_tattle,
    /* 0x5B */ MSG_actor_the_master_1_tattle,
    /* 0x5C */ MSG_actor_the_master_1_tattle,
    /* 0x5D */ MSG_actor_the_master_1_tattle,
    /* 0x5E */ MSG_actor_the_master_1_tattle,
    /* 0x5F */ MSG_actor_the_master_1_tattle,
    /* 0x60 */ MSG_actor_the_master_1_tattle,
    /* 0x61 */ MSG_actor_the_master_1_tattle,
    /* 0x62 */ MSG_actor_the_master_1_tattle,
    /* 0x63 */ MSG_actor_the_master_1_tattle,
    /* 0x64 */ MSG_actor_the_master_1_tattle,
    /* 0x65 */ MSG_actor_the_master_1_tattle,
    /* 0x66 */ MSG_actor_the_master_1_tattle,
    /* 0x67 */ MSG_actor_the_master_1_tattle,
    /* 0x68 */ MSG_actor_the_master_1_tattle,
    /* 0x69 */ MSG_actor_the_master_1_tattle,
    /* 0x6A */ MSG_actor_the_master_1_tattle,
    /* 0x6B */ MSG_actor_the_master_1_tattle,
    /* 0x6C */ MSG_actor_the_master_1_tattle,
    /* 0x6D */ MSG_actor_the_master_1_tattle,
    /* 0x6E */ MSG_actor_the_master_1_tattle,
    /* 0x6F */ MSG_actor_the_master_1_tattle,
    /* 0x70 */ MSG_actor_the_master_1_tattle,
    /* 0x71 */ MSG_actor_the_master_1_tattle,
    /* 0x72 */ MSG_actor_the_master_1_tattle,
    /* 0x73 */ MSG_actor_the_master_1_tattle,
    /* 0x74 */ MSG_actor_the_master_1_tattle,
    /* 0x75 */ MSG_actor_the_master_1_tattle,
    /* 0x76 */ MSG_actor_the_master_1_tattle,
    /* 0x77 */ NULL,
    /* 0x78 */ MSG_actor_the_master_1_tattle,
    /* 0x79 */ MSG_actor_the_master_1_tattle,
    /* 0x7A */ MSG_actor_the_master_1_tattle,
    /* 0x7B */ MSG_actor_the_master_2_tattle,
    /* 0x7C */ MSG_actor_the_master_3_tattle,
    /* 0x7D */ MSG_actor_chan_tattle,
    /* 0x7E */ MSG_actor_lee_tattle,
    /* 0x7F */ MSG_actor_lee_goombario_tattle,
    /* 0x80 */ MSG_actor_lee_kooper_tattle,
    /* 0x81 */ MSG_actor_lee_bombette_tattle,
    /* 0x82 */ MSG_actor_lee_parakarry_tattle,
    /* 0x83 */ MSG_actor_lee_bow_tattle,
    /* 0x84 */ MSG_actor_lee_watt_tattle,
    /* 0x85 */ MSG_actor_lee_sushie_tattle,
    /* 0x86 */ MSG_actor_lee_lakilester_tattle,
    /* 0x87 */ NULL,
    /* 0x88 */ NULL,
    /* 0x89 */ MSG_actor_jr_troopa1_tattle,
    /* 0x8A */ MSG_actor_jr_troopa2_tattle,
    /* 0x8B */ MSG_actor_jr_troopa3_tattle,
    /* 0x8C */ MSG_actor_jr_troopa4_tattle,
    /* 0x8D */ MSG_actor_jr_troopa5_tattle,
    /* 0x8E */ MSG_actor_jr_troopa5_tattle,
    /* 0x8F */ MSG_actor_jr_troopa5_tattle,
    /* 0x90 */ MSG_actor_blue_goomba_boss_tattle,
    /* 0x91 */ MSG_actor_red_goomba_boss_tattle,
    /* 0x92 */ MSG_actor_goomba_king_tattle,
    /* 0x93 */ MSG_actor_goomnut_tree_tattle,
    /* 0x94 */ NULL,
    /* 0x95 */ MSG_actor_magikoopa_boss_tattle,
    /* 0x96 */ MSG_actor_magikoopa_boss_dup_tattle,
    /* 0x97 */ MSG_actor_magikoopa_boss_tattle,
    /* 0x98 */ MSG_actor_magikoopa_boss_dup_tattle,
    /* 0x99 */ MSG_actor_fake_bowser_tattle,
    /* 0x9A */ MSG_actor_koopa_bros_tattle,
    /* 0x9B */ MSG_actor_green_ninjakoopa_tattle,
    /* 0x9C */ MSG_actor_red_ninjakoopa_tattle,
    /* 0x9D */ MSG_actor_blue_ninjakoopa_tattle,
    /* 0x9E */ MSG_actor_yellow_ninjakoopa_tattle,
    /* 0x9F */ NULL,
    /* 0xA0 */ MSG_actor_buzzar_tattle,
    /* 0xA1 */ MSG_actor_tutankoopa_tattle,
    /* 0xA2 */ MSG_actor_chomp_tattle,
    /* 0xA3 */ MSG_actor_tubba_blubba_tattle,
    /* 0xA4 */ MSG_actor_tubba_blubba_invincible_tattle,
    /* 0xA5 */ MSG_actor_tubba_heart_tattle,
    /* 0xA6 */ MSG_actor_stilt_guy_tattle,
    /* 0xA7 */ MSG_actor_shy_stack_tattle,
    /* 0xA8 */ MSG_actor_shy_squad_tattle,
    /* 0xA9 */ NULL,
    /* 0xAA */ MSG_actor_general_guy_tattle,
    /* 0xAB */ NULL,
    /* 0xAC */ MSG_actor_shy_guy_tattle,
    /* 0xAD */ NULL,
    /* 0xAE */ MSG_actor_shy_guy_tattle,
    /* 0xAF */ MSG_actor_anti_guy_tattle,
    /* 0xB0 */ MSG_actor_anti_guy_tattle,
    /* 0xB1 */ MSG_actor_big_lantern_ghost_tattle,
    /* 0xB2 */ MSG_actor_goomba_king_tattle,
    /* 0xB3 */ MSG_actor_lava_piranha_phase_1_tattle,
    /* 0xB4 */ MSG_actor_lava_piranha_phase_2_tattle,
    /* 0xB5 */ MSG_actor_lava_bud_phase_1_tattle,
    /* 0xB6 */ MSG_actor_lava_bud_phase_2_tattle,
    /* 0xB7 */ MSG_actor_petit_piranha_tattle,
    /* 0xB8 */ MSG_actor_lava_piranha_phase_1_tattle,
    /* 0xB9 */ MSG_actor_kent_c_koopa_tattle,
    /* 0xBA */ MSG_actor_huff_n_puff_tattle,
    /* 0xBB */ MSG_actor_tuff_puff_tattle,
    /* 0xBC */ MSG_actor_monstar_tattle,
    /* 0xBD */ MSG_actor_crystal_king_tattle,
    /* 0xBE */ MSG_actor_crystal_clone_tattle,
    /* 0xBF */ MSG_actor_crystal_bit_tattle,
    /* 0xC0 */ NULL,
    /* 0xC1 */ MSG_actor_bowser_phase_1_tattle,
    /* 0xC2 */ MSG_actor_bowser_phase_1_tattle,
    /* 0xC3 */ MSG_actor_bowser_phase_2_tattle,
    /* 0xC4 */ MSG_actor_bowser_phase_2_tattle,
    /* 0xC5 */ MSG_actor_bowser_phase_3_tattle,
    /* 0xC6 */ MSG_actor_bowser_phase_3_tattle,
    /* 0xC7 */ MSG_actor_blooper_tattle,
    /* 0xC8 */ MSG_actor_electro_blooper_tattle,
    /* 0xC9 */ MSG_actor_electro_blooper_tattle,
    /* 0xCA */ MSG_actor_super_blooper_tattle,
    /* 0xCB */ MSG_actor_super_blooper_tattle,
    /* 0xCC */ MSG_actor_blooper_baby_tattle,
    /* 0xCD */ MSG_actor_ghost_lakilester_tattle,
    /* 0xCE */ MSG_actor_slot_machine_start_tattle,
    /* 0xCF */ MSG_actor_slot_machine_stop_tattle,
    /* 0xD0 */ MSG_actor_whacka_tattle,
    /* 0xD1 */ MSG_actor_slot_machine_start_tattle,
    /* 0xD2 */ MSG_actor_slot_machine_start_tattle,
    /* 0xD3 */ MSG_actor_slot_machine_start_tattle,
};

ActorOffsets bActorOffsets[ACTOR_TYPE_COUNT] = {
    /* 0x00 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x01 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x02 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x03 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x04 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x05 */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x06 */ { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    /* 0x07 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x08 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x09 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x0A */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x0B */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x0C */ { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    /* 0x0D */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x0E */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x0F */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x10 */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x11 */ { .tattleCam = { 0, 254, 241 }, .shadow = 0 },
    /* 0x12 */ { .tattleCam = { 0, 14, 0 }, .shadow = 0 },
    /* 0x13 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x14 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x15 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x16 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x17 */ { .tattleCam = { 0, 10, 0 }, .shadow = 0 },
    /* 0x18 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x19 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x1A */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x1B */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x1C */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x1D */ { .tattleCam = { 0, 254, 241 }, .shadow = 0 },
    /* 0x1E */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x1F */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x20 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x21 */ { .tattleCam = { 0, 15, 23 }, .shadow = 0 },
    /* 0x22 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x23 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x24 */ { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    /* 0x25 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x26 */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x27 */ { .tattleCam = { 0, 7, 0 }, .shadow = 0 },
    /* 0x28 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x29 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x2A */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x2B */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x2C */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x2D */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x2E */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x2F */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x30 */ { .tattleCam = { 0, 14, 0 }, .shadow = 0 },
    /* 0x31 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x32 */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x33 */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x34 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x35 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x36 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x37 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x38 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x39 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x3A */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x3B */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x3C */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x3D */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x3E */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x3F */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x40 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x41 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x42 */ { .tattleCam = { 0, 8, 0 }, .shadow = 0 },
    /* 0x43 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x44 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x45 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x46 */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x47 */ { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    /* 0x48 */ { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    /* 0x49 */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x4A */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x4B */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x4C */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x4D */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x4E */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x4F */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x50 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x51 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x52 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x53 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x54 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x55 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x56 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x57 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x58 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x59 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x5A */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x5B */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x5C */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x5D */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x5E */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x5F */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x60 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x61 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x62 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x63 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x64 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x65 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x66 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x67 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x68 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x69 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x6A */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x6B */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x6C */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x6D */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x6E */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x6F */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x70 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x71 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x72 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x73 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x74 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x75 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x76 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x77 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x78 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x79 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x7A */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x7B */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x7C */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x7D */ { .tattleCam = { 0, 10, 0 }, .shadow = 0 },
    /* 0x7E */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x7F */ { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    /* 0x80 */ { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    /* 0x81 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0x82 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x83 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x84 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x85 */ { .tattleCam = { 0, 8, 0 }, .shadow = 0 },
    /* 0x86 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x87 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x88 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x89 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x8A */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x8B */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x8C */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x8D */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x8E */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x8F */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x90 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x91 */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x92 */ { .tattleCam = { 0, 6, 10 }, .shadow = 0 },
    /* 0x93 */ { .tattleCam = { 8, 12, 17 }, .shadow = 0 },
    /* 0x94 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x95 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x96 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x97 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x98 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x99 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0x9A */ { .tattleCam = { 0, 0, 26 }, .shadow = 26 },
    /* 0x9B */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x9C */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x9D */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x9E */ { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    /* 0x9F */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA0 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA1 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA2 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA3 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA4 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA5 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA6 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA7 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xA8 */ { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    /* 0xA9 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xAA */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xAB */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xAC */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xAD */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xAE */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xAF */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xB0 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xB1 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xB2 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xB3 */ { .tattleCam = { 25, 250, 60 }, .shadow = 0 },
    /* 0xB4 */ { .tattleCam = { 25, 250, 60 }, .shadow = 0 },
    /* 0xB5 */ { .tattleCam = { 0, 233, 0 }, .shadow = 0 },
    /* 0xB6 */ { .tattleCam = { 0, 233, 0 }, .shadow = 0 },
    /* 0xB7 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xB8 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xB9 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xBA */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xBB */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xBC */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xBD */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xBE */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xBF */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xC0 */ { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    /* 0xC1 */ { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    /* 0xC2 */ { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    /* 0xC3 */ { .tattleCam = { 241, 19, 45 }, .shadow = 241 },
    /* 0xC4 */ { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    /* 0xC5 */ { .tattleCam = { 241, 19, 45 }, .shadow = 241 },
    /* 0xC6 */ { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    /* 0xC7 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xC8 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xC9 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xCA */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xCB */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xCC */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xCD */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xCE */ { .tattleCam = { 0, 226, 0 }, .shadow = 0 },
    /* 0xCF */ { .tattleCam = { 0, 226, 0 }, .shadow = 0 },
    /* 0xD0 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xD1 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xD2 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    /* 0xD3 */ { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
};

s32 bMarioIdleAnims[] = {
    Debuff_NORMAL, PlayerAnim_WALKING,
    Debuff_DANGER, PlayerAnim_PANTING,
    Debuff_STONE, 0x00050001,
    Debuff_SLEEP, 0x00030004,
    Debuff_DIZZY, 0x00030006,
    Debuff_STOP, PlayerAnim_STAND_STILL,
    Debuff_HUSTLE, PlayerAnim_RUNNING,
    Debuff_BERSERK, 0x00040028,
    Debuff_PARALYZE, 0x00030004,
    Debuff_FROZEN, 0x0001000E,
    0xE, 0x00010002,
    Debuff_TURN_DONE, PlayerAnim_STAND_STILL,
    0x13, 0x00040029,
    0x14, 0x0004002A,
    0x15, 0x00030003,
    0x18, 0x00030005,
    0x16, 0x0010001,
    Debuff_THINKING, PlayerAnim_THINKING,
    Debuff_WEARY, 0x0001000D,
    Debuff_END,
};

s32 bMarioDefendAnims[] = {
    Debuff_NORMAL, PlayerAnim_CROUCH,
    Debuff_DANGER, PlayerAnim_PANTING,
    Debuff_STONE, 0x00050001,
    Debuff_SLEEP, 0x00030004,
    Debuff_DIZZY, 0x00030006,
    Debuff_STOP, PlayerAnim_STAND_STILL,
    Debuff_HUSTLE, PlayerAnim_CROUCH,
    Debuff_BERSERK, PlayerAnim_CROUCH,
    Debuff_PARALYZE, 0x00030004,
    Debuff_FROZEN, 0x0001000E,
    0xE, 0x00010002,
    Debuff_TURN_DONE, PlayerAnim_STAND_STILL,
    0x13, 0x00040029,
    0x14, 0x0004002A,
    0x15, 0x00030003,
    0x18, 0x00030005,
    0x16, 0x0010001,
    Debuff_THINKING, PlayerAnim_THINKING,
    Debuff_WEARY, 0x0001000D,
    Debuff_END,
};

s32 bMarioHideAnims[] = {
    Debuff_NORMAL, PlayerAnim_CROUCH,
    Debuff_DANGER, PlayerAnim_PANTING,
    Debuff_STONE, 0x00050001,
    Debuff_SLEEP, 0x00030004,
    Debuff_DIZZY, 0x00030006,
    Debuff_STOP, PlayerAnim_STAND_STILL,
    Debuff_HUSTLE, 0x0008000E,
    Debuff_BERSERK, 0x0008000E,
    Debuff_PARALYZE, 0x00030004,
    Debuff_FROZEN, 0x0001000E,
    0xE, 0x00010002,
    Debuff_TURN_DONE, PlayerAnim_CROUCH,
    0x13, 0x00040029,
    0x14, 0x0004002A,
    0x15, 0x00030003,
    0x18, 0x00030005,
    0x16, 0x0010001,
    Debuff_THINKING, PlayerAnim_THINKING,
    Debuff_WEARY, 0x0001000D,
    Debuff_END,
};

s32 bPeachIdleAnims[] = {
    Debuff_NORMAL, 0x000A0002,
    Debuff_TURN_DONE, 0x000C0028,
    Debuff_END,
};

s32 bMarioDefenseTable[] = {
    Element_NORMAL, 0,
    Element_END,
};

s32 bPlayerStatusTable[] = {
    Debuff_NORMAL, 100,
    Debuff_DEFAULT, 100,
    Debuff_SLEEP, 100,
    Debuff_POISON, 100,
    Debuff_FROZEN, 100,
    Debuff_DIZZY, 100,
    Debuff_FEAR, 100,
    Debuff_STATIC, 100,
    Debuff_PARALYZE, 100,
    Debuff_SHRINK, 100,
    Debuff_STOP, 100,
    Debuff_DEFAULT_TURN_MOD, 0,
    Debuff_SLEEP_TURN_MOD, 0,
    Debuff_POISON_TURN_MOD, 0,
    Debuff_FROZEN_TURN_MOD, 0,
    Debuff_DIZZY_TURN_MOD, 0,
    Debuff_FEAR_TURN_MOD, 0,
    Debuff_STATIC_TURN_MOD, 0,
    Debuff_PARALYZE_TURN_MOD, 0,
    Debuff_SHRINK_TURN_MOD, 0,
    Debuff_STOP_TURN_MOD, 0,
    Debuff_END,
};

ActorDesc bPlayerActorDesc = {
    .type = ACTOR_TYPE_player,
    .maxHP = 99,
    .statusTable = bPlayerStatusTable,

    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,

    .size = { 33, 43 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusMessageOffset = { 10, 30 },
};

ActorPartDesc bMarioParts[] = {
    {
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 0xFF,
        .idleAnimations = bMarioIdleAnims,
        .defenseTable = bMarioDefenseTable,
    },
};

s32 D_80283524[] = {
    0x00050000, 0xFFEC002D, 0x0000FFFB, 0x00550000, 0x000A007D, 0x00000019, 0x000A0032, 0xFFEC0032, 0x002DFFFB, 0x005A0032, 0x000A0082, 0x00370019, 0x000F0055, 0xFFEC0037, 0x0050FFFB, 0x005F0055, 0x000A0087, 0x005A0019, 0x000F007D, 0xFFEC0037, 0x0078FFFB, 0x005F007D, 0x000A0087, 0x00820019, 0x00690000, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, D_8028358C, D_8028358C, D_8028358C, D_8028358C, D_8028358C, D_8028358C, D_8028358C, D_8028358C, 0x00000000,
};

s16 D_802835D0[] = { 0x1C, 0x28 };
s16 D_802835D4[] = { 0, -2 };
s16 D_802835D8[] = { 0, -12 };

f32 D_802835DC[] = {
    0.0f, 4.5, 0.0f, 1.0f, 4.0f, 0.0f, 2.0f, 3.0f, 0.0f, 3.0f, 2.0f, 0.0f, 3.5f, 1.0f, 0.0f, 4.0f, 0.0f, 0.0f, 4.5, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 4.5, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f, 3.5f, -1.0f, 0.0f, 3.0f, -2.0f, 0.0f, 2.0f, -3.0f, 0.0f, 1.0f, -4.0f, 0.0f, 0.0f, -4.5f, 0.0f,
};

f32 D_80283690[] = {
    1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f,
};

s32 D_80283744[] = {
    0x00000000, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98, 0x80283D98,
};

MessageID bMessages[] = {
    MSG_merlee_increase_atk, MSG_merlee_increase_dmg, MSG_merlee_increase_star_points, MSG_merlee_end,
    MSG_charge_hammer, MSG_charge_hammer_more, MSG_charge_jump, MSG_charge_jump_more, MSG_charge_max,
    MSG_enemy_missed,
    MSG_player_dazed, MSG_player_slept, MSG_player_frozen, MSG_player_poisoned, MSG_player_shrunk, MSG_player_paralyzed, MSG_player_electrified, MSG_player_transparent,
    MSG_enemy_dazed, MSG_enemy_slept, MSG_enemy_frozen, MSG_enemy_poisoned, MSG_enemy_shrunk, MSG_enemy_paralyzed, MSG_enemy_electrified, MSG_enemy_cannot_move,
    MSG_star_energy_increased, MSG_star_energy_max, MSG_star_energy_filled,
    MSG_atk_up_n, MSG_def_up_n, 0x001D0084, 0x001D0085,
    MSG_enemy_transparent, MSG_enemy_electric_charge,
    MSG_partner_dazed, MSG_charge_goombario, MSG_charge_goombario_more, MSG_water_block_active, MSG_water_block_end, MSG_cloud_nine_active, MSG_cloud_nine_end, MSG_atk_up_active, MSG_atk_up_end, MSG_enemy_atk_down, MSG_cloud_nine_active,
    MSG_action_cmd_jump, MSG_action_cmd_hammer, 0x001D00B1, 0x001D00B2, 0x001D00B3, 0x001D00B4, 0x001D00AF, 0x001D00AF, 0x001D00B5, 0x001D00B6, 0x001D00B7, 0x001D00B8, 0x001D00B9, 0x001D00AF, 0x001D00BA, 0x001D00BB, 0x001D00BC, 0x001D00AF, 0x001D00BD, 0x001D00BE, 0x001D00BF,
    MSG_no_target_jump, MSG_no_target_hammer, MSG_no_battle_items, 0x00000000, 0x00000000,
    0x001D00C3, MSG_hammer_disabled, MSG_hammer_disabled, MSG_hammer_disabled, MSG_jump_disabled, MSG_jump_disabled, MSG_jump_disabled, MSG_items_disabled,
    MSG_no_switch_used_turn, MSG_no_switch_dazed, MSG_no_switch_used_turn, MSG_no_switch_dazed, 0x001D00C3,
};

MessageID bActorMessages[] = {
    MSG_party_mario, MSG_party_goombario, MSG_party_kooper, MSG_party_bombette, MSG_party_parakarry, MSG_party_goompa, MSG_party_watt, MSG_party_sushie, MSG_party_lakilester, MSG_party_bow, MSG_party_goombaria, MSG_party_twink, MSG_party_peach
};

s32 D_802838F8 = 0;

INCLUDE_ASM(s32, "code_190B20", create_target_list);

void player_create_target_list(Actor* actor) {
    create_target_list(actor, 0);
}

void enemy_create_target_list(Actor* actor) {
    create_target_list(actor, 1);
}

INCLUDE_ASM(s32, "code_190B20", func_80263064);

INCLUDE_ASM(s32, "code_190B20", func_80263230);

INCLUDE_ASM(s32, "code_190B20", func_8026324C);

INCLUDE_ASM(s32, "code_190B20", func_80263268);

INCLUDE_ASM(s32, "code_190B20", func_80263300);

INCLUDE_ASM(s32, "code_190B20", func_802633E8);

INCLUDE_ASM(s32, "code_190B20", func_80263434);

INCLUDE_ASM(s32, "code_190B20", func_80263464);

INCLUDE_ASM(s32, "code_190B20", func_802634B8);

INCLUDE_ASM(s32, "code_190B20", func_802636E4);

INCLUDE_ASM(s32, "code_190B20", func_80263914);

INCLUDE_ASM(s32, "code_190B20", count_power_plus);

INCLUDE_ASM(s32, "code_190B20", deduct_current_move_fp);

INCLUDE_ASM(s32, "code_190B20", func_80263C60);

INCLUDE_ASM(s32, "code_190B20", func_80263CC4);

INCLUDE_ASM(s32, "code_190B20", set_animation);

INCLUDE_ASM(s32, "code_190B20", func_80263E08);

INCLUDE_ASM(void, "code_190B20", set_animation_rate, ActorID actorID, s32 partIndex, f32 rate);

void set_actor_yaw(ActorID actorID, s32 yaw) {
    get_actor(actorID)->yaw = yaw;
}

void set_part_yaw(ActorID actorID, s32 partIndex, s32 value) {
    get_actor_part(get_actor(actorID), partIndex)->yaw = value;
}

INCLUDE_ASM(s32, "code_190B20", func_80263FE8);

INCLUDE_ASM(s32, "code_190B20", func_80264084);

INCLUDE_ASM(s32, "code_190B20", add_xz_vec3f);

INCLUDE_ASM(s32, "code_190B20", add_xz_vec3f_copy1);

INCLUDE_ASM(s32, "code_190B20", add_xz_vec3f_copy2);

INCLUDE_ASM(s32, "code_190B20", play_movement_dust_effects);

ActorPart* get_actor_part(Actor* actor, s32 partIndex) {
    ActorPart* part = &actor->partsTable[0];

    if (partIndex < 0 || part->nextPart == NULL) {
        return part;
    }

    while (part != NULL) {
        if (part->staticData->index == partIndex) {
            return part;
        }
        part = part->nextPart;
    }

    return NULL;
}

INCLUDE_ASM(s32, "code_190B20", load_player_actor);

INCLUDE_ASM(s32, "code_190B20", load_partner_actor);

INCLUDE_ASM(s32, "code_190B20", create_actor);

INCLUDE_ASM(s32, "code_190B20", func_80265CE8);

INCLUDE_ASM(s32, "code_190B20", func_80265D44);

s32 lookup_defense(DefenseTableEntry* defenseTable, Element elementKey) {
    DefenseTableEntry* row;
    s32 normalDefense = 0;

    for (row = defenseTable; row->element != Element_END; row++, defenseTable++) {
        if (row->element == Element_NORMAL) {
            normalDefense = defenseTable->defense;
        }

        if (row->element == elementKey) {
            normalDefense = defenseTable->defense;
            break;
        }
    }

    // Fall back to normal defense if given element is not specified in table
    return normalDefense;
}

INCLUDE_ASM(s32, "code_190B20", lookup_status_chance); // exactly (?) the same as lookup_defense

INCLUDE_ASM(s32, "code_190B20", lookup_status_duration_mod); // exactly (?) the same as lookup_defense

INCLUDE_ASM(s32, "code_190B20", inflict_status);

s32 inflict_partner_ko(Actor* target, s32 statusTypeKey, s32 duration) {
    if (statusTypeKey == Debuff_DAZE) {
        if (statusTypeKey != target->koStatus) {
            inflict_status(target, Debuff_DAZE);
            play_sound(0x2107);
        } else {
            target->koDuration += duration;
            if (target->koDuration > 9) {
                target->koDuration = 9;
            }
        }
    }

    return TRUE;
}

s32 get_defense(Actor* actor, s32* defenseTable, s32 elementFlags) {
    s32 defense;
    s32 minDefense = 0xFF;

    if (defenseTable != NULL) {
        if (elementFlags & 2) {
            defense = lookup_defense(defenseTable, Element_FIRE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 4) {
            defense = lookup_defense(defenseTable, Element_WATER);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 8) {
            defense = lookup_defense(defenseTable, Element_ICE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        // Element_MYSTERY missing?
        if (elementFlags & 0x10) {
            defense = lookup_defense(defenseTable, Element_MAGIC);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x40) {
            defense = lookup_defense(defenseTable, Element_HAMMER);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x80) {
            defense = lookup_defense(defenseTable, Element_JUMP);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x100) {
            defense = lookup_defense(defenseTable, Element_COSMIC);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x200) {
            defense = lookup_defense(defenseTable, Element_BLAST);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x20) {
            defense = lookup_defense(defenseTable, Element_SHOCK);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x800) {
            defense = lookup_defense(defenseTable, Element_QUAKE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x40000) {
            defense = lookup_defense(defenseTable, Element_THROW);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
    }

    // If no element flags were set, fall back to normal defense.
    if (minDefense == 0xFF) {
        defense = lookup_defense(defenseTable, Element_NORMAL);
        if (defense < 0xFF) {
            minDefense = defense;
        }
    }

    if (elementFlags & 0x8000000) { // "ignore defense" flag
        if (minDefense == 99) {
            // Immune
            minDefense = 999;
        } else if (minDefense > 0) {
            minDefense = 0;
        }
    }

    return minDefense;
}

INCLUDE_ASM(s32, "code_190B20", func_802664DC);

INCLUDE_ASM(void, "code_190B20", show_damage_popup, f32 x, f32 y, f32 z, s32 damageAmount);

INCLUDE_ASM(s32, "code_190B20", func_80266684);

INCLUDE_ASM(s32, "code_190B20", func_802666E4);

INCLUDE_ASM(s32, "code_190B20", func_802667F0);

INCLUDE_ASM(s32, "code_190B20", func_80266970);

INCLUDE_ASM(s32, "code_190B20", func_80266978);

INCLUDE_ASM(s32, "code_190B20", func_80266ADC);

INCLUDE_ASM(s32, "code_190B20", func_80266AF8);

INCLUDE_ASM(s32, "code_190B20", func_80266B14);

INCLUDE_ASM(s32, "code_190B20", try_inflict_status);

INCLUDE_ASM(s32, "code_190B20", inflict_status_set_duration);

INCLUDE_ASM(s32, "code_190B20", func_80266D6C);

INCLUDE_ASM(s32, "code_190B20", func_80266DAC);

INCLUDE_ASM(s32, "code_190B20", func_80266E14);

INCLUDE_ASM(s32, "code_190B20", func_80266E40);

INCLUDE_ASM(s32, "code_190B20", func_80266EA8);

INCLUDE_ASM(s32, "code_190B20", func_80266EE8);

INCLUDE_ASM(s32, "code_190B20", func_80266F60);

INCLUDE_ASM(s32, "code_190B20", func_80266F8C);

INCLUDE_ASM(s32, "code_190B20", func_80266FD8);

INCLUDE_ASM(s32, "code_190B20", func_80267018);

INCLUDE_ASM(s32, "code_190B20", func_8026709C);

INCLUDE_ASM(s32, "code_190B20", func_802670C8);

void add_part_decoration(ActorPart* part, s32 decorationIndex, DecorationId decorationType) {
    if ((part->idleAnimations) && !(part->flags & 2)) {
        DecorationTable* decorationTable = part->decorationTable;

        _remove_part_decoration(part, decorationIndex);
        decorationTable->decorationType[decorationIndex] = decorationType;
        decorationTable->unk_8BA[decorationIndex] = 1;
        decorationTable->unk_8BC[decorationIndex] = 0;
        func_8025CEC8(part);
    }
}

void add_actor_decoration(Actor* actor, s32 decorationIndex, DecorationId decorationType) {
    ActorPart* part;
    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if ((part->flags & 0x100001) == 0 && part->idleAnimations && (part->flags & 2) == 0) {
            add_part_decoration(part, decorationIndex, decorationType);
        }
    }
}

void remove_part_decoration(ActorPart* part, s32 decorationIndex) {
    _remove_part_decoration(part, decorationIndex);
}

void remove_actor_decoration(Actor* actor, s32 decorationIndex) {
    ActorPart* part;
    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if ((part->flags & 0x100001) == 0 && part->idleAnimations && (part->flags & 2) == 0) {
            remove_part_decoration(part, decorationIndex);
        }
    }
}

s32 heroes_is_ability_active(Actor* actor, Ability ability) {
    s32 actorGenus = actor->actorID & 0x700;
    s32 hasAbility = FALSE;

    if (actorGenus != 0x100) {
        // Separate ifs required to match
        if (actorGenus <= 0x100) {
            if (actorGenus == 0 && (gBattleStatus.flags2 & 0x40) == 0) {
                hasAbility = is_ability_active(ability);
            }
        }
    } else {
        hasAbility = is_partner_ability_active(ability);
    }

    return hasAbility;
}

void create_part_shadow(ActorID actorID, s32 partIndex) {
    ActorPart* part = get_actor_part(get_actor(actorID), partIndex);

    part->flags &= ~4;
    part->shadow = create_shadow_type(0, part->currentPos.x, part->currentPos.y, part->currentPos.z);
    part->shadowScale = part->size[0] / 24.0;
}

void remove_part_shadow(ActorID actorID, s32 partIndex) {
    ActorPart* part = get_actor_part(get_actor(actorID), partIndex);

    part->flags |= 4;
    func_80112328(part->shadow);
}

void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part) {
    part->flags &= ~4;
    part->shadow = create_shadow_type(0, part->currentPos.x, part->currentPos.y, part->currentPos.z);
    part->shadowScale = part->size[0] / 24.0;
}

void func_80071A50(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);
void func_80071C30(s32, f32 x, f32 y, f32 z, f32 scale /* maybe */, s32);

void remove_player_buffs(PlayerBuff buffs) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    ActorPart* playerPartsTable = player->partsTable;

    if (buffs & 1) {
        battleStatus->jumpCharge = 0;
        battleStatus->flags1 &= ~0x20000000;
    }
    if (buffs & 2) {
        battleStatus->hammerCharge = 0;
        battleStatus->flags1 &= ~0x10000000;
    }
    if (buffs & 8) {
        player->stoneDuration = 0;
        player->stoneStatus = 0;
    }
    if (buffs & 0x10) {
        battleStatus->hustleTurns = 0;
        battleStatus->flags1 &= ~0x04000000;
    }
    if ((buffs & 0x20) && (player->staticStatus != 0)) {
        player->staticDuration = 0;
        player->staticStatus = 0;
        func_800479A0(player->unk_436);
    }
    if ((buffs & 0x40) && (player->transStatus != 0)) {
        player->transDuration = 0;
        player->transStatus = 0;
        playerPartsTable->flags &= ~0x100;
        func_80047AA8(player->unk_436);
    }
    if ((buffs & 0x200) && (battleStatus->waterBlockTurnsLeft != 0)) {
        battleStatus->waterBlockTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_10 = 0;
        battleStatus->unk_A0[0] |= 0x10;

        func_80071A50(1, player->currentPos.x, player->currentPos.y + 18.0f, player->currentPos.z + 5.0f, 1.5f, 0xA);
        func_80071C30(0, player->currentPos.x - 10.0f, player->currentPos.y + 5.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
        func_80071C30(0, player->currentPos.x - 15.0f, player->currentPos.y + 32.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
        func_80071C30(1, player->currentPos.x + 15.0f, player->currentPos.y + 22.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);

        battleStatus->unk_A0 = NULL;
        play_sound(0x299);
    }
    if ((buffs & 0x100) && (battleStatus->turboChargeTurnsLeft != 0)) {
        battleStatus->turboChargeTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_24 = 0;
    }
    if ((buffs & 0x80) && (battleStatus->cloudNineTurnsLeft != 0)) {
        battleStatus->cloudNineTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_1A = 0;
        remove_effect(battleStatus->cloudNineEffect);
        battleStatus->cloudNineEffect = 0;
    }

    if ((partner != NULL) && (buffs & 0x10000)) {
        BattleStatus* bs = &gBattleStatus;

        partner->isGlowing = FALSE;
        bs->flags1 &= ~0x40000000;
    }
}

INCLUDE_ASM(s32, "code_190B20", func_8026777C);

INCLUDE_ASM(s32, "code_190B20", func_8026787C);

INCLUDE_ASM(s32, "code_190B20", func_80267A3C);

INCLUDE_ASM(s32, "code_190B20", reset_all_actor_sounds);

void hide_foreground_models_unsafe(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= 2;
            }
        }
    }
}

void show_foreground_models_unsafe(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~2;
            }
        }
    }
}

void hide_foreground_models(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id < 0) {
                break;
            } else {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= 2;
            }

        }
    }
}

void show_foreground_models(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id < 0) {
                break;
            } else {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~2;
            }
        }
    }
}


#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "code_190B20", start_rumble_type);

