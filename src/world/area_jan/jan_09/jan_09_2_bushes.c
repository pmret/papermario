#include "jan_09.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

#include "../common/MoveBush.inc.c"
#include "../common/MoveBushTemplates.h"

EvtScript N(EVS_MoveBush_RightShore) = EVT_MOVE_BUSHES(COLLIDER_o84,
    MODEL_o83, MODEL_o84, MV_RightShoreBushOffsetL, MV_RightShoreBushOffsetR);

EvtScript N(EVS_MoveBush_CliffTop1) = EVT_MOVE_BUSH(COLLIDER_o82,
    MODEL_o82, MV_CliffTopBush1OffsetR);

EvtScript N(EVS_MoveBush_CliffTop2) = EVT_MOVE_BUSHES(COLLIDER_o88,
    MODEL_o88, MODEL_o81, MV_CliffTopBush2OffsetL, MV_CliffTopBush2OffsetR);

EvtScript N(EVS_Inspect_MoveBush_RightShore) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o84, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_MoveBush_RightShore))
    Call(DisablePlayerInput, TRUE)
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_RightShoreBushOffsetR, LVar0)
        SetF(MV_RightShoreBushOffsetL, MV_RightShoreBushOffsetR)
        MulF(MV_RightShoreBushOffsetL, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_MoveBush_CliffTop1) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o82, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_MoveBush_CliffTop1))
    Call(DisablePlayerInput, TRUE)
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_CliffTopBush1OffsetR, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_MoveBush_CliffTop2) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o88, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_MoveBush_CliffTop2))
    Call(DisablePlayerInput, TRUE)
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_CliffTopBush2OffsetR, LVar0)
        SetF(MV_CliffTopBush2OffsetL, MV_CliffTopBush2OffsetR)
        MulF(MV_CliffTopBush2OffsetL, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ForceMoveCliffTopBushes) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o82, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o88, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_MoveBush_CliffTop1))
    Exec(N(EVS_MoveBush_CliffTop2))
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_CliffTopBush1OffsetR, LVar0)
        SetF(MV_CliffTopBush2OffsetR, LVar0)
        SetF(MV_CliffTopBush2OffsetL, MV_CliffTopBush2OffsetR)
        MulF(MV_CliffTopBush2OffsetL, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_80243EC0) = {
    Call(DisablePlayerInput, TRUE)
    Loop(3)
        Call(N(MoveBush_AnimateShearing), LVar1, 1)
        Wait(1)
        Call(N(MoveBush_AnimateShearing), LVar1, 0)
        Wait(1)
        Call(N(MoveBush_AnimateShearing), LVar1, -1)
        Wait(1)
    EndLoop
    Call(TranslateModel, LVar1, 0, 0, 0)
    Set(LVarA, LVar2)
    Call(GetModelCenter, LVar1)
    Call(DropItemEntity, ITEM_COIN, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE, LVarA)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(D_80243FC4_B69A74) = {
    Label(10)
        Label(0)
            IfEq(MV_Unk_05, 0)
                Wait(1)
                Goto(0)
            EndIf
        Set(LVar3, MV_Unk_05)
        Call(MakeLerp, 0, MV_Unk_05, 120, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Unk_05, LVar3)
            Sub(MV_Unk_05, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_802440C0) = {
    Call(DisablePlayerInput, TRUE)
    Wait(20)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Set(MV_Unk_05, 3600)
    Loop(60)
        Call(InterpPlayerYaw, MV_Unk_05, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        AddF(LVar0, Float(6.0))
        AddF(LVar1, Float(3.0))
        AddF(LVar2, Float(-29.0))
        DivF(LVar0, Float(1.09375))
        DivF(LVar1, Float(1.09375))
        DivF(LVar2, Float(1.09375))
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(UseSettingsFrom, CAM_DEFAULT, -25, 90, -330)
    Call(SetPanTarget, CAM_DEFAULT, -25, 90, -330)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetPlayerJumpscale, Float(0.296875))
    Call(PlayerJump, -25, 90, -330, 60)
    Call(SetPlayerPos, -25, 90, -330)
    Call(SetCamTarget, CAM_DEFAULT, -25, 90, -330)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(100)
    Return
    End
};

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o78);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 402, 20, 161 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_JAN09_Bush1_Coin,
        },
    }
};

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { 402.0f, 20.0f, 161.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o110);

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -153.0f, 20.0f, 475.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o116);

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { 147.0f, 20.0f, 489.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o117);

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { 193.0f, 20.0f, 473.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o154);

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { -93.0f, 20.0f, 289.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o155);

FoliageDropList N(Bush6_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -34, 22, 317 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_JAN09_Bush6_Coin,
        },
    }
};

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { -34.0f, 22.0f, 317.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .drops = &N(Bush6_Drops),
    .vectors = &N(Bush6_Effects),
};

FoliageModelList N(Bush7_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o118);

