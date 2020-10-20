#ifndef _SCRIPT_API_MAP_H_
#define _SCRIPT_API_MAP_H_

#include "common_structs.h"
#include "si.h"

#include "script_api/common.h"

ApiStatus MakeNpcs(ScriptInstance* script, s32 isInitialCall);
ApiStatus DoBasicAI(ScriptInstance* script, s32 isInitialCall);
ApiStatus ResetFromLava(ScriptInstance* script, s32 isInitialCall);
ApiStatus MakeShop(ScriptInstance* script, s32 isInitialCall);
ApiStatus MakeShopOwner(ScriptInstance* script, s32 isInitialCall);
ApiStatus MakeDoorAdvanced(ScriptInstance* script, s32 isInitialCall);
ApiStatus CheckActionState(ScriptInstance* script, s32 isInitialCall);
ApiStatus CreatePushBlockGrid(ScriptInstance* script, s32 isInitialCall);
ApiStatus SetPushBlock(ScriptInstance* script, s32 isInitialCall);
ApiStatus GetPushBlock(ScriptInstance* script, s32 isInitialCall);
ApiStatus GetGridIndexFromPos(ScriptInstance* script, s32 isInitialCall);
ApiStatus SetPushBlockFallEffect(ScriptInstance* script, s32 isInitialCall);
ApiStatus TeleportPartnerToPlayer(ScriptInstance* script, s32 isInitialCall);

extern Script EnterWalk;
extern Script EnterWalkShort;
extern Script EnterSavePoint;
extern Script ExitWalk;
extern Script ExitSingleDoor;
extern Script EnterSingleDoor;
extern Script ExitDoubleDoor;
extern Script EnterDoubleDoor;


#endif
