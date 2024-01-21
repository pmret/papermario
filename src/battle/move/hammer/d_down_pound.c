#include "common.h"
#include "script_api/battle.h"
#include "effects.h"

#define NAMESPACE battle_move_d_down_pound

#include "battle/common/move/HammerSupport.inc.c"

API_CALLABLE(func_802A10A4_74AE34) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        fx_green_impact(TRUE, var0 + 30, var1 + 25, var2, 45.0f);
    } else {
        fx_green_impact(FALSE, var0 + 30, var1 + 25, var2, 45.0f);
    }

    return ApiStatus_DONE2;
}

extern EvtScript N(UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(SetDamageSource, DMG_SRC_D_DOWN_POUND)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 50)
            Set(LVarE, 1)
            Set(LVarF, 2)
            ExecWait(N(UseMove_Impl))
        CaseEq(1)
            Set(LVarD, 50)
            Set(LVarE, 2)
            Set(LVarF, 4)
            ExecWait(N(UseMove_Impl))
        CaseEq(2)
            Set(LVarD, 50)
            Set(LVarE, 3)
            Set(LVarF, 6)
            ExecWait(N(UseMove_Impl))
    EndSwitch
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
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_IGNORE_DEFENSE, 25, 0, LVar9, 16)
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.3))
                    EndThread
                CaseEq(1)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.6))
                    EndThread
                CaseEq(2)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.9))
                    EndThread
            EndSwitch
        CaseDefault
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.3))
                    EndThread
                CaseEq(1)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    EndThread
                CaseEq(2)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.9))
                    EndThread
            EndSwitch
    EndSwitch
    Call(GetPlayerActionSuccess, LVar0)
    IfGt(LVar0, FALSE)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
        Call(MoveBattleCamOver, 5)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
        Call(MoveBattleCamOver, 50)
    EndIf
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    EndSwitch
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_Hammer_ReturnHome_C))
        Return
    EndIf
    Call(GetPlayerActionSuccess, LVarA)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_802A10A4_74AE34, LVar0, LVar1, LVar2)
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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
