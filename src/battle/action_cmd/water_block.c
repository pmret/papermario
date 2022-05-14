#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_water_block

#include "battle/action_cmd/water_block_1.png.inc.c"
#include "battle/action_cmd/water_block_1.pal.inc.c"

#include "battle/action_cmd/water_block_2.png.inc.c"
#include "battle/action_cmd/water_block_2.pal.inc.c"

#include "battle/action_cmd/water_block_3.png.inc.c"
#include "battle/action_cmd/water_block_3.pal.inc.c"

#include "battle/action_cmd/water_block_0.png.inc.c"
#include "battle/action_cmd/water_block_0.pal.inc.c"

#include "battle/action_cmd/water_block_block.png.inc.c"
#include "battle/action_cmd/water_block_block.pal.inc.c"

#include "battle/action_cmd/water_block_circle.png.inc.c"
#include "battle/action_cmd/water_block_circle.pal.inc.c"

#include "battle/action_cmd/water_block_cloud.png.inc.c"
#include "battle/action_cmd/water_block_cloud.pal.inc.c"

#include "battle/action_cmd/water_block_4.png.inc.c"
#include "battle/action_cmd/water_block_4.pal.inc.c"

HudScript HudScript_WaterBlock1[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_1_png, (s32)battle_action_cmd_water_block_1_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock2[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_2_png, (s32)battle_action_cmd_water_block_2_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock3[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_3_png, (s32)battle_action_cmd_water_block_3_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock0[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_0_png, (s32)battle_action_cmd_water_block_0_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlock4[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_4_png, (s32)battle_action_cmd_water_block_4_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlockBlock[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_32x32,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_block_png, (s32)battle_action_cmd_water_block_block_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlockCircle[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_circle_png, (s32)battle_action_cmd_water_block_circle_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript HudScript_WaterBlockCloud[] = {
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetTileSize, HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetCI, 60, (s32)battle_action_cmd_water_block_cloud_png, (s32)battle_action_cmd_water_block_cloud_pal,
    0x00000003,
    HUD_ELEMENT_OP_End
};

HudScript* D_802AB180_42C670[] = {
    HudScript_WaterBlock0
};

HudScript* D_802AB184_42C674[] = {
    HudScript_WaterBlock1, HudScript_WaterBlock2, HudScript_WaterBlock3, HudScript_WaterBlock4, HudScript_WaterBlock4, HudScript_WaterBlock4, HudScript_WaterBlock4, HudScript_WaterBlock4, HudScript_WaterBlock4, 0, 0
};

extern s32 D_80294460;

extern HudScript HudScript_AButton[];
extern HudScript HudScript_TimingBar3Chances[];
extern HudScript HudScript_TimingCharge4b[];
extern HudScript HudScript_TimingCharge4c[];
extern HudScript HudScript_TimingOK[];
extern HudScript HudScript_TimingWait[];

ApiStatus func_802A9000_42A4F0(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294460;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_WATER_BLOCK;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_64 = evt_get_variable(script, *args++);
    battleStatus->unk_84 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    id = hud_element_create(HudScript_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(HudScript_TimingBar3Chances);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(HudScript_TimingWait);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(HudScript_TimingWait);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(HudScript_TimingWait);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(HudScript_TimingOK);
    actionCommandStatus->hudElements[6] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(HudScript_TimingOK);
    actionCommandStatus->hudElements[7] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    id = hud_element_create(HudScript_TimingOK);
    actionCommandStatus->hudElements[8] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    actionCommandStatus->hudElements[10] = hud_element_create(D_802AB184_42C674[0]);
    hud_element_set_render_pos(actionCommandStatus->hudElements[10],
                               actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);

    actionCommandStatus->hudElements[11] = hud_element_create(HudScript_TimingCharge4c);
    hud_element_set_render_pos(actionCommandStatus->hudElements[11],
                               actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);

    id = hud_element_create(HudScript_TimingCharge4b);
    actionCommandStatus->hudElements[12] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);

    switch (actionCommandStatus->unk_64) {
        case 0:
            actionCommandStatus->hudElements[13] = hud_element_create(HudScript_WaterBlockBlock);
            id = actionCommandStatus->hudElements[13];
            break;
        case 1:
            actionCommandStatus->hudElements[13] = hud_element_create(HudScript_WaterBlockCircle);
            id = actionCommandStatus->hudElements[13];
            break;
        case 2:
            actionCommandStatus->hudElements[13] = hud_element_create(HudScript_WaterBlockCloud);
            id = actionCommandStatus->hudElements[13];
            break;
    }

    hud_element_set_render_pos(id, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    return ApiStatus_DONE2;
}

ApiStatus func_802A9398_42A888(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->unk_84 = 1;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    func_80269118();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/water_block", func_802A948C_42A97C);

void func_802AA014_42B504(void) {
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[1]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[6]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[7]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[8]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[13]);

    hudElement = actionCommandStatus->hudElements[10];
    if (hud_element_get_script(hudElement) != D_802AB180_42C670[battleStatus->unk_84]) {
        hud_element_set_script(hudElement, D_802AB180_42C670[battleStatus->unk_84]);
    }

    hud_element_draw_clipped(hudElement);
    hud_element_draw_clipped(actionCommandStatus->hudElements[11]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[12]);
}

void func_802AA0D8_42B5C8(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
    hud_element_free(gActionCommandStatus.hudElements[6]);
    hud_element_free(gActionCommandStatus.hudElements[7]);
    hud_element_free(gActionCommandStatus.hudElements[8]);
    hud_element_free(gActionCommandStatus.hudElements[10]);
    hud_element_free(gActionCommandStatus.hudElements[11]);
    hud_element_free(gActionCommandStatus.hudElements[12]);
    hud_element_free(gActionCommandStatus.hudElements[13]);
}
