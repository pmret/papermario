enum {
    I_00 = 0,
    I_01 = 1,
    I_02 = 2,
    I_03 = 3,
    I_04 = 4,
    I_05 = 5,
    I_06 = 6,
    I_07 = 7,
    I_08 = 8,
    I_09 = 9,
    I_0A = 10,
    I_0B = 11,
    I_0C = 12,
    I_0D = 13,
    I_0E = 14,
    I_0F = 15,
    I_10 = 16,
    I_11 = 17,
    I_12 = 18,
    I_13 = 19,
    I_14 = 20,
    I_15 = 21,
    I_16 = 22,
    I_17 = 23,
    I_18 = 24,
    I_19 = 25,
    I_1A = 26,
    I_1B = 27,
    I_1C = 28,
    I_END = 29,
};

enum {
    R_00 = 0,
    R_01 = 1,
    R_02 = 2,
    R_03 = 3,
    R_04 = 4,
    R_05 = 5,
    R_06 = 6,
    R_07 = 7,
    R_08 = 8,
    R_09 = 9,
    R_0A = 10,
    R_0B = 11,
    R_0C = 12,
    R_0D = 13,
    R_0E = 14,
    R_0F = 15,
    R_10 = 16,
    R_11 = 17,
    R_12 = 18,
    R_13 = 19,
    R_14 = 20,
    R_15 = 21,
    R_16 = 22,
    R_17 = 23,
    R_18 = 24,
    R_19 = 25,
    R_1A = 26,
    R_1B = 27,
    R_1C = 28,
    R_1D = 29,
    R_1E = 30,
    R_1F = 31,
    R_20 = 32,
    R_21 = 33,
    R_22 = 34,
    R_23 = 35,
    R_24 = 36,
    R_25 = 37,
    R_26 = 38,
    R_27 = 39,
    R_28 = 40,
    R_29 = 41,
    R_2A = 42,
    R_2B = 43,
    R_2C = 44,
    R_2D = 45,
    R_2E = 46,
    R_2F = 47,
    R_30 = 48,
    R_31 = 49,
    R_32 = 50,
    R_END = 51,
};

enum {
    QUALITY_BAD     = 0,
    QUALITY_OK      = 1,
    QUALITY_GOOD    = 2,
    QUALITY_GREAT   = 3,
    QUALITY_ODD     = 4,
};

// IngredientType
s32 CookingIngredients[] = {
    [I_00] ITEM_MUSHROOM,
    [I_01] ITEM_SUPER_SHROOM,
    [I_02] ITEM_ULTRA_SHROOM,
    [I_03] ITEM_LIFE_SHROOM,
    [I_04] ITEM_VOLT_SHROOM,
    [I_05] ITEM_FIRE_FLOWER,
    [I_06] ITEM_COCONUT,
    [I_07] ITEM_LIME,
    [I_08] ITEM_LEMON,
    [I_09] ITEM_HONEY_SYRUP,
    [I_0A] ITEM_MAPLE_SYRUP,
    [I_0B] ITEM_JAMMIN_JELLY,
    [I_0C] ITEM_APPLE,
    [I_0D] ITEM_RED_BERRY,
    [I_0E] ITEM_BLUE_BERRY,
    [I_0F] ITEM_YELLOW_BERRY,
    [I_10] ITEM_GOOMNUT,
    [I_11] ITEM_KOOPA_LEAF,
    [I_12] ITEM_DRIED_PASTA,
    [I_13] ITEM_DRIED_FRUIT,
    [I_14] ITEM_STRANGE_LEAF,
    [I_15] ITEM_CAKE_MIX,
    [I_16] ITEM_EGG,
    [I_17] ITEM_MELON,
    [I_18] ITEM_STINKY_HERB,
    [I_19] ITEM_ICED_POTATO,
    [I_1A] ITEM_DRIED_SHROOM,
    [I_1B] ITEM_BUBBLE_BERRY,
    [I_1C] ITEM_WHACKAS_BUMP,
    [I_END] -1
};

typedef struct CookingResult {
    /* 00 */ s32 quality;
    /* 04 */ s32 itemID;
} CookingResult; // size = 0x8

