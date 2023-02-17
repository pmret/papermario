#include "common.h"
#include "hud_element.h"

static s32 itemIcon;

// Returns time to sleep for on $x.
API_CALLABLE(N(GiveRefund)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = gBattleStatus.playerActor;
    s32 sellValue = gItemTable[battleStatus->moveArgument].sellValue;
    f32 posX;
    f32 posY = player->currentPos.y + player->size.y;
    f32 posZ;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 iconX;
        s32 iconY;
        s32 iconZ;
        s32 i;

        // 75% of the item's sell value, rounded up
        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, 0x17, 1 + 3 * i, facingAngleSign, 0);
            add_coins(1);

            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;

        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconX, &iconY, &iconZ);
        itemIcon = hud_element_create(&HES_Refund);
        hud_element_set_render_pos(itemIcon, iconX + 36, iconY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GiveRefundCleanup)) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 sellValue = gItemTable[battleStatus->moveArgument].sellValue;

    if (player_team_is_ability_active(battleStatus->playerActor, ABILITY_REFUND) && sellValue > 0) {
        hud_element_free(itemIcon);
    }

    return ApiStatus_DONE2;
}
