#include "arn_08.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/yakkey.h"

extern Npc* wPartnerNpc;
void func_800EF3C0(s32, s32);
void func_800EF3D4(s16);

Script N(802403B0) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    ClearDefeatedEnemies();
    SI_VAR(0) = 0;
    SI_VAR(1) = 6;
    SI_VAR(2) = 0;
    SI_VAR(4) = 1;
    SI_VAR(3) = -1;
    spawn 0x80285DFC;
    sleep 17;
    GotoMap("arn_07", 0);
    sleep 100;
});

Script N(80240470) = SCRIPT({
    bind N(802403B0) to TRIGGER_WALL_PRESS_A 6;
});

Script N(8024049C) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(80240470);
        return;
    }
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(4) = 1;
            SI_VAR(2) = 0;
            SI_VAR(3) = -1;
            await 0x80285E24;
            SI_AREA_FLAG(1) = 0;
            spawn N(80240470);
        }
        == 1 {
            DisablePlayerInput(TRUE);
            DisablePlayerPhysics(TRUE);
            if (STORY_PROGRESS == STORY_CH3_HEART_ESCAPED_WELL) {
                SetPlayerPos(1000, 1000, 0);
                SetNpcPos(NPC_PARTNER, 1000, 1000, 0);
                RotateModel(0, 80, 0, -1, 0);
                RotateModel(1, 80, 0, -1, 0);
                SetNpcAnimation(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_6));
                SetNpcJumpscale(NPC_PLAYER, 2.5);
                PlaySoundAtNpc(NPC_PLAYER, 0x20C8, 0);
                NpcJump0(NPC_PLAYER, -50, 0, 50, 10);
                SetNpcAnimation(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_7));
                sleep 1;
                SetNpcAnimation(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_6));
                PlaySoundAtNpc(NPC_PLAYER, 0x20C8, 0);
                NpcJump0(NPC_PLAYER, -110, 0, 110, 10);
                SetNpcAnimation(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_7));
                sleep 1;
                SetNpcAnimation(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_6));
                PlaySoundAtNpc(NPC_PLAYER, 0x20C8, 0);
                NpcJump0(NPC_PLAYER, -180, 0, 180, 10);
                SetNpcAnimation(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_7));
                sleep 1;
                MakeLerp(80, 0, 10, 0);
                loop {
                    UpdateLerp();
                    RotateModel(0, SI_VAR(0), 0, -1, 0);
                    RotateModel(1, SI_VAR(0), 0, -1, 0);
                    sleep 1;
                    if (SI_VAR(1) == 0) {
                        break loop;
                    }
                }
                PlaySoundAtCollider(6, 450, 0);
                sleep 20;
                SetPlayerPos(0, 0, 0);
                SetNpcPos(NPC_PARTNER, 0, 0, 0);
                STORY_PROGRESS = STORY_CH3_HEART_ESCAPED_WINDY_MILL;
            }
            DisablePlayerPhysics(FALSE);
            SetPlayerJumpscale(2.0);
            PlayerJump(-10, 0, 75, 18);
            DisablePlayerInput(FALSE);
            spawn N(80240470);
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_WINDY_MILL;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    SI_SAVE_FLAG(1979) = 1;
    if (STORY_PROGRESS >= STORY_CH4_FRYING_PAN_STOLEN) {
        SI_SAVE_FLAG(1016) = 0;
        SI_SAVE_FLAG(1017) = 0;
        SI_SAVE_FLAG(1018) = 0;
    }
    MakeNpcs(0, N(npcGroupList_80241828));
    await N(makeEntities);
    spawn N(80240BA0);
    GetDemoState(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        await N(8024118C);
        return;
    }
    spawn N(8024049C);
    spawn N(80240B50);
    spawn N(80240300);
});

static s32 N(pad_A6C)[] = {
    0x00000000,
};

