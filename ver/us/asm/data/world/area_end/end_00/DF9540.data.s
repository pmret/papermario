.include "macro.inc"

.section .data

glabel D_80242B40_DF9540
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80242B90_DF9590, D_80242B40_DF9540, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80242B90_DF9590
.word 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000023, 0x00000010, 0x00001000, 0x00000043, 0x00000006, SetCamViewport, 0x00000000, 0x0000000F, 0x0000001C, 0x00000122, 0x00000080, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, FadeOutMusic, 0x00000000, 0x000001F4, 0x00000043, 0x00000002, ClearAmbientSounds, 0x000000FA, 0x00000043, 0x00000002, EnableStatusMenu, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000044, 0x00000001, 0x80246B28, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80242C70_DF9670
.word 0x02070001, 0x020A0001, 0x03040001, 0x070D0001, 0x09040001, 0x0C040001, 0x0C0C0001, 0x0C140001, 0x0D030001, 0x0D040001, 0x0D0A0001, 0x0D140001, 0x0E0D0001, 0x0E110001, 0x11040001, 0x110F0001, 0x14020001, 0x140D0001, 0x140F0001, 0x14120001, 0x12020001, 0x12070001, 0x120F0001, 0x15040001, 0x16110001, 0x00000000

glabel D_80242CD8_DF96D8
.word 0x00020001, 0x00060001, 0x000E0001, 0x00030001, 0x00080001, 0x000A0001, 0x000D0001, 0x00130001, 0x00140001, 0x07000001, 0x07060001, 0x07080001, 0x08020001, 0x08040001, 0x08060001, 0x080A0001, 0x080D0001, 0x080E0001, 0x08130001, 0x08180001, 0x09080001, 0x0C0E0001, 0x0C080001, 0x0D060001, 0x0D080001, 0x0D0E0001, 0x0D130001, 0x12040001, 0x12080001, 0x13040001, 0x14020001, 0x14080001, 0x140A0001, 0x00000000

glabel D_80242D60_DF9760
.word 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000

glabel D_80242D70_DF9770
.word 0x00000000

glabel D_80242D74_DF9774
.word 0x002E0000, 0x000000A0, 0x000000AD, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000078, 0x00000000, 0x00000028, 0x00000000, 0x00000028, 0x00010000, 0x002E0001, 0x000000A0, 0x000000BF, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000050, 0x00000000, 0x00000028, 0x00000000, 0xFFFFFFFF, 0x00010000

glabel D_80242DE4_DF97E4
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000000EB, 0x00000000, 0x002E0009, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E000A, 0x000000A0, 0x000000AF, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E000B, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x0000024C, 0x00000000, 0x0000001E, 0x00000000, 0x00000292, 0x00010000, 0x002E000C, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x002E000D, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E000E, 0x000000A0, 0x000000AF, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E000F, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x00000584, 0x00000000, 0x0000001E, 0x00000000, 0x000005CA, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x002E0010, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0011, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0023, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000BE, 0x00000000, 0x0000001E, 0x00000001, 0x000000F6, 0x00010000, 0x002E0012, 0x000000A0, 0x000000A6, 0x00000000, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x000002F2, 0x00000000, 0x0000001E, 0x00000000, 0x00000338, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x002E0013, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0014, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0015, 0x000000A0, 0x000000AF, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0016, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0017, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0018, 0x000000A0, 0x000000AF, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x002E001F, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0029, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E002A, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E002B, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x0000017E, 0x00000000, 0x0000001E, 0x00000000, 0x000001C4, 0x00010000, 0x002E002C, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x0000017E, 0x00000000, 0x0000001E, 0x00000000, 0x000001C4, 0x00010000, 0x002E0024, 0x000000A0, 0x000000AA, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x000000B0, 0x00000000, 0x0000001E, 0x00000000, 0x000000F6, 0x00010000, 0x002E0022, 0x000000A0, 0x000000A6, 0x00000000, 0x00000004, 0x00000028, 0x00000002, 0x00000000, 0x0000017E, 0x00000000, 0x0000001E, 0x00000000, 0x000001C4, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000

glabel D_80243474_DF9E74
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000000EB, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E002D, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E002E, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000094, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E002F, 0x0000009F, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0030, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0031, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0032, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0033, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0034, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0035, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0036, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0037, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0038, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0039, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E003A, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E003B, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E003C, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E003E, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E003D, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E003F, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0040, 0x000000A0, 0x000000B6, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0041, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0042, 0x000000A0, 0x000000D0, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0043, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0044, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0045, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0046, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0047, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0048, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0049, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E004A, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E004B, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E004C, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E004D, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E004E, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0050, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E004F, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E006F, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0069, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0079, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E007A, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E007B, 0x000000A0, 0x000000B6, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E007C, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E007D, 0x000000A0, 0x000000D0, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E007E, 0x000000A0, 0x000000B6, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E007F, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0080, 0x000000A0, 0x000000D0, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0081, 0x000000A0, 0x000000B6, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0082, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0083, 0x000000A0, 0x000000D0, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0084, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0077, 0x000000A0, 0x000000BF, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000028, 0x00000000, 0x002E0067, 0x000000A0, 0x000000BA, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00010000, 0x002E0074, 0x000000A0, 0x000000CB, 0x00000001, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000096, 0x00000000, 0x0000001E, 0x00000001, 0x000000CE, 0x00010000, 0x002E0056, 0x000000A0, 0x000000B6, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0057, 0x000000A0, 0x000000C3, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00010000, 0x002E0058, 0x000000A0, 0x000000D0, 0x00000001, 0x00000000, 0x00000028, 0x00000001, 0x00000000, 0x00000088, 0x00000000, 0x0000001E, 0x00000000, 0x000000CE, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000001, func_80242558_DF8F58, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80242580_DF8F80, D_80242DE4_DF97E4, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80242580_DF8F80, D_80243474_DF9E74, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80242580_DF8F80, D_80242D74_DF9774, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
