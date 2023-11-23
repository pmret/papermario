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

#ifndef BBPLAYER
# define ALIGNED(x) __attribute__((aligned(x)))
#else
# define ALIGNED(x)
#endif

#define BBALIGNED(x) __attribute__((aligned(x)))

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

#define API_CALLABLE(name) ApiStatus name(Evt* script, b32 isInitialCall)

// standardized padding macros for map overlays
#define MAP_RODATA_PAD(n,name) const s32 N(rodata_pad_##name)[n] = {};
#define MAP_STATIC_PAD(n,name) BSS s32 N(static_pad_##name)[n];

#define PHYSICAL_TO_VIRTUAL(addr) (void*)((u32)(addr) + 0x80000000)
#define VIRTUAL_TO_PHYSICAL(addr) (u32)((u8*)(addr) - 0x80000000)

#ifdef DEBUG
#define IS_DEBUG_PANIC(statement, file, line) is_debug_panic(statement, file, line)
#else
#define IS_DEBUG_PANIC(statement, file, line) do {} while(TRUE)
#endif

#define PANIC() IS_DEBUG_PANIC("Panic", __FILE__, __LINE__)
#define ASSERT(condition) \
    if (!(condition)) { \
        IS_DEBUG_PANIC("Assertion failed: " #condition, __FILE__, __LINE__); \
    }

#define BADGE_MENU_PAGE(index) (&gPauseBadgesPages[index])
#define ITEM_MENU_PAGE(index) (&gPauseItemsPages[index])

#define MENU_PANEL_SELECTED_GRID_DATA(panel) \
    (panel)->gridData[(panel)->page * (panel)->numCols * (panel)->numRows + \
                      (panel)->numCols * (panel)->row + \
                      (panel)->col]

#define MAX_MAPVARS 16
#define MAX_MAPFLAGS 3
#define MAX_ENEMY_ACTORS 24

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
#define MAX_IMGFX_INSTANCES 90

#define MAX_STAR_PIECES 222

#define SP_PER_BAR 256
#define SP_PER_SEG 32

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define LAST_DEMO_SCENE_IDX 18

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

#define SPR_PAL_SIZE 16

#define BATTLE_ID_BIT 0x800
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

#define STATUS_KEY_IGNORE_RES 0xFE
#define STATUS_KEY_NEVER 0xFF
#define DMG_STATUS_KEY(typeFlag, duration, chance) (STATUS_FLAG_80000000 | typeFlag | (duration << 8) | chance)
#define DMG_STATUS_ALWAYS(typeFlag, duration) (STATUS_FLAG_80000000 | STATUS_FLAG_RIGHT_ON | typeFlag | (duration << 8))
#define DMG_STATUS_IGNORE_RES(typeFlag, duration) (STATUS_KEY_IGNORE_RES | typeFlag | (duration << 8))

#define _RDP_WHOLE(x) (((s32)(x * 65536.0) >> 16) & 0xFFFF)
#define _RDP_FRAC(x) ((s32)(x * 65536.0) & 0xFFFF)
#define _RDP_PACK_WHOLE(a, b) (_RDP_WHOLE(a) << 16) | _RDP_WHOLE(b)
#define _RDP_PACK_FRAC(a, b) (_RDP_FRAC(a) << 16) | _RDP_FRAC(b)

#define RDP_MATRIX(  \
    Ax, Bx, Cx, Dx, \
    Ay, By, Cy, Dy, \
    Az, Bz, Cz, Dz, \
    Aw, Bw, Cw, Dw ) \
{ \
    .m = { \
        { \
            _RDP_PACK_WHOLE(Ax, Ay), \
            _RDP_PACK_WHOLE(Az, Aw), \
            _RDP_PACK_WHOLE(Bx, By), \
            _RDP_PACK_WHOLE(Bz, Bw), \
        }, \
        { \
            _RDP_PACK_WHOLE(Cx, Cy), \
            _RDP_PACK_WHOLE(Cz, Cw), \
            _RDP_PACK_WHOLE(Dx, Dy), \
            _RDP_PACK_WHOLE(Dz, Dw), \
        }, \
        { \
            _RDP_PACK_FRAC(Ax, Ay), \
            _RDP_PACK_FRAC(Az, Aw), \
            _RDP_PACK_FRAC(Bx, By), \
            _RDP_PACK_FRAC(Bz, Bw), \
        }, \
        { \
            _RDP_PACK_FRAC(Cx, Cy), \
            _RDP_PACK_FRAC(Cz, Cw), \
            _RDP_PACK_FRAC(Dx, Dy), \
            _RDP_PACK_FRAC(Dz, Dw), \
        } \
    } \
};

