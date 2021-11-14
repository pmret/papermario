.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_8029CC48
.word L8024CFB0_17B890, L8024CFBC_17B89C, L8024CFC8_17B8A8, L8024CFFC_17B8DC, L8024D024_17B904, L8024D04C_17B92C, L8024D074_17B954, L8024D09C_17B97C, L8024D0C4_17B9A4, L8024D0EC_17B9CC, L8024D120_17BA00, L8024D154_17BA34, L8024D17C_17BA5C, L8024D1B0_17BA90, L8024D1E4_17BAC4, L8024D20C_17BAEC, L8024D240_17BB20, L8024D288_17BB68, L8024D2CC_17BBAC, L8024D2FC_17BBDC, L8024D314_17BBF4, L8024D324_17BC04, L8024D4A0_17BD80, L8024D424_17BD04, L8024D3B4_17BC94, L8024D348_17BC28, L8024D4EC_17BDCC, L8024D548_17BE28, L8024D5A0_17BE80, L8024DE00_17C6E0, L8024D5E4_17BEC4, L8024D5E4_17BEC4, L8024D654_17BF34, L8024D6A0_17BF80, L8024D6D4_17BFB4, L8024D740_17C020, L8024D7FC_17C0DC, L8024D7A0_17C080, L8024D85C_17C13C, L8024D8B8_17C198, L8024D910_17C1F0, L8024D97C_17C25C, L8024D97C_17C25C, L8024D9BC_17C29C, L8024DA18_17C2F8, L8024DA80_17C360, L8024DAE0_17C3C0, L8024DC9C_17C57C, L8024DCF0_17C5D0, L8024DD4C_17C62C, L8024DDA8_17C688, L8024DE00_17C6E0, L8024DE30_17C710, L8024DE8C_17C76C, L8024DEEC_17C7CC, L8024DF5C_17C83C, L8024DF94_17C874, L8024DFE8_17C8C8, L8024E04C_17C92C, L8024E0CC_17C9AC, L8024E144_17CA24, L8024E1A4_17CA84, L8024E1A4_17CA84, L8024E218_17CAF8, L8024E24C_17CB2C, L8024E274_17CB54, L8024E29C_17CB7C, L8024E2F8_17CBD8, L8024E320_17CC00, L8024DBEC_17C4CC, L8024DB48_17C428, L8024DBA0_17C480, L8024DBEC_17C4CC, L8024DC58_17C538

.section .text

