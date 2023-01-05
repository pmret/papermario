StaticAnimatorNode N(D_80251A80_C0F300) = {
    .pos = { 225.0f, 255.0f, 0.0f },
};

StaticAnimatorNode N(D_80251AAC_C0F32C) = {
    .displayList = N(D_8024C098_C09918),
    .pos = { 0.0f, -500.0f, 0.0f },
};

StaticAnimatorNode N(D_80251AD8_C0F358) = {
    .displayList = N(D_8024C030_C098B0),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251AAC_C0F32C),
};

StaticAnimatorNode N(D_80251B04_C0F384) = {
    .displayList = N(D_8024BFC8_C09848),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251AD8_C0F358),
};

StaticAnimatorNode N(D_80251B30_C0F3B0) = {
    .displayList = N(D_8024C2E0_C09B60),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251B04_C0F384),
};

StaticAnimatorNode N(D_80251B5C_C0F3DC) = {
    .displayList = N(D_8024C1F0_C09A70),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251B30_C0F3B0),
};

StaticAnimatorNode N(D_80251B88_C0F408) = {
    .displayList = N(D_8024C100_C09980),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251B5C_C0F3DC),
};

StaticAnimatorNode N(D_80251BB4_C0F434) = {
    .child = &N(D_80251B88_C0F408),
};

StaticAnimatorNode N(D_80251BE0_C0F460) = {
    .displayList = N(D_8024C560_C09DE0),
    .pos = { 0.0f, -500.0f, 0.0f },
};

StaticAnimatorNode N(D_80251C0C_C0F48C) = {
    .displayList = N(D_8024C4C0_C09D40),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251BE0_C0F460),
};

StaticAnimatorNode N(D_80251C38_C0F4B8) = {
    .displayList = N(D_8024C420_C09CA0),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80251C0C_C0F48C),
};

StaticAnimatorNode N(D_80251C64_C0F4E4) = {
    .sibling = &N(D_80251BB4_C0F434),
    .child = &N(D_80251C38_C0F4B8),
};

StaticAnimatorNode N(D_80251C90_C0F510) = {
    .displayList = N(D_8024B770_C08FF0),
};

StaticAnimatorNode N(D_80251CBC_C0F53C) = {
    .displayList = N(D_8024B8F8_C09178),
    .sibling = &N(D_80251C90_C0F510),
};

StaticAnimatorNode N(D_80251CE8_C0F568) = {
    .displayList = N(D_8024BAA0_C09320),
    .sibling = &N(D_80251CBC_C0F53C),
};

StaticAnimatorNode N(D_80251D14_C0F594) = {
    .displayList = N(D_802515B0_C0EE30),
    .sibling = &N(D_80251CE8_C0F568),
};

StaticAnimatorNode N(D_80251D40_C0F5C0) = {
    .displayList = N(D_80250168_C0D9E8),
    .sibling = &N(D_80251D14_C0F594),
};

StaticAnimatorNode N(D_80251D6C_C0F5EC) = {
    .displayList = N(D_80250108_C0D988),
    .sibling = &N(D_80251D40_C0F5C0),
};

StaticAnimatorNode N(D_80251D98_C0F618) = {
    .displayList = N(D_80251798_C0F018),
    .sibling = &N(D_80251D6C_C0F5EC),
};

StaticAnimatorNode N(D_80251DC4_C0F644) = {
    .displayList = N(D_80250360_C0DBE0),
    .sibling = &N(D_80251D98_C0F618),
};

StaticAnimatorNode N(D_80251DF0_C0F670) = {
    .displayList = N(D_80251710_C0EF90),
    .sibling = &N(D_80251DC4_C0F644),
};

StaticAnimatorNode N(D_80251E1C_C0F69C) = {
    .displayList = N(D_802502F8_C0DB78),
    .sibling = &N(D_80251DF0_C0F670),
};

