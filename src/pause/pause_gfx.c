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

#if VERSION_IQUE
#undef pause_prompt_check_abilities_png_height
#define pause_prompt_check_abilities_png_height 16
#endif

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

#if VERSION_IQUE
u8 gPauseMsg_17[] = { 0x8F, 0x0C, 0x75, 0x12, 0xFD };
u8 gPauseMsg_18[] = { 0x7B, 0x0E, 0x7C, 0x0E, 0xFD };
u8 gPauseMsg_19[] = { 0x77, 0x10, 0x74, 0x0D, 0xFD };
u8 gPauseMsg_1A[] = { 0x79, 0x12, 0x67, 0x09, 0xFD };
u8 gPauseMsg_32[] = { 0x64, 0x02, 0x75, 0x11, 0xFD };
u8 gPauseMsg_33[] = { 0x62, 0x05, 0x62, 0x05, 0x87, 0x06, 0x5F, 0x18, 0xFD };
u8 gPauseMsg_34[] = { 0x62, 0x05, 0x73, 0x02, 0x67, 0x11, 0x85, 0x10, 0xFD };
u8 gPauseMsg_35[] = { 0x7D, 0x0C, 0x85, 0x12, 0x85, 0x05, 0x79, 0x02, 0xFD };
u8 gPauseMsg_36[] = { 0x28, 0x30, 0xFD };
u8 gPauseMsg_37[] = { 0x26, 0x30, 0xFD };
u8 gPauseMsg_38[] = { 0x22, 0x30, 0xFD };
u8 gPauseMsg_39[] = { 0x0F, 0xFD };
u8 gPauseMsg_3A[] = { 0x0E, 0xFD };
u8 gPauseMsg_3B[] = { 0x69, 0x08, 0x81, 0x07, 0xFD };
u8 gPauseMsg_3C[] = { 0x7B, 0x25, 0x60, 0x01, 0xFD };
u8 gPauseMsg_3D[] = { 0x6B, 0x02, 0x6C, 0x02, 0x7B, 0x25, 0x60, 0x01, 0xFD };
u8 gPauseMsg_3E[] = { 0x6D, 0x0A, 0x6C, 0x02, 0x7B, 0x25, 0x60, 0x01, 0xFD };
u8 gPauseMsg_3F[] = { 0x69, 0x08, 0x81, 0x07, 0xFD };
u8 gPauseMsg_40[] = { 0x68, 0x04, 0x60, 0x01, 0xFD };
u8 gPauseMsg_41[] = { 0x6B, 0x02, 0x6C, 0x02, 0x68, 0x04, 0x60, 0x01, 0xFD };
u8 gPauseMsg_42[] = { 0x6D, 0x0A, 0x6C, 0x02, 0x68, 0x04, 0x60, 0x01, 0xFD };
u8 gPauseMsg_43[] = { 0x75, 0x04, 0x76, 0x04, 0x81, 0x03, 0xFD };
u8 gPauseMsg_44[] = { 0x82, 0x07, 0x6C, 0x02, 0xFD };
u8 gPauseMsg_46[] = { 0x22, 0x30, 0xFD };
u8 gPauseMsg_47[] = { 0x69, 0x07, 0x81, 0x07, 0x7B, 0x0E, 0x7C, 0x0E, 0xFD };
u8 gPauseMsg_48[] = { 0x81, 0x07, 0x6F, 0x17, 0x7B, 0x0E, 0x7C, 0x0E, 0xFD };
u8 gPauseMsg_49[] = { 0xFD };
u8 gPauseMsg_4A[] = { 0x69, 0x08, 0x81, 0x07, 0x6C, 0x14, 0x78, 0x0D, 0xF7, 0x22, 0x30, 0xFD };
u8 gPauseMsg_4B[] = { 0x76, 0x06, 0x8B, 0x06, 0x85, 0x07, 0x82, 0x12, 0x8C, 0x04, 0x87, 0x04, 0xFD };
u8 gPauseMsg_50[] = { 0x77, 0x10, 0x74, 0x0D, 0xFD };
u8 gPauseMsg_4F[] = { 0x8C, 0x07, 0x80, 0x05, 0x77, 0x10, 0x74, 0x0D, 0xFD };
u8 gPauseMsg_53[] = { 0x28, 0x30, 0xFD };
u8 gPauseMsg_54[] = { 0x26, 0x30, 0xFD };
u8 gPauseMsg_55[] = { 0x6A, 0x11, 0x8B, 0x06, 0xFD };
u8 gPauseMsg_56[] = { 0x74, 0x08, 0x74, 0x08, 0x74, 0x08, 0xFD };
#else
u8 gPauseMsg_17[] = { 0x33, 0x54, 0x41, 0x54, 0x53, 0xFD };                                                                   // Stats[End]
u8 gPauseMsg_18[] = { 0x22, 0x41, 0x44, 0x47, 0x45, 0xFD };                                                                   // Badge[End]
u8 gPauseMsg_19[] = { 0x29, 0x54, 0x45, 0x4D, 0x53, 0xFD };                                                                   // Items[End]
u8 gPauseMsg_1A[] = { 0x30, 0x41, 0x52, 0x54, 0x59, 0xFD };                                                                   // Party[End]
u8 gPauseMsg_32[] = { 0x23, 0x4F, 0x49, 0x4E, 0x53, 0xFD };                                                                   // Coins[End]
u8 gPauseMsg_33[] = { 0x33, 0x54, 0x41, 0x52, 0xF7, 0x30, 0x4F, 0x49, 0x4E, 0x54, 0x53, 0xFD };                               // Star Points[End]
u8 gPauseMsg_34[] = { 0x33, 0x54, 0x41, 0x52, 0xF7, 0x30, 0x49, 0x45, 0x43, 0x45, 0x53, 0xFD };                               // Star Pieces[End]
u8 gPauseMsg_35[] = { 0x30, 0x4C, 0x41, 0x59, 0xF7, 0x34, 0x49, 0x4D, 0x45, 0xFD };                                           // Play Time[End]
u8 gPauseMsg_36[] = { MSG_CHAR_UPPER_H, MSG_CHAR_UPPER_P, MSG_CHAR_READ_END };                                                // HP[End]
u8 gPauseMsg_37[] = { MSG_CHAR_UPPER_F, MSG_CHAR_UPPER_P, MSG_CHAR_READ_END };                                                // FP[End]
u8 gPauseMsg_38[] = { MSG_CHAR_UPPER_B, MSG_CHAR_UPPER_P, MSG_CHAR_READ_END };                                                // BP[End]
u8 gPauseMsg_39[] = { MSG_CHAR_FORWARDSLASH, MSG_CHAR_READ_END };                                                             // /[End]
u8 gPauseMsg_3A[] = { MSG_CHAR_PERIOD, MSG_CHAR_READ_END };                                                                   // .[End]
u8 gPauseMsg_3B[] = { 0x2E, 0x4F, 0x4E, 0x45, 0xFD };                                                                         // None[End]
u8 gPauseMsg_3C[] = { 0x22, 0x4F, 0x4F, 0x54, 0x53, 0xFD };                                                                   // Boots[End]
u8 gPauseMsg_3D[] = { 0x33, 0x55, 0x50, 0x45, 0x52, 0xF7, 0x22, 0x4F, 0x4F, 0x54, 0x53, 0xFD };                               // Super Boots[End]
u8 gPauseMsg_3E[] = { 0x35, 0x4C, 0x54, 0x52, 0x41, 0xF7, 0x22, 0x4F, 0x4F, 0x54, 0x53, 0xFD };                               // Ultra Boots[End]
u8 gPauseMsg_3F[] = { 0x2E, 0x4F, 0x4E, 0x45, 0xFD };                                                                         // None[End]
u8 gPauseMsg_40[] = { 0x28, 0x41, 0x4D, 0x4D, 0x45, 0x52, 0xFD };                                                             // Hammer[End]
u8 gPauseMsg_41[] = { 0x33, 0x55, 0x50, 0x45, 0x52, 0xF7, 0x28, 0x41, 0x4D, 0x4D, 0x45, 0x52, 0xFD };                         // Super Hammer[End]
u8 gPauseMsg_42[] = { 0x35, 0x4C, 0x54, 0x52, 0x41, 0xF7, 0x28, 0x41, 0x4D, 0x4D, 0x45, 0x52, 0xFD };                         // Ultra Hammer[End]
u8 gPauseMsg_43[] = { 0x2D, 0x41, 0x52, 0x49, 0x4F, 0xFD };                                                                   // Mario[End]
u8 gPauseMsg_44[] = { 0x2C, 0x45, 0x56, 0x45, 0x4C, 0xFD };                                                                   // Level[End]
u8 gPauseMsg_46[] = { MSG_CHAR_UPPER_B, MSG_CHAR_UPPER_P, MSG_CHAR_READ_END };                                                // BP[End]
u8 gPauseMsg_47[] = { 0x21, 0x4C, 0x4C, 0xF7, 0x22, 0x41, 0x44, 0x47, 0x45, 0x53, 0xFD };                                     // All Badges[End]
u8 gPauseMsg_48[] = { 0x21, 0x43, 0x54, 0x49, 0x56, 0x45, 0xFD };                                                             // Active[End]
u8 gPauseMsg_49[] = { 0x22, 0x41, 0x44, 0x47, 0x45, 0x53, 0xFD };                                                             // Badges[End]
u8 gPauseMsg_4A[] = { 0x2E, 0x4F, 0x54, 0xF7, 0x45, 0x4E, 0x4F, 0x55, 0x47, 0x48, 0xF7, 0x22, 0x30, 0xFD };                   // Not enough BP[End]
u8 gPauseMsg_4B[] = { 0x24, 0x4F, 0x4E, 0x07, 0x54, 0xF7, 0x57, 0x45, 0x41, 0x52, 0xF7, 0x4D, 0x4F, 0x52, 0x45, 0x01, 0xFD }; // Don't wear more![End]
u8 gPauseMsg_50[] = { 0x29, 0x54, 0x45, 0x4D, 0x53, 0xFD };                                                                   // Items[End]
u8 gPauseMsg_4F[] = { 0x2B, 0x45, 0x59, 0xF7, 0x29, 0x54, 0x45, 0x4D, 0x53, 0xFD };                                           // Key Items[End]
u8 gPauseMsg_53[] = { MSG_CHAR_UPPER_H, MSG_CHAR_UPPER_P, MSG_CHAR_READ_END };                                                // HP[End]
u8 gPauseMsg_54[] = { MSG_CHAR_UPPER_F, MSG_CHAR_UPPER_P, MSG_CHAR_READ_END };                                                // FP[End]
u8 gPauseMsg_55[] = { 0x21, 0x42, 0x49, 0x4C, 0x49, 0x54, 0x49, 0x45, 0x53, 0xFD };                                           // Abilities[End]
u8 gPauseMsg_56[] = { MSG_CHAR_QUESTION, MSG_CHAR_QUESTION, MSG_CHAR_QUESTION, MSG_CHAR_READ_END };                                                                               // ???[End]
#endif

