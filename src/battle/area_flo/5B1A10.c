#include "common.h"

#define NAMESPACE b_area_flo

#include "common/ShrinkActor.inc.c"

#define NAMESPACE dup_b_area_flo
#include "common/GetSelectedMoveID.inc.c"
#define NAMESPACE b_area_flo

#define NAMESPACE dup2_b_area_flo
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_flo

#include "common/StartRumbleWithParams.inc.c"

ApiStatus func_80218808_5B1CB8(Evt* script, s32 isInitialCall) {
    Actor* actor;
    s32 actorType;
    s32 value;

    Bytecode* readPos = script->ptrReadPos;
    ActorID actorId = evt_get_variable(script, *readPos++);

    if (actorId == -0x7F) {
        actorId = script->owner1.enemyID;
    }

    actor = get_actor(actorId);
    actorType = actor->actorType;

    // These gotos are weird, but they produce the least weird looking match
    // that I have found. Alternatives are an
    //    evt_set_variable(script, *readPos, 0);
    // in every possible else of every if, or a top level switch with breaks
    // instead of gotos.
    //
    // Likewise, combining the conditions in any way will break the compiler's
    // choice of the bnezl instruction.
    if (actorType != 0x47) {
        if (actorType >= 0x47) {
            if (actorType < 0x65) {
                if (actorType >= 0x4D) {
                    evt_set_variable(script, *readPos, -1);
                    goto done;
                }
            }
        }
    } else {
        if (actor->varTable[8] == 1) {
            evt_set_variable(script, *readPos, -1);
            goto done;
        }
    }

    evt_set_variable(script, *readPos, 0);

done:
    return ApiStatus_DONE2;
}