StaticAnimatorNode N(D_80251E48_C0F6C8) = {
    .displayList = N(D_802516A8_C0EF28),
    .sibling = &N(D_80251E1C_C0F69C),
};

StaticAnimatorNode N(D_80251E74_C0F6F4) = {
    .displayList = N(D_80250290_C0DB10),
    .sibling = &N(D_80251E48_C0F6C8),
};

StaticAnimatorNode N(D_80251EA0_C0F720) = {
    .displayList = N(D_80251638_C0EEB8),
    .sibling = &N(D_80251E74_C0F6F4),
};

StaticAnimatorNode N(D_80251ECC_C0F74C) = {
    .displayList = N(D_80250220_C0DAA0),
    .sibling = &N(D_80251EA0_C0F720),
};

StaticAnimatorNode N(D_80251EF8_C0F778) = {
    .sibling = &N(D_80251C64_C0F4E4),
    .child = &N(D_80251ECC_C0F74C),
};

StaticAnimatorNode N(D_80251F24_C0F7A4) = {
    .displayList = N(D_8024FAB0_C0D330),
    .rot = { 0x0000, 0x1FFF, 0x8001 },
    .pos = { -315.0f, 2.0f, -139.0f },
};

StaticAnimatorNode N(D_80251F50_C0F7D0) = {
    .displayList = N(D_8024FA18_C0D298),
    .rot = { 0x8001, 0x2AAA, 0x8001 },
    .pos = { -455.0f, 421.0f, -20.0f },
    .sibling = &N(D_80251F24_C0F7A4),
};

StaticAnimatorNode N(D_80251F7C_C0F7FC) = {
    .displayList = N(D_8024F980_C0D200),
    .rot = { 0x8001, 0xE001, 0x0000 },
    .pos = { -385.0f, 2.0f, 169.0f },
    .sibling = &N(D_80251F50_C0F7D0),
};

StaticAnimatorNode N(D_80251FA8_C0F828) = {
    .displayList = N(D_8024F8E8_C0D168),
    .rot = { 0x0000, 0x2AAA, 0x8001 },
    .pos = { -105.0f, 2.0f, -210.0f },
    .sibling = &N(D_80251F7C_C0F7FC),
};

StaticAnimatorNode N(D_80251FD4_C0F854) = {
    .displayList = N(D_8024F850_C0D0D0),
    .rot = { 0x0000, 0xEAAB, 0x8001 },
    .pos = { -5.0f, 2.0f, -180.0f },
    .sibling = &N(D_80251FA8_C0F828),
};

StaticAnimatorNode N(D_80252000_C0F880) = {
    .displayList = N(D_8024F7B8_C0D038),
    .rot = { 0x8001, 0x0AAA, 0x0000 },
    .pos = { -195.0f, 2.0f, 259.0f },
    .sibling = &N(D_80251FD4_C0F854),
};

StaticAnimatorNode N(D_8025202C_C0F8AC) = {
    .displayList = N(D_8024F720_C0CFA0),
    .rot = { 0x8001, 0xD556, 0x8001 },
    .pos = { -65.0f, 2.0f, 189.0f },
    .sibling = &N(D_80252000_C0F880),
};

StaticAnimatorNode N(D_80252058_C0F8D8) = {
    .displayList = N(D_8024F688_C0CF08),
    .rot = { 0x8001, 0x0000, 0x0000 },
    .pos = { 275.0f, 2.0f, -129.0f },
    .sibling = &N(D_8025202C_C0F8AC),
};

StaticAnimatorNode N(D_80252084_C0F904) = {
    .displayList = N(D_8024F5F0_C0CE70),
    .rot = { 0x0000, 0xF556, 0x8001 },
    .pos = { 195.0f, 421.0f, -40.0f },
    .sibling = &N(D_80252058_C0F8D8),
};

StaticAnimatorNode N(D_802520B0_C0F930) = {
    .displayList = N(D_8024F558_C0CDD8),
    .rot = { 0x8001, 0x1555, 0x8001 },
    .pos = { 85.0f, 2.0f, 329.0f },
    .sibling = &N(D_80252084_C0F904),
};

