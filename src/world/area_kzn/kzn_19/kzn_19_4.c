#include "kzn_19.h"

extern API_CALLABLE(SetAnimatorFlags);
extern API_CALLABLE(GetAnimatedPositionByTreeIndex);
extern API_CALLABLE(GetAnimatedRotationByTreeIndex);

extern EvtScript N(D_80242164_C8FD14);
extern StaticAnimatorNode* N(D_802431F8_C90DA8);
extern StaticAnimatorNode* N(D_80243388_C90F38);
extern StaticAnimatorNode* N(D_802434B8_C91068);

extern NpcSettings N(NpcSettings_Kolorado);
extern NpcSettings N(NpcSettings_Misstar);
extern NpcSettings N(NpcSettings_LavaPiranhaHead);

extern API_CALLABLE(func_80241BC0_C8F770);
extern API_CALLABLE(func_8024140C_C8EFBC);
extern API_CALLABLE(func_802413FC_C8EFAC);
extern API_CALLABLE(func_80240BD4_C8E784);
extern API_CALLABLE(func_80240CD8_C8E888);
extern API_CALLABLE(func_80240DA4_C8E954);

s32 N(D_802434D8_C91088)[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 1, 0x11000000, 0, 0, 0, 0, 0, 
    0, 17, 0x21100000, 0, 0, 0, 0, 0, 
    0, 18, 0x22100000, 0, 0, 0, 0, 0, 
    0, 274, 0x22110000, 0, 0, 0, 0, 0, 
    0, 290, 0x22210000, 0, 0, 0, 0, 0, 
    0, 0x00001122, 0x22211000, 0, 0, 0, 0, 0, 
    0, 0x00001222, 0x22221000, 0, 0, 0, 0, 0, 
    0x33333333, 0x33311222, 0x22221133, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 
    0x33333333, 0x33312222, 0x22222133, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 
    0x33333333, 0x33112222, 0x22222113, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x31122222, 0x22222113, 0x33333333, 
    0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33122222, 0x22222133, 0x33333333, 
    0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33112222, 0x22221133, 0x33333333, 
    0, 0, 0, 0, 0, 0x00012222, 0x22221000, 0, 
    0, 0, 0, 0, 0, 0x00011222, 0x22211000, 0, 
    0, 0, 0, 0, 0, 0x00001222, 0x22210000, 0, 
    0, 0, 0, 0, 0, 0x00001122, 0x22110000, 0, 
    0, 0, 0, 0, 0, 290, 0x22100000, 0, 
    0, 0, 0, 0, 0, 274, 0x21100000, 0, 
    0, 0, 0, 0, 0, 17, 0x11000000, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};

s32 N(D_802438D8_C91488)[] = {
    0x014041C1, 0xE7390241, 0x044F0000, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};

Gfx D_80243AD8_C91688[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(
        AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
        AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0),
    gsDPSetPrimColor(0, 0, 255, 160, 160, 0),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, 0x802438D8), //TODO fix pointers
    gsDPLoadTextureTile_4b(0x802434D8, G_IM_FMT_CI, 64, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE),
    gsSPEndDisplayList(),
};

s32 D_80243BB8_C91768[] = {
    0x007B6690, 0x007B70E0, 0x80234000,
    0x007B5960, 0x007B6690, 0x80234000,
    0x007C4F50, 0x007C7410, 0x80234000, 
    0x007C7410, 0x007C7E50, 0x80234000, 
    0x007B70E0, 0x007B8030, 0x80234000, 
    0x007B8030, 0x007B8D30, 0x80234000, 
    0x007B8D30, 0x007B97E0, 0x80234000, 
    0x007B97E0, 0x007BA280, 0x80234000, 
    0x007BA280, 0x007BB050, 0x80234000, 
    0x007BB050, 0x007BBD80, 0x80234000,
    0x007BBD80, 0x007BEDD0, 0x80234000, 
    0x007BEDD0, 0x007C16C0, 0x80234000, 
    0x007C16C0, 0x007C3A00, 0x80234000, 
    0x007C3A00, 0x007C44D0, 0x80234000, 
    0x007C44D0, 0x007C4F50, 0x80234000,
    0x007C7E50, 0x007CA850, 0x80234000, 
    0x007CA850, 0x007CD5F0, 0x80234000, 
    0x007CD5F0, 0x007CDB30, 0x80234000, 
    0x007CDB30, 0x007CEFF0, 0x80234000,
    0x007CEFF0, 0x007CFCC0, 0x80234000, 
    0x007CFCC0, 0x007D0860, 0x80234000,
    0x007D0860, 0x007D14E0, 0x80234000, 
    0x007D14E0, 0x007D2080, 0x80234000,
    0x007D2080, 0x007D2960, 0x80234000, 
    0x007D2960, 0x007D3260, 0x80234000, 
    0x007D3260, 0x007D5570, 0x80234000,
    0x007D5570, 0x007D6F80, 0x80234000,
    0x007D6F80, 0x007D76B0, 0x80234000,
    0x007D76B0, 0x007D8FF0, 0x80234000,
    0x007D8FF0, 0x007D96E0, 0x80234000,
    0x007D96E0, 0x007D98E0, 0x80234000,
    0x007D98E0, 0x007DA140, 0x80234000, 
    0x007DA140, 0x007DC180, 0x80234000, 
    0x007DC180, 0x007DE970, 0x80234000,
    0x007DE970, 0x007DF2B0, 0x80234000, 
    0x007DF2B0, 0x007E03B0, 0x80234000,
    0x007E03B0, 0x007E0E80, 0x80234000, 
};

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240B00_C8E6B0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240BD4_C8E784);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240CD8_C8E888);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240DA4_C8E954);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240E2C_C8E9DC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413C0_C8EF70);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413FC_C8EFAC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_8024140C_C8EFBC);

