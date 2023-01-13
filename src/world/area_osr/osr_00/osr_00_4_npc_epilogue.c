#include "osr_00.h"

NpcSettings N(NpcSettings_Unused) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/npc/Yoshi.inc.c"
#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/npc/Penguin.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Boo.inc.c"
#include "world/common/npc/Mouser.inc.c"

EvtScript N(EVS_NpcInteract_LeaderYoshi) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_Outro_0055)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LeaderYoshi) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_LeaderYoshi)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_Outro_0060)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_Outro_0061)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MayorPenguin) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_Outro_0056)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MayorPenguin) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MayorPenguin)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MayorPenguinWife) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_Outro_0057)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MayorPenguinWife) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MayorPenguinWife)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_Outro_0062)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_Outro_0063)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Moustafa) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_Outro_0058)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Moustafa) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Moustafa)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_Outro_005E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_Outro_005D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_Outro_005F)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_Outro_0059)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 0, MSG_Outro_005A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Guard_StopPlayer) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_ToadGuard_02, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_ToadGuard_02, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 0, MSG_Outro_005C)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, 610, 110, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 0, MSG_Outro_005B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard_02)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Guard_StopPlayer)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_YoshiLeader)[] = {
    ANIM_VillageLeader_Still,
    ANIM_VillageLeader_Idle,
    ANIM_VillageLeader_Talk,
    -1
};

s32 N(ExtraAnims_Yoshi)[] = {
    ANIM_Yoshi_Green_Still,
    ANIM_Yoshi_Green_Idle,
    ANIM_Yoshi_Green_Talk,
    -1
};

s32 N(ExtraAnims_YoshiKid)[] = {
    ANIM_YoshiKid_Green_Still,
    ANIM_YoshiKid_Green_Idle,
    ANIM_YoshiKid_Green_Talk,
    -1
};

StaticNpc N(NpcData_Yoshis)[] = {
    {
        .id = NPC_YoshiLeader,
        .settings = &N(NpcSettings_Yoshi),
        .pos = { 70.0f, 0.0f, -30.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_LeaderYoshi),
        .drops = YOSHI_DROPS,
        .animations = YOSHI_LEADER_ANIMS,
        .extraAnimations = N(ExtraAnims_YoshiLeader),
        .tattle = MSG_NpcTattle_VillageLeader,
    },
    {
        .id = NPC_Yoshi,
        .settings = &N(NpcSettings_Yoshi),
        .pos = { 70.0f, 0.0f, 400.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Yoshi),
        .drops = YOSHI_DROPS,
        .animations = YOSHI_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Yoshi),
        .tattle = MSG_NpcTattle_GenericYoshi,
    },
    {
        .id = NPC_YoshiKid,
        .settings = &N(NpcSettings_YoshiKid),
        .pos = { 160.0f, 0.0f, 540.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_YoshiKid),
        .drops = YOSHI_KID_DROPS,
        .animations = YOSHI_KID_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_YoshiKid),
        .tattle = MSG_NpcTattle_GreenYoshiKid,
    },
};

s32 N(ExtraAnims_MayorPenguin)[] = {
    ANIM_MayorPenguin_Still,
    ANIM_MayorPenguin_Idle,
    ANIM_MayorPenguin_Talk,
    -1
};

s32 N(ExtraAnims_MayorPenguinWife)[] = {
    ANIM_MayorPenguinWife_Still,
    ANIM_MayorPenguinWife_Idle,
    ANIM_MayorPenguinWife_Laugh,
    -1
};

s32 N(ExtraAnims_Penguin)[] = {
    ANIM_Penguin_Still,
    ANIM_Penguin_Idle,
    ANIM_Penguin_Talk,
    -1
};

