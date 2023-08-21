#include "jan_00.h"
#include "effects.h"

u32 N(unkAngle1) = 0;
s32 N(unkAngle2) = -1;
s32 N(unkAngle3) = -1;

#include "world/common/atomic/WhaleAnim.inc.c"

API_CALLABLE(N(UnkPlayerPosFunc)) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 170.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 170.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, LVar0, x);
    evt_set_float_variable(script, LVar1, y);
    evt_set_float_variable(script, LVar2, z);
    return ApiStatus_DONE2;
}

EvtScript N(D_8024595C_B25E9C) = {
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    EVT_CALL(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802459D4_B25F14) = {
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 0, 30, 30, 1, 0)
    EVT_SETF(LVar1, LVar0)
    EVT_DIVF(LVar1, EVT_FLOAT(3.0))
    EVT_CALL(RotateModel, MODEL_o173, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_dou, LVar1, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o170, -5, -68, 0)
    EVT_CALL(TranslateModel, MODEL_o183, -5, -68, 0)
    EVT_CALL(TranslateModel, MODEL_o167, 60, 29, -51)
    EVT_CALL(TranslateModel, MODEL_o168, 60, 29, 51)
    EVT_CALL(RotateModel, MODEL_o170, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o183, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o167, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o168, LVar1, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o170, 5, 68, 0)
    EVT_CALL(TranslateModel, MODEL_o183, 5, 68, 0)
    EVT_CALL(TranslateModel, MODEL_o167, -60, -29, 51)
    EVT_CALL(TranslateModel, MODEL_o168, -60, -29, -51)
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 0, -40, 30, 1, 0)
    EVT_CALL(TranslateModel, MODEL_bero, LVar0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245C10_B26150) = {
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 0, -30, 8, 1, 0)
    EVT_ADDF(LVar0, EVT_FLOAT(30.0))
    EVT_SETF(LVar1, LVar0)
    EVT_DIVF(LVar1, EVT_FLOAT(3.0))
    EVT_CALL(RotateModel, MODEL_o173, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_dou, LVar1, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o170, -5, -68, 0)
    EVT_CALL(TranslateModel, MODEL_o183, -5, -68, 0)
    EVT_CALL(TranslateModel, MODEL_o167, 60, 29, -51)
    EVT_CALL(TranslateModel, MODEL_o168, 60, 29, 51)
    EVT_CALL(RotateModel, MODEL_o170, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o183, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o167, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o168, LVar1, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o170, 5, 68, 0)
    EVT_CALL(TranslateModel, MODEL_o183, 5, 68, 0)
    EVT_CALL(TranslateModel, MODEL_o167, -60, -29, 51)
    EVT_CALL(TranslateModel, MODEL_o168, -60, -29, -51)
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 0, -40, 120, 1, 0)
    EVT_CALL(TranslateModel, MODEL_bero, LVar0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245E5C_B2639C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245E6C_B263AC) = {
    EVT_SET(LVar1, LVarC)
    EVT_MOD(LVar1, 4)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(N(UnkPlayerPosFunc))
        EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_2, LVar0, LVar1, LVar2, 0, -1, 0, 5)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    EVT_CALL(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245F6C_B264AC) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245F7C_B264BC) = {
    EVT_IF_GE(LVarC, 0)
        EVT_IF_LE(LVarC, 2)
            EVT_CALL(EnableModel, MODEL_o170, FALSE)
            EVT_CALL(EnableModel, MODEL_o183, TRUE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarC, 15)
        EVT_CALL(EnableModel, MODEL_o170, FALSE)
        EVT_CALL(EnableModel, MODEL_o183, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVarC, 22)
        EVT_CALL(EnableModel, MODEL_o170, FALSE)
        EVT_CALL(EnableModel, MODEL_o183, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableModel, MODEL_o170, TRUE)
    EVT_CALL(EnableModel, MODEL_o183, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802460A4_B265E4) = {
    EVT_SET(LVar0, LVarC)
    EVT_DIV(LVar0, 20)
    EVT_MOD(LVar0, 2)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, EVT_FLOAT(-1.0), EVT_FLOAT(1.0), 3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_dou, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o170, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o183, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o167, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o168, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o167, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o168, LVar0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024620C_B2674C) = {
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, EVT_FLOAT(-6.0), EVT_FLOAT(6.0), 3, 0, 0)
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar1, EVT_FLOAT(6.0), EVT_FLOAT(-6.0), 2, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, LVar0, LVar1, 0)
    EVT_CALL(TranslateGroup, MODEL_dou, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o170, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o183, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o167, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o168, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o167, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o168, LVar0, LVar1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024634C_B2688C) = {
    EVT_SET(LVar0, LVarC)
    EVT_DIV(LVar0, 20)
    EVT_MOD(LVar0, 2)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, EVT_FLOAT(-1.0), EVT_FLOAT(1.0), 3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_dou, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o170, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o183, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o167, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o168, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o167, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o168, LVar0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802464B4_B269F4) = {
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    EVT_CALL(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024652C_B26A6C) = {
    EVT_CALL(N(UnkFloatFunc001), LVarC, LVar0, 0, 8, 3, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_DIV(LVar1, 3)
    EVT_CALL(RotateModel, MODEL_o173, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_dou, LVar1, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o170, -5, -68, 0)
    EVT_CALL(TranslateModel, MODEL_o183, -5, -68, 0)
    EVT_CALL(TranslateModel, MODEL_o167, 60, 29, -51)
    EVT_CALL(TranslateModel, MODEL_o168, 60, 29, 51)
    EVT_CALL(RotateModel, MODEL_o170, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o183, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o167, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o168, LVar1, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o170, 5, 68, 0)
    EVT_CALL(TranslateModel, MODEL_o183, 5, 68, 0)
    EVT_CALL(TranslateModel, MODEL_o167, -60, -29, 51)
    EVT_CALL(TranslateModel, MODEL_o168, -60, -29, -51)
    EVT_SET(LVar0, LVarC)
    EVT_MUL(LVar0, 2)
    EVT_CALL(N(UnkFloatFunc001), LVar0, LVar0, 30, 60, 3, 0, 0)
    EVT_CALL(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802467AC) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_1, MODEL_karada, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(unkAngleFunc002)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_karada, CUSTOM_GFX_1, -1)
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_2, MODEL_onaka, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_2, EVT_PTR(N(unkAngleFunc003)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_onaka, CUSTOM_GFX_2, -1)
    EVT_THREAD
        EVT_LABEL(0)
        EVT_CALL(N(UnkAngleFunc001), 0, LVar0, LVar1, LVar2)
        EVT_SUBF(LVar0, -80)
        EVT_SUBF(LVar1, -18)
        EVT_SUBF(LVar2, 420)
        EVT_ADDF(LVar0, 55)
        EVT_ADDF(LVar1, -20)
        EVT_ADDF(LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_bero, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateModel, MODEL_o170, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateModel, MODEL_o183, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateModel, MODEL_o173, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateModel, MODEL_o167, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateModel, MODEL_o168, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_dou, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcYaw, NPC_Whale, LVar0)
        EVT_MULF(LVar0, -1)
        EVT_ADDF(LVar0, -90)
        EVT_CALL(TranslateModel, MODEL_bero, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o170, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o183, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o173, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o167, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o168, -100, 0, 0)
        EVT_CALL(TranslateGroup, MODEL_dou, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_bero, 100, -1, 0)
        EVT_CALL(TranslateModel, MODEL_o170, -5, -68, 0)
        EVT_CALL(TranslateModel, MODEL_o183, -5, -68, 0)
        EVT_CALL(TranslateModel, MODEL_o173, 102, 4, 0)
        EVT_CALL(TranslateModel, MODEL_o167, 60, 29, -51)
        EVT_CALL(TranslateModel, MODEL_o168, 60, 29, 51)
        EVT_CALL(RotateModel, MODEL_bero, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o170, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o183, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o173, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o167, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_dou, LVar0, 0, 1, 0)
        EVT_CALL(TranslateModel, MODEL_bero, -100, 1, 0)
        EVT_CALL(TranslateModel, MODEL_o170, 5, 68, 0)
        EVT_CALL(TranslateModel, MODEL_o183, 5, 68, 0)
        EVT_CALL(TranslateModel, MODEL_o173, -102, -4, 0)
        EVT_CALL(TranslateModel, MODEL_o167, -60, -29, 51)
        EVT_CALL(TranslateModel, MODEL_o168, -60, -29, -51)
        EVT_CALL(TranslateModel, MODEL_bero, 100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o170, 100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o183, 100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o173, 100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o167, 100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o168, 100, 0, 0)
        EVT_CALL(TranslateGroup, MODEL_dou, 100, 0, 0)
        EVT_CALL(GetNpcAnimation, NPC_Whale, LVar0)
        EVT_IF_NE(LVar0, LVarB)
            EVT_SET(LVarB, LVar0)
            EVT_SET(LVarC, 0)
            EVT_CALL(EnableModel, MODEL_o170, TRUE)
            EVT_CALL(EnableModel, MODEL_o183, FALSE)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(0x00B60003)
                    EVT_SET(LVarD, EVT_PTR(N(D_80245C10_B26150)))
                EVT_CASE_EQ(0x00B60000)
                    EVT_SET(LVarD, EVT_PTR(N(D_8024595C_B25E9C)))
                EVT_CASE_EQ(0x00B60002)
                    EVT_SET(LVarD, EVT_PTR(N(D_802459D4_B25F14)))
                EVT_CASE_EQ(0x00B60001)
                    EVT_SET(LVarD, EVT_PTR(N(D_802464B4_B269F4)))
                EVT_CASE_EQ(0x00B60004)
                    EVT_SET(LVarD, EVT_PTR(N(D_8024652C_B26A6C)))
                EVT_CASE_EQ(0x00B60005)
                    EVT_SET(LVarD, EVT_PTR(N(D_80245E5C_B2639C)))
                    EVT_CALL(EnableModel, MODEL_o170, FALSE)
                    EVT_CALL(EnableModel, MODEL_o183, FALSE)
                EVT_CASE_EQ(0x00B60006)
                    EVT_SET(LVarD, EVT_PTR(N(D_802460A4_B265E4)))
                    EVT_CALL(EnableModel, MODEL_o170, FALSE)
                    EVT_CALL(EnableModel, MODEL_o183, FALSE)
                EVT_CASE_EQ(0x00B60007)
                    EVT_SET(LVarD, EVT_PTR(N(D_8024620C_B2674C)))
                    EVT_CALL(EnableModel, MODEL_o170, FALSE)
                    EVT_CALL(EnableModel, MODEL_o183, FALSE)
                EVT_CASE_EQ(0x00B60008)
                    EVT_SET(LVarD, EVT_PTR(N(D_8024634C_B2688C)))
                EVT_CASE_EQ(0x00B60009)
                    EVT_SET(LVarD, EVT_PTR(N(D_80245E6C_B263AC)))
                EVT_CASE_EQ(0x00B6000A)
                    EVT_SET(LVarD, EVT_PTR(N(D_80245F6C_B264AC)))
                EVT_CASE_EQ(0x00B6000C)
                    EVT_SET(LVarD, EVT_PTR(N(D_80245F7C_B264BC)))
            EVT_END_SWITCH
        EVT_END_IF
        EVT_EXEC_WAIT(LVarD)
        EVT_ADD(LVarC, 1)
        EVT_IF_GT(LVarC, 1000)
            EVT_SET(LVarC, 0)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80247040) = {
    EVT_CALL(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
    EVT_RETURN
    EVT_END
};