CookingResult CookingResults[] = {
    [R_00] { QUALITY_BAD,   ITEM_MISTAKE },
    [R_01] { QUALITY_OK,    ITEM_FRIED_SHROOM },
    [R_02] { QUALITY_OK,    ITEM_SPICY_SOUP },
    [R_03] { QUALITY_OK,    ITEM_TASTY_TONIC },
    [R_04] { QUALITY_OK,    ITEM_NUTTY_CAKE },
    [R_05] { QUALITY_OK,    ITEM_KOOPA_TEA },
    [R_06] { QUALITY_OK,    ITEM_SPAGHETTI },
    [R_07] { QUALITY_ODD,   ITEM_DIZZY_DIAL },
    [R_08] { QUALITY_GOOD,  ITEM_BIG_COOKIE },
    [R_09] { QUALITY_OK,    ITEM_CAKE },
    [R_0A] { QUALITY_OK,    ITEM_FRIED_EGG },
    [R_0B] { QUALITY_OK,    ITEM_BOILED_EGG },
    [R_0C] { QUALITY_OK,    ITEM_SUPER_SODA },
    [R_0D] { QUALITY_OK,    ITEM_YOSHI_COOKIE },
    [R_0E] { QUALITY_GREAT, ITEM_DELUXE_FEAST },
    [R_0F] { QUALITY_OK,    ITEM_FROZEN_FRIES },
    [R_10] { QUALITY_OK,    ITEM_POTATO_SALAD },
    [R_11] { QUALITY_OK,    ITEM_HOT_SHROOM },
    [R_12] { QUALITY_GOOD,  ITEM_BLAND_MEAL },
    [R_13] { QUALITY_OK,    ITEM_HONEY_SHROOM },
    [R_14] { QUALITY_OK,    ITEM_MAPLE_SHROOM },
    [R_15] { QUALITY_OK,    ITEM_JELLY_SHROOM1 },
    [R_16] { QUALITY_OK,    ITEM_LIFE_SHROOM },
    [R_17] { QUALITY_OK,    ITEM_VOLT_SHROOM },
    [R_18] { QUALITY_ODD,   ITEM_SLEEPY_SHEEP },
    [R_19] { QUALITY_OK,    ITEM_SHROOM_CAKE },
    [R_1A] { QUALITY_OK,    ITEM_SHROOM_STEAK },
    [R_1B] { QUALITY_OK,    ITEM_HONEY_SUPER },
    [R_1C] { QUALITY_OK,    ITEM_MAPLE_SUPER },
    [R_1D] { QUALITY_OK,    ITEM_JELLY_SUPER },
    [R_1E] { QUALITY_GOOD,  ITEM_YUMMY_MEAL },
    [R_1F] { QUALITY_OK,    ITEM_HONEY_ULTRA },
    [R_20] { QUALITY_OK,    ITEM_MAPLE_ULTRA },
    [R_21] { QUALITY_OK,    ITEM_JELLY_ULTRA },
    [R_22] { QUALITY_OK,    ITEM_SWEET_SHROOM },
    [R_23] { QUALITY_OK,    ITEM_ELECTRO_POP },
    [R_24] { QUALITY_ODD,   ITEM_THUNDER_RAGE },
    [R_25] { QUALITY_OK,    ITEM_FIRE_POP },
    [R_26] { QUALITY_OK,    ITEM_EGG_MISSILE },
    [R_27] { QUALITY_GOOD,  ITEM_SPECIAL_SHAKE },
    [R_28] { QUALITY_OK,    ITEM_COCO_POP },
    [R_29] { QUALITY_GREAT, ITEM_HEALTHY_JUICE },
    [R_2A] { QUALITY_OK,    ITEM_LIME_CANDY },
    [R_2B] { QUALITY_OK,    ITEM_LEMON_CANDY },
    [R_2C] { QUALITY_OK,    ITEM_HONEY_CANDY },
    [R_2D] { QUALITY_OK,    ITEM_JELLY_POP },
    [R_2E] { QUALITY_OK,    ITEM_APPLE_PIE },
    [R_2F] { QUALITY_OK,    ITEM_KOOPASTA },
    [R_30] { QUALITY_OK,    ITEM_KOOKY_COOKIE },
    [R_31] { QUALITY_ODD,   ITEM_FIRE_FLOWER },
    [R_32] { QUALITY_GOOD,  ITEM_STRANGE_CAKE },
    [R_END] { -1, -1 },
};

