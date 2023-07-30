#include "common.h"
#include "ld_addrs.h"
#include "battle.h"
#include "battle_tables.h"
#include "hud_element.h"
#include "sprite.h"

SHIFT_BSS s32 D_800DC060;
SHIFT_BSS StageListRow* gCurrentStagePtr;
SHIFT_BSS s32 gBattleState;
SHIFT_BSS BattleStatus gBattleStatus;
SHIFT_BSS s32 gLastDrawBattleState;
SHIFT_BSS s32 D_800DC4D4;
SHIFT_BSS s32 gDefeatedBattleSubstate;
SHIFT_BSS s32 gBattleSubState;
SHIFT_BSS s32 D_800DC4E0;
SHIFT_BSS s32 gDefeatedBattleState;
SHIFT_BSS s32 gCurrentBattleID;
SHIFT_BSS s32 gCurrentStageID;
SHIFT_BSS s32 D_800DC4F0;
SHIFT_BSS Battle* gOverrideBattlePtr;
SHIFT_BSS s32 D_800DC4F8;
SHIFT_BSS Battle* gCurrentBattlePtr;

// standard battle area table entry
#define BTL_AREA(id, jpName) { \
    .dmaStart = battle_area_##id##_ROM_START, \
    .dmaEnd = battle_area_##id##_ROM_END, \
    .dmaDest = battle_area_##id##_VRAM, \
    .battles = &b_area_##id##_Formations, \
    .stages = &b_area_##id##_Stages, \
    .name = jpName, \
} \

// extended battle area with a dmaTable, used by kzn2 for lava piranha animations
#define BTL_AREA_DMA(id, jpName) { \
    .dmaStart = battle_area_##id##_ROM_START, \
    .dmaEnd = battle_area_##id##_ROM_END, \
    .dmaDest = battle_area_##id##_VRAM, \
    .battles = &b_area_##id##_Formations, \
    .stages = &b_area_##id##_Stages, \
    .dmaTable = b_area_##id##_dmaTable, \
    .name = jpName, \
} \

// auxiliary battle area for omo which contains only additional enemy data
#define BTL_AREA_AUX(id, jpName) { \
    .dmaStart = battle_area_##id##_ROM_START, \
    .dmaEnd = battle_area_##id##_ROM_END, \
    .dmaDest = battle_area_##id##_VRAM, \
    .name = jpName, \
} \

