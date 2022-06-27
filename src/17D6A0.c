#include "common.h"
#include "effects.h"
#include "message_ids.h"
#include "battle/battle.h"

s32 D_80280FC0[] = {
    0x000A005A, 0x00000032, 0x0003000B, 0x00000032, 0x0001002D, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032,
    0x00010031, 0x00000032, 0x00010031, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x00010032, 0x00000032,
    0x00010032, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x0003000A, 0x00000032, 0x0003000A, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000050, 0x0003000A, 0x00000014, 0x0003000B, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

s32 bActorNames[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA] = MSG_actor_red_goomba,
    [ACTOR_TYPE_RED_PARAGOOMBA] = MSG_actor_red_paragoomba,
    [ACTOR_TYPE_GLOOMBA] = MSG_actor_gloomba,
    [ACTOR_TYPE_PARAGLOOMBA] = MSG_actor_paragloomba,
    [ACTOR_TYPE_SPIKED_GLOOMBA] = MSG_actor_spiked_gloomba,
    [ACTOR_TYPE_DARK_KOOPA] = MSG_actor_dark_koopa,
    [ACTOR_TYPE_DARK_PARATROOPA] = MSG_actor_dark_paratroopa,
    [ACTOR_TYPE_GOOMBA] = MSG_actor_goomba,
    [ACTOR_TYPE_PARAGOOMBA] = MSG_actor_paragoomba,
    [ACTOR_TYPE_SPIKED_GOOMBA] = MSG_actor_spiked_goomba,
    [ACTOR_TYPE_FUZZY] = MSG_actor_fuzzy,
    [ACTOR_TYPE_KOOPA_TROOPA] = MSG_actor_koopa_troopa,
    [ACTOR_TYPE_PARATROOPA] = MSG_actor_paratroopa,
    [ACTOR_TYPE_BOB_OMB] = MSG_actor_bob_omb,
    [ACTOR_TYPE_BOB_OMB_DUP] = MSG_actor_bob_omb,
    [ACTOR_TYPE_BULLET_BILL] = MSG_actor_bullet_bill,
    [ACTOR_TYPE_BILL_BLASTER] = MSG_actor_bill_blaster,
    [ACTOR_TYPE_CLEFT] = MSG_actor_cleft,
    [ACTOR_TYPE_MONTY_MOLE] = MSG_actor_monty_mole,
    [ACTOR_TYPE_BANDIT] = MSG_actor_bandit,
    [ACTOR_TYPE_POKEY] = MSG_actor_pokey,
    [ACTOR_TYPE_POKEY_MUMMY] = MSG_actor_pokey_mummy,
    [ACTOR_TYPE_SWOOPER] = MSG_actor_swooper,
    [ACTOR_TYPE_BUZZY_BEETLE] = MSG_actor_buzzy_beetle,
    [ACTOR_TYPE_STONE_CHOMP] = MSG_actor_stone_chomp,
    [ACTOR_TYPE_PIRANHA_PLANT] = MSG_actor_piranha_plant,
    [ACTOR_TYPE_FOREST_FUZZY] = MSG_actor_forest_fuzzy,
    [ACTOR_TYPE_HYPER_GOOMBA] = MSG_actor_hyper_goomba,
    [ACTOR_TYPE_HYPER_PARAGOOMBA] = MSG_actor_hyper_paragoomba,
    [ACTOR_TYPE_HYPER_CLEFT] = MSG_actor_hyper_cleft,
    [ACTOR_TYPE_CLUBBA] = MSG_actor_clubba,
    [ACTOR_TYPE_SHY_GUY] = MSG_actor_shy_guy,
    [ACTOR_TYPE_GROOVE_GUY] = MSG_actor_groove_guy,
    [ACTOR_TYPE_SKY_GUY] = MSG_actor_sky_guy,
    [ACTOR_TYPE_MEDI_GUY] = MSG_actor_medi_guy,
    [ACTOR_TYPE_PYRO_GUY] = MSG_actor_pyro_guy,
    [ACTOR_TYPE_SPY_GUY] = MSG_actor_spy_guy,
    [ACTOR_TYPE_FUZZIPEDE] = MSG_actor_fuzzipede,
    [ACTOR_TYPE_HURT_PLANT] = MSG_actor_hurt_plant,
    [ACTOR_TYPE_M_BUSH] = MSG_actor_m_bush,
    [ACTOR_TYPE_AQUA_FUZZY] = MSG_actor_aqua_fuzzy,
    [ACTOR_TYPE_JUNGLE_FUZZY] = MSG_actor_jungle_fuzzy,
    [ACTOR_TYPE_SPEAR_GUY] = MSG_actor_spear_guy,
    [ACTOR_TYPE_LAVA_BUBBLE] = MSG_actor_lava_bubble,
    [ACTOR_TYPE_SPIKE_TOP] = MSG_actor_spike_top,
    [ACTOR_TYPE_PUTRID_PIRANHA] = MSG_actor_putrid_piranha,
    [ACTOR_TYPE_LAKITU] = MSG_actor_lakitu,
    [ACTOR_TYPE_SPINY] = MSG_actor_spiny,
    [ACTOR_TYPE_MONTY_MOLE_BOSS] = MSG_actor_monty_mole_boss,
    [ACTOR_TYPE_BZZAP] = MSG_actor_bzzap,
    [ACTOR_TYPE_CRAZEE_DAYZEE] = MSG_actor_crazee_dayzee,
    [ACTOR_TYPE_AMAZY_DAYZEE] = MSG_actor_amazy_dayzee,
    [ACTOR_TYPE_RUFF_PUFF] = MSG_actor_ruff_puff,
    [ACTOR_TYPE_SPIKE] = MSG_actor_spike,
    [ACTOR_TYPE_GULPIT] = MSG_actor_gulpit,
    [ACTOR_TYPE_GULPIT_ROCKS] = MSG_actor_gulpit_rocks,
    [ACTOR_TYPE_WHITE_CLUBBA] = MSG_actor_white_clubba,
    [ACTOR_TYPE_FROST_PIRANHA] = MSG_actor_frost_piranha,
    [ACTOR_TYPE_SWOOPULA] = MSG_actor_swoopula,
    [ACTOR_TYPE_DUPLIGHOST] = MSG_actor_duplighost,
    [ACTOR_TYPE_GHOST_GOOMBARIO] = MSG_actor_ghost_goombario,
    [ACTOR_TYPE_GHOST_KOOPER] = MSG_actor_ghost_kooper,
    [ACTOR_TYPE_GHOST_BOMBETTE] = MSG_actor_ghost_bombette,
    [ACTOR_TYPE_GHOST_PARAKARRY] = MSG_actor_ghost_parakarry,
    [ACTOR_TYPE_GHOST_BOW] = MSG_actor_ghost_bow,
    [ACTOR_TYPE_GHOST_WATT] = MSG_actor_ghost_watt,
    [ACTOR_TYPE_GHOST_SUSHIE] = MSG_actor_ghost_sushie,
    [ACTOR_TYPE_GHOST_LAKILESTER] = MSG_actor_ghost_lakilester,
    [ACTOR_TYPE_ALBINO_DINO] = MSG_actor_albino_dino,
    [ACTOR_TYPE_EMBER] = MSG_actor_ember,
    [ACTOR_TYPE_BONY_BEETLE] = MSG_actor_bony_beetle,
    [ACTOR_TYPE_DRY_BONES] = MSG_actor_dry_bones,
    [ACTOR_TYPE_DRY_BONES2] = MSG_actor_dry_bones,
    [ACTOR_TYPE_BOMBSHELL_BLASTER] = MSG_actor_bombshell_blaster,
    [ACTOR_TYPE_BOMBSHELL_BILL] = MSG_actor_bombshell_bill,
    [ACTOR_TYPE_HAMMER_BROS] = MSG_actor_hammer_bros,
    [ACTOR_TYPE_KOOPATROL] = MSG_actor_koopatrol,
    [ACTOR_TYPE_MAGIKOOPA] = MSG_actor_magikoopa,
    [ACTOR_TYPE_FLYING_MAGIKOOPA] = MSG_actor_magikoopa,
    [ACTOR_TYPE_MAGICLONE] = MSG_actor_magikoopa,
    [ACTOR_TYPE_FLYING_MAGICLONE] = MSG_actor_magikoopa,
    [ACTOR_TYPE_RED_MAGIKOOPA] = MSG_actor_red_magikoopa,
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA] = MSG_actor_red_magikoopa,
    [ACTOR_TYPE_GREEN_MAGIKOOPA] = MSG_actor_green_magikoopa,
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA] = MSG_actor_green_magikoopa,
    [ACTOR_TYPE_YELLOW_MAGIKOOPA] = MSG_actor_yellow_magikoopa,
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA] = MSG_actor_yellow_magikoopa,
    [ACTOR_TYPE_GRAY_MAGIKOOPA] = MSG_actor_gray_magikoopa,
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA] = MSG_actor_gray_magikoopa,
    [ACTOR_TYPE_WHITE_MAGIKOOPA] = MSG_actor_white_magikoopa,
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA] = MSG_actor_white_magikoopa,
    [ACTOR_TYPE_UNUSED_5B] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_5C] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_5D] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_5E] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_5F] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_60] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_61] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_62] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_63] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_64] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_65] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_66] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_67] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_68] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_69] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_6A] = MSG_actor_the_master,
    [ACTOR_TYPE_MONTY_HOLE] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_6C] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_6D] = MSG_actor_the_master,
    [ACTOR_TYPE_PLAYER] = MSG_actor_the_master,
    [ACTOR_TYPE_GOOMBARIO] = MSG_actor_the_master,
    [ACTOR_TYPE_KOOPER] = MSG_actor_the_master,
    [ACTOR_TYPE_BOMBETTE] = MSG_actor_the_master,
    [ACTOR_TYPE_PARAKARRY] = MSG_actor_the_master,
    [ACTOR_TYPE_BOW] = MSG_actor_the_master,
    [ACTOR_TYPE_WATT] = MSG_actor_the_master,
    [ACTOR_TYPE_SUSHIE] = MSG_actor_the_master,
    [ACTOR_TYPE_LAKILESTER] = MSG_actor_the_master,
    [ACTOR_TYPE_TWINK] = MSG_party_twink,
    [ACTOR_TYPE_UNUSED_78] = MSG_actor_the_master,
    [ACTOR_TYPE_UNUSED_79] = MSG_actor_the_master,
    [ACTOR_TYPE_THE_MASTER_1] = MSG_actor_the_master,
    [ACTOR_TYPE_THE_MASTER_2] = MSG_actor_the_master,
    [ACTOR_TYPE_THE_MASTER_3] = MSG_actor_the_master,
    [ACTOR_TYPE_CHAN] = MSG_actor_chan,
    [ACTOR_TYPE_LEE] = MSG_actor_lee,
    [ACTOR_TYPE_LEE_GOOMBARIO] = MSG_party_goombario,
    [ACTOR_TYPE_LEE_KOOPER] = MSG_party_kooper,
    [ACTOR_TYPE_LEE_BOMBETTE] = MSG_party_bombette,
    [ACTOR_TYPE_LEE_PARAKARRY] = MSG_party_parakarry,
    [ACTOR_TYPE_LEE_BOW] = MSG_party_bow,
    [ACTOR_TYPE_LEE_WATT] = MSG_party_watt,
    [ACTOR_TYPE_LEE_SUSHIE] = MSG_party_sushie,
    [ACTOR_TYPE_LEE_LAKILESTER] = MSG_party_lakilester,
    [ACTOR_TYPE_KAMMY_KOOPA] = MSG_actor_kammy_koopa,
    [ACTOR_TYPE_JR_TROOPA1] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA2] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA3] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA4] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA5] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA6] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA_DUP1] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_JR_TROOPA_DUP2] = MSG_actor_jr_troopa,
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS] = MSG_actor_blue_goomba_boss,
    [ACTOR_TYPE_RED_GOOMBA_BOSS] = MSG_actor_red_goomba_boss,
    [ACTOR_TYPE_GOOMBA_KING] = MSG_actor_goomba_king,
    [ACTOR_TYPE_GOOMNUT_TREE] = MSG_actor_goomnut_tree,
    [ACTOR_TYPE_GOOMBARIO_TUTOR1] = MSG_party_goombario,
    [ACTOR_TYPE_MAGIKOOPA_BOSS] = MSG_actor_magikoopa,
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS] = MSG_actor_magikoopa,
    [ACTOR_TYPE_MAGIKOOPA_DUP1] = MSG_actor_magikoopa,
    [ACTOR_TYPE_MAGIKOOPA_DUP2] = MSG_actor_magikoopa,
    [ACTOR_TYPE_FAKE_BOWSER] = MSG_actor_fake_bowser,
    [ACTOR_TYPE_KOOPA_BROS] = MSG_actor_koopa_bros,
    [ACTOR_TYPE_GREEN_NINJAKOOPA] = MSG_actor_green_ninjakoopa,
    [ACTOR_TYPE_RED_NINJAKOOPA] = MSG_actor_red_ninjakoopa,
    [ACTOR_TYPE_BLUE_NINJAKOOPA] = MSG_actor_blue_ninjakoopa,
    [ACTOR_TYPE_YELLOW_NINJAKOOPA] = MSG_actor_yellow_ninjakoopa,
    [ACTOR_TYPE_ELDSTAR] = MSG_party_goombario,
    [ACTOR_TYPE_BUZZAR] = MSG_actor_buzzar,
    [ACTOR_TYPE_TUTANKOOPA] = MSG_actor_tutankoopa,
    [ACTOR_TYPE_CHOMP] = MSG_actor_chomp,
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE] = MSG_actor_tubba_blubba,
    [ACTOR_TYPE_TUBBA_BLUBBA] = MSG_actor_tubba_blubba,
    [ACTOR_TYPE_TUBBA_HEART] = MSG_actor_tubba_heart,
    [ACTOR_TYPE_STILT_GUY] = MSG_actor_stilt_guy,
    [ACTOR_TYPE_SHY_STACK] = MSG_actor_shy_stack,
    [ACTOR_TYPE_SHY_SQUAD] = MSG_actor_shy_squad,
    [ACTOR_TYPE_GENERAL_GUY] = MSG_actor_general_guy_dup,
    [ACTOR_TYPE_TOY_TANK] = MSG_actor_general_guy,
    [ACTOR_TYPE_LIGHT_BULB] = MSG_actor_bulb,
    [ACTOR_TYPE_SIGNAL_GUY] = MSG_actor_shy_guy,
    [ACTOR_TYPE_SHY_SQUAD_DUP] = MSG_actor_shy_squad_dup,
    [ACTOR_TYPE_SHY_GUY_DUP] = MSG_actor_shy_guy,
    [ACTOR_TYPE_ANTI_GUY] = MSG_actor_anti_guy,
    [ACTOR_TYPE_ANTI_GUY_DUP] = MSG_actor_anti_guy,
    [ACTOR_TYPE_BIG_LANTERN_GHOST] = MSG_actor_big_lantern_ghost,
    [ACTOR_TYPE_GOOMBA_KING_DUP] = MSG_actor_goomba_king,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1] = MSG_actor_lava_piranha,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2] = MSG_actor_lava_piranha,
    [ACTOR_TYPE_LAVA_BUD_PHASE_1] = MSG_actor_lava_bud,
    [ACTOR_TYPE_LAVA_BUD_PHASE_2] = MSG_actor_lava_bud,
    [ACTOR_TYPE_PETIT_PIRANHA] = MSG_actor_petit_piranha,
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB] = MSG_actor_lava_piranha,
    [ACTOR_TYPE_KENT_C_KOOPA] = MSG_actor_kent_c_koopa,
    [ACTOR_TYPE_HUFF_N_PUFF] = MSG_actor_huff_n_puff,
    [ACTOR_TYPE_TUFF_PUFF] = MSG_actor_tuff_puff,
    [ACTOR_TYPE_MONSTAR] = MSG_actor_monstar,
    [ACTOR_TYPE_CRYSTAL_KING] = MSG_actor_crystal_king,
    [ACTOR_TYPE_CRYSTAL_CLONE] = MSG_actor_crystal_king,
    [ACTOR_TYPE_CRYSTAL_BIT] = MSG_actor_crystal_bit,
    [ACTOR_TYPE_INTRO_BOWSER] = MSG_actor_bowser,
    [ACTOR_TYPE_BOWSER_PHASE_1] = MSG_actor_bowser,
    [ACTOR_TYPE_BOWSER_DUP1] = MSG_actor_bowser,
    [ACTOR_TYPE_BOWSER_PHASE_2] = MSG_actor_bowser,
    [ACTOR_TYPE_BOWSER_DUP2] = MSG_actor_bowser,
    [ACTOR_TYPE_BOWSER_PHASE_3] = MSG_actor_bowser,
    [ACTOR_TYPE_BOWSER_DUP3] = MSG_actor_bowser,
    [ACTOR_TYPE_BLOOPER] = MSG_actor_blooper,
    [ACTOR_TYPE_ELECTRO_BLOOPER1] = MSG_actor_electro_blooper,
    [ACTOR_TYPE_ELECTRO_BLOOPER2] = MSG_actor_electro_blooper,
    [ACTOR_TYPE_SUPER_BLOOPER1] = MSG_actor_super_blooper,
    [ACTOR_TYPE_SUPER_BLOOPER2] = MSG_actor_super_blooper,
    [ACTOR_TYPE_BLOOPER_BABY] = MSG_actor_blooper_baby,
    [ACTOR_TYPE_LAKILESTER_DUP] = MSG_actor_ghost_lakilester,
    [ACTOR_TYPE_SLOT_MACHINE_START] = MSG_actor_slot_machine_start,
    [ACTOR_TYPE_SLOT_MACHINE_STOP] = MSG_actor_slot_machine_stop,
    [ACTOR_TYPE_WHACKA] = MSG_actor_whacka,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1] = MSG_actor_slot_machine_start,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2] = MSG_actor_slot_machine_start,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3] = MSG_actor_slot_machine_start,
};