s8 SingleRecipesWithoutCookbook[] = {
    [I_00] R_01,
    [I_01] R_01,
    [I_02] R_1A,
    [I_03] R_11,
    [I_04] R_11,
    [I_05] R_02,
    [I_06] R_03,
    [I_07] R_03,
    [I_08] R_03,
    [I_09] R_0C,
    [I_0A] R_0C,
    [I_0B] R_0C,
    [I_0C] R_0C,
    [I_0D] R_00,
    [I_0E] R_00,
    [I_0F] R_00,
    [I_10] R_04,
    [I_11] R_05,
    [I_12] R_06,
    [I_13] R_00,
    [I_14] R_00,
    [I_15] R_09,
    [I_16] R_0A,
    [I_17] R_27,
    [I_18] R_00,
    [I_19] R_10,
    [I_1A] R_00,
    [I_1B] R_00,
    [I_1C] R_00,
};

s8 SingleRecipesWithCookbook[] = {
    [I_00] R_01,
    [I_01] R_01,
    [I_02] R_1A,
    [I_03] R_11,
    [I_04] R_11,
    [I_05] R_02,
    [I_06] R_03,
    [I_07] R_03,
    [I_08] R_03,
    [I_09] R_0C,
    [I_0A] R_0C,
    [I_0B] R_0C,
    [I_0C] R_0C,
    [I_0D] R_0C,
    [I_0E] R_0C,
    [I_0F] R_0C,
    [I_10] R_04,
    [I_11] R_05,
    [I_12] R_06,
    [I_13] R_00,
    [I_14] R_07,
    [I_15] R_09,
    [I_16] R_0A,
    [I_17] R_27,
    [I_18] R_00,
    [I_19] R_10,
    [I_1A] R_01,
    [I_1B] R_03,
    [I_1C] R_1E,
};

