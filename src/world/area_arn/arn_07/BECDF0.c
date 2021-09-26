#include "arn_07.h"
#include "effects.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/tubbas_heart.h"

#include "world/common/StarSpiritEffectFunc.inc.c"

s32 N(itemList_80242040)[] = {
    ITEM_MYSTICAL_KEY,
    ITEM_NONE,
};

EvtSource N(80242048) = SCRIPT({
    FadeOutMusic(0, 1000);
    EVT_VAR(0) = 0;
    if (EVT_VAR(0) == 0) {
        DisablePlayerInput(TRUE);
        UseSettingsFrom(0, 145, 65, 0);
        SetCamSpeed(0, 0.6005859375);
        SetPanTarget(0, 145, 30, 0);
        GetCamDistance(0, EVT_VAR(1));
        EVT_VAR(1) -= 100;
        SetCamDistance(0, EVT_VAR(1));
        if (10000 != 10000) {
            GetCamPitch(0, EVT_VAR(2), EVT_VAR(3));
            SetCamPitch(0, EVT_VAR(2), 10000);
        }
        PanToTarget(0, 0, 1);
        N(StarSpiritEffectFunc2)(2, 50, 100, 31, -6, 145, 65, 0, 30, 0);
        spawn {
            N(StarSpiritEffectFunc3)();
        }
        spawn {
            sleep 1;
            PlaySound(0x80000067);
            N(StarSpiritEffectFunc1)();
            StopSound(0x80000067);
            PlaySoundAt(0xB2, 0, 145, 65, 0);
        }
        spawn {
            sleep 12;
            SetPlayerAnimation(0x1002A);
        }
        spawn {
            sleep 50;
            sleep 115;
            PlaySoundAt(0x137, 0, 145, 65, 0);
        }
        N(StarSpiritEffectFunc4)(1);
        spawn {
            sleep 80;
            SetPlayerAnimation(ANIM_10002);
        }
        EVT_VAR(1) += 100;
        SetCamDistance(0, EVT_VAR(1));
        SetPanTarget(0, 145, 0, 0);
        N(StarSpiritEffectFunc4)(2);
        GetPlayerPos(EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        UseSettingsFrom(0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        SetCamSpeed(0, 1.0);
        SetPanTarget(0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
    } else {
        N(StarSpiritEffectFunc5)(2, 145, 30, 0, 0);
        spawn {
            N(StarSpiritEffectFunc6)();
        }
        sleep 1;
    }
    N(StarSpiritEffectFunc4)(3);
    PlaySoundAtPlayer(312, 0);
    DisablePlayerInput(TRUE);
    EVT_STORY_PROGRESS = STORY_CH3_STAR_SPIRIT_RESCUED;
    GotoMapSpecial("kmr_23", 2, 14);
    sleep 100;
});

EvtSource N(80242498) = SCRIPT({
    EVT_VAR(0) = 1;
    if (EVT_VAR(0) == 0) {
        DisablePlayerInput(TRUE);
        UseSettingsFrom(0, 145, 65, 0);
        SetCamSpeed(0, 0.6005859375);
        SetPanTarget(0, 145, 30, 0);
        GetCamDistance(0, EVT_VAR(1));
        EVT_VAR(1) -= 100;
        SetCamDistance(0, EVT_VAR(1));
        if (10000 != 10000) {
            GetCamPitch(0, EVT_VAR(2), EVT_VAR(3));
            SetCamPitch(0, EVT_VAR(2), 10000);
        }
        PanToTarget(0, 0, 1);
        N(StarSpiritEffectFunc2)(2, 50, 100, 31, -6, 145, 65, 0, 30, 0);
        spawn {
            N(StarSpiritEffectFunc3)();
        }
        spawn {
            sleep 1;
            PlaySound(0x80000067);
            N(StarSpiritEffectFunc1)();
            StopSound(0x80000067);
            PlaySoundAt(0xB2, 0, 145, 65, 0);
        }
        spawn {
            sleep 12;
            SetPlayerAnimation(0x1002A);
        }
        spawn {
            sleep 50;
            sleep 115;
            PlaySoundAt(0x137, 0, 145, 65, 0);
        }
        N(StarSpiritEffectFunc4)(1);
        spawn {
            sleep 80;
            SetPlayerAnimation(ANIM_10002);
        }
        EVT_VAR(1) += 100;
        SetCamDistance(0, EVT_VAR(1));
        SetPanTarget(0, 145, 0, 0);
        N(StarSpiritEffectFunc4)(2);
        GetPlayerPos(EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        UseSettingsFrom(0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        SetCamSpeed(0, 1.0);
        SetPanTarget(0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
    } else {
        N(StarSpiritEffectFunc5)(2, 145, 30, 0, 0);
        spawn {
            N(StarSpiritEffectFunc6)();
        }
        sleep 1;
    }
    N(StarSpiritEffectFunc4)(3);
    PlaySoundAtPlayer(312, 0);
    DisablePlayerInput(TRUE);
    EVT_STORY_PROGRESS = STORY_CH3_STAR_SPIRIT_RESCUED;
    GotoMapSpecial("kmr_23", 2, 14);
    sleep 100;
});

EvtSource N(exitSingleDoor_802428D4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    EVT_VAR(0) = 0;
    EVT_VAR(1) = 10;
    EVT_VAR(2) = 29;
    EVT_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_08", 0);
    sleep 100;
});

EvtSource N(exitWalk_80242978) = EXIT_WALK_SCRIPT(60,  1, "arn_03",  0);

EvtSource N(exitWalk_802429D4) = EXIT_WALK_SCRIPT(60,  2, "mim_12",  1);

static const f64 rodata_alignment = 0.0;

EvtSource N(80242A30) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetPlayerPos(-28, 0, -333);
    SetNpcPos(NPC_PARTNER, -28, 0, -333);
    SetCamSpeed(0, 90.0);
    SetCamType(0, 0, 0);
    SetCamPitch(0, 25.0, -4.0);
    SetCamDistance(0, 1100);
    SetCamPosA(0, 500, 0);
    SetCamPosB(0, 0, -500);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 5, 0, -147);
    PanToTarget(0, 0, 1);
    RotateModel(29, 80, 0, -1, 0);
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    SetNpcJumpscale(NPC_TUBBAS_HEART, 2.5);
    NpcJump0(NPC_TUBBAS_HEART, 0, 20, -120, 8);
    sleep 1;
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 0, 10, -60, 12);
    sleep 1;
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 0, 0, 0, 12);
    sleep 1;
    SetNpcVar(0, 0, 0);
    spawn {
        loop {
            PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
            NpcJump0(NPC_TUBBAS_HEART, 0, 0, 0, 10);
            sleep 1;
            GetNpcVar(0, 0, EVT_VAR(0));
            if (EVT_VAR(0) == 1) {
                break loop;
            }
        }
        SetNpcVar(0, 0, 2);
    }
    spawn {
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(29, EVT_VAR(0), 0, -1, 0);
            sleep 1;
            if (EVT_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(10, 450, 0);
    }
    NpcFaceNpc(NPC_TUBBAS_HEART, NPC_WORLD_TUBBA, 0);
    SpeakToPlayer(NPC_TUBBAS_HEART, NPC_ANIM_tubbas_heart_Palette_00_Anim_A, NPC_ANIM_tubbas_heart_Palette_00_Anim_1, 5, MESSAGE_ID(0x0E, 0x00C7));
    SetNpcVar(0, 0, 1);
    loop {
        GetNpcVar(0, 0, EVT_VAR(0));
        if (EVT_VAR(0) == 2) {
            break loop;
        }
        sleep 1;
    }
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 75, 0, 10, 12);
    sleep 1;
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 150, 0, 20, 12);
    sleep 1;
    spawn {
        sleep 4;
        SetCamSpeed(0, 90.0);
        SetCamPitch(0, 2.0, -9.0);
        SetCamDistance(0, 700);
        SetCamPosA(0, 500, 0);
        SetCamPosB(0, 0, -500);
        SetCamPosC(0, 0, 0);
        SetPanTarget(0, 65, 0, -137);
        PanToTarget(0, 0, 1);
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM_world_tubba_Palette_00_Anim_22);
    }
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 298, 56, 31, 18);
    SetNpcPos(NPC_TUBBAS_HEART, 0, -1000, 0);
    EnableNpcShadow(NPC_TUBBAS_HEART, FALSE);
    spawn {
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM_world_tubba_Palette_00_Anim_23);
        sleep 20;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM_world_tubba_Palette_00_Anim_6);
    }
    sleep 20;
    spawn {
        PlaySoundAtCollider(10, 449, 0);
        MakeLerp(0, 80, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(29, EVT_VAR(0), 0, -1, 0);
            sleep 1;
            if (EVT_VAR(1) == 0) {
                break loop;
            }
        }
    }
    spawn {
        sleep 30;
        UseSettingsFrom(0, 236, 0, -46);
        SetCamSpeed(0, 4.0);
        SetCamPitch(0, 8.0, -9.0);
        SetCamDistance(0, 450);
        SetPanTarget(0, 250, 0, -46);
        PanToTarget(0, 0, 1);
    }
    ModifyColliderFlags(0, 10, 0x7FFFFE00);
    SetPlayerPos(0, 20, -195);
    SetNpcPos(NPC_PARTNER, 0, 20, -195);
    EnablePartnerAI();
    PlayerMoveTo(0, 0, 45);
    ModifyColliderFlags(1, 10, 0x7FFFFE00);
    spawn {
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(29, EVT_VAR(0), 0, -1, 0);
            sleep 1;
            if (EVT_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(10, 450, 0);
    }
    PlayerMoveTo(200, 0, 35);
    sleep 5;
    SpeakToPlayer(NPC_WORLD_TUBBA, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 0, MESSAGE_ID(0x0E, 0x00C8));
    SetNpcVar(1, 0, 1);
    sleep 30;
    DisablePlayerInput(FALSE);
});

