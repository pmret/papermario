#include "arn_03.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/world_bow.h"

static s32 N(D_80244A20)[112];

EvtSource N(exitWalk_80241830) = EXIT_WALK_SCRIPT(60,  0, "arn_07",  1);

EvtSource N(exitWalk_8024188C) = EXIT_WALK_SCRIPT(60,  1, "arn_05",  0);

EvtSource N(802418E8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241830), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024188C), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterWalk_80241930) = {
    EVT_CALL(GetLoadType, EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(802418E8))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(EVT_SAVE_VAR(0), -34)
        EVT_CALL(SetPlayerPos, -175, 165, 160)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -175, 165, 160)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_CALL(SetPlayerSpeed, 4)
        EVT_CALL(PlayerMoveTo, -55, 160, 0)
        EVT_EXEC(N(802418E8))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_VAR(0), EVT_PTR(N(802418E8)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(EVT_AREA_FLAG(3), 0)
    EVT_SET(EVT_AREA_FLAG(4), 0)
    EVT_SET(EVT_AREA_FLAG(5), 0)
    EVT_IF_LT(EVT_SAVE_VAR(0), -16)
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244740)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244788)))
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(1020), 1)
        EVT_SET(EVT_MAP_VAR(0), 450)
        EVT_SET(EVT_MAP_VAR(1), 450)
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80241780))
    EVT_EXEC(N(enterWalk_80241930))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1BB8)[] = {
    0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80241BC0) = {
    .moveSpeed = 1.0f,
    .moveTime = 25,
    .waitTime = 30,
    .alertRadius = 50.0f,
    .unk_10 = { .f = 50.0f },
    .unk_14 = 10,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 80.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_80241BF0) = {
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

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80240B94_BDF924)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}

void N(func_80240E90_BDFC20)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
    npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
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

void N(func_80241068_BDFDF8)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
            npc->currentAnim.w = enemy->animList[0];
        }
    }
}

ApiStatus N(func_8024113C_BDFECC)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_80240E90_BDFC20)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80241068_BDFDF8)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, npcAISettings, territoryPtr);
            break;
    }

    enemy->varTable[0] = npc->pos.y;
    return ApiStatus_BLOCK;
}

#include "world/common/StashVars.inc.c"

EvtSource N(80241C6C) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(80241C9C) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

s32 N(D_80241CCC_BE0A5C) = {
    0x00000000,
};

s32 N(D_80241CD0_BE0A60) = {
    0x00000000,
};

EvtSource N(80241CD4) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(1))
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, EVT_VAR(1))
            EVT_CALL(GetPlayerPos, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(N(AddPlayerHandsOffset), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_BITWISE_OR_CONST(EVT_VAR(0), 0x50000)
            EVT_CALL(MakeItemEntity, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(RemoveItemEntity, EVT_VAR(0))
    EVT_END_SWITCH
    EVT_CALL(N(func_80241648_BE03D8), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(80241E18) = {
    EVT_CALL(N(func_80241680_BE0410), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(80241CD4), 0x10, 0, EVT_PTR(N(D_80244A20)), 0, 1)
    EVT_CALL(N(func_802415F4_BE0384), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtSource N(80241E68) = {
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetPlayerAnimation, ANIM_80007)
    EVT_WAIT_FRAMES(20)
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241EB0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0073))
                EVT_SET(EVT_AREA_FLAG(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0074))
                EVT_SET(EVT_AREA_FLAG(2), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0075))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0076))
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0077))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0078))
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetPlayerAnimation, ANIM_80007)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EndSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242064) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(25)
    EVT_THREAD
        EVT_WAIT_FRAMES(50)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 325)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(6))
        EVT_IF_NE(EVT_VAR(6), 9)
            EVT_CALL(BringPartnerOut, 9)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
            EVT_IF_EQ(EVT_VAR(6), 4)
                EVT_CALL(NpcJump0, NPC_PARTNER, -81, 176, 171, 20)
            EVT_ELSE
                EVT_CALL(NpcJump0, NPC_PARTNER, -81, 186, 171, 20)
            EVT_END_IF
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(NpcJump0, NPC_SELF, -8, 186, 159, 60)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, -4, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x006E))
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, -1, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 5, MESSAGE_ID(0x0E, 0x006F))
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x0070))
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, -1, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 5, MESSAGE_ID(0x0E, 0x0071))
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x0072))
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(6))
    EVT_IF_NE(EVT_VAR(6), 9)
        EVT_CALL(PutPartnerAway)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_SELF, 30, 125, 30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_THREAD
    EVT_CALL(func_802CF56C, 2)
    EVT_WAIT_FRAMES(15)
    EVT_SET(EVT_SAVE_VAR(0), -34)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, 3)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802424E0) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), -34)
        EVT_CALL(SetNpcPos, NPC_SELF, 175, 240, 145)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242064)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241EB0)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_8024254C) = {
    EVT_IF_NE(EVT_MAP_VAR(0), 0)
        EVT_IF_GE(EVT_MAP_VAR(0), EVT_MAP_VAR(1))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0081))
            EVT_SET(EVT_VAR(0), 118)
            EVT_SET(EVT_VAR(1), 1)
            EVT_EXEC_WAIT(N(80241C6C))
            EVT_CALL(AddKeyItem, ITEM_KOOT_PACKAGE)
            EVT_SET(EVT_MAP_VAR(0), 0)
            EVT_SET(EVT_SAVE_FLAG(1015), 1)
            EVT_SET(EVT_SAVE_FLAG(1020), 0)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0080))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(3), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0079))
                EVT_SET(EVT_AREA_FLAG(3), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x007A))
                EVT_SET(EVT_AREA_FLAG(3), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x007B))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x007C))
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x007D))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x007E))
    EVT_END_SWITCH
    EVT_IF_EQ(EVT_SAVE_FLAG(1015), 0)
        EVT_IF_EQ(EVT_SAVE_VAR(348), 18)
            EVT_EXEC_WAIT(N(80241E68))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x007F))
            EVT_CALL(EndSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0)
            EVT_SET(EVT_MAP_VAR(0), 0)
            EVT_SET(EVT_MAP_VAR(1), 450)
            EVT_SET(EVT_SAVE_FLAG(1020), 1)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_ADD(EVT_MAP_VAR(0), 1)
                    EVT_WAIT_FRAMES(1)
                    EVT_IF_GE(EVT_MAP_VAR(0), EVT_MAP_VAR(1))
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802428A8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024254C)))
    EVT_RETURN
    EVT_END
};