s8 DoubleRecipesMatrix[] = {
/*          I_00  I_01  I_02  I_03  I_04  I_05  I_06  I_07  I_08  I_09  I_0A  I_0B  I_0C  I_0D  I_0E  I_0F  I_10  I_11  I_12  I_13  I_14  I_15  I_16  I_17  I_18  I_19  I_1A  I_1B  I_1C */
/* I_00 */  R_00, R_11, R_1A, R_1A, R_11, R_11, R_00, R_00, R_00, R_13, R_14, R_15, R_00, R_00, R_00, R_00, R_17, R_17, R_12, R_17, R_17, R_19, R_12, R_00, R_00, R_12, R_01, R_00, R_00, 
/* I_01 */    -1, R_00, R_1A, R_1A, R_11, R_12, R_00, R_00, R_00, R_1B, R_1C, R_1D, R_00, R_00, R_00, R_00, R_16, R_16, R_12, R_17, R_16, R_19, R_12, R_00, R_00, R_12, R_11, R_00, R_00, 
/* I_02 */    -1,   -1, R_00, R_1A, R_1A, R_1E, R_00, R_00, R_00, R_1F, R_20, R_21, R_00, R_00, R_00, R_00, R_16, R_16, R_1E, R_17, R_16, R_22, R_1E, R_00, R_00, R_1E, R_1A, R_00, R_00, 
/* I_03 */    -1,   -1,   -1, R_00, R_00, R_12, R_00, R_00, R_00, R_1B, R_1C, R_1D, R_00, R_00, R_00, R_00, R_16, R_16, R_12, R_17, R_16, R_22, R_12, R_00, R_00, R_12, R_1A, R_00, R_00, 
/* I_04 */    -1,   -1,   -1,   -1, R_00, R_12, R_00, R_00, R_00, R_1B, R_1C, R_1D, R_00, R_00, R_00, R_00, R_16, R_16, R_12, R_24, R_07, R_23, R_12, R_00, R_00, R_12, R_11, R_00, R_00, 
/* I_05 */    -1,   -1,   -1,   -1,   -1, R_00, R_00, R_00, R_00, R_00, R_00, R_00, R_00, R_00, R_00, R_00, R_12, R_00, R_00, R_00, R_00, R_25, R_26, R_00, R_00, R_0F, R_01, R_00, R_00, 
/* I_06 */    -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_00, R_03, R_0C, R_27, R_0C, R_0C, R_0C, R_0C, R_00, R_0C, R_12, R_00, R_00, R_28, R_00, R_0C, R_00, R_12, R_00, R_00, R_00, 
/* I_07 */    -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_0C, R_03, R_0C, R_27, R_0C, R_0C, R_0C, R_0C, R_00, R_0C, R_00, R_00, R_00, R_2A, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_08 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_03, R_0C, R_27, R_0C, R_0C, R_0C, R_0C, R_00, R_0C, R_00, R_00, R_00, R_2B, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_09 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_0C, R_27, R_03, R_03, R_03, R_03, R_00, R_0C, R_00, R_00, R_00, R_2C, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_0A */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_27, R_0C, R_0C, R_0C, R_0C, R_00, R_0C, R_00, R_00, R_00, R_30, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_0B */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_27, R_27, R_27, R_27, R_00, R_0C, R_00, R_00, R_00, R_2D, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_0C */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_0C, R_0C, R_0C, R_00, R_00, R_00, R_00, R_00, R_2E, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_0D */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_0C, R_0C, R_00, R_12, R_12, R_00, R_18, R_08, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_0E */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_0C, R_00, R_12, R_12, R_00, R_18, R_08, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_0F */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_12, R_12, R_00, R_18, R_08, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_10 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_12, R_12, R_00, R_12, R_08, R_00, R_00, R_00, R_00, R_00, R_00, R_00, 
/* I_11 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_2F, R_00, R_00, R_30, R_00, R_27, R_00, R_00, R_00, R_00, R_00, 
/* I_12 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_1E, R_12, R_00, R_12, R_00, R_00, R_12, R_00, R_00, R_00, 
/* I_13 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_31, R_00, R_00, R_00, R_00, R_1E, R_00, R_00, R_00, 
/* I_14 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_32, R_0B, R_27, R_07, R_1E, R_00, R_00, R_00, 
/* I_15 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_08, R_0D, R_30, R_12, R_00, R_00, R_00, 
/* I_16 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_0B, R_12, R_00, R_00, R_00, 
/* I_17 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_00, R_00, R_00, R_00, 
/* I_18 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_00, R_00, R_00, 
/* I_19 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_00, R_00, 
/* I_1A */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, R_00, 
/* I_1B */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, R_00, 
/* I_1C */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, R_00, 
};

typedef struct ExtraCookingPair {
    /* 00 */ s32 inputA;
    /* 04 */ s32 inputB;
    /* 04 */ s32 output;
} ExtraCookingPair; // size = 0x8

ExtraCookingPair ExtraDoubleRecipes[] = {
    { ITEM_SPECIAL_SHAKE, ITEM_DRIED_SHROOM,  R_29 },
    { ITEM_SPECIAL_SHAKE, ITEM_STRANGE_LEAF,  R_29 },
    { ITEM_SPECIAL_SHAKE, ITEM_STINKY_HERB,   R_29 },
    { ITEM_POTATO_SALAD,  ITEM_SPAGHETTI,     R_1E },
    { ITEM_POTATO_SALAD,  ITEM_FRIED_SHROOM,  R_12 },
    { ITEM_POTATO_SALAD,  ITEM_HOT_SHROOM,    R_1E },
    { ITEM_POTATO_SALAD,  ITEM_SHROOM_STEAK,  R_0E },
    { ITEM_STRANGE_LEAF,  ITEM_WHACKAS_BUMP,  R_0E },
};

