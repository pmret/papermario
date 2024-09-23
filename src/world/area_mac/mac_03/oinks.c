#include "mac_03.h"
#include "effects.h"

#define LIL_OINK_COIN_COST 10

typedef struct LilOinkReward {
    /* 0x00 */ s32 itemID;
    /* 0x04 */ s32 quantity;
    /* 0x08 */ s32 chance;
} LilOinkReward; // size = 0x0C

#include "world/common/todo/GetFloorCollider.inc.c"
#include "world/common/todo/GetPlayerCoins.inc.c"

API_CALLABLE(N(DismissCoinCounter)) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetRollingCapsulePosition)) {
    //  f32 angle = clamp_angle(EVT_FIXED_TO_FLOAT(script->varTable[2])); ? TODO
    f32 angle = script->varTable[2] + EVT_FIXED_OFFSET;

    angle = clamp_angle(angle * (1.0f / 1024.0f));
    script->varTable[2] =  167.0f  + (sin_deg(angle) * 110.0f);
    script->varTable[3] =   85.0f;
    script->varTable[4] = -343.75f - (cos_deg(angle) * 110.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(LoadLilOinks)) {
    s32 varBase = GB_MAC03_LilOink_00;
    s32 numPigs = evt_get_variable(NULL, GB_MAC03_LilOinkCount);
    EffectInstance* effect = fx_lil_oink(0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    s32 i;

    evt_set_variable(script, MV_LilOinkEffect, (s32) effect);

    for (i = 0; i < numPigs; i++) {
        effect->data.lilOink->type[i] = evt_get_variable(NULL, varBase + i);
        effect->data.lilOink->x[i] = 300 + (i * 30);
        effect->data.lilOink->y[i] = 20.0f;
        effect->data.lilOink->z[i] = -180.0f;
        effect->data.lilOink->rot[i] = 270.0f;
        effect->data.lilOink->flags[i] |= LIL_OINK_FLAG_VISIBLE;
        effect->data.lilOink->flags[i] |= LIL_OINK_FLAG_ANIM_CHANGED;
        effect->data.lilOink->nextAnim[i] = LIL_OINK_ANIM_2;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateLilOink)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    s32 type = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    s32 rot = evt_get_variable(script, *args++);

    effect->data.lilOink->type[i] = type;
    effect->data.lilOink->x[i] = x;
    effect->data.lilOink->y[i] = y;
    effect->data.lilOink->z[i] = z;
    effect->data.lilOink->rot[i] = rot;
    effect->data.lilOink->flags[i] |= LIL_OINK_FLAG_VISIBLE;

    if (i != MAX_LIL_OINKS - 1) {
        effect->data.lilOink->flags[i] |= LIL_OINK_FLAG_ANIM_CHANGED;
        effect->data.lilOink->nextAnim[i] = LIL_OINK_ANIM_2;
        evt_set_variable(script, i + GB_MAC03_LilOink_00, type);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetLilOinkPosition)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    s32 rot = evt_get_variable(script, *args++);

    effect->data.lilOink->x[i] = x;
    effect->data.lilOink->y[i] = y;
    effect->data.lilOink->z[i] = z;
    effect->data.lilOink->rot[i] = rot;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetLilOinkPosition)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    s32 xOut = *args++;
    s32 yOut = *args++;
    s32 zOut = *args++;
    s32 rotOut = *args++;

    evt_set_variable(script, xOut, effect->data.lilOink->x[i]);
    evt_set_variable(script, yOut, effect->data.lilOink->y[i]);
    evt_set_variable(script, zOut, effect->data.lilOink->z[i]);
    evt_set_variable(script, rotOut, effect->data.lilOink->rot[i]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(HideLilOink)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);

    effect->data.lilOink->flags[i] &= ~LIL_OINK_FLAG_VISIBLE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetLilOinkAnim)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    s32 anim = evt_get_variable(script, *args++);

    effect->data.lilOink->flags[i] |= LIL_OINK_FLAG_ANIM_CHANGED;
    effect->data.lilOink->nextAnim[i] = anim;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(PopLilOinkList)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    s32 i;

    for (i = 1; i < MAX_LIL_OINKS - 1; i++) {
        s32 type = evt_get_variable(script, GB_MAC03_LilOink_00 + i);
        f32 x, y, z, rot;

        evt_set_variable(script, GB_MAC03_LilOinkCount + i, type);

        x = effect->data.lilOink->x[i];
        y = effect->data.lilOink->y[i];
        z = effect->data.lilOink->z[i];
        rot = effect->data.lilOink->rot[i];

        effect->data.lilOink->type[i - 1] = type;
        effect->data.lilOink->x[i - 1] = x;
        effect->data.lilOink->y[i - 1] = y;
        effect->data.lilOink->z[i - 1] = z;
        effect->data.lilOink->rot[i - 1] = rot;
        effect->data.lilOink->flags[i - 1] |= LIL_OINK_FLAG_VISIBLE;
    }
    effect->data.lilOink->flags[MAX_LIL_OINKS - 2] &= ~LIL_OINK_FLAG_VISIBLE;
    evt_set_variable(script, GB_MAC03_LilOinkCount, 9);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TurnCrank) = {
    Call(GetPartnerInUse, LVar0)
    IfEq(LVar0, PARTNER_LAKILESTER)
        Return
    EndIf
    Set(LVar0, 0)
    Loop(3)
        Call(RotateModel, MODEL_handle1, 3, -1, 0, 0)
        Wait(1)
        Call(RotateModel, MODEL_handle1, -3, -1, 0, 0)
        Wait(1)
    EndLoop
    IfEq(MF_Unk_06, FALSE)
        Return
    EndIf
    IfNe(GB_MAC03_LilOinkCapsuleState, 0)
        Return
    EndIf
    Call(N(GetPlayerCoins))
    IfLt(LVar0, LIL_OINK_COIN_COST)
        Call(PlaySound, SOUND_MENU_ERROR)
        Return
    EndIf
    Call(PlaySound, SOUND_FLOOR_SWITCH_ACTIVATE)
    Call(DisablePlayerInput, TRUE)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(AddCoin, -LIL_OINK_COIN_COST)
    Wait(20)
    Call(N(DismissCoinCounter))
    Set(MF_Unk_06, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 138, 25, -406)
    Call(SetPanTarget, CAM_DEFAULT, 138, 25, -406)
    Call(SetCamPitch, CAM_DEFAULT, 15, -13)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Thread
        Call(PlaySoundAt, SOUND_TURN_MECHANISM, SOUND_SPACE_DEFAULT, 111, 89, -358)
        Set(LVar0, 0)
        Loop(5)
            Add(LVar0, 6)
            Call(RotateModel, MODEL_handle1, LVar0, 0, 0, -1)
            Wait(1)
        EndLoop
        Loop(30)
            Add(LVar0, 10)
            Call(RotateModel, MODEL_handle1, LVar0, 0, 0, -1)
            Wait(1)
        EndLoop
        Loop(5)
            Add(LVar0, 6)
            Call(RotateModel, MODEL_handle1, LVar0, 0, 0, -1)
            Wait(1)
        EndLoop
    EndThread
    SetF(LVar0, Float(1.0))
    Loop(20)
        AddF(LVar0, Float(0.2))
        Call(ScaleModel, MODEL_boo, LVar0, LVar0, LVar0)
        Wait(1)
        SubF(LVar0, Float(0.2))
        Call(ScaleModel, MODEL_boo, LVar0, LVar0, LVar0)
        Wait(1)
    EndLoop
    SetF(LVar0, Float(1.0))
    Loop(10)
        SubF(LVar0, Float(0.04))
        Call(ScaleModel, MODEL_boo, 1, LVar0, 1)
        Wait(1)
    EndLoop
    Wait(20)
    Loop(10)
        AddF(LVar0, Float(0.08))
        Call(ScaleModel, MODEL_boo, 1, LVar0, 1)
        Wait(1)
    EndLoop
    Call(PlaySoundAt, SOUND_CAPSULE_OPEN, SOUND_SPACE_DEFAULT, 134, 132, -399)
    Loop(5)
        SubF(LVar0, Float(0.08))
        Call(ScaleModel, MODEL_boo, 1, LVar0, 1)
        Wait(1)
    EndLoop
    Call(PlaySoundAt, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT, 170, 73, -450)
    Set(GB_MAC03_LilOinkCapsuleState, 1)
    Call(SetPanTarget, CAM_DEFAULT, 230, 20, -270)
    Call(SetCamPitch, CAM_DEFAULT, 15, -6)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnableModel, MODEL_capsule, TRUE)
    Call(MakeLerp, 0, 900, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(N(GetRollingCapsulePosition))
        Call(SetNpcPos, NPC_Capsule, LVar2, LVar3, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Loop(10)
        Add(LVar4, 5)
        Call(SetNpcPos, NPC_Capsule, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(SetNpcJumpscale, NPC_Capsule, 1)
    Call(NpcJump0, NPC_Capsule, LVar2, Float(63.0), -273, 5)
    Call(PlaySoundAtNpc, NPC_Capsule, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_Capsule, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Capsule, LVar0, LVar1, LVar2, 10)
    Call(PlaySoundAtNpc, NPC_Capsule, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Capsule, LVar0, LVar1, LVar2, 5)
    Call(PlaySoundAtNpc, NPC_Capsule, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_capsule, COLLIDER_FLAGS_UPPER_MASK)
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_LilOinkExplanation) = {
    SetGroup(EVT_GROUP_00)
    Call(SetNpcSpeed, NPC_Toad_03, Float(4.0))
    Call(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Run)
    Call(NpcMoveTo, NPC_Toad_03, 157, -310, 0)
    Call(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_Toad_03, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Station_0053)
    Call(ShowChoice, MSG_Choice_000D)
    IfEq(LVar0, 0)
        Set(LVar0, MSG_MAC_Station_0056)
    Else
        Set(LVar0, MSG_MAC_Station_0055)
    EndIf
    Call(ContinueSpeech, NPC_Toad_03, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Wait(10)
    Set(MF_Unk_08, TRUE)
    Call(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Run)
    Call(NpcMoveTo, NPC_Toad_03, 220, -160, 0)
    Call(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Idle)
    Return
    End
};

EvtScript N(EVS_UseMachinePrompt) = {
    Call(DisablePlayerInput, TRUE)
    IfEq(MF_Unk_08, FALSE)
        Exec(N(EVS_LilOinkExplanation))
        Call(GetPartnerInUse, LVar0)
        IfNe(LVar0, PARTNER_NONE)
            Call(InterruptUsePartner)
            Wait(10)
        EndIf
        Call(PlayerMoveTo, 95, -365, 10)
    EndIf
    Loop(0)
        IfNe(MF_Unk_08, FALSE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(ShowCoinCounter, TRUE)
    Set(MF_Unk_06, TRUE)
    Call(DisablePlayerInput, FALSE)
    Label(0)
        Wait(1)
        Call(N(GetFloorCollider), LVar0)
        IfEq(LVar0, COLLIDER_step)
            Goto(0)
        EndIf
        IfEq(LVar0, -1)
            Goto(0)
        EndIf
    Call(N(DismissCoinCounter))
    Set(MF_Unk_06, FALSE)
    Return
    End
};

LilOinkReward N(LilOinkPrizes)[] = {
    [LIL_OINK_TYPE_BLACK]       { .itemID = ITEM_DRIED_SHROOM,  .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_WHITE]       { .itemID = ITEM_SUPER_SHROOM,  .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_PINK]        { .itemID = ITEM_FIRE_FLOWER,   .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_PIKACHU]     { .itemID = ITEM_THUNDER_RAGE,  .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_SHROOM]      { .itemID = ITEM_LIFE_SHROOM,   .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_FLOWER]      { .itemID = ITEM_MAPLE_SYRUP,   .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_STAR]        { .itemID = ITEM_SHOOTING_STAR, .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_QUESTION]    { .itemID = ITEM_REPEL_GEL,     .quantity = 1, .chance = 100 },
    [LIL_OINK_TYPE_SILVER]      { .itemID = ITEM_JAMMIN_JELLY,  .quantity = 1, .chance = 100 },
#if VERSION_JP
    [LIL_OINK_TYPE_GOLD]        { .itemID = ITEM_JELLY_SHROOM,  .quantity = 1, .chance = 100 },
#else
    [LIL_OINK_TYPE_GOLD]        { .itemID = ITEM_ULTRA_SHROOM,  .quantity = 1, .chance = 100 },
#endif
};

API_CALLABLE(N(GetLilOinkPrize)) {
    Bytecode* args = script->ptrReadPos;
    s32 oinkType = evt_get_variable(script, GB_MAC03_LilOink_00);
    s32 itemID = *args++;
    s32 quantity = *args++;
    s32 chance = *args++;
    LilOinkReward* reward = &N(LilOinkPrizes)[oinkType];

    evt_set_variable(script, itemID, reward->itemID);
    evt_set_variable(script, quantity, reward->quantity);
    evt_set_variable(script, chance, reward->chance);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpawnLilOinkPrize) = {
    Call(N(GetLilOinkPrize), LVar4, LVar5, LVar6)
    Call(RandInt, 100, LVar7)
    IfGt(LVar7, LVar6)
        Return
    EndIf
    Call(GetNpcPos, NPC_LilOink_01, LVar1, LVar2, LVar3)
    Loop(LVar5)
        Call(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_OpenCapsule) = {
    Call(N(GetFloorCollider), LVar0)
    IfNe(LVar0, COLLIDER_hummer)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Set(MF_Unk_07, TRUE)
    SetF(LVar0, Float(1.0))
    Loop(5)
        SubF(LVar0, Float(0.03))
        Call(ScaleModel, MODEL_capsule, 1, LVar0, 1)
        Wait(1)
    EndLoop
    Loop(5)
        AddF(LVar0, Float(0.03))
        Call(ScaleModel, MODEL_capsule, 1, LVar0, 1)
        Wait(1)
    EndLoop
    Call(GetNpcPos, NPC_Capsule, LVar0, LVar1, LVar2)
    Sub(LVar1, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    Call(EnableModel, MODEL_capsule, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_capsule, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_MAC03_LilOinkCapsuleState, 2)
    Call(SetNpcPos, NPC_Capsule, LVar0, LVar1, LVar2)
    Call(SetNpcYaw, NPC_Capsule, 90)
    Call(EnableNpcShadow, NPC_Capsule, TRUE)
    Call(RandInt, 100, LVar3)
    Switch(LVar3)
        CaseLt(3)
            Set(LVar3, LIL_OINK_TYPE_GOLD)
        CaseLt(12)
            Set(LVar3, LIL_OINK_TYPE_SILVER)
        CaseLt(19)
            Set(LVar3, LIL_OINK_TYPE_SHROOM)
        CaseLt(26)
            Set(LVar3, LIL_OINK_TYPE_FLOWER)
        CaseLt(33)
            Set(LVar3, LIL_OINK_TYPE_STAR)
        CaseLt(40)
            Set(LVar3, LIL_OINK_TYPE_QUESTION)
        CaseLt(55)
            Set(LVar3, LIL_OINK_TYPE_BLACK)
        CaseLt(70)
            Set(LVar3, LIL_OINK_TYPE_WHITE)
        CaseLt(85)
            Set(LVar3, LIL_OINK_TYPE_PINK)
        CaseDefault
            Set(LVar3, LIL_OINK_TYPE_PIKACHU)
    EndSwitch
    Call(PlaySoundAtNpc, NPC_Capsule, SOUND_TORNADO_JUMP, SOUND_SPACE_DEFAULT)
    Call(N(CreateLilOink), 10, LVar3, LVar0, LVar1, LVar2, 90)
    Wait(10)
    IfGe(GB_MAC03_LilOinkCount, 10)
        Set(LVarA, LVar3)
        Call(GetNpcPos, NPC_LilOink_01, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Wait(10)
        Call(EnableNpcAI, NPC_LilOink_01, FALSE)
        Call(NpcFaceNpc, NPC_LilOink_01, NPC_Capsule, 0)
        Wait(10)
        Call(NpcJump0, NPC_LilOink_01, LVar0, LVar1, LVar2, 15)
        Exec(N(EVS_SpawnLilOinkPrize))
        Call(PlaySoundAtNpc, NPC_LilOink_01, SOUND_PLAYER_RUN_AWAY, SOUND_SPACE_DEFAULT)
        Call(SetNpcSpeed, NPC_LilOink_01, 4)
        Call(NpcMoveTo, NPC_LilOink_01, 580, -170, 0)
        Call(NpcJump0, NPC_LilOink_01, 620, 20, -170, 15)
        Call(EnableNpcShadow, NPC_LilOink_01, FALSE)
        Call(SetNpcSpeed, NPC_LilOink_01, 1)
        Call(EnableNpcAI, NPC_LilOink_01, TRUE)
        Call(N(PopLilOinkList))
        Set(LVar0, 0)
        Set(LVar1, NPC_LilOink_01)
        Set(LVar6, GB_MAC03_LilOinkCount)
        Loop(LVar6)
            Call(N(GetLilOinkPosition), LVar0, LVar2, LVar3, LVar4, LVar5)
            Call(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            Call(SetNpcYaw, LVar1, LVar5)
            Add(LVar0, 1)
            Add(LVar1, 1)
        EndLoop
        Set(LVar3, LVarA)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, 360, 20, -165)
    Call(SetPanTarget, CAM_DEFAULT, 360, 20, -165)
    Call(SetCamSpeed, CAM_DEFAULT, 3)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(N(SetLilOinkAnim), 10, LIL_OINK_ANIM_2)
    Call(SetNpcJumpscale, NPC_Capsule, Float(1.0))
    Call(NpcJump0, NPC_Capsule, 330, 20, -220, 20)
    Call(SetNpcSpeed, NPC_Capsule, Float(4.0))
    Call(NpcMoveTo, NPC_Capsule, 360, -180, 0)
    Set(GB_MAC03_LilOinkCapsuleState, 0)
    Call(EnableNpcShadow, NPC_Capsule, FALSE)
    Call(N(GetLilOinkPosition), 10, LVar0, LVar1, LVar2, LVar4)
    Call(N(HideLilOink), 10)
    Set(LVar5, NPC_LilOink_01)
    Add(LVar5, GB_MAC03_LilOinkCount)
    Call(SetNpcPos, LVar5, LVar0, LVar1, LVar2)
    Call(SetNpcYaw, LVar5, LVar4)
    Call(EnableNpcShadow, LVar5, TRUE)
    Call(N(CreateLilOink), GB_MAC03_LilOinkCount, LVar3, LVar0, LVar1, LVar2, LVar4)
    Add(GB_MAC03_LilOinkCount, 1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_LilOinkFlee) = {
    Set(LVar1, NPC_LilOink_01)
    Add(LVar1, LVar0)
    Call(EnableNpcAI, LVar1, FALSE)
    Call(NpcFacePlayer, LVar1, 0)
    Wait(10)
    Call(GetNpcPos, LVar1, LVar2, LVar3, LVar4)
    Call(NpcJump0, LVar1, LVar2, LVar3, LVar4, 10)
    Call(PlaySoundAtNpc, LVar1, SOUND_PLAYER_RUN_AWAY, SOUND_SPACE_DEFAULT)
    Call(SetNpcSpeed, LVar1, 8)
    Call(NpcMoveTo, LVar1, 580, LVar4, 0)
    Call(NpcJump0, LVar1, 620, 20, LVar4, 15)
    Call(EnableNpcShadow, LVar1, FALSE)
    Call(SetNpcSpeed, LVar1, 1)
    Call(EnableNpcAI, LVar1, TRUE)
    Call(N(HideLilOink), LVar0)
    Sub(GB_MAC03_LilOinkCount, 1)
    Return
    End
};

EvtScript N(EVS_EnterPen) = {
    Call(DisablePlayerInput, TRUE)
    Call(func_802D2C14, 1)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deili, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_deili, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlayerMoveTo, 370, -208, 15)
    Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deili, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deili, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(func_802D2C14, 0)
    Call(DisablePlayerInput, FALSE)
    IfEq(GB_MAC03_LilOinkCount, 0)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Set(LVar0, GB_MAC03_LilOinkCount)
    Set(LVar6, GB_MAC03_LilOinkCount)
    Loop(LVar6)
        Add(LVar0, -1)
        Exec(N(EVS_LilOinkFlee))
        Wait(5)
    EndLoop
    Loop(0)
        IfEq(GB_MAC03_LilOinkCount, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ExitPen) = {
    SetGroup(EVT_GROUP_00)
    Call(DisablePlayerInput, TRUE)
    Call(func_802D2C14, 1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliu, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_deiliu, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlayerMoveTo, 370, -328, 15)
    Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deiliu, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deiliu, COLLIDER_FLAGS_UPPER_MASK)
    Call(func_802D2C14, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SyncLilOinkNpcPositions) = {
    Loop(0)
        IfNe(GB_MAC03_LilOinkCount, 0)
            Set(LVar0, 0)
            Set(LVar1, NPC_LilOink_01)
            Set(LVar6, GB_MAC03_LilOinkCount)
            Loop(LVar6)
                Call(GetNpcPos, LVar1, LVar2, LVar3, LVar4)
                Call(GetNpcYaw, LVar1, LVar5)
                Call(N(SetLilOinkPosition), LVar0, LVar2, LVar3, LVar4, LVar5)
                Add(LVar0, 1)
                Add(LVar1, 1)
            EndLoop
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_InitializeLilOinks) = {
    IfEq(GB_MAC03_LilOinkCapsuleState, 1)
        Call(SetNpcPos, NPC_Capsule, 277, Float(63.0), -273)
    Else
        Call(EnableModel, MODEL_capsule, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_capsule, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Set(MF_Unk_06, FALSE)
    Set(MF_Unk_07, FALSE)
    IfEq(GB_MAC03_LilOinkCount, 0)
        Set(MF_Unk_08, FALSE)
    Else
        Set(MF_Unk_08, TRUE)
    EndIf
    Call(N(LoadLilOinks))
    IfNe(GB_MAC03_LilOinkCount, 0)
        Set(LVar0, 0)
        Set(LVar1, NPC_LilOink_01)
        Set(LVar6, GB_MAC03_LilOinkCount)
        Loop(LVar6)
            Call(N(GetLilOinkPosition), LVar0, LVar2, LVar3, LVar4, LVar5)
            Call(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            Call(SetNpcYaw, LVar1, LVar5)
            Add(LVar0, 1)
            Add(LVar1, 1)
        EndLoop
    EndIf
    Exec(N(EVS_SyncLilOinkNpcPositions))
    BindTrigger(Ref(N(EVS_UseMachinePrompt)), TRIGGER_FLOOR_TOUCH, COLLIDER_step, 1, 0)
    BindTrigger(Ref(N(EVS_TurnCrank)), TRIGGER_CEILING_TOUCH, COLLIDER_jump, 1, 0)
    BindTrigger(Ref(N(EVS_OpenCapsule)), TRIGGER_WALL_HAMMER, COLLIDER_capsule, 1, 0)
    BindTrigger(Ref(N(EVS_EnterPen)), TRIGGER_WALL_PRESS_A, COLLIDER_deili, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPen)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliu, 1, 0)
    Return
    End
};
