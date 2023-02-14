/// @file kmr_11.h
/// @brief Goomba Region - Goomba King's Castle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_11_shape.h"
#include "mapfs/kmr_11_hit.h"

#include "sprite/npc/GoombaKing.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/GoombaBros.h"
#include "sprite/npc/WorldKammy.h"

#include "animation_script.h"

enum {
    NPC_BlueGoombaBro   = 0,
    NPC_RedGoombaBro    = 1,
    NPC_GoombaKing      = 2,
    NPC_Kammy           = 4,
};

enum {
    MV_SwitchEntityID       = MapVar(0),
};

enum {
    MF_SpawnFlag_StarPiece  = MapFlag(10),
};

#define NAMESPACE kmr_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_Interact_SwitchBush);
extern EvtScript N(EVS_Scene_MeetGoombaKing);
extern EvtScript N(EVS_Scene_SelfDestruct);
extern EvtScript N(EVS_PlayFortressAnimation);
extern EvtScript N(EVS_PlayBridgeAnimation);
extern EvtScript N(EVS_Scene_KammyWatching);
extern EvtScript N(EVS_BadExit_kmr_24_0);

extern NpcGroupList N(DefaultNPCs);

extern StaticAnimatorNode* N(AnimSkeleton_Fortress)[];
extern StaticAnimatorNode* N(AnimSkeleton_Bridge)[];
extern AnimScript N(AnimScript_Fortress);
extern AnimScript N(AnimScript_Bridge);

API_CALLABLE(N(SetCameraVFov));
API_CALLABLE(N(SetupFog));

API_CALLABLE(InitAnimatedModels);
API_CALLABLE(SetAnimatedModelRenderMode);
API_CALLABLE(DeleteAnimatedModel);