s32 MysteryResultOptions[] = {
    ITEM_FIRE_FLOWER,
    ITEM_TASTY_TONIC,
    ITEM_SUPER_SODA,
    ITEM_SLEEPY_SHEEP,
    ITEM_LIFE_SHROOM,
    ITEM_DIZZY_DIAL,
    ITEM_VOLT_SHROOM,
    ITEM_FRIED_SHROOM,
    ITEM_KOOPASTA,
    ITEM_SPICY_SOUP,
    ITEM_KOOPA_TEA,
    ITEM_SPAGHETTI,
    ITEM_FRIED_EGG,
    ITEM_BOILED_EGG,
    ITEM_POTATO_SALAD,
    ITEM_HONEY_SHROOM,
    ITEM_BLAND_MEAL,
    ITEM_THUNDER_RAGE,
    ITEM_EGG_MISSILE,
    ITEM_APPLE_PIE,
    ITEM_KOOKY_COOKIE,
    ITEM_BIG_COOKIE,
    ITEM_SPECIAL_SHAKE,
};

API_CALLABLE(func_80242C44_825F04);

// result in LVar6, quality in LVar7, item to remove in LVar8?
INCLUDE_ASM(s32, "world/area_mac/mac_02/mac_02_6_npc", func_80242C44_825F04);

API_CALLABLE(N(GetCookResultForDoubleRecipe)) {
    Bytecode* args = script->ptrReadPos;
    CookingResult* result;
    ExtraCookingPair* extraList;
    s32 inputItemA, inputItemB;
    s32 outVarItemID, outVarQuality;
    s32 resultItemID, resultQuality;
    s32 inputIdxA, inputIdxB;
    s32 recipeIdx;
    s32 resultIdx;
    s32 i;

    outVarItemID = *args++;
    outVarQuality = *args++;
    inputItemA = evt_get_variable(script, *args++);
    inputItemB = evt_get_variable(script, *args++);
    inputIdxA = 0;
    for (inputIdxA = 0; inputIdxA < I_END; inputIdxA++) {
        if (CookingIngredients[inputIdxA] == inputItemA) {
            break;
        }
    }
    for (inputIdxB = 0; inputIdxB < I_END; inputIdxB++) {
        if (CookingIngredients[inputIdxB] == inputItemB) {
            break;
        }
    }
    // check the recipe matrix
    resultIdx = 0;
    if ((inputIdxA < I_END) && (inputIdxB < I_END)) {
        if (inputIdxA < inputIdxB) {
            recipeIdx = inputIdxB + (inputIdxA * I_END);
        } else {
            recipeIdx = inputIdxA + (inputIdxB * I_END);
        }
        resultIdx = DoubleRecipesMatrix[recipeIdx];
    }
    if (resultIdx < 0) {
        resultIdx = 0;
    }
    // if the matrix was mistake or not in range, check the extra recipes
    if (resultIdx == 0) {
        for (i = 0; i < 8; i++) {
            if (((ExtraDoubleRecipes[i].inputA == inputItemA) && (ExtraDoubleRecipes[i].inputB == inputItemB))
             || ((ExtraDoubleRecipes[i].inputA == inputItemB) && (ExtraDoubleRecipes[i].inputB == inputItemA))) {
                resultIdx = ExtraDoubleRecipes[i].output;
            }
        }
    }
    result = &CookingResults[resultIdx];
    resultItemID = result->itemID;
    resultQuality = result->quality;
    evt_set_variable(script, outVarItemID, resultItemID);
    evt_set_variable(script, outVarQuality, resultQuality);
    return ApiStatus_DONE2;
}

