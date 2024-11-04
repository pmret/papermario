#include "mac_06.h"
#include "model.h"
#include "effects.h"

#define CLONED_MODEL_GULL   CLONED_MODEL(1000)
#define CLONED_MODEL_UNUSED CLONED_MODEL(0)

NpcSettings N(NpcSettings_Whale) = {
    .height = 24,
    .radius = 48,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Kolorado) = {
    .height = 40,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_JrTroopa) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

f32 D_80243434_867F74 = 0.0f;
f32 D_80243438_867F78 = 0.0f;
s32 D_8024343C_867F7C = 0;
s32 D_80243440_867F80 = 0;

API_CALLABLE(N(func_80240E80_8659C0)) {
    Bytecode* args = script->ptrReadPos;
    Npc* whale = get_npc_safe(NPC_Whale);
    Npc* kolorado;
    Npc* partner;
    f32 forward, radius;
    f32 x, y, z;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        switch (script->functionTemp[0]) {
            case 0:
                script->functionTemp[1] = 70;
                break;
            case 1:
                script->functionTemp[1] = 100;
                break;
            default:
                script->functionTemp[1] = 40;
               break;
        }
    }

    radius = script->functionTemp[1];
    forward = -whale->yaw;
    x = whale->pos.x + 30.0f + sin_deg(forward) * radius;
    z = whale->pos.z + cos_deg(forward) * radius;
    y = whale->pos.y + 50.0f;

    switch (script->functionTemp[0]) {
        case 0:
            gPlayerStatus.pos.x = x;
            gPlayerStatus.pos.y = y + D_80243434_867F74;
            gPlayerStatus.pos.z = z;
            whale->colliderPos.x = whale->pos.x;
            whale->colliderPos.y = whale->pos.y;
            whale->colliderPos.z = whale->pos.z;
            whale->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
        case 1:
            partner = get_npc_safe(NPC_PARTNER);
            if (partner == NULL) {
                return ApiStatus_DONE2;
            }
            partner->pos.x = x;
            partner->pos.y = y;
            partner->pos.z = z;
            partner->colliderPos.x = partner->pos.x;
            partner->colliderPos.y = partner->pos.y;
            partner->colliderPos.z = partner->pos.z;
            partner->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
        case 2:
            kolorado = get_npc_safe(NPC_Kolorado);
            kolorado->pos.x = x;
            kolorado->pos.y = y;
            kolorado->pos.z = z;
            kolorado->colliderPos.x = kolorado->pos.x;
            kolorado->colliderPos.y = kolorado->pos.y;
            kolorado->colliderPos.z = kolorado->pos.z;
            kolorado->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80241098_865BD8)) {
    u32 buttons = gGameStatusPtr->pressedButtons[0];
    Npc* npc = get_npc_safe(NPC_Whale);

    switch (D_8024343C_867F7C) {
        case 0:
            if (buttons & BUTTON_A) {
                D_8024343C_867F7C = 10;
                break;
            }
            if (D_80243440_867F80 >= 150) {
                return ApiStatus_DONE2;
            }
            D_80243440_867F80++;
            break;

        case 10:
            npc->curAnim = ANIM_Kolorado_Shout;
            D_80243434_867F74 = 0.0f;
            D_80243438_867F78 = 5.0f;
            D_8024343C_867F7C = 11;
            break;

        case 11:
            D_80243434_867F74 += D_80243438_867F78;
            if (D_80243434_867F74 < 70.0f) {
                if (D_80243438_867F78 < 4.0f) {
                    D_80243438_867F78 = 4.0f;
                }
                D_80243438_867F78 += 1.0f;
            } else {
                D_80243438_867F78 -= 2.0f;
            }
            if (npc->curAnim == ANIM_Kolorado_Idle) {
                D_80243438_867F78 = 4.0f;
                D_8024343C_867F7C++;
            }
            break;

        case 12:
            D_80243434_867F74 -= D_80243438_867F78;
            if (D_80243434_867F74 < 0.0f) {
                D_80243434_867F74 = 0.0f;
                return ApiStatus_DONE2;
            }
            D_80243438_867F78 += 1.0f;
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80241290_865DD0)) {
    if(gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_802412AC_865DEC)) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    s32 outVarX = *args++;
    s32 outVarY = *args++;
    s32 outVarZ = *args++;
    s32 modelIndex = get_model_list_index_from_tree_index(modelID);
    Model* model = get_model_from_list_index(modelIndex);
    f32 x, y, z;

    if (model->flags & MODEL_FLAG_HAS_TRANSFORM) {
        // get model translation from transform matrix
        x = model->userTransformMtx[3][0];
        y = model->userTransformMtx[3][1];
        z = model->userTransformMtx[3][2];
    } else {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }

    evt_set_float_variable(script, outVarX, x);
    evt_set_float_variable(script, outVarY, y);
    evt_set_float_variable(script, outVarZ, z);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Whale) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_06_ENTRY_0)
        Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
        Call(NpcFlyTo, NPC_Whale, 50, LVar1, 500, 120, 0, EASING_SIN_OUT)
        Thread
            Call(N(func_80241098_865BD8))
        EndThread
        Wait(150)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Idle)
        Call(NpcFlyTo, NPC_Whale, 500, LVar1, 500, 120, 0, EASING_COS_IN)
        IfEq(GF_StartedChapter5, FALSE)
            Set(GF_StartedChapter5, TRUE)
            Call(FadeOutMusic, 0, 1500)
            Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_5, TRANSITION_BEGIN_OR_END_CHAPTER)
        Else
            Call(GotoMap, Ref("jan_00"), jan_00_ENTRY_0)
        EndIf
    Else
        Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
        IfGe(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
            IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
                Call(NpcFlyTo, NPC_Whale, -550, LVar1, 500, 240, 0, EASING_LINEAR)
                Call(SetNpcVar, NPC_JrTroopa, 0, 1)
                Return
            EndIf
        EndIf
        Call(NpcFlyTo, NPC_Whale, -70, LVar1, 500, 120, 0, EASING_SIN_OUT)
        Thread
            Call(N(func_80241098_865BD8))
        EndThread
        Wait(150)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Idle)
        Call(NpcFlyTo, NPC_Whale, -500, LVar1, 500, 120, 0, EASING_COS_IN)
        Call(GotoMap, Ref("mac_05"), mac_05_ENTRY_1)
    EndIf
    Return
    End
};

