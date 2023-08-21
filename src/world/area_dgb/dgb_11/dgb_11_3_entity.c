#include "dgb_11.h"
#include "entity.h"
#include "animation_script.h"
#include "sprite/player.h"

extern AnimScript Entity_ScriptSpring_AnimLaunch;

API_CALLABLE(N(PlaySpringAnimation)) {
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, MV_SpringEntityID));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_TetherCamToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar1, LVar3)
            EVT_SET(LVar1, LVar3)
        EVT_END_IF
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LaunchToCeiling) = {
    EVT_CALL(PlayerJump, 375, 270, -250, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_IF_EQ(AF_DGB_03, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_DGB_03, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetZoneEnabled, ZONE_o203, FALSE)
    EVT_IF_EQ(AF_DGB_02, FALSE)
        EVT_IF_EQ(GF_DGB10_BoardedFloor3, FALSE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
            EVT_WAIT(1)
            EVT_SET(LVar3, 500)
            EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_EXEC_GET_TID(N(EVS_LaunchToCeiling), LVarB)
            EVT_LOOP(0)
                EVT_WAIT(1)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_GE(LVar1, 165)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetPlayerPos, LVar0, 165, LVar2)
            EVT_KILL_THREAD(LVarB)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_JumpHitHead)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.0))
            EVT_CALL(PlayerJump1, 375, 25, -250, 10)
            EVT_CALL(N(PlaySpringAnimation))
            EVT_CALL(PlaySoundAtPlayer, SOUND_SPRING, SOUND_SPACE_DEFAULT)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_CALL(PlayerJump, 375, 0, -175, 15)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_WAIT(2)
            EVT_CALL(SetZoneEnabled, ZONE_o203, TRUE)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(AF_DGB_03, FALSE)
        EVT_ELSE
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
            EVT_WAIT(1)
            EVT_THREAD
                EVT_WAIT(8)
                EVT_CALL(GotoMap, EVT_PTR("dgb_10"), dgb_10_ENTRY_1)
                EVT_WAIT(100)
            EVT_END_THREAD
            EVT_SET(LVar3, 500)
            EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_CALL(PlayerJump, 375, 270, -250, 20)
            EVT_SET(AF_DGB_03, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
        EVT_WAIT(1)
        EVT_SET(LVar3, 25)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, 375, 0, -175, 15)
        EVT_SET(AF_DGB_02, FALSE)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_WAIT(2)
        EVT_CALL(SetZoneEnabled, ZONE_o203, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_SET(AF_DGB_03, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_D_DOWN_JUMP, 250, 75, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DGB11_Item_DDownJump)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 375, 0, -250, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_SET(MV_SpringEntityID, LVar0)
    EVT_RETURN
    EVT_END
};
