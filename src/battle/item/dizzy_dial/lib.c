#include "dizzy_dial.h"

extern s32 D_80108A64;
MenuIcon* D_802A1CD4;
s32* D_802A1CD0;

void func_802A11D4_7332A4(void);
void battle_star_peach_dash_UnkStarFunc1(void);
void func_8024ECF8(void);
ApiStatus func_80252B3C(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A1000_727910)(ScriptInstance* script) {
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
        D_802A1CD4 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1CD4, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A11D4_727AE4)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1CD4);
    }

    return ApiStatus_DONE2;
}

void func_802A123C_727B4C(void) {
    func_80138D88(0, 0, 0x140, 0xF0, 160.0f);
}

ApiStatus N(func_802A1270_727B80)(ScriptInstance* script, s32 isInitialCall) {
    Camera *camera = &gCameras[1];
    f32 a;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    switch(script->functionTemp[0].s) {
        case 0:
            script->functionTemp[1].s = 0;
            script->functionTemp[2].s = 0;
            play_sound(0x2033);
            camera->unk_1C = 0;
            D_802A1CD0 = bind_dynamic_entity_7(NULL, func_802A123C_727B4C);
            script->functionTemp[0].s = 1;
        case 1:
            camera->flags |= 8;
            a = script->functionTemp[1].s;
            guRotateF(camera->viewMtxShaking, a, 0.0f, 0.0f, 1.0f);
            script->functionTemp[1].s = 2.0 * ((1.0 - sin_rad(((script->functionTemp[2].s + 0x5A) * 6.28318f) / 360.0f)) * 360.0);
            script->functionTemp[2].s++;
            if (script->functionTemp[2].s < 0x5B) {
                return ApiStatus_BLOCK;
            }
            camera->unk_1C = 0;
            camera->flags &= ~8;
            func_801235C0(D_802A1CD0);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
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

        N(func_802A1000_727910)();
        sleep SI_VAR(0);

        sleep 15;

        N(func_802A11D4_727AE4)();
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
    battle_star_peach_dash_UnkStarFunc1();
    sleep SI_VAR(0);
    sleep 15;
    func_802A11D4_7332A4();
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
    SI_VAR(10) =c 0x9A;
    await 0x802A13D0;
    UseCamPreset(2);
    MoveBattleCamOver(20);
    sleep 10;
    spawn {
        sleep 5;
        AddBattleCamZoom(0xFFFFFF06);
        MoveBattleCamOver(80);
        func_8024ECF8(0, 0, 1);
        sleep 80;
        AddBattleCamZoom(250);
        MoveBattleCamOver(3);
        func_8024ECF8(0, 0, 1);
    }
    N(func_802A1270_727B80)();
    spawn {
        StartRumble(8);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 4.0);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 2.0);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 0.5);
        sleep 10;
        UseCamPreset(3);
        MoveBattleCamOver(10);
        func_8024ECF8(0, 0, 0);
    }
    InitTargetIterator();
0:
    SetGoalToTarget(0xFFFFFF81);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(154, SI_VAR(0), SI_VAR(1));
    MakeStatusField(SI_VAR(0), 0x40000, 100, SI_VAR(0));
    func_80252B3C(SI_VAR(0), 0x50000000, SI_VAR(0), 0, 32);
1:
    sleep 5;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 30;
    await 0x802A1800;
});
