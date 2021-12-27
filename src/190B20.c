#include "common.h"
#include "nu/nusys.h"
#include "effects.h"
#include "battle/battle.h"
#include "hud_element.h"
#include "message_ids.h"
#include "model.h"
#include "sprite.h"

typedef struct Temp14 {
    /* 0x00 */ s32 dmaStart;
    /* 0x04 */ s32 dmaEnd;
    /* 0x08 */ s32 dmaDest;
    /* 0x0C */ ActorDesc* actorDesc;
    /* 0x10 */ s32 y;
} Temp14; // size = 0x14

s32 D_80280FC0[] = {
    0x000A005A, 0x00000032, 0x0003000B, 0x00000032, 0x0001002D, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x00010031, 0x00000032, 0x00010031, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x00010032, 0x00000032, 0x00010032, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000032, 0x0003000A, 0x00000032, 0x0003000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000050, 0x0003000A, 0x00000014, 0x0003000B, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
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
    [ACTOR_TYPE_GOOMBARIO_TUTOR2] = MSG_party_goombario,
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
    [ACTOR_TYPE_GOOMBARIO_TUTOR2] = { .walk = { 0x0000, 0x0000 }, .fly = { 0x0000, 0x0000 }, .jump = 0x0000, .hurt = 0x0000, .delay = { 30, 30 } },
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
    [ACTOR_TYPE_GOOMBARIO_TUTOR2] = NULL,
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
    [ACTOR_TYPE_GOOMBARIO_TUTOR2] = { .tattleCam = { 0, 0, 0 }, .shadow = 0 },
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

s32 bMarioIdleAnims[] = {
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

ActorDesc bPlayerActorDesc = {
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

Vec3s D_80283524[] = {
    { 0x0005, 0x0000, 0xFFEC },
    { 0x002D, 0x0000, 0xFFFB },
    { 0x0055, 0x0000, 0x000A },
    { 0x007D, 0x0000, 0x0019 },
    { 0x000A, 0x0032, 0xFFEC },
    { 0x0032, 0x002D, 0xFFFB },
    { 0x005A, 0x0032, 0x000A },
    { 0x0082, 0x0037, 0x0019 },
    { 0x000F, 0x0055, 0xFFEC },
    { 0x0037, 0x0050, 0xFFFB },
    { 0x005F, 0x0055, 0x000A },
    { 0x0087, 0x005A, 0x0019 },
    { 0x000F, 0x007D, 0xFFEC },
    { 0x0037, 0x0078, 0xFFFB },
    { 0x005F, 0x007D, 0x000A },
    { 0x0087, 0x0082, 0x0019 },
    { 0x0069, 0x0000, 0x0000 },
};

s32 D_8028358C[] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                     &D_8028358C, &D_8028358C, &D_8028358C, &D_8028358C, &D_8028358C, &D_8028358C, &D_8028358C, &D_8028358C,
                     0x00000000,
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

s32 D_802838F8 = 0;

extern Temp14 D_80283F10[];

extern EvtSource D_80293820;
extern f32 D_802938A4;
extern s16 D_802938A8;
extern EffectInstance* gDamageCountEffects[24];
extern s32 gDamageCountTimers[24];
extern Gfx D_80293970[];
extern s32 D_802939C0;
extern s32 D_802939C4[0];
extern s32 D_80293A10[0];
extern s32 D_80293A34[0];
extern s32 D_80293A58[0];
extern s32 D_80293A7C[0];
extern s32 D_80293AA0[0];
extern s32 D_80293AC4[0];

s32 func_80265CE8(u32*, s32);

void create_target_list(Actor* actor, s32 arg1);
INCLUDE_ASM(s32, "190B20", create_target_list);

void player_create_target_list(Actor* actor) {
    create_target_list(actor, 0);
}

void enemy_create_target_list(Actor* actor) {
    create_target_list(actor, 1);
}

void func_80263064(s32, s32, s32);
INCLUDE_ASM(s32, "190B20", func_80263064);

void func_80263230(s32 arg0, s32 arg1) {
    func_80263064(arg0, arg1, 0);
}

void func_8026324C(s32 arg0, s32 arg1) {
    func_80263064(arg0, arg1, 1);
}

void func_80263268(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* partner = battleStatus->partnerActor;

    battleStatus->changePartnerAllowed = 0;
    if (partner != NULL) {
        s32 partnersEnabled;
        s32 i;

        battleStatus->changePartnerAllowed = 1;
        partnersEnabled = 0;

        for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
            if (playerData->partners[i].enabled) {
                partnersEnabled++;
            }
        }

        if (partnersEnabled >= 2) {
            if (partner->koStatus == STATUS_DAZE) {
                battleStatus->changePartnerAllowed = 0;
            } else if (partner->debuff == 7) {
                battleStatus->changePartnerAllowed = 0;
            } else if (playerData->currentPartner == PARTNER_GOOMPA) {
                battleStatus->changePartnerAllowed = -1;
            }
        } else {
            battleStatus->changePartnerAllowed = -1;
        }
    } else {
        battleStatus->changePartnerAllowed = -1;
    }
}

void func_80263300(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    PlayerData* playerData = &gPlayerData;
    s32 cond;
    s32 i;

    battleStatus->menuStatus[0] = 0;
    cond = FALSE;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        s16 itemID = playerData->invItems[i];

        if (itemID != 0) {
            StaticItem* staticItem = &gItemTable[itemID];

            if (staticItem->typeFlags & 2) {
                battleStatus->moveCategory = 2;
                battleStatus->selectedItemID = playerData->invItems[i];
                battleStatus->currentTargetListFlags = staticItem->targetFlags;
                player_create_target_list(player);

                if (player->targetListLength != 0) {
                    battleStatus->menuStatus[0] += 1;
                    cond = TRUE;
                }
            }
        }
    }

    if (!cond) {
        battleStatus->menuStatus[0] = 0;
    }
}

s32 btl_are_all_enemies_defeated(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* enemy;
    s32 enemiesStillAlive = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        s32 flagEnemyDefeated = ENEMY_FLAGS_400000 | ENEMY_FLAGS_4000;
        enemy = battleStatus->enemyActors[i];

        // If currentEnemyFlags signify that the enemy isn't dead yet...
        if (enemy != NULL && !(enemy->flags & flagEnemyDefeated)) {
            // Countinue the battle
            enemiesStillAlive = TRUE;
        }
    }
    return !enemiesStillAlive;
}

s32 btl_check_enemies_defeated(void) {
    if (btl_are_all_enemies_defeated()) {
        btl_set_state(0x1A);
        return TRUE;
    }
    return FALSE;
}

s32 btl_check_player_defeated(void) {
    if (gPlayerData.curHP > 0) {
        return FALSE;
    }
    D_800DC4E4 = gBattleState;
    D_800DC4D8 = gBattleState2;
    btl_set_state(0x1B);
    return TRUE;
}


void btl_init_menu_boots(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    StaticMove* move;
    s32 i;
    s32 moveCount;
    s32 hasAnyBadgeMoves;
    s32 fpCost;

    // If you don't have boots equipped, disable this menu
    if (playerData->bootsLevel == -1) {
        battleStatus->menuStatus[1] = 0;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
        battleStatus->submenuMoves[i] = MOVE_NONE;
    }

    // Standard jump move
    moveCount = 1;
    battleStatus->submenuMoves[0] = playerData->bootsLevel + MOVE_JUMP1;
    battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;

    // Jump badges
    do {
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            s16 badge = playerData->equippedBadges[i];
            if (badge != ITEM_NONE) {
                StaticMove* moveTable = gMoveTable;
                u8 moveID = gItemTable[badge].moveID;

                move = &moveTable[moveID];
                if (move->battleSubmenu == BATTLE_SUBMENU_JUMP) {
                    battleStatus->submenuMoves[moveCount] = moveID;
                    battleStatus->submenuIcons[moveCount] = playerData->equippedBadges[i];
                    moveCount++;
                }
            }
        }
    } while (0);

    battleStatus->submenuMoveCount = moveCount;

    hasAnyBadgeMoves = FALSE;
    for (i = 0; i < battleStatus->submenuMoveCount; i++) {
        move = &gMoveTable[battleStatus->submenuMoves[i]];

        // Calculate FP cost
        fpCost = move->costFP;
        if (fpCost != 0) {
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_SAVER);
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_FANATIC) * 2;
            if (fpCost < 1) {
                fpCost = 1;
            }
        }

        // See if there are any targets for this move
        battleStatus->moveCategory = 0;
        battleStatus->selectedItemID = playerData->bootsLevel;
        battleStatus->currentTargetListFlags = move->flags; // Controls target filters
        player_create_target_list(player);

        // If there are targets, enable the move
        if (player->targetListLength != 0) {
            hasAnyBadgeMoves = TRUE;
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_ENABLED;
        }

        // If you don't have enough FP, disable the move
        if (playerData->curFP < fpCost) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NOT_ENOUGH_FP;
        }

        // If there are no targets available, disable the move
        if (player->targetListLength == 0) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS_2;
        }
        if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
            battleStatus->submenuStatus[moveCount] = BATTLE_SUBMENU_STATUS_NO_TARGETS;
        }
    }

    if (!hasAnyBadgeMoves) {
        // Only the standard jump is available - no badge moves.
        // Selecting this submenu should immediately pick the standard jump move
        battleStatus->menuStatus[1] = -1;
    } else {
        // Enable this submenu
        battleStatus->menuStatus[1] = 1;
    }
}


