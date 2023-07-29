#include "pra_13.h"
#include "sprite.h"
#include "sprite/player.h"

#include "world/common/enemy/Bombette.h"
#include "world/common/enemy/Duplighost.h"

NpcSettings N(NpcSettings_Player) = {
    .height = 30,
    .radius = 45,
    .level = 99,
};

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/todo/PlayBigSmokePuff.inc.c"

API_CALLABLE(N(DoNothingWithNpcID)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);

    get_npc_safe(npcID);
    return ApiStatus_DONE2;
}

void N(appendGfx_fake_player)(void* data);
void N(worker_draw_fake_player)(void);

API_CALLABLE(N(CreateFakePlayerRenderer)) {
    script->array[0] = create_worker_world(NULL, N(worker_draw_fake_player));
    return ApiStatus_DONE2;
}

void N(worker_draw_fake_player)(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    Npc* npc = get_npc_safe(NPC_FakeMario);

    if (gPlayerStatusPtr->flags & PS_FLAG_HAS_REFLECTION) {
        s32 x, y, z;

        get_screen_coords(gCurrentCamID, npc->pos.x, npc->pos.y, -npc->pos.z, &x, &y, &z);
        rtPtr->renderMode = npc->renderMode;
        rtPtr->dist = -z;
        rtPtr->appendGfxArg = npc;
        rtPtr->appendGfx = N(appendGfx_fake_player);
        queue_render_task(rtPtr);
    }
}

void N(appendGfx_fake_player)(void* data) {
    Npc* npc = data;
    Matrix4f mtxTransform, mtxTranslate, sp98, mtxScale;

    npc_get_render_yaw(npc);
    guRotateF(mtxTransform, npc->renderYaw + gCameras[gCurrentCamID].curYaw, 0.0f, 1.0f, 0.0f);
    guScaleF(mtxScale, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(mtxTransform, mtxScale, mtxTransform);
    guTranslateF(mtxTranslate, npc->pos.x, npc->pos.y, npc->pos.z);
    guMtxCatF(mtxTransform, mtxTranslate, mtxTransform);
    spr_update_player_sprite(PLAYER_SPRITE_AUX2, npc->curAnim, 1.0f);
    spr_draw_player_sprite(PLAYER_SPRITE_AUX2, 0, 0, 0, mtxTransform);
}

EvtScript N(EVS_ImposterSpin) = {
    EVT_CALL(MakeLerp, 0, 8 * 360, 40, EASING_QUADRATIC_OUT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, LVar4, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_ImpostersCaught) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, pra_13_ENTRY_2)
        EVT_IF_LT(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_WAIT(10)
            EVT_CALL(SetNpcYaw, NPC_FakeMario, 90)
            EVT_THREAD
                EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
                EVT_CALL(PlayerMoveTo, 440, -70, 0)
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_CALL(GetNpcPos, NPC_FakeMario, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(5.0), LVar0, LVar1, LVar2, EVT_FLOAT(350.0), EVT_FLOAT(12.0), EVT_FLOAT(-7.0))
            EVT_CALL(SpeakToPlayer, NPC_FakeMario, ANIM_Mario1_Flail, ANIM_Mario1_Flail, 0, MSG_CH7_0139)
            EVT_CALL(SpeakToPlayer, NPC_FakeBombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013A)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_THREAD
                EVT_CALL(GetNpcPos, NPC_FakeMario, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_FakeMario, NPC_DISPOSE_LOCATION)
                EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Duplighost_01, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_01, SOUND_SMOKE_BURST, 0)
                EVT_CALL(SetNpcFlagBits, NPC_Duplighost_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_SET(LVar4, 2)
                EVT_CALL(SetNpcYaw, NPC_Duplighost_01, 90)
                EVT_EXEC_WAIT(N(EVS_ImposterSpin))
                EVT_CALL(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim04)
                EVT_CALL(SetNpcFlagBits, NPC_Duplighost_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(NpcMoveTo, NPC_Duplighost_01, 430, -70, 15)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetNpcPos, NPC_FakeBombette, LVar0, LVar1, LVar2)
                EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_FakeBombette, 389, 0, -61)
                EVT_CALL(SetNpcPos, NPC_Duplighost_02, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_02, SOUND_SMOKE_BURST, 0)
                EVT_CALL(SetNpcFlagBits, NPC_FakeBombette, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_HAS_NO_SPRITE, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_Duplighost_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_SET(LVar4, 3)
                EVT_CALL(SetNpcYaw, NPC_Duplighost_02, 90)
                EVT_EXEC_WAIT(N(EVS_ImposterSpin))
                EVT_CALL(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim04)
                EVT_CALL(SetNpcFlagBits, NPC_Duplighost_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(NpcMoveTo, NPC_Duplighost_02, 420, -70, 15)
            EVT_END_THREAD
            EVT_WAIT(35)
            EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_DefeatImposters) = {
    EVT_CALL(SetNpcPos, NPC_Duplighost_01, 400, 0, -70)
    EVT_CALL(SetNpcPos, NPC_Duplighost_02, 370, 0, -70)
    EVT_CALL(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim02)
    EVT_CALL(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim02)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(SetNpcPos, NPC_FakeBombette, NPC_DISPOSE_LOCATION)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Duplighost_01, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0, MSG_CH7_013B)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Duplighost_01, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_Duplighost_02, 270, 0)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_01, SOUND_2CB, 0)
        EVT_CALL(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim04)
        EVT_CALL(NpcMoveTo, NPC_Duplighost_01, 0, -70, 45)
        EVT_CALL(SetNpcPos, NPC_Duplighost_01, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_02, SOUND_2CB, 0)
    EVT_CALL(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim04)
    EVT_CALL(NpcMoveTo, NPC_Duplighost_02, -30, -70, 45)
    EVT_CALL(SetNpcPos, NPC_Duplighost_02, -30, -1000, 0)
    EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeMario) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mario1_Idle)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, pra_13_ENTRY_2)
        EVT_IF_LT(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            EVT_CALL(SetNpcPos, NPC_SELF, 375, 0, -59)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(GF_PRA_BrokeIllusion, TRUE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
                EVT_CALL(SetNpcPos, NPC_SELF, 465, 0, -59)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeBombette) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_ImpostersCaught)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_Scene_DefeatImposters)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, pra_13_ENTRY_2)
        EVT_IF_LT(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            EVT_CALL(SetNpcPos, NPC_SELF, 345, 0, -59)
            EVT_MALLOC_ARRAY(16, LVarA)
            EVT_CALL(N(CreateFakePlayerRenderer))
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(GF_PRA_BrokeIllusion, TRUE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
                EVT_CALL(SetNpcPos, NPC_SELF, 435, 0, -59)
                EVT_MALLOC_ARRAY(16, LVarA)
                EVT_CALL(N(CreateFakePlayerRenderer))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_01) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_FakeMario) = {
    .id = NPC_FakeMario,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_FakeMario),
    .settings = &N(NpcSettings_Player),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = BOMBETTE_ANIMS,
};

NpcData N(NpcData_Imposters)[] = {
    {
        .id = NPC_FakeBombette,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FakeBombette),
        .settings = &N(NpcSettings_Player),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Duplighost_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Duplighost_01),
        .settings = &N(NpcSettings_Player),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Duplighost_02),
        .settings = &N(NpcSettings_Player),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FakeMario), BTL_PRA3_FORMATION_02, BTL_PRA3_STAGE_00),
    NPC_GROUP(N(NpcData_Imposters), BTL_PRA3_FORMATION_02, BTL_PRA3_STAGE_00),
    {}
};


