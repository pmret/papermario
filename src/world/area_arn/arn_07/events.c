#include "arn_07.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/world_skolar.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/bootler.h"

Script N(80243790) = SCRIPT({
    spawn N(802437AC);
});

Script N(802437AC) = SCRIPT({
    SI_VAR(0) = 0.0;
    SI_VAR(1) = 30;
    PlaySoundAtModel(23, 0x8000004A, 0);
0:
    SI_VAR(0) += 1.0;
    N(func_80240800_BED5F0)();
    RotateModel(27, SI_VAR(0), 0, 0, 1);
    sleep 1;
    SI_VAR(1) -= 1;
    if (SI_VAR(1) > 0) {
        goto 0;
    }
    SI_VAR(1) = 30;
    RandInt(100, SI_VAR(2));
    if (SI_VAR(2) > 10) {
        goto 0;
    }
    SI_VAR(2) = 1.0;
    loop 50 {
        SI_VAR(2) -= 0.0107421875;
        SI_VAR(0) +=f SI_VAR(2);
        RotateModel(27, SI_VAR(0), 0, 0, 1);
        sleep 1;
    }
    loop 50 {
        SI_VAR(2) += 0.0107421875;
        SI_VAR(0) +=f SI_VAR(2);
        RotateModel(27, SI_VAR(0), 0, 0, 1);
        sleep 1;
    }
    SI_VAR(1) = 30;
    goto 0;
});

Script N(802439B0) = SCRIPT({
    group 0;
    func_802D5830(1);
    func_802D6420();
    if (SI_VAR(0) == 0) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00D8), 160, 40);
        func_802D6954();
        func_802D5830(0);
        return;
    }
    if (SI_VAR(0) == -1) {
        func_802D6954();
        func_802D5830(0);
        return;
    }
    FindKeyItem(31, SI_VAR(0));
    RemoveKeyItemAt(SI_VAR(0));
    func_802D6954();
    STORY_PROGRESS = STORY_CH3_UNLOCKED_WINDY_MILL;
    N(GetEntityPosition)(SI_MAP_VAR(0), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlaySoundAt(0x269, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) = SI_MAP_VAR(0);
    N(SetEntityFlags100000)();
    func_802D5830(0);
    unbind;
});

Script N(80243B28) = SCRIPT({
    bind N(exitSingleDoor_802428D4) to TRIGGER_WALL_PRESS_A 10;
});

Script N(makeEntities) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH3_UNLOCKED_WINDY_MILL) {
        MakeEntity(0x802BCD68, 10, 30, -155, 0, MAKE_ENTITY_END);
        AssignScript(N(80243B28));
        SI_MAP_VAR(0) = SI_VAR(0);
    }
});

f32 N(D_80243BC0_BF09B0)[] = {
     4.5f, 3.5f, 2.6f, 2.0f,
     1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80243BD8) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .unk_14 = 3,
    .chaseSpeed = 4.0f,
    .unk_1C = { .s = 5 },
    .unk_20 = 1,
    .chaseRadius = 150.0f,
    .unk_2C = 1,
};

Script N(npcAI_80243C08) = SCRIPT({
    SetSelfVar(0, 1);
    SetSelfVar(5, -850);
    SetSelfVar(6, 60);
    SetSelfVar(1, 700);
    N(func_80241C5C_BEEA4C)(N(npcAISettings_80243BD8));
});

NpcSettings N(npcSettings_80243C78) = {
    .height = 18,
    .radius = 20,
    .ai = &N(npcAI_80243C08),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
    .unk_2A = 1,
};

Script N(80243CA4) = SCRIPT({

});

Script N(80243CB4) = SCRIPT({

});

NpcSettings N(npcSettings_80243CC4) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80243CA4),
    .onDefeat = &N(80243CB4),
    .level = 13,
};

NpcSettings N(npcSettings_80243CF0) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80243D1C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80243D48) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80243D74) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_80243DA0) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

Script N(80243DCC) = SCRIPT({
    loop {
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
        ShakeCam(0, 0, 3, 0.80078125);
    }
});

