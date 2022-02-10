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

typedef struct WindowsGroup {
    /* 0x00 */ u8 min;
    /* 0x01 */ u8 max;
} WindowsGroup; // size = 0x02

s32 gWindowStyles[] = {
    3, 3, 11, 12, 13, 14, 3, 21, 3, 0, 9, 3, 0, 1, 3, 9,
    10, 7, 8, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 11, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
};

SimpleWindowUpdateData gSimpleWindowUpdates[] = {
    {
        .flags = 0,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = 0,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_HIDDEN | WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = 0,
        .windowFlagsSet = WINDOW_FLAGS_HIDDEN,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_1,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_DARKENING,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 100,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_DARKENING,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 0
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_OPACITY,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 184
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_OPACITY,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 255
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_OPACITY,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_HIDDEN | WINDOW_FLAGS_8,
        .darkening = 0,
        .opacity = 184
    },
    {
        .flags = SIMPLE_WINDOW_UPDATE_DARKENING,
        .windowFlagsSet = 0,
        .windowFlagsUnset = WINDOW_FLAGS_HIDDEN | WINDOW_FLAGS_8,
        .darkening = 100,
        .opacity = 0
    },
    { },
    { },
    { },
    { }
};

u8 gWindowAppearScales[] = { 50, 80, 100, 105, 100 };
u8 gWindowAppearFlags[] = { DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, 0};
u8 gWindowDisappearScales[] = { 105, 100, 77, 57, 40, 27, 16, 8, 3, 0 };
u8 gWindowDisappearFlags[] = { DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE,
                    DRAW_FLAGS_ROTSCALE, DRAW_FLAGS_ROTSCALE, 0 };

WindowsGroup gWindowsGroups[] = {
    { WINDOW_ID_0, WINDOW_ID_63 }, // all windows
    { WINDOW_ID_8, WINDOW_ID_9 }, // battle ?
    { WINDOW_ID_PAUSE_MAIN, WINDOW_ID_PAUSE_TAB_INVIS }, // pause menu
    { WINDOW_ID_PAUSE_CURSOR, WINDOW_ID_63 } // file menu
};

// this is definitely wrong but I had issues trying to use an array accessor
void clear_windows(void) {
    Window* windowIt = gWindows;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gWindows); i++, windowIt++) {
        windowIt->flags = 0;
    }
}