#define UNPACK_PAL_R(color) (((color) >> 11) & 0x1F)
#define UNPACK_PAL_G(color) (((color) >> 6) & 0x1F)
#define UNPACK_PAL_B(color) (((color) >> 1) & 0x1F)
#define UNPACK_PAL_A(color) ((color) & 1)

#define PACK_PAL_RGBA(r, g, b, a) (((r) << 11) | ((g) << 6) | ((b) << 1) | (a));

#define PM_RM_TILEMODE_B    GBL_c1(G_BL_CLR_BL, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA)

#define PM_CC_01        0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0
#define PM_CC_02        0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0
#define PM_CC_03        TEXEL0, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0
#define PM_CC_04        PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0
#define PM_CC_05        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0
#define PM_CC_06        COMBINED, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, COMBINED
#define PM_CC_07        0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0
#define PM_CC_PRIM_FULL_ALPHA       0, 0, 0, PRIMITIVE, 0, 0, 0, 1
#define PM_CC_PRIM_NO_ALPHA         0, 0, 0, PRIMITIVE, 0, 0, 0, 0
#define PM_CC_0A        0, 0, 0, 0, ENVIRONMENT, 0, TEXEL0, 0
#define PM_CC_0B        0, 0, 0, 0, ENVIRONMENT, 0, TEXEL1, 0
#define PM_CC_0C        0, 0, 0, 0, 0, 0, 0, COMBINED
#define PM_CC_0D        0, 0, 0, 0, SHADE, 0, TEXEL1, 0
#define PM_CC_0E        0, 0, 0, TEXEL0, 0, 0, 0, 0
#define PM_CC_0F        0, 0, 0, TEXEL0, 0, 0, 0, 1
#define PM_CC_10        0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE
#define PM_CC_11        0, 0, 0, TEXEL0, SHADE, 0, TEXEL0, 0
#define PM_CC_12        0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0
#define PM_CC_13        TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL1

#define PM_CC_14        PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0
#define PM_CC_15        PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1

#define PM_CC_16        COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED

// (COMB * PRIM) + ENV
#define PM_CC_17        COMBINED, 0, PRIMITIVE, ENVIRONMENT, 0, 0, 0, COMBINED

#define PM_CC_18        COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED
#define PM_CC_19        COMBINED, 0, SHADE, PRIMITIVE, 0, 0, 0, COMBINED
#define PM_CC_1B        COMBINED, 0, PRIMITIVE, ENVIRONMENT, COMBINED, 0, SHADE, 0

#define PM_CC_NOISE     NOISE, 0, SHADE_ALPHA, 0, 0, 0, 0, 1

#define PM_CC_1A        TEXEL0, 0, PRIMITIVE_ALPHA, PRIMITIVE, 0, 0, 0, TEXEL0

// implements ENV_TINT_DEPTH for untextured models
// applies just the base color; depth-based fog color will be added during RPD blend step
// color = SHADE * PRIM_ALPHA + PRIM
// alpha = SHADE
#define PM_CC_NOTEX_TINT_FOG \
    SHADE, 0, PRIMITIVE_ALPHA, PRIMITIVE, 0, 0, 0, SHADE

// implements ENV_TINT_REMAP for untextured models
// color = SHADE * PRIM + ENV
// alpha = SHADE
#define PM_CC_NOTEX_TINT_REMAP \
    SHADE, 0, PRIMITIVE, ENVIRONMENT, 0, 0, 0, SHADE

#define PM_CC_20        COMBINED, PRIMITIVE, PRIMITIVE_ALPHA, COMBINED, 0, 0, 0, COMBINED
#define PM_CC_21        COMBINED, 0, PRIMITIVE_ALPHA, PRIMITIVE, 0, 0, 0, COMBINED
#define PM_CC_22        TEXEL0, TEXEL1, SHADE_ALPHA, TEXEL1, 0, 0, 0, TEXEL0
#define PM_CC_23        1, TEXEL0, PRIMITIVE, TEXEL0, 0, 0, 0, TEXEL0
#define PM_CC1_24       1, TEXEL0, PRIMITIVE, TEXEL0, 1, TEXEL0, TEXEL1, TEXEL0
#define PM_CC2_24       1, TEXEL1, TEXEL0, COMBINED, 0, 0, 0, COMBINED
#define PM_CC_26        0, 0, 0, 0, TEXEL0, TEXEL1, SHADE, 0
#define PM_CC_27        0, 0, 0, SHADE, 0, 0, 0, COMBINED
#define PM_CC_28        SHADE, 0, PRIMITIVE, ENVIRONMENT, 0, 0, 0, COMBINED

