#include "omo_03.h"
#include "entity.h"

#define NAME_SUFFIX _Spring
#include "world/common/EnableCameraFollowPlayerY.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_TetherCamToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring_Exit) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
    EVT_IF_EQ(AF_OMO_04, FALSE)
        EVT_CALL(N(EnableCameraFollowPlayerY_Spring))
        EVT_THREAD
            EVT_WAIT(6)
            EVT_CALL(GotoMap, EVT_PTR("mac_04"), mac_04_ENTRY_2)
            EVT_WAIT(100)
        EVT_END_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, -245, 270, 250, 20)
    EVT_ELSE
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump, -95, 0, 250, 25)
        EVT_SET(AF_OMO_04, FALSE)
    EVT_END_IF
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_EnterSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 100)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
    EVT_THREAD
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CASE_EQ(PARTNER_BOW)
            EVT_CASE_EQ(PARTNER_WATT)
            EVT_CASE_DEFAULT
                EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.7))
                EVT_CALL(NpcJump0, NPC_PARTNER, -150, 25, 250, 37)
                EVT_CALL(NpcJump0, NPC_PARTNER, -110, 0, 190, 20)
        EVT_END_SWITCH
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, -150, 25, 250, 25)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -250, 60, 50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -150, 0, 250, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring_Exit)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 203, 0, 200, 0, MODEL_o930, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OMO03_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 400, 60, -50, 0, ITEM_STONE_CAP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO03_HiddenItem_StoneCap)
    EVT_RETURN
    EVT_END
};
