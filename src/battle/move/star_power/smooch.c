#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleMisstar.h"

#define NAMESPACE battle_move_smooch

#include "common/StarPower.inc.c"

#include "common/AddHP.inc.c"

API_CALLABLE(func_802A156C_7922FC) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_recover(0, var1, var2, var3, var4);

    return ApiStatus_DONE2;
}

EvtScript N(802A1630) = {
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

EvtScript N(802A19C8) = {
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

EvtScript N(802A1D60) = {
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

EvtScript N(802A1F6C) = {
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

EvtScript N(802A23BC) = {
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

Vec2i N(RecoverEffectPositions)[] = {
    {  15,  15 },
    { -33,  27 },
    { -22, -26 },
    {  10, -35 },
    {  35,   0 },
};

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(802A1630))
    EVT_SET_CONST(LVar0, ANIM_BattleMisstar_Still)
    EVT_EXEC_WAIT(N(802A1D60))
    EVT_WAIT(16)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 180, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 150, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 120, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 90, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 60, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 30, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_ADD(LVar0, 30)
    EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 20, 0, EASING_COS_IN_OUT)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMisstar_Idle)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_ADD(LVar1, 15)
    EVT_ADD(LVar2, -5)
    EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 10, 0, EASING_COS_IN_OUT)
    EVT_CALL(PlaySound, SOUND_245)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 1, 0)
        EVT_WAIT(2)
        EVT_USE_BUF(EVT_PTR(N(RecoverEffectPositions)))
        EVT_LOOP(ARRAY_COUNT(N(RecoverEffectPositions)))
            EVT_BUF_READ2(LVar5, LVar6)
            EVT_SET(LVar3, LVar0)
            EVT_SET(LVar4, LVar1)
            EVT_ADD(LVar3, LVar5)
            EVT_ADD(LVar4, LVar6)
            EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar3, LVar4, LVar2, 1, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_ADD(LVar0, 5)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar0, 25)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 10, 0, EASING_COS_IN_OUT)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FallBack)
    EVT_WAIT(12)
    EVT_THREAD
        EVT_EXEC_WAIT(N(802A1F6C))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.35), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.38), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.4), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.35), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.38), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.4), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.95), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_LOOP(10)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_CALL(func_802A156C_7922FC, LVar0, LVar1, LVar2, 20)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 20)
    EVT_CALL(N(AddHP), 20)
    EVT_THREAD
        EVT_CALL(N(UnkBackgroundFunc))
    EVT_END_THREAD
    EVT_CALL(func_80276EFC)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_160)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};
