#include "kkj_19.h"

typedef struct IngredientSouce {
    /* 0x00 */ s32 itemID;
    /* 0x04 */ s32 colliderID;
    /* 0x08 */ s32 overrideDescMsg;
} IngredientSouce; // size = 0x0C

IngredientSouce N(IngredientSources)[] = {
    { ITEM_BAKING_SUGAR,        COLLIDER_o101, MSG_NONE },
    { ITEM_BAKING_SALT,         COLLIDER_o102, MSG_NONE },
    { ITEM_BAKING_EGG,          COLLIDER_o103, MSG_NONE },
    { ITEM_BAKING_STRAWBERRY,   COLLIDER_o105, MSG_NONE },
    { ITEM_BAKING_CREAM,        COLLIDER_o106, MSG_NONE },
    { ITEM_BAKING_BUTTER,       COLLIDER_o107, MSG_NONE },
    { ITEM_BAKING_CLEANSER,     COLLIDER_o108, MSG_NONE },
    { ITEM_BAKING_WATER,        COLLIDER_o114, MSG_NONE },
    { ITEM_BAKING_FLOUR,        COLLIDER_o109, MSG_NONE },
    { ITEM_BAKING_MILK,         COLLIDER_o110, MSG_NONE },
};

s32 N(IngredientWindowsOpen) = FALSE;
s32 N(IngredientWindowsDismissTime) = 0;
s32 N(IngredientWindowsIndex) = 0;

API_CALLABLE(N(TryOpenIngredientWindows)) {
    Bytecode* args = script->ptrReadPos;
    s32 canCheck;

    N(IngredientWindowsIndex) = evt_get_variable(script, *args++);
    canCheck = evt_get_variable(NULL, AF_KKJ19_CanTakeIngredients);

    if (canCheck == TRUE) {
        N(IngredientWindowsOpen) = TRUE;
        N(IngredientWindowsDismissTime) = 5;
    } else {
        N(IngredientWindowsOpen) = FALSE;
    }

    return ApiStatus_DONE2;
}

void N(worker_update_ingredient_windows)(void) {
    if (N(IngredientWindowsOpen)) {
        set_window_update(WINDOW_ID_ITEM_INFO_NAME, (s32)basic_window_update);
        set_window_update(WINDOW_ID_ITEM_INFO_DESC, (s32)basic_window_update);
    } else {
        set_window_update(WINDOW_ID_ITEM_INFO_NAME, (s32)basic_hidden_window_update);
        set_window_update(WINDOW_ID_ITEM_INFO_DESC, (s32)basic_hidden_window_update);
    }

    if (N(IngredientWindowsDismissTime) > 0) {
        N(IngredientWindowsDismissTime)--;
    } else {
        N(IngredientWindowsOpen) = FALSE;
    }
}

void N(draw_content_ingredient_name)(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    IngredientSouce* ingredient = &N(IngredientSources)[N(IngredientWindowsIndex)];
    ItemData* item = &gItemTable[ingredient->itemID];
    s32 halfWidth = get_msg_width(item->nameMsg, 0) >> 1;

    draw_msg(item->nameMsg, baseX + 60 - halfWidth, baseY + 6, 255, 0, 0);
}

void N(draw_content_ingredient_desc)(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    IngredientSouce* ingredient = &N(IngredientSources)[N(IngredientWindowsIndex)];
    ItemData* item = &gItemTable[ingredient->itemID];

    if (ingredient->overrideDescMsg != MSG_NONE) {
        draw_msg(ingredient->overrideDescMsg, baseX + 8, baseY, 255, 10, 0);
    } else {
        draw_msg(item->shortDescMsg, baseX + 8, baseY, 255, 10, 0);
    }
}

EvtScript N(EVS_TouchFloor_IngredientStation) = {
    Call(N(TryOpenIngredientWindows), LVar0)
    Return
    End
};

WindowStyleCustom N(IngredientNameWS) = {
    .background = {},
    .corners = {
        .imgData = ui_box_corners5_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_30, PM_CC_BOX2_CYC2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_31, PM_CC_BOX2_CYC2),
    .color1 = { 255, 183, 181, 255 },
    .color2 = { 122,  89,  63, 255 },
};

MenuWindowBP N(IngredientWindows)[] = {
    {
        .windowID = WINDOW_ID_ITEM_INFO_NAME,
        .pos = { 100, 66 },
        .width = 120,
        .height = 28,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &N(draw_content_ingredient_name),
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &N(IngredientNameWS) },
    },
    {
        .windowID = WINDOW_ID_ITEM_INFO_DESC,
        .pos = { 32, 184 },
        .width = 256,
        .height = 32,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &N(draw_content_ingredient_desc),
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { -1 },
    }
};

API_CALLABLE(N(CreateIngredientInfoWindows)) {
    s32 i;

    N(IngredientWindowsOpen) = FALSE;
    N(IngredientWindowsDismissTime) = 0;
    N(IngredientWindowsIndex) = 0;

    get_worker(create_worker_frontUI(N(worker_update_ingredient_windows), NULL));
    setup_pause_menu_tab(N(IngredientWindows), ARRAY_COUNT(N(IngredientWindows)));

    for (i = 0; i < ARRAY_COUNT(N(IngredientSources)); i++) {
        bind_trigger_1(&N(EVS_TouchFloor_IngredientStation), TRIGGER_FLOOR_TOUCH, N(IngredientSources)[i].colliderID, i, 0, 3);
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoor_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kkj_19_ENTRY_0)
    Set(LVar1, COLLIDER_ttse)
    Set(LVar2, MODEL_o95)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(GotoMap, Ref("kkj_00"), kkj_00_ENTRY_3)
    Else
        Call(GotoMap, Ref("kkj_10"), kkj_10_ENTRY_3)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Exec(N(EVS_ManageBaking))
    Else
        Set(LVar0, kkj_19_ENTRY_0)
        Set(LVar2, MODEL_o95)
        Set(LVar3, DOOR_SWING_IN)
        ExecWait(EnterSingleDoor)
        Exec(N(EVS_BindExitTriggers))
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(MakeNpcs, FALSE, Ref(N(IntroNPCs)))
        CaseEq(STORY_CH4_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(PeachNPCs)))
    EndSwitch
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Exec(N(EVS_EnterMap))
    Wait(1)
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Call(N(CreateIngredientInfoWindows))
    EndIf
    Return
    End
};