const s32 CookableItemIDs[] = {
    ITEM_SPICY_SOUP,
    ITEM_APPLE_PIE,
    ITEM_HONEY_ULTRA,
    ITEM_MAPLE_ULTRA,
    ITEM_JELLY_ULTRA,
    ITEM_KOOPASTA,
    ITEM_FRIED_SHROOM,
    ITEM_SHROOM_CAKE,
    ITEM_SHROOM_STEAK,
    ITEM_HOT_SHROOM,
    ITEM_SWEET_SHROOM,
    ITEM_BLAND_MEAL,
    ITEM_YUMMY_MEAL,
    ITEM_DELUXE_FEAST,
    ITEM_SPECIAL_SHAKE,
    ITEM_HEALTHY_JUICE,
    ITEM_BIG_COOKIE,
    ITEM_CAKE,
    ITEM_MISTAKE,
    ITEM_KOOPA_TEA,
    ITEM_HONEY_SUPER,
    ITEM_MAPLE_SUPER,
    ITEM_JELLY_SUPER,
    ITEM_SPAGHETTI,
    ITEM_EGG_MISSILE,
    ITEM_FRIED_EGG,
    ITEM_HONEY_SHROOM,
    ITEM_HONEY_CANDY,
    ITEM_ELECTRO_POP,
    ITEM_FIRE_POP,
    ITEM_LIME_CANDY,
    ITEM_COCO_POP,
    ITEM_LEMON_CANDY,
    ITEM_JELLY_POP,
    ITEM_STRANGE_CAKE,
    ITEM_KOOKY_COOKIE,
    ITEM_FROZEN_FRIES,
    ITEM_POTATO_SALAD,
    ITEM_NUTTY_CAKE,
    ITEM_MAPLE_SHROOM,
    ITEM_BOILED_EGG,
    ITEM_YOSHI_COOKIE,
    ITEM_JELLY_SHROOM1,
    ITEM_TASTY_TONIC,
    ITEM_DIZZY_DIAL,
    ITEM_SUPER_SODA,
    ITEM_REPEL_GEL,
    ITEM_LIFE_SHROOM,
    ITEM_VOLT_SHROOM,
    ITEM_SLEEPY_SHEEP,
    ITEM_THUNDER_RAGE,
    ITEM_FIRE_FLOWER,
};

const s32 CookableDiscoveredFlags[] = {
    GF_MAC02_DiscoveredRecipe_00, GF_MAC02_DiscoveredRecipe_01, GF_MAC02_DiscoveredRecipe_02, GF_MAC02_DiscoveredRecipe_03, GF_MAC02_DiscoveredRecipe_04, GF_MAC02_DiscoveredRecipe_05, GF_MAC02_DiscoveredRecipe_06, GF_MAC02_DiscoveredRecipe_07,
    GF_MAC02_DiscoveredRecipe_08, GF_MAC02_DiscoveredRecipe_09, GF_MAC02_DiscoveredRecipe_0A, GF_MAC02_DiscoveredRecipe_0B, GF_MAC02_DiscoveredRecipe_0C, GF_MAC02_DiscoveredRecipe_0D, GF_MAC02_DiscoveredRecipe_0E, GF_MAC02_DiscoveredRecipe_0F,
    GF_MAC02_DiscoveredRecipe_10, GF_MAC02_DiscoveredRecipe_11, GF_MAC02_DiscoveredRecipe_12, GF_MAC02_DiscoveredRecipe_13, GF_MAC02_DiscoveredRecipe_14, GF_MAC02_DiscoveredRecipe_15, GF_MAC02_DiscoveredRecipe_16, GF_MAC02_DiscoveredRecipe_17,
    GF_MAC02_DiscoveredRecipe_18, GF_MAC02_DiscoveredRecipe_19, GF_MAC02_DiscoveredRecipe_1A, GF_MAC02_DiscoveredRecipe_1B, GF_MAC02_DiscoveredRecipe_1C, GF_MAC02_DiscoveredRecipe_1D, GF_MAC02_DiscoveredRecipe_1E, GF_MAC02_DiscoveredRecipe_1F,
    GF_MAC02_DiscoveredRecipe_20, GF_MAC02_DiscoveredRecipe_21, GF_MAC02_DiscoveredRecipe_22, GF_MAC02_DiscoveredRecipe_23, GF_MAC02_DiscoveredRecipe_24, GF_MAC02_DiscoveredRecipe_25, GF_MAC02_DiscoveredRecipe_26, GF_MAC02_DiscoveredRecipe_27,
    GF_MAC02_DiscoveredRecipe_28, GF_MAC02_DiscoveredRecipe_29, GF_MAC02_DiscoveredRecipe_2A, GF_MAC02_DiscoveredRecipe_2B, GF_MAC02_DiscoveredRecipe_2C, GF_MAC02_DiscoveredRecipe_2D, GF_MAC02_DiscoveredRecipe_2E, GF_MAC02_DiscoveredRecipe_2F,
    GF_MAC02_DiscoveredRecipe_30, GF_MAC02_DiscoveredRecipe_31, GF_MAC02_DiscoveredRecipe_32, GF_MAC02_DiscoveredRecipe_33 
};