#include "world/common/atomic/LetterChoice.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241BC0_C8F770);

s32 N(LetterList)[] = {
    ITEM_LETTER25,
    ITEM_NONE 
};

EvtScript N(D_80244688_C92238) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER25, 0,
        MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802446D8_C92288) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_SET(LVar0, ITEM_STAR_PIECE)
        EVT_SET(LVar1, 3)
        EVT_EXEC_WAIT(N(Delivery_ShowGotStarPiece))
        EVT_CALL(AddStarPieces, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024473C_C922EC) = {
    EVT_IF_EQ(GF_KZN19_KoloradoDeadEnd, FALSE)
        EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 300)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 4)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0100)
        EVT_SET(GF_KZN19_KoloradoDeadEnd, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_LABEL(5)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_WAIT(30)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802448BC_C9246C) = {
    EVT_LABEL(0)
    EVT_IF_EQ(MV_Unk_0A, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(60)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 70, 25, 60)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 170, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 280, 70, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 0, MSG_CH5_0107)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 450, 25, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 450, 25, -20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(NpcMoveTo, NPC_SELF, 535, -60, 0)
    EVT_WAIT(20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 304, 25, -35)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAux, NPC_LavaPiranhaHead, 0)
    EVT_WAIT(10)
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_EXEC(N(D_80242164_C8FD14))
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244B1C_C926CC) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_0101)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_EXEC_WAIT(N(D_80244688_C92238))
    EVT_EXEC_WAIT(N(D_802446D8_C92288))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244B78_C92728) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(kzn_19_ENTRY_0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024473C_C922EC)))
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_80244B1C_C926CC)))
            EVT_CASE_EQ(kzn_19_ENTRY_1)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_802448BC_C9246C)))
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(D_80244C3C_C927EC)[] = {
    {  250.0,    40.0,  -35.0 },
    {  410.0,    30.0,    0.0 },
    {  460.0,    40.0,  -30.0 },
    {  510.0,    50.0,  -72.0 },
    {  540.0,    60.0, -115.0 },
};