void btl_init_menu_hammer(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    StaticMove* move;
    s32 i;
    s32 moveCount;
    s32 hasAnyBadgeMoves;
    s32 fpCost;

    // If you don't have a hammer, disable this menu
    if (playerData->hammerLevel == -1) {
        battleStatus->menuStatus[2] = 0;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
        battleStatus->submenuMoves[i] = 0;
    }

    // Standard hammer move
    moveCount = 1;
    battleStatus->submenuMoves[0] = playerData->hammerLevel + MOVE_HAMMER1;
    battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;

    // Hammer badges
    do {
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            s16 badge = playerData->equippedBadges[i];
            if (badge != MOVE_NONE) {
                StaticMove* moveTable = gMoveTable;
                u8 moveID = gItemTable[badge].moveID;
                move = &moveTable[moveID];
                if (move->battleSubmenu == BATTLE_SUBMENU_HAMMER) {
                    battleStatus->submenuMoves[moveCount] = moveID;
                    battleStatus->submenuIcons[moveCount] = playerData->equippedBadges[i];
                    moveCount++;
                }
            }
        }
    } while (0);

    battleStatus->submenuMoveCount = moveCount;

    hasAnyBadgeMoves = FALSE;
    for (i = 0; i < battleStatus->submenuMoveCount; i++) {
            move = &gMoveTable[battleStatus->submenuMoves[i]];

            // Calculate FP cost
            fpCost = move->costFP;
            if (fpCost != 0) {
                fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_SAVER);
                fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_FANATIC) * 2;
                if (fpCost < 1) {
                    fpCost = 1;
                }
            }

            // See if there are any targets for this move
            battleStatus->moveCategory = 1;
            battleStatus->selectedItemID = playerData->hammerLevel;
            battleStatus->currentTargetListFlags = move->flags;
            player_create_target_list(player);

            // If there are targets, enable the move
            if (player->targetListLength != 0) {
                hasAnyBadgeMoves = TRUE;
                battleStatus->submenuStatus[i] = 1;
            }

            // If you don't have enough FP, disable the move
            if (playerData->curFP < fpCost) {
                battleStatus->submenuStatus[i] = 0;
            }

            // If there are no targets available, disable the move
            if (player->targetListLength == 0) {
                battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS_2;
            }
            if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
                battleStatus->submenuStatus[moveCount] = BATTLE_SUBMENU_STATUS_NO_TARGETS;
            }
    }

    if (!hasAnyBadgeMoves) {
        // Only the standard hammer is available - no badge moves.
        // Selecting this submenu should immediately pick the standard hammer move
        battleStatus->menuStatus[2] = -1;
    } else {
        // Enable this submenu
        battleStatus->menuStatus[2] = 1;
    }
}

void btl_init_menu_partner(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 fpCost;
    s32 i;
    s32 hasAnyBadgeMoves;

    for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
        battleStatus->submenuMoves[i] = 0;
    }

    // In the move table (enum MoveIDs), partners get move IDs set up like this:
    //
    //  Move ID offset | Description          | Goombario example
    // ----------------+----------------------+-------------------
    //  0              | No rank only         | Headbonk
    //  1              | Super rank only      | Headbonk (2)
    //  2              | Ultra rank only      | Headbonk (3)
    //  3              | Always unlocked      | Tattle
    //  4              | Unlocked after super | Charge
    //  5              | Unlocked after ultra | Multibonk

    battleStatus->submenuMoveCount = partner->staticActorData->level + 2;

    // Offsets 0,1,2
    battleStatus->submenuMoves[0] =
        playerData->currentPartner * 6
        + (MOVE_HEADBONK1 - 6)
        + partner->staticActorData->level;

    // Offsets 3,4,5
    for (i = 1; i < battleStatus->submenuMoveCount; i++) {
        battleStatus->submenuMoves[i] =
            playerData->currentPartner * 6
            + (MOVE_TATTLE - 6)
            + (i - 1);
    }

    hasAnyBadgeMoves = FALSE;
    for (i = 0; i < battleStatus->submenuMoveCount; i++){
            StaticMove* move = &gMoveTable[battleStatus->submenuMoves[i]];

            fpCost = move->costFP;
            if (fpCost != 0) {
                fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_SAVER);
                fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_FANATIC) * 2;
                if (fpCost < 1) {
                    fpCost = 1;
                }
            }

            battleStatus->moveCategory = 5;
            battleStatus->selectedItemID = partner->staticActorData->level;
            battleStatus->currentTargetListFlags = move->flags;
            player_create_target_list(partner);

            if (partner->targetListLength != 0){
                hasAnyBadgeMoves = TRUE;
                battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_ENABLED;
            }

            if (partner->targetListLength == 0) {
                battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS_2;
            }

            if (playerData->curFP < fpCost) {
                battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NOT_ENOUGH_FP;
            }
            if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
                battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS;
            }

    }

    if (!hasAnyBadgeMoves) {
        battleStatus->menuStatus[3] = -1;
    } else {
        battleStatus->menuStatus[3] = 1;
    }
}

s32 count_power_plus(s32 arg0) {
    s32 pp;
    s32 i;

    if (gGameStatusPtr->peachFlags & 1) {
        return 0;
    }

    pp = 0;
    for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
        u8 moveID = gItemTable[gPlayerData.equippedBadges[i]].moveID;

        if (gMoveTable[moveID].battleSubmenu == 7 && moveID == MOVE_POWER_PLUS) {
            if (gBattleStatus.flags1 & BS_FLAGS1_10 || arg0 & 0x80) {
                pp++;
            }
        }
    }

    return pp;
}

void deduct_current_move_fp(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* actor = battleStatus->playerActor;
    s32 fpCost = gMoveTable[battleStatus->selectedMoveID].costFP;

    if (fpCost != 0) {
        fpCost -= player_team_is_ability_active(actor, ABILITY_FLOWER_SAVER);
        fpCost -= player_team_is_ability_active(actor, ABILITY_FLOWER_FANATIC) * 2;
        if (fpCost < 1) {
            fpCost = 1;
        }
    }

    playerData->curFP -= fpCost;
}

void reset_actor_turn_info(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        actor = battleStatus->enemyActors[i];
        if (actor != NULL) {
            actor->hpChangeCounter = 0;
            actor->damageCounter = 0;
            actor->unk_204 = 0;
        }

    }
    actor = battleStatus->playerActor;
    actor->hpChangeCounter = 0;
    actor->damageCounter = 0;
    actor->unk_204 = 0;

    actor = battleStatus->partnerActor;
    if (actor != NULL) {
        actor->hpChangeCounter = 0;
        actor->damageCounter = 0;
        actor->unk_204 = 0;
    }
}

void func_80263CC4(s32 arg0) {
    start_script(&D_80293820, 10, 0)->varTable[0] = arg0;
}

void set_animation(s32 actorID, s32 partIdx, s32 animationIndex) {
    if (animationIndex >= 0) {
        Actor* actor = get_actor(actorID);
        ActorPart* part;

        switch (actorID & 0x700) {
            case 0x0:
                part = &actor->partsTable[0];
                if (part->currentAnimation != animationIndex) {
                    part->currentAnimation = animationIndex;
                    spr_update_player_sprite(0, animationIndex, part->animationRate);
                }
                break;
            case 0x100:
                if (partIdx != 0) {
                    part = get_actor_part(actor, partIdx);

                    if (part == NULL) {
                        part = &actor->partsTable[0];
                    }
                } else {
                    part = &actor->partsTable[0];
                }

                if (part->currentAnimation != animationIndex) {
                    part->currentAnimation = animationIndex;
                    spr_update_sprite(part->unk_84, animationIndex, part->animationRate);
                    part->unk_8C = func_802DE5C8(part->unk_84);
                }
                break;
            case 0x200:
                part = get_actor_part(actor, partIdx);
                if (part->currentAnimation != animationIndex) {
                    part->currentAnimation = animationIndex;
                    spr_update_sprite(part->unk_84, animationIndex, part->animationRate);
                    part->unk_8C = func_802DE5C8(part->unk_84);
                }
                break;
        }
    }
}

