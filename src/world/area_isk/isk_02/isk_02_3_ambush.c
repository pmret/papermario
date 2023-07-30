#include "isk_02.h"

extern EvtScript N(EVS_ManageSarcophagus1);
extern EvtScript N(EVS_ManageSarcophagus2);
extern EvtScript N(EVS_ManageSarcophagus3);

API_CALLABLE(N(AwaitPlayerMummyAmbush)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);

    if (dist2D(x, y, gPlayerStatus.pos.x, gPlayerStatus.pos.z) > 250.0f) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupSarcophagi) = {
    EVT_SET(AF_ISK02_OpeningSarcophagus1, FALSE)
    EVT_SET(AF_ISK02_OpeningSarcophagus2, FALSE)
    EVT_SET(AF_ISK02_OpeningSarcophagus3, FALSE)
    EVT_EXEC(N(EVS_ManageSarcophagus1))
    EVT_EXEC(N(EVS_ManageSarcophagus2))
    EVT_EXEC(N(EVS_ManageSarcophagus3))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h1o, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h2o, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h3o, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSarcophagus) = {
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(PlaySoundAtModel, LVar3, SOUND_1D1, SOUND_SPACE_MODE_0)
        EVT_CALL(TranslateModel, LVar3, 0, 0, 13)
        EVT_WAIT(3)
        EVT_CALL(MakeLerp, 0, 35, 9, EASING_COS_IN_OUT)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(1.1))
            EVT_CALL(TranslateModel, LVar3, LVar2, 0, 13)
            EVT_CALL(RotateModel, LVar3, LVar0, 0, 1, 0)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_WAIT(3)
    EVT_ELSE
        EVT_CALL(TranslateModel, LVar3, EVT_FLOAT(38.5), 0, 13)
        EVT_CALL(RotateModel, LVar3, 35, 0, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageSarcophagus1) = {
    EVT_IF_EQ(AF_ISK02_Sarcophagus1Opened, FALSE)
        EVT_LABEL(5)
            EVT_CALL(N(AwaitPlayerMummyAmbush), -210, 580)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(5)
            EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_ISK02_OpeningSarcophagus1, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Pokey_01, NPC_FLAG_INVISIBLE, FALSE)
    EVT_SET(LVar0, AF_ISK02_Sarcophagus1Opened)
    EVT_SET(LVar3, MODEL_g346)
    EVT_EXEC_WAIT(N(EVS_OpenSarcophagus))
    EVT_SET(AF_ISK02_OpeningSarcophagus1, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h1c, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_h1o, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(AF_ISK02_Sarcophagus1Opened, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageSarcophagus2) = {
    EVT_IF_EQ(AF_ISK02_Sarcophagus2Opened, FALSE)
        EVT_LABEL(5)
            EVT_CALL(N(AwaitPlayerMummyAmbush), -30, 670)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(5)
            EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_SPIKE_SHIELD, -133, 1, 500, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ISK02_Item_SpikeShield)
    EVT_SET(AF_ISK02_OpeningSarcophagus2, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Pokey_02, NPC_FLAG_INVISIBLE, FALSE)
    EVT_SET(LVar0, AF_ISK02_Sarcophagus2Opened)
    EVT_SET(LVar3, MODEL_g348)
    EVT_EXEC_WAIT(N(EVS_OpenSarcophagus))
    EVT_SET(AF_ISK02_OpeningSarcophagus2, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h2c, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_h2o, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(AF_ISK02_Sarcophagus2Opened, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageSarcophagus3) = {
    EVT_IF_EQ(AF_ISK02_Sarcophagus3Opened, FALSE)
        EVT_LABEL(5)
            EVT_CALL(N(AwaitPlayerMummyAmbush), 220, 600)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(5)
            EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_ISK02_OpeningSarcophagus3, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Pokey_03, NPC_FLAG_INVISIBLE, FALSE)
    EVT_SET(LVar0, AF_ISK02_Sarcophagus3Opened)
    EVT_SET(LVar3, MODEL_g350)
    EVT_EXEC_WAIT(N(EVS_OpenSarcophagus))
    EVT_SET(AF_ISK02_OpeningSarcophagus3, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h3c, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_h3o, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(AF_ISK02_Sarcophagus3Opened, TRUE)
    EVT_RETURN
    EVT_END
};
