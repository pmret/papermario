#include "jan_04.h"

BSS PAL_BIN N(palette)[256];
BSS IMG_BIN N(raster)[0x3D90]; // similar to LoadPartyImage include but with D_8024A290 in the middle randomly
BSS Evt* D_8024A290;
BSS char D_8024A294[0xC]; // padding?
BSS MessageImageData N(image);

API_CALLABLE(N(LoadPartyImage)) {
    u32 decompressedSize;
    void* compressed = load_asset_by_name("party_opuku", &decompressedSize);

    decode_yay0(compressed, &N(palette));
    general_heap_free(compressed);

    N(image).raster = N(raster);
    N(image).palette = N(palette);
    N(image).width = 150;
    N(image).height = 105;
    N(image).format = G_IM_FMT_CI;
    N(image).bitDepth = G_IM_SIZ_8b;
    set_message_images(&N(image));
    return ApiStatus_DONE2;
}

Vec3f N(YoshiKidsRunPath)[] = {
    { -350.0,     0.0,   15.0 },
    { -220.0,    25.0,   15.0 },
    { -110.0,     0.0,   30.0 },
    {  -50.0,     0.0,  130.0 },
    {   50.0,     0.0,  110.0 },
    {  160.0,    25.0,  160.0 },
    {  255.0,     0.0,  285.0 },
};

EvtScript N(EVS_Scene_Epilogue) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetNpcPos, NPC_Sushie, -40, 0, 15)
    EVT_CALL(SetNpcYaw, NPC_Sushie, 270)
    EVT_CALL(SetNpcAnimation, NPC_Sushie, ANIM_WorldSushie_Read)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKid_04, ANIM_YoshiKid_Yellow_Sleep)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKid_02, ANIM_YoshiKid_Red_Sleep)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -20, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -20, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(90)
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_YoshiKid_01, -350, 0, 15)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKid_01, ANIM_YoshiKid_Green_Run)
        EVT_CALL(LoadPath, 90, EVT_PTR(N(YoshiKidsRunPath)), ARRAY_COUNT(N(YoshiKidsRunPath)), EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_YoshiKid_01, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetNpcPos, NPC_YoshiKid_05, -350, 0, 15)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKid_05, ANIM_YoshiKid_Purple_Run)
        EVT_CALL(LoadPath, 90, EVT_PTR(N(YoshiKidsRunPath)), ARRAY_COUNT(N(YoshiKidsRunPath)), EASING_LINEAR)
        EVT_LABEL(11)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_YoshiKid_05, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(11)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(InterpNpcYaw, NPC_Sushie, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Sushie, ANIM_WorldSushie_Talk)
    EVT_CALL(SetNpcJumpscale, NPC_Sushie, EVT_FLOAT(2.0))
    EVT_CALL(GetNpcPos, NPC_Sushie, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Sushie, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKid_01, ANIM_YoshiKid_Green_Talk)
    EVT_CALL(SetNpcFlagBits, NPC_YoshiKid_03, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcPos, NPC_YoshiKid_03, -350, 0, 15)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Run)
    EVT_CALL(SetNpcSpeed, NPC_YoshiKid_03, EVT_FLOAT(5.0))
    EVT_CALL(NpcMoveTo, NPC_YoshiKid_03, -100, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Idle)
    EVT_CHILD_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcJumpscale, NPC_YoshiKid_03, EVT_FLOAT(2.0))
        EVT_LOOP(10)
            EVT_CALL(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Jump)
            EVT_CALL(GetNpcPos, NPC_YoshiKid_03, LVar0, LVar1, LVar2)
            EVT_CALL(NpcJump0, NPC_YoshiKid_03, LVar0, LVar1, LVar2, 10)
            EVT_CALL(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Land)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(90)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), flo_00_ENTRY_B)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(2, epilogue);