EvtSource N(802428CC) = {
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_IF_GT(EVT_VAR(0), EVT_VAR(3))
        EVT_ADD(EVT_VAR(0), 60)
        EVT_CALL(SetNpcYaw, 4, 90)
    EVT_ELSE
        EVT_SUB(EVT_VAR(0), 60)
        EVT_CALL(SetNpcYaw, 4, 270)
    EVT_END_IF
    EVT_ADD(EVT_VAR(1), 20)
    EVT_CALL(SetNpcPos, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_802CFD30, 4, 7, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtSource N(802429D4) = {
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_IF_GT(EVT_VAR(0), EVT_VAR(3))
        EVT_ADD(EVT_VAR(0), 30)
    EVT_ELSE
        EVT_SUB(EVT_VAR(0), 30)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 40, 0)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, 4, 7, EVT_VAR(0), 0, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, 4, EVT_VAR(0), EVT_VAR(2), 40)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242B0C) = {
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_IF_GT(EVT_VAR(0), EVT_VAR(3))
        EVT_ADD(EVT_VAR(0), 60)
    EVT_ELSE
        EVT_SUB(EVT_VAR(0), 60)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 255, 0, 40, 0)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, 4, 7, EVT_VAR(0), 0, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, 4, EVT_VAR(0), EVT_VAR(2), 40)
    EVT_CALL(SetNpcPos, 4, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242C60) = {
    EVT_EXEC_WAIT(N(802429D4))
    EVT_SET(EVT_MAP_VAR(2), 0)
    EVT_SET(EVT_MAP_VAR(3), 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(25)
        EVT_CALL(SetPlayerAnimation, ANIM_80017)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_9)
        EVT_LOOP(0)
            EVT_IF_EQ(EVT_MAP_VAR(2), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_1)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_boo_Palette_01_Anim_8)
    EVT_CALL(EndSpeech, 4, NPC_ANIM_boo_Palette_01_Anim_8, NPC_ANIM_boo_Palette_01_Anim_8, 5)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_boo_Palette_01_Anim_1)
    EVT_WAIT_FRAMES(10)
    EVT_EXEC_WAIT(N(80242B0C))
    EVT_SET(EVT_MAP_VAR(2), 1)
    EVT_WAIT_FRAMES(15)
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80242DC4) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(4), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0082))
                EVT_SET(EVT_AREA_FLAG(4), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0083))
                EVT_SET(EVT_AREA_FLAG(4), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0084))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0085))
        EVT_CASE_LT(39)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_ADD(EVT_VAR(2), -20)
                EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FIXED(2.0))
                EVT_CALL(NpcMoveTo, NPC_PARTNER, EVT_VAR(0), EVT_VAR(2), 0)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0086))
            EVT_EXEC_WAIT(N(802428CC))
            EVT_CALL(PlayerFaceNpc, 4, 1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 4, 1)
            EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x0087))
            EVT_EXEC_WAIT(N(80242C60))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0088))
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
        EVT_CASE_GE(39)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_ADD(EVT_VAR(2), -20)
                EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FIXED(2.0))
                EVT_CALL(NpcMoveTo, NPC_PARTNER, EVT_VAR(0), EVT_VAR(2), 0)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0089))
            EVT_EXEC_WAIT(N(802428CC))
            EVT_CALL(PlayerFaceNpc, 4, 1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 4, 1)
            EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x008A))
            EVT_EXEC_WAIT(N(80242C60))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x008B))
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802431A4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80242DC4)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_802431C8) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(5), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x008C))
                EVT_SET(EVT_AREA_FLAG(5), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x008D))
                EVT_SET(EVT_AREA_FLAG(5), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x008E))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x008F))
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0090))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0091))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80243328) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802431C8)))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024334C) = {
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
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 2, 36, 10, 185, 56, 10, 185, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 479, 215, 198, 150 },
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
    .tattle = MESSAGE_ID(0x1A, 0x00AA),
};

