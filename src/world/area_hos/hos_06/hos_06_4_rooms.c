#include "hos_06.h"

// unused, makes sense to be in this source file
API_CALLABLE(N(func_80240D30_A3A210)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(D_80244060_A3D540) = {
    EVT_CALL(RotateGroup, MODEL_g10, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244090_A3D570) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g12, LVar1, 0, 0, 1)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g54, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g55, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g56, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g57, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g58, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g86, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244260_A3D740) = {
    EVT_CALL(RotateGroup, MODEL_g10, LVar0, 1, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244290_A3D770) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g29, 1)
            EVT_CALL(SetGroupEnabled, MODEL_g81, 1)
            EVT_CALL(SetGroupEnabled, MODEL_g51, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetGroupEnabled, MODEL_g1, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g35, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetGroupEnabled, MODEL_g1, 1)
            EVT_CALL(SetGroupEnabled, MODEL_g35, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g29, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g81, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g31, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g51, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802443C0_A3D8A0) = {
    EVT_CALL(RotateGroup, MODEL_g32, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802443F0_A3D8D0) = {
    EVT_CALL(RotateGroup, MODEL_g61, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244420_A3D900) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, 100)
        EVT_CALL(SetGroupEnabled, MODEL_g31, 0)
        EVT_CALL(SetGroupEnabled, MODEL_g50, 1)
    EVT_ELSE
        EVT_CALL(SetGroupEnabled, MODEL_g31, 1)
        EVT_CALL(SetGroupEnabled, MODEL_g50, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802444B8) = {
    EVT_CALL(SetGroupEnabled, MODEL_g29, 0)
    EVT_CALL(SetGroupEnabled, MODEL_g81, 0)
    EVT_CALL(SetGroupEnabled, MODEL_g31, 0)
    EVT_CALL(SetGroupEnabled, MODEL_g51, 0)
    EVT_BIND_PADLOCK(EVT_PTR(N(D_80244420_A3D900)), TRIGGER_FLOOR_TOUCH, COLLIDER_o92, 0, 0, 1)
    EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_80244060_A3D540)), EVT_PTR(N(D_80244090_A3D570)), EVT_PTR(N(D_80244260_A3D740)), EVT_PTR(N(D_80244290_A3D770)), COLLIDER_o158, COLLIDER_o159, MODEL_g2, 0)
    EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802443C0_A3D8A0)), 0, 0, 0, COLLIDER_o161, COLLIDER_o160, MODEL_o1, 0)
    EVT_CALL(MakeDoorAdvanced, 1, EVT_PTR(N(D_802443F0_A3D8D0)), 0, 0, 0, COLLIDER_o163, COLLIDER_o162, MODEL_o1, 0)
    EVT_RETURN
    EVT_END
};
