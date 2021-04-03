#include "arn_03.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/world_bow.h"

s32 D_80244A20[0x70];

Script N(exitWalk_80241830) = EXIT_WALK_SCRIPT(60,  0, "arn_07",  1);

Script N(exitWalk_8024188C) = EXIT_WALK_SCRIPT(60,  1, "arn_05",  0);

Script N(802418E8) = SCRIPT({
    bind N(exitWalk_80241830) to TRIGGER_FLOOR_ABOVE 1;
    bind N(exitWalk_8024188C) to TRIGGER_FLOOR_ABOVE 5;
});

Script N(enterWalk_80241930) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(802418E8);
        return;
    }
    if (STORY_PROGRESS < STORY_CH3_ARRIVED_AT_GHOST_TOWN) {
        SetPlayerPos(-175, 165, 160);
        InterpPlayerYaw(90, 0);
        SetNpcPos(NPC_PARTNER, -175, 165, 160);
        InterpNpcYaw(NPC_PARTNER, 90, 0);
        SetPlayerSpeed(4);
        PlayerMoveTo(-55, 160, 0);
        spawn N(802418E8);
        return;
    }
    SI_VAR(0) = N(802418E8);
    spawn EnterWalk;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SI_AREA_FLAG(3) = 0;
    SI_AREA_FLAG(4) = 0;
    SI_AREA_FLAG(5) = 0;
    if (STORY_PROGRESS < STORY_CH3_DEFEATED_TUBBA_BLUBBA) {
        MakeNpcs(0, N(npcGroupList_80244740));
    } else {
        MakeNpcs(0, N(npcGroupList_80244788));
    }
    if (SI_SAVE_FLAG(1020) == 1) {
        SI_MAP_VAR(0) = 450;
        SI_MAP_VAR(1) = 450;
    }
    await N(makeEntities);
    spawn N(80241780);
    spawn N(enterWalk_80241930);
    sleep 1;
});

static s32 N(pad_1BB8)[] = {
    0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80241BC0) = {
    .moveSpeed = 1.0f,
    .moveTime = 25,
    .waitTime = 30,
    .alertRadius = 50.0f,
    .unk_10 = { .f = 50.0f },
    .unk_14 = 10,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 80.0f },
    .unk_2C = 1,
};

Script N(npcAI_80241BF0) = SCRIPT({
    N(func_8024113C_BDFECC)(N(npcAISettings_80241BC0));
});

NpcSettings N(npcSettings_80241C10) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_80241BF0),
    .level = 99,
};

NpcSettings N(npcSettings_80241C3C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

s32 N(D_80241C68_BE09F8) = {
    0x00000000,
};

Script N(80241C6C) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

Script N(80241C9C) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 16);
    return;
});

s32 N(D_80241CCC_BE0A5C) = {
    0x00000000,
};

s32 N(D_80241CD0_BE0A60) = {
    0x00000000,
};

Script N(80241CD4) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    func_802D6420();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveKeyItemAt(SI_VAR(1));
            GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(SomeXYZFuncTodoRename)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            SI_VAR(0) |=c 0x50000;
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(SI_VAR(0));
        }
    }
    N(func_80241648_BE03D8)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(80241E18) = {
    SI_CMD(ScriptOpcode_CALL, N(func_80241680_BE0410), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80241CD4), 0x10, 0, D_80244A20, 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_802415F4_BE0384), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(80241E68) = SCRIPT({
    SetPlayerAnimation(ANIM_10002);
    sleep 1;
    SetPlayerAnimation(0x80007);
    sleep 20;
});

Script N(interact_80241EB0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(2) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0073));
                SI_AREA_FLAG(2) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0074));
                SI_AREA_FLAG(2) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0075));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0076));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0077));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0078));
            SetPlayerAnimation(ANIM_10002);
            sleep 10;
            SetPlayerAnimation(0x80007);
            sleep 20;
            EndSpeech(-1, 9765124, 9765121, 0);
        }
    }
});

