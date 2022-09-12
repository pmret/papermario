#include "arn_03.h"
#include "entity.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/world_bow.h"


static s32 N(KeyItemChoiceList)[112];

EvtScript N(exitWalk_80241830) = EXIT_WALK_SCRIPT(60,  0, "arn_07",  1);

EvtScript N(exitWalk_8024188C) = EXIT_WALK_SCRIPT(60,  1, "arn_05",  0);

EvtScript N(802418E8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241830), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024188C), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterWalk_80241930) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(802418E8))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, -34)
        EVT_CALL(SetPlayerPos, -175, 165, 160)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -175, 165, 160)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_CALL(SetPlayerSpeed, 4)
        EVT_CALL(PlayerMoveTo, -55, 160, 0)
        EVT_EXEC(N(802418E8))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(802418E8)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(AreaFlag(3), 0)
    EVT_SET(AreaFlag(4), 0)
    EVT_SET(AreaFlag(5), 0)
    EVT_IF_LT(GB_StoryProgress, -16)
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244740)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244788)))
    EVT_END_IF
    EVT_IF_EQ(GF_ARN03_WaitingForPackage, 1)
        EVT_SET(MapVar(0), 450)
        EVT_SET(MapVar(1), 450)
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80241780))
    EVT_EXEC(N(enterWalk_80241930))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1BB8)[] = {
    0x00000000, 0x00000000,
};

MobileAISettings N(npcAISettings_80241BC0) = {
    .moveSpeed = 1.0f,
    .moveTime = 25,
    .waitTime = 30,
    .alertRadius = 50.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 10,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 80.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80241BF0) = {
    EVT_CALL(N(func_8024113C_BDFECC), EVT_PTR(N(npcAISettings_80241BC0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241C10) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_80241BF0),
    .level = 99,
};

NpcSettings N(npcSettings_80241C3C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

void N(func_80240E90_BDFC20)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f20;
    f32 temp_f22;

    posX = npc->pos.x;
    posZ = npc->pos.z;
    temp_f22 = (*(enemy->territory->patrol.points + script->functionTemp[2])).x;
    temp_f20 = (*(enemy->territory->patrol.points + script->functionTemp[2])).z;

    npc->yaw = atan2(posX, posZ, temp_f22, temp_f20);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    posX = npc->pos.x;
    posY = npc->pos.y + (*(enemy->territory->patrol.points + script->functionTemp[2])).y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
    posY += (*(enemy->territory->patrol.points + script->functionTemp[2])).y;
    posW = posY - npc->pos.y;
    if (posW > 2.0) {
        npc->pos.y += 2.0;
    } else if (posW < -2.0) {
        npc->pos.y -= 2.0;
    } else {
        npc->pos.y = posY;
    }

    posW = dist2D(npc->pos.x, npc->pos.z, temp_f22, temp_f20);
    if (!(posW > npc->moveSpeed)) {
        script->functionTemp[0] = 2;
    }
}

void N(func_80241068_BDFDF8)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration < 0) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] >= 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
        } else {
            script->functionTemp[0] = 4;
            npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        }
    }
}

ApiStatus N(func_8024113C_BDFECC)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detectPos.x;
    territory.pointZ = enemy->territory->patrol.detectPos.z;
    territory.sizeX = enemy->territory->patrol.detectSize.x;
    territory.sizeZ = enemy->territory->patrol.detectSize.z;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(PatrolAI_MoveInit)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_80240E90_BDFC20)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(PatrolAI_LoiterInit)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80241068_BDFDF8)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(PatrolAI_PostLoiter)(script, npcAISettings, territoryPtr);
            break;
    }

    enemy->varTable[0] = npc->pos.y;
    return ApiStatus_BLOCK;
}

static s32** N(varStash) = NULL;


EvtScript N(80241C6C) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80241C9C) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

s32 N(ItemChoice_HasSelectedItem) = {
    0x00000000,
};

s32 N(ItemChoice_SelectedItemID) = {
    0x00000000,
};

