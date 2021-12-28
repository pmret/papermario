#include "dgb_06.h"
#include "sprite/npc/boo.h"
#include "message_ids.h"

enum {
    NPC_BOO,
};

EntryList N(entryList) = {
    { -575.0f,   0.0f,  175.0f, 90.0f },
    { -150.0f, 100.0f, -250.0f,  0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_06_tattle },
};

EvtSource N(80240320) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3B8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitSingleDoor_802403C0) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 12)
    EVT_SET(EVT_VAR(2), 5)
    EVT_SET(EVT_VAR(3), -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_04"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterSingleDoor_80240474) = {
    EVT_CALL(UseDoorSounds, 0)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 5)
            EVT_SET(EVT_VAR(3), -1)
            EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, 589824)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80240B44)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_IF_EQ(EVT_SAVE_FLAG(1047), 0)
        EVT_CALL(EnableGroup, 28, 0)
    EVT_ELSE
        EVT_CALL(EnableGroup, 25, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(N(exitSingleDoor_802403C0), TRIGGER_WALL_PRESS_A, 12, 1, 0)
    EVT_EXEC(N(80240320))
    EVT_EXEC(N(enterSingleDoor_80240474))
    EVT_RETURN
    EVT_END
};

#include "world/common/StashVars.inc.c"

EvtSource N(80240624) = {
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 2)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ShowGotItem, EVT_VAR(0), 0, 0)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(8024068C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_EXEC_WAIT(N(80240624))
    EVT_END_IF
    EVT_SWITCH(EVT_VAR(11))
        EVT_CASE_EQ(0)
            EVT_CALL(AddItem, EVT_VAR(10), EVT_VAR(0))
        EVT_CASE_EQ(1)
            EVT_CALL(AddKeyItem, EVT_VAR(10))
        EVT_CASE_EQ(2)
            EVT_CALL(AddBadge, EVT_VAR(10), EVT_VAR(0))
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024076C) = {
    EVT_SET(EVT_VAR(10), 19)
    EVT_SET(EVT_VAR(11), 1)
    EVT_SET(EVT_SAVE_FLAG(1048), 1)
    EVT_EXEC_WAIT(N(8024068C))
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EAE30, -300, 50, -200, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignFlag, EVT_SAVE_FLAG(1048))
    EVT_CALL(AssignScript, EVT_PTR(N(8024076C)))
    EVT_CALL(MakeEntity, 0x802EA7E0, -125, 60, 175, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_834)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240840) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtSource N(interact_8024086C) = {
    EVT_IF_EQ(EVT_AREA_FLAG(4), 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00F0))
        EVT_SET(EVT_AREA_FLAG(4), 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00F1))
        EVT_SET(EVT_AREA_FLAG(4), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802408FC) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), -26)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024086C)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80240954) = {
    .id = NPC_BOO,
    .settings = &N(npcSettings_80240840),
    .pos = { -300.0f, 10.0f, 150.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802408FC),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00B3),
};

NpcGroupList N(npcGroupList_80240B44) = {
    NPC_GROUP(N(npcGroup_80240954), BATTLE_ID(0, 0, 0, 0)),
    {},
};

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