API_CALLABLE(N(SetRecipeDiscovered)) {
    s32 cookedItems[ARRAY_COUNT(CookableItemIDs)];
    s32 cookedFlags[ARRAY_COUNT(CookableDiscoveredFlags)];
    s32 cookedItemID;
    s32 i;

    cookedItemID = evt_get_variable(script, *script->ptrReadPos);
    memcpy(cookedItems, CookableItemIDs, sizeof(CookableItemIDs));
    memcpy(cookedFlags, CookableDiscoveredFlags, sizeof(CookableDiscoveredFlags));

    for (i = 0; i < ARRAY_COUNT(CookableItemIDs); i++) {
        if (cookedItemID == cookedItems[i]) {
            evt_set_variable(NULL, cookedFlags[i], 1);
            break;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetItemCount)) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_count());
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckItemsHasRoom)) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_empty_count());
    return ApiStatus_DONE2;
}

static s32 N(TayceT_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];

API_CALLABLE(N(TayceT_MakeItemList)) {
    s32 i;

    for (i = 0; i < ITEM_NUM_CONSUMABLES; i++) {
        N(TayceT_ItemChoiceList)[i] = i + ITEM_FIRST_CONSUMABLE;
    }
    N(TayceT_ItemChoiceList)[i] = ITEM_NONE;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_TayceTCooking) = {
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -220, -425, 30)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Cooking)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Cooking, ANIM_TayceT_Cooking, 5, MSG_MAC_Bridge_000E)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_TurnBack)
    EVT_WAIT(30)
    EVT_CALL(SetNpcYaw, NPC_TayceT, 90)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -236, -318, 20)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_100, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_FryingPan)[] = {
    ITEM_FRYING_PAN,
    ITEM_NONE
};

