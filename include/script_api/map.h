#ifndef _SCRIPT_API_MAP_H_
#define _SCRIPT_API_MAP_H_

#include "common_structs.h"
#include "evt.h"

#include "script_api/common.h"

ApiStatus MakeNpcs(Evt* script, s32 isInitialCall);
ApiStatus DoBasicAI(Evt* script, s32 isInitialCall);
ApiStatus ResetFromLava(Evt* script, s32 isInitialCall);
ApiStatus MakeShop(Evt* script, s32 isInitialCall);
ApiStatus MakeShopOwner(Evt* script, s32 isInitialCall);
ApiStatus MakeDoorAdvanced(Evt* script, s32 isInitialCall);
ApiStatus CheckActionState(Evt* script, s32 isInitialCall);
ApiStatus CreatePushBlockGrid(Evt* script, s32 isInitialCall);
ApiStatus SetPushBlock(Evt* script, s32 isInitialCall);
ApiStatus GetPushBlock(Evt* script, s32 isInitialCall);
ApiStatus GetGridIndexFromPos(Evt* script, s32 isInitialCall);
ApiStatus SetPushBlockFallEffect(Evt* script, s32 isInitialCall);
ApiStatus TeleportPartnerToPlayer(Evt* script, s32 isInitialCall);

extern EvtSource EnterWalk;
extern EvtSource EnterWalkShort;
extern EvtSource EnterSavePoint;
extern EvtSource ExitWalk;
extern EvtSource ExitSingleDoor;
extern EvtSource EnterSingleDoor;
extern EvtSource ExitDoubleDoor;
extern EvtSource EnterDoubleDoor;


#endif
