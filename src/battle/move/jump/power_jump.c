#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"

#define NAMESPACE battle_move_power_jump

#include "battle/common/move/JumpSupport.inc.c"

extern EvtScript N(EVS_UseMove_Basic);
extern EvtScript N(EVS_UseMove_Super);
extern EvtScript N(EVS_UseMove_Ultra);

EvtScript N(EVS_UseMove) = {
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(ShowActionHud, true)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_UseMove_Basic))
        CaseEq(1)
            ExecWait(N(EVS_UseMove_Super))
        CaseEq(2)
            ExecWait(N(EVS_UseMove_Ultra))
    EndSwitch
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Return
    End
};

EvtScript N(EVS_802A26B4) = {
    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
    EndChildThread
    Return
    End
};

EvtScript N(EVS_UseMove_Basic) = {
    ExecWait(N(EVS_JumpSupport_ApproachAndJump))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    ExecWait(N(EVS_802A26B4))
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(false)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_1, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseGt(HIT_RESULT_HIT)
            ExecWait(N(EVS_JumpSupport_Rebound))
        CaseDefault
            ExecWait(N(EVS_JumpSupport_F))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove_Super) = {
    ExecWait(N(EVS_JumpSupport_ApproachAndJump))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    ExecWait(N(EVS_802A26B4))
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(false)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_2, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseGt(HIT_RESULT_HIT)
            ExecWait(N(EVS_JumpSupport_Rebound))
        CaseDefault
            ExecWait(N(EVS_JumpSupport_F))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseMove_Ultra) = {
    ExecWait(N(EVS_JumpSupport_ApproachAndJump))
    Call(PlayerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 1, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        ExecWait(N(EVS_JumpSupport_Miss))
        Return
    EndIf
    ExecWait(N(EVS_802A26B4))
    Wait(1)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(false)
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 8, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(SetActorSounds, ACTOR_PLAYER, ACTOR_SOUND_HURT, SOUND_ACTOR_JUMPED_3, SOUND_NONE)
            Call(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, 5, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseGt(HIT_RESULT_HIT)
            ExecWait(N(EVS_JumpSupport_Rebound))
        CaseDefault
            ExecWait(N(EVS_JumpSupport_F))
    EndSwitch
    Return
    End
};
