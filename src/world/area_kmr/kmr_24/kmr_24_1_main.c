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
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Choice_004D, 160, 40)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(N(SaveAndContinue))
            EVT_WAIT(10)
        EVT_CASE_EQ(1)
            EVT_CALL(N(SaveAndContinue))
            EVT_WAIT(10)
            EVT_CALL(N(ExitGame))
            EVT_WAIT(100)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_CALL(GotoMapSpecial, EVT_PTR("osr_03"), osr_03_ENTRY_4, TRANSITION_AFTER_SAVE_PROMPT)
    EVT_WAIT(100)
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
    EVT_EXEC(N(EVS_SaveAndContinue_Prompt))
    EVT_RETURN
    EVT_END
};
