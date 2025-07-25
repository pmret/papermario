#include "isk_02.h"

extern EvtScript N(EVS_ManageSarcophagus1);
extern EvtScript N(EVS_ManageSarcophagus2);
extern EvtScript N(EVS_ManageSarcophagus3);

API_CALLABLE(N(AwaitPlayerMummyAmbush)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);

    if (dist2D(x, y, gPlayerStatus.pos.x, gPlayerStatus.pos.z) > 250.0f) {
        script->varTable[0] = false;
    } else {
        script->varTable[0] = true;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupSarcophagi) = {
    Set(AF_ISK02_OpeningSarcophagus1, false)
    Set(AF_ISK02_OpeningSarcophagus2, false)
    Set(AF_ISK02_OpeningSarcophagus3, false)
    Exec(N(EVS_ManageSarcophagus1))
    Exec(N(EVS_ManageSarcophagus2))
    Exec(N(EVS_ManageSarcophagus3))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h1o, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h2o, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h3o, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_OpenSarcophagus) = {
    IfEq(LVar0, 0)
        Call(PlaySoundAtModel, LVar3, SOUND_SARCOPHAGUS_OPEN, SOUND_SPACE_DEFAULT)
        Call(TranslateModel, LVar3, 0, 0, 13)
        Wait(3)
        Call(MakeLerp, 0, 35, 9, EASING_COS_IN_OUT)
        Label(10)
            Call(UpdateLerp)
            Set(LVar2, LVar0)
            MulF(LVar2, Float(1.1))
            Call(TranslateModel, LVar3, LVar2, 0, 13)
            Call(RotateModel, LVar3, LVar0, 0, 1, 0)
            Add(LVar0, 1)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(10)
            EndIf
        Wait(3)
    Else
        Call(TranslateModel, LVar3, Float(38.5), 0, 13)
        Call(RotateModel, LVar3, 35, 0, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_ManageSarcophagus1) = {
    IfEq(AF_ISK02_Sarcophagus1Opened, false)
        Label(5)
            Call(N(AwaitPlayerMummyAmbush), -210, 580)
            Wait(1)
            IfEq(LVar0, 0)
                Goto(5)
            EndIf
    EndIf
    Set(AF_ISK02_OpeningSarcophagus1, true)
    Call(SetNpcFlagBits, NPC_Pokey_01, NPC_FLAG_INVISIBLE, false)
    Set(LVar0, AF_ISK02_Sarcophagus1Opened)
    Set(LVar3, MODEL_g346)
    ExecWait(N(EVS_OpenSarcophagus))
    Set(AF_ISK02_OpeningSarcophagus1, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h1c, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_h1o, COLLIDER_FLAGS_UPPER_MASK)
    Set(AF_ISK02_Sarcophagus1Opened, true)
    Return
    End
};

EvtScript N(EVS_ManageSarcophagus2) = {
    IfEq(AF_ISK02_Sarcophagus2Opened, false)
        Label(5)
            Call(N(AwaitPlayerMummyAmbush), -30, 670)
            Wait(1)
            IfEq(LVar0, 0)
                Goto(5)
            EndIf
    EndIf
    Call(MakeItemEntity, ITEM_SPIKE_SHIELD, -133, 1, 500, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ISK02_Item_SpikeShield)
    Set(AF_ISK02_OpeningSarcophagus2, true)
    Call(SetNpcFlagBits, NPC_Pokey_02, NPC_FLAG_INVISIBLE, false)
    Set(LVar0, AF_ISK02_Sarcophagus2Opened)
    Set(LVar3, MODEL_g348)
    ExecWait(N(EVS_OpenSarcophagus))
    Set(AF_ISK02_OpeningSarcophagus2, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h2c, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_h2o, COLLIDER_FLAGS_UPPER_MASK)
    Set(AF_ISK02_Sarcophagus2Opened, true)
    Return
    End
};

EvtScript N(EVS_ManageSarcophagus3) = {
    IfEq(AF_ISK02_Sarcophagus3Opened, false)
        Label(5)
            Call(N(AwaitPlayerMummyAmbush), 220, 600)
            Wait(1)
            IfEq(LVar0, 0)
                Goto(5)
            EndIf
    EndIf
    Set(AF_ISK02_OpeningSarcophagus3, true)
    Call(SetNpcFlagBits, NPC_Pokey_03, NPC_FLAG_INVISIBLE, false)
    Set(LVar0, AF_ISK02_Sarcophagus3Opened)
    Set(LVar3, MODEL_g350)
    ExecWait(N(EVS_OpenSarcophagus))
    Set(AF_ISK02_OpeningSarcophagus3, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_h3c, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_h3o, COLLIDER_FLAGS_UPPER_MASK)
    Set(AF_ISK02_Sarcophagus3Opened, true)
    Return
    End
};
