#include "mgm_01.h"
#include "include_asset.h"

#include "world/area_mgm/mgm_01/panel_1_coin.png.h"
INCLUDE_IMG("world/area_mgm/mgm_01/panel_1_coin.png", mgm_01_panel_1_coin_img);
INCLUDE_PAL("world/area_mgm/mgm_01/panel_1_coin.pal", mgm_01_panel_1_coin_pal);

#include "world/area_mgm/mgm_01/panel_5_coins.png.h"
INCLUDE_IMG("world/area_mgm/mgm_01/panel_5_coins.png", mgm_01_panel_5_coins_img);
INCLUDE_PAL("world/area_mgm/mgm_01/panel_5_coins.pal", mgm_01_panel_5_coins_pal);

#include "world/area_mgm/mgm_01/panel_times_5.png.h"
INCLUDE_IMG("world/area_mgm/mgm_01/panel_times_5.png", mgm_01_panel_times_5_img);
INCLUDE_PAL("world/area_mgm/mgm_01/panel_times_5.pal", mgm_01_panel_times_5_pal);

#include "world/area_mgm/mgm_01/panel_bowser.png.h"
INCLUDE_IMG("world/area_mgm/mgm_01/panel_bowser.png", mgm_01_panel_bowser_img);
INCLUDE_PAL("world/area_mgm/mgm_01/panel_bowser.pal", mgm_01_panel_bowser_pal);

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
