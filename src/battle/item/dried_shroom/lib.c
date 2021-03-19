#include "dried_shroom.h"

extern s32 D_80108A64;
MenuIcon* D_802A1A90;

void func_802A123C_73330C();
void func_802D7520();
void func_802A12FC_75E8CC();
void func_802D75D8();

ApiStatus N(func_802A1000_71CCE0)(ScriptInstance* script, s32 isInitialCall) {
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
        D_802A1A90 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1A90, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A11D4_71CEB4)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
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

Script N(script1) = SCRIPT({
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
        N(func_802A1000_71CCE0)();
        sleep SI_VAR(0);
        sleep 15;
        N(func_802A11D4_71CEB4)();
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

Script N(script2) = SCRIPT({
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
    N(func_802A1000_71CCE0)();
    sleep SI_VAR(0);
    sleep 15;
    N(func_802A11D4_71CEB4)();
    RemoveItemEntity(SI_VAR(14));
});

Script N(script3) = SCRIPT({
    UseIdleAnimation(0, 0);
    SetGoalToHome(0);
    SetActorSpeed(0, 8.0);
    SetAnimation(0, 0, 0x10005);
    PlayerRunToGoal(0);
    SetAnimation(0, 0, 0x10002);
    UseIdleAnimation(0, 1);
});

Script N(script4) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(0, 8341);
            sleep 10;
        }
    }
    SetAnimation(0, 0, 0x1001C);
    sleep 45;
});

Script N(script5) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(0, 8341);
            sleep 10;
        }
    }
    SetAnimation(0, 0, 0x10025);
    sleep 45;
});

Script N(script6) = SCRIPT({
    SI_VAR(10) =c 0x8D;
    await 0x802A1340;
    await 0x802A180C;
    SetAnimation(0, 0, 0x1001D);
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 35;
    func_802A123C_73330C(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SI_VAR(2) += 5;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    func_802A12FC_75E8CC();
    sleep 30;
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(2) += 5;
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    SetAnimation(0, 0, 0x10002);
    sleep 20;
    await 0x802A1770;
});

