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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Run)
    EVT_LABEL(0)
        EVT_CALL(GetAngleToNPC, NPC_PARTNER, LVar0)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(4.0), LVar0)
        EVT_CALL(InterpPlayerYaw, LVar0, 0)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyPartnerAround) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(EnableNpcBlur, NPC_PARTNER, TRUE)
    EVT_LABEL(10)
        EVT_CALL(LoadPath, 500, EVT_PTR(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
        EVT_LABEL(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};