StaticAnimatorNode N(D_802520DC_C0F95C) = {
    .displayList = N(D_8024F4C0_C0CD40),
    .rot = { 0x8001, 0x1555, 0x0000 },
    .pos = { 215.0f, 421.0f, 29.0f },
    .sibling = &N(D_802520B0_C0F930),
};

StaticAnimatorNode N(D_80252108_C0F988) = {
    .sibling = &N(D_80251EF8_C0F778),
    .child = &N(D_802520DC_C0F95C),
};

StaticAnimatorNode N(D_80252134_C0F9B4) = {
    .displayList = N(D_8024F328_C0CBA8),
    .rot = { 0x8001, 0x0000, 0x0000 },
    .pos = { 8.0f, -23.0f, -49.0f },
};

StaticAnimatorNode N(D_80252160_C0F9E0) = {
    .displayList = N(D_8024F160_C0C9E0),
    .rot = { 0x0000, 0xF8E4, 0x8001 },
    .pos = { 73.0f, -23.0f, 20.0f },
    .sibling = &N(D_80252134_C0F9B4),
};

StaticAnimatorNode N(D_8025218C_C0FA0C) = {
    .displayList = N(D_8024F1F8_C0CA78),
    .rot = { 0x8001, 0x0000, 0x0000 },
    .pos = { -1.0f, -23.0f, 49.0f },
    .sibling = &N(D_80252160_C0F9E0),
};

StaticAnimatorNode N(D_802521B8_C0FA38) = {
    .displayList = N(D_8024F290_C0CB10),
    .rot = { 0x8001, 0x0000, 0x8001 },
    .pos = { 18.0f, -23.0f, 0.0f },
    .sibling = &N(D_8025218C_C0FA0C),
};

StaticAnimatorNode N(D_802521E4_C0FA64) = {
    .rot = { 0x0000, 0x1FFF, 0x0000 },
    .pos = { 61.0f, 47.0f, -31.0f },
    .child = &N(D_802521B8_C0FA38),
};

StaticAnimatorNode N(D_80252210_C0FA90) = {
    .displayList = N(D_8024F3C0_C0CC40),
    .rot = { 0x8001, 0x0AAA, 0x0000 },
    .pos = { -415.0f, 21.0f, 20.0f },
    .sibling = &N(D_802521E4_C0FA64),
};

StaticAnimatorNode N(D_8025223C_C0FABC) = {
    .displayList = N(D_8024F0C8_C0C948),
    .rot = { 0x8001, 0xF8E4, 0x8001 },
    .pos = { 195.0f, 211.0f, -39.0f },
    .sibling = &N(D_80252210_C0FA90),
};

StaticAnimatorNode N(D_80252268_C0FAE8) = {
    .displayList = N(D_8024F030_C0C8B0),
    .rot = { 0x8001, 0xF1C8, 0x8001 },
    .pos = { 95.0f, 210.0f, -30.0f },
    .sibling = &N(D_8025223C_C0FABC),
};

StaticAnimatorNode N(D_80252294_C0FB14) = {
    .displayList = N(D_8024EF98_C0C818),
    .rot = { 0x8001, 0x1555, 0x8001 },
    .pos = { 115.0f, 211.0f, 39.0f },
    .sibling = &N(D_80252268_C0FAE8),
};

StaticAnimatorNode N(D_802522C0_C0FB40) = {
    .displayList = N(D_8024EF00_C0C780),
    .rot = { 0x8001, 0x0AAA, 0x8001 },
    .pos = { 215.0f, 211.0f, 39.0f },
    .sibling = &N(D_80252294_C0FB14),
};

StaticAnimatorNode N(D_802522EC_C0FB6C) = {
    .sibling = &N(D_80252108_C0F988),
    .child = &N(D_802522C0_C0FB40),
};

