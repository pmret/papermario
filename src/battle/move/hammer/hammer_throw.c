#include "common.h"
#include "effects.h"
#include "entity.h"
#include "sprite/player.h"
#include "include_asset.h"

#define NAMESPACE battle_move_hammer_throw

#include "battle/common/move/HammerSupport.inc.c"

static s32 pad_images = 0;

INCLUDE_IMG("battle/move/hammer/dusty_hammer.png", battle_move_hammer_throw_dusty_hammer_png);
INCLUDE_PAL("battle/move/hammer/dusty_hammer.pal", battle_move_hammer_throw_dusty_hammer_pal);

INCLUDE_IMG("battle/move/hammer/basic_hammer.png", battle_move_hammer_throw_basic_hammer_png);
INCLUDE_PAL("battle/move/hammer/basic_hammer.pal", battle_move_hammer_throw_basic_hammer_pal);

INCLUDE_IMG("battle/move/hammer/super_hammer.png", battle_move_hammer_throw_super_hammer_png);
INCLUDE_PAL("battle/move/hammer/super_hammer.pal", battle_move_hammer_throw_super_hammer_pal);

INCLUDE_IMG("battle/move/hammer/ultra_hammer.png", battle_move_hammer_throw_ultra_hammer_png);
INCLUDE_PAL("battle/move/hammer/ultra_hammer.pal", battle_move_hammer_throw_ultra_hammer_pal);

#include "battle/move/hammer/hammer_throw.vtx.inc.c"

#include "battle/move/hammer/dusty_hammer.gfx.inc.c"
#include "battle/move/hammer/basic_hammer.gfx.inc.c"
#include "battle/move/hammer/super_hammer.gfx.inc.c"
#include "battle/move/hammer/ultra_hammer.gfx.inc.c"

EntityModelScript N(EMS_DustyHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(dusty_hammer_gfx), RENDER_MODE_ALPHATEST);
EntityModelScript N(EMS_BasicHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(basic_hammer_gfx), RENDER_MODE_ALPHATEST);
EntityModelScript N(EMS_SuperHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(super_hammer_gfx), RENDER_MODE_ALPHATEST);
EntityModelScript N(EMS_UltraHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(ultra_hammer_gfx), RENDER_MODE_ALPHATEST);

