#ifndef _MACROS_H_
#define _MACROS_H_

#include "common.h"

#ifndef SPLAT
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
  TYPE __attribute__((naked)) NAME(ARGS) { __asm__( ".include \"include/macro.inc\"\n.include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\n.set reorder\n.set at"); }
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

#define N(sym) NS(NAMESPACE, sym)

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define ASSERT(condition) if (!(condition)) { while (1) {} }
#define PANIC() ASSERT(0)
#define STATIC_ASSERT(condition) enum { static_assert_fail = 1/(!!(condition)) } // Causes division by zero ("not integer constant") if false

#define BATTLE_STATUS (&gBattleStatus)
#define GAME_STATUS (*gGameStatusPtr)
#define PLAYER_STATUS (&gPlayerStatus)
#define UI_STATUS (&gUIStatus)
#define PLAYER_DATA (&gPlayerData)
#define CAM(id) (&gCameras[id])
#define CURRENT_CAM (&gCameras[gCurrentCameraID])

#define BADGE_MENU_PAGE(index) (&gBadgeMenuPages[index])
#define ITEM_MENU_PAGE(index) (&gItemMenuPages[index])

#define MAX_MAPVARS 16
#define MAX_MAPFLAGS 3

#define MAX_ANIMATED_MODELS 16
#define MAX_ANIMATED_MESHES 16
#define MAX_MODELS 256
#define MAX_SCRIPTS 128
#define MAX_NPCS 64
#define MAX_TRIGGERS 64
#define MAX_SHADOWS 60
#define MAX_ENTITIES 30
#define MAX_DYNAMIC_ENTITIES 16

// Alternative to libultra's M_PI: non-float version; more digits cause issues
#define PI 3.141592f
#define TAU 6.28318f

//NOTE: SCRIPT_ALLOC is probably not quite correct, but this is the closest thing to matching for the functions its used in. Needs more work.
#define SCRIPT_ALLOC(new, index) \
{ \
    ScriptList** temp = &gCurrentScriptListPtr; \
    s32 *numScripts = &gNumScripts; \
    new = heap_malloc(sizeof(ScriptInstance)); \
    (**temp)[index] = new; \
    (*numScripts)++; \
    ASSERT(new != NULL); \
}

#define SCRIPT_FREE(index) \
{ \
    ScriptList** temp = &gCurrentScriptListPtr; \
    s32 *numScripts = &gNumScripts; \
    heap_free((**temp)[index]); \
    (**temp)[index] = NULL; \
    (*numScripts)--; \
}

#define SQ(x) (x*x)

// Fixed-point short literal
#define F16(f) (s16)(f * 327.67f)

#define _NS(x, y) x ## _ ## y
#define NS(x, y) _NS(x, y)

#endif
