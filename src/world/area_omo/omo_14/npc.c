#include "omo_14.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(SurroundPlayer)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    f32 goalPosX = playerStatus->pos.x +
        ((playerStatus->colliderDiameter + npc->collisionDiameter) * 0.5f * sin_deg((npc->npcID * 360.0f) / 10.0f));
    f32 goalPosZ = playerStatus->pos.z -
        ((playerStatus->colliderDiameter + npc->collisionDiameter) * 0.5f * cos_deg((npc->npcID * 360.0f) / 10.0f));
    f32 dist = dist2D(npc->pos.x, npc->pos.z, goalPosX, goalPosZ);

    if (npc->moveSpeed < dist) {
        if (npc->flags & NPC_FLAG_COLLDING_WITH_WORLD) {
            if (npc->yaw < 180.0f) {
                npc->yaw = npc->pos.z > 0.0f ? 45.0f : 135.0f;
            } else {
                npc->yaw = npc->pos.z > 0.0f ? 315.0f : 225.0f;
            }
        } else {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, goalPosX, goalPosZ);
        }
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    } else {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
    }

    if (script->varTableF[11] == playerStatus->pos.x && script->varTableF[13] == playerStatus->pos.z) {
        if (dist < 20.0f) {
            script->varTable[14]++;
        } else {
            script->varTable[14] = 0;
        }
    }
    script->varTableF[11] = playerStatus->pos.x;
    script->varTableF[12] = playerStatus->pos.y;
    script->varTableF[13] = playerStatus->pos.z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SimpleMoveNPC)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    f32 x = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    if (npc->moveSpeed < dist2D(npc->pos.x, npc->pos.z, x, z)) {
        if (npc->flags & NPC_FLAG_COLLDING_WITH_WORLD) {
            if (npc->yaw < 180.0f) {
                npc->yaw = npc->pos.z > 0.0f ? 45.0f : 135.0f;
            } else {
                npc->yaw = npc->pos.z > 0.0f ? 315.0f : 225.0f;
            }
        } else {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        }
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetActingPartner)) {
    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        script->varTable[9] = gPartnerStatus.actingPartner;
    } else {
        script->varTable[9] = -1;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IsPartnerWatt)) {
    if (gPartnerStatus.actingPartner == PARTNER_WATT) {
        script->varTable[1] = TRUE;
    } else {
        script->varTable[1] = FALSE;
    }
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ShyGuy_Stationary.inc.c"

Vec2i N(CrowdChaseGoalPositions)[] = {
    { 200,   0 },
    { 210, -10 },
    { 210,  10 },
    { 220, -20 },
    { 220,   0 },
    { 220,  20 },
    { 230,  30 },
    { 230,  10 },
    { 230,   0 },
    { 230,  10 },
    { 230,  30 },
};

EvtScript N(EVS_NpcIdle_ShyGuy_Loner) = {
    SetF(LVarA, Float(3.5 / DT))
    Set(AF_OMO_11, FALSE)
    Call(SetNpcSpeed, NPC_SELF, LVarA)
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            IfGt(LVar2, -210)
                Call(N(GetActingPartner))
                Set(MV_ActingPartner, LVar9)
                Switch(LVar9)
                    CaseEq(-1)
                        Call(SetNpcSpeed, NPC_SELF, LVarA)
                        Call(N(SurroundPlayer))
                        IfGt(LVarE, 30)
                            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                            Call(GetPlayerPos, LVar0, LVar1, LVar2)
                            IfEq(LVar1, 0)
                                Call(PlaySound, SOUND_MASTER_SMACK)
                                Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
                                Thread
                                    Call(ShakeCam, CAM_DEFAULT, 1, 4, Float(1.0))
                                EndThread
                                Wait(3 * DT)
                                Call(SetPlayerAnimation, ANIM_Mario1_PanicRun)
                                Call(SetPlayerJumpscale, Float(1.0))
                                Call(PlaySound, SOUND_MASTER_PUNCH)
                                Call(PlayerJump1, LVar0, LVar1, LVar2, 15 * DT)
                                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                            Else
                                Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                                Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10 * DT)
                            EndIf
                            Set(LVarE, 0)
                        EndIf
                    CaseEq(PARTNER_WATT)
                        UseBuf(Ref(N(CrowdChaseGoalPositions)))
                        BufRead2(LVar3, LVar4)
                        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        IfLt(LVar0, 180)
                            Call(GetSelfVar, 1, LVar9)
                            IfNe(LVar9, 6)
                                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                                Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                                Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15 * DT)
                            EndIf
                            IfEq(AF_OMO_11, FALSE)
                                Set(AF_OMO_11, TRUE)
                            EndIf
                            UseBuf(Ref(N(CrowdChaseGoalPositions)))
                            BufRead2(LVar1, LVar2)
                            Call(SetNpcSpeed, NPC_SELF, Float(4.0 / DT))
                            Call(N(SimpleMoveNPC), LVar3, LVar4)
                        Else
                            Call(GetPlayerPos, LVar0, LVar1, LVar2)
                            IfLt(LVar0, 150)
                                Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                                Call(NpcJump0, NPC_SELF, LVar3, 0, LVar4, 15 * DT)
                                Wait(30 * DT)
                            Else
                                Call(DisablePlayerInput, TRUE)
                                Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                                Call(NpcJump0, NPC_SELF, LVar3, 0, LVar4, 15 * DT)
                                Wait(30 * DT)
                                Call(DisablePlayerInput, FALSE)
                            EndIf
                            Call(SetSelfVar, 0, 1)
                        EndIf
                    CaseEq(PARTNER_BOW)
                        Call(GetPlayerPos, LVar2, LVar3, LVar4)
                        IfLt(LVar2, 30)
                            Call(N(SimpleMoveNPC), 200, 0)
                        Else
                            Call(N(SimpleMoveNPC), -150, 0)
                        EndIf
                EndSwitch
                Set(LVar9, MV_ActingPartner)
                Call(SetSelfVar, 1, LVar9)
            Else
                Call(N(SimpleMoveNPC), 200, 0)
            EndIf
        CaseEq(1)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            IfLt(LVar2, 150)
                Call(N(GetActingPartner))
                IfNe(LVar9, 6)
                    Call(SetSelfVar, 0, 0)
                EndIf
            Else
                Call(DisablePlayerInput, TRUE)
                Call(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH4_005D)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15 * DT)
                Call(SetNpcSpeed, NPC_SELF, Float(4.0 / DT))
                Call(NpcMoveTo, NPC_SELF, 230, 0, 0)
                Call(SetNpcSpeed, NPC_SELF, LVarA)
                Set(LVar0, 1)
                Loop(10)
                    Call(SetNpcVar, LVar0, 0, 2)
                    Add(LVar0, 1)
                EndLoop
                Wait(45 * DT)
                Call(StopSound, SOUND_LOOP_SHY_GUY_CROWD_1)
                Call(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH4_005E)
                Thread
                    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
                EndThread
                Call(PlaySoundAtCollider, COLLIDER_tt1, SOUND_TROMP_CRASH, SOUND_SPACE_DEFAULT)
                PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 37, 37, 1, 10, 30)
                Call(EnableModel, MODEL_o821, TRUE)
                Loop(10)
                    Call(EnableModel, MODEL_o823, TRUE)
                    Call(EnableModel, MODEL_o828, TRUE)
                    Wait(1)
                    Call(EnableModel, MODEL_o823, FALSE)
                    Call(EnableModel, MODEL_o828, FALSE)
                    Wait(1)
                EndLoop
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
                Wait(40 * DT)
                Call(InterpNpcYaw, NPC_SELF, 270, 0)
                Wait(20 * DT)
                Call(SetNpcSpeed, NPC_SELF, Float(4.0))
                Call(NpcMoveTo, NPC_SELF, 300, 0, 0)
                Set(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
                Wait(30 * DT)
                Call(DisablePlayerInput, FALSE)
                Call(RemoveNpc, NPC_SELF)
            EndIf
    EndSwitch
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_ShyGuy_Crowd) = {
    Call(RandInt, 15, LVarA)
    Add(LVarA, 20)
    DivF(LVarA, Float(10.0 * DT))
    Call(SetNpcSpeed, NPC_SELF, LVarA)
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            IfGt(LVar2, -210)
                Call(N(GetActingPartner))
                Set(MV_ActingPartner, LVar9)
                Switch(LVar9)
                    CaseEq(-1)
                        Call(SetNpcSpeed, NPC_SELF, LVarA)
                        Call(N(SurroundPlayer))
                        IfGt(LVarE, 30)
                            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                            Call(GetPlayerPos, LVar0, LVar1, LVar2)
                            IfEq(LVar1, 0)
                                Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
                            Else
                                Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                                Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10 * DT)
                            EndIf
                            Set(LVarE, 0)
                        EndIf
                    CaseEq(PARTNER_WATT)
                        Call(GetSelfVar, 1, LVar9)
                        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        IfNe(LVar9, 6)
                            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                            Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15 * DT)
                        EndIf
                        Call(GetSelfNpcID, LVar5)
                        UseBuf(Ref(N(CrowdChaseGoalPositions)))
                        Loop(LVar5)
                            BufRead2(LVar3, LVar4)
                        EndLoop
                        IfEq(LVar0, LVarF)
                            Set(LVar3, LVar0)
                            Add(LVar3, 10)
                            Set(LVar4, 50)
                        EndIf
                        Set(LVarF, LVar0)
                        Call(SetNpcSpeed, NPC_SELF, Float(7.0 / DT))
                        Call(N(SimpleMoveNPC), LVar3, LVar4)
                        Call(GetNpcVar, NPC_ShyGuy_01, 0, LVar0)
                        IfEq(LVar0, 1)
                            Call(SetSelfVar, 0, 1)
                        EndIf
                    CaseEq(PARTNER_BOW)
                        Call(GetPlayerPos, LVar2, LVar3, LVar4)
                        IfLt(LVar2, 30)
                            Call(N(SimpleMoveNPC), 200, 0)
                        Else
                            Call(N(SimpleMoveNPC), -150, 0)
                        EndIf
                EndSwitch
                Set(LVar9, MV_ActingPartner)
                Call(SetSelfVar, 1, LVar9)
            Else
                Call(N(SimpleMoveNPC), 200, 0)
            EndIf
        CaseEq(1)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(RandInt, 360, LVar0)
            Call(InterpNpcYaw, NPC_SELF, LVar0, 0)
            Call(RandInt, 20 * DT, LVar0)
            Add(LVar0, 1)
            Wait(LVar0)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(SetNpcJumpscale, NPC_SELF, 2)
            Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 12 * DT)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 1)
                Call(N(GetActingPartner))
                IfNe(LVar9, 6)
                    Call(SetSelfVar, 0, 0)
                EndIf
            EndIf
        CaseEq(2)
            Call(RandInt, 15 * DT, LVar0)
            Add(LVar0, 1)
            Wait(LVar0)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
            Call(NpcJump0, NPC_SELF, 235, LVar1, LVar2, 20 * DT * DT)
            Wait(30 * DT)
            Call(SetSelfVar, 0, 3)
        CaseEq(3)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
            Call(SetNpcSpeed, NPC_SELF, Float(4.0 / DT))
            Call(NpcMoveTo, NPC_SELF, 235, 0, 0)
            Call(NpcMoveTo, NPC_SELF, 300, 0, 0)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_Loner) = {
    IfLt(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy_Loner)))
        Call(SetNpcPos, NPC_SELF, 120, 0, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim02)
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

Vec3i N(CrowdInitialPositions)[] = {
    { 150, 0, -100 },
    { 150, 0,  -50 },
    { 150, 0,    0 },
    { 150, 0,   50 },
    { 150, 0,  100 },
    { 180, 0, -100 },
    { 180, 0,  -50 },
    { 180, 0,    0 },
    { 180, 0,   50 },
    { 180, 0,  100 },
};

EvtScript N(EVS_NpcInit_ShyGuy_Crowd) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy_Crowd)))
    IfLt(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        Call(GetSelfNpcID, LVar0)
        Sub(LVar0, 0)
        UseBuf(Ref(N(CrowdInitialPositions)))
        Loop(LVar0)
            BufRead3(LVar1, LVar2, LVar3)
        EndLoop
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim02)
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_ShyGuy_Loner) = {
    .id = NPC_ShyGuy_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_ShyGuy_Loner),
    .settings = &N(NpcSettings_ShyGuy_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_Crowd)[] = {
    {
        .id = NPC_ShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_10,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_11,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy_Loner)),
    NPC_GROUP(N(NpcData_ShyGuy_Crowd)),
    {}
};