s32 D_80281454[] = { 0x78, 0x93, 0x99, 0xB2, -1 };

ActorSounds bActorSoundTable[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_RED_PARAGOOMBA] = { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GLOOMBA] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PARAGLOOMBA] = { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SPIKED_GLOOMBA] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_DARK_KOOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_DARK_PARATROOPA] = { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GOOMBA] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PARAGOOMBA] = { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SPIKED_GOOMBA] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FUZZY] = { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_KOOPA_TROOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PARATROOPA] = { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOB_OMB] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOB_OMB_DUP] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BULLET_BILL] = { .walk = { 0x02C9, 0x02C9 }, .fly = { 0x02C9, 0x02C9 }, .jump = 0x02C9, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BILL_BLASTER] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_CLEFT] = { .walk = { 0x20D0, 0x20D0 }, .fly = { 0x20D0, 0x20D0 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MONTY_MOLE] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BANDIT] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x20C1, 0x20C1 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_POKEY] = { .walk = { 0x0343, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_POKEY_MUMMY] = { .walk = { 0x0343, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SWOOPER] = { .walk = { 0x0351, 0x0351 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BUZZY_BEETLE] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_STONE_CHOMP] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PIRANHA_PLANT] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FOREST_FUZZY] = { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_HYPER_GOOMBA] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_HYPER_PARAGOOMBA] = { .walk = { 0x20DF, 0x20DF }, .fly = { 0x20DF, 0x20DF }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_HYPER_CLEFT] = { .walk = { 0x20D0, 0x20D0 }, .fly = { 0x20D0, 0x20D0 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_CLUBBA] = { .walk = { 0x20C4, 0x20C4 }, .fly = { 0x20C4, 0x20C4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SHY_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GROOVE_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SKY_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MEDI_GUY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0380, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PYRO_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SPY_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FUZZIPEDE] = { .walk = { 0x20D9, 0x20D9 }, .fly = { 0x20D9, 0x20D9 }, .jump = 0x20D9, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_HURT_PLANT] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_M_BUSH] = { .walk = { 0x20C6, 0x20C6 }, .fly = { 0x20C6, 0x20C6 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_AQUA_FUZZY] = { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JUNGLE_FUZZY] = { .walk = { 0x0331, 0x0331 }, .fly = { 0x0331, 0x0331 }, .jump = 0x0331, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SPEAR_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAVA_BUBBLE] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SPIKE_TOP] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PUTRID_PIRANHA] = { .walk = { 0x03CE, 0x03CE }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAKITU] = { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    [ACTOR_TYPE_SPINY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MONTY_MOLE_BOSS] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BZZAP] = { .walk = { 0x0357, 0x0000 }, .fly = { 0x0357, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_CRAZEE_DAYZEE] = { .walk = { 0x02D6, 0x02D6 }, .fly = { 0x02D6, 0x02D6 }, .jump = 0x02D5, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_AMAZY_DAYZEE] = { .walk = { 0x02D6, 0x02D6 }, .fly = { 0x02D6, 0x02D6 }, .jump = 0x02D5, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_RUFF_PUFF] = { .walk = { 0x0295, 0x0000 }, .fly = { 0x0295, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SPIKE] = { .walk = { 0x0295, 0x0000 }, .fly = { 0x0295, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GULPIT] = { .walk = { 0x20C4, 0x20C4 }, .fly = { 0x20C4, 0x20C4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GULPIT_ROCKS] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_WHITE_CLUBBA] = { .walk = { 0x20C4, 0x20C4 }, .fly = { 0x20C4, 0x20C4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FROST_PIRANHA] = { .walk = { 0x03CE, 0x03CE }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SWOOPULA] = { .walk = { 0x0351, 0x0351 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_DUPLIGHOST] = { .walk = { 0x02CA, 0x02CA }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_GOOMBARIO] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_KOOPER] = { .walk = { 0x0100, 0x0100 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_BOMBETTE] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_PARAKARRY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_BOW] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_WATT] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_SUSHIE] = { .walk = { 0x029A, 0x029A }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GHOST_LAKILESTER] = { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    [ACTOR_TYPE_ALBINO_DINO] = { .walk = { 0x030B, 0x02FD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_EMBER] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BONY_BEETLE] = { .walk = { 0x20CD, 0x20CD }, .fly = { 0x20CD, 0x20CD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_DRY_BONES] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_DRY_BONES2] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOMBSHELL_BLASTER] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOMBSHELL_BILL] = { .walk = { 0x02C9, 0x02C9 }, .fly = { 0x02C9, 0x02C9 }, .jump = 0x02C9, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_HAMMER_BROS] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_KOOPATROL] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MAGICLONE] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_MAGICLONE] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_RED_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GREEN_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_YELLOW_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GRAY_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_WHITE_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_5B] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_5C] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_5D] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_5E] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_5F] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_60] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_61] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_62] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_63] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_64] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_65] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_66] = { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    [ACTOR_TYPE_UNUSED_67] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x20DD, 0x20DD }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_68] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_69] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_6A] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MONTY_HOLE] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_6C] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_6D] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PLAYER] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_GOOMBARIO] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_KOOPER] = { .walk = { 0x0100, 0x0100 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOMBETTE] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_PARAKARRY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOW] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_WATT] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SUSHIE] = { .walk = { 0x029A, 0x029A }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAKILESTER] = { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    [ACTOR_TYPE_TWINK] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { -5, -5 } },
    [ACTOR_TYPE_UNUSED_78] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_UNUSED_79] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_THE_MASTER_1] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_THE_MASTER_2] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_THE_MASTER_3] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_CHAN] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE] = { .walk = { 0x02CA, 0x02CA }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_GOOMBARIO] = { .walk = { 0x20DD, 0x20DD }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_KOOPER] = { .walk = { 0x0100, 0x0100 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_BOMBETTE] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_PARAKARRY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_BOW] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_WATT] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_SUSHIE] = { .walk = { 0x029A, 0x029A }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LEE_LAKILESTER] = { .walk = { 0x0295, 0x0295 }, .fly = { 0x0295, 0x0295 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { -5, -5 } },
    [ACTOR_TYPE_KAMMY_KOOPA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA1] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA2] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA3] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA4] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA5] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA6] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA_DUP1] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_JR_TROOPA_DUP2] = { .walk = { 0x20C1, 0x20C1 }, .fly = { 0x0351, 0x0351 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS] = { .walk = { 0x03AC, 0x03AC }, .fly = { 0x0000, 0x0000 }, .jump = 0x010F, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_RED_GOOMBA_BOSS] = { .walk = { 0x03AC, 0x03AC }, .fly = { 0x0000, 0x0000 }, .jump = 0x010F, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GOOMBA_KING] = { .walk = { 0x20EC, 0x20EC }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 22, 30 } },
    [ACTOR_TYPE_GOOMNUT_TREE] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_GOOMBARIO_TUTOR1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_MAGIKOOPA_BOSS] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MAGIKOOPA_DUP1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_MAGIKOOPA_DUP2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_FAKE_BOWSER] = { .walk = { 0x03EA, 0x03EA }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_KOOPA_BROS] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_GREEN_NINJAKOOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_RED_NINJAKOOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BLUE_NINJAKOOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_YELLOW_NINJAKOOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_ELDSTAR] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BUZZAR] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x20EF, 0x20EF }, .jump = 0x0000, .hurt = 0x0000, .delay = { -14, -14 } },
    [ACTOR_TYPE_TUTANKOOPA] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { -3, -3 } },
    [ACTOR_TYPE_CHOMP] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE] = { .walk = { 0x20F6, 0x20F6 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_TUBBA_BLUBBA] = { .walk = { 0x20F6, 0x20F6 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_TUBBA_HEART] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x20C8, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_STILT_GUY] = { .walk = { 0x2066, 0x2066 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SHY_STACK] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 10, 10 } },
    [ACTOR_TYPE_SHY_SQUAD] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_GENERAL_GUY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_TOY_TANK] = { .walk = { 0x037E, 0x037E }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_LIGHT_BULB] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SIGNAL_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SHY_SQUAD_DUP] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SHY_GUY_DUP] = { .walk = { 0x20BA, 0x20BA }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_ANTI_GUY] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_ANTI_GUY_DUP] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_BIG_LANTERN_GHOST] = { .walk = { 0x037D, 0x037D }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_GOOMBA_KING_DUP] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAVA_BUD_PHASE_1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAVA_BUD_PHASE_2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_PETIT_PIRANHA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_KENT_C_KOOPA] = { .walk = { 0x20EC, 0x20EC }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_HUFF_N_PUFF] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x03D1, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_TUFF_PUFF] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_MONSTAR] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_CRYSTAL_KING] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_CRYSTAL_CLONE] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_CRYSTAL_BIT] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_INTRO_BOWSER] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOWSER_PHASE_1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOWSER_DUP1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOWSER_PHASE_2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOWSER_DUP2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOWSER_PHASE_3] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x03E7, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BOWSER_DUP3] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_BLOOPER] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    [ACTOR_TYPE_ELECTRO_BLOOPER1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    [ACTOR_TYPE_ELECTRO_BLOOPER2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    [ACTOR_TYPE_SUPER_BLOOPER1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    [ACTOR_TYPE_SUPER_BLOOPER2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 25, 25 } },
    [ACTOR_TYPE_BLOOPER_BABY] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_LAKILESTER_DUP] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SLOT_MACHINE_START] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_SLOT_MACHINE_STOP] = { .walk = { 0x20BA, 0x03B4 }, .fly = { 0x20BA, 0x03B4 }, .jump = 0x03E2, .hurt = 0x010F, .delay = { 30, 30 } },
    [ACTOR_TYPE_WHACKA] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
};