void func_80263E08(Actor* actor, ActorPart* part, s32 anim) {
    if (anim >= 0) {
        switch (actor->actorID & 0x700) {
            case 0x0:
                if (part->currentAnimation != anim) {
                    part->currentAnimation = anim;
                    spr_update_player_sprite(0, anim, part->animationRate);
                }
                break;
            case 0x100:
            case 0x200:
                if (part->currentAnimation != anim) {
                    part->currentAnimation = anim;
                    spr_update_sprite(part->unk_84, anim, part->animationRate);
                    part->unk_8C = func_802DE5C8(part->unk_84);
                }
                break;
        }
    }
}

void set_animation_rate(s32 actorID, s32 partIndex, f32 rate) {
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorID & 0x700) {
        case ACTOR_PARTNER:
            if (partIndex != 0) {
                part = get_actor_part(actor, partIndex);
                if (part != NULL) {
                    part->animationRate = rate;
                    return;
                }
            }
            actor->partsTable[0].animationRate = rate;
            break;
        case ACTOR_PLAYER:
        case ACTOR_ENEMY0:
            part = get_actor_part(actor, partIndex);
            part->animationRate = rate;
            break;
    }
}

void set_actor_yaw(s32 actorID, s32 yaw) {
    get_actor(actorID)->yaw = yaw;
}

void set_part_yaw(s32 actorID, s32 partIndex, s32 value) {
    get_actor_part(get_actor(actorID), partIndex)->yaw = value;
}

void func_80263FE8(s32 actorID, s32 partIndex, s32 flags) {
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorID & 0x700) {
        case ACTOR_PLAYER:
            actor->flags |= flags;
            break;
        case ACTOR_PARTNER:
        case ACTOR_ENEMY0:
            if (partIndex == 0) {
                actor->flags |= flags;
            } else {
                part = get_actor_part(actor, partIndex);
                part->flags |= flags;
            }
            break;
    }
}

void func_80264084(s32 actorID, s32 partIndex, s32 flags) {
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorID & 0x700) {
        case ACTOR_PLAYER:
            actor->flags &= ~flags;
            break;
        case ACTOR_PARTNER:
        case ACTOR_ENEMY0:
            if (partIndex == 0) {
                actor->flags &= ~flags;
            } else {
                part = get_actor_part(actor, partIndex);
                part->flags &= ~flags;
            }
            break;
    }
}

void add_xz_vec3f(Vec3f* vector, f32 speed, f32 angleDeg) {
    f32 angleRad = angleDeg * TAU / 360.0f;
    f32 sinAngleRad = sin_rad(angleRad);
    f32 cosAngleRad = cos_rad(angleRad);

    vector->x += speed * sinAngleRad;
    vector->z += -speed * cosAngleRad;
}

void add_xz_vec3f_copy1(Vec3f* vector, f32 speed, f32 angleDeg) {
    f32 angleRad = angleDeg * TAU / 360.0f;
    f32 sinAngleRad = sin_rad(angleRad);
    f32 cosAngleRad = cos_rad(angleRad);

    vector->x += speed * sinAngleRad;
    vector->z += -speed * cosAngleRad;
}

void add_xz_vec3f_copy2(Vec3f* vector, f32 speed, f32 angleDeg) {
    f32 angleRad = angleDeg * TAU / 360.0f;
    f32 sinAngleRad = sin_rad(angleRad);
    f32 cosAngleRad = cos_rad(angleRad);

    vector->x += speed * sinAngleRad;
    vector->z += -speed * cosAngleRad;
}

// matching after data migration
#ifdef NON_MATCHING
void play_movement_dust_effects(s32 var0, f32 xPos, f32 yPos, f32 zPos, f32 angleDeg) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;

    if (var0 == 2) {
        fx_land(0, xPos, yPos + 0.0f, zPos, D_802938A4);
    } else if (var0 == 1) {
        D_802938A8 = 4;
    } else if (D_802938A8++ >= 4) {
        D_802938A8 = 0;
        temp_f20 = (clamp_angle(-angleDeg) * TAU) / 360.0f;
        temp_f20_2 = sin_rad(temp_f20);
        temp_f0 = cos_rad(temp_f20);
        fx_walk(0, xPos + (temp_f20_2 * 24.0f * 0.2f), yPos + 1.5f, zPos + (temp_f0 * 24.0f * 0.2f), temp_f20_2, temp_f0);
    }
}
#else
INCLUDE_ASM(void, "190B20", play_movement_dust_effects, s32 var0, f32 xPos, f32 yPos, f32 zPos, f32 angleDeg);
#endif

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

