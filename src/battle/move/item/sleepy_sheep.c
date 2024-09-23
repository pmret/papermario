#include "common.h"
#include "script_api/battle.h"
#include "entity.h"
#include "ld_addrs.h"
#include "effects.h"
#include "sprite/player.h"
#include "include_asset.h"

#define NAMESPACE battle_item_sleepy_sheep

#include "battle/common/move/ItemRefund.inc.c"

s32 virtual_entity_create(EntityModelScript*);
void virtual_entity_set_pos(s32, s32, s32, s32);
void virtual_entity_set_scale(s32, f32, f32, f32);
void virtual_entity_delete_by_index(s32);

extern s32 D_802A3E88_7214D8[];
extern EntityModelScript* D_802A3F28_721578[10];
extern f32 D_802A3F00_721550[];

BSS s32 D_802A3F54; // unused?
BSS s32 D_802A3F58[10];
BSS s32 D_802A3F80[2]; // unused?
BSS Vec3f D_802A3F88;

API_CALLABLE(N(func_802A123C_71E88C)) {
    Vec3f* posPtr = &D_802A3F88;
    s32 entityID;
    f32 x, y, z;
    s32 cond;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            posPtr->x = -200.0f;
            posPtr->z = 10.0f;
            for (i = 0; i < ARRAY_COUNT(D_802A3F58); i++) {
                entityID = D_802A3F58[i] = virtual_entity_create(D_802A3F28_721578[i]);
                x = D_802A3E88_7214D8[i * 3] + posPtr->x;
                y = D_802A3E88_7214D8[i * 3 + 1];
                z = D_802A3E88_7214D8[i * 3 + 2] + posPtr->z;
                virtual_entity_set_pos(entityID, x, y, z);
                virtual_entity_set_scale(entityID, D_802A3F00_721550[i], D_802A3F00_721550[i], 1.0f);
            }
            script->functionTemp[1] = (gGameStatusPtr->frameCounter % 10) & 0xFFFF;
            script->functionTemp[0] = 1;
            break;
        case 1:
            posPtr->x += 6.0f;
            cond = FALSE;
            if (!((gGameStatusPtr->frameCounter % 3) & 0xFFFF)) {
                script->functionTemp[1] = (script->functionTemp[1] + 1) % 10;
            }

            for (i = 0; i < ARRAY_COUNT(D_802A3F58); i++) {
                entityID = D_802A3F58[i];
                x = D_802A3E88_7214D8[i * 3] + posPtr->x;
                y = D_802A3E88_7214D8[i * 3 + 1];
                z = D_802A3E88_7214D8[i * 3 + 2] + posPtr->z;
                virtual_entity_set_pos(entityID, x, y, z);
                if (!cond && script->functionTemp[1] == i && !((gGameStatusPtr->frameCounter % 5) & 0xFFFF)) {
                    if (x > 0.0f) {
                        y = x;
                        if (x > 100.0f) {
                            y = x - 50.0f;
                        }
                        y = rand_int(y);
                    }

                    if (x > 40.0f) {
                        x = -(x - 40.0f);
                    }
                    fx_landing_dust(3, x, y, z, 0.0f);
                    cond = TRUE;
                }
            }
            if (gGameStatusPtr->frameCounter & 1) {
                s32 randIdx = rand_int(9);

                x = D_802A3E88_7214D8[randIdx * 3] + posPtr->x;
                y = D_802A3E88_7214D8[randIdx * 3 + 1];
                z = D_802A3E88_7214D8[randIdx * 3 + 2] + posPtr->z;

                fx_landing_dust(2, x, y, z, 0.0f);
            }
            if (posPtr->x >= 320.0f) {
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            for (i = 0; i < ARRAY_COUNT(D_802A3F58); i++) {
                virtual_entity_delete_by_index(D_802A3F58[i]);
            }
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802A1740_71ED90)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 90;
    }

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);
        ActorPart* targetPart = get_actor_part(targetActor, target->partID);

        if (targetActor->transparentStatus == 0 && !(targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
            targetActor->yaw += 33.0f;
            targetActor->yaw = clamp_angle(targetActor->yaw);
        }
    }

    if (script->functionTemp[1] != 0) {
        script->functionTemp[1]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A1848_71EE98)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;
    s32 cond;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    cond = FALSE;

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);

        if (targetActor != NULL) {
            ActorPart* targetPart = get_actor_part(targetActor, target->partID);
            if ((targetActor->transparentStatus == 0) && !(targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
                if (targetActor->yaw < 360.0f) {
                    targetActor->yaw += 33.0f;
                    if (targetActor->yaw >= 360.0f) {
                        targetActor->yaw = 360.0f;
                    }
                    cond = TRUE;
                }
            }
        }
    }

    if (!cond) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#include "battle/common/move/UseItem.inc.c"

