#include "mac_01.h"

#define NAME_SUFFIX _IntroScene
#include "world/common/todo/UnkMachiFunc.inc.c"
#define NAME_SUFFIX

EvtScript N(D_80261880_822100) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(EnableModel, MODEL_ju_1, FALSE)
    EVT_CALL(N(UnkMachiFunc_IntroScene))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -560, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -560, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, NPC_Luigi, -460, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_Luigi, 90)
    EVT_THREAD
        EVT_CALL(func_802D1270, -100, 0, EVT_FLOAT(4.0))
        EVT_CALL(func_802D1270, -25, -25, EVT_FLOAT(4.0))
        EVT_CALL(func_802D1270, 0, -100, EVT_FLOAT(4.0))
        EVT_CALL(func_802D1270, 0, -400, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Luigi, EVT_FLOAT(4.0))
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Run)
        EVT_CALL(NpcMoveTo, NPC_Luigi, -100, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_RunBack)
        EVT_CALL(NpcMoveTo, NPC_Luigi, -25, -25, 0)
        EVT_CALL(NpcMoveTo, NPC_Luigi, 0, -100, 0)
        EVT_CALL(NpcMoveTo, NPC_Luigi, 0, -340, 0)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_IdleBack)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(MakeLerp, 300, 400, 100, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(75)
    EVT_CALL(GotoMap, EVT_PTR("osr_00"), osr_00_ENTRY_4)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
