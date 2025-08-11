#include "dgb_11.h"
#include "entity.h"
#include "animation_script.h"
#include "sprite/player.h"

extern AnimScript Entity_ScriptSpring_AnimLaunch;

API_CALLABLE(N(PlaySpringAnimation)) {
    Entity* entity = get_entity_by_index(evt_get_variable(nullptr, MV_SpringEntityID));

    if (entity == nullptr) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_TetherCamToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar1, LVar3)
            Set(LVar1, LVar3)
        EndIf
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_LaunchToCeiling) = {
    Call(PlayerJump, 375, 270, -250, 20)
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    IfEq(AF_DGB_03, true)
        Return
    EndIf
    Set(AF_DGB_03, true)
    Call(DisablePlayerInput, true)
    Call(SetZoneEnabled, ZONE_o203, false)
    IfEq(AF_DGB_02, false)
        IfEq(GF_DGB10_BoardedFloor3, false)
            Call(DisablePlayerPhysics, true)
            Call(SetPlayerActionState, ACTION_STATE_JUMP)
            Wait(1)
            Set(LVar3, 500)
            ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
            Call(SetPlayerJumpscale, Float(0.7))
            ExecGetTID(N(EVS_LaunchToCeiling), LVarB)
            Loop(0)
                Wait(1)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfGe(LVar1, 165)
                    BreakLoop
                EndIf
            EndLoop
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(SetPlayerPos, LVar0, 165, LVar2)
            KillThread(LVarB)
            Call(SetPlayerAnimation, ANIM_MarioW2_JumpHitHead)
            Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
            Wait(10)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(SetPlayerJumpscale, Float(0.0))
            Call(PlayerJump1, 375, 25, -250, 10)
            Call(N(PlaySpringAnimation))
            Call(PlaySoundAtPlayer, SOUND_SPRING, SOUND_SPACE_DEFAULT)
            Call(SetPlayerJumpscale, Float(0.7))
            Call(PlayerJump, 375, 0, -175, 15)
            KillThread(LVarA)
            Call(SetPlayerActionState, ACTION_STATE_IDLE)
            Wait(2)
            Call(SetZoneEnabled, ZONE_o203, true)
            Call(DisablePlayerPhysics, false)
            Call(DisablePlayerInput, false)
            Set(AF_DGB_03, false)
        Else
            Call(DisablePlayerPhysics, true)
            Call(SetPlayerActionState, ACTION_STATE_JUMP)
            Wait(1)
            Thread
                Wait(8)
                Call(GotoMap, Ref("dgb_10"), dgb_10_ENTRY_1)
                Wait(100)
            EndThread
            Set(LVar3, 500)
            ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
            Call(SetPlayerJumpscale, Float(0.7))
            Call(PlayerJump, 375, 270, -250, 20)
            Set(AF_DGB_03, false)
        EndIf
    Else
        Call(SetPlayerActionState, ACTION_STATE_JUMP)
        Wait(1)
        Set(LVar3, 25)
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, 375, 0, -175, 15)
        Set(AF_DGB_02, false)
        KillThread(LVarA)
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
        Wait(2)
        Call(SetZoneEnabled, ZONE_o203, true)
        Call(DisablePlayerInput, false)
        Set(AF_DGB_03, false)
    EndIf
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_D_DOWN_JUMP, 250, 75, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DGB11_Item_DDownJump)
    Call(MakeEntity, Ref(Entity_ScriptSpring), 375, 0, -250, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Set(MV_SpringEntityID, LVar0)
    Return
    End
};
