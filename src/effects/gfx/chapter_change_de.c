#include "include_asset.h"

INCLUDE_IMG("effects/gfx/de/world/ch0.png", D_PAL_09000000_425E60);
INCLUDE_IMG("effects/gfx/de/D_PAL_09000B40_4269A0.png", D_PAL_09000B40_4269A0);
INCLUDE_IMG("effects/gfx/de/world/text_chapter.png", D_PAL_09001680_4274E0);
INCLUDE_IMG("effects/gfx/de/D_PAL_09001B80_4279E0.png", D_PAL_09001B80_4279E0);
INCLUDE_IMG("effects/gfx/de/D_PAL_09002080_427EE0.png", D_PAL_09002080_427EE0);
INCLUDE_IMG("effects/gfx/de/D_PAL_09002580_4283E0.png", D_PAL_09002580_4283E0);
INCLUDE_IMG("effects/gfx/de/world/text_end_of.png", D_PAL_09002A80_4288E0);
INCLUDE_IMG("effects/gfx/de/world/exclamation_point.png", D_PAL_09003AC0_429920);
INCLUDE_IMG("effects/gfx/de/world/ch1.png", D_PAL_09003D40_429BA0);
INCLUDE_IMG("effects/gfx/de/world/ch2.png", D_PAL_09004D40_42ABA0);
INCLUDE_IMG("effects/gfx/de/world/ch3.png", D_PAL_09005D40_42BBA0);
INCLUDE_IMG("effects/gfx/de/world/ch4.png", D_PAL_09006D40_42CBA0);
INCLUDE_IMG("effects/gfx/de/world/ch5.png", D_PAL_09007D40_42DBA0);
INCLUDE_IMG("effects/gfx/de/world/ch6.png", D_PAL_09008D40_42EBA0);
INCLUDE_IMG("effects/gfx/de/world/ch7.png", D_PAL_09009D40_42FBA0);
INCLUDE_IMG("effects/gfx/de/world/ch8.png", D_PAL_0900AD40_430BA0);
INCLUDE_IMG("effects/gfx/de/world/chapter_rainbow.png", D_PAL_0900BD40_431BA0);

#include "effects/gfx/de/D_PAL_0900BE40_431CA0.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900BE88_431CE8.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900BED0_431D30.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900BF18_431D78.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900BF60_431DC0.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900BFA8_431E08.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900BFF0_431E50.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C038_431E98.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C080_431EE0.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C168_431FC8.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C1B0_432010.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C1F8_432058.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C240_4320A0.gfx.inc.c"

//#include "effects/gfx/de/D_PAL_0900C328_432188.gfx.inc.c"
Gfx D_PAL_0900C328_432188[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile(&D_PAL_09002A80_4288E0[0x820], G_IM_FMT_IA, G_IM_SIZ_8b, 104, 0, 0, 0, 103, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

#include "effects/gfx/de/D_PAL_0900C370_4321D0.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C458_4322B8.gfx.inc.c"
#include "effects/gfx/de/D_PAL_0900C540_4323A0.gfx.inc.c"
