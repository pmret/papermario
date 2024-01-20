#include "pra_13.h"
#include "sprite.h"
#include "sprite/player.h"

#include "world/common/enemy/Bombette.h"
#include "world/common/enemy/Duplighost.h"

NpcSettings N(NpcSettings_Player) = {
    .height = 30,
    .radius = 45,
    .level = ACTOR_LEVEL_NONE,
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
    Call(MakeLerp, 0, 8 * 360, 40, EASING_QUADRATIC_OUT)
    Label(1)
        Call(UpdateLerp)
        Call(SetNpcRotation, LVar4, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_Scene_ImpostersCaught) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, pra_13_ENTRY_2)
        IfLt(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            Call(DisablePlayerInput, TRUE)
            Wait(10)
            Call(SetNpcYaw, NPC_FakeMario, 90)
            Thread
                Call(SetPlayerSpeed, Float(2.0))
                Call(PlayerMoveTo, 440, -70, 0)
            EndThread
            Wait(15)
            Call(GetNpcPos, NPC_FakeMario, LVar0, LVar1, LVar2)
            Call(SetCamProperties, CAM_DEFAULT, Float(5.0), LVar0, LVar1, LVar2, Float(350.0), Float(12.0), Float(-7.0))
            Call(SpeakToPlayer, NPC_FakeMario, ANIM_Mario1_Flail, ANIM_Mario1_Flail, 0, MSG_CH7_0139)
            Call(SpeakToPlayer, NPC_FakeBombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013A)
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
            Thread
                Call(GetNpcPos, NPC_FakeMario, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_FakeMario, NPC_DISPOSE_LOCATION)
                Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_Duplighost_01, LVar0, LVar1, LVar2)
                Call(PlaySoundAtNpc, NPC_Duplighost_01, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
                Call(SetNpcFlagBits, NPC_Duplighost_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Set(LVar4, 2)
                Call(SetNpcYaw, NPC_Duplighost_01, 90)
                ExecWait(N(EVS_ImposterSpin))
                Call(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim04)
                Call(SetNpcFlagBits, NPC_Duplighost_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(NpcMoveTo, NPC_Duplighost_01, 430, -70, 15)
            EndThread
            Thread
                Call(GetNpcPos, NPC_FakeBombette, LVar0, LVar1, LVar2)
                Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_FakeBombette, 389, 0, -61)
                Call(SetNpcPos, NPC_Duplighost_02, LVar0, LVar1, LVar2)
                Call(PlaySoundAtNpc, NPC_Duplighost_02, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
                Call(SetNpcFlagBits, NPC_FakeBombette, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_HAS_NO_SPRITE, TRUE)
                Call(SetNpcFlagBits, NPC_Duplighost_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Set(LVar4, 3)
                Call(SetNpcYaw, NPC_Duplighost_02, 90)
                ExecWait(N(EVS_ImposterSpin))
                Call(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim04)
                Call(SetNpcFlagBits, NPC_Duplighost_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(NpcMoveTo, NPC_Duplighost_02, 420, -70, 15)
            EndThread
            Wait(35)
            Call(StartBossBattle, SONG_SPECIAL_BATTLE)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_DefeatImposters) = {
    Call(SetNpcPos, NPC_Duplighost_01, 400, 0, -70)
    Call(SetNpcPos, NPC_Duplighost_02, 370, 0, -70)
    Call(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim02)
    Call(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim02)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(SetNpcPos, NPC_FakeBombette, NPC_DISPOSE_LOCATION)
    Wait(10)
    Call(SpeakToPlayer, NPC_Duplighost_01, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0, MSG_CH7_013B)
    Wait(10)
    Call(InterpNpcYaw, NPC_Duplighost_01, 270, 0)
    Call(InterpNpcYaw, NPC_Duplighost_02, 270, 0)
    Wait(15)
    Thread
        Call(PlaySoundAtNpc, NPC_Duplighost_01, SOUND_DUPLIGHOST_LEAP, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim04)
        Call(NpcMoveTo, NPC_Duplighost_01, 0, -70, 45)
        Call(SetNpcPos, NPC_Duplighost_01, NPC_DISPOSE_LOCATION)
    EndThread
    Call(PlaySoundAtNpc, NPC_Duplighost_02, SOUND_DUPLIGHOST_LEAP, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim04)
    Call(NpcMoveTo, NPC_Duplighost_02, -30, -70, 45)
    Call(SetNpcPos, NPC_Duplighost_02, -30, -1000, 0)
    Set(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    SetGroup(EVT_GROUP_0B)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeMario) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Mario1_Idle)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, pra_13_ENTRY_2)
        IfLt(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            Call(SetNpcPos, NPC_SELF, 375, 0, -59)
        EndIf
    Else
        IfEq(GF_PRA_BrokeIllusion, TRUE)
            IfLt(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
                Call(SetNpcPos, NPC_SELF, 465, 0, -59)
                Call(InterpNpcYaw, NPC_SELF, 270, 0)
            EndIf
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeBombette) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_ImpostersCaught)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_Scene_DefeatImposters)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, pra_13_ENTRY_2)
        IfLt(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            Call(SetNpcPos, NPC_SELF, 345, 0, -59)
            MallocArray(16, LVarA)
            Call(N(CreateFakePlayerRenderer))
        EndIf
    Else
        IfEq(GF_PRA_BrokeIllusion, TRUE)
            IfLt(GB_StoryProgress, STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
                Call(SetNpcPos, NPC_SELF, 435, 0, -59)
                MallocArray(16, LVarA)
                Call(N(CreateFakePlayerRenderer))
            EndIf
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_01) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_02) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    Return
    End
};

NpcData N(NpcData_FakeMario) = {
    .id = NPC_FakeMario,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_FakeMario),
    .settings = &N(NpcSettings_Player),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
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
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
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


