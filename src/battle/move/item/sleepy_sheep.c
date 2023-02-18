#include "common.h"
#include "script_api/battle.h"
#include "entity.h"
#include "ld_addrs.h"
#include "effects.h"

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
        script->functionTemp[1] = 0x5A;
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
#include "battle/move/item/sleepy_sheep1.png.inc.c"
#include "battle/move/item/sleepy_sheep1.pal.inc.c"

#include "battle/move/item/sleepy_sheep2.png.h"
#include "battle/move/item/sleepy_sheep2.png.inc.c"
#include "battle/move/item/sleepy_sheep2.pal.inc.c"

#include "battle/move/item/sleepy_sheep3.png.h"
#include "battle/move/item/sleepy_sheep3.png.inc.c"
#include "battle/move/item/sleepy_sheep3.pal.inc.c"

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

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, ITEM_SLEEPY_SHEEP)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -67, -15, -5)
    EVT_CALL(SetBattleCamOffsetZ, 45)
    EVT_CALL(SetBattleCamZoom, 169)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_364)
        EVT_LOOP(7)
            EVT_CALL(StartRumble, 2)
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.25))
            EVT_WAIT(2)
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 32)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 20, EMOTER_POS, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(30)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_THREAD
        EVT_CALL(N(func_802A123C_71E88C))
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_THREAD
        EVT_WAIT(40)
        EVT_CALL(N(func_802A1740_71ED90))
        EVT_CALL(N(func_802A1848_71EE98))
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(8)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_1002B, ANIM_Mario_1002B, ANIM_Mario_AnimMidair)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 15, 0, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
        EVT_WAIT(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
        EVT_WAIT(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
        EVT_WAIT(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
        EVT_WAIT(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
        EVT_WAIT(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(modelCommandList)))
    EVT_SET(LVar7, -200)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 0)
    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar7, LVar8, LVar9)
    EVT_CALL(SetVirtualEntityScale, LVarA, EVT_FLOAT(0.711), EVT_FLOAT(0.711), EVT_FLOAT(0.711))
    EVT_CALL(SetVirtualEntityMoveSpeed, LVarA, EVT_FLOAT(7.0))
    EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(1.4))
    EVT_CALL(SetOwnerTarget, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_CALL(VirtualEntityMoveTo, LVarA, LVar0, LVar1, LVar2, 0)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_ShockStill)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.2), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.3), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(3)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.2), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(PlayEffect, 0x6, 3, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(1.4))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    EVT_CALL(PlayEffect, 0x6, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_ADD(LVar0, 20)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    EVT_CALL(PlayEffect, 0x6, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ADD(LVar0, 10)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 0)
    EVT_CALL(PlayEffect, 0x6, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 270)
        EVT_CALL(VirtualEntityMoveTo, LVarA, LVar0, LVar1, LVar2, 0)
        EVT_CALL(DeleteVirtualEntity, LVarA)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LVar0, 268435456, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetItemPower, ITEM_SLEEPY_SHEEP, LVar0, LVar1)
    EVT_CALL(MakeStatusField, LVar0, 4096, 100, LVar0)
    EVT_CALL(ItemAfflictEnemy, LVar0, 1342177280, LVar0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_LABEL(1)
    EVT_WAIT(5)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
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
