#include "obk_04.h"

#include "world/common/npc/Boo.inc.c"

API_CALLABLE(N(func_80240050_BC7EB0)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* blur = heap_malloc(sizeof(s32)); // todo what is this

    npc->blur.any = blur;
    *blur = NULL;
    npc->planarFlyDist = 125.0f;
    npc->yaw = 0.0f;
    npc->pos.x = 0.0f;
    npc->pos.y = -875.0f;
    npc->pos.z = 0.0f;
    npc->duration = 60;
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

void N(func_802400D0_BC7F30)(Npc* npc) {
    if (npc->yaw > 340.0f || npc->yaw < 20.0f) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        npc->unk_A2 = 0;
        func_8003D624(npc, 0, 0, 0, 0, 0, npc->unk_A2);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        func_8003D624(npc, 7, gPlayerStatusPtr->alpha1, 255, 0, 0, npc->unk_A2);
        npc->unk_9A = 255;
    }
}

void N(func_80240198_BC7FF8)(void) {
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_02));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_03));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_04));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_05));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_06));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_07));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_08));
    N(func_802400D0_BC7F30)(get_npc_unsafe(NPC_Boo_09));
}

void N(func_8024022C_BC808C)(void) {
    get_npc_unsafe(NPC_Boo_02)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_03)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_04)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_05)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_06)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_07)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_08)->unk_A2 = 0;
    get_npc_unsafe(NPC_Boo_09)->unk_A2 = 0;
}

s32 N(func_802402A0_BC8100)(s32 arg0) {
    s32 ret = 12;

    switch (arg0) {
        case 0:
            ret = 12;
            break;
        case 1:
            ret = 100;
            break;
        case 2:
            ret = 13;
            break;
        case 3:
            ret = 14;
            break;
    }
    return ret;
}

API_CALLABLE(N(func_802402F4_BC8154)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* temp_s3 = npc->blur.any;
    s32 temp_v0;

    switch (script->functionTemp[1]) {
        case 0:
            temp_v0 = evt_get_variable(script, MV_Unk_01);
            if (temp_v0 == 1) {
                *temp_s3 = temp_v0;
                script->functionTemp[1] = 10;
            }
            break;
        case 1:
            break;
        case 10:
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 11;
            }
            break;
        case 11:
            if (npc->pos.y <= -920.0f) {
                N(func_80240198_BC7FF8)();
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->pos.y -= 0.5f;
            if (npc->pos.y <= -988.0f) {
                evt_set_variable(script, MV_Unk_02, 1);
                N(func_8024022C_BC808C)();
                script->functionTemp[1] = 12;
            }
            break;
        case 12:
            script->functionTemp[1] = N(func_802402A0_BC8100)(evt_get_variable(script, MV_Unk_03));
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 13:
            script->functionTemp[1] = N(func_802402A0_BC8100)(evt_get_variable(script, MV_Unk_03));
            npc->yaw = clamp_angle(npc->yaw - 2.0f);
            break;
        case 14:
            evt_set_variable(script, MV_Unk_03, 0);
            npc->duration++;
            if (npc->duration == 50) {
                script->functionTemp[1] = 15;
            }
            npc->planarFlyDist -= 2.0f;
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 15:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 12;
            }
            npc->planarFlyDist += 2.0f;
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 100:
            script->functionTemp[1] = N(func_802402A0_BC8100)(evt_get_variable(script, MV_Unk_03));
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802405B4_BC8414)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->blur.any = get_npc_unsafe(0); // TODO what is this?
    script->functionTemp[2] = script->owner2.npcID * 45;
    npc->flags |= NPC_FLAG_40000;
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80240624_BC8484);

