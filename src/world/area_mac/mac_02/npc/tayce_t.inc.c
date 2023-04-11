#include "gcc/string.h"

// enum mapping itemIDs -> index in single recipe arrays and column/rows in double recipe matrix
enum CookingIngredientID {
    iRSH = 0,   // ITEM_MUSHROOM
    iSSH = 1,   // ITEM_SUPER_SHROOM
    iUSH = 2,   // ITEM_ULTRA_SHROOM
    iLSH = 3,   // ITEM_LIFE_SHROOM
    iVSH = 4,   // ITEM_VOLT_SHROOM
    iFFL = 5,   // ITEM_FIRE_FLOWER
    iCOC = 6,   // ITEM_COCONUT
    iLIM = 7,   // ITEM_LIME
    iLEM = 8,   // ITEM_LEMON
    iHSY = 9,   // ITEM_HONEY_SYRUP
    iMSY = 10,  // ITEM_MAPLE_SYRUP
    iJAM = 11,  // ITEM_JAMMIN_JELLY
    iAPP = 12,  // ITEM_APPLE
    iRBY = 13,  // ITEM_RED_BERRY
    iBBY = 14,  // ITEM_BLUE_BERRY
    iYBY = 15,  // ITEM_YELLOW_BERRY
    iGMN = 16,  // ITEM_GOOMNUT
    iKLF = 17,  // ITEM_KOOPA_LEAF
    iDRP = 18,  // ITEM_DRIED_PASTA
    iDRF = 19,  // ITEM_DRIED_FRUIT
    iSLF = 20,  // ITEM_STRANGE_LEAF
    iMIX = 21,  // ITEM_CAKE_MIX
    iEGG = 22,  // ITEM_EGG
    iMEL = 23,  // ITEM_MELON
    iSTK = 24,  // ITEM_STINKY_HERB
    iPOT = 25,  // ITEM_ICED_POTATO
    iDSH = 26,  // ITEM_DRIED_SHROOM
    iBUB = 27,  // ITEM_BUBBLE_BERRY
    iBMP = 28,  // ITEM_WHACKAS_BUMP
    INPUT_END = 29,
};

// enum mapping cooking result to itemID/quality rating
enum CookingResultID {
    rXXX = 0,   // ITEM_MISTAKE
    rFRS = 1,   // ITEM_FRIED_SHROOM
    rSPS = 2,   // ITEM_SPICY_SOUP
    rTTN = 3,   // ITEM_TASTY_TONIC
    rNUT = 4,   // ITEM_NUTTY_CAKE
    rTEA = 5,   // ITEM_KOOPA_TEA
    rSPG = 6,   // ITEM_SPAGHETTI
    rDZD = 7,   // ITEM_DIZZY_DIAL
    rBCK = 8,   // ITEM_BIG_COOKIE
    rCAK = 9,   // ITEM_CAKE
    rFEG = 10,  // ITEM_FRIED_EGG
    rBEG = 11,  // ITEM_BOILED_EGG
    rSOD = 12,  // ITEM_SUPER_SODA
    rYCK = 13,  // ITEM_YOSHI_COOKIE
    rDLX = 14,  // ITEM_DELUXE_FEAST
    rFZF = 15,  // ITEM_FROZEN_FRIES
    rPOT = 16,  // ITEM_POTATO_SALAD
    rHOT = 17,  // ITEM_HOT_SHROOM
    rBLN = 18,  // ITEM_BLAND_MEAL
    rHSH = 19,  // ITEM_HONEY_SHROOM
    rMSH = 20,  // ITEM_MAPLE_SHROOM
    rJSH = 21,  // ITEM_JELLY_SHROOM1
    rLSH = 22,  // ITEM_LIFE_SHROOM
    rVSH = 23,  // ITEM_VOLT_SHROOM
    rSLS = 24,  // ITEM_SLEEPY_SHEEP
    rSHC = 25,  // ITEM_SHROOM_CAKE
    rSHS = 26,  // ITEM_SHROOM_STEAK
    rHSU = 27,  // ITEM_HONEY_SUPER
    rMSU = 28,  // ITEM_MAPLE_SUPER
    rJSU = 29,  // ITEM_JELLY_SUPER
    rYUM = 30,  // ITEM_YUMMY_MEAL
    rHUL = 31,  // ITEM_HONEY_ULTRA
    rMUL = 32,  // ITEM_MAPLE_ULTRA
    rJUL = 33,  // ITEM_JELLY_ULTRA
    rSWS = 34,  // ITEM_SWEET_SHROOM
    rELP = 35,  // ITEM_ELECTRO_POP
    rTHR = 36,  // ITEM_THUNDER_RAGE
    rFIP = 37,  // ITEM_FIRE_POP
    rEGM = 38,  // ITEM_EGG_MISSILE
    rSSH = 39,  // ITEM_SPECIAL_SHAKE
    rCOP = 40,  // ITEM_COCO_POP
    rJUI = 41,  // ITEM_HEALTHY_JUICE
    rLIC = 42,  // ITEM_LIME_CANDY
    rLEC = 43,  // ITEM_LEMON_CANDY
    rHNC = 44,  // ITEM_HONEY_CANDY
    rJLP = 45,  // ITEM_JELLY_POP
    rPIE = 46,  // ITEM_APPLE_PIE
    rKOO = 47,  // ITEM_KOOPASTA
    rKCK = 48,  // ITEM_KOOKY_COOKIE
    rFFL = 49,  // ITEM_FIRE_FLOWER
    rSTR = 50,  // ITEM_STRANGE_CAKE
    RESULT_END = 51,
};