StaticNpc N(npcGroup_80243568) = {
    .id = 1,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 209.0f, 185.0f, 217.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802428A8),
    .yaw = 90,
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
    .tattle = MESSAGE_ID(0x1A, 0x00AB),
};

StaticNpc N(npcGroup_80243758) = {
    .id = 2,
    .settings = &N(npcSettings_80241C10),
    .pos = { 379.0f, 186.0f, 186.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802431A4),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 2, 379, 10, 186, 399, 10, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 479, 215, 198, 150 },
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
    .tattle = MESSAGE_ID(0x1A, 0x00AC),
};

StaticNpc N(npcGroup_80243948) = {
    .id = 3,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 544.0f, 235.0f, 128.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80243328),
    .yaw = 90,
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
    .tattle = MESSAGE_ID(0x1A, 0x00AD),
};

StaticNpc N(npcGroup_80243B38) = {
    .id = 4,
    .settings = &N(npcSettings_80241C3C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_8024334C),
    .yaw = 90,
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
};

EvtSource N(idle_80243D28) = {
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_ADD(EVT_VAR(3), -60)
    EVT_SET(EVT_VAR(4), EVT_VAR(0))
    EVT_ADD(EVT_VAR(4), 60)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, EVT_VAR(5))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_MULF(EVT_VAR(6), EVT_FIXED(0.1))
        EVT_ADDF(EVT_VAR(6), EVT_FIXED(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_VAR(6))
        EVT_CALL(NpcMoveTo, NPC_SELF, EVT_VAR(3), EVT_VAR(2), 0)
        EVT_CALL(RandInt, 5, EVT_VAR(5))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_MULF(EVT_VAR(6), EVT_FIXED(0.1))
        EVT_ADDF(EVT_VAR(6), EVT_FIXED(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_VAR(6))
        EVT_CALL(NpcMoveTo, NPC_SELF, EVT_VAR(4), EVT_VAR(2), 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80243E90) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80243ECC) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80243F08) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243D28)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_HAS_SHADOW)), FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80243F44) = {
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
    },
    {
        .id = 6,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 180.0f, 285.0f, 182.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243ECC),
        .yaw = 90,
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
    },
    {
        .id = 7,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 349.0f, 286.0f, 152.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243F08),
        .yaw = 90,
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
    },
    {
        .id = 8,
        .settings = &N(npcSettings_80241C3C),
        .pos = { 490.0f, 324.0f, 128.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80243F44),
        .yaw = 90,
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
    },
};

NpcGroupList N(npcGroupList_80244740) = {
    NPC_GROUP(N(npcGroup_80243378), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243568), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243758), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243948), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243B38), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80244788) = {
    NPC_GROUP(N(npcGroup_80243378), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243568), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243758), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243948), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243B38), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243F80), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_47DC) = {
    0x00000000,
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EA564, 300, 237, 60, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1007))
    EVT_CALL(MakeEntity, EVT_PTR(D_802E9A18), 250, 237, 125, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_802415F4_BE0384)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &N(D_80241CCC_BE0A5C);
        *ptr = 0;
    }

    ptr = &N(D_80241CCC_BE0A5C);
    if (*ptr != NULL) {
        ptr = &N(D_80241CCC_BE0A5C);
        *ptr = 0;
        evt_set_variable(script, *args, N(D_80241CD0_BE0A60));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241648_BE03D8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241CD0_BE0A60) = evt_get_variable(script, *args);
    N(D_80241CCC_BE0A5C) = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241680_BE0410)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