EvtScript N(80241CD4) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_BITWISE_OR_CONST(LVar0, 0x50000)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80241E18) = {
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(80241CD4), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241E68) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80241EB0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-26)
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0073)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0074)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0075)
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0076)
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0077)
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0078)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
            EVT_WAIT(20)
            EVT_CALL(EndSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80242064) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(25)
    EVT_THREAD
        EVT_WAIT(50)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, 0, 325)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
        EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(GetCurrentPartnerID, LVar6)
        EVT_IF_NE(LVar6, 9)
            EVT_CALL(BringPartnerOut, 9)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            EVT_WAIT(5)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
            EVT_IF_EQ(LVar6, 4)
                EVT_CALL(NpcJump0, NPC_PARTNER, -81, 176, 171, 20)
            EVT_ELSE
                EVT_CALL(NpcJump0, NPC_PARTNER, -81, 186, 171, 20)
            EVT_END_IF
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(NpcJump0, NPC_SELF, -8, 186, 159, 60)
    EVT_WAIT(15)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, -4, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MSG_CH3_006E)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, -1, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 5, MSG_CH3_006F)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MSG_CH3_0070)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, -1, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 5, MSG_CH3_0071)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MSG_CH3_0072)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(10)
    EVT_CALL(GetCurrentPartnerID, LVar6)
    EVT_IF_NE(LVar6, 9)
        EVT_CALL(PutPartnerAway)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_SELF, 30, 125, 30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_THREAD
    EVT_CALL(func_802CF56C, 2)
    EVT_WAIT(15)
    EVT_SET(GB_StoryProgress, -34)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, 3)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802424E0) = {
    EVT_IF_LT(GB_StoryProgress, -34)
        EVT_CALL(SetNpcPos, NPC_SELF, 175, 240, 145)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242064)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241EB0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024254C) = {
    EVT_IF_NE(MapVar(0), 0)
        EVT_IF_GE(MapVar(0), MapVar(1))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0081)
            EVT_SET(LVar0, 118)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(80241C6C))
            EVT_CALL(AddKeyItem, ITEM_KOOT_PACKAGE)
            EVT_SET(MapVar(0), 0)
            EVT_SET(GF_ARN03_RecievedPackage, 1)
            EVT_SET(GF_ARN03_WaitingForPackage, 0)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0080)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-26)
            EVT_IF_EQ(AreaFlag(3), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0079)
                EVT_SET(AreaFlag(3), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_007A)
                EVT_SET(AreaFlag(3), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_007B)
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_007C)
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_007D)
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_007E)
    EVT_END_SWITCH
    EVT_IF_EQ(GF_ARN03_RecievedPackage, 0)
        EVT_IF_EQ(GB_KootFavor_Current, 18)
            EVT_EXEC_WAIT(N(80241E68))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_007F)
            EVT_CALL(EndSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0)
            EVT_SET(MapVar(0), 0)
            EVT_SET(MapVar(1), 450)
            EVT_SET(GF_ARN03_WaitingForPackage, 1)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_ADD(MapVar(0), 1)
                    EVT_WAIT(1)
                    EVT_IF_GE(MapVar(0), MapVar(1))
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802428A8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024254C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802428CC) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_ADD(LVar0, 60)
        EVT_CALL(SetNpcYaw, 4, 90)
    EVT_ELSE
        EVT_SUB(LVar0, 60)
        EVT_CALL(SetNpcYaw, 4, 270)
    EVT_END_IF
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetNpcPos, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_802CFD30, 4, 7, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802429D4) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_ADD(LVar0, 30)
    EVT_ELSE
        EVT_SUB(LVar0, 30)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 40, 0)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, 4, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, 4, LVar0, LVar2, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242B0C) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_ADD(LVar0, 60)
    EVT_ELSE
        EVT_SUB(LVar0, 60)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 255, 0, 40, 0)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, 4, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, 4, LVar0, LVar2, 40)
    EVT_CALL(SetNpcPos, 4, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242C60) = {
    EVT_EXEC_WAIT(N(802429D4))
    EVT_SET(MapVar(2), 0)
    EVT_SET(MapVar(3), 0)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80017)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_9)
        EVT_LOOP(0)
            EVT_IF_EQ(MapVar(2), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_1)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_boo_Palette_01_Anim_8)
    EVT_CALL(EndSpeech, 4, NPC_ANIM_boo_Palette_01_Anim_8, NPC_ANIM_boo_Palette_01_Anim_8, 5)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_boo_Palette_01_Anim_1)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(80242B0C))
    EVT_SET(MapVar(2), 1)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80242DC4) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-26)
            EVT_IF_EQ(AreaFlag(4), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0082)
                EVT_SET(AreaFlag(4), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0083)
                EVT_SET(AreaFlag(4), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0084)
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0085)
        EVT_CASE_LT(39)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar2, -20)
                EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0))
                EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0086)
            EVT_EXEC_WAIT(N(802428CC))
            EVT_CALL(PlayerFaceNpc, 4, 1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 4, 1)
            EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MSG_CH3_0087)
            EVT_EXEC_WAIT(N(80242C60))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0088)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
        EVT_CASE_GE(39)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar2, -20)
                EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0))
                EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0089)
            EVT_EXEC_WAIT(N(802428CC))
            EVT_CALL(PlayerFaceNpc, 4, 1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 4, 1)
            EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MSG_CH3_008A)
            EVT_EXEC_WAIT(N(80242C60))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_008B)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802431A4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80242DC4)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802431C8) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-26)
            EVT_IF_EQ(AreaFlag(5), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_008C)
                EVT_SET(AreaFlag(5), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_008D)
                EVT_SET(AreaFlag(5), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_008E)
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_008F)
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0090)
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MSG_CH3_0091)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243328) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802431C8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024334C) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80243378) = {
    .id = 0,
    .settings = &N(npcSettings_80241C10),
    .pos = { 36.0f, 185.0f, 140.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802424E0),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 2, 36, 10, 185, 56, 10, 185, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 479, 215, 198, 150 }},
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
    .tattle = MSG_NpcTattle_ARN_LovesBow,
};