s32 bActorTattles[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA] = NULL,
    [ACTOR_TYPE_RED_PARAGOOMBA] = NULL,
    [ACTOR_TYPE_GLOOMBA] = MSG_actor_gloomba_tattle,
    [ACTOR_TYPE_PARAGLOOMBA] = MSG_actor_paragloomba_tattle,
    [ACTOR_TYPE_SPIKED_GLOOMBA] = MSG_actor_spiked_gloomba_tattle,
    [ACTOR_TYPE_DARK_KOOPA] = MSG_actor_dark_koopa_tattle,
    [ACTOR_TYPE_DARK_PARATROOPA] = MSG_actor_dark_paratroopa_tattle,
    [ACTOR_TYPE_GOOMBA] = MSG_actor_goomba_tattle,
    [ACTOR_TYPE_PARAGOOMBA] = MSG_actor_paragoomba_tattle,
    [ACTOR_TYPE_SPIKED_GOOMBA] = MSG_actor_spiked_goomba_tattle,
    [ACTOR_TYPE_FUZZY] = MSG_actor_fuzzy_tattle,
    [ACTOR_TYPE_KOOPA_TROOPA] = MSG_actor_koopa_troopa_tattle,
    [ACTOR_TYPE_PARATROOPA] = MSG_actor_paratroopa_tattle,
    [ACTOR_TYPE_BOB_OMB] = MSG_actor_bob_omb_tattle,
    [ACTOR_TYPE_BOB_OMB_DUP] = MSG_actor_bob_omb_tattle,
    [ACTOR_TYPE_BULLET_BILL] = MSG_actor_bullet_bill_tattle,
    [ACTOR_TYPE_BILL_BLASTER] = MSG_actor_bill_blaster_tattle,
    [ACTOR_TYPE_CLEFT] = MSG_actor_cleft_tattle,
    [ACTOR_TYPE_MONTY_MOLE] = MSG_actor_monty_mole_tattle,
    [ACTOR_TYPE_BANDIT] = MSG_actor_bandit_tattle,
    [ACTOR_TYPE_POKEY] = MSG_actor_pokey_tattle,
    [ACTOR_TYPE_POKEY_MUMMY] = MSG_actor_pokey_mummy_tattle,
    [ACTOR_TYPE_SWOOPER] = MSG_actor_swooper_tattle,
    [ACTOR_TYPE_BUZZY_BEETLE] = MSG_actor_buzzy_beetle_tattle,
    [ACTOR_TYPE_STONE_CHOMP] = MSG_actor_stone_chomp_tattle,
    [ACTOR_TYPE_PIRANHA_PLANT] = MSG_actor_piranha_plant_tattle,
    [ACTOR_TYPE_FOREST_FUZZY] = MSG_actor_forest_fuzzy_tattle,
    [ACTOR_TYPE_HYPER_GOOMBA] = MSG_actor_hyper_goomba_tattle,
    [ACTOR_TYPE_HYPER_PARAGOOMBA] = MSG_actor_hyper_paragoomba_tattle,
    [ACTOR_TYPE_HYPER_CLEFT] = MSG_actor_hyper_cleft_tattle,
    [ACTOR_TYPE_CLUBBA] = MSG_actor_clubba_tattle,
    [ACTOR_TYPE_SHY_GUY] = MSG_actor_shy_guy_tattle,
    [ACTOR_TYPE_GROOVE_GUY] = MSG_actor_groove_guy_tattle,
    [ACTOR_TYPE_SKY_GUY] = MSG_actor_sky_guy_tattle,
    [ACTOR_TYPE_MEDI_GUY] = MSG_actor_medi_guy_tattle,
    [ACTOR_TYPE_PYRO_GUY] = MSG_actor_pyro_guy_tattle,
    [ACTOR_TYPE_SPY_GUY] = MSG_actor_spy_guy_tattle,
    [ACTOR_TYPE_FUZZIPEDE] = NULL,
    [ACTOR_TYPE_HURT_PLANT] = MSG_actor_hurt_plant_tattle,
    [ACTOR_TYPE_M_BUSH] = MSG_actor_m_bush_tattle,
    [ACTOR_TYPE_AQUA_FUZZY] = NULL,
    [ACTOR_TYPE_JUNGLE_FUZZY] = MSG_actor_jungle_fuzzy_tattle,
    [ACTOR_TYPE_SPEAR_GUY] = MSG_actor_spear_guy_tattle,
    [ACTOR_TYPE_LAVA_BUBBLE] = MSG_actor_lava_bubble_tattle,
    [ACTOR_TYPE_SPIKE_TOP] = MSG_actor_spike_top_tattle,
    [ACTOR_TYPE_PUTRID_PIRANHA] = MSG_actor_putrid_piranha_tattle,
    [ACTOR_TYPE_LAKITU] = MSG_actor_lakitu_tattle,
    [ACTOR_TYPE_SPINY] = MSG_actor_spiny_tattle,
    [ACTOR_TYPE_MONTY_MOLE_BOSS] = MSG_actor_monty_mole_boss_tattle,
    [ACTOR_TYPE_BZZAP] = MSG_actor_bzzap_tattle,
    [ACTOR_TYPE_CRAZEE_DAYZEE] = MSG_actor_crazee_dayzee_tattle,
    [ACTOR_TYPE_AMAZY_DAYZEE] = MSG_actor_amazy_dayzee_tattle,
    [ACTOR_TYPE_RUFF_PUFF] = MSG_actor_ruff_puff_tattle,
    [ACTOR_TYPE_SPIKE] = MSG_actor_spike_tattle,
    [ACTOR_TYPE_GULPIT] = MSG_actor_gulpit_tattle,
    [ACTOR_TYPE_GULPIT_ROCKS] = MSG_actor_gulpit_rocks_tattle,
    [ACTOR_TYPE_WHITE_CLUBBA] = MSG_actor_white_clubba_tattle,
    [ACTOR_TYPE_FROST_PIRANHA] = MSG_actor_frost_piranha_tattle,
    [ACTOR_TYPE_SWOOPULA] = MSG_actor_swoopula_tattle,
    [ACTOR_TYPE_DUPLIGHOST] = MSG_actor_duplighost_tattle,
    [ACTOR_TYPE_GHOST_GOOMBARIO] = MSG_actor_ghost_goombario_tattle,
    [ACTOR_TYPE_GHOST_KOOPER] = MSG_actor_ghost_kooper_tattle,
    [ACTOR_TYPE_GHOST_BOMBETTE] = MSG_actor_ghost_bombette_tattle,
    [ACTOR_TYPE_GHOST_PARAKARRY] = MSG_actor_ghost_parakarry_tattle,
    [ACTOR_TYPE_GHOST_BOW] = MSG_actor_ghost_bow_tattle,
    [ACTOR_TYPE_GHOST_WATT] = MSG_actor_ghost_watt_tattle,
    [ACTOR_TYPE_GHOST_SUSHIE] = MSG_actor_ghost_sushie_tattle,
    [ACTOR_TYPE_GHOST_LAKILESTER] = MSG_actor_ghost_lakilester_tattle,
    [ACTOR_TYPE_ALBINO_DINO] = MSG_actor_albino_dino_tattle,
    [ACTOR_TYPE_EMBER] = MSG_actor_ember_tattle,
    [ACTOR_TYPE_BONY_BEETLE] = MSG_actor_bony_beetle_tattle,
    [ACTOR_TYPE_DRY_BONES] = MSG_actor_dry_bones_tattle,
    [ACTOR_TYPE_DRY_BONES2] = MSG_actor_dry_bones_tattle,
    [ACTOR_TYPE_BOMBSHELL_BLASTER] = MSG_actor_bombshell_blaster_tattle,
    [ACTOR_TYPE_BOMBSHELL_BILL] = MSG_actor_bombshell_bill_tattle,
    [ACTOR_TYPE_HAMMER_BROS] = MSG_actor_hammer_bros_tattle,
    [ACTOR_TYPE_KOOPATROL] = MSG_actor_koopatrol_tattle,
    [ACTOR_TYPE_MAGIKOOPA] = MSG_actor_magikoopa_tattle,
    [ACTOR_TYPE_FLYING_MAGIKOOPA] = MSG_actor_magikoopa_dup_tattle,
    [ACTOR_TYPE_MAGICLONE] = MSG_actor_magiclone_tattle,
    [ACTOR_TYPE_FLYING_MAGICLONE] = MSG_actor_magiclone_dup_tattle,
    [ACTOR_TYPE_RED_MAGIKOOPA] = MSG_actor_red_magikoopa_tattle,
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA] = MSG_actor_flying_red_magikoopa_tattle,
    [ACTOR_TYPE_GREEN_MAGIKOOPA] = MSG_actor_green_magikoopa_tattle,
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA] = MSG_actor_flying_green_magikoopa_tattle,
    [ACTOR_TYPE_YELLOW_MAGIKOOPA] = MSG_actor_yellow_magikoopa_tattle,
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA] = MSG_actor_flying_yellow_magikoopa_tattle,
    [ACTOR_TYPE_GRAY_MAGIKOOPA] = MSG_actor_gray_magikoopa_tattle,
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA] = MSG_actor_flying_gray_magikoopa_tattle,
    [ACTOR_TYPE_WHITE_MAGIKOOPA] = MSG_actor_flying_white_magikoopa_tattle,
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA] = MSG_actor_white_magikoopa_tattle,
    [ACTOR_TYPE_UNUSED_5B] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_5C] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_5D] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_5E] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_5F] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_60] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_61] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_62] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_63] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_64] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_65] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_66] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_67] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_68] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_69] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_6A] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_MONTY_HOLE] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_6C] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_6D] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_PLAYER] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_GOOMBARIO] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_KOOPER] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_BOMBETTE] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_PARAKARRY] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_BOW] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_WATT] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_SUSHIE] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_LAKILESTER] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_TWINK] = NULL,
    [ACTOR_TYPE_UNUSED_78] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_UNUSED_79] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_THE_MASTER_1] = MSG_actor_the_master_1_tattle,
    [ACTOR_TYPE_THE_MASTER_2] = MSG_actor_the_master_2_tattle,
    [ACTOR_TYPE_THE_MASTER_3] = MSG_actor_the_master_3_tattle,
    [ACTOR_TYPE_CHAN] = MSG_actor_chan_tattle,
    [ACTOR_TYPE_LEE] = MSG_actor_lee_tattle,
    [ACTOR_TYPE_LEE_GOOMBARIO] = MSG_actor_lee_goombario_tattle,
    [ACTOR_TYPE_LEE_KOOPER] = MSG_actor_lee_kooper_tattle,
    [ACTOR_TYPE_LEE_BOMBETTE] = MSG_actor_lee_bombette_tattle,
    [ACTOR_TYPE_LEE_PARAKARRY] = MSG_actor_lee_parakarry_tattle,
    [ACTOR_TYPE_LEE_BOW] = MSG_actor_lee_bow_tattle,
    [ACTOR_TYPE_LEE_WATT] = MSG_actor_lee_watt_tattle,
    [ACTOR_TYPE_LEE_SUSHIE] = MSG_actor_lee_sushie_tattle,
    [ACTOR_TYPE_LEE_LAKILESTER] = MSG_actor_lee_lakilester_tattle,
    [ACTOR_TYPE_KAMMY_KOOPA] = NULL,
    [ACTOR_TYPE_JR_TROOPA1] = NULL,
    [ACTOR_TYPE_JR_TROOPA2] = MSG_actor_jr_troopa1_tattle,
    [ACTOR_TYPE_JR_TROOPA3] = MSG_actor_jr_troopa2_tattle,
    [ACTOR_TYPE_JR_TROOPA4] = MSG_actor_jr_troopa3_tattle,
    [ACTOR_TYPE_JR_TROOPA5] = MSG_actor_jr_troopa4_tattle,
    [ACTOR_TYPE_JR_TROOPA6] = MSG_actor_jr_troopa5_tattle,
    [ACTOR_TYPE_JR_TROOPA_DUP1] = MSG_actor_jr_troopa5_tattle,
    [ACTOR_TYPE_JR_TROOPA_DUP2] = MSG_actor_jr_troopa5_tattle,
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS] = MSG_actor_blue_goomba_boss_tattle,
    [ACTOR_TYPE_RED_GOOMBA_BOSS] = MSG_actor_red_goomba_boss_tattle,
    [ACTOR_TYPE_GOOMBA_KING] = MSG_actor_goomba_king_tattle,
    [ACTOR_TYPE_GOOMNUT_TREE] = MSG_actor_goomnut_tree_tattle,
    [ACTOR_TYPE_GOOMBARIO_TUTOR1] = NULL,
    [ACTOR_TYPE_MAGIKOOPA_BOSS] = MSG_actor_magikoopa_boss_tattle,
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS] = MSG_actor_magikoopa_boss_dup_tattle,
    [ACTOR_TYPE_MAGIKOOPA_DUP1] = MSG_actor_magikoopa_boss_tattle,
    [ACTOR_TYPE_MAGIKOOPA_DUP2] = MSG_actor_magikoopa_boss_dup_tattle,
    [ACTOR_TYPE_FAKE_BOWSER] = MSG_actor_fake_bowser_tattle,
    [ACTOR_TYPE_KOOPA_BROS] = MSG_actor_koopa_bros_tattle,
    [ACTOR_TYPE_GREEN_NINJAKOOPA] = MSG_actor_green_ninjakoopa_tattle,
    [ACTOR_TYPE_RED_NINJAKOOPA] = MSG_actor_red_ninjakoopa_tattle,
    [ACTOR_TYPE_BLUE_NINJAKOOPA] = MSG_actor_blue_ninjakoopa_tattle,
    [ACTOR_TYPE_YELLOW_NINJAKOOPA] = MSG_actor_yellow_ninjakoopa_tattle,
    [ACTOR_TYPE_ELDSTAR] = NULL,
    [ACTOR_TYPE_BUZZAR] = MSG_actor_buzzar_tattle,
    [ACTOR_TYPE_TUTANKOOPA] = MSG_actor_tutankoopa_tattle,
    [ACTOR_TYPE_CHOMP] = MSG_actor_chomp_tattle,
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE] = MSG_actor_tubba_blubba_tattle,
    [ACTOR_TYPE_TUBBA_BLUBBA] = MSG_actor_tubba_blubba_invincible_tattle,
    [ACTOR_TYPE_TUBBA_HEART] = MSG_actor_tubba_heart_tattle,
    [ACTOR_TYPE_STILT_GUY] = MSG_actor_stilt_guy_tattle,
    [ACTOR_TYPE_SHY_STACK] = MSG_actor_shy_stack_tattle,
    [ACTOR_TYPE_SHY_SQUAD] = MSG_actor_shy_squad_tattle,
    [ACTOR_TYPE_GENERAL_GUY] = NULL,
    [ACTOR_TYPE_TOY_TANK] = MSG_actor_general_guy_tattle,
    [ACTOR_TYPE_LIGHT_BULB] = NULL,
    [ACTOR_TYPE_SIGNAL_GUY] = MSG_actor_shy_guy_tattle,
    [ACTOR_TYPE_SHY_SQUAD_DUP] = NULL,
    [ACTOR_TYPE_SHY_GUY_DUP] = MSG_actor_shy_guy_tattle,
    [ACTOR_TYPE_ANTI_GUY] = MSG_actor_anti_guy_tattle,
    [ACTOR_TYPE_ANTI_GUY_DUP] = MSG_actor_anti_guy_tattle,
    [ACTOR_TYPE_BIG_LANTERN_GHOST] = MSG_actor_big_lantern_ghost_tattle,
    [ACTOR_TYPE_GOOMBA_KING_DUP] = MSG_actor_goomba_king_tattle,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1] = MSG_actor_lava_piranha_phase_1_tattle,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2] = MSG_actor_lava_piranha_phase_2_tattle,
    [ACTOR_TYPE_LAVA_BUD_PHASE_1] = MSG_actor_lava_bud_phase_1_tattle,
    [ACTOR_TYPE_LAVA_BUD_PHASE_2] = MSG_actor_lava_bud_phase_2_tattle,
    [ACTOR_TYPE_PETIT_PIRANHA] = MSG_actor_petit_piranha_tattle,
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB] = MSG_actor_lava_piranha_phase_1_tattle,
    [ACTOR_TYPE_KENT_C_KOOPA] = MSG_actor_kent_c_koopa_tattle,
    [ACTOR_TYPE_HUFF_N_PUFF] = MSG_actor_huff_n_puff_tattle,
    [ACTOR_TYPE_TUFF_PUFF] = MSG_actor_tuff_puff_tattle,
    [ACTOR_TYPE_MONSTAR] = MSG_actor_monstar_tattle,
    [ACTOR_TYPE_CRYSTAL_KING] = MSG_actor_crystal_king_tattle,
    [ACTOR_TYPE_CRYSTAL_CLONE] = MSG_actor_crystal_clone_tattle,
    [ACTOR_TYPE_CRYSTAL_BIT] = MSG_actor_crystal_bit_tattle,
    [ACTOR_TYPE_INTRO_BOWSER] = NULL,
    [ACTOR_TYPE_BOWSER_PHASE_1] = MSG_actor_bowser_phase_1_tattle,
    [ACTOR_TYPE_BOWSER_DUP1] = MSG_actor_bowser_phase_1_tattle,
    [ACTOR_TYPE_BOWSER_PHASE_2] = MSG_actor_bowser_phase_2_tattle,
    [ACTOR_TYPE_BOWSER_DUP2] = MSG_actor_bowser_phase_2_tattle,
    [ACTOR_TYPE_BOWSER_PHASE_3] = MSG_actor_bowser_phase_3_tattle,
    [ACTOR_TYPE_BOWSER_DUP3] = MSG_actor_bowser_phase_3_tattle,
    [ACTOR_TYPE_BLOOPER] = MSG_actor_blooper_tattle,
    [ACTOR_TYPE_ELECTRO_BLOOPER1] = MSG_actor_electro_blooper_tattle,
    [ACTOR_TYPE_ELECTRO_BLOOPER2] = MSG_actor_electro_blooper_tattle,
    [ACTOR_TYPE_SUPER_BLOOPER1] = MSG_actor_super_blooper_tattle,
    [ACTOR_TYPE_SUPER_BLOOPER2] = MSG_actor_super_blooper_tattle,
    [ACTOR_TYPE_BLOOPER_BABY] = MSG_actor_blooper_baby_tattle,
    [ACTOR_TYPE_LAKILESTER_DUP] = MSG_actor_ghost_lakilester_tattle,
    [ACTOR_TYPE_SLOT_MACHINE_START] = MSG_actor_slot_machine_start_tattle,
    [ACTOR_TYPE_SLOT_MACHINE_STOP] = MSG_actor_slot_machine_stop_tattle,
    [ACTOR_TYPE_WHACKA] = MSG_actor_whacka_tattle,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1] = MSG_actor_slot_machine_start_tattle,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2] = MSG_actor_slot_machine_start_tattle,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3] = MSG_actor_slot_machine_start_tattle,
};