Script N(80243E24) = SCRIPT({
    DisablePlayerInput(TRUE);
    UseSettingsFrom(0, 236, 0, -46);
    SetCamSpeed(0, 90.0);
    SetPanTarget(0, 250, 0, -46);
    PanToTarget(0, 0, 1);
    SetPlayerAnimation(ANIM_10002);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_8));
    SetNpcYaw(NPC_SELF, 90);
    sleep 10;
    SpeakToPlayer(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_12), NPC_ANIM(world_tubba, Palette_00, Anim_8), 5, MESSAGE_ID(0x0E, 0x00CA));
    sleep 10;
    InterpNpcYaw(NPC_SELF, 270, 0);
    sleep 10;
    SpeakToPlayer(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_12), NPC_ANIM(world_tubba, Palette_00, Anim_8), 5, MESSAGE_ID(0x0E, 0x00CB));
    SetCamDistance(0, 300);
    SetCamSpeed(0, 2.0);
    SetCamPitch(0, 5.0, -16.0);
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    WaitForCam(0, 1.0);
});

Script N(80243FE8) = SCRIPT({
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_22));
    sleep 15;
    loop 4 {
        PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
        SetNpcVar(3, 0, 1);
        sleep 4;
        PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
        SetNpcVar(6, 0, 1);
        sleep 4;
        PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
        SetNpcVar(2, 0, 1);
        sleep 6;
        PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
        SetNpcVar(4, 0, 1);
        sleep 8;
        PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
        SetNpcVar(5, 0, 1);
        sleep 6;
        PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
        SetNpcVar(7, 0, 1);
        sleep 6;
    }
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_23));
    sleep 30;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_22));
    sleep 10;
    PlaySoundAtNpc(NPC_SELF, 0xB0000010, 0);
    SetNpcVar(3, 0, 1);
    sleep 15;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_21));
    sleep 45;
    UseSettingsFrom(0, 236, 0, -46);
    SetCamSpeed(0, 90.0);
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 50;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PanToTarget(0, 0, 1);
    sleep 5;
    SetPlayerAnimation(ANIM_STAND_STILL);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_F));
    SpeakToPlayer(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_12), NPC_ANIM(world_tubba, Palette_00, Anim_8), 0, MESSAGE_ID(0x0E, 0x00CC));
    spawn {
        sleep 5;
        SetCamSpeed(0, 90.0);
        loop 40 {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    spawn {
        func_802CF56C(2);
        loop 45 {
            PlayerFaceNpc(-1, 1);
        }
    }
    SI_VAR(10) = spawn N(80243DCC);
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 800;
    NpcMoveTo(NPC_SELF, SI_VAR(0), SI_VAR(2), 80);
    kill SI_VAR(10);
    SetNpcPos(NPC_SELF, 0, -1000, 0);
    EnableNpcShadow(NPC_SELF, FALSE);
    STORY_PROGRESS = STORY_CH3_DEFEATED_TUBBA_BLUBBA;
    SetMusicTrack(0, SONG_CHEERFUL_BOOS_MANSION, 0, 8);
    GetCurrentPartnerID(SI_VAR(6));
    if (SI_VAR(6) == 9) {
        SI_VAR(5) = -4;
        func_802CF56C(0);
        DisablePartnerAI(0);
        SetNpcPos(NPC_PARTNER, 257, 25, 0);
    }
    SetCamSpeed(0, 90.0);
    SetCamDistance(0, 300);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 10;
    if (SI_VAR(6) != 9) {
        SI_VAR(5) = 8;
        SetNpcPos(NPC_WORLD_BOW, 257, 25, 0);
        func_802CFD30(NPC_WORLD_BOW, 7, 0, 0, 0, 0);
        NpcFacePlayer(NPC_WORLD_BOW, 0);
        MakeLerp(0, 240, 20, 0);
        loop {
            UpdateLerp();
            func_802CFD30(NPC_WORLD_BOW, 7, SI_VAR(0), 0, 0, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        func_802CF56C(0);
    }
    sleep 10;
    spawn {
        if (SI_VAR(6) != 9) {
            DisablePartnerAI(0);
            sleep 1;
            NpcFaceNpc(NPC_PARTNER, NPC_WORLD_BOW, 0);
            sleep 5;
        }
    }
    SpeakToPlayer(SI_VAR(5), NPC_ANIM(world_bow, Palette_00, Anim_B), NPC_ANIM(world_bow, Palette_00, Anim_B), 0, MESSAGE_ID(0x0E, 0x00CD));
    InterpPlayerYaw(270, 0);
    sleep 10;
    GetNpcPos(SI_VAR(5), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += -20;
    SetCamProperties(0, 2.0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 300.0, 15.0, -7.0);
    PlayerFaceNpc(SI_VAR(5), 0);
    sleep 10;
    SpeakToPlayer(SI_VAR(5), NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00CE));
    ShowChoice(1966093);
    if (SI_VAR(0) == 0) {
        ContinueSpeech(SI_VAR(5), NPC_ANIM(world_bow, Palette_00, Anim_B), NPC_ANIM(world_bow, Palette_00, Anim_B), 0, MESSAGE_ID(0x0E, 0x00CF));
    } else {
        ContinueSpeech(SI_VAR(5), NPC_ANIM(world_bow, Palette_00, Anim_B), NPC_ANIM(world_bow, Palette_00, Anim_B), 0, MESSAGE_ID(0x0E, 0x00D0));
    }
    SpeakToPlayer(SI_VAR(5), NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00D1));
    UseSettingsFrom(0, 175, 0, 0);
    SetCamSpeed(0, 4.0);
    SetPanTarget(0, 175, 0, 0);
    WaitForCam(0, 1.0);
    SetNpcPos(NPC_BOOTLER, 93, 160, -6);
    InterpNpcYaw(NPC_BOOTLER, 90, 0);
    spawn {
        sleep 10;
        InterpPlayerYaw(270, 0);
    }
    spawn {
        if (SI_VAR(6) != 9) {
            sleep 12;
            InterpNpcYaw(NPC_PARTNER, 270, 0);
        }
    }
    MakeLerp(160, 31, 70, 0);
    loop {
        UpdateLerp();
        SetNpcPos(NPC_BOOTLER, 93, SI_VAR(0), -6);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    spawn {
        if (SI_VAR(6) != 9) {
            InterpNpcYaw(NPC_PARTNER, 90, 0);
        }
    }
    SpeakToPlayer(SI_VAR(5), NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00D2));
    spawn {
        if (SI_VAR(6) != 9) {
            sleep 12;
            InterpNpcYaw(NPC_PARTNER, 270, 0);
        }
    }
    sleep 10;
    InterpPlayerYaw(270, 0);
    spawn N(80242048);
    sleep 20;
    spawn {
        if (SI_VAR(6) != 9) {
            MakeLerp(240, 0, 20, 0);
            loop {
                UpdateLerp();
                func_802CFD30(NPC_WORLD_BOW, 7, SI_VAR(0), 0, 0, 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            SetNpcPos(NPC_WORLD_BOW, 0, -1000, 0);
            EnablePartnerAI();
        } else {
            sleep 20;
            ClearPartnerMoveHistory(-4);
            EnablePartnerAI();
        }
        sleep 8;
        func_802CF56C(2);
    }
    sleep 20;
    DisablePlayerInput(FALSE);
});

Script N(idle_80244C54) = SCRIPT({
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            break loop;
        }
        sleep 1;
    }
    StartBossBattle(11);
});

Script N(idle_80244CC8) = SCRIPT({
10:
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            break loop;
        }
        sleep 1;
    }
    spawn {
        SI_VAR(0) = 0.5;
        MakeLerp(50, 80, 15, 0);
        loop {
            UpdateLerp();
            SI_VAR(2) =f SI_VAR(0);
            SI_VAR(2) /=f 100;
            SetNpcScale(NPC_SELF, SI_VAR(2), SI_VAR(2), SI_VAR(2));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    spawn {
        RandInt(80, SI_VAR(2));
        RandInt(10, SI_VAR(3));
        SI_VAR(3) += 5;
        MakeLerp(SI_VAR(2), 240, SI_VAR(3), 0);
        loop {
            UpdateLerp();
            func_802CFD30(NPC_SELF, 7, SI_VAR(0), 0, 0, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    SetNpcPos(NPC_SELF, 293, 59, 21);
    sleep 1;
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetNpcJumpscale(NPC_SELF, -0.2998046875);
    RandInt(100, SI_VAR(3));
    SI_VAR(0) -= SI_VAR(3);
    SI_VAR(1) += 100;
    NpcJump0(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    SetNpcPos(NPC_SELF, 0, -1000, 0);
    SetSelfVar(0, 0);
    goto 10;
});

Script N(defeat_80244FB8) = SCRIPT({
    SetEncounterStatusFlags(2, 1);
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 1, 8);
            await N(80243E24);
            spawn N(80243FE8);
        }
        == 1 {}
        == 2 {
        }
    }
});

Script N(init_80245058) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(init_80245090) = SCRIPT({
    SetSelfVar(0, 0);
    BindNpcIdle(NPC_SELF, N(idle_80244C54));
    BindNpcDefeat(NPC_SELF, N(defeat_80244FB8));
    if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(init_80245104) = SCRIPT({
    SetSelfVar(0, 0);
    BindNpcIdle(NPC_SELF, N(idle_80244CC8));
    if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(init_80245164) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(init_8024519C) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
        RemoveNpc(NPC_SELF);
    }
});

NpcAnimID N(extraAnimationList_802451D4)[] = {
    NPC_ANIM(world_tubba, Palette_00, Anim_0),
    NPC_ANIM(world_tubba, Palette_00, Anim_22),
    NPC_ANIM(world_tubba, Palette_00, Anim_23),
    NPC_ANIM(world_tubba, Palette_00, Anim_6),
    NPC_ANIM(world_tubba, Palette_00, Anim_10),
    NPC_ANIM(world_tubba, Palette_00, Anim_8),
    NPC_ANIM(world_tubba, Palette_00, Anim_F),
    NPC_ANIM(world_tubba, Palette_00, Anim_12),
    ANIM_END,
};

NpcAnimID N(extraAnimationList_802451F8)[] = {
    NPC_ANIM(boo, Palette_00, Anim_0),
    ANIM_END,
};

NpcAnimID N(extraAnimationList_80245200)[] = {
    NPC_ANIM(boo, Palette_01, Anim_0),
    ANIM_END,
};

NpcAnimID N(extraAnimationList_80245208)[] = {
    NPC_ANIM(bootler, Palette_00, Anim_1),
    ANIM_END,
};

Script N(idle_80245210) = SCRIPT({
    loop {
        loop 10 {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) -= 1;
            SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
        loop 10 {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
});

Script N(80245304) = SCRIPT({
    DisablePartnerAI(0);
    func_802CF56C(2);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = SI_VAR(0);
    SI_VAR(3) += -50;
    SI_VAR(4) = SI_VAR(1);
    SI_VAR(4) += 26;
    SetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(3), SI_VAR(4), SI_VAR(2));
    PlayerFaceNpc(13, 0);
    NpcFaceNpc(NPC_PARTNER, NPC_WORLD_SKOLAR, 0);
    SI_VAR(0) += -25;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 475.0);
    SetCamPitch(0, 18, -8);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 1;
    WaitForPlayerInputEnabled();
    DisablePlayerInput(TRUE);
    sleep 40;
    SpeakToPlayer(NPC_WORLD_SKOLAR, NPC_ANIM(world_skolar, Palette_00, Anim_2), NPC_ANIM(world_skolar, Palette_00, Anim_1), 512, MESSAGE_ID(0x0E, 0x00D3));
    SetCamDistance(0, 300.0);
    SetCamPitch(0, 18, -9);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    MakeLerp(0, 360, 10, 0);
    loop {
        UpdateLerp();
        SetNpcRotation(NPC_WORLD_SKOLAR, 0, SI_VAR(0), 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    EnableNpcAI(13, 0);
    SetNpcAnimation(NPC_WORLD_SKOLAR, NPC_ANIM(world_skolar, Palette_00, Anim_3));
    sleep 20;
    SetPlayerAnimation(ANIM_GOT_ITEM);
    PlaySoundAtPlayer(313, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = SI_VAR(1);
    SI_VAR(1) += 50;
    SI_VAR(2) += 10;
    SI_VAR(3) += 30;
    loop 5 {
        PlayEffect(0x11, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0);
        sleep 6;
        PlayEffect(0x11, 1, SI_VAR(0), SI_VAR(3), SI_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0);
        sleep 6;
    }
    sleep 20;
    PlaySoundAtPlayer(392, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(0x52, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 30, 0, 0, 0, 0, 0, 0, 0);
    sleep 30;
    SetPlayerAnimation(ANIM_10002);
    SetNpcAnimation(NPC_WORLD_SKOLAR, NPC_ANIM(world_skolar, Palette_00, Anim_1));
    EnableNpcAI(13, 1);
    PostChapter3StatUpdate();
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x0193), 160, 40);
    sleep 10;
    GetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 250.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    SpeakToPlayer(NPC_WORLD_SKOLAR, NPC_ANIM(world_skolar, Palette_00, Anim_2), NPC_ANIM(world_skolar, Palette_00, Anim_1), 512, MESSAGE_ID(0x0E, 0x00D4));
    sleep 10;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -25;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300.0);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    SpeakToPlayer(NPC_WORLD_SKOLAR, NPC_ANIM(world_skolar, Palette_00, Anim_2), NPC_ANIM(world_skolar, Palette_00, Anim_1), 512, MESSAGE_ID(0x0E, 0x00D5));
    SetNpcFlagBits(NPC_WORLD_SKOLAR, NPC_FLAG_40000, TRUE);
    spawn {
        loop 25 {
            GetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            PlayEffect(0x11, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 4;
        }
    }
    spawn {
        SI_VAR(2) = 0;
        SI_VAR(3) = 1800;
        MakeLerp(SI_VAR(2), SI_VAR(3), 100, 2);
        loop {
            UpdateLerp();
            SetNpcRotation(NPC_WORLD_SKOLAR, 0, SI_VAR(0), 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    spawn {
        GetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        SI_VAR(5) = SI_VAR(3);
        SI_VAR(5) += 180;
        MakeLerp(SI_VAR(3), SI_VAR(5), 100, 2);
        loop {
            UpdateLerp();
            SetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(2), SI_VAR(0), SI_VAR(4));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        SetNpcPos(NPC_WORLD_SKOLAR, 0, -1000, 0);
    }
    spawn {
        sleep 15;
        PlaySoundAtNpc(NPC_WORLD_SKOLAR, 0x2045, 0);
    }
    sleep 10;
    SetPlayerAnimation(0x1002A);
    sleep 90;
    ResetCam(0, 3);
    sleep 20;
    SetPlayerAnimation(ANIM_10002);
    STORY_PROGRESS = STORY_CH3_STAR_SPRIT_DEPARTED;
    spawn N(80241F10);
    EnablePartnerAI();
    DisablePlayerInput(FALSE);
});

Script N(init_80245C9C) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 3) {
        BindNpcIdle(NPC_SELF, N(idle_80245210));
        spawn N(80245304);
    } else {
        RemoveNpc(NPC_SELF);
    }
});

StaticNpc N(npcGroup_80245D0C)[] = {
    {
        .id = NPC_WORLD_TUBBA,
        .settings = &N(npcSettings_80243CF0),
        .pos = { 309.0f, 0.0f, 11.0f },
        .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000,
        .init = &N(init_80245090),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_tubba, Palette_00, Anim_6),
            NPC_ANIM(world_tubba, Palette_00, Anim_9),
            NPC_ANIM(world_tubba, Palette_00, Anim_C),
            NPC_ANIM(world_tubba, Palette_00, Anim_C),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
            NPC_ANIM(world_tubba, Palette_00, Anim_0),
        },
        .extraAnimations = N(extraAnimationList_802451D4),
    },
    {
        .id = NPC_TUBBAS_HEART,
        .settings = &N(npcSettings_80243CC4),
        .pos = { -10.0f, 50.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000,
        .init = &N(init_80245058),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
            NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        },
    },
};

StaticNpc N(npcGroup_802460EC)[] = {
    {
        .id = NPC_BOO0,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO1,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO2,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO3,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO4,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_00, Anim_1),
            NPC_ANIM(boo, Palette_00, Anim_2),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_1),
            NPC_ANIM(boo, Palette_00, Anim_1),
            NPC_ANIM(boo, Palette_00, Anim_0),
            NPC_ANIM(boo, Palette_00, Anim_0),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
        },
        .extraAnimations = N(extraAnimationList_802451F8),
    },
    {
        .id = NPC_BOO5,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_00, Anim_1),
            NPC_ANIM(boo, Palette_00, Anim_2),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_1),
            NPC_ANIM(boo, Palette_00, Anim_1),
            NPC_ANIM(boo, Palette_00, Anim_0),
            NPC_ANIM(boo, Palette_00, Anim_0),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
            NPC_ANIM(boo, Palette_00, Anim_3),
        },
        .extraAnimations = N(extraAnimationList_802451F8),
    },
};