// float regalloc
#ifdef NON_MATCHING
API_CALLABLE(N(func_80240624_BC8484)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    Npc* npc2 = npc->blur.any;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f6;
    s32* temp_s2;
    f32 yaw;
    f32 new_var;
    f32 f1;


    temp_s2 = npc2->blur.any;
    switch (script->functionTemp[1]) {
        case 0:
            npc->yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            if (*temp_s2 == 1) {
                script->functionTemp[1] = 1;
                npc->duration = rand_int(20) + 10;
            }
            break;
        case 1:
            npc->yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            npc->duration--;
            if (npc->duration == 0) {
                sfx_play_sound_at_position(0xB000000F, 0, npc->pos.x, npc->pos.y, npc->pos.z);
                script->functionTemp[1] = 2;
                npc->duration = 0;
                npc->moveToPos.x = npc->pos.x;
                npc->moveToPos.y = npc->pos.y;
                npc->moveToPos.z = npc->pos.z;
            }
            break;
        case 2:
            npc->yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            new_var = npc->yaw;
            npc->pos.x = npc2->pos.x;
            npc->pos.z = npc2->pos.z;
            npc_move_heading(npc, npc2->planarFlyDist, new_var);
            temp_f4 = (40.0f - npc->duration) / 40.0f;
            temp_f12 = npc->pos.z;
            f1 = (npc->pos.x - npc->moveToPos.x) * (temp_f4 * temp_f4);
            temp_f6 = (npc->pos.z - npc->moveToPos.z) * (temp_f4 * temp_f4);
            temp_f2 = npc2->pos.y + 1000.0f;
            npc->pos.x -= f1;
            npc->pos.y = temp_f2;
            npc->pos.y -= (npc->pos.y - npc->moveToPos.y) * ((temp_f4 * temp_f4) * temp_f4);
            npc->pos.z = temp_f12 - temp_f6;
            npc->duration++;
            if (npc->duration == 40) {
                script->functionTemp[1] = 12;
            }
            break;
        case 12:
        case 13:
        case 14:
            yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            npc->yaw = yaw;
            script->functionTemp[1] = N(func_802402A0_BC8100)(evt_get_variable(script, MV_Unk_03));
            npc->pos.x = npc2->pos.x;
            npc->pos.z = npc2->pos.z;
            npc_move_heading(npc, npc2->planarFlyDist, yaw);
            npc->pos.y = npc2->pos.y + 1000.0f;
            break;
        case 100:
            script->functionTemp[1] = N(func_802402A0_BC8100)(evt_get_variable(script, MV_Unk_03));
            break;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240624_BC8484);
#endif

EvtScript N(EVS_NpcIdle_Boo_01) = {
    EVT_WAIT(4)
    EVT_CALL(N(func_80240050_BC7EB0))
    EVT_LABEL(10)
        EVT_CALL(N(func_802402F4_BC8154))
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Boo_02) = {
    EVT_WAIT(5)
    EVT_CALL(N(func_802405B4_BC8414))
    EVT_LABEL(10)
        EVT_CALL(func_80240624_BC8484)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024129C_BC90FC) = {
    EVT_IF_EQ(MV_Unk_05, LVar0)
        EVT_SET(MV_Unk_06, 1)
    EVT_ELSE
        EVT_SET(MV_Unk_06, 2)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Cower)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Idle)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 1)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 1)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_03) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 2)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 2)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_04) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 3)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 3)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_05) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 4)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 4)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_06) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 5)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 5)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_07) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 6)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 6)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_08) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 7)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 7)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Boo_09) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar0, 8)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar0, 8)
            EVT_EXEC_WAIT(N(D_8024129C_BC90FC))
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

EvtScript N(EVS_NpcInit_Boo_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_02)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_03)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_04)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_05)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_06)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_07) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_07)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_08) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_08)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_09) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Boo_09)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Boo_01) = {
    .id = NPC_Boo_01,
    .settings = &N(NpcSettings_Boo),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_02) = {
    .id = NPC_Boo_02,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_02),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_03) = {
    .id = NPC_Boo_03,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_03),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_04) = {
    .id = NPC_Boo_04,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_04),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_05) = {
    .id = NPC_Boo_05,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_05),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_06) = {
    .id = NPC_Boo_06,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_06),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_07) = {
    .id = NPC_Boo_07,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_07),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_08) = {
    .id = NPC_Boo_08,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_08),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
};

