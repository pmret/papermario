#include "kkj_17.h"
#include "hud_element.h"
#include "sprite/player.h"

extern IconHudScriptPair gItemHudScripts[];

// ------------------------------------------------------
// begin modified Chest.inc.c
// differences are:
// - inclusion of N(ChestItems)
// - removal of N(EVS_Chest_GetItem)

#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = NULL;

EvtScript N(EVS_Chest_ShowGotItem) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
    EVT_WAIT(40)
    EVT_CALL(ShowGotItem, LVar0, FALSE, 0)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

s32 N(ChestItems)[] = {
    ITEM_POWER_RUSH,
    ITEM_SHOOTING_STAR,
    ITEM_DEEP_FOCUS1,
    ITEM_LAST_STAND,
    ITEM_JAMMIN_JELLY,
};

// end modified Chest.inc.c
// ------------------------------------------------------

//TODO this whole file is probably an include shared with kkj_17, but the temp required in this function prevents deduplication
API_CALLABLE(N(ChestItemPrompt)) {
    PopupMenu *menu;
    s32 menuIdx;
    s32 selectIdx;
    s32 canUseItem;
    s32 itemUsedBefore;
    s32 i;

    if (isInitialCall) {
        menu = heap_malloc(sizeof(*menu));
        script->functionTempPtr[2] = menu;
        script->varTable[10] = script->varTable[0];

        // NOTE: identical to ChestItemPrompt in hos_06 EXCEPT here, where varTable[0] is required instead of varTable[10]
        if (script->varTable[0] == 0) {
            // storing items
            script->varTable[1] = GF_KKJ16_Item_PowerRush;
            script->varTable[2] = GF_KKJ_Stored_PowerRush;
            menu->popupType = POPUP_MENU_USEKEY;
        } else {
            // retrieving items
            script->varTable[1] = GF_KKJ_Stored_PowerRush;
            script->varTable[2] = GF_KKJ_Retrieved_PowerRush;
            menu->popupType = POPUP_MENU_TAKE_FROM_CHEST;
        }

        menuIdx = 0;
        for (i = 0; i < ARRAY_COUNT(N(ChestItems)); i++) {
            // meaning of 'can use' and 'used before' depends on type of chest interaction
            canUseItem = evt_get_variable(NULL, script->varTable[1] + i);
            itemUsedBefore = evt_get_variable(NULL, script->varTable[2] + i);
            if (canUseItem && !itemUsedBefore) {
                ItemData* item = &gItemTable[N(ChestItems)[i]];
                IconHudScriptPair* itemHudScripts = &gItemHudScripts[item->hudElemID];
                menu->ptrIcon[menuIdx] = itemHudScripts->enabled;
                menu->userIndex[menuIdx] = i;
                menu->enabled[menuIdx] = TRUE;
                menu->nameMsg[menuIdx] = item->nameMsg;
                menu->descMsg[menuIdx] = item->shortDescMsg;
                menuIdx++;
            }
        }

        if (menuIdx == 0) {
            script->varTable[0] = 0;
            return ApiStatus_DONE1;
        }

        menu->numEntries = menuIdx;
        menu->initialPos = 0;
        create_standard_popup_menu(menu);
        script->functionTemp[0] = 0;
    }

    menu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] == POPUP_RESULT_CHOOSING) {
            return ApiStatus_BLOCK;
        }
        hide_popup_menu();
    }

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 15) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();

    if (script->functionTemp[1] == POPUP_RESULT_CANCEL) {
        script->varTable[0] = -1;
    } else {
        selectIdx = menu->userIndex[script->functionTemp[1] - 1];
        script->varTable[0] = N(ChestItems)[selectIdx];
        if (script->varTable[10] == 0) {
            evt_set_variable(NULL, script->varTable[2] + selectIdx, 1);
        }
        heap_free(script->functionTempPtr[2]);
    }

    return ApiStatus_DONE2;
}

// assumes itemID on LVar0, sets GF_KKJ_Retrieved_* based on item list position
API_CALLABLE(N(SetItemRetrieved)) {
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(N(ChestItems)); i++) {
        s32 listItemID = N(ChestItems)[i];

        if (script->varTable[0] == listItemID) {
            found = TRUE;
            break;
        }
    }

    if (found) {
        evt_set_variable(NULL, GF_KKJ_Retrieved_PowerRush + i, TRUE);
    }

    return ApiStatus_DONE2;
}

#include "world/common/todo/GetItemEmptyCount.inc.c"

EvtScript N(EVS_OpenChest) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o89, SOUND_OPEN_MAGIC_CHEST, 0)
    EVT_CALL(MakeLerp, 0, 80, 20, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g21, LVar0, -1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseChest) = {
    EVT_CALL(MakeLerp, 80, 0, 20, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g21, LVar0, -1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o89, SOUND_CLOSE_MAGIC_CHEST, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FindMagicChest) = {
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_018E)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToNpc, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, NPC_PARTNER, MSG_Peach_018F)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0190)
    EVT_CALL(SpeakToNpc, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, NPC_PARTNER, MSG_Peach_0191)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0192)
    EVT_CALL(SpeakToNpc, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, NPC_PARTNER, MSG_Peach_0193)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMagicChest_Peach) = {
    EVT_SET(LVar0, 0)
    EVT_CALL(N(ChestItemPrompt))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
        EVT_CASE_EQ(0)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0194)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
            EVT_CALL(SpeakToNpc, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, NPC_PARTNER, MSG_Peach_0195)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0196)
            EVT_CALL(SpeakToNpc, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, NPC_PARTNER, MSG_Peach_0197)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
        EVT_CASE_DEFAULT
            EVT_WAIT(10)
            EVT_SET(LVar9, LVar0)
            EVT_EXEC_WAIT(N(EVS_OpenChest))
            EVT_CALL(N(GetItemName), LVar9)
            EVT_CALL(SetMessageText, LVar9, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_0198, 160, 40)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_CloseChest))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMagicChest_Mario) = {
    EVT_EXEC_WAIT(N(EVS_OpenChest))
    EVT_SET(LVar0, 1)
    EVT_CALL(N(ChestItemPrompt))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D4, 160, 40)
        EVT_CASE_OR_EQ(269)
        EVT_CASE_OR_EQ(297)
        EVT_CASE_OR_EQ(273)
            EVT_SET_GROUP(EVT_GROUP_00)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
            EVT_CALL(ShowGotItem, LVar0, FALSE, 0)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_CALL(AddBadge, LVar0, LVar1)
            EVT_CALL(N(SetItemRetrieved))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(N(GetItemEmptyCount))
            EVT_IF_LE(LVar1, 0)
                EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D5, 160, 40)
            EVT_ELSE
                EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_ANIMS)
                EVT_CALL(AddItem, LVar0, LVar1)
                EVT_CALL(N(SetItemRetrieved))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_CloseChest))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_MagicChest) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_IF_EQ(GF_KKJ17_FoundMagicChest, FALSE)
            EVT_EXEC_WAIT(N(EVS_FindMagicChest))
            EVT_SET(GF_KKJ17_FoundMagicChest, TRUE)
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_UseMagicChest_Peach))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_UseMagicChest_Mario))
    EVT_END_IF
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMagicChest) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_MagicChest)), TRIGGER_WALL_PRESS_A, COLLIDER_o89, 1, 0)
    EVT_RETURN
    EVT_END
};
