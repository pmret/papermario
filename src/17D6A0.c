#include "common.h"
#include "effects.h"
#include "message_ids.h"
#include "battle/battle.h"
#include "hud_element.h"
#include "entity.h"
#include "ld_addrs.h"
#include "battle/action_cmd.h"

extern IMG_BIN ui_battle_menu_spirits_png[];
extern PAL_BIN ui_battle_menu_spirits_pal[];
extern IMG_BIN ui_battle_unk_star_png[];
extern PAL_BIN ui_battle_unk_star_pal[];

extern ActorBlueprint battle_partner_goombario;
extern ActorBlueprint battle_partner_kooper;
extern ActorBlueprint battle_partner_bombette;
extern ActorBlueprint battle_partner_parakarry;
extern ActorBlueprint battle_partner_goompa;
extern ActorBlueprint battle_partner_watt;
extern ActorBlueprint battle_partner_sushie;
extern ActorBlueprint battle_partner_lakilester;
extern ActorBlueprint battle_partner_bow;
extern ActorBlueprint battle_partner_twink;

PlayerCelebrationAnimOptions D_80280FC0 = {
    10, 90,
    {
        50, 196619,
        50, ANIM_Mario_1002D,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        50, ANIM_Mario_DustOff,
        50, ANIM_Mario_DustOff,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        50, ANIM_Mario_ThumbsUp,
        50, ANIM_Mario_ThumbsUp,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        50, ANIM_Mario_3000A,
        50, ANIM_Mario_3000A,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        80, ANIM_Mario_3000A,
        20, ANIM_Mario_3000B,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
    }
};

s32 bActorNames[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA]                  MSG_EnemyName_RedGoomba,
    [ACTOR_TYPE_RED_PARAGOOMBA]              MSG_EnemyName_RedParagoomba,
    [ACTOR_TYPE_GLOOMBA]                     MSG_EnemyName_Gloomba,
    [ACTOR_TYPE_PARAGLOOMBA]                 MSG_EnemyName_Paragloomba,
    [ACTOR_TYPE_SPIKED_GLOOMBA]              MSG_EnemyName_SpikedGloomba,
    [ACTOR_TYPE_DARK_KOOPA]                  MSG_EnemyName_DarkKoopa,
    [ACTOR_TYPE_DARK_PARATROOPA]             MSG_EnemyName_DarkParatroopa,
    [ACTOR_TYPE_GOOMBA]                      MSG_EnemyName_Goomba,
    [ACTOR_TYPE_PARAGOOMBA]                  MSG_EnemyName_Paragoomba,
    [ACTOR_TYPE_SPIKED_GOOMBA]               MSG_EnemyName_SpikedGoomba,
    [ACTOR_TYPE_FUZZY]                       MSG_EnemyName_Fuzzy,
    [ACTOR_TYPE_KOOPA_TROOPA]                MSG_EnemyName_KoopaTroopa,
    [ACTOR_TYPE_PARATROOPA]                  MSG_EnemyName_Paratroopa,
    [ACTOR_TYPE_BOB_OMB]                     MSG_EnemyName_BobOmb,
    [ACTOR_TYPE_BOB_OMB_DUP]                 MSG_EnemyName_BobOmb,
    [ACTOR_TYPE_BULLET_BILL]                 MSG_EnemyName_BulletBill,
    [ACTOR_TYPE_BILL_BLASTER]                MSG_EnemyName_BillBlaster,
    [ACTOR_TYPE_CLEFT]                       MSG_EnemyName_Cleft,
    [ACTOR_TYPE_MONTY_MOLE]                  MSG_EnemyName_MontyMole,
    [ACTOR_TYPE_BANDIT]                      MSG_EnemyName_Bandit,
    [ACTOR_TYPE_POKEY]                       MSG_EnemyName_Pokey,
    [ACTOR_TYPE_POKEY_MUMMY]                 MSG_EnemyName_PokeyMummy,
    [ACTOR_TYPE_SWOOPER]                     MSG_EnemyName_Swooper,
    [ACTOR_TYPE_BUZZY_BEETLE]                MSG_EnemyName_BuzzyBeetle,
    [ACTOR_TYPE_STONE_CHOMP]                 MSG_EnemyName_StoneChomp,
    [ACTOR_TYPE_PIRANHA_PLANT]               MSG_EnemyName_PiranhaPlant,
    [ACTOR_TYPE_FOREST_FUZZY]                MSG_EnemyName_ForestFuzzy,
    [ACTOR_TYPE_HYPER_GOOMBA]                MSG_EnemyName_HyperGoomba,
    [ACTOR_TYPE_HYPER_PARAGOOMBA]            MSG_EnemyName_HyperParagoomba,
    [ACTOR_TYPE_HYPER_CLEFT]                 MSG_EnemyName_HyperCleft,
    [ACTOR_TYPE_CLUBBA]                      MSG_EnemyName_Clubba,
    [ACTOR_TYPE_SHY_GUY]                     MSG_EnemyName_ShyGuy,
    [ACTOR_TYPE_GROOVE_GUY]                  MSG_EnemyName_GrooveGuy,
    [ACTOR_TYPE_SKY_GUY]                     MSG_EnemyName_SkyGuy,
    [ACTOR_TYPE_MEDI_GUY]                    MSG_EnemyName_MediGuy,
    [ACTOR_TYPE_PYRO_GUY]                    MSG_EnemyName_PyroGuy,
    [ACTOR_TYPE_SPY_GUY]                     MSG_EnemyName_SpyGuy,
    [ACTOR_TYPE_FUZZIPEDE]                   MSG_EnemyName_Fuzzipede,
    [ACTOR_TYPE_HURT_PLANT]                  MSG_EnemyName_HurtPlant,
    [ACTOR_TYPE_M_BUSH]                      MSG_EnemyName_MBush,
    [ACTOR_TYPE_AQUA_FUZZY]                  MSG_EnemyName_AquaFuzzy,
    [ACTOR_TYPE_JUNGLE_FUZZY]                MSG_EnemyName_JungleFuzzy,
    [ACTOR_TYPE_SPEAR_GUY]                   MSG_EnemyName_SpearGuy,
    [ACTOR_TYPE_LAVA_BUBBLE]                 MSG_EnemyName_LavaBubble,
    [ACTOR_TYPE_SPIKE_TOP]                   MSG_EnemyName_SpikeTop,
    [ACTOR_TYPE_PUTRID_PIRANHA]              MSG_EnemyName_PutridPiranha,
    [ACTOR_TYPE_LAKITU]                      MSG_EnemyName_Lakitu,
    [ACTOR_TYPE_SPINY]                       MSG_EnemyName_Spiny,
    [ACTOR_TYPE_MONTY_MOLE_BOSS]             MSG_EnemyName_MontyMoleBoss,
    [ACTOR_TYPE_BZZAP]                       MSG_EnemyName_Bzzap,
    [ACTOR_TYPE_CRAZEE_DAYZEE]               MSG_EnemyName_CrazeeDayzee,
    [ACTOR_TYPE_AMAZY_DAYZEE]                MSG_EnemyName_AmazyDayzee,
    [ACTOR_TYPE_RUFF_PUFF]                   MSG_EnemyName_RuffPuff,
    [ACTOR_TYPE_SPIKE]                       MSG_EnemyName_Spike,
    [ACTOR_TYPE_GULPIT]                      MSG_EnemyName_Gulpit,
    [ACTOR_TYPE_GULPIT_ROCKS]                MSG_EnemyName_GulpitRocks,
    [ACTOR_TYPE_WHITE_CLUBBA]                MSG_EnemyName_WhiteClubba,
    [ACTOR_TYPE_FROST_PIRANHA]               MSG_EnemyName_FrostPiranha,
    [ACTOR_TYPE_SWOOPULA]                    MSG_EnemyName_Swoopula,
    [ACTOR_TYPE_DUPLIGHOST]                  MSG_EnemyName_Duplighost,
    [ACTOR_TYPE_GHOST_GOOMBARIO]             MSG_EnemyName_GhostGoombario,
    [ACTOR_TYPE_GHOST_KOOPER]                MSG_EnemyName_GhostKooper,
    [ACTOR_TYPE_GHOST_BOMBETTE]              MSG_EnemyName_GhostBombette,
    [ACTOR_TYPE_GHOST_PARAKARRY]             MSG_EnemyName_GhostParakarry,
    [ACTOR_TYPE_GHOST_BOW]                   MSG_EnemyName_GhostBow,
    [ACTOR_TYPE_GHOST_WATT]                  MSG_EnemyName_GhostWatt,
    [ACTOR_TYPE_GHOST_SUSHIE]                MSG_EnemyName_GhostSushie,
    [ACTOR_TYPE_GHOST_LAKILESTER]            MSG_EnemyName_GhostLakilester,
    [ACTOR_TYPE_ALBINO_DINO]                 MSG_EnemyName_AlbinoDino,
    [ACTOR_TYPE_EMBER]                       MSG_EnemyName_Ember,
    [ACTOR_TYPE_BONY_BEETLE]                 MSG_EnemyName_BonyBeetle,
    [ACTOR_TYPE_DRY_BONES]                   MSG_EnemyName_DryBones,
    [ACTOR_TYPE_DRY_BONES2]                  MSG_EnemyName_DryBones,
    [ACTOR_TYPE_BOMBSHELL_BLASTER]           MSG_EnemyName_BombshellBlaster,
    [ACTOR_TYPE_BOMBSHELL_BILL]              MSG_EnemyName_BombshellBill,
    [ACTOR_TYPE_HAMMER_BROS]                 MSG_EnemyName_HammerBros,
    [ACTOR_TYPE_KOOPATROL]                   MSG_EnemyName_Koopatrol,
    [ACTOR_TYPE_MAGIKOOPA]                   MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_FLYING_MAGIKOOPA]            MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_MAGICLONE]                   MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_FLYING_MAGICLONE]            MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_RED_MAGIKOOPA]               MSG_EnemyName_RedMagikoopa,
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA]        MSG_EnemyName_RedMagikoopa,
    [ACTOR_TYPE_GREEN_MAGIKOOPA]             MSG_EnemyName_GreenMagikoopa,
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA]      MSG_EnemyName_GreenMagikoopa,
    [ACTOR_TYPE_YELLOW_MAGIKOOPA]            MSG_EnemyName_YellowMagikoopa,
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA]     MSG_EnemyName_YellowMagikoopa,
    [ACTOR_TYPE_GRAY_MAGIKOOPA]              MSG_EnemyName_GrayMagikoopa,
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA]       MSG_EnemyName_GrayMagikoopa,
    [ACTOR_TYPE_WHITE_MAGIKOOPA]             MSG_EnemyName_WhiteMagikoopa,
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA]      MSG_EnemyName_WhiteMagikoopa,
    [ACTOR_TYPE_UNUSED_5B]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_5C]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_5D]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_5E]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_5F]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_60]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_61]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_62]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_63]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_64]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_65]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_66]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_67]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_68]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_69]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_6A]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_MONTY_HOLE]                  MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_6C]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_6D]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_PLAYER]                      MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_GOOMBARIO]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_KOOPER]                      MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_BOMBETTE]                    MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_PARAKARRY]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_BOW]                         MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_WATT]                        MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_SUSHIE]                      MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_LAKILESTER]                  MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_TWINK]                       MSG_Menus_Party_Twink,
    [ACTOR_TYPE_UNUSED_78]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_UNUSED_79]                   MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_THE_MASTER_1]                MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_THE_MASTER_2]                MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_THE_MASTER_3]                MSG_EnemyName_TheMaster,
    [ACTOR_TYPE_CHAN]                        MSG_EnemyName_Chan,
    [ACTOR_TYPE_LEE]                         MSG_EnemyName_Lee,
    [ACTOR_TYPE_LEE_GOOMBARIO]               MSG_Menus_Party_Goombario,
    [ACTOR_TYPE_LEE_KOOPER]                  MSG_Menus_Party_Kooper,
    [ACTOR_TYPE_LEE_BOMBETTE]                MSG_Menus_Party_Bombette,
    [ACTOR_TYPE_LEE_PARAKARRY]               MSG_Menus_Party_Parakarry,
    [ACTOR_TYPE_LEE_BOW]                     MSG_Menus_Party_Bow,
    [ACTOR_TYPE_LEE_WATT]                    MSG_Menus_Party_Watt,
    [ACTOR_TYPE_LEE_SUSHIE]                  MSG_Menus_Party_Sushie,
    [ACTOR_TYPE_LEE_LAKILESTER]              MSG_Menus_Party_Lakilester,
    [ACTOR_TYPE_KAMMY_KOOPA]                 MSG_EnemyName_KammyKoopa,
    [ACTOR_TYPE_JR_TROOPA1]                  MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA2]                  MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA3]                  MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA4]                  MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA5]                  MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA6]                  MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA_DUP1]              MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_JR_TROOPA_DUP2]              MSG_EnemyName_JrTroopa,
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS]            MSG_EnemyName_BlueGoombaBoss,
    [ACTOR_TYPE_RED_GOOMBA_BOSS]             MSG_EnemyName_RedGoombaBoss,
    [ACTOR_TYPE_GOOMBA_KING]                 MSG_EnemyName_GoombaKing,
    [ACTOR_TYPE_GOOMNUT_TREE]                MSG_EnemyName_GoomnutTree,
    [ACTOR_TYPE_GOOMBARIO_TUTOR1]            MSG_Menus_Party_Goombario,
    [ACTOR_TYPE_MAGIKOOPA_BOSS]              MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS]       MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_MAGIKOOPA_DUP1]              MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_MAGIKOOPA_DUP2]              MSG_EnemyName_Magikoopa,
    [ACTOR_TYPE_FAKE_BOWSER]                 MSG_EnemyName_FakeBowser,
    [ACTOR_TYPE_KOOPA_BROS]                  MSG_EnemyName_KoopaBros,
    [ACTOR_TYPE_GREEN_NINJAKOOPA]            MSG_EnemyName_GreenNinjakoopa,
    [ACTOR_TYPE_RED_NINJAKOOPA]              MSG_EnemyName_RedNinjakoopa,
    [ACTOR_TYPE_BLUE_NINJAKOOPA]             MSG_EnemyName_BlueNinjakoopa,
    [ACTOR_TYPE_YELLOW_NINJAKOOPA]           MSG_EnemyName_YellowNinjakoopa,
    [ACTOR_TYPE_ELDSTAR]                     MSG_Menus_Party_Goombario,
    [ACTOR_TYPE_BUZZAR]                      MSG_EnemyName_Buzzar,
    [ACTOR_TYPE_TUTANKOOPA]                  MSG_EnemyName_Tutankoopa,
    [ACTOR_TYPE_CHOMP]                       MSG_EnemyName_Chomp,
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE]     MSG_EnemyName_TubbaBlubba,
    [ACTOR_TYPE_TUBBA_BLUBBA]                MSG_EnemyName_TubbaBlubba,
    [ACTOR_TYPE_TUBBA_HEART]                 MSG_EnemyName_TubbaHeart,
    [ACTOR_TYPE_STILT_GUY]                   MSG_EnemyName_StiltGuy,
    [ACTOR_TYPE_SHY_STACK]                   MSG_EnemyName_ShyStack,
    [ACTOR_TYPE_SHY_SQUAD]                   MSG_EnemyName_ShySquad,
    [ACTOR_TYPE_GENERAL_GUY]                 MSG_EnemyName_GeneralGuyDup,
    [ACTOR_TYPE_TOY_TANK]                    MSG_EnemyName_GeneralGuy,
    [ACTOR_TYPE_LIGHT_BULB]                  MSG_EnemyName_Bulb,
    [ACTOR_TYPE_SIGNAL_GUY]                  MSG_EnemyName_ShyGuy,
    [ACTOR_TYPE_SHY_SQUAD_DUP]               MSG_EnemyName_ShySquadDup,
    [ACTOR_TYPE_SHY_GUY_DUP]                 MSG_EnemyName_ShyGuy,
    [ACTOR_TYPE_ANTI_GUY]                    MSG_EnemyName_AntiGuy,
    [ACTOR_TYPE_ANTI_GUY_DUP]                MSG_EnemyName_AntiGuy,
    [ACTOR_TYPE_BIG_LANTERN_GHOST]           MSG_EnemyName_BigLanternGhost,
    [ACTOR_TYPE_GOOMBA_KING_DUP]             MSG_EnemyName_GoombaKing,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1]        MSG_EnemyName_LavaPiranha,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2]        MSG_EnemyName_LavaPiranha,
    [ACTOR_TYPE_LAVA_BUD_PHASE_1]            MSG_EnemyName_LavaBud,
    [ACTOR_TYPE_LAVA_BUD_PHASE_2]            MSG_EnemyName_LavaBud,
    [ACTOR_TYPE_PETIT_PIRANHA]               MSG_EnemyName_PetitPiranha,
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB]          MSG_EnemyName_LavaPiranha,
    [ACTOR_TYPE_KENT_C_KOOPA]                MSG_EnemyName_KentCKoopa,
    [ACTOR_TYPE_HUFF_N_PUFF]                 MSG_EnemyName_HuffNPuff,
    [ACTOR_TYPE_TUFF_PUFF]                   MSG_EnemyName_TuffPuff,
    [ACTOR_TYPE_MONSTAR]                     MSG_EnemyName_Monstar,
    [ACTOR_TYPE_CRYSTAL_KING]                MSG_EnemyName_CrystalKing,
    [ACTOR_TYPE_CRYSTAL_CLONE]               MSG_EnemyName_CrystalKing,
    [ACTOR_TYPE_CRYSTAL_BIT]                 MSG_EnemyName_CrystalBit,
    [ACTOR_TYPE_INTRO_BOWSER]                MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BOWSER_PHASE_1]              MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BOWSER_DUP1]                 MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BOWSER_PHASE_2]              MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BOWSER_DUP2]                 MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BOWSER_PHASE_3]              MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BOWSER_DUP3]                 MSG_EnemyName_Bowser,
    [ACTOR_TYPE_BLOOPER]                     MSG_EnemyName_Blooper,
    [ACTOR_TYPE_ELECTRO_BLOOPER1]            MSG_EnemyName_ElectroBlooper,
    [ACTOR_TYPE_ELECTRO_BLOOPER2]            MSG_EnemyName_ElectroBlooper,
    [ACTOR_TYPE_SUPER_BLOOPER1]              MSG_EnemyName_SuperBlooper,
    [ACTOR_TYPE_SUPER_BLOOPER2]              MSG_EnemyName_SuperBlooper,
    [ACTOR_TYPE_BLOOPER_BABY]                MSG_EnemyName_BlooperBaby,
    [ACTOR_TYPE_LAKILESTER_DUP]              MSG_EnemyName_GhostLakilester,
    [ACTOR_TYPE_SLOT_MACHINE_START]          MSG_EnemyName_SlotMachineStart,
    [ACTOR_TYPE_SLOT_MACHINE_STOP]           MSG_EnemyName_SlotMachineStop,
    [ACTOR_TYPE_WHACKA]                      MSG_EnemyName_Whacka,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1]     MSG_EnemyName_SlotMachineStart,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2]     MSG_EnemyName_SlotMachineStart,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3]     MSG_EnemyName_SlotMachineStart,
};

