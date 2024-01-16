#ifndef _SCRIPT_API_MAP_H_
#define _SCRIPT_API_MAP_H_

#include "common_structs.h"
#include "evt.h"

#include "script_api/common.h"

API_CALLABLE(MakeNpcs);
API_CALLABLE(BasicAI_Main);
API_CALLABLE(ResetFromLava);
API_CALLABLE(MakeShop);
API_CALLABLE(MakeShopOwner);
API_CALLABLE(CreateMapRoom);
API_CALLABLE(CheckActionState);
API_CALLABLE(CreatePushBlockGrid);
API_CALLABLE(SetPushBlock);
API_CALLABLE(GetPushBlock);
API_CALLABLE(GetGridIndexFromPos);
API_CALLABLE(SetPushBlockFallEffect);
API_CALLABLE(TeleportPartnerToPlayer);

extern EvtScript EnterWalk;
extern EvtScript EnterWalkShort;
extern EvtScript EnterSavePoint;
extern EvtScript ExitWalk;
extern EvtScript ExitSingleDoor;
extern EvtScript EnterSingleDoor;
extern EvtScript ExitSplitSingleDoor;
extern EvtScript EnterSplitSingleDoor;
extern EvtScript ExitDoubleDoor;
extern EvtScript EnterDoubleDoor;
extern EvtScript ExitSplitDoubleDoor;
extern EvtScript EnterSplitDoubleDoor;
extern EvtScript BaseExitDoor;
extern EvtScript BaseEnterDoor;
extern EvtScript EnterPostPipe;
extern EvtScript EVS_ShopOwnerDialog;

#endif
