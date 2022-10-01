#include "mgm_00.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(D_80243C40_E123E0);
extern EvtScript N(EVS_BindInteractTriggers);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [mgm_00_ENTRY_0]    { -152.0,    0.0, -218.0,   90.0 },
    [mgm_00_ENTRY_1]    {  -25.0,   30.0, -168.0,   90.0 },
    [mgm_00_ENTRY_2]    {   95.0,   30.0, -168.0,   90.0 },
    [mgm_00_ENTRY_3]    {  237.0,    0.0,  -53.0,  270.0 },
    [mgm_00_ENTRY_4]    {   20.0,    0.0,  -80.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_mgm_00 },
};

EvtScript N(D_80241850_E0FFF0) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/Pipe.inc.c"
#include "world/common/atomic/Pipe.data.inc.c"

EvtScript N(EVS_GotoMap_ToadTown) = {
    EVT_CALL(GotoMap, EVT_PTR("mac_03"), mac_03_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterPipe_ToadTown) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, mgm_00_ENTRY_0)
    EVT_SET(LVarB, COLLIDER_deili1)
    EVT_SET(LVarC, EVT_PTR(N(EVS_GotoMap_ToadTown)))
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitHorizontal))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_JumpAttack) = {
    EVT_CALL(GotoMap, EVT_PTR("mgm_01"), mgm_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterPipe_JumpAttack) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, mgm_00_ENTRY_1)
    EVT_SET(LVarB, COLLIDER_deili2)
    EVT_SET(LVarC, EVT_PTR(N(EVS_GotoMap_JumpAttack)))
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_SmashAttack) = {
    EVT_CALL(GotoMap, EVT_PTR("mgm_02"), mgm_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

const s32 N(rodata_pad) = 0;

EvtScript N(EVS_OnEnterPipe_SmashAttack) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, mgm_00_ENTRY_2)
    EVT_SET(LVarB, COLLIDER_deili3)
    EVT_SET(LVarC, EVT_PTR(N(EVS_GotoMap_SmashAttack)))
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_ToadTown)), TRIGGER_WALL_PUSH, COLLIDER_deili1, 1, 0)
    EVT_IF_EQ(GF_MGM_Unlocked_JumpAttack, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_JumpAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili2, 1, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_MGM_Unlocked_SmashAttack, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_SmashAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili3, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_IF_EQ(GF_MGM_Unlocked_JumpAttack, FALSE)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_o5, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_deili2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o5, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MGM_Unlocked_SmashAttack, FALSE)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_o9, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_deili3, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o9, FALSE)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mgm_00_ENTRY_0)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_SET(LVarB, 1)
            EVT_EXEC(N(EVS_Pipe_EnterHorizontal))
        EVT_CASE_EQ(mgm_00_ENTRY_1)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(N(EVS_Pipe_EnterVertical))
        EVT_CASE_EQ(mgm_00_ENTRY_2)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(N(EVS_Pipe_EnterVertical))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_EXEC_WAIT(N(D_80243C40_E123E0))
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(D_80241850_E0FFF0))
    EVT_EXEC(N(EVS_BindInteractTriggers))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
