/// @file end_00.h
/// @brief Ending - Parade (Day)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../end.h"
#include "mapfs/end_00_shape.h"
#include "mapfs/end_00_hit.h"

#include "sprite/npc/ParadeLuigi.h"
#include "sprite/npc/ParadePartner.h"
#include "sprite/npc/ParadeToad.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/VannaT.h"
#include "sprite/npc/KoopaBros.h"
#include "sprite/npc/Bobomb.h"
#include "sprite/npc/ParadeKolorado.h"
#include "sprite/npc/Rowf.h"
#include "sprite/npc/Moustafa.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/Buzzar.h"
#include "sprite/npc/ParadeChick.h"
#include "sprite/npc/TubbasHeart.h"
#include "sprite/npc/Bootler.h"
#include "sprite/npc/Boo.h"
#include "sprite/npc/ParadeTubbaBalloon.h"
#include "sprite/npc/GoombaBros.h"
#include "sprite/npc/GoombaKing.h"
#include "sprite/npc/HuffNPuff.h"
#include "sprite/npc/TuffPuff.h"
#include "sprite/npc/GourmetGuy.h"

#include "sprite/npc/RafaelRaven.h"
#include "sprite/npc/LavaPiranha.h"
#include "sprite/npc/ParadeYoshi.h"
#include "sprite/npc/YoshiKid.h"

#include "sprite/npc/CrystalKing.h"
#include "sprite/npc/Duplighost.h"
#include "sprite/npc/MageJrTroopa.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/ParadeKoopas.h"
#include "sprite/npc/ParadeBurntBowser.h"

enum {
	NPC_00                      = 0,
	NPC_01                      = 1,
	NPC_02                      = 2,
	NPC_03                      = 3,
	NPC_04                      = 4,
	NPC_05                      = 5,
	NPC_06                      = 6,
	NPC_07                      = 7,
	NPC_08                      = 8,
	NPC_09                      = 9,
	NPC_0A                      = 10,
	NPC_0B                      = 11,
	NPC_0C                      = 12,
	NPC_0D                      = 13,
	NPC_0E                      = 14,
	NPC_0F                      = 15,
	NPC_10                      = 16,
	NPC_11                      = 17,
	NPC_12                      = 18,
	NPC_13                      = 19,
	NPC_14                      = 20,
	NPC_15                      = 21,
	NPC_16                      = 22,
	NPC_17                      = 23,
	NPC_18                      = 24,
	NPC_19                      = 25,
	NPC_1A                      = 26,
	NPC_1B                      = 27,
	NPC_1C                      = 28,
	NPC_1D                      = 29,
	NPC_1E                      = 30,
	NPC_1F                      = 31,
	NPC_20                      = 32,
	NPC_21                      = 33,
	NPC_22                      = 34,
	NPC_23                      = 35,
	NPC_24                      = 36,
	NPC_25                      = 37,
	NPC_26                      = 38,
	NPC_27                      = 39,
	NPC_28                      = 40,
	NPC_29                      = 41,
	NPC_2A                      = 42,
	NPC_2B                      = 43,
	NPC_2C                      = 44,
	NPC_2D                      = 45,
	NPC_2E                      = 46,
	NPC_2F                      = 47,
	NPC_30                      = 48,
	NPC_31                      = 49,
	NPC_32                      = 50,
	NPC_33                      = 51,
	NPC_34                      = 52,
	NPC_35                      = 53,
	NPC_36                      = 54,
	NPC_37                      = 55,
	NPC_38                      = 56,
	NPC_39                      = 57,
	NPC_3A                      = 58,
	NPC_3B                      = 59,
	NPC_3C                      = 60,
	NPC_3D                      = 61,
	NPC_3E                      = 62,
	NPC_3F                      = 63,
	NPC_40                      = 64,
	NPC_41                      = 65,
	NPC_42                      = 66,
	NPC_43                      = 67,
	NPC_44                      = 68,
	NPC_45                      = 69,
	NPC_46                      = 70,
	NPC_47                      = 71,
	NPC_48                      = 72,
	NPC_49                      = 73,
	NPC_4A                      = 74,
	NPC_4B                      = 75,
	NPC_4C                      = 76,
	NPC_4D                      = 77,
	NPC_4E                      = 78,
	NPC_4F                      = 79,
	NPC_50                      = 80,
	NPC_51                      = 81,
	NPC_52                      = 82,
	NPC_53                      = 83,
	NPC_54                      = 84,
	NPC_55                      = 85,
	NPC_56                      = 86,
	NPC_57                      = 87,
	NPC_58                      = 88,
	NPC_59                      = 89,
	NPC_5A                      = 90,
	NPC_5B                      = 91,
};

#define PARADE_SCROLL_RATE (2.0f/3.0f)

enum {
    PARADE_PHASE_0	     	= 0,
};

#define NAMESPACE end_00