ActorOffsets bActorOffsets[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_RED_PARAGOOMBA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GLOOMBA] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PARAGLOOMBA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPIKED_GLOOMBA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_DARK_KOOPA] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_DARK_PARATROOPA] = { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GOOMBA] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PARAGOOMBA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPIKED_GOOMBA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FUZZY] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_KOOPA_TROOPA] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PARATROOPA] = { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BOB_OMB] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BOB_OMB_DUP] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BULLET_BILL] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BILL_BLASTER] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CLEFT] = { .tattleCam = { 0, 254, 241 }, .shadow = 0 },
    [ACTOR_TYPE_MONTY_MOLE] = { .tattleCam = { 0, 14, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BANDIT] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_POKEY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_POKEY_MUMMY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SWOOPER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BUZZY_BEETLE] = { .tattleCam = { 0, 10, 0 }, .shadow = 0 },
    [ACTOR_TYPE_STONE_CHOMP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PIRANHA_PLANT] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FOREST_FUZZY] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_HYPER_GOOMBA] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_HYPER_PARAGOOMBA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_HYPER_CLEFT] = { .tattleCam = { 0, 254, 241 }, .shadow = 0 },
    [ACTOR_TYPE_CLUBBA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SHY_GUY] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GROOVE_GUY] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SKY_GUY] = { .tattleCam = { 0, 15, 23 }, .shadow = 0 },
    [ACTOR_TYPE_MEDI_GUY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PYRO_GUY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPY_GUY] = { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FUZZIPEDE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_HURT_PLANT] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_M_BUSH] = { .tattleCam = { 0, 7, 0 }, .shadow = 0 },
    [ACTOR_TYPE_AQUA_FUZZY] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JUNGLE_FUZZY] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPEAR_GUY] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LAVA_BUBBLE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPIKE_TOP] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PUTRID_PIRANHA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LAKITU] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPINY] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MONTY_MOLE_BOSS] = { .tattleCam = { 0, 14, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BZZAP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CRAZEE_DAYZEE] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_AMAZY_DAYZEE] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_RUFF_PUFF] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SPIKE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GULPIT] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GULPIT_ROCKS] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_WHITE_CLUBBA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FROST_PIRANHA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SWOOPULA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_DUPLIGHOST] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_GOOMBARIO] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_KOOPER] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_BOMBETTE] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_PARAKARRY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_BOW] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_WATT] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_SUSHIE] = { .tattleCam = { 0, 8, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GHOST_LAKILESTER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_ALBINO_DINO] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_EMBER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BONY_BEETLE] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_DRY_BONES] = { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    [ACTOR_TYPE_DRY_BONES2] = { .tattleCam = { 0, 3, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BOMBSHELL_BLASTER] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BOMBSHELL_BILL] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_HAMMER_BROS] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_KOOPATROL] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MAGICLONE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_MAGICLONE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_RED_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GREEN_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_YELLOW_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GRAY_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_WHITE_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_5B] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_5C] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_5D] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_5E] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_5F] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_60] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_61] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_62] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_63] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_64] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_65] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_66] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_67] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_68] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_69] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_6A] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MONTY_HOLE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_6C] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_6D] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PLAYER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GOOMBARIO] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_KOOPER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BOMBETTE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PARAKARRY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BOW] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_WATT] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SUSHIE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LAKILESTER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TWINK] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_78] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_UNUSED_79] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_THE_MASTER_1] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_THE_MASTER_2] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_THE_MASTER_3] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CHAN] = { .tattleCam = { 0, 10, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_GOOMBARIO] = { .tattleCam = { 0, 6, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_KOOPER] = { .tattleCam = { 0, 2, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_BOMBETTE] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_PARAKARRY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_BOW] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_WATT] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_SUSHIE] = { .tattleCam = { 0, 8, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LEE_LAKILESTER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_KAMMY_KOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA1] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA2] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA3] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA4] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA5] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA6] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA_DUP1] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_JR_TROOPA_DUP2] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_RED_GOOMBA_BOSS] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GOOMBA_KING] = { .tattleCam = { 0, 6, 10 }, .shadow = 0 },
    [ACTOR_TYPE_GOOMNUT_TREE] = { .tattleCam = { 8, 12, 17 }, .shadow = 0 },
    [ACTOR_TYPE_GOOMBARIO_TUTOR1] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MAGIKOOPA_BOSS] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MAGIKOOPA_DUP1] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MAGIKOOPA_DUP2] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_FAKE_BOWSER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_KOOPA_BROS] = { .tattleCam = { 0, 0, 26 }, .shadow = 26 },
    [ACTOR_TYPE_GREEN_NINJAKOOPA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_RED_NINJAKOOPA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BLUE_NINJAKOOPA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_YELLOW_NINJAKOOPA] = { .tattleCam = { 0, 4, 0 }, .shadow = 0 },
    [ACTOR_TYPE_ELDSTAR] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BUZZAR] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TUTANKOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CHOMP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TUBBA_BLUBBA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TUBBA_HEART] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_STILT_GUY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SHY_STACK] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SHY_SQUAD] = { .tattleCam = { 0, 5, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GENERAL_GUY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TOY_TANK] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LIGHT_BULB] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SIGNAL_GUY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SHY_SQUAD_DUP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SHY_GUY_DUP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_ANTI_GUY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_ANTI_GUY_DUP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BIG_LANTERN_GHOST] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_GOOMBA_KING_DUP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1] = { .tattleCam = { 25, 250, 60 }, .shadow = 0 },
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2] = { .tattleCam = { 25, 250, 60 }, .shadow = 0 },
    [ACTOR_TYPE_LAVA_BUD_PHASE_1] = { .tattleCam = { 0, 233, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LAVA_BUD_PHASE_2] = { .tattleCam = { 0, 233, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PETIT_PIRANHA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_KENT_C_KOOPA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_HUFF_N_PUFF] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_TUFF_PUFF] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_MONSTAR] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CRYSTAL_KING] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CRYSTAL_CLONE] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_CRYSTAL_BIT] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_INTRO_BOWSER] = { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    [ACTOR_TYPE_BOWSER_PHASE_1] = { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    [ACTOR_TYPE_BOWSER_DUP1] = { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    [ACTOR_TYPE_BOWSER_PHASE_2] = { .tattleCam = { 241, 19, 45 }, .shadow = 241 },
    [ACTOR_TYPE_BOWSER_DUP2] = { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    [ACTOR_TYPE_BOWSER_PHASE_3] = { .tattleCam = { 241, 19, 45 }, .shadow = 241 },
    [ACTOR_TYPE_BOWSER_DUP3] = { .tattleCam = { 0, 0, 0 }, .shadow = 241 },
    [ACTOR_TYPE_BLOOPER] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_ELECTRO_BLOOPER1] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_ELECTRO_BLOOPER2] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SUPER_BLOOPER1] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SUPER_BLOOPER2] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_BLOOPER_BABY] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_LAKILESTER_DUP] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SLOT_MACHINE_START] = { .tattleCam = { 0, 226, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SLOT_MACHINE_STOP] = { .tattleCam = { 0, 226, 0 }, .shadow = 0 },
    [ACTOR_TYPE_WHACKA] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
};

