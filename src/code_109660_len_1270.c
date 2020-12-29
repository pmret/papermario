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
    struct802E7F40* temp_v1;

    temp_v1 = entity->dataBuf;
    entity->scale.y = 0.85714287f;
    temp_v1->unk_04 = 0xFFFF;
    temp_v1->unk_00 = D_8015C7D0;
}

extern UNK_TYPE D_0A004350;
extern UNK_TYPE D_0A0026F0;

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7F6C);
/*void func_802E7F6C(Entity* entity) {
    struct802E7F40* temp = entity->dataBuf;

    temp->unk_0C = entity->position.y;
    func_802E7DE0(entity, &D_0A004350, &D_0A0026F0);
}*/

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7FA0);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E854C);

extern UNK_TYPE D_802EAE7C;
extern f64 D_802EB370;

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8858);
/*s32 func_802E8858(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 phi_a0 = 0;

    if (entity->unk_06 & 1) {
        if ((playerStatus->actionState == ActionState_GROUND_POUND) || (playerStatus->actionState == ActionState_ULTRA_POUND)) {
            set_action_state(ActionState_FALLING);
            phi_a0 = 1;
        }
    }

    if (phi_a0 != 0) {
        func_802E7F6C(entity);
        func_80110BCC(entity, &D_802EAE7C);
        func_80110678(entity);
        func_8010FD68(entity);
        play_sound(0x20AE);
    }
}*/

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E88EC);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E89B0);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E89F8);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8A58);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8ADC);

void func_802E8BC0(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = &gPlayerStatus;
    struct802E7DE0* temp = (struct802E7DE0*)entity->dataBuf;
    MapConfig* mapConfig = get_current_map_header();
    f32 temp_f20;
    f32 entryX;
    f32 entryZ;

    entryX = GET_MAP_ENTRY(mapConfig, temp->unk_00C)->x;
    entryZ = GET_MAP_ENTRY(mapConfig, temp->unk_00C)->z;
    temp->unk_004 = func_800E0088(entryX, entryZ) / playerStatus->runSpeed;
    if (temp->unk_004 == 0) {
        temp->unk_004 = 1;
    }

    entryX = GET_MAP_ENTRY(mapConfig, temp->unk_00C)->x;
    entryZ = GET_MAP_ENTRY(mapConfig, temp->unk_00C)->z;
    temp_f20 = atan2(playerStatus2->position.x, playerStatus2->position.z, entryX, entryZ);
    disable_player_input();
    disable_player_static_collisions();
    move_player(temp->unk_004, temp_f20, playerStatus2->runSpeed);
}

void func_802E8C94(Entity* entity) {
    Trigger* trigger = (Trigger*)entity->dataBuf; // TODO: is Trigger correct?

    if (--trigger->params1.w == -1) {
        func_8010FD68(entity);
    }
}

void player_enter_blue_pipe(Entity* bluePipe) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Trigger* pipeTrigger = (Trigger*)bluePipe->dataBuf; // TODO: is Trigger correct?

    playerStatus->targetYaw = CURRENT_CAM->currentYaw + 180.0f;
    pipeTrigger->params1.w = 0x19;
    playerStatus->renderMode = 0xD;

    func_802DDFF8(0x10002, 5, 2, 1, 1, 0, 0);
    play_sound(0x163);
    disable_player_shadow();
}

void func_802E8D74(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Trigger* entityTrigger = (Trigger*)entity->dataBuf; // TODO: is Trigger correct?

    playerStatus->position.y--;
    entityTrigger->params1.w--;

    if (entityTrigger->params1.w == -1) {
        playerStatus->renderMode = 0xD;
        playerStatus->position.y -= 50.0f;
        func_802DDFF8(0x10002, 0, 0, 0, 0, 0, 0);
        func_8010FD68(entity);
    }
}

void func_802E8E10(Entity* entity) {
    Bytecode* triggerScriptStart = ((Trigger*)entity->dataBuf)->scriptStart;

    D_8009A650[0] &= ~0x40;
    entity->boundScript = triggerScriptStart;
    func_80110678(entity);
}

INCLUDE_ASM(s32, "code_109660_len_1270", push_entity_matrix);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8F94);
