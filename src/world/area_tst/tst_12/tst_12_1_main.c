#include "tst_12.h"
#include "effects.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [tst_12_ENTRY_0]    {  416.0,    0.0,   76.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

EvtScript N(D_80240050_B1D340) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVar2, LVar1, LVar3)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVarE, LVar1, 200)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TESTING)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o92, SURFACE_TYPE_FLOWERS)
    EVT_SET(LVar0, 544)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 100)
    EVT_SET(LVar3, 386)
    EVT_SET(LVar4, 174)
    EVT_SET(LVar5, 40)
    EVT_EXEC(N(D_80240050_B1D340))
    EVT_SET(LVar0, 327)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 24)
    EVT_SET(LVar3, 89)
    EVT_SET(LVar4, 252)
    EVT_SET(LVar5, 40)
    EVT_EXEC(N(D_80240050_B1D340))
    EVT_RETURN
    EVT_END
};
