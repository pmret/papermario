#include "common.h"

void create_shadow_callback(Shadow* shadow) {
    shadow->scale.x = 0.1f;
    shadow->scale.y = 0.1f;
    shadow->scale.z = 0.1f;
}

//TODO: make sure this is the right struct for this.
s32 func_802E0DB0(Shadow* shadow) {

    if (((shadow->unk_06 & 4) != 0) && (gPlayerStatus.flags & 2) != 0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM(s32, "code_102610_len_2330", func_802E0DE0);

typedef struct struct802E10F4 {
    char unk_0[4];
    s16 angle;
} struct802E10F4;

void func_802E10F4(Entity* entity) {
    struct802E10F4* temp;

    temp = (struct802E10F4*)entity->dataBuf;
    temp->angle = clamp_angle(temp->angle + 6);
    func_802E3650(entity);
}

void func_802E114C(void) {

    func_80027088(1);
    disable_player_input();
    gPlayerStatusPtr->currentSpeed = 0.0f;
}

void func_802E117C(void) {
    func_80027088(0);
    enable_player_input();
}

void save_game_at_player_position(void) {
    GameStatus* gameStatus = GAME_STATUS;

    gameStatus->savedPos.x = gPlayerStatusPtr->position.x;
    gameStatus->savedPos.y = gPlayerStatusPtr->position.y;
    gameStatus->savedPos.z = gPlayerStatusPtr->position.z;
    fio_save_game(gameStatus->saveSlot);
}

void func_802E1204(Entity* entity) {

    if (get_global_flag(0xF8405BDF) == 0) {
        s32* temp = &D_802EB390;
        *temp = 0;
        load_string(0x1D0000, temp);
        set_global_flag(0xF8405BDF);
        return;
    }

    func_8010FD68(entity);
    func_8010FD68(entity);
}

void func_802E1270(Entity* entity) {
    s32* temp = &D_802EB390;

    if (*temp != 0) {
        func_8010FD68(entity);
    }
}

void func_802E1298(void) {
    s32* temp1 = &D_802EB390;
    s32* temp2 = &D_802EB394;
    *temp1 = 0;
    *temp2 = 0;
    D_802EB39C = load_string(0x1D0004, temp2);
    D_802EB398 = load_string(0x1E000A, temp1);
}

void func_802E12F8(void) {
    load_message_to_printer(0x1D0005, D_802EB39C);
    play_sound(0x10);
}

void func_802E1328(Entity* entity) {
    s32* temp = &D_802EB394;

    if (*temp != 0) {
        func_8010FD68(entity);
    }
}

void func_802E1350(Entity* entity) {
    s32* temp = &D_802EB390;
    if (*temp != 0) {
        if (D_802EB398->unk_4E8 == 1) {
            func_8010FBC0(entity, &D_802E99DC);
        } else {
            func_8010FD68(entity);
        }
        close_message(D_802EB39C);
    }
}

void func_802E13B8(Entity* entity) {
    struct802E3650* temp = entity->dataBuf;

    entity_init_Hammer23Block_normal(entity);
    entity->unk_3C = func_802E0DE0;
    temp->unk_04 = 8;
}
