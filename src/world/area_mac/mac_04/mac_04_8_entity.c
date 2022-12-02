#include "mac_04.h"
#include "entity.h"
#include "sprite.h"

void N(func_80241D30_844900)(void);
void N(func_80241DAC_84497C)(void*);

MAP_RODATA_PAD(2,unk);

API_CALLABLE(N(func_80241C90_844860)) {
    gPlayerStatus.animFlags |= PA_FLAGS_IN_DISGUISE;
    evt_set_variable(script, MV_Unk_0B, create_worker_world(NULL, N(func_80241D30_844900)));

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241CEC_8448BC)) {
    s32 index = evt_get_variable(script, MapVar(11));
    gPlayerStatus.animFlags &= ~PA_FLAGS_IN_DISGUISE;
    free_worker(index);

    return ApiStatus_DONE2;
}

void N(func_80241D30_844900)(void) {
    RenderTask renderTask;
    s32 screenX, screenY, screenZ;

    get_screen_coords(gCurrentCamID, gPlayerStatus.position.x, gPlayerStatus.position.y, gPlayerStatus.position.z, &screenX, &screenY, &screenZ);

    renderTask.appendGfxArg = &gPlayerStatus;
    renderTask.appendGfx = N(func_80241DAC_84497C);
    renderTask.renderMode = gPlayerStatus.renderMode;
    renderTask.distance = screenZ;

    queue_render_task(&renderTask);
}