u32 bMarioIdleAnims[] = {
    STATUS_NORMAL, ANIM_WALKING,
    STATUS_DANGER, ANIM_PANTING,
    STATUS_STONE, 0x00050001,
    STATUS_SLEEP, 0x00030004,
    STATUS_DIZZY, 0x00030006,
    STATUS_STOP, ANIM_STAND_STILL,
    STATUS_HUSTLE, ANIM_RUNNING,
    STATUS_BERSERK, 0x00040028,
    STATUS_PARALYZE, 0x00030004,
    STATUS_FROZEN, 0x0001000E,
    0xE, 0x00010002,
    STATUS_TURN_DONE, ANIM_STAND_STILL,
    0x13, 0x00040029,
    0x14, 0x0004002A,
    0x15, 0x00030003,
    0x18, 0x00030005,
    0x16, 0x0010001,
    STATUS_THINKING, ANIM_THINKING,
    STATUS_WEARY, 0x0001000D,
    STATUS_END,
};

s32 bMarioDefendAnims[] = {
    STATUS_NORMAL, ANIM_CROUCH,
    STATUS_DANGER, ANIM_PANTING,
    STATUS_STONE, 0x00050001,
    STATUS_SLEEP, 0x00030004,
    STATUS_DIZZY, 0x00030006,
    STATUS_STOP, ANIM_STAND_STILL,
    STATUS_HUSTLE, ANIM_CROUCH,
    STATUS_BERSERK, ANIM_CROUCH,
    STATUS_PARALYZE, 0x00030004,
    STATUS_FROZEN, 0x0001000E,
    0xE, 0x00010002,
    STATUS_TURN_DONE, ANIM_STAND_STILL,
    0x13, 0x00040029,
    0x14, 0x0004002A,
    0x15, 0x00030003,
    0x18, 0x00030005,
    0x16, 0x0010001,
    STATUS_THINKING, ANIM_THINKING,
    STATUS_WEARY, 0x0001000D,
    STATUS_END,
};