enum CookingResultQuality {
    QUALITY_BAD     = 0,
    QUALITY_OK      = 1,
    QUALITY_GOOD    = 2,
    QUALITY_GREAT   = 3,
    QUALITY_ODD     = 4,
};

s32 CookingIngredients[] = {
    [iRSH] ITEM_MUSHROOM,
    [iSSH] ITEM_SUPER_SHROOM,
    [iUSH] ITEM_ULTRA_SHROOM,
    [iLSH] ITEM_LIFE_SHROOM,
    [iVSH] ITEM_VOLT_SHROOM,
    [iFFL] ITEM_FIRE_FLOWER,
    [iCOC] ITEM_COCONUT,
    [iLIM] ITEM_LIME,
    [iLEM] ITEM_LEMON,
    [iHSY] ITEM_HONEY_SYRUP,
    [iMSY] ITEM_MAPLE_SYRUP,
    [iJAM] ITEM_JAMMIN_JELLY,
    [iAPP] ITEM_APPLE,
    [iRBY] ITEM_RED_BERRY,
    [iBBY] ITEM_BLUE_BERRY,
    [iYBY] ITEM_YELLOW_BERRY,
    [iGMN] ITEM_GOOMNUT,
    [iKLF] ITEM_KOOPA_LEAF,
    [iDRP] ITEM_DRIED_PASTA,
    [iDRF] ITEM_DRIED_FRUIT,
    [iSLF] ITEM_STRANGE_LEAF,
    [iMIX] ITEM_CAKE_MIX,
    [iEGG] ITEM_EGG,
    [iMEL] ITEM_MELON,
    [iSTK] ITEM_STINKY_HERB,
    [iPOT] ITEM_ICED_POTATO,
    [iDSH] ITEM_DRIED_SHROOM,
    [iBUB] ITEM_BUBBLE_BERRY,
    [iBMP] ITEM_WHACKAS_BUMP,
    [INPUT_END] -1
};

typedef struct CookingResult {
    /* 00 */ s32 quality;
    /* 04 */ s32 itemID;
} CookingResult; // size = 0x8