StaticNpc N(npcGroup_80246C8C) = {
    .id = NPC_WORLD_BOW,
    .settings = &N(npcSettings_80243D1C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
    .init = &N(init_80245164),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(world_bow, Palette_00, Anim_1),
        NPC_ANIM(world_bow, Palette_00, Anim_2),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_1),
        NPC_ANIM(world_bow, Palette_00, Anim_1),
        NPC_ANIM(world_bow, Palette_00, Anim_0),
        NPC_ANIM(world_bow, Palette_00, Anim_0),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
        NPC_ANIM(world_bow, Palette_00, Anim_3),
    },
};

StaticNpc N(npcGroup_80246E7C) = {
    .id = NPC_BOOTLER,
    .settings = &N(npcSettings_80243D1C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
    .init = &N(init_8024519C),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(bootler, Palette_00, Anim_1),
        NPC_ANIM(bootler, Palette_00, Anim_2),
        NPC_ANIM(bootler, Palette_00, Anim_3),
        NPC_ANIM(bootler, Palette_00, Anim_3),
        NPC_ANIM(bootler, Palette_00, Anim_1),
        NPC_ANIM(bootler, Palette_00, Anim_1),
        NPC_ANIM(bootler, Palette_00, Anim_0),
        NPC_ANIM(bootler, Palette_00, Anim_0),
        NPC_ANIM(bootler, Palette_00, Anim_5),
        NPC_ANIM(bootler, Palette_00, Anim_6),
        NPC_ANIM(bootler, Palette_00, Anim_7),
        NPC_ANIM(bootler, Palette_00, Anim_8),
        NPC_ANIM(bootler, Palette_00, Anim_5),
        NPC_ANIM(bootler, Palette_00, Anim_6),
        NPC_ANIM(bootler, Palette_00, Anim_7),
        NPC_ANIM(bootler, Palette_00, Anim_8),
    },
    .extraAnimations = N(extraAnimationList_80245208),
};

