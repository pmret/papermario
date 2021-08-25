#include "hustle_drink.h"

static HudElement* D_802A1E70;

ApiStatus N(GiveRefund)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;
    f32 posX, posY, posZ;
    posY = player->currentPos.y + player->size.y;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 i;
        s32 iconPosX, iconPosY, iconPosZ;

        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, 0x17, (i * 3) + 1, facingAngleSign, 0);
            add_coins(1);
            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;
        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconPosX, &iconPosY, &iconPosZ);
        D_802A1E70 = create_hud_element(&D_80108A64);
        set_hud_element_render_pos(D_802A1E70, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        free_hud_element(D_802A1E70);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A123C_72619C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    if (player->debuff != 0) {
        player->debuffDuration = 0;
        player->debuff = 0;
        remove_status_1(player->unk_436);
    }
    if (player->staticStatus != 0) {
        player->staticDuration = 0;
        player->staticStatus = 0;
        remove_status_2(player->unk_436);
    }
    if (player->stoneStatus != 0) {
        player->stoneDuration = 0;
        player->stoneStatus = 0;
    }
    if (player->transStatus != 0) {
        player->transDuration = 0;
        player->transStatus = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12C4_726224)(Evt* script, s32 isInitialCall) {
    gBattleStatus.hustleTurns = 2;

    return ApiStatus_DONE2;
}

EvtSource N(UseItemWithEffect) = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseBattleCamPreset(69);
        sleep 10;

        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_208D);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
        GetActorPos(ACTOR_PLAYER, $x, $y, $z);
        $x += 18;
        SetActorSpeed(ACTOR_PLAYER, 4.0);
        SetGoalPos(ACTOR_PLAYER, $x, $y, $z);
        PlayerRunToGoal(ACTOR_PLAYER);

        $y += 45;
        $effectY = $y;
        $effectY += 10;
        $effectY += 2;
        PlayEffect(0x33, 1, $x, $effectY, $z, 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), $x, $y, $z, 1, 0);
        SI_VAR(10) = $x;

        N(GiveRefund)();
        sleep $x;

        sleep 15;

        N(GiveRefundCleanup)();
        RemoveItemEntity(SI_VAR(10));
    } else {
        GetActorPos(ACTOR_PLAYER, $x, $y, $z);
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_208D);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
        sleep 4;

        $y += 45;
        $effectY = $y;
        $effectY += 10;
        $effectY += 2;
        PlayEffect(0x33, 1, $x, $effectY, $z, 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), $x, $y, $z, 1, 0);
        SI_VAR(10) = $x;

        sleep 15;
        RemoveItemEntity(SI_VAR(10));
    }
});

EvtSource N(UseItem) = SCRIPT({
    UseBattleCamPreset(19);
    SetBattleCamTarget(-85, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(30);
    sleep 10;

    SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
    GetActorPos(ACTOR_PLAYER, $x, $y, $z);
    $y += 45;
    MakeItemEntity(SI_VAR(10), $x, $y, $z, 1, 0);
    SI_VAR(14) = $x;

    N(GiveRefund)();
    sleep $x;

    sleep 15;

    N(GiveRefundCleanup)();
    RemoveItemEntity(SI_VAR(14));
});

EvtSource N(PlayerGoHome) = SCRIPT({
    UseIdleAnimation(ACTOR_PLAYER, 0);
    SetGoalToHome(ACTOR_PLAYER);
    SetActorSpeed(ACTOR_PLAYER, 8.0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    PlayerRunToGoal(ACTOR_PLAYER);

    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    UseIdleAnimation(ACTOR_PLAYER, 1);
});

EvtSource N(EatItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_EAT);
    sleep 45;
});

EvtSource N(DrinkItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_DRINK);
    sleep 45;
});

EvtSource N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_HUSTLE_DRINK;
    await N(UseItemWithEffect);
    await N(DrinkItem);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_SQUISH);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
    N(func_802A12C4_726224)();
    N(func_802A123C_72619C)();
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    UseBattleCamPreset(13);
    BattleCamTargetActor(ACTOR_SELF);
    MoveBattleCamOver(20);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_369);
    spawn {
        loop 2 {
            SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.1005859375, 1.0, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.2001953125, 0.9501953125, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.30078125, 0.900390625, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3505859375, 0.8505859375, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.380859375, 0.80078125, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.400390625, 0.80078125, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.30078125, 0.8505859375, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.2001953125, 0.900390625, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.1005859375, 0.9501953125, 1.0);
            sleep 1;
        }
        SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.1005859375, 1.0, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.2001953125, 0.9501953125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.30078125, 0.900390625, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.3505859375, 0.8505859375, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.380859375, 0.80078125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.400390625, 0.80078125, 1.0);
        sleep 1;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_208E);
        SetActorScale(ACTOR_SELF, 0.900390625, 1.30078125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 0.900390625, 1.2001953125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 0.9501953125, 1.1005859375, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
        sleep 1;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    loop 10 {
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_369);
        PlayEffect(0x6, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x6, 1, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
        sleep 4;
    }
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    sleep 20;
    await N(PlayerGoHome);
});