void load_player_actor(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player;
    ActorPart* part;
    DecorationTable* decorationTable;
    ActorPartMovement* partMovement;
    s32 i;
    s32 j;

    battleStatus->playerActor = heap_malloc(sizeof(*player));
    player = battleStatus->playerActor;

    ASSERT(player != NULL);

    player->unk_134 = battleStatus->unk_93++;
    player->footStepCounter = 0;
    player->flags = 0;
    player->staticActorData = &bPlayerActorDesc;
    player->actorType = bPlayerActorDesc.type;

    if ((gBattleStatus.flags2 & BS_FLAGS2_40) || (gGameStatusPtr->demoFlags & 2)) {
        player->homePos.x = player->currentPos.x = -130.0f;
        player->homePos.y = player->currentPos.y = 0.0f;
        player->homePos.z = player->currentPos.z = -10.0f;
    } else {
        player->homePos.x = player->currentPos.x = -95.0f;
        player->homePos.y = player->currentPos.y = 0.0f;
        player->homePos.z = player->currentPos.z = 0.0f;
    }

    player->headOffset.x = 0;
    player->headOffset.y = 0;
    player->headOffset.z = 0;
    player->rotation.x = 0.0f;
    player->rotation.y = 0.0f;
    player->rotation.z = 0.0f;
    player->rotationPivotOffset.x = 0;
    player->rotationPivotOffset.y = 0;
    player->rotationPivotOffset.z = 0;
    player->unk_19A = 0;
    player->yaw = 0.0f;
    player->renderMode = RENDER_MODE_ALPHATEST;
    player->scale.x = 1.0f;
    player->scale.y = 1.0f;
    player->scale.z = 1.0f;
    player->scaleModifier.x = 1.0f;
    player->scaleModifier.y = 1.0f;
    player->scaleModifier.z = 1.0f;
    player->size.x = player->staticActorData->size.x;
    player->size.y = player->staticActorData->size.y;
    player->actorID = 0;
    player->healthBarPosition.x = player->currentPos.x;
    player->healthBarPosition.y = player->currentPos.y;
    player->healthBarPosition.z = player->currentPos.z;
    player->scalingFactor = 1.0f;
    player->unk_200 = NULL;
    player->unk_204 = 0;
    player->unk_205 = 0;
    player->unk_194 = 0;
    player->unk_195 = 0;
    player->unk_196 = 0;
    player->unk_197 = 0;
    player->idleScriptSource = NULL;
    player->takeTurnScriptSource = NULL;
    player->onHitScriptSource = NULL;
    player->onTurnChanceScriptSource = NULL;
    player->idleScript = NULL;
    player->takeTurnScript = NULL;
    player->onHitScript = NULL;
    player->onTurnChangeScript = NULL;
    player->turnPriority = 0;
    player->statusTable = bPlayerStatusTable;
    player->debuff = 0;
    player->debuffDuration = 0;
    player->staticStatus = 0;
    player->staticDuration = 0;
    player->stoneStatus = 0;
    player->stoneDuration = 0;
    player->koStatus = 0;
    player->koDuration = 0;
    player->transStatus = 0;
    player->transDuration = 0;
    player->isGlowing = 0;
    player->unk_21E = 0;
    player->unk_21D = 0;
    player->attackBoost = 0;
    player->defenseBoost = 0;
    player->chillOutAmount = 0;
    player->chillOutTurns = 0;
    player->status = 0;
    player->actorTypeData1[0] = bActorSoundTable[player->actorType].walk[0];
    player->actorTypeData1[1] = bActorSoundTable[player->actorType].walk[1];
    player->actorTypeData1[2] = bActorSoundTable[player->actorType].fly[0];
    player->actorTypeData1[3] = bActorSoundTable[player->actorType].fly[1];
    player->actorTypeData1[4] = bActorSoundTable[player->actorType].jump;
    player->actorTypeData1[5] = bActorSoundTable[player->actorType].hurt;
    player->actorTypeData1b[0] = bActorSoundTable[player->actorType].delay[0];
    player->actorTypeData1b[1] = bActorSoundTable[player->actorType].delay[1];

    for (i = 0; i < ARRAY_COUNT(player->unk_438); i++) {
        player->unk_438[i] = 0;
    }

    part = heap_malloc(sizeof(*part));
    player->partsTable = part;

    ASSERT(part != NULL)

    player->numParts = 1;
    part->staticData = bMarioParts;
    part->partOffset.x = 0;
    part->partOffset.y = 0;
    part->partOffset.z = 0;
    part->partOffset.x = 12;
    part->partOffset.y = 32;
    part->partOffset.z = 5;
    part->decorationTable = NULL;
    part->flags = 0;
    part->targetFlags = 0;
    part->partOffsetFloat.x = 0.0f;
    part->partOffsetFloat.y = 0.0f;
    part->partOffsetFloat.z = 0.0f;
    part->rotationPivotOffset.x = 0;
    part->rotationPivotOffset.y = 0;
    part->rotationPivotOffset.z = 0;
    part->visualOffset.x = 0;
    part->visualOffset.y = 0;
    part->visualOffset.z = 0;
    part->absolutePosition.x = 0.0f;
    part->absolutePosition.y = 0.0f;
    part->absolutePosition.z = 0.0f;
    part->defenseTable = bMarioDefenseTable;

    if (gBattleStatus.flags2 & BS_FLAGS2_40) {
        part->idleAnimations = bPeachIdleAnims;
    } else {
        part->idleAnimations = bMarioIdleAnims;
    }

    part->eventFlags = 0;
    part->partFlags3 = 0;
    part->opacity = 0xFF;
    part->size.y = player->size.y;
    part->size.x = player->size.x;
    part->yaw = 0.0f;
    part->targetOffset.x = 0;
    part->targetOffset.y = 0;
    part->unk_70 = 0;
    part->rotation.x = 0.0f;
    part->rotation.y = 0.0f;
    part->rotation.z = 0.0f;
    part->scale.x = 1.0f;
    part->scale.y = 1.0f;
    part->scale.z = 1.0f;
    part->verticalStretch = 1;
    part->unkOffset[0] = 0;
    part->unkOffset[1] = 0;
    part->animationRate = 1.0f;
    part->currentAnimation = func_80265CE8(part->idleAnimations, 1U);
    part->nextPart = NULL;
    part->partTypeData[0] = bActorSoundTable[player->actorType].walk[0];
    part->partTypeData[1] = bActorSoundTable[player->actorType].walk[1];
    part->partTypeData[2] = bActorSoundTable[player->actorType].fly[0];
    part->partTypeData[3] = bActorSoundTable[player->actorType].fly[1];
    part->partTypeData[4] = bActorSoundTable[player->actorType].jump;
    part->partTypeData[5] = bActorSoundTable[player->actorType].hurt;
    part->actorTypeData2b[0] = bActorSoundTable[player->actorType].delay[0];
    part->actorTypeData2b[1] = bActorSoundTable[player->actorType].delay[1];

    if (part->idleAnimations != NULL) {
        s32 j;

        part->decorationTable = heap_malloc(sizeof(*decorationTable));
        decorationTable = part->decorationTable;

        ASSERT(decorationTable != NULL);

        decorationTable->unk_6C0 = 0;
        decorationTable->unk_750 = 0;
        decorationTable->unk_764 = 0;
        decorationTable->unk_768 = 0;
        decorationTable->unk_7D8 = 0;
        decorationTable->unk_7D9 = 0;

        for (j = 0; j < ARRAY_COUNT(decorationTable->posX); j++) {
            decorationTable->posX[j] = player->currentPos.x;
            decorationTable->posY[j] = player->currentPos.y;
            decorationTable->posZ[j] = player->currentPos.z;
        }

        decorationTable->unk_7DA = 3;
        decorationTable->unk_7DB = 0;
        decorationTable->effectType = 0;

        for (j = 0; j < ARRAY_COUNT(decorationTable->unk_8B0); j++) {
            decorationTable->unk_8B0[j] = NULL;
            decorationTable->decorationType[j] = 0;
        }
    }

    partMovement = heap_malloc(sizeof(*partMovement));
    part->movement = partMovement;

    ASSERT(partMovement != NULL);

    player->shadow = create_shadow_type(0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
    player->shadowScale = player->size.x / 24.0;
    player->hudElementDataIndex = create_status_icon_set();
    player->ptrDefuffIcon = playFX_41(0, -142.0f, 34.0f, 1.0f, 0);
    player->unk_228 = NULL;

    if (is_ability_active(ABILITY_ZAP_TAP)) {
        player->staticStatus = STATUS_STATIC;
        player->staticDuration = 127;
    }
}

void load_partner_actor(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor;
    ActorDesc* actorDesc;
    Evt* takeTurnScript;
    s32 partCount;
    s32 currentPartner;
    Temp14* partnerData;
    f32 x;
    f32 y;
    f32 z;
    ActorPart* part;
    s32 i;
    s32 i2;

    currentPartner = playerData->currentPartner;
    battleStatus->partnerActor = NULL;

    if (currentPartner != PARTNER_NONE) {
        partnerData = &D_80283F10[currentPartner];
        actorDesc = partnerData->actorDesc;

        ASSERT(actorDesc != NULL);

        nuPiReadRom(partnerData->dmaStart, partnerData->dmaDest, partnerData->dmaEnd - partnerData->dmaStart);
        if ((gBattleStatus.flags2 & 0x40) || (gGameStatusPtr->demoFlags & 2)) {
            x = -95.0f;
            y = partnerData->y;
            z = 0.0f;
            gBattleStatus.flags1 |= 0x100000;
        } else {
            x = -130.0f;
            y = partnerData->y;
            z = -10.0f;
        }
        partCount = actorDesc->partCount;
        battleStatus->partnerActor = heap_malloc(sizeof(*partnerActor));
        partnerActor = battleStatus->partnerActor;

        ASSERT(partnerActor != NULL);

        actorDesc->level = playerData->partners[playerData->currentPartner].level;
        partnerActor->unk_134 = battleStatus->unk_93++;
        partnerActor->footStepCounter = 0;
        partnerActor->staticActorData = actorDesc;
        partnerActor->actorType = actorDesc->type;
        partnerActor->flags = actorDesc->flags;
        partnerActor->homePos.x = partnerActor->currentPos.x = x;
        partnerActor->homePos.y = partnerActor->currentPos.y = y;
        partnerActor->homePos.z = partnerActor->currentPos.z = z;
        partnerActor->headOffset.x = 0;
        partnerActor->headOffset.y = 0;
        partnerActor->headOffset.z = 0;
        partnerActor->currentHP = actorDesc->maxHP;
        partnerActor->numParts = partCount;
        partnerActor->idleScriptSource = NULL;
        partnerActor->takeTurnScriptSource = actorDesc->script;
        partnerActor->onHitScriptSource = NULL;
        partnerActor->onTurnChanceScriptSource = NULL;
        partnerActor->idleScript = NULL;
        partnerActor->takeTurnScript = NULL;
        partnerActor->onHitScript = NULL;
        partnerActor->onTurnChangeScript = NULL;
        partnerActor->turnPriority = 0;
        partnerActor->enemyIndex = 0;
        partnerActor->yaw = 0.0f;
        partnerActor->rotation.x = 0.0f;
        partnerActor->rotation.y = 0.0f;
        partnerActor->rotation.z = 0.0f;
        partnerActor->rotationPivotOffset.x = 0;
        partnerActor->rotationPivotOffset.y = 0;
        partnerActor->rotationPivotOffset.z = 0;
        partnerActor->scale.x = 1.0f;
        partnerActor->scale.y = 1.0f;
        partnerActor->scale.z = 1.0f;
        partnerActor->scaleModifier.x = 1.0f;
        partnerActor->scaleModifier.y = 1.0f;
        partnerActor->scaleModifier.z = 1.0f;
        partnerActor->unk_19A = 0;
        partnerActor->size.x = actorDesc->size.x;
        partnerActor->size.y = actorDesc->size.y;
        partnerActor->healthBarPosition.x = partnerActor->homePos.x;
        partnerActor->healthBarPosition.y = partnerActor->homePos.y;
        partnerActor->healthBarPosition.z = partnerActor->homePos.z;
        partnerActor->scalingFactor = 1.0f;
        partnerActor->unk_200 = NULL;
        partnerActor->unk_204 = 0;
        partnerActor->unk_205 = 0;
        partnerActor->unk_194 = 0;
        partnerActor->unk_195 = 0;
        partnerActor->unk_196 = 0;
        partnerActor->unk_197 = 0;
        partnerActor->renderMode = RENDER_MODE_ALPHATEST;
        partnerActor->actorID = ACTOR_PARTNER;
        partnerActor->statusTable = actorDesc->statusTable;
        partnerActor->debuff = 0;
        partnerActor->debuffDuration = 0;
        partnerActor->staticStatus = 0;
        partnerActor->staticDuration = 0;
        partnerActor->stoneStatus = 0;
        partnerActor->stoneDuration = 0;
        partnerActor->koStatus = 0;
        partnerActor->koDuration = 0;
        partnerActor->transStatus = 0;
        partnerActor->transDuration = 0;
        partnerActor->isGlowing = 0;
        partnerActor->unk_21E = 0;
        partnerActor->unk_21D = 0;
        partnerActor->attackBoost = 0;
        partnerActor->defenseBoost = 0;
        partnerActor->chillOutAmount = 0;
        partnerActor->chillOutTurns = 0;
        partnerActor->status = 0;
        partnerActor->actorTypeData1[0] = bActorSoundTable[partnerActor->actorType].walk[0];
        partnerActor->actorTypeData1[1] = bActorSoundTable[partnerActor->actorType].walk[1];
        partnerActor->actorTypeData1[2] = bActorSoundTable[partnerActor->actorType].fly[0];
        partnerActor->actorTypeData1[3] = bActorSoundTable[partnerActor->actorType].fly[1];
        partnerActor->actorTypeData1[4] = bActorSoundTable[partnerActor->actorType].jump;
        partnerActor->actorTypeData1[5] = bActorSoundTable[partnerActor->actorType].hurt;
        partnerActor->actorTypeData1b[0] = bActorSoundTable[partnerActor->actorType].delay[0];
        partnerActor->actorTypeData1b[1] = bActorSoundTable[partnerActor->actorType].delay[1];

        for (i2 = 0; i2 < ARRAY_COUNT(partnerActor->unk_438); i2++) {
            partnerActor->unk_438[i2] = 0;
        }

        part = heap_malloc(sizeof(*part));
        partnerActor->partsTable = part;

        ASSERT(part != NULL);

        for (i = 0; i < partCount; i++) {
            ActorPartDesc* actorPartDesc = &actorDesc->partsData[i];
            part->decorationTable = NULL;
            part->staticData = actorPartDesc;

            part->flags = actorPartDesc->flags | 4;
            part->targetFlags = 0;

            part->partOffsetFloat.x = part->partOffset.x = actorPartDesc->posOffset.x;
            part->partOffsetFloat.y = part->partOffset.y = actorPartDesc->posOffset.y;
            part->partOffsetFloat.z = part->partOffset.z = actorPartDesc->posOffset.z;

            part->visualOffset.x = 0;
            part->visualOffset.y = 0;
            part->visualOffset.z = 0;
            part->absolutePosition.x = 0.0f;
            part->absolutePosition.y = 0.0f;
            part->absolutePosition.z = 0.0f;
            part->defenseTable = actorPartDesc->defenseTable;
            part->idleAnimations = actorPartDesc->idleAnimations;
            part->eventFlags = actorPartDesc->eventFlags;
            part->partFlags3 = actorPartDesc->elementImmunityFlags;
            part->opacity = actorPartDesc->opacity;
            part->size.y = partnerActor->size.y;
            part->size.x = partnerActor->size.x;
            part->yaw = 0.0f;
            part->targetOffset.x = actorPartDesc->targetOffset.x;
            part->targetOffset.y = actorPartDesc->targetOffset.y;
            part->unk_70 = 0;
            part->rotationPivotOffset.x = 0;
            part->rotationPivotOffset.y = 0;
            part->rotationPivotOffset.z = 0;
            part->rotation.x = 0.0f;
            part->rotation.y = 0.0f;
            part->rotation.z = 0.0f;
            part->scale.x = 1.0f;
            part->scale.y = 1.0f;
            part->scale.z = 1.0f;
            part->verticalStretch = 1;
            part->unkOffset[0] = 0;
            part->unkOffset[1] = 0;
            part->partTypeData[0] = bActorSoundTable[partnerActor->actorType].walk[0];
            part->partTypeData[1] = bActorSoundTable[partnerActor->actorType].walk[1];
            part->partTypeData[2] = bActorSoundTable[partnerActor->actorType].fly[0];
            part->partTypeData[3] = bActorSoundTable[partnerActor->actorType].fly[1];
            part->partTypeData[4] = bActorSoundTable[partnerActor->actorType].jump;
            part->partTypeData[5] = bActorSoundTable[partnerActor->actorType].hurt;
            part->actorTypeData2b[0] = bActorSoundTable[partnerActor->actorType].delay[0];
            part->actorTypeData2b[1] = bActorSoundTable[partnerActor->actorType].delay[1];

            if (part->idleAnimations != NULL) {
                DecorationTable* decorationTable;
                s32 j;

                part->decorationTable  = heap_malloc(sizeof(*decorationTable));
                decorationTable = part->decorationTable;

                ASSERT(decorationTable != NULL);

                decorationTable->unk_6C0 = 0;
                decorationTable->unk_750 = 0;
                decorationTable->unk_764 = 0;
                decorationTable->unk_768 = 0;
                decorationTable->unk_7D8 = 0;
                decorationTable->unk_7D9 = 0;

                for (j = 0; j < ARRAY_COUNT(decorationTable->posX); j++) {
                    decorationTable->posX[j] = partnerActor->currentPos.x;
                    decorationTable->posY[j] = partnerActor->currentPos.y;
                    decorationTable->posZ[j] = partnerActor->currentPos.z;
                }

                decorationTable->unk_7DA = 3;
                decorationTable->unk_7DB = 0;
                decorationTable->effectType = 0;

                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_8B0); j++) {
                    decorationTable->unk_8B0[j] = NULL;
                    decorationTable->decorationType[j] = 0;
                }
            }

            if (part->flags >= 0) {
                part->movement = heap_malloc(sizeof(*part->movement));
                ASSERT(part->movement != NULL);
            }

            part->animationRate = 1.0f;
            part->currentAnimation = 0;
            part->unk_84 = -1;

            if (part->idleAnimations != NULL) {
                part->currentAnimation = func_80265CE8(part->idleAnimations, 1);
                part->unk_84 = spr_load_npc_sprite(part->currentAnimation | 0x80000000, NULL);
            }

            if (i + 1 >= partCount) {
                part->nextPart = NULL;
                continue;
            }

            part->nextPart = heap_malloc(sizeof(*part->nextPart));
            part = part->nextPart;
            if (part == NULL) {
                PANIC();
            }

            part->nextPart = NULL;
        }

        partnerActor->shadow = create_shadow_type(0, partnerActor->currentPos.x, partnerActor->currentPos.y, partnerActor->currentPos.z);
        partnerActor->shadowScale = partnerActor->size.x / 24.0;
        partnerActor->hudElementDataIndex = create_status_icon_set();
        partnerActor->ptrDefuffIcon = playFX_41(0, -142.0f, 34.0f, 1.0f, 0);
        partnerActor->unk_228 = NULL;

        takeTurnScript = start_script(partnerActor->takeTurnScriptSource, 10, 0);
        partnerActor->takeTurnID = takeTurnScript->id;
        takeTurnScript->owner1.actorID = ACTOR_PARTNER;
    }
}