Script N(idle_80242064) = SCRIPT({
    DisablePlayerInput(TRUE);
    sleep 25;
    spawn {
        sleep 50;
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 325);
        SetCamSpeed(0, 4.0);
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PanToTarget(0, 0, 1);
    }
    spawn {
        sleep 20;
        GetCurrentPartnerID(SI_VAR(6));
        if (SI_VAR(6) != 9) {
            BringPartnerOut(9);
            DisablePartnerAI(0);
            sleep 1;
            NpcFaceNpc(NPC_PARTNER, NPC_SELF, 0);
            sleep 5;
            SetNpcJumpscale(NPC_PARTNER, 0);
            if (SI_VAR(6) == 4) {
                NpcJump0(NPC_PARTNER, -81, 176, 171, 20);
            } else {
                NpcJump0(NPC_PARTNER, -81, 186, 171, 20);
            }
            EnablePartnerAI();
        }
    }
    SetNpcJumpscale(NPC_SELF, 0);
    NpcJump0(NPC_SELF, -8, 186, 159, 60);
    sleep 15;
    DisablePartnerAI(0);
    InterpNpcYaw(NPC_SELF, -4, 0);
    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x006E));
    InterpNpcYaw(NPC_PARTNER, -1, 0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 5, MESSAGE_ID(0x0E, 0x006F));
    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x0070));
    InterpNpcYaw(NPC_PARTNER, -1, 0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 5, MESSAGE_ID(0x0E, 0x0071));
    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x0072));
    EnablePartnerAI();
    sleep 10;
    GetCurrentPartnerID(SI_VAR(6));
    if (SI_VAR(6) != 9) {
        PutPartnerAway();
    }
    spawn {
        NpcMoveTo(NPC_SELF, 30, 125, 30);
        InterpNpcYaw(NPC_SELF, 270, 0);
    }
    func_802CF56C(2);
    sleep 15;
    STORY_PROGRESS = STORY_CH3_ARRIVED_AT_GHOST_TOWN;
    DisablePlayerInput(FALSE);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 3);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
});

Script N(init_802424E0) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH3_ARRIVED_AT_GHOST_TOWN) {
        SetNpcPos(NPC_SELF, 175, 240, 145);
        BindNpcIdle(NPC_SELF, N(idle_80242064));
    }
    BindNpcInteract(NPC_SELF, N(interact_80241EB0));
});

Script N(interact_8024254C) = SCRIPT({
    if (SI_MAP_VAR(0) != 0) {
        if (SI_MAP_VAR(0) >= SI_MAP_VAR(1)) {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0081));
            SI_VAR(0) = 118;
            SI_VAR(1) = 1;
            await N(80241C6C);
            AddKeyItem(ITEM_PACKAGE);
            SI_MAP_VAR(0) = 0;
            SI_SAVE_FLAG(1015) = 1;
            SI_SAVE_FLAG(1020) = 0;
            return;
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0080));
            return;
        }
    }
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(3) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0079));
                SI_AREA_FLAG(3) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x007A));
                SI_AREA_FLAG(3) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x007B));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x007C));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x007D));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x007E));
        }
    }
    if (SI_SAVE_FLAG(1015) == 0) {
        if (SI_SAVE_VAR(348) == 18) {
            await N(80241E68);
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x007F));
            EndSpeech(-1, 9765124, 9765121, 0);
            SI_MAP_VAR(0) = 0;
            SI_MAP_VAR(1) = 450;
            SI_SAVE_FLAG(1020) = 1;
            spawn {
                loop {
                    SI_MAP_VAR(0) += 1;
                    sleep 1;
                    if (SI_MAP_VAR(0) >= SI_MAP_VAR(1)) {
                        break loop;
                    }
                }
            }
        }
    }
});

Script N(init_802428A8) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024254C));
});

