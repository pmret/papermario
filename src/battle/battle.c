#include "common.h"
#include "ld_addrs.h"
#include "battle.h"
#include "battle_tables.h"
#include "hud_element.h"
#include "sprite.h"

extern s32 D_800DC060;
extern Stage* D_800DC064;

BattleArea gBattleAreas[0x30] = {
    {
        AREA(area_kmr_part_1),
        .name = "エリア ＫＭＲ その１",
        .battles = &b_area_kmr_part_1_formationTable,
        .stages = &b_area_kmr_part_1_stageTable,
    },
    {
        AREA(area_kmr_part_2),
        .name = "エリア ＫＭＲ その２",
        .battles = &b_area_kmr_part_2_formationTable,
        .stages = &b_area_kmr_part_2_stageTable,
    },
    {
        AREA(area_kmr_part_3),
        .name = "エリア ＫＭＲ その３",
        .battles = &b_area_kmr_part_3_formationTable,
        .stages = &b_area_kmr_part_3_stageTable,
    },
    {
        AREA(area_mac),
        .name = "エリア ＭＡＣ",
        .battles = &b_area_mac_formationTable,
        .stages = &b_area_mac_stageTable,
    },
    {
        AREA(area_hos),
        .name = "エリア ＨＯＳ",
        .battles = &b_area_hos_formationTable,
        .stages = &b_area_hos_stageTable,
    },
    {
        AREA(area_nok),
        .name = "エリア ＮＯＫ",
        .battles = &b_area_nok_formationTable,
        .stages = &b_area_nok_stageTable,
    },
    {
        AREA(area_trd_part_1),
        .name = "エリア ＴＲＤ その１",
        .battles = &b_area_trd_part_1_formationTable,
        .stages = &b_area_trd_part_1_stageTable,
    },
    {
        AREA(area_trd_part_2),
        .name = "エリア ＴＲＤ その２",
        .battles = &b_area_trd_part_2_formationTable,
        .stages = &b_area_trd_part_2_stageTable,
    },
    {
        AREA(area_trd_part_3),
        .name = "エリア ＴＲＤ その３",
        .battles = &b_area_trd_part_3_formationTable,
        .stages = &b_area_trd_part_3_stageTable,
    },
    {
        AREA(area_iwa),
        .name = "エリア ＩＷＡ",
        .battles = &b_area_iwa_formationTable,
        .stages = &b_area_iwa_stageTable,
    },
    {
        AREA(area_sbk),
        .name = "エリア ＳＢＫ",
        .battles = &b_area_sbk_formationTable,
        .stages = &b_area_sbk_stageTable,
    },
    {
        AREA(area_isk_part_1),
        .name = "エリア ＩＳＫ その１",
        .battles = &b_area_isk_part_1_formationTable,
        .stages = &b_area_isk_part_1_stageTable,
    },
    {
        AREA(area_isk_part_2),
        .name = "エリア ＩＳＫ その２",
        .battles = &b_area_isk_part_2_formationTable,
        .stages = &b_area_isk_part_2_stageTable,
    },
    {
        AREA(area_mim),
        .name = "エリア ＭＩＭ",
        .battles = &b_area_mim_formationTable,
        .stages = &b_area_mim_stageTable,
    },
    {
        AREA(area_arn),
        .name = "エリア ＡＲＮ",
        .battles = &b_area_arn_formationTable,
        .stages = &b_area_arn_stageTable,
    },
    {
        AREA(area_dgb),
        .name = "エリア ＤＧＢ",
        .battles = &b_area_dgb_formationTable,
        .stages = &b_area_dgb_stageTable,
    },
    {
        AREA(area_omo),
        .name = "エリア ＯＭＯ",
        .battles = &b_area_omo_formationTable,
        .stages = &b_area_omo_stageTable,
    },
    {
        AREA(area_omo2),
        .name = "エリア ＯＭＯ２",
        .battles = &b_area_omo2_formationTable,
        .stages = &b_area_omo2_stageTable,
    },
    {
        AREA(area_omo3),
        .name = "エリア ＯＭＯ３",
        .battles = 0x8022EA2C,
        .stages = 0x8022EB1C,
    },
    {
        AREA(area_kgr),
        .name = "エリア ＫＧＲ",
        .battles = &b_area_kgr_formationTable,
        .stages = &b_area_kgr_stageTable,
    },
    {
        AREA(area_jan),
        .name = "エリア ＪＡＮ",
        .battles = &b_area_jan_formationTable,
        .stages = &b_area_jan_stageTable,
    },
    {
        AREA(area_jan2),
        .name = "エリア ＪＡＮ２",
        .battles = &b_area_jan2_formationTable,
        .stages = &b_area_jan2_stageTable,
    },
    {
        AREA(area_kzn),
        .name = "エリア ＫＺＮ",
        .battles = &b_area_kzn_formationTable,
        .stages = &b_area_kzn_stageTable,
    },
    {
        AREA(area_kzn2),
        .name = "エリア ＫＺＮ２",
        .battles = 0x8022AA08,
        .stages = 0x8022AA44,
        .dmaTable = 0x8022AA84,
    },
    {
        AREA(area_flo),
        .name = "エリア ＦＬＯ",
        .battles = 0x80234574,
        .stages = 0x8023486C,
    },
    {
        AREA(area_flo2),
        .name = "エリア ＦＬＯ２",
        .battles = 0x802356FC,
        .stages = 0x80235788,
    },
    {
        AREA(area_tik),
        .name = "エリア ＴＩＫ",
        .battles = 0x802340B4,
        .stages = 0x802342BC,
    },
    {
        AREA(area_tik2),
        .name = "エリア ＴＩＫ２",
        .battles = 0x80227A90,
        .stages = 0x80227AE0,
    },
    {
        AREA(area_tik3),
        .name = "エリア ＴＩＫ３",
        .battles = 0x802232E8,
        .stages = 0x8022334C,
    },
    {
        AREA(area_sam),
        .name = "エリア ＳＡＭ",
        .battles = &b_area_sam_formationTable,
        .stages = &b_area_sam_stageTable,
    },
    {
        AREA(area_sam2),
        .name = "エリア ＳＡＭ２",
        .battles = 0x802234F0,
        .stages = 0x8022352C,
    },
    {
        AREA(area_pra),
        .name = "エリア ＰＲＡ",
        .battles = 0x8022F4D4,
        .stages = 0x8022F614,
    },
    {
        AREA(area_pra2),
        .name = "エリア ＰＲＡ２",
        .battles = &b_area_pra2_formationTable,
        .stages = &b_area_pra2_stageTable,
    },
    {
        AREA(area_pra3),
        .name = "エリア ＰＲＡ３",
        .battles = &b_area_pra3_formationTable,
        .stages = &b_area_pra3_stageTable,
    },
    {
        AREA(area_kpa),
        .name = "エリア ＫＰＡ",
        .battles = 0x80231A64,
        .stages = 0x80231ED8,
    },
    {
        AREA(area_kpa2),
        .name = "エリア ＫＰＡ２",
        .battles = 0x802346A8,
        .stages = 0x80234720,
    },
    {
        AREA(area_kpa3),
        .name = "エリア ＫＰＡ３",
        .battles = 0x8022839C,
        .stages = 0x802283EC,
    },
    {
        AREA(area_kpa4),
        .name = "エリア ＫＰＡ４",
        .battles = 0x80227910,
        .stages = 0x80227988,
    },
    {
        AREA(area_kkj),
        .name = "エリア ＫＫＪ",
        .battles = 0x802185BC,
        .stages = 0x802185E4,
    },
    {
        AREA(area_dig),
        .name = "エリア ＤＩＧ",
        .battles = 0x8022A7C4,
        .stages = 0x8022A83C,
    },
    {},
    {
        AREA(area_omo2_1),
        .name = "エリア ＯＭＯ２＿１",
    },
    {
        AREA(area_omo2_2),
        .name = "エリア ＯＭＯ２＿２",
    },
    {
        AREA(area_omo2_3),
        .name = "エリア ＯＭＯ２＿３",
    },
    {
        AREA(area_omo2_4),
        .name = "エリア ＯＭＯ２＿４",
    },
    {
        AREA(area_omo2_5),
        .name = "エリア ＯＭＯ２＿５",
    },
    {
        AREA(area_omo2_6),
        .name = "エリア ＯＭＯ２＿６",
    },
    {},
};