BattleArea gBattleAreas[] = {
    [BTL_AREA_KMR_1]    BTL_AREA(kmr_part_1, "エリア ＫＭＲ その１"),
    [BTL_AREA_KMR_2]    BTL_AREA(kmr_part_2, "エリア ＫＭＲ その２"),
    [BTL_AREA_KMR_3]    BTL_AREA(kmr_part_3, "エリア ＫＭＲ その３"),
    [BTL_AREA_MAC]      BTL_AREA(mac, "エリア ＭＡＣ"),
    [BTL_AREA_HOS]      BTL_AREA(hos, "エリア ＨＯＳ"),
    [BTL_AREA_NOK]      BTL_AREA(nok, "エリア ＮＯＫ"),
    [BTL_AREA_TRD_1]    BTL_AREA(trd_part_1, "エリア ＴＲＤ その１"),
    [BTL_AREA_TRD_2]    BTL_AREA(trd_part_2, "エリア ＴＲＤ その２"),
    [BTL_AREA_TRD_3]    BTL_AREA(trd_part_3, "エリア ＴＲＤ その３"),
    [BTL_AREA_IWA]      BTL_AREA(iwa, "エリア ＩＷＡ"),
    [BTL_AREA_SBK]      BTL_AREA(sbk, "エリア ＳＢＫ"),
    [BTL_AREA_ISK_1]    BTL_AREA(isk_part_1, "エリア ＩＳＫ その１"),
    [BTL_AREA_ISK_2]    BTL_AREA(isk_part_2, "エリア ＩＳＫ その２"),
    [BTL_AREA_MIM]      BTL_AREA(mim, "エリア ＭＩＭ"),
    [BTL_AREA_ARN]      BTL_AREA(arn, "エリア ＡＲＮ"),
    [BTL_AREA_DGB]      BTL_AREA(dgb, "エリア ＤＧＢ"),
    [BTL_AREA_OMO]      BTL_AREA(omo, "エリア ＯＭＯ"),
    [BTL_AREA_OMO2]     BTL_AREA(omo2, "エリア ＯＭＯ２"),
    [BTL_AREA_OMO3]     BTL_AREA(omo3, "エリア ＯＭＯ３"),
    [BTL_AREA_KGR]      BTL_AREA(kgr, "エリア ＫＧＲ"),
    [BTL_AREA_JAN]      BTL_AREA(jan, "エリア ＪＡＮ"),
    [BTL_AREA_JAN2]     BTL_AREA(jan2, "エリア ＪＡＮ２"),
    [BTL_AREA_KZN]      BTL_AREA(kzn, "エリア ＫＺＮ"),
    [BTL_AREA_KZN2]     BTL_AREA_DMA(kzn2, "エリア ＫＺＮ２"),
    [BTL_AREA_FLO]      BTL_AREA(flo, "エリア ＦＬＯ"),
    [BTL_AREA_FLO2]     BTL_AREA(flo2, "エリア ＦＬＯ２"),
    [BTL_AREA_TIK]      BTL_AREA(tik, "エリア ＴＩＫ"),
    [BTL_AREA_TIK2]     BTL_AREA(tik2, "エリア ＴＩＫ２"),
    [BTL_AREA_TIK3]     BTL_AREA(tik3, "エリア ＴＩＫ３"),
    [BTL_AREA_SAM]      BTL_AREA(sam, "エリア ＳＡＭ"),
    [BTL_AREA_SAM2]     BTL_AREA(sam2, "エリア ＳＡＭ２"),
    [BTL_AREA_PRA]      BTL_AREA(pra, "エリア ＰＲＡ"),
    [BTL_AREA_PRA2]     BTL_AREA(pra2, "エリア ＰＲＡ２"),
    [BTL_AREA_PRA3]     BTL_AREA(pra3, "エリア ＰＲＡ３"),
    [BTL_AREA_KPA]      BTL_AREA(kpa, "エリア ＫＰＡ"),
    [BTL_AREA_KPA2]     BTL_AREA(kpa2, "エリア ＫＰＡ２"),
    [BTL_AREA_KPA3]     BTL_AREA(kpa3, "エリア ＫＰＡ３"),
    [BTL_AREA_KPA4]     BTL_AREA(kpa4, "エリア ＫＰＡ４"),
    [BTL_AREA_KKJ]      BTL_AREA(kkj, "エリア ＫＫＪ"),
    [BTL_AREA_DIG]      BTL_AREA(dig, "エリア ＤＩＧ"),
    [BTL_AREA_OMO2_1]   BTL_AREA_AUX(omo2_1, "エリア ＯＭＯ２＿１"),
    [BTL_AREA_OMO2_2]   BTL_AREA_AUX(omo2_2, "エリア ＯＭＯ２＿２"),
    [BTL_AREA_OMO2_3]   BTL_AREA_AUX(omo2_3, "エリア ＯＭＯ２＿３"),
    [BTL_AREA_OMO2_4]   BTL_AREA_AUX(omo2_4, "エリア ＯＭＯ２＿４"),
    [BTL_AREA_OMO2_5]   BTL_AREA_AUX(omo2_5, "エリア ＯＭＯ２＿５"),
    [BTL_AREA_OMO2_6]   BTL_AREA_AUX(omo2_6, "エリア ＯＭＯ２＿６"),
};

