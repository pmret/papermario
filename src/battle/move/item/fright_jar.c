#include "common.h"
#include "script_api/battle.h"
#include "model.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_fright_jar

#include "battle/common/move/ItemRefund.inc.c"

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_FRIGHT_JAR)
    ExecWait(N(UseItemWithEffect))
    Call(N(FadeBackgroundDarken))
    Thread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 50)
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_FRIGHT_JAR)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, -40)
    Add(LVar1, 5)
    SetF(LVar3, Float(0.7))
    Loop(5)
        PlayEffect(EFFECT_FRIGHT_JAR, 0, LVar0, LVar1, LVar2, LVar3, 25, 0)
        Add(LVar0, 5)
        AddF(LVar3, Float(0.15))
        Wait(7)
    EndLoop
    PlayEffect(EFFECT_FRIGHT_JAR, 0, LVar0, LVar1, LVar2, Float(1.5), 60, 0)
    Wait(20)
    Loop(4)
        Call(AddBattleCamDist, -100)
        Call(MoveBattleCamOver, 2)
        Wait(2)
        Call(AddBattleCamDist, 100)
        Call(MoveBattleCamOver, 2)
        Wait(2)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 20)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(SetDamageSource, DMG_SRC_FRIGHT_JAR)
        Call(ItemSpookEnemy, LVar0, DAMAGE_TYPE_FEAR | DAMAGE_TYPE_STATUS_ALWAYS_HITS | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_NO_CONTACT, 0, 100, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Walk)
    Call(N(FadeBackgroundLighten))
    Wait(20)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