EvtScript N(EVS_TayceT_FryingPanAndCake) = {
    EVT_IF_EQ(GF_MAC02_TayceT_HoldingCake, TRUE)
        EVT_CALL(N(CheckItemsHasRoom), LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
            EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
            EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
            EVT_SET(GF_MAC02_TayceT_HoldingCake, TRUE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0017)
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_FryingPan))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0018)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_TalkHappy, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0019)
            EVT_EXEC_WAIT(N(EVS_Scene_TayceTCooking))
            EVT_CALL(N(CheckItemsHasRoom), LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
                EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
                EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
                EVT_SET(GF_MAC02_TayceT_HoldingCake, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Cookbook)[] = {
    ITEM_COOKBOOK,
    ITEM_NONE 
};

EvtScript N(EVS_TayceT_RequestCookbook) = {
    EVT_IF_EQ(AF_MAC_01, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001D)
        EVT_SET(AF_MAC_01, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001E)
        EVT_SET(AF_MAC_01, FALSE)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Cookbook)))
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001F)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0020)
            EVT_SET(GF_MAC02_TayceT_HasCookbook, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TayceT_Cook) = {
    #define LABEL_CHOOSE_FIRST 1
    #define LABEL_CHOOSE_SECOND 2
    #define LABEL_CONFIRM_ONE 5
    #define LABEL_COOK 6
    #define LABEL_DONE 9

   // greeting and opening choice
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_MAC02_Met_TayceT, FALSE)
        EVT_SET(GF_MAC02_Met_TayceT, TRUE)
        EVT_SET(AF_MAC_01, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0000)
    EVT_ELSE
        EVT_IF_EQ(AF_MAC_01, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0001)
            EVT_SET(AF_MAC_01, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0002)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(GetItemCount), LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0003)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0005)

   // choose the first ingredient
    EVT_LABEL(LABEL_CHOOSE_FIRST)
    EVT_SET(LVar3, 0)
    EVT_CALL(N(TayceT_MakeItemList))
    EVT_CHOOSE_CONSUMABLE_FROM(N(TayceT_ItemChoiceList), 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0006)
            EVT_CALL(ShowChoice, MSG_Choice_0009)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                EVT_GOTO(LABEL_DONE)
            EVT_END_IF
            EVT_CALL(CloseMessage)
            EVT_SET(LVar3, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar8, LVar0)
            EVT_CALL(AddItem, LVar0, LVar1)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar3, 1)
        EVT_GOTO(LABEL_CHOOSE_FIRST)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC02_TayceT_HasCookbook, FALSE)
        EVT_GOTO(LABEL_CONFIRM_ONE)
    EVT_END_IF
    EVT_CALL(N(GetItemCount), LVar0)
    EVT_IF_LT(LVar0, 2)
        EVT_GOTO(LABEL_CONFIRM_ONE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0007)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_CALL(CloseMessage)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(LABEL_CONFIRM_ONE)
    EVT_END_IF

    // choose the second ingredient
    EVT_LABEL(LABEL_CHOOSE_SECOND)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_SET(LVar3, 0)
    EVT_CALL(N(TayceT_MakeItemList))
    EVT_CHOOSE_CONSUMABLE_FROM(N(TayceT_ItemChoiceList), 0)
    EVT_CALL(AddItem, LVar8, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0008)
            EVT_CALL(ShowChoice, MSG_Choice_0008)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(CloseMessage)
                EVT_GOTO(LABEL_CONFIRM_ONE)
            EVT_END_IF
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                EVT_GOTO(LABEL_DONE)
            EVT_END_IF
            EVT_CALL(CloseMessage)
            EVT_SET(LVar3, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar9, LVar0)
            EVT_CALL(AddItem, LVar0, LVar1)
            EVT_IF_EQ(LVar8, LVar9)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0009)
                EVT_SET(LVar3, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_EQ(LVar3, 1)
        EVT_GOTO(LABEL_CHOOSE_SECOND)
    EVT_END_IF

    // confirm cooking with two ingredients
    // no label here, but this position would be LABEL_CONFIRM_TWO
    EVT_SET(LVar0, LVar8)
    EVT_CALL(N(GetItemName), LVar0)
    EVT_CALL(SetMessageMsg, LVar0, 0)
    EVT_SET(LVar1, LVar9)
    EVT_CALL(N(GetItemName), LVar1)
    EVT_CALL(SetMessageMsg, LVar1, 1)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000B)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(N(GetCookResultForDoubleRecipe), LVar6, LVar7, LVar8, LVar9)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_CALL(RemoveItem, LVar9, LVar0)
    EVT_GOTO(LABEL_COOK)

    // confirm cooking with one ingredient
    EVT_LABEL(LABEL_CONFIRM_ONE)
    EVT_SET(LVar0, LVar8)
    EVT_CALL(N(GetItemName), LVar0)
    EVT_CALL(SetMessageMsg, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000A)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(func_80242C44_825F04, LVar6, LVar7, LVar8, GF_MAC02_TayceT_HasCookbook)
    EVT_CALL(RemoveItem, LVar8, LVar0)

    // the actual cooking animation and reaction message
    EVT_LABEL(LABEL_COOK)
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000D)
    EVT_EXEC_WAIT(N(EVS_Scene_TayceTCooking))
    EVT_SWITCH(LVar7)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0012)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000F)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0010)
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0013)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0011)
    EVT_END_SWITCH
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0014)
    EVT_CALL(N(SetRecipeDiscovered), LVar6)
    EVT_GIVE_CONSUMABLE_REWARD_ALT(LVar6)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0015)

    // end the script
    EVT_LABEL(LABEL_DONE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TayceT) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_EXEC_WAIT(N(EVS_TayceT_FryingPanAndCake))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_COOKBOOK, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_EXEC_WAIT(N(EVS_TayceT_Cook))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_TayceT_RequestCookbook))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TayceT) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TayceT)))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 45, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, -236, 20, -318)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_Idle)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_IF_NE(GF_MAC02_TayceT_HoldingCake, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_IdleSad)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_MAC_01, FALSE)
    EVT_RETURN
    EVT_END
};
