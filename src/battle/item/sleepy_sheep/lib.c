#include "sleepy_sheep.h"

extern s32 D_80108A64;
static HudElement* D_802A3F50;

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
        D_802A3F50 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A3F50, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0].s = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        free_icon(D_802A3F50);
    }

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING

extern Vec3f D_802A3F88;
extern s32* D_802A3F58;

s32 N(D_802A3E88_7214D8)[] = {
    0x00000000, 0x00000000, 0x00000000,
    0xFFFFFFE2, 0x00000000, 0xFFFFFFCE,
    0xFFFFFFE5, 0x00000000, 0x0000001E,
    0xFFFFFFBA, 0x00000000, 0xFFFFFFFB,
    0xFFFFFF97, 0x00000000, 0x0000001E,
    0xFFFFFF92, 0x00000000, 0xFFFFFFCE,
    0xFFFFFF6F, 0x00000000, 0xFFFFFFFB,
    0xFFFFFF56, 0x00000000, 0xFFFFFFCE,
    0xFFFFFF42, 0x00000000, 0xFFFFFFE2,
    0xFFFFFF2E, 0x00000000, 0xFFFFFFF6
};

f32 N(D_802A3F00_721550)[] = {
    0x3F800000, 0x3F800000, 0x3F400000, 0x3F800000,
    0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x3F400000, 0x3F400000
};

s32 N(D_802A3F28_721578)[] = {
    0x802A3260, 0x802A32A0, 0x802A32E0, 0x802A3260,
    0x802A32A0, 0x802A32E0, 0x802A3260, 0x802A32A0,
    0x802A32E0, 0x802A3260
};

void func_802D4364(s32, s32, s32, s32);
void func_802D43AC(s32, f32, f32, f32);
void func_802D43F4(s32);