EvtScript N(EVS_80244C78) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerPos, 185, 25, -35)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 155, 25, -35)
    EVT_CALL(SetNpcPos, NPC_Misstar, 250, 40, -35)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 217, 25, -35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 217, 25, -35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 380)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_SET(AF_KZN_08, TRUE)
    EVT_CALL(PlaySound, SOUND_8000006B)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(AF_KZN_08, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_CH5_0109)
    EVT_WAIT(10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 370, 25, 70)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Misstar, 90, 0)
    EVT_CALL(LoadPath, 45, EVT_PTR(N(D_80244C3C_C927EC)), 5, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Misstar, 0, -1000, 0)
    EVT_WAIT(15)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_SET(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245010_C92BC0) = {
    EVT_THREAD
        EVT_CALL(func_80241BC0_C8F770, 0, 15)
        EVT_CALL(PlayModelAnimation, 0, 0x80200000)
        EVT_CALL(SetAnimatedModelRootPosition, 0, 220, 20, -40)
        EVT_CALL(func_80241BC0_C8F770, 3, 36)
        EVT_CALL(PlayModelAnimation, 3, 0x8020A000)
        EVT_CALL(SetAnimatedModelRootPosition, 3, 220, 20, -40)
        EVT_WAIT(59)
        EVT_CALL(func_80241BC0_C8F770, 0, 0)
        EVT_CALL(PlayModelAnimation, 0, 0x80200000)
        EVT_CALL(func_80241BC0_C8F770, 3, 34)
        EVT_CALL(PlayModelAnimation, 3, 0x8020A000)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(func_80241BC0_C8F770, 1, 32)
        EVT_CALL(PlayModelAnimation, 1, 0x80204000)
        EVT_CALL(SetAnimatedModelRootPosition, 1, 220, 20, -40)
        EVT_WAIT(59)
        EVT_CALL(func_80241BC0_C8F770, 1, 31)
        EVT_CALL(PlayModelAnimation, 1, 0x80204000)
    EVT_END_THREAD
    EVT_WAIT(7)
    EVT_CALL(func_80241BC0_C8F770, 2, 32)
    EVT_CALL(PlayModelAnimation, 2, 0x80207000)
    EVT_CALL(SetAnimatedModelRootPosition, 2, 270, 34, -20)
    EVT_WAIT(62)
    EVT_CALL(func_80241BC0_C8F770, 2, 31)
    EVT_CALL(PlayModelAnimation, 2, 0x80207000)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024522C_C92DDC) = {
    EVT_CALL(func_80241BC0_C8F770, 0, 0)
    EVT_CALL(PlayModelAnimation, 0, 0x80200000)
    EVT_CALL(func_80241BC0_C8F770, 1, 31)
    EVT_CALL(PlayModelAnimation, 1, 0x80204000)
    EVT_CALL(func_80241BC0_C8F770, 3, 34)
    EVT_CALL(PlayModelAnimation, 3, 0x8020A000)
    EVT_WAIT(10)
    EVT_CALL(func_80241BC0_C8F770, 2, 31)
    EVT_CALL(PlayModelAnimation, 2, 0x80207000)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802452E8_C92E98) = {
    EVT_CALL(func_80241BC0_C8F770, 0, 17)
    EVT_CALL(PlayModelAnimation, 0, 0x80200000)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245320_C92ED0) = {
    EVT_CALL(func_80241BC0_C8F770, 0, 16)
    EVT_CALL(PlayModelAnimation, 0, 0x80200000)
    EVT_CALL(func_80241BC0_C8F770, 1, 33)
    EVT_CALL(PlayModelAnimation, 1, 0x80204000)
    EVT_CALL(func_80241BC0_C8F770, 2, 33)
    EVT_CALL(PlayModelAnimation, 2, 0x80207000)
    EVT_CALL(func_80241BC0_C8F770, 3, 35)
    EVT_CALL(PlayModelAnimation, 3, 0x8020A000)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802453D0_C92F80) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_GT(LVar0, 150)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_LAVA_PIRANHA_THEME, 0, 8)
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(N(D_802431F8_C90DA8)))
    EVT_CALL(func_80241BC0_C8F770, 0, 0)
    EVT_CALL(PlayModelAnimation, 0, 0x80200000)
    EVT_CALL(SetAnimatedModelRootPosition, 0, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, 0, 128, 1)
    EVT_CALL(LoadAnimatedModel, 1, EVT_PTR(N(D_80243388_C90F38)))
    EVT_CALL(func_80241BC0_C8F770, 1, 31)
    EVT_CALL(PlayModelAnimation, 1, 0x80204000)
    EVT_CALL(SetAnimatedModelRootPosition, 1, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, 1, 128, 1)
    EVT_CALL(LoadAnimatedModel, 2, EVT_PTR(N(D_80243388_C90F38)))
    EVT_CALL(func_80241BC0_C8F770, 2, 31)
    EVT_CALL(PlayModelAnimation, 2, 0x80207000)
    EVT_CALL(SetAnimatedModelRootPosition, 2, 270, -100, -20)
    EVT_CALL(SetAnimatorFlags, 2, 128, 1)
    EVT_CALL(LoadAnimatedModel, 3, EVT_PTR(N(D_802434B8_C91068)))
    EVT_CALL(func_80241BC0_C8F770, 3, 34)
    EVT_CALL(PlayModelAnimation, 3, 0x8020A000)
    EVT_CALL(SetAnimatedModelRootPosition, 3, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, 3, 128, 1)
    EVT_CALL(func_8024140C_C8EFBC)
    EVT_CALL(SetSelfVar, 1, 1)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 300, 25, -20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 25, -20)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 40, 80, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_poko, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(InterruptUsePartner)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 200, -30, 0)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_3C5, 0, 330, 25, -50)
    EVT_EXEC(N(D_80245010_C92BC0))
    EVT_WAIT(59)
    EVT_THREAD
        EVT_CALL(MakeLerp, 40, 0, 80, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_poko, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 235, 25, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 235, 25, -20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(420.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-10.7))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC(N(D_802452E8_C92E98))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0102)
    EVT_EXEC(N(D_8024522C_C92DDC))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 256, -30, 30)
    EVT_EXEC(N(D_802452E8_C92E98))
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0103)
    EVT_EXEC(N(D_8024522C_C92DDC))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_EXEC(N(D_802452E8_C92E98))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_EXEC(N(D_8024522C_C92DDC))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 20)
        EVT_LOOP(3)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar0, 2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(440.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar0, 2)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_LAVA_PIRANHA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245BDC_C9378C) = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_LavaPiranhaHead, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_LavaPiranhaHead, LVar0, 0, LVar2)
    EVT_CALL(func_802413FC_C8EFAC)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 10, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 90)
    EVT_CALL(func_80240CD8_C8E888, 0, 0, LVar0, 0, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 0, 1, 1, 1)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 1, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 9, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 9, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 5, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 6, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 7, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 0, 8, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_LavaBud_01, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_LavaBud_01, LVar0, 0, LVar2)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 1, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 8, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 90)
    EVT_CALL(func_80240CD8_C8E888, 1, 0, LVar0, 0, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 0, 1, 1, 1)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 4, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
    EVT_CALL(func_80240BD4_C8E784, 1, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 1, 1, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 1, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 1, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 5, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 1, 6, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_LavaBud_02, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_LavaBud_02, LVar0, 0, LVar2)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 2, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 8, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 90)
    EVT_CALL(func_80240CD8_C8E888, 2, 0, LVar0, 0, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 0, 1, 1, 1)
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 4, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
    EVT_CALL(func_80240BD4_C8E784, 2, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 2, 1, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 7, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 2, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 2, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 5, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 2, 6, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 3, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 3, 0, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 3, 0, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 3, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 3, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 3, 6, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 3, 1, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 3, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 3, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 3, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 3, 5, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 3, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, 3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240BD4_C8E784, 3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, 3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240CD8_C8E888, 3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(func_80240DA4_C8E954, 3, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246FC8_C94B78) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetEncounterStatusFlags, 2, TRUE)
            EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
            EVT_CALL(SetPlayerPos, 125, 25, -35)
            EVT_CALL(SetNpcPos, NPC_PARTNER, 100, 25, -35)
            EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 125, 25, -35)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 205, 25, -35)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 470)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-8.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(EnableGroup, MODEL_ato, TRUE)
            EVT_CALL(EnableGroup, MODEL_naka, TRUE)
            EVT_CALL(EnableGroup, MODEL_mae, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, 0, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(PlaySoundAt, SOUND_3C6, 0, 330, 25, -50)
            EVT_EXEC(N(D_80245320_C92ED0))
            EVT_WAIT(1)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(D_80245BDC_C9378C)))
            EVT_SET(MV_Unk_0A, 1)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802471F0_C94DA0) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kzn_19_ENTRY_1)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(SetNpcAnimation, NPC_LavaPiranhaHead, ANIM_LavaPiranha_Anim03)
            EVT_CALL(SetNpcAnimation, NPC_LavaBud_01, ANIM_LavaBud_Anim03)
            EVT_CALL(SetNpcAnimation, NPC_LavaBud_02, ANIM_LavaBud_Anim03)
            EVT_MALLOC_ARRAY(64, LVar0)
            EVT_CALL(SetSelfVar, 0, LVar0)
            EVT_USE_ARRAY(LVar0)
            EVT_CALL(SetSelfVar, 1, 0)
            EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(D_80245BDC_C9378C)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_802453D0_C92F80)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(D_80246FC8_C94B78)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_05, 0, -1000, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024733C_C94EEC) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247394_C94F44) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(D_8024733C_C94EEC)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(D_802473F4_C94FA4) = {
    .id = NPC_Kolorado,
    .settings = &N(NpcSettings_Kolorado),
    .pos = { 380.0f, 250.0f, -330.0f },
    .yaw = 90,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR | NPC_FLAG_400000,
    .init = &N(D_80244B78_C92728),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
    .tattle = MSG_NpcTattle_Kolorado,
};

