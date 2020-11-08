#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include "types.h"

typedef s32 MessageID;

#define MESSAGE_ID(section, index) ((section << 0x10) + index)

#define MessageID_TATTLE_KMR_03 MESSAGE_ID(0x19, 0x3B)
#define MessageID_TATTLE_KMR_12 MESSAGE_ID(0x19, 0x40)

#define MessageID_SIGN_MUSHROOM_GOOMBA_TRAP MESSAGE_ID(0x1D, 0x167)
#define MessageID_SIGN_GOOMBA_KINGS_FORTRESS_AHEAD MESSAGE_ID(0x1D, 0x168)

#endif