// enemy types to ignore when deciding initialEnemyCount
s32 D_80281454[] = {
    ACTOR_TYPE_UNUSED_78,
    ACTOR_TYPE_GOOMNUT_TREE,
    ACTOR_TYPE_FAKE_BOWSER,
    ACTOR_TYPE_GOOMBA_KING_DUP,
    -1
};

ActorSounds bActorSoundTable[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_RED_PARAGOOMBA] = {
        .walk = { SOUND_20DF, SOUND_20DF },
        .fly = { SOUND_20DF, SOUND_20DF },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GLOOMBA] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PARAGLOOMBA] = {
        .walk = { SOUND_20DF, SOUND_20DF },
        .fly = { SOUND_20DF, SOUND_20DF },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SPIKED_GLOOMBA] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_DARK_KOOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_DARK_PARATROOPA] = {
        .walk = { SOUND_20DF, SOUND_20DF },
        .fly = { SOUND_20DF, SOUND_20DF },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GOOMBA] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PARAGOOMBA] = {
        .walk = { SOUND_20DF, SOUND_20DF },
        .fly = { SOUND_20DF, SOUND_20DF },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SPIKED_GOOMBA] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FUZZY] = {
        .walk = { SOUND_331, SOUND_331 },
        .fly = { SOUND_331, SOUND_331 },
        .jump = SOUND_331,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_KOOPA_TROOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PARATROOPA] = {
        .walk = { SOUND_20DF, SOUND_20DF },
        .fly = { SOUND_20DF, SOUND_20DF },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOB_OMB] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOB_OMB_DUP] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BULLET_BILL] = {
        .walk = { SOUND_2C9, SOUND_2C9 },
        .fly = { SOUND_2C9, SOUND_2C9 },
        .jump = SOUND_2C9,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BILL_BLASTER] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CLEFT] = {
        .walk = { SOUND_20D0, SOUND_20D0 },
        .fly = { SOUND_20D0, SOUND_20D0 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MONTY_MOLE] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BANDIT] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_20C1, SOUND_20C1 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_POKEY] = {
        .walk = { SOUND_343, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_POKEY_MUMMY] = {
        .walk = { SOUND_343, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SWOOPER] = {
        .walk = { SOUND_351, SOUND_351 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BUZZY_BEETLE] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_STONE_CHOMP] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PIRANHA_PLANT] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FOREST_FUZZY] = {
        .walk = { SOUND_331, SOUND_331 },
        .fly = { SOUND_331, SOUND_331 },
        .jump = SOUND_331,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_HYPER_GOOMBA] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_HYPER_PARAGOOMBA] = {
        .walk = { SOUND_20DF, SOUND_20DF },
        .fly = { SOUND_20DF, SOUND_20DF },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_HYPER_CLEFT] = {
        .walk = { SOUND_20D0, SOUND_20D0 },
        .fly = { SOUND_20D0, SOUND_20D0 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CLUBBA] = {
        .walk = { SOUND_20C4, SOUND_20C4 },
        .fly = { SOUND_20C4, SOUND_20C4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SHY_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GROOVE_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SKY_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MEDI_GUY] = {
        .walk = { NULL, NULL },
        .fly = { SOUND_380, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PYRO_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SPY_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FUZZIPEDE] = {
        .walk = { SOUND_20D9, SOUND_20D9 },
        .fly = { SOUND_20D9, SOUND_20D9 },
        .jump = SOUND_20D9,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_HURT_PLANT] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_M_BUSH] = {
        .walk = { SOUND_20C6, SOUND_20C6 },
        .fly = { SOUND_20C6, SOUND_20C6 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_AQUA_FUZZY] = {
        .walk = { SOUND_331, SOUND_331 },
        .fly = { SOUND_331, SOUND_331 },
        .jump = SOUND_331,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JUNGLE_FUZZY] = {
        .walk = { SOUND_331, SOUND_331 },
        .fly = { SOUND_331, SOUND_331 },
        .jump = SOUND_331,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SPEAR_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAVA_BUBBLE] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SPIKE_TOP] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PUTRID_PIRANHA] = {
        .walk = { SOUND_3CE, SOUND_3CE },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAKITU] = {
        .walk = { SOUND_295, SOUND_295 },
        .fly = { SOUND_295, SOUND_295 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { -5, -5 }
    },
    [ACTOR_TYPE_SPINY] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MONTY_MOLE_BOSS] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BZZAP] = {
        .walk = { SOUND_357, NULL },
        .fly = { SOUND_357, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CRAZEE_DAYZEE] = {
        .walk = { SOUND_2D6, SOUND_2D6 },
        .fly = { SOUND_2D6, SOUND_2D6 },
        .jump = SOUND_2D5,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_AMAZY_DAYZEE] = {
        .walk = { SOUND_2D6, SOUND_2D6 },
        .fly = { SOUND_2D6, SOUND_2D6 },
        .jump = SOUND_2D5,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_RUFF_PUFF] = {
        .walk = { SOUND_295, NULL },
        .fly = { SOUND_295, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SPIKE] = {
        .walk = { SOUND_295, NULL },
        .fly = { SOUND_295, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GULPIT] = {
        .walk = { SOUND_20C4, SOUND_20C4 },
        .fly = { SOUND_20C4, SOUND_20C4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GULPIT_ROCKS] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_WHITE_CLUBBA] = {
        .walk = { SOUND_20C4, SOUND_20C4 },
        .fly = { SOUND_20C4, SOUND_20C4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FROST_PIRANHA] = {
        .walk = { SOUND_3CE, SOUND_3CE },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SWOOPULA] = {
        .walk = { SOUND_351, SOUND_351 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_DUPLIGHOST] = {
        .walk = { SOUND_2CA, SOUND_2CA },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_GOOMBARIO] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_KOOPER] = {
        .walk = { SOUND_100, SOUND_100 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_BOMBETTE] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_PARAKARRY] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_BOW] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_WATT] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_SUSHIE] = {
        .walk = { SOUND_29A, SOUND_29A },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GHOST_LAKILESTER] = {
        .walk = { SOUND_295, SOUND_295 },
        .fly = { SOUND_295, SOUND_295 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { -5, -5 }
    },
    [ACTOR_TYPE_ALBINO_DINO] = {
        .walk = { SOUND_30B, SOUND_2FD },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_EMBER] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BONY_BEETLE] = {
        .walk = { SOUND_20CD, SOUND_20CD },
        .fly = { SOUND_20CD, SOUND_20CD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_DRY_BONES] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_DRY_BONES2] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOMBSHELL_BLASTER] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOMBSHELL_BILL] = {
        .walk = { SOUND_2C9, SOUND_2C9 },
        .fly = { SOUND_2C9, SOUND_2C9 },
        .jump = SOUND_2C9,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_HAMMER_BROS] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_KOOPATROL] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MAGICLONE] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_MAGICLONE] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_RED_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GREEN_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_YELLOW_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GRAY_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_WHITE_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_5B] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_5C] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_5D] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_5E] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_5F] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_60] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_61] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_62] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_63] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_64] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_65] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_66] = {
        .walk = { SOUND_295, SOUND_295 },
        .fly = { SOUND_295, SOUND_295 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { -5, -5 }
    },
    [ACTOR_TYPE_UNUSED_67] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { SOUND_20DD, SOUND_20DD },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_68] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_69] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_6A] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MONTY_HOLE] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_6C] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_6D] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PLAYER] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GOOMBARIO] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_KOOPER] = {
        .walk = { SOUND_100, SOUND_100 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOMBETTE] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PARAKARRY] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOW] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_WATT] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SUSHIE] = {
        .walk = { SOUND_29A, SOUND_29A },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAKILESTER] = {
        .walk = { SOUND_295, SOUND_295 },
        .fly = { SOUND_295, SOUND_295 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { -5, -5 }
    },
    [ACTOR_TYPE_TWINK] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { -5, -5 }
    },
    [ACTOR_TYPE_UNUSED_78] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_UNUSED_79] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_THE_MASTER_1] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_THE_MASTER_2] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_THE_MASTER_3] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CHAN] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE] = {
        .walk = { SOUND_2CA, SOUND_2CA },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_GOOMBARIO] = {
        .walk = { SOUND_20DD, SOUND_20DD },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_KOOPER] = {
        .walk = { SOUND_100, SOUND_100 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_BOMBETTE] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_PARAKARRY] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_BOW] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_WATT] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_SUSHIE] = {
        .walk = { SOUND_29A, SOUND_29A },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LEE_LAKILESTER] = {
        .walk = { SOUND_295, SOUND_295 },
        .fly = { SOUND_295, SOUND_295 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { -5, -5 }
    },
    [ACTOR_TYPE_KAMMY_KOOPA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA1] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA2] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA3] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA4] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA5] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA6] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA_DUP1] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_JR_TROOPA_DUP2] = {
        .walk = { SOUND_20C1, SOUND_20C1 },
        .fly = { SOUND_351, SOUND_351 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS] = {
        .walk = { SOUND_3AC, SOUND_3AC },
        .fly = { NULL, NULL },
        .jump = SOUND_10F,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_RED_GOOMBA_BOSS] = {
        .walk = { SOUND_3AC, SOUND_3AC },
        .fly = { NULL, NULL },
        .jump = SOUND_10F,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GOOMBA_KING] = {
        .walk = { SOUND_20EC, SOUND_20EC },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 22, 30 }
    },
    [ACTOR_TYPE_GOOMNUT_TREE] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GOOMBARIO_TUTOR1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MAGIKOOPA_BOSS] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MAGIKOOPA_DUP1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MAGIKOOPA_DUP2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_FAKE_BOWSER] = {
        .walk = { SOUND_3EA, SOUND_3EA },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_KOOPA_BROS] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GREEN_NINJAKOOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_RED_NINJAKOOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BLUE_NINJAKOOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_YELLOW_NINJAKOOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_ELDSTAR] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BUZZAR] = {
        .walk = { NULL, NULL },
        .fly = { SOUND_20EF, SOUND_20EF },
        .jump = NULL,
        .hurt = NULL,
        .delay = { -14, -14 }
    },
    [ACTOR_TYPE_TUTANKOOPA] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { -3, -3 }
    },
    [ACTOR_TYPE_CHOMP] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE] = {
        .walk = { SOUND_20F6, SOUND_20F6 },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_TUBBA_BLUBBA] = {
        .walk = { SOUND_20F6, SOUND_20F6 },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_TUBBA_HEART] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_20C8,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_STILT_GUY] = {
        .walk = { SOUND_2066, SOUND_2066 },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SHY_STACK] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 10, 10 }
    },
    [ACTOR_TYPE_SHY_SQUAD] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GENERAL_GUY] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_TOY_TANK] = {
        .walk = { SOUND_37E, SOUND_37E },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LIGHT_BULB] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SIGNAL_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SHY_SQUAD_DUP] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SHY_GUY_DUP] = {
        .walk = { SOUND_20BA, SOUND_20BA },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_ANTI_GUY] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_ANTI_GUY_DUP] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { NULL, NULL },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BIG_LANTERN_GHOST] = {
        .walk = { SOUND_37D, SOUND_37D },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_GOOMBA_KING_DUP] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAVA_BUD_PHASE_1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAVA_BUD_PHASE_2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PETIT_PIRANHA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_KENT_C_KOOPA] = {
        .walk = { SOUND_20EC, SOUND_20EC },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_HUFF_N_PUFF] = {
        .walk = { NULL, NULL },
        .fly = { SOUND_3D1, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_TUFF_PUFF] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_MONSTAR] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CRYSTAL_KING] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CRYSTAL_CLONE] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_CRYSTAL_BIT] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_INTRO_BOWSER] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_3E7,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOWSER_PHASE_1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_3E7,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOWSER_DUP1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOWSER_PHASE_2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_3E7,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOWSER_DUP2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOWSER_PHASE_3] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = SOUND_3E7,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BOWSER_DUP3] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_BLOOPER] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 25, 25 }
    },
    [ACTOR_TYPE_ELECTRO_BLOOPER1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 25, 25 }
    },
    [ACTOR_TYPE_ELECTRO_BLOOPER2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 25, 25 }
    },
    [ACTOR_TYPE_SUPER_BLOOPER1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 25, 25 }
    },
    [ACTOR_TYPE_SUPER_BLOOPER2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 25, 25 }
    },
    [ACTOR_TYPE_BLOOPER_BABY] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_LAKILESTER_DUP] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SLOT_MACHINE_START] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SLOT_MACHINE_STOP] = {
        .walk = { SOUND_20BA, SOUND_3B4 },
        .fly = { SOUND_20BA, SOUND_3B4 },
        .jump = SOUND_JUMP_3E2,
        .hurt = SOUND_10F,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_WHACKA] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3] = {
        .walk = { NULL, NULL },
        .fly = { NULL, NULL },
        .jump = NULL,
        .hurt = NULL,
        .delay = { 30, 30 }
    },
};