Script N(80240A70) = SCRIPT({
    loop {
        if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WELL) {
            break loop;
        }
        sleep 1;
    }
    N(func_8024008C_BF482C)();
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    N(func_80240000_BF47A0)();
    SI_AREA_FLAG(1) = 1;
    if (STORY_PROGRESS < STORY_CH3_WENT_DOWN_THE_WELL) {
        STORY_PROGRESS = STORY_CH3_WENT_DOWN_THE_WELL;
    }
    GotoMap("arn_09", 1);
    sleep 100;
});

Script N(80240B50) = SCRIPT({
    SetCamProperties(0, 90.0, 0, 0, 0, 470.0, 17.0, -7.0);
    spawn N(80240A70);
});

static s32 N(pad_B98)[] = {
    0x00000000, 0x00000000,
};

Script N(80240BA0) = SCRIPT({
    PlaySound(0x8000004B);
    spawn {
        SI_VAR(0) = 0;
    10:
        RotateModel(9, SI_VAR(0), 0, 0, 1);
        RotateModel(15, SI_VAR(0), 0, 0, 1);
        RotateModel(11, SI_VAR(0), 0, 0, 1);
        RotateModel(13, SI_VAR(0), 0, 0, -1);
        RotateModel(17, SI_VAR(0), 0, 0, -1);
        SI_VAR(0) += 1;
        sleep 1;
        goto 10;
    }
});

static s32 N(pad_CB4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80240CC0) = SCRIPT({
    N(func_802400C0_BF4860)();
    DemoJoystickXY(2, 0);
    sleep 1;
    DemoJoystickXY(12, 4);
    sleep 1;
    DemoJoystickXY(28, 11);
    sleep 1;
    DemoJoystickXY(47, 22);
    sleep 1;
    DemoJoystickXY(68, 38);
    sleep 1;
    DemoJoystickXY(67, 48);
    sleep 1;
    DemoJoystickXY(64, 59);
    sleep 1;
    DemoJoystickXY(64, 62);
    sleep 4;
    DemoSetButtons(32768);
    sleep 10;
    DemoJoystickXY(64, 58);
    DemoSetButtons(0);
    sleep 1;
    DemoJoystickXY(70, 34);
    sleep 1;
    DemoJoystickXY(77, -2);
    sleep 1;
    DemoJoystickXY(74, -23);
    sleep 1;
    DemoJoystickXY(71, -36);
    sleep 1;
    DemoJoystickXY(69, -44);
    sleep 1;
    DemoJoystickXY(67, -49);
    sleep 1;
    DemoJoystickXY(30, -30);
    sleep 1;
    DemoJoystickXY(0, 0);
    sleep 1;
    DemoJoystickXY(0, -1);
    sleep 8;
    DemoSetButtons(32768);
    sleep 2;
    DemoJoystickXY(0, -2);
    sleep 2;
    DemoJoystickXY(0, -1);
    sleep 2;
    DemoJoystickXY(0, 0);
    sleep 1;
    DemoSetButtons(0);
    sleep 1;
    DemoJoystickXY(1, 0);
    sleep 1;
    DemoJoystickXY(0, 0);
    N(func_802400D4_BF4874)();
    DemoSetButtons(32768);
    sleep 12;
    DemoSetButtons(0);
    sleep 20;
    if (SI_SAVE_FLAG(9) == 1) {
        return;
    }
    SI_SAVE_FLAG(9) = 1;
    GotoMapSpecial("arn_08", 2, 2);
    sleep 100;
});

Script N(802410AC) = SCRIPT({
    sleep 10;
    loop {
        GetDemoState(SI_VAR(0));
        if (SI_VAR(0) == 2) {
            break loop;
        }
        sleep 1;
    }
    if (SI_SAVE_FLAG(9) == 1) {
        return;
    }
    SI_SAVE_FLAG(9) = 1;
    GotoMapSpecial("arn_08", 2, 3);
    sleep 35;
});

