#include "MonitorPlayerOrbiting.h"

API_CALLABLE(N(MonitorPlayerOrbiting)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerOrbitTarget* target = (PlayerOrbitTarget*) evt_get_variable(script, *script->ptrReadPos);
    PlayerOrbitState* orbit;
    s32 prevAngle, curAngle;
    s32 deltaAngle;
    s32 dist;

    if (isInitialCall) {
        orbit = script->functionTempPtr[1] = heap_malloc(sizeof(*orbit));
        orbit->pos.x = target->pos.x;
        orbit->pos.y = target->pos.y;
        orbit->pos.z = target->pos.z;
        orbit->startRadius = target->startRadius;
        orbit->orbitRadius = target->orbitRadius;
        orbit->eventListener = target->eventListener;
        orbit->totalOrbitAngle = 0;
        orbit->numRotations = 0;
        orbit->state = 0;
        orbit->firstPlayerX = 0;
        orbit->firstPlayerZ = 0;
        orbit->lastPlayerX = 0;
        orbit->lastPlayerZ = 0;
        orbit->direction = 0;
        orbit->lastNumRotations = 0;
    }

    orbit = script->functionTempPtr[1];
    switch (orbit->state) {
        case ORBIT_STATE_FIRST_FRAME:
            // wait for player to come within range
            dist = get_xz_dist_to_player(orbit->pos.x, orbit->pos.z);
            if (dist < orbit->startRadius) {
                orbit->firstPlayerX = playerStatus->pos.x;
                orbit->firstPlayerZ = playerStatus->pos.z;
                orbit->state++;
            }
            break;

        case ORBIT_STATE_SECOND_FRAME:
            // determine direction the player is orbiting
            dist = get_xz_dist_to_player(orbit->pos.x, orbit->pos.z);
            if (dist < orbit->startRadius) {
                prevAngle = atan2(orbit->pos.x, orbit->pos.z, orbit->firstPlayerX, orbit->firstPlayerZ);
                curAngle = atan2(orbit->pos.x, orbit->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                deltaAngle = get_clamped_angle_diff(prevAngle, curAngle);
                orbit->direction = signF(deltaAngle);
                orbit->state++;
                break;
            }
            orbit->state = ORBIT_STATE_FIRST_FRAME;
            break;

        case ORBIT_STATE_STARTING_ORBIT:
            dist = get_xz_dist_to_player(orbit->pos.x, orbit->pos.z);
            if (dist < orbit->startRadius) {
                prevAngle = atan2(orbit->pos.x, orbit->pos.z, orbit->lastPlayerX, orbit->lastPlayerZ);
                curAngle = atan2(orbit->pos.x, orbit->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                deltaAngle = get_clamped_angle_diff(prevAngle, curAngle);
                if (orbit->direction == signF(deltaAngle)) {
                    prevAngle = atan2(orbit->pos.x, orbit->pos.z, orbit->firstPlayerX, orbit->firstPlayerZ);
                    curAngle = atan2(orbit->pos.x, orbit->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                    deltaAngle = get_clamped_angle_diff(prevAngle, curAngle);
                    if (fabsf(deltaAngle) > 90.0f) {
                        if (orbit->eventListener != NULL) {
                            orbit->eventListener(orbit, PLAYER_ORBIT_BEGIN);
                        }
                        orbit->totalOrbitAngle += fabsf(deltaAngle);
                        orbit->state++;
                    }
                    break;
                }
            }
            orbit->state = ORBIT_STATE_FIRST_FRAME;
            break;

        case ORBIT_STATE_MAINTAIN_ORBIT:
            dist = get_xz_dist_to_player(orbit->pos.x, orbit->pos.z);
            if (dist < orbit->orbitRadius) {
                prevAngle = atan2(orbit->pos.x, orbit->pos.z, orbit->lastPlayerX, orbit->lastPlayerZ);
                curAngle = atan2(orbit->pos.x, orbit->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                deltaAngle = get_clamped_angle_diff(prevAngle, curAngle);
                if (orbit->direction != signF(deltaAngle)) {
                    if (orbit->eventListener != NULL) {
                        orbit->eventListener(orbit, PLAYER_ORBIT_CHANGE_DIRECTION);
                    }
                    orbit->state++;
                } else {
                    orbit->totalOrbitAngle = orbit->totalOrbitAngle + fabsf(deltaAngle);
                    orbit->numRotations = orbit->totalOrbitAngle / 360;
                    if (orbit->numRotations != orbit->lastNumRotations) {
                        if (orbit->eventListener != NULL) {
                            orbit->eventListener(orbit, PLAYER_ORBIT_COMPLETE_ROTATION);
                        }
                        orbit->lastNumRotations = orbit->numRotations;
                    }
                }
                if (orbit->eventListener != NULL) {
                    orbit->eventListener(orbit, PLAYER_ORBIT_CONTINUE_ORBIT);
                }
            } else {
                if (orbit->eventListener != NULL) {
                    orbit->eventListener(orbit, PLAYER_ORBIT_LEFT_REGION);
                }
                orbit->state++;
            }
            break;

        case ORBIT_STATE_BREAK_ORBIT:
            orbit->totalOrbitAngle = 0.0f;
            orbit->numRotations = 0;
            orbit->lastNumRotations = 0;
            orbit->state = ORBIT_STATE_FIRST_FRAME;
            break;
    }

    orbit->lastPlayerX = playerStatus->pos.x;
    orbit->lastPlayerZ = playerStatus->pos.z;

    return ApiStatus_BLOCK;
}
