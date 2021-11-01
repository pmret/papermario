#include "common.h"

#define NAMESPACE b_area_kkj

extern s32 D_802187E4_6DC584;

ApiStatus func_80218000_6DBDA0(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);

    D_802187E4_6DC584 += 9;
    D_802187E4_6DC584 = clamp_angle(D_802187E4_6DC584);
    actor->unk_19A = sin_rad((D_802187E4_6DC584 * TAU) / 360.0f) * 3.0f;

    return ApiStatus_DONE2;
}

#include "world/common/SetEntityPositionF.inc.c"

#include "world/common/GetEntityPosition.inc.c"

ApiStatus func_80218220_6DBFC0(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[9]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rotation.y = (1.0f - cos_rad(entity->scale.y * PI)) * 1080.0f * 0.5f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8021833C_6DC0DC(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
        set_screen_overlay_center(1, 0, 0, 0);
        set_screen_overlay_center(1, 1, 320, 240);
        set_screen_overlay_params_back(12, 150);
    }
    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    set_screen_overlay_center(1, 0, 0, 0);
    set_screen_overlay_center(1, 1, 320, 240);
    set_screen_overlay_params_back(0xFF, -1);
    return ApiStatus_DONE2;
}

ApiStatus func_802183EC_6DC18C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 30;
        set_screen_overlay_center(1, 0, 0, 0);
        set_screen_overlay_center(1, 1, 320, 240);
        set_screen_overlay_params_back(12, 150);
    }
    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    set_screen_overlay_center(1, 0, 0, 0);
    set_screen_overlay_center(1, 1, 320, 240);
    set_screen_overlay_params_back(0xFF, -1);
    return ApiStatus_DONE2;
}

ApiStatus func_8021849C_6DC23C(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 entityIndex = script->varTable[9];
    Entity* entity = get_entity_by_index(entityIndex);

    entity->unk_07 = 0;
    collisionStatus->lastWallHammered = entityIndex | 0x4000;
    playerStatus->flags |= 0x1000000;
    entity->collisionFlags = 0x40;
    playerStatus->actionState = ACTION_STATE_HAMMER;
    entity->staticData->unk_data_ptr2(entity);
    entity->unk_07 = 0xA;
    entity->flags |= ENTITY_FLAGS_DETECTED_COLLISION;
    collisionStatus->lastWallHammered = -1;

    return ApiStatus_DONE2;
}