extern EvtScript N(EVS_UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarD, 50) // duration
            Set(LVarE, BASIC_HAMMER_DMG_BAD)
            Set(LVarF, BASIC_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(1)
            Set(LVarD, 50) // duration
            Set(LVarE, SUPER_HAMMER_DMG_BAD)
            Set(LVarF, SUPER_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove_Impl))
        CaseEq(2)
            Set(LVarD, 50) // duration
            Set(LVarE, ULTRA_HAMMER_DMG_BAD)
            Set(LVarF, ULTRA_HAMMER_DMG_GOOD)
            ExecWait(N(EVS_UseMove_Impl))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A3E5C) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Set(LVar1, 0)
    Loop(10)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, TRUE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            BreakLoop
        EndIf
        Wait(1)
        Add(LVar1, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Begin)
    EndLoop
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Begin)
    Switch(LVar1)
        CaseLt(3)
            Wait(4)
        CaseLt(5)
            Wait(3)
        CaseLt(7)
            Wait(2)
        CaseLt(9)
            Wait(1)
        CaseLt(11)
            Wait(0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A3FE0) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Set(LVar1, 0)
    Loop(10)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, TRUE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            BreakLoop
        EndIf
        Wait(1)
        Add(LVar1, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Begin)
    EndLoop
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Begin)
    Switch(LVar1)
        CaseLt(3)
            Wait(4)
        CaseLt(5)
            Wait(3)
        CaseLt(7)
            Wait(2)
        CaseLt(9)
            Wait(1)
        CaseLt(11)
            Wait(0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_802A4164) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Set(LVar1, 0)
    Loop(10)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, TRUE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            BreakLoop
        EndIf
        Wait(1)
        Add(LVar1, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Begin)
    EndLoop
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Begin)
    Switch(LVar1)
        CaseLt(3)
            Wait(4)
        CaseLt(5)
            Wait(3)
        CaseLt(7)
            Wait(2)
        CaseLt(9)
            Wait(1)
        CaseLt(11)
            Wait(0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove_Impl) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 16)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerRunToGoal, 0)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_802A3E5C))
        CaseEq(1)
            ExecWait(N(EVS_802A3FE0))
        CaseEq(2)
            ExecWait(N(EVS_802A4164))
    EndSwitch
    Call(InitTargetIterator)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    Call(AddBattleCamDist, 50)
    Call(MoveBattleCamOver, 20)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Raise)
            Wait(4)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Hold1)
        CaseEq(1)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Raise)
            Wait(4)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Hold1)
        CaseEq(2)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Raise)
            Wait(4)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Hold1)
    EndSwitch
    Call(GetActionCommandMode, LVar0)
    IfGt(LVar0, AC_MODE_NOT_LEARNED)
        Call(N(ShouldMovesAutoSucceed))
        IfEq(LVar0, 0)
            Loop(45)
                Wait(1)
                Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
                IfNe(LVar0, FALSE)
                    BreakLoop
                EndIf
            EndLoop
        EndIf
        Add(LVarD, 6)
        Call(action_command_hammer_start, 0, LVarD, AC_DIFFICULTY_3)
        Call(SetActionProgress, 0)
        Set(LVar1, 0)
        Loop(30)
            Wait(1)
            Call(GetActionProgress, LVar0)
            IfNe(LVar0, 0)
                IfNe(LVar1, 1)
                    Call(GetMenuSelection, LVar3, LVar4, LVar5)
                    Switch(LVar4)
                        CaseEq(0)
                            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Hold2)
                        CaseEq(1)
                            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Hold2)
                        CaseEq(2)
                            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Hold2)
                    EndSwitch
                    Set(LVar1, 1)
                EndIf
            EndIf
            Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            IfEq(LVar0, FALSE)
                BreakLoop
            EndIf
        EndLoop
    Else
        Wait(10)
        Call(GetMenuSelection, LVar3, LVar4, LVar5)
        Switch(LVar4)
            CaseEq(0)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Hold2)
            CaseEq(1)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Hold2)
            CaseEq(2)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Hold2)
        EndSwitch
        Wait(30)
    EndIf
    Call(GetActionCommandMode, LVar0)
    IfGt(LVar0, AC_MODE_NOT_LEARNED)
        Loop(0)
            Wait(1)
            Call(GetSmashActionQuality, LVar0)
            IfNe(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Throw)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_1)
        CaseEq(1)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Throw)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_2)
        CaseEq(2)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Throw)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_3)
    EndSwitch
    Wait(3)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(CreateVirtualEntity, LVarA, Ref(N(EMS_BasicHammer)))
        CaseEq(1)
            Call(CreateVirtualEntity, LVarA, Ref(N(EMS_SuperHammer)))
        CaseEq(2)
            Call(CreateVirtualEntity, LVarA, Ref(N(EMS_UltraHammer)))
    EndSwitch
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Add(LVar1, 42)
    Add(LVar2, 5)
    Call(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    Call(SetVirtualEntityScale, LVarA, Float(0.6), Float(0.6), Float(0.6))
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetPlayerActionQuality, LVar3)
    Switch(LVar3)
        CaseGt(FALSE)
            Thread
                Set(LVar0, 0)
                Loop(9)
                    Add(LVar0, 60)
                    Call(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetVirtualEntityJumpGravity, LVarA, Float(1.3))
            Add(LVar2, 5)
            Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 11)
        CaseDefault
            Thread
                Set(LVar0, 0)
                Loop(18)
                    Add(LVar0, 60)
                    Call(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetVirtualEntityJumpGravity, LVarA, Float(0.7))
            Add(LVar2, 5)
            Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 20)
    EndSwitch
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(PlayerTestEnemy, LVar3, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_NO_CONTACT, 25, 0, 0, 16)
    IfEq(LVar3, HIT_RESULT_MISS)
        Call(VirtualEntityLandJump, LVarA)
        Call(DeleteVirtualEntity, LVarA)
        ExecWait(N(EVS_HammerSupport_ReturnHome_SmashMiss))
        Return
    EndIf
    Thread
        Call(GetPlayerActionQuality, LVar3)
        Switch(LVar3)
            CaseGt(FALSE)
                Call(SetVirtualEntityJumpGravity, LVarA, Float(1.4))
                Add(LVar0, 60)
                Add(LVar1, 0)
                Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 10)
                Call(DeleteVirtualEntity, LVarA)
            CaseDefault
                Call(SetVirtualEntityJumpGravity, LVarA, Float(0.8))
                Add(LVar0, 40)
                Add(LVar1, 0)
                Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 15)
                Call(DeleteVirtualEntity, LVarA)
        EndSwitch
    EndThread
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(FALSE)
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
    Call(MoveBattleCamOver, 10)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
        CaseEq(1)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
        CaseEq(2)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    EndSwitch
    Call(GetPlayerActionQuality, LVar0)
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
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_THROW | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
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
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_THROW | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
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
