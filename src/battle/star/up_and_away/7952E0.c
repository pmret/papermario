#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKalmar.h"
#include "entity.h"
#include "model.h"

extern EntityModelScript D_80283EE8;

#define NAMESPACE battle_star_up_and_away

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_7957F8(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 200;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] += 2;

    if (script->functionTemp[0] >= 254) {
        set_background_color_blend(0, 0, 0, 254);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802A15B4_795894(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 254;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] -= 5;

    if (script->functionTemp[0] <= 200) {
        set_background_color_blend(0, 0, 0, 200);

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802A1628_795908(Evt* script, s32 isInitialCall) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);
    u32 flags;

    script->varTable[0] = 0;
    flags = targetActor->flags;

    if (!(flags & ACTOR_FLAG_TARGET_ONLY)) {
        if (!(flags & ACTOR_FLAG_NO_DMG_APPLY)) {
            if (!(flags & ACTOR_FLAG_2000) && targetActor->actorBlueprint->upAndAwayChance != 0 && rand_int(100) <= targetActor->actorBlueprint->upAndAwayChance) {
                script->varTable[0] = 1;
            }
        } else {
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_DONE2;
}

EvtScript N(802A16D0) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
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
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
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

EvtScript N(802A1A68) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
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
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
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

EvtScript N(802A1E00) = {
    EVT_WAIT(8)
    EVT_CALL(SetForegroundModelsVisible, 0)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, 0x2041)
    EVT_CALL(CreateNpc, 100, LVar0)
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, 100, ((NPC_FLAG_40000)), TRUE)
    EVT_CALL(SetNpcPos, 100, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, 100, 0, 5)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 1)
    EVT_SET(LVar0, 0)
    EVT_LOOP(8)
        EVT_ADD(LVar0, 67)
        EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 30, 0, 10)
    EVT_CALL(SetForegroundModelsVisible, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802A200C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, 0x2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, 0x2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A245C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
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

EvtScript N(usePower) = {
    EVT_EXEC_WAIT(N(802A16D0))
    EVT_SET_CONST(LVar0, ANIM_BattleKalmar_Idle)
    EVT_EXEC_WAIT(N(802A1E00))
    EVT_CALL(SetNpcAnimation, 100, ANIM_BattleKalmar_Shout)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(20)
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    EVT_CALL(func_802A1518_7957F8)
    EVT_CALL(PlaySound, 0x247)
    EVT_CALL(PlayEffect, 0x39, 0, 0, 20, 0, EVT_FLOAT(1.0), 90, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(PlayEffect, 0x3A, 0, 0, 50, 0, 300, 100, 10, 40, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlayEffect, 0x39, 0, 0, 20, 0, EVT_FLOAT(1.0), 90, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(75)
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(func_802A1628_795908)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(ItemCheckHit, LVar1, 0, 0, 0, 0)
    EVT_IF_EQ(LVar1, 6)
        EVT_SET(LVar0, 0)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(DispatchEvent, LVar0, 61)
            EVT_CALL(SetActorRotationOffset, LVar0, 0, 10, 0)
            EVT_THREAD
                EVT_CALL(GetOwnerTarget, LVarB, LVar1)
                EVT_WAIT(10)
                EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(D_80283EE8))
                EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                EVT_SET(LVarD, LVar0)
                EVT_SET(LVarE, LVar1)
                EVT_SET(LVarF, LVar2)
                EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
                EVT_SETF(LVar0, EVT_FLOAT(0.2))
                EVT_CALL(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
                EVT_LOOP(4)
                    EVT_ADDF(LVar0, EVT_FLOAT(0.2))
                    EVT_CALL(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_SET(LVar0, 0)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 72)
                    EVT_CALL(SetVirtualEntityRotation, LVarA, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(PlaySound, 0x2052)
                EVT_SET(LVar0, LVarD)
                EVT_SET(LVar1, LVarE)
                EVT_SET(LVar2, LVarF)
                EVT_SET(LVar3, 0)
                EVT_LOOP(50)
                    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
                    EVT_CALL(SetVirtualEntityRotation, LVarA, 0, LVar3, 0)
                    EVT_ADD(LVar1, 6)
                    EVT_ADD(LVar3, 45)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(PlaySound, 0x2071)
                EVT_CALL(GetOwnerTarget, LVarA, LVar1)
                EVT_CALL(SetActorFlagBits, LVarA, 4, 1)
                EVT_SETF(LVar0, EVT_FLOAT(1.0))
                EVT_LOOP(18)
                    EVT_SUBF(LVar0, EVT_FLOAT(0.05))
                    EVT_CALL(SetActorScale, LVarA, LVar0, LVar0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorPos, LVarA, 0, -1000, 0)
                EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                EVT_LOOP(10)
                    EVT_CALL(PlayEffect, 0x11, 1, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_ADD(LVar1, 30)
                    EVT_WAIT(5)
                EVT_END_LOOP
                EVT_CALL(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, 1)
                EVT_CALL(RemoveActor, LVarA)
            EVT_END_THREAD
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(PlayerDamageEnemy, LVar0, 0, 65535, 0, 0, BS_FLAGS1_800 | BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(5)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(70)
    EVT_CALL(func_802A15B4_795894)
    EVT_EXEC_WAIT(N(802A200C))
    EVT_CALL(func_80276EFC)
    EVT_EXEC_WAIT(N(802A245C))
    EVT_RETURN
    EVT_END
};
