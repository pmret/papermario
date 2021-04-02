#include "arn_09.h"
#include "sprite/npc/tubbas_heart.h"

extern s32 D_000001E4;

Script N(script_80240140) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 0;
    SI_VAR(1) = 5;
    SI_VAR(2) = 0;
    SI_VAR(4) = 1;
    SI_VAR(3) = 1;
    spawn 0x80285DFC;
    sleep 17;
    GotoMap("arn_10", 0);
    sleep 100;
});

Script N(script_802401F4) = SCRIPT({
    bind N(script_80240140) to TRIGGER_WALL_PRESS_A 5;
});

Script N(script_80240220) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 0;
            SI_VAR(4) = 1;
            SI_VAR(3) = 1;
            await 0x80285E24;
            spawn N(script_802401F4);
        }
        == 1 {
            spawn N(script_802401F4);
        }
    }
});

Script N(script_Main) = SCRIPT({
    WORLD_LOCATION = LOCATION_WINDY_MILL;
    SetSpriteShading(524288);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80240974));
    await N(script_MakeEntities);
    spawn N(script_80240220);
    spawn N(script_802404D0);
    spawn N(script_802400A0);
});

static s32 N(pad_398)[] = {
    0x00000000, 0x00000000,
};

Script N(script_802403A0) = SCRIPT({
    if (SI_AREA_FLAG(1) == 1) {
        return;
    }
    SI_AREA_FLAG(1) = 1;
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(6);
    sleep 1;
    SetPlayerJumpscale(1.0);
    PlayerJump(0, 200, 0, 30);
    GotoMap("arn_08", 1);
    sleep 100;
    DisablePlayerInput(FALSE);
    DisablePlayerPhysics(FALSE);
});

Script N(script_MakeEntities) = SCRIPT({
    MakeEntity(0x802EAA30, 0, 0, 0, 0, ARGS_END);
    AssignScript(N(script_802403A0));
});

static s32 N(pad_4CC)[] = {
    0x00000000,
};

Script N(script_802404D0) = SCRIPT({
    if (SI_AREA_FLAG(1) == 0) {
        return;
    }
    SI_AREA_FLAG(1) = 1;
    DisablePlayerInput(TRUE);
    SetPlayerActionState(8);
    func_802D2484();
    SetPlayerActionState(6);
    SetPlayerJumpscale(1.5);
    PlayerJump(50, 0, 0, 16);
    SetPlayerAnimation(ANIM_10002);
    SI_AREA_FLAG(1) = 0;
    DisablePlayerInput(FALSE);
});

static s32 N(pad_5A8)[] = {
    0x00000000, 0x00000000,
};

Script N(script_802405B0) = SCRIPT({

});

Script N(script_802405C0) = SCRIPT({

});

NpcSettings N(npcSettings_802405D0) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(script_802405B0),
    .onDefeat = &N(script_802405C0),
    .level = 13,
};

Script N(script_Idle_802405FC) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_13));
    SetNpcJumpscale(NPC_SELF, 2.5);
    PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
    NpcJump0(NPC_SELF, 0, 25, -10, 6);
    PlaySoundAtNpc(NPC_SELF, 0x2086, 0);
    N(func_80240000_BF6060)();
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_13));
    SetNpcJumpscale(NPC_SELF, 2.5);
    PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
    NpcJump0(NPC_SELF, 0, 200, 0, 15);
    SetNpcPos(NPC_SELF, 0, -1000, 0);
    STORY_PROGRESS = STORY_CH3_HEART_ESCAPED_WELL;
});

Script N(script_Init_80240730) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH3_HEART_FLED_SECOND_TUNNEL) {
        RemoveNpc(NPC_SELF);
    } else {
        BindNpcIdle(NPC_SELF, N(script_Idle_802405FC));
    }
});

StaticNpc N(npcGroup_80240784) = {
    .id = 0,
    .settings = &N(npcSettings_802405D0),
    .pos = { 0.0f, 25.0f, 0.0f },
    .flags = 0x00000D05,
    .init = &N(script_Init_80240730),
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

NpcGroupList N(npcGroupList_80240974) = {
    NPC_GROUP(N(npcGroup_80240784), BATTLE_ID(0, 0, 0, 0)),
    {},
};

ApiStatus N(func_80240000_BF6060)(ScriptInstance *script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }
    
    play_model_animation(entity->virtualModelIndex, &D_000001E4);
    return ApiStatus_DONE2;
}
