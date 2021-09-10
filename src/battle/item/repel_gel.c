#include "repel_gel.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72DDAC)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_E, script->varTable[0]);
    player->status = 0;
    part->flags |= 0x100;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    EVT_VAR(10) = (const) ITEM_REPEL_GEL;
    await N(UseItemWithEffect);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_375);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_30008);
    sleep 45;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 20;
    PlayEffect(0x33, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_376);
    GetItemPower(ITEM_REPEL_GEL, EVT_VAR(0), EVT_VAR(1));
    N(func_802A123C_72DDAC)();
    sleep 20;
    ShowMessageBox(17, 60);
    WaitForMessageBoxDone();
    await N(PlayerGoHome);
});