#define PM_CC1_29        TEXEL0, SHADE,    TEXEL0,       TEXEL0, 1, TEXEL1, TEXEL0, TEXEL1
#define PM_CC2_29        TEXEL0, COMBINED, TEXEL0_ALPHA, TEXEL0, 1, TEXEL0, TEXEL1, TEXEL0

#define	PM_CC_ALT_INTERFERENCE  TEXEL1, 0, TEXEL0, 0, TEXEL1, 0, TEXEL0, 0

#define PM_CC_2B    PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, TEXEL1
#define PM_CC_2C    PRIMITIVE, 0, TEXEL1, 0, TEXEL1, 0, PRIMITIVE, 0
#define PM_CC_2D    PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0
#define PM_CC_2E    0, 0, 0, TEXEL0, TEXEL1, 0, PRIMITIVE, 0
#define PM_CC_2F    PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0
#define PM_CC_32    PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0

#define PM_CC_33    ENVIRONMENT, PRIMITIVE, COMBINED, PRIMITIVE, COMBINED, 0, PRIMITIVE, 0

#define PM_CC_34    TEXEL0, CENTER, SCALE, ENVIRONMENT, 0, 0, 0, TEXEL0
#define PM_CC_35    0, PRIMITIVE, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED

#define PM_CC_36    TEXEL0, TEXEL1, TEXEL0, TEXEL1, 1, TEXEL0, TEXEL1, 1
#define PM_CC_37    0, 0, 0, COMBINED, COMBINED, TEXEL1, TEXEL1, TEXEL1

#define PM_CC_38    TEXEL1, K4, PRIMITIVE_ALPHA, TEXEL0, TEXEL0, TEXEL1, ENVIRONMENT, ENVIRONMENT
#define PM_CC_39    TEXEL1, K4, COMBINED_ALPHA, COMBINED, 0, 0, 0, 1

#define PM_CC_3A    0, 0, 0, PRIMITIVE, 1, TEXEL0, PRIMITIVE, TEXEL0
#define PM_CC_3B    0, 0, 0, SHADE, 1, 0, PRIMITIVE, 0

#define PM_CC_3C    0, 0, 0, PRIMITIVE, SHADE, 0, PRIMITIVE, 0

#define PM_CC_3D    SHADE, ENVIRONMENT, TEXEL0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0

#define PM_CC_3E    0, 0, 0, COMBINED, 0, 0, 0, PRIMITIVE

#define PM_CC_3F    TEXEL0, 0, SHADE, 0, SHADE, 0, PRIMITIVE, 0

// animated tiles spreading over the screen when the game is reset
// color = pure black
// alpha = texture
#define PM_CC_RESET_TILES   0, 0, 0, 0, 0, 0, 0, TEXEL0

// light with animated alpha surrounding the flower gate in mac_01 as it appears
// color = pure white
// alpha = SHADE * PRIM
#define PM_CC_FLOWER_GATE_GLOW  0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0

// light with animated alpha pouring through the opening in kkj_27 as the secret wall rotates
// color = TEXEL0 * SHADE
// alpha = PRIM
#define PM_CC_KKJ_SPILL_LIGHT   TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE

// color = SHADE + PRIM
// alpha = PRIMITIVE * TEXEL0
#define PM_CC_DAMAGE_INDICATOR  1, 0, SHADE, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0

// custom combine modes for shadows
#define PM_CC1_SHADOW   0, 0, 0, 0, PRIMITIVE, 0, TEXEL0, 0
#define PM_CC2_SHADOW   0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0

// custom cycle1 modes for window styles
#define PM_CC_WINDOW_2              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1
#define PM_CC_WINDOW_3              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0
#define PM_CC_WINDOW_4              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, PRIMITIVE
#define PM_CC_WINDOW_5              0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1
#define PM_CC_WINDOW_6              0, 0, 0, TEXEL1, PRIMITIVE, 0, TEXEL1, 0
#define PM_CC_WINDOW_7              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 1
// custom cycle2 modes for window styles
#define PM_CC_WINDOW_1              COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED

#define PM_CC_IMGFX_COLOR_FILL      0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0
#define PM_CC_IMGFX_HOLOGRAM        NOISE, PRIMITIVE, PRIMITIVE, TEXEL0, TEXEL0, 0, PRIMITIVE, 0

