#include "stone_cap.h"

extern s32 D_80108A64;
static MenuIcon* D_802A1A60;

ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;
    f32 posX, posY, posZ;
    posY = player->currentPos.y + player->size.y;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        s32 i;
        s32 iconPosX, iconPosY, iconPosZ;

        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ItemId_COIN, posX, posY, posZ, 0x17, (i * 3) + 1, facingAngleSign, 0);
            add_coins(1);
            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;
        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconPosX, &iconPosY, &iconPosZ);
        D_802A1A60 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1A60, iconPosX + 36, iconPosY - 63);
    }
 
    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1A60);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A123C_7217DC)(ScriptInstance *script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            inflict_status(player, 12, script->varTable[0]);
            player->status = 0;
            script->functionTemp[1].s = 3;
            script->functionTemp[0].s = 1;
            break;

        case 1:
            for (i = 0; i < 10; i++) {
                f32 x = player->currentPos.x + ((rand_int(20) - 10) * player->scalingFactor);
                f32 y = player->currentPos.y + ((rand_int(20) + 10) * player->scalingFactor);
                f32 z = player->currentPos.z + 5.0f;
                func_80071FF0(0, x, y, z, 1.0f, 25);
            }

            if (script->functionTemp[1].s == 0) {
                BattleStatus* battleStatus2 = &gBattleStatus;

                battleStatus2->flags1 &= ~0x04000000;
                battleStatus->hustleTurns = 0;
                battleStatus->itemUsesLeft = 0;

                return ApiStatus_DONE2;
            }

            script->functionTemp[1].s--;
            break;
    }

    return ApiStatus_BLOCK;
}

Script N(UseItemWithEffect) = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseCamPreset(69);
        sleep 10;
        PlaySoundAtActor(ActorID_PLAYER, 8333);
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_GOT_ITEM);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 18;
        SetActorSpeed(ActorID_PLAYER, 4.0);
        SetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
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
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlaySoundAtActor(ActorID_PLAYER, 8333);
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_GOT_ITEM);
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

Script N(UseItem) = SCRIPT({
    UseCamPreset(19);
    SetBattleCamTarget(0xFFFFFFAB, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(30);
    sleep 10;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_GOT_ITEM);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 45;
    MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
    SI_VAR(14) = SI_VAR(0);
    N(GiveRefund)();
    sleep SI_VAR(0);
    sleep 15;
    N(GiveRefundCleanup)();
    RemoveItemEntity(SI_VAR(14));
});

Script N(PlayerGoHome) = SCRIPT({ 
    UseIdleAnimation(ActorID_PLAYER, 0);
    SetGoalToHome(ActorID_PLAYER);
    SetActorSpeed(ActorID_PLAYER, 8.0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_RUNNING);
    PlayerRunToGoal(0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    UseIdleAnimation(ActorID_PLAYER, 1);
});

Script N(EatItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ActorID_PLAYER, 8341);
            sleep 10;
        }
    }
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_EAT);
    sleep 45;
});

Script N(DrinkItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ActorID_PLAYER, 8341);
            sleep 10;
        }
    }
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_DRINK);
    sleep 45;
});
