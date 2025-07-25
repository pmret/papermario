#include "iwa_00.h"
#include "effects.h"

#include "world/common/enemy/MontyMole_GroundAmbush.inc.c"
#include "world/common/enemy/MontyMole_WallAmbush.inc.c"
#include "world/common/enemy/Whacka.inc.c"

#include "world/common/complete/GiveReward.inc.c"
#if VERSION_JP
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"
#include "world/common/todo/UnkScriptJP00.inc.c"
#endif

API_CALLABLE(N(func_80240118_90CD58)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 20;
    }
    if (script->functionTemp[1] & 1) {
        npc->flags &= ~NPC_FLAG_INVISIBLE;
    } else {
        npc->flags |= NPC_FLAG_INVISIBLE;
    }
    if (script->functionTemp[1] == 15) {
        sfx_play_sound_at_position(SOUND_ACTOR_DEATH, SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z);
        fx_damage_stars(FX_DAMAGE_STARS_1, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z, 0.0f, -1.0f, 0.0f, 10);
    }

    temp = script->functionTemp[1];
    if (script->functionTemp[1] == 10) {
        fx_big_smoke_puff(npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 10.0f);
        // odd logic needed to match
        if (script->functionTemp[1] == temp) {
            spawn_drops(enemy);
        }
    }

    script->functionTemp[1]--;
    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

NpcData N(NpcData_MontyMole_GroundAmbush)[] = {
    {
        .id = NPC_MontyMole_01,
        .pos = { 880.0f, 70.0f, 67.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 880, 70, 67 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 880, 70, 67 },
                .detectSize = { 120 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_GroundAmbush),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_01_Hole,
        .pos = { 880.0f, 70.0f, 67.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 880, 70, 67 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_GroundAmbush_Hole),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DISABLE_AI | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
    },
};

NpcData N(NpcData_MontyMole_WallAmbush)[] = {
    {
        .id = NPC_MontyMole_02,
        .pos = { 1220.0f, -30.0f, 70.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 1220, -30, 70 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 1220, -30, 70 },
                .detectSize = { 120 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_WallAmbush),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_02_Hole,
        .pos = { 1220.0f, -30.0f, 70.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 1220, -30, 70 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_WallAmbush_Hole),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DISABLE_AI | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
    },
};

