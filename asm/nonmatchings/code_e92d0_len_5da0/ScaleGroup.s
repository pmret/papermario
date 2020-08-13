.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ScaleGroup
/* 0EE3CC 802C9A1C 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0EE3D0 802C9A20 AFB20058 */  sw    $s2, 0x58($sp)
/* 0EE3D4 802C9A24 0080902D */  daddu $s2, $a0, $zero
/* 0EE3D8 802C9A28 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0EE3DC 802C9A2C AFB10054 */  sw    $s1, 0x54($sp)
/* 0EE3E0 802C9A30 AFB00050 */  sw    $s0, 0x50($sp)
/* 0EE3E4 802C9A34 F7B80070 */  sdc1  $f24, 0x70($sp)
/* 0EE3E8 802C9A38 F7B60068 */  sdc1  $f22, 0x68($sp)
/* 0EE3EC 802C9A3C F7B40060 */  sdc1  $f20, 0x60($sp)
/* 0EE3F0 802C9A40 8E50000C */  lw    $s0, 0xc($s2)
/* 0EE3F4 802C9A44 0C0B1EAF */  jal   get_variable
/* 0EE3F8 802C9A48 8E050000 */   lw    $a1, ($s0)
/* 0EE3FC 802C9A4C 0C046C24 */  jal   func_8011B090
/* 0EE400 802C9A50 0040202D */   daddu $a0, $v0, $zero
/* 0EE404 802C9A54 0040882D */  daddu $s1, $v0, $zero
/* 0EE408 802C9A58 2402FFFF */  addiu $v0, $zero, -1
/* 0EE40C 802C9A5C 16220007 */  bne   $s1, $v0, .L802C9A7C
/* 0EE410 802C9A60 26100004 */   addiu $s0, $s0, 4
/* 0EE414 802C9A64 3C04802D */  lui   $a0, 0x802d
/* 0EE418 802C9A68 24848D88 */  addiu $a0, $a0, -0x7278
/* 0EE41C 802C9A6C 0C0B2568 */  jal   func_802C95A0
/* 0EE420 802C9A70 0240282D */   daddu $a1, $s2, $zero
/* 0EE424 802C9A74 080B26C7 */  j     .L802C9B1C
/* 0EE428 802C9A78 24020002 */   addiu $v0, $zero, 2

.L802C9A7C:
/* 0EE42C 802C9A7C 8E050000 */  lw    $a1, ($s0)
/* 0EE430 802C9A80 26100004 */  addiu $s0, $s0, 4
/* 0EE434 802C9A84 0C0B210B */  jal   get_float_variable
/* 0EE438 802C9A88 0240202D */   daddu $a0, $s2, $zero
/* 0EE43C 802C9A8C 8E050000 */  lw    $a1, ($s0)
/* 0EE440 802C9A90 26100004 */  addiu $s0, $s0, 4
/* 0EE444 802C9A94 0240202D */  daddu $a0, $s2, $zero
/* 0EE448 802C9A98 0C0B210B */  jal   get_float_variable
/* 0EE44C 802C9A9C 46000606 */   mov.s $f24, $f0
/* 0EE450 802C9AA0 0240202D */  daddu $a0, $s2, $zero
/* 0EE454 802C9AA4 8E050000 */  lw    $a1, ($s0)
/* 0EE458 802C9AA8 0C0B210B */  jal   get_float_variable
/* 0EE45C 802C9AAC 46000586 */   mov.s $f22, $f0
/* 0EE460 802C9AB0 0220202D */  daddu $a0, $s1, $zero
/* 0EE464 802C9AB4 0C046C70 */  jal   func_8011B1C0
/* 0EE468 802C9AB8 46000506 */   mov.s $f20, $f0
/* 0EE46C 802C9ABC 0040802D */  daddu $s0, $v0, $zero
/* 0EE470 802C9AC0 96020000 */  lhu   $v0, ($s0)
/* 0EE474 802C9AC4 30420400 */  andi  $v0, $v0, 0x400
/* 0EE478 802C9AC8 1440000A */  bnez  $v0, .L802C9AF4
/* 0EE47C 802C9ACC 00000000 */   nop   
/* 0EE480 802C9AD0 4405C000 */  mfc1  $a1, $f24
/* 0EE484 802C9AD4 4406B000 */  mfc1  $a2, $f22
/* 0EE488 802C9AD8 4407A000 */  mfc1  $a3, $f20
/* 0EE48C 802C9ADC 0C019DF0 */  jal   guScaleF
/* 0EE490 802C9AE0 26040050 */   addiu $a0, $s0, 0x50
/* 0EE494 802C9AE4 96020000 */  lhu   $v0, ($s0)
/* 0EE498 802C9AE8 34421400 */  ori   $v0, $v0, 0x1400
/* 0EE49C 802C9AEC 080B26C6 */  j     .L802C9B18
/* 0EE4A0 802C9AF0 A6020000 */   sh    $v0, ($s0)

