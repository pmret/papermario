#include "trd_01.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

#include "world/common/UnkNpcAIMainFunc5.inc.c"

#include "world/common/UnkNpcAIFunc43.inc.c"

#include "world/common/UnkNpcAIFunc44.inc.c"

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

#include "world/common/UnkNpcAIFunc42.inc.c"

#include "world/common/UnkNpcAIFunc45.inc.c"

#include "world/common/UnkNpcAIMainFunc4.inc.c"

ApiStatus func_80241630_99DFC0(Evt* script, s32 isInitialCall) {
    Enemy* owner1 = script->owner1.enemy;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    owner1->territory->wander.point.x = npc->pos.x;
    owner1->territory->wander.point.y = npc->pos.y;
    owner1->territory->wander.point.z = npc->pos.z;
    owner1->territory->wander.detect.x = npc->pos.x;
    owner1->territory->wander.detect.y = npc->pos.y;
    owner1->territory->wander.detect.z = npc->pos.z;
    return ApiStatus_DONE2;
}
