#include "common.h"
#include "ld_addrs.h"

s32 D_80293B80[] = {
    -1,
    ITEM_MUSHROOM,
    ITEM_FIRE_FLOWER,
    ITEM_DUSTY_HAMMER,
    ITEM_POW_BLOCK,
    ITEM_PEBBLE,
    ITEM_VOLT_SHROOM,
    ITEM_THUNDER_RAGE,
    ITEM_SNOWMAN_DOLL,
    ITEM_DRIED_SHROOM,
    ITEM_SHOOTING_STAR,
    ITEM_SLEEPY_SHEEP,
    ITEM_STONE_CAP,
    ITEM_TASTY_TONIC,
    ITEM_THUNDER_BOLT,
    ITEM_SUPER_SHROOM,
    ITEM_ULTRA_SHROOM,
    ITEM_SUPER_SODA,
    ITEM_HUSTLE_DRINK,
    ITEM_STOP_WATCH,
    ITEM_DIZZY_DIAL,
    ITEM_PLEASE_COME_BACK,
    ITEM_EGG_MISSILE,
    ITEM_INSECTICIDE_HERB,
    ITEM_FRIGHT_JAR,
    ITEM_MYSTERY,
    ITEM_REPEL_GEL,
    ITEM_LIFE_SHROOM,
    ITEM_COCONUT,
    ITEM_ELECTRO_POP,
    ITEM_STRANGE_CAKE,
    ITEM_KOOKY_COOKIE,
    ITEM_NONE
};

extern EvtScript battle_item_food_main;
extern EvtScript battle_item_mushroom_main;
extern EvtScript battle_item_fire_flower_main;
extern EvtScript battle_item_dusty_hammer_main;
extern EvtScript battle_item_pow_block_main;
extern EvtScript battle_item_pebble_main;
extern EvtScript battle_item_volt_shroom_main;
extern EvtScript battle_item_thunder_rage_main;
extern EvtScript battle_item_snowman_doll_main;
extern EvtScript battle_item_shooting_star_main;
extern EvtScript battle_item_sleepy_sheep_main;
extern EvtScript battle_item_stone_cap_main;
extern EvtScript battle_item_tasty_tonic_main;
extern EvtScript battle_item_thunder_bolt_main;
extern EvtScript battle_item_super_soda_main;
extern EvtScript battle_item_hustle_drink_main;
extern EvtScript battle_item_stop_watch_main;
extern EvtScript battle_item_dizzy_dial_main;
extern EvtScript battle_item_please_come_back_main;
extern EvtScript battle_item_egg_missile_main;
extern EvtScript battle_item_insecticide_herb_main;
extern EvtScript battle_item_fright_jar_main;
extern EvtScript battle_item_mystery_main;
extern EvtScript battle_item_repel_gel_main;
extern EvtScript battle_item_life_shroom_main;
extern EvtScript battle_item_coconut_main;
extern EvtScript battle_item_electro_pop_main;
extern EvtScript battle_item_strange_cake_main;

#define BTL_ITEM_TABLE_ENTRY(name) { name##_ROM_START, name##_ROM_END, name##_VRAM, &battle_item_##name##_main }

typedef struct BattleTableEntry {
    /* 0x00 */ u8* romStart;
    /* 0x04 */ u8* romEnd;
    /* 0x08 */ u8* vramStart;
    /* 0x0C */ EvtScript* mainScript;
} BattleTableEntry; // size = 0x10

