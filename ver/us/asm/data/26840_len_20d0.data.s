.include "macro.inc"

.section .data

dlabel D_80078190
.word 0xF8030125, 0x07D0FDBC, 0xF8860355, 0x06FCFBAB, 0xFEDAF82D, 0x0245077D, 0xFCA9F901, 0x0456065D, 0xFC33FBB2, 0xFCEFFE94, 0xFFD80080, 0x00A4007D, 0x090E0673, 0x02FF0053, 0xFEF2FEA7, 0xFEF9FF7B

dlabel D_800781D0
.word 0xB1011110, 0x00FFFE34, 0xBB90E21E, 0x00FB10EF, 0xF2D180C4, 0xB3B1D3CF, 0xD1FDFE80, 0x1D2D3D3B, 0x2C3BFC1D, 0x80DEF0D0, 0xD3D2B3D1, 0xF480A203, 0xD00DA9EA, 0xCB729041, 0x4E1D2D0C, 0x1E102F90, 0xF21203F0, 0xC2D1D4F3, 0x80B0A1BF, 0xD21E1270, 0x4D804C39, 0x2C7E306D, 0xB9CF90E1, 0xF2F3F2E1, 0xE21622C1, 0xE728F4F0, 0x211010FF, 0xA1ED9F2F, 0xF561333C, 0xD0A1DAC2, 0xFF144122, 0x2DEFA1FA, 0xE10E2330, 0x320EF091, 0x9AF2CF55, 0x1361EE1C, 0x919D0FD2, 0x52064DE1, 0x0991D01B, 0x152E36FD, 0x12CB8122, 0xBC65F073, 0xCE3FAE71, 0x4E9370F5, 0x6ED21BD1, 0x610A5D00, 0x00000000, 0x00000000

dlabel D_80078290
.word 0x00000003, 0x0000000B, 0x00000000, 0x00000009, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00000007, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, 0x00001388, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000

dlabel D_800782F8
.word 0x00000001, 0x0000000B, 0x00000000, 0x0000000A, 0x00004E20, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00007FFF

dlabel D_80078320
.word 0x00000001, 0x0000000D, 0x00000000, 0x0000000C, 0x00004E20, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00007FFF

dlabel D_80078348
.short 0x0000, 0x0001, 0x0000, 0x000E, 0x0000, 0x0000, 0x0000, 0x000D, 0x0000, 0x4E20, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x0000

dlabel D_8007836A
.short 0x0000, 0x0000, 0x7FFF, 0x034A, 0x0349, 0x0100, 0x0000

dlabel D_80078378
.word 0x01000000, 0x00080012, 0x3C7F2D7F, 0x2B5F1D00, 0xFF002700, 0xFF000000

dlabel D_80078390
.word 0x01000000, 0x0008001A, 0x3C7F237F, 0x3C3F2A1F, 0x2A0F2A07, 0x2A033600, 0xFF003600, 0xFF000000, 0x34337F26, 0x3F1600FF, 0x343B7F3B, 0x3FFF0000

dlabel D_800783C0
.word D_80078378, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390, D_80078390

dlabel D_80078400
.word snd_SEFCmd_00_SetVolume, snd_SEFCmd_01_SetPan, snd_SEFCmd_02_SetInstrument, snd_SEFCmd_03_SetReverb

dlabel D_80078410
.byte 0x80, 0x04, 0xCF, 0x3C, 0x80, 0x04, 0xD0, 0x0C, 0x80, 0x04, 0xD0, 0x38, 0x80, 0x04, 0xD0, 0x50, 0x80, 0x04, 0xD0, 0x7C, 0x80, 0x04, 0xD1, 0x14, 0x80, 0x04, 0xD1, 0x30, 0x80, 0x04, 0xD1, 0x5C, 0x80, 0x04, 0xD1, 0x80, 0x80, 0x04, 0xD1, 0xB4, 0x80, 0x04, 0xD2, 0x3C, 0x80, 0x04, 0xD2, 0xB0, 0x80, 0x04, 0xD2, 0xE4, 0x80, 0x04, 0xD3, 0x10, 0x80, 0x04, 0xD3, 0x1C, 0x80, 0x04, 0xD3, 0x24, 0x80, 0x04, 0xD3, 0x3C, 0x80, 0x04, 0xD3, 0x54, 0x80, 0x04, 0xD3, 0x6C, 0x80, 0x04, 0xD3, 0xA0, 0x80, 0x04, 0xD3, 0xF8

