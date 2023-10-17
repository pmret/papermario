#include "omo_08.h"
#include "effects.h"

extern EvtScript N(EVS_HitBox);

enum {
    BOX_COLOR_GREEN     = 0,
    BOX_COLOR_YELLOW    = 1,
    BOX_COLOR_RED       = 2,
    BOX_COLOR_BLUE      = 3,
};

#define BOX_SEQUENCE(a, b, c, d) (a << 6 | b << 4 | c << 2 | d)

s32 N(GreenBoxInfo)[] = {
    BOX_COLOR_GREEN,
    MODEL_bm1_2, MODEL_b1_2,
    MODEL_bm1_1, MODEL_b1_1,
};

s32 N(YellowBoxInfo)[] = {
    BOX_COLOR_YELLOW,
    MODEL_bm2_2, MODEL_b2_2,
    MODEL_bm2_1, MODEL_b2_1,
};

s32 N(RedBoxInfo)[] = {
    BOX_COLOR_RED,
    MODEL_bm3_2, MODEL_b3_2,
    MODEL_bm3_1, MODEL_b3_1,
};

s32 N(BlueBoxInfo)[] = {
    BOX_COLOR_BLUE,
    MODEL_bm4_2, MODEL_b4_2,
    MODEL_bm4_1, MODEL_b4_1,
};