StaticAnimatorNode N(D_80252318_C0FB98) = {
    .displayList = N(D_8024BEF8_C09778),
    .rot = { 0x0000, 0x0AAA, 0x0000 },
    .pos = { -375.0f, 2.0f, 0.0f },
};

StaticAnimatorNode N(D_80252344_C0FBC4) = {
    .displayList = N(D_8024BE60_C096E0),
    .rot = { 0x0000, 0xEAAB, 0x8001 },
    .pos = { -175.0f, 2.0f, -49.0f },
    .sibling = &N(D_80252318_C0FB98),
};

StaticAnimatorNode N(D_80252370_C0FBF0) = {
    .displayList = N(D_8024BDC8_C09648),
    .rot = { 0x8001, 0x0000, 0x8001 },
    .pos = { 75.0f, 2.0f, -49.0f },
    .sibling = &N(D_80252344_C0FBC4),
};

StaticAnimatorNode N(D_8025239C_C0FC1C) = {
    .sibling = &N(D_802522EC_C0FB6C),
    .child = &N(D_80252370_C0FBF0),
};

StaticAnimatorNode N(D_802523C8_C0FC48) = {
    .sibling = &N(D_80251A80_C0F300),
    .child = &N(D_8025239C_C0FC1C),
};

StaticAnimatorNode N(D_802523F4_C0FC74) = {
    .displayList = N(D_8024DEF8_dgb_01),
};

StaticAnimatorNode N(D_80252420_C0FCA0) = {
    .displayList = N(D_8024E120_C0B9A0),
    .sibling = &N(D_802523F4_C0FC74),
};

StaticAnimatorNode N(D_8025244C_C0FCCC) = {
    .displayList = N(D_8024E0A8_C0B928),
    .sibling = &N(D_80252420_C0FCA0),
};

StaticAnimatorNode N(D_80252478_C0FCF8) = {
    .displayList = N(D_8024E020_C0B8A0),
    .sibling = &N(D_8025244C_C0FCCC),
};

StaticAnimatorNode N(D_802524A4_C0FD24) = {
    .displayList = N(D_8024DFA0_C0B820),
    .sibling = &N(D_80252478_C0FCF8),
};

StaticAnimatorNode N(D_802524D0_C0FD50) = {
    .displayList = N(D_8024E1A8_C0BA28),
    .sibling = &N(D_802524A4_C0FD24),
};

StaticAnimatorNode N(D_802524FC_C0FD7C) = {
    .displayList = N(D_8024DD60_C0B5E0),
    .sibling = &N(D_802524D0_C0FD50),
};

StaticAnimatorNode N(D_80252528_C0FDA8) = {
    .displayList = N(D_8024DC50_C0B4D0),
    .sibling = &N(D_802524FC_C0FD7C),
};

StaticAnimatorNode N(D_80252554_C0FDD4) = {
    .rot = { 0x0000, 0x0000, 0xEA9F },
    .pos = { -360.0f, 85.0f, -1.0f },
    .child = &N(D_80252528_C0FDA8),
};

StaticAnimatorNode N(D_80252580_C0FE00) = {
    .displayList = N(D_8024ECB0_C0C530),
};

StaticAnimatorNode N(D_802525AC_C0FE2C) = {
    .displayList = N(D_8024EE18_C0C698),
    .sibling = &N(D_80252580_C0FE00),
};

StaticAnimatorNode N(D_802525D8_C0FE58) = {
    .rot = { 0xEAAB, 0x2E87, 0xF02E },
    .pos = { 35.0f, 316.0f, 36.0f },
    .sibling = &N(D_80252554_C0FDD4),
    .child = &N(D_802525AC_C0FE2C),
};

StaticAnimatorNode N(D_80252604_C0FE84) = {
    .displayList = N(D_80250720_C0DFA0),
};

StaticAnimatorNode N(D_80252630_C0FEB0) = {
    .displayList = N(D_80250910_C0E190),
    .sibling = &N(D_80252604_C0FE84),
};

