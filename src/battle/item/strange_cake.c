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
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    playFX_40(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A18D8_731BD8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

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

EvtSource N(script6) = {
    EVT_CALL(GetMenuSelection, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_IF_EQ(EVT_VAR(1), 211)
        EVT_SET_CONST(EVT_VAR(10), 0xD3)
        EVT_SET(EVT_VAR(1), 0)
        EVT_EXEC_WAIT(battle_item_strange_cake_UseItemWithEffect)
        EVT_EXEC_WAIT(battle_item_strange_cake_EatItem)
        EVT_CALL(battle_item_strange_cake_func_802A1A8C_731D8C)
        EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 20)
        EVT_ADD(EVT_VAR(1), 25)
        EVT_CALL(battle_item_strange_cake_func_802A18D8_731BD8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 25)
        EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_CALL(battle_item_strange_cake_AddFP, EVT_VAR(3))
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetAnimation, 0, 0, 65586)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(func_802D75D8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_CALL(SetAnimation, 0, 0, 65538)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetAnimation, 0, 0, 65567)
    EVT_ELSE
        EVT_SET_CONST(EVT_VAR(10), 0xD2)
        EVT_SET(EVT_VAR(1), 0)
        EVT_EXEC_WAIT(battle_item_strange_cake_UseItemWithEffect)
        EVT_EXEC_WAIT(battle_item_strange_cake_EatItem)
        EVT_CALL(SetAnimation, 0, 0, 65567)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_THREAD
        EVT_WAIT_FRAMES(220)
        EVT_CALL(PlaySoundAtActor, 0, 1011)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, 0, 872)
    EVT_CALL(battle_item_strange_cake_func_802A13E4_7316E4)
    EVT_WAIT_FRAMES(2)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(battle_item_strange_cake_script7)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(battle_item_strange_cake_script8)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(battle_item_strange_cake_script9)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(battle_item_strange_cake_PlayerGoHome)
    EVT_RETURN
    EVT_END
};

EvtSource N(script7) = {
    EVT_CALL(SetAnimation, 0, 0, 65538)
    EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_CALL(PlayEffect, 87, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(battle_item_strange_cake_func_802A1AD8_731DD8)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ShowMessageBox, 16, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtSource N(script8) = {
    EVT_CALL(SetAnimation, 0, 0, 65538)
    EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_CALL(PlayEffect, 51, 6, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(battle_item_strange_cake_func_802A1B14_731E14)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ShowMessageBox, 17, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtSource N(script9) = {
    EVT_CALL(SetAnimation, 0, 0, 196612)
    EVT_CALL(SetGoalToTarget, 0)
    EVT_CALL(GetGoalPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_EXEC(DoSleepHit)
    EVT_CALL(battle_item_strange_cake_func_802A1B68_731E68)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ShowMessageBox, 11, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

