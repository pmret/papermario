#include "kmr_03.h"

s32 N(npcGroupList_80241450)[];
Script N(MakeEntities);
Script N(Script_802422B8);
Script N(Script_80242340);

ApiStatus func_802401B0_8C8140(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[1] = func_800E0088(npc->pos.x, npc->pos.z) / npc->moveSpeed * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/UnkPositionFunc.inc.c"

// 8C8680
Script N(ExitWalk_802406F0) = EXIT_WALK_SCRIPT(60, 0, "kmr_04", 0);

Script N(ExitWalk_8024074C) = EXIT_WALK_SCRIPT(60, 1, "kmr_05", 0);

Script N(Script_802407A8) = SCRIPT({
    bind N(ExitWalk_802406F0) to 0x80000 3;
    bind N(ExitWalk_8024074C) to 0x80000 5;
});

Script N(Main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GOOMBA_VILLAGE;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    SI_AREA_FLAG(8) = 0;
    MakeNpcs(0, N(npcGroupList_80241450));
    ClearDefeatedEnemies();
    await N(MakeEntities);
    await N(Script_802422B8);
    spawn N(Script_802406C0);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) != 2) {
        SI_VAR(0) = N(Script_802407A8);
        spawn EnterWalk;
    } else {
        spawn N(Script_802407A8);
        spawn N(Script_80242340);
    }
    sleep 1;
});

s32 padding[] = {0, 0};

// 8C88E0
s32 N(npcSettings_80240950)[] = {
    0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00630010,
};

Script N(Script_8024097C) = SCRIPT({
1:
    if (SI_AREA_FLAG(8) == 1) {
100:
        AwaitPlayerLeave(294, 123, 170);
        EnableNpcAI(0, 0);
        DisablePlayerInput(1);
        SetNpcSpeed(0, 4.0);
        SetNpcAnimation(0, 0x9D0003);
        func_802401B0_8C8140();
        GetAngleToPlayer(0, SI_VAR(2));
        loop SI_VAR(1) {
            GetNpcPos(0, SI_VAR(7), SI_VAR(8), SI_VAR(9));
            AddVectorPolar(SI_VAR(7), SI_VAR(9), 4.0, SI_VAR(2));
            SetNpcPos(0, SI_VAR(7), SI_VAR(8), SI_VAR(9));
            sleep 1;
        }
        PlayerFaceNpc(0, 3);
        SetPlayerSpeed(3.0);
        PlayerMoveTo(243, 243, 0);
        SetNpcVar(0, 0, 1);
        EnableNpcAI(0, 1);
        DisablePlayerInput(0);
        goto 100;
    }
    sleep 1;
    goto 1;
});