Script N(init_8024706C) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER) {
        if (STORY_PROGRESS < STORY_CH3_STAR_SPIRIT_RESCUED) {
            RemoveNpc(NPC_SELF);
        }
    }
});

StaticNpc N(npcGroup_802470BC) = {
    .id = NPC_PARAGOOMBA0,
    .settings = &N(npcSettings_80243C78),
    .pos = { -216.0f, 60.0f, -10.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024706C),
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -216, 60, -10, 30, 0, -32767, 0, -216, 60, -10, 250 },
    .animations = {
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_3),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_5),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802472AC) = {
    .id = NPC_PARAGOOMBA1,
    .settings = &N(npcSettings_80243C78),
    .pos = { 0.0f, 60.0f, 150.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024706C),
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 0, 60, 150, 30, 0, -32767, 0, 0, 60, 150, 250 },
    .animations = {
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_3),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_5),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_8024749C) = {
    .id = NPC_PARAGOOMBA2,
    .settings = &N(npcSettings_80243C78),
    .pos = { 260.0f, 60.0f, 30.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024706C),
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 260, 60, 30, 30, 0, -32767, 0, 260, 60, 30, 250 },
    .animations = {
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_3),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_5),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_8024768C) = {
    .id = NPC_WORLD_SKOLAR,
    .settings = &N(npcSettings_80243D48),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245C9C),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_0),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
        NPC_ANIM(world_skolar, Palette_00, Anim_1),
    },
};

