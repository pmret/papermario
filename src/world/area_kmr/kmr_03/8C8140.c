#include "kmr_03.h"
#include "sprite/npc/goompa.h"
#include "entity.h"

enum {
    NPC_GOOMPA,
};

ApiStatus N(func_802401B0_8C8140)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[1] = get_xz_dist_to_player(npc->pos.x, npc->pos.z) / npc->moveSpeed * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/UnkPositionFunc.inc.c"

EvtScript N(exitWalk_802406F0) = EXIT_WALK_SCRIPT(60,  0, "kmr_04",  0);

EvtScript N(exitWalk_8024074C) = EXIT_WALK_SCRIPT(60,  1, "kmr_05",  0);

EvtScript N(802407A8) = {
    EVT_BIND_TRIGGER(N(exitWalk_802406F0), TRIGGER_FLOOR_ABOVE, 3, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024074C), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 30)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_SET(AreaFlag(8), 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80241450)))
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC_WAIT(N(802422B8))
    EVT_EXEC(N(802406C0))
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 2)
        EVT_SET(LocalVar(0), EVT_PTR(N(802407A8)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_EXEC(N(802407A8))
        EVT_EXEC(N(80242340))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_948)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240950) = {
    .height = 22,
    .radius = 24,
    .level = 99,
    .actionFlags = 16,
};

EvtScript N(8024097C) = {
    EVT_LABEL(1)
    EVT_IF_EQ(AreaFlag(8), 1)
        EVT_LABEL(100)
        EVT_CALL(AwaitPlayerLeave, 294, 123, 170)
        EVT_CALL(EnableNpcAI, 0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SetNpcSpeed, 0, EVT_FLOAT(4.0))
        EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_goompa_Palette_00_Anim_3)
        EVT_CALL(N(func_802401B0_8C8140))
        EVT_CALL(GetAngleToPlayer, 0, LocalVar(2))
        EVT_LOOP(LocalVar(1))
            EVT_CALL(GetNpcPos, 0, LocalVar(7), LocalVar(8), LocalVar(9))
            EVT_CALL(AddVectorPolar, LocalVar(7), LocalVar(9), EVT_FLOAT(4.0), LocalVar(2))
            EVT_CALL(SetNpcPos, 0, LocalVar(7), LocalVar(8), LocalVar(9))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlayerFaceNpc, 0, 3)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 243, 243, 0)
        EVT_CALL(SetNpcVar, 0, 0, 1)
        EVT_CALL(EnableNpcAI, 0, 1)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(npcAI_80240B50) = {
    EVT_LABEL(1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(-122)
            EVT_LABEL(89)
            EVT_CALL(N(UnkPositionFunc), -118, 86, -70, -15)
            EVT_WAIT(1)
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_GOTO(89)
            EVT_END_IF
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcAux, 0, 0)
            EVT_CALL(PlaySoundAtNpc, 0, SOUND_262, 0)
            EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 45, 15, 1, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_goompa_Palette_00_Anim_8, NPC_ANIM_goompa_Palette_00_Anim_1, 0, MESSAGE_ID(0x0B, 0x00A6))
            EVT_CALL(UseSettingsFrom, 0, -220, 20, -72)
            EVT_CALL(SetPanTarget, 0, -20, 0, 68)
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
            EVT_CALL(SetCamDistance, 0, 275)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.5))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_THREAD
                EVT_WAIT(20)
                EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
                EVT_CALL(PlayerMoveTo, -38, 68, 0)
            EVT_END_THREAD
            EVT_CALL(GetNpcPos, 0, LocalVar(7), LocalVar(8), LocalVar(9))
            EVT_CALL(SetNpcSpeed, 0, EVT_FLOAT(4.0))
            EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_goompa_Palette_00_Anim_3)
            EVT_CALL(NpcMoveTo, 0, 0, 70, 0)
            EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_goompa_Palette_00_Anim_1)
            EVT_CALL(InterpNpcYaw, 0, 276, 20)
            EVT_WAIT(30)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_goompa_Palette_00_Anim_8, NPC_ANIM_goompa_Palette_00_Anim_1, 0, MESSAGE_ID(0x0B, 0x00A7))
            EVT_WAIT(5)
            EVT_CALL(SetPlayerAnimation, ANIM_80007)
            EVT_WAIT(30)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_goompa_Palette_00_Anim_8, NPC_ANIM_goompa_Palette_00_Anim_1, 0, MESSAGE_ID(0x0B, 0x00A8))
            EVT_CALL(N(UnkFunc41), 0, 5)
            EVT_SET(GB_StoryProgress, -121)
            EVT_CALL(UseSettingsFrom, 0, -220, 20, -72)
            EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, 0, 0, 0)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(hit_80240F64) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goompa_Palette_00_Anim_7)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goompa_Palette_00_Anim_1)
    EVT_ADD(MapVar(0), 1)
    EVT_IF_LT(MapVar(0), 3)
        EVT_CALL(GetOwnerEncounterTrigger, LocalVar(0))
        EVT_SWITCH(LocalVar(0))
            EVT_CASE_EQ(2)
                EVT_CALL(SetNpcVar, 0, 0, 1)
                EVT_IF_EQ(AreaFlag(6), 1)
                EVT_ELSE
                    EVT_SET(AreaFlag(6), 1)
                    EVT_SET(AreaFlag(7), 0)
                EVT_END_IF
            EVT_CASE_EQ(4)
                EVT_CALL(SetNpcVar, 0, 0, 1)
                EVT_IF_EQ(AreaFlag(7), 1)
                EVT_ELSE
                    EVT_SET(AreaFlag(6), 0)
                    EVT_SET(AreaFlag(7), 1)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goompa_Palette_00_Anim_3)
    EVT_ELSE
        EVT_WAIT(10)
        EVT_CALL(GetNpcPos, 0, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE)
        EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(8024097C)))
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_80240B50)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802411A8) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80240B50)))
    EVT_CALL(BindNpcAux, -1, EVT_PTR(N(8024097C)))
    EVT_CALL(BindNpcHit, -1, EVT_PTR(N(hit_80240F64)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_GE(-121)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_GRAVITY)), FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT)), TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80241260) = {
    .id = NPC_GOOMPA,
    .settings = &N(npcSettings_80240950),
    .pos = { -50.0f, 0.0f, 80.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_400000,
    .init = &N(init_802411A8),
    .yaw = 45,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_goompa_Palette_00_Anim_1,
        NPC_ANIM_goompa_Palette_00_Anim_2,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_1,
        NPC_ANIM_goompa_Palette_00_Anim_1,
        NPC_ANIM_goompa_Palette_00_Anim_0,
        NPC_ANIM_goompa_Palette_00_Anim_0,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
        NPC_ANIM_goompa_Palette_00_Anim_3,
    },
    .tattle = MESSAGE_ID(0x1A, 0x0063),
};

