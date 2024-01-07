#include "include_asset.h"

#include "PR/gbi.h"

Lights1 D_09000000_398BC0 = gdSPDefLights1(255, 255, 255, 255, 255, 255, 255, 65, 109);

INCLUDE_IMG("effects/gfx/D_09000018_398BD8.png", D_09000018_398BD8);
#include "effects/gfx/D_09000218_398DD8.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09000288_398E48.png", D_09000288_398E48);
#include "effects/gfx/D_09001288_399E48.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_090012F8_399EB8.png", D_090012F8_399EB8);
INCLUDE_PAL("effects/gfx/D_090012F8_399EB8.pal", D_090014F8_39A0B8);
#include "effects/gfx/D_09001518_39A0D8.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_090015B8_39A178.png", D_090015B8_39A178);
#include "effects/gfx/D_090017B8_39A378.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09001828_39A3E8.png", D_09001828_39A3E8);
INCLUDE_PAL("effects/gfx/D_09001828_39A3E8.pal", D_09001C28_39A7E8);
#include "effects/gfx/D_09001C48_39A808.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09001CE8_39A8A8.png", D_09001CE8_39A8A8);
#include "effects/gfx/D_09002CE8_39B8A8.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09002D58_39B918.png", D_09002D58_39B918);
INCLUDE_PAL("effects/gfx/D_09002D58_39B918.pal", D_09003558_39C118);
#include "effects/gfx/D_09003578_39C138.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09003618_39C1D8.png", D_09003618_39C1D8);
#include "effects/gfx/D_09003E18_39C9D8.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09003E88_39CA48.png", D_09003E88_39CA48);
INCLUDE_PAL("effects/gfx/D_09003E88_39CA48.pal", D_09004088_39CC48);
#include "effects/gfx/D_090040A8_39CC68.gfx.inc.c"

// what's this?
char D_09004148_39CD08[] = {
    0x0, 0x0, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0xFF, 0x83, 0x0, 0x0, 0x0, 0x41, 0x0, 0x1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x7D, 0x0, 0x0, 0x0, 0x41, 0x0, 0x1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x7D, 0x0, 0x0, 0xFF, 0xAB, 0x0, 0x1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0xFF, 0xCE, 0x0, 0x0, 0x0, 0xA, 0x0, 0x1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};

INCLUDE_IMG("effects/gfx/D_09004248_39CE08.png", D_09004248_39CE08);
INCLUDE_PAL("effects/gfx/D_09004248_39CE08.pal", D_09004A48_39D608);
#include "effects/gfx/D_09004A68_39D628.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09004B08_39D6C8.png", D_09004B08_39D6C8);
#include "effects/gfx/D_09005308_39DEC8.gfx.inc.c"
INCLUDE_IMG("effects/gfx/D_09005378_39DF38.png", D_09005378_39DF38);
#include "effects/gfx/D_09006378_39EF38.gfx.inc.c"
#include "effects/gfx/D_090063E8_39EFA8.vtx.inc.c"
#include "effects/gfx/D_09006428_39EFE8.vtx.inc.c"
#include "effects/gfx/D_09006468_39F028.vtx.inc.c"
#include "effects/gfx/D_090064A8_39F068.vtx.inc.c"
#include "effects/gfx/D_090064E8_39F0A8.vtx.inc.c"
#include "effects/gfx/D_09006568_39F128.vtx.inc.c"
#include "effects/gfx/D_090065E8_39F1A8.vtx.inc.c"
#include "effects/gfx/D_09006628_39F1E8.vtx.inc.c"
#include "effects/gfx/D_090067E8_39F3A8.vtx.inc.c"
#include "effects/gfx/D_09006828_39F3E8.vtx.inc.c"
#include "effects/gfx/D_09006868_39F428.vtx.inc.c"
#include "effects/gfx/D_090068A8_39F468.vtx.inc.c"
#include "effects/gfx/D_090068E8_39F4A8.vtx.inc.c"
#include "effects/gfx/D_09006928_39F4E8.vtx.inc.c"
#include "effects/gfx/D_09006968_39F528.vtx.inc.c"
#include "effects/gfx/D_090069A8_39F568.vtx.inc.c"

#include "effects/gfx/D_090069E8_39F5A8.gfx.inc.c"
#include "effects/gfx/D_09006A48_39F608.gfx.inc.c"
#include "effects/gfx/D_09006AA8_39F668.gfx.inc.c"
#include "effects/gfx/D_09006B08_39F6C8.gfx.inc.c"
#include "effects/gfx/D_09006B68_39F728.gfx.inc.c"
#include "effects/gfx/D_09006BA8_39F768.gfx.inc.c"
#include "effects/gfx/D_09006C08_39F7C8.gfx.inc.c"
#include "effects/gfx/D_09006C68_39F828.gfx.inc.c"
#include "effects/gfx/D_09006C98_39F858.gfx.inc.c"
#include "effects/gfx/D_09006CF0_39F8B0.gfx.inc.c"
#include "effects/gfx/D_09006D48_39F908.gfx.inc.c"
#include "effects/gfx/D_09006D78_39F938.gfx.inc.c"
#include "effects/gfx/D_09006DA0_39F960.gfx.inc.c"
#include "effects/gfx/D_09006E28_39F9E8.gfx.inc.c"
#include "effects/gfx/D_09006E88_39FA48.gfx.inc.c"
#include "effects/gfx/D_09006EB8_39FA78.gfx.inc.c"
#include "effects/gfx/D_09006F20_39FAE0.gfx.inc.c"
#include "effects/gfx/D_09006F48_39FB08.gfx.inc.c"
#include "effects/gfx/D_09006FB0_39FB70.gfx.inc.c"
#include "effects/gfx/D_09006FD8_39FB98.gfx.inc.c"
#include "effects/gfx/D_09007030_39FBF0.gfx.inc.c"
#include "effects/gfx/D_09007090_39FC50.gfx.inc.c"
#include "effects/gfx/D_090070E8_39FCA8.gfx.inc.c"
#include "effects/gfx/D_09007148_39FD08.gfx.inc.c"
#include "effects/gfx/D_09007188_39FD48.gfx.inc.c"
#include "effects/gfx/D_090071D0_39FD90.gfx.inc.c"
#include "effects/gfx/D_09007200_39FDC0.gfx.inc.c"

#include "effects/gfx/D_09007230_39FDF0.gfx.inc.c"
#include "effects/gfx/D_09007298_39FE58.vtx.inc.c"
#include "effects/gfx/D_090072D8_39FE98.gfx.inc.c"