void reset_battle_status(void) {
    gGameStatusPtr->demoFlags = 0;
    gBattleState = BATTLE_STATE_0;
    D_800DC4E0 = 1;
    gBattleSubState = BTL_SUBSTATE_INIT;
    gLastDrawBattleState = BATTLE_STATE_0;
    D_800DC4F0 = 0;
    D_800DC4D4 = 0;
    gCurrentBattlePtr = NULL;
    D_800DC4F8 = 0;
    gCurrentBattleID = 0;
    gCurrentStagePtr = NULL;
    D_800DC060 = 0;
    gCurrentStageID = 0;
    gOverrideBattlePtr = NULL;
}

void ALT_reset_battle_status(void) {
    reset_battle_status();
}

void func_80072BCC(s32 arg0) {
    D_800DC4F8 = arg0;
}

void load_battle_section(void) {
    BattleArea* battleArea = &gBattleAreas[UNPACK_BTL_AREA(gCurrentBattleID)];
    s32 battleIdx = UNPACK_BTL_INDEX(gCurrentBattleID);

    dma_copy(battleArea->dmaStart, battleArea->dmaEnd, battleArea->dmaDest);

    gCurrentBattlePtr = &(*battleArea->battles)[battleIdx];

    if (gCurrentStageID < 0) {
        gCurrentStagePtr = NULL;
    } else {
        gCurrentStagePtr = &(*battleArea->stages)[gCurrentStageID];
    }

    btl_set_state(BATTLE_STATE_NORMAL_START);
    gLastDrawBattleState = BATTLE_STATE_0;
}

void load_battle(s32 battleID) {
    gCurrentBattleID = battleID;
    set_game_mode(GAME_MODE_BATTLE);
    gBattleState = BATTLE_STATE_0;
    gLastDrawBattleState = BATTLE_STATE_0;
    gBattleSubState = BTL_SUBSTATE_INIT;
}

void set_battle_stage(s32 stageID) {
    gCurrentStageID = stageID;
}

void set_battle_formation(Battle* battle) {
    gOverrideBattlePtr = battle;
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
    playerData->hasActionCommands = TRUE;
    playerData->starPoints = 55;
    playerData->bootsLevel = 0;
    playerData->hammerLevel = 0;
    playerData->coins = 34;

    for (i = 1; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = TRUE;
        playerData->partners[i].level = 2;
    }

    playerData->curPartner = PARTNER_GOOMBARIO;

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
    playerData->merleeSpellType = MERLEE_SPELL_0;
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
    clear_worker_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
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
    initialize_status_bar();
    clear_item_entity_data();
    set_screen_overlay_params_front(OVERLAY_TYPE_9, 255.0f);

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
            playerData->curPartner = PARTNER_BOW;
            battleID = BTL_DIG_FORMATION_01;
            break;
        case 2:
            setup_demo_player();
            mode = 0;
            playerData->curPartner = PARTNER_PARAKARRY;
            gGameStatusPtr->demoFlags |= 2;
            battleID = BTL_DIG_FORMATION_02;
            break;
        case 3:
            setup_demo_player();
            mode = 0;
            playerData->curPartner = PARTNER_WATT;
            battleID = BTL_DIG_FORMATION_03;
            break;
        case 4:
            setup_demo_player();
            playerData->curPartner = PARTNER_KOOPER;
            gGameStatusPtr->demoFlags |= 4;
            mode = 0;
            battleID = BTL_DIG_FORMATION_04;
            break;
        default:
            setup_demo_player();
            mode = 2;
            battleID = BTL_DIG_FORMATION_00;
    }

    gGameStatusPtr->debugEnemyContact = DEBUG_CONTACT_NONE;
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
    gCurrentEncounter.instigatorValue = 0;
    set_battle_stage(BTL_STAGE_DEFAULT);
    gGameStatusPtr->demoFlags |= 1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
    load_battle(battleID);
}

static const f32 padding[] = { 0.0f, 0.0f };