CookingResult CookingResults[] = {
    [rXXX] { QUALITY_BAD,   ITEM_MISTAKE },
    [rFRS] { QUALITY_OK,    ITEM_FRIED_SHROOM },
    [rSPS] { QUALITY_OK,    ITEM_SPICY_SOUP },
    [rTTN] { QUALITY_OK,    ITEM_TASTY_TONIC },
    [rNUT] { QUALITY_OK,    ITEM_NUTTY_CAKE },
    [rTEA] { QUALITY_OK,    ITEM_KOOPA_TEA },
    [rSPG] { QUALITY_OK,    ITEM_SPAGHETTI },
    [rDZD] { QUALITY_ODD,   ITEM_DIZZY_DIAL },
    [rBCK] { QUALITY_GOOD,  ITEM_BIG_COOKIE },
    [rCAK] { QUALITY_OK,    ITEM_CAKE },
    [rFEG] { QUALITY_OK,    ITEM_FRIED_EGG },
    [rBEG] { QUALITY_OK,    ITEM_BOILED_EGG },
    [rSOD] { QUALITY_OK,    ITEM_SUPER_SODA },
    [rYCK] { QUALITY_OK,    ITEM_YOSHI_COOKIE },
    [rDLX] { QUALITY_GREAT, ITEM_DELUXE_FEAST },
    [rFZF] { QUALITY_OK,    ITEM_FROZEN_FRIES },
    [rPOT] { QUALITY_OK,    ITEM_POTATO_SALAD },
    [rHOT] { QUALITY_OK,    ITEM_HOT_SHROOM },
    [rBLN] { QUALITY_GOOD,  ITEM_BLAND_MEAL },
    [rHSH] { QUALITY_OK,    ITEM_HONEY_SHROOM },
    [rMSH] { QUALITY_OK,    ITEM_MAPLE_SHROOM },
    [rJSH] { QUALITY_OK,    ITEM_JELLY_SHROOM1 },
    [rLSH] { QUALITY_OK,    ITEM_LIFE_SHROOM },
    [rVSH] { QUALITY_OK,    ITEM_VOLT_SHROOM },
    [rSLS] { QUALITY_ODD,   ITEM_SLEEPY_SHEEP },
    [rSHC] { QUALITY_OK,    ITEM_SHROOM_CAKE },
    [rSHS] { QUALITY_OK,    ITEM_SHROOM_STEAK },
    [rHSU] { QUALITY_OK,    ITEM_HONEY_SUPER },
    [rMSU] { QUALITY_OK,    ITEM_MAPLE_SUPER },
    [rJSU] { QUALITY_OK,    ITEM_JELLY_SUPER },
    [rYUM] { QUALITY_GOOD,  ITEM_YUMMY_MEAL },
    [rHUL] { QUALITY_OK,    ITEM_HONEY_ULTRA },
    [rMUL] { QUALITY_OK,    ITEM_MAPLE_ULTRA },
    [rJUL] { QUALITY_OK,    ITEM_JELLY_ULTRA },
    [rSWS] { QUALITY_OK,    ITEM_SWEET_SHROOM },
    [rELP] { QUALITY_OK,    ITEM_ELECTRO_POP },
    [rTHR] { QUALITY_ODD,   ITEM_THUNDER_RAGE },
    [rFIP] { QUALITY_OK,    ITEM_FIRE_POP },
    [rEGM] { QUALITY_OK,    ITEM_EGG_MISSILE },
    [rSSH] { QUALITY_GOOD,  ITEM_SPECIAL_SHAKE },
    [rCOP] { QUALITY_OK,    ITEM_COCO_POP },
    [rJUI] { QUALITY_GREAT, ITEM_HEALTHY_JUICE },
    [rLIC] { QUALITY_OK,    ITEM_LIME_CANDY },
    [rLEC] { QUALITY_OK,    ITEM_LEMON_CANDY },
    [rHNC] { QUALITY_OK,    ITEM_HONEY_CANDY },
    [rJLP] { QUALITY_OK,    ITEM_JELLY_POP },
    [rPIE] { QUALITY_OK,    ITEM_APPLE_PIE },
    [rKOO] { QUALITY_OK,    ITEM_KOOPASTA },
    [rKCK] { QUALITY_OK,    ITEM_KOOKY_COOKIE },
    [rFFL] { QUALITY_ODD,   ITEM_FIRE_FLOWER },
    [rSTR] { QUALITY_GOOD,  ITEM_STRANGE_CAKE },
    [RESULT_END] { -1, -1 },
};