INCLUDE_ASM(s32, "190B20", create_actor);

s32 func_80265CE8(u32* anim, s32 arg1) {
    s32 ret;

    if (anim == 0) {
        return 0;
    }

    ret = 0;
    while (*anim != NULL) {
        if (*anim == 1) {
            ret = anim[1];
        }
        if (*anim == arg1) {
            ret = anim[1];
            break;
        }
        anim += 2;
    }
    return ret;
}

s32 func_80265D44(s32 arg0) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    u32* anim = &player->partsTable->idleAnimations[0];
    s32 ret;

    if (anim == NULL) {
        return 0;
    }
    ret = 0;

    if (!(battleStatus->flags2 & BS_FLAGS2_40)) {
        if (playerData->curHP < 6) {
            if (arg0 == 1) {
                arg0 = 26;
            }

            if (arg0 == 18) {
                arg0 = 22;
            }

            if (arg0 == 28) {
                arg0 = 29;
            }
        }

        if (player->debuff == 9) {
            if (arg0 == 1) {
                arg0 = 26;
            }

            if (arg0 == 18) {
                arg0 = 22;
            }

            if (arg0 == 28) {
                arg0 = 29;
            }
        }

        if (player->debuff == 4 && arg0 == 18) {
            arg0 = 24;
        }
    }

    while (*anim != NULL) {
        if (*anim == 1) {
            ret = anim[1];
        }
        if (*anim == arg0) {
            ret = anim[1];
            break;
        }
        anim += 2;
    }

    return ret;
}

