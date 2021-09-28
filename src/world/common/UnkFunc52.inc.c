#include "common.h"

ApiStatus N(UnkFunc52)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;

    ActorID actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    actor = get_actor(actorID);

    switch (actor->actorType) {
        case 0x4D: case 0x4E: case 0x4F: case 0x50:
        case 0x51: case 0x52: case 0x53: case 0x54:
        case 0x55: case 0x56: case 0x57: case 0x58:
        case 0x59: case 0x5A: case 0x5B: case 0x5C:
        case 0x5D: case 0x5E: case 0x5F: case 0x60:
        case 0x61: case 0x62: case 0x63: case 0x64:
            evt_set_variable(script, *args, -1);
            break;

        case 0x47:
            if (actor->varTable[8] == 1) {
                evt_set_variable(script, *args, -1);
                break;
            }
        default:
            evt_set_variable(script, *args, 0);
    }

    return ApiStatus_DONE2;
}