s32 bActorTattles[ACTOR_TYPE_COUNT] = {
    [ACTOR_TYPE_RED_GOOMBA] = NULL,
    [ACTOR_TYPE_RED_PARAGOOMBA] = NULL,
    [ACTOR_TYPE_GLOOMBA] = MSG_EnemyTattle_Gloomba,
    [ACTOR_TYPE_PARAGLOOMBA] = MSG_EnemyTattle_Paragloomba,
    [ACTOR_TYPE_SPIKED_GLOOMBA] = MSG_EnemyTattle_SpikedGloomba,
    [ACTOR_TYPE_DARK_KOOPA] = MSG_EnemyTattle_DarkKoopa,
    [ACTOR_TYPE_DARK_PARATROOPA] = MSG_EnemyTattle_DarkParatroopa,
    [ACTOR_TYPE_GOOMBA] = MSG_EnemyTattle_Goomba,
    [ACTOR_TYPE_PARAGOOMBA] = MSG_EnemyTattle_Paragoomba,
    [ACTOR_TYPE_SPIKED_GOOMBA] = MSG_EnemyTattle_SpikedGoomba,
    [ACTOR_TYPE_FUZZY] = MSG_EnemyTattle_Fuzzy,
    [ACTOR_TYPE_KOOPA_TROOPA] = MSG_EnemyTattle_KoopaTroopa,
    [ACTOR_TYPE_PARATROOPA] = MSG_EnemyTattle_Paratroopa,
    [ACTOR_TYPE_BOB_OMB] = MSG_EnemyTattle_BobOmb,
    [ACTOR_TYPE_BOB_OMB_DUP] = MSG_EnemyTattle_BobOmb,
    [ACTOR_TYPE_BULLET_BILL] = MSG_EnemyTattle_BulletBill,
    [ACTOR_TYPE_BILL_BLASTER] = MSG_EnemyTattle_BillBlaster,
    [ACTOR_TYPE_CLEFT] = MSG_EnemyTattle_Cleft,
    [ACTOR_TYPE_MONTY_MOLE] = MSG_EnemyTattle_MontyMole,
    [ACTOR_TYPE_BANDIT] = MSG_EnemyTattle_Bandit,
    [ACTOR_TYPE_POKEY] = MSG_EnemyTattle_Pokey,
    [ACTOR_TYPE_POKEY_MUMMY] = MSG_EnemyTattle_PokeyMummy,
    [ACTOR_TYPE_SWOOPER] = MSG_EnemyTattle_Swooper,
    [ACTOR_TYPE_BUZZY_BEETLE] = MSG_EnemyTattle_BuzzyBeetle,
    [ACTOR_TYPE_STONE_CHOMP] = MSG_EnemyTattle_StoneChomp,
    [ACTOR_TYPE_PIRANHA_PLANT] = MSG_EnemyTattle_PiranhaPlant,
    [ACTOR_TYPE_FOREST_FUZZY] = MSG_EnemyTattle_ForestFuzzy,
    [ACTOR_TYPE_HYPER_GOOMBA] = MSG_EnemyTattle_HyperGoomba,
    [ACTOR_TYPE_HYPER_PARAGOOMBA] = MSG_EnemyTattle_HyperParagoomba,
    [ACTOR_TYPE_HYPER_CLEFT] = MSG_EnemyTattle_HyperCleft,
    [ACTOR_TYPE_CLUBBA] = MSG_EnemyTattle_Clubba,
    [ACTOR_TYPE_SHY_GUY] = MSG_EnemyTattle_ShyGuy,
    [ACTOR_TYPE_GROOVE_GUY] = MSG_EnemyTattle_GrooveGuy,
    [ACTOR_TYPE_SKY_GUY] = MSG_EnemyTattle_SkyGuy,
    [ACTOR_TYPE_MEDI_GUY] = MSG_EnemyTattle_MediGuy,
    [ACTOR_TYPE_PYRO_GUY] = MSG_EnemyTattle_PyroGuy,
    [ACTOR_TYPE_SPY_GUY] = MSG_EnemyTattle_SpyGuy,
    [ACTOR_TYPE_FUZZIPEDE] = NULL,
    [ACTOR_TYPE_HURT_PLANT] = MSG_EnemyTattle_HurtPlant,
    [ACTOR_TYPE_M_BUSH] = MSG_EnemyTattle_MBush,
    [ACTOR_TYPE_AQUA_FUZZY] = NULL,
    [ACTOR_TYPE_JUNGLE_FUZZY] = MSG_EnemyTattle_JungleFuzzy,
    [ACTOR_TYPE_SPEAR_GUY] = MSG_EnemyTattle_SpearGuy,
    [ACTOR_TYPE_LAVA_BUBBLE] = MSG_EnemyTattle_LavaBubble,
    [ACTOR_TYPE_SPIKE_TOP] = MSG_EnemyTattle_SpikeTop,
    [ACTOR_TYPE_PUTRID_PIRANHA] = MSG_EnemyTattle_PutridPiranha,
    [ACTOR_TYPE_LAKITU] = MSG_EnemyTattle_Lakitu,
    [ACTOR_TYPE_SPINY] = MSG_EnemyTattle_Spiny,
    [ACTOR_TYPE_MONTY_MOLE_BOSS] = MSG_EnemyTattle_MontyMoleBoss,
    [ACTOR_TYPE_BZZAP] = MSG_EnemyTattle_Bzzap,
    [ACTOR_TYPE_CRAZEE_DAYZEE] = MSG_EnemyTattle_CrazeeDayzee,
    [ACTOR_TYPE_AMAZY_DAYZEE] = MSG_EnemyTattle_AmazyDayzee,
    [ACTOR_TYPE_RUFF_PUFF] = MSG_EnemyTattle_RuffPuff,
    [ACTOR_TYPE_SPIKE] = MSG_EnemyTattle_Spike,
    [ACTOR_TYPE_GULPIT] = MSG_EnemyTattle_Gulpit,
    [ACTOR_TYPE_GULPIT_ROCKS] = MSG_EnemyTattle_GulpitRocks,
    [ACTOR_TYPE_WHITE_CLUBBA] = MSG_EnemyTattle_WhiteClubba,
    [ACTOR_TYPE_FROST_PIRANHA] = MSG_EnemyTattle_FrostPiranha,
    [ACTOR_TYPE_SWOOPULA] = MSG_EnemyTattle_Swoopula,
    [ACTOR_TYPE_DUPLIGHOST] = MSG_EnemyTattle_Duplighost,
    [ACTOR_TYPE_GHOST_GOOMBARIO] = MSG_EnemyTattle_GhostGoombario,
    [ACTOR_TYPE_GHOST_KOOPER] = MSG_EnemyTattle_GhostKooper,
    [ACTOR_TYPE_GHOST_BOMBETTE] = MSG_EnemyTattle_GhostBombette,
    [ACTOR_TYPE_GHOST_PARAKARRY] = MSG_EnemyTattle_GhostParakarry,
    [ACTOR_TYPE_GHOST_BOW] = MSG_EnemyTattle_GhostBow,
    [ACTOR_TYPE_GHOST_WATT] = MSG_EnemyTattle_GhostWatt,
    [ACTOR_TYPE_GHOST_SUSHIE] = MSG_EnemyTattle_GhostSushie,
    [ACTOR_TYPE_GHOST_LAKILESTER] = MSG_EnemyTattle_GhostLakilester,
    [ACTOR_TYPE_ALBINO_DINO] = MSG_EnemyTattle_AlbinoDino,
    [ACTOR_TYPE_EMBER] = MSG_EnemyTattle_Ember,
    [ACTOR_TYPE_BONY_BEETLE] = MSG_EnemyTattle_BonyBeetle,
    [ACTOR_TYPE_DRY_BONES] = MSG_EnemyTattle_DryBones,
    [ACTOR_TYPE_DRY_BONES2] = MSG_EnemyTattle_DryBones,
    [ACTOR_TYPE_BOMBSHELL_BLASTER] = MSG_EnemyTattle_BombshellBlaster,
    [ACTOR_TYPE_BOMBSHELL_BILL] = MSG_EnemyTattle_BombshellBill,
    [ACTOR_TYPE_HAMMER_BROS] = MSG_EnemyTattle_HammerBros,
    [ACTOR_TYPE_KOOPATROL] = MSG_EnemyTattle_Koopatrol,
    [ACTOR_TYPE_MAGIKOOPA] = MSG_EnemyTattle_Magikoopa,
    [ACTOR_TYPE_FLYING_MAGIKOOPA] = MSG_EnemyTattle_MagikoopaDup,
    [ACTOR_TYPE_MAGICLONE] = MSG_EnemyTattle_Magiclone,
    [ACTOR_TYPE_FLYING_MAGICLONE] = MSG_EnemyTattle_MagicloneDup,
    [ACTOR_TYPE_RED_MAGIKOOPA] = MSG_EnemyTattle_RedMagikoopa,
    [ACTOR_TYPE_FLYING_RED_MAGIKOOPA] = MSG_EnemyTattle_FlyingRedMagikoopa,
    [ACTOR_TYPE_GREEN_MAGIKOOPA] = MSG_EnemyTattle_GreenMagikoopa,
    [ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA] = MSG_EnemyTattle_FlyingGreenMagikoopa,
    [ACTOR_TYPE_YELLOW_MAGIKOOPA] = MSG_EnemyTattle_YellowMagikoopa,
    [ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA] = MSG_EnemyTattle_FlyingYellowMagikoopa,
    [ACTOR_TYPE_GRAY_MAGIKOOPA] = MSG_EnemyTattle_GrayMagikoopa,
    [ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA] = MSG_EnemyTattle_FlyingGrayMagikoopa,
    [ACTOR_TYPE_WHITE_MAGIKOOPA] = MSG_EnemyTattle_FlyingWhiteMagikoopa,
    [ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA] = MSG_EnemyTattle_WhiteMagikoopa,
    [ACTOR_TYPE_UNUSED_5B] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_5C] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_5D] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_5E] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_5F] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_60] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_61] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_62] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_63] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_64] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_65] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_66] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_67] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_68] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_69] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_6A] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_MONTY_HOLE] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_6C] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_6D] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_PLAYER] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_GOOMBARIO] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_KOOPER] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_BOMBETTE] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_PARAKARRY] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_BOW] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_WATT] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_SUSHIE] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_LAKILESTER] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_TWINK] = NULL,
    [ACTOR_TYPE_UNUSED_78] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_UNUSED_79] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_THE_MASTER_1] = MSG_EnemyTattle_TheMaster1,
    [ACTOR_TYPE_THE_MASTER_2] = MSG_EnemyTattle_TheMaster2,
    [ACTOR_TYPE_THE_MASTER_3] = MSG_EnemyTattle_TheMaster3,
    [ACTOR_TYPE_CHAN] = MSG_EnemyTattle_Chan,
    [ACTOR_TYPE_LEE] = MSG_EnemyTattle_Lee,
    [ACTOR_TYPE_LEE_GOOMBARIO] = MSG_EnemyTattle_LeeGoombario,
    [ACTOR_TYPE_LEE_KOOPER] = MSG_EnemyTattle_LeeKooper,
    [ACTOR_TYPE_LEE_BOMBETTE] = MSG_EnemyTattle_LeeBombette,
    [ACTOR_TYPE_LEE_PARAKARRY] = MSG_EnemyTattle_LeeParakarry,
    [ACTOR_TYPE_LEE_BOW] = MSG_EnemyTattle_LeeBow,
    [ACTOR_TYPE_LEE_WATT] = MSG_EnemyTattle_LeeWatt,
    [ACTOR_TYPE_LEE_SUSHIE] = MSG_EnemyTattle_LeeSushie,
    [ACTOR_TYPE_LEE_LAKILESTER] = MSG_EnemyTattle_LeeLakilester,
    [ACTOR_TYPE_KAMMY_KOOPA] = NULL,
    [ACTOR_TYPE_JR_TROOPA1] = NULL,
    [ACTOR_TYPE_JR_TROOPA2] = MSG_EnemyTattle_JrTroopa1,
    [ACTOR_TYPE_JR_TROOPA3] = MSG_EnemyTattle_JrTroopa2,
    [ACTOR_TYPE_JR_TROOPA4] = MSG_EnemyTattle_JrTroopa3,
    [ACTOR_TYPE_JR_TROOPA5] = MSG_EnemyTattle_JrTroopa4,
    [ACTOR_TYPE_JR_TROOPA6] = MSG_EnemyTattle_JrTroopa5,
    [ACTOR_TYPE_JR_TROOPA_DUP1] = MSG_EnemyTattle_JrTroopa5,
    [ACTOR_TYPE_JR_TROOPA_DUP2] = MSG_EnemyTattle_JrTroopa5,
    [ACTOR_TYPE_BLUE_GOOMBA_BOSS] = MSG_EnemyTattle_BlueGoombaBoss,
    [ACTOR_TYPE_RED_GOOMBA_BOSS] = MSG_EnemyTattle_RedGoombaBoss,
    [ACTOR_TYPE_GOOMBA_KING] = MSG_EnemyTattle_GoombaKing,
    [ACTOR_TYPE_GOOMNUT_TREE] = MSG_EnemyTattle_GoomnutTree,
    [ACTOR_TYPE_GOOMBARIO_TUTOR1] = NULL,
    [ACTOR_TYPE_MAGIKOOPA_BOSS] = MSG_EnemyTattle_MagikoopaBoss,
    [ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS] = MSG_EnemyTattle_MagikoopaBossDup,
    [ACTOR_TYPE_MAGIKOOPA_DUP1] = MSG_EnemyTattle_MagikoopaBoss,
    [ACTOR_TYPE_MAGIKOOPA_DUP2] = MSG_EnemyTattle_MagikoopaBossDup,
    [ACTOR_TYPE_FAKE_BOWSER] = MSG_EnemyTattle_FakeBowser,
    [ACTOR_TYPE_KOOPA_BROS] = MSG_EnemyTattle_KoopaBros,
    [ACTOR_TYPE_GREEN_NINJAKOOPA] = MSG_EnemyTattle_GreenNinjakoopa,
    [ACTOR_TYPE_RED_NINJAKOOPA] = MSG_EnemyTattle_RedNinjakoopa,
    [ACTOR_TYPE_BLUE_NINJAKOOPA] = MSG_EnemyTattle_BlueNinjakoopa,
    [ACTOR_TYPE_YELLOW_NINJAKOOPA] = MSG_EnemyTattle_YellowNinjakoopa,
    [ACTOR_TYPE_ELDSTAR] = NULL,
    [ACTOR_TYPE_BUZZAR] = MSG_EnemyTattle_Buzzar,
    [ACTOR_TYPE_TUTANKOOPA] = MSG_EnemyTattle_Tutankoopa,
    [ACTOR_TYPE_CHOMP] = MSG_EnemyTattle_Chomp,
    [ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE] = MSG_EnemyTattle_TubbaBlubba,
    [ACTOR_TYPE_TUBBA_BLUBBA] = MSG_EnemyTattle_TubbaBlubbaInvincible,
    [ACTOR_TYPE_TUBBA_HEART] = MSG_EnemyTattle_TubbaHeart,
    [ACTOR_TYPE_STILT_GUY] = MSG_EnemyTattle_StiltGuy,
    [ACTOR_TYPE_SHY_STACK] = MSG_EnemyTattle_ShyStack,
    [ACTOR_TYPE_SHY_SQUAD] = MSG_EnemyTattle_ShySquad,
    [ACTOR_TYPE_GENERAL_GUY] = NULL,
    [ACTOR_TYPE_TOY_TANK] = MSG_EnemyTattle_GeneralGuy,
    [ACTOR_TYPE_LIGHT_BULB] = NULL,
    [ACTOR_TYPE_SIGNAL_GUY] = MSG_EnemyTattle_ShyGuy,
    [ACTOR_TYPE_SHY_SQUAD_DUP] = NULL,
    [ACTOR_TYPE_SHY_GUY_DUP] = MSG_EnemyTattle_ShyGuy,
    [ACTOR_TYPE_ANTI_GUY] = MSG_EnemyTattle_AntiGuy,
    [ACTOR_TYPE_ANTI_GUY_DUP] = MSG_EnemyTattle_AntiGuy,
    [ACTOR_TYPE_BIG_LANTERN_GHOST] = MSG_EnemyTattle_BigLanternGhost,
    [ACTOR_TYPE_GOOMBA_KING_DUP] = MSG_EnemyTattle_GoombaKing,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_1] = MSG_EnemyTattle_LavaPiranhaPhase1,
    [ACTOR_TYPE_LAVA_PIRANHA_PHASE_2] = MSG_EnemyTattle_LavaPiranhaPhase2,
    [ACTOR_TYPE_LAVA_BUD_PHASE_1] = MSG_EnemyTattle_LavaBudPhase1,
    [ACTOR_TYPE_LAVA_BUD_PHASE_2] = MSG_EnemyTattle_LavaBudPhase2,
    [ACTOR_TYPE_PETIT_PIRANHA] = MSG_EnemyTattle_PetitPiranha,
    [ACTOR_TYPE_PETIT_PIRANHA_BOMB] = MSG_EnemyTattle_LavaPiranhaPhase1,
    [ACTOR_TYPE_KENT_C_KOOPA] = MSG_EnemyTattle_KentCKoopa,
    [ACTOR_TYPE_HUFF_N_PUFF] = MSG_EnemyTattle_HuffNPuff,
    [ACTOR_TYPE_TUFF_PUFF] = MSG_EnemyTattle_TuffPuff,
    [ACTOR_TYPE_MONSTAR] = MSG_EnemyTattle_Monstar,
    [ACTOR_TYPE_CRYSTAL_KING] = MSG_EnemyTattle_CrystalKing,
    [ACTOR_TYPE_CRYSTAL_CLONE] = MSG_EnemyTattle_CrystalClone,
    [ACTOR_TYPE_CRYSTAL_BIT] = MSG_EnemyTattle_CrystalBit,
    [ACTOR_TYPE_INTRO_BOWSER] = NULL,
    [ACTOR_TYPE_BOWSER_PHASE_1] = MSG_EnemyTattle_BowserPhase1,
    [ACTOR_TYPE_BOWSER_DUP1] = MSG_EnemyTattle_BowserPhase1,
    [ACTOR_TYPE_BOWSER_PHASE_2] = MSG_EnemyTattle_BowserPhase2,
    [ACTOR_TYPE_BOWSER_DUP2] = MSG_EnemyTattle_BowserPhase2,
    [ACTOR_TYPE_BOWSER_PHASE_3] = MSG_EnemyTattle_BowserPhase3,
    [ACTOR_TYPE_BOWSER_DUP3] = MSG_EnemyTattle_BowserPhase3,
    [ACTOR_TYPE_BLOOPER] = MSG_EnemyTattle_Blooper,
    [ACTOR_TYPE_ELECTRO_BLOOPER1] = MSG_EnemyTattle_ElectroBlooper,
    [ACTOR_TYPE_ELECTRO_BLOOPER2] = MSG_EnemyTattle_ElectroBlooper,
    [ACTOR_TYPE_SUPER_BLOOPER1] = MSG_EnemyTattle_SuperBlooper,
    [ACTOR_TYPE_SUPER_BLOOPER2] = MSG_EnemyTattle_SuperBlooper,
    [ACTOR_TYPE_BLOOPER_BABY] = MSG_EnemyTattle_BlooperBaby,
    [ACTOR_TYPE_LAKILESTER_DUP] = MSG_EnemyTattle_GhostLakilester,
    [ACTOR_TYPE_SLOT_MACHINE_START] = MSG_EnemyTattle_SlotMachineStart,
    [ACTOR_TYPE_SLOT_MACHINE_STOP] = MSG_EnemyTattle_SlotMachineStop,
    [ACTOR_TYPE_WHACKA] = MSG_EnemyTattle_Whacka,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP1] = MSG_EnemyTattle_SlotMachineStart,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP2] = MSG_EnemyTattle_SlotMachineStart,
    [ACTOR_TYPE_SLOT_MACHINE_START_DUP3] = MSG_EnemyTattle_SlotMachineStart,
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
    STATUS_NORMAL,          ANIM_Mario_Walking,
    STATUS_DANGER,          ANIM_Mario_AnimPanting,
    STATUS_STONE,           ANIM_Mario_50001,
    STATUS_SLEEP,           ANIM_Mario_30004,
    STATUS_DIZZY,           ANIM_Mario_30006,
    STATUS_STOP,            ANIM_Mario_StandStill,
    STATUS_HUSTLE,          ANIM_Mario_Running,
    STATUS_BERSERK,         ANIM_Mario_40028,
    STATUS_PARALYZE,        ANIM_Mario_30004,
    STATUS_FROZEN,          ANIM_Mario_StunnedStill,
    STATUS_TRANSPARENT,     ANIM_Mario_10002,
    STATUS_TURN_DONE,       ANIM_Mario_StandStill,
    STATUS_13,              ANIM_Mario_40029,
    STATUS_14,              ANIM_Mario_4002A,
    STATUS_15,              ANIM_Mario_30003,
    STATUS_18,              ANIM_Mario_30005,
    STATUS_16,              ANIM_Mario_CrouchStill,
    STATUS_THINKING,        ANIM_Mario_Thinking,
    STATUS_WEARY,           ANIM_Mario_1000D,
    STATUS_END
};