dlabel gBlankSEFData
.word 0x00000000, 0x00000000, 0x00000000

dlabel D_80078470
.word snd_BGMCmd_E0_MasterTempo, snd_BGMCmd_E1_MasterVolume, snd_BGMCmd_E2_MasterTranspose, snd_BGMCmd_E3, snd_BGMCmd_E4_MasterTempoFade, snd_BGMCmd_E5_MasterVolumeFade, snd_BGMCmd_E6_MasterEffect, snd_BGMCmd_NOP, snd_BGMCmd_E8_TrackOverridePatch, snd_BGMCmd_E9_SubTrackVolume, snd_BGMCmd_EA_SubTrackPan, snd_BGMCmd_EB_SubTrackReverb, snd_BGMCmd_EC_SegTrackVolume, snd_BGMCmd_ED_SubTrackCoarseTune, snd_BGMCmd_EE_SubTrackFineTune, snd_BGMCmd_EF_SegTrackTune, snd_BGMCmd_F0_TrackTremolo, snd_BGMCmd_F1_TrackTremoloSpeed, snd_BGMCmd_F2_TrackTremoloTime, snd_BGMCmd_F3_TrackTremoloStop, snd_BGMCmd_F4, snd_BGMCmd_F5_TrackVoice, snd_BGMCmd_F6_TrackVolumeFade, snd_BGMCmd_F7_SubTrackReverbType, snd_BGMCmd_NOP, snd_BGMCmd_NOP, snd_BGMCmd_NOP, snd_BGMCmd_NOP, snd_BGMCmd_FC_Jump, snd_BGMCmd_FD, snd_BGMCmd_FE, snd_BGMCmd_FF, 0x02010101, 0x04030200, 0x02010101, 0x01010102, 0x03010100, 0x02010301, 0x00000000, 0x03030303

dlabel D_80078510
.byte 0x30, 0x18, 0x20, 0x28, 0x30, 0x38, 0x40, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

dlabel D_80078520
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80078530
.short 0x0000, 0x0200, 0x0800, 0x1200, 0x2000, 0x3200, 0x4800, 0x6200, 0x8000, 0x0000

dlabel D_80078544
.word 0x01000000, 0x0008000C

dlabel D_8007854C
.word 0x3D7FFF00, 0x3400FF00

dlabel D_80078554
.word 0x5C00FF00

dlabel D_80078558
.byte 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x58, 0x56, 0x53, 0x51, 0x4F, 0x4A, 0x45, 0x40, 0x3B, 0x37, 0x35, 0x33, 0x31, 0x2F, 0x2D, 0x2B, 0x29, 0x27, 0x26, 0x25, 0x23, 0x21, 0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14

dlabel D_80078580
.byte 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