void reset_battle_status(void) {
    gGameStatusPtr->demoFlags = 0;
    gBattleState = BATTLE_STATE_0;
    D_800DC4E0 = 1;
    gBattleState2 = BATTLE_STATE2_UNK_0;
    D_800DC4D0 = 0;
    D_800DC4F0 = 0;
    D_800DC4D4 = 0;
    D_800DC4FC = NULL;
    D_800DC4F8 = 0;
    D_800DC4E8 = 0;
    D_800DC064 = NULL;
    D_800DC060 = 0;
    D_800DC4EC = 0;
    D_800DC4F4 = 0;
}

void ALT_reset_battle_status(void) {
    reset_battle_status();
}

void func_80072BCC(s32 arg0) {
    D_800DC4F8 = arg0;
}

void load_battle_section(void) {
    BattleArea* battleArea = &gBattleAreas[gCurrentBattleSection];
    s32 battleIdx = D_800DC4EB;

    dma_copy(battleArea->dmaStart, battleArea->dmaEnd, battleArea->dmaDest);

    D_800DC4FC = &(*battleArea->battles)[battleIdx];

    if (D_800DC4EC < 0) {
        D_800DC064 = NULL;
    } else {
        D_800DC064 = &(*battleArea->stages)[D_800DC4EC];
    }

    btl_set_state(1);
    D_800DC4D0 = 0;
}

void load_battle(s32 arg0) {
    D_800DC4E8 = arg0;
    set_game_mode(GAME_MODE_BATTLE);
    gBattleState = 0;
    D_800DC4D0 = 0;
    gBattleState2 = 0;
}

void set_battle_stage(s32 arg0) {
    D_800DC4EC = arg0;
}

