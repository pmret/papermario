#include "common.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_peach_focus

#include "battle/common/move/StarPowerSupport.inc.c"

enum N(ActorVars) {
    AVAR_Twink_PowerLevel   = 0,
    AVAR_Twink_DefensePtr   = 1,
};

API_CALLABLE(N(IncreaseTwinkDefense)) {
    // a pointer to Twink's DefenseTable is stored in his actorVar1 in twink.c
    // it has now been copied to this script var, where we can retrieve it
    s32* twinkDefenseTable = script->varTablePtr[0];

    // increment the value of the first key in the defense table
    twinkDefenseTable[1]++;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    Call(UseBattleCamPreset, BTL_CAM_PRESET_69)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Run)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 16)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Startle)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -105, -7, 0)
    Call(SetBattleCamZoom, 213)
    Call(MoveBattleCamOver, 60)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach3_Pray)
    Call(PlaySound, SOUND_BEGIN_WISH)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
    Call(N(FadeBackgroundDarken))
    Call(GetActorVar, ACTOR_PARTNER, AVAR_Twink_PowerLevel, LVar0)
    IfEq(LVar0, 0)
        Call(ActorSpeak, MSG_CH8_0096, ACTOR_PLAYER, 0, ANIM_Peach3_Pray, ANIM_Peach3_Pray)
    EndIf
    Wait(20)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Idle)
    Wait(10)
    Call(PlaySound, SOUND_WISH_ASCENDING)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
    Wait(30)
    Call(PlaySound, SOUND_STAR_POWER_RECOVERY)
    Call(GetActorVar, ACTOR_PARTNER, AVAR_Twink_PowerLevel, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_PARTNER, AVAR_Twink_PowerLevel, LVar0)
    Call(ModifyActorDecoration, ACTOR_PARTNER, 1, 0, LVar0, 0, 0, 0)
    Call(GetActorVar, ACTOR_PARTNER, AVAR_Twink_DefensePtr, LVar0)
    Call(N(IncreaseTwinkDefense))
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetActorYaw, ACTOR_SELF, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_SELF, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_SELF, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_SELF, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_SELF, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Wait(1)
    Call(PlayerYieldTurn)
    Call(N(FadeBackgroundLighten))
    Wait(15)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Walk)
    Return
    End
};
