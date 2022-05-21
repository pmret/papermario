#include "common.h"

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
    evt_set_variable(script, outVar, atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleToPlayer(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;

    s32 npcID = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;

    Npc* npc = resolve_npc(script, npcID);
    evt_set_variable(script, outVar, atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z));

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
                   playerStatus->position.x, playerStatus->position.z,
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
    Bytecode outVar = EVT_VAR(0);

    if (isInitialCall) {
        *targetX = evt_get_variable(script, *args++);
        *targetZ = evt_get_variable(script, *args++);
        *distanceRequired = evt_get_variable(script, *args++);
        outVar = *args++;
    }

    distance = dist2D(
                   playerStatus->position.x, playerStatus->position.z,
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
                   playerStatus->position.x, playerStatus->position.z,
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

ApiStatus func_802D4BDC(Evt* script, s32 initialCall) {
    s32* t0 = &script->functionTemp[0];
    s32* t1 = &script->functionTemp[1];
    s32 t1v;

    if (initialCall) {
        *t0 = 0;
        *t1 = 0;
    }

    if (*t0 == 0) {
        t1v = *t1;
        if (t1v == 255) {
            return ApiStatus_DONE2;
        }

        t1v += 10;
        *t1 = t1v;
        if (t1v > 255) {
            *t1 = 255;
        }

        set_screen_overlay_params_back(10, *t1);
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802D4C4C(Evt* script, s32 initialCall) {
    s32* t0 = &script->functionTemp[0];
    s32* t1 = &script->functionTemp[1];
    s32 t1v;

    if (initialCall) {
        *t0 = 0;
        *t1 = 255;
    }

    if (*t0 == 0) {
        t1v = *t1;
        if (t1v == 0) {
            set_screen_overlay_params_back(255, -1.0f);
            return ApiStatus_DONE2;
        }
        t1v -= 10;
        *t1 = t1v;
        if (t1v < 0) {
            *t1 = 0;
        }
        set_screen_overlay_params_back(10, *t1);
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802D4CC4(Evt* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 value = evt_get_variable(script, *args++);

    if (value < 0) {
        set_screen_overlay_params_back(255, -1.0f);
    } else {
        set_screen_overlay_params_back(10, value);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802D4D14(Evt* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 value = evt_get_float_variable(script, *args++);

    set_screen_overlay_center(0, 0, 0xC, 0x14);
    set_screen_overlay_center(0, 1, 0x134, 0xDC);
    set_screen_overlay_params_front(0xC, value);

    return ApiStatus_DONE2;
}

ApiStatus func_802D4D88(Evt* script, s32 initialCall) {
    set_screen_overlay_params_front(0xC, 0);
    return ApiStatus_DONE2;
}

void load_path_data(s32 numVectors, f32* arg1, Vec3f* staticVectorList, Vec3f* vectors);

#ifdef NON_EQUIVALENT
// most likely functionally equivalent, lots of issues though.
void load_path_data(s32 numVectors, f32* arg1, Vec3f* staticVectorList, Vec3f* vectors) {
    struct Vec3f* temp_s4;
    f32* temp_s7;
    s32 i;
    f32* temp;
    f32 new_var;
    f32 new_var2;

    temp_s7 = heap_malloc(numVectors * sizeof(f32));
    temp_s4 = heap_malloc(numVectors * sizeof(Vec3f));
    arg1[0] = 0.0f;

    for (i = 1; i < numVectors; i++) {
        f32 temp_x = SQ(staticVectorList[i].x - staticVectorList[i - 1].x);
        f32 temp_y = SQ(staticVectorList[i].y - staticVectorList[i - 1].y);
        f32 temp_z = SQ(staticVectorList[i].z - staticVectorList[i - 1].z);
        arg1[i] = arg1[i - 1] + sqrtf(temp_x + temp_y + temp_z);
    }

    for (i = 1; i < numVectors; i++) {
        arg1[i] = arg1[i] / arg1[numVectors - 1];
    }

    vectors[0].x = 0;

    vectors[numVectors - 1].z = 0;
    vectors[0].z = 0;

    vectors[numVectors - 1].x = 0;

    vectors[0].y = 0;
    vectors[numVectors - 1].y = 0;

    for (i = 0; i < (numVectors - 1); i++) {
        f32 temp = temp_s7[i];
        temp_s7[i] = arg1[i + 1] - arg1[i];
        temp_s4[i + 1].x = ((staticVectorList[i + 1].x - staticVectorList[i].x) / temp_s7[i]);
        temp_s4[i + 1].y = ((staticVectorList[i + 1].y - staticVectorList[i].y) / temp);
        temp_s4[i + 1].z = ((staticVectorList[i + 1].z - staticVectorList[i].z) / temp);
    }

    vectors[1].x = temp_s4[2].x - temp_s4[1].x;
    vectors[1].y = temp_s4[2].y - temp_s4[1].y;
    vectors[1].z = temp_s4[2].z - temp_s4[1].z;
    temp_s4[1].x = ((arg1[2] - arg1[0]) * 2);
    temp_s4[1].y = ((arg1[2] - arg1[0]) * 2);
    temp_s4[1].z = ((arg1[2] - arg1[0]) * 2);

    for (i = 1; i < numVectors - 2; i++) {
        f32 temp_x = temp_s7[i] / temp_s4[i].x;
        f32 temp_y = temp_s7[i] / temp_s4[i].y;
        f32 temp_z = temp_s7[i] / temp_s4[i].z;
        new_var = vectors[i].x;
        vectors[i + 1].x = (temp_s4[i + 2].x - temp_s4[i].x) - (new_var * temp_x);
        vectors[i + 1].y = (temp_s4[i + 2].y - temp_s4[i].y) - (new_var * temp_y);
        vectors[i + 1].z = (temp_s4[i + 2].z - temp_s4[i].z) - (new_var * temp_z);
        temp_s4[i].x = ((arg1[i + 2] - arg1[i]) * 2) - (temp_s7[i] * temp_x);
        temp_s4[i].y = ((arg1[i + 2] - arg1[i]) * 2) - (temp_s7[i] * temp_y);
        temp_s4[i].z = ((arg1[i + 2] - arg1[i]) * 2) - (temp_s7[i] * temp_z);
    }

    vectors[numVectors - 2].x = vectors[numVectors - 2].x - (temp_s7[numVectors - 2] * vectors[numVectors - 1].x);
    vectors[numVectors - 2].y = vectors[numVectors - 2].y - (temp_s7[numVectors - 2] * vectors[numVectors - 1].y);
    vectors[numVectors - 2].z = vectors[numVectors - 2].z - (temp_s7[numVectors - 2] * vectors[numVectors - 1].z);

    for (i = (numVectors - 2); i > 0 ; i--) {
        vectors[i].x = (vectors[i].x - (temp_s7[i] * vectors[i + 1].x)) / temp_s4[i].x;
        vectors[i].y = (vectors[i].y - (temp_s7[i] * vectors[i + 1].y)) / temp_s4[i].y;
        vectors[i].z = (vectors[i].z - (temp_s7[i] * vectors[i + 1].z)) / temp_s4[i].z;
    }

    heap_free(temp_s7);
    heap_free(temp_s4);
}
#else
INCLUDE_ASM(s32, "evt/f8f60_len_1560", load_path_data);
#endif

void get_path_position(f32 alpha, Vec3f* outPos, s32 numVectors, f32* normalizedLengths, Vec3f* staticVectors, Vec3f* vectors) {
    s32 limit = numVectors - 1;
    f32 lenDiff;
    f32 diff2;
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

    lenDiff = normalizedLengths[i + 1] - normalizedLengths[i];
    diff2 = alpha - normalizedLengths[i];

    outPos->x = (((((((vectors[i + 1].x - vectors[i].x) * diff2) / lenDiff) + (vectors[i].x * 3.0f)) * diff2) + (((staticVectors[i + 1].x - staticVectors[i].x) / lenDiff) - (((2.0f * vectors[i].x) + vectors[i + 1].x) * lenDiff))) * diff2) + staticVectors[i].x;

    outPos->y = (((((((vectors[i + 1].y - vectors[i].y) * diff2) / lenDiff) + (vectors[i].y * 3.0f)) * diff2) + (((staticVectors[i + 1].y - staticVectors[i].y) / lenDiff) - (((2.0f * vectors[i].y) + vectors[i + 1].y) * lenDiff))) * diff2) + staticVectors[i].y;

    outPos->z = (((((((vectors[i + 1].z - vectors[i].z) * diff2) / lenDiff) + (vectors[i].z * 3.0f)) * diff2) + (((staticVectors[i + 1].z - staticVectors[i].z) / lenDiff) - (((2.0f * vectors[i].z) + vectors[i + 1].z) * lenDiff))) * diff2) + staticVectors[i].z;
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
    path->unk_04 = heap_malloc(numVectors * sizeof(f32));
    path->staticVectorList = vectorList;
    path->vectors = heap_malloc(numVectors * sizeof(Vec3f));
    load_path_data(path->numVectors, path->unk_04, path->staticVectorList, path->vectors);

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
        case 0:
            alpha = 1.0f / path->timeLeft * path->timeElapsed;
            break;
        case 1:
            alpha = 1.0f / SQ(path->timeLeft) * SQ(path->timeElapsed);
            break;
        case 4:
            diff = path->timeLeft - path->timeElapsed;
            alpha = 1.0f - (SQ(diff) / SQ(path->timeLeft));
            break;
        case 10:
            alpha = (1.0f - cos_rad((PI / path->timeLeft) * path->timeElapsed)) * 0.5f;
            break;
        default:
            alpha = 0.0f;
            break;
    }

    get_path_position(alpha, &pos, path->numVectors, path->unk_04, path->staticVectorList, path->vectors);
    script->varTable[1] = (pos.x * 1024.0f) + -2.3e8f;
    script->varTable[2] = (pos.y * 1024.0f) + -2.3e8f;
    script->varTable[3] = (pos.z * 1024.0f) + -2.3e8f;

    if (path->timeElapsed < path->timeLeft) {
        path->timeElapsed = path->timeElapsed + 1;
        script->varTable[0] = 1;
    } else {
        heap_free(path->unk_04);
        heap_free(path->vectors);
        heap_free(script->varTablePtr[15]);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetDist2D(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;

    evt_set_float_variable(script, outVar, dist2D(
                           evt_get_float_variable(script, *args++),
                           evt_get_float_variable(script, *args++),
                           evt_get_float_variable(script, *args++),
                           evt_get_float_variable(script, *args++)
                       ));

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

ApiStatus EnableStatusMenu(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    if (evt_get_variable(script, *args++) != 0) {
        decrement_status_menu_disabled();
    } else {
        increment_status_menu_disabled();
    }

    return ApiStatus_DONE2;
}

ApiStatus ShowStatusMenu(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (evt_get_variable(script, *args++) != 0) {
        func_800E9894();
        close_status_menu();
    } else {
        func_800E98C4();
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

    evt_set_variable(script, *args, clamp_angle(evt_get_variable(script, *args)));

    return ApiStatus_DONE2;
}

ApiStatus ClampAngleFloat(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_float_variable(script, *args, clamp_angle(evt_get_float_variable(script, *args)));

    return ApiStatus_DONE2;
}