static s32 _pad = 0;

#include "battle/move/item/sleepy_sheep1.png.h"
INCLUDE_IMG("battle/move/item/sleepy_sheep1.png", battle_item_sleepy_sheep1_png);
INCLUDE_PAL("battle/move/item/sleepy_sheep1.pal", battle_item_sleepy_sheep1_pal);

#include "battle/move/item/sleepy_sheep2.png.h"
INCLUDE_IMG("battle/move/item/sleepy_sheep2.png", battle_item_sleepy_sheep2_png);
INCLUDE_PAL("battle/move/item/sleepy_sheep2.pal", battle_item_sleepy_sheep2_pal);

#include "battle/move/item/sleepy_sheep3.png.h"
INCLUDE_IMG("battle/move/item/sleepy_sheep3.png", battle_item_sleepy_sheep3_png);
INCLUDE_PAL("battle/move/item/sleepy_sheep3.pal", battle_item_sleepy_sheep3_pal);

Vtx N(model)[] = {
    { .v = {{ -28,  0,  0 }, FALSE, { 0,    1536 }, { 0, 0, 0, 255 }}},
    { .v = {{  27,  0,  0 }, FALSE, { 1792, 1536 }, { 0, 0, 0, 255 }}},
    { .v = {{  27, 47,  0 }, FALSE, { 1792,    0 }, { 0, 0, 0, 255 }}},
    { .v = {{ -28, 47,  0 }, FALSE, { 0,       0 }, { 0, 0, 0, 255 }}},
};

Gfx N(frame1_displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep1_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep1_png, G_IM_FMT_CI, battle_item_sleepy_sheep1_png_width, battle_item_sleepy_sheep1_png_height, 0, 0, battle_item_sleepy_sheep1_png_width - 1, battle_item_sleepy_sheep1_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame2_displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep2_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep2_png, G_IM_FMT_CI, battle_item_sleepy_sheep2_png_width, battle_item_sleepy_sheep2_png_height, 0, 0, battle_item_sleepy_sheep2_png_width - 1, battle_item_sleepy_sheep2_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame3_displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep3_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep3_png, G_IM_FMT_CI, battle_item_sleepy_sheep3_png_width, battle_item_sleepy_sheep3_png_height, 0, 0, battle_item_sleepy_sheep3_png_width - 1, battle_item_sleepy_sheep3_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript N(modelCommandList) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(frame1_displayList), 2)
    ems_Draw(N(frame2_displayList), 3)
    ems_Draw(N(frame1_displayList), 2)
    ems_Draw(N(frame3_displayList), 2)
    ems_Restart
    ems_End
};

EntityModelScript N(modelCommandList2) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(frame2_displayList),3)
    ems_Draw(N(frame1_displayList),2)
    ems_Draw(N(frame3_displayList),2)
    ems_Draw(N(frame1_displayList),2)
    ems_Restart
    ems_End
};

