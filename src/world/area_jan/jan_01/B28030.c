#include "jan_01.h"

static char* N(exit_str_0) = "jan_00";
static char* N(exit_str_1) = "jan_02";

#include "world/common/atomic/TexturePan.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_01/B28030", func_8024030C_B2833C);

#include "world/common/atomic/enemy/FuzzyAI.inc.c"

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"
