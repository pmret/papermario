#include "common.h"
#include "nu/nusys.h"

enum SimpleWindowUpdateFlags {
    SIMPLE_WINDOW_UPDATE_1          = 0x1,
    SIMPLE_WINDOW_UPDATE_OPACITY    = 0x2,
    SIMPLE_WINDOW_UPDATE_DARKENING  = 0x4,
};

typedef struct SimpleWindowUpdateData {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 windowFlagsSet;
    /* 0x02 */ u8 windowFlagsUnset;
    /* 0x03 */ u8 darkening;
    /* 0x04 */ u8 opacity;
} SimpleWindowUpdateData; // size = 0x05

typedef struct WindowGroup {
    /* 0x00 */ u8 min;
    /* 0x01 */ u8 max;
} WindowGroup; // size = 0x02

SHIFT_BSS Window gWindows[64];

WindowStyle gWindowStyles[64] = {
    { WINDOW_STYLE_3 }, { WINDOW_STYLE_3 }, { WINDOW_STYLE_11 }, { WINDOW_STYLE_12 },
    { WINDOW_STYLE_13 }, { WINDOW_STYLE_14 }, { WINDOW_STYLE_3 }, { WINDOW_STYLE_21 },
    { WINDOW_STYLE_3 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_9 }, { WINDOW_STYLE_3 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_1 }, { WINDOW_STYLE_3 }, { WINDOW_STYLE_9 },
    { WINDOW_STYLE_10 }, { WINDOW_STYLE_7 }, { WINDOW_STYLE_8 }, { WINDOW_STYLE_3 },
    { WINDOW_STYLE_3 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_3 }, { WINDOW_STYLE_11 }, { WINDOW_STYLE_12 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 },
    { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_0 }, { WINDOW_STYLE_1 }
};

SimpleWindowUpdateData gSimpleWindowUpdates[] = {
    {
        .flags = 0,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = 0,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_HIDDEN | WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = 0,
        .windowFlagsSet = WINDOW_FLAG_HIDDEN,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_1,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_DARKENING,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 100,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_DARKENING,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_OPACITY,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 184
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_OPACITY,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 255
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_OPACITY,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_HIDDEN | WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 0,
        .opacity = 184
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_DARKENING,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAG_HIDDEN | WINDOW_FLAG_INITIAL_ANIMATION,
        .darkening = 100,
        .opacity = 0
    },
    {},
    {},
    {},
    {}
};

u8 gWindowAppearScales[] = { 50, 80, 100, 105, 100 };
u8 gWindowAppearFlags[] = { DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, 0};
u8 gWindowDisappearScales[] = { 105, 100, 77, 57, 40, 27, 16, 8, 3, 0 };
u8 gWindowDisappearFlags[] = { DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE,
                               DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE,
                               DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, 0 };

WindowGroup gWindowGroups[] = {
    { WINDOW_ID_0, WINDOW_ID_FILEMENU_FILE3_TITLE }, // all windows
    { WINDOW_ID_8, WINDOW_ID_BATTLE_POPUP }, // battle ?
    { WINDOW_ID_PAUSE_MAIN, WINDOW_ID_PAUSE_TAB_INVIS }, // pause menu
    { WINDOW_ID_FILEMENU_MAIN, WINDOW_ID_FILEMENU_FILE3_TITLE } // file menu
};

void clear_windows(void) {
    Window* window = gWindows;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gWindows); i++, window++) {
        window->flags = 0;
    }
}

void update_windows(void) {
    Window* window;
    s32 i;
    u8 flags;

    for (i = 0, window = gWindows; i < ARRAY_COUNT(gWindows); i++, window++) {
        flags = window->flags;

        if (!flags || (flags & WINDOW_FLAG_DISABLED)) {
            continue;
        }

        if (flags & WINDOW_FLAG_FPUPDATE_CHANGED) {
            window->flags = flags & ~WINDOW_FLAG_FPUPDATE_CHANGED;
            window->fpUpdate = window->fpPending;
            window->updateCounter = 0;
        }
    }
}

