#include "coconut.h"

MenuIcon* D_802A1E80;
void* D_80108A64; // an image

// Returns time to sleep for on SI_VAR(0).
ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = BATTLE_STATUS;
    Actor* player = PLAYER_ACTOR;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 posX;
    f32 posY = player->currentPos.y + player->size.y;
    f32 posZ;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        s32 iconX;
        s32 iconY;
        s32 iconZ;
        s32 i;

        // 75% of the item's sell value, rounded up
        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ItemId_COIN, posX, posY, posZ, 0x17, 1 + 3 * i, facingAngleSign, 0);
            add_coins(1);

            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;

        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconX, &iconY, &iconZ);
        D_802A1E80 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1E80, iconX + 36, iconY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = BATTLE_STATUS;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(battleStatus->playerActor, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1E80);
    }

    return ApiStatus_DONE2;
}

Script D_802A1240_72F960 = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseCamPreset(69);
        sleep 10;
        PlaySoundAtActor(0, 8333);
        SetAnimation(0, 0, 0x1001F);
        GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 18;
        SetActorSpeed(0, 4.0);
        SetGoalPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlayerRunToGoal(0);
        SI_VAR(1) += 45;
        SI_VAR(3) = SI_VAR(1);
        SI_VAR(3) += 10;
        SI_VAR(3) += 2;
        PlayEffect(51, 1, SI_VAR(0), SI_VAR(3), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
        SI_VAR(10) = SI_VAR(0);
        N(GiveRefund)();
        sleep SI_VAR(0);
        sleep 15;
        N(GiveRefundCleanup)();
        RemoveItemEntity(SI_VAR(10));
    } else {
        GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlaySoundAtActor(0, 8333);
        SetAnimation(0, 0, 0x1001F);
        sleep 4;
        SI_VAR(1) += 45;
        SI_VAR(3) = SI_VAR(1);
        SI_VAR(3) += 10;
        SI_VAR(3) += 2;
        PlayEffect(51, 1, SI_VAR(0), SI_VAR(3), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
        SI_VAR(10) = SI_VAR(0);
        sleep 15;
        RemoveItemEntity(SI_VAR(10));
    }
});

Script D_802A1544_72FC64 = SCRIPT({
    UseCamPreset(19);
    SetBattleCamTarget(0xFFFFFFAB, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(30);
    sleep 10;
    SetAnimation(0, 0, 0x1001F);
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 45;
    MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
    SI_VAR(14) = SI_VAR(0);
    N(GiveRefund)();
    sleep SI_VAR(0);
    sleep 15;
    N(GiveRefundCleanup)();
    RemoveItemEntity(SI_VAR(14));
});

Script D_802A1670_72FFD0 = SCRIPT({
    UseIdleAnimation(0, 0);
    SetGoalToHome(0);
    SetActorSpeed(0, 8.0);
    SetAnimation(0, 0, PlayerAnim_RUNNING);
    PlayerRunToGoal(0);
    SetAnimation(0, 0, 0x10002);
    UseIdleAnimation(0, 1);
});

Script Script_802A170C = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(0, 0x2095);
            sleep 10;
        }
    }
    SetAnimation(0, 0, 0x1001C);
    sleep 45;
});

Script D_802A1784_7300E4 = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(0, 0x2095);
            sleep 10;
        }
    }
    SetAnimation(0, 0, 0x10025);
    sleep 45;
});