s32 gPauseMessages[] = {
    [PAUSE_MSG_NONE]                MSG_NONE,
    [PAUSE_MSG_TUT_NAME_BADGES]     MSG_MenuTip_BadgeTutorial_01,
    [PAUSE_MSG_TUT_UNUSED_1]        MSG_MenuTip_002B,
    [PAUSE_MSG_TUT_UNUSED_2]		MSG_MenuTip_002C,
    [PAUSE_MSG_TUT_UNUSED_3]		MSG_MenuTip_002D,
    [PAUSE_MSG_TUT_UNUSED_4]		MSG_MenuTip_002E,
    [PAUSE_MSG_TUT_UNUSED_5]		MSG_MenuTip_002F,
    [PAUSE_MSG_TUT_UNUSED_6]		MSG_MenuTip_0030,
    [PAUSE_MSG_TUT_UNUSED_7]		MSG_MenuTip_0031,
    [PAUSE_MSG_TUT_DESC_1]		    MSG_MenuTip_BadgeTutorial_02,
    [PAUSE_MSG_TUT_DESC_2]		    MSG_MenuTip_BadgeTutorial_03,
    [PAUSE_MSG_TUT_DESC_3]		    MSG_MenuTip_BadgeTutorial_04,
    [PAUSE_MSG_TUT_DESC_4]		    MSG_MenuTip_BadgeTutorial_05,
    [PAUSE_MSG_TUT_DESC_5]		    MSG_MenuTip_BadgeTutorial_06,
    [PAUSE_MSG_TUT_DESC_6]		    MSG_MenuTip_BadgeTutorial_07,
    [PAUSE_MSG_TUT_DESC_7]		    MSG_MenuTip_BadgeTutorial_08,
    [PAUSE_MSG_TUT_CMD_1]		    MSG_MenuTip_BadgeTutorial_09,
    [PAUSE_MSG_TUT_CMD_2]		    MSG_MenuTip_BadgeTutorial_10,
    [PAUSE_MSG_TUT_CMD_3]		    MSG_MenuTip_BadgeTutorial_11,
    [PAUSE_MSG_TUT_CMD_4]		    MSG_MenuTip_BadgeTutorial_12,
    [PAUSE_MSG_TUT_CMD_5]		    MSG_MenuTip_BadgeTutorial_13,
    [PAUSE_MSG_TUT_CMD_6]		    MSG_MenuTip_BadgeTutorial_14,
    [PAUSE_MSG_TUT_CMD_7]		    MSG_MenuTip_BadgeTutorial_15,
    [PAUSE_MSG_17]		            (s32) gPauseMsg_17,
    [PAUSE_MSG_18]		            (s32) gPauseMsg_18,
    [PAUSE_MSG_19]		            (s32) gPauseMsg_19,
    [PAUSE_MSG_1A]		            (s32) gPauseMsg_1A,
    [PAUSE_MSG_TAB_STATS]		    MSG_MenuTip_StatsTab,
    [PAUSE_MSG_TAB_BADGES]		    MSG_MenuTip_BadgesTab,
    [PAUSE_MSG_TAB_ITEMS]		    MSG_MenuTip_ItemsTab,
    [PAUSE_MSG_TAB_PARTY]		    MSG_MenuTip_PartyTab,
    [PAUSE_MSG_TAB_SPIRITS]		    MSG_MenuTip_SpiritsTab,
    [PAUSE_MSG_TAB_MAP]             MSG_MenuTip_MapTab,
    [PAUSE_MSG_TIP_CONTROLS]        MSG_MenuTip_ControllingMario,
    [PAUSE_MSG_TIP_HP]		        MSG_MenuTip_HeartPoints,
    [PAUSE_MSG_TIP_FP]		        MSG_MenuTip_FlowerPoints,
    [PAUSE_MSG_TIP_BP]		        MSG_MenuTip_BadgePoints,
    [PAUSE_MSG_TIP_BOOTS_1]		    MSG_MenuTip_Boots1,
    [PAUSE_MSG_TIP_BOOTS_2]		    MSG_MenuTip_Boots2,
    [PAUSE_MSG_TIP_BOOTS_3]		    MSG_MenuTip_Boots3,
    [PAUSE_MSG_TIP_HAMMER_0]		MSG_MenuTip_Hammer0,
    [PAUSE_MSG_TIP_HAMMER_1]		MSG_MenuTip_Hammer1,
    [PAUSE_MSG_TIP_HAMMER_2]		MSG_MenuTip_Hammer2,
    [PAUSE_MSG_TIP_HAMMER_3]		MSG_MenuTip_Hammer3,
    [PAUSE_MSG_TIP_STAR_POWER]		MSG_MenuTip_StarPower,
    [PAUSE_MSG_TIP_STAR_POINTS]		MSG_MenuTip_StarPoints,
    [PAUSE_MSG_TIP_COINS]		    MSG_MenuTip_Coins,
    [PAUSE_MSG_TIP_SECRETS]		    MSG_MenuTip_Secrets,
    [PAUSE_MSG_TIP_STAR_PIECES]		MSG_MenuTip_StarPieces,
    [PAUSE_MSG_TIP_TIME]		    MSG_MenuTip_Time,
    [PAUSE_MSG_LBL_COINS]		    (s32) gPauseMsg_32,
    [PAUSE_MSG_LBL_STAR_POINTS]		(s32) gPauseMsg_33,
    [PAUSE_MSG_LBL_STAR_PIECES]		(s32) gPauseMsg_34,
    [PAUSE_MSG_LBL_TIME]		    (s32) gPauseMsg_35,
    [PAUSE_MSG_LBL_HP]		        (s32) gPauseMsg_36,
    [PAUSE_MSG_LBL_FP]		        (s32) gPauseMsg_37,
    [PAUSE_MSG_LBL_BP]		        (s32) gPauseMsg_38,
    [PAUSE_MSG_SLASH]		        (s32) gPauseMsg_39,
    [PAUSE_MSG_DOT]		            (s32) gPauseMsg_3A,
    [PAUSE_MSG_3B]		            (s32) gPauseMsg_3B,
    [PAUSE_MSG_3C]		            (s32) gPauseMsg_3C,
    [PAUSE_MSG_3D]		            (s32) gPauseMsg_3D,
    [PAUSE_MSG_3E]		            (s32) gPauseMsg_3E,
    [PAUSE_MSG_3F]		            (s32) gPauseMsg_3F,
    [PAUSE_MSG_40]		            (s32) gPauseMsg_40,
    [PAUSE_MSG_41]		            (s32) gPauseMsg_41,
    [PAUSE_MSG_42]		            (s32) gPauseMsg_42,
    [PAUSE_MSG_MARIO]		        (s32) gPauseMsg_43,
    [PAUSE_MSG_LEVEL]		        (s32) gPauseMsg_44,
    [PAUSE_MSG_NO_BADGE]		    MSG_MenuTip_None,
    [PAUSE_MSG_BADGE_BP]		    (s32) gPauseMsg_46,
    [PAUSE_MSG_ALL_BADGES]		    (s32) gPauseMsg_47,
    [PAUSE_MSG_ACTIVE]		        (s32) gPauseMsg_48,
    [PAUSE_MSG_BADGES]		        (s32) gPauseMsg_49,
    [PAUSE_MSG_NOT_ENOUGH_BP]		(s32) gPauseMsg_4A,
    [PAUSE_MSG_DONT_WEAR_MORE]		(s32) gPauseMsg_4B,
    [PAUSE_MSG_BAGDE_DESC_ALL]		MSG_MenuTip_BadgeTab_All,
    [PAUSE_MSG_BAGDE_DESC_ACTIVE]   MSG_MenuTip_BadgeTab_Equipped,
    [PAUSE_MSG_BAGDE_DESC_NONE]		MSG_MenuTip_None,
    [PAUSE_MSG_KEY_ITEMS]		    (s32) gPauseMsg_4F,
    [PAUSE_MSG_CONSUMABLES]		    (s32) gPauseMsg_50,
    [PAUSE_MSG_DESC_CONSUMABLES]    MSG_MenuTip_ItemTab_Consumables,
    [PAUSE_MSG_DESC_KEY_ITEMS]		MSG_MenuTip_ItemTab_KeyItems,
    [PAUSE_MSG_PARTNER_HP]		    (s32) gPauseMsg_53,
    [PAUSE_MSG_PARTNER_FP]		    (s32) gPauseMsg_54,
    [PAUSE_MSG_PARTNER_ABILITIES]   (s32) gPauseMsg_55,
    [PAUSE_MSG_UNKNOWN_SPIRIT]      (s32) gPauseMsg_56,
};

Gfx* gPauseDLLabels[] = {
    [PAUSE_LBL_HP]        gPauseDLBannerHp,
    [PAUSE_LBL_FP]        gPauseDLBannerFp,
    [PAUSE_LBL_BP]        gPauseDLBannerBp,
    [PAUSE_LBL_BOOTS]     gPauseDLBannerBoots,
    [PAUSE_LBL_HAMMER]    gPauseDLBannerHammer,
    [PAUSE_LBL_ENERGY]    gPauseDLBannerStarEnergy,
    [PAUSE_LBL_STATS]     gPauseDLStatsBar,
    [PAUSE_LBL_AVAILABLE] gPauseDLAvailable,
    [PAUSE_LBL_ABILITIES] gPauseDLCheckAbilities,
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

    gSPDisplayList(gMainGfxPos++, gPauseDLLabels[index]);
    pause_draw_rect(x * 4, y * 4, (x + xOffset) * 4, (y + 16) * 4, 0, 0, 0, 0x400, 0x400);
}

BSS s8 gPauseBufferPal1[512];
BSS s8 gPauseBufferImg1[15752];
BSS s8 gPauseBufferPal2[512];
BSS s8 gPauseBufferImg2[15752];
