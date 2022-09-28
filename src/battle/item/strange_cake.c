#include "strange_cake.h"
#include "effects.h"
#include "pause/pause_common.h"
#include "hud_element.h"
#include "battle/item/strange_cake1.png.h"
#include "battle/item/strange_cake2.png.h"
#include "battle/item/strange_cake3.png.h"

#include "ItemRefund.inc.c"

extern HudScript* N(D_802A2848_732B48)[];
extern s32 N(D_802A2858_732B58)[];

extern s32 D_802A2DD8[5];
extern s32 D_802A2DE4;
extern s32 D_802A2DEC;
extern s32 D_802A2DF0;
extern s32 D_802A2DF4;
extern s32 D_802A2DF8;
extern s32 D_802A2DFC;
extern s32 D_802A2E00;

void N(func_802A123C_73153C(void)) {
    s32 var_s3;
    s32 id;
    s32 i;

    if (D_802A2DEC < 6) {
        if (D_802A2DEC > 0) {
            draw_box(0, 7, 106, 86, 0, 36, 36, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 108, 90, 139, 118);

            for (i = 0; i < ARRAY_COUNT(D_802A2DD8); i++) {
                id = D_802A2DD8[i];
                hud_element_set_render_pos(id, 124, (i * 26) + 104 - (D_802A2DF4 / 100));
                hud_element_draw_without_clipping(id);
            }
            id = D_802A2DD8[0];
            hud_element_set_render_pos(id, 124, (i * 26) + 104 - (D_802A2DF4 / 100));
            hud_element_draw_without_clipping(id);
        }
    }
}

s32 N(func_802A13E4_7316E4)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 temp_a0_4;
    s32 temp_v1_3;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 id;
    s32 i;

    if (isInitialCall) {
        D_802A2DEC = 0;
    }

    switch (D_802A2DEC) {
        case 0:
            D_802A2E00 = create_generic_entity_frontUI(NULL, N(func_802A123C_73153C));
            D_802A2DF4 = rand_int(13000);
            D_802A2DF8 = 1000;

            for (i = 0; i < ARRAY_COUNT(D_802A2DD8); i++) {
                id = hud_element_create(N(D_802A2848_732B48)[N(D_802A2858_732B58)[i]]);
                D_802A2DD8[i] = id;
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            }
            D_802A2DEC = 1;

            return ApiStatus_BLOCK;
        case 1:
            D_802A2DF4 += D_802A2DF8;
            if (D_802A2DF4 / 100 >= 130) {
                D_802A2DF4 -= 13000;
            }

            if (D_802A2DF8 > 400) {
                D_802A2DF8 -= 10;
            } else if (D_802A2DF8 > 100) {
                D_802A2DF8 -= 5;
            } else {
                D_802A2DF8 -= 1;
            }

            if (D_802A2DF8 < 10) {
                D_802A2DF0 = D_802A2DF4 / 100;

                if (((D_802A2DF4 / 100) % 26) < 13) {
                    if (rand_int(100) < 80) {
                        D_802A2DEC = 2;
                    } else {
                        D_802A2DEC = 3;
                    }
                    break;
                }

                if (rand_int(100) < 60) {
                    D_802A2DEC = 3;
                } else {
                    D_802A2DEC = 2;
                }
            }
            break;
        case 2:
            temp_a0_4 = D_802A2DF0 % 26;
            var_v0_2 = temp_a0_4 + 3;
            if (var_v0_2 < 0) {
                var_v0_2 += 3;
            }
            temp_a0_4 = var_v0_2 >> 2;
            D_802A2DF0 -= temp_a0_4;
            D_802A2DF4 = D_802A2DF0 * 100;
            if (temp_a0_4 == 0) {
                D_802A2DEC = 4;
            }
            break;
        case 3:
            temp_v1_3 = D_802A2DF0 % 26;
            if (temp_v1_3 == 0) {
                D_802A2DEC = 4;
                break;
            }
            temp_a0_4 = 26 - temp_v1_3;
            var_v0_3 = temp_a0_4 + 3;
            if (var_v0_3 < 0) {
                var_v0_3 += 3;
            }
            temp_a0_4 = var_v0_3 >> 2;
            D_802A2DF0 += temp_a0_4;
            D_802A2DF4 = D_802A2DF0 * 100;
            break;
        case 4:
            D_802A2DFC = 20;
            D_802A2DEC = 5;
            break;
        case 5:
            if (D_802A2DFC != 0) {
                D_802A2DFC--;
                break;
            }

            var_v0_3 = i = D_802A2DF0 / 26; // use of i required to match
            battleStatus->selectedItemID = N(D_802A2858_732B58)[var_v0_3];
            script->varTable[0] = battleStatus->selectedItemID;
            free_generic_entity(D_802A2E00);
            for (i = 0; i < ARRAY_COUNT(D_802A2DD8); i++) {
                hud_element_free(D_802A2DD8[i]);
            }
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(func_802A1818_731B18)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A18D8_731BD8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);
    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