void update_windows(void) {
    Window* window;
    s32 i;
    u8 flags;

    for (i = 0, window = gWindows; i < 64; i++, window++) {
        flags = window->flags;

        if (!flags || (flags & WINDOW_FLAGS_DISABLED)) {
            continue;
        }

        if (flags & WINDOW_FLAGS_FPUPDATE_CHANGED) {
            window->flags = flags & ~WINDOW_FLAGS_FPUPDATE_CHANGED;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_8;
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
        window->flags &= ~WINDOW_FLAGS_8;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~(WINDOW_FLAGS_8 | WINDOW_FLAGS_HIDDEN);
    }
}
//#define NON_MATCHING
#ifdef NON_MATCHING
void render_windows(s32* windowsArray, s32 parent, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32* arg7) {
    Window* window;
    Window* childWindow;
    s32 i;
    s32 childWindowID;
    s32 counter;
    Matrix4f outMtx;
    f32* matrix2;
    s32 flags;
    s32 posX, posY, posZ;
    f32 scaleX, scaleY, rotX, rotY, rotZ;
    s32 darkening, opacity;
    s32 boxFlags;
    s32 boxTranslateX;
    s32 boxTranslateY;
    s32 fpUpdateIdx;
    s32 width, height;
    void (*fpUpdateFunc)(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                                 f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
    s32 windowStyle;
    void* fpDrawContents;
    s32 drawContentsArg0;

    for (i = 0; i < ARRAY_COUNT(gWindows); i++) {
        window = &gWindows[parent];
        childWindowID = windowsArray[i];
        if (childWindowID < 0) {
            continue;
        }
        childWindow = &gWindows[childWindowID];
        if (childWindow->flags == 0 || (childWindow->flags & WINDOW_FLAGS_DISABLED)) {
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
        flags = 0;
        rotX = rotY = rotZ = 0.0f;
        scaleY = scaleX = 1.0f;
        darkening = 0;
        opacity = 255;
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
                darkening = updateData->darkening;
            }
            if (updateData->flags & SIMPLE_WINDOW_UPDATE_OPACITY) {
                opacity = updateData->opacity;
            }
        } else {
            fpUpdateFunc = childWindow->fpUpdate.func;
            fpUpdateFunc(childWindowID, &flags, &posX, &posY, &posZ, &scaleX, &scaleY, &rotX, &rotY, &rotZ, &darkening, &opacity);
        }
        if (childWindow->fpUpdate.i) {
            if (childWindow->updateCounter < 255) {
                childWindow->updateCounter++;
            }
        }
        if (scaleX == 0 || scaleY == 0 || (childWindow->flags & WINDOW_FLAGS_HIDDEN)) {
            continue;
        }

        darkening += arg6;
        opacity = opacity * arg5 / 255;
        fpDrawContents = childWindow->fpDrawContents;
        drawContentsArg0 = childWindow->drawContentsArg0;
        windowStyle = gWindowStyles[childWindowID];
        matrix2 = outMtx;

        if (darkening > 255) {
            darkening = 255;
        }
        flags |= arg2;
        if (!(arg2 & DRAW_FLAGS_ROTSCALE)) {
            posX += arg3;
            posY += arg4;
        }

        if (parent == -1) {
            boxTranslateX = 320;
        } else {
            boxTranslateX = window->width;
        }
        boxTranslateY = 240;
        if (parent != -1) {
            boxTranslateY = window->height;
        }
        boxFlags = flags;
        if (childWindow->flags & WINDOW_FLAGS_40) {
            boxFlags |= DRAW_FLAGS_2;
        }
        if (draw_box(boxFlags, windowStyle, posX, posY, posZ, width, height, opacity, darkening,
                    scaleX, scaleY, rotX, rotY, rotZ, fpDrawContents, drawContentsArg0, arg7,
                    boxTranslateX, boxTranslateY, matrix2) == 0) {
            if (flags == 0 && arg7 == 0) {
                matrix2 = NULL;
            }
            if (childWindow->flags & WINDOW_FLAGS_HAS_CHILDREN) {
                render_windows(windowsArray, childWindowID, flags, posX, posY, opacity, darkening, matrix2);
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "ddaf0_len_c50", render_windows);
#endif

void render_window_root(void) {
    s32 sp20[ARRAY_COUNT(gWindows)];
    s32* ptr = sp20;
    s32 i;
    Window* window;

    for (i = 0; i < ARRAY_COUNT(gWindows); i++) {
        *ptr++ = -1;
    }
    for (i = 0, window = gWindows; i < ARRAY_COUNT(gWindows); window++, i++) {
        if (window->flags != 0) {
            sp20[window->priority] = i;
        }
    }

    gSPLoadGeometryMode(gMasterGfxPos++, 0);
    gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_SHADING_SMOOTH);
    gDPPipelineMode(gMasterGfxPos++, G_PM_NPRIMITIVE);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_SHADE, G_CC_SHADE);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
    gSPSetOtherMode(gMasterGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 16, 0x2CF0); // WHAT?? does it make several operations at once?
    gSPClipRatio(gMasterGfxPos++, FRUSTRATIO_2);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
    gDPPipeSync(gMasterGfxPos++);
    render_windows(sp20, WINDOW_ID_NONE, 0, 0, 0, 255, 0, 0);
}

void set_window_properties(s32 windowID, s32 posX, s32 posY, s32 width, s32 height, u8 priority, void* fpDrawContents, PopupMessage* drawContentsArg0, s8 parent) {
    Window* window = &gWindows[windowID];
    u8 priorityCopy = priority;

    window->flags = WINDOW_FLAGS_1 | WINDOW_FLAGS_HIDDEN;
    window->pos.x = posX;
    window->pos.y = posY;
    window->width = width;
    window->fpUpdate.i = 0;
    window->parent = parent;
    window->height = height;
    window->fpDrawContents = fpDrawContents;
    window->drawContentsArg0 = drawContentsArg0;
    if (parent >= 0) {
        gWindows[parent].flags |= WINDOW_FLAGS_HAS_CHILDREN;
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
    if (gWindows[windowID].flags & WINDOW_FLAGS_1) {
        gWindows[windowID].flags |= WINDOW_FLAGS_FPUPDATE_CHANGED | WINDOW_FLAGS_8;
        gWindows[windowID].fpPending = pendingFunc;
        gWindows[windowID].originalPriority = priority;
    }
}

void set_window_update(s32 windowID, WindowUpdateFunc func) {
    if (gWindows[windowID].flags & WINDOW_FLAGS_1) {
        if (func.i == gWindows[windowID].fpUpdate.i) {
            gWindows[windowID].flags &= ~WINDOW_FLAGS_FPUPDATE_CHANGED;
        } else {
            gWindows[windowID].flags |= WINDOW_FLAGS_FPUPDATE_CHANGED | WINDOW_FLAGS_8;
            gWindows[windowID].fpPending = func;
        }
    }
}

void set_windows_visible(s32 groupIdx) {
    s32 i;
    Window* window = gWindows;
    u8 min = gWindowsGroups[groupIdx].min;
    u8 max = gWindowsGroups[groupIdx].max;

    for (i = 0; i < 64; i++, window++) {
        if (window->flags & WINDOW_FLAGS_1) {
            if (i < min || i > max) {
                window->flags |= WINDOW_FLAGS_DISABLED;
            } else {
                window->flags &= ~WINDOW_FLAGS_DISABLED;
            }
        }
    }
}

void setup_pause_menu_tab(MenuWindowBP* bp, s32 count) {
    s32 i;

    for (i = 0; i < count; i++, bp++) {
        set_window_properties(bp->windowID, bp->pos.x, bp->pos.y, bp->width, bp->height, bp->priority, bp->fpDrawContents, bp->tab, bp->parentID);
        if (bp->style != -1) {
            gWindowStyles[bp->windowID] = bp->style;
        }
        set_window_update(bp->windowID, bp->fpUpdate);
        gWindows[bp->windowID].flags |= bp->extraFlags;
    }
}

