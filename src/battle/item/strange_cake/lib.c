#include "strange_cake.h"

static HudElement* D_802A2DD0;

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
        D_802A2DD0 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A2DD0, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        free_icon(D_802A2DD0);
    }

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING

extern s32 D_802A25E4;
extern HudElement* D_802A2DF4;
extern s32 D_802A2DD8;

ApiStatus N(func_802A123C_73153C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;
    HudElement** ptr;
    s32 var;
    s32* var2;

    if (D_802A25E4 < 6) {
        if (D_802A25E4 > 0) {
            draw_box(0, 7, 0x6A, 0x56, 0, 0x24, 0x24, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 108, 90, 139, 118);

            ptr = &D_802A2DF4;
            for (i = 0; i < 7; i++) {
                var2 = *ptr;
                var = (D_802A2DD8 / 100) - 0x68;
                ptr++;
                set_icon_render_pos(var2, 0x7C, (i * 0x1A) - var);
                draw_icon_2(var2);
            }

            var2 = D_802A2DF4;
            var = (D_802A2DD8 / 100) - 0x68;
            set_icon_render_pos(var2, 0x7C, (i * 0x1A) - var);
            draw_icon_2(var2);
        }
    }
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/strange_cake/lib", battle_item_strange_cake_func_802A123C_73153C);
#endif

#ifdef NON_MATCHING

extern s32 D_802A2DEC;
extern s32 D_802A2DF0;
extern s32 D_802A2DF4;
extern s32 D_802A2DF8;
extern s32 D_802A2DFC;
extern s32 D_802A2E00;
extern s32* D_802A2DD8;
extern HudElement** D_802A25C8;

s32 N(D_802A2848_732B48)[] = {
    0x802A27F8, 0x802A2820, 0x802A27D0, 0x802A27F8
};

s32 N(D_802A2858_732B58)[] = {
    0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001
};

ApiStatus N(func_802A13E4_7316E4)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        D_802A2DEC = 0;
    }

    switch (D_802A2DEC) {
        case 0: {
            s32 i;
            HudElement** iconPtr;

            D_802A2E00 = create_dynamic_entity_frontUI(NULL, func_802A123C_73153C);
            i = rand_int(13000);
            D_802A2DF4 = i;

            D_802A2DF8 = 1000;

            for (i = 0; i < 5; i++) {
                s32* B48Ptr = &N(D_802A2848_732B48);
                s32* B58Ptr = &N(D_802A2858_732B58);
                HudElement* icon = create_icon(*(B48Ptr + * (B58Ptr + i)));

                *(&D_802A2DD8 + i) = icon;
                set_icon_flags(icon, 0x80);
            }
            D_802A2DEC = 1;
        }
        break;

        case 1: {
            s32* ECptr = &D_802A2DF4;
            s32* F0ptr = &D_802A2DF8;

            *ECptr += *F0ptr;
            if (*ECptr / 100 >= 130) {
                s32* test = ECptr;
                *test -= 0x32C8;
            }

            if (*F0ptr > 400) {
                *F0ptr -= 10;
            } else if (*F0ptr > 100) {
                *F0ptr -= 5;
            } else {
                *F0ptr -= 1;
            }

            if (D_802A2DF8 < 10) {
                D_802A2DF0 = D_802A2DF4 / 100;
                if (D_802A2DF0 % 26 < 13) {
                    if (rand_int(100) < 80) {
                        D_802A2DEC = 2;
                    } else {
                        D_802A2DEC = 3;
                    }
                } else if (rand_int(100) < 60) {
                    D_802A2DEC = 3;
                } else {
                    D_802A2DEC = 2;
                }
            }
        }
        break;

        case 2: {
            s32* E8ptr = &D_802A2DF0;
            s32 a, b, c, d;

            d = *E8ptr % 26;
            a = d;
            c = a + 3;
            if (c < 0) {
                c = a + 6;
            }
            d = c >> 2;
            *E8ptr -= d;
            D_802A2DF4 = *E8ptr * 100;
            if (d == 0) {
                D_802A2DEC = 4;
            }
        }
        break;

        case 3: {
            s32* E8ptr = &D_802A2DF0;
            s32 a, b, c, d;

            d = *E8ptr % 26;
            if (d == 0) {
                D_802A2DEC = 4;
                break;
            }
            a = d;
            b = 26;
            b -= a;
            c = b + 3;
            if (c < 0) {
                c = b + 6;
            }
            c = c >> 2;
            *E8ptr += c;
            D_802A2DF4 = *E8ptr * 100;
        }
        break;

        case 4: {
            D_802A2DFC = 20;
            D_802A2DEC = 5;
        }
        break;

        case 5: {
            s32* F4ptr = &D_802A2DFC;
            s32 i;
            s16 g;
            HudElement** iconPtr;

            if (*F4ptr != 0) {
                *F4ptr -= 1;
                break;
            }
            iconPtr = &D_802A25C8;
            i = D_802A2DF0 / 26;
            g = N(D_802A2858_732B58)[i];
            battleStatus->selectedItemID = g;
            script->varTable[0] = g;
            free_dynamic_entity(D_802A2E00);
            for (i = 0; i < 5; i++) {
                free_icon(*iconPtr++);
            }
        }
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/strange_cake/lib", battle_item_strange_cake_func_802A13E4_7316E4,
            ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus N(func_802A1818_731B18)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    func_80071090(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A18D8_731BD8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    func_80071090(1, a, b, c, d);
    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

ApiStatus N(func_802A1A40_731D40)(ScriptInstance* script, s32 isInitialCall) {
    StaticItem* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1A8C_731D8C)(ScriptInstance* script, s32 isInitialCall) {
    StaticItem* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curFP += item->potencyB;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }

    script->varTable[3] = item->potencyB;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1AD8_731DD8)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_STATIC, 3);
    player->status = 0;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1B14_731E14)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_E, 3);
    player->status = 0;
    part->flags |= 0x100;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1B68_731E68)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_SLEEP, 3);
    player->status = 0;

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
