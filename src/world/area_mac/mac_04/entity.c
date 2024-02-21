#include "mac_04.h"
#include "entity.h"
#include "sprite.h"

void N(render_shrunk_player)(void);
void N(appendGfx_shrunk_player)(void*);

MAP_RODATA_PAD(2,unk);

API_CALLABLE(N(CreateShrinkingWorker)) {
    gPlayerStatus.animFlags |= PA_FLAG_INVISIBLE;
    evt_set_variable(script, MV_DrawShinkingPlayerWorker, create_worker_world(NULL, N(render_shrunk_player)));

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyShrinkingWorker)) {
    s32 index = evt_get_variable(script, MV_DrawShinkingPlayerWorker);
    gPlayerStatus.animFlags &= ~PA_FLAG_INVISIBLE;
    free_worker(index);

    return ApiStatus_DONE2;
}

void N(render_shrunk_player)(void) {
    RenderTask renderTask;
    s32 screenX, screenY, screenZ;

    get_screen_coords(gCurrentCamID,
        gPlayerStatus.pos.x, gPlayerStatus.pos.y, gPlayerStatus.pos.z,
        &screenX, &screenY, &screenZ);

    renderTask.appendGfxArg = &gPlayerStatus;
    renderTask.appendGfx = N(appendGfx_shrunk_player);
    renderTask.renderMode = gPlayerStatus.renderMode;
    renderTask.dist = screenZ;

    queue_render_task(&renderTask);
}

