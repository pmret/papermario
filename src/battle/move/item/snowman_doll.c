#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_snowman_doll

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_71C06C)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_2, x, y, z, 30.0f);
    fx_sparkles(FX_SPARKLES_2, x, y, z, 30.0f);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_SNOWMAN_DOLL)
    ExecWait(N(UseItemWithEffect))
    Call(N(FadeBackgroundDarken))
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_WINTERY_JINGLE)
    Thread
        Loop(45)
            Call(RandInt, 300, LVar0)
            Sub(LVar0, 150)
            Set(LVar1, 170)
            Call(RandInt, 50, LVar2)
            Sub(LVar2, 25)
            PlayEffect(EFFECT_SNOWFLAKE, LVar0, LVar1, LVar2, 60, 0)
            Wait(2)
        EndLoop
    EndThread
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 50)
    Wait(50)
    PlayEffect(EFFECT_SNOWMAN_DOLL, 0, 0, 0, 20, Float(1.0), 160, 0)
    Thread
        Wait(17)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        Wait(46)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        Wait(25)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        Wait(25)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SNOWMAN_DOLL_JUMP)
        Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    EndThread
    Wait(15)
    Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(2.0))
    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    Wait(110)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(N(func_802A123C_71C06C), LVar0, LVar1, LVar2)
        Call(GetItemPower, ITEM_SNOWMAN_DOLL, LVar0, LVar1)
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
        Wait(5)
        Label(1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(30)
    Call(N(FadeBackgroundLighten))
    ExecWait(N(PlayerGoHome))
    Return
    End
};
