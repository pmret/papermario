#include "common.h"
#include "hud_element.h"

static s32 itemIcon;

// out LVar0: time caller should wait for coin spawns
API_CALLABLE(N(GiveRefund)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = gBattleStatus.playerActor;
    s32 sellValue = gItemTable[battleStatus->moveArgument].sellValue;
    f32 posX;
    f32 posY = player->curPos.y + player->size.y;
    f32 posZ;
    f32 angle = 0.0f;
    s32 delayTime = 0;
    s32 tempIcon;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 iconX;
        s32 iconY;
        s32 iconZ;
        s32 i;

        // 75% of the item's sell value, rounded up
        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->curPos.x;
            posZ = player->curPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, ITEM_SPAWN_MODE_TOSS_FADE1, 1 + 3 * i, angle, 0);
            add_coins(1);

            angle += 30.0f;
        }

        delayTime = (i * 3) + 30;

        posX = player->curPos.x;
        posY = player->curPos.y;
        posZ = player->curPos.z;

        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconX, &iconY, &iconZ);

#if VERSION_PAL
        switch (gCurrentLanguage) {
            case LANGUAGE_EN:
                itemIcon = tempIcon = hud_element_create(&HES_Refund);
                break;
            case LANGUAGE_DE:
                itemIcon = tempIcon = hud_element_create(&HES_Refund_de);
                break;
            case LANGUAGE_FR:
                itemIcon = tempIcon = hud_element_create(&HES_Refund_fr);
                break;
            case LANGUAGE_ES:
                itemIcon = tempIcon = hud_element_create(&HES_Refund_es);
                break;
        }
        hud_element_set_render_pos(tempIcon, iconX + 36, iconY - 63);
#else
        itemIcon = hud_element_create(&HES_Refund);
        hud_element_set_render_pos(itemIcon, iconX + 36, iconY - 63);
#endif
    }

    script->varTable[0] = delayTime;

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
