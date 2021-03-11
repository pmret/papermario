#include "common.h"
#include "map.h"

MapConfig* get_current_map_header(void);
void disable_player_input(void);
void disable_player_static_collisions(void);
void move_player(s32, f32, f32);
s32 func_802E854C();

typedef struct struct802E7DE0 {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ u8* unk_008;
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ u8 unk_010[36];
    /* 0x034 */ s8 unk_034[36];
    /* 0x058 */ u8 unk_058[36];
    /* 0x07C */ u8 unk_07C[36];
    /* 0x0A0 */ u8 unk_0A0[36];
    /* 0x0C4 */ f32 unk_0C4[36];
    /* 0x154 */ f32 unk_154[36];
    /* 0x1E4 */ f32 unk_1E4[36];
    /* 0x274 */ f32 unk_274[36];
    /* 0x304 */ f32 unk_304[36];
} struct802E7DE0;

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7DE0);

typedef struct struct802E7F40 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[6];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[4];
    /* 0x14 */ s32 unk_14;
} struct802E7F40;

void func_802E7F40(Entity* entity) {
    struct802E7F40* temp = entity->dataBuf;

    entity->scale.y = 0.85714287f;
    temp->unk_00 = D_8015C7D0[0];
    temp->unk_04 = 0xFFFF;
}

void func_802E7F6C(Entity* entity) {
    struct802E7F40* temp = entity->dataBuf;

    temp->unk_0C = entity->position.y;
    func_802E7DE0(entity, &D_0A004350, &D_0A0026F0);
}

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7FA0);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E854C);

s32 func_802E8858(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 phi_a0 = FALSE;

    if (entity->unk_06 & 1) {
        if ((playerStatus->actionState == ActionState_GROUND_POUND) || (playerStatus->actionState == ActionState_ULTRA_POUND)) {
            set_action_state(ActionState_FALLING);
            phi_a0 = TRUE;
        }
    }

    if (phi_a0) {
        func_802E7F6C(entity);
        func_80110BCC(entity, &D_802EAE7C);
        func_80110678(entity);
        exec_entity_updatecmd(entity);
        play_sound(0x20AE);
    }
}

f32 func_800E546C(void);

void func_802E88EC(Entity* entity, f32 arg1) {
    struct802E7F40* temp = entity->dataBuf;

    if (temp->unk_00 != -1) {
        s32 flag = FALSE;

        // can't do || here, or gcc realizes it can reuse the temp->unk_04 load
        if (temp->unk_04 == 0xFFFF) {
            flag = TRUE;
        } else if (!get_global_flag(temp->unk_04)) {
            flag = TRUE;
        }

        if (flag) {
            make_item_entity(temp->unk_00, entity->position.x, entity->position.y + 33.0, entity->position.z, 0xA, 0,
                             func_800E546C(), temp->unk_04);
        }
    }
}

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

extern f64 D_802EB380;

void func_802E89F8(Entity* entity) {
    s32 temp_v0;
    struct802E89B0* temp;

    temp = entity->dataBuf;
    temp->unk_04--;
    if ((temp->unk_04 != -1) && (temp->unk_08 == 0)) {
        entity->position.y += D_802EB380;
        return;
    }
    temp->unk_04 = 0;
    exec_entity_updatecmd(entity);
}

void func_802E8A58(Entity* entity) {
    struct802E89B0* temp = entity->dataBuf;

    if (temp->unk_0C == (*gGameStatusPtr)->entryID) {
        switch (temp->unk_04) {
            case 0:
                if (gCollisionStatus.currentFloor > 0) {
                    temp->unk_04 = 1;
                }
                return;
            case 1:
                if (gCollisionStatus.currentFloor < 0) {
                    temp->unk_04 = 2;
                }
                return;
            default:
                exec_entity_updatecmd(entity);
                return;
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
        *D_8009A650 |= 0x40;
        if ((playerStatus->flags & 0x3000) == 0) {
            s32 phi_v0 = playerStatus->stickAxis[0];
            s32 temp_a0 = playerStatus->stickAxis[1];

            if (phi_v0 < 0) {
                phi_v0 = -phi_v0;
            }

            if ((phi_v0 != 0) || (temp_a0 != 0)) {
                if (atan2(0.0f, 0.0f, phi_v0, temp_a0) < 60.0f) {
                    exec_entity_updatecmd(entity);
                    return;
                }
            }
        }
    } else {
        *D_8009A650 &= ~0x40;
    }
}
#else
INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8ADC);
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

    D_8009A650[0] &= ~0x40;
    entity->boundScript = triggerScriptStart;
    func_80110678(entity);
}

INCLUDE_ASM(s32, "code_109660_len_1270", push_entity_matrix);

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
