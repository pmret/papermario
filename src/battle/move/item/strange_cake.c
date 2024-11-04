#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "hud_element.h"
#include "sprite/player.h"
#include "include_asset.h"

#define NAMESPACE battle_item_strange_cake

#include "battle/common/move/ItemRefund.inc.c"
#include "battle/common/move/UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/move/item/strange_cake1.png.h"
INCLUDE_IMG("battle/move/item/strange_cake1.png", battle_item_strange_cake1_png);
INCLUDE_PAL("battle/move/item/strange_cake1.pal", battle_item_strange_cake1_pal);

#include "battle/move/item/strange_cake2.png.h"
INCLUDE_IMG("battle/move/item/strange_cake2.png", battle_item_strange_cake2_png);
INCLUDE_PAL("battle/move/item/strange_cake2.pal", battle_item_strange_cake2_pal);

#include "battle/move/item/strange_cake3.png.h"
INCLUDE_IMG("battle/move/item/strange_cake3.png", battle_item_strange_cake3_png);
INCLUDE_PAL("battle/move/item/strange_cake3.pal", battle_item_strange_cake3_pal);

HudScript N(D_802A27D0) = HES_TEMPLATE_CI_ENUM_SIZE(battle_item_strange_cake1, 32, 32);
HudScript N(D_802A27F8) = HES_TEMPLATE_CI_ENUM_SIZE(battle_item_strange_cake2, 32, 32);
HudScript N(D_802A2820) = HES_TEMPLATE_CI_ENUM_SIZE(battle_item_strange_cake3, 32, 32);

HudScript* N(D_802A2848_732B48)[] = {
    &N(D_802A27F8), &N(D_802A2820), &N(D_802A27D0), &N(D_802A27F8)
};

// indexes into D_802A2848_732B48
s32 N(D_802A2858_732B58)[] = {
    0, 1, 2, 0, 1, 0
};

BSS s32 D_802A2DD4; // unused?
BSS s32 D_802A2DD8[5];
BSS s32 D_802A2DEC;
BSS s32 D_802A2DF0;
BSS s32 D_802A2DF4;
BSS s32 D_802A2DF8;
BSS s32 D_802A2DFC;
BSS s32 D_802A2E00;

void N(func_802A123C_73153C(void)) {
    s32 var_s3;
    s32 id;
    s32 i;

    if (D_802A2DEC < 6) {
        if (D_802A2DEC > 0) {
            draw_box(0, WINDOW_STYLE_7, 106, 86, 0, 36, 36, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 108, 90, 139, 118);

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

API_CALLABLE(N(func_802A13E4_7316E4)) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 temp_a0_4;
    s32 temp_v1_3;
    s32 var_v0_2;
    s32 var_v0_3;
    HudElemID hid;
    s32 i;

    if (isInitialCall) {
        D_802A2DEC = 0;
    }

    switch (D_802A2DEC) {
        case 0:
            D_802A2E00 = create_worker_frontUI(NULL, N(func_802A123C_73153C));
            D_802A2DF4 = rand_int(13000);
            D_802A2DF8 = 1000;

            for (i = 0; i < ARRAY_COUNT(D_802A2DD8); i++) {
                hid = hud_element_create(N(D_802A2848_732B48)[N(D_802A2858_732B58)[i]]);
                D_802A2DD8[i] = hid;
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80);
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
            battleStatus->moveArgument = N(D_802A2858_732B58)[var_v0_3];
            script->varTable[0] = battleStatus->moveArgument;
            free_worker(D_802A2E00);
            for (i = 0; i < ARRAY_COUNT(D_802A2DD8); i++) {
                hud_element_free(D_802A2DD8[i]);
            }
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SpawnHeartRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnFlowerRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);
    return ApiStatus_DONE2;
}

#if !VERSION_PAL
#include "common/AddHP.inc.c"
#include "common/AddFP.inc.c"

API_CALLABLE(N(func_802A1A40_731D40)) {
    ItemData* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}
#endif

API_CALLABLE(N(func_802A1A8C_731D8C)) {
    ItemData* item = &gItemTable[ITEM_KOOKY_COOKIE];
    PlayerData* playerData = &gPlayerData;

    playerData->curFP += item->potencyB;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }

    script->varTable[3] = item->potencyB;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A1AD8_731DD8)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_KEY_STATIC, 3);
    player->statusAfflicted = 0;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A1B14_731E14)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_KEY_TRANSPARENT, 3);
    player->statusAfflicted = 0;
    part->flags |= ACTOR_PART_FLAG_TRANSPARENT;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A1B68_731E68)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_KEY_SLEEP, 3);
    player->statusAfflicted = 0;

    return ApiStatus_DONE2;
}

extern EvtScript N(script7);
extern EvtScript N(script8);
extern EvtScript N(script9);

EvtScript N(EVS_UseItem) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    IfEq(LVar1, ITEM_KOOKY_COOKIE)
        SetConst(LVarA, ITEM_KOOKY_COOKIE)
        Set(LVar1, 0)
        ExecWait(N(UseItemWithEffect))
        ExecWait(N(EatItem))
        Call(N(func_802A1A8C_731D8C))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 20)
        Add(LVar1, 25)
        Call(N(SpawnFlowerRecoveryFX), LVar0, LVar1, LVar2, LVar3)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 25)
        Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
#if !VERSION_PAL
        Call(N(AddFP), LVar3)
#endif
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
        Wait(30)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    Else
        SetConst(LVarA, ITEM_STRANGE_CAKE)
        Set(LVar1, 0)
        ExecWait(N(UseItemWithEffect))
        ExecWait(N(EatItem))
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    EndIf
    Wait(10)
    Thread
        Wait(220)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_DING)
    EndThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MYSTERY_REEL)
    Call(N(func_802A13E4_7316E4))
    Wait(2)
    Switch(LVar0)
        CaseEq(0)
            ExecWait(N(script7))
        CaseEq(1)
            ExecWait(N(script8))
        CaseEq(2)
            ExecWait(N(script9))
    EndSwitch
    ExecWait(N(PlayerGoHome))
    Return
    End
};

EvtScript N(script7) = {
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(1.0), 30, 0)
    Call(N(func_802A1AD8_731DD8))
    Wait(20)
    Call(ShowMessageBox, BTL_MSG_PLAYER_CHARGED, 60)
    Call(WaitForMessageBoxDone)
    Return
    End
};

EvtScript N(script8) = {
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, Float(1.0), 30, 0)
    Call(N(func_802A1B14_731E14))
    Wait(20)
    Call(ShowMessageBox, BTL_MSG_PLAYER_TRANSPARENT, 60)
    Call(WaitForMessageBoxDone)
    Return
    End
};

EvtScript N(script9) = {
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Sleep)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Exec(EVS_PlaySleepHitFX)
    Call(N(func_802A1B68_731E68))
    Wait(20)
    Call(ShowMessageBox, BTL_MSG_PLAYER_ASLEEP, 60)
    Call(WaitForMessageBoxDone)
    Return
    End
};