dlabel D_800785A0
.word 0x0393756C, 0x034736DE, 0x02FAE1DA, 0x02AEA34C, 0x02624E48, 0x0215F944, 0x01C9BAB6, 0x01A39034, 0x017D65B2, 0x015751A6, 0x01312724, 0x0121E2F0, 0x01129EBC, 0x01035A88, 0x00F41654, 0x00E4D220, 0x00D58DEC, 0x00C649B8, 0x00B70584, 0x00A7D7C6, 0x00989392, 0x00894F5E, 0x007A0B2A, 0x006AC6F6, 0x005B82C2, 0x004C3E8E, 0x00449C74, 0x003CFA5A, 0x00355840, 0x002DB626, 0x0029F054, 0x0026140C, 0x00224E3A, 0x001E71F2, 0x001CF41C, 0x001B7646, 0x0019E1FA, 0x00186424, 0x0016CFD8, 0x00155202, 0x0013D42C, 0x00123FE0, 0x0010C20A, 0x000F2DBE, 0x000E7A0E, 0x000DAFE8, 0x000CE5C2, 0x000C3212, 0x000B67EC, 0x000A9DC6, 0x0009EA16, 0x00091FF0, 0x000855CA, 0x00078BA4, 0x0006D7F4, 0x00060DCE, 0x0005B3F6, 0x000543A8, 0x0004E9D0, 0x00048FF8, 0x0004630C, 0x00043620, 0x00040934, 0x0003F2BE, 0x0003C5D2, 0x000398E6, 0x00038270, 0x00035584, 0x00032898, 0x0002FBAC, 0x0002E536, 0x0002B84A, 0x00028B5E, 0x00025E72, 0x000247FC, 0x00021B10, 0x0001EE24, 0x0001C138, 0x0001AAC2, 0x00017DD6, 0x00016760, 0x00013A74, 0x00010D88, 0x0000F712, 0x0000E09C, 0x0000CA26, 0x0000B3B0, 0x00009D3A, 0x000086C4, 0x0000704E, 0x000059D8, 0x00004362, 0x00002CEC, 0x00001676, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80078730
.word 0x3F800000, 0x3F8012EF, 0x3F8025E1, 0x3F8038D6, 0x3F804BCD, 0x3F805EC7, 0x3F8071C4, 0x3F8084C4, 0x3F8097C7, 0x3F80AACC, 0x3F80BDD4, 0x3F80D0DF, 0x3F80E3ED, 0x3F80F6FE, 0x3F810A12, 0x3F811D28, 0x3F813041, 0x3F81435D, 0x3F81567C, 0x3F81699E, 0x3F817CC2, 0x3F818FE9, 0x3F81A313, 0x3F81B640, 0x3F81C970, 0x3F81DCA3, 0x3F81EFD9, 0x3F820311, 0x3F82164C, 0x3F82298A, 0x3F823CCB, 0x3F82500F, 0x3F826356, 0x3F82769F, 0x3F8289EB, 0x3F829D3A, 0x3F82B08C, 0x3F82C3E1, 0x3F82D739, 0x3F82EA94, 0x3F82FDF1, 0x3F831151, 0x3F8324B4, 0x3F83381A, 0x3F834B83, 0x3F835EEF, 0x3F83725E, 0x3F8385D0, 0x3F839944, 0x3F83ACBB, 0x3F83C035, 0x3F83D3B2, 0x3F83E732, 0x3F83FAB5, 0x3F840E3B, 0x3F8421C4, 0x3F84354F, 0x3F8448DD, 0x3F845C6E, 0x3F847002, 0x3F848399, 0x3F849733, 0x3F84AAD0, 0x3F84BE70, 0x3F84D213, 0x3F84E5B9, 0x3F84F961, 0x3F850D0C, 0x3F8520BA, 0x3F85346B, 0x3F85481F, 0x3F855BD6, 0x3F856F90, 0x3F85834D, 0x3F85970D, 0x3F85AAD0, 0x3F85BE96, 0x3F85D25F, 0x3F85E62A, 0x3F85F9F8, 0x3F860DC9, 0x3F86219D, 0x3F863574, 0x3F86494E, 0x3F865D2B, 0x3F86710B, 0x3F8684EE, 0x3F8698D4, 0x3F86ACBD, 0x3F86C0A9, 0x3F86D498, 0x3F86E88A, 0x3F86FC7F, 0x3F871077, 0x3F872472, 0x3F87386F, 0x3F874C6F, 0x3F876072, 0x3F877478, 0x3F878881, 0x3F879C8D, 0x3F87B09C, 0x3F87C4AE, 0x3F87D8C3, 0x3F87ECDB, 0x3F8800F6, 0x3F881514, 0x3F882935, 0x3F883D59, 0x3F885180, 0x3F8865AA, 0x3F8879D7, 0x3F888E07, 0x3F88A23A, 0x3F88B670, 0x3F88CAA9, 0x3F88DEE5, 0x3F88F324, 0x3F890766, 0x3F891BAB, 0x3F892FF3, 0x3F89443E, 0x3F89588C, 0x3F896CDD, 0x3F898131, 0x3F899588, 0x3F89A9E2, 0x3F89BE3F, 0x3F800000, 0x3F89D29F, 0x3F946637, 0x3F9FC997, 0x3FAC0CB1, 0x3FB940B0, 0x3FC77811, 0x3FD6C6BB, 0x3FE7421D, 0x3FF9014B, 0x40060E8F, 0x4010582B, 0x401B6BE2, 0x40275936, 0x403430DA, 0x404204C9, 0x4050E860, 0x4060F077, 0x40723381, 0x408264D5, 0x408C667B, 0x40972CB6, 0x40A2C69C, 0x40AF446B, 0x40BCB7A0, 0x40CB3311, 0x40DACB04, 0x40EB954F, 0x40FDA974, 0x41089062, 0x41130B3F, 0x411E53FF, 0x3F800000, 0x3F7FDA28, 0x3F7FB456, 0x3F7F8E89, 0x3F7F68C2, 0x3F7F4300, 0x3F7F1D44, 0x3F7EF78E, 0x3F7ED1DD, 0x3F7EAC32, 0x3F7E868C, 0x3F7E60EC, 0x3F7E3B51, 0x3F7E15BC, 0x3F7DF02C, 0x3F7DCAA2, 0x3F7DA51E, 0x3F7D7F9F, 0x3F7D5A26, 0x3F7D34B2, 0x3F7D0F44, 0x3F7CE9DB, 0x3F7CC478, 0x3F7C9F1A, 0x3F7C79C2, 0x3F7C546F, 0x3F7C2F22, 0x3F7C09DA, 0x3F7BE498, 0x3F7BBF5B, 0x3F7B9A24, 0x3F7B74F2, 0x3F7B4FC6, 0x3F7B2A9F, 0x3F7B057E, 0x3F7AE062, 0x3F7ABB4C, 0x3F7A963B, 0x3F7A7130, 0x3F7A4C2A, 0x3F7A272A, 0x3F7A022F, 0x3F79DD3A, 0x3F79B84A, 0x3F799360, 0x3F796E7B, 0x3F79499C, 0x3F7924C2, 0x3F78FFED, 0x3F78DB1E, 0x3F78B654, 0x3F789190, 0x3F786CD1, 0x3F784818, 0x3F782364, 0x3F77FEB6, 0x3F77DA0D, 0x3F77B569, 0x3F7790CB, 0x3F776C32, 0x3F77479F, 0x3F772311, 0x3F76FE88, 0x3F76DA05, 0x3F76B587, 0x3F76910F, 0x3F766C9C, 0x3F76482E, 0x3F7623C6, 0x3F75FF63, 0x3F75DB06, 0x3F75B6AE, 0x3F75925B, 0x3F756E0E, 0x3F7549C6, 0x3F752583, 0x3F750146, 0x3F74DD0E, 0x3F74B8DB, 0x3F7494AE, 0x3F747086, 0x3F744C63, 0x3F742846, 0x3F74042E, 0x3F73E01C, 0x3F73BC0F, 0x3F739807, 0x3F737404, 0x3F735007, 0x3F732C0F, 0x3F73081C, 0x3F72E42F, 0x3F72C047, 0x3F729C64, 0x3F727887, 0x3F7254AF, 0x3F7230DC, 0x3F720D0F, 0x3F71E947, 0x3F71C584, 0x3F71A1C6, 0x3F717E0E, 0x3F715A5B, 0x3F7136AD, 0x3F711305, 0x3F70EF62, 0x3F70CBC4, 0x3F70A82B, 0x3F708498, 0x3F70610A, 0x3F703D81, 0x3F7019FD, 0x3F6FF67F, 0x3F6FD306, 0x3F6FAF92, 0x3F6F8C23, 0x3F6F68BA, 0x3F6F4556, 0x3F6F21F7, 0x3F6EFE9D, 0x3F6EDB49, 0x3F6EB7FA, 0x3F6E94B0, 0x3F6E716B, 0x3F6E4E2B, 0x3F6E2AF1, 0x3F6E07BC, 0x3F6DE48C, 0x3F800000, 0x3F6DC161, 0x3F5CCFA0, 0x3F4D1303, 0x3F3E7583, 0x3F30E2A9, 0x3F244774, 0x3F18923F, 0x3F0DB2A4, 0x3F03996B, 0x3EF470E1, 0x3EE30526, 0x3ED2D741, 0x3EC3D08B, 0x3EB5DBFB, 0x3EA8E607, 0x3E9CDC8A, 0x3E91AEA9, 0x3E874CBE, 0x3E7B5080, 0x3E69675D, 0x3E58C500, 0x3E495220, 0x3E3AF91B, 0x3E2DA5DB, 0x3E2145B8, 0x3E15C75E, 0x3E0B1AB6, 0x3E0130CE, 0x3DEFF78B, 0x3DDEDD71, 0x3DCEFB5A, 0x3DC03B0C, 0x3DB287E0, 0x3DA5CEA6, 0x3D99FD90, 0x3D8F0410, 0x3D84D2CB, 0x3D76B6F6, 0x3D6521C0, 0x3D54CD52, 0x3D45A2D5, 0x3D378D0A, 0x3D2A7839, 0x3D1E5213, 0x3D130992, 0x3D088EF0, 0x3CFDA6F5, 0x3CEB932C, 0x3CDAC934, 0x3CCB318C, 0x3CBCB65A, 0x3CAF435F, 0x3CA2C5C3, 0x3C972C06, 0x3C8C65F5, 0x3C826474, 0x3C7232F8, 0x3C60F025, 0x3C50E83A, 0x3C4204D2, 0x3C3430FF, 0x3C275980, 0x3C1B6C42, 0x3C10589D, 0x3C060F18, 0x3BF90275, 0x3BE7435B, 0x3BD6C80E, 0x3BC7797C, 0x3BB9422B, 0x3BAC0E26, 0x3B9FCB0C, 0x3B9467C1, 0x3B89D42A, 0x3B800183, 0x3B6DC413, 0x3B5CD229, 0x3B4D1572, 0x3B3E77CA, 0x3B30E4BA, 0x3B24494B, 0x3B18940B, 0x3B0DB45E, 0x3B039B00, 0x3AF473B0, 0x3AE307F8, 0x3AD2D9AC, 0x3AC3D2FE, 0x3AB5DE1E, 0x3AA8E7EB, 0x3A9CDE48, 0x3A91B06C, 0x3A874E3D, 0x3A7B5348, 0x3A696A67, 0x3A58C7AD, 0x3A495447, 0x3A3AFB69, 0x3A2DA799, 0x3A214763, 0x3A15C955, 0x3A0B1CA9, 0x3A01329B, 0x39EFFA23, 0x39DEDFF5, 0x39CEFD29, 0x39C03D9D, 0x39B28A81, 0x39A5D10A, 0x3999FFC6, 0x398F0541, 0x3984D410, 0x3976BADD, 0x39652533, 0x3954CEFA, 0x3945A566, 0x39379050, 0x392A7A3D, 0x391E5312, 0x39130AB4, 0x39089109, 0x38FDABE8, 0x38EB9814, 0x38DACBBE, 0x38CB316C, 0x38BCB903, 0x38AF47AC
