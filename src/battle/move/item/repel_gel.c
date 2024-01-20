#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_repel_gel

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_72DDAC)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_KEY_TRANSPARENT, script->varTable[0]);
    player->statusAfflicted = 0;
    part->flags |= ACTOR_PART_FLAG_TRANSPARENT;

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_REPEL_GEL)
    ExecWait(N(UseItemWithEffect))
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_REPEL_GEL_APPLY)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_ApplyCream)
    Wait(45)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 3, LVar0, LVar1, LVar2, Float(1.0), 30, 0)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_REPEL_GEL_VANISH)
    Call(GetItemPower, ITEM_REPEL_GEL, LVar0, LVar1)
    Call(N(func_802A123C_72DDAC))
    Wait(20)
    Call(ShowMessageBox, BTL_MSG_PLAYER_TRANSPARENT, 60)
    Call(WaitForMessageBoxDone)
    ExecWait(N(PlayerGoHome))
    Return
    End
};

