#include "common.h"
#include "ld_addrs.h"
#include "battle.h"
#include "battle_tables.h"
#include "hud_element.h"
#include "sprite.h"

extern s32 D_800DC060;
extern Stage* D_800DC064;

BattleArea gBattleAreas[] = {
    [BTL_AREA_KMR_PART_1] = {
        BTL_AREA(area_kmr_part_1),
        .name = "エリア ＫＭＲ その１",
        .battles = &b_area_kmr_part_1_formationTable,
        .stages = &b_area_kmr_part_1_stageTable,
    },
    [BTL_AREA_KMR_PART_2] = {
        BTL_AREA(area_kmr_part_2),
        .name = "エリア ＫＭＲ その２",
        .battles = &b_area_kmr_part_2_formationTable,
        .stages = &b_area_kmr_part_2_stageTable,
    },
    [BTL_AREA_KMR_PART_3] = {
        BTL_AREA(area_kmr_part_3),
        .name = "エリア ＫＭＲ その３",
        .battles = &b_area_kmr_part_3_formationTable,
        .stages = &b_area_kmr_part_3_stageTable,
    },
    [BTL_AREA_MAC] = {
        BTL_AREA(area_mac),
        .name = "エリア ＭＡＣ",
        .battles = &b_area_mac_formationTable,
        .stages = &b_area_mac_stageTable,
    },
    [BTL_AREA_HOS] = {
        BTL_AREA(area_hos),
        .name = "エリア ＨＯＳ",
        .battles = &b_area_hos_formationTable,
        .stages = &b_area_hos_stageTable,
    },
    [BTL_AREA_NOK] = {
        BTL_AREA(area_nok),
        .name = "エリア ＮＯＫ",
        .battles = &b_area_nok_formationTable,
        .stages = &b_area_nok_stageTable,
    },
    [BTL_AREA_TRD_PART_1] = {
        BTL_AREA(area_trd_part_1),
        .name = "エリア ＴＲＤ その１",
        .battles = &b_area_trd_part_1_formationTable,
        .stages = &b_area_trd_part_1_stageTable,
    },
    [BTL_AREA_TRD_PART_2] = {
        BTL_AREA(area_trd_part_2),
        .name = "エリア ＴＲＤ その２",
        .battles = &b_area_trd_part_2_formationTable,
        .stages = &b_area_trd_part_2_stageTable,
    },
    [BTL_AREA_TRD_PART_3] = {
        BTL_AREA(area_trd_part_3),
        .name = "エリア ＴＲＤ その３",
        .battles = &b_area_trd_part_3_formationTable,
        .stages = &b_area_trd_part_3_stageTable,
    },
    [BTL_AREA_IWA] = {
        BTL_AREA(area_iwa),
        .name = "エリア ＩＷＡ",
        .battles = &b_area_iwa_formationTable,
        .stages = &b_area_iwa_stageTable,
    },
    [BTL_AREA_SBK] = {
        BTL_AREA(area_sbk),
        .name = "エリア ＳＢＫ",
        .battles = &b_area_sbk_formationTable,
        .stages = &b_area_sbk_stageTable,
    },
    [BTL_AREA_ISK_PART_1] = {
        BTL_AREA(area_isk_part_1),
        .name = "エリア ＩＳＫ その１",
        .battles = &b_area_isk_part_1_formationTable,
        .stages = &b_area_isk_part_1_stageTable,
    },
    [BTL_AREA_ISK_PART_2] = {
        BTL_AREA(area_isk_part_2),
        .name = "エリア ＩＳＫ その２",
        .battles = &b_area_isk_part_2_formationTable,
        .stages = &b_area_isk_part_2_stageTable,
    },
    [BTL_AREA_MIM] = {
        BTL_AREA(area_mim),
        .name = "エリア ＭＩＭ",
        .battles = &b_area_mim_formationTable,
        .stages = &b_area_mim_stageTable,
    },
    [BTL_AREA_ARN] = {
        BTL_AREA(area_arn),
        .name = "エリア ＡＲＮ",
        .battles = &b_area_arn_formationTable,
        .stages = &b_area_arn_stageTable,
    },
    [BTL_AREA_DGB] = {
        BTL_AREA(area_dgb),
        .name = "エリア ＤＧＢ",
        .battles = &b_area_dgb_formationTable,
        .stages = &b_area_dgb_stageTable,
    },
    [BTL_AREA_OMO] = {
        BTL_AREA(area_omo),
        .name = "エリア ＯＭＯ",
        .battles = &b_area_omo_formationTable,
        .stages = &b_area_omo_stageTable,
    },
    [BTL_AREA_OMO2] = {
        BTL_AREA(area_omo2),
        .name = "エリア ＯＭＯ２",
        .battles = &b_area_omo2_formationTable,
        .stages = &b_area_omo2_stageTable,
    },
    [BTL_AREA_OMO3] = {
        BTL_AREA(area_omo3),
        .name = "エリア ＯＭＯ３",
        .battles = &b_area_omo3_formationTable,
        .stages = &b_area_omo3_stageTable,
    },
    [BTL_AREA_KGR] = {
        BTL_AREA(area_kgr),
        .name = "エリア ＫＧＲ",
        .battles = &b_area_kgr_formationTable,
        .stages = &b_area_kgr_stageTable,
    },
    [BTL_AREA_JAN] = {
        BTL_AREA(area_jan),
        .name = "エリア ＪＡＮ",
        .battles = &b_area_jan_formationTable,
        .stages = &b_area_jan_stageTable,
    },
    [BTL_AREA_JAN2] = {
        BTL_AREA(area_jan2),
        .name = "エリア ＪＡＮ２",
        .battles = &b_area_jan2_formationTable,
        .stages = &b_area_jan2_stageTable,
    },
    [BTL_AREA_KZN] = {
        BTL_AREA(area_kzn),
        .name = "エリア ＫＺＮ",
        .battles = &b_area_kzn_formationTable,
        .stages = &b_area_kzn_stageTable,
    },
    [BTL_AREA_KZN2] = {
        BTL_AREA(area_kzn2),
        .name = "エリア ＫＺＮ２",
        .battles = 0x8022AA08,
        .stages = 0x8022AA44,
        .dmaTable = 0x8022AA84,
    },
    [BTL_AREA_FLO] = {
        BTL_AREA(area_flo),
        .name = "エリア ＦＬＯ",
        .battles = 0x80234574,
        .stages = 0x8023486C,
    },
    [BTL_AREA_FLO2] = {
        BTL_AREA(area_flo2),
        .name = "エリア ＦＬＯ２",
        .battles = 0x802356FC,
        .stages = 0x80235788,
    },
    [BTL_AREA_TIK] = {
        BTL_AREA(area_tik),
        .name = "エリア ＴＩＫ",
        .battles = 0x802340B4,
        .stages = 0x802342BC,
    },
    [BTL_AREA_TIK2] = {
        BTL_AREA(area_tik2),
        .name = "エリア ＴＩＫ２",
        .battles = 0x80227A90,
        .stages = 0x80227AE0,
    },
    [BTL_AREA_TIK3] = {
        BTL_AREA(area_tik3),
        .name = "エリア ＴＩＫ３",
        .battles = 0x802232E8,
        .stages = 0x8022334C,
    },
    [BTL_AREA_SAM] = {
        BTL_AREA(area_sam),
        .name = "エリア ＳＡＭ",
        .battles = &b_area_sam_formationTable,
        .stages = &b_area_sam_stageTable,
    },
    [BTL_AREA_SAM2] = {
        BTL_AREA(area_sam2),
        .name = "エリア ＳＡＭ２",
        .battles = &b_area_sam2_formationTable,
        .stages = &b_area_sam2_stageTable,
    },
    [BTL_AREA_PRA] = {
        BTL_AREA(area_pra),
        .name = "エリア ＰＲＡ",
        .battles = &b_area_pra_formationTable,
        .stages = &b_area_pra_stageTable,
    },
    [BTL_AREA_PRA2] = {
        BTL_AREA(area_pra2),
        .name = "エリア ＰＲＡ２",
        .battles = &b_area_pra2_formationTable,
        .stages = &b_area_pra2_stageTable,
    },
    [BTL_AREA_PRA3] = {
        BTL_AREA(area_pra3),
        .name = "エリア ＰＲＡ３",
        .battles = &b_area_pra3_formationTable,
        .stages = &b_area_pra3_stageTable,
    },
    [BTL_AREA_KPA] = {
        BTL_AREA(area_kpa),
        .name = "エリア ＫＰＡ",
        .battles = 0x80231A64,
        .stages = 0x80231ED8,
    },
    [BTL_AREA_KPA2] = {
        BTL_AREA(area_kpa2),
        .name = "エリア ＫＰＡ２",
        .battles = 0x802346A8,
        .stages = 0x80234720,
    },
    [BTL_AREA_KPA3] = {
        BTL_AREA(area_kpa3),
        .name = "エリア ＫＰＡ３",
        .battles = 0x8022839C,
        .stages = 0x802283EC,
    },
    [BTL_AREA_KPA4] = {
        BTL_AREA(area_kpa4),
        .name = "エリア ＫＰＡ４",
        .battles = 0x80227910,
        .stages = 0x80227988,
    },
    [BTL_AREA_KKJ] = {
        BTL_AREA(area_kkj),
        .name = "エリア ＫＫＪ",
        .battles = 0x802185BC,
        .stages = 0x802185E4,
    },
    [BTL_AREA_DIG] = {
        BTL_AREA(area_dig),
        .name = "エリア ＤＩＧ",
        .battles = 0x8022A7C4,
        .stages = 0x8022A83C,
    },
    [BTL_AREA_OMO2_1] = {
        BTL_AREA(area_omo2_1),
        .name = "エリア ＯＭＯ２＿１",
    },
    [BTL_AREA_OMO2_2] = {
        BTL_AREA(area_omo2_2),
        .name = "エリア ＯＭＯ２＿２",
    },
    [BTL_AREA_OMO2_3] = {
        BTL_AREA(area_omo2_3),
        .name = "エリア ＯＭＯ２＿３",
    },
    [BTL_AREA_OMO2_4] = {
        BTL_AREA(area_omo2_4),
        .name = "エリア ＯＭＯ２＿４",
    },
    [BTL_AREA_OMO2_5] = {
        BTL_AREA(area_omo2_5),
        .name = "エリア ＯＭＯ２＿５",
    },
    [BTL_AREA_OMO2_6] = {
        BTL_AREA(area_omo2_6),
        .name = "エリア ＯＭＯ２＿６",
    },
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
    D_800DC4F4 = NULL;
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

    btl_set_state(BATTLE_STATE_NORMAL_START);
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

void set_battle_formation(Battle* battle) {
    D_800DC4F4 = battle;
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
            battleID = BTL_DIG_FORMATION_00;
            break;
        case 1:
            setup_demo_player();
            mode = 0;
            playerData->currentPartner = PARTNER_BOW;
            battleID = BTL_DIG_FORMATION_01;
            break;
        case 2:
            setup_demo_player();
            mode = 0;
            playerData->currentPartner = PARTNER_PARAKARRY;
            gGameStatusPtr->demoFlags |= 2;
            battleID = BTL_DIG_FORMATION_02;
            break;
        case 3:
            setup_demo_player();
            mode = 0;
            playerData->currentPartner = PARTNER_WATT;
            battleID = BTL_DIG_FORMATION_03;
            break;
        case 4:
            setup_demo_player();
            playerData->currentPartner = PARTNER_KOOPER;
            gGameStatusPtr->demoFlags |= 4;
            mode = 0;
            battleID = BTL_DIG_FORMATION_04;
            break;
        default:
            setup_demo_player();
            mode = 2;
            battleID = BTL_DIG_FORMATION_00;
    }

    gGameStatusPtr->debugEnemyContact = 0;
    gGameStatusPtr->unk_7C = 1;

    switch (mode) {
        case 0:
            gCurrentEncounter.firstStrikeType = FIRST_STRIKE_NONE;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_NONE;
            gCurrentEncounter.hitTier = 0;
            gGameStatusPtr->demoFlags |= 0x10;
            gGameStatusPtr->demoFlags |= 0x20;
            gGameStatusPtr->demoFlags |= 0x40;
            break;
        case 1:
            gCurrentEncounter.firstStrikeType = FIRST_STRIKE_PLAYER;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_HAMMER;
            gCurrentEncounter.hitTier = playerData->hammerLevel;
            gGameStatusPtr->demoFlags |= 0x10;
            break;
        case 2:
            gCurrentEncounter.firstStrikeType = FIRST_STRIKE_PLAYER;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_JUMP;
            gCurrentEncounter.hitTier = playerData->bootsLevel;
            gGameStatusPtr->demoFlags |= 0x10;
            break;
        case 3:
            gCurrentEncounter.firstStrikeType = FIRST_STRIKE_PLAYER;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_PARTNER;
            gGameStatusPtr->demoFlags |= 0x20;
            break;
        case 4:
            gCurrentEncounter.firstStrikeType = FIRST_STRIKE_ENEMY;
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_NONE;
            gCurrentEncounter.hitTier = 0;
            gGameStatusPtr->demoFlags |= 0x40;
            break;
    }

    evt_set_variable(NULL, GF_Tutorial_SwapTurnOrder, 1);
    gCurrentEncounter.unk_07 = 0;
    gCurrentEncounter.unk_10 = 0;
    set_battle_stage(-1);
    gGameStatusPtr->demoFlags |= 1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
    load_battle(battleID);
}

static const f32 padding[] = { 0.0f, 0.0f };