StaticNpc N(D_802475E4_C95194) = {
    .id = NPC_Misstar,
    .settings = &N(NpcSettings_Misstar),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .yaw = 270,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_400000,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldMisstar_Idle,
        .walk   = ANIM_WorldMisstar_Idle,
        .run    = ANIM_WorldMisstar_Idle,
        .chase  = ANIM_WorldMisstar_Idle,
        .anim_4 = ANIM_WorldMisstar_Idle,
        .anim_5 = ANIM_WorldMisstar_Idle,
        .death  = ANIM_WorldMisstar_Idle,
        .hit    = ANIM_WorldMisstar_Idle,
        .anim_8 = ANIM_WorldMisstar_Still,
        .anim_9 = ANIM_WorldMisstar_Idle,
        .anim_A = ANIM_WorldMisstar_Idle,
        .anim_B = ANIM_WorldMisstar_Idle,
        .anim_C = ANIM_WorldMisstar_Idle,
        .anim_D = ANIM_WorldMisstar_Idle,
        .anim_E = ANIM_WorldMisstar_Idle,
        .anim_F = ANIM_WorldMisstar_Idle,
    },
    .tattle = MSG_NpcTattle_Misstar,
};

s32 N(D_802477D4_C95384)[] = {
    ANIM_LavaPiranha_Anim03,
    ANIM_LavaPiranha_Anim0E,
    -1
};

