#include "hos_06.h"
#include "hud_element.h"

extern IconHudScriptPair gItemHudScripts[];

NpcSettings N(NpcSettings_Merluvlee) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Merlow) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#define NAME_SUFFIX _Merlow
#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_MERLOW,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt) = {
    Call(N(LetterDelivery_Init),
        NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle,
        ITEM_LETTER_TO_MERLOW, ITEM_NONE,
        MSG_HOS_0058, MSG_HOS_0059, MSG_HOS_005A, MSG_HOS_005B,
        Ref(N(LetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};
#define NAME_SUFFIX

EvtScript N(EVS_NpcInteract_Merluvlee_Passthrough) = {
    ExecWait(N(EVS_NpcInteract_Merluvlee))
    Return
    End
};

ShopItemData N(MerlowBadgeInventory)[MERLOW_BADGE_COUNT] = {
    { .itemID = ITEM_ATTACK_FX_A,    .price =  1, .descMsg = MSG_ItemShopDesc_AttackFXA },
    { .itemID = ITEM_PAY_OFF,        .price =  1, .descMsg = MSG_ItemShopDesc_PayOff },
    { .itemID = ITEM_CHILL_OUT,      .price =  3, .descMsg = MSG_ItemShopDesc_ChillOut },
    { .itemID = ITEM_PRETTY_LUCKY,   .price =  5, .descMsg = MSG_ItemShopDesc_PrettyLucky },
    { .itemID = ITEM_FEELING_FINE,   .price =  5, .descMsg = MSG_ItemShopDesc_FeelingFine },

    { .itemID = ITEM_HAPPY_HEART_A,  .price =  8, .descMsg = MSG_ItemShopDesc_HappyHeart },
    { .itemID = ITEM_HAPPY_FLOWER_A, .price =  8, .descMsg = MSG_ItemShopDesc_HappyFlower },
    { .itemID = ITEM_PEEKABOO,       .price = 10, .descMsg = MSG_ItemShopDesc_Peekaboo },
    { .itemID = ITEM_ZAP_TAP,        .price = 10, .descMsg = MSG_ItemShopDesc_ZapTap },
    { .itemID = ITEM_HEART_FINDER,   .price = 12, .descMsg = MSG_ItemShopDesc_HeartFinder },

    { .itemID = ITEM_FLOWER_FINDER,  .price = 12, .descMsg = MSG_ItemShopDesc_FlowerFinder },
    { .itemID = ITEM_HP_DRAIN,       .price = 15, .descMsg = MSG_ItemShopDesc_HPDrain },
    { .itemID = ITEM_MONEY_MONEY,    .price = 20, .descMsg = MSG_ItemShopDesc_MoneyMoney },
    { .itemID = ITEM_FLOWER_SAVER_A, .price = 25, .descMsg = MSG_ItemShopDesc_FlowerSaver },
    { .itemID = ITEM_POWER_PLUS_A,   .price = 25, .descMsg = MSG_ItemShopDesc_PowerPlus },
};

API_CALLABLE(N(Merlow_GetPlayerStarPieces)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.starPieces);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Merlow_SetBadgePurchased)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    evt_set_variable(NULL, GF_HOS06_MerlowBadge_00 + index, TRUE);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Merlow_ShopBadgesPopup)) {
    PlayerData* playerData = &gPlayerData;
    PopupMenu* menu;
    s32 selected, menuPos, i;

    if (isInitialCall) {
        script->functionTempPtr[2] = heap_malloc(sizeof(*menu));
        menu = script->functionTempPtr[2];
        menuPos = 0;
        for (i = 0; i < MERLOW_BADGE_COUNT; i++) {
            if (!evt_get_variable(NULL, GF_HOS06_MerlowBadge_00 + i)) {
                ItemData* item = &gItemTable[N(MerlowBadgeInventory)[i].itemID];
                IconHudScriptPair* itemHudScripts = &gItemHudScripts[item->hudElemID];
                menu->userIndex[menuPos] = i;
                menu->nameMsg[menuPos] = item->nameMsg;
                menu->ptrIcon[menuPos] = itemHudScripts->enabled;
                menu->enabled[menuPos] = playerData->starPieces >= N(MerlowBadgeInventory)[i].price;
                if (playerData->starPieces < N(MerlowBadgeInventory)[i].price) {
                    menu->ptrIcon[menuPos] = itemHudScripts->disabled;
                    menu->enabled[menuPos] = FALSE;
                }
                menu->descMsg[menuPos] = N(MerlowBadgeInventory)[i].descMsg;
                menu->value[menuPos] = N(MerlowBadgeInventory)[i].price;
                menuPos++;
            }
        }
        menu->popupType = POPUP_MENU_TRADE_FOR_BADGE;
        menu->numEntries = menuPos;
        menu->initialPos = 0;
        create_standard_popup_menu(menu);
        script->functionTemp[0] = 0;
    }

    menu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] != POPUP_RESULT_CHOOSING) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }
    script->functionTemp[0]++;
    if (script->functionTemp[0] < 20) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    selected = script->functionTemp[1];
    if (selected != POPUP_RESULT_CANCEL) {
        ShopItemData* selectedItem;
        i = menu->userIndex[selected - 1];
        selectedItem = &N(MerlowBadgeInventory)[i];
        script->varTable[0] = selectedItem->itemID;
        script->varTable[1] = selectedItem->price;
        script->varTable[2] = i;
        script->varTable[4] = gItemTable[selectedItem->itemID].nameMsg;
        script->varTable[5] = gMoveTable[gItemTable[selectedItem->itemID].moveID].costBP;
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTempPtr[2]);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_Merlow) = {
    ExecWait(N(EVS_LetterPrompt_Merlow))
    ExecWait(N(EVS_LetterReward_Merlow))
    IfNe(LVarC, 0)
        Return
    EndIf
    IfGe(GB_HOS06_Merlow_PurchaseCount, MERLOW_BADGE_COUNT)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_004C)
        Return
    EndIf
    IfEq(MF_PurchasedBadge, TRUE)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_004D)
    Else
        IfEq(GF_HOS06_Met_Merlow, FALSE)
            Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_004A)
            Set(GF_HOS06_Met_Merlow, TRUE)
        Else
            Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_004B)
        EndIf
    EndIf
    Call(ShowChoice, MSG_Choice_0014)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_004E)
        Return
    EndIf
    Call(N(Merlow_GetPlayerStarPieces), LVar0)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_004F)
        Return
    EndIf
    Call(ContinueSpeech, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0050)
    Label(0)
    Call(N(Merlow_ShopBadgesPopup))
    Wait(10)
    IfEq(LVar0, -1)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0051)
        Return
    EndIf
    Call(N(Merlow_GetPlayerStarPieces), LVar3)
    IfLt(LVar3, LVar1)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0051)
        Goto(0)
    EndIf
    Call(SetMessageText, LVar4, 0)
    Call(SetMessageValue, LVar1, 1)
    Call(SetMessageValue, LVar5, 2)
    IfEq(LVar1, 1)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0053)
    Else
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0052)
    EndIf
    Set(LVar3, LVar0)
    Call(ShowChoice, MSG_Choice_000D)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0054)
        Goto(0)
    EndIf
    Call(CloseMessage)
    Mul(LVar1, -1)
    Call(AddStarPieces, LVar1)
    Add(GB_HOS06_Merlow_PurchaseCount, 1)
    Set(MF_PurchasedBadge, TRUE)
    Call(N(Merlow_SetBadgePurchased), LVar2)
    // awkward
    #define NAME_SUFFIX _Merlow
    EVT_GIVE_BADGE_REWARD_ALT(LVar3, LVar1)
    #define NAME_SUFFIX
    IfGe(GB_HOS06_Merlow_PurchaseCount, MERLOW_BADGE_COUNT)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0055)
        Return
    EndIf
    Call(N(Merlow_GetPlayerStarPieces), LVar0)
    IfLe(LVar0, 0)
        Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0055)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0056)
    Call(ShowChoice, MSG_Choice_000D)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Merlow, ANIM_Merlow_Talk, ANIM_Merlow_Idle, 0, MSG_HOS_0057)
        Return
    EndIf
    Call(CloseMessage)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Merluvlee_Passthrough) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Merluvlee_Passthrough)))
    Exec(N(EVS_NpcInit_Merluvlee))
    Return
    End
};

EvtScript N(EVS_NpcInit_Merlow) = {
    Set(MF_PurchasedBadge, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Merlow)))
    Return
    End
};

NpcData N(NpcData_Merluvlee)[] = {
    {
        .id = NPC_Merluvlee,
        .pos = { 62.0f, 20.0f, 7.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Merluvlee_Passthrough),
        .settings = &N(NpcSettings_Merluvlee),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merluvlee_Idle,
        },
        .tattle = MSG_NpcTattle_Merluvlee,
    },
    {
        .id = NPC_Merlow,
        .pos = { -150.0f, 160.0f, -25.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Merlow),
        .settings = &N(NpcSettings_Merlow),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merlow_Idle,
        },
        .tattle = MSG_NpcTattle_Merlow,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Merluvlee)),
    {}
};