Script N(NpcAI_80240B50) = SCRIPT({
1:
    match STORY_PROGRESS {
        == STORY_CH0_FELL_OFF_CLIFF {
89:
            N(UnkPositionFunc)(0xFFFFFF8A, 86, 0xFFFFFFBA, 0xFFFFFFF1);
            sleep 1;
            if (SI_VAR(0) == 0) {
                goto 89;
            }
            DisablePlayerInput(1);
            SetNpcAux(0, 0);
            PlaySoundAtNpc(0, 610, 0);
            ShowEmote(0, 0, 45, 15, 1, 0, 0, 0, 0);
            sleep 15;
            NpcFacePlayer(-1, 5);
            sleep 10;
            SpeakToPlayer(0, 0x9D0008, 0x9D0001, 0, 0xB00A6);
            UseSettingsFrom(0, 0xFFFFFF24, 20, 0xFFFFFFB8);
            SetPanTarget(0, 0xFFFFFFEC, 0, 68);
            SetCamPitch(0, 15.0, -8.5);
            SetCamDistance(0, 275);
            SetCamSpeed(0, 1.5);
            PanToTarget(0, 0, 1);
            spawn {
                sleep 20;
                SetPlayerSpeed(2.0);
                PlayerMoveTo(0xFFFFFFDA, 68, 0);
            }
            GetNpcPos(0, SI_VAR(7), SI_VAR(8), SI_VAR(9));
            SetNpcSpeed(0, 4.0);
            SetNpcAnimation(0, 0x9D0003);
            NpcMoveTo(0, 0, 70, 0);
            SetNpcAnimation(0, 0x9D0001);
            InterpNpcYaw(0, 276, 20);
            sleep 30;
            SpeakToPlayer(0, 0x9D0008, 0x9D0001, 0, 0xB00A7);
            sleep 5;
            SetPlayerAnimation(0x80007);
            sleep 30;
            SpeakToPlayer(0, 0x9D0008, 0x9D0001, 0, 0xB00A8);
            func_80240000_8C7F90(0, 5);
            STORY_PROGRESS = STORY_CH0_GOOMPA_JOINED_PARTY;
            UseSettingsFrom(0, 0xFFFFFF24, 20, 0xFFFFFFB8);
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamSpeed(0, 3.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            PanToTarget(0, 0, 0);
            EnablePartnerAI();
            DisablePlayerInput(0);
            sleep 1;
        }
    }
});

Script N(Hit_80240F64) = SCRIPT({
    SetNpcAnimation(-1, 0x9D0007);
    sleep 10;
    SetNpcAnimation(-1, 0x9D0001);
    SI_MAP_VAR(0) += 1;
    if (SI_MAP_VAR(0) < 3) {
        GetOwnerEncounterTrigger(SI_VAR(0));
        match SI_VAR(0) {
            == 2 {
                SetNpcVar(0, 0, 1);
                if (SI_AREA_FLAG(6) == 1) {
                } else {
                    SI_AREA_FLAG(6) = 1;
                    SI_AREA_FLAG(7) = 0;
                }
            }
            == 4 {
                SetNpcVar(0, 0, 1);
                if (SI_AREA_FLAG(7) == 1) {
                } else {
                    SI_AREA_FLAG(6) = 0;
                    SI_AREA_FLAG(7) = 1;
                }
            }
        }
        sleep 10;
        SetNpcAnimation(-1, 0x9D0003);
    } else {
        sleep 10;
        GetNpcPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetNpcPos(0xFFFFFFFC, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetNpcFlagBits(0xFFFFFFFC, 512, 1);
        SetNpcPos(0, 0, 0xFFFFFC18, 0);
        SetNpcFlagBits(0, 256, 0);
        EnablePartnerAI();
        SetNpcAux(-1, N(Script_8024097C));
        BindNpcAI(-1, N(NpcAI_80240B50));
    }
});

Script N(Init_802411A8) = SCRIPT({
    BindNpcIdle(-1, N(NpcAI_80240B50));
    BindNpcAux(-1, N(Script_8024097C));
    BindNpcHit(-1, N(Hit_80240F64));
    match STORY_PROGRESS {
        >= 0xFFFFFF87 {
            SetNpcFlagBits(-1, 512, 0);
            SetNpcFlagBits(-1, 8, 1);
            SetNpcPos(-1, 0, 0xFFFFFC18, 0);
        }
    }
});

s32 N(npcGroup_80241260)[] = {
    0x00000000, N(npcSettings_80240950), 0xC2480000, 0x00000000, 0x42A00000, 0x00400105, N(Init_802411A8), 0x00000000,
    0x00000000, 0x0000002D, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x009D0001, 0x009D0002, 0x009D0003, 0x009D0003, 0x009D0001, 0x009D0001, 0x009D0000, 0x009D0000,
    0x009D0003, 0x009D0003, 0x009D0003, 0x009D0003, 0x009D0003, 0x009D0003, 0x009D0003, 0x009D0003,
    0x00000000, 0x00000000, 0x00000000, 0x001A0063,
};

s32 N(npcGroupList_80241450)[] = {
    0x00000001, N(npcGroup_80241260), 0x00020000, 0x00000000, 0x00000000, 0x00000000,
};

s32 N(padding2)[] = {0, 0};

Script N(Script_80241470) = SCRIPT({
    ModifyColliderFlags(0, 9, 0x7FFFFE00);
    STORY_PROGRESS = STORY_CH0_LEFT_THE_PLAYGROUND;
});

Script N(Script_802414A8) = SCRIPT({
    SI_SAVE_FLAG(54) = 1;
});

Script N(Script_802414C8) = SCRIPT({
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 1;
    goto 0;
});

Script N(MakeEntities) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH0_LEFT_THE_PLAYGROUND) {
        MakeEntity(0x802EA10C, 45, 0, 70, 15, 0x80000000);
        AssignScript(N(Script_80241470));
    } else {
        ModifyColliderFlags(0, 9, 0x7FFFFE00);
    }
    if (SI_SAVE_FLAG(54) == 0) {
        MakeEntity(0x802EA19C, 230, 0, 310, 15, 0x80000000);
        AssignScript(N(Script_802414A8));
    }
    MakeEntity(0x802EA588, 230, 60, 310, 15, 151, 0x80000000);
    AssignBlockFlag(SI_SAVE_FLAG(52));
    MakeEntity(0x802EA0C4, 230, 50, 0xFFFFFF60, 15, 0x80000000);
    MakeEntity(0x802EA0C4, 165, 0, 380, 20, 0x80000000);
    MakeEntity(0x802EA564, 0xFFFFFF56, 0, 370, 43, 343, 0x80000000);
    AssignBlockFlag(SI_SAVE_FLAG(50));
    MakeEntity(0x802EAA54, 345, 75, 0xFFFFFF06, 0, 100, 0x80000000);
    MakeItemEntity(343, 345, 205, 0xFFFFFF06, 17, SI_SAVE_FLAG(56));
    MakeItemEntity(343, 345, 230, 0xFFFFFF06, 17, SI_SAVE_FLAG(57));
    MakeItemEntity(343, 345, 255, 0xFFFFFF06, 17, SI_SAVE_FLAG(58));
    MakeItemEntity(343, 345, 280, 0xFFFFFF06, 17, SI_SAVE_FLAG(59));
    MakeItemEntity(128, 229, 250, 0xFFFFFF64, 17, SI_SAVE_FLAG(49));
    MakeEntity(0x802EAB04, 300, 0, 150, 0, 18, 0x80000000);
    AssignPanelFlag(SI_SAVE_FLAG(88));
    MakeEntity(0x802EA7E0, 130, 60, 0, 0, 0x80000000);
});