s32 bMarioDefendAnims[] = {
    STATUS_NORMAL,          ANIM_Mario_Crouch,
    STATUS_DANGER,          ANIM_Mario_AnimPanting,
    STATUS_STONE,           ANIM_Mario_50001,
    STATUS_SLEEP,           ANIM_Mario_30004,
    STATUS_DIZZY,           ANIM_Mario_30006,
    STATUS_STOP,            ANIM_Mario_StandStill,
    STATUS_HUSTLE,          ANIM_Mario_Crouch,
    STATUS_BERSERK,         ANIM_Mario_Crouch,
    STATUS_PARALYZE,        ANIM_Mario_30004,
    STATUS_FROZEN,          ANIM_Mario_StunnedStill,
    STATUS_TRANSPARENT,     ANIM_Mario_10002,
    STATUS_TURN_DONE,       ANIM_Mario_StandStill,
    STATUS_13,              ANIM_Mario_40029,
    STATUS_14,              ANIM_Mario_4002A,
    STATUS_15,              ANIM_Mario_30003,
    STATUS_18,              ANIM_Mario_30005,
    STATUS_16,              ANIM_Mario_CrouchStill,
    STATUS_THINKING,        ANIM_Mario_Thinking,
    STATUS_WEARY,           ANIM_Mario_1000D,
    STATUS_END
};