s8 SingleRecipesWithoutCookbook[] = {
    [iRSH] rFRS,    // ITEM_MUSHROOM      -->  ITEM_FRIED_SHROOM
    [iSSH] rFRS,    // ITEM_SUPER_SHROOM  -->  ITEM_FRIED_SHROOM
    [iUSH] rSHS,    // ITEM_ULTRA_SHROOM  -->  ITEM_SHROOM_STEAK
    [iLSH] rHOT,    // ITEM_LIFE_SHROOM   -->  ITEM_HOT_SHROOM
    [iVSH] rHOT,    // ITEM_VOLT_SHROOM   -->  ITEM_HOT_SHROOM
    [iFFL] rSPS,    // ITEM_FIRE_FLOWER   -->  ITEM_SPICY_SOUP
    [iCOC] rTTN,    // ITEM_COCONUT       -->  ITEM_TASTY_TONIC
    [iLIM] rTTN,    // ITEM_LIME          -->  ITEM_TASTY_TONIC
    [iLEM] rTTN,    // ITEM_LEMON         -->  ITEM_TASTY_TONIC
    [iHSY] rSOD,    // ITEM_HONEY_SYRUP   -->  ITEM_SUPER_SODA
    [iMSY] rSOD,    // ITEM_MAPLE_SYRUP   -->  ITEM_SUPER_SODA
    [iJAM] rSOD,    // ITEM_JAMMIN_JELLY  -->  ITEM_SUPER_SODA
    [iAPP] rSOD,    // ITEM_APPLE         -->  ITEM_SUPER_SODA
    [iRBY] rXXX,    // ITEM_RED_BERRY     -->  ITEM_MISTAKE
    [iBBY] rXXX,    // ITEM_BLUE_BERRY    -->  ITEM_MISTAKE
    [iYBY] rXXX,    // ITEM_YELLOW_BERRY  -->  ITEM_MISTAKE
    [iGMN] rNUT,    // ITEM_GOOMNUT       -->  ITEM_NUTTY_CAKE
    [iKLF] rTEA,    // ITEM_KOOPA_LEAF    -->  ITEM_KOOPA_TEA
    [iDRP] rSPG,    // ITEM_DRIED_PASTA   -->  ITEM_SPAGHETTI
    [iDRF] rXXX,    // ITEM_DRIED_FRUIT   -->  ITEM_MISTAKE
    [iSLF] rXXX,    // ITEM_STRANGE_LEAF  -->  ITEM_MISTAKE
    [iMIX] rCAK,    // ITEM_CAKE_MIX      -->  ITEM_CAKE
    [iEGG] rFEG,    // ITEM_EGG           -->  ITEM_FRIED_EGG
    [iMEL] rSSH,    // ITEM_MELON         -->  ITEM_SPECIAL_SHAKE
    [iSTK] rXXX,    // ITEM_STINKY_HERB   -->  ITEM_MISTAKE
    [iPOT] rPOT,    // ITEM_ICED_POTATO   -->  ITEM_POTATO_SALAD
    [iDSH] rXXX,    // ITEM_DRIED_SHROOM  -->  ITEM_MISTAKE
    [iBUB] rXXX,    // ITEM_BUBBLE_BERRY  -->  ITEM_MISTAKE
    [iBMP] rXXX,    // ITEM_WHACKAS_BUMP  -->  ITEM_MISTAKE
};

