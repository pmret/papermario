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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(SetNpcPos, NPC_Sushie, -40, 0, 15)
    Call(SetNpcYaw, NPC_Sushie, 270)
    Call(SetNpcAnimation, NPC_Sushie, ANIM_WorldSushie_Read)
    Call(SetNpcAnimation, NPC_YoshiKid_04, ANIM_YoshiKid_Yellow_Sleep)
    Call(SetNpcAnimation, NPC_YoshiKid_02, ANIM_YoshiKid_Red_Sleep)
    Call(UseSettingsFrom, CAM_DEFAULT, -20, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -20, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(90)
    Thread
        Call(SetNpcPos, NPC_YoshiKid_01, -350, 0, 15)
        Call(SetNpcAnimation, NPC_YoshiKid_01, ANIM_YoshiKid_Green_Run)
        Call(LoadPath, 90, Ref(N(YoshiKidsRunPath)), ARRAY_COUNT(N(YoshiKidsRunPath)), EASING_LINEAR)
        Label(10)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_YoshiKid_01, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(10)
        EndIf
    EndThread
    Thread
        Wait(15)
        Call(SetNpcPos, NPC_YoshiKid_05, -350, 0, 15)
        Call(SetNpcAnimation, NPC_YoshiKid_05, ANIM_YoshiKid_Purple_Run)
        Call(LoadPath, 90, Ref(N(YoshiKidsRunPath)), ARRAY_COUNT(N(YoshiKidsRunPath)), EASING_LINEAR)
        Label(11)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_YoshiKid_05, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(11)
        EndIf
    EndThread
    Wait(60)
    Call(InterpNpcYaw, NPC_Sushie, 90, 0)
    Call(SetNpcAnimation, NPC_Sushie, ANIM_WorldSushie_Talk)
    Call(SetNpcJumpscale, NPC_Sushie, Float(2.0))
    Call(GetNpcPos, NPC_Sushie, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Sushie, LVar0, LVar1, LVar2, 10)
    Call(SetNpcAnimation, NPC_YoshiKid_01, ANIM_YoshiKid_Green_Talk)
    Call(SetNpcFlagBits, NPC_YoshiKid_03, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcPos, NPC_YoshiKid_03, -350, 0, 15)
    Call(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Run)
    Call(SetNpcSpeed, NPC_YoshiKid_03, Float(5.0))
    Call(NpcMoveTo, NPC_YoshiKid_03, -100, 0, 0)
    Call(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Idle)
    ChildThread
        Wait(20)
        Call(SetNpcJumpscale, NPC_YoshiKid_03, Float(2.0))
        Loop(10)
            Call(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Jump)
            Call(GetNpcPos, NPC_YoshiKid_03, LVar0, LVar1, LVar2)
            Call(NpcJump0, NPC_YoshiKid_03, LVar0, LVar1, LVar2, 10)
            Call(SetNpcAnimation, NPC_YoshiKid_03, ANIM_YoshiKid_Blue_Land)
            Wait(8)
        EndLoop
    EndChildThread
    Wait(90)
    Call(FadeOutMusic, 0, 1000)
    Call(GotoMap, Ref("flo_00"), flo_00_ENTRY_B)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(2, epilogue);
