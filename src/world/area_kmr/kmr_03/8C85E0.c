#include "kmr_03.h"

EvtSource N(80242340) = SCRIPT({
    UseSettingsFrom(0, -270, 20, -80);
    SetPanTarget(0, -270, 20, -80);
    SetCamDistance(0, 700.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    if (SI_STORY_PROGRESS >= STORY_CH0_FOUND_HAMMER) {
        SetPlayerPos(0, -1000, 0);
        DisablePlayerInput(TRUE);
        SetPlayerPos(-224, 20, -80);
        SetNpcPos(NPC_PARTNER, -224, 20, -80);
        sleep 20;
        SetCamSpeed(0, 3.0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
        return;
    }
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerPos(SI_VAR(0), -1000, SI_VAR(2));
    sleep 30;
    SetCamDistance(0, 220);
    SetCamSpeed(0, 1.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    spawn {
        sleep 18;
        PlaySoundAtPlayer(373, 0);
        sleep 30;
        PlaySoundAtPlayer(374, 0);
        sleep 28;
        PlaySoundAtPlayer(373, 0);
    }
    HidePlayerShadow(TRUE);
    SetPlayerAnimation(ANIM_10002);
    SetPlayerPos(-224, 120, -80);
    InterpPlayerYaw(90, 0);
0:
    sleep 1;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += -2;
    SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(1) > 86) {
        goto 0;
    }
    SetPlayerPos(-310, 20, -80);
    spawn {
        sleep 20;
        SetPanTarget(0, -310, 20, -80);
        SetCamSpeed(0, 0.2001953125);
        PanToTarget(0, 0, 1);
    }
    func_802D286C(10240);
    func_802D2520(ANIM_10002, 5, 5, 1, 1, 0);
    sleep 100;
    WaitForCam(0, 1.0);
    func_802D2520(ANIM_10002, 0, 0, 0, 0, 0);
    HidePlayerShadow(FALSE);
    SetPlayerAnimation(ANIM_BEFORE_JUMP);
    sleep 10;
    SetPlayerAnimation(ANIM_MIDAIR_STILL);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerJumpscale(1.0);
    PlayerJump(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    SetPlayerAnimation(ANIM_10002);
    spawn {
        SetCamSpeed(0, 3.0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
    }
    sleep 30;
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
});
