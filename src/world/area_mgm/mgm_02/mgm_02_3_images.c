#include "mgm_02.h"
#include "include_asset.h"

#include "world/area_mgm/mgm_02/panel_peach.png.h"
INCLUDE_IMG("world/area_mgm/mgm_02/panel_peach.png", mgm_02_panel_peach_img);
INCLUDE_PAL("world/area_mgm/mgm_02/panel_peach.pal", mgm_02_panel_peach_pal);

MessageImageData N(MsgImg_PeachPanel)[] = {
    {
        .raster   = N(panel_peach_img),
        .palette  = N(panel_peach_pal),
        .width    = N(panel_peach_img_width),
        .height   = N(panel_peach_img_height),
        .format   = G_IM_FMT_CI,
        .bitDepth = G_IM_SIZ_4b,
    }
};

API_CALLABLE(N(SetMsgImgs_Panel)) {
    set_message_images(N(MsgImg_PeachPanel));
    return ApiStatus_DONE2;
}
