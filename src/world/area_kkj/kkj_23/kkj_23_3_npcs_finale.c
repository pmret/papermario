#include "kkj_23.h"
#include "sprite/player.h"

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/npc/Peach.h"

Vec3f N(FlyAwayPath)[] = {
    {  250.0,    10.0, -240.0 },
    {  220.0,     0.0, -260.0 },
    {  205.0,    40.0, -280.0 },
    {  170.0,   190.0, -300.0 },
};

API_CALLABLE(N(UpdatePropellerSoundPos)) {
    Npc *npc = get_npc_safe(NPC_Bowser_Prop);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z;

    sfx_adjust_env_sound_pos(SOUND_LRAW_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT, x, y, z);
    script->varTable[0] = y;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePropellerSounds) = {
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_Prop, SOUND_LOOP_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT)
    EVT_LOOP(0)
        EVT_CALL(N(UpdatePropellerSoundPos))
        EVT_IF_LT(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_LOOP_BOWSER_PROPELLER)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BowserTauntMario) = {
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_IF_EQ(GF_KKJ23_BowserFledToTower, TRUE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    EVT_CALL(AwaitPlayerApproach, 100, -60, 300)
    EVT_SET(GF_KKJ23_BowserFledToTower, TRUE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarLaugh)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    EVT_END_THREAD
    EVT_CALL(AwaitPlayerApproach, 0, -60, 250)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(FlyAwayPath)), ARRAY_COUNT(N(FlyAwayPath)), EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, LVar1, LVar2, LVar3)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 40)
    EVT_ADD(LVar3, -3)
    EVT_CALL(SetNpcPos, NPC_Peach, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

s32 N(HoverYOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Bowser_Body) = {
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(HoverYOffsets)))
    EVT_LOOP(10)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(GetNpcPos, NPC_Bowser_Body, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, LVar1)
        EVT_CALL(SetNpcPos, NPC_Bowser_Body, LVar2, LVar3, LVar4)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Bowser_Propeller) = {
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(HoverYOffsets)))
    EVT_LOOP(10)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(GetNpcPos, NPC_Bowser_Prop, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, LVar1)
        EVT_CALL(SetNpcPos, NPC_Bowser_Prop, LVar2, LVar3, LVar4)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Peach) = {
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(HoverYOffsets)))
    EVT_LOOP(10)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(GetNpcPos, NPC_Peach, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, LVar1)
        EVT_CALL(SetNpcPos, NPC_Peach, LVar2, LVar3, LVar4)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_Body) = {
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_IF_EQ(GF_KKJ23_BowserFledToTower, TRUE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bowser_Body)))
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(SetNpcPos, NPC_SELF, 250, 10, -250)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_ClownCarIdle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_Propeller) = {
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_IF_EQ(GF_KKJ23_BowserFledToTower, TRUE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bowser_Propeller)))
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(SetNpcPos, NPC_SELF, 250, 10, -250)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_ClownCarPropeller)
    EVT_EXEC(N(EVS_UpdatePropellerSounds))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Peach) = {
    EVT_CALL(SetNpcPos, NPC_Peach, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_IF_EQ(GF_KKJ23_BowserFledToTower, TRUE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Peach)))
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(SetNpcPos, NPC_Peach, 278, 50, -253)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TiedIdle)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Bowser_Body) = {
    .id = NPC_Bowser_Body,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Body),
    .settings = &N(NpcSettings_Bowser),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
};

NpcData N(NpcData_Bowser_Prop) = {
    .id = NPC_Bowser_Prop,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Propeller),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
};

NpcData N(NpcData_Peach) = {
    .id = NPC_Peach,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Peach),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
};

NpcGroupList N(FinaleNPCs) = {
    NPC_GROUP(N(NpcData_Bowser_Body)),
    NPC_GROUP(N(NpcData_Bowser_Prop)),
    NPC_GROUP(N(NpcData_Peach)),
    {}
};