s32 bMarioHideAnims[] = {
    STATUS_NORMAL,          ANIM_Mario_Crouch,
    STATUS_DANGER,          ANIM_Mario_AnimPanting,
    STATUS_STONE,           ANIM_Mario_50001,
    STATUS_SLEEP,           ANIM_Mario_30004,
    STATUS_DIZZY,           ANIM_Mario_30006,
    STATUS_STOP,            ANIM_Mario_StandStill,
    STATUS_HUSTLE,          ANIM_Mario_8000E,
    STATUS_BERSERK,         ANIM_Mario_8000E,
    STATUS_PARALYZE,        ANIM_Mario_30004,
    STATUS_FROZEN,          ANIM_Mario_StunnedStill,
    STATUS_TRANSPARENT,     ANIM_Mario_10002,
    STATUS_TURN_DONE,       ANIM_Mario_Crouch,
    STATUS_13,              ANIM_Mario_40029,
    STATUS_14,              ANIM_Mario_4002A,
    STATUS_15,              ANIM_Mario_30003,
    STATUS_18,              ANIM_Mario_30005,
    STATUS_16,              ANIM_Mario_CrouchStill,
    STATUS_THINKING,        ANIM_Mario_Thinking,
    STATUS_WEARY,           ANIM_Mario_1000D,
    STATUS_END
};

s32 bPeachIdleAnims[] = {
    STATUS_NORMAL,          ANIM_Peach_A0002,
    STATUS_TURN_DONE,       ANIM_Peach_C0028,
    STATUS_END
};

s32 bMarioDefenseTable[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END
};

s32 bPlayerStatusTable[] = {
    STATUS_NORMAL,          100,
    STATUS_DEFAULT,         100,
    STATUS_SLEEP,           100,
    STATUS_POISON,          100,
    STATUS_FROZEN,          100,
    STATUS_DIZZY,           100,
    STATUS_FEAR,            100,
    STATUS_STATIC,          100,
    STATUS_PARALYZE,        100,
    STATUS_SHRINK,          100,
    STATUS_STOP,            100,
    STATUS_DEFAULT_TURN_MOD,  0,
    STATUS_SLEEP_TURN_MOD,    0,
    STATUS_POISON_TURN_MOD,   0,
    STATUS_FROZEN_TURN_MOD,   0,
    STATUS_DIZZY_TURN_MOD,    0,
    STATUS_FEAR_TURN_MOD,     0,
    STATUS_STATIC_TURN_MOD,   0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD,   0,
    STATUS_STOP_TURN_MOD,     0,
    STATUS_END
};

ActorBlueprint bPlayerActorBlueprint = {
    .type = ACTOR_TYPE_PLAYER,
    .maxHP = 99,
    .statusTable = bPlayerStatusTable,

    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
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

//TODO Vec3f[]
f32 D_802835DC[] = {
    0.0f, 4.5, 0.0f, 1.0f, 4.0f, 0.0f, 2.0f, 3.0f, 0.0f, 3.0f, 2.0f, 0.0f, 3.5f, 1.0f, 0.0f, 4.0f, 0.0f, 0.0f, 4.5,
    0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 4.5, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f, 3.5f, -1.0f, 0.0f, 3.0f, -2.0f, 0.0f, 2.0f, -3.0f,
    0.0f, 1.0f, -4.0f, 0.0f, 0.0f, -4.5f, 0.0f,
};

//TODO Vec3f[]
f32 D_80283690[] = {
    1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f,
    0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f, 1.1f, 1.1f, 1.1f, 1.0f, 1.0f,
    1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f,
};

extern EntityModelScript D_80283D98;
EntityModelScript* D_80283744[] = {
    NULL, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98, &D_80283D98,
};

s32 bMessages[] = {
    [BTL_MSG_00]    MSG_Menus_Merlee_IncreaseAttack,
    [BTL_MSG_01]    MSG_Menus_Merlee_DecreaseDamage,
    [BTL_MSG_02]    MSG_Menus_Merlee_IncreaseStarPoints,
    [BTL_MSG_03]    MSG_Menus_Merlee_Exhausted,
    [BTL_MSG_04]    MSG_Menus_ChargeHammer,
    [BTL_MSG_05]    MSG_Menus_ChargeHammerMore,
    [BTL_MSG_06]    MSG_Menus_ChargeJump,
    [BTL_MSG_07]    MSG_Menus_ChargeJumpMore,
    [BTL_MSG_08]    MSG_Menus_ChargeMaxedOut,
    [BTL_MSG_09]    MSG_Menus_EnemyMissed,

    // player status effects
    [BTL_MSG_0A]    MSG_Menus_PlayerDazed,
    [BTL_MSG_0B]    MSG_Menus_PlayerAsleep,
    [BTL_MSG_0C]    MSG_Menus_PlayerFrozen,
    [BTL_MSG_0D]    MSG_Menus_PlayerPoisoned,
    [BTL_MSG_0E]    MSG_Menus_PlayerShrunk,
    [BTL_MSG_0F]    MSG_Menus_PlayerParalyzed,
    [BTL_MSG_10]    MSG_Menus_PlayerElectricCharge,
    [BTL_MSG_11]    MSG_Menus_PlayerTransparent,

    // enemy status effects
    [BTL_MSG_12]    MSG_Menus_EnemyDazed,
    [BTL_MSG_13]    MSG_Menus_EnemyAsleep,
    [BTL_MSG_14]    MSG_Menus_EnemyFrozen,
    [BTL_MSG_15]    MSG_Menus_EnemyPoisoned,
    [BTL_MSG_16]    MSG_Menus_EnemyShrunk,
    [BTL_MSG_17]    MSG_Menus_EnemyParalyzed,
    [BTL_MSG_18]    MSG_Menus_EnemyElectrified,
    [BTL_MSG_19]    MSG_Menus_EnemyCantMove,

    [BTL_MSG_1A]    MSG_Menus_StarEnergyRecharged,
    [BTL_MSG_1B]    MSG_Menus_StarEnergyMaxedOut,
    [BTL_MSG_1C]    MSG_Menus_StarEnergyFilled,
    [BTL_MSG_1D]    MSG_Menus_AttackUp,
    [BTL_MSG_1E]    MSG_Menus_DefenseUp,
    [BTL_MSG_1F]    MSG_Menus_0084,
    [BTL_MSG_20]    MSG_Menus_0085,

    [BTL_MSG_21]    MSG_Menus_EnemyTransparent,
    [BTL_MSG_22]    MSG_Menus_EnemyElectricCharge,
    [BTL_MSG_23]    MSG_Menus_PartnerInjured,
    [BTL_MSG_24]    MSG_Menus_ChargeGoombario,
    [BTL_MSG_25]    MSG_Menus_ChargeGoombarioMore,
    [BTL_MSG_26]    MSG_Menus_WaterBlockBegin,
    [BTL_MSG_27]    MSG_Menus_WaterBlockEnd,
    [BTL_MSG_28]    MSG_Menus_CloudNineBegin,
    [BTL_MSG_29]    MSG_Menus_CloudNineEnd,
    [BTL_MSG_2A]    MSG_Menus_TurboChargeBegin,
    [BTL_MSG_2B]    MSG_Menus_TurboChargeEnd,
    [BTL_MSG_2C]    MSG_Menus_ChillOutBegin,
    [BTL_MSG_2D]    MSG_Menus_CloudNineBegin,

    // move action command tips
    [BTL_MSG_2E]    MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_2F]    MSG_Menus_MoveTip_PushLeftWithTiming,
    [BTL_MSG_30]    MSG_Menus_MoveTip_PressBeforeStriking,
    [BTL_MSG_31]    MSG_Menus_MoveTip_PressRepeatedly,
    [BTL_MSG_32]    MSG_Menus_MoveTip_PushLeftRepeatedly,
    [BTL_MSG_33]    MSG_Menus_MoveTip_PushLeftToAim,
    [BTL_MSG_34]    MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_35]    MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_36]    MSG_Menus_MoveTip_PressAsShown,
    [BTL_MSG_37]    MSG_Menus_MoveTip_NOT_USED_1,
    [BTL_MSG_38]    MSG_Menus_MoveTip_PressAsLightsUp,
    [BTL_MSG_39]    MSG_Menus_MoveTip_NOT_USED_2,
    [BTL_MSG_3A]    MSG_Menus_MoveTip_PressBothRepeatedly,
    [BTL_MSG_3B]    MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_3C]    MSG_Menus_MoveTip_HoldThenTap,
    [BTL_MSG_3D]    MSG_Menus_MoveTip_HoldThenRelease,
    [BTL_MSG_3E]    MSG_Menus_MoveTip_MoveToAim,
    [BTL_MSG_3F]    MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_40]    MSG_Menus_MoveTip_PressToRunAway,
    [BTL_MSG_41]    MSG_Menus_MoveTip_PressToReduceDamage,
    [BTL_MSG_42]    MSG_Menus_MoveTip_NOT_USED_3,

    // no targets available
    [BTL_MSG_43]    MSG_Menus_Battle_NoTarget_Jump,
    [BTL_MSG_44]    MSG_Menus_Battle_NoTarget_Hammer,
    [BTL_MSG_45]    MSG_Menus_Battle_NoTarget_Item,
    [BTL_MSG_46]    0,
    [BTL_MSG_47]    0,

    // errors and warnings
    [BTL_MSG_48]    MSG_Menus_Battle_CantSelectNow,
    [BTL_MSG_49]    MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_4A]    MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_4B]    MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_4C]    MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_4D]    MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_4E]    MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_4F]    MSG_Menus_Battle_CantUseItems,
    [BTL_MSG_50]    MSG_Menus_Battle_CantSwitch,
    [BTL_MSG_51]    MSG_Menus_Battle_CantMove,
    [BTL_MSG_52]    MSG_Menus_Battle_CantSwitch,
    [BTL_MSG_53]    MSG_Menus_Battle_CantMove,
    [BTL_MSG_54]    MSG_Menus_Battle_CantSelectNow,
};

