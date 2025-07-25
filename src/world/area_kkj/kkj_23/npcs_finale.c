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
    Call(PlaySoundAtNpc, NPC_Bowser_Prop, SOUND_LOOP_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT)
    Loop(0)
        Call(N(UpdatePropellerSoundPos))
        IfLt(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(StopSound, SOUND_LOOP_BOWSER_PROPELLER)
    Return
    End
};

EvtScript N(EVS_BowserTauntMario) = {
    IfEq(GF_KKJ13_BowserTaunts, true)
        IfEq(GF_KKJ23_BowserFledToTower, true)
            Return
        EndIf
    EndIf
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    Call(AwaitPlayerApproach, 100, -60, 300)
    Set(GF_KKJ23_BowserFledToTower, true)
    Thread
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarLaugh)
        Wait(30)
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    EndThread
    Call(AwaitPlayerApproach, 0, -60, 250)
    Call(LoadPath, 30, Ref(N(FlyAwayPath)), ARRAY_COUNT(N(FlyAwayPath)), EASING_LINEAR)
    Label(0)
    Call(GetNextPathPos)
    Call(SetNpcPos, NPC_Bowser_Body, LVar1, LVar2, LVar3)
    Call(SetNpcPos, NPC_Bowser_Prop, LVar1, LVar2, LVar3)
    Add(LVar1, 28)
    Add(LVar2, 40)
    Add(LVar3, -3)
    Call(SetNpcPos, NPC_Peach, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Call(SetNpcPos, NPC_Bowser_Body, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    Return
    End
};

s32 N(HoverYOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Bowser_Body) = {
    Label(0)
    UseBuf(Ref(N(HoverYOffsets)))
    Loop(10)
        BufRead1(LVar1)
        Call(GetNpcPos, NPC_Bowser_Body, LVar2, LVar3, LVar4)
        Add(LVar3, LVar1)
        Call(SetNpcPos, NPC_Bowser_Body, LVar2, LVar3, LVar4)
        Wait(3)
    EndLoop
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Bowser_Propeller) = {
    Label(0)
    UseBuf(Ref(N(HoverYOffsets)))
    Loop(10)
        BufRead1(LVar1)
        Call(GetNpcPos, NPC_Bowser_Prop, LVar2, LVar3, LVar4)
        Add(LVar3, LVar1)
        Call(SetNpcPos, NPC_Bowser_Prop, LVar2, LVar3, LVar4)
        Wait(3)
    EndLoop
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Peach) = {
    Label(0)
    UseBuf(Ref(N(HoverYOffsets)))
    Loop(10)
        BufRead1(LVar1)
        Call(GetNpcPos, NPC_Peach, LVar2, LVar3, LVar4)
        Add(LVar3, LVar1)
        Call(SetNpcPos, NPC_Peach, LVar2, LVar3, LVar4)
        Wait(3)
    EndLoop
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bowser_Body) = {
    Call(SetNpcPos, NPC_Bowser_Body, NPC_DISPOSE_LOCATION)
    IfEq(GF_KKJ13_BowserTaunts, true)
        IfEq(GF_KKJ23_BowserFledToTower, true)
            Return
        EndIf
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bowser_Body)))
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(SetNpcPos, NPC_SELF, 250, 10, -250)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_ClownCarIdle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bowser_Propeller) = {
    Call(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    IfEq(GF_KKJ13_BowserTaunts, true)
        IfEq(GF_KKJ23_BowserFledToTower, true)
            Return
        EndIf
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bowser_Propeller)))
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(SetNpcPos, NPC_SELF, 250, 10, -250)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_ClownCarPropeller)
    Exec(N(EVS_UpdatePropellerSounds))
    Return
    End
};

EvtScript N(EVS_NpcInit_Peach) = {
    Call(SetNpcPos, NPC_Peach, NPC_DISPOSE_LOCATION)
    IfEq(GF_KKJ13_BowserTaunts, true)
        IfEq(GF_KKJ23_BowserFledToTower, true)
            Return
        EndIf
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Peach)))
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(SetNpcPos, NPC_Peach, 278, 50, -253)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TiedIdle)
    Return
    End
};

NpcData N(NpcData_Bowser_Body) = {
    .id = NPC_Bowser_Body,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Body),
    .settings = &N(NpcSettings_Bowser),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
};

NpcData N(NpcData_Bowser_Prop) = {
    .id = NPC_Bowser_Prop,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Propeller),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
};

NpcData N(NpcData_Peach) = {
    .id = NPC_Peach,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Peach),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
};

NpcGroupList N(FinaleNPCs) = {
    NPC_GROUP(N(NpcData_Bowser_Body)),
    NPC_GROUP(N(NpcData_Bowser_Prop)),
    NPC_GROUP(N(NpcData_Peach)),
    {}
};