API_CALLABLE(N(SeagullYawInterp)) {
    f32 x1 = evt_get_float_variable(script, LVar1);
    f32 y1 = evt_get_float_variable(script, LVar3);
    f32 x2 = evt_get_float_variable(script, LVar4);
    f32 y2 = evt_get_float_variable(script, LVar5);
    f32 lastYaw = evt_get_float_variable(script, LVar7);
    f32 newYaw, deltaYaw;

    if (evt_get_variable(script, LFlag0)) {
        evt_set_float_variable(script, LVar6, 0.0f);
        evt_set_float_variable(script, LVar7, 0.0f);
        evt_set_variable(script, LFlag0, FALSE);
        evt_set_variable(script, LFlag1, TRUE);
        return ApiStatus_DONE2;
    }

    if (x1 == x2 && y1 == y2) {
        return ApiStatus_DONE2;
    }

    if (evt_get_variable(script, LFlag1)) {
        newYaw = atan2(-x1, y1, -x2, y2);
        evt_set_float_variable(script, LVar6, newYaw);
        evt_set_float_variable(script, LVar7, newYaw);
        evt_set_variable(script, LFlag1, FALSE);
        return ApiStatus_DONE2;
    }

    newYaw = atan2(-x1, y1, -x2, y2);
    newYaw = clamp_angle(newYaw);
    evt_set_float_variable(script, LVar6, newYaw);

    deltaYaw = lastYaw - newYaw;
    if (deltaYaw >= 180.0f) {
        lastYaw -= 360.0f;
    } else if (deltaYaw <= -180.0f) {
        lastYaw += 360.0f;
    }

    evt_set_float_variable(script, LVar7, lastYaw + (f32)((newYaw - lastYaw) * 0.1));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MakeJrTroopaBubbles)) {
    Npc* jrTroopa = get_npc_safe(NPC_JrTroopa);
    f32 x = jrTroopa->pos.x + 10.0f;
    f32 y = jrTroopa->pos.y;
    f32 z = jrTroopa->pos.z;

    if (y < 0.0f) {
        fx_rising_bubble(0, x, y, z, 0.0f);
        sfx_adjust_env_sound_pos(SOUND_LRAW_JR_TROOPA_SWIM, SOUND_SPACE_DEFAULT, x, y, z);
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInit_Whale) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_NO_SPRITE, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_06_ENTRY_0)
        Call(InterpPlayerYaw, 90, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
        Call(InterpNpcYaw, NPC_Kolorado, 90, 0)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
        Call(SetNpcPos, NPC_SELF, -300, 0, 500)
    Else
        Call(InterpPlayerYaw, 270, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Call(InterpNpcYaw, NPC_Kolorado, 270, 0)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Call(SetNpcPos, NPC_SELF, 300, 0, 500)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Whale)))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Thread
        Call(N(func_80240E80_8659C0), 0)
    EndThread
    Thread
        Call(N(func_80240E80_8659C0), 1)
    EndThread
    Thread
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
                Call(N(func_80240E80_8659C0), 2)
            CaseEq(STORY_CH5_TRADED_VASE_FOR_SEED)
                Call(N(func_80240E80_8659C0), 2)
        EndSwitch
    EndThread
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
            Return
        EndIf
    EndIf
    Thread
        Call(N(func_80241290_865DD0))
        Call(GetEntryID, LVar0)
        IfEq(LVar0, mac_06_ENTRY_0)
            Call(GotoMap, Ref("jan_00"), jan_00_ENTRY_0)
        Else
            Call(GotoMap, Ref("mac_05"), mac_05_ENTRY_1)
        EndIf
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Return
    End
};

