#include "osr_00.h"
#include "ld_addrs.h"
#include "charset/peach_letter.png.h"

#include "sprite/npc/Luigi.h"

#include "world/common/atomic/ApplyTint.inc.c"

API_CALLABLE(N(func_80240678_AACEA8)) {
    Bytecode* args = script->ptrReadPos;
    s32 primR = *args++;
    s32 primG = *args++;
    s32 primB = *args++;
    s32 envR = *args++;
    s32 envG = *args++;
    s32 envB = *args++;
    mdl_set_remap_tint_params(primR, primG, primB, envR, envG, envB);
    return ApiStatus_DONE2;
}

BSS IMG_BIN N(PeachLetterImg)[charset_peach_letter_png_width * charset_peach_letter_png_height];
BSS PAL_BIN N(PeachLetterPal)[0x100];
MAP_STATIC_PAD(2, letter);
BSS MessageImageData N(MsgImage);

// TODO look into + 1 here...
API_CALLABLE(N(func_802406E0_AACF10)) {
    s8* romStart = charset_ROM_START;
    u8* rasterOffset = charset_peach_letter_png;
    u16* paletteOffset = (u16*) charset_peach_letter_pal + 1; // todo ???

    dma_copy(romStart + (s32)rasterOffset, romStart + (s32)rasterOffset + sizeof(N(PeachLetterImg)), &N(PeachLetterImg));
    dma_copy(romStart + (s32)paletteOffset, romStart + (s32)paletteOffset + sizeof(N(PeachLetterPal)), &N(PeachLetterPal));

    N(MsgImage).raster   = N(PeachLetterImg);
    N(MsgImage).palette  = N(PeachLetterPal);
    N(MsgImage).width    = charset_peach_letter_png_width;
    N(MsgImage).height   = charset_peach_letter_png_height;
    N(MsgImage).format   = G_IM_FMT_CI;
    N(MsgImage).bitDepth = G_IM_SIZ_8b;
    set_message_images(&N(MsgImage));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_ShowInvitation) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 775)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 20, -19)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    EVT_CALL(N(func_80240678_AACEA8), 200, 200, 200, 40, 40, 40)
    EVT_CALL(N(func_802406E0_AACF10))
    EVT_WAIT(15 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0022, 160, 40)
    EVT_WAIT(12 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Intro_0023, 160, 40)
    EVT_WAIT(3)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_20"), kmr_20_ENTRY_1, TRANSITION_SLOW_FADE_TO_WHITE)
    EVT_WAIT(40 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_ApproachParty) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(675.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(3.5), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(60.0), 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, 0, -250, 150 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_RunBack)
        EVT_CALL(SetNpcPos, NPC_Luigi, 0, 0, 350)
        EVT_CALL(NpcMoveTo, NPC_Luigi, 0, -200, 150 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_IdleBack)
    EVT_END_THREAD
    EVT_WAIT(100 * DT)
    EVT_CALL(GotoMap, EVT_PTR("kkj_00"), kkj_00_ENTRY_5)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