ApiStatus N(func_802A1A40_731D40)(Evt* script, s32 isInitialCall) {
    ItemData* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1A8C_731D8C)(Evt* script, s32 isInitialCall) {
    ItemData* item = &gItemTable[ITEM_KOOKY_COOKIE];
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

    inflict_status(player, STATUS_TRANSPARENT, 3);
    player->status = 0;
    part->flags |= ACTOR_PART_FLAG_100;

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

HudScript N(D_802A27D0) = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_32x32, HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32) battle_item_strange_cake1_png, (s32) battle_item_strange_cake1_pal,
    0x00000003,
    HUD_ELEMENT_OP_End,
};

HudScript N(D_802A27F8) = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_32x32, HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32) battle_item_strange_cake2_png, (s32) battle_item_strange_cake2_pal,
    0x00000003,
    HUD_ELEMENT_OP_End,
};

HudScript N(D_802A2820) = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_32x32,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32) battle_item_strange_cake3_png, (s32) battle_item_strange_cake3_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript* N(D_802A2848_732B48)[] = {
    &N(D_802A27F8), &N(D_802A2820), &N(D_802A27D0), &N(D_802A27F8)
};

// indexes into D_802A2848_732B48
s32 N(D_802A2858_732B58)[] = {
    0, 1, 2, 0, 1, 0
};

EvtScript N(script6) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar1, 211)
        EVT_SET_CONST(LVarA, 0xD3)
        EVT_SET(LVar1, 0)
        EVT_EXEC_WAIT(battle_item_strange_cake_UseItemWithEffect)
        EVT_EXEC_WAIT(battle_item_strange_cake_EatItem)
        EVT_CALL(battle_item_strange_cake_func_802A1A8C_731D8C)
        EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_ADD(LVar1, 25)
        EVT_CALL(battle_item_strange_cake_func_802A18D8_731BD8, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(battle_item_strange_cake_AddFP, LVar3)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, 0, 0, 65586)
        EVT_WAIT(30)
        EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
        EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(SetAnimation, 0, 0, 65538)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, 0, 0, 65567)
    EVT_ELSE
        EVT_SET_CONST(LVarA, 0xD2)
        EVT_SET(LVar1, 0)
        EVT_EXEC_WAIT(battle_item_strange_cake_UseItemWithEffect)
        EVT_EXEC_WAIT(battle_item_strange_cake_EatItem)
        EVT_CALL(SetAnimation, 0, 0, 65567)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(220)
        EVT_CALL(PlaySoundAtActor, 0, 1011)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, 0, 872)
    EVT_CALL(battle_item_strange_cake_func_802A13E4_7316E4)
    EVT_WAIT(2)
    EVT_SWITCH(LVar0)
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

EvtScript N(script7) = {
    EVT_CALL(SetAnimation, 0, 0, 65538)
    EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlayEffect, 87, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(battle_item_strange_cake_func_802A1AD8_731DD8)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, 16, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtScript N(script8) = {
    EVT_CALL(SetAnimation, 0, 0, 65538)
    EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlayEffect, 51, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(battle_item_strange_cake_func_802A1B14_731E14)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, 17, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtScript N(script9) = {
    EVT_CALL(SetAnimation, 0, 0, 196612)
    EVT_CALL(SetGoalToTarget, 0)
    EVT_CALL(GetGoalPos, 0, LVar0, LVar1, LVar2)
    EVT_EXEC(DoSleepHit)
    EVT_CALL(battle_item_strange_cake_func_802A1B68_731E68)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, 11, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