StaticNpc N(npcGroup_80243568) = {
    .id = 1,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 209.0f, 185.0f, 217.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802428A8),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
    .tattle = MSG_NpcTattle_ARN_BooA,
};

StaticNpc N(npcGroup_80243758) = {
    .id = 2,
    .settings = &N(npcSettings_80241C10),
    .pos = { 379.0f, 186.0f, 186.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802431A4),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 2, 379, 10, 186, 399, 10, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 479, 215, 198, 150 }},
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
    .tattle = MSG_NpcTattle_ARN_BooB,
};

StaticNpc N(npcGroup_80243948) = {
    .id = 3,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 544.0f, 235.0f, 128.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80243328),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
    .tattle = MSG_NpcTattle_ARN_BooC,
};

StaticNpc N(npcGroup_80243B38) = {
    .id = 4,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_8024334C),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
};

EvtScript N(idle_80243D28) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -60)
    EVT_SET(LVar4, LVar0)
    EVT_ADD(LVar4, 60)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(0.1))
        EVT_ADDF(LVar6, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, LVar6)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
        EVT_CALL(RandInt, 5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(0.1))
        EVT_ADDF(LVar6, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, LVar6)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar4, LVar2, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243E90) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243ECC) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243F08) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243F44) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80243F80)[] = {
    {
        .id = 5,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 36.0f, 277.0f, 140.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243E90),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    },
    {
        .id = 6,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 180.0f, 285.0f, 182.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243ECC),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    },
    {
        .id = 7,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 349.0f, 286.0f, 152.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243F08),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    },
    {
        .id = 8,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 490.0f, 324.0f, 128.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243F44),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    },
};

NpcGroupList N(npcGroupList_80244740) = {
    NPC_GROUP(N(npcGroup_80243378)),
    NPC_GROUP(N(npcGroup_80243568)),
    NPC_GROUP(N(npcGroup_80243758)),
    NPC_GROUP(N(npcGroup_80243948)),
    NPC_GROUP(N(npcGroup_80243B38)),
    {},
};

NpcGroupList N(npcGroupList_80244788) = {
    NPC_GROUP(N(npcGroup_80243378)),
    NPC_GROUP(N(npcGroup_80243568)),
    NPC_GROUP(N(npcGroup_80243758)),
    NPC_GROUP(N(npcGroup_80243948)),
    NPC_GROUP(N(npcGroup_80243B38)),
    NPC_GROUP(N(npcGroup_80243F80)),
    {},
};

static s32 N(pad_47DC) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 300, 237, 60, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN03_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 250, 237, 125, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeKeyChoice.inc.c"
