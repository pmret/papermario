.include "macro.inc"

.section .data

dlabel D_80241670_AC67E0
.word 0x3FC00000, 0x0000003C, 0x0000001E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001

dlabel D_802416A0_AC6810
.word 0x00000043, 0x00000002, DoBasicAI, D_80241670_AC67E0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802416C0_AC6830
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, D_802416A0_AC6810, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010, 0x00000000, 0x00170013, 0x00000000, 0x00000000, D_802416A0_AC6810, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

dlabel D_80241718_AC6888
.word 0x3FC00000, 0x0000001E, 0x0000001E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001

dlabel D_80241748_AC68B8
.word 0x00000043, 0x00000002, func_80240B94_AC5D04, D_80241718_AC6888, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241768_AC68D8
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, D_80241748_AC68B8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010, 0x00000000, 0x00170013, 0x00000000, 0x00000000, D_80241748_AC68B8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

dlabel D_802417C0_AC6930
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241818_AC6988
.word 0x00000000, 0x001A0017, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241844_AC69B4
.word 0x00000000, 0x00160019, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241870_AC69E0
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024189C_AC6A0C
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

dlabel D_802418C8_AC6A38
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x00930304, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000008, 0x00940005, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x0000003C, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x00930301, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000008, 0x00940001, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419CC_AC6B3C
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000009, 0x00CE0004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x008F0007, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x0000003C, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000009, 0x00CE0001, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x008F0002, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AD0_AC6C40
.word 0x00000008, 0x00000001, 0x0000001E, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000096, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000007, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000007, 0x00000008, 0x00000001, 0x00000014, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B68_AC6CD8
.word 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000096, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000007, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000007, 0x00000008, 0x00000001, 0x0000000F, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241BF4_AC6D64
.word 0x0000000A, 0x00000002, 0xF9718882, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000004, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, WaitForPlayerInputEnabled, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870304, 0x00870301, 0x00000010, 0x00000042, 0x00000024, 0x00000002, 0xF9718882, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241CB0_AC6E20
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00890004, 0x00890001, 0x00000000, 0x00000033, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241CE0_AC6E50
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00830204, 0x00830201, 0x00000010, 0x00000038, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D10_AC6E80
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00830104, 0x00830101, 0x00000010, 0x00000039, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D40_AC6EB0
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00830004, 0x00830001, 0x00000010, 0x0000003A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D70_AC6EE0
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00840004, 0x00840001, 0x00000010, 0x0000003B, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241DA0_AC6F10
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870004, 0x00870001, 0x00000010, 0x0000003C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241DD0_AC6F40
.word 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870304, 0x00870301, 0x00000010, 0x0000003D, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870304, 0x00870301, 0x00000010, 0x0000003E, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000003, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870304, 0x00870301, 0x00000010, 0x0000003F, 0x00000020, 0x00000000, 0x00000016, 0x00000001, 0x00000004, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870304, 0x00870301, 0x00000010, 0x00000040, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000006, 0x00870302, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFCE, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000032, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8280, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFE363C83, 0xFFFFFF0B, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000006, 0x00870301, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x000000B4, 0x00000005, 0x00000024, 0x00000002, 0xF9718881, 0x00000001, 0x00000047, 0x00000005, D_80241138_AC62A8, 0x00000100, 0x0000000A, 0x00000001, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870304, 0x00870301, 0x00000010, 0x00000041, 0x00000023, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242048_AC71B8
.word 0x00000043, 0x00000003, SetNpcAnimation, 0x00000008, 0x00940001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x00930301, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00930304, 0x00930301, 0x00000010, 0x00000034, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802420AC_AC721C
.word 0x00000043, 0x00000003, EnableNpcAI, 0x00000007, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000008, 0x00940001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x00930301, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00940005, 0x00940001, 0x00000010, 0x00000035, 0x00000043, 0x00000003, EnableNpcAI, 0x00000007, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242138_AC72A8
.word 0x00000043, 0x00000003, SetNpcAnimation, 0x00000009, 0x00CE0001, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x008F0002, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00CE0004, 0x00CE0001, 0x00000010, 0x00000036, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024219C_AC730C
.word 0x00000043, 0x00000003, EnableNpcAI, 0x00000009, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000009, 0x00CE0001, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x008F0002, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008F0007, 0x008F0002, 0x00000010, 0x00000037, 0x00000043, 0x00000003, EnableNpcAI, 0x00000009, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242228_AC7398
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241AD0_AC6C40, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241CB0_AC6E20, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242260_AC73D0
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241B68_AC6CD8, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241CE0_AC6E50, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242298_AC7408
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241D10_AC6E80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802422BC_AC742C
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241D40_AC6EB0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802422E0_AC7450
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241D70_AC6EE0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242304_AC7474
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241DA0_AC6F10, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242328_AC7498
.word 0x0000000A, 0x00000002, 0xF9718881, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFFFFFFCE, 0x00000000, 0xFFFFFF0B, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000005, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0x00000000, 0xFFFFFEFC, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241BF4_AC6D64, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241DD0_AC6F40, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423CC_AC753C
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802418C8_AC6A38, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242048_AC71B8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242404_AC7574
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_802420AC_AC721C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242428_AC7598
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802419CC_AC6B3C, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242138_AC72A8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242460_AC75D0
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_8024219C_AC730C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242484_AC75F4
.word 0x00000000, D_802417C0_AC6930, 0x00000000, 0x00000000, 0x43AF0000, 0x00000D09, D_80242228_AC7398, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00890001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802417C0_AC6930, 0x42C80000, 0x00000000, 0x432F0000, 0x00000D09, D_80242260_AC73D0, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830201, 0x00830202, 0x00830203, 0x00830203, 0x00830201, 0x00830201, 0x00830206, 0x00830206, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_802416C0_AC6830, 0x43480000, 0x00000000, 0x42DC0000, 0x00000D09, D_80242298_AC7408, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000000C8, 0x00000000, 0x0000006E, 0x00000046, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000C8, 0x00000000, 0x0000006E, 0x00000046, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830101, 0x00830102, 0x00830103, 0x00830103, 0x00830101, 0x00830101, 0x00830106, 0x00830106, 0x00830103, 0x00830103, 0x00830103, 0x00830103, 0x00830103, 0x00830103, 0x00830103, 0x00830103, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_80241768_AC68D8, 0xC37A0000, 0x00000000, 0x43610000, 0x00000D09, D_802422BC_AC742C, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0xFFFFFF06, 0x00000000, 0x000000E1, 0x0000012C, 0x00000000, 0xFFFFFFCE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0xFFFFFF06, 0x00000000, 0x000000E1, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830001, 0x00830002, 0x00830003, 0x00830003, 0x00830001, 0x00830001, 0x00830006, 0x00830006, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, D_802416C0_AC6830, 0xC32A0000, 0x00000000, 0x42C80000, 0x00000D09, D_802422E0_AC7450, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFF56, 0x00000000, 0x00000064, 0x00000046, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFF56, 0x00000000, 0x00000064, 0x00000046, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00840001, 0x00840002, 0x00840003, 0x00840003, 0x00840001, 0x00840001, 0x00840006, 0x00840006, 0x00840003, 0x00840003, 0x00840003, 0x00840003, 0x00840003, 0x00840003, 0x00840003, 0x00840003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, D_802417C0_AC6930, 0xC25C0000, 0x42C80000, 0xC3B40000, 0x00000D09, D_80242304_AC7474, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, D_802417C0_AC6930, 0x00000000, 0xC47A0000, 0x00000000, 0x00000D09, D_80242328_AC7498, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00870301, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000007, D_80241818_AC6988, 0x432A0000, 0x00000000, 0x43AC8000, 0x00400D01, D_802423CC_AC753C, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00930301, 0x00930302, 0x00930303, 0x00930303, 0x00930301, 0x00930301, 0x00930300, 0x00930300, 0x00930301, 0x00930301, 0x00930301, 0x00930301, 0x00930301, 0x00930301, 0x00930301, 0x00930301, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, D_80241844_AC69B4, 0x43480000, 0x00000000, 0x43A28000, 0x00400D01, D_80242404_AC7574, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00940001, 0x00940004, 0x00940004, 0x00940004, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00940001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000009, D_80241870_AC69E0, 0xC3160000, 0x00000000, 0x00000000, 0x00400C09, D_80242428_AC7598, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00CE0001, 0x00CE0002, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00CE0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, D_8024189C_AC6A0C, 0xC2F00000, 0x00000000, 0xC1700000, 0x00400909, D_80242460_AC75D0, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x008F0002, 0x008F0005, 0x008F0006, 0x008F0006, 0x008F0002, 0x008F0002, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x008F0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000B, D_80242484_AC75F4, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
