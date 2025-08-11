#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/WorldBombette.h"
#include "battle/action_cmd/hammer.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_hammer_attack

#include "battle/common/move/HammerSupport.inc.c"

extern EvtScript N(EVS_UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, true)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 45)// action command duration
            Set(LVarE, 1) // bad input dmg
            Set(LVarF, 2) // good input dmg
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(1)
            Set(LVarD, 45)// action command duration
            Set(LVarE, 2) // bad input dmg
            Set(LVarF, 4) // good input dmg
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(2)
            Set(LVarD, 45)// action command duration
            Set(LVarE, 3) // bad input dmg
            Set(LVarF, 6) // good input dmg
            ExecWait(N(EVS_UseMove_Impl))
    EndSwitch
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
    Call(GetMashActionQuality, LVar0) // incorrect use, should use GetSmashActionQuality
    Switch(LVar0)
        CaseGt(0)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.3))
                    EndThread
                CaseEq(1)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.6))
                    EndThread
                CaseEq(2)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.9))
                    EndThread
            EndSwitch
        CaseDefault
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar1)
                CaseEq(0)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.3))
                    EndThread
                CaseEq(1)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    EndThread
                CaseEq(2)
                    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.9))
                    EndThread
            EndSwitch
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Wait(1)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
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

EvtScript N(EVS_FirstStrike) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVar9, 1)
            SetConst(LVarA, ANIM_MarioB1_Smash1_Hold1)
            SetConst(LVarB, ANIM_MarioB1_Smash1_PreSwing)
            SetConst(LVarC, ANIM_MarioB1_Smash1_Swing)
        CaseEq(1)
            Set(LVar9, 2)
            SetConst(LVarA, ANIM_MarioB1_Smash2_Hold1)
            SetConst(LVarB, ANIM_MarioB1_Smash2_Hold2)
            SetConst(LVarC, ANIM_MarioB1_Smash2_Swing)
        CaseEq(2)
            Set(LVar9, 3)
            SetConst(LVarA, ANIM_MarioB1_Smash3_Hold1)
            SetConst(LVarB, ANIM_MarioB1_Smash3_Hold2)
            SetConst(LVarC, ANIM_MarioB1_Smash3_Swing)
    EndSwitch
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 32)
    Set(LVar1, 0)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(UseBattleCamPresetImmediately, BTL_CAM_PLAYER_AIM_HAMMER)
    Call(SetAnimation, ACTOR_PLAYER, 0, LVarA)
    Wait(8)
    Call(SetAnimation, ACTOR_PLAYER, 0, LVarB)
    Wait(3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Call(SetAnimation, ACTOR_PLAYER, 0, LVarC)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_1)
            Call(StartRumble, BTL_RUMBLE_PLAYER_MIN)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.3))
            EndThread
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_2)
            Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.6))
            EndThread
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_3)
            Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.9))
            EndThread
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Wait(1)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
    EndSwitch
    Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_SMASH, SUPPRESS_EVENTS_HAMMER, 0, LVar9, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    ExecWait(N(EVS_HammerSupport_ReturnHome_SmashSuccess))
    Return
    End
};

extern EvtScript N(EVS_UseBerserker_Impl);

EvtScript N(EVS_UseBerserker) = {
    Call(ShowActionHud, true)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 75) // action command duration
            Set(LVarE, 1) // bad input dmg
            Set(LVarF, 2) // good input dmg
            ExecWait(N(EVS_UseBerserker_Impl))
        CaseEq(1)
            Set(LVarD, 66) // action command duration
            Set(LVarE, 2) // bad input dmg
            Set(LVarF, 4) // good input dmg
            ExecWait(N(EVS_UseBerserker_Impl))
        CaseEq(2)
            Set(LVarD, 57) // action command duration
            Set(LVarE, 3) // bad input dmg
            Set(LVarF, 6) // good input dmg
            ExecWait(N(EVS_UseBerserker_Impl))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseBerserker_Impl) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseBasicHammer))
        CaseEq(1)
            ExecWait(N(EVS_UseSuperHammer))
        CaseEq(2)
            ExecWait(N(EVS_UseUltraHammer))
    EndSwitch
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, LVar9, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
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
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Call(GetMashActionQuality, LVar0) // incorrect use, should use GetSmashActionQuality
    Switch(LVar0)
        CaseGt(0)
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
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    Wait(1)
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_SMASH, 25, 0, 0, 16)
    IfEq(LVar0, HIT_RESULT_MISS)
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