StaticNpc N(NpcData_Penguins)[] = {
    {
        .id = NPC_MayorPenguin,
        .settings = &N(NpcSettings_Penguin),
        .pos = { 150.0f, 0.0f, 105.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_MayorPenguin),
        .drops = PENGUIN_DROPS,
        .animations = MAYOR_PENGUIN_ANIMS,
        .extraAnimations = N(ExtraAnims_MayorPenguin),
        .tattle = MSG_NpcTattle_MayorPenguin,
    },
    {
        .id = NPC_MayorPenguinWife,
        .settings = &N(NpcSettings_Penguin),
        .pos = { 200.0f, 0.0f, 105.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_MayorPenguinWife),
        .drops = PENGUIN_DROPS,
        .animations = MAYOR_PENGUIN_WIFE_ANIMS,
        .extraAnimations = N(ExtraAnims_MayorPenguinWife),
        .tattle = MSG_NpcTattle_MayorPenguinWife,
    },
    {
        .id = NPC_Penguin_01,
        .settings = &N(NpcSettings_Penguin),
        .pos = { 115.0f, 0.0f, 540.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Penguin_01),
        .drops = PENGUIN_DROPS,
        .animations = PENGUIN_ANIMS,
        .extraAnimations = N(ExtraAnims_Penguin),
    },
    {
        .id = NPC_Penguin_02,
        .settings = &N(NpcSettings_Penguin),
        .pos = { 208.0f, 0.0f, 540.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Penguin_02),
        .drops = PENGUIN_DROPS,
        .animations = PENGUIN_ANIMS,
        .extraAnimations = N(ExtraAnims_Penguin),
    },
};

s32 N(ExtraAnims_Moustafa)[] = {
    ANIM_Moustafa_Still,
    ANIM_Moustafa_Idle,
    ANIM_Moustafa_Shout,
    -1
};

s32 N(ExtraAnims_Mouser)[] = {
    ANIM_Mouser_Blue_Still,
    ANIM_Mouser_Blue_Idle,
    ANIM_Mouser_Blue_Talk,
    -1
};

StaticNpc N(NpcData_Mousers)[] = {
    {
        .id = NPC_Moustafa,
        .settings = &N(NpcSettings_Mouser),
        .pos = { -60.0f, 0.0f, -20.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Moustafa),
        .drops = MOUSER_DROPS,
        .animations = MOUSTAFA_ANIMS,
        .extraAnimations = N(ExtraAnims_Moustafa),
        .tattle = MSG_NpcTattle_Moustafa,
    },
    {
        .id = NPC_Mouser,
        .settings = &N(NpcSettings_Mouser),
        .pos = { -100.0f, 0.0f, -50.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Mouser),
        .drops = MOUSER_DROPS,
        .animations = MOUSER_PURPLE_ANIMS,
        .extraAnimations = N(ExtraAnims_Mouser),
    },
};

s32 N(ExtraAnims_Boos)[] = {
    ANIM_Boo_Still,
    ANIM_Boo_Idle,
    ANIM_Boo_Talk,
    -1
};

StaticNpc N(NpcData_Boos)[] = {
    {
        .id = NPC_Boo_01,
        .settings = &N(NpcSettings_Boo),
        .pos = { 270.0f, 20.0f, 175.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Boo_01),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_Boos),
    },
    {
        .id = NPC_Boo_02,
        .settings = &N(NpcSettings_Boo),
        .pos = { 320.0f, 20.0f, 200.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Boo_02),
        .drops = BOO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_Boos),
    },
};

s32 N(ExtraAnims_Toad)[] = {
    ANIM_Toad_Red_Still,
    ANIM_Toad_Red_Idle,
    ANIM_Toad_Red_Talk,
    -1
};

s32 N(ExtraAnims_ToadGuard)[] = {
    ANIM_ToadGuard_Red_Still,
    ANIM_ToadGuard_Red_Idle,
    ANIM_ToadGuard_Red_Talk,
    -1
};

StaticNpc N(NpcData_Toads)[] = {
    {
        .id = NPC_Toad,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -25.0f, 0.0f, 200.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Toad),
        .drops = TOAD_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
    },
    {
        .id = NPC_ToadGuard_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -50.0f, 0.0f, -200.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ToadGuard_01),
        .drops = TOAD_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
    {
        .id = NPC_ToadGuard_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 560.0f, 20.0f, 100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ToadGuard_02),
        .drops = TOAD_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Yoshis)),
    NPC_GROUP(N(NpcData_Penguins)),
    NPC_GROUP(N(NpcData_Mousers)),
    NPC_GROUP(N(NpcData_Boos)),
    NPC_GROUP(N(NpcData_Toads)),
    {}
};
