#include "mgm_02.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(D_80242650_E183D0);
extern EvtScript N(EVS_80244FD4);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [mgm_02_ENTRY_0]    { -300.0,  200.0,  200.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_mgm_02 },
};

EvtScript N(D_80242450_E181D0) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -300, -20, 200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, -20, 220)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerPos, 250, 200, 220)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 250, 200, 220)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_LABEL(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_NE(LVar1, -20)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_EXEC(N(D_80242450_E181D0))
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(D_80242650_E183D0))
    EVT_EXEC_WAIT(N(EVS_80244FD4))
    EVT_RETURN
    EVT_END
};