ApiStatus func_802A123C_71E88C(ScriptInstance* script, s32 isInitialCall) {
    s32 i;
    Vec3f vecf;
    s32 flag;
    Vec3f* D_802A3F88_ptr = &D_802A3F88;
    s32* D_802A3E88_7214D8_ptr1; // = &N(D_802A3E88_7214D8);
    s32* D_802A3E88_7214D8_ptr2; // = &N(D_802A3E88_7214D8);
    s32* D_802A3E88_7214D8_ptr3; // = &N(D_802A3E88_7214D8);
    s32* D_802A3F58_ptr;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    switch (script->functionTemp[0].s) {
        case 0: {
            s32* D_802A3F28_721578_ptr = &N(D_802A3F28_721578);
            s32 loop1, loop2, loop3;
            D_802A3F58_ptr = &D_802A3F58;

            D_802A3F88_ptr->x = -200.0f;
            D_802A3F88_ptr->z = 10.0f;

            D_802A3E88_7214D8_ptr1 = N(D_802A3E88_7214D8) + 0;
            D_802A3E88_7214D8_ptr2 = N(D_802A3E88_7214D8) + 1;
            D_802A3E88_7214D8_ptr3 = N(D_802A3E88_7214D8) + 2;

            for (i = 0; i < 10; i++) {
                D_802A3F58_ptr[i] = func_802D420C(D_802A3F28_721578_ptr[i]);

                func_802D4364(D_802A3F58_ptr[i],
                              *D_802A3E88_7214D8_ptr1 + D_802A3F88_ptr->x,
                              *D_802A3E88_7214D8_ptr2,
                              *D_802A3E88_7214D8_ptr3 + D_802A3F88_ptr->z);
                func_802D43AC(D_802A3F58_ptr[i], N(D_802A3F00_721550)[i], N(D_802A3F00_721550)[i], 1.0f);
                D_802A3E88_7214D8_ptr1 += i * 3 + 0;
                D_802A3E88_7214D8_ptr2 += i * 3 + 1;
                D_802A3E88_7214D8_ptr3 += i * 3 + 2;
            }
            script->functionTemp[0].s = 1;
            script->functionTemp[1].s = gGameStatusPtr->frameCounter % 10;
        }
        break;

        case 1:
            D_802A3F88.x += 6.0f;
            if (gGameStatusPtr->frameCounter % 3 == 0) {
                script->functionTemp[1].s++;
                script->functionTemp[1].s %= 10;
            }

            flag = 0;
            D_802A3F58_ptr = &D_802A3F58;
            D_802A3E88_7214D8_ptr1 = N(D_802A3E88_7214D8);
            D_802A3E88_7214D8_ptr2 = N(D_802A3E88_7214D8);
            D_802A3E88_7214D8_ptr3 = N(D_802A3E88_7214D8);
            for (i = 0; i < 10; i++) {
                f32 x, y, z;

                D_802A3E88_7214D8_ptr1 += i * 3 + 0;
                D_802A3E88_7214D8_ptr2 += i * 3 + 1;
                D_802A3E88_7214D8_ptr3 += i * 3 + 2;

                x = *D_802A3E88_7214D8_ptr1 + D_802A3F88.x;
                y = *D_802A3E88_7214D8_ptr2;
                z = *D_802A3E88_7214D8_ptr3 + D_802A3F88.z;

                func_802D4364(D_802A3F58_ptr[i], x, y, z);

                if (flag == 0 && script->functionTemp[1].s == i) {
                    f32 x2, y2;
                    if (gGameStatusPtr->frameCounter % 5 == 0) {

                        y2 = y;
                        if (x > 0.0f) {
                            x2 = x;
                            if (x > 100.0f) {
                                x2 = x - 50.0f;
                            }
                            y2 = rand_int(x2);
                        }
                        x2 = x;
                        if (x > 40.0f) {
                            x2 = -(x - 40.0f);
                        }
                        fx_walk_large(3, x2, y2, z, 0);
                        flag = 1;
                    }
                }
                D_802A3E88_7214D8_ptr1 += 0xC;
                D_802A3E88_7214D8_ptr2 += 0xC;
                D_802A3E88_7214D8_ptr3 += 0xC;
            }
            if (gGameStatusPtr->frameCounter & 1) {
                s32 randIdx = rand_int(9);
                fx_walk_large(2, N(D_802A3E88_7214D8)[randIdx * 3 + 0] + D_802A3F88_ptr->x,
                              N(D_802A3E88_7214D8)[randIdx * 3 + 1],
                              N(D_802A3E88_7214D8)[randIdx * 3 + 2] + D_802A3F88_ptr->z, 0);
            }
            if (D_802A3F88_ptr->x >= 320.0f) {
                script->functionTemp[0].s = 2;
                break;
            }
            return ApiStatus_DONE2;

        case 2:
            for (i = 0; i < 10; i++) {
                func_802D43F4(*(&D_802A3F58 + i));
            }

            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/sleepy_sheep/lib", battle_item_sleepy_sheep_func_802A123C_71E88C,
            ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus N(func_802A1740_71ED90)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 0x5A;
    }

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);
        ActorPart* targetPart = get_actor_part(targetActor, target->partID);

        if ((targetActor->transStatus == 0) && !(targetPart->eventFlags & 0x20)) {
            targetActor->yaw += 33.0f;
            targetActor->yaw = clamp_angle(targetActor->yaw);
        }
    }

    if (script->functionTemp[1].s != 0) {
        script->functionTemp[1].s--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1848_71EE98)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;
    s32 ret;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    ret = 0;

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);

        if (targetActor != NULL) {
            ActorPart* targetPart = get_actor_part(targetActor, target->partID);
            if ((targetActor->transStatus == 0) && !(targetPart->eventFlags & 0x20)) {
                if (targetActor->yaw < 360.0f) {
                    targetActor->yaw += 33.0f;
                    if (targetActor->yaw >= 360.0f) {
                        targetActor->yaw = 360.0f;
                    }
                    ret = 1;
                }
            }
        }
    }

    return (ret == 0) * ApiStatus_DONE2;
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