StaticAnimatorNode N(D_8025265C_C0FEDC) = {
    .displayList = N(D_80250698_C0DF18),
    .sibling = &N(D_80252630_C0FEB0),
};

StaticAnimatorNode N(D_80252688_C0FF08) = {
    .displayList = N(D_80250798_C0E018),
    .sibling = &N(D_8025265C_C0FEDC),
};

StaticAnimatorNode N(D_802526B4_C0FF34) = {
    .displayList = N(D_80250820_C0E0A0),
    .sibling = &N(D_80252688_C0FF08),
};

StaticAnimatorNode N(D_802526E0_C0FF60) = {
    .displayList = N(D_80250898_C0E118),
    .sibling = &N(D_802526B4_C0FF34),
};

StaticAnimatorNode N(D_8025270C_C0FF8C) = {
    .rot = { 0xFC72, 0xFE27, 0x0000 },
    .pos = { 133.0f, 271.0f, 30.0f },
    .sibling = &N(D_802525D8_C0FE58),
    .child = &N(D_802526E0_C0FF60),
};

StaticAnimatorNode N(D_80252738_C0FFB8) = {
    .displayList = N(D_8024C918_C0A198),
    .pos = { 252.0f, 0.0f, 0.0f },
};

StaticAnimatorNode N(D_80252764_C0FFE4) = {
    .displayList = N(D_8024C998_C0A218),
    .pos = { 252.0f, 0.0f, 0.0f },
    .sibling = &N(D_80252738_C0FFB8),
};

StaticAnimatorNode N(D_80252790_C10010) = {
    .displayList = N(D_8024C808_C0A088),
    .pos = { 252.0f, 0.0f, 0.0f },
    .sibling = &N(D_80252764_C0FFE4),
};

StaticAnimatorNode N(D_802527BC_C1003C) = {
    .sibling = &N(D_80252790_C10010),
};

StaticAnimatorNode N(D_802527E8_C10068) = {
    .rot = { 0x0000, 0x0000, 0xF60C },
    .pos = { -252.0f, 0.0f, 0.0f },
    .child = &N(D_802527BC_C1003C),
};

StaticAnimatorNode N(D_80252814_C10094) = {
    .rot = { 0x0000, 0x0000, 0x09F4 },
    .pos = { 253.0f, 285.0f, 86.0f },
    .child = &N(D_802527E8_C10068),
};

StaticAnimatorNode N(D_80252840_C100C0) = {
    .displayList = N(D_8024CAF0_C0A370),
    .sibling = &N(D_80252814_C10094),
};

StaticAnimatorNode N(D_8025286C_C100EC) = {
    .displayList = N(D_8024CC28_C0A4A8),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80252840_C100C0),
};

StaticAnimatorNode N(D_80252898_C10118) = {
    .displayList = N(D_8024CB68_C0A3E8),
    .sibling = &N(D_8025286C_C100EC),
};

StaticAnimatorNode N(D_802528C4_C10144) = {
    .displayList = N(D_8024CD98_C0A618),
    .sibling = &N(D_80252898_C10118),
};

StaticAnimatorNode N(D_802528F0_C10170) = {
    .displayList = N(D_8024CD10_C0A590),
    .sibling = &N(D_802528C4_C10144),
};

StaticAnimatorNode N(D_8025291C_C1019C) = {
    .displayList = N(D_8024CCA0_C0A520),
    .sibling = &N(D_802528F0_C10170),
};

StaticAnimatorNode N(D_80252948_C101C8) = {
    .displayList = N(D_8024CE08_C0A688),
    .sibling = &N(D_8025291C_C1019C),
};

StaticAnimatorNode N(D_80252974_C101F4) = {
    .displayList = N(D_8024C670_C09EF0),
    .sibling = &N(D_80252948_C101C8),
};

StaticAnimatorNode N(D_802529A0_C10220) = {
    .sibling = &N(D_8025270C_C0FF8C),
    .child = &N(D_80252974_C101F4),
};

