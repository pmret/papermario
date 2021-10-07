#include "common.h"

#define NAMESPACE action_command_fire_shell

INCLUDE_ASM(s32, "battle/action_cmd/fire_shell", func_802A9000_4269D0);

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/fire_shell", func_802A9294_426C64);

#include "battle/action_cmd/common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
