#include "pra_31.h"

#include "world/common/enemy/AlbinoDino.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

API_CALLABLE(N(GetAngleToPlayer)) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    script->varTable[0] = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatus.pos.x, gPlayerStatus.pos.z));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CalculateDinoLerpValues)) {
    script->varTable[6] = script->varTable[0] + 90;
    script->varTable[7] = script->varTable[5] + 90;
    script->varTable[8] = abs(script->varTable[6] - script->varTable[7]);

    if (script->varTable[8] == 270) {
        script->varTable[8] = 90;
        if (script->varTable[6] > script->varTable[7]) {
            script->varTable[6] -= 360;
        } else {
            script->varTable[7] -= 360;
        }
    }
    script->varTable[8] = (script->varTable[8] / 90) * 20;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ChangeDinoDirection) = {
    EVT_CALL(N(GetAngleToPlayer))
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(45, 134)
            EVT_SET(LVar5, 90)
            EVT_SET(LVar6, ANIM_AlbinoDino_Still)
            EVT_SET(LVarA, 90)
        EVT_CASE_RANGE(135, 224)
            EVT_SET(LVar5, 180)
            EVT_SET(LVar6, ANIM_AlbinoDino_StillFwd)
            EVT_SET(LVarA, 270)
        EVT_CASE_RANGE(225, 314)
            EVT_SET(LVar5, 270)
            EVT_SET(LVar6, ANIM_AlbinoDino_Still)
            EVT_SET(LVarA, 270)
        EVT_CASE_DEFAULT
            EVT_SET(LVar5, 0)
            EVT_SET(LVar6, ANIM_AlbinoDino_StillBack)
            EVT_SET(LVarA, 270)
    EVT_END_SWITCH
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(NPC_AlbinoDino_01)
            EVT_SET(LVar0, MV_DinoYaw_01)
        EVT_CASE_EQ(NPC_AlbinoDino_02)
            EVT_SET(LVar0, MV_DinoYaw_02)
        EVT_CASE_EQ(NPC_AlbinoDino_03)
            EVT_SET(LVar0, MV_DinoYaw_03)
    EVT_END_SWITCH
    EVT_IF_NE(LVar5, LVar0)
        EVT_THREAD
            EVT_CALL(N(CalculateDinoLerpValues))
            EVT_CALL(MakeLerp, LVar6, LVar7, LVar8, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SWITCH(LVar3)
                    EVT_CASE_EQ(NPC_AlbinoDino_01)
                        EVT_SET(MV_StatueYaw_01, LVar0)
                    EVT_CASE_EQ(NPC_AlbinoDino_02)
                        EVT_SET(MV_StatueYaw_02, LVar0)
                    EVT_CASE_EQ(NPC_AlbinoDino_03)
                        EVT_SET(MV_StatueYaw_03, LVar0)
                EVT_END_SWITCH
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_PRA_ROTATE_ALBINO_DINO, SOUND_SPACE_DEFAULT)
        EVT_SWITCH(LVar5)
            EVT_CASE_OR_EQ(90)
            EVT_CASE_OR_EQ(270)
                EVT_CALL(MakeLerp, 0, 540, 30, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
                EVT_CALL(SetNpcYaw, NPC_SELF, LVarA)
            EVT_CASE_DEFAULT
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(SetNpcYaw, NPC_SELF, LVarA)
                EVT_END_THREAD
                EVT_CALL(MakeLerp, 0, 360, 20, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar6)
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(NPC_AlbinoDino_01)
            EVT_SET(MV_DinoYaw_01, LVar5)
        EVT_CASE_EQ(NPC_AlbinoDino_02)
            EVT_SET(MV_DinoYaw_02, LVar5)
        EVT_CASE_EQ(NPC_AlbinoDino_03)
            EVT_SET(MV_DinoYaw_03, LVar5)
    EVT_END_SWITCH
    EVT_CALL(N(SetDinoAngle), LVar3, LVar5)
    EVT_CALL(SpeakToPlayer, NPC_SELF, LVar6, LVar6, 5, LVar4)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_AlbinoDino_01) = {
    EVT_SET(LVar3, NPC_AlbinoDino_01)
    EVT_SET(LVar4, MSG_CH7_0167)
    EVT_EXEC_WAIT(N(EVS_ChangeDinoDirection))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_AlbinoDino_02) = {
    EVT_SET(LVar3, NPC_AlbinoDino_02)
    EVT_SET(LVar4, MSG_CH7_0168)
    EVT_EXEC_WAIT(N(EVS_ChangeDinoDirection))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_AlbinoDino_03) = {
    EVT_SET(LVar3, NPC_AlbinoDino_03)
    EVT_SET(LVar4, MSG_CH7_0169)
    EVT_EXEC_WAIT(N(EVS_ChangeDinoDirection))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_AlbinoDino_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_AlbinoDino_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_AlbinoDino_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_AlbinoDino_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_AlbinoDino_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_AlbinoDino_03)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_AlbinoDinos)[] = {
    {
        .id = NPC_AlbinoDino_01,
        .pos = { 190.0f, -10.0f, 165.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_AlbinoDino_01),
        .settings = &N(NpcSettings_AlbinoDino),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ALBINO_DINO_ANIMS,
        .tattle = MSG_NpcTattle_AlbinoDino,
    },
    {
        .id = NPC_AlbinoDino_02,
        .pos = { 300.0f, -10.0f, 89.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_AlbinoDino_02),
        .settings = &N(NpcSettings_AlbinoDino),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ALBINO_DINO_ANIMS,
        .tattle = MSG_NpcTattle_AlbinoDino,
    },
    {
        .id = NPC_AlbinoDino_03,
        .pos = { 452.0f, -10.0f, 139.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_AlbinoDino_03),
        .settings = &N(NpcSettings_AlbinoDino),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ALBINO_DINO_ANIMS,
        .tattle = MSG_NpcTattle_AlbinoDino,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_AlbinoDinos), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_01),
    {}
};