StaticAnimatorNode N(D_802529CC_C1024C) = {
    .displayList = N(D_8024D2B8_C0AB38),
};

StaticAnimatorNode N(D_802529F8_C10278) = {
    .displayList = N(D_8024D448_C0ACC8),
    .sibling = &N(D_802529CC_C1024C),
};

StaticAnimatorNode N(D_80252A24_C102A4) = {
    .displayList = N(D_8024D3C8_C0AC48),
    .sibling = &N(D_802529F8_C10278),
};

StaticAnimatorNode N(D_80252A50_C102D0) = {
    .pos = { 105.0f, -8.0f, 87.0f },
    .child = &N(D_80252A24_C102A4),
};

StaticAnimatorNode N(D_80252A7C_C102FC) = {
    .displayList = N(D_8024D580_C0AE00),
    .sibling = &N(D_80252A50_C102D0),
};

StaticAnimatorNode N(D_80252AA8_C10328) = {
    .displayList = N(D_8024D680_C0AF00),
    .sibling = &N(D_80252A7C_C102FC),
};

StaticAnimatorNode N(D_80252AD4_C10354) = {
    .displayList = N(D_8024D828_C0B0A8),
    .sibling = &N(D_80252AA8_C10328),
};

StaticAnimatorNode N(D_80252B00_C10380) = {
    .displayList = N(D_8024D788_C0B008),
    .sibling = &N(D_80252AD4_C10354),
};

StaticAnimatorNode N(D_80252B2C_C103AC) = {
    .displayList = N(D_8024D700_C0AF80),
    .sibling = &N(D_80252B00_C10380),
};

StaticAnimatorNode N(D_80252B58_C103D8) = {
    .displayList = N(D_8024D8D0_C0B150),
    .sibling = &N(D_80252B2C_C103AC),
};

StaticAnimatorNode N(D_80252B84_C10404) = {
    .displayList = N(D_8024D060_C0A8E0),
    .sibling = &N(D_80252B58_C103D8),
};

StaticAnimatorNode N(D_80252BB0_C10430) = {
    .rot = { 0x0000, 0x1FFF, 0x0000 },
    .pos = { 61.0f, 47.0f, -31.0f },
    .sibling = &N(D_802529A0_C10220),
    .child = &N(D_80252B84_C10404),
};

StaticAnimatorNode N(D_80252BDC_C1045C) = {
    .displayList = N(D_8024E6D8_C0BF58),
    .rot = { 0x038E, 0x0000, 0x18E3 },
    .pos = { -465.0f, 210.0f, -90.0f },
};

StaticAnimatorNode N(D_80252C08_C10488) = {
    .displayList = N(D_8024E5B0_C0BE30),
    .rot = { 0x0000, 0x18E3, 0x1555 },
    .pos = { -465.0f, 210.0f, 90.0f },
    .sibling = &N(D_80252BDC_C1045C),
};

StaticAnimatorNode N(D_80252C34_C104B4) = {
    .displayList = N(D_8024E800_C0C080),
    .sibling = &N(D_80252C08_C10488),
};

StaticAnimatorNode N(D_80252C60_C104E0) = {
    .displayList = N(D_8024EA60_C0C2E0),
    .sibling = &N(D_80252C34_C104B4),
};

StaticAnimatorNode N(D_80252C8C_C1050C) = {
    .displayList = N(D_8024E9D8_C0C258),
    .sibling = &N(D_80252C60_C104E0),
};

StaticAnimatorNode N(D_80252CB8_C10538) = {
    .displayList = N(D_8024E968_C0C1E8),
    .sibling = &N(D_80252C8C_C1050C),
};

StaticAnimatorNode N(D_80252CE4_C10564) = {
    .displayList = N(D_8024E8C0_C0C140),
    .pos = { 0.0f, -500.0f, 0.0f },
    .sibling = &N(D_80252CB8_C10538),
};

