#include "mac_04.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 20

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 mac_04_D_8024F5D0[];

ApiStatus func_802417AC_84437C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_04_D_8024F5D0[i] = ptr[i];
        }
        mac_04_D_8024F5D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_04_D_8024F5D0[i] = i + 16;
            mac_04_D_8024F5D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

s32 func_80241848_844418(void) {
    s32 bpCost = 0;
    s32 i = 0;
    ItemData* itemTable = gItemTable;

    for (; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
        s16 badge = gPlayerData.equippedBadges[i];

        if (badge != 0) {
            bpCost += gMoveTable[itemTable[badge].moveID].costBP;
        }
    }
    return bpCost;
}

ApiStatus func_802418AC_84447C(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 bpCost = func_80241848_844418();
    s32 i;

    if (gPlayerData.maxBP >= bpCost) {
        evt_set_variable(script, outVar, FALSE);
        return ApiStatus_DONE2;
    } else {
        s16* badges = gPlayerData.equippedBadges;

        for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
            badges[i] = 0;
        }
        enforce_hpfp_limits();
        evt_set_variable(script, outVar, TRUE);
        return ApiStatus_DONE2;
    }
}

ApiStatus PostChapter4StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetFloorCollider.inc.c"

ApiStatus N(IsPartnerBow)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetPlayerCoins.inc.c"

ApiStatus func_802419E4_8445B4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 out1 = *args++;
    s32 out2 = *args++;
    s32 out3 = *args++;

    evt_set_variable(script, out1, gPlayerData.hardMaxHP);
    evt_set_variable(script, out2, gPlayerData.hardMaxFP);
    evt_set_variable(script, out3, gPlayerData.maxBP);
    return ApiStatus_DONE2;
}

ApiStatus func_80241A64_844634(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 bp = 0;
    s32 fp = 0;
    s32 hp = 0;

    switch (script->varTable[10]) {
        case 0:
            hp = 10;
            fp = -5;
            bp = -3;
            break;
        case 1:
            hp = -5;
            fp = 10;
            bp = -3;
            break;
        case 2:
            hp = -5;
            fp = -5;
            bp = 6;
            break;
    }

    playerData->hardMaxHP += hp;
    playerData->curMaxHP += hp;
    if (playerData->curMaxHP > 75) {
        playerData->curMaxHP = 75;
    }
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    playerData->hardMaxFP += fp;
    playerData->curMaxFP += fp;
    if (playerData->curMaxFP > 75) {
        playerData->curMaxFP = 75;
    }
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    playerData->maxBP += bp;
    if (playerData->maxBP > 30) {
        playerData->maxBP = 30;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80241B90_844760(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = playerData->curMaxHP;
    script->varTable[1] = playerData->curMaxFP;
    script->varTable[2] = playerData->maxBP;
    return ApiStatus_DONE2;
}

ApiStatus N(SetNpcShadowScale)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

ApiStatus N(80241C20_8447F0)(Evt* script, s32 isInitialCall) {
    func_800E9894();
    return ApiStatus_DONE2;
}

ApiStatus func_80241C40_844810(Evt* script, s32 isInitialCall) {
    func_800E98C4();
    return ApiStatus_DONE2;
}

ApiStatus func_80241C60_844830(Evt* script, s32 isInitialCall) {
    func_800E98C4();
    open_status_menu_long();
    return ApiStatus_DONE2;
}