Script N(802428CC) = SCRIPT({
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    if (SI_VAR(0) > SI_VAR(3)) {
        SI_VAR(0) += 60;
        SetNpcYaw(0x4, 90);
    } else {
        SI_VAR(0) -= 60;
        SetNpcYaw(0x4, 270);
    }
    SI_VAR(1) += 20;
    SetNpcPos(0x4, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802CFD30(0x4, 7, 0, 0, 0, 0);
    sleep 1;
});

Script N(802429D4) = SCRIPT({
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    if (SI_VAR(0) > SI_VAR(3)) {
        SI_VAR(0) += 30;
    } else {
        SI_VAR(0) -= 30;
    }
    spawn {
        MakeLerp(0, 255, 40, 0);
    10:
        UpdateLerp();
        func_802CFD30(0x4, 7, SI_VAR(0), 0, 0, 0);
        sleep 1;
        if (SI_VAR(1) == 1) {
            goto 10;
        }
    }
    NpcMoveTo(0x4, SI_VAR(0), SI_VAR(2), 40);
});

Script N(80242B0C) = SCRIPT({
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    if (SI_VAR(0) > SI_VAR(3)) {
        SI_VAR(0) += 60;
    } else {
        SI_VAR(0) -= 60;
    }
    spawn {
        MakeLerp(255, 0, 40, 0);
    10:
        UpdateLerp();
        func_802CFD30(0x4, 7, SI_VAR(0), 0, 0, 0);
        sleep 1;
        if (SI_VAR(1) == 1) {
            goto 10;
        }
    }
    NpcMoveTo(0x4, SI_VAR(0), SI_VAR(2), 40);
    SetNpcPos(0x4, 0, -1000, 0);
});

Script N(80242C60) = SCRIPT({
    await N(802429D4);
    SI_MAP_VAR(2) = 0;
    SI_MAP_VAR(3) = 0;
    spawn {
        sleep 25;
        SetPlayerAnimation(0x80017);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_9));
        loop {
            if (SI_MAP_VAR(2) == 1) {
                break loop;
            }
            sleep 1;
        }
        SetPlayerAnimation(ANIM_10002);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_1));
    }
    SetNpcAnimation(0x4, NPC_ANIM(boo, Palette_01, Anim_8));
    EndSpeech(4, 9765128, 9765128, 5);
    sleep 30;
    SetNpcAnimation(0x4, NPC_ANIM(boo, Palette_01, Anim_1));
    sleep 10;
    await N(80242B0C);
    SI_MAP_VAR(2) = 1;
    sleep 15;
});

Script N(interact_80242DC4) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(4) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0082));
                SI_AREA_FLAG(4) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0083));
                SI_AREA_FLAG(4) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0084));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0085));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            DisablePartnerAI(0);
            DisablePlayerPhysics(TRUE);
            spawn {
                GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SI_VAR(2) += -20;
                SetNpcSpeed(NPC_PARTNER, 2.0);
                NpcMoveTo(NPC_PARTNER, SI_VAR(0), SI_VAR(2), 0);
                NpcFaceNpc(NPC_PARTNER, NPC_SELF, 1);
            }
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0086));
            await N(802428CC);
            PlayerFaceNpc(4, 1);
            NpcFaceNpc(NPC_PARTNER, 0x4, 1);
            SpeakToPlayer(0x4, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x0087));
            await N(80242C60);
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0088));
            DisablePlayerPhysics(FALSE);
            EnablePartnerAI();
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            DisablePartnerAI(0);
            DisablePlayerPhysics(TRUE);
            spawn {
                GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SI_VAR(2) += -20;
                SetNpcSpeed(NPC_PARTNER, 2.0);
                NpcMoveTo(NPC_PARTNER, SI_VAR(0), SI_VAR(2), 0);
                NpcFaceNpc(NPC_PARTNER, NPC_SELF, 1);
            }
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0089));
            await N(802428CC);
            PlayerFaceNpc(4, 1);
            NpcFaceNpc(NPC_PARTNER, 0x4, 1);
            SpeakToPlayer(0x4, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x008A));
            await N(80242C60);
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x008B));
            DisablePlayerPhysics(FALSE);
            EnablePartnerAI();
        }
    }
});

Script N(init_802431A4) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80242DC4));
});

Script N(interact_802431C8) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(5) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x008C));
                SI_AREA_FLAG(5) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x008D));
                SI_AREA_FLAG(5) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x008E));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x008F));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0090));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0091));
        }
    }
});

Script N(init_80243328) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_802431C8));
});

Script N(init_8024334C) = SCRIPT({
    SetNpcPos(NPC_SELF, 0, -1000, 0);
});

StaticNpc N(npcGroup_80243378) = {
    .id = 0,
    .settings = &N(npcSettings_80241C10),
    .pos = { 36.0f, 185.0f, 140.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802424E0),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 2, 36, 10, 185, 56, 10, 185, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 479, 215, 198, 150 },
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
    .tattle = MESSAGE_ID(0x1A, 0x00AA),
};

StaticNpc N(npcGroup_80243568) = {
    .id = 1,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 209.0f, 185.0f, 217.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802428A8),
    .yaw = 90,
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
    .tattle = MESSAGE_ID(0x1A, 0x00AB),
};

StaticNpc N(npcGroup_80243758) = {
    .id = 2,
    .settings = &N(npcSettings_80241C10),
    .pos = { 379.0f, 186.0f, 186.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802431A4),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 2, 379, 10, 186, 399, 10, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 479, 215, 198, 150 },
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
    .tattle = MESSAGE_ID(0x1A, 0x00AC),
};

