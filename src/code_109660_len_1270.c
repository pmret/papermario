#include "common.h"

INCLUDE_ASM("code_109660_len_1270", func_802E7DE0);

INCLUDE_ASM("code_109660_len_1270", func_802E7F40);

INCLUDE_ASM("code_109660_len_1270", func_802E7F6C);

INCLUDE_ASM("code_109660_len_1270", func_802E7FA0);

INCLUDE_ASM("code_109660_len_1270", func_802E854C);

INCLUDE_ASM("code_109660_len_1270", func_802E8858);

INCLUDE_ASM("code_109660_len_1270", func_802E88EC);

INCLUDE_ASM("code_109660_len_1270", func_802E89B0);

INCLUDE_ASM("code_109660_len_1270", func_802E89F8);

INCLUDE_ASM("code_109660_len_1270", func_802E8A58);

INCLUDE_ASM("code_109660_len_1270", func_802E8ADC);

INCLUDE_ASM("code_109660_len_1270", func_802E8BC0);

INCLUDE_ASM("code_109660_len_1270", func_802E8C94);

void player_enter_blue_pipe(Entity* bluePipe) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Trigger* pipeTrigger = bluePipe->trigger;

    playerStatus->targetYaw = gCameras[gCurrentCameraID].currentYaw + 180.0f;
    pipeTrigger->params1 = 0x19;
    playerStatus->renderMode = 0xD;

    func_802DDFF8(0x10002, 5, 2, 1, 1, 0, 0);
    play_sound(0x163);
    disable_player_shadow();
}

void func_802E8D74(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Trigger* entityTrigger = entity->trigger;

    playerStatus->position.y--;
    entityTrigger->params1--;

    if (entityTrigger->params1 == -1) {
        playerStatus->renderMode = 0xD;
        playerStatus->position.y -= 50.0f;
        func_802DDFF8(0x10002, 0, 0, 0, 0, 0, 0);
        func_8010FD68(entity);
    }
}

void func_802E8E10(Entity* entity) {
    Bytecode* triggerScriptStart = entity->trigger->scriptStart;

    D_8009A650[0] &= ~0x40;
    entity->boundScript = triggerScriptStart;
    func_80110678();
}

INCLUDE_ASM("code_109660_len_1270", push_entity_matrix);

INCLUDE_ASM("code_109660_len_1270", func_802E8F94);

INCLUDE_ASM("code_109660_len_1270", func_802E9050);
