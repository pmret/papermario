#ifndef _MACROS_H_
#define _MACROS_H_

#include "types.h"
#include "include_asm.h"

#ifndef M2CTX

#ifdef SHIFT
#define SHIFT_BSS __attribute__ ((section (".bss")))
#else
#define SHIFT_BSS extern
#endif

#ifdef SHIFT
#define MATCHING_BSS(size)
#else
#define MATCHING_BSS(size) static BSS u8 padding_bss[size];
#endif

#define BSS __attribute__ ((section (".bss")))
#define TRANSPARENT_UNION __attribute__ ((__transparent_union__))
#else
#define SHIFT_BSS static
#define BSS static
#define TRANSPARENT_UNION
#endif

#define ALIGNED(x) __attribute__((aligned(x)))
#define ALIGN16(val) (((val) + 0xF) & ~0xF)
#define ALIGN8(val) (((val) + 0x7) & ~0x7)

#define NAME_SUFFIX
#define NAME_PREFIX
#define A(sym) NS(AREA, NAME_PREFIX, sym, NAME_SUFFIX)
#define N(sym) NS(NAMESPACE, NAME_PREFIX, sym, NAME_SUFFIX)

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#if !defined(PERMUTER) && !defined(M2CTX) && defined(OLD_GCC)
#define NOP_FIX __asm__(".set nogpopt");
#define NOP_UNFIX __asm__(".set gpopt");
#else
#define NOP_FIX
#define NOP_UNFIX
#endif

#define PTR_LIST_END ((void*) -1)

#define API_CALLABLE(name) ApiStatus name(Evt* script, s32 isInitialCall)

// standardized padding macros for map overlays
#define MAP_RODATA_PAD(n,name) const s32 N(rodata_pad_##name)[n] = {};
#define MAP_STATIC_PAD(n,name) BSS s32 N(static_pad_##name)[n];

#define PHYSICAL_TO_VIRTUAL(addr) (void*)((u32)(addr) + 0x80000000)
#define VIRTUAL_TO_PHYSICAL(addr) (u32)((u8*)(addr) - 0x80000000)

