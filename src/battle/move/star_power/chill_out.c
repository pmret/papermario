#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleMuskular.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_chill_out

BSS s32 D_802A2CC0;

#include "common/StarPower.inc.c"

API_CALLABLE(func_802A1518_7905E8) {
    D_802A2CC0 = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A1528_7905F8) {
    script->varTable[0] = D_802A2CC0;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A153C_79060C) {
    f32 a = rand_int(200) - 25;
    f32 b = rand_int(120) + 7;
    f32 c = rand_int(50) - 25;

    fx_cold_breath(2, a, b, c, 2.0f, 20);

    a = rand_int(200) - 25;
    b = rand_int(120) + 7;
    c = rand_int(50) - 25;

    fx_sparkles(FX_SPARKLES_4, a, b, c, 40.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A163C_79070C) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* target = get_actor(actor->targetActorID);
    ActorPart* part = get_actor_part(target, actor->targetPartIndex);
    s32 flag1 = ACTOR_FLAG_NO_DMG_APPLY; // these manual flag ones are necessary to match. once we figure out flags, we can add more
    s32 flag2 = ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED;

    script->varTable[0] = 0;

    if ((target->flags & ACTOR_FLAG_TARGET_ONLY)
        || (target->flags & flag1)
        || (target->flags & ACTOR_FLAG_2000)
        || (part->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED)
        || (part->eventFlags & flag2)
    ) {
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A16F4_7907C4) {
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target = get_actor(enemy->targetActorID);
    ActorPart* targetPart = get_actor_part(target, enemy->targetPartIndex);
    f32 x, y, z;

    if (target->flags & ACTOR_FLAG_TARGET_ONLY) {
        return ApiStatus_DONE2;
    }

    if (target->flags & ACTOR_FLAG_NO_DMG_APPLY) {
        return ApiStatus_DONE2;
    }

    if (target->flags & ACTOR_FLAG_2000) {
        return ApiStatus_DONE2;
    }

    if (targetPart->eventFlags & ACTOR_PART_FLAG_40000) {
        return ApiStatus_DONE2;
    }

    if (targetPart->eventFlags & ACTOR_PART_FLAG_80000) {
        return ApiStatus_DONE2;
    }

    target->chillOutTurns = 4;
    target->chillOutAmount = 3;

    dispatch_damage_event_actor_0(target, 0, 10);

    x = target->curPos.x + target->headOffset.x + (target->size.x / 2);
    if (target->flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y = target->curPos.y + target->headOffset.y - target->size.y;
    } else if (!(target->flags & ACTOR_FLAG_8000)) {
        y = target->curPos.y + target->headOffset.y + target->size.y;
    } else {
        y = target->curPos.y + target->headOffset.y + target->size.y * 2;
    }
    z = target->curPos.z + target->headOffset.z + 5.0f;

    fx_stat_change(5, x, y, z, 1.0f, 60);
    sfx_play_sound(SOUND_2106);
    D_802A2CC0 = 1;

    return ApiStatus_DONE2;
}

EvtScript N(802A18F0) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Pray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A1C88) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Pray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A2020) = {
    EVT_WAIT(8)
    EVT_CALL(SetForegroundModelsVisible, FALSE)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, SOUND_2041)
    EVT_CALL(CreateNpc, NPC_BTL_SPIRIT, LVar0)
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, NPC_BTL_SPIRIT, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CALL(SetNpcPos, NPC_BTL_SPIRIT, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, NPC_BTL_SPIRIT, 0, NPC_DECORATION_WHITE_GLOW_BEHIND)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(8)
        EVT_ADD(LVar0, 67)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetForegroundModelsVisible, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802A222C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(PlaySound, SOUND_2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, EASING_CUBIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
        EVT_CALL(DeleteNpc, NPC_BTL_SPIRIT)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(PlaySound, SOUND_2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, EASING_CUBIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
        EVT_CALL(DeleteNpc, NPC_BTL_SPIRIT)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A267C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_ELSE
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(N(UnkStarFunc), 3)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UsePower) = {
    EVT_CALL(func_802A1518_7905E8)
    EVT_EXEC_WAIT(N(802A18F0))
    EVT_SET_CONST(LVar0, ANIM_BattleMuskular_Idle)
    EVT_EXEC_WAIT(N(802A2020))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMuskular_Shout)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(PlaySound, SOUND_244)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
    EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(func_802A163C_79070C)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetOwnerTarget, LVarA, LVarB)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.1), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.2), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.3), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.35), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.38), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.4), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.3), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.2), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.1), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_END_THREAD
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LOOP(30)
        EVT_CALL(func_802A153C_79060C)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_CALL(ChooseNextTarget, ITER_FIRST, 0)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_802A163C_79070C)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(func_802A16F4_7907C4)
    EVT_ELSE
        EVT_CALL(PlayerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 0, BS_FLAGS1_FORCE_HIT_IMMUNE | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_WAIT(5)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(func_802A1528_7905F8)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ShowMessageBox, BTL_MSG_CHILL_OUT_BEGIN, 60)
    EVT_END_IF
    EVT_CALL(PlayerYieldTurn)
    EVT_EXEC_WAIT(N(802A222C))
    EVT_EXEC_WAIT(N(802A267C))
    EVT_CALL(func_802A1528_7905F8)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(WaitForMessageBoxDone)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
