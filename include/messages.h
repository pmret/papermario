#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include "types.h"

typedef s32 MessageID;

#define MESSAGE_ID(section, index) ((section << 0x10) + index)

// 00 Introduction
// 01 Postgame Celebration
// 02 Toad Town Gate Sector
// 03 Toad Town Castle Sector
// 04 Toad Town Bridge Sector
// 05 Toad Town Train Sector
// 06 Toad Town Warehouse Sector
// 07 Toad Town Docks Sector
// 08 Minigames
// 09 Castle Grounds
// 0A Shooting Star Summit
// 0B Chapter 0
// 0C Chapter 1
// 0D Chapter 2
// 0E Chapter 3
// 0F Chapter 4
// 10 Chapter 5
// 11 Chapter 6
// 12 Chapter 7
// 13 Bowser's Castle
// 14 Peach Segments
// 15 Koopa Koot Favors
// 16 Russ T Advice
// 17 News Bulletin
// 18 Gossip Bulletin

// 19 Map Tattles
#define MessageID_TATTLE_KMR_03 MESSAGE_ID(0x19, 0x3B)
#define MessageID_TATTLE_KMR_12 MESSAGE_ID(0x19, 0x40)

// 1A NPC Tattles
// 1B Entity Tattles
// 1C Enemy Tattles

// 1D Menus I
#define MessageID_SIGN_MUSHROOM_GOOMBA_TRAP MESSAGE_ID(0x1D, 0x167)
#define MessageID_SIGN_GOOMBA_KINGS_FORTRESS_AHEAD MESSAGE_ID(0x1D, 0x168)

// 1E Choices
// 1F Menus II
// 20 Party Letters + Luigi's Diary
// 21 Advice Fortunes
// 22 Treasure Fortunes
// 23 Item Descriptions I
// 24 Item Descriptions II
// 25 Item Descriptions III
// 26 Item Names
// 27 Shop Messages
// 28 Partner Descriptions
// 29 Enemy Names
// 2A Mario Moves
// 2B Partner Moves
// 2C Quiz Questions
// 2D Quiz Options
// 2E Credits

#endif
