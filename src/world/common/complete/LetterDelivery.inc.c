#include "common.h"
#include "sprite/npc/WorldParakarry.h"

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"

enum DeliveryResult {
    DELIVERY_NOT_POSSIBLE   = 0,
    DELIVERY_REJECTED       = 1,
    DELIVERY_ACCEPTED       = 2,
};

BSS s32 N(LetterDelivery_SavedNpcAnim);

API_CALLABLE(N(LetterDelivery_Init)) {
    Bytecode* args = script->ptrReadPos;

    script->varTable[2] = evt_get_variable(script, *args++);
    script->varTable[3] = evt_get_variable(script, *args++);
    script->varTable[4] = evt_get_variable(script, *args++);
    script->varTable[5] = evt_get_variable(script, *args++);
    script->varTable[6] = evt_get_variable(script, *args++);
    script->varTable[7] = evt_get_variable(script, *args++);
    script->varTable[8] = evt_get_variable(script, *args++);
    script->varTable[9] = evt_get_variable(script, *args++);
    script->varTable[10] = evt_get_variable(script, *args++);
    script->varTable[11] = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(LetterDelivery_CalcLetterPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 varX = *args++;
    f32 x = evt_get_variable(script, varX);
    s32 varY = *args++;
    f32 y = evt_get_variable(script, varY);
    s32 varZ = *args++;
    f32 z = evt_get_variable(script, varZ);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    f32 currentCamYaw = clamp_angle(gCameras[gCurrentCameraID].curYaw + 180.0f);

    add_vec2D_polar(&x, &z, 15.0f, partner->yaw);
    add_vec2D_polar(&x, &z, 10.0f, currentCamYaw);

    evt_set_variable(script, varX, x);
    evt_set_variable(script, varY, y);
    evt_set_variable(script, varZ, z);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(LetterDelivery_SaveNpcAnim)) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    N(LetterDelivery_SavedNpcAnim) = npc->curAnim;
    npc->curAnim = script->varTable[4];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(LetterDelivery_RestoreNpcAnim)) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    npc->curAnim = N(LetterDelivery_SavedNpcAnim);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_LetterDelivery_CarryLetter) = {
    Loop(0)
        Call(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        Call(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
        Call(SetItemPos, LVar0, LVar3, LVar4, LVar5)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_LetterDelivery_ItemPrompt) = {
    Set(LVar9, LVar1)
    Call(ShowKeyChoicePopup)
    Set(LVarA, LVar0)
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
        CaseDefault
            Call(RemoveKeyItemAt, LVar1)
            Call(DisablePartnerAI, 0)
            Call(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            Call(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
            BitwiseOrConst(LVar0, VIS_GROUP_5 << 16)
            Call(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            ExecGetTID(N(EVS_LetterDelivery_CarryLetter), LVarA)
            Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Walk)
            Call(GetAngleBetweenNPCs, LVar9, NPC_PARTNER, LVarB)
            Call(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            Call(GetNpcPos, LVar9, LVar6, LVar7, LVar8)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            IfLe(LVarB, 180)
                Add(LVar6, 20)
            Else
                Add(LVar6, -20)
            EndIf
            Add(LVar7, 10)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
            Call(NpcJump1, NPC_PARTNER, LVar6, LVar7, LVar8, 20)
            KillThread(LVarA)
            Call(RemoveItemEntity, LVar0)
            Wait(20)
            Call(GetNpcYaw, NPC_PARTNER, LVarA)
            Add(LVarA, 180)
            Call(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
            Wait(5)
            Call(NpcJump1, NPC_PARTNER, LVar3, LVar4, LVar5, 20)
            Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Idle)
            Call(NpcFaceNpc, NPC_PARTNER, LVar9, 0)
            Wait(5)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Call(EnablePartnerAI)
            Wait(5)
    EndSwitch
    Call(N(ItemChoice_SaveSelected), LVarA)
    Call(CloseChoicePopup)
    Unbind
    Return
    End
};

EvtScript N(EVS_ShowLetterChoice) = {
    Set(LVar0, LVarB)
    Set(LVar1, LVar2)
    Call(N(BuildKeyItemChoiceList), LVar0)
    BindPadlock(N(EVS_LetterDelivery_ItemPrompt), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(KeyItemChoiceList)), 0, 1)
    Call(N(ItemChoice_WaitForSelection), LVar0)
    Return
    End
};

// returns DeliveryResult on LVarC
EvtScript N(EVS_DoLetterDelivery) = {
    Set(LVarC, DELIVERY_NOT_POSSIBLE)
    IfLt(GB_StoryProgress, STORY_CH2_PARAKARRY_JOINED_PARTY)
        Return
    EndIf
    Call(N(LetterDelivery_SaveNpcAnim))
    Call(GetCurrentPartnerID, LVar0)
    Call(FindKeyItem, LVar5, LVar1)
    IfEq(LVar0, PARTNER_PARAKARRY)
        IfNe(LVar1, -1)
            Call(DisablePartnerAI, 0)
            Call(PlayerFaceNpc, LVar2, FALSE)
            Wait(1)
            Call(GetNpcPos, LVar2, LVarD, LVar0, LVarE)
            Call(GetNpcPos, NPC_PARTNER, LVarD, LVarE, LVarF)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
            Add(LVar0, 10)
            Call(NpcJump1, NPC_PARTNER, LVarD, LVar0, LVarF, 10)
            Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, LVar2, LVar7)
            Call(EnablePartnerAI)
            ExecWait(N(EVS_ShowLetterChoice))
            Switch(LVar0)
                CaseEq(-1)
                    Call(DisablePartnerAI, 0)
                    Wait(1)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar8)
                    Call(EnablePartnerAI)
                    Set(LVarC, DELIVERY_REJECTED)
                CaseDefault
                    Call(DisablePartnerAI, 0)
                    Wait(1)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar9)
                    IfNe(LVarA, 0)
                        Call(SpeakToPlayer, LVar2, LVar3, LVar4, 0, LVarA)
                    EndIf
                    Call(EnablePartnerAI)
                    IfNe(LVar6, ITEM_NONE)
                        EVT_GIVE_KEY_REWARD(LVar6)
                    EndIf
                    Set(LVarC, DELIVERY_ACCEPTED)
            EndSwitch
        EndIf
    EndIf
    Call(N(LetterDelivery_RestoreNpcAnim))
    Return
    End
};

#define EVT_LETTER_PROMPT(npcName, npcID, animTalk, animIdle, msg1, msg2, ms3, msg4, itemID, itemList) \
    EvtScript N(EVS_LetterPrompt_##npcName) = { \
        Call(N(LetterDelivery_Init), \
            npcID, animTalk, animIdle, \
            itemID, ITEM_NONE, \
            msg1, msg2, ms3, msg4, \
            Ref(itemList)) \
        ExecWait(N(EVS_DoLetterDelivery)) \
        Return \
        End \
    }

#define EVT_LETTER_REWARD(npcName) \
    EvtScript N(EVS_LetterReward_##npcName) = { \
        IfEq(LVarC, DELIVERY_ACCEPTED) \
            EVT_GIVE_STAR_PIECE() \
        EndIf \
        Return \
        End \
    }

#define EVT_LETTER_CHECK(npcName) \
    ExecWait(N(EVS_LetterPrompt_##npcName)) \
    ExecWait(N(EVS_LetterReward_##npcName))