s32 N(D_802477E0_C95390)[] = {
    ANIM_LavaBud_Anim03,
    -1
};

StaticNpc N(D_802477E8_C95398)[] = {
    {
        .id = NPC_LavaPiranhaHead,
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .flags = NPC_FLAG_4 | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(D_802471F0_C94DA0),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_LavaPiranha_Anim03,
            .walk   = ANIM_LavaPiranha_Anim03,
            .run    = ANIM_LavaPiranha_Anim03,
            .chase  = ANIM_LavaPiranha_Anim03,
            .anim_4 = ANIM_LavaPiranha_Anim03,
            .anim_5 = ANIM_LavaPiranha_Anim03,
            .death  = ANIM_LavaPiranha_Anim03,
            .hit    = ANIM_LavaPiranha_Anim03,
            .anim_8 = ANIM_LavaPiranha_Anim03,
            .anim_9 = ANIM_LavaPiranha_Anim03,
            .anim_A = ANIM_LavaPiranha_Anim03,
            .anim_B = ANIM_LavaPiranha_Anim03,
            .anim_C = ANIM_LavaPiranha_Anim03,
            .anim_D = ANIM_LavaPiranha_Anim03,
            .anim_E = ANIM_LavaPiranha_Anim03,
            .anim_F = ANIM_LavaPiranha_Anim03,
        },
        .extraAnimations = N(D_802477D4_C95384),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_01,
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_40000,
        .init = &N(D_80247394_C94F44),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_LavaBud_Anim03,
            .walk   = ANIM_LavaBud_Anim03,
            .run    = ANIM_LavaBud_Anim03,
            .chase  = ANIM_LavaBud_Anim03,
            .anim_4 = ANIM_LavaBud_Anim03,
            .anim_5 = ANIM_LavaBud_Anim03,
            .death  = ANIM_LavaBud_Anim03,
            .hit    = ANIM_LavaBud_Anim03,
            .anim_8 = ANIM_LavaBud_Anim03,
            .anim_9 = ANIM_LavaBud_Anim03,
            .anim_A = ANIM_LavaBud_Anim03,
            .anim_B = ANIM_LavaBud_Anim03,
            .anim_C = ANIM_LavaBud_Anim03,
            .anim_D = ANIM_LavaBud_Anim03,
            .anim_E = ANIM_LavaBud_Anim03,
            .anim_F = ANIM_LavaBud_Anim03,
        },
        .extraAnimations = N(D_802477E0_C95390),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_02,
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_40000,
        .init = &N(D_80247394_C94F44),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_LavaBud_Anim03,
            .walk   = ANIM_LavaBud_Anim03,
            .run    = ANIM_LavaBud_Anim03,
            .chase  = ANIM_LavaBud_Anim03,
            .anim_4 = ANIM_LavaBud_Anim03,
            .anim_5 = ANIM_LavaBud_Anim03,
            .death  = ANIM_LavaBud_Anim03,
            .hit    = ANIM_LavaBud_Anim03,
            .anim_8 = ANIM_LavaBud_Anim03,
            .anim_9 = ANIM_LavaBud_Anim03,
            .anim_A = ANIM_LavaBud_Anim03,
            .anim_B = ANIM_LavaBud_Anim03,
            .anim_C = ANIM_LavaBud_Anim03,
            .anim_D = ANIM_LavaBud_Anim03,
            .anim_E = ANIM_LavaBud_Anim03,
            .anim_F = ANIM_LavaBud_Anim03,
        },
        .extraAnimations = N(D_802477E0_C95390),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
};

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(D_802473F4_C94FA4)),
    NPC_GROUP(N(D_802477E8_C95398), BTL_KZN2_FORMATION_00, BTL_KZN2_STAGE_06),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(D_802475E4_C95194)),
    {}
};
