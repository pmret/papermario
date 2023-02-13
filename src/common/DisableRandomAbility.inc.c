#include "common.h"

s32 N(hammer_icons)[] = { ITEM_HAMMER1_ICON, ITEM_HAMMER2_ICON, ITEM_HAMMER3_ICON };

s32 N(hammer_text)[] = { 73, 74, 75 };

s32 N(jump_icons)[] = { ITEM_BOOTS1_ICON, ITEM_BOOTS2_ICON, ITEM_BOOTS3_ICON };

s32 N(jump_text)[] = { 76, 77, 78 };

API_CALLABLE(N(DisableRandomAbility)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s32 turnsLost;
    s32 i = 0;
    s32 temp[3];

    if (battleStatus->hammerLossTurns == -1) {
        temp[i++] = 0;
    }

    if (battleStatus->jumpLossTurns == -1) {
        temp[i++] = 1;
    }

    if (battleStatus->itemLossTurns == -1) {
        temp[i++] = 2;
    }

    turnsLost = rand_int(2) + 2;
    switch (temp[rand_int(i - 1)]) {
        case 0:
            battleStatus->hammerLossTurns = turnsLost;
            evt_set_variable(script, *args++, N(hammer_icons)[playerData->hammerLevel]);
            evt_set_variable(script, *args++, N(hammer_text)[playerData->hammerLevel]);
            break;

        case 1:
            battleStatus->jumpLossTurns = turnsLost;
            evt_set_variable(script, *args++, N(jump_icons)[playerData->bootsLevel]);
            evt_set_variable(script, *args++, N(jump_text)[playerData->bootsLevel]);
            break;

        case 2:
            battleStatus->itemLossTurns = turnsLost;
            evt_set_variable(script, *args++, ITEM_ITEMS_ICON);
            evt_set_variable(script, *args++, 79);
            break;
    }

    return ApiStatus_DONE2;
}