NpcGroupList N(npcGroupList_80241450) = {
    NPC_GROUP(N(npcGroup_80241260), 0x0002, BTL_DEFAULT_STAGE),
    {},
};

static s32 N(pad_1468)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80241470) = {
    EVT_CALL(ModifyColliderFlags, 0, 9, 0x7FFFFE00)
    EVT_SET(GB_StoryProgress, -117)
    EVT_RETURN
    EVT_END
};

EvtScript N(802414A8) = {
    EVT_SET(GF_KMR03_Hammer1Block, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802414C8) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_IF_LT(GB_StoryProgress, -117)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block), 45, 0, 70, 15, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80241470)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 9, 0x7FFFFE00)
    EVT_END_IF
    EVT_IF_EQ(GF_KMR03_Hammer1Block, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block), 230, 0, 310, 15, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(802414A8)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 230, 60, 310, 15, 151, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR03_HiddenItem_RepelGel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 230, 50, -160, 15, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 165, 0, 380, 20, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -170, 0, 370, 43, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR03_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 345, 75, -250, 0, 100, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 205, -250, 17, GF_KMR03_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 230, -250, 17, GF_KMR03_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 255, -250, 17, GF_KMR03_Item_CoinC)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 280, -250, 17, GF_KMR03_Item_CoinD)
    EVT_CALL(MakeItemEntity, ITEM_FIRE_FLOWER, 229, 250, -156, 17, GF_KMR02_Item_FireFlower)
    EVT_CALL(MakeEntity, &Entity_HiddenPanel, 300, 0, 150, 0, 18, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KMR03_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 130, 60, 0, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
