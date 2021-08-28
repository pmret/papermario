#include "strange_cake.h"
#include "effects.h"
#include "battle/item/strange_cake1.png.h"
#include "battle/item/strange_cake2.png.h"
#include "battle/item/strange_cake3.png.h"

#include "ItemRefund.inc.c"

#ifdef NON_MATCHING

extern s32 D_802A25E4;
extern HudElement* D_802A2DF4;
extern s32 D_802A2DD8;

ApiStatus N(func_802A123C_73153C)(Evt* script, s32 isInitialCall) {
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
                set_hud_element_render_pos(var2, 0x7C, (i * 0x1A) - var);
                draw_hud_element_3(var2);
            }

            var2 = D_802A2DF4;
            var = (D_802A2DD8 / 100) - 0x68;
            set_hud_element_render_pos(var2, 0x7C, (i * 0x1A) - var);
            draw_hud_element_3(var2);
        }
    }
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/strange_cake", battle_item_strange_cake_func_802A123C_73153C);
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

ApiStatus N(func_802A13E4_7316E4)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        D_802A2DEC = 0;
    }

    switch (D_802A2DEC) {
        case 0: {
            s32 i;
            HudElement** iconPtr;

            D_802A2E00 = create_generic_entity_frontUI(NULL, func_802A123C_73153C);
            i = rand_int(13000);
            D_802A2DF4 = i;

            D_802A2DF8 = 1000;

            for (i = 0; i < 5; i++) {
                s32* B48Ptr = &N(D_802A2848_732B48);
                s32* B58Ptr = &N(D_802A2858_732B58);
                HudElement* icon = create_hud_element(*(B48Ptr + * (B58Ptr + i)));

                *(&D_802A2DD8 + i) = icon;
                set_hud_element_flags(icon, 0x80);
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
            free_generic_entity(D_802A2E00);
            for (i = 0; i < 5; i++) {
                free_hud_element(*iconPtr++);
            }
        }
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/strange_cake", battle_item_strange_cake_func_802A13E4_7316E4,
            Evt* script, s32 isInitialCall);
#endif

ApiStatus N(func_802A1818_731B18)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    playFX_40(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A18D8_731BD8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    playFX_40(1, a, b, c, d);
    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

ApiStatus N(func_802A1A40_731D40)(Evt* script, s32 isInitialCall) {
    StaticItem* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1A8C_731D8C)(Evt* script, s32 isInitialCall) {
    StaticItem* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curFP += item->potencyB;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }

    script->varTable[3] = item->potencyB;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1AD8_731DD8)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_STATIC, 3);
    player->status = 0;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1B14_731E14)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_E, 3);
    player->status = 0;
    part->flags |= 0x100;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1B68_731E68)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_SLEEP, 3);
    player->status = 0;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/item/strange_cake1.png.inc.c"
#include "battle/item/strange_cake1.pal.inc.c"
#include "battle/item/strange_cake2.png.inc.c"
#include "battle/item/strange_cake2.pal.inc.c"
#include "battle/item/strange_cake3.png.inc.c"
#include "battle/item/strange_cake3.pal.inc.c"

s32 N(data)[] = {
    0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x00000002, 0x0000003C, 0x802A2170, 0x802A2370,
    0x00000003, 0x00000000, 0x00000008, 0x00000005,
    0x00000003, 0x00000004, 0x00000002, 0x0000003C,
    0x802A2390, 0x802A2590, 0x00000003, 0x00000000,
    0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x00000002, 0x0000003C, 0x802A25B0, 0x802A27B0,
    0x00000003, 0x00000000
};

s32 N(D_802A2848_732B48)[] = {
    0x802A27F8, 0x802A2820, 0x802A27D0, 0x802A27F8
};

s32 N(D_802A2858_732B58)[] = {
    0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x000000000
};

EvtSource N(script6) = SCRIPT({
    GetMenuSelection(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    if (EVT_VAR(1) == 211) {
        EVT_VAR(10) = (const) ITEM_KOOKY_COOKIE;
        EVT_VAR(1) = 0;
        await N(UseItemWithEffect);
        await N(EatItem);
        N(func_802A1A8C_731D8C)();
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(0) += 20;
        EVT_VAR(1) += 25;
        N(func_802A18D8_731BD8)(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 25;
        func_802D7520(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        N(AddFP)(EVT_VAR(3));
        sleep 10;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
        sleep 30;
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        func_802D75D8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
        sleep 20;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
    } else {
        EVT_VAR(10) = (const) ITEM_STRANGE_CAKE;
        EVT_VAR(1) = 0;
        await N(UseItemWithEffect);
        await N(EatItem);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
    }
    sleep 10;
    spawn {
        sleep 220;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_3F3);
    }
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_368);
    N(func_802A13E4_7316E4)();
    sleep 2;
    match EVT_VAR(0) {
        == 0 {
            await N(script7);
        }
        == 1 {
            await N(script8);
        }
        == 2 {
            await N(script9);
        }
    }
    await N(PlayerGoHome);
});

EvtSource N(script7) = SCRIPT({
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 20;
    PlayEffect(0x57, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A1AD8_731DD8)();
    sleep 20;
    ShowMessageBox(16, 60);
    WaitForMessageBoxDone();
});

EvtSource N(script8) = SCRIPT({
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 20;
    PlayEffect(0x33, 6, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A1B14_731E14)();
    sleep 20;
    ShowMessageBox(17, 60);
    WaitForMessageBoxDone();
});

EvtSource N(script9) = SCRIPT({
    SetAnimation(ACTOR_PLAYER, 0, ANIM_30004);
    SetGoalToTarget(ACTOR_PLAYER);
    GetGoalPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    spawn DoSleepHit;
    N(func_802A1B68_731E68)();
    sleep 20;
    ShowMessageBox(11, 60);
    WaitForMessageBoxDone();
});