#ifdef DEBUG
#define ASSERT(condition) \
    if (!(condition)) { \
        func_80025F44("Assertion failed: " #condition, __FILE__, __LINE__); \
        while (TRUE) {} \
    }
#define PANIC() \
    func_80025F44("Panic!", __FILE__, __LINE__); \
    while (TRUE) {}
#else
#define ASSERT(condition) if (!(condition)) { while (TRUE) {} }
#define PANIC() while (TRUE) {}
#endif

#define BADGE_MENU_PAGE(index) (&gPauseBadgesPages[index])
#define ITEM_MENU_PAGE(index) (&gPauseItemsPages[index])

#define MENU_PANEL_SELECTED_GRID_DATA(panel) \
    (panel)->gridData[(panel)->page * (panel)->numCols * (panel)->numRows + \
                      (panel)->numCols * (panel)->row + \
                      (panel)->col]

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
#define MAX_WORKERS 16
#define MAX_TEX_PANNERS 16
#define MAX_ITEM_ENTITIES 256
#define MAX_FOLD_STATES 90

#define MAX_STAR_PIECES 222

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define WORLD_ENTITY_HEAP_SIZE 0x17FF0
#define COLLISION_HEAP_SIZE 0x18000
#define GENERAL_HEAP_SIZE 0x54000
#define SPRITE_HEAP_SIZE 0x40000
#define BATTLE_HEAP_SIZE 0x25800
#define FRAME_BUFFER_SIZE 0x25800

#define CAM_NEAR_CLIP 16
#define CAM_FAR_CLIP 4096

// Size of tmem in bytes (4kB)
#define TMEM_SIZE 0x1000
// Height of tiles to use when copying fullscreen images (6)
#define SCREEN_COPY_TILE_HEIGHT ((TMEM_SIZE) / ((SCREEN_WIDTH) * (2)))

// Alternative to libultra's M_PI: non-float version; more digits cause issues
#define PI      3.141592f
#define PI_D    3.141592
#define TAU     6.28318f
#define PI_S    3.14159f // Shorter PI

// Angle conversion macros
#define DEG_TO_BINANG(x) ((x) * (0x8000 / 180.0f))
#define RAD_TO_BINANG(x) ((x) * (f32)(0x8000 / M_PI))
#define DEG_TO_RAD(deg) (((deg) * TAU) / 360.0f)

// Should be 1.0f / 0x7FFF, but precision is wrong for a double
#define SHT_MINV 3.051851e-05

#define SPRITE_WORLD_SCALE_F (5.0f/7.0f)
#define SPRITE_WORLD_SCALE_D (5.0/7.0)

#define SPRITE_ID(name, pal_anim) ((name) << 16 | (pal_anim))

#define BATTLE_NPC_ID_BIT 0x800
#define BATTLE_ENTITY_ID_BIT 0x800

#define UNPACK_BTL_AREA(battleID) (((battleID) >> 8) & 0xFF)
#define UNPACK_BTL_INDEX(battleID) ((battleID) & 0xFF)

#define COLLISION_WITH_NPC_BIT 0x2000
#define COLLISION_WITH_ENTITY_BIT 0x4000

#define ENTITY_COLLIDER_ID(entityIndex) (entityIndex | COLLISION_WITH_ENTITY_BIT)

#define NO_COLLIDER -1

#define NPC_DISPOSE_LOCATION    0,-1000,0
#define NPC_DISPOSE_POS_X   0
#define NPC_DISPOSE_POS_Y   -1000
#define NPC_DISPOSE_POS_Z   0

#define PACK_FILL_COLOR(r, g, b, a) (GPACK_RGBA5551(r, g, b, a) << 0x10) | GPACK_RGBA5551(r, g, b, a)
#define PACK_FILL_DEPTH(z,dz) (GPACK_ZDZ(z, dz) << 0x10) | GPACK_ZDZ(z, dz)

#define SQ(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define QUART(x) ((x) * (x) * (x) * (x))

/// Fixed-point short literal
#define F16(f) (s16)(f * 327.67f)

/// X.10 fixed-point literal
#define X10(f) (s32)(f * 1024.0f)

#define _NS(w, x, y, z) w ## _ ## x ## y ## z
#define NS(w, x, y, z) _NS(w, x, y, z)

#define ASCII_TO_U32(a, b, c, d) ((u32)((a << 24) | (b << 16) | (c << 8) | (d << 0)))

#define ITEM_VIS_GROUP(itemID, visGroupID) ((visGroupID) << 16 | (itemID))
#define PACK_ROOM_FLAGS(itemVisGroup, roomFlags) ((itemVisGroup) << 12 | (roomFlags))

// loads integrator with standard parameter set used for falling

#define LOAD_INTEGRATOR_FALL(ptr) \
    (ptr)[0] =  0.11430f; \
    (ptr)[1] = -0.28710f; \
    (ptr)[2] = -0.18230f; \
    (ptr)[3] =  0.01152f; \

/* common AI function and script variables */
// ai script
#define AI_TEMP_STATE                  functionTemp[0]
#define AI_TEMP_STATE_AFTER_SUSPEND    functionTemp[1]
#define AI_PATROL_GOAL_INDEX           functionTemp[2]
// melee enemy
#define AI_VAR_ATTACK_STATE    varTable[0]
#define AI_VAR_MELEE_PRE_TIME  varTable[1]
#define AI_VAR_MELEE_HIT_TIME  varTable[2]
#define AI_VAR_MELEE_MISS_TIME varTable[3]
#define AI_VAR_NEXT_STATE      varTable[7]
// melee hitbox
#define AI_VAR_HITNPC_YOFFSET  varTable[0]
#define AI_VAR_HITNPC_DIST     varTable[1]
#define AI_VAR_HITNPC_2        varTable[2]
#define AI_VAR_HITNPC_3        varTable[3]
#define AI_VAR_HITNPC_4        varTable[4]
#define AI_VAR_HITNPC_SOUND    varTable[15]
// projectile hitbox
#define VAR_PROJECTILE_HITBOX_STATE varTable[0]
#define AI_PROJECTILE_AMMO_COUNT varTable[3]

#define INTEGER_LOG2(x) ((x) <= 2 ? 1 : (x) <= 4 ? 2 : (x) <= 8 ? 3 : (x) <= 16 ? 4 : (x) <= 32 ? 5 : (x) <= 64 ? 6 : (x) <= 128 ? 7 : (x) <= 256 ? 8 : (x) <= 512 ? 9 : 10)

#define FOLIAGE_MODEL_LIST(names...) \
{ \
    .count = __NARG__(names), \
    .models = {  names } \
}

#define STATUS_CHANCE_IGNORE_RES 0xFE
#define STATUS_CHANCE_NEVER 0xFF
#define DMG_STATUS_CHANCE(typeFlag, duration, chance) (STATUS_FLAG_80000000 | typeFlag | (duration << 8) | chance)
#define DMG_STATUS_ALWAYS(typeFlag, duration) (STATUS_FLAG_80000000 | STATUS_FLAG_RIGHT_ON | typeFlag | (duration << 8))
#define DMG_STATUS_IGNORE_RES(typeFlag, duration) (typeFlag | (duration << 8) | STATUS_CHANCE_IGNORE_RES)

#ifdef OLD_GCC
#define VLA 0
#else
#define VLA
#endif

#ifdef M2CTX
#define VLA 0
#endif

#if VERSION_PAL
#define DT (50.0f/60.0f)
#else
#define DT (1.0f)
#endif

#endif