StaticNpc N(NpcData_Boo_09) = {
    .id = NPC_Boo_09,
    .settings = &N(NpcSettings_Boo),
    .pos = { 176.0f, 0.0f, -173.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_Boo_09),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
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

EvtScript N(EVS_NpcInteract_Boo_12) = {
    EVT_IF_EQ(GF_OBK04_HiddenPanel, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Boo_12, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003F)
    EVT_ELSE
        EVT_IF_EQ(GF_OBK04_HeardAboutHiddenPanels, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Boo_12, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0040)
            EVT_SET(GF_OBK04_HeardAboutHiddenPanels, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Boo_12, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0041)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_12) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_12)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_CALL(SetNpcPos, NPC_Boo_12, -160, 10, -175)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Boo_10)[] = {
    {
        .id = NPC_Boo_10,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_Boo_10),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Boo_Idle,
            .walk   = ANIM_Boo_Walk,
            .run    = ANIM_Boo_Run,
            .chase  = ANIM_Boo_Run,
            .anim_4 = ANIM_Boo_Idle,
            .anim_5 = ANIM_Boo_Idle,
            .death  = ANIM_Boo_Still,
            .hit    = ANIM_Boo_Still,
            .anim_8 = ANIM_Boo_Run,
            .anim_9 = ANIM_Boo_Run,
            .anim_A = ANIM_Boo_Run,
            .anim_B = ANIM_Boo_Run,
            .anim_C = ANIM_Boo_Run,
            .anim_D = ANIM_Boo_Run,
            .anim_E = ANIM_Boo_Run,
            .anim_F = ANIM_Boo_Run,
        },
    },
    {
        .id = NPC_Boo_11,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_4000,
        .init = &N(EVS_NpcInit_Boo_11),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Boo_Idle,
            .walk   = ANIM_Boo_Walk,
            .run    = ANIM_Boo_Run,
            .chase  = ANIM_Boo_Run,
            .anim_4 = ANIM_Boo_Idle,
            .anim_5 = ANIM_Boo_Idle,
            .death  = ANIM_Boo_Still,
            .hit    = ANIM_Boo_Still,
            .anim_8 = ANIM_Boo_Run,
            .anim_9 = ANIM_Boo_Run,
            .anim_A = ANIM_Boo_Run,
            .anim_B = ANIM_Boo_Run,
            .anim_C = ANIM_Boo_Run,
            .anim_D = ANIM_Boo_Run,
            .anim_E = ANIM_Boo_Run,
            .anim_F = ANIM_Boo_Run,
        },
    },
};

StaticNpc N(NpcData_Boo_12) = {
    .id = NPC_Boo_12,
    .settings = &N(NpcSettings_Boo),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Boo_12),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Boo_Idle,
        .walk   = ANIM_Boo_Walk,
        .run    = ANIM_Boo_Run,
        .chase  = ANIM_Boo_Run,
        .anim_4 = ANIM_Boo_Idle,
        .anim_5 = ANIM_Boo_Idle,
        .death  = ANIM_Boo_Still,
        .hit    = ANIM_Boo_Still,
        .anim_8 = ANIM_Boo_Run,
        .anim_9 = ANIM_Boo_Run,
        .anim_A = ANIM_Boo_Run,
        .anim_B = ANIM_Boo_Run,
        .anim_C = ANIM_Boo_Run,
        .anim_D = ANIM_Boo_Run,
        .anim_E = ANIM_Boo_Run,
        .anim_F = ANIM_Boo_Run,
    },
    .tattle = MSG_NpcTattle_OBK_BootsTutor,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    NPC_GROUP(N(NpcData_Boo_06)),
    NPC_GROUP(N(NpcData_Boo_07)),
    NPC_GROUP(N(NpcData_Boo_08)),
    NPC_GROUP(N(NpcData_Boo_09)),
    NPC_GROUP(N(NpcData_Boo_10)),
    NPC_GROUP(N(NpcData_Boo_12)),
    {}
};
