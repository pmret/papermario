#include "common.h"
#include "npc.h"

// checks whether the player has crossed the plane defined by points A = (Ax, Az) and B = (Bx, Bz)
// this plane divides space into two halves: a "positive" region and "negative" region, with the positive
// region on the right side of the line going from A to B.
/*
    ex: the region depicted goes from x = [0,100] and z = [0,100] with A = (10,10) and B = (60,80)
(z)
100 ---------------++++++
    ---------------++++++
    --------------+++++++
    -------------++++++++
    ------------B++++++++
    ------------+++++++++
    -----------++++++++++
    ----------+++++++++++
    ----------+++++++++++
    ---------++++++++++++
    --------+++++++++++++
    --------+++++++++++++
    -------++++++++++++++
    ------+++++++++++++++
    -----++++++++++++++++
    -----++++++++++++++++
    ----+++++++++++++++++
    ---++++++++++++++++++
    --A++++++++++++++++++
    --+++++++++++++++++++
  0 -++++++++++++++++++++
    0                   100 (x)
*/

// returns (on LVar0) the side of the plane the player is on
#define PLANE_SIDE_NEGATIVE     0
#define PLANE_SIDE_POSITIVE     1

API_CALLABLE(N(CheckPositionRelativeToPlane)) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 Ax = evt_get_variable(script, *args++);
    f32 Az = evt_get_variable(script, *args++);
    f32 Bx = evt_get_variable(script, *args++);
    f32 Bz = evt_get_variable(script, *args++);
    f32 dzdx;

    dzdx = (Bz - Az) / (Bx - Ax);

    // this is equivalent to testing the determinant: ((Bx - Ax)*(Pz - Az) - (Bz - Az)*(Px - Ax)) < 0
    if (playerStatus->pos.z < ((dzdx * playerStatus->pos.x) + (Az - (dzdx * Ax)))) {
        script->varTable[0] = PLANE_SIDE_NEGATIVE;
    } else {
        script->varTable[0] = PLANE_SIDE_POSITIVE;
    }

    return ApiStatus_DONE2;
}
