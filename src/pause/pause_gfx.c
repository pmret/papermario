#include "pause_common.h"
#include "message_ids.h"

#include "pause/image_143BF0.png.h"
#include "pause/image_143FF0.png.h"
#include "pause/world_map.png.h"
#include "pause/world_map.png.h"
#include "pause/spirits_bg.png.h"
#include "pause/orbs.png.h"
#include "pause/map_location.png.h"
#include "pause/map_path_marker.png.h"
#include "pause/map_arrows.png.h"
#include "pause/banner_hp.png.h"
#include "pause/banner_fp.png.h"
#include "pause/banner_bp.png.h"
#include "pause/banner_boots.png.h"
#include "pause/banner_hammer.png.h"
#include "pause/banner_star_energy.png.h"
#include "pause/available.png.h"
#include "pause/prompt_check_abilities.png.h"
#include "pause/stats_bar.png.h"

#include "pause/image_1439F0.png.inc.c"
#include "pause/image_143BF0.png.inc.c"
#include "pause/image_143FF0.png.inc.c"
#include "pause/world_map.png.inc.c"
#include "pause/world_map.pal.inc.c"
#include "pause/spirits_bg.png.inc.c"
#include "pause/spirits_bg.pal.inc.c"
#include "pause/orbs.png.inc.c"
#include "pause/map_location.png.inc.c"
#include "pause/map_path_marker.png.inc.c"
#include "pause/map_arrows.png.inc.c"
#include "pause/banner_hp.png.inc.c"
#include "pause/banner_hp.pal.inc.c"
#include "pause/banner_fp.png.inc.c"
#include "pause/banner_fp.pal.inc.c"
#include "pause/banner_bp.png.inc.c"
#include "pause/banner_bp.pal.inc.c"
#include "pause/banner_boots.png.inc.c"
#include "pause/banner_boots.pal.inc.c"
#include "pause/banner_hammer.png.inc.c"
#include "pause/banner_hammer.pal.inc.c"
#include "pause/banner_star_energy.png.inc.c"
#include "pause/banner_star_energy.pal.inc.c"
#include "pause/available.png.inc.c"
#include "pause/available.pal.inc.c"
#include "pause/prompt_check_abilities.png.inc.c"
#include "pause/prompt_check_abilities.pal.inc.c"
#include "pause/stats_bar.png.inc.c"
#include "pause/stats_bar.pal.inc.c"

