.include "macro.inc"

.section .data

dlabel D_80240D10_900380
.word 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240FFC_90066C, D_80240D10_900380, 0x00000009, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80240DE0_900450
.short 0x0136, 0x0122, 0x010E, 0x00FA, 0x00E6, 0x00D2, 0x00BE, 0x00AA, 0x0096, 0x0082, 0x006E, 0x005A, 0x0046, 0x0032, 0x0020, 0x0010, 0x0008, 0x0004, 0x0002, 0x0001

dlabel D_80240E08_900478
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80240010_8FF680, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000043, 0x00000001, func_80240208_8FF878, 0x00000043, 0x00000003, FadeOutMusic, 0x00000000, 0x000007D0, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GotoMapSpecial, 0x802483A0, 0x00000000, 0x00000006, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248398, 0x00000000, 0x00000006, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248390, 0x00000000, 0x00000006, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248388, 0x00000001, 0x00000006, 0x00000016, 0x00000001, 0x00000004, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248380, 0x00000004, 0x00000006, 0x00000016, 0x00000001, 0x00000005, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248378, 0x00000000, 0x00000006, 0x00000016, 0x00000001, 0x00000006, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248370, 0x00000000, 0x00000006, 0x00000016, 0x00000001, 0x00000007, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248368, 0x00000002, 0x00000006, 0x00000016, 0x00000001, 0x00000008, 0x00000043, 0x00000004, GotoMapSpecial, 0x80248360, 0x00000001, 0x00000006, 0x00000023, 0x00000000, 0x00000043, 0x00000001, func_802401E0_8FF850, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240FFC_90066C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, SetPlayerPos, 0xFFFFFF38, 0x00000000, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, SetPlayerPos, 0xFFFFFFA1, 0x00000000, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00200000, 0x00000001, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010006, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000200, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x000000D0, 0x000000D0, 0x000000D0, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetCamType, 0x00000000, 0x00000004, 0x00000000, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000001B8, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0x00000000, 0x00000064, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetCamPosC, 0x00000000, 0x00000000, 0x00000041, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x8024829C, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802482B4, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802482CC, 0x00000016, 0x00000001, 0x00000004, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802482E4, 0x00000016, 0x00000001, 0x00000005, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802482FC, 0x00000016, 0x00000001, 0x00000006, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80248314, 0x00000016, 0x00000001, 0x00000007, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x8024832C, 0x00000016, 0x00000001, 0x00000008, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80248344, 0x00000023, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000044, 0x00000001, D_80240E08_900478, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000041, 0x00000000, 0x00000008, 0x00000043, 0x00000002, ClearAmbientSounds, 0x000000FA, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
