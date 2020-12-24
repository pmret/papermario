#include "kmr_03.h"

Script M(Script_80242340) = SCRIPT({
    UseSettingsFrom(0, 0xFFFFFEF2, 20, 0xFFFFFFB0);
    SetPanTarget(0, 0xFFFFFEF2, 20, 0xFFFFFFB0);
    SetCamDistance(0, 700.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    if (SI_SAVE_VAR(0) >= 0xFFFFFF89) {
        SetPlayerPos(0, 0xFFFFFC18, 0);
        DisablePlayerInput(1);
        SetPlayerPos(0xFFFFFF20, 20, 0xFFFFFFB0);
        SetNpcPos(0xFFFFFFFC, 0xFFFFFF20, 20, 0xFFFFFFB0);
        sleep 20;
        SetCamSpeed(0, 3.0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(0);
        return;
    }
    DisablePlayerInput(1);
    DisablePlayerPhysics(1);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerPos(SI_VAR(0), 0xFFFFFC18, SI_VAR(2));
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
    HidePlayerShadow(1);
    SetPlayerAnimation(0x10002);
    SetPlayerPos(0xFFFFFF20, 120, 0xFFFFFFB0);
    InterpPlayerYaw(90, 0);
0: // TODO: this is a do..while
    sleep 1;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 0xFFFFFFFE;
    SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(1) > 86) {
        goto 0;
    }
    SetPlayerPos(0xFFFFFECA, 20, 0xFFFFFFB0);
    spawn {
        sleep 20;
        SetPanTarget(0, 0xFFFFFECA, 20, 0xFFFFFFB0);
        SetCamSpeed(0, 0.2001953125);
        PanToTarget(0, 0, 1);
    }
    0x802D286C(0x2800);
    0x802D2520(0x10002, 5, 5, 1, 1, 0);
    sleep 100;
    WaitForCam(0, 1.0);
    0x802D2520(0x10002, 0, 0, 0, 0, 0);
    HidePlayerShadow(0);
    SetPlayerAnimation(0x10006);
    sleep 10;
    SetPlayerAnimation(0x10007);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerJumpscale(1.0);
    PlayerJump(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    SetPlayerAnimation(0x10002);
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
    DisablePlayerPhysics(0);
    DisablePlayerInput(0);
});