StaticAnimatorNode N(D_80252D10_C10590) = {
    .displayList = N(D_8024EAD0_C0C350),
    .sibling = &N(D_80252CE4_C10564),
};

StaticAnimatorNode N(D_80252D3C_C105BC) = {
    .displayList = N(D_8024E4D8_C0BD58),
    .sibling = &N(D_80252D10_C10590),
};

StaticAnimatorNode N(D_80252D68_C105E8) = {
    .pos = { 0.0f, -188.0f, 0.0f },
    .sibling = &N(D_80252BB0_C10430),
    .child = &N(D_80252D3C_C105BC),
};

StaticAnimatorNode N(D_80252D94_C10614) = {
    .displayList = N(D_802510C8_C0E948),
    .pos = { -179.0f, 34.0f, 98.0f },
};

StaticAnimatorNode N(D_80252DC0_C10640) = {
    .displayList = N(D_80250E88_C0E708),
    .pos = { -179.0f, 34.0f, 98.0f },
    .sibling = &N(D_80252D94_C10614),
};

StaticAnimatorNode N(D_80252DEC_C1066C) = {
    .displayList = N(D_80251050_C0E8D0),
    .pos = { -179.0f, 34.0f, 98.0f },
    .sibling = &N(D_80252DC0_C10640),
};

StaticAnimatorNode N(D_80252E18_C10698) = {
    .displayList = N(D_80250FC8_C0E848),
    .pos = { -179.0f, 34.0f, 98.0f },
    .sibling = &N(D_80252DEC_C1066C),
};

StaticAnimatorNode N(D_80252E44_C106C4) = {
    .displayList = N(D_80250F40_C0E7C0),
    .pos = { -179.0f, 34.0f, 98.0f },
    .sibling = &N(D_80252E18_C10698),
};

StaticAnimatorNode N(D_80252E70_C106F0) = {
    .displayList = N(D_80250DE0_C0E660),
    .pos = { -179.0f, 34.0f, 98.0f },
    .sibling = &N(D_80252E44_C106C4),
};

StaticAnimatorNode N(D_80252E9C_C1071C) = {
    .rot = { 0xFB06, 0xC60C, 0 },
    .pos = { 179.0f, -34.0f, -98.0f },
    .child = &N(D_80252E70_C106F0),
};

StaticAnimatorNode N(D_80252EC8_C10748) = {
    .rot = { 0, 0xFA06, 0xC464 },
    .pos = { -245.0f, 196.0f, 21.0f },
    .sibling = &N(D_80252D68_C105E8),
    .child = &N(D_80252E9C_C1071C),
};

StaticAnimatorNode N(D_80252EF4_C10774) = {
    .sibling = &N(D_802523C8_C0FC48),
    .child = &N(D_80252EC8_C10748),
};

StaticAnimatorNode N(D_80252F20_C107A0) = {
    .child = &N(D_80252EF4_C10774),
};

