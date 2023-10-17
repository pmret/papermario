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
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_LAKILESTER)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_LOOP(3)
        EVT_CALL(RotateModel, MODEL_handle1, 3, -1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(RotateModel, MODEL_handle1, -3, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_EQ(MF_Unk_06, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GB_MAC03_LilOinkCapsuleState, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetPlayerCoins))
    EVT_IF_LT(LVar0, LIL_OINK_COIN_COST)
        EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_FLOOR_SWITCH_ACTIVATE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(AddCoin, -LIL_OINK_COIN_COST)
    EVT_WAIT(20)
    EVT_CALL(N(DismissCoinCounter))
    EVT_SET(MF_Unk_06, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 138, 25, -406)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 138, 25, -406)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -13)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_TURN_MECHANISM, SOUND_SPACE_DEFAULT, 111, 89, -358)
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, 6)
            EVT_CALL(RotateModel, MODEL_handle1, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(30)
            EVT_ADD(LVar0, 10)
            EVT_CALL(RotateModel, MODEL_handle1, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(5)
            EVT_ADD(LVar0, 6)
            EVT_CALL(RotateModel, MODEL_handle1, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_LOOP(20)
        EVT_ADDF(LVar0, EVT_FLOAT(0.2))
        EVT_CALL(ScaleModel, MODEL_boo, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
        EVT_SUBF(LVar0, EVT_FLOAT(0.2))
        EVT_CALL(ScaleModel, MODEL_boo, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_SUBF(LVar0, EVT_FLOAT(0.04))
        EVT_CALL(ScaleModel, MODEL_boo, 1, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_LOOP(10)
        EVT_ADDF(LVar0, EVT_FLOAT(0.08))
        EVT_CALL(ScaleModel, MODEL_boo, 1, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_CAPSULE_OPEN, SOUND_SPACE_DEFAULT, 134, 132, -399)
    EVT_LOOP(5)
        EVT_SUBF(LVar0, EVT_FLOAT(0.08))
        EVT_CALL(ScaleModel, MODEL_boo, 1, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT, 170, 73, -450)
    EVT_SET(GB_MAC03_LilOinkCapsuleState, 1)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 230, 20, -270)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -6)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnableModel, MODEL_capsule, TRUE)
    EVT_CALL(MakeLerp, 0, 900, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(N(GetRollingCapsulePosition))
        EVT_CALL(SetNpcPos, NPC_Capsule, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_ADD(LVar4, 5)
        EVT_CALL(SetNpcPos, NPC_Capsule, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcJumpscale, NPC_Capsule, 1)
    EVT_CALL(NpcJump0, NPC_Capsule, LVar2, EVT_FLOAT(63.0), -273, 5)
    EVT_CALL(PlaySoundAtNpc, NPC_Capsule, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_Capsule, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Capsule, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_Capsule, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_Capsule, LVar0, LVar1, LVar2, 5)
    EVT_CALL(PlaySoundAtNpc, NPC_Capsule, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_capsule, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LilOinkExplanation) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetNpcSpeed, NPC_Toad_03, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Run)
    EVT_CALL(NpcMoveTo, NPC_Toad_03, 157, -310, 0)
    EVT_CALL(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Station_0053)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 0)
        EVT_SET(LVar0, MSG_MAC_Station_0056)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Station_0055)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_Toad_03, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_WAIT(10)
    EVT_SET(MF_Unk_08, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Run)
    EVT_CALL(NpcMoveTo, NPC_Toad_03, 220, -160, 0)
    EVT_CALL(SetNpcAnimation, NPC_Toad_03, ANIM_Toad_Red_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMachinePrompt) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(MF_Unk_08, FALSE)
        EVT_EXEC(N(EVS_LilOinkExplanation))
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_IF_NE(LVar0, PARTNER_NONE)
            EVT_CALL(InterruptUsePartner)
            EVT_WAIT(10)
        EVT_END_IF
        EVT_CALL(PlayerMoveTo, 95, -365, 10)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_IF_NE(MF_Unk_08, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_SET(MF_Unk_06, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_EQ(LVar0, COLLIDER_step)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_EQ(LVar0, -1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(N(DismissCoinCounter))
    EVT_SET(MF_Unk_06, FALSE)
    EVT_RETURN
    EVT_END
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
    [LIL_OINK_TYPE_GOLD]        { .itemID = ITEM_ULTRA_SHROOM,  .quantity = 1, .chance = 100 },
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
    EVT_CALL(N(GetLilOinkPrize), LVar4, LVar5, LVar6)
    EVT_CALL(RandInt, 100, LVar7)
    EVT_IF_GT(LVar7, LVar6)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_LilOink_01, LVar1, LVar2, LVar3)
    EVT_LOOP(LVar5)
        EVT_CALL(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenCapsule) = {
    EVT_CALL(N(GetFloorCollider), LVar0)
    EVT_IF_NE(LVar0, COLLIDER_hummer)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_SET(MF_Unk_07, TRUE)
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_LOOP(5)
        EVT_SUBF(LVar0, EVT_FLOAT(0.03))
        EVT_CALL(ScaleModel, MODEL_capsule, 1, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(5)
        EVT_ADDF(LVar0, EVT_FLOAT(0.03))
        EVT_CALL(ScaleModel, MODEL_capsule, 1, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, NPC_Capsule, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 10)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    EVT_CALL(EnableModel, MODEL_capsule, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_capsule, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_MAC03_LilOinkCapsuleState, 2)
    EVT_CALL(SetNpcPos, NPC_Capsule, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcYaw, NPC_Capsule, 90)
    EVT_CALL(EnableNpcShadow, NPC_Capsule, TRUE)
    EVT_CALL(RandInt, 100, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_LT(3)
            EVT_SET(LVar3, LIL_OINK_TYPE_GOLD)
        EVT_CASE_LT(12)
            EVT_SET(LVar3, LIL_OINK_TYPE_SILVER)
        EVT_CASE_LT(19)
            EVT_SET(LVar3, LIL_OINK_TYPE_SHROOM)
        EVT_CASE_LT(26)
            EVT_SET(LVar3, LIL_OINK_TYPE_FLOWER)
        EVT_CASE_LT(33)
            EVT_SET(LVar3, LIL_OINK_TYPE_STAR)
        EVT_CASE_LT(40)
            EVT_SET(LVar3, LIL_OINK_TYPE_QUESTION)
        EVT_CASE_LT(55)
            EVT_SET(LVar3, LIL_OINK_TYPE_BLACK)
        EVT_CASE_LT(70)
            EVT_SET(LVar3, LIL_OINK_TYPE_WHITE)
        EVT_CASE_LT(85)
            EVT_SET(LVar3, LIL_OINK_TYPE_PINK)
        EVT_CASE_DEFAULT
            EVT_SET(LVar3, LIL_OINK_TYPE_PIKACHU)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtNpc, NPC_Capsule, SOUND_TORNADO_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(CreateLilOink), 10, LVar3, LVar0, LVar1, LVar2, 90)
    EVT_WAIT(10)
    EVT_IF_GE(GB_MAC03_LilOinkCount, 10)
        EVT_SET(LVarA, LVar3)
        EVT_CALL(GetNpcPos, NPC_LilOink_01, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcAI, NPC_LilOink_01, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_LilOink_01, NPC_Capsule, 0)
        EVT_WAIT(10)
        EVT_CALL(NpcJump0, NPC_LilOink_01, LVar0, LVar1, LVar2, 15)
        EVT_EXEC(N(EVS_SpawnLilOinkPrize))
        EVT_CALL(PlaySoundAtNpc, NPC_LilOink_01, SOUND_PLAYER_RUN_AWAY, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcSpeed, NPC_LilOink_01, 4)
        EVT_CALL(NpcMoveTo, NPC_LilOink_01, 580, -170, 0)
        EVT_CALL(NpcJump0, NPC_LilOink_01, 620, 20, -170, 15)
        EVT_CALL(EnableNpcShadow, NPC_LilOink_01, FALSE)
        EVT_CALL(SetNpcSpeed, NPC_LilOink_01, 1)
        EVT_CALL(EnableNpcAI, NPC_LilOink_01, TRUE)
        EVT_CALL(N(PopLilOinkList))
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, NPC_LilOink_01)
        EVT_SET(LVar6, GB_MAC03_LilOinkCount)
        EVT_LOOP(LVar6)
            EVT_CALL(N(GetLilOinkPosition), LVar0, LVar2, LVar3, LVar4, LVar5)
            EVT_CALL(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(SetNpcYaw, LVar1, LVar5)
            EVT_ADD(LVar0, 1)
            EVT_ADD(LVar1, 1)
        EVT_END_LOOP
        EVT_SET(LVar3, LVarA)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 360, 20, -165)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 360, 20, -165)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(N(SetLilOinkAnim), 10, LIL_OINK_ANIM_2)
    EVT_CALL(SetNpcJumpscale, NPC_Capsule, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Capsule, 330, 20, -220, 20)
    EVT_CALL(SetNpcSpeed, NPC_Capsule, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_Capsule, 360, -180, 0)
    EVT_SET(GB_MAC03_LilOinkCapsuleState, 0)
    EVT_CALL(EnableNpcShadow, NPC_Capsule, FALSE)
    EVT_CALL(N(GetLilOinkPosition), 10, LVar0, LVar1, LVar2, LVar4)
    EVT_CALL(N(HideLilOink), 10)
    EVT_SET(LVar5, NPC_LilOink_01)
    EVT_ADD(LVar5, GB_MAC03_LilOinkCount)
    EVT_CALL(SetNpcPos, LVar5, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcYaw, LVar5, LVar4)
    EVT_CALL(EnableNpcShadow, LVar5, TRUE)
    EVT_CALL(N(CreateLilOink), GB_MAC03_LilOinkCount, LVar3, LVar0, LVar1, LVar2, LVar4)
    EVT_ADD(GB_MAC03_LilOinkCount, 1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LilOinkFlee) = {
    EVT_SET(LVar1, NPC_LilOink_01)
    EVT_ADD(LVar1, LVar0)
    EVT_CALL(EnableNpcAI, LVar1, FALSE)
    EVT_CALL(NpcFacePlayer, LVar1, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, LVar1, LVar2, LVar3, LVar4)
    EVT_CALL(NpcJump0, LVar1, LVar2, LVar3, LVar4, 10)
    EVT_CALL(PlaySoundAtNpc, LVar1, SOUND_PLAYER_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcSpeed, LVar1, 8)
    EVT_CALL(NpcMoveTo, LVar1, 580, LVar4, 0)
    EVT_CALL(NpcJump0, LVar1, 620, 20, LVar4, 15)
    EVT_CALL(EnableNpcShadow, LVar1, FALSE)
    EVT_CALL(SetNpcSpeed, LVar1, 1)
    EVT_CALL(EnableNpcAI, LVar1, TRUE)
    EVT_CALL(N(HideLilOink), LVar0)
    EVT_SUB(GB_MAC03_LilOinkCount, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterPen) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deili, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deili, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, 370, -208, 15)
    EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deili, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deili, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(GB_MAC03_LilOinkCount, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_SET(LVar0, GB_MAC03_LilOinkCount)
    EVT_SET(LVar6, GB_MAC03_LilOinkCount)
    EVT_LOOP(LVar6)
        EVT_ADD(LVar0, -1)
        EVT_EXEC(N(EVS_LilOinkFlee))
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_IF_EQ(GB_MAC03_LilOinkCount, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPen) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliu, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deiliu, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, 370, -328, 15)
    EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deiliu, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deiliu, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SyncLilOinkNpcPositions) = {
    EVT_LOOP(0)
        EVT_IF_NE(GB_MAC03_LilOinkCount, 0)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, NPC_LilOink_01)
            EVT_SET(LVar6, GB_MAC03_LilOinkCount)
            EVT_LOOP(LVar6)
                EVT_CALL(GetNpcPos, LVar1, LVar2, LVar3, LVar4)
                EVT_CALL(GetNpcYaw, LVar1, LVar5)
                EVT_CALL(N(SetLilOinkPosition), LVar0, LVar2, LVar3, LVar4, LVar5)
                EVT_ADD(LVar0, 1)
                EVT_ADD(LVar1, 1)
            EVT_END_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitializeLilOinks) = {
    EVT_IF_EQ(GB_MAC03_LilOinkCapsuleState, 1)
        EVT_CALL(SetNpcPos, NPC_Capsule, 277, EVT_FLOAT(63.0), -273)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_capsule, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_capsule, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(MF_Unk_06, FALSE)
    EVT_SET(MF_Unk_07, FALSE)
    EVT_IF_EQ(GB_MAC03_LilOinkCount, 0)
        EVT_SET(MF_Unk_08, FALSE)
    EVT_ELSE
        EVT_SET(MF_Unk_08, TRUE)
    EVT_END_IF
    EVT_CALL(N(LoadLilOinks))
    EVT_IF_NE(GB_MAC03_LilOinkCount, 0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, NPC_LilOink_01)
        EVT_SET(LVar6, GB_MAC03_LilOinkCount)
        EVT_LOOP(LVar6)
            EVT_CALL(N(GetLilOinkPosition), LVar0, LVar2, LVar3, LVar4, LVar5)
            EVT_CALL(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(SetNpcYaw, LVar1, LVar5)
            EVT_ADD(LVar0, 1)
            EVT_ADD(LVar1, 1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_EXEC(N(EVS_SyncLilOinkNpcPositions))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseMachinePrompt)), TRIGGER_FLOOR_TOUCH, COLLIDER_step, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TurnCrank)), TRIGGER_CEILING_TOUCH, COLLIDER_jump, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OpenCapsule)), TRIGGER_WALL_HAMMER, COLLIDER_capsule, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_EnterPen)), TRIGGER_WALL_PRESS_A, COLLIDER_deili, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPen)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliu, 1, 0)
    EVT_RETURN
    EVT_END
};
