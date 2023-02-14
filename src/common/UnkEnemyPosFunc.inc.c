#include "common.h"

API_CALLABLE(N(UnkEnemyPosFunc)) {
    Bytecode* args = script->ptrReadPos;
    Vec3f temp;
    Vec3f homePoses[4];
    s32 temp_s1;
    s32 temp_v1;
    Actor* enemy;
    Vec3f* iVec;
    Vec3f* jVec;
    s32 i, j;

    temp_s1 = get_actor(ACTOR_ENEMY4)->state.varTable[3];
    switch (temp_s1) {
        case 2:
            enemy = N(UnkEnemyFunc(3));
            homePoses[0].x = enemy->homePos.x;
            homePoses[0].y = enemy->homePos.y;
            homePoses[0].z = enemy->homePos.z;
            enemy = N(UnkEnemyFunc(6));
            homePoses[1].x = enemy->homePos.x;
            homePoses[1].y = enemy->homePos.y;
            homePoses[1].z = enemy->homePos.z;
            break;
        case 3:
            enemy = N(UnkEnemyFunc(3));
            homePoses[0].x = enemy->homePos.x;
            homePoses[0].y = enemy->homePos.y;
            homePoses[0].z = enemy->homePos.z;
            enemy = N(UnkEnemyFunc(5));
            homePoses[1].x = enemy->homePos.x;
            homePoses[1].y = enemy->homePos.y;
            homePoses[1].z = enemy->homePos.z;
            enemy = N(UnkEnemyFunc(6));
            homePoses[2].x = enemy->homePos.x;
            homePoses[2].y = enemy->homePos.y;
            homePoses[2].z = enemy->homePos.z;
            break;
        case 4:
            enemy = N(UnkEnemyFunc(3));
            homePoses[0].x = enemy->homePos.x;
            homePoses[0].y = enemy->homePos.y;
            homePoses[0].z = enemy->homePos.z;
            enemy = N(UnkEnemyFunc(4));
            homePoses[1].x = enemy->homePos.x;
            homePoses[1].y = enemy->homePos.y;
            homePoses[1].z = enemy->homePos.z;
            enemy = N(UnkEnemyFunc(5));
            homePoses[2].x = enemy->homePos.x;
            homePoses[2].y = enemy->homePos.y;
            homePoses[2].z = enemy->homePos.z;
            enemy = N(UnkEnemyFunc(6));
            homePoses[3].x = enemy->homePos.x;
            homePoses[3].y = enemy->homePos.y;
            homePoses[3].z = enemy->homePos.z;
            break;
    }

    for (i = 0; i < temp_s1 - 1; i++) {
        for (j = i; j < temp_s1; j++) {
            iVec = &homePoses[i];
            jVec = &homePoses[j];
            if (iVec->x < jVec->x) {
                temp = *iVec;
                *iVec = *jVec;
                *jVec = temp;
            }
        }
    }

    temp_v1 = get_actor(script->owner1.enemyID)->state.varTable[1];
    switch (temp_s1) {
        case 2:
            switch (temp_v1) {
                case 3:
                    evt_set_variable(script, *args++, homePoses[0].x);
                    evt_set_variable(script, *args++, homePoses[0].y);
                    evt_set_variable(script, *args++, homePoses[0].z);
                    break;
                case 6:
                    evt_set_variable(script, *args++, homePoses[1].x);
                    evt_set_variable(script, *args++, homePoses[1].y);
                    evt_set_variable(script, *args++, homePoses[1].z);
                    break;
            }
            break;
        case 3:
            switch (temp_v1) {
                case 3:
                    evt_set_variable(script, *args++, homePoses[0].x);
                    evt_set_variable(script, *args++, homePoses[0].y);
                    evt_set_variable(script, *args++, homePoses[0].z);
                    break;
                case 5:
                    evt_set_variable(script, *args++, homePoses[1].x);
                    evt_set_variable(script, *args++, homePoses[1].y);
                    evt_set_variable(script, *args++, homePoses[1].z);
                    break;
                case 6:
                    evt_set_variable(script, *args++, homePoses[2].x);
                    evt_set_variable(script, *args++, homePoses[2].y);
                    evt_set_variable(script, *args++, homePoses[2].z);
                    break;
            }
            break;
        case 4:
            switch (temp_v1) {
                case 3:
                    evt_set_variable(script, *args++, homePoses[0].x);
                    evt_set_variable(script, *args++, homePoses[0].y);
                    evt_set_variable(script, *args++, homePoses[0].z);
                    break;
                case 4:
                    evt_set_variable(script, *args++, homePoses[1].x);
                    evt_set_variable(script, *args++, homePoses[1].y);
                    evt_set_variable(script, *args++, homePoses[1].z);
                    break;
                case 5:
                    evt_set_variable(script, *args++, homePoses[2].x);
                    evt_set_variable(script, *args++, homePoses[2].y);
                    evt_set_variable(script, *args++, homePoses[2].z);
                    break;
                case 6:
                    evt_set_variable(script, *args++, homePoses[3].x);
                    evt_set_variable(script, *args++, homePoses[3].y);
                    evt_set_variable(script, *args++, homePoses[3].z);
                    break;
            }
            break;
    }
    return ApiStatus_DONE2;
}