.L802C9AF4:
/* 0EE4A4 802C9AF4 4405C000 */  mfc1  $a1, $f24
/* 0EE4A8 802C9AF8 4406B000 */  mfc1  $a2, $f22
/* 0EE4AC 802C9AFC 4407A000 */  mfc1  $a3, $f20
/* 0EE4B0 802C9B00 0C019DF0 */  jal   guScaleF
/* 0EE4B4 802C9B04 27A40010 */   addiu $a0, $sp, 0x10
/* 0EE4B8 802C9B08 27A40010 */  addiu $a0, $sp, 0x10
/* 0EE4BC 802C9B0C 26050050 */  addiu $a1, $s0, 0x50
/* 0EE4C0 802C9B10 0C019D80 */  jal   guMtxCatF
/* 0EE4C4 802C9B14 00A0302D */   daddu $a2, $a1, $zero
.L802C9B18:
/* 0EE4C8 802C9B18 24020002 */  addiu $v0, $zero, 2
.L802C9B1C:
/* 0EE4CC 802C9B1C 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0EE4D0 802C9B20 8FB20058 */  lw    $s2, 0x58($sp)
/* 0EE4D4 802C9B24 8FB10054 */  lw    $s1, 0x54($sp)
/* 0EE4D8 802C9B28 8FB00050 */  lw    $s0, 0x50($sp)
/* 0EE4DC 802C9B2C D7B80070 */  ldc1  $f24, 0x70($sp)
/* 0EE4E0 802C9B30 D7B60068 */  ldc1  $f22, 0x68($sp)
/* 0EE4E4 802C9B34 D7B40060 */  ldc1  $f20, 0x60($sp)
/* 0EE4E8 802C9B38 03E00008 */  jr    $ra
/* 0EE4EC 802C9B3C 27BD0078 */   addiu $sp, $sp, 0x78

/* 0EE4F0 802C9B40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EE4F4 802C9B44 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EE4F8 802C9B48 0080882D */  daddu $s1, $a0, $zero
/* 0EE4FC 802C9B4C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EE500 802C9B50 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EE504 802C9B54 8E30000C */  lw    $s0, 0xc($s1)
/* 0EE508 802C9B58 8E050000 */  lw    $a1, ($s0)
/* 0EE50C 802C9B5C 0C0B1EAF */  jal   get_variable
/* 0EE510 802C9B60 26100004 */   addiu $s0, $s0, 4
/* 0EE514 802C9B64 8E100000 */  lw    $s0, ($s0)
/* 0EE518 802C9B68 0C046C24 */  jal   func_8011B090
/* 0EE51C 802C9B6C 0040202D */   daddu $a0, $v0, $zero
/* 0EE520 802C9B70 0220202D */  daddu $a0, $s1, $zero
/* 0EE524 802C9B74 0040302D */  daddu $a2, $v0, $zero
/* 0EE528 802C9B78 0C0B2026 */  jal   set_variable
/* 0EE52C 802C9B7C 0200282D */   daddu $a1, $s0, $zero
/* 0EE530 802C9B80 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EE534 802C9B84 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EE538 802C9B88 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EE53C 802C9B8C 24020002 */  addiu $v0, $zero, 2
/* 0EE540 802C9B90 03E00008 */  jr    $ra
/* 0EE544 802C9B94 27BD0020 */   addiu $sp, $sp, 0x20