s32 lookup_defense(DictionaryEntry* defenseTable, s32 elementKey) {
    s32 normalDefense = 0;

    while (defenseTable->key != ELEMENT_END) {
        if (defenseTable->key == ELEMENT_NORMAL) {
            normalDefense = defenseTable->value;
        }

        if (defenseTable->key == elementKey) {
            normalDefense = defenseTable->value;
            break;
        }
        defenseTable++;
    }

    // Fall back to normal defense if given element is not specified in table
    return normalDefense;
}

s32 lookup_status_chance(DictionaryEntry* statusTable, s32 statusKey) {
    s32 defaultChance = 0;

    while (statusTable->key != STATUS_END) {
        if (statusTable->key == STATUS_DEFAULT) {
            defaultChance = statusTable->value;
        }

        if (statusTable->key == statusKey) {
            defaultChance = statusTable->value;
            break;
        }
        statusTable++;
    }

    // Fall back to normal chance if given element is not specified in table
    return defaultChance;
}

s32 lookup_status_duration_mod(DictionaryEntry* statusTable, s32 statusKey) {
    s32 defaultTurnMod = 0;

    while (statusTable->key != ELEMENT_END) {
        if (statusTable->key == STATUS_DEFAULT_TURN_MOD) {
            defaultTurnMod = statusTable->value;
        }

        if (statusTable->key == statusKey) {
            defaultTurnMod = statusTable->value;
            break;
        }
        statusTable++;
    }

    // Fall back to normal duration if given element is not specified in table
    return defaultTurnMod;
}

s32 inflict_status(Actor* target, s32 statusTypeKey, s32 duration) {
    BattleStatus* battleStatus = &gBattleStatus;
    EffectInstance* effect;

    switch (statusTypeKey) {
        case STATUS_FEAR:
        case STATUS_DIZZY:
        case STATUS_PARALYZE:
        case STATUS_SLEEP:
        case STATUS_FROZEN:
        case STATUS_STOP:
        case STATUS_POISON:
        case STATUS_SHRINK:
            if (target->actorID != ACTOR_PLAYER || (!is_ability_active(ABILITY_FEELING_FINE) &&
                !is_ability_active(ABILITY_BERSERKER) && battleStatus->hustleTurns == 0)) {

                if (target->actorID != ACTOR_PARTNER) {
                    if (target->debuff != statusTypeKey) {
                        target->status = statusTypeKey;
                    }
                    target->ptrDefuffIcon->ptrPropertyList[15] = 0;
                    target->debuff = statusTypeKey;
                    target->debuffDuration = duration;
                    if ((s8)duration > 9) {
                        target->debuffDuration = 9;
                    }

                    switch (statusTypeKey) {
                        case STATUS_FROZEN:
                            if (target->actorID != ACTOR_PARTNER) {
                                effect = target->unk_228;
                                if (effect != NULL) {
                                    effect->flags |= EFFECT_INSTANCE_FLAGS_10;
                                }
                                target->unk_228 = playFX_81(0, target->currentPos.x, target->currentPos.y,
                                                            target->currentPos.z, 1.0f, 0);
                                func_80047820(target->hudElementDataIndex, STATUS_FROZEN);
                            }
                            return TRUE;
                        case STATUS_SLEEP:
                            func_80266DAC(target, 3);
                            func_80047820(target->hudElementDataIndex, STATUS_SLEEP);
                            return TRUE;
                        case STATUS_PARALYZE:
                            func_80266DAC(target, 7);
                            func_80047820(target->hudElementDataIndex, STATUS_PARALYZE);
                            return TRUE;
                        case STATUS_DIZZY:
                            func_80047820(target->hudElementDataIndex, STATUS_DIZZY);
                            return TRUE;
                        case STATUS_FEAR:
                            func_80266DAC(target, 5);
                            func_80047820(target->hudElementDataIndex, STATUS_FEAR);
                            return TRUE;
                        case STATUS_POISON:
                            func_80266DAC(target, 6);
                            func_80047820(target->hudElementDataIndex, STATUS_POISON);
                            return TRUE;
                        case STATUS_SHRINK:
                            func_80047820(target->hudElementDataIndex, STATUS_SHRINK);
                            return TRUE;
                    }
                }
                return TRUE;
            } else {
                return FALSE;
            }
            break;
        case STATUS_STATIC:
            if (target->actorID != ACTOR_PARTNER) {
                target->staticStatus = statusTypeKey;
                target->staticDuration = duration;
                if ((s8)duration > 9) {
                    target->staticDuration = 9;
                }
                target->status = STATUS_STATIC;
                func_80266DAC(target, 4);
                func_80047928(target->hudElementDataIndex, STATUS_STATIC);
            }
            return TRUE;
        case STATUS_STONE:
            if (target->actorID != ACTOR_PARTNER) {
                target->stoneStatus = STATUS_STONE;
                target->stoneDuration = duration;
                if ((s8)duration > 9) {
                    target->stoneDuration = 9;
                }
                target->status = STATUS_STONE;
            }
            return TRUE;
        case STATUS_DAZE:
            if (target->koStatus < statusTypeKey) {
                target->koStatus = STATUS_DAZE;
                target->koDuration = duration;
                if ((s8)duration > 9) {
                    target->koDuration = 9;
                }
                target->status = STATUS_DAZE;
            }
            return TRUE;
        case STATUS_E:
            if (target->actorID != ACTOR_PARTNER) {
                target->transStatus = STATUS_E;
                target->transDuration = duration;
                if ((s8)duration > 9) {
                    target->transDuration = 9;
                }
                target->status = STATUS_E;
                func_80047A30(target->hudElementDataIndex, STATUS_E);
            }
            return TRUE;
        case STATUS_END:
        case STATUS_NORMAL:
        case STATUS_DEFAULT:
        default:
            return TRUE;
    }
}

s32 inflict_partner_ko(Actor* target, s32 statusTypeKey, s32 duration) {
    if (statusTypeKey == STATUS_DAZE) {
        if (statusTypeKey != target->koStatus) {
            inflict_status(target, STATUS_DAZE, duration);
            sfx_play_sound(0x2107);
        } else {
            target->koDuration += duration;
            if (target->koDuration > 9) {
                target->koDuration = 9;
            }
        }
    }

    return TRUE;
}

