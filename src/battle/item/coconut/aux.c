#include "coconut.h"

MenuIcon* D_802A1E80;
void* D_80108A64; // an image

#ifdef NON_MATCHING
ApiStatus func_802A1000_72F720(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus;
    Actor* player;
    Actor* player2;
    s32 sellValue;
    s32 numCoins;
    s32 pickupDelay;
    f32 facingAngleSign;
    s32 i;

    f32 posX;
    f32 posY;
    f32 posZ;

    s32 iconX;
    s32 iconY;
    s32 iconZ;

    i = 0;
    facingAngleSign = 0.0f;

    battleStatus = BATTLE_STATUS;
    sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    posY = battleStatus->playerActor->currentPos.y + battleStatus->playerActor->size.y;

    player = PLAYER_ACTOR;

    // If Refund is equipped, the player gets
    if (heroes_is_ability_active(battleStatus->playerActor, Ability_REFUND)) {
        //player2 = player;

        if (sellValue > 0) {
            // 75% of the item's sell value, rounded up
            sellValue = (sellValue * 75 + 99) / 100;

            pickupDelay = 1;
                player2 = player;

            while (i < sellValue) {
                posX = player2->currentPos.x;
                posZ = player2->currentPos.z;

                make_item_entity(ItemId_COIN, posX, posY, posZ, 0x17, pickupDelay, facingAngleSign, 0);
                add_coins(1);

                pickupDelay += 3;
                facingAngleSign += 30.0f;
                i++;
            }

            i = (i * 3) + 30;

                //player2 = player;
            posX = player2->currentPos.x;
            posY = player2->currentPos.y;
            posZ = player2->currentPos.z;

            get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconX, &iconY, &iconZ);
            D_802A1E80 = create_icon(&D_80108A64);
            set_icon_render_pos(D_802A1E80, iconX + 36, iconY - 63);
        }
    }

    script->varTable[0] = i;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/coconut", func_802A1000_72F720, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus func_802A11D4_72F8F4(ScriptInstance* script, s32 isInitialCall) {
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
        func_802A1000_72F720();
        sleep SI_VAR(0);
        sleep 15;
        func_802A11D4_72F8F4();
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
    func_802A1000_72F720();
    sleep SI_VAR(0);
    sleep 15;
    func_802A11D4_72F8F4();
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