void N(appendGfx_shrunk_player)(void* data) {
    PlayerStatus* playerStatus = data;
    f32 shrinkScale = evt_get_float_variable(NULL, MV_PlayerShrinkScale);
    Matrix4f transformMtx;
    Matrix4f tempMtx;

    guRotateF(transformMtx, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guScaleF(tempMtx, shrinkScale * SPRITE_WORLD_SCALE_D, shrinkScale * SPRITE_WORLD_SCALE_D, shrinkScale * SPRITE_WORLD_SCALE_D);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    guTranslateF(tempMtx, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    playerStatus->animNotifyValue = spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerStatus->trueAnimation, 1.0f);
    spr_draw_player_sprite(PLAYER_SPRITE_MAIN, 0, 0, NULL, transformMtx);
}

EvtScript N(EVS_ShrinkPlayer) = {
    SetF(MV_PlayerShrinkScale, Float(1.0))
    Call(SetPlayerFlagBits, PS_FLAG_TIME_STOPPED, TRUE)
    Call(N(CreateShrinkingWorker))
    Thread
        Wait(8)
        Call(MakeLerp, 100, 20, 20, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            SetF(MV_PlayerShrinkScale, LVar0)
            DivF(MV_PlayerShrinkScale, 100)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_UnshrinkPlayer) = {
    SetF(MV_PlayerShrinkScale, Float(0.2))
    Call(SetPlayerFlagBits, PS_FLAG_TIME_STOPPED, TRUE)
    Call(N(CreateShrinkingWorker))
    Thread
        Call(MakeLerp, 20, 100, 40, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(MV_PlayerShrinkScale, LVar0)
            DivF(MV_PlayerShrinkScale, 100)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_FinishUnshrinking) = {
    Call(SetPlayerFlagBits, PS_FLAG_TIME_STOPPED, FALSE)
    Call(N(DestroyShrinkingWorker))
    Return
    End
};

EvtScript N(EVS_FocusCameraOnPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_EnterToybox) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    ExecWait(N(EVS_ShrinkPlayer))
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    ExecGetTID(N(EVS_FocusCameraOnPlayer), LVarA)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_OMO_TOYBOX_LID, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, -90, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(LVar2, 0)
            Sub(LVar2, LVar0)
            Div(LVar2, 3)
            Call(RotateGroup, MODEL_box_top, LVar0, 0, 0, 1)
            Call(TranslateGroup, MODEL_box_top, 0, LVar2, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(PlaySoundAtPlayer, SOUND_TRANSPORTER_IN, SOUND_SPACE_DEFAULT)
        Call(SetPlayerJumpscale, Float(0.35))
        Call(PlayerJump, -450, 20, -160, 32)
    EndThread
    Wait(25)
    IfEq(GF_StartedChapter4, FALSE)
        Set(GF_StartedChapter4, TRUE)
        Call(FadeOutMusic, 0, 1500)
        Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_4, TRANSITION_BEGIN_OR_END_CHAPTER)
        Wait(100)
        Return
    EndIf
    Call(GotoMap, Ref("omo_03"), omo_03_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitToybox) = {
    Set(AF_ExitingToybox, TRUE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    ExecWait(N(EVS_UnshrinkPlayer))
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    Thread
        Call(MakeLerp, -90, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(LVar2, 0)
            Sub(LVar2, LVar0)
            Div(LVar2, 3)
            Call(RotateGroup, MODEL_box_top, LVar0, 0, 0, 1)
            Call(TranslateGroup, MODEL_box_top, 0, LVar2, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_OMO_TOYBOX_LID, SOUND_SPACE_DEFAULT)
    EndThread
    ExecGetTID(N(EVS_FocusCameraOnPlayer), LVarA)
    Call(PlaySoundAtPlayer, SOUND_TRANSPORTER_OUT, SOUND_SPACE_DEFAULT)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, -480, 45, -90, 25)
    ExecWait(N(EVS_FinishUnshrinking))
    KillThread(LVarA)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_BounceOffSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    ExecGetTID(N(EVS_FocusCameraOnPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, -430, 20, -45, 15)
    Set(AF_ExitingToybox, FALSE)
    KillThread(LVarA)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_UseSpring_Toybox) = {
    IfEq(AF_ExitingToybox, FALSE)
        Exec(N(EVS_EnterToybox))
    Else
        Exec(N(EVS_BounceOffSpring))
    EndIf
    Return
    End
};

EvtScript N(EVS_UnlockStoreroom) = {
    ExecWait(N(EVS_MakeStoreroom))
    Return
    End
};

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(StoreroomKeyList)[] = {
    ITEM_STOREROOM_KEY,
    ITEM_NONE
};

EvtScript N(EVS_ItemPrompt_StoreroomKey) = {
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        Return
    EndIf
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 155, 48, -480)
    Set(LVar0, MV_StoreroomLockEntityID)
    Call(N(RemovePadlock))
    Wait(5)
    Call(RemoveKeyItemAt, LVar1)
    Call(CloseChoicePopup)
    Unbind
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0004)
    Call(SetNpcFlagBits, NPC_HarryT, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Run)
    Call(NpcMoveTo, NPC_HarryT, 295, -460, 0)
    Call(NpcMoveTo, NPC_HarryT, 230, -480, 0)
    Call(NpcJump0, NPC_HarryT, 200, 30, -524, 0)
    Call(SetNpcPos, NPC_HarryT, 200, 30, -524)
    Call(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
    Call(SetNpcFlagBits, NPC_HarryT, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0005)
    Set(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ForceStoreroomUnlock) = {
    Set(LVar0, MV_StoreroomLockEntityID)
    Call(N(RemovePadlock))
    Return
    End
};

EvtScript N(EVS_OnInspect_StreetSign) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_0173, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfLt(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
        Call(MakeEntity, Ref(Entity_Padlock), 155, 48, -480, 90, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UnlockStoreroom)))
        Set(MV_StoreroomLockEntityID, LVar0)
        Call(SetEntityCullMode, 3)
        BindPadlock(Ref(N(EVS_ItemPrompt_StoreroomKey)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(StoreroomKeyList)), 0, 1)
    EndIf
    Call(MakeItemEntity, ITEM_VIS_GROUP(ITEM_TOY_TRAIN, VIS_GROUP_2), 50, 40, -430, ITEM_SPAWN_MODE_KEY, GF_MAC04_Item_ToyTrain)
    Thread
        IfLt(GB_StoryProgress, STORY_CH4_GOT_TOY_TRAIN)
            Loop(0)
                IfNe(GF_MAC04_Item_ToyTrain, FALSE)
                    Set(GB_StoryProgress, STORY_CH4_GOT_TOY_TRAIN)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndIf
    EndThread
    Call(MakeItemEntity, ITEM_VIS_GROUP(ITEM_SNOWMAN_DOLL, VIS_GROUP_2), 50, 40, -310, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC04_Item_SnowmanDoll)
    Call(MakeItemEntity, ITEM_VIS_GROUP(ITEM_VOLT_SHROOM, VIS_GROUP_2), 50, 40, -370, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC04_Item_VoltShroom)
    Call(MakeItemEntity, ITEM_VIS_GROUP(ITEM_DIZZY_DIAL, VIS_GROUP_2), 50, 40, -490, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC04_Item_DizzyDial)
    Call(MakeEntity, Ref(Entity_ScriptSpring), -480, 20, -90, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring_Toybox)))
    Call(SetEntityCullMode, 2)
    BindTrigger(Ref(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    Return
    End
};
