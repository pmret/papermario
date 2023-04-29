#include "mgm_01.h"

#include "world/area_mgm/mgm_01/panel_1_coin.png.h"
#include "world/area_mgm/mgm_01/panel_1_coin.png.inc.c"
#include "world/area_mgm/mgm_01/panel_1_coin.pal.inc.c"

#include "world/area_mgm/mgm_01/panel_5_coins.png.h"
#include "world/area_mgm/mgm_01/panel_5_coins.png.inc.c"
#include "world/area_mgm/mgm_01/panel_5_coins.pal.inc.c"

#include "world/area_mgm/mgm_01/panel_times_5.png.h"
#include "world/area_mgm/mgm_01/panel_times_5.png.inc.c"
#include "world/area_mgm/mgm_01/panel_times_5.pal.inc.c"

#include "world/area_mgm/mgm_01/panel_bowser.png.h"
#include "world/area_mgm/mgm_01/panel_bowser.png.inc.c"
#include "world/area_mgm/mgm_01/panel_bowser.pal.inc.c"

MessageImageData N(MsgImgs_Panels)[] = {
    {
        .raster   = N(panel_1_coin_img),
        .palette  = N(panel_1_coin_pal),
        .width    = N(panel_1_coin_img_width),
        .height   = N(panel_1_coin_img_height),
        .format   = G_IM_FMT_CI,
        .bitDepth = G_IM_SIZ_4b,
    },
    {
        .raster   = N(panel_5_coins_img),
        .palette  = N(panel_5_coins_pal),
        .width    = N(panel_5_coins_img_width),
        .height   = N(panel_5_coins_img_height),
        .format   = G_IM_FMT_CI,
        .bitDepth = G_IM_SIZ_4b,
    },
    {
        .raster   = N(panel_times_5_img),
        .palette  = N(panel_times_5_pal),
        .width    = N(panel_times_5_img_width),
        .height   = N(panel_times_5_img_height),
        .format   = G_IM_FMT_CI,
        .bitDepth = G_IM_SIZ_4b,
    },
    {
        .raster   = N(panel_bowser_img),
        .palette  = N(panel_bowser_pal),
        .width    = N(panel_bowser_img_width),
        .height   = N(panel_bowser_img_height),
        .format   = G_IM_FMT_CI,
        .bitDepth = G_IM_SIZ_4b,
    }
};

API_CALLABLE(N(SetMsgImgs_Panels)) {
    set_message_images(N(MsgImgs_Panels));
    return ApiStatus_DONE2;
}
