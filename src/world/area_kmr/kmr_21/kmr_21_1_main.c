#include "kmr_21.h"

typedef struct TitleDataFile {
    /* 0x00 */ s32 img_offset_title;
    /* 0x04 */ s32 img_offset_copyright;
    /* 0x08 */ s32 img_offset_press_start;
    /* 0x0C */ unsigned char unk_0C[4];
    // end of header
    /* 0x10 */ s8 data[VLA];
} TitleDataFile; // size may vary

static TitleDataFile* TitleData;
static IMG_PTR TitleImage;

s32 TitlePrimAlpha = 0;
s32 TitlePosY = 106;

Gfx N(Gfx_TexSetup_TitleImage)[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetCombineMode(PM_CC_2E, PM_CC_2E),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsSPEndDisplayList(),
};

void worker_render_title_image(void) {
    s32 i;

    gSPDisplayList(gMainGfxPos++, N(Gfx_TexSetup_TitleImage));
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, TitlePrimAlpha);
    gDPPipeSync(gMainGfxPos++);

    for (i = 0; i < 56; i++) {
        gDPLoadTextureTile(gMainGfxPos++, &TitleImage[1600 * i], G_IM_FMT_RGBA, G_IM_SIZ_32b, 200, 112,
                           0, 0, 199, 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMainGfxPos++,
            /* ulx */ 60 * 4,
            /* uly */ (i * 2 + TitlePosY) * 4,
            /* lrx */ 260 * 4,
            /* lry */ ((i * 2 + 2) + TitlePosY) * 4,
            G_TX_RENDERTILE, 0, 0, 1024, 1024);
    }
    gDPPipeSync(gMainGfxPos++);
}

API_CALLABLE(N(LoadTitleImage)) {
    u32 assetSize;
    void* compressed = load_asset_by_name("title_data", &assetSize);
    TitleData = (TitleDataFile*) heap_malloc(assetSize);

    decode_yay0(compressed, TitleData);
    general_heap_free(compressed);
    TitleImage = (IMG_PTR)(TitleData->img_offset_title + (s32)TitleData);
    create_worker_frontUI(NULL, worker_render_title_image);
    return ApiStatus_DONE2;
}

#if !VERSION_PAL
API_CALLABLE(N(AwaitConfirmInput)) {
    u32 pressedButtons = gGameStatusPtr->pressedButtons[0];
    if (pressedButtons & (BUTTON_A | BUTTON_START)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
#endif

API_CALLABLE(N(SetTitlePrimAlpha)) {
    TitlePrimAlpha = script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetTitlePosY)) {
    TitlePosY = script->varTable[0];
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_ShowTitle) = {
    EVT_CALL(N(LoadTitleImage))
    EVT_WAIT(15 * DT)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 100 * DT, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetTitlePrimAlpha))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 106, 56, 100 * DT, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetTitlePosY))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30 * DT)
    EVT_CALL(MakeLerp, 255, 0, 50 * DT, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetTitlePrimAlpha))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(15 * DT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, -1000, 0, 0) //@bug? improper dispose location for player
    EVT_WAIT(1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 208, 208, 208)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 440)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 100)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 65)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_Scene_ShowTitle))
    EVT_RETURN
    EVT_END
};
