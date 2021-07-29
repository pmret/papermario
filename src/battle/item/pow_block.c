#include "pow_block.h"

static HudElement* D_802A2120;

ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
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
        D_802A2120 = create_hud_element(&D_80108A64);
        set_hud_element_render_pos(D_802A2120, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        free_hud_element(D_802A2120);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A123C_718A8C)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (player->scalingFactor == 1.0) {
        s32 var = script->varTable[10];
        get_entity_by_index(var);
        collisionStatus->currentCeiling = var | 0x4000;
        playerStatus->flags |= 2;
        update_entities();
        collisionStatus->currentCeiling = -1;
        playerStatus->flags &= ~2;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12E4_718B34)(ScriptInstance* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->flags |= 0x20000000;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1318_718B68)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->scale.x = player->scalingFactor;
    entity->scale.y = player->scalingFactor;
    entity->scale.z = player->scalingFactor;
    if (player->scalingFactor != 1.0) {
        entity->position.y -= 10.0f;
    }

    return ApiStatus_DONE2;
}

Script N(UseItemWithEffect) = SCRIPT({
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

Script N(UseItem) = SCRIPT({
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

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_P_O_W_BLOCK;
    await N(UseItemWithEffect);
    sleep 10;
    MakeEntity(0x802EA2E0, -40, 60, 0, 0, MAKE_ENTITY_END);
    SI_VAR(10) = SI_VAR(0);
    N(func_802A1318_718B68)();
    PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    spawn {
        sleep 15;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_HIT_BLOCK);
        N(func_802A123C_718A8C)();
        PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        StartRumble(4);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 6.0);
        ShakeCam(1, 0, 2, 5.0);
        ShakeCam(1, 0, 2, 4.0);
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2030);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 2.0);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 0.5);
        ShakeCam(1, 0, 2, 0.2001953125);
    }
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetActorSpeed(ACTOR_PLAYER, 4.0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    SetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlayerRunToGoal(ACTOR_PLAYER);
    sleep 5;
    SetJumpAnimations(ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009);
    SetActorJumpGravity(ACTOR_PLAYER, 0.6005859375);
    SetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80273444(20, 0, 0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ITEM_P_O_W_BLOCK, SI_VAR(3), SI_VAR(4));
    ApplyShrinkFromOwner(SI_VAR(3));
    func_80269EAC(22);
    ItemDamageEnemy(SI_VAR(0), 0x38000400, 0, SI_VAR(3), 32);
1:
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    PlayEffect(0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -60, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -70, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A12E4_718B34)();
    sleep 30;
    await N(PlayerGoHome);
});