void set_battle_formation(s32 arg0) {
    D_800DC4F4 = arg0;
}

void func_80072CEC(f32 arg0, f32 arg1, f32 arg2) {
}

void func_80072CF4(void) {
    func_80072CEC(1.0f, 1.1f, 1.2f);
}

void setup_demo_player(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    playerData->curHP = 15;
    playerData->curMaxHP = 15;
    playerData->hardMaxHP = 15;
    playerData->curFP = 10;
    playerData->curMaxFP = 10;
    playerData->hardMaxFP = 10;
    playerData->level = 3;
    playerData->hasActionCommands = 1;
    playerData->starPoints = 55;
    playerData->bootsLevel = 0;
    playerData->hammerLevel = 0;
    playerData->coins = 34;

    for (i = 1; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = TRUE;
        playerData->partners[i].level = 2;
    }

    playerData->currentPartner = PARTNER_GOOMBARIO;

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        playerData->badges[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        playerData->equippedBadges[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        playerData->invItems[i] = 0;
    }

    playerData->unk_288 = 0;
    playerData->merleeSpellType = 0;
    playerData->merleeCastsLeft = 0;
    playerData->merleeTurnCount = 0;
    playerData->maxStarPower = 0;
    playerData->specialBarsFilled = 0;
    playerData->starBeamLevel = 0;
}

void load_demo_battle(u32 index) {
    PlayerData* playerData = &gPlayerData;
    u32 mode;
    s32 battleID;

    gGameStatusPtr->demoFlags = 0;
    gGameStatusPtr->areaID = 0;
    gGameStatusPtr->mapID = 0;
    gGameStatusPtr->isBattle = FALSE;

    general_heap_create();
    clear_generic_entity_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(0);
    clear_animator_list();
    clear_entity_models();
    clear_npcs();
    hud_element_clear_cache();
    clear_trigger_data();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    func_80138188();
    reset_battle_status();
    clear_encounter_status();
    clear_entity_data(1);
    clear_effect_data();
    clear_player_status();
    clear_printers();
    clear_item_entity_data();
    clear_player_data();
    initialize_status_menu();
    clear_item_entity_data();
    set_screen_overlay_params_front(9, 255.0f);

    switch (index) {
        case 0:
            setup_demo_player();
            mode = 0;
            playerData->hasActionCommands = FALSE;
            battleID = 0x2700;
            break;
        case 1:
            setup_demo_player();
            mode = 0;
            playerData->currentPartner = PARTNER_BOW;
            battleID = 0x2701;
            break;
        case 2:
            setup_demo_player();
            mode = 0;
            playerData->currentPartner = PARTNER_PARAKARRY;
            gGameStatusPtr->demoFlags |= 2;
            battleID = 0x2702;
            break;
        case 3:
            setup_demo_player();
            mode = 0;
            playerData->currentPartner = PARTNER_WATT;
            battleID = 0x2703;
            break;
        case 4:
            setup_demo_player();
            playerData->currentPartner = PARTNER_KOOPER;
            gGameStatusPtr->demoFlags |= 4;
            mode = 0;
            battleID = 0x2704;
            break;
        default:
            setup_demo_player();
            mode = 2;
            battleID = 0x2700;
    }

    gGameStatusPtr->debugEnemyContact = 0;
    gGameStatusPtr->unk_7C = 1;

    switch (mode) {
        case 0:
            gCurrentEncounter.eFirstStrike = FIRST_STRIKE_NONE;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_NONE;
            gCurrentEncounter.hitTier = 0;
            gGameStatusPtr->demoFlags |= 0x10;
            gGameStatusPtr->demoFlags |= 0x20;
            gGameStatusPtr->demoFlags |= 0x40;
            break;
        case 1:
            gCurrentEncounter.eFirstStrike = FIRST_STRIKE_PLAYER;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_HAMMER;
            gCurrentEncounter.hitTier = playerData->hammerLevel;
            gGameStatusPtr->demoFlags |= 0x10;
            break;
        case 2:
            gCurrentEncounter.eFirstStrike = FIRST_STRIKE_PLAYER;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_JUMP;
            gCurrentEncounter.hitTier = playerData->bootsLevel;
            gGameStatusPtr->demoFlags |= 0x10;
            break;
        case 3:
            gCurrentEncounter.eFirstStrike = FIRST_STRIKE_PLAYER;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_PARTNER;
            gGameStatusPtr->demoFlags |= 0x20;
            break;
        case 4:
            gCurrentEncounter.eFirstStrike = FIRST_STRIKE_ENEMY;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_NONE;
            gCurrentEncounter.hitTier = 0;
            gGameStatusPtr->demoFlags |= 0x40;
            break;
    }

    evt_set_variable(NULL, EVT_SAVE_FLAG(1817), 1);
    gCurrentEncounter.unk_07 = 0;
    gCurrentEncounter.unk_10 = 0;
    set_battle_stage(-1);
    gGameStatusPtr->demoFlags |= 1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
    load_battle(battleID);
}

static const f32 padding[] = { 0.0f, 0.0f };