Vec3f N(FlightPath)[] = {
    { -332.0,    50.0,  120.0 },
    { -160.0,    70.0,  300.0 },
    {  -71.0,    80.0,  130.0 },
    {  105.0,    90.0,  262.0 },
    {  221.0,   100.0,  120.0 },
    {  404.0,    85.0,  150.0 },
    {  238.0,    70.0,  -57.0 },
    {   63.0,    70.0,  -42.0 },
    { -131.0,    60.0,  144.0 },
    {  -75.0,   100.0,  -60.0 },
    {  200.0,    60.0, -300.0 },
    {   20.0,    60.0, -280.0 },
    {   70.0,    60.0,   80.0 },
    { -332.0,    50.0,  120.0 },
};

EvtScript N(EVS_FlyingGull) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(CloneModel, MODEL_hontai, CLONED_MODEL_GULL)
    Set(LFlag0, TRUE)
    Set(LFlag1, FALSE)
    SetF(LVar7, 0)
    Label(10)
        Call(LoadPath, 500, Ref(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
        Label(0)
            Call(GetNextPathPos)
            Call(TranslateModel, MODEL_hontai, LVar1, LVar2, LVar3)
            SetF(LVar8, LVar2)
            MulF(LVar8, -1)
            Call(TranslateModel, CLONED_MODEL_GULL, LVar1, LVar8, LVar3)
            Call(N(SeagullYawInterp))
            Call(RotateModel, MODEL_hontai, LVar7, 0, 1, 0)
            Call(RotateModel, CLONED_MODEL_GULL, LVar7, 0, 1, 0)
            Call(RotateModel, CLONED_MODEL_GULL, 180, 0, 0, 1)
            Set(LVar4, LVar1)
            Set(LVar5, LVar3)
            Wait(1)
            IfEq(LVar0, 1)
                Goto(0)
            EndIf
        Goto(10)
    Return
    End
};

EvtScript N(EVS_UnusedGull) = {
    Call(CloneModel, MODEL_hontai, LVar0)
    Set(LVarF, LVar0)
    Set(LFlag0, TRUE)
    Set(LFlag1, FALSE)
    SetF(LVar7, 0)
    Set(LVar8, 0)
    Set(LVar9, 0)
    Set(LVarA, 0)
    Call(RandInt, 200, LVar1)
    Add(LVar0, -100)
    Call(RandInt, 50, LVar2)
    Add(LVar0, 50)
    Call(RandInt, 200, LVar3)
    Add(LVar0, -100)
    Label(10)
    Label(0)
    Set(LVarE, LVarF)
    IfEq(LVarE, CLONED_MODEL_UNUSED)
        Set(LVarE, 22)
    Else
        Add(LVarE, -1)
    EndIf
    Call(N(func_802412AC_865DEC), LVarE, MV_Unk_00, MV_Unk_01, MV_Unk_02)
    SetF(LVar0, MV_Unk_00)
    SubF(LVar0, LVar1)
    IfLt(LVar0, 0)
        AddF(LVar8, -1)
    Else
        AddF(LVar8, 1)
    EndIf
    IfLe(LVar8, -10)
        SetF(LVar8, -10)
    EndIf
    IfGe(LVar8, 10)
        SetF(LVar8, 10)
    EndIf
    AddF(LVar1, LVar8)
    SetF(LVar0, MV_Unk_01)
    SubF(LVar0, LVar2)
    IfLt(LVar0, 0)
        AddF(LVar9, -1)
    Else
        AddF(LVar9, 1)
    EndIf
    IfLe(LVar9, -10)
        SetF(LVar9, -10)
    EndIf
    IfGe(LVar9, 10)
        SetF(LVar9, 10)
    EndIf
    AddF(LVar2, LVar9)
    SetF(LVar0, MV_Unk_02)
    SubF(LVar0, LVar3)
    IfLt(LVar0, 0)
        AddF(LVarA, -1)
    Else
        AddF(LVarA, 1)
    EndIf
    IfLe(LVarA, -10)
        SetF(LVarA, -10)
    EndIf
    IfGe(LVarA, 10)
        SetF(LVarA, 10)
    EndIf
    AddF(LVar3, LVarA)
    Call(TranslateModel, LVarF, LVar1, LVar2, LVar3)
    Call(N(SeagullYawInterp))
    Call(RotateModel, LVarF, LVar7, 0, 1, 0)
    Set(LVar4, LVar1)
    Set(LVar5, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Goto(10)
    Return
    End
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    Call(SetSelfVar, 0, 0)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(60)
    Call(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    Call(PlaySound, SOUND_LOOP_JR_TROOPA_SWIM)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    Call(SetNpcPos, NPC_SELF, 250, -30, 500)
    Wait(5)
    ChildThread
        Loop(0)
            Call(N(MakeJrTroopaBubbles))
            Wait(5)
        EndLoop
    EndChildThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Call(NpcMoveTo, NPC_SELF, -300, 500, 0)
    Call(GotoMap, Ref("mac_05"), mac_05_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    IfGe(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa)))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

NpcData N(NpcData_Whale) = {
    .id = NPC_Whale,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Whale),
    .settings = &N(NpcSettings_Whale),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Kolorado_Idle,
        .walk   = ANIM_Kolorado_Walk,
        .run    = ANIM_Kolorado_Run,
        .chase  = ANIM_Kolorado_Run,
        .anim_4 = ANIM_Kolorado_Idle,
        .anim_5 = ANIM_Kolorado_Idle,
        .death  = ANIM_Kolorado_Idle,
        .hit    = ANIM_Kolorado_Idle,
        .anim_8 = ANIM_Kolorado_Idle,
        .anim_9 = ANIM_Kolorado_Idle,
        .anim_A = ANIM_Kolorado_Idle,
        .anim_B = ANIM_Kolorado_Idle,
        .anim_C = ANIM_Kolorado_Idle,
        .anim_D = ANIM_Kolorado_Idle,
        .anim_E = ANIM_Kolorado_Idle,
        .anim_F = ANIM_Kolorado_Idle,
    },
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = COMMON_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Kolorado_Idle,
        .walk   = ANIM_Kolorado_Walk,
        .run    = ANIM_Kolorado_Run,
        .chase  = ANIM_Kolorado_Run,
        .anim_4 = ANIM_Kolorado_Idle,
        .anim_5 = ANIM_Kolorado_Idle,
        .death  = ANIM_Kolorado_Idle,
        .hit    = ANIM_Kolorado_Idle,
        .anim_8 = ANIM_Kolorado_Idle,
        .anim_9 = ANIM_Kolorado_Idle,
        .anim_A = ANIM_Kolorado_Idle,
        .anim_B = ANIM_Kolorado_Idle,
        .anim_C = ANIM_Kolorado_Idle,
        .anim_D = ANIM_Kolorado_Idle,
        .anim_E = ANIM_Kolorado_Idle,
        .anim_F = ANIM_Kolorado_Idle,
    },
};

