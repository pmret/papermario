/// @file kmr_20.h
/// @brief Goomba Region - Mario's House

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_20_shape.h"
#include "mapfs/kmr_20_hit.h"

#include "sprite/npc/Luigi.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/ShyGuy.h"

enum {
    NPC_Scene_Parakarry         = 0,
    NPC_Scene_Luigi             = 1,

    NPC_Luigi_0                 = 0,
    NPC_Luigi_1                 = 1,
    NPC_ShyGuy                  = 2,
};

enum {
    MV_RecordsDataPtr       = MapVar(10),
};

enum {
    MF_LuigiWaiting         = MapFlag(10),
    MF_ReadyForPlayerEntry  = MapFlag(11),
    MF_Unk_0C               = MapFlag(12),
    MF_LuigiInBasement      = MapFlag(13),
};

#define NAMESPACE kmr_20

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_FadeOutAmbientSounds);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_Setup_Interactables);
extern EvtScript N(EVS_SetupBed);
extern EvtScript N(EVS_Scene_BeginGame);
extern EvtScript N(EVS_Scene_SettingOff);
extern EvtScript N(EVS_Scene_BeginEpilogue);
extern EvtScript N(EVS_Scene_EpilogueGetLetter);
extern EvtScript N(EVS_Scene_LuigiWaitingAround);
extern EvtScript N(EVS_Scene_CaughtLuigiInBasement);
extern EvtScript N(EVS_Inspect_Records);
extern EvtScript N(EVS_SecretPanel_Flip);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(SceneNPCs);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(func_80241C9C_8EDABC));
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, s32 bgAlpha, s32 frameAlpha);
