#include "common.h"

// args: start, end, duration, EasingType
ApiStatus MakeLerp(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    script->varTable[0xC] = evt_get_variable(script, *ptrReadPos++); // start
    script->varTable[0xD] = evt_get_variable(script, *ptrReadPos++); // end
    script->varTable[0xF] = evt_get_variable(script, *ptrReadPos++); // duration
    script->varTable[0xB] = evt_get_variable(script, *ptrReadPos++); // easing type
    script->varTable[0xE] = 0; // elapsed

    return ApiStatus_DONE2;
}

ApiStatus UpdateLerp(Evt* script, s32 isInitialCall) {
    script->varTable[0x0] = (s32) update_lerp(
                                script->varTable[0xB],
                                script->varTable[0xC],
                                script->varTable[0xD],
                                script->varTable[0xE],
                                script->varTable[0xF]
                            );

    if (script->varTable[0xE] >= script->varTable[0xF]) {
        script->varTable[0x1] = 0; // finished
    } else {
        script->varTable[0x1] = 1; // lerping
    }
    script->varTable[0xE]++;

    return ApiStatus_DONE2;
}

ApiStatus RandInt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    s32 max = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;

    evt_set_variable(script, outVar, rand_int(max));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleBetweenNPCs(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    s32 aID = evt_get_variable(script, *args++);
    s32 bID = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;

    Npc* a = resolve_npc(script, aID);
    Npc* b = resolve_npc(script, bID);
    evt_set_variable(script, outVar, atan2(a->pos.x, a->pos.z, b->pos.x, b->pos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleToNPC(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;

    s32 npcID = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;

    Npc* npc = resolve_npc(script, npcID);
    evt_set_variable(script, outVar, atan2(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleToPlayer(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;

    s32 npcID = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;

    Npc* npc = resolve_npc(script, npcID);
    evt_set_variable(script, outVar, atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z));

    return ApiStatus_DONE2;
}

ApiStatus AwaitPlayerApproach(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;

    if (isInitialCall) {
        *targetX = evt_get_variable(script, *args++);
        *targetZ = evt_get_variable(script, *args++);
        *distanceRequired = evt_get_variable(script, *args++);
    }

    distance = dist2D(
                   playerStatus->pos.x, playerStatus->pos.z,
                   *targetX, *targetZ
               );

    if (distance < *distanceRequired) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus IsPlayerWithin(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;
    Bytecode outVar = LVar0;

    if (isInitialCall) {
        *targetX = evt_get_variable(script, *args++);
        *targetZ = evt_get_variable(script, *args++);
        *distanceRequired = evt_get_variable(script, *args++);
        outVar = *args++;
    }

    distance = dist2D(
                   playerStatus->pos.x, playerStatus->pos.z,
                   *targetX, *targetZ
               );

    evt_set_variable(script, outVar, 0);
    if (distance < *distanceRequired) {
        evt_set_variable(script, outVar, 1);
    }

    return ApiStatus_DONE2;
}

ApiStatus AwaitPlayerLeave(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;

    if (isInitialCall) {
        *targetX = evt_get_variable(script, *ptrReadPos++);
        *targetZ = evt_get_variable(script, *ptrReadPos++);
        *distanceRequired = evt_get_variable(script, *ptrReadPos++);
    }

    distance = dist2D(
                   playerStatus->pos.x, playerStatus->pos.z,
                   *targetX, *targetZ
               );

    if (distance > *distanceRequired) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus AddVectorPolar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    Bytecode xVar = *args++;
    f32 x = evt_get_float_variable(script, xVar);

    Bytecode yVar = *args++;
    f32 y = evt_get_float_variable(script, yVar);

    f32 r = evt_get_float_variable(script, *args++);

    add_vec2D_polar(&x, &y, r, evt_get_float_variable(script, *args++));

    evt_set_float_variable(script, xVar, x);
    evt_set_float_variable(script, yVar, y);

    return ApiStatus_DONE2;
}

ApiStatus func_802D4BDC(Evt* script, s32 isInitialCall) {
    s32* ready = &script->functionTemp[0];
    s32* progress = &script->functionTemp[1];
    s32 t1v;

    if (isInitialCall) {
        *ready = 0;
        *progress = 0;
    }

    // always zero?
    if (*ready == 0) {
        t1v = *progress;
        if (t1v == 255) {
            return ApiStatus_DONE2;
        }

        t1v += 10;
        *progress = t1v;
        if (t1v > 255) {
            *progress = 255;
        }

        set_screen_overlay_params_back(OVERLAY_START_BATTLE, *progress);
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802D4C4C(Evt* script, s32 isInitialCall) {
    s32* ready = &script->functionTemp[0];
    s32* progress = &script->functionTemp[1];
    s32 t1v;

    if (isInitialCall) {
        *ready = 0;
        *progress = 255;
    }

    // always zero?
    if (*ready == 0) {
        t1v = *progress;
        if (t1v == 0) {
            set_screen_overlay_params_back(OVERLAY_NONE, -1.0f);
            return ApiStatus_DONE2;
        }
        t1v -= 10;
        *progress = t1v;
        if (t1v < 0) {
            *progress = 0;
        }
        set_screen_overlay_params_back(OVERLAY_START_BATTLE, *progress);
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802D4CC4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 value = evt_get_variable(script, *args++);

    if (value < 0) {
        set_screen_overlay_params_back(OVERLAY_NONE, -1.0f);
    } else {
        set_screen_overlay_params_back(OVERLAY_START_BATTLE, value);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802D4D14(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 value = evt_get_float_variable(script, *args++);

    set_screen_overlay_center(SCREEN_LAYER_FRONT, 0, 12, 20);
    set_screen_overlay_center(SCREEN_LAYER_FRONT, 1, 308, 220);
    set_screen_overlay_params_front(OVERLAY_BLUR, value);

    return ApiStatus_DONE2;
}

ApiStatus func_802D4D88(Evt* script, s32 isInitialCall) {
    set_screen_overlay_params_front(OVERLAY_BLUR, 0);
    return ApiStatus_DONE2;
}

void load_path_data(s32 num, f32* normalizedLengths, Vec3f* pathPositions, Vec3f* outVectors) {
    f32* lenBuf = heap_malloc(num * sizeof(f32));
    Vec3f* vecBuf = heap_malloc(num * sizeof(Vec3f));
    s32 i;

    // compute the distance of each vector along the path and map to the range [0,1]
    normalizedLengths[0] = 0.0f;
    for (i = 1; i < num; i++) {
        f32 dx = pathPositions[i].x - pathPositions[i-1].x;
        f32 dy = pathPositions[i].y - pathPositions[i-1].y;
        f32 dz = pathPositions[i].z - pathPositions[i-1].z;
        f32 length = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
        normalizedLengths[i] = normalizedLengths[i-1] + length;
    }
    for (i = 1; i < num; i++) {
        normalizedLengths[i] /= normalizedLengths[num-1];
    }

    // end points
    outVectors[0].x = 0.0f;
    outVectors[0].y = 0.0f;
    outVectors[0].z = 0.0f;
    outVectors[num-1].x = 0.0f;
    outVectors[num-1].y = 0.0f;
    outVectors[num-1].z = 0.0f;

    for (i = 0; i < num - 1; i++) {
        lenBuf[i] = normalizedLengths[i+1] - normalizedLengths[i];
        vecBuf[i+1].x = (pathPositions[i+1].x - pathPositions[i].x) / lenBuf[i];
        vecBuf[i+1].y = (pathPositions[i+1].y - pathPositions[i].y) / lenBuf[i];
        vecBuf[i+1].z = (pathPositions[i+1].z - pathPositions[i].z) / lenBuf[i];
    }

    // n = 1
    outVectors[1].x = vecBuf[2].x - vecBuf[1].x;
    outVectors[1].y = vecBuf[2].y - vecBuf[1].y;
    outVectors[1].z = vecBuf[2].z - vecBuf[1].z;
    vecBuf[1].x = 2.0f * (normalizedLengths[2] - normalizedLengths[0]);
    vecBuf[1].y = 2.0f * (normalizedLengths[2] - normalizedLengths[0]);
    vecBuf[1].z = 2.0f * (normalizedLengths[2] - normalizedLengths[0]);

    // 1 < n < N - 2
    for (i = 1; i < num - 2; i++) {
        f32 sx = lenBuf[i] / vecBuf[i].x;
        f32 sy = lenBuf[i] / vecBuf[i].y;
        f32 sz = lenBuf[i] / vecBuf[i].z;
        outVectors[i+1].x = (vecBuf[i+2].x - vecBuf[i+1].x) - outVectors[i].x * sx;
        outVectors[i+1].y = (vecBuf[i+2].y - vecBuf[i+1].y) - outVectors[i].y * sy;
        outVectors[i+1].z = (vecBuf[i+2].z - vecBuf[i+1].z) - outVectors[i].z * sz;
        vecBuf[i+1].x = 2.0f * (normalizedLengths[i+2] - normalizedLengths[i]) - lenBuf[i] * sx;
        vecBuf[i+1].y = 2.0f * (normalizedLengths[i+2] - normalizedLengths[i]) - lenBuf[i] * sy;
        vecBuf[i+1].z = 2.0f * (normalizedLengths[i+2] - normalizedLengths[i]) - lenBuf[i] * sz;
    }

    // n = N - 2
    outVectors[num-2].x -= (lenBuf[num-2] * outVectors[num-1].x);
    outVectors[num-2].y -= (lenBuf[num-2] * outVectors[num-1].y);
    outVectors[num-2].z -= (lenBuf[num-2] * outVectors[num-1].z);

    for (i = num - 2; i > 0; i--) {
        outVectors[i].x = (outVectors[i].x - (lenBuf[i] * outVectors[i+1].x)) / vecBuf[i].x;
        outVectors[i].y = (outVectors[i].y - (lenBuf[i] * outVectors[i+1].y)) / vecBuf[i].y;
        outVectors[i].z = (outVectors[i].z - (lenBuf[i] * outVectors[i+1].z)) / vecBuf[i].z;
    }

    heap_free(lenBuf);
    heap_free(vecBuf);
}

void get_path_position(f32 alpha, Vec3f* outPos, s32 numVectors, f32* normalizedLengths, Vec3f* pathPoints, Vec3f* vectors) {
    s32 limit = numVectors - 1;
    f32 curLength;
    f32 curProgress;
    f32 ax, ay, az, bx, by, bz, dx, dy, dz;
    s32 i;

    for (i = 0; i < limit;) {
        s32 temp_v1 = (i + limit) / 2;

        if (normalizedLengths[temp_v1] < alpha) {
            i = temp_v1 + 1;
        } else {
            limit = temp_v1;
        }
    }

    if (i > 0) {
        i--;
    }

    curLength = normalizedLengths[i+1] - normalizedLengths[i];
    curProgress = alpha - normalizedLengths[i];

    dx = (pathPoints[i+1].x - pathPoints[i].x) / curLength;
    ax = (((vectors[i+1].x - vectors[i].x) * curProgress / curLength) + (3.0f * vectors[i].x)) * curProgress;
    bx = dx - (((2.0f * vectors[i].x) + vectors[i+1].x) * curLength);
    outPos->x = ((ax + bx) * curProgress) + pathPoints[i].x;

    dy = (pathPoints[i+1].y - pathPoints[i].y) / curLength;
    ay = (((vectors[i+1].y - vectors[i].y) * curProgress / curLength) + (3.0f * vectors[i].y)) * curProgress;
    by = dy - (((2.0f * vectors[i].y) + vectors[i+1].y) * curLength);
    outPos->y = ((ay + by) * curProgress) + pathPoints[i].y;

    dz = (pathPoints[i+1].z - pathPoints[i].z) / curLength;
    az = (((vectors[i+1].z - vectors[i].z) * curProgress / curLength) + (3.0f * vectors[i].z)) * curProgress;
    bz = dz - (((2.0f * vectors[i].z) + vectors[i+1].z) * curLength);
    outPos->z = ((az + bz) * curProgress) + pathPoints[i].z;
}

s32 LoadPath(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 time = evt_get_variable(script, *args++);
    Vec3f* vectorList = (Vec3f*) evt_get_variable(script, *args++);
    s32 numVectors = evt_get_variable(script, *args++);
    s32 easingType = evt_get_variable(script, *args++);
    Path* path = heap_malloc(sizeof(*path));

    script->varTablePtr[15] = path;
    path->numVectors = numVectors;
    path->lengths = heap_malloc(numVectors * sizeof(f32));
    path->staticVectorList = vectorList;
    path->vectors = heap_malloc(numVectors * sizeof(Vec3f));
    load_path_data(path->numVectors, path->lengths, path->staticVectorList, path->vectors);

    path->timeElapsed = 0;
    path->timeLeft = time - 1;
    path->easingType = easingType;

    return ApiStatus_DONE2;
}

ApiStatus GetNextPathPos(Evt* script, s32 isInitialCall) {
    Path* path = script->varTablePtr[0xF];
    Vec3f pos;
    f32 alpha;
    f32 diff;

    switch (path->easingType) {
        case EASING_LINEAR:
            alpha = 1.0f / path->timeLeft * path->timeElapsed;
            break;
        case EASING_QUADRATIC_IN:
            alpha = 1.0f / SQ(path->timeLeft) * SQ(path->timeElapsed);
            break;
        case EASING_QUADRATIC_OUT:
            diff = path->timeLeft - path->timeElapsed;
            alpha = 1.0f - (SQ(diff) / SQ(path->timeLeft));
            break;
        case EASING_COS_IN_OUT:
            alpha = (1.0f - cos_rad((PI / path->timeLeft) * path->timeElapsed)) * 0.5f;
            break;
        default:
            alpha = 0.0f;
            break;
    }

    get_path_position(alpha, &pos, path->numVectors, path->lengths, path->staticVectorList, path->vectors);
    script->varTable[1] = (pos.x * 1024.0f) + -2.3e8f;
    script->varTable[2] = (pos.y * 1024.0f) + -2.3e8f;
    script->varTable[3] = (pos.z * 1024.0f) + -2.3e8f;

    if (path->timeElapsed < path->timeLeft) {
        path->timeElapsed = path->timeElapsed + 1;
        script->varTable[0] = 1;
    } else {
        heap_free(path->lengths);
        heap_free(path->vectors);
        heap_free(script->varTablePtr[15]);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetDist2D(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    f32 ax = evt_get_float_variable(script, *args++);
    f32 ay = evt_get_float_variable(script, *args++);
    f32 bx = evt_get_float_variable(script, *args++);
    f32 by = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, outVar, dist2D(ax, ay, bx, by));

    return ApiStatus_DONE2;
}

ApiStatus SetTimeFreezeMode(Evt* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;

    set_time_freeze_mode(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus ModifyGlobalOverrideFlags(Evt* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 setMode = evt_get_variable(script, *args++);
    s32 flags = evt_get_variable(script, *args++);

    if (setMode) {
        gOverrideFlags |= flags;
    } else {
        gOverrideFlags &= ~flags;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetValueByRef(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    s32 dest = evt_get_variable(script, *args++); /* Reference */
    s32 src = evt_get_variable(script, *args++);
    evt_set_variable(script, dest, src);

    return ApiStatus_DONE2;
}

ApiStatus GetValueByRef(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 src = evt_get_variable(script, *args++); /* Reference */
    Bytecode dest = *args++;

    evt_set_variable(script, dest, evt_get_variable(script, src));

    return ApiStatus_DONE2;
}

ApiStatus EnableWorldStatusBar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    b32 shouldEnable = evt_get_variable(script, *args++);

    if (shouldEnable) {
        decrement_status_bar_disabled();
    } else {
        increment_status_bar_disabled();
    }

    return ApiStatus_DONE2;
}

ApiStatus ShowWorldStatusBar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    b32 shouldShow = evt_get_variable(script, *args++);

    if (shouldShow) {
        status_bar_ignore_changes();
        close_status_bar();
    } else {
        status_bar_respond_to_changes();
    }

    return ApiStatus_DONE2;
}

ApiStatus SetGameMode(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s16 mode = evt_get_variable(script, *args++);

    set_game_mode(mode);

    return ApiStatus_DONE2;
}

ApiStatus ClampAngleInt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 angle = evt_get_variable(script, *args);

    evt_set_variable(script, *args++, clamp_angle(angle));

    return ApiStatus_DONE2;
}

ApiStatus ClampAngleFloat(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 angle = evt_get_float_variable(script, *args);

    evt_set_float_variable(script, *args++, clamp_angle(angle));

    return ApiStatus_DONE2;
}

#if VERSION_PAL
ApiStatus GetLanguage(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCurrentLanguage);
    return ApiStatus_DONE2;
}
#endif