Gfx gPauseDLBannerHp[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_banner_hp_pal),
    gsDPLoadTextureTile_4b(pause_banner_hp_png, G_IM_FMT_CI, pause_banner_hp_png_width, pause_banner_hp_png_height, 0, 0, pause_banner_hp_png_width - 1, pause_banner_hp_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLBannerFp[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_banner_fp_pal),
    gsDPLoadTextureTile_4b(pause_banner_fp_png, G_IM_FMT_CI, pause_banner_fp_png_width, pause_banner_fp_png_height, 0, 0, pause_banner_fp_png_width - 1, pause_banner_fp_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLBannerBp[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_banner_bp_pal),
    gsDPLoadTextureTile_4b(pause_banner_bp_png, G_IM_FMT_CI, pause_banner_bp_png_width, pause_banner_bp_png_height, 0, 0, pause_banner_bp_png_width - 1, pause_banner_bp_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLBannerBoots[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_banner_boots_pal),
    gsDPLoadTextureTile_4b(pause_banner_boots_png, G_IM_FMT_CI, pause_banner_boots_png_width, pause_banner_boots_png_height, 0, 0, pause_banner_boots_png_width - 1, pause_banner_boots_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLBannerHammer[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_banner_hammer_pal),
    gsDPLoadTextureTile_4b(pause_banner_hammer_png, G_IM_FMT_CI, pause_banner_hammer_png_width, pause_banner_hammer_png_height, 0, 0, pause_banner_hammer_png_width - 1, pause_banner_hammer_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLBannerStarEnergy[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_banner_star_energy_pal),
    gsDPLoadTextureTile_4b(pause_banner_star_energy_png, G_IM_FMT_CI, pause_banner_star_energy_png_width, pause_banner_star_energy_png_height, 0, 0, pause_banner_star_energy_png_width - 1, pause_banner_star_energy_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLStatsBar[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_stats_bar_pal),
    gsDPLoadTextureTile_4b(pause_stats_bar_png, G_IM_FMT_CI, pause_stats_bar_png_width, pause_stats_bar_png_height, 0, 0, pause_stats_bar_png_width - 1, pause_stats_bar_png_height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_WRAP, 8, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLWorldMap[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPLoadTLUT_pal256(pause_world_map_pal),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLPathPoints[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile(pause_map_location_png, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, 0, 15, 15, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadMultiTile(pause_map_path_marker_png, 0x100, 1, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, 0, 15, 15, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLArrows[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(pause_arrows_png, G_IM_FMT_IA, pause_arrows_png_width, pause_arrows_png_height, 0, 0, pause_arrows_png_width - 1, pause_arrows_png_height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLOrbs[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile(pause_orbs_png, G_IM_FMT_RGBA, G_IM_SIZ_16b, pause_orbs_png_width, pause_orbs_png_height, 0, 0, pause_orbs_png_width - 1, pause_orbs_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLAvailable[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_available_pal),
    gsDPLoadTextureTile_4b(pause_available_png, G_IM_FMT_CI, pause_available_png_width, pause_available_png_height, 0, 0, pause_available_png_width - 1, pause_available_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLCheckAbilities[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, pause_prompt_check_abilities_pal),
    gsDPLoadTextureTile_4b(pause_prompt_check_abilities_png, G_IM_FMT_CI, pause_prompt_check_abilities_png_width, pause_prompt_check_abilities_png_height, 0, 0, pause_prompt_check_abilities_png_width - 1, pause_prompt_check_abilities_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx gPauseDLSpiritsBg[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPLoadTLUT_pal16(0, pause_spirits_bg_pal),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

s8 gPauseMsg_17[] = { 0x33, 0x54, 0x41, 0x54, 0x53, 0xFD };                                                                   // Stats[End]
s8 gPauseMsg_18[] = { 0x22, 0x41, 0x44, 0x47, 0x45, 0xFD };                                                                   // Badge[End]
s8 gPauseMsg_19[] = { 0x29, 0x54, 0x45, 0x4D, 0x53, 0xFD };                                                                   // Items[End]
s8 gPauseMsg_1A[] = { 0x30, 0x41, 0x52, 0x54, 0x59, 0xFD };                                                                   // Party[End]
s8 gPauseMsg_32[] = { 0x23, 0x4F, 0x49, 0x4E, 0x53, 0xFD };                                                                   // Coins[End]
s8 gPauseMsg_33[] = { 0x33, 0x54, 0x41, 0x52, 0xF7, 0x30, 0x4F, 0x49, 0x4E, 0x54, 0x53, 0xFD };                               // Star Points[End]
s8 gPauseMsg_34[] = { 0x33, 0x54, 0x41, 0x52, 0xF7, 0x30, 0x49, 0x45, 0x43, 0x45, 0x53, 0xFD };                               // Star Pieces[End]
s8 gPauseMsg_35[] = { 0x30, 0x4C, 0x41, 0x59, 0xF7, 0x34, 0x49, 0x4D, 0x45, 0xFD };                                           // Play Time[End]
s8 gPauseMsg_36[] = { 0x28, 0x30, 0xFD };                                                                                     // HP[End]
s8 gPauseMsg_37[] = { 0x26, 0x30, 0xFD };                                                                                     // FP[End]
s8 gPauseMsg_38[] = { 0x22, 0x30, 0xFD };                                                                                     // BP[End]
s8 gPauseMsg_39[] = { 0x0F, 0xFD };                                                                                           // /[End]
s8 gPauseMsg_3A[] = { 0x0E, 0xFD };                                                                                           // .[End]
s8 gPauseMsg_3B[] = { 0x2E, 0x4F, 0x4E, 0x45, 0xFD };                                                                         // None[End]
s8 gPauseMsg_3C[] = { 0x22, 0x4F, 0x4F, 0x54, 0x53, 0xFD };                                                                   // Boots[End]
s8 gPauseMsg_3D[] = { 0x33, 0x55, 0x50, 0x45, 0x52, 0xF7, 0x22, 0x4F, 0x4F, 0x54, 0x53, 0xFD };                               // Super Boots[End]
s8 gPauseMsg_3E[] = { 0x35, 0x4C, 0x54, 0x52, 0x41, 0xF7, 0x22, 0x4F, 0x4F, 0x54, 0x53, 0xFD };                               // Ultra Boots[End]
s8 gPauseMsg_3F[] = { 0x2E, 0x4F, 0x4E, 0x45, 0xFD };                                                                         // None[End]
s8 gPauseMsg_40[] = { 0x28, 0x41, 0x4D, 0x4D, 0x45, 0x52, 0xFD };                                                             // Hammer[End]
s8 gPauseMsg_41[] = { 0x33, 0x55, 0x50, 0x45, 0x52, 0xF7, 0x28, 0x41, 0x4D, 0x4D, 0x45, 0x52, 0xFD };                         // Super Hammer[End]
s8 gPauseMsg_42[] = { 0x35, 0x4C, 0x54, 0x52, 0x41, 0xF7, 0x28, 0x41, 0x4D, 0x4D, 0x45, 0x52, 0xFD };                         // Ultra Hammer[End]
s8 gPauseMsg_43[] = { 0x2D, 0x41, 0x52, 0x49, 0x4F, 0xFD };                                                                   // Mario[End]
s8 gPauseMsg_44[] = { 0x2C, 0x45, 0x56, 0x45, 0x4C, 0xFD };                                                                   // Level[End]
s8 gPauseMsg_46[] = { 0x22, 0x30, 0xFD };                                                                                     // BP[End]
s8 gPauseMsg_47[] = { 0x21, 0x4C, 0x4C, 0xF7, 0x22, 0x41, 0x44, 0x47, 0x45, 0x53, 0xFD };                                     // All Badges[End]
s8 gPauseMsg_48[] = { 0x21, 0x43, 0x54, 0x49, 0x56, 0x45, 0xFD };                                                             // Active[End]
s8 gPauseMsg_49[] = { 0x22, 0x41, 0x44, 0x47, 0x45, 0x53, 0xFD };                                                             // Badges[End]
s8 gPauseMsg_4A[] = { 0x2E, 0x4F, 0x54, 0xF7, 0x45, 0x4E, 0x4F, 0x55, 0x47, 0x48, 0xF7, 0x22, 0x30, 0xFD };                   // Not enough BP[End]
s8 gPauseMsg_4B[] = { 0x24, 0x4F, 0x4E, 0x07, 0x54, 0xF7, 0x57, 0x45, 0x41, 0x52, 0xF7, 0x4D, 0x4F, 0x52, 0x45, 0x01, 0xFD }; // Don't wear more![End]
s8 gPauseMsg_50[] = { 0x29, 0x54, 0x45, 0x4D, 0x53, 0xFD };                                                                   // Items[End]
s8 gPauseMsg_4F[] = { 0x2B, 0x45, 0x59, 0xF7, 0x29, 0x54, 0x45, 0x4D, 0x53, 0xFD };                                           // Key Items[End]
s8 gPauseMsg_53[] = { 0x28, 0x30, 0xFD };                                                                                     // HP[End]
s8 gPauseMsg_54[] = { 0x26, 0x30, 0xFD };                                                                                     // FP[End]
s8 gPauseMsg_55[] = { 0x21, 0x42, 0x49, 0x4C, 0x49, 0x54, 0x49, 0x45, 0x53, 0xFD };                                           // Abilities[End]
s8 gPauseMsg_56[] = { 0x1F, 0x1F, 0x1F, 0xFD };                                                                               // ???[End]

s32 gPauseMessages[] = {
    0, MSG_MenuTip_BadgeTutorial_01, MSG_MenuTip_002B, MSG_MenuTip_002C,
    MSG_MenuTip_002D, MSG_MenuTip_002E, MSG_MenuTip_002F, MSG_MenuTip_0030,
    MSG_MenuTip_0031, MSG_MenuTip_BadgeTutorial_02, MSG_MenuTip_BadgeTutorial_03, MSG_MenuTip_BadgeTutorial_04,
    MSG_MenuTip_BadgeTutorial_05, MSG_MenuTip_BadgeTutorial_06, MSG_MenuTip_BadgeTutorial_07, MSG_MenuTip_BadgeTutorial_08,
    MSG_MenuTip_BadgeTutorial_09, MSG_MenuTip_BadgeTutorial_10, MSG_MenuTip_BadgeTutorial_11, MSG_MenuTip_BadgeTutorial_12,
    MSG_MenuTip_BadgeTutorial_13, MSG_MenuTip_BadgeTutorial_14, MSG_MenuTip_BadgeTutorial_15, (s32)gPauseMsg_17,
    (s32)gPauseMsg_18,      (s32)gPauseMsg_19,      (s32)gPauseMsg_1A,      MSG_MenuTip_StatsTab,
    MSG_MenuTip_BadgesTab, MSG_MenuTip_ItemsTab, MSG_MenuTip_PartyTab, MSG_MenuTip_SpiritsTab,
    MSG_MenuTip_MapTab, MSG_MenuTip_ControllingMario, MSG_MenuTip_HeartPoints, MSG_MenuTip_FlowerPoints,
    MSG_MenuTip_BadgePoints, MSG_MenuTip_Boots1, MSG_MenuTip_Boots2, MSG_MenuTip_Boots3,
    MSG_MenuTip_Hammer0, MSG_MenuTip_Hammer1, MSG_MenuTip_Hammer2, MSG_MenuTip_Hammer3,
    MSG_MenuTip_StarPower, MSG_MenuTip_StarPoints, MSG_MenuTip_Coins, MSG_MenuTip_Secrets,
    MSG_MenuTip_StarPieces, MSG_MenuTip_Time, (s32)gPauseMsg_32,      (s32)gPauseMsg_33,
    (s32)gPauseMsg_34,      (s32)gPauseMsg_35,      (s32)gPauseMsg_36,      (s32)gPauseMsg_37,
    (s32)gPauseMsg_38,      (s32)gPauseMsg_39,      (s32)gPauseMsg_3A,      (s32)gPauseMsg_3B,
    (s32)gPauseMsg_3C,      (s32)gPauseMsg_3D,      (s32)gPauseMsg_3E,      (s32)gPauseMsg_3F,
    (s32)gPauseMsg_40,      (s32)gPauseMsg_41,      (s32)gPauseMsg_42,      (s32)gPauseMsg_43,
    (s32)gPauseMsg_44,      MSG_MenuTip_None, (s32)gPauseMsg_46,      (s32)gPauseMsg_47,
    (s32)gPauseMsg_48,      (s32)gPauseMsg_49,      (s32)gPauseMsg_4A,      (s32)gPauseMsg_4B,
    MSG_MenuTip_BadgeTab_All, MSG_MenuTip_BadgeTab_Equipped, MSG_MenuTip_None, (s32)gPauseMsg_4F,
    (s32)gPauseMsg_50,      MSG_MenuTip_ItemTab_Consumables, MSG_MenuTip_ItemTab_KeyItems, (s32)gPauseMsg_53,
    (s32)gPauseMsg_54,      (s32)gPauseMsg_55,      (s32)gPauseMsg_56
};

Gfx* gPauseDLLabels[] = {
    gPauseDLBannerHp, gPauseDLBannerFp, gPauseDLBannerBp, gPauseDLBannerBoots, gPauseDLBannerHammer,
    gPauseDLBannerStarEnergy, gPauseDLStatsBar, gPauseDLAvailable, gPauseDLCheckAbilities
};

s32 pause_get_menu_msg(s32 index) {
    return gPauseMessages[index];
}

void pause_draw_menu_label(s32 index, s32 x, s32 y) {
    s32 xOffset = 64;

    if (index == 8) {
        xOffset = 128;
    }
    if (index == 3) {
        xOffset = 48;
    }
    if (index == 4) {
        xOffset = 48;
    }
    if (index == 5) {
        xOffset = 48;
    }
    if (index == 6) {
        xOffset = 160;
    }

    gSPDisplayList(gMasterGfxPos++, gPauseDLLabels[index]);
    pause_draw_rect(x * 4, y * 4, (x + xOffset) * 4, (y + 16) * 4, 0, 0, 0, 0x400, 0x400);
}

BSS s8 gPauseBufferPal1[512];
BSS s8 gPauseBufferImg1[15752];
BSS s8 gPauseBufferPal2[512];
BSS s8 gPauseBufferImg2[15752];