s32 bMarioHideAnims[] = {
    STATUS_NORMAL, ANIM_CROUCH,
    STATUS_DANGER, ANIM_PANTING,
    STATUS_STONE, 0x00050001,
    STATUS_SLEEP, 0x00030004,
    STATUS_DIZZY, 0x00030006,
    STATUS_STOP, ANIM_STAND_STILL,
    STATUS_HUSTLE, 0x0008000E,
    STATUS_BERSERK, 0x0008000E,
    STATUS_PARALYZE, 0x00030004,
    STATUS_FROZEN, 0x0001000E,
    0xE, 0x00010002,
    STATUS_TURN_DONE, ANIM_CROUCH,
    0x13, 0x00040029,
    0x14, 0x0004002A,
    0x15, 0x00030003,
    0x18, 0x00030005,
    0x16, 0x0010001,
    STATUS_THINKING, ANIM_THINKING,
    STATUS_WEARY, 0x0001000D,
    STATUS_END,
};

s32 bPeachIdleAnims[] = {
    STATUS_NORMAL, 0x000A0002,
    STATUS_TURN_DONE, 0x000C0028,
    STATUS_END,
};

s32 bMarioDefenseTable[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 bPlayerStatusTable[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorBlueprint bPlayerActorBlueprint = {
    .type = ACTOR_TYPE_PLAYER,
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

ActorPartBlueprint bMarioParts[] = {
    {
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = bMarioIdleAnims,
        .defenseTable = bMarioDefenseTable,
    },
};

Vec3s btl_actorHomePositions[] = {
    { 5, 0, -20 },
    { 45, 0, -5 },
    { 85, 0, 10 },
    { 125, 0, 25 },
    { 10, 50, -20 },
    { 50, 45, -5 },
    { 90, 50, 10 },
    { 130, 55, 25 },
    { 15, 85, -20 },
    { 55, 80, -5 },
    { 95, 85, 10 },
    { 135, 90, 25 },
    { 15, 125, -20 },
    { 55, 120, -5 },
    { 95, 125, 10 },
    { 135, 130, 25 },
    { 105, 0, 0 },
};

// TODO: what is this, and look into warnings that are silenced via casts
s32* D_8028358C[] = {
    (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1,
    (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C,
    (s32*)D_8028358C, (s32*)D_8028358C, 0
};

s16 bMsgHeights[] = { 28, 40 }; // keyed by number of lines in the message (1 or 2)
s16 D_802835D4[] = { 0, -2 };
s16 D_802835D8[] = { 0, -12 };

f32 D_802835DC[] = {
    0.0f, 4.5, 0.0f, 1.0f, 4.0f, 0.0f, 2.0f, 3.0f, 0.0f, 3.0f, 2.0f, 0.0f, 3.5f, 1.0f, 0.0f, 4.0f, 0.0f, 0.0f, 4.5,
    0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 4.5, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f, 3.5f, -1.0f, 0.0f, 3.0f, -2.0f, 0.0f, 2.0f, -3.0f,
    0.0f, 1.0f, -4.0f, 0.0f, 0.0f, -4.5f, 0.0f,
};

f32 D_80283690[] = {
    1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f,
    0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f,
    1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f,
};

extern void D_80283D98;
UNK_PTR D_80283744[] = {
    NULL, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98,
};

s32 bMessages[] = {
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

s32 bActorMessages[] = {
    MSG_party_mario, MSG_party_goombario, MSG_party_kooper, MSG_party_bombette, MSG_party_parakarry, MSG_party_goompa, MSG_party_watt, MSG_party_sushie, MSG_party_lakilester, MSG_party_bow, MSG_party_goombaria, MSG_party_twink, MSG_party_peach
};
PopupMessage* D_802838F8 = NULL;

extern PopupMessage popupMessages[32];
extern s16 D_8029F64C;
extern s16 D_8029F640;
extern s16 D_8029F64A;
extern s16 D_8029F64E;
extern s16 D_8029F650;

void func_8024FB3C(PopupMessage* popup);
void btl_show_message_popup(PopupMessage* popup);

void func_8024EDC0(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        popup->active = FALSE;
        popup->message = NULL;
    }
}

void func_8024EDEC(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
            popup->message = NULL;
        }
        popup->active = FALSE;
    }
}

void func_8024EE48(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->updateFunc != NULL) {
            popup->updateFunc(popup);
        }
    }
}

void func_8024EEA8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->unk_08 != NULL) {
            popup->unk_08(popup);
        }
    }
}

