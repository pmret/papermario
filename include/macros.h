#ifndef _MACROS_H_
#define _MACROS_H_

#include "common.h"
#include "include_asm.h"

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

#define N(sym) NS(NAMESPACE, sym)

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define PHYSICAL_TO_VIRTUAL(addr) (void*)((u32)(addr) + 0x80000000)
#define VIRTUAL_TO_PHYSICAL(addr) (u32)((u8*)(addr) - 0x80000000)

#define ASSERT(condition) if (!(condition)) { while (1) {} }
#define PANIC() ASSERT(0)
#define STATIC_ASSERT(condition) enum { static_assert_fail = 1/(!!(condition)) } // Causes division by zero ("not integer constant") if false

#define CAM(id) (&gCameras[id])

#define BADGE_MENU_PAGE(index) (&gBadgeMenuPages[index])
#define ITEM_MENU_PAGE(index) (&gItemMenuPages[index])

#define MAX_MAPVARS 16
#define MAX_MAPFLAGS 3

#define MAX_ANIMATED_MODELS 16
#define MAX_ANIMATED_MESHES 16
#define MAX_ENTITY_MODELS 256
#define MAX_MODELS 256
#define MAX_MODEL_TRANSFORM_GROUPS 4
#define MAX_SCRIPTS 128
#define MAX_NPCS 64
#define MAX_TRIGGERS 64
#define MAX_SHADOWS 60
#define MAX_ENTITIES 30
#define MAX_DYNAMIC_ENTITIES 16
#define MAX_TEX_PANNERS 16
#define MAX_ITEM_ENTITIES 256

// Alternative to libultra's M_PI: non-float version; more digits cause issues
#define PI      3.141592f
#define PI_D    3.141592
#define TAU     6.28318f
#define PI_S    3.14159f // Shorter PI

#define SPRITE_WORLD_SCALE 0.71428573f

#define PACK_FILL_COLOR(r, g, b, a) (GPACK_RGBA5551(r, g, b, a) << 0x10) | GPACK_RGBA5551(r, g, b, a)

//NOTE: SCRIPT_ALLOC is probably not quite correct, but this is the closest thing to matching for the functions its used in. Needs more work.
#define SCRIPT_ALLOC(new, index) \
{ \
    (*gCurrentScriptListPtr)[index] = new = heap_malloc(sizeof(ScriptInstance)); \
    gNumScripts++; \
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
#define CUBE(x) (x*x*x)
#define QUART(x) (x*x*x*x)

// Fixed-point short literal
#define F16(f) (s16)(f * 327.67f)

#define _NS(x, y) x ## _ ## y
#define NS(x, y) _NS(x, y)

#define ASCII_TO_U32(a, b, c, d) ((u32)((a << 24) | (b << 16) | (c << 8) | (d << 0)))

#endif