// items with (*) are upgraded from ITEM_MISTAKE when using the cookbook
s8 SingleRecipesWithCookbook[] = {
    [iRSH] rFRS,    // ITEM_MUSHROOM      -->  ITEM_FRIED_SHROOM
    [iSSH] rFRS,    // ITEM_SUPER_SHROOM  -->  ITEM_FRIED_SHROOM
    [iUSH] rSHS,    // ITEM_ULTRA_SHROOM  -->  ITEM_SHROOM_STEAK
    [iLSH] rHOT,    // ITEM_LIFE_SHROOM   -->  ITEM_HOT_SHROOM
    [iVSH] rHOT,    // ITEM_VOLT_SHROOM   -->  ITEM_HOT_SHROOM
    [iFFL] rSPS,    // ITEM_FIRE_FLOWER   -->  ITEM_SPICY_SOUP
    [iCOC] rTTN,    // ITEM_COCONUT       -->  ITEM_TASTY_TONIC
    [iLIM] rTTN,    // ITEM_LIME          -->  ITEM_TASTY_TONIC
    [iLEM] rTTN,    // ITEM_LEMON         -->  ITEM_TASTY_TONIC
    [iHSY] rSOD,    // ITEM_HONEY_SYRUP   -->  ITEM_SUPER_SODA
    [iMSY] rSOD,    // ITEM_MAPLE_SYRUP   -->  ITEM_SUPER_SODA
    [iJAM] rSOD,    // ITEM_JAMMIN_JELLY  -->  ITEM_SUPER_SODA
    [iAPP] rSOD,    // ITEM_APPLE         -->  ITEM_SUPER_SODA
    [iRBY] rSOD,    // ITEM_RED_BERRY     -->  ITEM_SUPER_SODA      (*)
    [iBBY] rSOD,    // ITEM_BLUE_BERRY    -->  ITEM_SUPER_SODA      (*)
    [iYBY] rSOD,    // ITEM_YELLOW_BERRY  -->  ITEM_SUPER_SODA      (*)
    [iGMN] rNUT,    // ITEM_GOOMNUT       -->  ITEM_NUTTY_CAKE
    [iKLF] rTEA,    // ITEM_KOOPA_LEAF    -->  ITEM_KOOPA_TEA
    [iDRP] rSPG,    // ITEM_DRIED_PASTA   -->  ITEM_SPAGHETTI
    [iDRF] rXXX,    // ITEM_DRIED_FRUIT   -->  ITEM_MISTAKE
    [iSLF] rDZD,    // ITEM_STRANGE_LEAF  -->  ITEM_DIZZY_DIAL      (*)
    [iMIX] rCAK,    // ITEM_CAKE_MIX      -->  ITEM_CAKE
    [iEGG] rFEG,    // ITEM_EGG           -->  ITEM_FRIED_EGG
    [iMEL] rSSH,    // ITEM_MELON         -->  ITEM_SPECIAL_SHAKE
    [iSTK] rXXX,    // ITEM_STINKY_HERB   -->  ITEM_MISTAKE
    [iPOT] rPOT,    // ITEM_ICED_POTATO   -->  ITEM_POTATO_SALAD
    [iDSH] rFRS,    // ITEM_DRIED_SHROOM  -->  ITEM_FRIED_SHROOM    (*)
    [iBUB] rTTN,    // ITEM_BUBBLE_BERRY  -->  ITEM_TASTY_TONIC     (*)
    [iBMP] rYUM,    // ITEM_WHACKAS_BUMP  -->  ITEM_YUMMY_MEAL      (*)
};

