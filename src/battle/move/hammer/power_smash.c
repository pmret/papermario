#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE battle_move_power_smash

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(ShowActionHud, true)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 45) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD + 2)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD + 2)
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(1)
            Set(LVarD, 45) // duration
            Set(LVarE, SUPER_HAMMER_DMG_BAD + 2)
            Set(LVarF, SUPER_HAMMER_DMG_GOOD + 2)
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(2)
            Set(LVarD, 45) // duration
            Set(LVarE, ULTRA_HAMMER_DMG_BAD + 2)
            Set(LVarF, ULTRA_HAMMER_DMG_GOOD + 2)
            ExecWait(N(EVS_UseMove_Impl))
    EndSwitch
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Return
    End
};

EvtScript N(EVS_802A3188) = {
    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
    EndThread
    Return
    End
};

EvtScript N(EVS_UseMove_Impl) = {
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
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Wait(1)
    ExecWait(N(EVS_802A3188))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(false)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                CaseEq(1)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                CaseEq(2)
                    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EndSwitch
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
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
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(EVS_HammerSupport_ReturnHome_SmashSuccess))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        EndCaseGroup
    EndSwitch
    Return
    End
};
