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
    EVT_SET_CONST(LVarA, ITEM_REPEL_GEL)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_REPEL_GEL_APPLY)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_ApplyCream)
    EVT_WAIT(45)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 3, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_REPEL_GEL_VANISH)
    EVT_CALL(GetItemPower, ITEM_REPEL_GEL, LVar0, LVar1)
    EVT_CALL(N(func_802A123C_72DDAC))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, BTL_MSG_PLAYER_TRANSPARENT, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

