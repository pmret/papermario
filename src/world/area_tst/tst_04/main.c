
#include "tst_04.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupReflection);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(PushGoompaTest)) {
    Npc* npc = get_npc_safe(NPC_Goompa);

    if (npc != NULL && npc->curFloor == COLLIDER_o3) {
        f32 sinTheta;
        f32 cosTheta;
        f32 xTemp;
        f32 zTemp;

        dist2D(npc->pos.x, npc->pos.z, 0.0f, -100.0f);
        sinTheta = sin_rad(1 / 180.0f * PI_S);
        cosTheta = cos_rad(1 / 180.0f * PI_S);
        xTemp = npc->pos.x - 0.0f;
        zTemp = npc->pos.z - -100.0f;
        npc->pos.x = npc->pos.x + (((cosTheta * xTemp) + (sinTheta * zTemp)) - xTemp);
        npc->pos.z = npc->pos.z + (((-sinTheta * xTemp) + (cosTheta * zTemp)) - zTemp);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(PushPartnerTest)) {
    Npc *npc = get_npc_safe(NPC_PARTNER);
    f32 angle, sinAngle, cosAngle;
    f32 dist;
    f32 x0, x1;
    f32 z0, z1;

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    dist = dist2D(npc->pos.x, npc->pos.z, -250.0f, -100.0f);

    angle = evt_get_variable(script, LVar0) - 1;
    sinAngle = sin_rad(DEG_TO_RAD(angle));
    cosAngle = cos_rad(DEG_TO_RAD(angle));
    x0 = dist * cosAngle;
    z0 = dist * -sinAngle;

    angle = evt_get_variable(script, LVar0);
    sinAngle = sin_rad(DEG_TO_RAD(angle));
    cosAngle = cos_rad(DEG_TO_RAD(angle));
    x1 = dist * cosAngle;
    z1 = dist * -sinAngle;

    npc->pos.x += x1 - x0;
    npc->pos.z += z1 - z0;

    return ApiStatus_DONE2;
}

EntryList N(Entrances) = {
    [tst_04_ENTRY_0]    { -484.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_1]    {  484.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_04_ENTRY_A]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

EvtScript N(EVS_GotoMap_tst_03_1) = {
    Call(GotoMap, Ref("tst_03"), tst_03_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_UpdateMovingFloor) = {
    Label(0)
        Call(MakeLerp, 0, 100, 50, EASING_COS_IN_OUT)
        Label(10)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o5, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o5)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(MakeLerp, 100, 0, 50, EASING_COS_IN_OUT)
        Label(20)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o5, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o5)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(20)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UpdateSpinningFloor) = {
    Label(0)
        Call(MakeLerp, 0, 360, 360, EASING_LINEAR)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o3, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, COLLIDER_o3)
            Call(N(PushGoompaTest))
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Goto(0)
        Call(MakeLerp, 20, -20, 40, EASING_COS_IN_OUT)
        Label(20)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o3, LVar0, 0, 0, 1)
            Call(UpdateColliderTransform, COLLIDER_o3)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(20)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UpdateSpinningWall) = {
    Label(0)
        Call(MakeLerp, 0, 360, 360, EASING_LINEAR)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o1, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, COLLIDER_o1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TESTING)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    BindTrigger(Ref(N(EVS_GotoMap_tst_03_1)), TRIGGER_WALL_PUSH, COLLIDER_deilitw, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o5, MODEL_o5)
    Call(ParentColliderToModel, COLLIDER_o3, MODEL_o3)
    Call(ParentColliderToModel, COLLIDER_o1, MODEL_o1)
    Call(ParentColliderToModel, COLLIDER_o2, MODEL_o2)
    Call(ParentColliderToModel, COLLIDER_o18, MODEL_o18)
    Exec(N(EVS_UpdateMovingFloor))
    Exec(N(EVS_UpdateSpinningFloor))
    Exec(N(EVS_UpdateSpinningWall))
    Exec(N(EVS_SetupReflection))
    Return
    End
};