NpcGroupList N(npcGroupList_8024787C) = {
    NPC_GROUP(N(npcGroup_80245D0C), BATTLE_ID(14, 16, 0, 2)),
    NPC_GROUP(N(npcGroup_802460EC), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246C8C), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246E7C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_802478B8) = {
    NPC_GROUP(N(npcGroup_802470BC), BATTLE_ID(14, 6, 0, 2)),
    NPC_GROUP(N(npcGroup_802472AC), BATTLE_ID(14, 7, 0, 2)),
    NPC_GROUP(N(npcGroup_8024749C), BATTLE_ID(14, 8, 0, 2)),
    {},
};

NpcGroupList N(npcGroupList_802478E8) = {
    NPC_GROUP(N(npcGroup_8024768C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

void N(func_80240950_BED740)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}

#ifdef NON_MATCHING
void N(func_80240B00_BED8F0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f24;
    f32 posX, posY, posZ, posW;
    s32 var;
    f32 temp_f0;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_s4 = 0;

    f32 a = enemy->varTable[7];
    f32 temp_f2  = a / 100.0;
    f32 b = enemy->varTable[3];
    f32 temp_f26 = b / 100.0;
    f32 c = enemy->varTable[4];
    f32 temp_f20 = c / 100.0;
    f32 d = enemy->varTable[1];
    f32 temp_f22 = d / 100.0;

    enemy->varTable[4] = npc->pos.y * 100.0;
    temp_f24 = temp_f26 + temp_f2;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (temp_f22 < (temp_f24 - npc->pos.y)) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            test = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            npc->pos.y = test;
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY;
            phi_f4 += temp_f26;
            d = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            test = d;
            npc->pos.y = test;
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }
        //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);

        if (fabsf(phi_f4 - npc->pos.y) < 1.0) {
            npc->pos.y = phi_f4;
            enemy->varTable[0] &= ~0x10;
        }
    } else if (enemy->varTable[1] > 0) {
        temp_f0 = sin_deg(enemy->varTable[2]);
        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        }
        if (phi_v0) {
            npc->pos.y = posY + temp_f26 + (temp_f0 * temp_f22);
        } else {
            npc->pos.y = temp_f24 + (temp_f0 * temp_f22);
        }
        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1].s <= 0) {
                script->functionTemp[1].s = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    func_800494C0(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0].s = 10;
                    } else {
                        script->functionTemp[0].s = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1].s--;
        }
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            phi_s4 = 1;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | phi_s4) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            return;
        }
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1].s < 3)) {
                script->functionTemp[0].s = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_arn/arn_07/events", arn_07_func_80240B00_BED8F0, ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

void N(func_802411E8_BEDFD8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f24 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f26 = temp_f24 + (f32)((f32)enemy->varTable[7] / 100.0);
    s32 var;

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (enemy->varTable[1] > 0) {
        f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
        f32 sin_degrees = sin_deg(enemy->varTable[2]);
        s32 phi_v0;

        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        }

        if (phi_v0) {
            npc->pos.y = posY + temp_f24 + (sin_degrees * temp_f22);
        } else {
            npc->pos.y = temp_f26 + (sin_degrees * temp_f22);
        }

        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) && func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            npc->moveToPos.y = npc->pos.y;
            func_800494C0(npc, 0x2F4, 0x200000);
            if (enemy->npcSettings->unk_2A & 1) {
                script->functionTemp[0].s = 10;
            } else {
                script->functionTemp[0].s = 12;
            }
            return;
        }
    } else {
        enemy->varTable[9]--;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s > 0) {
            if (!(enemy->npcSettings->unk_2A & 0x10)) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
            }
            npc->duration = (rand_int(1000) % 11) + 5;
        } else {
            script->functionTemp[0].s = 0;
        }
    }
}

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_802415A4_BEE394)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80243BC0_BF09B0)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