s32 bActorMessages[] = {
    MSG_Menus_Party_Mario,
    MSG_Menus_Party_Goombario,
    MSG_Menus_Party_Kooper,
    MSG_Menus_Party_Bombette,
    MSG_Menus_Party_Parakarry,
    MSG_Menus_Party_Goompa,
    MSG_Menus_Party_Watt,
    MSG_Menus_Party_Sushie,
    MSG_Menus_Party_Lakilester,
    MSG_Menus_Party_Bow,
    MSG_Menus_Party_Goombaria,
    MSG_Menus_Party_Twink,
    MSG_Menus_Party_Peach
};

PopupMessage* bPopupMessage = NULL;

s32 D_802838FC_padding = 0;

//TODO split files

#include "ui/battle/cursor_hand.png.inc.c"
#include "ui/battle/cursor_hand.pal.inc.c"

Vtx D_80283B20[4] = {
    {{{ -22, -6, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{   9, -6, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
    {{{   9, 25, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
    {{{ -22, 25, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
};

Gfx D_80283B60[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_80283B00),
    gsDPLoadTextureTile_4b(D_80283900, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_80283B20, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsSPEndDisplayList(),
};

EntityModelScript D_80283C48 = STANDARD_ENTITY_MODEL_SCRIPT(D_80283B60, RENDER_MODE_ALPHATEST);

Vtx D_80283C68[4] = {
    {{{ -16, -16, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
    {{{  15, -16, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
    {{{  15,  15, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{ -16,  15, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
};

Gfx D_80283CA8[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_menu_spirits_pal),
    gsDPLoadTextureTile_4b(ui_battle_menu_spirits_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_80283C68, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript D_80283D98 = STANDARD_ENTITY_MODEL_SCRIPT(D_80283CA8, RENDER_MODE_2D);

Vtx D_80283DB8[4] = {
    {{{ -16, -16, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
    {{{  15, -16, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{  15,  15, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
    {{{ -16,  15, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
};

Gfx D_80283DF8[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_unk_star_pal),
    gsDPLoadTextureTile_4b(ui_battle_unk_star_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(D_80283DB8, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),

};
EntityModelScript D_80283EE8 = STANDARD_ENTITY_MODEL_SCRIPT(D_80283DF8, RENDER_MODE_ALPHATEST);

s32 D_80283F04_padding = 0;
s32 D_80283F08_padding = 0;
s32 D_80283F0C_padding = 0;

#define BATTLE_PARTNER_ENTRY(name, Y) \
    { \
        (u32)battle_partner_##name##_ROM_START, \
        (u32)battle_partner_##name##_ROM_END, \
        battle_partner_##name##_VRAM, \
        &battle_partner_##name, \
        Y \
    }

PartnerDMAData bPartnerDmaTable[] = {
    {},
    BATTLE_PARTNER_ENTRY(goombario, 0),
    BATTLE_PARTNER_ENTRY(kooper, 0),
    BATTLE_PARTNER_ENTRY(bombette, 0),
    BATTLE_PARTNER_ENTRY(parakarry, 30),
    BATTLE_PARTNER_ENTRY(goompa, 0),
    BATTLE_PARTNER_ENTRY(watt, 20),
    BATTLE_PARTNER_ENTRY(sushie, 0),
    BATTLE_PARTNER_ENTRY(lakilester, 10),
    BATTLE_PARTNER_ENTRY(bow, 20),
    {},
    BATTLE_PARTNER_ENTRY(twink, 30),
};

// BSS
BSS PopupMessage popupMessages[32];
BSS s16 D_8029F640;
BSS s16 D_8029F642;
BSS s16 D_8029F644;
BSS s16 D_8029F646;
BSS s16 D_8029F648;
BSS s16 D_8029F64A;
BSS s16 D_8029F64C;
BSS s16 D_8029F64E;
BSS s16 D_8029F650;

extern HudScript HES_AimReticle;
extern HudScript HES_AimTarget;
extern HudScript HES_CDownButton;
extern HudScript HES_CLeftButton;
extern HudScript HES_CRightButton;
extern HudScript HES_CUpButton;
extern HudScript HES_Item_Boots1;
extern HudScript HES_Item_Boots2;
extern HudScript HES_Item_Boots3;
extern HudScript HES_Item_Hammer1;
extern HudScript HES_Item_Hammer2;
extern HudScript HES_Item_Hammer3;
extern HudScript HES_Item_Items;
extern HudScript HES_MashBButton2;
extern HudScript HES_MashCDownButton1;
extern HudScript HES_MashCLeftButton;
extern HudScript HES_MashCRightButton1;
extern HudScript HES_MashCUpButton;
extern HudScript HES_RotateStickCW;
extern HudScript HES_StickBackAndForth;
extern HudScript HES_StickTapLeft;
extern HudScript HES_StickTapRight;
extern HudScript HES_TimingBlink;

void func_8024F394(void* data);
void func_8024F5AC(void* data);
void func_8024F768(void* data);
void btl_update_message_popup(void* popup);
void btl_show_message_popup(void* popup);

void btl_popup_messages_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        popup->active = FALSE;
        popup->message = NULL;
    }
}

void btl_popup_messages_delete(void) {
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

void btl_popup_messages_update(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->updateFunc != NULL) {
            popup->updateFunc(popup);
        }
    }
}

void btl_popup_messages_draw_world_geometry(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->renderWorldFunc != NULL) {
            popup->renderWorldFunc(popup);
        }
    }
}

void btl_popup_messages_draw_ui(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->renderUIFunc != NULL) {
            popup->renderUIFunc(popup);
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

void func_8024EFE0(f32 x, f32 y, f32 z, s32 numMessages, s32 arg4, s32 arg5) {
    BattleStatus* battleStatus = &gBattleStatus;
    PopupMessage* popup;
    Message* message;
    EntityModelScript** sp10;
    f32 var_f20;
    f32 var_f22;
    f32* f1;
    f32* f2;
    f32* f3;
    s32 arg5mod8;
    s32 iMod8;
    s32 sign;
    s32 cond;
    s32 one;
    s32 two;
    s32 i;

    var_f22 = 1.0f;
    cond = FALSE;
    var_f20 = 1.0f;
    if (numMessages < 1) {
        numMessages = 1;
        cond = TRUE;
        var_f22 = 0.4f;
        var_f20 = 0.7f;
    }

    if (battleStatus->flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) {
        var_f22 *= 2.0;
    }

    popup = btl_create_popup();
    if (popup != NULL) {
        sign = 1;
        if (arg5 < 0) {
            arg5 = -arg5;
            sign = -1;
        }

        while (TRUE) {
            if (arg5 > 5) {
                arg5 -= 5;
            } else {
                break;
            }
        }

        battleStatus->unk_90 = 0;
        popup->updateFunc = func_8024F394;
        popup->renderWorldFunc = func_8024F5AC;
        popup->unk_00 = 0;
        popup->renderUIFunc = NULL;
        popup->messageIndex = 1;
        popup->active |= 0x10;
        message = popup->message = heap_malloc(numMessages * sizeof(*popup->message));
        ASSERT (popup->message != NULL);

        for (i = 0; i < numMessages; i++, message++) {
            sp10 = &D_80283744[numMessages];
            message->unk_00 = 1;
            message->unk_04 = load_entity_model(*sp10);
            set_entity_model_flags(message->unk_04, ENTITY_MODEL_FLAG_HIDDEN);
            bind_entity_model_setupGfx(message->unk_04, message, func_8024F768);
            message->pos.x = x;
            message->pos.y = y;
            message->pos.z = z;
            arg5mod8 = arg5 % 8;
            arg5++;

            one = 1;
            two = 2;

            f1 = &D_802835DC[arg5mod8 * 3];
            f2 = &D_802835DC[arg5mod8 * 3 + one];
            f3 = &D_802835DC[arg5mod8 * 3 + two];
            message->vel.x = 2.0 * *f1 * sign * var_f20;
            message->vel.y = 2.0 * *f2 * var_f20;
            message->vel.z = 2.0 * *f3 * var_f20;
            message->accel.x = *f1 * sign * var_f20;
            message->accel.y = *f2 * var_f20;
            message->accel.z = *f3 * var_f20;

            iMod8 = (i % 8);
            message->scale = D_80283690[iMod8 * 3] * var_f22;
            message->rotZ = 0;
            message->rotVelZ = sign * 107;
            message->rotY = clamp_angle(180.0f - gCameras[CAM_BATTLE].currentYaw);
            message->unk_20 = 14;
            message->unk_24 = arg4;
            message->unk_44 = 240;
            if (cond) {
                message->unk_44 = 10;
            }
            message->unk_48 = 255.0f;
        }
    }
}

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
                    clear_entity_model_flags(modelIdx, MODEL_FLAG_FLAG_20);
                }
                exec_entity_model_commandlist(modelIdx);
                break;
            } else {
                exec_entity_model_commandlist(modelIdx);
                if (message->unk_20 >= 0) {
                    message->pos.x += message->vel.x;
                    message->pos.y += message->vel.y;
                    message->pos.z += message->vel.z;
                }
                message->rotY = clamp_angle(180.0f - gCameras[CAM_BATTLE].currentYaw);
                message->rotZ += message->rotVelZ;
                message->rotZ = clamp_angle(message->rotZ);
                message->rotVelZ *= 0.8;
                if (message->unk_20 < 10) {
                    message->accel.x *= 0.5;
                    message->accel.y *= 0.5;
                    message->accel.z *= 0.5;
                    message->vel.x = message->accel.x;
                    message->vel.y = message->accel.y;
                    message->vel.z = message->accel.z;
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
    Matrix4f mtxRotX;
    Matrix4f mtxRotY;
    Matrix4f mtxRotZ;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f mtxScale;
    Mtx sp218;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00 != 0) {
            if (message->unk_24 != 0) {
                break;
            } else {
                s32 modelIdx = message->unk_04;

                guTranslateF(sp18, message->pos.x, message->pos.y, message->pos.z);
                guRotateF(mtxRotX, 0.0f, 1.0f, 0.0f, 0.0f);
                guRotateF(mtxRotY, message->rotY, 0.0f, 1.0f, 0.0f);
                guRotateF(mtxRotZ, message->rotZ, 0.0f, 0.0f, 1.0f);
                guScaleF(mtxScale, message->scale, message->scale, message->scale);
                guMtxCatF(mtxRotZ, mtxRotX, sp158);
                guMtxCatF(sp158, mtxRotY, sp118);
                guMtxCatF(mtxScale, sp118, sp158);
                guMtxCatF(sp158, sp18, sp198);
                guMtxF2L(sp198, &sp218);
                draw_entity_model_A(modelIdx, &sp218);
            }
        }
    }
}

void func_8024F768(void* data) {
    Message* message = data;
    s32 alphaAmt = message->unk_44;

    if (alphaAmt > 10) {
        alphaAmt = 10;
    }
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, (alphaAmt * 255) / 10);
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
        popup->updateFunc = btl_update_message_popup;
        popup->renderUIFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->renderWorldFunc = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        popup->unk_17 = TRUE;
        popup->message = NULL;
        D_8029F640 = 0;
        bPopupMessage = popup;
        D_8029F64A = FALSE;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

void btl_show_variable_battle_message(s32 messageIndex, s32 duration, s32 varValue) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = btl_update_message_popup;
        popup->renderUIFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->renderWorldFunc = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        popup->unk_17 = TRUE;
        popup->message = NULL;
        D_8029F640 = varValue;
        bPopupMessage = popup;
        D_8029F64A = FALSE;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

s32 btl_is_popup_displayed(void) {
    return bPopupMessage != NULL;
}

void btl_set_popup_duration(s32 duration) {
    PopupMessage* popup = bPopupMessage;

    if (D_8029F64A && popup != NULL) {
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
    PopupMessage* popup = bPopupMessage;

    if (popup != NULL && popup->messageIndex < BTL_MSG_43 && popup->messageIndex >= BTL_MSG_2E) {
        popup->duration = 0;
    }
}

void btl_update_message_popup(void* data) {
    PopupMessage* popup = data;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 shouldDisposeWindow = FALSE;

    s32 temp_a0;

    switch (popup->messageIndex) {
        case BTL_MSG_00:
        case BTL_MSG_01:
        case BTL_MSG_02:
        case BTL_MSG_03:
        case BTL_MSG_04:
        case BTL_MSG_05:
        case BTL_MSG_06:
        case BTL_MSG_07:
        case BTL_MSG_08:
        case BTL_MSG_09:
        case BTL_MSG_0A:
        case BTL_MSG_0B:
        case BTL_MSG_0C:
        case BTL_MSG_0D:
        case BTL_MSG_0E:
        case BTL_MSG_0F:
        case BTL_MSG_10:
        case BTL_MSG_11:
        case BTL_MSG_12:
        case BTL_MSG_13:
        case BTL_MSG_14:
        case BTL_MSG_15:
        case BTL_MSG_16:
        case BTL_MSG_17:
        case BTL_MSG_18:
        case BTL_MSG_19:
        case BTL_MSG_1A:
        case BTL_MSG_1B:
        case BTL_MSG_1C:
        case BTL_MSG_1D:
        case BTL_MSG_1E:
        case BTL_MSG_1F:
        case BTL_MSG_20:
        case BTL_MSG_21:
        case BTL_MSG_22:
        case BTL_MSG_23:
        case BTL_MSG_24:
        case BTL_MSG_25:
        case BTL_MSG_26:
        case BTL_MSG_27:
        case BTL_MSG_28:
        case BTL_MSG_29:
        case BTL_MSG_2A:
        case BTL_MSG_2B:
        case BTL_MSG_2C:
        case BTL_MSG_2D:
        case BTL_MSG_50:
        case BTL_MSG_51:
        case BTL_MSG_52:
        case BTL_MSG_53:
        case BTL_MSG_54:
            switch (popup->unk_16) {
                default:
                    break;
                case 0:
                    popup->unk_16 = 1;
                    break;
                case 1:
                    popup->unk_16 = 2;
                    break;
                case 2:
                    if (battleStatus->currentButtonsPressed & (BUTTON_A | BUTTON_B)) {
                        popup->duration = 0;
                    }

                    if (popup->duration != 0) {
                        popup->duration--;
                    } else {
                        popup->unk_16 = 3;
                    }
                    break;
                case 4:
                    shouldDisposeWindow = TRUE;
                    break;
                case 3:
                    popup->unk_16 = 4;
                    break;
            }
            break;
        // move action command tips
        case BTL_MSG_2E:
        case BTL_MSG_2F:
        case BTL_MSG_30:
        case BTL_MSG_31:
        case BTL_MSG_32:
        case BTL_MSG_33:
        case BTL_MSG_34:
        case BTL_MSG_35:
        case BTL_MSG_36:
        case BTL_MSG_37:
        case BTL_MSG_38:
        case BTL_MSG_39:
        case BTL_MSG_3A:
        case BTL_MSG_3B:
        case BTL_MSG_3C:
        case BTL_MSG_3D:
        case BTL_MSG_3E:
        case BTL_MSG_3F:
        case BTL_MSG_40:
        case BTL_MSG_41:
        case BTL_MSG_42:
            temp_a0 = battleStatus->actionCommandMode;
            D_8029F64A = TRUE;
            if (temp_a0 == ACTION_COMMAND_MODE_NOT_LEARNED) {
                D_8029F64A = FALSE;
                shouldDisposeWindow = TRUE;
                break;
            }

            switch (popup->unk_16) {
                case 0:
                    gBattleStatus.flags1 |= BS_FLAGS1_4000;
                    gBattleStatus.flags1 &= ~BS_FLAGS1_10000;
                    switch (popup->messageIndex) {
                        case BTL_MSG_32:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_2F:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_33:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AimTarget);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            hud_element_create_transform_B(D_8029F644);
                            break;
                        case BTL_MSG_34:
                            D_8029F642 = hud_element_create(&HES_CUpButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_CDownButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);

                            D_8029F646 = hud_element_create(&HES_CLeftButton);
                            hud_element_set_flags(D_8029F646, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F646, -100, -100);

                            D_8029F648 = hud_element_create(&HES_CRightButton);
                            hud_element_set_flags(D_8029F648, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F648, -100, -100);
                            break;
                        case BTL_MSG_35:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_36:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);

                            D_8029F646 = hud_element_create(&HES_CDownButton);
                            hud_element_set_flags(D_8029F646, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F646, -100, -100);
                            break;
                        case BTL_MSG_37:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_38:
                            D_8029F642 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_39:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            D_8029F644 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_3A:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_3D:
                            D_8029F642 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AButtonDown);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_3E:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AimTarget);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            hud_element_create_transform_B(D_8029F644);

                            D_8029F646 = hud_element_create(&HES_AimReticle);
                            hud_element_set_flags(D_8029F646, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F646, -100, -100);
                            hud_element_create_transform_B(D_8029F646);
                            break;
                        case BTL_MSG_40:
                        case BTL_MSG_41:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            // fallthrough
                        case BTL_MSG_2E:
                        case BTL_MSG_30:
                        case BTL_MSG_31:
                        case BTL_MSG_3B:
                        case BTL_MSG_3C:
                        case BTL_MSG_3F:
                        case BTL_MSG_42:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                    }
                    popup->unk_16 = 1;
                    break;
                case 1:
                    if (gBattleStatus.flags1 & BS_FLAGS1_10000) {
                        gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
                        set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW_TRANSPARENT);
                        popup->duration = 0;
                        popup->unk_16 = 2;
                    } else if (!(gBattleStatus.flags1 & BS_FLAGS1_4000) && (temp_a0 != 2)) {
                        set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW_TRANSPARENT);
                        switch (popup->messageIndex) {
                            case BTL_MSG_31:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                break;
                            case BTL_MSG_32:
                                hud_element_set_script(D_8029F642, &HES_StickMashLeft);
                                break;
                            case BTL_MSG_2F:
                                hud_element_set_script(D_8029F642, &HES_StickTapLeft);
                                hud_element_set_script(D_8029F644, &HES_TimingBlink);
                                break;
                            case BTL_MSG_33:
                                hud_element_set_script(D_8029F642, &HES_StickTapLeft);
                                hud_element_set_script(D_8029F644, &HES_AimTarget);
                                break;
                            case BTL_MSG_34:
                                hud_element_set_script(D_8029F642, &HES_MashCUpButton);
                                hud_element_set_script(D_8029F644, &HES_MashCDownButton1);
                                hud_element_set_script(D_8029F646, &HES_MashCLeftButton);
                                hud_element_set_script(D_8029F648, &HES_MashCRightButton1);
                                break;
                            case BTL_MSG_35:
                                hud_element_set_script(D_8029F642, &HES_StickBackAndForth);
                                break;
                            case BTL_MSG_36:
                                hud_element_set_script(D_8029F642, &HES_PressAButton);
                                hud_element_set_script(D_8029F644, &HES_PressBButton);
                                hud_element_set_script(D_8029F646, &HES_PressCDownButton);
                                break;
                            case BTL_MSG_37:
                                hud_element_set_script(D_8029F642, &HES_RotateStickCW);
                                break;
                            case BTL_MSG_38:
                                hud_element_set_script(D_8029F642, &HES_TimingBlink);
                                hud_element_set_script(D_8029F644, &HES_MashAButton);
                                break;
                            case BTL_MSG_39:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                hud_element_set_script(D_8029F644, &HES_MashBButton2);
                                break;
                            case BTL_MSG_3A:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                hud_element_set_script(D_8029F644, &HES_MashBButton1);
                                break;
                            case BTL_MSG_3B:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                break;
                            case BTL_MSG_3D:
                                hud_element_set_script(D_8029F642, &HES_TimingBlink);
                                hud_element_set_script(D_8029F644, &HES_PressAButton);
                                break;
                            case BTL_MSG_3E:
                                hud_element_set_script(D_8029F642, &HES_StickTapRight);
                                break;
                            case BTL_MSG_3F:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                break;
                            case BTL_MSG_40:
                            case BTL_MSG_41:
                                hud_element_set_script(D_8029F642, &HES_PressAButton);
                                /* fallthrough */
                            case BTL_MSG_2E:
                            case BTL_MSG_30:
                            case BTL_MSG_3C:
                            case BTL_MSG_42:
                                hud_element_set_script(D_8029F642, &HES_PressAButton);
                                break;
                        }
                        if (popup->duration != -1) {
                            popup->duration = 30;
                        }
                        popup->unk_16 = 2;
                        break;
                    }
                    break;
                case 2:
                    if ((temp_a0 != popup->unk_16) || (gBattleStatus.flags1 & BS_FLAGS1_10000)) {
                        s16* duration;

                        if (D_8029F64E < 192) {
                            if (D_8029F64C == 0) {
                                D_8029F64E += 10;
                                if (D_8029F64E > 192) {
                                    D_8029F64E = 192;
                                }
                            } else {
                                break;
                            }
                        }

                        gWindows[9].pos.y = D_8029F64E + D_8029F650;

                        duration = &popup->duration; // TODO required to match
                        if (*duration != -1) {
                            if (popup->duration != 0) {
                                popup->duration--;
                            } else {
                                switch (popup->messageIndex) {
                                    case BTL_MSG_2E:
                                    case BTL_MSG_30:
                                    case BTL_MSG_31:
                                    case BTL_MSG_32:
                                    case BTL_MSG_35:
                                    case BTL_MSG_37:
                                    case BTL_MSG_3B:
                                    case BTL_MSG_3C:
                                    case BTL_MSG_3F:
                                    case BTL_MSG_40:
                                    case BTL_MSG_41:
                                    case BTL_MSG_42:
                                        hud_element_free(D_8029F642);
                                        break;
                                    case BTL_MSG_2F:
                                    case BTL_MSG_33:
                                    case BTL_MSG_38:
                                    case BTL_MSG_39:
                                    case BTL_MSG_3A:
                                    case BTL_MSG_3D:
                                        hud_element_free(D_8029F642);
                                        hud_element_free(D_8029F644);
                                        break;
                                    case BTL_MSG_36:
                                    case BTL_MSG_3E:
                                        hud_element_free(D_8029F642);
                                        hud_element_free(D_8029F644);
                                        hud_element_free(D_8029F646);
                                        break;
                                    case BTL_MSG_34:
                                        hud_element_free(D_8029F642);
                                        hud_element_free(D_8029F644);
                                        hud_element_free(D_8029F646);
                                        hud_element_free(D_8029F648);
                                        break;
                                }
                                D_8029F64A = FALSE;
                                shouldDisposeWindow = TRUE;
                            }
                        }
                    }
                    break;
            }
            break;
        case BTL_MSG_43:
        case BTL_MSG_44:
        case BTL_MSG_45:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_48:
            switch (popup->unk_16) {
                default:
                    break;
                case 0:
                    popup->unk_16 = 1;
                    break;
                case 1:
                    popup->unk_16 = 2;
                    break;
                case 2:
                    if (battleStatus->currentButtonsPressed & (BUTTON_A | BUTTON_B)) {
                        popup->duration = 0;
                    }

                    if (popup->duration != 0) {
                        popup->duration--;
                    } else {
                        popup->unk_16 = 3;
                    }
                    break;
                case 3:
                    popup->unk_16 = 4;
                    break;
                case 4:
                    shouldDisposeWindow = TRUE;
                    break;
            }
            break;
        case BTL_MSG_49:
        case BTL_MSG_4A:
        case BTL_MSG_4B:
        case BTL_MSG_4C:
        case BTL_MSG_4D:
        case BTL_MSG_4E:
        case BTL_MSG_4F:
            switch (popup->unk_16) {
                case 0:
                    switch (popup->messageIndex) {
                        case BTL_MSG_49:
                            D_8029F642 = hud_element_create(&HES_Item_Hammer1);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_4A:
                            D_8029F642 = hud_element_create(&HES_Item_Hammer2);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_4B:
                            D_8029F642 = hud_element_create(&HES_Item_Hammer3);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_4C:
                            D_8029F642 = hud_element_create(&HES_Item_Boots1);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_4D:
                            D_8029F642 = hud_element_create(&HES_Item_Boots2);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_4E:
                            D_8029F642 = hud_element_create(&HES_Item_Boots3);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_4F:
                            D_8029F642 = hud_element_create(&HES_Item_Items);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                    }
                    popup->unk_16 = 1;
                    break;
                case 1:
                    if (popup->duration != 0) {
                        popup->duration--;
                        break;
                    }
                    shouldDisposeWindow = TRUE;
                    hud_element_free(D_8029F642);
                    break;
            }
            break;
    }
    if (shouldDisposeWindow) {
        set_window_update(WINDOW_ID_9, WINDOW_UPDATE_HIDE);
        bPopupMessage = NULL;
        free_popup(popup);
    }
}

void func_80250818(void* data, s32 x, s32 y) {
    PopupMessage* popup = data;
    s32 messageID;
    s32 msgLinesIdx;
    s32 opacity;

    x += 15;
    y += 6;

    switch (popup->messageIndex) {
        case BTL_MSG_00:
        case BTL_MSG_01:
        case BTL_MSG_02:
        case BTL_MSG_03:
        case BTL_MSG_08:
        case BTL_MSG_09:
        case BTL_MSG_0A:
        case BTL_MSG_0B:
        case BTL_MSG_0C:
        case BTL_MSG_0D:
        case BTL_MSG_0E:
        case BTL_MSG_0F:
        case BTL_MSG_10:
        case BTL_MSG_11:
        case BTL_MSG_12:
        case BTL_MSG_13:
        case BTL_MSG_14:
        case BTL_MSG_15:
        case BTL_MSG_16:
        case BTL_MSG_17:
        case BTL_MSG_18:
        case BTL_MSG_19:
        case BTL_MSG_1A:
        case BTL_MSG_1B:
        case BTL_MSG_1C:
        case BTL_MSG_23:
        case BTL_MSG_24:
        case BTL_MSG_25:
        case BTL_MSG_26:
        case BTL_MSG_27:
        case BTL_MSG_28:
        case BTL_MSG_29:
        case BTL_MSG_2A:
        case BTL_MSG_2B:
        case BTL_MSG_2C:
        case BTL_MSG_2D:
        case BTL_MSG_43:
        case BTL_MSG_44:
        case BTL_MSG_45:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_48:
        case BTL_MSG_50:
        case BTL_MSG_52:
        case BTL_MSG_53:
        case BTL_MSG_54:
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            draw_msg(messageID, x, y + D_802835D4[msgLinesIdx], 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_04:
        case BTL_MSG_05:
        case BTL_MSG_06:
        case BTL_MSG_07:
        case BTL_MSG_1D:
        case BTL_MSG_1E:
        case BTL_MSG_1F:
        case BTL_MSG_20:
        case BTL_MSG_21:
        case BTL_MSG_22:
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += D_802835D4[msgLinesIdx];
            set_message_value(D_8029F640, 0);
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_51:
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += D_802835D4[msgLinesIdx];
            set_message_msg(bActorMessages[D_8029F640], 0);
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_49:
        case BTL_MSG_4A:
        case BTL_MSG_4B:
        case BTL_MSG_4C:
        case BTL_MSG_4D:
        case BTL_MSG_4E:
        case BTL_MSG_4F:
            messageID = bMessages[popup->messageIndex];
            draw_msg(messageID, x + 0x1D, y + 6, 255, MSG_PAL_0F, 0);
            hud_element_set_render_pos(D_8029F642, x + 13, y + 14);
            hud_element_draw_clipped(D_8029F642);
            break;
        case BTL_MSG_2E:
        case BTL_MSG_2F:
        case BTL_MSG_30:
        case BTL_MSG_31:
        case BTL_MSG_32:
        case BTL_MSG_33:
        case BTL_MSG_34:
        case BTL_MSG_35:
        case BTL_MSG_36:
        case BTL_MSG_37:
        case BTL_MSG_38:
        case BTL_MSG_39:
        case BTL_MSG_3A:
        case BTL_MSG_3B:
        case BTL_MSG_3C:
        case BTL_MSG_3D:
        case BTL_MSG_3E:
        case BTL_MSG_3F:
        case BTL_MSG_40:
        case BTL_MSG_41:
        case BTL_MSG_42:
            opacity = 255;
            if (popup->unk_16 < 2) {
                opacity = 160;
            }
            if (popup->messageIndex == BTL_MSG_3B) {
                opacity = 255;
            }

            x -= 11;
            y -= 6;
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += D_802835D4[msgLinesIdx];
            draw_msg(messageID, x + 11, y + 6, opacity, MSG_PAL_0F, 0);

            switch (popup->messageIndex) {
                case BTL_MSG_2E:
                    hud_element_set_render_pos(D_8029F642, x + 65, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_2F:
                    hud_element_set_render_pos(D_8029F642, x + 55, y + 14);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 73, y + 31);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_30:
                    hud_element_set_render_pos(D_8029F642, x + 64, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_31:
                    hud_element_set_render_pos(D_8029F642, x + 67, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_32:
                    hud_element_set_render_pos(D_8029F642, x + 56, y + 14);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_33:
                    hud_element_set_render_pos(D_8029F642, x + 65, y + 13);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 146, y + 32);
                    hud_element_set_scale(D_8029F644, 0.8f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    func_80144218(D_8029F644);
                    break;
                case BTL_MSG_36:
                    hud_element_set_render_pos(D_8029F642, x + 86, y + 13);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 64, y + 13);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);

                    hud_element_set_render_pos(D_8029F646, x + 108, y + 13);
                    hud_element_set_scale(D_8029F646, 0.5f);
                    hud_element_set_alpha(D_8029F646, opacity);
                    hud_element_draw_clipped(D_8029F646);
                    break;
                case BTL_MSG_38:
                    hud_element_set_render_pos(D_8029F642, x + 105, y + 13);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 65, y + 14);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_3A:
                    hud_element_set_render_pos(D_8029F642, x + 63, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 84, y + 14);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_3C:
                    hud_element_set_render_pos(D_8029F642, x + 124, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_3D:
                    hud_element_set_render_pos(D_8029F642, x + 56, y + 31);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 53, y + 14);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_3E:
                    hud_element_set_render_pos(D_8029F642, x + 107, y + 13);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 210, y + 15);
                    hud_element_set_scale(D_8029F644, 0.8f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    func_80144218(D_8029F644);

                    hud_element_set_render_pos(D_8029F646, x + 56, y + 15);
                    hud_element_set_scale(D_8029F646, 0.8f);
                    hud_element_set_alpha(D_8029F646, opacity);
                    func_80144218(D_8029F646);
                    break;
                case BTL_MSG_40:
                case BTL_MSG_41:
                    hud_element_set_render_pos(D_8029F642, x + 64, y + 13);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
            }
            break;
    }
}

void btl_show_message_popup(void* data) {
    PopupMessage* popup = data;
    s32 numLines;
    s32 posX;
    s32 posY = 80;
    s32 width;
    s32 msgWidth;
    s32 height;

    switch (popup->messageIndex) {
        case BTL_MSG_00:
        case BTL_MSG_01:
        case BTL_MSG_02:
        case BTL_MSG_03:
        case BTL_MSG_08:
        case BTL_MSG_09:
        case BTL_MSG_0A:
        case BTL_MSG_0B:
        case BTL_MSG_0C:
        case BTL_MSG_0D:
        case BTL_MSG_0E:
        case BTL_MSG_0F:
        case BTL_MSG_10:
        case BTL_MSG_11:
        case BTL_MSG_12:
        case BTL_MSG_13:
        case BTL_MSG_14:
        case BTL_MSG_15:
        case BTL_MSG_16:
        case BTL_MSG_17:
        case BTL_MSG_18:
        case BTL_MSG_19:
        case BTL_MSG_1A:
        case BTL_MSG_1B:
        case BTL_MSG_1C:
        case BTL_MSG_23:
        case BTL_MSG_24:
        case BTL_MSG_25:
        case BTL_MSG_26:
        case BTL_MSG_27:
        case BTL_MSG_28:
        case BTL_MSG_29:
        case BTL_MSG_2A:
        case BTL_MSG_2B:
        case BTL_MSG_2C:
        case BTL_MSG_2D:
        case BTL_MSG_43:
        case BTL_MSG_44:
        case BTL_MSG_45:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_48:
        case BTL_MSG_50:
        case BTL_MSG_52:
        case BTL_MSG_53:
        case BTL_MSG_54:
            if (popup->unk_17) {
                s32 messageID;

                popup->unk_17 = FALSE;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 30;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(WINDOW_ID_9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_49:
        case BTL_MSG_4A:
        case BTL_MSG_4B:
        case BTL_MSG_4C:
        case BTL_MSG_4D:
        case BTL_MSG_4E:
        case BTL_MSG_4F:
            if (popup->unk_17) {
                popup->unk_17 = FALSE;
                msgWidth = get_msg_width(bMessages[popup->messageIndex], 0) + 55;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                height = 40;
                set_window_properties(WINDOW_ID_9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_04:
        case BTL_MSG_05:
        case BTL_MSG_06:
        case BTL_MSG_07:
        case BTL_MSG_1D:
        case BTL_MSG_1E:
        case BTL_MSG_1F:
        case BTL_MSG_20:
        case BTL_MSG_21:
        case BTL_MSG_22:
            if (popup->unk_17) {
                s32 messageID;

                popup->unk_17 = FALSE;
                messageID = bMessages[popup->messageIndex];
                set_message_value(D_8029F640, 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(WINDOW_ID_9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_51:
            if (popup->unk_17) {
                s32 messageID;

                popup->unk_17 = FALSE;
                messageID = bMessages[popup->messageIndex];
                set_message_msg(bActorMessages[D_8029F640], 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(WINDOW_ID_9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_2E:
        case BTL_MSG_2F:
        case BTL_MSG_30:
        case BTL_MSG_31:
        case BTL_MSG_32:
        case BTL_MSG_33:
        case BTL_MSG_34:
        case BTL_MSG_35:
        case BTL_MSG_36:
        case BTL_MSG_37:
        case BTL_MSG_38:
        case BTL_MSG_39:
        case BTL_MSG_3A:
        case BTL_MSG_3B:
        case BTL_MSG_3C:
        case BTL_MSG_3D:
        case BTL_MSG_3E:
        case BTL_MSG_3F:
        case BTL_MSG_40:
        case BTL_MSG_41:
        case BTL_MSG_42:
            if (popup->unk_17) {
                s32 messageID;

                popup->unk_17 = FALSE;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                posY = 192;
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                if (popup->messageIndex == BTL_MSG_3B) {
                    posY = 120;
                    D_8029F64C = 1;
                }
                D_8029F64E = posY;
                D_8029F650 = D_802835D8[numLines];

                posY = D_8029F64E + D_8029F650;
                set_window_properties(WINDOW_ID_9, posX, posY, width, height, 0, func_80250818, popup, -1);
                if (popup->messageIndex == BTL_MSG_3B) {
                    set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
                } else {
                    set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW_DARKENED);
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
    if (bPopupMessage != NULL) {
        bPopupMessage->duration = 0;
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

            if (actor->flags & ACTOR_FLAG_8000) {
                y -= actor->size.y / 2;
            }

            fx_flashing_box_shockwave(0, x, y, z, f1, f2);
        }
        part = part->nextPart;
    }
}