FoliageVectorList N(Bush7_Effects) = {
    .count = 1,
    .vectors = {
        { 34.0f, 20.0f, 167.0f },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush7_BushModels),
    .vectors = &N(Bush7_Effects),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o119);

FoliageVectorList N(Bush8_Effects) = {
    .count = 1,
    .vectors = {
        { 95.0f, 20.0f, 184.0f },
    }
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o153);

FoliageVectorList N(Bush9_Effects) = {
    .count = 1,
    .vectors = {
        { 334.0f, 20.0f, 287.0f },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .vectors = &N(Bush9_Effects),
};

FoliageModelList N(Bush10_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o121);

FoliageVectorList N(Bush10_Effects) = {
    .count = 1,
    .vectors = {
        { 388.0f, 20.0f, 279.0f },
    }
};

SearchBushConfig N(SearchBush_Bush10) = {
    .bush = &N(Bush10_BushModels),
    .vectors = &N(Bush10_Effects),
};

FoliageModelList N(Bush11_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o113);

FoliageVectorList N(Bush11_Effects) = {
    .count = 1,
    .vectors = {
        { 454.0f, 20.0f, 148.0f },
    }
};

SearchBushConfig N(SearchBush_Bush11) = {
    .bush = &N(Bush11_BushModels),
    .vectors = &N(Bush11_Effects),
};

FoliageModelList N(Bush12_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o115);

FoliageVectorList N(Bush12_Effects) = {
    .count = 1,
    .vectors = {
        { 359.0f, 20.0f, -127.0f },
    }
};

SearchBushConfig N(SearchBush_Bush12) = {
    .bush = &N(Bush12_BushModels),
    .vectors = &N(Bush12_Effects),
};

FoliageModelList N(Bush13_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o178);

FoliageVectorList N(Bush13_Effects) = {
    .count = 1,
    .vectors = {
        { -343.0f, 110.0f, -319.0f },
    }
};

SearchBushConfig N(SearchBush_Bush13) = {
    .bush = &N(Bush13_BushModels),
    .vectors = &N(Bush13_Effects),
};

FoliageModelList N(Bush14_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o177);

FoliageVectorList N(Bush14_Effects) = {
    .count = 1,
    .vectors = {
        { -286.0f, 112.0f, -381.0f },
    }
};

SearchBushConfig N(SearchBush_Bush14) = {
    .bush = &N(Bush14_BushModels),
    .vectors = &N(Bush14_Effects),
};

FoliageModelList N(Bush15_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o163);

FoliageVectorList N(Bush15_Effects) = {
    .count = 1,
    .vectors = {
        { -234.0f, 110.0f, -376.0f },
    }
};

SearchBushConfig N(SearchBush_Bush15) = {
    .bush = &N(Bush15_BushModels),
    .vectors = &N(Bush15_Effects),
};

FoliageModelList N(Bush16_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o164);

FoliageVectorList N(Bush16_Effects) = {
    .count = 1,
    .vectors = {
        { -57.0f, 110.0f, -438.0f },
    }
};

SearchBushConfig N(SearchBush_Bush16) = {
    .bush = &N(Bush16_BushModels),
    .vectors = &N(Bush16_Effects),
};

FoliageModelList N(Bush17_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o158);

FoliageVectorList N(Bush17_Effects) = {
    .count = 1,
    .vectors = {
        { 109.0f, 20.0f, -452.0f },
    }
};

SearchBushConfig N(SearchBush_Bush17) = {
    .bush = &N(Bush17_BushModels),
    .vectors = &N(Bush17_Effects),
};

FoliageModelList N(Bush18_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o159);

FoliageVectorList N(Bush18_Effects) = {
    .count = 1,
    .vectors = {
        { 159.0f, 20.0f, -485.0f },
    }
};

SearchBushConfig N(SearchBush_Bush18) = {
    .bush = &N(Bush18_BushModels),
    .vectors = &N(Bush18_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_09_ENTRY_3)
        Exec(N(EVS_ForceMoveCliffTopBushes))
    EndIf
    BindTrigger(Ref(N(EVS_Inspect_MoveBush_RightShore)), TRIGGER_WALL_PRESS_A, COLLIDER_o84, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_MoveBush_CliffTop1)), TRIGGER_WALL_PRESS_A, COLLIDER_o82, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_MoveBush_CliffTop2)), TRIGGER_WALL_PRESS_A, COLLIDER_o88, 1, 0)
    Exec(N(D_80243FC4_B69A74))
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o78, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o228, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o229, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o230, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush5)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o231, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush6)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o232, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush7)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o233, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush8)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o234, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush9)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o235, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush10)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o236, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush11)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o237, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush12)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o238, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush13)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o239, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush14)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o240, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush15)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o241, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush16)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o242, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush17)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o243, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush18)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o244, 1, 0)
    Return
    End
};
