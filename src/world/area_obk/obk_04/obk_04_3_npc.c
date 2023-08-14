#include "obk_04.h"

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

API_CALLABLE(N(InitHiddenBoo)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* isGameStarted = heap_malloc(sizeof(s32));

    npc->blur.keepAwayStarted = isGameStarted;
    *isGameStarted = FALSE;
    npc->planarFlyDist = 125.0f; // default ring radius
    npc->yaw = 0.0f;
    npc->pos.x = 0.0f;
    npc->pos.y = -875.0f;
    npc->pos.z = 0.0f;
    npc->duration = 60;
    script->functionTemp[1] = RING_STATE_0;
    return ApiStatus_DONE2;
}

void N(func_802400D0_BC7F30)(Npc* npc) {
    if (npc->yaw > 340.0f || npc->yaw < 20.0f) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        npc->imgfxFlags = 0;
        npc_set_imgfx_params(npc, IMGFX_CLEAR, 0, 0, 0, 0, npc->imgfxFlags);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        npc_set_imgfx_params(npc, IMGFX_SET_ALPHA, gPlayerStatusPtr->alpha1, 255, 0, 0, npc->imgfxFlags);
        npc->imgfxArg1 = 255;
    }
}

void N(func_80240198_BC7FF8)(void) {
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo1));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo2));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo3));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo4));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo5));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo6));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo7));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_KeepAwayBoo8));
}

void N(func_8024022C_BC808C)(void) {
    get_npc_unsafe(NPC_KeepAwayBoo1)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo2)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo3)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo4)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo5)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo6)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo7)->imgfxFlags = 0;
    get_npc_unsafe(NPC_KeepAwayBoo8)->imgfxFlags = 0;
}

s32 N(SetRingMovement)(s32 arg0) {
    s32 ret = RING_STATE_12;

    switch (arg0) {
        case KEEP_AWAY_CLOCKWISE:
            ret = RING_STATE_12;
            break;
        case KEEP_AWAY_STOP:
            ret = RING_STATE_100;
            break;
        case KEEP_AWAY_COUNTER_CLOCKWISE:
            ret = RING_STATE_13;
            break;
        case KEEP_AWAY_SPIRAL:
            ret = RING_STATE_14;
            break;
    }
    return ret;
}

