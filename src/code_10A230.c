#include "common.h"
#include "map.h"

typedef struct struct802E89B0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
} struct802E89B0;

void func_802E89B0(Entity* entity) {
    struct802E89B0* temp_s0;

    temp_s0 = entity->dataBuf;
    if (get_global_flag(temp_s0->unk_14)) {
        temp_s0->unk_04 = 0x10;
        exec_entity_updatecmd(entity);
    }
}

void func_802E89F8(Entity* entity) {
    struct802E89B0* temp = entity->dataBuf;

    temp->unk_04--;
    if ((temp->unk_04 != -1) && (temp->unk_08 == 0)) {
        entity->position.y += 2.3125;
    } else {
        temp->unk_04 = 0;
        exec_entity_updatecmd(entity);
    }
}

void func_802E8A58(Entity* entity) {
    struct802E89B0* temp = entity->dataBuf;

    if (temp->unk_0C == gGameStatusPtr->entryID) {
        switch (temp->unk_04) {
            case 0:
                if (gCollisionStatus.currentFloor > 0) {
                    temp->unk_04 = 1;
                }
                break;
            case 1:
                if (gCollisionStatus.currentFloor < 0) {
                    temp->unk_04 = 2;
                }
                break;
            default:
                exec_entity_updatecmd(entity);
                break;
        }
    } else {
        exec_entity_updatecmd(entity);
    }
}

#ifdef NON_MATCHING
// small regalloc issue
void func_802E8ADC(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->unk_06 & 1) != 0) {
        OVERRIDE_FLAG_SET(0x40);

        if (!(playerStatus->flags & 0x3000)) {
            s32 stickAxis0 = playerStatus->stickAxis[0];
            s32 stickAxis1 = playerStatus->stickAxis[1];

            stickAxis0 = abs(stickAxis0);

            if ((stickAxis0 != 0) || (stickAxis1 != 0)) {
                if (atan2(0.0f, 0.0f, stickAxis0, stickAxis1) < 60.0f) {
                    exec_entity_updatecmd(entity);
                }
            }
        }
    } else {
        OVERRIDE_FLAG_UNSET(0x40);
    }
}
#else
INCLUDE_ASM(s32, "code_10A230", func_802E8ADC);
#endif

void func_802E8BC0(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = &gPlayerStatus;
    struct802E89B0* temp = entity->dataBuf;
    MapConfig* mapConfig = get_current_map_header();
    f32 temp_f20;
    f32 entryX;
    f32 entryZ;

    entryX = GET_MAP_ENTRY(mapConfig, temp->unk_0C)->x;
    entryZ = GET_MAP_ENTRY(mapConfig, temp->unk_0C)->z;
    temp->unk_04 = func_800E0088(entryX, entryZ) / playerStatus->runSpeed;
    if (temp->unk_04 == 0) {
        temp->unk_04 = 1;
    }

    entryX = GET_MAP_ENTRY(mapConfig, temp->unk_0C)->x;
    entryZ = GET_MAP_ENTRY(mapConfig, temp->unk_0C)->z;
    temp_f20 = atan2(playerStatus2->position.x, playerStatus2->position.z, entryX, entryZ);
    disable_player_input();
    disable_player_static_collisions();
    move_player(temp->unk_04, temp_f20, playerStatus2->runSpeed);
}

void func_802E8C94(Entity* entity) {
    Trigger* trigger = (Trigger*)entity->dataBuf; // TODO: is Trigger correct?

    if (--trigger->params1 == -1) {
        exec_entity_updatecmd(entity);
    }
}

void player_enter_blue_pipe(Entity* bluePipe) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Trigger* pipeTrigger = (Trigger*)bluePipe->dataBuf; // TODO: is Trigger correct?

    playerStatus->targetYaw = CURRENT_CAM->currentYaw + 180.0f;
    pipeTrigger->params1 = 0x19;
    playerStatus->renderMode = 0xD;

    func_802DDFF8(0x10002, 5, 2, 1, 1, 0, 0);
    play_sound(0x163);
    disable_player_shadow();
}

void func_802E8D74(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Trigger* entityTrigger = (Trigger*)entity->dataBuf; // TODO: is Trigger correct?

    playerStatus->position.y--;
    entityTrigger->params1--;

    if (entityTrigger->params1 == -1) {
        playerStatus->renderMode = 0xD;
        playerStatus->position.y -= 50.0f;
        func_802DDFF8(0x10002, 0, 0, 0, 0, 0, 0);
        exec_entity_updatecmd(entity);
    }
}

void func_802E8E10(Entity* entity) {
    Bytecode* triggerScriptStart = ((Trigger*)entity->dataBuf)->scriptStart;

    OVERRIDE_FLAG_UNSET(0x40);
    entity->boundScript = triggerScriptStart;
    func_80110678(entity);
}

INCLUDE_ASM(s32, "code_10A230", push_entity_matrix);

f32 func_802E8F94(Entity* entity) {
    struct802E89B0* temp_s0;
    s32* temp = &D_8015C7D0;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    f32* temp5;

    temp2 = temp[0];
    temp3 = temp[1];
    temp4 = temp[2];
    entity->unk_3C = &push_entity_matrix;
    temp_s0 = entity->dataBuf;
    temp5 = &entity->position.y; // required... wtf
    temp_s0->unk_0C = temp2;
    temp_s0->unk_10 = temp3;
    temp_s0->unk_14 = temp4;
    temp_s0->unk_18 = entity->position.y;
    temp_s0->unk_08 = get_global_flag(temp_s0->unk_14);
    *temp5 = entity->position.y - (temp_s0->unk_08 ? 15.0 : 52.0);
}
