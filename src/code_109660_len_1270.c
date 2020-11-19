#include "common.h"
#include "map.h"

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7DE0);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7F40);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7F6C);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E7FA0);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E854C);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8858);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E88EC);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E89B0);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E89F8);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8A58);

INCLUDE_ASM(s32, "code_109660_len_1270", func_802E8ADC);

// TODO: what is this struct?
typedef struct struct802E8BC0 {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ s32 unk_0C; 
} struct802E8BC0;

MapConfig* get_current_map_header(void);
void disable_player_input(void);
void disable_player_static_collisions(void);
void move_player(s32, f32, f32);

void func_802E8BC0(Entity *entity) {
    PlayerStatus *playerStatus = &gPlayerStatus;
    PlayerStatus *playerStatus2 = &gPlayerStatus;
    struct802E8BC0* temp = (struct802E8BC0*)entity->dataBuf;
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

    if (--trigger->params1.w == -1) {
        func_8010FD68();
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
