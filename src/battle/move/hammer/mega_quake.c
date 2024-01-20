#include "common.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_mega_quake

#include "battle/common/move/HammerSupport.inc.c"

API_CALLABLE(func_802A10A4_756824) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] != 0) {
        if (script->functionTemp[0] != 1) {
            return ApiStatus_BLOCK;
        }
    } else {
        script->functionTemp[1] = 30;
        script->functionTemp[0] = 1;
    }

    set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
    set_screen_overlay_center(SCREEN_LAYER_BACK, 1, SCREEN_WIDTH, SCREEN_HEIGHT);
    set_screen_overlay_params_back(OVERLAY_BLUR, 160.0f);

    if (script->functionTemp[1] != 0) {
        script->functionTemp[1]--;
        return ApiStatus_BLOCK;
    } else {
        set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
        set_screen_overlay_center(SCREEN_LAYER_BACK, 1, SCREEN_WIDTH, SCREEN_HEIGHT);
        set_screen_overlay_params_back(OVERLAY_BLUR, 0.0f);
        return ApiStatus_DONE2;
    }
}

extern EvtScript N(EVS_802A3238);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 80)
            Set(LVarE, 3)
            Set(LVarF, 6)
            ExecWait(N(EVS_802A3238))
        CaseEq(1)
            Set(LVarD, 80)
            Set(LVarE, 3)
            Set(LVarF, 6)
            ExecWait(N(EVS_802A3238))
        CaseEq(2)
            Set(LVarD, 80)
            Set(LVarE, 3)
            Set(LVarF, 6)
            ExecWait(N(EVS_802A3238))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A3238) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_Hammer_UseBasicQuake))
        CaseEq(1)
            ExecWait(N(EVS_Hammer_UseSuperQuake))
        CaseEq(2)
            ExecWait(N(EVS_Hammer_UseUltraQuake))
    EndSwitch
    Thread
        Wait(8)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 24)
        Add(LVar1, 10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 0, 30, 0, 0, 0, 0, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 33, 30, 0, 0, 0, 0, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 60, 8, 66, 30, 0, 0, 0, 0, 0)
    EndThread
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
            Call(StartRumble, BTL_RUMBLE_PLAYER_MAX)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.3))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.5))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(3.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.5))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(1.05))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.6))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.15))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.07519531))
            EndThread
            Thread
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Add(LVar0, 24)
                Add(LVar1, 10)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 48, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 72, 30, 0, 0, 0, 0, 0)
            EndThread
            Thread
                Wait(10)
                PlayEffect(EFFECT_SHOCKWAVE, 1, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EndThread
        CaseDefault
            Call(StartRumble, BTL_RUMBLE_PLAYER_MAX)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.24))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.2))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(2.4))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.2))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.84))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.48))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.12))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.06))
            EndThread
            Thread
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Add(LVar0, 24)
                Add(LVar1, 10)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 0, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 24, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 48, 30, 0, 0, 0, 0, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 72, 8, 72, 30, 0, 0, 0, 0, 0)
            EndThread
            Thread
                Wait(10)
                PlayEffect(EFFECT_SHOCKWAVE, 1, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EndThread
    EndSwitch
    Call(GetPlayerActionSuccess, LVar0)
    IfGt(LVar0, FALSE)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_46)
        Call(MoveBattleCamOver, 5)
        Wait(15)
        SetF(LVar6, Float(0.0))
        Loop(10)
            Set(LVar4, LVar3)
            Set(LVar5, LVar2)
            AddF(LVar6, Float(36.0))
            Call(AddVectorPolar, LVar4, LVar5, Float(300.0), LVar6)
            Set(LVarA, LVarF)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar3, 1, LVar2, LVar4, 1, LVar5, Float(4.0), 30, 0, 0, 0, 0)
            Set(LVarF, LVarA)
        EndLoop
        Wait(10)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PRESET_46)
        Call(MoveBattleCamOver, 50)
    EndIf
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_QUAKE_3)
    EndSwitch
    Wait(10)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_STRIKE_3)
    EndSwitch
    Set(LVar9, 0)
    Call(InitTargetIterator)
    Label(10)
        Call(SetGoalToTarget, ACTOR_PLAYER)
        Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_QUAKE_HAMMER, 29, 0, 0, 16)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(11)
        EndIf
        Call(GetPlayerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(FALSE)
                Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
            CaseDefault
                Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
        EndSwitch
        Label(11)
        Call(ChooseNextTarget, ITER_NEXT, LVar1)
        Add(LVar9, 1)
        Call(GetTargetListLength, LVar1)
        IfLt(LVar9, LVar1)
            Goto(10)
        EndIf
    Thread
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndThread
    Wait(10)
    ExecWait(N(EVS_Hammer_ReturnHome_B))
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};


