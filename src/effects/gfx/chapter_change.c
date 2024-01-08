#include "include_asset.h"

INCLUDE_IMG("effects/gfx/world/ch0.png", D_09000000_3EBE60);
INCLUDE_IMG("effects/gfx/D_09000B40_3EC9A0.png", D_09000B40_3EC9A0);
INCLUDE_IMG("effects/gfx/world/text_chapter.png", D_09001680_3ED4E0);
INCLUDE_IMG("effects/gfx/D_09001B80_3ED9E0.png", D_09001B80_3ED9E0);
INCLUDE_IMG("effects/gfx/D_09002080_3EDEE0.png", D_09002080_3EDEE0);
INCLUDE_IMG("effects/gfx/D_09002580_3EE3E0.png", D_09002580_3EE3E0);
INCLUDE_IMG("effects/gfx/world/text_end_of.png", D_09002A80_3EE8E0);
INCLUDE_IMG("effects/gfx/world/exclamation_point.png", D_09003AC0_3EF920);
INCLUDE_IMG("effects/gfx/world/ch1.png", D_09003D40_3EFBA0);
INCLUDE_IMG("effects/gfx/world/ch2.png", D_09004D40_3F0BA0);
INCLUDE_IMG("effects/gfx/world/ch3.png", D_09005D40_3F1BA0);
INCLUDE_IMG("effects/gfx/world/ch4.png", D_09006D40_3F2BA0);
INCLUDE_IMG("effects/gfx/world/ch5.png", D_09007D40_3F3BA0);
INCLUDE_IMG("effects/gfx/world/ch6.png", D_09008D40_3F4BA0);
INCLUDE_IMG("effects/gfx/world/ch7.png", D_09009D40_3F5BA0);
INCLUDE_IMG("effects/gfx/world/ch8.png", D_0900AD40_3F6BA0);
INCLUDE_IMG("effects/gfx/world/chapter_rainbow.png", D_0900BD40_3F7BA0);

#include "effects/gfx/D_0900BE40_3F7CA0.gfx.inc.c"
#include "effects/gfx/D_0900BE88_3F7CE8.gfx.inc.c"
#include "effects/gfx/D_0900BED0_3F7D30.gfx.inc.c"
#include "effects/gfx/D_0900BF18_3F7D78.gfx.inc.c"
#include "effects/gfx/D_0900BF60_3F7DC0.gfx.inc.c"
#include "effects/gfx/D_0900BFA8_3F7E08.gfx.inc.c"
#include "effects/gfx/D_0900BFF0_3F7E50.gfx.inc.c"
#include "effects/gfx/D_0900C038_3F7E98.gfx.inc.c"
#include "effects/gfx/D_0900C080_3F7EE0.gfx.inc.c"
#include "effects/gfx/D_0900C168_3F7FC8.gfx.inc.c"
#include "effects/gfx/D_0900C1B0_3F8010.gfx.inc.c"
#include "effects/gfx/D_0900C1F8_3F8058.gfx.inc.c"
#include "effects/gfx/D_0900C240_3F80A0.gfx.inc.c"

// TODO allow splat to output the reference to halfway into the texture
//#include "effects/gfx/D_0900C328_3F8188.gfx.inc.c"
Gfx D_0900C328_3F8188[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile(&D_09002A80_3EE8E0[0x820], G_IM_FMT_IA, G_IM_SIZ_8b, 104, 0, 0, 0, 103, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

#include "effects/gfx/D_0900C370_3F81D0.gfx.inc.c"
#include "effects/gfx/D_0900C458_3F82B8.gfx.inc.c"
#include "effects/gfx/D_0900C540_3F83A0.gfx.inc.c"