void N(func_802417A8_BEE598)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    s32 phi_v0;
    f32 phi_f20;
    f32 a = enemy->varTable[3];
    f32 b = enemy->varTable[7];

    npc->jumpVelocity += npc->jumpScale;
    temp_f20 = a / 100.0;
    temp_f22 = b / 100.0;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->jumpVelocity >= 0.0) {
        npc->pos.y += npc->jumpVelocity;
        npc->currentAnim = enemy->animList[9];
        enemy->unk_07 = 0;
        if (!(npc->flags & 8)) {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        } else {
            phi_v0 = FALSE;
        }
        if (phi_v0) {
            temp_f2 = posY + temp_f20;
            if (temp_f2 <= npc->pos.y) {
                npc->pos.y = temp_f2;
                script->functionTemp[0].s = 0;
            }
        } else if (npc->pos.y >= npc->moveToPos.y) {
            script->functionTemp[0].s = 0;
        }
    } else if (npc->jumpVelocity < 0.0) {
        npc->duration++;
        if (npc->duration >= aiSettings->unk_20) {
            npc->duration = 0;
            phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            temp_f0_2 = get_clamped_angle_diff(npc->yaw, phi_f20);
            if (aiSettings->unk_1C.s < fabsf(temp_f0_2)) {
                phi_f20 = npc->yaw;
                if (temp_f0_2 < 0.0f) {
                    phi_f20 += -aiSettings->unk_1C.s;
                } else {
                    phi_f20 += aiSettings->unk_1C.s;
                }
            }
            npc->yaw = clamp_angle(phi_f20);
        }

        if (npc->flags & 8) {
            if (npc->pos.y + npc->jumpVelocity < temp_f22) {
                npc->pos.y = temp_f22;
                npc->jumpVelocity = 0.0f;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = (fabsf(npc->jumpVelocity) + npc->collisionHeight) + 10.0;
        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            if (posW <= (npc->collisionHeight + fabsf(npc->jumpVelocity))) {
                npc->jumpVelocity = 0.0f;
                npc->pos.y = posY;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        } else if (fabsf(npc->jumpVelocity) < ((npc->pos.y - temp_f22) + npc->collisionHeight)) {
            npc->pos.y = npc->pos.y + npc->jumpVelocity;
            return;
        }
        npc->jumpVelocity = 0.0f;
    }
}

void N(func_80241B38_BEE928)(Npc *npc, Enemy *enemy, ScriptInstance *script, NpcAISettings *aiSettings) {
    f32 posX, posY, posZ, posW;
    s32 temp_a1;
    s32 temp_v1;
    s32 phi_v0;

    script->functionTemp[0].s = 0;
    npc->duration = 0;
    temp_v1 = npc->flags & ~0x200;
    npc->flags = (npc->flags & ~0x200) | 0x800;
    if (enemy->territory->wander.isFlying) {
        npc->flags = temp_v1 | 0x808;
    } else {
        npc->flags = npc->flags & ~8;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    enemy->varTable[2] = 0;
    enemy->varTable[9] = 0;
    enemy->varTable[3] = ((posW * 100.0) + 0.5);
    enemy->varTable[7] = ((posY * 100.0) + 0.5);
    script->functionTemp[1].s = aiSettings->unk_14;
    enemy->unk_B0 |= 0x10;
}

ApiStatus N(func_80241C5C_BEEA4C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_34 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80241B38_BEE928)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240950_BED740)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240B00_BED8F0)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_802411E8_BEDFD8)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_802415A4_BEE394)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 14:
            N(func_802417A8_BEE598)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

ApiStatus PostChapter3StatUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(3);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

