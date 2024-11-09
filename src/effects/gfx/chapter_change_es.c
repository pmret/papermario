#include "include_asset.h"

INCLUDE_IMG("effects/gfx/es/world/ch0.png", D_PAL_09000000_43E980);
INCLUDE_IMG("effects/gfx/es/D_PAL_09000B40_43F4C0.png", D_PAL_09000B40_43F4C0);
INCLUDE_IMG("effects/gfx/es/world/text_chapter.png", D_PAL_09001680_440000);
INCLUDE_IMG("effects/gfx/es/D_PAL_09001B80_440500.png", D_PAL_09001B80_440500);
INCLUDE_IMG("effects/gfx/es/D_PAL_09002080_440A00.png", D_PAL_09002080_440A00);
INCLUDE_IMG("effects/gfx/es/D_PAL_09002580_440F00.png", D_PAL_09002580_440F00);
INCLUDE_IMG("effects/gfx/es/world/text_end_of.png", D_PAL_09002A80_441400);
INCLUDE_IMG("effects/gfx/es/world/exclamation_point.png", D_PAL_09003AC0_442440);
INCLUDE_IMG("effects/gfx/es/world/ch1.png", D_PAL_09003D40_4426C0);
INCLUDE_IMG("effects/gfx/es/world/ch2.png", D_PAL_09004D40_4436C0);
INCLUDE_IMG("effects/gfx/es/world/ch3.png", D_PAL_09005D40_4446C0);
INCLUDE_IMG("effects/gfx/es/world/ch4.png", D_PAL_09006D40_4456C0);
INCLUDE_IMG("effects/gfx/es/world/ch5.png", D_PAL_09007D40_4466C0);
INCLUDE_IMG("effects/gfx/es/world/ch6.png", D_PAL_09008D40_4476C0);
INCLUDE_IMG("effects/gfx/es/world/ch7.png", D_PAL_09009D40_4486C0);
INCLUDE_IMG("effects/gfx/es/world/ch8.png", D_PAL_0900AD40_4496C0);
INCLUDE_IMG("effects/gfx/es/world/chapter_rainbow.png", D_PAL_0900BD40_44A6C0);

#include "effects/gfx/es/D_PAL_0900BE40_44A7C0.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900BE88_44A808.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900BED0_44A850.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900BF18_44A898.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900BF60_44A8E0.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900BFA8_44A928.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900BFF0_44A970.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C038_44A9B8.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C080_44AA00.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C168_44AAE8.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C1B0_44AB30.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C1F8_44AB78.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C240_44ABC0.gfx.inc.c"

//#include "effects/gfx/es/D_PAL_0900C328_44ACA8.gfx.inc.c"
Gfx D_PAL_0900C328_44ACA8[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile(&D_PAL_09002A80_441400[0x820], G_IM_FMT_IA, G_IM_SIZ_8b, 104, 0, 0, 0, 103, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

#include "effects/gfx/es/D_PAL_0900C370_44ACF0.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C458_44ADD8.gfx.inc.c"
#include "effects/gfx/es/D_PAL_0900C540_44AEC0.gfx.inc.c"