s32 get_defense(Actor* actor, DictionaryEntry* defenseTable, s32 elementFlags) {
    s32 defense;
    s32 minDefense = 0xFF;

    if (defenseTable != NULL) {
        if (elementFlags & 2) {
            defense = lookup_defense(defenseTable, ELEMENT_FIRE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 4) {
            defense = lookup_defense(defenseTable, ELEMENT_WATER);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 8) {
            defense = lookup_defense(defenseTable, ELEMENT_ICE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        // ELEMENT_MYSTERY missing?
        if (elementFlags & 0x10) {
            defense = lookup_defense(defenseTable, ELEMENT_MAGIC);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x40) {
            defense = lookup_defense(defenseTable, ELEMENT_HAMMER);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x80) {
            defense = lookup_defense(defenseTable, ELEMENT_JUMP);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x100) {
            defense = lookup_defense(defenseTable, ELEMENT_COSMIC);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x200) {
            defense = lookup_defense(defenseTable, ELEMENT_BLAST);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x20) {
            defense = lookup_defense(defenseTable, ELEMENT_SHOCK);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x800) {
            defense = lookup_defense(defenseTable, ELEMENT_QUAKE);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
        if (elementFlags & 0x40000) {
            defense = lookup_defense(defenseTable, ELEMENT_THROW);
            if (defense < minDefense) {
                minDefense = defense;
            }
        }
    }

    // If no element flags were set, fall back to normal defense.
    if (minDefense == 0xFF) {
        defense = lookup_defense(defenseTable, ELEMENT_NORMAL);
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

INCLUDE_ASM(s32, "190B20", func_802664DC);

INCLUDE_ASM(void, "190B20", show_damage_popup, f32 x, f32 y, f32 z, s32 damageAmount, s32 arg4);

void func_80266684(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gDamageCountEffects); i++) {
        if (gDamageCountEffects[i] != NULL) {
            gDamageCountTimers[i]--;
            if (gDamageCountTimers[i] == 0) {
                // TODO use actual effect instance struct when we know what it is
                ((s32**)gDamageCountEffects[i])[3][12] = 5;
                gDamageCountEffects[i] = NULL;
            }
        }
    };
}

INCLUDE_ASM(void, "190B20", func_802666E4, Actor* actor, f32 arg1, f32 arg2, f32 arg3, s16 arg4);

INCLUDE_ASM(void, "190B20", func_802667F0, s32 arg0, Actor* arg1, f32 arg2, f32 arg3, f32 arg4);

void func_80266970(Actor* target) {
    target->unk_204 = 0;
}

INCLUDE_ASM(s32, "190B20", func_80266978);

void func_80266ADC(Actor* target) {
    target->unk_206 = -1;
    target->flags |= ACTOR_FLAG_80000;
}

void func_80266AF8(Actor* target) {
    target->unk_206 = 0;
    target->flags &= ~ACTOR_FLAG_80000;
}

void func_80266B14(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gBattleStatus.enemyActors); i++) {
        Actor* enemy = gBattleStatus.enemyActors[i];

        if (enemy != NULL) {
            if (enemy->unk_206 > 0) {
                enemy->unk_206--;
                if (enemy->unk_206 == 0) {
                    enemy->flags &= ~ENEMY_FLAGS_80000;
                }
            }
        }
    }
}

// dumb label
#ifdef NON_MATCHING
s32 try_inflict_status(Actor* actor, s32 statusTypeKey, s32 statusKey) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 phi_s0;
    s32 duration;

    if (battleStatus->statusChance == 0xFE) {
        duration = battleStatus->statusDuration;
        return inflict_status_set_duration(actor, statusTypeKey, statusKey,
                                           duration + lookup_status_duration_mod(actor->statusTable, statusKey));
    }

    duration = 0;

    if (actor->statusTable != NULL) {
        if (!(battleStatus->currentAttackStatus & 0x40000000)) {
            phi_s0 = lookup_status_chance(actor->statusTable, statusTypeKey);
        } else {
            if (lookup_status_chance(actor->statusTable, statusTypeKey) != 0) {
                phi_s0 = 100;
            } else {
                goto meow;
            }
        }

        if (phi_s0 > 0) {
            phi_s0 = (phi_s0 * battleStatus->statusChance) / 100;
            if (phi_s0 > 0 && phi_s0 >= rand_int(100)) {
                duration = lookup_status_duration_mod(actor->statusTable, statusKey) + 3;
            }
        }
    } else {
        duration = 3;
    }

// TODO remove this label (required to match)
meow:
    if (duration > 0) {
        if (battleStatus->currentAttackStatus < 0) {
            duration = battleStatus->statusDuration;
            duration += lookup_status_duration_mod(actor->statusTable, statusKey);
            inflict_status(actor, statusTypeKey, duration);
        } else {
            inflict_status(actor, statusTypeKey, duration);

        }
    } else {
        duration = 0;
    }
    return duration;
}
#else
INCLUDE_ASM(s32, "190B20", try_inflict_status);
#endif

s32 inflict_status_set_duration(Actor* actor, s32 statusTypeKey, s32 statusDurationKey, s32 duration) {
    s32 var0 = duration;
    s32 statusDuration = 0;

    if (actor->statusTable == NULL || lookup_status_chance(actor->statusTable, statusTypeKey) > 0) {
        statusDuration = var0;
    }

    if (statusDuration > 0) {
        return inflict_status(actor, statusTypeKey, statusDuration);
    } else {
        var0 = 0;
    }

    return 0;
}

void func_80266D6C(ActorPart* part, s32 arg1) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        if (decorationTable->unk_6C0 != arg1) {
            decorationTable->unk_6C0 = arg1;
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6C1 = 1;
        }
    }
}

void func_80266DAC(Actor* actor, s32 arg1) {
    ActorPart* partIt = &actor->partsTable[0];

    while (partIt != NULL) {
        if (!(partIt->flags & ACTOR_PART_FLAG_INVISIBLE) &&
           (partIt->idleAnimations != NULL) &&
           !(partIt->flags & ACTOR_PART_FLAG_2))
        {
            func_80266D6C(partIt, arg1);
        }
        partIt = partIt->nextPart;
    }
}

void func_80266E14(ActorPart* part) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        part->decorationTable->unk_6C0 = 0;
    }
}

void func_80266E40(Actor* actor) {
    ActorPart* partIt = actor->partsTable;
    s8 e = 0xE;
    s8 f = 0xF;

    while (partIt != NULL) {
        DecorationTable* decorationTable = partIt->decorationTable;

        do {
            if (!(partIt->flags & (ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_INVISIBLE)) &&
                (partIt->idleAnimations != NULL) &&
                !(partIt->flags & ACTOR_PART_FLAG_2))
            {
                if (decorationTable->unk_6C0 != e && decorationTable->unk_6C0 != f) {
                    decorationTable->unk_6C0 = 0;
                }
            }
        } while (0); // required to match
        partIt = partIt->nextPart;
    }
}

void func_80266EA8(ActorPart* part, s32 arg1) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        if (decorationTable->unk_750 != arg1) {
            decorationTable->unk_750 = arg1;
            decorationTable->unk_752 = 0;
            decorationTable->unk_751 = 1;
        }
    }
}

void func_80266EE8(Actor* actor, s32 arg1) {
    ActorPart* partIt = &actor->partsTable[0];

    while (partIt != NULL) {
        if (!(partIt->flags & (ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_INVISIBLE)) &&
            (partIt->idleAnimations != NULL) &&
            !(partIt->flags & ACTOR_PART_FLAG_2))
        {
            func_80266EA8(partIt, arg1);
        }
        partIt = partIt->nextPart;
    }
}

void func_80266F60(ActorPart* part) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        part->decorationTable->unk_750 = 0;
    }
}

void func_80266F8C(Actor* actor) {
    ActorPart* actorPart = &actor->partsTable[0];

    while (actorPart != NULL) {
        DecorationTable* decorationTable = actorPart->decorationTable;

        do {
            if (!(actorPart->flags & (ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_INVISIBLE)) &&
                actorPart->idleAnimations != NULL &&
                !(actorPart->flags & ACTOR_PART_FLAG_2))
            {
                decorationTable->unk_750 = 0;
            }
        } while (0); // required to match
        actorPart = actorPart->nextPart;
    }
}

void func_80266FD8(ActorPart* part, s32 arg1) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        if (decorationTable->unk_764 != arg1) {
            decorationTable->unk_764 = arg1;
            decorationTable->unk_766 = 0;
            decorationTable->unk_765 = 1;
        }
    }
}

void func_80267018(Actor* actor, s32 arg1) {
    ActorPart* actorPart = &actor->partsTable[0];

    while (actorPart != NULL) {
        if (!(actorPart->flags & (ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000)) &&
            actorPart->decorationTable != NULL && !(actorPart->flags & ACTOR_PART_FLAG_2) &&
            actorPart->idleAnimations != NULL)
        {
            func_80266FD8(actorPart, arg1);
        }
        actorPart = actorPart->nextPart;
    }
}

void func_8026709C(ActorPart* part) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        part->decorationTable->unk_764 = 0;
    }
}

void func_802670C8(Actor* actor) {
    ActorPart* partIt;

   for (partIt = actor->partsTable; partIt != NULL; partIt = partIt->nextPart) {
        DecorationTable* decorationTable = partIt->decorationTable;

        do {
            if (!(partIt->flags & (ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_INVISIBLE)) &&
                (partIt->idleAnimations != NULL) &&
                !(partIt->flags & ACTOR_PART_FLAG_2))
            {
                decorationTable->unk_764 = 0;
            }
        } while (0); // TODO make match better
    }
}

void add_part_decoration(ActorPart* part, s32 decorationIndex, s32 decorationType) {
    if ((part->idleAnimations) && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        _remove_part_decoration(part, decorationIndex);
        decorationTable->decorationType[decorationIndex] = decorationType;
        decorationTable->unk_8BA[decorationIndex] = 1;
        decorationTable->unk_8BC[decorationIndex] = 0;
        func_8025CEC8(part);
    }
}

void add_actor_decoration(Actor* actor, s32 decorationIndex, s32 decorationType) {
    ActorPart* part;
    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if (!(part->flags & (ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000)) && part->idleAnimations &&
            !(part->flags & ACTOR_PART_FLAG_2))
        {
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
        if (!(part->flags & (ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000)) && part->idleAnimations &&
            !(part->flags & ACTOR_PART_FLAG_2))
        {
            remove_part_decoration(part, decorationIndex);
        }
    }
}

