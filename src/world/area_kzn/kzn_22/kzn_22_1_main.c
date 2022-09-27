#include "kzn_22.h"

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

extern EvtScript N(EVS_802403E0);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EvtScript N(D_802404EC_C9A6EC) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, 3)
    EVT_THREAD
        EVT_SET(LVar0, 3)
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 600)
        EVT_SET(LVar4, -400)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 1)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240608_C9A808) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, 4)
    EVT_THREAD
        EVT_SET(LVar0, 4)
        EVT_SET(LVar1, 500)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, -400)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240724_C9A924) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseExitHeading, 60, kzn_22_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, "kzn_20", kzn_20_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240790_C9A990) = {
    EVT_BIND_TRIGGER(N(D_80240724_C9A924), TRIGGER_FLOOR_TOUCH, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802407BC_C9A9BC) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yougan1_1, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(10)
    EVT_CALL(SetTexPanOffset, 6, 0, LVar0, 0)
    EVT_CALL(SetTexPanOffset, 6, 1, LVar1, LVar2)
    EVT_ADD(LVar0, 0xFFFFFBB4)
    EVT_ADD(LVar1, 300)
    EVT_ADD(LVar2, -500)
    EVT_WAIT(1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802408A8_C9AAA8) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yougan2_2, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
    EVT_CALL(SetTexPanOffset, 1, 0, LVar0, LVar1)
    EVT_ADD(LVar0, 300)
    EVT_ADD(LVar1, -500)
    EVT_WAIT(1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240958_C9AB58) = {
    EVT_LOOP(0)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetModelCenter, MODEL_yu)
            EVT_CALL(GetPlayerPos, LVar0, LVar3, LVar2)
            EVT_IF_LT(LVar3, LVar1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_LAKILESTER)
            EVT_CALL(InterruptUsePartner) 
            EVT_CALL(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/GetFloorCollider.inc.c"

EvtScript N(D_80240A34_C9AC34) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(SetTexPanner, MODEL_yu1, 2)
    EVT_CALL(SetTexPanner, MODEL_yu, 2)
    EVT_CALL(EnableModel, MODEL_yu, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o591, MODEL_yu)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_SET(LVarA, 0)
    EVT_LABEL(10)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o591)
    EVT_CALL(SetTexPanOffset, 2, 0, LVar0, LVar1)
    EVT_CALL(SetTexPanOffset, 2, 1, LVar2, LVar3)
    EVT_SUB(LVar0, 700)
    EVT_ADD(LVar1, 700)
    EVT_ADD(LVar2, 200)
    EVT_SUB(LVar3, 300)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(N(GetFloorCollider), LVar0)
            EVT_IF_EQ(LVar0, 9)
                EVT_EXEC(N(D_80240958_C9AB58))
                EVT_CALL(EnableModel, MODEL_yu, TRUE)
                EVT_CALL(EnableModel, MODEL_yu1, FALSE)
                EVT_SET(LVarA, 10)
            EVT_END_IF
        EVT_CASE_EQ(10)
            EVT_IF_LT(LVar4, 140)
                EVT_SET(LVar5, EVT_FLOAT(1.5))
            EVT_ELSE
                EVT_IF_EQ(AF_KZN_10, FALSE)
                    EVT_SET(LVar5, EVT_FLOAT(0.0))
                EVT_ELSE
                    EVT_IF_LT(LVar4, 285)
                        EVT_SET(LVar5, EVT_FLOAT(2.8))
                    EVT_ELSE
                        EVT_SET(LVar5, EVT_FLOAT(0.0))
                        EVT_SET(LVarA, -1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_ADDF(LVar4, LVar5)
    EVT_CALL(TranslateModel, MODEL_yu, 0, LVar4, 0)
    EVT_WAIT(1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o582, .pos = { 200.0, 150.0, 180.0 }},
    { .colliderID = COLLIDER_o357, .pos = { 200.0, 150.0, 180.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_22)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SET(LVar0, N(D_80240790_C9A990))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_802403E0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o591, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(D_802407BC_C9A9BC))
    EVT_EXEC(N(D_802408A8_C9AAA8))
    EVT_EXEC(N(D_80240A34_C9AC34))
    EVT_SET(LVar0, 46)
    EVT_EXEC(N(D_802404EC_C9A6EC))
    EVT_SET(LVar0, 47)
    EVT_EXEC(N(D_80240608_C9A808))
    EVT_RETURN
    EVT_END
};
