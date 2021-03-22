#include "shooting_star.h"

extern s32 D_80108A64;
MenuIcon* D_802A1EE0;

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
        D_802A1EE0 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1EE0, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1EE0);
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(ApiStatus, "battle/item/shooting_star_71D770", battle_item_shooting_star_func_802A123C_71D9AC, ScriptInstance *script, s32 isInitialCall);
/*
void func_8006FE30(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

ApiStatus N(func_802A123C_71D9AC)(ScriptInstance *script, s32 isInitialCall) {
    s32 c8 = 200;
    s32 temp_s1 = 100 + rand_int(c8);
    s32 temp_s0 = rand_int(40);
    s32 phi_a0;
    s32 phi_v0;
    s32 rand;
    f32 temp_f20;
    f32 temp_f22;
    f32 test;

    if (script->varTable[0] & 3) {
        rand = rand_int(100);
        rand += c8;
        temp_f22 = temp_s1 - rand;
        rand = rand_int(100);
        rand -= 50;
        temp_f20 = temp_s0 - rand;
        phi_v0 = rand_int(10);
        phi_a0 = 2;
    } else {
        rand = rand_int(100);
        rand += 200;
        temp_f22 = temp_s1 - rand;
        rand = rand_int(100);
        rand -= 50;
        temp_f20 = temp_s0 - rand;
        phi_v0 = rand_int(10);
        phi_a0 = 3;
    }

    do {
        func_8006FE30(phi_a0, temp_s1, c8, temp_s0, temp_f22, 0, temp_f20, phi_v0 + 7);
        if (temp_f20) {
            temp_f20 -= rand;
        }
    } while (0);

    return ApiStatus_DONE2;
}
*/

ApiStatus N(func_802A1388_71DAF8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
 
    func_80070190(2, a, b, c, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1444_71DBB4)(ScriptInstance *script, s32 isInitialCall) {
    s32 ret;

    if (isInitialCall) {
        func_8011D82C(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 10;
    }

    set_background_color_blend(0, 0, 0, ((10 - script->functionTemp[0].s) * 16) & 240);
    script->functionTemp[0].s--;
    do {} while (0);
    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}

ApiStatus N(func_802A14D4_71DC44)(ScriptInstance *script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 10;
    }
    set_background_color_blend(0, 0, 0, (script->functionTemp[0].s * 16) & 240);
    script->functionTemp[0].s--;
    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);

        return ApiStatus_DONE2;
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