EvtScript N(EVS_GreenLightOff) = {
    EVT_CALL(EnableModel, MODEL_bm1_1, TRUE)
    EVT_CALL(EnableModel, MODEL_b1_1, TRUE)
    EVT_CALL(EnableModel, MODEL_bm1_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b1_2, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YellowLightOff) = {
    EVT_CALL(EnableModel, MODEL_bm2_1, TRUE)
    EVT_CALL(EnableModel, MODEL_b2_1, TRUE)
    EVT_CALL(EnableModel, MODEL_bm2_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b2_2, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RedLightOff) = {
    EVT_CALL(EnableModel, MODEL_bm3_1, TRUE)
    EVT_CALL(EnableModel, MODEL_b3_1, TRUE)
    EVT_CALL(EnableModel, MODEL_bm3_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b3_2, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlueLightOff) = {
    EVT_CALL(EnableModel, MODEL_bm4_1, TRUE)
    EVT_CALL(EnableModel, MODEL_b4_1, TRUE)
    EVT_CALL(EnableModel, MODEL_bm4_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b4_2, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GreenLightOn) = {
    EVT_CALL(EnableModel, MODEL_bm1_1, FALSE)
    EVT_CALL(EnableModel, MODEL_b1_1, FALSE)
    EVT_CALL(EnableModel, MODEL_bm1_2, TRUE)
    EVT_CALL(EnableModel, MODEL_b1_2, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YellowLightOn) = {
    EVT_CALL(EnableModel, MODEL_bm2_1, FALSE)
    EVT_CALL(EnableModel, MODEL_b2_1, FALSE)
    EVT_CALL(EnableModel, MODEL_bm2_2, TRUE)
    EVT_CALL(EnableModel, MODEL_b2_2, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RedLightOn) = {
    EVT_CALL(EnableModel, MODEL_bm3_1, FALSE)
    EVT_CALL(EnableModel, MODEL_b3_1, FALSE)
    EVT_CALL(EnableModel, MODEL_bm3_2, TRUE)
    EVT_CALL(EnableModel, MODEL_b3_2, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlueLightOn) = {
    EVT_CALL(EnableModel, MODEL_bm4_1, FALSE)
    EVT_CALL(EnableModel, MODEL_b4_1, FALSE)
    EVT_CALL(EnableModel, MODEL_bm4_2, TRUE)
    EVT_CALL(EnableModel, MODEL_b4_2, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ResetBoxesAfterAmbush) = {
    // wait for all shy guys to be defeated
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_02, LVar0, LVar2, LVar3)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_03, LVar0, LVar3, LVar4)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_04, LVar0, LVar4, LVar5)
        EVT_ADD(LVar1, LVar2)
        EVT_ADD(LVar1, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_IF_NE(LVar1, 4 * NPC_DISPOSE_POS_Y)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_THREAD
        EVT_EXEC(N(EVS_GreenLightOff))
        EVT_CALL(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm1_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm1_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_THREAD
        EVT_EXEC(N(EVS_YellowLightOff))
        EVT_CALL(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm2_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm2_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_EXEC(N(EVS_RedLightOff))
        EVT_CALL(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm3_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm3_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_EXEC(N(EVS_BlueLightOff))
    EVT_CALL(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_bm4_2, LVar0, -1, 0, 0)
        EVT_CALL(RotateModel, MODEL_bm4_1, LVar0, -1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MV_BoxHitSequence, 0)
    EVT_SET(MV_BoxHitCount, 0)
    EVT_CALL(EnableModel, MODEL_bm1_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b1_2, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(GreenBoxInfo)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o907, 1, 0)
    EVT_CALL(EnableModel, MODEL_bm2_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b2_2, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(YellowBoxInfo)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o911, 1, 0)
    EVT_CALL(EnableModel, MODEL_bm3_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b3_2, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(RedBoxInfo)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o915, 1, 0)
    EVT_CALL(EnableModel, MODEL_bm4_2, FALSE)
    EVT_CALL(EnableModel, MODEL_b4_2, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(BlueBoxInfo)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o918, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BoxResult_GiveCoins) = {
    EVT_SET(LVar0, 4)
    EVT_LOOP(3)
        EVT_EXEC(N(EVS_GreenLightOff))
        EVT_WAIT(LVar0)
        EVT_EXEC(N(EVS_YellowLightOff))
        EVT_WAIT(LVar0)
        EVT_EXEC(N(EVS_RedLightOff))
        EVT_WAIT(LVar0)
        EVT_EXEC(N(EVS_BlueLightOff))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_CHIME_2, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_GreenLightOn))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_CHIME_1, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_YellowLightOn))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_CHIME_3, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_RedLightOn))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_CHIME_4, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_BlueLightOn))
        EVT_WAIT(LVar0)
        EVT_SUB(LVar0, 1)
    EVT_END_LOOP
    EVT_WAIT(4)
    EVT_SET(LVar0, 4)
    EVT_LOOP(3)
        EVT_EXEC(N(EVS_GreenLightOff))
        EVT_EXEC(N(EVS_YellowLightOff))
        EVT_EXEC(N(EVS_RedLightOff))
        EVT_EXEC(N(EVS_BlueLightOff))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySound, SOUND_OMO_BOX_DONE)
        EVT_EXEC(N(EVS_GreenLightOn))
        EVT_EXEC(N(EVS_YellowLightOn))
        EVT_EXEC(N(EVS_RedLightOn))
        EVT_EXEC(N(EVS_BlueLightOn))
        EVT_WAIT(LVar0)
        EVT_SUB(LVar0, 1)
    EVT_END_LOOP
    EVT_WAIT(2)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm1_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm1_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_b1_1)
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm2_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm2_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_b2_1)
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm3_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm3_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_b3_1)
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm4_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm4_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_b4_1)
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
        EVT_WAIT(20)
        EVT_CALL(ResetCam, CAM_DEFAULT, 2)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BoxResult_RepairTrack) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(4)
        EVT_EXEC(N(EVS_GreenLightOff))
        EVT_WAIT(3)
        EVT_EXEC(N(EVS_YellowLightOff))
        EVT_WAIT(3)
        EVT_EXEC(N(EVS_RedLightOff))
        EVT_WAIT(3)
        EVT_EXEC(N(EVS_BlueLightOff))
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_CHIME_2, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_GreenLightOn))
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_CHIME_1, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_YellowLightOn))
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_CHIME_3, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_RedLightOn))
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_CHIME_4, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_BlueLightOn))
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 160, 10, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 160, 10, -200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 700)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 40, EVT_FLOAT(-4.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_t1, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_o875)
        EVT_CALL(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.8))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_t2, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_o877)
        EVT_CALL(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.8))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_t3, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_o879)
        EVT_CALL(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.8))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_t4, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetModelCenter, MODEL_o881)
        EVT_CALL(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.8))
    EVT_END_THREAD
    EVT_WAIT(100)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 100, 0, 370)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 100, 0, 370)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 16, EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetModelCenter, MODEL_b1_1)
        EVT_CALL(SetGroupVisibility, MODEL_b1, MODEL_GROUP_HIDDEN)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o907, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        EVT_LOOP(4)
            EVT_SET(LVar3, 20)
            EVT_CALL(RandInt, 40, LVar6)
            EVT_SUB(LVar3, LVar6)
            EVT_ADD(LVar3, LVar0)
            EVT_SET(LVar4, 20)
            EVT_CALL(RandInt, 40, LVar7)
            EVT_SUB(LVar4, LVar7)
            EVT_ADD(LVar4, LVar1)
            EVT_SET(LVar5, 20)
            EVT_CALL(RandInt, 40, LVar8)
            EVT_SUB(LVar5, LVar8)
            EVT_ADD(LVar5, LVar2)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(GetModelCenter, MODEL_b2_1)
        EVT_CALL(SetGroupVisibility, MODEL_b2, MODEL_GROUP_HIDDEN)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o911, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        EVT_LOOP(4)
            EVT_SET(LVar3, 20)
            EVT_CALL(RandInt, 40, LVar6)
            EVT_SUB(LVar3, LVar6)
            EVT_ADD(LVar3, LVar0)
            EVT_SET(LVar4, 20)
            EVT_CALL(RandInt, 40, LVar7)
            EVT_SUB(LVar4, LVar7)
            EVT_ADD(LVar4, LVar1)
            EVT_SET(LVar5, 20)
            EVT_CALL(RandInt, 40, LVar8)
            EVT_SUB(LVar5, LVar8)
            EVT_ADD(LVar5, LVar2)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(GetModelCenter, MODEL_b3_1)
        EVT_CALL(SetGroupVisibility, MODEL_b3, MODEL_GROUP_HIDDEN)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o915, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        EVT_LOOP(4)
            EVT_SET(LVar3, 20)
            EVT_CALL(RandInt, 40, LVar6)
            EVT_SUB(LVar3, LVar6)
            EVT_ADD(LVar3, LVar0)
            EVT_SET(LVar4, 20)
            EVT_CALL(RandInt, 40, LVar7)
            EVT_SUB(LVar4, LVar7)
            EVT_ADD(LVar4, LVar1)
            EVT_SET(LVar5, 20)
            EVT_CALL(RandInt, 40, LVar8)
            EVT_SUB(LVar5, LVar8)
            EVT_ADD(LVar5, LVar2)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(GetModelCenter, MODEL_b4_1)
        EVT_CALL(SetGroupVisibility, MODEL_b4, MODEL_GROUP_HIDDEN)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o918, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        EVT_LOOP(4)
            EVT_SET(LVar3, 20)
            EVT_CALL(RandInt, 40, LVar6)
            EVT_SUB(LVar3, LVar6)
            EVT_ADD(LVar3, LVar0)
            EVT_SET(LVar4, 20)
            EVT_CALL(RandInt, 40, LVar7)
            EVT_SUB(LVar4, LVar7)
            EVT_ADD(LVar4, LVar1)
            EVT_SET(LVar5, 20)
            EVT_CALL(RandInt, 40, LVar8)
            EVT_SUB(LVar5, LVar8)
            EVT_ADD(LVar5, LVar2)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o907, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o911, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o915, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o918, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(20)
    EVT_CALL(ResetCam, CAM_DEFAULT, 2)
    EVT_SET(GB_StoryProgress, STORY_CH4_SOLVED_COLOR_PUZZLE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BoxResult_ReleaseShyGuys) = {
    EVT_SET(LVar0, 4)
    EVT_LOOP(3)
        EVT_EXEC(N(EVS_GreenLightOff))
        EVT_WAIT(LVar0)
        EVT_EXEC(N(EVS_YellowLightOff))
        EVT_WAIT(LVar0)
        EVT_EXEC(N(EVS_RedLightOff))
        EVT_WAIT(LVar0)
        EVT_EXEC(N(EVS_BlueLightOff))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_CHIME_2, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_BlueLightOn))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_CHIME_1, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_RedLightOn))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_CHIME_3, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_YellowLightOn))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_CHIME_4, SOUND_SPACE_DEFAULT)
        EVT_EXEC(N(EVS_GreenLightOn))
        EVT_WAIT(LVar0)
        EVT_SUB(LVar0, 1)
    EVT_END_LOOP
    EVT_WAIT(4)
    EVT_SET(LVar0, 4)
    EVT_LOOP(3)
        EVT_EXEC(N(EVS_GreenLightOff))
        EVT_EXEC(N(EVS_YellowLightOff))
        EVT_EXEC(N(EVS_RedLightOff))
        EVT_EXEC(N(EVS_BlueLightOff))
        EVT_WAIT(LVar0)
        EVT_CALL(PlaySound, SOUND_OMO_BOX_DONE)
        EVT_EXEC(N(EVS_GreenLightOn))
        EVT_EXEC(N(EVS_YellowLightOn))
        EVT_EXEC(N(EVS_RedLightOn))
        EVT_EXEC(N(EVS_BlueLightOn))
        EVT_WAIT(LVar0)
        EVT_SUB(LVar0, 1)
    EVT_END_LOOP
    EVT_WAIT(2)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm1_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm1_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o907, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetModelCenter, MODEL_b1_1)
        EVT_CALL(SetNpcPos, NPC_ShyGuy_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_01, EVT_FLOAT(1.0))
        EVT_ADD(LVar2, 60)
        EVT_CALL(NpcJump0, NPC_ShyGuy_01, LVar0, 0, LVar2, 20)
        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_01, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm2_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm2_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o911, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetModelCenter, MODEL_b2_1)
        EVT_CALL(SetNpcPos, NPC_ShyGuy_02, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_02, EVT_FLOAT(1.0))
        EVT_ADD(LVar2, 60)
        EVT_CALL(NpcJump0, NPC_ShyGuy_02, LVar0, 0, LVar2, 20)
        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_02, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm3_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm3_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o915, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetModelCenter, MODEL_b3_1)
        EVT_CALL(SetNpcPos, NPC_ShyGuy_03, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_03, EVT_FLOAT(1.0))
        EVT_ADD(LVar2, 60)
        EVT_CALL(NpcJump0, NPC_ShyGuy_03, LVar0, 0, LVar2, 20)
        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_03, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_bm4_2, LVar0, -1, 0, 0)
            EVT_CALL(RotateModel, MODEL_bm4_1, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o918, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetModelCenter, MODEL_b4_1)
        EVT_CALL(SetNpcPos, NPC_ShyGuy_04, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_04, EVT_FLOAT(1.0))
        EVT_ADD(LVar2, 60)
        EVT_CALL(NpcJump0, NPC_ShyGuy_04, LVar0, 0, LVar2, 20)
        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_04, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
        EVT_CALL(ResetCam, CAM_DEFAULT, 1)
        EVT_EXEC(N(EVS_ResetBoxesAfterAmbush))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitBox) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVT_PTR(N(GreenBoxInfo)))
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_GLOW_2, SOUND_SPACE_DEFAULT)
        EVT_CASE_EQ(EVT_PTR(N(YellowBoxInfo)))
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_GLOW_1, SOUND_SPACE_DEFAULT)
        EVT_CASE_EQ(EVT_PTR(N(RedBoxInfo)))
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_GLOW_3, SOUND_SPACE_DEFAULT)
        EVT_CASE_EQ(EVT_PTR(N(BlueBoxInfo)))
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_GLOW_4, SOUND_SPACE_DEFAULT)
    EVT_END_SWITCH
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ1(LVar1)
    EVT_BUF_READ4(LVar2, LVar3, LVar4, LVar5)
    EVT_LOOP(5)
        EVT_CALL(EnableModel, LVar2, FALSE)
        EVT_CALL(EnableModel, LVar3, FALSE)
        EVT_CALL(EnableModel, LVar4, TRUE)
        EVT_CALL(EnableModel, LVar5, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, LVar2, TRUE)
        EVT_CALL(EnableModel, LVar3, TRUE)
        EVT_CALL(EnableModel, LVar4, FALSE)
        EVT_CALL(EnableModel, LVar5, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_MUL(MV_BoxHitSequence, 4) // shift left by 2
    EVT_BITWISE_OR(MV_BoxHitSequence, LVar1)
    EVT_ADD(MV_BoxHitCount, 1)
    EVT_IF_EQ(MV_BoxHitCount, 4)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(5)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 100, 0, 370)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 100, 0, 370)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, -450)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 16, EVT_FLOAT(-6.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(30)
        EVT_SWITCH(MV_BoxHitSequence)
            EVT_CASE_EQ(BOX_SEQUENCE(BOX_COLOR_GREEN, BOX_COLOR_YELLOW, BOX_COLOR_RED, BOX_COLOR_BLUE))
                EVT_EXEC_WAIT(N(EVS_BoxResult_GiveCoins))
            EVT_CASE_EQ(BOX_SEQUENCE(BOX_COLOR_YELLOW, BOX_COLOR_GREEN, BOX_COLOR_RED, BOX_COLOR_BLUE))
                EVT_EXEC_WAIT(N(EVS_BoxResult_RepairTrack))
            EVT_CASE_DEFAULT
                EVT_EXEC_WAIT(N(EVS_BoxResult_ReleaseShyGuys))
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_THREAD
            EVT_LABEL(10)
            EVT_CALL(EnableModel, LVar2, FALSE)
            EVT_CALL(EnableModel, LVar3, FALSE)
            EVT_CALL(EnableModel, LVar4, TRUE)
            EVT_CALL(EnableModel, LVar5, TRUE)
            EVT_WAIT(5)
            EVT_CALL(EnableModel, LVar2, TRUE)
            EVT_CALL(EnableModel, LVar3, TRUE)
            EVT_CALL(EnableModel, LVar4, FALSE)
            EVT_CALL(EnableModel, LVar5, FALSE)
            EVT_WAIT(10)
            EVT_IF_NE(MV_BoxHitCount, 4)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_THREAD
    EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBoxes) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_SOLVED_COLOR_PUZZLE)
        EVT_SET(MV_BoxHitSequence, 0)
        EVT_SET(MV_BoxHitCount, 0)
        EVT_CALL(EnableModel, MODEL_bm1_2, FALSE)
        EVT_CALL(EnableModel, MODEL_b1_2, FALSE)
        EVT_SET(LVar0, EVT_PTR(N(GreenBoxInfo)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o907, 1, 0)
        EVT_CALL(EnableModel, MODEL_bm2_2, FALSE)
        EVT_CALL(EnableModel, MODEL_b2_2, FALSE)
        EVT_SET(LVar0, EVT_PTR(N(YellowBoxInfo)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o911, 1, 0)
        EVT_CALL(EnableModel, MODEL_bm3_2, FALSE)
        EVT_CALL(EnableModel, MODEL_b3_2, FALSE)
        EVT_SET(LVar0, EVT_PTR(N(RedBoxInfo)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o915, 1, 0)
        EVT_CALL(EnableModel, MODEL_bm4_2, FALSE)
        EVT_CALL(EnableModel, MODEL_b4_2, FALSE)
        EVT_SET(LVar0, EVT_PTR(N(BlueBoxInfo)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o918, 1, 0)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_box, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o907, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o911, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o915, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o918, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sen1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sen2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(RotateGroup, MODEL_t1, 90, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_t2, 90, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_t3, 90, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_t4, 90, 1, 0, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
