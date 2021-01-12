.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC200_E2C930
/* E2C930 802BC200 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* E2C934 802BC204 AFB600A8 */  sw        $s6, 0xa8($sp)
/* E2C938 802BC208 0080B02D */  daddu     $s6, $a0, $zero
/* E2C93C 802BC20C AFB700AC */  sw        $s7, 0xac($sp)
/* E2C940 802BC210 00C0B82D */  daddu     $s7, $a2, $zero
/* E2C944 802BC214 AFB3009C */  sw        $s3, 0x9c($sp)
/* E2C948 802BC218 0000982D */  daddu     $s3, $zero, $zero
/* E2C94C 802BC21C AFB20098 */  sw        $s2, 0x98($sp)
/* E2C950 802BC220 0260902D */  daddu     $s2, $s3, $zero
/* E2C954 802BC224 27A40050 */  addiu     $a0, $sp, 0x50
/* E2C958 802BC228 AFB400A0 */  sw        $s4, 0xa0($sp)
/* E2C95C 802BC22C 0260A02D */  daddu     $s4, $s3, $zero
/* E2C960 802BC230 AFBF00B0 */  sw        $ra, 0xb0($sp)
/* E2C964 802BC234 AFB500A4 */  sw        $s5, 0xa4($sp)
/* E2C968 802BC238 AFB10094 */  sw        $s1, 0x94($sp)
/* E2C96C 802BC23C AFB00090 */  sw        $s0, 0x90($sp)
/* E2C970 802BC240 8EC20040 */  lw        $v0, 0x40($s6)
/* E2C974 802BC244 0260A82D */  daddu     $s5, $s3, $zero
/* E2C978 802BC248 0040802D */  daddu     $s0, $v0, $zero
/* E2C97C 802BC24C 8EC20044 */  lw        $v0, 0x44($s6)
/* E2C980 802BC250 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2C984 802BC254 00451021 */  addu      $v0, $v0, $a1
/* E2C988 802BC258 AE020000 */  sw        $v0, ($s0)
/* E2C98C 802BC25C 3C02802C */  lui       $v0, %hi(func_802BC974_E2D0A4)
/* E2C990 802BC260 2442C974 */  addiu     $v0, $v0, %lo(func_802BC974_E2D0A4)
/* E2C994 802BC264 AEC2003C */  sw        $v0, 0x3c($s6)
/* E2C998 802BC268 240200FF */  addiu     $v0, $zero, 0xff
/* E2C99C 802BC26C A2C2000B */  sb        $v0, 0xb($s6)
/* E2C9A0 802BC270 C6000004 */  lwc1      $f0, 4($s0)
/* E2C9A4 802BC274 8EC50048 */  lw        $a1, 0x48($s6)
/* E2C9A8 802BC278 8EC70050 */  lw        $a3, 0x50($s6)
/* E2C9AC 802BC27C 44060000 */  mfc1      $a2, $f0
/* E2C9B0 802BC280 0200882D */  daddu     $s1, $s0, $zero
/* E2C9B4 802BC284 0C019E40 */  jal       guTranslateF
/* E2C9B8 802BC288 AEC6004C */   sw       $a2, 0x4c($s6)
.L802BC28C:
/* E2C9BC 802BC28C 32E2FFFF */  andi      $v0, $s7, 0xffff
/* E2C9C0 802BC290 26F70040 */  addiu     $s7, $s7, 0x40
/* E2C9C4 802BC294 8EC50044 */  lw        $a1, 0x44($s6)
/* E2C9C8 802BC298 27A40010 */  addiu     $a0, $sp, 0x10
/* E2C9CC 802BC29C 0C019D60 */  jal       guMtxL2F
/* E2C9D0 802BC2A0 00A22821 */   addu     $a1, $a1, $v0
/* E2C9D4 802BC2A4 27A40050 */  addiu     $a0, $sp, 0x50
/* E2C9D8 802BC2A8 27A50010 */  addiu     $a1, $sp, 0x10
/* E2C9DC 802BC2AC 0C019D80 */  jal       guMtxCatF
/* E2C9E0 802BC2B0 00A0302D */   daddu    $a2, $a1, $zero
/* E2C9E4 802BC2B4 C7A00040 */  lwc1      $f0, 0x40($sp)
/* E2C9E8 802BC2B8 E6000040 */  swc1      $f0, 0x40($s0)
/* E2C9EC 802BC2BC C7A00044 */  lwc1      $f0, 0x44($sp)
/* E2C9F0 802BC2C0 E6000058 */  swc1      $f0, 0x58($s0)
/* E2C9F4 802BC2C4 C7A00048 */  lwc1      $f0, 0x48($sp)
/* E2C9F8 802BC2C8 2E820005 */  sltiu     $v0, $s4, 5
/* E2C9FC 802BC2CC 10400011 */  beqz      $v0, .L802BC314
/* E2CA00 802BC2D0 E6000070 */   swc1     $f0, 0x70($s0)
/* E2CA04 802BC2D4 3C02802C */  lui       $v0, %hi(jtbl_802BCFC0_E2D6F0)
/* E2CA08 802BC2D8 00551021 */  addu      $v0, $v0, $s5
/* E2CA0C 802BC2DC 8C42CFC0 */  lw        $v0, %lo(jtbl_802BCFC0_E2D6F0)($v0)
/* E2CA10 802BC2E0 00400008 */  jr        $v0
/* E2CA14 802BC2E4 00000000 */   nop
glabel L802BC2E8_E2CA18
/* E2CA18 802BC2E8 241300C0 */  addiu     $s3, $zero, 0xc0
/* E2CA1C 802BC2EC 080AF0C5 */  j         .L802BC314
/* E2CA20 802BC2F0 0000902D */   daddu    $s2, $zero, $zero
glabel L802BC2F4_E2CA24
/* E2CA24 802BC2F4 080AF0C4 */  j         .L802BC310
/* E2CA28 802BC2F8 24130060 */   addiu    $s3, $zero, 0x60
glabel L802BC2FC_E2CA2C
/* E2CA2C 802BC2FC 080AF0C4 */  j         .L802BC310
/* E2CA30 802BC300 24130020 */   addiu    $s3, $zero, 0x20
glabel L802BC304_E2CA34
/* E2CA34 802BC304 080AF0C4 */  j         .L802BC310
/* E2CA38 802BC308 241300A0 */   addiu    $s3, $zero, 0xa0
glabel L802BC30C_E2CA3C
/* E2CA3C 802BC30C 241300E0 */  addiu     $s3, $zero, 0xe0
.L802BC310:
/* E2CA40 802BC310 24120014 */  addiu     $s2, $zero, 0x14
.L802BC314:
/* E2CA44 802BC314 24040005 */  addiu     $a0, $zero, 5
/* E2CA48 802BC318 A233000E */  sb        $s3, 0xe($s1)
/* E2CA4C 802BC31C 0C00A67F */  jal       rand_int
/* E2CA50 802BC320 A2320020 */   sb       $s2, 0x20($s1)
/* E2CA54 802BC324 0040182D */  daddu     $v1, $v0, $zero
/* E2CA58 802BC328 32820001 */  andi      $v0, $s4, 1
/* E2CA5C 802BC32C 14400003 */  bnez      $v0, .L802BC33C
/* E2CA60 802BC330 2462000A */   addiu    $v0, $v1, 0xa
/* E2CA64 802BC334 2402FFF6 */  addiu     $v0, $zero, -0xa
/* E2CA68 802BC338 00431023 */  subu      $v0, $v0, $v1
.L802BC33C:
/* E2CA6C 802BC33C 44820000 */  mtc1      $v0, $f0
/* E2CA70 802BC340 00000000 */  nop
/* E2CA74 802BC344 46800020 */  cvt.s.w   $f0, $f0
/* E2CA78 802BC348 E6000028 */  swc1      $f0, 0x28($s0)
/* E2CA7C 802BC34C 26B50004 */  addiu     $s5, $s5, 4
/* E2CA80 802BC350 26940001 */  addiu     $s4, $s4, 1
/* E2CA84 802BC354 3C014120 */  lui       $at, 0x4120
/* E2CA88 802BC358 44810000 */  mtc1      $at, $f0
/* E2CA8C 802BC35C 2A820005 */  slti      $v0, $s4, 5
/* E2CA90 802BC360 E6000088 */  swc1      $f0, 0x88($s0)
/* E2CA94 802BC364 A2200008 */  sb        $zero, 8($s1)
/* E2CA98 802BC368 A2200014 */  sb        $zero, 0x14($s1)
/* E2CA9C 802BC36C A220001A */  sb        $zero, 0x1a($s1)
/* E2CAA0 802BC370 26310001 */  addiu     $s1, $s1, 1
/* E2CAA4 802BC374 1440FFC5 */  bnez      $v0, .L802BC28C
/* E2CAA8 802BC378 26100004 */   addiu    $s0, $s0, 4
/* E2CAAC 802BC37C 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* E2CAB0 802BC380 8FB700AC */  lw        $s7, 0xac($sp)
/* E2CAB4 802BC384 8FB600A8 */  lw        $s6, 0xa8($sp)
/* E2CAB8 802BC388 8FB500A4 */  lw        $s5, 0xa4($sp)
/* E2CABC 802BC38C 8FB400A0 */  lw        $s4, 0xa0($sp)
/* E2CAC0 802BC390 8FB3009C */  lw        $s3, 0x9c($sp)
/* E2CAC4 802BC394 8FB20098 */  lw        $s2, 0x98($sp)
/* E2CAC8 802BC398 8FB10094 */  lw        $s1, 0x94($sp)
/* E2CACC 802BC39C 8FB00090 */  lw        $s0, 0x90($sp)
/* E2CAD0 802BC3A0 03E00008 */  jr        $ra
/* E2CAD4 802BC3A4 27BD00B8 */   addiu    $sp, $sp, 0xb8
