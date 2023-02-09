#include "jan_14.h"

#include "world/common/todo/PullVine.inc.c"

EvtScript N(D_80241570_B7B5C0) = {
    EVT_CALL(GetModelCenter, LVarE)
    EVT_SET(LVar6, LVar0)
    EVT_SET(LVar7, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_ADD(LVar7, -20)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(N(PullVine_WaitForPlayerGrab), LVar6, LVar7, LVar8, 20)
    EVT_CALL(GetPlayerActionState, LVar1)
    EVT_IF_NE(LVar1, ACTION_STATE_JUMP)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(GetModelCenter, LVarD)
        EVT_CALL(PlaySoundAt, SOUND_2089, 0, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(0.0))
        EVT_SETF(LVar1, EVT_FLOAT(0.0))
        EVT_THREAD
            EVT_LOOP(3)
                EVT_IF_NE(LVar9, 0)
                    EVT_CALL(TranslateModel, LVar9, -2, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarA, 0)
                    EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarB, 0)
                    EVT_CALL(TranslateModel, LVarB, 2, 0, 0)
                EVT_END_IF
                EVT_WAIT(1)
                EVT_IF_NE(LVar9, 0)
                    EVT_CALL(TranslateModel, LVar9, 2, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarA, 0)
                    EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarB, 0)
                    EVT_CALL(TranslateModel, LVarB, -2, 0, 0)
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_NE(LVar9, 0)
                EVT_CALL(TranslateModel, LVar9, 0, 0, 0)
            EVT_END_IF
            EVT_IF_NE(LVarA, 0)
                EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
            EVT_END_IF
            EVT_IF_NE(LVarB, 0)
                EVT_CALL(TranslateModel, LVarB, 0, 0, 0)
            EVT_END_IF
        EVT_END_THREAD
        EVT_IF_EQ(LVar5, 0)
            EVT_EXEC(MV_Unk_0A)
        EVT_ELSE
            EVT_THREAD
                EVT_WAIT(LVar5)
                EVT_EXEC(MV_Unk_0A)
            EVT_END_THREAD
        EVT_END_IF
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000D)
        EVT_LOOP(50)
            EVT_CALL(N(PullVine_UpdatePosition), LVar0, EVT_FLOAT(-15.0), LVar2)
            EVT_ADDF(LVar1, LVar2)
            EVT_MULF(LVar1, EVT_FLOAT(0.93))
            EVT_ADDF(LVar0, LVar1)
            EVT_CALL(TranslateModel, LVarD, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVarE, 0, LVar0, 0)
            EVT_SET(LVar3, LVar7)
            EVT_ADD(LVar3, LVar0)
            EVT_SET(LVar4, LVar8)
            EVT_ADD(LVar4, 2)
            EVT_ADD(LVar3, 5)
            EVT_CALL(SetPlayerPos, LVar6, LVar3, LVar4)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, LVarF)
        EVT_CALL(SetPlayerJumpscale, 1)
        EVT_CALL(PlayerJump, LVar6, LVar1, LVar4, 10)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_CALL(GetModelCenter, LVarD)
        EVT_CALL(PlaySoundAt, SOUND_2089, 0, LVar0, LVar1, LVar2)
        EVT_THREAD
            EVT_WAIT(10)
            EVT_LOOP(5)
                EVT_IF_NE(LVar9, 0)
                    EVT_CALL(TranslateModel, LVar9, -2, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarA, 0)
                    EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarB, 0)
                    EVT_CALL(TranslateModel, LVarB, 2, 0, 0)
                EVT_END_IF
                EVT_WAIT(1)
                EVT_IF_NE(LVar9, 0)
                    EVT_CALL(TranslateModel, LVar9, 2, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarA, 0)
                    EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarB, 0)
                    EVT_CALL(TranslateModel, LVarB, -2, 0, 0)
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_NE(LVar9, 0)
                EVT_CALL(TranslateModel, LVar9, 0, 0, 0)
            EVT_END_IF
            EVT_IF_NE(LVarA, 0)
                EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
            EVT_END_IF
            EVT_IF_NE(LVarB, 0)
                EVT_CALL(TranslateModel, LVarB, 0, 0, 0)
            EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_SETF(LVar0, EVT_FLOAT(-15.0))
            EVT_SETF(LVar1, EVT_FLOAT(0.0))
            EVT_LOOP(100)
                EVT_CALL(N(PullVine_UpdatePosition), LVar0, EVT_FLOAT(20.0), LVar2)
                EVT_ADDF(LVar1, LVar2)
                EVT_MULF(LVar1, EVT_FLOAT(0.93))
                EVT_ADDF(LVar0, LVar1)
                EVT_CALL(TranslateModel, LVarD, 0, LVar0, 0)
                EVT_CALL(TranslateModel, LVarE, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/PullVineSub.inc.c"

EvtScript N(D_80241E10_B7BE60) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o12, SOUND_209F, 0)
    EVT_SET(LVar0, MV_Unk_00)
    EVT_SET(LVar1, MV_Unk_01)
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_LOOP(60)
        EVT_SETF(LVar2, MV_Unk_00)
        EVT_SETF(LVar3, MV_Unk_01)
        EVT_SUBF(LVar2, LVar0)
        EVT_SUBF(LVar3, LVar1)
        EVT_SETF(LVar4, LVar2)
        EVT_SETF(LVar5, LVar3)
        EVT_MULF(LVar4, EVT_FLOAT(0.09375))
        EVT_MULF(LVar5, EVT_FLOAT(0.09375))
        EVT_MULF(LVar6, EVT_FLOAT(0.8))
        EVT_MULF(LVar7, EVT_FLOAT(0.8))
        EVT_ADDF(LVar6, LVar4)
        EVT_ADDF(LVar7, LVar5)
        EVT_ADDF(LVar0, LVar6)
        EVT_ADDF(LVar1, LVar7)
        EVT_CALL(TranslateModel, MODEL_o40, MV_Unk_00, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o54, MV_Unk_01, 0, 0)
        EVT_CALL(N(PullVine_ShearBushModel), 55, LVar6)
        EVT_CALL(N(PullVine_ShearBushModel), 57, LVar7)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241FD8_B7C028) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o12, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(MV_Unk_01, LVar0)
        EVT_SETF(MV_Unk_00, MV_Unk_01)
        EVT_MULF(MV_Unk_01, EVT_FLOAT(1.5))
        EVT_MULF(MV_Unk_00, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802420A8_B7C0F8) = {
    EVT_SWITCH(LVarC)
        EVT_CASE_EQ(1)
            EVT_EXEC(N(D_80241E10_B7BE60))
            EVT_EXEC(N(D_80241FD8_B7C028))
        EVT_CASE_EQ(2)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar0, -20)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetNpcPos, NPC_JungleFuzzy_01, LVar0, 100, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_JungleFuzzy_01, NPC_FLAG_GRAVITY | NPC_FLAG_8000, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar2, 15)
            EVT_CALL(MakeItemEntity, ITEM_FIRE_FLOWER, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN14_PullVine_FireFlower)
        EVT_CASE_EQ(4)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar0, -20)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetNpcPos, NPC_JungleFuzzy_02, LVar0, 100, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_JungleFuzzy_02, NPC_FLAG_GRAVITY | NPC_FLAG_8000, TRUE)
        EVT_CASE_EQ(5)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar2, 15)
            EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN14_PullVine_Mushroom)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupVines) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o10, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o78, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o79, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o76, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o80, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, jan_14_ENTRY_1)
        EVT_SET(LVarC, 1)
    EVT_ELSE
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(D_80241E10_B7BE60))
        EVT_EXEC(N(D_80241FD8_B7C028))
    EVT_END_IF
    EVT_SET(LVarF, 7)
    EVT_SET(MV_Unk_0A, EVT_PTR(N(D_802420A8_B7C0F8)))
    EVT_SET(LVarD, 69)
    EVT_SET(LVarE, 70)
    EVT_SET(LVar9, 25)
    EVT_SET(LVarA, 26)
    EVT_SET(LVarB, 27)
    EVT_SET(LVar5, 0)
    EVT_EXEC(N(D_80241570_B7B5C0))
    EVT_SET(LVarC, 2)
    EVT_SET(LVarD, 60)
    EVT_SET(LVarE, 61)
    EVT_SET(LVar9, 11)
    EVT_SET(LVarA, 12)
    EVT_SET(LVarB, 13)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(D_80241570_B7B5C0))
    EVT_SET(LVarC, 3)
    EVT_SET(LVarD, 63)
    EVT_SET(LVarE, 64)
    EVT_SET(LVar9, 16)
    EVT_SET(LVarA, 17)
    EVT_SET(LVarB, 0)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(D_80241570_B7B5C0))
    EVT_SET(LVarC, 4)
    EVT_SET(LVarD, 66)
    EVT_SET(LVarE, 67)
    EVT_SET(LVar9, 20)
    EVT_SET(LVarA, 21)
    EVT_SET(LVarB, 22)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(D_80241570_B7B5C0))
    EVT_SET(LVarC, 5)
    EVT_SET(LVarD, 72)
    EVT_SET(LVarE, 73)
    EVT_SET(LVar9, 31)
    EVT_SET(LVarA, 30)
    EVT_SET(LVarB, 0)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(D_80241570_B7B5C0))
    EVT_RETURN
    EVT_END
};
