#include "common.h"
#include "ld_addrs.h"
#include "battle.h"

extern EvtScript battle_item_food_EVS_UseItem;
extern EvtScript battle_item_mushroom_EVS_UseItem;
extern EvtScript battle_item_fire_flower_EVS_UseItem;
extern EvtScript battle_item_dusty_hammer_EVS_UseItem;
extern EvtScript battle_item_pow_block_EVS_UseItem;
extern EvtScript battle_item_pebble_EVS_UseItem;
extern EvtScript battle_item_volt_shroom_EVS_UseItem;
extern EvtScript battle_item_thunder_rage_EVS_UseItem;
extern EvtScript battle_item_snowman_doll_EVS_UseItem;
extern EvtScript battle_item_shooting_star_EVS_UseItem;
extern EvtScript battle_item_sleepy_sheep_EVS_UseItem;
extern EvtScript battle_item_stone_cap_EVS_UseItem;
extern EvtScript battle_item_tasty_tonic_EVS_UseItem;
extern EvtScript battle_item_thunder_bolt_EVS_UseItem;
extern EvtScript battle_item_super_soda_EVS_UseItem;
extern EvtScript battle_item_hustle_drink_EVS_UseItem;
extern EvtScript battle_item_stop_watch_EVS_UseItem;
extern EvtScript battle_item_dizzy_dial_EVS_UseItem;
extern EvtScript battle_item_please_come_back_EVS_UseItem;
extern EvtScript battle_item_egg_missile_EVS_UseItem;
extern EvtScript battle_item_insecticide_herb_EVS_UseItem;
extern EvtScript battle_item_fright_jar_EVS_UseItem;
extern EvtScript battle_item_mystery_EVS_UseItem;
extern EvtScript battle_item_repel_gel_EVS_UseItem;
extern EvtScript battle_item_life_shroom_EVS_UseItem;
extern EvtScript battle_item_coconut_EVS_UseItem;
extern EvtScript battle_item_electro_pop_EVS_UseItem;
extern EvtScript battle_item_strange_cake_EVS_UseItem;

#define GENERIC_FOOD_ITEM -1

// items in this list must correspond with BattleMoveEntry in gBattleItemTable
s32 ItemKeys[] = {
    GENERIC_FOOD_ITEM,
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

BattleMoveEntry gBattleItemTable[] = {
    BTL_ITEM(food),
    BTL_ITEM(mushroom),
    BTL_ITEM(fire_flower),
    BTL_ITEM(dusty_hammer),
    BTL_ITEM(pow_block),
    BTL_ITEM(pebble),
    BTL_ITEM(volt_shroom),
    BTL_ITEM(thunder_rage),
    BTL_ITEM(snowman_doll),
    BTL_ITEM(mushroom),
    BTL_ITEM(shooting_star),
    BTL_ITEM(sleepy_sheep),
    BTL_ITEM(stone_cap),
    BTL_ITEM(tasty_tonic),
    BTL_ITEM(thunder_bolt),
    BTL_ITEM(mushroom),
    BTL_ITEM(mushroom),
    BTL_ITEM(super_soda),
    BTL_ITEM(hustle_drink),
    BTL_ITEM(stop_watch),
    BTL_ITEM(dizzy_dial),
    BTL_ITEM(please_come_back),
    BTL_ITEM(egg_missile),
    BTL_ITEM(insecticide_herb),
    BTL_ITEM(fright_jar),
    BTL_ITEM(mystery),
    BTL_ITEM(repel_gel),
    BTL_ITEM(life_shroom),
    BTL_ITEM(coconut),
    BTL_ITEM(electro_pop),
    BTL_ITEM(strange_cake),
    BTL_ITEM(strange_cake),
};

// Offsets into gBattleItemTable?
u16 D_80293E04[] = {
    1, 31, 1, 5, 1, 2, 9, 3, 9, 3, 9, 1, 10, 6, 10, 6, 10, 4, 11, 8, 11, 8, 11, 4, 12, 3, 12, 3, 12, 1,
};

API_CALLABLE(LoadItemScript) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    s16 itemID = battleStatus->moveArgument;
    ItemData* item = &gItemTable[itemID];
    s32 i = 0;
    s32* itemPtr;

    while (TRUE) {
        if (playerData->invItems[i] == itemID) {
            playerData->invItems[i] = ITEM_NONE;
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

    itemPtr = &ItemKeys[0];
    for (i = 0; *itemPtr != ITEM_NONE; i++, itemPtr++) {
        if (*itemPtr == battleStatus->moveArgument) {
            break;
        }
    }

    if (*itemPtr == ITEM_NONE) {
        if (item->typeFlags & ITEM_TYPE_FLAG_FOOD_OR_DRINK) {
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

API_CALLABLE(LoadMysteryItemScript) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;
    ItemData* item = &gItemTable[battleStatus->moveArgument];
    SelectableTarget* target;
    s32* itemPtr;
    s32 i;

    battleStatus->curTargetListFlags = item->targetFlags | TARGET_FLAG_PRIMARY_ONLY;
    battleStatus->curAttackElement = 0;

    create_current_pos_target_list(actor);
    target = &actor->targetData[actor->targetIndexList[0]];

    battleStatus->curTargetID = target->actorID;
    battleStatus->curTargetPart = target->partID;

    itemPtr = &ItemKeys[0];
    for (i = 0; *itemPtr != ITEM_NONE; i++, itemPtr++) {
        if (*itemPtr == battleStatus->moveArgument){
            break;
        }
    }

    if (*itemPtr == ITEM_NONE) {
        if (item->typeFlags & ITEM_TYPE_FLAG_FOOD_OR_DRINK) {
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

EvtScript EVS_UseMystery = {
    EVT_WAIT(2)
    EVT_CALL(LoadMysteryItemScript)
    EVT_EXEC_WAIT(LVar0)
    EVT_RETURN
    EVT_END
};