void N(func_80241DAC_84497C)(void* data) {
    PlayerStatus* playerStatus = data;
    f32 shrinkScale = evt_get_float_variable(NULL, MV_PlayerShrinkScale);
    Matrix4f transformMtx;
    Matrix4f tempMtx;

    guRotateF(transformMtx, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guScaleF(tempMtx, shrinkScale * SPRITE_WORLD_SCALE_D, shrinkScale * SPRITE_WORLD_SCALE_D, shrinkScale * SPRITE_WORLD_SCALE_D);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    guTranslateF(tempMtx, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    playerStatus->animNotifyValue = spr_update_player_sprite(0, playerStatus->trueAnimation, 1.0f);
    spr_draw_player_sprite(0, 0, 0, NULL, transformMtx);
}

EvtScript N(D_8024E840_851410) = {
    EVT_SETF(MV_PlayerShrinkScale, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_TIME_STOPPED, TRUE)
    EVT_CALL(N(func_80241C90_844860))
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(MakeLerp, 100, 20, 20, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(MV_PlayerShrinkScale, LVar0)
            EVT_DIVF(MV_PlayerShrinkScale, 100)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E924_8514F4) = {
    EVT_SETF(MV_PlayerShrinkScale, EVT_FLOAT(0.2))
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_TIME_STOPPED, TRUE)
    EVT_CALL(N(func_80241C90_844860))
    EVT_THREAD
        EVT_CALL(MakeLerp, 20, 100, 40, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(MV_PlayerShrinkScale, LVar0)
            EVT_DIVF(MV_PlayerShrinkScale, 100)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E9FC_8515CC) = {
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_TIME_STOPPED, FALSE)
    EVT_CALL(N(func_80241CEC_8448BC))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024EA2C_8515FC) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterToybox) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC_WAIT(N(D_8024E840_851410))
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(D_8024EA2C_8515FC), LVarA)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_1AA, 0)
        EVT_CALL(MakeLerp, 0, -90, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar2, 0)
            EVT_SUB(LVar2, LVar0)
            EVT_DIV(LVar2, 3)
            EVT_CALL(RotateGroup, MODEL_box_top, LVar0, 0, 0, 1)
            EVT_CALL(TranslateGroup, MODEL_box_top, 0, LVar2, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtPlayer, SOUND_D9, 0)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.35))
        EVT_CALL(PlayerJump, -450, 20, -160, 32)
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_IF_EQ(GF_StartedChapter4, FALSE)
        EVT_SET(GF_StartedChapter4, TRUE)
        EVT_CALL(FadeOutMusic, 0, 1500)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_4, TRANSITION_6)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_03"), omo_03_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024ECDC) = {
    EVT_SET(AF_MAC_02, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC_WAIT(N(D_8024E924_8514F4))
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(MakeLerp, -90, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar2, 0)
            EVT_SUB(LVar2, LVar0)
            EVT_DIV(LVar2, 3)
            EVT_CALL(RotateGroup, MODEL_box_top, LVar0, 0, 0, 1)
            EVT_CALL(TranslateGroup, MODEL_box_top, 0, LVar2, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_1AA, 0)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(D_8024EA2C_8515FC), LVarA)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DA, 0)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, -480, 45, -90, 25)
    EVT_EXEC_WAIT(N(D_8024E9FC_8515CC))
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024EED8_851AA8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(D_8024EA2C_8515FC), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, -430, 20, -45, 15)
    EVT_SET(AF_MAC_02, FALSE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring_Toybox) = {
    EVT_IF_EQ(AF_MAC_02, FALSE)
        EVT_EXEC(N(EVS_EnterToybox))
    EVT_ELSE
        EVT_EXEC(N(D_8024EED8_851AA8))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024EFF4_851BC4) = {
    EVT_EXEC_WAIT(N(D_80242E48_845A18))
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(D_8024F010_851BE0)[] = {
    ITEM_STOREROOM_KEY,
    ITEM_NONE
};

EvtScript N(D_8024F018_851BE8) = {
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_269, 0, 155, 48, -480)
    EVT_SET(LVar0, MV_Unk_00)
    EVT_CALL(N(RemovePadlock))
    EVT_WAIT(5)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0004)
    EVT_CALL(SetNpcFlagBits, NPC_HarryT, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Run)
    EVT_CALL(NpcMoveTo, NPC_HarryT, 295, -460, 0)
    EVT_CALL(NpcMoveTo, NPC_HarryT, 230, -480, 0)
    EVT_CALL(NpcJump0, NPC_HarryT, 200, 30, -524, 0)
    EVT_CALL(SetNpcPos, NPC_HarryT, 200, 30, -524)
    EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_HarryT, NPC_FLAG_100, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0005)
    EVT_SET(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024F24C) = {
    EVT_SET(LVar0, MV_Unk_00)
    EVT_CALL(N(RemovePadlock))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024F278_851E48) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0173, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 155, 48, -480, 90, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_8024EFF4_851BC4)))
        EVT_SET(MV_Unk_00, LVar0)
        EVT_CALL(SetEntityCullMode, 3)
        EVT_BIND_PADLOCK(EVT_PTR(N(D_8024F018_851BE8)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(D_8024F010_851BE0)), 0, 1)
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_VIS_GROUP(ITEM_TOY_TRAIN, VIS_GROUP_2), 50, 40, -430, ITEM_SPAWN_MODE_KEY, GF_MAC04_Item_ToyTrain)
    EVT_THREAD
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TOY_TRAIN)
            EVT_LOOP(0)
                EVT_IF_NE(GF_MAC04_Item_ToyTrain, FALSE)
                    EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TOY_TRAIN)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeItemEntity, ITEM_VIS_GROUP(ITEM_SNOWMAN_DOLL, VIS_GROUP_2), 50, 40, -310, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC04_Item_SnowmanDoll)
    EVT_CALL(MakeItemEntity, ITEM_VIS_GROUP(ITEM_VOLT_SHROOM, VIS_GROUP_2), 50, 40, -370, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC04_Item_VoltShroom)
    EVT_CALL(MakeItemEntity, ITEM_VIS_GROUP(ITEM_DIZZY_DIAL, VIS_GROUP_2), 50, 40, -490, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC04_Item_DizzyDial)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -480, 20, -90, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring_Toybox)))
    EVT_CALL(SetEntityCullMode, 2)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_8024F278_851E48)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    EVT_RETURN
    EVT_END
};
