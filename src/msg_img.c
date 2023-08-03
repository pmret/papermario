#include "common.h"

#include "ui/msg/bubble_left.png.inc.c"
#include "ui/msg/bubble_mid.png.inc.c"
#include "ui/msg/bubble_right.png.inc.c"
#include "ui/msg/arrow.png.inc.c"
#include "ui/msg/frame_a_1_1.png.inc.c"
#include "ui/msg/frame_a_1_2.png.inc.c"
#include "ui/msg/frame_a_1_3.png.inc.c"
#include "ui/msg/frame_a_1_4.png.inc.c"
#include "ui/msg/frame_a_1_5.png.inc.c"
#include "ui/msg/frame_a_2_1.png.inc.c"
#include "ui/msg/frame_a_2_5.png.inc.c"
#include "ui/msg/frame_a_3_1.png.inc.c"
#include "ui/msg/frame_a_3_5.png.inc.c"
#include "ui/msg/frame_a_4_1.png.inc.c"
#include "ui/msg/frame_a_4_5.png.inc.c"
#include "ui/msg/frame_a_5_1.png.inc.c"
#include "ui/msg/frame_a_5_2.png.inc.c"
#include "ui/msg/frame_a_5_3.png.inc.c"
#include "ui/msg/frame_a_5_4.png.inc.c"
#include "ui/msg/frame_a_5_5.png.inc.c"
#include "ui/msg/frame_b_1_1.png.inc.c"
#include "ui/msg/frame_b_1_2.png.inc.c"
#include "ui/msg/frame_b_1_3.png.inc.c"
#include "ui/msg/frame_b_1_4.png.inc.c"
#include "ui/msg/frame_b_1_5.png.inc.c"
#include "ui/msg/frame_b_2_1.png.inc.c"
#include "ui/msg/frame_b_2_5.png.inc.c"
#include "ui/msg/frame_b_3_1.png.inc.c"
#include "ui/msg/frame_b_3_5.png.inc.c"
#include "ui/msg/frame_b_4_1.png.inc.c"
#include "ui/msg/frame_b_4_5.png.inc.c"
#include "ui/msg/frame_b_5_1.png.inc.c"
#include "ui/msg/frame_b_5_2.png.inc.c"
#include "ui/msg/frame_b_5_3.png.inc.c"
#include "ui/msg/frame_b_5_4.png.inc.c"
#include "ui/msg/frame_b_5_5.png.inc.c"

// TODO: make assets
unsigned char ui_msg_palettes[16][32] = {
    {115,158,255,255,247,187,231,57,222,245,198,47,156,229,123,221,189,239,222,247,156,229,115,157,0,1,0,1,0,1,0,1},
    {115,158,231,59,222,249,214,183,206,117,181,175,140,101,107,93,173,109,206,117,140,101,99,27,0,1,0,1,0,1,0,1},
    {115,158,255,255,246,245,246,113,245,171,204,229,172,97,131,155,197,173,230,181,164,163,115,157,0,1,0,1,0,1,0,1},
    {115,158,255,255,214,189,198,63,181,191,156,245,140,107,115,161,181,177,214,185,148,169,115,157,0,1,0,1,0,1,0,1},
    {115,158,255,255,247,179,247,169,247,95,206,29,165,29,123,219,198,43,231,51,165,35,115,157,0,1,0,1,0,1,0,1},
    {115,158,231,57,246,159,139,79,171,207,180,85,213,89,171,209,168,63,168,63,168,63,168,63,168,63,122,3,65,1,0,1},
    {115,158,231,57,246,159,188,81,168,63,180,85,213,89,168,63,168,63,168,63,168,63,168,63,168,63,122,3,65,1,0,1},
    {115,158,231,57,246,159,131,13,168,63,180,19,213,89,168,63,168,63,168,63,168,63,168,63,168,63,122,3,65,1,0,1},
    {115,158,255,255,247,187,231,57,222,245,198,47,156,229,123,221,189,239,222,247,156,229,115,157,0,1,0,1,0,1,0,1},
    {115,158,66,15,132,29,181,171,214,179,181,171,123,221,66,15,66,15,66,15,66,15,115,157,0,1,0,1,0,1,0,1},
    {115,158,255,255,247,57,238,247,230,115,197,107,172,97,131,155,197,173,230,181,164,163,115,157,0,1,0,1,0,1,0,1},
    {115,158,255,255,231,61,214,187,206,121,173,113,140,107,115,161,181,177,214,185,148,169,115,157,0,1,0,1,0,1,0,1},
    {115,158,255,255,247,183,239,115,231,45,198,39,165,31,123,219,198,43,231,51,165,35,115,157,0,1,0,1,0,1,0,1},
    {115,158,231,57,230,29,147,143,188,21,196,79,213,87,171,209,168,63,168,63,168,63,168,63,168,63,130,137,65,1,0,1},
    {115,158,231,57,230,29,172,83,172,19,196,79,213,87,163,141,168,63,168,63,168,63,168,63,168,63,130,137,65,1,0,1},
    {115,158,231,57,230,29,155,75,168,63,196,79,205,23,168,63,168,63,168,63,168,63,168,63,168,63,130,137,65,1,0,1},
};

#include "ui/msg/sign_corner_topleft.png.inc.c"
#include "ui/msg/sign_corner_topright.png.inc.c"
#include "ui/msg/sign_corner_bottomleft.png.inc.c"
#include "ui/msg/sign_corner_bottomright.png.inc.c"
#include "ui/msg/lamppost_corner_bottomright.png.inc.c"
#include "ui/msg/sign_side_top.png.inc.c"
#include "ui/msg/sign_side_left.png.inc.c"
#include "ui/msg/sign_side_right.png.inc.c"
#include "ui/msg/sign_side_bottom.png.inc.c"
#include "ui/msg/sign_fill.png.inc.c"
#include "ui/msg/sign_corner_topleft.pal.inc.c"
#include "ui/msg/lamppost_corner_bottomright.pal.inc.c"
#include "ui/msg/background.png.inc.c"
#include "ui/msg/rewind_arrow.png.inc.c"
#include "ui/msg/rewind_arrow.pal.inc.c"
#include "ui/msg/star.png.inc.c"
#include "ui/msg/star_silhouette.png.inc.c"

BSS IMG_BIN MsgCharImgTitle[0xF60];
BSS IMG_BIN MsgCharImgNormal[0x5100];
BSS IMG_BIN MsgCharImgSubtitle[0xB88];
BSS char MSG_unused[8];
BSS PAL_BIN D_802F4560[80][8];

MATCHING_BSS(0x6DA0);