BattleTableEntry gBattleItemTable[] = {
    BTL_ITEM_TABLE_ENTRY(food),
    BTL_ITEM_TABLE_ENTRY(mushroom),
    BTL_ITEM_TABLE_ENTRY(fire_flower),
    BTL_ITEM_TABLE_ENTRY(dusty_hammer),
    BTL_ITEM_TABLE_ENTRY(pow_block),
    BTL_ITEM_TABLE_ENTRY(pebble),
    BTL_ITEM_TABLE_ENTRY(volt_shroom),
    BTL_ITEM_TABLE_ENTRY(thunder_rage),
    BTL_ITEM_TABLE_ENTRY(snowman_doll),
    BTL_ITEM_TABLE_ENTRY(mushroom),
    BTL_ITEM_TABLE_ENTRY(shooting_star),
    BTL_ITEM_TABLE_ENTRY(sleepy_sheep),
    BTL_ITEM_TABLE_ENTRY(stone_cap),
    BTL_ITEM_TABLE_ENTRY(tasty_tonic),
    BTL_ITEM_TABLE_ENTRY(thunder_bolt),
    BTL_ITEM_TABLE_ENTRY(mushroom),
    BTL_ITEM_TABLE_ENTRY(mushroom),
    BTL_ITEM_TABLE_ENTRY(super_soda),
    BTL_ITEM_TABLE_ENTRY(hustle_drink),
    BTL_ITEM_TABLE_ENTRY(stop_watch),
    BTL_ITEM_TABLE_ENTRY(dizzy_dial),
    BTL_ITEM_TABLE_ENTRY(please_come_back),
    BTL_ITEM_TABLE_ENTRY(egg_missile),
    BTL_ITEM_TABLE_ENTRY(insecticide_herb),
    BTL_ITEM_TABLE_ENTRY(fright_jar),
    BTL_ITEM_TABLE_ENTRY(mystery),
    BTL_ITEM_TABLE_ENTRY(repel_gel),
    BTL_ITEM_TABLE_ENTRY(life_shroom),
    BTL_ITEM_TABLE_ENTRY(coconut),
    BTL_ITEM_TABLE_ENTRY(electro_pop),
    BTL_ITEM_TABLE_ENTRY(strange_cake),
    BTL_ITEM_TABLE_ENTRY(strange_cake),
};

// Offsets into gBattleItemTable?
u16 D_80293E04[] = {
    1, 31, 1, 5, 1, 2, 9, 3, 9, 3, 9, 1, 10, 6, 10, 6, 10, 4, 11, 8, 11, 8, 11, 4, 12, 3, 12, 3, 12, 1,
};

ApiStatus LoadItemScript(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    s16 itemID = battleStatus->selectedItemID;
    ItemData* item = &gItemTable[itemID];
    s32 i = 0;
    s32* itemPtr;

    while (1) {
        if (playerData->invItems[i] == itemID) {
            playerData->invItems[i] = 0;
            break;
        }
        i++;
    }
    sort_items();

    if (battleStatus->selectedMoveID == MOVE_DOUBLE_DIP) {
        if (battleStatus->itemUsesLeft == 2) {
            deduct_current_move_fp();
        }
    }

    if (battleStatus->selectedMoveID == MOVE_TRIPLE_DIP) {
        if (battleStatus->itemUsesLeft == 3) {
            deduct_current_move_fp();
        }
    }

    itemPtr = &D_80293B80[0];
    for (i = 0; *itemPtr != ITEM_NONE; i++, itemPtr++) {
        if (*itemPtr == battleStatus->selectedItemID) {
            break;
        }
    }

    if (*itemPtr == ITEM_NONE) {
        if (item->typeFlags & 0x80) {
            i = 0;
        } else {
            i = 1;
        }
    }

    dma_copy(gBattleItemTable[i].romStart, gBattleItemTable[i].romEnd, gBattleItemTable[i].vramStart);

    script->varTablePtr[0] = gBattleItemTable[i].mainScript;
    script->varTable[1] = FALSE;

    return ApiStatus_DONE2;
}

ApiStatus LoadFreeItemScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;
    ItemData* item = &gItemTable[battleStatus->selectedItemID];
    SelectableTarget* target;
    s32* itemPtr;
    s32 i;

    battleStatus->currentTargetListFlags = item->targetFlags | 0x8000;
    battleStatus->currentAttackElement = 0;

    player_create_target_list(actor);
    target = &actor->targetData[actor->targetIndexList[0]];

    battleStatus->currentTargetID = target->actorID;
    battleStatus->currentTargetPart = target->partID;

    itemPtr = &D_80293B80[0];
    for (i = 0; *itemPtr != ITEM_NONE; i++, itemPtr++) {
        if (*itemPtr == battleStatus->selectedItemID){
            break;
        }
    }

    if (*itemPtr == ITEM_NONE) {
        if (item->typeFlags & 0x80) {
            i = 0;
        } else {
            i = 1;
        }
    }

    dma_copy(gBattleItemTable[i].romStart, gBattleItemTable[i].romEnd, gBattleItemTable[i].vramStart);
    script->varTablePtr[0] = gBattleItemTable[i].mainScript;
    script->varTable[1] = TRUE;
    return ApiStatus_DONE2;
}

EvtScript UseMystery = {
    EVT_WAIT(2)
    EVT_CALL(LoadFreeItemScript)
    EVT_EXEC_WAIT(LVar0)
    EVT_RETURN
    EVT_END
};
