/// @file kmr_22.h
/// @brief Goomba Region - Chapter Start

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_22_shape.h"
#include "mapfs/kmr_22_hit.h"

#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/HuffNPuff.h"
#include "sprite/npc/RuffPuff.h"
#include "sprite/npc/CrystalKing.h"
#include "sprite/npc/WorldBowser.h"

enum {
    NPC_Eldstar                 = 0,
    NPC_Mamar                   = 1,
    NPC_Skolar                  = 2,
    NPC_Muskular                = 3,
    NPC_Misstar                 = 4,
    NPC_Klevar                  = 5,
    NPC_Kalmar                  = 6,
    NPC_KoopaBros_01            = 7,
    NPC_KoopaBros_02            = 8,
    NPC_KoopaBros_03            = 9,
    NPC_KoopaBros_04            = 10,
    NPC_Tutankoopa              = 11,
    NPC_ChainChomp_01           = 12,
    NPC_ChainChomp_02           = 13,
    NPC_ChainChomp_03           = 14,
    NPC_ChainChomp_04           = 15,
    NPC_ChainChomp_05           = 16,
    NPC_Tubba                   = 17,
    NPC_GeneralGuy              = 18,
    NPC_ShyGuy_01               = 19,
    NPC_ShyGuy_02               = 20,
    NPC_LavaPiranhaHead         = 21,
    NPC_LavaBud_01              = 22,
    NPC_LavaBud_02              = 23,
    NPC_HuffNPuff_Body          = 25,
    NPC_HuffNPuff_Face          = 26,
    NPC_HuffNPuff_Arms          = 27,
    NPC_RuffPuff_01             = 28,
    NPC_RuffPuff_02             = 29,
    NPC_CrystalKing             = 30,
    NPC_IceCube                 = 31,
    NPC_IceSphere               = 32,
    NPC_IceSpike                = 33,
    NPC_Bowser                  = 34,
};

enum {
    MV_VinesData                = MapVar(0),
    MV_BossDefeated             = MapVar(10),
};

#define NAMESPACE kmr_22

extern EvtScript N(EVS_Main);
extern NpcGroupList N(NpcGroup_Chapter1);
extern NpcGroupList N(NpcGroup_Chapter2);
extern NpcGroupList N(NpcGroup_Chapter3);
extern NpcGroupList N(NpcGroup_Chapter4);
extern NpcGroupList N(NpcGroup_Chapter5);
extern NpcGroupList N(NpcGroup_Chapter6);
extern NpcGroupList N(NpcGroup_Chapter7);
extern NpcGroupList N(NpcGroup_Chapter8);

extern API_CALLABLE(SetAnimatorFlags);
extern API_CALLABLE(GetAnimatedPositionByTreeIndex);
extern API_CALLABLE(GetAnimatedRotationByTreeIndex);