void btl_draw_popup_messages(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->drawFunc != NULL) {
            popup->drawFunc(popup);
        }
    }
}

PopupMessage* btl_create_popup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (!popup->active) {
            popup->active = TRUE;
            return popup;
        }
    }

    return NULL;
}

void free_popup(PopupMessage* popup) {
    if (popup->message != NULL) {
        heap_free(popup->message);
        popup->message = NULL;
    }
    popup->active = FALSE;
}

INCLUDE_ASM(s32, "17D6A0", func_8024EFE0);

void func_8024F394(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00 != 0) {
            s32 modelIdx = message->unk_04;

            found = TRUE;
            if (message->unk_24 != 0) {
                message->unk_24--;
                if (message->unk_24 == 0) {
                    clear_entity_model_flags(modelIdx, MODEL_FLAGS_FLAG_20);
                }
                exec_entity_model_commandlist(modelIdx);
                break;
            } else {
                exec_entity_model_commandlist(modelIdx);
                if (message->unk_20 >= 0) {
                    message->unk_38 += message->unk_14;
                    message->unk_3C += message->unk_18;
                    message->unk_40 += message->unk_1C;
                }
                message->unk_30 = clamp_angle(180.0f - gCameras[CAM_BATTLE].currentYaw);
                message->unk_28 += message->unk_2C;
                message->unk_28 = clamp_angle(message->unk_28);
                message->unk_2C *= 0.8;
                if (message->unk_20 < 10) {
                    message->unk_08 *= 0.5;
                    message->unk_0C *= 0.5;
                    message->unk_10 *= 0.5;
                    message->unk_14 = message->unk_08;
                    message->unk_18 = message->unk_0C;
                    message->unk_1C = message->unk_10;
                }

                message->unk_20--;
                if (message->unk_20 < 0) {
                    message->unk_44--;
                    if (message->unk_44 < 0) {
                        free_entity_model_by_index(modelIdx);
                        message->unk_00 = 0;
                    }
                }
            }
        }
    }

    if (!found) {
        heap_free(popup->message);
        popup->message = NULL;
        free_popup(popup);
    }
}