API_CALLABLE(N(UpdateHiddenBoo)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* temp_s3 = npc->blur.any;
    s32 temp_v0;

    switch (script->functionTemp[1]) {
        case RING_STATE_0:
            temp_v0 = evt_get_variable(script, MV_KeepAwayStarted);
            if (temp_v0 == 1) {
                *temp_s3 = temp_v0;
                script->functionTemp[1] = RING_STATE_10;
            }
            break;
        case RING_STATE_1:
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
                N(func_80240198_BC7FF8)();
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->pos.y -= 0.5f;
            if (npc->pos.y <= -988.0f) {
                evt_set_variable(script, MV_Unk_02, 1);
                N(func_8024022C_BC808C)();
                script->functionTemp[1] = RING_STATE_12;
            }
            break;
        case RING_STATE_12:
            script->functionTemp[1] = N(SetRingMovement)(evt_get_variable(script, MV_KeepAwayMovement));
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case RING_STATE_13:
            script->functionTemp[1] = N(SetRingMovement)(evt_get_variable(script, MV_KeepAwayMovement));
            npc->yaw = clamp_angle(npc->yaw - 2.0f);
            break;
        case RING_STATE_14:
            evt_set_variable(script, MV_KeepAwayMovement, KEEP_AWAY_CLOCKWISE);
            npc->duration++;
            if (npc->duration == 50) {
                script->functionTemp[1] = RING_STATE_15;
            }
            npc->planarFlyDist -= 2.0f;
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case RING_STATE_15:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = RING_STATE_12;
            }
            npc->planarFlyDist += 2.0f;
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case RING_STATE_100:
            script->functionTemp[1] = N(SetRingMovement)(evt_get_variable(script, MV_KeepAwayMovement));
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitKeepAwayBoo)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->blur.keepAwayNpc = get_npc_unsafe(NPC_Boo_01);
    script->functionTemp[2] = script->owner2.npcID * 45; // starting yaw
    npc->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
    script->functionTemp[1] = RING_STATE_0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateKeepAwayBoo)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    Npc* hiddenBoo = npc->blur.keepAwayNpc;
    f32 posX, posY, posZ;
    f32 interpAlpha, alphaSquared, alphaCubed;
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
            alphaCubed = interpAlpha * interpAlpha * interpAlpha;

            posX = npc->pos.x;
            posZ = npc->pos.z;
            deltaX = (npc->pos.x - npc->moveToPos.x) * alphaSquared;
            deltaZ = (npc->pos.z - npc->moveToPos.z) * alphaSquared;

            posY = hiddenBoo->pos.y + 1000.0f;
            npc->pos.y = posY;

            npc->pos.x = posX - deltaX;
            npc->pos.y -= (npc->pos.y - npc->moveToPos.y) * alphaCubed;
            npc->pos.z = posZ - deltaZ;
            npc->duration++;
            if (npc->duration == 40) {
                script->functionTemp[1] = RING_STATE_12;
            }
            break;
        // at this stage, the movement of the ring is controlled by MV_KeepAwayMovement
        case RING_STATE_12:
        case RING_STATE_13:
        case RING_STATE_14:
            yaw = clamp_angle(script->functionTemp[2] + hiddenBoo->yaw);
            npc->yaw = yaw;
            script->functionTemp[1] = N(SetRingMovement)(evt_get_variable(script, MV_KeepAwayMovement));
            npc->pos.x = hiddenBoo->pos.x;
            npc->pos.z = hiddenBoo->pos.z;
            npc_move_heading(npc, hiddenBoo->planarFlyDist, yaw);
            npc->pos.y = hiddenBoo->pos.y + 1000.0f;
            break;
        case RING_STATE_100:
            script->functionTemp[1] = N(SetRingMovement)(evt_get_variable(script, MV_KeepAwayMovement));
            break;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Boo_01) = {
    EVT_WAIT(4)
    EVT_CALL(N(InitHiddenBoo))
    EVT_LABEL(10)
        EVT_CALL(N(UpdateHiddenBoo))
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KeepAwayBoo) = {
    EVT_WAIT(5)
    EVT_CALL(N(InitKeepAwayBoo))
    EVT_LABEL(10)
        EVT_CALL(N(UpdateKeepAwayBoo))
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
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo1)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo2)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo3) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo3)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo4) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo4)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo5) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo5)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo6) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo6)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo7) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo7)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KeepAwayBoo8) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KeepAwayBoo)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_KeepAwayBoo8)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
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
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo1),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo2) = {
    .id = NPC_KeepAwayBoo2,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo2),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo3) = {
    .id = NPC_KeepAwayBoo3,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo3),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo4) = {
    .id = NPC_KeepAwayBoo4,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo4),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo5) = {
    .id = NPC_KeepAwayBoo5,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo5),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo6) = {
    .id = NPC_KeepAwayBoo6,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo6),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo7) = {
    .id = NPC_KeepAwayBoo7,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo7),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_KeepAwayBoo8) = {
    .id = NPC_KeepAwayBoo8,
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KeepAwayBoo8),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

EvtScript N(EVS_NpcInit_Boo_10) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_11) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TutorialBoo) = {
    EVT_IF_EQ(GF_OBK04_HiddenPanel, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_TutorialBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003F)
    EVT_ELSE
        EVT_IF_EQ(GF_OBK04_HeardAboutHiddenPanels, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_TutorialBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0040)
            EVT_SET(GF_OBK04_HeardAboutHiddenPanels, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TutorialBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0041)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TutorialBoo) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TutorialBoo)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(SetNpcPos, NPC_TutorialBoo, -160, 10, -175)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KeepAwayExtras)[] = {
    {
        .id = NPC_LeaderBoo,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo_10),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
    {
        .id = NPC_DummyBoo,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Boo_11),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
};

NpcData N(NpcData_TutorialBoo) = {
    .id = NPC_TutorialBoo,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_TutorialBoo),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
    .tattle = MSG_NpcTattle_OBK_BootsTutor,
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
    NPC_GROUP(N(NpcData_KeepAwayExtras)),
    NPC_GROUP(N(NpcData_TutorialBoo)),
    {}
};