s8 DoubleRecipesMatrix[] = {
/*          iRSH  iSSH  iUSH  iLSH  iVSH  iFFL  iCOC  iLIM  iLEM  iHSY  iMSY  iJAM  iAPP  iRBY  iBBY  iYBY  iGMN  iKLF  iDRP  iDRF  iSLF  iMIX  iEGG  iMEL  iSTK  iPOT  iDSH  iBUB  iBMP */
/* iRSH */  rXXX, rHOT, rSHS, rSHS, rHOT, rHOT, rXXX, rXXX, rXXX, rHSH, rMSH, rJSH, rXXX, rXXX, rXXX, rXXX, rVSH, rVSH, rBLN, rVSH, rVSH, rSHC, rBLN, rXXX, rXXX, rBLN, rFRS, rXXX, rXXX,
/* iSSH */    -1, rXXX, rSHS, rSHS, rHOT, rBLN, rXXX, rXXX, rXXX, rHSU, rMSU, rJSU, rXXX, rXXX, rXXX, rXXX, rLSH, rLSH, rBLN, rVSH, rLSH, rSHC, rBLN, rXXX, rXXX, rBLN, rHOT, rXXX, rXXX,
/* iUSH */    -1,   -1, rXXX, rSHS, rSHS, rYUM, rXXX, rXXX, rXXX, rHUL, rMUL, rJUL, rXXX, rXXX, rXXX, rXXX, rLSH, rLSH, rYUM, rVSH, rLSH, rSWS, rYUM, rXXX, rXXX, rYUM, rSHS, rXXX, rXXX,
/* iLSH */    -1,   -1,   -1, rXXX, rXXX, rBLN, rXXX, rXXX, rXXX, rHSU, rMSU, rJSU, rXXX, rXXX, rXXX, rXXX, rLSH, rLSH, rBLN, rVSH, rLSH, rSWS, rBLN, rXXX, rXXX, rBLN, rSHS, rXXX, rXXX,
/* iVSH */    -1,   -1,   -1,   -1, rXXX, rBLN, rXXX, rXXX, rXXX, rHSU, rMSU, rJSU, rXXX, rXXX, rXXX, rXXX, rLSH, rLSH, rBLN, rTHR, rDZD, rELP, rBLN, rXXX, rXXX, rBLN, rHOT, rXXX, rXXX,
/* iFFL */    -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rBLN, rXXX, rXXX, rXXX, rXXX, rFIP, rEGM, rXXX, rXXX, rFZF, rFRS, rXXX, rXXX,
/* iCOC */    -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rXXX, rTTN, rSOD, rSSH, rSOD, rSOD, rSOD, rSOD, rXXX, rSOD, rBLN, rXXX, rXXX, rCOP, rXXX, rSOD, rXXX, rBLN, rXXX, rXXX, rXXX,
/* iLIM */    -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSOD, rTTN, rSOD, rSSH, rSOD, rSOD, rSOD, rSOD, rXXX, rSOD, rXXX, rXXX, rXXX, rLIC, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iLEM */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rTTN, rSOD, rSSH, rSOD, rSOD, rSOD, rSOD, rXXX, rSOD, rXXX, rXXX, rXXX, rLEC, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iHSY */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSOD, rSSH, rTTN, rTTN, rTTN, rTTN, rXXX, rSOD, rXXX, rXXX, rXXX, rHNC, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iMSY */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSSH, rSOD, rSOD, rSOD, rSOD, rXXX, rSOD, rXXX, rXXX, rXXX, rKCK, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iJAM */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSSH, rSSH, rSSH, rSSH, rXXX, rSOD, rXXX, rXXX, rXXX, rJLP, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iAPP */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSOD, rSOD, rSOD, rXXX, rXXX, rXXX, rXXX, rXXX, rPIE, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iRBY */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSOD, rSOD, rXXX, rBLN, rBLN, rXXX, rSLS, rBCK, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iBBY */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSOD, rXXX, rBLN, rBLN, rXXX, rSLS, rBCK, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iYBY */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rBLN, rBLN, rXXX, rSLS, rBCK, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iGMN */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rBLN, rBLN, rXXX, rBLN, rBCK, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iKLF */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rKOO, rXXX, rXXX, rKCK, rXXX, rSSH, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iDRP */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rYUM, rBLN, rXXX, rBLN, rXXX, rXXX, rBLN, rXXX, rXXX, rXXX,
/* iDRF */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rFFL, rXXX, rXXX, rXXX, rXXX, rYUM, rXXX, rXXX, rXXX,
/* iSLF */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rSTR, rBEG, rSSH, rDZD, rYUM, rXXX, rXXX, rXXX,
/* iMIX */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rBCK, rYCK, rKCK, rBLN, rXXX, rXXX, rXXX,
/* iEGG */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rBEG, rBLN, rXXX, rXXX, rXXX,
/* iMEL */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iSTK */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rXXX, rXXX, rXXX,
/* iPOT */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rXXX, rXXX,
/* iDSH */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX, rXXX,
/* iBUB */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX, rXXX,
/* iBMP */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, rXXX,
};

typedef struct ExtraCookingPair {
    /* 00 */ s32 inputA;
    /* 04 */ s32 inputB;
    /* 04 */ s32 output;
} ExtraCookingPair; // size = 0x8

// additional recipes checked for inputs not included in the matrix
ExtraCookingPair ExtraDoubleRecipes[] = {
    { ITEM_SPECIAL_SHAKE, ITEM_DRIED_SHROOM,  rJUI }, // --> ITEM_HEALTHY_JUICE
    { ITEM_SPECIAL_SHAKE, ITEM_STRANGE_LEAF,  rJUI }, // --> ITEM_HEALTHY_JUICE
    { ITEM_SPECIAL_SHAKE, ITEM_STINKY_HERB,   rJUI }, // --> ITEM_HEALTHY_JUICE
    { ITEM_POTATO_SALAD,  ITEM_SPAGHETTI,     rYUM }, // --> ITEM_YUMMY_MEAL
    { ITEM_POTATO_SALAD,  ITEM_FRIED_SHROOM,  rBLN }, // --> ITEM_BLAND_MEAL
    { ITEM_POTATO_SALAD,  ITEM_HOT_SHROOM,    rYUM }, // --> ITEM_YUMMY_MEAL
    { ITEM_POTATO_SALAD,  ITEM_SHROOM_STEAK,  rDLX }, // --> ITEM_DELUXE_FEAST
    { ITEM_STRANGE_LEAF,  ITEM_WHACKAS_BUMP,  rDLX }, // --> ITEM_DELUXE_FEAST
};