StaticNpc N(npcGroup_80243948) = {
    .id = 3,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 544.0f, 235.0f, 128.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80243328),
    .yaw = 90,
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
    .tattle = MESSAGE_ID(0x1A, 0x00AD),
};

StaticNpc N(npcGroup_80243B38) = {
    .id = 4,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_8024334C),
    .yaw = 90,
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
};

Script N(idle_80243D28) = SCRIPT({
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = SI_VAR(0);
    SI_VAR(3) += -60;
    SI_VAR(4) = SI_VAR(0);
    SI_VAR(4) += 60;
    loop {
        RandInt(5, SI_VAR(5));
        SI_VAR(6) =f SI_VAR(5);
        SI_VAR(6) *= 0.1005859375;
        SI_VAR(6) += 0.80078125;
        SetNpcSpeed(NPC_SELF, SI_VAR(6));
        NpcMoveTo(NPC_SELF, SI_VAR(3), SI_VAR(2), 0);
        RandInt(5, SI_VAR(5));
        SI_VAR(6) =f SI_VAR(5);
        SI_VAR(6) *= 0.1005859375;
        SI_VAR(6) += 0.80078125;
        SetNpcSpeed(NPC_SELF, SI_VAR(6));
        NpcMoveTo(NPC_SELF, SI_VAR(4), SI_VAR(2), 0);
    }
});

Script N(init_80243E90) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_80243D28));
    SetNpcFlagBits(NPC_SELF, 0x00000010, FALSE);
});

Script N(init_80243ECC) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_80243D28));
    SetNpcFlagBits(NPC_SELF, 0x00000010, FALSE);
});

Script N(init_80243F08) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_80243D28));
    SetNpcFlagBits(NPC_SELF, 0x00000010, FALSE);
});

Script N(init_80243F44) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_80243D28));
    SetNpcFlagBits(NPC_SELF, 0x00000010, FALSE);
});

StaticNpc N(npcGroup_80243F80)[] = {
    {
        .id = 5,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 36.0f, 277.0f, 140.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_200 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243E90),
        .yaw = 90,
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
    },
    {
        .id = 6,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 180.0f, 285.0f, 182.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_200 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243ECC),
        .yaw = 90,
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
    },
    {
        .id = 7,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 349.0f, 286.0f, 152.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_200 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243F08),
        .yaw = 90,
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
    },
    {
        .id = 8,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 490.0f, 324.0f, 128.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_200 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243F44),
        .yaw = 90,
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
    },
};

NpcGroupList N(npcGroupList_80244740) = {
    NPC_GROUP(N(npcGroup_80243378), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243568), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243758), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243948), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243B38), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80244788) = {
    NPC_GROUP(N(npcGroup_80243378), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243568), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243758), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243948), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243B38), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243F80), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_47DC) = {
    0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, 300, 237, 60, 0, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1007));
    MakeEntity(0x802E9A18, 250, 237, 125, 0, MAKE_ENTITY_END);
});

void N(func_80240000_BDED90)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;

    script->functionTemp[1].s = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->functionTemp[2].s = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        ret = dist2D(posX, posZ, i[enemy->territory->patrol.points].x, i[enemy->territory->patrol.points].z);
        if (ret < max) {
            max = ret;
            script->functionTemp[2].s = j;
        }
    }

    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
}

void N(func_80240158_BDEEE8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, z;
    s32 var;

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1].s <= 0) {
            script->functionTemp[1].s = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.s, 0)) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
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

    if (npc->unk_8C == 0) {
        if (npc->moveSpeed < 4.0) {
            func_8003D660(npc, 0);
        } else {
            func_8003D660(npc, 1);
        }
        
        x = (*(enemy->territory->patrol.points + script->functionTemp[2].s)).x;
        z = (*(enemy->territory->patrol.points + script->functionTemp[2].s)).z;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, x, z) <= npc->moveSpeed) {
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || 
                (aiSettings->waitTime <= 0) || (script->functionTemp[1].s == 0)) {
                script->functionTemp[0].s = 4;
            }
            if (rand_int(10000) % 100 < aiSettings->moveTime) {
                script->functionTemp[0].s = 4;
            }
        }
    }
}

#include "world/common/UnkNpcAIFunc1.inc.c"