glabel btl_cam_use_preset
/* 17B814 8024CF34 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17B818 8024CF38 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17B81C 8024CF3C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17B820 8024CF40 AFB10014 */  sw        $s1, 0x14($sp)
/* 17B824 8024CF44 0080882D */  daddu     $s1, $a0, $zero
/* 17B828 8024CF48 AFB00010 */  sw        $s0, 0x10($sp)
/* 17B82C 8024CF4C 0000802D */  daddu     $s0, $zero, $zero
/* 17B830 8024CF50 AFB20018 */  sw        $s2, 0x18($sp)
/* 17B834 8024CF54 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 17B838 8024CF58 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 17B83C 8024CF5C 14400518 */  bnez      $v0, .L8024E3C0
/* 17B840 8024CF60 AFBF001C */   sw       $ra, 0x1c($sp)
/* 17B844 8024CF64 24020001 */  addiu     $v0, $zero, 1
/* 17B848 8024CF68 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17B84C 8024CF6C A022F2A6 */  sb        $v0, %lo(D_8029F2A6)($at)
/* 17B850 8024CF70 2E22004A */  sltiu     $v0, $s1, 0x4a
/* 17B854 8024CF74 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17B858 8024CF78 A020F2A2 */  sb        $zero, %lo(D_8029F2A2)($at)
/* 17B85C 8024CF7C 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17B860 8024CF80 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17B864 8024CF84 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17B868 8024CF88 A020F2A5 */  sb        $zero, %lo(D_8029F2A5)($at)
/* 17B86C 8024CF8C 3C01802A */  lui       $at, %hi(D_8029F2A7)
/* 17B870 8024CF90 A020F2A7 */  sb        $zero, %lo(D_8029F2A7)($at)
/* 17B874 8024CF94 104004F7 */  beqz      $v0, .L8024E374
/* 17B878 8024CF98 00111080 */   sll      $v0, $s1, 2
/* 17B87C 8024CF9C 3C01802A */  lui       $at, %hi(jtbl_8029CC48)
/* 17B880 8024CFA0 00220821 */  addu      $at, $at, $v0
/* 17B884 8024CFA4 8C22CC48 */  lw        $v0, %lo(jtbl_8029CC48)($at)
/* 17B888 8024CFA8 00400008 */  jr        $v0
/* 17B88C 8024CFAC 00000000 */   nop
dlabel L8024CFB0_17B890
/* 17B890 8024CFB0 3C108028 */  lui       $s0, %hi(CamPreset_A)
/* 17B894 8024CFB4 080938DD */  j         .L8024E374
/* 17B898 8024CFB8 26100E54 */   addiu    $s0, $s0, %lo(CamPreset_A)
dlabel L8024CFBC_17B89C
/* 17B89C 8024CFBC 3C108028 */  lui       $s0, %hi(CamPreset_B)
/* 17B8A0 8024CFC0 080938DD */  j         .L8024E374
/* 17B8A4 8024CFC4 26100CE8 */   addiu    $s0, $s0, %lo(CamPreset_B)
dlabel L8024CFC8_17B8A8
/* 17B8A8 8024CFC8 3C028028 */  lui       $v0, %hi(D_80280CE4)
/* 17B8AC 8024CFCC 8C420CE4 */  lw        $v0, %lo(D_80280CE4)($v0)
/* 17B8B0 8024CFD0 105104FB */  beq       $v0, $s1, .L8024E3C0
/* 17B8B4 8024CFD4 240201F4 */   addiu    $v0, $zero, 0x1f4
/* 17B8B8 8024CFD8 3C108028 */  lui       $s0, %hi(CamPreset_C)
/* 17B8BC 8024CFDC 26100DAC */  addiu     $s0, $s0, %lo(CamPreset_C)
/* 17B8C0 8024CFE0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B8C4 8024CFE4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B8C8 8024CFE8 2402001E */  addiu     $v0, $zero, 0x1e
/* 17B8CC 8024CFEC 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17B8D0 8024CFF0 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17B8D4 8024CFF4 080938DD */  j         .L8024E374
/* 17B8D8 8024CFF8 00000000 */   nop
dlabel L8024CFFC_17B8DC
/* 17B8DC 8024CFFC 3C028028 */  lui       $v0, %hi(D_80280CE4)
/* 17B8E0 8024D000 8C420CE4 */  lw        $v0, %lo(D_80280CE4)($v0)
/* 17B8E4 8024D004 105104EE */  beq       $v0, $s1, .L8024E3C0
/* 17B8E8 8024D008 240201E0 */   addiu    $v0, $zero, 0x1e0
/* 17B8EC 8024D00C 3C108028 */  lui       $s0, %hi(CamPreset_D)
/* 17B8F0 8024D010 26100DC8 */  addiu     $s0, $s0, %lo(CamPreset_D)
/* 17B8F4 8024D014 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B8F8 8024D018 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B8FC 8024D01C 080934CC */  j         .L8024D330
/* 17B900 8024D020 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024D024_17B904
/* 17B904 8024D024 3C028028 */  lui       $v0, %hi(D_80280CE4)
/* 17B908 8024D028 8C420CE4 */  lw        $v0, %lo(D_80280CE4)($v0)
/* 17B90C 8024D02C 105104E4 */  beq       $v0, $s1, .L8024E3C0
/* 17B910 8024D030 240201F4 */   addiu    $v0, $zero, 0x1f4
/* 17B914 8024D034 3C108028 */  lui       $s0, %hi(CamPreset_E)
/* 17B918 8024D038 26100DE4 */  addiu     $s0, $s0, %lo(CamPreset_E)
/* 17B91C 8024D03C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B920 8024D040 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B924 8024D044 080934CC */  j         .L8024D330
/* 17B928 8024D048 2402000A */   addiu    $v0, $zero, 0xa
dlabel L8024D04C_17B92C
/* 17B92C 8024D04C 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17B930 8024D050 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17B934 8024D054 2402012C */  addiu     $v0, $zero, 0x12c
/* 17B938 8024D058 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B93C 8024D05C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B940 8024D060 24020014 */  addiu     $v0, $zero, 0x14
/* 17B944 8024D064 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17B948 8024D068 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17B94C 8024D06C 080938D9 */  j         .L8024E364
/* 17B950 8024D070 24020001 */   addiu    $v0, $zero, 1
dlabel L8024D074_17B954
/* 17B954 8024D074 3C108028 */  lui       $s0, %hi(CamPreset_G)
/* 17B958 8024D078 26100D3C */  addiu     $s0, $s0, %lo(CamPreset_G)
/* 17B95C 8024D07C 2402012C */  addiu     $v0, $zero, 0x12c
/* 17B960 8024D080 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B964 8024D084 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B968 8024D088 24020014 */  addiu     $v0, $zero, 0x14
/* 17B96C 8024D08C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17B970 8024D090 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17B974 8024D094 080938D9 */  j         .L8024E364
/* 17B978 8024D098 24020001 */   addiu    $v0, $zero, 1
dlabel L8024D09C_17B97C
/* 17B97C 8024D09C 3C108028 */  lui       $s0, %hi(CamPreset_H)
/* 17B980 8024D0A0 26100D74 */  addiu     $s0, $s0, %lo(CamPreset_H)
/* 17B984 8024D0A4 2402012C */  addiu     $v0, $zero, 0x12c
/* 17B988 8024D0A8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B98C 8024D0AC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B990 8024D0B0 24020014 */  addiu     $v0, $zero, 0x14
/* 17B994 8024D0B4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17B998 8024D0B8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17B99C 8024D0BC 080938DD */  j         .L8024E374
/* 17B9A0 8024D0C0 00000000 */   nop
dlabel L8024D0C4_17B9A4
/* 17B9A4 8024D0C4 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17B9A8 8024D0C8 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17B9AC 8024D0CC 2402012C */  addiu     $v0, $zero, 0x12c
/* 17B9B0 8024D0D0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B9B4 8024D0D4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B9B8 8024D0D8 24020014 */  addiu     $v0, $zero, 0x14
/* 17B9BC 8024D0DC 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17B9C0 8024D0E0 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17B9C4 8024D0E4 080938D9 */  j         .L8024E364
/* 17B9C8 8024D0E8 24020001 */   addiu    $v0, $zero, 1
dlabel L8024D0EC_17B9CC
/* 17B9CC 8024D0EC 3C02802A */  lui       $v0, %hi(D_8029F2B4)
/* 17B9D0 8024D0F0 8C42F2B4 */  lw        $v0, %lo(D_8029F2B4)($v0)
/* 17B9D4 8024D0F4 3C048028 */  lui       $a0, %hi(CamPreset_C)
/* 17B9D8 8024D0F8 24840DAC */  addiu     $a0, $a0, %lo(CamPreset_C)
/* 17B9DC 8024D0FC 104404B0 */  beq       $v0, $a0, .L8024E3C0
/* 17B9E0 8024D100 240201F4 */   addiu    $v0, $zero, 0x1f4
/* 17B9E4 8024D104 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17B9E8 8024D108 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17B9EC 8024D10C 24020078 */  addiu     $v0, $zero, 0x78
/* 17B9F0 8024D110 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17B9F4 8024D114 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17B9F8 8024D118 080938DD */  j         .L8024E374
/* 17B9FC 8024D11C 0080802D */   daddu    $s0, $a0, $zero
dlabel L8024D120_17BA00
/* 17BA00 8024D120 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17BA04 8024D124 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17BA08 8024D128 240200C8 */  addiu     $v0, $zero, 0xc8
/* 17BA0C 8024D12C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BA10 8024D130 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BA14 8024D134 24020008 */  addiu     $v0, $zero, 8
/* 17BA18 8024D138 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BA1C 8024D13C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BA20 8024D140 24020014 */  addiu     $v0, $zero, 0x14
/* 17BA24 8024D144 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BA28 8024D148 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BA2C 8024D14C 080938D4 */  j         .L8024E350
/* 17BA30 8024D150 2402000F */   addiu    $v0, $zero, 0xf
dlabel L8024D154_17BA34
/* 17BA34 8024D154 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17BA38 8024D158 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17BA3C 8024D15C 2402012C */  addiu     $v0, $zero, 0x12c
/* 17BA40 8024D160 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BA44 8024D164 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BA48 8024D168 24020008 */  addiu     $v0, $zero, 8
/* 17BA4C 8024D16C 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BA50 8024D170 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BA54 8024D174 080938D1 */  j         .L8024E344
/* 17BA58 8024D178 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024D17C_17BA5C
/* 17BA5C 8024D17C 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17BA60 8024D180 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17BA64 8024D184 24020190 */  addiu     $v0, $zero, 0x190
/* 17BA68 8024D188 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BA6C 8024D18C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BA70 8024D190 24020008 */  addiu     $v0, $zero, 8
/* 17BA74 8024D194 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BA78 8024D198 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BA7C 8024D19C 24020014 */  addiu     $v0, $zero, 0x14
/* 17BA80 8024D1A0 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BA84 8024D1A4 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BA88 8024D1A8 080938D4 */  j         .L8024E350
/* 17BA8C 8024D1AC 2402001E */   addiu    $v0, $zero, 0x1e
dlabel L8024D1B0_17BA90
/* 17BA90 8024D1B0 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17BA94 8024D1B4 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17BA98 8024D1B8 240200C8 */  addiu     $v0, $zero, 0xc8
/* 17BA9C 8024D1BC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BAA0 8024D1C0 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BAA4 8024D1C4 24020008 */  addiu     $v0, $zero, 8
/* 17BAA8 8024D1C8 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BAAC 8024D1CC A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BAB0 8024D1D0 24020014 */  addiu     $v0, $zero, 0x14
/* 17BAB4 8024D1D4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BAB8 8024D1D8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BABC 8024D1DC 080938D4 */  j         .L8024E350
/* 17BAC0 8024D1E0 2402000F */   addiu    $v0, $zero, 0xf
dlabel L8024D1E4_17BAC4
/* 17BAC4 8024D1E4 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17BAC8 8024D1E8 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17BACC 8024D1EC 2402012C */  addiu     $v0, $zero, 0x12c
/* 17BAD0 8024D1F0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BAD4 8024D1F4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BAD8 8024D1F8 24020008 */  addiu     $v0, $zero, 8
/* 17BADC 8024D1FC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BAE0 8024D200 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BAE4 8024D204 080938D1 */  j         .L8024E344
/* 17BAE8 8024D208 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024D20C_17BAEC
/* 17BAEC 8024D20C 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17BAF0 8024D210 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17BAF4 8024D214 24020190 */  addiu     $v0, $zero, 0x190
/* 17BAF8 8024D218 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BAFC 8024D21C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BB00 8024D220 24020008 */  addiu     $v0, $zero, 8
/* 17BB04 8024D224 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BB08 8024D228 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BB0C 8024D22C 24020014 */  addiu     $v0, $zero, 0x14
/* 17BB10 8024D230 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BB14 8024D234 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BB18 8024D238 080938D4 */  j         .L8024E350
/* 17BB1C 8024D23C 2402001E */   addiu    $v0, $zero, 0x1e
dlabel L8024D240_17BB20
/* 17BB20 8024D240 3C108028 */  lui       $s0, %hi(CamPreset_H)
/* 17BB24 8024D244 26100D74 */  addiu     $s0, $s0, %lo(CamPreset_H)
/* 17BB28 8024D248 2402010B */  addiu     $v0, $zero, 0x10b
/* 17BB2C 8024D24C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BB30 8024D250 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BB34 8024D254 24020008 */  addiu     $v0, $zero, 8
/* 17BB38 8024D258 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BB3C 8024D25C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BB40 8024D260 24020014 */  addiu     $v0, $zero, 0x14
/* 17BB44 8024D264 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BB48 8024D268 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BB4C 8024D26C 24020017 */  addiu     $v0, $zero, 0x17
/* 17BB50 8024D270 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BB54 8024D274 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BB58 8024D278 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BB5C 8024D27C A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BB60 8024D280 080938DD */  j         .L8024E374
/* 17BB64 8024D284 00000000 */   nop
dlabel L8024D288_17BB68
/* 17BB68 8024D288 3C108028 */  lui       $s0, %hi(CamPreset_H)
/* 17BB6C 8024D28C 26100D74 */  addiu     $s0, $s0, %lo(CamPreset_H)
/* 17BB70 8024D290 2402012C */  addiu     $v0, $zero, 0x12c
/* 17BB74 8024D294 24030008 */  addiu     $v1, $zero, 8
/* 17BB78 8024D298 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BB7C 8024D29C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BB80 8024D2A0 24020014 */  addiu     $v0, $zero, 0x14
/* 17BB84 8024D2A4 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BB88 8024D2A8 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BB8C 8024D2AC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BB90 8024D2B0 A423F284 */  sh        $v1, %lo(D_8029F284)($at)
/* 17BB94 8024D2B4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BB98 8024D2B8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BB9C 8024D2BC 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BBA0 8024D2C0 A423F286 */  sh        $v1, %lo(D_8029F286)($at)
/* 17BBA4 8024D2C4 080938DD */  j         .L8024E374
/* 17BBA8 8024D2C8 00000000 */   nop
dlabel L8024D2CC_17BBAC
/* 17BBAC 8024D2CC 3C108028 */  lui       $s0, %hi(CamPreset_H)
/* 17BBB0 8024D2D0 26100D74 */  addiu     $s0, $s0, %lo(CamPreset_H)
/* 17BBB4 8024D2D4 24020190 */  addiu     $v0, $zero, 0x190
/* 17BBB8 8024D2D8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BBBC 8024D2DC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BBC0 8024D2E0 24020008 */  addiu     $v0, $zero, 8
/* 17BBC4 8024D2E4 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BBC8 8024D2E8 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BBCC 8024D2EC 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BBD0 8024D2F0 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BBD4 8024D2F4 080934CC */  j         .L8024D330
/* 17BBD8 8024D2F8 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024D2FC_17BBDC
/* 17BBDC 8024D2FC 24020014 */  addiu     $v0, $zero, 0x14
/* 17BBE0 8024D300 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BBE4 8024D304 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BBE8 8024D308 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17BBEC 8024D30C 080938DD */  j         .L8024E374
/* 17BBF0 8024D310 26100E00 */   addiu    $s0, $s0, %lo(CamPreset_J)
dlabel L8024D314_17BBF4
/* 17BBF4 8024D314 3C108028 */  lui       $s0, %hi(CamPreset_K)
/* 17BBF8 8024D318 26100E1C */  addiu     $s0, $s0, %lo(CamPreset_K)
/* 17BBFC 8024D31C 080934CC */  j         .L8024D330
/* 17BC00 8024D320 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024D324_17BC04
/* 17BC04 8024D324 3C108028 */  lui       $s0, %hi(CamPreset_L)
/* 17BC08 8024D328 26100E38 */  addiu     $s0, $s0, %lo(CamPreset_L)
/* 17BC0C 8024D32C 24020014 */  addiu     $v0, $zero, 0x14
.L8024D330:
/* 17BC10 8024D330 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BC14 8024D334 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BC18 8024D338 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BC1C 8024D33C A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17BC20 8024D340 080938DD */  j         .L8024E374
/* 17BC24 8024D344 00000000 */   nop
dlabel L8024D348_17BC28
/* 17BC28 8024D348 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17BC2C 8024D34C 26100E00 */  addiu     $s0, $s0, %lo(CamPreset_J)
/* 17BC30 8024D350 3C01C2A0 */  lui       $at, 0xc2a0
/* 17BC34 8024D354 44816000 */  mtc1      $at, $f12
/* 17BC38 8024D358 44800000 */  mtc1      $zero, $f0
/* 17BC3C 8024D35C 2402010A */  addiu     $v0, $zero, 0x10a
/* 17BC40 8024D360 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BC44 8024D364 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BC48 8024D368 44060000 */  mfc1      $a2, $f0
/* 17BC4C 8024D36C 24020008 */  addiu     $v0, $zero, 8
/* 17BC50 8024D370 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BC54 8024D374 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BC58 8024D378 44867000 */  mtc1      $a2, $f14
/* 17BC5C 8024D37C 24020028 */  addiu     $v0, $zero, 0x28
/* 17BC60 8024D380 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BC64 8024D384 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BC68 8024D388 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BC6C 8024D38C A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BC70 8024D390 0C093948 */  jal       btl_cam_set_target_pos
/* 17BC74 8024D394 00000000 */   nop
/* 17BC78 8024D398 24020014 */  addiu     $v0, $zero, 0x14
/* 17BC7C 8024D39C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BC80 8024D3A0 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BC84 8024D3A4 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17BC88 8024D3A8 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17BC8C 8024D3AC 080938DD */  j         .L8024E374
/* 17BC90 8024D3B0 00000000 */   nop
dlabel L8024D3B4_17BC94
/* 17BC94 8024D3B4 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17BC98 8024D3B8 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17BC9C 8024D3BC 240200FA */  addiu     $v0, $zero, 0xfa
/* 17BCA0 8024D3C0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BCA4 8024D3C4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BCA8 8024D3C8 24020008 */  addiu     $v0, $zero, 8
/* 17BCAC 8024D3CC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BCB0 8024D3D0 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BCB4 8024D3D4 24020014 */  addiu     $v0, $zero, 0x14
/* 17BCB8 8024D3D8 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BCBC 8024D3DC A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BCC0 8024D3E0 2402000E */  addiu     $v0, $zero, 0xe
/* 17BCC4 8024D3E4 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BCC8 8024D3E8 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BCCC 8024D3EC 24020001 */  addiu     $v0, $zero, 1
/* 17BCD0 8024D3F0 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BCD4 8024D3F4 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BCD8 8024D3F8 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17BCDC 8024D3FC A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17BCE0 8024D400 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17BCE4 8024D404 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17BCE8 8024D408 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17BCEC 8024D40C A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17BCF0 8024D410 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17BCF4 8024D414 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17BCF8 8024D418 3C018028 */  lui       $at, %hi(D_80280CE0)
/* 17BCFC 8024D41C 080938DD */  j         .L8024E374
/* 17BD00 8024D420 A0220CE0 */   sb       $v0, %lo(D_80280CE0)($at)
dlabel L8024D424_17BD04
/* 17BD04 8024D424 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17BD08 8024D428 26100E00 */  addiu     $s0, $s0, %lo(CamPreset_J)
/* 17BD0C 8024D42C 3C01C2BE */  lui       $at, 0xc2be
/* 17BD10 8024D430 44816000 */  mtc1      $at, $f12
/* 17BD14 8024D434 3C014190 */  lui       $at, 0x4190
/* 17BD18 8024D438 44817000 */  mtc1      $at, $f14
/* 17BD1C 8024D43C 3C064120 */  lui       $a2, 0x4120
/* 17BD20 8024D440 240200FF */  addiu     $v0, $zero, 0xff
/* 17BD24 8024D444 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BD28 8024D448 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BD2C 8024D44C 24020008 */  addiu     $v0, $zero, 8
/* 17BD30 8024D450 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BD34 8024D454 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BD38 8024D458 24020014 */  addiu     $v0, $zero, 0x14
/* 17BD3C 8024D45C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BD40 8024D460 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BD44 8024D464 2402001D */  addiu     $v0, $zero, 0x1d
/* 17BD48 8024D468 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BD4C 8024D46C A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BD50 8024D470 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BD54 8024D474 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BD58 8024D478 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17BD5C 8024D47C A020F2A2 */  sb        $zero, %lo(D_8029F2A2)($at)
/* 17BD60 8024D480 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17BD64 8024D484 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17BD68 8024D488 0C093948 */  jal       btl_cam_set_target_pos
/* 17BD6C 8024D48C 00000000 */   nop
/* 17BD70 8024D490 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17BD74 8024D494 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17BD78 8024D498 080938DD */  j         .L8024E374
/* 17BD7C 8024D49C 00000000 */   nop
dlabel L8024D4A0_17BD80
/* 17BD80 8024D4A0 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17BD84 8024D4A4 26100E00 */  addiu     $s0, $s0, %lo(CamPreset_J)
/* 17BD88 8024D4A8 240200E6 */  addiu     $v0, $zero, 0xe6
/* 17BD8C 8024D4AC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BD90 8024D4B0 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BD94 8024D4B4 24020008 */  addiu     $v0, $zero, 8
/* 17BD98 8024D4B8 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BD9C 8024D4BC A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BDA0 8024D4C0 24020014 */  addiu     $v0, $zero, 0x14
/* 17BDA4 8024D4C4 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BDA8 8024D4C8 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BDAC 8024D4CC 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BDB0 8024D4D0 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BDB4 8024D4D4 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BDB8 8024D4D8 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17BDBC 8024D4DC 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17BDC0 8024D4E0 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17BDC4 8024D4E4 080938DD */  j         .L8024E374
/* 17BDC8 8024D4E8 00000000 */   nop
dlabel L8024D4EC_17BDCC
/* 17BDCC 8024D4EC 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17BDD0 8024D4F0 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17BDD4 8024D4F4 24020136 */  addiu     $v0, $zero, 0x136
/* 17BDD8 8024D4F8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BDDC 8024D4FC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BDE0 8024D500 24020008 */  addiu     $v0, $zero, 8
/* 17BDE4 8024D504 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BDE8 8024D508 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BDEC 8024D50C 2402001E */  addiu     $v0, $zero, 0x1e
/* 17BDF0 8024D510 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BDF4 8024D514 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BDF8 8024D518 24020010 */  addiu     $v0, $zero, 0x10
/* 17BDFC 8024D51C 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BE00 8024D520 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BE04 8024D524 24020001 */  addiu     $v0, $zero, 1
/* 17BE08 8024D528 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BE0C 8024D52C A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BE10 8024D530 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17BE14 8024D534 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17BE18 8024D538 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17BE1C 8024D53C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17BE20 8024D540 0809369A */  j         .L8024DA68
/* 17BE24 8024D544 00000000 */   nop
dlabel L8024D548_17BE28
/* 17BE28 8024D548 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17BE2C 8024D54C 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17BE30 8024D550 24020140 */  addiu     $v0, $zero, 0x140
/* 17BE34 8024D554 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BE38 8024D558 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BE3C 8024D55C 24020008 */  addiu     $v0, $zero, 8
/* 17BE40 8024D560 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BE44 8024D564 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BE48 8024D568 24020005 */  addiu     $v0, $zero, 5
/* 17BE4C 8024D56C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BE50 8024D570 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BE54 8024D574 24020001 */  addiu     $v0, $zero, 1
/* 17BE58 8024D578 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BE5C 8024D57C A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BE60 8024D580 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BE64 8024D584 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17BE68 8024D588 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17BE6C 8024D58C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17BE70 8024D590 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17BE74 8024D594 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17BE78 8024D598 08093659 */  j         .L8024D964
/* 17BE7C 8024D59C 00000000 */   nop
dlabel L8024D5A0_17BE80
/* 17BE80 8024D5A0 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17BE84 8024D5A4 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17BE88 8024D5A8 24020154 */  addiu     $v0, $zero, 0x154
/* 17BE8C 8024D5AC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BE90 8024D5B0 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BE94 8024D5B4 24020008 */  addiu     $v0, $zero, 8
/* 17BE98 8024D5B8 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BE9C 8024D5BC A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BEA0 8024D5C0 24020005 */  addiu     $v0, $zero, 5
/* 17BEA4 8024D5C4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BEA8 8024D5C8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BEAC 8024D5CC 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BEB0 8024D5D0 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BEB4 8024D5D4 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BEB8 8024D5D8 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17BEBC 8024D5DC 080935C6 */  j         .L8024D718
/* 17BEC0 8024D5E0 24020001 */   addiu    $v0, $zero, 1
dlabel L8024D5E4_17BEC4
/* 17BEC4 8024D5E4 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17BEC8 8024D5E8 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17BECC 8024D5EC 2402012C */  addiu     $v0, $zero, 0x12c
/* 17BED0 8024D5F0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BED4 8024D5F4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BED8 8024D5F8 24020008 */  addiu     $v0, $zero, 8
/* 17BEDC 8024D5FC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BEE0 8024D600 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BEE4 8024D604 2402000F */  addiu     $v0, $zero, 0xf
/* 17BEE8 8024D608 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BEEC 8024D60C A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BEF0 8024D610 2402FFE0 */  addiu     $v0, $zero, -0x20
/* 17BEF4 8024D614 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BEF8 8024D618 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BEFC 8024D61C 24020014 */  addiu     $v0, $zero, 0x14
/* 17BF00 8024D620 3C01802A */  lui       $at, %hi(D_8029F2A7)
/* 17BF04 8024D624 A022F2A7 */  sb        $v0, %lo(D_8029F2A7)($at)
/* 17BF08 8024D628 24020001 */  addiu     $v0, $zero, 1
/* 17BF0C 8024D62C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BF10 8024D630 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BF14 8024D634 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17BF18 8024D638 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17BF1C 8024D63C 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17BF20 8024D640 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17BF24 8024D644 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17BF28 8024D648 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17BF2C 8024D64C 080938DD */  j         .L8024E374
/* 17BF30 8024D650 00000000 */   nop
dlabel L8024D654_17BF34
/* 17BF34 8024D654 3C108028 */  lui       $s0, %hi(CamPreset_N)
/* 17BF38 8024D658 26100D90 */  addiu     $s0, $s0, %lo(CamPreset_N)
/* 17BF3C 8024D65C 3C01C282 */  lui       $at, 0xc282
/* 17BF40 8024D660 44810000 */  mtc1      $at, $f0
/* 17BF44 8024D664 3C0141F0 */  lui       $at, 0x41f0
/* 17BF48 8024D668 44811000 */  mtc1      $at, $f2
/* 17BF4C 8024D66C 2402012C */  addiu     $v0, $zero, 0x12c
/* 17BF50 8024D670 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BF54 8024D674 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BF58 8024D678 24020008 */  addiu     $v0, $zero, 8
/* 17BF5C 8024D67C 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BF60 8024D680 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BF64 8024D684 2402000A */  addiu     $v0, $zero, 0xa
/* 17BF68 8024D688 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BF6C 8024D68C A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17BF70 8024D690 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BF74 8024D694 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BF78 8024D698 08093825 */  j         .L8024E094
/* 17BF7C 8024D69C 00000000 */   nop
dlabel L8024D6A0_17BF80
/* 17BF80 8024D6A0 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17BF84 8024D6A4 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17BF88 8024D6A8 240200DC */  addiu     $v0, $zero, 0xdc
/* 17BF8C 8024D6AC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BF90 8024D6B0 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BF94 8024D6B4 24020008 */  addiu     $v0, $zero, 8
/* 17BF98 8024D6B8 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BF9C 8024D6BC A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BFA0 8024D6C0 2402001E */  addiu     $v0, $zero, 0x1e
/* 17BFA4 8024D6C4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BFA8 8024D6C8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BFAC 8024D6CC 08093650 */  j         .L8024D940
/* 17BFB0 8024D6D0 24020018 */   addiu    $v0, $zero, 0x18
dlabel L8024D6D4_17BFB4
/* 17BFB4 8024D6D4 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17BFB8 8024D6D8 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17BFBC 8024D6DC 24020118 */  addiu     $v0, $zero, 0x118
/* 17BFC0 8024D6E0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17BFC4 8024D6E4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17BFC8 8024D6E8 24020008 */  addiu     $v0, $zero, 8
/* 17BFCC 8024D6EC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17BFD0 8024D6F0 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17BFD4 8024D6F4 2402001E */  addiu     $v0, $zero, 0x1e
/* 17BFD8 8024D6F8 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17BFDC 8024D6FC A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17BFE0 8024D700 2402FFFC */  addiu     $v0, $zero, -4
/* 17BFE4 8024D704 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17BFE8 8024D708 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17BFEC 8024D70C 24020001 */  addiu     $v0, $zero, 1
/* 17BFF0 8024D710 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17BFF4 8024D714 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
.L8024D718:
/* 17BFF8 8024D718 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17BFFC 8024D71C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C000 8024D720 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C004 8024D724 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C008 8024D728 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C00C 8024D72C A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17C010 8024D730 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17C014 8024D734 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17C018 8024D738 080938DD */  j         .L8024E374
/* 17C01C 8024D73C 00000000 */   nop
dlabel L8024D740_17C020
/* 17C020 8024D740 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C024 8024D744 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C028 8024D748 2402017C */  addiu     $v0, $zero, 0x17c
/* 17C02C 8024D74C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C030 8024D750 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C034 8024D754 24020008 */  addiu     $v0, $zero, 8
/* 17C038 8024D758 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C03C 8024D75C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C040 8024D760 2402003C */  addiu     $v0, $zero, 0x3c
/* 17C044 8024D764 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C048 8024D768 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C04C 8024D76C 24020001 */  addiu     $v0, $zero, 1
/* 17C050 8024D770 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C054 8024D774 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C058 8024D778 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C05C 8024D77C A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17C060 8024D780 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C064 8024D784 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C068 8024D788 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C06C 8024D78C A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C070 8024D790 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17C074 8024D794 A022F2A5 */  sb        $v0, %lo(D_8029F2A5)($at)
/* 17C078 8024D798 08093659 */  j         .L8024D964
/* 17C07C 8024D79C 00000000 */   nop
dlabel L8024D7A0_17C080
/* 17C080 8024D7A0 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C084 8024D7A4 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C088 8024D7A8 24020140 */  addiu     $v0, $zero, 0x140
/* 17C08C 8024D7AC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C090 8024D7B0 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C094 8024D7B4 24020008 */  addiu     $v0, $zero, 8
/* 17C098 8024D7B8 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C09C 8024D7BC A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C0A0 8024D7C0 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C0A4 8024D7C4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C0A8 8024D7C8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C0AC 8024D7CC 2402FFFC */  addiu     $v0, $zero, -4
/* 17C0B0 8024D7D0 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C0B4 8024D7D4 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C0B8 8024D7D8 24020001 */  addiu     $v0, $zero, 1
/* 17C0BC 8024D7DC 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C0C0 8024D7E0 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C0C4 8024D7E4 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C0C8 8024D7E8 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C0CC 8024D7EC 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C0D0 8024D7F0 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C0D4 8024D7F4 08093659 */  j         .L8024D964
/* 17C0D8 8024D7F8 00000000 */   nop
dlabel L8024D7FC_17C0DC
/* 17C0DC 8024D7FC 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C0E0 8024D800 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C0E4 8024D804 2402012C */  addiu     $v0, $zero, 0x12c
/* 17C0E8 8024D808 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C0EC 8024D80C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C0F0 8024D810 24020008 */  addiu     $v0, $zero, 8
/* 17C0F4 8024D814 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C0F8 8024D818 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C0FC 8024D81C 2402003C */  addiu     $v0, $zero, 0x3c
/* 17C100 8024D820 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C104 8024D824 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C108 8024D828 24020001 */  addiu     $v0, $zero, 1
/* 17C10C 8024D82C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C110 8024D830 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C114 8024D834 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C118 8024D838 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17C11C 8024D83C 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C120 8024D840 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C124 8024D844 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C128 8024D848 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C12C 8024D84C 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17C130 8024D850 A022F2A5 */  sb        $v0, %lo(D_8029F2A5)($at)
/* 17C134 8024D854 08093659 */  j         .L8024D964
/* 17C138 8024D858 00000000 */   nop
dlabel L8024D85C_17C13C
/* 17C13C 8024D85C 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C140 8024D860 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C144 8024D864 24020140 */  addiu     $v0, $zero, 0x140
/* 17C148 8024D868 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C14C 8024D86C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C150 8024D870 24020008 */  addiu     $v0, $zero, 8
/* 17C154 8024D874 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C158 8024D878 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C15C 8024D87C 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C160 8024D880 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C164 8024D884 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C168 8024D888 2402FFFC */  addiu     $v0, $zero, -4
/* 17C16C 8024D88C 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C170 8024D890 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C174 8024D894 24020001 */  addiu     $v0, $zero, 1
/* 17C178 8024D898 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C17C 8024D89C A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C180 8024D8A0 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C184 8024D8A4 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C188 8024D8A8 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C18C 8024D8AC A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C190 8024D8B0 08093659 */  j         .L8024D964
/* 17C194 8024D8B4 00000000 */   nop
dlabel L8024D8B8_17C198
/* 17C198 8024D8B8 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C19C 8024D8BC 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C1A0 8024D8C0 24020140 */  addiu     $v0, $zero, 0x140
/* 17C1A4 8024D8C4 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C1A8 8024D8C8 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C1AC 8024D8CC 24020008 */  addiu     $v0, $zero, 8
/* 17C1B0 8024D8D0 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C1B4 8024D8D4 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C1B8 8024D8D8 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C1BC 8024D8DC 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C1C0 8024D8E0 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C1C4 8024D8E4 24020001 */  addiu     $v0, $zero, 1
/* 17C1C8 8024D8E8 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C1CC 8024D8EC A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C1D0 8024D8F0 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C1D4 8024D8F4 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17C1D8 8024D8F8 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C1DC 8024D8FC A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C1E0 8024D900 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C1E4 8024D904 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C1E8 8024D908 08093659 */  j         .L8024D964
/* 17C1EC 8024D90C 00000000 */   nop
dlabel L8024D910_17C1F0
/* 17C1F0 8024D910 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C1F4 8024D914 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C1F8 8024D918 24020168 */  addiu     $v0, $zero, 0x168
/* 17C1FC 8024D91C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C200 8024D920 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C204 8024D924 24020008 */  addiu     $v0, $zero, 8
/* 17C208 8024D928 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C20C 8024D92C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C210 8024D930 24020014 */  addiu     $v0, $zero, 0x14
/* 17C214 8024D934 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C218 8024D938 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C21C 8024D93C 2402FFFC */  addiu     $v0, $zero, -4
.L8024D940:
/* 17C220 8024D940 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C224 8024D944 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C228 8024D948 24020001 */  addiu     $v0, $zero, 1
/* 17C22C 8024D94C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C230 8024D950 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C234 8024D954 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C238 8024D958 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C23C 8024D95C 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C240 8024D960 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
.L8024D964:
/* 17C244 8024D964 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17C248 8024D968 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17C24C 8024D96C 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C250 8024D970 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17C254 8024D974 080938DD */  j         .L8024E374
/* 17C258 8024D978 00000000 */   nop
dlabel L8024D97C_17C25C
/* 17C25C 8024D97C 3C10802A */  lui       $s0, %hi(D_8029F2B4)
/* 17C260 8024D980 8E10F2B4 */  lw        $s0, %lo(D_8029F2B4)($s0)
/* 17C264 8024D984 240200C8 */  addiu     $v0, $zero, 0xc8
/* 17C268 8024D988 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C26C 8024D98C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C270 8024D990 24020007 */  addiu     $v0, $zero, 7
/* 17C274 8024D994 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C278 8024D998 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C27C 8024D99C 3C01802A */  lui       $at, %hi(D_8029F2A0)
/* 17C280 8024D9A0 A422F2A0 */  sh        $v0, %lo(D_8029F2A0)($at)
/* 17C284 8024D9A4 3C01802A */  lui       $at, %hi(D_8029F29C)
/* 17C288 8024D9A8 A020F29C */  sb        $zero, %lo(D_8029F29C)($at)
/* 17C28C 8024D9AC 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17C290 8024D9B0 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17C294 8024D9B4 080938DD */  j         .L8024E374
/* 17C298 8024D9B8 00000000 */   nop
dlabel L8024D9BC_17C29C
/* 17C29C 8024D9BC 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C2A0 8024D9C0 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C2A4 8024D9C4 240200D6 */  addiu     $v0, $zero, 0xd6
/* 17C2A8 8024D9C8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C2AC 8024D9CC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C2B0 8024D9D0 24020008 */  addiu     $v0, $zero, 8
/* 17C2B4 8024D9D4 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C2B8 8024D9D8 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C2BC 8024D9DC 24020014 */  addiu     $v0, $zero, 0x14
/* 17C2C0 8024D9E0 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C2C4 8024D9E4 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C2C8 8024D9E8 24020010 */  addiu     $v0, $zero, 0x10
/* 17C2CC 8024D9EC 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C2D0 8024D9F0 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C2D4 8024D9F4 2402FFFE */  addiu     $v0, $zero, -2
/* 17C2D8 8024D9F8 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C2DC 8024D9FC A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C2E0 8024DA00 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C2E4 8024DA04 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C2E8 8024DA08 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C2EC 8024DA0C A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17C2F0 8024DA10 0809369A */  j         .L8024DA68
/* 17C2F4 8024DA14 24020001 */   addiu    $v0, $zero, 1
dlabel L8024DA18_17C2F8
/* 17C2F8 8024DA18 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C2FC 8024DA1C 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C300 8024DA20 2402012C */  addiu     $v0, $zero, 0x12c
/* 17C304 8024DA24 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C308 8024DA28 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C30C 8024DA2C 24020008 */  addiu     $v0, $zero, 8
/* 17C310 8024DA30 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C314 8024DA34 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C318 8024DA38 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C31C 8024DA3C A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C320 8024DA40 24020010 */  addiu     $v0, $zero, 0x10
/* 17C324 8024DA44 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C328 8024DA48 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C32C 8024DA4C 24020001 */  addiu     $v0, $zero, 1
/* 17C330 8024DA50 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C334 8024DA54 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C338 8024DA58 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C33C 8024DA5C A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17C340 8024DA60 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C344 8024DA64 A020F2A2 */  sb        $zero, %lo(D_8029F2A2)($at)
.L8024DA68:
/* 17C348 8024DA68 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C34C 8024DA6C A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17C350 8024DA70 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17C354 8024DA74 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17C358 8024DA78 080938DD */  j         .L8024E374
/* 17C35C 8024DA7C 00000000 */   nop
dlabel L8024DA80_17C360
/* 17C360 8024DA80 3C108028 */  lui       $s0, %hi(CamPreset_N)
/* 17C364 8024DA84 26100D90 */  addiu     $s0, $s0, %lo(CamPreset_N)
/* 17C368 8024DA88 3C014270 */  lui       $at, 0x4270
/* 17C36C 8024DA8C 44810000 */  mtc1      $at, $f0
/* 17C370 8024DA90 3C014220 */  lui       $at, 0x4220
/* 17C374 8024DA94 44811000 */  mtc1      $at, $f2
/* 17C378 8024DA98 240201AE */  addiu     $v0, $zero, 0x1ae
/* 17C37C 8024DA9C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C380 8024DAA0 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C384 8024DAA4 24020008 */  addiu     $v0, $zero, 8
/* 17C388 8024DAA8 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C38C 8024DAAC A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C390 8024DAB0 2402000A */  addiu     $v0, $zero, 0xa
/* 17C394 8024DAB4 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C398 8024DAB8 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C39C 8024DABC 24020010 */  addiu     $v0, $zero, 0x10
/* 17C3A0 8024DAC0 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C3A4 8024DAC4 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C3A8 8024DAC8 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C3AC 8024DACC A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C3B0 8024DAD0 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C3B4 8024DAD4 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17C3B8 8024DAD8 08093827 */  j         .L8024E09C
/* 17C3BC 8024DADC 00000000 */   nop
dlabel L8024DAE0_17C3C0
/* 17C3C0 8024DAE0 3C108028 */  lui       $s0, %hi(CamPreset_N)
/* 17C3C4 8024DAE4 26100D90 */  addiu     $s0, $s0, %lo(CamPreset_N)
/* 17C3C8 8024DAE8 3C014270 */  lui       $at, 0x4270
/* 17C3CC 8024DAEC 44810000 */  mtc1      $at, $f0
/* 17C3D0 8024DAF0 3C014220 */  lui       $at, 0x4220
/* 17C3D4 8024DAF4 44811000 */  mtc1      $at, $f2
/* 17C3D8 8024DAF8 240201CC */  addiu     $v0, $zero, 0x1cc
/* 17C3DC 8024DAFC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C3E0 8024DB00 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C3E4 8024DB04 24020008 */  addiu     $v0, $zero, 8
/* 17C3E8 8024DB08 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C3EC 8024DB0C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C3F0 8024DB10 2402000A */  addiu     $v0, $zero, 0xa
/* 17C3F4 8024DB14 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C3F8 8024DB18 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C3FC 8024DB1C 2402001B */  addiu     $v0, $zero, 0x1b
/* 17C400 8024DB20 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C404 8024DB24 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C408 8024DB28 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C40C 8024DB2C A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C410 8024DB30 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C414 8024DB34 A420F27C */  sh        $zero, %lo(D_8029F27C)($at)
/* 17C418 8024DB38 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C41C 8024DB3C A020F2A2 */  sb        $zero, %lo(D_8029F2A2)($at)
/* 17C420 8024DB40 0809382B */  j         .L8024E0AC
/* 17C424 8024DB44 00000000 */   nop
dlabel L8024DB48_17C428
/* 17C428 8024DB48 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17C42C 8024DB4C 26100E00 */  addiu     $s0, $s0, %lo(CamPreset_J)
/* 17C430 8024DB50 3C01C28C */  lui       $at, 0xc28c
/* 17C434 8024DB54 44816000 */  mtc1      $at, $f12
/* 17C438 8024DB58 44800000 */  mtc1      $zero, $f0
/* 17C43C 8024DB5C 24020186 */  addiu     $v0, $zero, 0x186
/* 17C440 8024DB60 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C444 8024DB64 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C448 8024DB68 44060000 */  mfc1      $a2, $f0
/* 17C44C 8024DB6C 24020008 */  addiu     $v0, $zero, 8
/* 17C450 8024DB70 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C454 8024DB74 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C458 8024DB78 44867000 */  mtc1      $a2, $f14
/* 17C45C 8024DB7C 2402002D */  addiu     $v0, $zero, 0x2d
/* 17C460 8024DB80 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C464 8024DB84 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C468 8024DB88 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C46C 8024DB8C A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C470 8024DB90 0C093948 */  jal       btl_cam_set_target_pos
/* 17C474 8024DB94 00000000 */   nop
/* 17C478 8024DB98 08093710 */  j         .L8024DC40
/* 17C47C 8024DB9C 2402000A */   addiu    $v0, $zero, 0xa
dlabel L8024DBA0_17C480
/* 17C480 8024DBA0 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17C484 8024DBA4 26100E00 */  addiu     $s0, $s0, %lo(CamPreset_J)
/* 17C488 8024DBA8 44806000 */  mtc1      $zero, $f12
/* 17C48C 8024DBAC 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 17C490 8024DBB0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C494 8024DBB4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C498 8024DBB8 24020008 */  addiu     $v0, $zero, 8
/* 17C49C 8024DBBC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C4A0 8024DBC0 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C4A4 8024DBC4 2402002D */  addiu     $v0, $zero, 0x2d
/* 17C4A8 8024DBC8 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C4AC 8024DBCC A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C4B0 8024DBD0 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C4B4 8024DBD4 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C4B8 8024DBD8 44066000 */  mfc1      $a2, $f12
/* 17C4BC 8024DBDC 0C093948 */  jal       btl_cam_set_target_pos
/* 17C4C0 8024DBE0 46006386 */   mov.s    $f14, $f12
/* 17C4C4 8024DBE4 08093710 */  j         .L8024DC40
/* 17C4C8 8024DBE8 24020028 */   addiu    $v0, $zero, 0x28
dlabel L8024DBEC_17C4CC
/* 17C4CC 8024DBEC 3C108028 */  lui       $s0, %hi(CamPreset_J)
/* 17C4D0 8024DBF0 26100E00 */  addiu     $s0, $s0, %lo(CamPreset_J)
/* 17C4D4 8024DBF4 3C01C248 */  lui       $at, 0xc248
/* 17C4D8 8024DBF8 44816000 */  mtc1      $at, $f12
/* 17C4DC 8024DBFC 44800000 */  mtc1      $zero, $f0
/* 17C4E0 8024DC00 2402012C */  addiu     $v0, $zero, 0x12c
/* 17C4E4 8024DC04 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C4E8 8024DC08 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C4EC 8024DC0C 44060000 */  mfc1      $a2, $f0
/* 17C4F0 8024DC10 24020008 */  addiu     $v0, $zero, 8
/* 17C4F4 8024DC14 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C4F8 8024DC18 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C4FC 8024DC1C 44867000 */  mtc1      $a2, $f14
/* 17C500 8024DC20 2402002D */  addiu     $v0, $zero, 0x2d
/* 17C504 8024DC24 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C508 8024DC28 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C50C 8024DC2C 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C510 8024DC30 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C514 8024DC34 0C093948 */  jal       btl_cam_set_target_pos
/* 17C518 8024DC38 00000000 */   nop
/* 17C51C 8024DC3C 24020014 */  addiu     $v0, $zero, 0x14
.L8024DC40:
/* 17C520 8024DC40 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C524 8024DC44 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C528 8024DC48 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17C52C 8024DC4C A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17C530 8024DC50 080938DD */  j         .L8024E374
/* 17C534 8024DC54 00000000 */   nop
dlabel L8024DC58_17C538
/* 17C538 8024DC58 3C108028 */  lui       $s0, %hi(CamPreset_N)
/* 17C53C 8024DC5C 26100D90 */  addiu     $s0, $s0, %lo(CamPreset_N)
/* 17C540 8024DC60 3C01C296 */  lui       $at, 0xc296
/* 17C544 8024DC64 44810000 */  mtc1      $at, $f0
/* 17C548 8024DC68 3C014316 */  lui       $at, 0x4316
/* 17C54C 8024DC6C 44811000 */  mtc1      $at, $f2
/* 17C550 8024DC70 240200A6 */  addiu     $v0, $zero, 0xa6
/* 17C554 8024DC74 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C558 8024DC78 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C55C 8024DC7C 24020008 */  addiu     $v0, $zero, 8
/* 17C560 8024DC80 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C564 8024DC84 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C568 8024DC88 24020001 */  addiu     $v0, $zero, 1
/* 17C56C 8024DC8C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C570 8024DC90 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C574 8024DC94 08093823 */  j         .L8024E08C
/* 17C578 8024DC98 24020011 */   addiu    $v0, $zero, 0x11
dlabel L8024DC9C_17C57C
/* 17C57C 8024DC9C 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C580 8024DCA0 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C584 8024DCA4 24020136 */  addiu     $v0, $zero, 0x136
/* 17C588 8024DCA8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C58C 8024DCAC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C590 8024DCB0 24020008 */  addiu     $v0, $zero, 8
/* 17C594 8024DCB4 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C598 8024DCB8 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C59C 8024DCBC 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C5A0 8024DCC0 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C5A4 8024DCC4 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C5A8 8024DCC8 24020010 */  addiu     $v0, $zero, 0x10
/* 17C5AC 8024DCCC 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C5B0 8024DCD0 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C5B4 8024DCD4 24020001 */  addiu     $v0, $zero, 1
/* 17C5B8 8024DCD8 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C5BC 8024DCDC A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C5C0 8024DCE0 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C5C4 8024DCE4 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17C5C8 8024DCE8 08093849 */  j         .L8024E124
/* 17C5CC 8024DCEC 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DCF0_17C5D0
/* 17C5D0 8024DCF0 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C5D4 8024DCF4 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C5D8 8024DCF8 240200FA */  addiu     $v0, $zero, 0xfa
/* 17C5DC 8024DCFC 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C5E0 8024DD00 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C5E4 8024DD04 24020008 */  addiu     $v0, $zero, 8
/* 17C5E8 8024DD08 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C5EC 8024DD0C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C5F0 8024DD10 24020078 */  addiu     $v0, $zero, 0x78
/* 17C5F4 8024DD14 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C5F8 8024DD18 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C5FC 8024DD1C 24020010 */  addiu     $v0, $zero, 0x10
/* 17C600 8024DD20 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C604 8024DD24 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C608 8024DD28 24020001 */  addiu     $v0, $zero, 1
/* 17C60C 8024DD2C 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C610 8024DD30 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C614 8024DD34 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C618 8024DD38 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17C61C 8024DD3C 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17C620 8024DD40 A022F2A5 */  sb        $v0, %lo(D_8029F2A5)($at)
/* 17C624 8024DD44 080937CF */  j         .L8024DF3C
/* 17C628 8024DD48 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DD4C_17C62C
/* 17C62C 8024DD4C 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17C630 8024DD50 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17C634 8024DD54 2402012C */  addiu     $v0, $zero, 0x12c
/* 17C638 8024DD58 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C63C 8024DD5C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C640 8024DD60 24020008 */  addiu     $v0, $zero, 8
/* 17C644 8024DD64 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C648 8024DD68 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C64C 8024DD6C 24020078 */  addiu     $v0, $zero, 0x78
/* 17C650 8024DD70 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C654 8024DD74 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C658 8024DD78 24020010 */  addiu     $v0, $zero, 0x10
/* 17C65C 8024DD7C 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C660 8024DD80 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C664 8024DD84 24020001 */  addiu     $v0, $zero, 1
/* 17C668 8024DD88 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C66C 8024DD8C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C670 8024DD90 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C674 8024DD94 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17C678 8024DD98 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17C67C 8024DD9C A022F2A5 */  sb        $v0, %lo(D_8029F2A5)($at)
/* 17C680 8024DDA0 080937CF */  j         .L8024DF3C
/* 17C684 8024DDA4 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DDA8_17C688
/* 17C688 8024DDA8 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C68C 8024DDAC 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C690 8024DDB0 24020140 */  addiu     $v0, $zero, 0x140
/* 17C694 8024DDB4 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C698 8024DDB8 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C69C 8024DDBC 24020008 */  addiu     $v0, $zero, 8
/* 17C6A0 8024DDC0 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C6A4 8024DDC4 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C6A8 8024DDC8 24020005 */  addiu     $v0, $zero, 5
/* 17C6AC 8024DDCC 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C6B0 8024DDD0 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C6B4 8024DDD4 24020001 */  addiu     $v0, $zero, 1
/* 17C6B8 8024DDD8 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C6BC 8024DDDC A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C6C0 8024DDE0 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C6C4 8024DDE4 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C6C8 8024DDE8 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C6CC 8024DDEC A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17C6D0 8024DDF0 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C6D4 8024DDF4 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C6D8 8024DDF8 0809384B */  j         .L8024E12C
/* 17C6DC 8024DDFC 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DE00_17C6E0
/* 17C6E0 8024DE00 3C108028 */  lui       $s0, %hi(CamPreset_D)
/* 17C6E4 8024DE04 26100DC8 */  addiu     $s0, $s0, %lo(CamPreset_D)
/* 17C6E8 8024DE08 24020032 */  addiu     $v0, $zero, 0x32
/* 17C6EC 8024DE0C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C6F0 8024DE10 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C6F4 8024DE14 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 17C6F8 8024DE18 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C6FC 8024DE1C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C700 8024DE20 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C704 8024DE24 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17C708 8024DE28 080938DD */  j         .L8024E374
/* 17C70C 8024DE2C 00000000 */   nop
dlabel L8024DE30_17C710
/* 17C710 8024DE30 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C714 8024DE34 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C718 8024DE38 24020118 */  addiu     $v0, $zero, 0x118
/* 17C71C 8024DE3C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C720 8024DE40 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C724 8024DE44 24020008 */  addiu     $v0, $zero, 8
/* 17C728 8024DE48 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C72C 8024DE4C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C730 8024DE50 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C734 8024DE54 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C738 8024DE58 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C73C 8024DE5C 2402FFFC */  addiu     $v0, $zero, -4
/* 17C740 8024DE60 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C744 8024DE64 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C748 8024DE68 24020001 */  addiu     $v0, $zero, 1
/* 17C74C 8024DE6C 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C750 8024DE70 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C754 8024DE74 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C758 8024DE78 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C75C 8024DE7C 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C760 8024DE80 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C764 8024DE84 080937D1 */  j         .L8024DF44
/* 17C768 8024DE88 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DE8C_17C76C
/* 17C76C 8024DE8C 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C770 8024DE90 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C774 8024DE94 2402017C */  addiu     $v0, $zero, 0x17c
/* 17C778 8024DE98 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C77C 8024DE9C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C780 8024DEA0 24020008 */  addiu     $v0, $zero, 8
/* 17C784 8024DEA4 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C788 8024DEA8 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C78C 8024DEAC 2402003C */  addiu     $v0, $zero, 0x3c
/* 17C790 8024DEB0 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C794 8024DEB4 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C798 8024DEB8 24020001 */  addiu     $v0, $zero, 1
/* 17C79C 8024DEBC 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C7A0 8024DEC0 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C7A4 8024DEC4 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17C7A8 8024DEC8 A022F2A5 */  sb        $v0, %lo(D_8029F2A5)($at)
/* 17C7AC 8024DECC 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C7B0 8024DED0 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C7B4 8024DED4 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C7B8 8024DED8 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17C7BC 8024DEDC 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C7C0 8024DEE0 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C7C4 8024DEE4 080937D1 */  j         .L8024DF44
/* 17C7C8 8024DEE8 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DEEC_17C7CC
/* 17C7CC 8024DEEC 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17C7D0 8024DEF0 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17C7D4 8024DEF4 240200DC */  addiu     $v0, $zero, 0xdc
/* 17C7D8 8024DEF8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C7DC 8024DEFC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C7E0 8024DF00 24020008 */  addiu     $v0, $zero, 8
/* 17C7E4 8024DF04 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C7E8 8024DF08 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C7EC 8024DF0C 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C7F0 8024DF10 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C7F4 8024DF14 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C7F8 8024DF18 24020018 */  addiu     $v0, $zero, 0x18
/* 17C7FC 8024DF1C 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C800 8024DF20 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C804 8024DF24 24020001 */  addiu     $v0, $zero, 1
/* 17C808 8024DF28 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C80C 8024DF2C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C810 8024DF30 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C814 8024DF34 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17C818 8024DF38 24020100 */  addiu     $v0, $zero, 0x100
.L8024DF3C:
/* 17C81C 8024DF3C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C820 8024DF40 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
.L8024DF44:
/* 17C824 8024DF44 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17C828 8024DF48 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17C82C 8024DF4C 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C830 8024DF50 A422F27C */  sh        $v0, %lo(D_8029F27C)($at)
/* 17C834 8024DF54 080938DD */  j         .L8024E374
/* 17C838 8024DF58 00000000 */   nop
dlabel L8024DF5C_17C83C
/* 17C83C 8024DF5C 3C108028 */  lui       $s0, %hi(CamPreset_N)
/* 17C840 8024DF60 26100D90 */  addiu     $s0, $s0, %lo(CamPreset_N)
/* 17C844 8024DF64 3C01C2BE */  lui       $at, 0xc2be
/* 17C848 8024DF68 44810000 */  mtc1      $at, $f0
/* 17C84C 8024DF6C 3C0141B0 */  lui       $at, 0x41b0
/* 17C850 8024DF70 44811000 */  mtc1      $at, $f2
/* 17C854 8024DF74 240200D2 */  addiu     $v0, $zero, 0xd2
/* 17C858 8024DF78 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C85C 8024DF7C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C860 8024DF80 24020008 */  addiu     $v0, $zero, 8
/* 17C864 8024DF84 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C868 8024DF88 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C86C 8024DF8C 08093820 */  j         .L8024E080
/* 17C870 8024DF90 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024DF94_17C874
/* 17C874 8024DF94 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C878 8024DF98 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C87C 8024DF9C 24020140 */  addiu     $v0, $zero, 0x140
/* 17C880 8024DFA0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C884 8024DFA4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C888 8024DFA8 24020008 */  addiu     $v0, $zero, 8
/* 17C88C 8024DFAC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C890 8024DFB0 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C894 8024DFB4 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C898 8024DFB8 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C89C 8024DFBC A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C8A0 8024DFC0 2402FFFC */  addiu     $v0, $zero, -4
/* 17C8A4 8024DFC4 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C8A8 8024DFC8 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C8AC 8024DFCC 24020001 */  addiu     $v0, $zero, 1
/* 17C8B0 8024DFD0 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C8B4 8024DFD4 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C8B8 8024DFD8 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C8BC 8024DFDC A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C8C0 8024DFE0 0809380D */  j         .L8024E034
/* 17C8C4 8024DFE4 24020100 */   addiu    $v0, $zero, 0x100
dlabel L8024DFE8_17C8C8
/* 17C8C8 8024DFE8 3C108028 */  lui       $s0, %hi(CamPreset_M)
/* 17C8CC 8024DFEC 26100D20 */  addiu     $s0, $s0, %lo(CamPreset_M)
/* 17C8D0 8024DFF0 24020140 */  addiu     $v0, $zero, 0x140
/* 17C8D4 8024DFF4 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C8D8 8024DFF8 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C8DC 8024DFFC 24020008 */  addiu     $v0, $zero, 8
/* 17C8E0 8024E000 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C8E4 8024E004 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C8E8 8024E008 2402001E */  addiu     $v0, $zero, 0x1e
/* 17C8EC 8024E00C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C8F0 8024E010 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C8F4 8024E014 24020001 */  addiu     $v0, $zero, 1
/* 17C8F8 8024E018 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C8FC 8024E01C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C900 8024E020 24020100 */  addiu     $v0, $zero, 0x100
/* 17C904 8024E024 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C908 8024E028 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17C90C 8024E02C 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C910 8024E030 A420F286 */  sh        $zero, %lo(D_8029F286)($at)
.L8024E034:
/* 17C914 8024E034 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C918 8024E038 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17C91C 8024E03C 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17C920 8024E040 A422F27C */  sh        $v0, %lo(D_8029F27C)($at)
/* 17C924 8024E044 080938DD */  j         .L8024E374
/* 17C928 8024E048 00000000 */   nop
dlabel L8024E04C_17C92C
/* 17C92C 8024E04C 3C108028 */  lui       $s0, %hi(CamPreset_N)
/* 17C930 8024E050 26100D90 */  addiu     $s0, $s0, %lo(CamPreset_N)
/* 17C934 8024E054 3C0141C8 */  lui       $at, 0x41c8
/* 17C938 8024E058 44810000 */  mtc1      $at, $f0
/* 17C93C 8024E05C 3C014270 */  lui       $at, 0x4270
/* 17C940 8024E060 44811000 */  mtc1      $at, $f2
/* 17C944 8024E064 24020190 */  addiu     $v0, $zero, 0x190
/* 17C948 8024E068 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C94C 8024E06C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C950 8024E070 24020008 */  addiu     $v0, $zero, 8
/* 17C954 8024E074 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C958 8024E078 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C95C 8024E07C 2402001E */  addiu     $v0, $zero, 0x1e
.L8024E080:
/* 17C960 8024E080 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C964 8024E084 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C968 8024E088 2402000A */  addiu     $v0, $zero, 0xa
.L8024E08C:
/* 17C96C 8024E08C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17C970 8024E090 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
.L8024E094:
/* 17C974 8024E094 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C978 8024E098 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
.L8024E09C:
/* 17C97C 8024E09C 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C980 8024E0A0 A020F2A2 */  sb        $zero, %lo(D_8029F2A2)($at)
/* 17C984 8024E0A4 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C988 8024E0A8 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
.L8024E0AC:
/* 17C98C 8024E0AC 3C01802A */  lui       $at, %hi(D_8029F278)
/* 17C990 8024E0B0 AC20F278 */  sw        $zero, %lo(D_8029F278)($at)
/* 17C994 8024E0B4 3C01802A */  lui       $at, %hi(D_8029F270)
/* 17C998 8024E0B8 E420F270 */  swc1      $f0, %lo(D_8029F270)($at)
/* 17C99C 8024E0BC 3C01802A */  lui       $at, %hi(D_8029F274)
/* 17C9A0 8024E0C0 E422F274 */  swc1      $f2, %lo(D_8029F274)($at)
/* 17C9A4 8024E0C4 080938DD */  j         .L8024E374
/* 17C9A8 8024E0C8 00000000 */   nop
dlabel L8024E0CC_17C9AC
/* 17C9AC 8024E0CC 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17C9B0 8024E0D0 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17C9B4 8024E0D4 240200C8 */  addiu     $v0, $zero, 0xc8
/* 17C9B8 8024E0D8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17C9BC 8024E0DC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17C9C0 8024E0E0 24020008 */  addiu     $v0, $zero, 8
/* 17C9C4 8024E0E4 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17C9C8 8024E0E8 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17C9CC 8024E0EC 2402003C */  addiu     $v0, $zero, 0x3c
/* 17C9D0 8024E0F0 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17C9D4 8024E0F4 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17C9D8 8024E0F8 2402000B */  addiu     $v0, $zero, 0xb
/* 17C9DC 8024E0FC 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17C9E0 8024E100 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17C9E4 8024E104 24020001 */  addiu     $v0, $zero, 1
/* 17C9E8 8024E108 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17C9EC 8024E10C A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17C9F0 8024E110 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17C9F4 8024E114 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17C9F8 8024E118 3C01802A */  lui       $at, %hi(D_8029F2A5)
/* 17C9FC 8024E11C A022F2A5 */  sb        $v0, %lo(D_8029F2A5)($at)
/* 17CA00 8024E120 24020100 */  addiu     $v0, $zero, 0x100
.L8024E124:
/* 17CA04 8024E124 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17CA08 8024E128 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
.L8024E12C:
/* 17CA0C 8024E12C 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17CA10 8024E130 A422F27C */  sh        $v0, %lo(D_8029F27C)($at)
/* 17CA14 8024E134 3C01802A */  lui       $at, %hi(D_8029F2A6)
/* 17CA18 8024E138 A020F2A6 */  sb        $zero, %lo(D_8029F2A6)($at)
/* 17CA1C 8024E13C 080938DD */  j         .L8024E374
/* 17CA20 8024E140 00000000 */   nop
dlabel L8024E144_17CA24
/* 17CA24 8024E144 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17CA28 8024E148 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17CA2C 8024E14C 2402012C */  addiu     $v0, $zero, 0x12c
/* 17CA30 8024E150 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CA34 8024E154 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CA38 8024E158 24020008 */  addiu     $v0, $zero, 8
/* 17CA3C 8024E15C 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CA40 8024E160 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CA44 8024E164 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CA48 8024E168 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17CA4C 8024E16C 24020010 */  addiu     $v0, $zero, 0x10
/* 17CA50 8024E170 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17CA54 8024E174 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17CA58 8024E178 24020100 */  addiu     $v0, $zero, 0x100
/* 17CA5C 8024E17C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17CA60 8024E180 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17CA64 8024E184 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17CA68 8024E188 A422F27C */  sh        $v0, %lo(D_8029F27C)($at)
/* 17CA6C 8024E18C 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17CA70 8024E190 A020F2A2 */  sb        $zero, %lo(D_8029F2A2)($at)
/* 17CA74 8024E194 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17CA78 8024E198 A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17CA7C 8024E19C 080938DD */  j         .L8024E374
/* 17CA80 8024E1A0 00000000 */   nop
dlabel L8024E1A4_17CA84
/* 17CA84 8024E1A4 3C108028 */  lui       $s0, %hi(CamPreset_I)
/* 17CA88 8024E1A8 26100D58 */  addiu     $s0, $s0, %lo(CamPreset_I)
/* 17CA8C 8024E1AC 2402012C */  addiu     $v0, $zero, 0x12c
/* 17CA90 8024E1B0 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CA94 8024E1B4 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CA98 8024E1B8 24020008 */  addiu     $v0, $zero, 8
/* 17CA9C 8024E1BC 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CAA0 8024E1C0 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CAA4 8024E1C4 2402000F */  addiu     $v0, $zero, 0xf
/* 17CAA8 8024E1C8 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CAAC 8024E1CC A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17CAB0 8024E1D0 2402FFE0 */  addiu     $v0, $zero, -0x20
/* 17CAB4 8024E1D4 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17CAB8 8024E1D8 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17CABC 8024E1DC 24020014 */  addiu     $v0, $zero, 0x14
/* 17CAC0 8024E1E0 3C01802A */  lui       $at, %hi(D_8029F2A7)
/* 17CAC4 8024E1E4 A022F2A7 */  sb        $v0, %lo(D_8029F2A7)($at)
/* 17CAC8 8024E1E8 24020001 */  addiu     $v0, $zero, 1
/* 17CACC 8024E1EC 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17CAD0 8024E1F0 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17CAD4 8024E1F4 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17CAD8 8024E1F8 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
/* 17CADC 8024E1FC 24020100 */  addiu     $v0, $zero, 0x100
/* 17CAE0 8024E200 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17CAE4 8024E204 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17CAE8 8024E208 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17CAEC 8024E20C A422F27C */  sh        $v0, %lo(D_8029F27C)($at)
/* 17CAF0 8024E210 080938DD */  j         .L8024E374
/* 17CAF4 8024E214 00000000 */   nop
dlabel L8024E218_17CAF8
/* 17CAF8 8024E218 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17CAFC 8024E21C 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17CB00 8024E220 24020190 */  addiu     $v0, $zero, 0x190
/* 17CB04 8024E224 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CB08 8024E228 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CB0C 8024E22C 24020008 */  addiu     $v0, $zero, 8
/* 17CB10 8024E230 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CB14 8024E234 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CB18 8024E238 24020014 */  addiu     $v0, $zero, 0x14
/* 17CB1C 8024E23C 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CB20 8024E240 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17CB24 8024E244 080938D4 */  j         .L8024E350
/* 17CB28 8024E248 2402001B */   addiu    $v0, $zero, 0x1b
dlabel L8024E24C_17CB2C
/* 17CB2C 8024E24C 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17CB30 8024E250 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17CB34 8024E254 24020166 */  addiu     $v0, $zero, 0x166
/* 17CB38 8024E258 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CB3C 8024E25C A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CB40 8024E260 24020008 */  addiu     $v0, $zero, 8
/* 17CB44 8024E264 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CB48 8024E268 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CB4C 8024E26C 080938B0 */  j         .L8024E2C0
/* 17CB50 8024E270 2402000A */   addiu    $v0, $zero, 0xa
dlabel L8024E274_17CB54
/* 17CB54 8024E274 3C108028 */  lui       $s0, %hi(CamPreset_C)
/* 17CB58 8024E278 26100DAC */  addiu     $s0, $s0, %lo(CamPreset_C)
/* 17CB5C 8024E27C 24020032 */  addiu     $v0, $zero, 0x32
/* 17CB60 8024E280 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CB64 8024E284 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17CB68 8024E288 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 17CB6C 8024E28C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CB70 8024E290 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CB74 8024E294 080938DD */  j         .L8024E374
/* 17CB78 8024E298 00000000 */   nop
dlabel L8024E29C_17CB7C
/* 17CB7C 8024E29C 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17CB80 8024E2A0 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17CB84 8024E2A4 2402010B */  addiu     $v0, $zero, 0x10b
/* 17CB88 8024E2A8 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CB8C 8024E2AC A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CB90 8024E2B0 24020008 */  addiu     $v0, $zero, 8
/* 17CB94 8024E2B4 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CB98 8024E2B8 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CB9C 8024E2BC 24020014 */  addiu     $v0, $zero, 0x14
.L8024E2C0:
/* 17CBA0 8024E2C0 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CBA4 8024E2C4 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17CBA8 8024E2C8 24020010 */  addiu     $v0, $zero, 0x10
/* 17CBAC 8024E2CC 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17CBB0 8024E2D0 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17CBB4 8024E2D4 24020001 */  addiu     $v0, $zero, 1
/* 17CBB8 8024E2D8 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17CBBC 8024E2DC A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17CBC0 8024E2E0 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17CBC4 8024E2E4 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17CBC8 8024E2E8 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17CBCC 8024E2EC A020F2A3 */  sb        $zero, %lo(D_8029F2A3)($at)
/* 17CBD0 8024E2F0 080938DD */  j         .L8024E374
/* 17CBD4 8024E2F4 00000000 */   nop
dlabel L8024E2F8_17CBD8
/* 17CBD8 8024E2F8 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17CBDC 8024E2FC 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17CBE0 8024E300 240200D6 */  addiu     $v0, $zero, 0xd6
/* 17CBE4 8024E304 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CBE8 8024E308 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CBEC 8024E30C 24020008 */  addiu     $v0, $zero, 8
/* 17CBF0 8024E310 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CBF4 8024E314 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CBF8 8024E318 080938D1 */  j         .L8024E344
/* 17CBFC 8024E31C 24020014 */   addiu    $v0, $zero, 0x14
dlabel L8024E320_17CC00
/* 17CC00 8024E320 3C108028 */  lui       $s0, %hi(CamPreset_F)
/* 17CC04 8024E324 26100D04 */  addiu     $s0, $s0, %lo(CamPreset_F)
/* 17CC08 8024E328 2402012C */  addiu     $v0, $zero, 0x12c
/* 17CC0C 8024E32C 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CC10 8024E330 A422F280 */  sh        $v0, %lo(D_8029F280)($at)
/* 17CC14 8024E334 24020008 */  addiu     $v0, $zero, 8
/* 17CC18 8024E338 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17CC1C 8024E33C A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17CC20 8024E340 24020004 */  addiu     $v0, $zero, 4
.L8024E344:
/* 17CC24 8024E344 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CC28 8024E348 A422F29E */  sh        $v0, %lo(D_8029F29E)($at)
/* 17CC2C 8024E34C 24020010 */  addiu     $v0, $zero, 0x10
.L8024E350:
/* 17CC30 8024E350 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17CC34 8024E354 A422F286 */  sh        $v0, %lo(D_8029F286)($at)
/* 17CC38 8024E358 24020001 */  addiu     $v0, $zero, 1
/* 17CC3C 8024E35C 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17CC40 8024E360 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
.L8024E364:
/* 17CC44 8024E364 3C01802A */  lui       $at, %hi(D_8029F2A2)
/* 17CC48 8024E368 A022F2A2 */  sb        $v0, %lo(D_8029F2A2)($at)
/* 17CC4C 8024E36C 3C01802A */  lui       $at, %hi(D_8029F2A3)
/* 17CC50 8024E370 A022F2A3 */  sb        $v0, %lo(D_8029F2A3)($at)
.L8024E374:
/* 17CC54 8024E374 8E4200C4 */  lw        $v0, 0xc4($s2)
/* 17CC58 8024E378 3C018028 */  lui       $at, %hi(D_80280CE4)
/* 17CC5C 8024E37C AC310CE4 */  sw        $s1, %lo(D_80280CE4)($at)
/* 17CC60 8024E380 10400005 */  beqz      $v0, .L8024E398
/* 17CC64 8024E384 0200202D */   daddu    $a0, $s0, $zero
/* 17CC68 8024E388 8E4400C8 */  lw        $a0, 0xc8($s2)
/* 17CC6C 8024E38C 0C0B102B */  jal       kill_script_by_ID
/* 17CC70 8024E390 00000000 */   nop
/* 17CC74 8024E394 0200202D */  daddu     $a0, $s0, $zero
.L8024E398:
/* 17CC78 8024E398 24060020 */  addiu     $a2, $zero, 0x20
/* 17CC7C 8024E39C 3C01802A */  lui       $at, %hi(D_8029F2B4)
/* 17CC80 8024E3A0 AC24F2B4 */  sw        $a0, %lo(D_8029F2B4)($at)
/* 17CC84 8024E3A4 0C0B0CF8 */  jal       start_script
/* 17CC88 8024E3A8 2405000A */   addiu    $a1, $zero, 0xa
/* 17CC8C 8024E3AC AE4200C4 */  sw        $v0, 0xc4($s2)
/* 17CC90 8024E3B0 8C420144 */  lw        $v0, 0x144($v0)
/* 17CC94 8024E3B4 3C01802A */  lui       $at, %hi(D_8029F29C)
/* 17CC98 8024E3B8 A020F29C */  sb        $zero, %lo(D_8029F29C)($at)
/* 17CC9C 8024E3BC AE4200C8 */  sw        $v0, 0xc8($s2)
.L8024E3C0:
/* 17CCA0 8024E3C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 17CCA4 8024E3C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 17CCA8 8024E3C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 17CCAC 8024E3CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 17CCB0 8024E3D0 03E00008 */  jr        $ra
/* 17CCB4 8024E3D4 27BD0020 */   addiu    $sp, $sp, 0x20