s32 player_team_is_ability_active(Actor* actor, s32 ability) {
    s32 actorGenus = actor->actorID & 0x700;
    s32 hasAbility = FALSE;

    switch (actorGenus) {
        case ACTOR_PLAYER:
            if (!(gBattleStatus.flags2 & BS_FLAGS2_40)) {
                hasAbility = is_ability_active(ability);
            }
            break;
        case ACTOR_PARTNER:
            hasAbility = is_partner_ability_active(ability);
            break;
        case ACTOR_ENEMY0:
            break;
    }

    return hasAbility;
}

void create_part_shadow(s32 actorID, s32 partIndex) {
    ActorPart* part = get_actor_part(get_actor(actorID), partIndex);

    part->flags &= ~ACTOR_PART_FLAG_4;
    part->shadowIndex = create_shadow_type(0, part->currentPos.x, part->currentPos.y, part->currentPos.z);
    part->shadowScale = part->size.x / 24.0;
}

void remove_part_shadow(s32 actorID, s32 partIndex) {
    ActorPart* part = get_actor_part(get_actor(actorID), partIndex);

    part->flags |= ACTOR_PART_FLAG_4;
    delete_shadow(part->shadowIndex);
}

void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part) {
    part->flags &= ~ACTOR_PART_FLAG_4;
    part->shadowIndex = create_shadow_type(0, part->currentPos.x, part->currentPos.y, part->currentPos.z);
    part->shadowScale = part->size.x / 24.0;
}

void remove_player_buffs(s32 buffs) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    ActorPart* playerPartsTable = player->partsTable;

    if (buffs & 1) {
        battleStatus->jumpCharge = 0;
        battleStatus->flags1 &= ~BS_FLAGS1_20000000;
    }
    if (buffs & 2) {
        battleStatus->hammerCharge = 0;
        battleStatus->flags1 &= ~BS_FLAGS1_10000000;
    }
    if (buffs & 8) {
        player->stoneDuration = 0;
        player->stoneStatus = 0;
    }
    if (buffs & 0x10) {
        battleStatus->hustleTurns = 0;
        battleStatus->flags1 &= ~BS_FLAGS1_4000000;
    }
    if (buffs & 0x20 && (player->staticStatus != 0)) {
        player->staticDuration = 0;
        player->staticStatus = 0;
        remove_status_static(player->hudElementDataIndex);
    }
    if (buffs & 0x40 && (player->transStatus != 0)) {
        player->transDuration = 0;
        player->transStatus = 0;
        playerPartsTable->flags &= ~0x100;
        remove_status_transparent(player->hudElementDataIndex);
    }
    if (buffs & 0x200 && (battleStatus->waterBlockTurnsLeft != 0)) {
        battleStatus->waterBlockTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_10 = 0;
        battleStatus->unk_A0[0] |= 0x10;

        playFX_5A(1, player->currentPos.x, player->currentPos.y + 18.0f, player->currentPos.z + 5.0f, 1.5f, 0xA);
        playFX_5F(0, player->currentPos.x - 10.0f, player->currentPos.y + 5.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
        playFX_5F(0, player->currentPos.x - 15.0f, player->currentPos.y + 32.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
        playFX_5F(1, player->currentPos.x + 15.0f, player->currentPos.y + 22.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);

        battleStatus->unk_A0 = NULL;
        sfx_play_sound(SOUND_299);
    }
    if (buffs & 0x100 && (battleStatus->turboChargeTurnsLeft != 0)) {
        battleStatus->turboChargeTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_24 = 0;
    }
    if (buffs & 0x80 && (battleStatus->cloudNineTurnsLeft != 0)) {
        battleStatus->cloudNineTurnsLeft = 0;
        battleStatus->unk_43C->unk_0C->unk_1A = 0;
        remove_effect(battleStatus->cloudNineEffect);
        battleStatus->cloudNineEffect = NULL;
    }

    if (partner != NULL && (buffs & 0x10000)) {
        partner->isGlowing = FALSE;
        gBattleStatus.flags1 &= ~BS_FLAGS1_40000000;
    }
}

void btl_update_ko_status(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 koDuration = player->koDuration;
    s32 i;

    player->koDuration = player->debuffDuration;
    if (player->koDuration > 0) {
        player->koStatus = STATUS_DAZE;
        player->ptrDefuffIcon->ptrPropertyList[15] = player->koDuration;

        if (koDuration == 0) {
            sfx_play_sound(SOUND_2107);
        }
    }

    if (partner != NULL) {
        if (partner->koDuration < partner->debuffDuration) {
            partner->koStatus = STATUS_DAZE;
            partner->koDuration = partner->debuffDuration;
        }

        if (partner->koDuration > 0) {
            partner->koStatus = STATUS_DAZE;
            partner->ptrDefuffIcon->ptrPropertyList[15] = partner->koDuration;
        }
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        Actor* enemy = battleStatus->enemyActors[i];

        if (enemy != NULL) {
            enemy->koDuration = enemy->debuffDuration;
            if (enemy->koDuration > 0) {
                enemy->koStatus = STATUS_DAZE;
                enemy->ptrDefuffIcon->ptrPropertyList[15] = enemy->koDuration;
            }
        }
    }
}

void btl_appendGfx_prim_quad(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 right, u16 bottom) {
    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_80293970);

    if (a == 255) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMasterGfxPos++, left, top, right, bottom);

    gDPPipeSync(gMasterGfxPos++);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
}

void btl_draw_prim_quad(s32 r, s32 g, s32 b, s32 a, s32 left, s32 top, s32 arg6, s32 arg7) {
    u16 right = left + arg6;
    u16 bottom = top + arg7;

    btl_appendGfx_prim_quad(r, g, b, a, left, top, right, bottom);
}

void reset_all_actor_sounds(Actor* actor) {
    ActorPart* partIt = &actor->partsTable[0];

    actor->actorTypeData1[0] = bActorSoundTable[actor->actorType].walk[0];
    actor->actorTypeData1[1] = bActorSoundTable[actor->actorType].walk[1];
    actor->actorTypeData1[2] = bActorSoundTable[actor->actorType].fly[0];
    actor->actorTypeData1[3] = bActorSoundTable[actor->actorType].fly[1];
    actor->actorTypeData1[4] = bActorSoundTable[actor->actorType].jump;
    actor->actorTypeData1[5] = bActorSoundTable[actor->actorType].hurt;
    actor->actorTypeData1b[0] = bActorSoundTable[actor->actorType].delay[0];
    actor->actorTypeData1b[1] = bActorSoundTable[actor->actorType].delay[1];

    while (partIt != NULL) {
        partIt->partTypeData[0] = actor->actorTypeData1[0];
        partIt->partTypeData[1] = actor->actorTypeData1[1];
        partIt->partTypeData[2] = actor->actorTypeData1[2];
        partIt->partTypeData[3] = actor->actorTypeData1[3];
        partIt->partTypeData[4] = actor->actorTypeData1[4];
        partIt->partTypeData[5] = actor->actorTypeData1[5];
        partIt->actorTypeData2b[0] = actor->actorTypeData1b[0];
        partIt->actorTypeData2b[1] = actor->actorTypeData1b[1];
        partIt = partIt->nextPart;
    }
}

void hide_foreground_models_unchecked(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= MODEL_FLAGS_ENABLED;
            }
        }
    }
}

void show_foreground_models_unchecked(void) {
    FGModelData* data = gBattleStatus.foregroundModelData;

    if (data != NULL && data->idList != NULL) {
        s32* idList = data->idList;
        while (*idList != 0) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~MODEL_FLAGS_ENABLED;
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
                model->flags |= MODEL_FLAGS_ENABLED;
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
                model->flags &= ~MODEL_FLAGS_ENABLED;
            }
        }
    }
}


#include "common/StartRumbleWithParams.inc.c"

void start_rumble_type(u32 arg0) {
    if (D_802939C0 != 0) {
        kill_script_by_ID(D_802939C0);
    }

    switch (arg0) {
        case 0:
            break;
        case 1:
            D_802939C0 = start_script(D_802939C4, 0xA, 0x20)->id;
            break;
        case 2:
            D_802939C0 = start_script(D_80293A10, 0xA, 0x20)->id;
            break;
        case 3:
            D_802939C0 = start_script(D_80293A34, 0xA, 0x20)->id;
            break;
        case 4:
            D_802939C0 = start_script(D_80293A58, 0xA, 0x20)->id;
            break;
        case 5:
            D_802939C0 = start_script(D_80293A7C, 0xA, 0x20)->id;
            break;
        case 6:
            D_802939C0 = start_script(D_80293AA0, 0xA, 0x20)->id;
            break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            D_802939C0 = start_script(D_80293AC4, 0xA, 0x20)->id;
            break;
    }
}