Script N(8024116C) = SCRIPT({
    N(func_802400F4_BF4894)();
});

s32 N(D_80241188_BF5928) = {
    0x00000000,
};

Script N(8024118C) = SCRIPT({
    SetCamProperties(0, 90.0, 0, 0, 0, 470.0, 17.0, -7.0);
    N(func_8024019C_BF493C)();
    SI_SAVE_FLAG(9) = 0;
    spawn N(802410AC);
    spawn N(80240CC0);
});

static s32 N(pad_11FC)[] = {
    0x00000000,
};

Script N(80241200) = SCRIPT({

});

Script N(80241210) = SCRIPT({

});

NpcSettings N(npcSettings_80241220) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80241200),
    .onDefeat = &N(80241210),
    .level = 13,
};

NpcSettings N(npcSettings_8024124C) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

Script N(idle_80241278) = SCRIPT({

});

Script N(init_80241288) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH3_HEART_ESCAPED_WELL) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    } else {
        BindNpcIdle(NPC_SELF, N(idle_80241278));
    }
});

Script N(interact_802412E8) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH5_WHALE_MOUTH_OPEN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BA));
        }
        < STORY_CH6_FLOWER_GATE_OPEN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BB));
        }
        < STORY_CH7_INVITED_TO_STARBORN_VALLEY {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BC));
        }
        < STORY_CH8_OPENED_PATH_TO_STAR_WAY {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BD));
        }
        >= STORY_CH8_OPENED_PATH_TO_STAR_WAY {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BE));
        }
    }
});

Script N(init_802413E8) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH4_FRYING_PAN_STOLEN) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    } else {
        BindNpcInteract(NPC_SELF, N(interact_802412E8));
    }
});

StaticNpc N(npcGroup_80241448) = {
    .id = 0,
    .settings = &N(npcSettings_80241220),
    .pos = { -23.0f, 75.0f, 31.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241288),
    .yaw = 270,
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
};

StaticNpc N(npcGroup_80241638) = {
    .id = 1,
    .settings = &N(npcSettings_8024124C),
    .pos = { 38.0f, 0.0f, 97.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802413E8),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00B4),
};

NpcGroupList N(npcGroupList_80241828) = {
    NPC_GROUP(N(npcGroup_80241448), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80241638), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_184C)[] = {
    0x00000000,
};

Script N(makeEntities) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH3_WENT_DOWN_THE_WELL) {
        MakeEntity(0x802BCE84, 0, 30, 0, 0, MAKE_ENTITY_END);
    }
});

ApiStatus N(func_802400C0_BF4860)(ScriptInstance *script, s32 isInitialCall) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802400D4_BF4874)(ScriptInstance *script, s32 isInitialCall) {
    func_800EF300();
    return ApiStatus_DONE2;
}

ApiStatus N(func_802400F4_BF4894)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (!(playerStatus->position.y > -10.0f)) {
        f32 temp_f20 = func_800E34D8();
        s32 var;

        playerStatus->position.y = func_800E3514(temp_f20, &var);
        script->functionTemp[0].s += fabsf(temp_f20);

        return (script->functionTemp[0].s > 50) * ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_8024019C_BF493C)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* dataPtr = &N(D_80241188_BF5928);

    switch (*dataPtr) {
        case 0:
            *dataPtr = 1;
            break;
        case 1:
        case 2:
            (*dataPtr)++;
            break;
        case 3: {
            Npc** partnerNpcPtr = &wPartnerNpc;

            clear_partner_move_history(*partnerNpcPtr);
            func_800EF3C0(playerStatus->position.x, playerStatus->position.z);
            func_800EF3D4(0);
            set_npc_yaw(*partnerNpcPtr, 90.0f);
            playerStatus->targetYaw = 90.0f;
            playerStatus->currentYaw = 90.0f;
            playerStatus->spriteFacingAngle = 0.0f;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}
