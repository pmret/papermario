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
    EVT_SETF(LVarA, EVT_FLOAT(3.5 / DT))
    EVT_SET(AF_OMO_11, FALSE)
    EVT_CALL(SetNpcSpeed, NPC_SELF, LVarA)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_IF_GT(LVar2, -210)
                EVT_CALL(N(GetActingPartner))
                EVT_SET(MV_ActingPartner, LVar9)
                EVT_SWITCH(LVar9)
                    EVT_CASE_EQ(-1)
                        EVT_CALL(SetNpcSpeed, NPC_SELF, LVarA)
                        EVT_CALL(N(SurroundPlayer))
                        EVT_IF_GT(LVarE, 30)
                            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                            EVT_IF_EQ(LVar1, 0)
                                EVT_CALL(PlaySound, SOUND_3ED)
                                EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
                                EVT_THREAD
                                    EVT_CALL(ShakeCam, CAM_DEFAULT, 1, 4, EVT_FLOAT(1.0))
                                EVT_END_THREAD
                                EVT_WAIT(3 * DT)
                                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_PanicRun)
                                EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
                                EVT_CALL(PlaySound, SOUND_3EE)
                                EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 15 * DT)
                                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                            EVT_ELSE
                                EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                                EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10 * DT)
                            EVT_END_IF
                            EVT_SET(LVarE, 0)
                        EVT_END_IF
                    EVT_CASE_EQ(PARTNER_WATT)
                        EVT_USE_BUF(EVT_PTR(N(CrowdChaseGoalPositions)))
                        EVT_BUF_READ2(LVar3, LVar4)
                        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        EVT_IF_LT(LVar0, 180)
                            EVT_CALL(GetSelfVar, 1, LVar9)
                            EVT_IF_NE(LVar9, 6)
                                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                                EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15 * DT)
                            EVT_END_IF
                            EVT_IF_EQ(AF_OMO_11, FALSE)
                                EVT_SET(AF_OMO_11, TRUE)
                            EVT_END_IF
                            EVT_USE_BUF(EVT_PTR(N(CrowdChaseGoalPositions)))
                            EVT_BUF_READ2(LVar1, LVar2)
                            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0 / DT))
                            EVT_CALL(N(SimpleMoveNPC), LVar3, LVar4)
                        EVT_ELSE
                            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                            EVT_IF_LT(LVar0, 150)
                                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                                EVT_CALL(NpcJump0, NPC_SELF, LVar3, 0, LVar4, 15 * DT)
                                EVT_WAIT(30 * DT)
                            EVT_ELSE
                                EVT_CALL(DisablePlayerInput, TRUE)
                                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                                EVT_CALL(NpcJump0, NPC_SELF, LVar3, 0, LVar4, 15 * DT)
                                EVT_WAIT(30 * DT)
                                EVT_CALL(DisablePlayerInput, FALSE)
                            EVT_END_IF
                            EVT_CALL(SetSelfVar, 0, 1)
                        EVT_END_IF
                    EVT_CASE_EQ(PARTNER_BOW)
                        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
                        EVT_IF_LT(LVar2, 30)
                            EVT_CALL(N(SimpleMoveNPC), 200, 0)
                        EVT_ELSE
                            EVT_CALL(N(SimpleMoveNPC), -150, 0)
                        EVT_END_IF
                EVT_END_SWITCH
                EVT_SET(LVar9, MV_ActingPartner)
                EVT_CALL(SetSelfVar, 1, LVar9)
            EVT_ELSE
                EVT_CALL(N(SimpleMoveNPC), 200, 0)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_IF_LT(LVar2, 150)
                EVT_CALL(N(GetActingPartner))
                EVT_IF_NE(LVar9, 6)
                    EVT_CALL(SetSelfVar, 0, 0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH4_005D)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15 * DT)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0 / DT))
                EVT_CALL(NpcMoveTo, NPC_SELF, 230, 0, 0)
                EVT_CALL(SetNpcSpeed, NPC_SELF, LVarA)
                EVT_SET(LVar0, 1)
                EVT_LOOP(10)
                    EVT_CALL(SetNpcVar, LVar0, 0, 2)
                    EVT_ADD(LVar0, 1)
                EVT_END_LOOP
                EVT_WAIT(45 * DT)
                EVT_CALL(StopSound, SOUND_8000004C)
                EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH4_005E)
                EVT_THREAD
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
                EVT_END_THREAD
                EVT_CALL(PlaySoundAtCollider, COLLIDER_tt1, SOUND_1E4, SOUND_SPACE_MODE_0)
                EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 37, 37, 1, 10, 30)
                EVT_CALL(EnableModel, MODEL_o821, TRUE)
                EVT_LOOP(10)
                    EVT_CALL(EnableModel, MODEL_o823, TRUE)
                    EVT_CALL(EnableModel, MODEL_o828, TRUE)
                    EVT_WAIT(1)
                    EVT_CALL(EnableModel, MODEL_o823, FALSE)
                    EVT_CALL(EnableModel, MODEL_o828, FALSE)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
                EVT_WAIT(40 * DT)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                EVT_WAIT(20 * DT)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 300, 0, 0)
                EVT_SET(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
                EVT_WAIT(30 * DT)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_Crowd) = {
    EVT_CALL(RandInt, 15, LVarA)
    EVT_ADD(LVarA, 20)
    EVT_DIVF(LVarA, EVT_FLOAT(10.0 * DT))
    EVT_CALL(SetNpcSpeed, NPC_SELF, LVarA)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_IF_GT(LVar2, -210)
                EVT_CALL(N(GetActingPartner))
                EVT_SET(MV_ActingPartner, LVar9)
                EVT_SWITCH(LVar9)
                    EVT_CASE_EQ(-1)
                        EVT_CALL(SetNpcSpeed, NPC_SELF, LVarA)
                        EVT_CALL(N(SurroundPlayer))
                        EVT_IF_GT(LVarE, 30)
                            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                            EVT_IF_EQ(LVar1, 0)
                                EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
                            EVT_ELSE
                                EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                                EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10 * DT)
                            EVT_END_IF
                            EVT_SET(LVarE, 0)
                        EVT_END_IF
                    EVT_CASE_EQ(PARTNER_WATT)
                        EVT_CALL(GetSelfVar, 1, LVar9)
                        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        EVT_IF_NE(LVar9, 6)
                            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                            EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15 * DT)
                        EVT_END_IF
                        EVT_CALL(GetSelfNpcID, LVar5)
                        EVT_USE_BUF(EVT_PTR(N(CrowdChaseGoalPositions)))
                        EVT_LOOP(LVar5)
                            EVT_BUF_READ2(LVar3, LVar4)
                        EVT_END_LOOP
                        EVT_IF_EQ(LVar0, LVarF)
                            EVT_SET(LVar3, LVar0)
                            EVT_ADD(LVar3, 10)
                            EVT_SET(LVar4, 50)
                        EVT_END_IF
                        EVT_SET(LVarF, LVar0)
                        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(7.0 / DT))
                        EVT_CALL(N(SimpleMoveNPC), LVar3, LVar4)
                        EVT_CALL(GetNpcVar, NPC_ShyGuy_01, 0, LVar0)
                        EVT_IF_EQ(LVar0, 1)
                            EVT_CALL(SetSelfVar, 0, 1)
                        EVT_END_IF
                    EVT_CASE_EQ(PARTNER_BOW)
                        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
                        EVT_IF_LT(LVar2, 30)
                            EVT_CALL(N(SimpleMoveNPC), 200, 0)
                        EVT_ELSE
                            EVT_CALL(N(SimpleMoveNPC), -150, 0)
                        EVT_END_IF
                EVT_END_SWITCH
                EVT_SET(LVar9, MV_ActingPartner)
                EVT_CALL(SetSelfVar, 1, LVar9)
            EVT_ELSE
                EVT_CALL(N(SimpleMoveNPC), 200, 0)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(RandInt, 360, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
            EVT_CALL(RandInt, 20 * DT, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(LVar0)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, 2)
            EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 12 * DT)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(N(GetActingPartner))
                EVT_IF_NE(LVar9, 6)
                    EVT_CALL(SetSelfVar, 0, 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 15 * DT, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(LVar0)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, NPC_SELF, 235, LVar1, LVar2, 20 * DT * DT)
            EVT_WAIT(30 * DT)
            EVT_CALL(SetSelfVar, 0, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0 / DT))
            EVT_CALL(NpcMoveTo, NPC_SELF, 235, 0, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 300, 0, 0)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_Loner) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_Loner)))
        EVT_CALL(SetNpcPos, NPC_SELF, 120, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim02)
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_Crowd)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_SUB(LVar0, 0)
        EVT_USE_BUF(EVT_PTR(N(CrowdInitialPositions)))
        EVT_LOOP(LVar0)
            EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim02)
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