#define PM_CC_MSG_NOISE_OUTLINE     NOISE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0
#define PM_CC_MSG_STATIC            NOISE, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, TEXEL0

#define PM_CC_CANDLE_1              TEXEL0, TEXEL1, TEXEL0, 1, 1, TEXEL0, TEXEL1, 1
#define PM_CC_CANDLE_2              0, PRIMITIVE, COMBINED, ENVIRONMENT, COMBINED, TEXEL1, TEXEL1, TEXEL1

#define PM_CC_BOX1_OPAQUE           TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL1
#define PM_CC_BOX2_OPAQUE           TEXEL0, 0, TEXEL1, 0, 0, 0, 0, TEXEL1
#define PM_CC_BOX1_TRANSPARENT      TEXEL0, 0, PRIMITIVE, 0, TEXEL1, 0, PRIMITIVE, 0
#define PM_CC_BOX2_TRANSPARENT      TEXEL0, 0, TEXEL1, 0, TEXEL1, 0, PRIMITIVE, 0

#define PM_CC_BOX1_CYC2             TEXEL0, ENVIRONMENT, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED
#define PM_CC_BOX2_CYC2             PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED

#define PM_CC_30        1, 0, TEXEL1, 0, 0, 0, 0, TEXEL1
#define PM_CC_31        1, 0, TEXEL1, 0, TEXEL1, 0, PRIMITIVE, 0

#define PM_CC_42        TEXEL0, 0, SHADE, 0, TEXEL0, 0, 0, TEXEL0

#define PM_CC_43        PRIMITIVE, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1
#define PM_CC_44        PRIMITIVE, TEXEL1, PRIMITIVE_ALPHA, TEXEL1, 0, 0, 0, 1

#define PM_CC_45        TEXEL0, 0, PRIMITIVE, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0
#define PM_CC_46        TEXEL0, ENVIRONMENT, PRIMITIVE, 0, PRIMITIVE, 0, TEXEL0, 0
#define PM_CC_47        TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, 0, TEXEL0, 0

#define PM_CC_48        PRIMITIVE, 0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, SHADE

#define PM_CC_49        TEXEL0, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0

#define PM_CC_4A        TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0
#define PM_CC_4B        PRIMITIVE, CENTER, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED
#define PM_CC_4C        1, COMBINED, PRIMITIVE, COMBINED, 0, 0, 0, COMBINED
#define PM_CC_4D        ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0
#define PM_CC_4E        SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0
#define PM_CC_4F        0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0

#define PM_CC_50        TEXEL0, 0, TEXEL1, 0, 0, 0, 0, TEXEL1
#define PM_CC_51        TEXEL0, 0, TEXEL1, 0, PRIMITIVE, 0, TEXEL1, 0
#define PM_CC_52        SHADE, ENVIRONMENT, COMBINED, COMBINED, 0, 0, 0, COMBINED

#define PM_CC_53        TEXEL1, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0
#define PM_CC_54        COMBINED, TEXEL0, COMBINED_ALPHA, TEXEL0, PRIMITIVE, 0, TEXEL0, 0
#define PM_CC_55        PRIMITIVE, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, 1

#define PM_CC_56        0, 0, 0, 0, PRIMITIVE, TEXEL0, PRIMITIVE, 0
#define PM_CC_57        1, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, ENVIRONMENT, PRIMITIVE
#define PM_CC_58        0, 0, 0, 0, 1, 0, ENVIRONMENT, PRIMITIVE

#define PM_CC_59        0, 0, 0, 0, SHADE, 0, TEXEL0, 0
#define PM_CC_5A        SHADE, ENVIRONMENT, TEXEL0, TEXEL0, 0, 0, 0, TEXEL0

#define PM_CC_5B        1, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0
#define PM_CC_5C        1, 0, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0
#define PM_CC_5D        1, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define PM_CC_5E        1, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0

#define PM_CC_HOS_BG_SHADE      0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0

#define PM_CC_CONST_ALPHA_1         0, 0, 0, 0, 0, 0, 0, 1
#define PM_CC_CONST_0               0, 0, 0, 0, 0, 0, 0, 0
#define PM_CC_CONST_1               0, 0, 0, 1, 0, 0, 0, 1

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

#define DMA_COPY_SEGMENT(segment) dma_copy(segment##_ROM_START, segment##_ROM_END, segment##_VRAM)

#endif
