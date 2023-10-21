#include "obk_08.h"

enum {
    RING_STATE_0        = 0,
    RING_STATE_1        = 1,
    RING_STATE_2        = 2,
    RING_STATE_10       = 10,
    RING_STATE_11       = 11,
    RING_STATE_12       = 12,
    RING_STATE_13       = 13,
    RING_STATE_14       = 14,
    RING_STATE_15       = 15,
    RING_STATE_100      = 100,
};

#include "world/common/npc/Boo.inc.c"

API_CALLABLE(N(func_802408A0_BD4110)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* isGameStarted = heap_malloc(sizeof(s32)); // todo what is this

    npc->blur.keepAwayStarted = isGameStarted;
    *isGameStarted = NULL;
    npc->planarFlyDist = 125.0f;
    npc->yaw = 0.0f;
    npc->pos.x = 0.0f;
    npc->pos.y = -875.0f;
    npc->pos.z = 0.0f;
    npc->duration = 60;
    script->functionTemp[1] = RING_STATE_0;
    return ApiStatus_DONE2;
}

void N(func_80240920_BD4190)(Npc* npc) {
    if (npc->yaw > 340.0f || npc->yaw < 20.0f) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        npc->imgfxFlags = 0;
        npc_set_imgfx_params(npc, IMGFX_CLEAR, 0, 0, 0, 0, npc->imgfxFlags);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        npc_set_imgfx_params(npc, IMGFX_SET_ALPHA, gPlayerStatusPtr->curAlpha, 0, 0, 0, npc->imgfxFlags);
        npc->imgfxArg1 = 255;
    }
}

void func_802409E8_BD4258(void) {
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo1));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo2));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo3));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo4));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo5));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo6));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo7));
    N(func_80240920_BD4190)(get_npc_unsafe(NPC_KeepAwayBoo8));
}

void func_80240A7C_BD42EC(void) {
    get_npc_unsafe(NPC_KeepAwayBoo1)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo2)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo3)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo4)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo5)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo6)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo7)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo8)->imgfxFlags = 0;
}