StaticAnimatorNode* N(SmashBridgesSkeleton)[] = {
    &N(D_80252F20_C107A0), &N(D_80252EF4_C10774), &N(D_80252EC8_C10748), &N(D_80252E9C_C1071C),
    &N(D_80252E70_C106F0), &N(D_80252E44_C106C4), &N(D_80252E18_C10698), &N(D_80252DEC_C1066C),
    &N(D_80252DC0_C10640), &N(D_80252D94_C10614), &N(D_80252D68_C105E8), &N(D_80252D3C_C105BC),
    &N(D_80252D10_C10590), &N(D_80252CE4_C10564), &N(D_80252CB8_C10538), &N(D_80252C8C_C1050C),
    &N(D_80252C60_C104E0), &N(D_80252C34_C104B4), &N(D_80252C08_C10488), &N(D_80252BDC_C1045C),
    &N(D_80252BB0_C10430), &N(D_80252B84_C10404), &N(D_80252B58_C103D8), &N(D_80252B2C_C103AC),
    &N(D_80252B00_C10380), &N(D_80252AD4_C10354), &N(D_80252AA8_C10328), &N(D_80252A7C_C102FC),
    &N(D_80252A50_C102D0), &N(D_80252A24_C102A4), &N(D_802529F8_C10278), &N(D_802529CC_C1024C),
    &N(D_802529A0_C10220), &N(D_80252974_C101F4), &N(D_80252948_C101C8), &N(D_8025291C_C1019C),
    &N(D_802528F0_C10170), &N(D_802528C4_C10144), &N(D_80252898_C10118), &N(D_8025286C_C100EC),
    &N(D_80252840_C100C0), &N(D_80252814_C10094), &N(D_802527E8_C10068), &N(D_802527BC_C1003C),
    &N(D_80252790_C10010), &N(D_80252764_C0FFE4), &N(D_80252738_C0FFB8), &N(D_8025270C_C0FF8C),
    &N(D_802526E0_C0FF60), &N(D_802526B4_C0FF34), &N(D_80252688_C0FF08), &N(D_8025265C_C0FEDC),
    &N(D_80252630_C0FEB0), &N(D_80252604_C0FE84), &N(D_802525D8_C0FE58), &N(D_802525AC_C0FE2C),
    &N(D_80252580_C0FE00), &N(D_80252554_C0FDD4), &N(D_80252528_C0FDA8), &N(D_802524FC_C0FD7C),
    &N(D_802524D0_C0FD50), &N(D_802524A4_C0FD24), &N(D_80252478_C0FCF8), &N(D_8025244C_C0FCCC),
    &N(D_80252420_C0FCA0), &N(D_802523F4_C0FC74), &N(D_802523C8_C0FC48), &N(D_8025239C_C0FC1C),
    &N(D_80252370_C0FBF0), &N(D_80252344_C0FBC4), &N(D_80252318_C0FB98), &N(D_802522EC_C0FB6C),
    &N(D_802522C0_C0FB40), &N(D_80252294_C0FB14), &N(D_80252268_C0FAE8), &N(D_8025223C_C0FABC),
    &N(D_80252210_C0FA90), &N(D_802521E4_C0FA64), &N(D_802521B8_C0FA38), &N(D_8025218C_C0FA0C),
    &N(D_80252160_C0F9E0), &N(D_80252134_C0F9B4), &N(D_80252108_C0F988), &N(D_802520DC_C0F95C),
    &N(D_802520B0_C0F930), &N(D_80252084_C0F904), &N(D_80252058_C0F8D8), &N(D_8025202C_C0F8AC),
    &N(D_80252000_C0F880), &N(D_80251FD4_C0F854), &N(D_80251FA8_C0F828), &N(D_80251F7C_C0F7FC),
    &N(D_80251F50_C0F7D0), &N(D_80251F24_C0F7A4), &N(D_80251EF8_C0F778), &N(D_80251ECC_C0F74C),
    &N(D_80251EA0_C0F720), &N(D_80251E74_C0F6F4), &N(D_80251E48_C0F6C8), &N(D_80251E1C_C0F69C),
    &N(D_80251DF0_C0F670), &N(D_80251DC4_C0F644), &N(D_80251D98_C0F618), &N(D_80251D6C_C0F5EC),
    &N(D_80251D40_C0F5C0), &N(D_80251D14_C0F594), &N(D_80251CE8_C0F568), &N(D_80251CBC_C0F53C),
    &N(D_80251C90_C0F510), &N(D_80251C64_C0F4E4), &N(D_80251C38_C0F4B8), &N(D_80251C0C_C0F48C),
    &N(D_80251BE0_C0F460), &N(D_80251BB4_C0F434), &N(D_80251B88_C0F408), &N(D_80251B5C_C0F3DC),
    &N(D_80251B30_C0F3B0), &N(D_80251B04_C0F384), &N(D_80251AD8_C0F358), &N(D_80251AAC_C0F32C),
    &N(D_80251A80_C0F300),  0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
