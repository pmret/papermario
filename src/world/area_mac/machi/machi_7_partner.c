#include "machi.h"
#include "sprite/player.h"

Vec3f N(FlightPath)[] = {
    { -332.0,    10.0,  120.0 },
    { -160.0,    50.0,  300.0 },
    {  -71.0,    60.0,  130.0 },
    {  105.0,    70.0,  262.0 },
    {  221.0,    80.0,  120.0 },
    {  404.0,    65.0,  150.0 },
    {  238.0,    50.0,  -57.0 },
    {   63.0,    50.0,  -42.0 },
    { -131.0,    20.0,  144.0 },
    {  -75.0,    80.0,  -60.0 },
    {  200.0,    40.0, -300.0 },
    {   20.0,     0.0, -280.0 },
    {   70.0,     0.0,   80.0 },
    { -332.0,    10.0,  120.0 },
};

EvtScript N(EVS_ChasePartner) = {
    Call(SetPlayerAnimation, ANIM_Mario1_Run)
    Label(0)
        Call(GetAngleToNPC, NPC_PARTNER, LVar0)
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        Call(AddVectorPolar, LVar1, LVar3, Float(4.0), LVar0)
        Call(InterpPlayerYaw, LVar0, 0)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_FlyPartnerAround) = {
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING, TRUE)
    Call(EnableNpcBlur, NPC_PARTNER, TRUE)
    Label(10)
        Call(LoadPath, 500, Ref(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
        Label(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 1)
                Goto(0)
            EndIf
        Goto(10)
    Return
    End
};