AnimID N(ExtraAnims_JrTroopa)[] = {
    ANIM_JrTroopa_Still,
    ANIM_JrTroopa_Idle,
    ANIM_JrTroopa_ChargeTripped,
    ANIM_LIST_END
};

NpcData N(NpcData_JrTroopa) = {
    .id = NPC_JrTroopa,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_JrTroopa),
    .settings = &N(NpcSettings_JrTroopa),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_JrTroopa_Idle,
        .walk   = ANIM_JrTroopa_Walk,
        .run    = ANIM_JrTroopa_Walk,
        .chase  = ANIM_JrTroopa_Walk,
        .anim_4 = ANIM_JrTroopa_Idle,
        .anim_5 = ANIM_JrTroopa_Idle,
        .death  = ANIM_JrTroopa_Idle,
        .hit    = ANIM_JrTroopa_Idle,
        .anim_8 = ANIM_JrTroopa_Idle,
        .anim_9 = ANIM_JrTroopa_Idle,
        .anim_A = ANIM_JrTroopa_Idle,
        .anim_B = ANIM_JrTroopa_Idle,
        .anim_C = ANIM_JrTroopa_Idle,
        .anim_D = ANIM_JrTroopa_Idle,
        .anim_E = ANIM_JrTroopa_Idle,
        .anim_F = ANIM_JrTroopa_Idle,
    },
    .extraAnimations = N(ExtraAnims_JrTroopa),
    .tattle = MSG_NpcTattle_JrTroopa,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa)),
    NPC_GROUP(N(NpcData_Whale)),
    NPC_GROUP(N(NpcData_Kolorado)),
    {}
};
