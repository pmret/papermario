#include "common.h"
#include "battle/battle.h"


ApiStatus N(UnkFunc52)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;

    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    actor = get_actor(actorID);

    switch (actor->actorType) {
        case ACTOR_TYPE_MAGIKOOPA:
        case ACTOR_TYPE_FLYING_MAGIKOOPA:
        case ACTOR_TYPE_MAGICLONE:
        case ACTOR_TYPE_FLYING_MAGICLONE:
        case ACTOR_TYPE_RED_MAGIKOOPA:
        case ACTOR_TYPE_FLYING_RED_MAGIKOOPA:
        case ACTOR_TYPE_GREEN_MAGIKOOPA:
        case ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA:
        case ACTOR_TYPE_YELLOW_MAGIKOOPA:
        case ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA:
        case ACTOR_TYPE_GRAY_MAGIKOOPA:
        case ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA:
        case ACTOR_TYPE_WHITE_MAGIKOOPA:
        case ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA:
        case ACTOR_TYPE_UNUSED_5B:
        case ACTOR_TYPE_UNUSED_5C:
        case ACTOR_TYPE_UNUSED_5D:
        case ACTOR_TYPE_UNUSED_5E:
        case ACTOR_TYPE_UNUSED_5F:
        case ACTOR_TYPE_UNUSED_60:
        case ACTOR_TYPE_UNUSED_61:
        case ACTOR_TYPE_UNUSED_62:
        case ACTOR_TYPE_UNUSED_63:
        case ACTOR_TYPE_UNUSED_64:
            evt_set_variable(script, *args, -1);
            break;

        case ACTOR_TYPE_DRY_BONES:
            if (actor->state.varTable[8] == 1) {
                evt_set_variable(script, *args, -1);
                break;
            }
        default:
            evt_set_variable(script, *args, 0);
    }

    return ApiStatus_DONE2;
}