EvtScript N(EVS_NpcInteract_Whacka_01) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfLt(LVar0, LVar3)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Else
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
    EndIf
    Switch(GB_IWA00_Whacka_HitCount)
        CaseEq(0)
            IfEq(GF_IWA00_Met_Whacka, false)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0027)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0028)
            EndIf
        CaseLe(2)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0028)
        CaseLe(4)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0029)
        CaseLe(6)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002A)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002B)
    EndSwitch
    Set(GF_IWA00_Met_Whacka, true)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Whacka_01) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Whacka_Idle)
    Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
    Call(SetNpcPos, NPC_Whacka_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Whacka_02, NPC_DISPOSE_LOCATION)
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGe(LVar1, 20)
        Wait(1)
        Goto(0)
    EndIf
    IfLt(LVar0, 600)
        Wait(1)
        Goto(0)
    EndIf
    IfGt(LVar0, 850)
        Wait(1)
        Goto(0)
    EndIf
    Call(SetNpcPos, NPC_Whacka_01, LVarA, LVarB, LVarC)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Whacka_PopUp)
    Wait(15)
    Call(SetNpcPos, NPC_Whacka_02, LVarA, LVarB, LVarC)
    Wait(5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Whacka_Idle)
    Wait(30)
    Label(10)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLe(LVar0, 900)
        Goto(10)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Whacka_Burrow)
    Call(SetNpcPos, NPC_Whacka_02, NPC_DISPOSE_LOCATION)
    Wait(15)
    Call(SetNpcPos, NPC_Whacka_01, NPC_DISPOSE_LOCATION)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcHit_Whacka_02) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(LVarA, 1)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Set(LVarA, 1)
        CaseEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(GetCurrentPartnerID, LVar2)
            IfEq(LVar2, PARTNER_KOOPER)
                Set(LVarA, 2)
            Else
                Set(LVarA, 3)
            EndIf
        CaseDefault
            Set(LVarA, 0)
    EndSwitch
    IfEq(LVarA, 0)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(BindNpcInteract, NPC_Whacka_01, 0)
    Call(EnableNpcAI, NPC_Whacka_01, false)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfLt(LVar0, LVar3)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Set(LVarB, 0)
    Else
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
        Set(LVarB, 1)
    EndIf
    Add(GB_IWA00_Whacka_HitCount, 1)
    IfEq(LVarA, 3)
        Add(GB_IWA00_Whacka_HitCount, 1)
    EndIf
    Switch(LVarA)
        CaseOrEq(2)
        CaseOrEq(3)
            Call(PlaySoundAtNpc, NPC_Whacka_01, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
        EndCaseGroup
    EndSwitch
    Switch(LVarA)
        CaseOrEq(1)
        CaseOrEq(2)
            Wait(1)
            Call(SetNpcAnimation, NPC_Whacka_01, ANIM_Whacka_Hurt)
            Wait(15)
            Call(GetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            IfEq(LVarB, 0)
                Add(LVar0, 14)
            Else
                Sub(LVar0, 14)
            EndIf
            Add(LVar1, 30)
            Add(LVar2, 2)
            Call(MakeItemEntity, ITEM_WHACKAS_BUMP, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, 0)
            Call(SetNpcAnimation, NPC_Whacka_01, ANIM_Whacka_Idle)
            Wait(5)
        EndCaseGroup
        CaseEq(3)
            Call(GetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            Add(LVar0, 1)
            Call(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            Wait(1)
            Sub(LVar0, 2)
            Call(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            Wait(1)
            Add(LVar0, 2)
            Call(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            Wait(1)
            Sub(LVar0, 1)
            Call(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            Wait(1)
        EndCaseGroup
    EndSwitch
    IfLt(GB_IWA00_Whacka_HitCount, 8)
        Switch(LVarA)
            CaseEq(1)
                Call(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002C)
            CaseEq(2)
                Call(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002D)
            CaseEq(3)
                Call(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002E)
        EndSwitch
        Call(SetNpcAnimation, NPC_Whacka_01, ANIM_Whacka_Burrow)
        Wait(15)
    Else
        Call(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002F)
        Wait(2)
    EndIf
    IfGe(GB_IWA00_Whacka_HitCount, 8)
        Call(N(func_80240118_90CD58))
    EndIf
    Call(SetNpcPos, NPC_Whacka_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Whacka_02, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, false)
    Call(RemoveNpc, NPC_Whacka_01)
    Call(RemoveNpc, NPC_Whacka_02)
    Return
    End
};

EvtScript N(EVS_NpcInit_Whacka_01) = {
    Call(SetNpcVar, NPC_Whacka_01, 8, 0)
    IfLt(GB_IWA00_Whacka_HitCount, 8)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Whacka_01)))
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Whacka_01)))
        Call(EnableNpcShadow, NPC_SELF, false)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLIP_INSTANTLY, true)
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Whacka_02) = {
    IfLt(GB_IWA00_Whacka_HitCount, 8)
        Call(EnableNpcShadow, NPC_SELF, false)
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Whacka_02)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Whacka)[] = {
    {
        .id = NPC_Whacka_01,
        .pos = { 725.0f, -30.0f, 225.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Whacka_01),
        .settings = &N(NpcSettings_Whacka),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = WHACKA_ANIMS,
        .tattle = MSG_NpcTattle_Whacka,
    },
    {
        .id = NPC_Whacka_02,
        .pos = { 725.0f, -30.0f, 225.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Whacka_02),
        .settings = &N(NpcSettings_Whacka),
        .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = WHACKA_ANIMS,
        .tattle = MSG_NpcTattle_Whacka,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_MontyMole_GroundAmbush), BTL_IWA_FORMATION_06, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_WallAmbush), BTL_IWA_FORMATION_07, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Whacka)),
    {}
};