void N(func_802404C0_BDF250)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if ((aiSettings->unk_14 >= 0) && func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        func_800494C0(npc, 0x2F4, 0x200000);
        if (!(enemy->npcSettings->unk_2A & 1)) {
            script->functionTemp[0].s = 12;
        } else {
            script->functionTemp[0].s = 10;
        }
    } else if (npc->unk_8C == 0) {
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[1].s--;
            if (script->functionTemp[1].s != 0) {
                if (!(enemy->npcSettings->unk_2A & 0x10)) {
                    npc->yaw = clamp_angle(npc->yaw + 180.0f);
                }
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                script->functionTemp[0].s = 4;
            }
        }
    }
}

void N(func_8024067C_BDF40C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
}

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

void N(func_8024094C_BDF6DC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (!func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 1)) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        npc->currentAnim = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0].s = 14;
    } else {
        func_8003D660(npc, 1);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (npc->duration > 0) {
            npc->duration--;
        } else {
            script->functionTemp[0].s = 12;
        }
    }
}

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

void N(func_80240AD4_BDF864)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = script->functionTemp[2].s; i < enemy->territory->patrol.numPoints; i++) {
        if (i[enemy->territory->patrol.points].y <= npc->pos.y) {
            script->functionTemp[2].s = i;
            break;
        }
    }

    npc->moveSpeed = aiSettings->moveSpeed;
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    script->functionTemp[0].s = 1;
}

ApiStatus N(func_80240B94_BDF924)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= 0xBFFFFFFF;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_BDED90)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_80240158_BDEEE8)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_802404C0_BDF250)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_8024067C_BDF40C)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_8024094C_BDF6DC)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(func_80240AD4_BDF864)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}

void N(func_80240E90_BDFC20)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f20;
    f32 temp_f22;

    posX = npc->pos.x;
    posZ = npc->pos.z;
    temp_f22 = (*(enemy->territory->patrol.points + script->functionTemp[2].s)).x;
    temp_f20 = (*(enemy->territory->patrol.points + script->functionTemp[2].s)).z;

    npc->yaw = atan2(posX, posZ, temp_f22, temp_f20);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    posX = npc->pos.x;
    posY = npc->pos.y + (*(enemy->territory->patrol.points + script->functionTemp[2].s)).y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    posY += (*(enemy->territory->patrol.points + script->functionTemp[2].s)).y;
    posW = posY - npc->pos.y;
    if (posW > 2.0) {
        npc->pos.y += 2.0;
    } else if (posW < -2.0) {
        npc->pos.y -= 2.0;
    } else {
        npc->pos.y = posY;
    }

    posW = dist2D(npc->pos.x, npc->pos.z, temp_f22, temp_f20);
    if (!(posW > npc->moveSpeed)) {
        script->functionTemp[0].s = 2;
    }
}

void N(func_80241068_BDFDF8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration < 0) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s >= 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
        } else {
            script->functionTemp[0].s = 4;
            npc->currentAnim = enemy->animList[0];
        }
    }
}

ApiStatus N(func_8024113C_BDFECC)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_34 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_BDED90)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_80240E90_BDFC20)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80241068_BDFDF8)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_8024067C_BDF40C)(script, npcAISettings, territoryPtr);
            break;
    }

    enemy->varTable[0] = npc->pos.y;
    return ApiStatus_BLOCK;
}

ApiStatus N(func_802412B0_BE0040)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

ApiStatus N(func_802415F4_BE0384)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &N(D_80241CCC_BE0A5C);
        *ptr = 0;
    }

    ptr = &N(D_80241CCC_BE0A5C);
    if (*ptr != NULL) {
        ptr = &N(D_80241CCC_BE0A5C);
        *ptr = 0;
        set_variable(script, *args, N(D_80241CD0_BE0A60));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241648_BE03D8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    N(D_80241CD0_BE0A60) = get_variable(script, *args);
    N(D_80241CCC_BE0A5C) = 1;
    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus func_80241680_BE0410(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* temp_v0 = get_variable(script, *args);
    s32* ptr = temp_v0;
    s32 i;

    i = 0;
    if (ptr != NULL) {
        s32 new_var;
        for (new_var = ptr[0]; new_var != 0; i++) {
            *(D_80244A20 + i) = ptr[i];
        }
        D_80244A20[i] = 0;
    } else {
        for (; i < 0x70; i++) {
            *(D_80244A20 + i) = i + 16;
            D_80244A20[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_arn/arn_03/BDED90", arn_03_func_80241680_BE0410, ScriptInstance* script, s32 isInitialCall);
#endif
 