// when cooking a mystery, theres is a 50% chance to create ITEM_MISTAKE, and a 50% chance to select
// any one of these outcomes with equal probability
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

API_CALLABLE(N(GetCookResultForSingleRecipe)) {
    Bytecode* args = script->ptrReadPos;
    s32 hasCookbook;
    s32 inputItem;
    s32 outVarItemID;
    s32 outVarQuality;
    s32 resultItemID;
    s32 resultQuality;
    s32 i;

    outVarItemID = *args++;
    outVarQuality = *args++;
    inputItem = evt_get_variable(script, *args++);
    hasCookbook = evt_get_variable(script, *args++);

    if (inputItem == ITEM_MYSTERY) {
        if (rand_int(1000) < 500) {
            resultItemID = ITEM_MISTAKE;
            resultQuality = 0;
        } else {
            i = rand_int(10000) % ARRAY_COUNT(MysteryResultOptions);
            resultItemID = MysteryResultOptions[i];
            resultQuality = 4;
        }
    } else {
        for (i = 0; i < INPUT_END; i++) {
            if (CookingIngredients[i] == inputItem) {
                break;
            }
        }
        if (i < INPUT_END) {
            if (hasCookbook) {
                i = SingleRecipesWithCookbook[i];
            } else {
                i = SingleRecipesWithoutCookbook[i];
            }
        } else {
            i = 0;
        }
        resultQuality = CookingResults[i].quality;
        resultItemID = CookingResults[i].itemID;
    }
    evt_set_variable(script, outVarItemID, resultItemID);
    evt_set_variable(script, outVarQuality, resultQuality);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetCookResultForDoubleRecipe)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVarItemID = *args++;
    s32 outVarQuality = *args++;
    s32 inputItemA = evt_get_variable(script, *args++);
    s32 inputItemB = evt_get_variable(script, *args++);
    ExtraCookingPair* extraList;
    s32 resultItemID, resultQuality;
    s32 inputIdxA, inputIdxB;
    s32 recipeIdx;
    s32 resultIdx;
    s32 i;

    // get ingredient enum values
    for (inputIdxA = 0; inputIdxA < INPUT_END; inputIdxA++) {
        if (CookingIngredients[inputIdxA] == inputItemA) {
            break;
        }
    }
    for (inputIdxB = 0; inputIdxB < INPUT_END; inputIdxB++) {
        if (CookingIngredients[inputIdxB] == inputItemB) {
            break;
        }
    }
    // check the recipe matrix
    resultIdx = 0;
    if ((inputIdxA < INPUT_END) && (inputIdxB < INPUT_END)) {
        if (inputIdxA < inputIdxB) {
            recipeIdx = inputIdxB + (inputIdxA * INPUT_END);
        } else {
            recipeIdx = inputIdxA + (inputIdxB * INPUT_END);
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
    resultItemID = CookingResults[resultIdx].itemID;
    resultQuality = CookingResults[resultIdx].quality;
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
            evt_set_variable(NULL, cookedFlags[i], TRUE);
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
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -220, -425, 30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Cooking)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Cooking, ANIM_TayceT_Cooking, 5, MSG_MAC_Bridge_000E)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_TurnBack)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcYaw, NPC_TayceT, 90)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -236, -318, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
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
    EVT_CALL(SetMessageText, LVar0, 0)
    EVT_SET(LVar1, LVar9)
    EVT_CALL(N(GetItemName), LVar1)
    EVT_CALL(SetMessageText, LVar1, 1)
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
    EVT_CALL(SetMessageText, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000A)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_CALL(N(GetCookResultForSingleRecipe), LVar6, LVar7, LVar8, GF_MAC02_TayceT_HasCookbook)
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