EntityModelScript N(modelCommandList3) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(frame1_displayList), 2)
    ems_Draw(N(frame3_displayList), 2)
    ems_Draw(N(frame1_displayList), 2)
    ems_Draw(N(frame2_displayList), 3)
    ems_Restart
    ems_End
};

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_SLEEPY_SHEEP)
    ExecWait(N(UseItemWithEffect))
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -67, -15, -5)
    Call(SetBattleCamOffsetY, 45)
    Call(SetBattleCamDist, 169)
    Call(MoveBattleCamOver, 50)
    Thread
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SHEEP_STAMPEDE)
        Loop(7)
            Call(StartRumble, BTL_RUMBLE_HIT_MIN)
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.25))
            Wait(2)
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
        EndLoop
    EndThread
    Wait(20)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 32)
    Call(ShowEmote, 0, EMOTE_QUESTION, -45, 20, EMOTER_POS, LVar0, LVar1, LVar2, 10)
    Wait(30)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Thread
        Call(N(func_802A123C_71E88C))
    EndThread
    Call(InitTargetIterator)
    Thread
        Wait(40)
        Call(N(func_802A1740_71ED90))
        Call(N(func_802A1848_71EE98))
    EndThread
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(8)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Flail, ANIM_Mario1_Flail, ANIM_Mario1_Fall)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerHopToGoal, 15, 0, 0)
    Thread
        Wait(5)
        Call(SetActorYaw, ACTOR_PLAYER, 150)
        Wait(1)
        Call(SetActorYaw, ACTOR_PLAYER, 120)
        Wait(1)
        Call(SetActorYaw, ACTOR_PLAYER, 90)
        Wait(1)
        Call(SetActorYaw, ACTOR_PLAYER, 60)
        Wait(1)
        Call(SetActorYaw, ACTOR_PLAYER, 30)
        Wait(1)
        Call(SetActorYaw, ACTOR_PLAYER, 0)
    EndThread
    Wait(40)
    Call(CreateVirtualEntity, LVarA, Ref(N(modelCommandList)))
    Set(LVar7, -200)
    Set(LVar8, 0)
    Set(LVar9, 0)
    Call(SetVirtualEntityPosition, LVarA, LVar7, LVar8, LVar9)
    Call(SetVirtualEntityScale, LVarA, Float(0.711), Float(0.711), Float(0.711))
    Call(SetVirtualEntityMoveSpeed, LVarA, Float(7.0))
    Call(SetVirtualEntityJumpGravity, LVarA, Float(1.4))
    Call(SetOwnerTarget, ACTOR_PLAYER, 0)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Call(VirtualEntityMoveTo, LVarA, LVar0, LVar1, LVar2, 0)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
    Thread
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_VacantStare)
        Call(SetActorScale, ACTOR_PLAYER, Float(1.2), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PLAYER, Float(1.3), Float(0.8), Float(1.0))
        Wait(3)
        Call(SetActorScale, ACTOR_PLAYER, Float(1.2), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PLAYER, Float(1.0), Float(1.0), Float(1.0))
    EndThread
    PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0)
    Wait(2)
    Call(SetVirtualEntityJumpGravity, LVarA, Float(1.4))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    PlayEffect(EFFECT_LANDING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Add(LVar0, 20)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    PlayEffect(EFFECT_LANDING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
    Add(LVar0, 10)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    PlayEffect(EFFECT_LANDING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
    Wait(5)
    Thread
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 270)
        Call(VirtualEntityMoveTo, LVarA, LVar0, LVar1, LVar2, 0)
        Call(DeleteVirtualEntity, LVarA)
    EndThread
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 20)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetItemPower, ITEM_SLEEPY_SHEEP, LVar0, LVar1)
        Call(MakeStatusField, LVar0, STATUS_FLAG_SLEEP, 100, LVar0)
        Call(ItemAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, LVar0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Wait(5)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(30)
    ExecWait(N(PlayerGoHome))
    Return
    End
};

s32 D_802A3E88_7214D8[] = {
    0, 0, 0,
    -30, 0, -50,
    -27, 0, 30,
    -70, 0, -5,
    -105, 0, 30,
    -110, 0, -50,
    -145, 0, -5,
    -170, 0, -50,
    -190, 0, -30,
    -210, 0, -10,
};

f32 D_802A3F00_721550[] = { 1.0f, 1.0f, 0.75f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.75f, 0.75f };

EntityModelScript* D_802A3F28_721578[] = {
    &N(modelCommandList),
    &N(modelCommandList2),
    &N(modelCommandList3),
    &N(modelCommandList),
    &N(modelCommandList2),
    &N(modelCommandList3),
    &N(modelCommandList),
    &N(modelCommandList2),
    &N(modelCommandList3),
    &N(modelCommandList)
};