API_CALLABLE(N(func_80240AF0_BD4360)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* isGameStarted = npc->blur.keepAwayStarted;
    s32 temp_v0;

    switch (script->functionTemp[1]) {
        case RING_STATE_0:
            temp_v0 = evt_get_variable(script, AF_OBK08_KeepAwayStarted);
            if (temp_v0 == TRUE) {
                *isGameStarted = temp_v0;
                script->functionTemp[1] = RING_STATE_10;
            }
            break;
        case RING_STATE_10:
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = RING_STATE_11;
            }
            break;
        case RING_STATE_11:
            if (npc->pos.y <= -920.0f) {
                func_802409E8_BD4258();
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->pos.y -= 0.5f;
            if (npc->pos.y <= -988.0f) {
                evt_set_variable(script, MV_Unk_01, 1);
                func_80240A7C_BD42EC();
                script->functionTemp[1] = RING_STATE_12;
            }
            break;
        case RING_STATE_12:
            if (evt_get_variable(script, MV_Unk_02) == 1) {
                script->functionTemp[1] = RING_STATE_13;
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case RING_STATE_13:
            if (evt_get_variable(script, MV_Unk_02) == 0) {
                script->functionTemp[1] = RING_STATE_12;
            }
            break;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240CA0_BD4510)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->blur.keepAwayNpc = get_npc_unsafe(NPC_Boo_01);
    script->functionTemp[2] = script->owner2.npcID * 45;
    npc->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
    script->functionTemp[1] = RING_STATE_0;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80240D10_BD4580) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    Npc* hiddenBoo = npc->blur.keepAwayNpc;
    f32 posX, posY, posZ;
    f32 interpAlpha, alphaSquared;
    f32 deltaX, deltaZ;
    s32* isGameStarted;
    f32 yaw;

    isGameStarted = hiddenBoo->blur.keepAwayStarted;
    switch (script->functionTemp[1]) {
        case RING_STATE_0:
            npc->yaw = clamp_angle(script->functionTemp[2] + hiddenBoo->yaw);
            if (*isGameStarted == TRUE) {
                script->functionTemp[1] = RING_STATE_1;
                npc->duration = rand_int(20) + 10;
            }
            break;
        case RING_STATE_1:
            yaw = clamp_angle(script->functionTemp[2] + hiddenBoo->yaw);
            npc->yaw = yaw;
            npc->duration--;
            if (npc->duration == 0) {
                sfx_play_sound_at_position(SOUND_SEQ_BOO_VANISH, SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z);
                script->functionTemp[1] = RING_STATE_2;
                npc->duration = 0;
                npc->moveToPos.x = npc->pos.x;
                npc->moveToPos.y = npc->pos.y;
                npc->moveToPos.z = npc->pos.z;
            }
            break;
        case RING_STATE_2:
            // here `moveToPos` is original position
            yaw = clamp_angle(script->functionTemp[2] + hiddenBoo->yaw);
            npc->yaw = yaw;
            npc->pos.x = hiddenBoo->pos.x;
            npc->pos.z = hiddenBoo->pos.z;
            npc_move_heading(npc, hiddenBoo->planarFlyDist, yaw);

            interpAlpha = (40.0f - npc->duration) / 40.0f;
            alphaSquared = interpAlpha * interpAlpha;

            posX = npc->pos.x;
            posY = hiddenBoo->pos.y + 1000.0f;
            posZ = npc->pos.z;

            deltaX = (npc->pos.x - npc->moveToPos.x) * alphaSquared;
            deltaZ = (npc->pos.z - npc->moveToPos.z) * alphaSquared;
            npc->pos.y = posY;

            npc->pos.x = posX - deltaX;
            npc->pos.y = (npc->pos.y - npc->moveToPos.y) * npc->duration / 40.0f + npc->moveToPos.y;
            npc->pos.z = posZ - deltaZ;
            npc->duration++;
            if (npc->duration == 40) {
                script->functionTemp[1] = RING_STATE_10;
            }
            break;
        case RING_STATE_10:
            yaw = clamp_angle(script->functionTemp[2] + hiddenBoo->yaw);
            npc->yaw = yaw;
            if (evt_get_variable(script, MV_Unk_02) == 1) {
                script->functionTemp[1] = RING_STATE_13;
            }
            npc->pos.x = hiddenBoo->pos.x;
            npc->pos.z = hiddenBoo->pos.z;
            npc_move_heading(npc, hiddenBoo->planarFlyDist, yaw);
            npc->pos.y = hiddenBoo->pos.y + 1000.0f;
            break;
        case RING_STATE_13:
            if (evt_get_variable(script, MV_Unk_02) == 0) {
                script->functionTemp[1] = RING_STATE_10;
            }
            break;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Boo_01) = {
    EVT_WAIT(4)
    EVT_CALL(N(func_802408A0_BD4110))
    EVT_LABEL(10)
        EVT_CALL(N(func_80240AF0_BD4360))
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KeepAwayBoo) = {
    EVT_WAIT(5)
    EVT_CALL(N(func_80240CA0_BD4510))
    EVT_LABEL(10)
        EVT_CALL(func_80240D10_BD4580)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnHit_KeepAwayBoo) = {
    EVT_IF_EQ(MV_ThrowTargetNpc, LVar0)
        EVT_SET(MV_KeepAwayResult, KEEP_AWAY_RIGHT)
    EVT_ELSE
        EVT_SET(MV_KeepAwayResult, KEEP_AWAY_WRONG)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Cower)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Idle)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo1) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo1)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo1)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo2) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo2)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo2)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo3) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo3)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo3)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo4) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo4)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo4)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo5) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo5)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo5)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo6) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo6)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo6)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo7) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo7)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo7)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KeepAwayBoo8) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, NPC_KeepAwayBoo8)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, NPC_KeepAwayBoo8)
            EVT_EXEC_WAIT(N(EVS_OnHit_KeepAwayBoo))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_01)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo1)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo2)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo3) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo3)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo4) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo4)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo5) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo5)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo6) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo6)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo7) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo7)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo8) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo8)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Boo_01) = {
    .id = NPC_Boo_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Boo_01),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo1) = {
    .id = NPC_KeepAwayBoo1,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo1),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo2) = {
    .id = NPC_KeepAwayBoo2,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo2),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo3) = {
    .id = NPC_KeepAwayBoo3,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo3),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo4) = {
    .id = NPC_KeepAwayBoo4,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo4),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo5) = {
    .id = NPC_KeepAwayBoo5,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo5),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo6) = {
    .id = NPC_KeepAwayBoo6,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo6),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo7) = {
    .id = NPC_KeepAwayBoo7,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo7),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo8) = {
    .id = NPC_KeepAwayBoo8,
    .pos = { -268.0f, 52.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KeepAwayBoo8),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

#define TRAFFIC_BOO_START_Y 40.0f
#define TRAFFIC_BOO_START_Z -430.0f
#include "../common/TrafficBoos.inc.c"

EvtScript N(EVS_NpcInit_TrafficBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrafficBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TrafficBoos)[] = {
    {
        .id = NPC_TrafficBoo1,
        .pos = { 523.0f, -139.0f, 193.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_TrafficBoo1),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
    {
        .id = NPC_TrafficBoo2,
        .pos = { 473.0f, -122.0f, 247.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_TrafficBoo2),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
};

EvtScript N(EVS_NpcInit_Boo_12) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_13) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KeepAwayExtras)[] = {
    {
        .id = NPC_LeaderBoo,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Boo_12),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
    {
        .id = NPC_DummyBoo,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Boo_13),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_KeepAwayBoo1)),
    NPC_GROUP(N(NpcData_KeepAwayBoo2)),
    NPC_GROUP(N(NpcData_KeepAwayBoo3)),
    NPC_GROUP(N(NpcData_KeepAwayBoo4)),
    NPC_GROUP(N(NpcData_KeepAwayBoo5)),
    NPC_GROUP(N(NpcData_KeepAwayBoo6)),
    NPC_GROUP(N(NpcData_KeepAwayBoo7)),
    NPC_GROUP(N(NpcData_KeepAwayBoo8)),
    NPC_GROUP(N(NpcData_TrafficBoos)),
    NPC_GROUP(N(NpcData_KeepAwayExtras)),
    {}
};
