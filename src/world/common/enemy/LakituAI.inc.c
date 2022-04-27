// required include args
#ifndef AI_LAKITU_FIRST_SPINY_ID
#error  AI_LAKITU_FIRST_SPINY_ID must be defined for LakituAI
#define AI_LAKITU_FIRST_SPINY_ID 0
#endif
#ifndef AI_LAKITU_LAST_SPINY_ID
#error  AI_LAKITU_LAST_SPINY_ID must be defined for LakituAI
#define AI_LAKITU_LAST_SPINY_ID 0
#endif

// prerequisites
#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/state/LakituAI_GetAvailableSpiny.inc.c"
#include "world/common/enemy/state/LakituAI_Wander.inc.c"
#include "world/common/enemy/state/LakituAI_Loiter.inc.c"
#include "world/common/enemy/state/LakituAI_Main.inc.c"
