.include "macro.inc"

.section .data

dlabel EVS_UpdateBulletinKootFavor
.word 0x0000000B, 0x00000002, 0xF5DE02DC, 0x00000009, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xF8405CB3, 0x00000027, 0x00000002, 0xFE363C81, 0xF8405CB4, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000002, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xF8405CB3, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xF8405CB4, 0x00000001, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xF8405CB3, 0x00000027, 0x00000002, 0xFE363C80, 0xF8405CB4, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xF840622A, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802485E8_808E68
.word 0x00170000, 0x00180000, 0xFFFFFF80, 0x00170001, 0x00180001, 0xFFFFFF96, 0x00170002, 0x00180002, 0xFFFFFF9F, 0x00170003, 0x00180003, 0xFFFFFFB5, 0x00170004, 0x00180004, 0xFFFFFFBD, 0x00170005, 0x00180005, 0xFFFFFFC5, 0x00170006, 0x00180006, 0xFFFFFFCC, 0x00170007, 0x00180007, 0xFFFFFFD0, 0x00170008, 0x00180008, 0xFFFFFFDF, 0x00170009, 0x00180009, 0xFFFFFFF1, 0x0017000A, 0x0018000A, 0xFFFFFFF6, 0x0017000B, 0x0018000B, 0xFFFFFFFA, 0x0017000C, 0x0018000C, 0xFFFFFFFD, 0x0017000D, 0x0018000D, 0x00000002, 0x0017000E, 0x0018000E, 0x00000005, 0x0017000F, 0x0018000F, 0x0000000B, 0x00170010, 0x00180010, 0x00000018, 0x00170011, 0x00180011, 0x00000028, 0x00170012, 0x00180012, 0x0000002B, 0x00170013, 0x00180013, 0x00000032, 0x00170014, 0x00180014, 0x00000039, 0x00170015, 0x00180015, 0x0000003D, 0x00170016, 0x00180016, 0x0000003E, 0x00170017, 0x00180017, 0x00000057, 0x00170018, 0x00180018, 0x0000005C

dlabel D_80248714_808F94
.word 0x00170019, 0x00180019, 0x00000060

dlabel EVS_ReadBulletin_News
.word 0x00000043, 0x00000001, SelectBulletinMessages, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000001, GetBulletinMessages, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0xFE363C80, 0x000000A0, 0x00000028, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000046, 0x00000001, EVS_UpdateBulletinKootFavor, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel EVS_ReadBulletin_Gossip
.word 0x00000043, 0x00000001, SelectBulletinMessages, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000001, GetBulletinMessages, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0xFE363C81, 0x000000A0, 0x00000028, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000046, 0x00000001, EVS_UpdateBulletinKootFavor, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, EVS_ReadBulletin_News, 0x00000100, 0x00000010, 0x00000001, 0x00000000, 0x00000047, 0x00000005, EVS_ReadBulletin_Gossip, 0x00000100, 0x00000011, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80248860_8090E0
.word 0xC33E0000, 0xC3520000, 0x42C80000, 0x42F00000, 0x00000002, 0xFAA2B58A

dlabel D_80248878_8090F8
.word 0xC3160000, 0x43A50000, 0x42DC0000, 0x43020000, 0x00000008, 0xFAA2B58B

dlabel D_80248890_809110
.word 0x43850000, 0x43B90000, 0x43480000, 0x435C0000, 0x00000005, 0xFAA2B58C, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000043, 0x00000002, EnableMusicProximityMix, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B58E, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B58E, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000002, mac_01_MonitorMusicProximityTrigger, D_80248860_8090E0, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, mac_01_MonitorMusicProximityTrigger, D_80248878_8090F8, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, mac_01_MonitorMusicProximityTrigger, D_80248890_809110, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