void basic_window_update(s32 windowID, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                        f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowID];
    s32 counter = window->updateCounter;

    if (counter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (counter < 5) {
        *flags = gWindowAppearFlags[counter];
        *scaleX = (f32)gWindowAppearScales[counter] * 0.01;
        *scaleY = (f32)gWindowAppearScales[counter] * 0.01;
        *rotZ = (4 - counter) * 3;
    } else {
        *flags = gWindowAppearFlags[4];
        *scaleX = 1.0f;
        *scaleY = 1.0f;
        *rotZ = 0.0f;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void basic_hidden_window_update(s32 windowID, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                        f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowID];
    s32 counter = window->updateCounter;

    if (counter < 10) {
        *flags = gWindowDisappearFlags[counter];
        *scaleX = (f32)gWindowDisappearScales[counter] * 0.01;
        *scaleY = (f32)gWindowDisappearScales[counter] * 0.01;
        *rotZ = -counter;
    } else {
        *flags = gWindowDisappearFlags[9];
        *scaleX = 0.0f;
        *scaleY = 0.0f;
        *rotZ = 0.0f;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void main_menu_window_update(s32 windowID, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                        f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowID];
    s32 counter = window->updateCounter;

    if (counter < 10) {
        *darkening = (counter + 1) * 16;
    } else {
        *darkening = 160;
        window->flags &= ~(WINDOW_FLAG_INITIAL_ANIMATION | WINDOW_FLAG_HIDDEN);
    }
}

void render_windows(s32* windowsArray, s32 parent, s32 flags, s32 baseX, s32 baseY, s32 opacity, s32 darkening, f32 (*rotScaleMtx)[4]) {
    Window* window;
    Window* childWindow;
    s32 i;
    s32 childWindowID;
    s32 counter;
    Matrix4f matrix;
    f32 (*outMtx)[4];
    s32 childFlags;
    s32 posX, posY, posZ;
    f32 scaleX, scaleY, rotX, rotY, rotZ;
    s32 childDarkening, childOpacity;
    s32 boxFlags;
    s32 boxTranslateX;
    s32 boxTranslateY;
    s32 fpUpdateIdx;
    s32 width, height;
    s32 (*fpUpdateFunc)(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                                 f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
    s32 childWindowIdCopy;
    WindowStyle windowStyle;
    void* fpDrawContents;
    void* drawContentsArg0;
    s32* windowArrayIt;

    for (i = 0, windowArrayIt = windowsArray; i < ARRAY_COUNT(gWindows); i++, windowArrayIt++) {
        window = &gWindows[parent];
        childWindowID = *windowArrayIt;

        if (childWindowID < 0) {
            continue;
        }

        childWindow = &gWindows[childWindowID];
        if (childWindow->flags == 0 || (childWindow->flags & WINDOW_FLAG_DISABLED)) {
            continue;
        }

        fpUpdateIdx = childWindow->fpUpdate.i;
        if (fpUpdateIdx == 0 || childWindow->parent != parent) {
            continue;
        }

        counter = childWindow->updateCounter;
        posX = childWindow->pos.x;
        posY = childWindow->pos.y;
        posZ = 0;
        childFlags = 0;
        rotX = rotY = rotZ = 0.0f;
        scaleY = scaleX = 1.0f;
        childDarkening = 0;
        childOpacity = 255;
        width = childWindow->width;
        height = childWindow->height;

        if (fpUpdateIdx > 0 && fpUpdateIdx < 14) {
            SimpleWindowUpdateData* updateData = &gSimpleWindowUpdates[fpUpdateIdx];
            childWindow->flags |= updateData->windowFlagsSet;
            childWindow->flags &= ~updateData->windowFlagsUnset;

            if (counter == 0 && (updateData->flags & SIMPLE_WINDOW_UPDATE_1)) {
                update_window_hierarchy(childWindowID, childWindow->originalPriority);
            }
            if (updateData->flags & SIMPLE_WINDOW_UPDATE_DARKENING) {
                childDarkening = updateData->darkening;
            }
            if (updateData->flags & SIMPLE_WINDOW_UPDATE_OPACITY) {
                childOpacity = updateData->opacity;
            }
        } else {
            //type conversion needed for matching
            fpUpdateFunc = (s32 (*)(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                                 f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity))(childWindow->fpUpdate.func);
            fpUpdateFunc(childWindowID, &childFlags, &posX, &posY, &posZ, &scaleX, &scaleY, &rotX, &rotY, &rotZ, &childDarkening, &childOpacity);
        }

        if (childWindow->fpUpdate.i) {
            if (childWindow->updateCounter < 255) {
                childWindow->updateCounter++;
            }
        }

        if (scaleX == 0 || scaleY == 0 || (childWindow->flags & WINDOW_FLAG_HIDDEN)) {
            continue;
        }

        childDarkening += darkening;
        childOpacity = childOpacity * opacity / 255;
        fpDrawContents = childWindow->fpDrawContents;
        drawContentsArg0 = childWindow->drawContentsArg0;
        windowStyle = gWindowStyles[childWindowID];
        outMtx = matrix;
        //needed to match
        childWindowIdCopy = childWindowID;

        if (childDarkening > 255) {
            childDarkening = 255;
        }
        childFlags |= flags;
        if (!(flags & DRAW_FLAG_ROTSCALE)) {
            posX += baseX;
            posY += baseY;
        }

        if (parent == -1) {
            boxTranslateX = SCREEN_WIDTH;
        } else {
            boxTranslateX = window->width;
        }

        boxTranslateY = SCREEN_HEIGHT;
        if (parent != -1) {
            boxTranslateY = window->height;
        }

        boxFlags = childFlags;
        if (childWindow->flags & WINDOW_FLAG_40) {
            boxFlags |= DRAW_FLAG_ANIMATED_BACKGROUND;
        }

        if (draw_box(boxFlags, windowStyle, posX, posY, posZ, width, height, childOpacity, childDarkening,
                    scaleX, scaleY, rotX, rotY, rotZ, fpDrawContents, drawContentsArg0, rotScaleMtx,
                    boxTranslateX, boxTranslateY, outMtx) == 0) {
            if (childFlags == 0 && rotScaleMtx == 0) {
                outMtx = NULL;
            }

            if (childWindow->flags & WINDOW_FLAG_HAS_CHILDREN) {
                render_windows(windowsArray, childWindowIdCopy, childFlags, posX, posY, childOpacity, childDarkening, outMtx);
            }
        }
    }
}

void render_window_root(void) {
    s32 priorityArray[ARRAY_COUNT(gWindows)];
    s32* ptr = priorityArray;
    s32 i;
    Window* window;

    for (i = 0; i < ARRAY_COUNT(gWindows); i++) {
        *ptr++ = -1;
    }
    for (i = 0, window = gWindows; i < ARRAY_COUNT(gWindows); window++, i++) {
        if (window->flags != 0) {
            priorityArray[window->priority] = i;
        }
    }

    gSPLoadGeometryMode(gMainGfxPos++, 0);
    gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_SHADING_SMOOTH);
    gDPPipelineMode(gMainGfxPos++, G_PM_NPRIMITIVE);
    gDPSetCombineMode(gMainGfxPos++, G_CC_SHADE, G_CC_SHADE);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 16, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE);
    gSPClipRatio(gMainGfxPos++, FRUSTRATIO_2);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
    gDPPipeSync(gMainGfxPos++);
    render_windows(priorityArray, WINDOW_ID_NONE, 0, 0, 0, 255, 0, NULL);
}

void set_window_properties(s32 windowID, s32 posX, s32 posY, s32 width, s32 height, u8 priority, void* fpDrawContents, void* drawContentsArg0, s8 parent) {
    Window* window = &gWindows[windowID];
    u8 priorityCopy = priority;

    window->flags = WINDOW_FLAG_INITIALIZED | WINDOW_FLAG_HIDDEN;
    window->pos.x = posX;
    window->pos.y = posY;
    window->width = width;
    window->fpUpdate.i = 0;
    window->parent = parent;
    window->height = height;
    window->fpDrawContents = fpDrawContents;
    window->drawContentsArg0 = drawContentsArg0;
    if (parent >= 0) {
        gWindows[parent].flags |= WINDOW_FLAG_HAS_CHILDREN;
    }
    update_window_hierarchy(windowID, priorityCopy);
    window->originalPriority = priority;
}

void update_window_hierarchy(s32 windowID, u8 priority) {
    s32 priorityArray[ARRAY_COUNT(gWindows) + 1];
    s32* ptr;
    s32 i;
    s32 currentPriority;
    Window* window;

    if (priority > ARRAY_COUNT(gWindows)) {
        priority = ARRAY_COUNT(gWindows);
    }

    ptr = priorityArray;
    for (i = 0; i < ARRAY_COUNT(priorityArray); i++, ptr++) {
        *ptr = -1;
    }
    priorityArray[priority] = windowID;

    for (i = 0, window = gWindows; i < ARRAY_COUNT(gWindows); i++, window++) {
        if (window->flags && i != windowID) {
            currentPriority = window->priority;
            if (currentPriority >= priority) {
                currentPriority++;
            }
            priorityArray[currentPriority] = i;
        }
    }

    currentPriority = 0;
    for (i = 0, ptr = priorityArray; i < ARRAY_COUNT(priorityArray); i++, ptr++) {
        if (*ptr != -1) {
            gWindows[*ptr].priority = currentPriority++;
        }
    }
}

void replace_window_update(s32 windowID, s8 priority, WindowUpdateFunc pendingFunc) {
    if (gWindows[windowID].flags & WINDOW_FLAG_INITIALIZED) {
        gWindows[windowID].flags |= WINDOW_FLAG_FPUPDATE_CHANGED | WINDOW_FLAG_INITIAL_ANIMATION;
        gWindows[windowID].fpPending = pendingFunc;
        gWindows[windowID].originalPriority = priority;
    }
}

void set_window_update(s32 windowID, s32 func) {
    if (gWindows[windowID].flags & WINDOW_FLAG_INITIALIZED) {
        if (func == gWindows[windowID].fpUpdate.i) {
            gWindows[windowID].flags &= ~WINDOW_FLAG_FPUPDATE_CHANGED;
        } else {
            gWindows[windowID].flags |= WINDOW_FLAG_FPUPDATE_CHANGED | WINDOW_FLAG_INITIAL_ANIMATION;
            gWindows[windowID].fpPending.i = func;
        }
    }
}

void set_windows_visible(s32 groupIdx) {
    s32 i;
    Window* window = gWindows;
    u8 min = gWindowGroups[groupIdx].min;
    u8 max = gWindowGroups[groupIdx].max;

    for (i = 0; i < ARRAY_COUNT(gWindows); i++, window++) {
        if (window->flags & WINDOW_FLAG_INITIALIZED) {
            if (i < min || i > max) {
                window->flags |= WINDOW_FLAG_DISABLED;
            } else {
                window->flags &= ~WINDOW_FLAG_DISABLED;
            }
        }
    }
}

void setup_pause_menu_tab(MenuWindowBP* bp, s32 count) {
    s32 i;

    for (i = 0; i < count; i++, bp++) {
        set_window_properties(bp->windowID, bp->pos.x, bp->pos.y, bp->width, bp->height, bp->priority,
                              bp->fpDrawContents, bp->tab, bp->parentID);
        if (bp->style.defaultStyleID != -1) {
            gWindowStyles[bp->windowID] = bp->style;
        }
        set_window_update(bp->windowID, bp->fpUpdate.i);
        gWindows[bp->windowID].flags |= bp->extraFlags;
    }
}

