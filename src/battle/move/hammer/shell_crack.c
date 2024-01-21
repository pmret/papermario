#include "common.h"
#include "script_api/battle.h"
#include "effects.h"

#define NAMESPACE battle_move_shell_crack

#include "battle/common/move/HammerSupport.inc.c"

API_CALLABLE(func_802A10A4_77F2E4) {
    ActorState* playerActorState = &gBattleStatus.playerActor->state;
    s32 i;

    for (i = 0; i < 20; i++) {
        fx_floating_cloud_puff(0,
            (playerActorState->goalPos.x + (f32) rand_int(30)) - 15.0f,
            (playerActorState->goalPos.y + (f32) rand_int(20)) - 15.0f,
             playerActorState->goalPos.z + 5.0f, 1.0f, 25);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 60)
            Set(LVarE, 1)
            Set(LVarF, 2)
            ExecWait(N(UseMove_Impl))
        CaseEq(1)
            Set(LVarD, 60)
            Set(LVarE, 2)
            Set(LVarF, 4)
            ExecWait(N(UseMove_Impl))
        CaseEq(2)
            Set(LVarD, 60)
            Set(LVarE, 3)
            Set(LVarF, 6)
            ExecWait(N(UseMove_Impl))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A3248) = {
    Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(6.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(5.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(4.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
    EndThread
    Return
    End
};

EvtScript N(UseMove_Impl) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseBasicHammer))
        CaseEq(1)
            ExecWait(N(EVS_UseSuperHammer))
        CaseEq(2)
            ExecWait(N(EVS_UseUltraHammer))
    EndSwitch
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    ExecWait(N(EVS_802A3248))
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(func_802A10A4_77F2E4)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Wait(1)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_Hammer_ReturnHome_C))
        Return
    EndIf
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                CaseEq(1)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                CaseEq(2)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EndSwitch
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SHELL_CRACK, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                CaseEq(1)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                CaseEq(2)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EndSwitch
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_SHELL_CRACK, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(EVS_Hammer_ReturnHome_A))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_Hammer_ReturnHome_C))
        EndCaseGroup
    EndSwitch
    Return
    End
};