EvtSource N(802433C8) = SCRIPT({
    bind N(exitWalk_80242978) TRIGGER_FLOOR_ABOVE 5;
    bind N(exitWalk_802429D4) TRIGGER_FLOOR_ABOVE 1;
    if (EVT_STORY_PROGRESS < STORY_CH3_UNLOCKED_WINDY_MILL) {
        bind_padlock N(802439B0) TRIGGER_WALL_PRESS_A entity(0) N(itemList_80242040);
    } else {
        bind N(exitSingleDoor_802428D4) TRIGGER_WALL_PRESS_A 10;
    }
});

EvtSource N(enterWalk_8024346C) = SCRIPT({
    GetEntryID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            if (EVT_STORY_PROGRESS == STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
                await N(80242A30);
                spawn N(802433C8);
            } else {
                EVT_VAR(2) = 29;
                EVT_VAR(3) = 1;
                await EnterSingleDoor;
                spawn N(802433C8);
            }
        }
        == 1 {
            EVT_VAR(0) = N(802433C8);
            spawn EnterWalk;
            sleep 1;
        }
        == 2 {
            EVT_VAR(0) = N(802433C8);
            spawn EnterWalk;
            sleep 1;
        }
        == 3 {
            spawn N(802433C8);
            sleep 1;
        }
    }
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    EVT_SAVE_FLAG(1977) = 1;
    match EVT_STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            MakeNpcs(0, N(npcGroupList_802478B8));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            MakeNpcs(0, N(npcGroupList_8024787C));
        }
        == STORY_CH3_BEGAN_PEACH_MISSION {
            MakeNpcs(0, N(npcGroupList_802478E8));
        } else {
            MakeNpcs(0, N(npcGroupList_802478B8));
        }
    }
    await N(makeEntities);
    if (EVT_STORY_PROGRESS == STORY_CH3_DEFEATED_TUBBA_BLUBBA) {
        spawn N(80242498);
    }
    spawn N(enterWalk_8024346C);
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) == 3) {
        sleep 65;
    }
    spawn N(80243790);
    spawn N(80241F10);
    UseDoorSounds(0);
    SetCamSpeed(0, 0.30078125);
});
