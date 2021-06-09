#include "dried_shroom.h"

extern s32 D_80108A64;
static HudElement* D_802A1A90;

ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;
    f32 posX, posY, posZ;
    posY = player->currentPos.y + player->size.y;

    if (heroes_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
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
        D_802A1A90 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1A90, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        free_icon(D_802A1A90);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A123C_71CF1C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    func_80071090(0, a, b, c, d);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12FC_71CFDC)(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

Script N(UseItemWithEffect) = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseCamPreset(69);
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

Script N(UseItem) = SCRIPT({
    UseCamPreset(19);
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

Script N(PlayerGoHome) = SCRIPT({
    UseIdleAnimation(ACTOR_PLAYER, 0);
    SetGoalToHome(ACTOR_PLAYER);
    SetActorSpeed(ACTOR_PLAYER, 8.0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    PlayerRunToGoal(ACTOR_PLAYER);

    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    UseIdleAnimation(ACTOR_PLAYER, 1);
});

Script N(EatItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_EAT);
    sleep 45;
});

Script N(DrinkItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_DRINK);
    sleep 45;
});
