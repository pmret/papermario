#include "kmr_24.h"
#include "fio.h"
#include "game_modes.h"

API_CALLABLE(N(ExitGame)) {
    s16 progress;
    s16 result;

    if (isInitialCall) {
        set_map_transition_effect(TRANSITION_BEGIN_OR_END_GAME);
        script->functionTemp[1] = 0;
    }

    progress = script->functionTemp[1];
    result = update_exit_map_screen_overlay(&progress);

    if (result == 0) {
        script->functionTemp[1] = progress;
        return ApiStatus_BLOCK;
    } else {
        set_game_mode(GAME_MODE_STARTUP);
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(SaveAndContinue)) {
    // push current map
    u16 curArea  = gGameStatusPtr->areaID;
    u16 curMap   = gGameStatusPtr->mapID;
    u16 curEntry = gGameStatusPtr->entryID;
    // save with map being osr_03, entry 4
    u16 areaID, mapID;
    get_map_IDs_by_name("osr_03", &areaID, &mapID);
    gGameStatusPtr->areaID  = areaID;
    gGameStatusPtr->mapID   = mapID;
    gGameStatusPtr->entryID = osr_03_ENTRY_4;
    fio_save_game(gGameStatusPtr->saveSlot);
    // and continue
    gGameStatusPtr->areaID  = curArea;
    gGameStatusPtr->mapID   = curMap;
    gGameStatusPtr->entryID = curEntry;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SaveAndContinue_Prompt) = {
    Wait(10)
    Call(ShowMessageAtScreenPos, MSG_Choice_004D, 160, 40)
    Switch(LVar0)
        CaseEq(0)
            Call(N(SaveAndContinue))
            Wait(10)
        CaseEq(1)
            Call(N(SaveAndContinue))
            Wait(10)
            Call(N(ExitGame))
            Wait(100)
        CaseEq(2)
    EndSwitch
    Call(GotoMapSpecial, Ref("osr_03"), osr_03_ENTRY_4, TRANSITION_AFTER_SAVE_PROMPT)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, -1000, 0, 0) //@bug? improper dispose location for player
    Wait(1)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EndIf
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 208, 208, 208)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 440)
    Call(SetCamPosA, CAM_DEFAULT, 0, 100)
    Call(SetCamPosB, CAM_DEFAULT, 0, 0)
    Call(SetCamPosC, CAM_DEFAULT, 0, 65)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Wait(1)
    Exec(N(EVS_SaveAndContinue_Prompt))
    Return
    End
};