void func_8024F5AC(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f sp1D8;
    Mtx sp218;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00 != 0) {
            if (message->unk_24 != 0) {
                break;
            } else {
                s32 modelIdx = message->unk_04;

                guTranslateF(sp18, message->unk_38, message->unk_3C, message->unk_40);
                guRotateF(sp58, 0.0f, 1.0f, 0.0f, 0.0f);
                guRotateF(sp98, message->unk_30, 0.0f, 1.0f, 0.0f);
                guRotateF(spD8, message->unk_28, 0.0f, 0.0f, 1.0f);
                guScaleF(sp1D8, message->unk_34, message->unk_34, message->unk_34);
                guMtxCatF(spD8, sp58, sp158);
                guMtxCatF(sp158, sp98, sp118);
                guMtxCatF(sp1D8, sp118, sp158);
                guMtxCatF(sp158, sp18, sp198);
                guMtxF2L(sp198, &sp218);
                draw_entity_model_A(modelIdx, &sp218);
            }
        }
    }
}

void func_8024F768(void* data) {
    Message* message = data;
    s32 var_a3 = message->unk_44;

    if (var_a3 > 0xA) {
        var_a3 = 0xA;
    }
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, (var_a3 * 255) / 10);
}

void func_8024F7C8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];

        if (popup->active && (popup->active & 0x10)) {
            Message* message = popup->message;
            s32 j;

            for (j = 0; j < popup->messageIndex; j++, message++) {
                if (message->unk_00 != 0) {
                    message->unk_24 = 0;
                    message->unk_20 = 1;
                    message->unk_44 = 20;
                }
            }
        }
    }
}

ApiStatus func_8024F84C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 arg4 = evt_get_variable(script, *args++);
    s32 arg5 = evt_get_variable(script, *args++);
    s32 arg6 = evt_get_variable(script, *args++);

    func_8024EFE0(x, y, z, arg4, arg5, arg6);
    return ApiStatus_DONE2;
}

ApiStatus func_8024F940(Evt* script, s32 isInitialCall) {
    func_8024F7C8();
    return ApiStatus_DONE2;
}

void btl_show_battle_message(s32 messageIndex, s32 duration) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = func_8024FB3C;
        popup->drawFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->unk_08 = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        popup->unk_17 = 1;
        popup->message = NULL;
        D_8029F640 = 0;
        D_802838F8 = popup;
        D_8029F64A = 0;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

void btl_show_variable_battle_message(s32 messageIndex, s32 duration, s32 varValue) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = func_8024FB3C;
        popup->drawFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->unk_08 = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        popup->unk_17 = 1;
        popup->message = NULL;
        D_8029F640 = varValue;
        D_802838F8 = popup;
        D_8029F64A = 0;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

s32 btl_is_popup_displayed(void) {
    return D_802838F8 != NULL;
}

void btl_set_popup_duration(s32 duration) {
    PopupMessage* popup = D_802838F8;

    if (D_8029F64A != NULL && popup != NULL) {
        popup->duration = duration;
    }
}

void func_8024FAE8(void) {
    D_8029F64C = 1;
}

void func_8024FAFC(void) {
    D_8029F64C = 0;
}

void close_action_command_instruction_popup(void) {
    PopupMessage* popup = D_802838F8;

    if (popup != NULL && popup->messageIndex < 67 && popup->messageIndex >= 46) {
        popup->duration = 0;
    }
}

INCLUDE_ASM(s32, "17D6A0", func_8024FB3C);

void func_80250818(void);
INCLUDE_ASM(s32, "17D6A0", func_80250818);

void btl_show_message_popup(PopupMessage* popup) {
    s32 numLines;
    s32 posX;
    s32 posY = 80;
    s32 width;
    s32 msgWidth;
    s32 height;

    switch (popup->messageIndex) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 80:
        case 82:
        case 83:
        case 84:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 30;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
            if (popup->unk_17 != 0) {
                popup->unk_17 = 0;
                msgWidth = get_msg_width(bMessages[popup->messageIndex], 0) + 55;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                height = 40;
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                set_message_value(D_8029F640, 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 81:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                set_message_msg(bActorMessages[D_8029F640], 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                posY = 192;
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                if (popup->messageIndex == 0x3B) {
                    posY = 120;
                    D_8029F64C = 1;
                }
                D_8029F64E = posY;
                D_8029F650 = D_802835D8[numLines];

                posY = D_8029F64E + D_8029F650;
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                if (popup->messageIndex == 0x3B) {
                    set_window_update(9, 1);
                } else {
                    set_window_update(9, 8);
                }
            }
            break;
    }
}

ApiStatus ShowMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    btl_show_battle_message(messageIndex, duration);
    return ApiStatus_DONE2;
}

ApiStatus ShowVariableMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 varValue = evt_get_variable(script, *args++);

    btl_show_variable_battle_message(messageIndex, duration, varValue);
    return ApiStatus_DONE2;
}

ApiStatus IsMessageBoxDisplayed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, btl_is_popup_displayed());
    return ApiStatus_DONE2;
}

ApiStatus WaitForMessageBoxDone(Evt* script, s32 isInitialCall) {
    return !btl_is_popup_displayed() * ApiStatus_DONE2;
}

ApiStatus ForceCloseMessageBox(Evt* script, s32 isInitialCall) {
    if (D_802838F8 != NULL) {
        D_802838F8->duration = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetMessageBoxDuration(Evt* script, s32 isInitialCall) {
    btl_set_popup_duration(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_80251434(Evt* script, s32 isInitialCall) {
    func_8024FAE8();
    return ApiStatus_DONE2;
}

ApiStatus func_80251454(Evt* script, s32 isInitialCall) {
    func_8024FAFC();
    return ApiStatus_DONE2;
}

void func_80251474(Actor* actor) {
    ActorPart* part = actor->partsTable;

    while (part != NULL) {
        if (!(part->flags & ACTOR_PART_FLAG_INVISIBLE) &&
            part->idleAnimations != NULL &&
            !(part->flags & ACTOR_PART_FLAG_40000000))
        {
            f32 x = part->currentPos.x;
            f32 y = part->currentPos.y + (actor->size.y / 10);
            f32 z = part->currentPos.z;
            s32 f1 = (part->size.x + (part->size.x / 4)) * actor->scalingFactor;
            s32 f2 = (part->size.y - 2) * actor->scalingFactor;

            if (actor->flags & 0x8000) {
                y -= actor->size.y / 2;
            }

            fx_flashing_box_shockwave(0, x, y, z, f1, f2);
        }
        part = part->nextPart;
    }
}
