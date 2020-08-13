.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel AwaitPlayerLeave
/* 0F940C 802D4A5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9410 802D4A60 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9414 802D4A64 0080882D */  daddu $s1, $a0, $zero
/* 0F9418 802D4A68 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F941C 802D4A6C 3C128011 */  lui   $s2, 0x8011
/* 0F9420 802D4A70 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F9424 802D4A74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F9428 802D4A78 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F942C 802D4A7C 10A0000E */  beqz  $a1, .L802D4AB8
/* 0F9430 802D4A80 8E30000C */   lw    $s0, 0xc($s1)
/* 0F9434 802D4A84 8E050000 */  lw    $a1, ($s0)
/* 0F9438 802D4A88 0C0B1EAF */  jal   get_variable
/* 0F943C 802D4A8C 26100004 */   addiu $s0, $s0, 4
/* 0F9440 802D4A90 AE220070 */  sw    $v0, 0x70($s1)
/* 0F9444 802D4A94 8E050000 */  lw    $a1, ($s0)
/* 0F9448 802D4A98 26100004 */  addiu $s0, $s0, 4
/* 0F944C 802D4A9C 0C0B1EAF */  jal   get_variable
/* 0F9450 802D4AA0 0220202D */   daddu $a0, $s1, $zero
/* 0F9454 802D4AA4 AE220074 */  sw    $v0, 0x74($s1)
/* 0F9458 802D4AA8 8E050000 */  lw    $a1, ($s0)
/* 0F945C 802D4AAC 0C0B1EAF */  jal   get_variable
/* 0F9460 802D4AB0 0220202D */   daddu $a0, $s1, $zero
/* 0F9464 802D4AB4 AE220078 */  sw    $v0, 0x78($s1)
.L802D4AB8:
/* 0F9468 802D4AB8 C6240070 */  lwc1  $f4, 0x70($s1)
/* 0F946C 802D4ABC 46802120 */  cvt.s.w $f4, $f4
/* 0F9470 802D4AC0 44062000 */  mfc1  $a2, $f4
/* 0F9474 802D4AC4 C6240074 */  lwc1  $f4, 0x74($s1)
/* 0F9478 802D4AC8 46802120 */  cvt.s.w $f4, $f4
/* 0F947C 802D4ACC C64C0028 */  lwc1  $f12, 0x28($s2)
/* 0F9480 802D4AD0 C64E0030 */  lwc1  $f14, 0x30($s2)
/* 0F9484 802D4AD4 44072000 */  mfc1  $a3, $f4
/* 0F9488 802D4AD8 0C00A7B5 */  jal   dist2D
/* 0F948C 802D4ADC 00000000 */   nop   
/* 0F9490 802D4AE0 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F9494 802D4AE4 468010A0 */  cvt.s.w $f2, $f2
/* 0F9498 802D4AE8 4600103C */  c.lt.s $f2, $f0
/* 0F949C 802D4AEC 00000000 */  nop   
/* 0F94A0 802D4AF0 45010002 */  bc1t  .L802D4AFC
/* 0F94A4 802D4AF4 24020002 */   addiu $v0, $zero, 2
/* 0F94A8 802D4AF8 0000102D */  daddu $v0, $zero, $zero
.L802D4AFC:
/* 0F94AC 802D4AFC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F94B0 802D4B00 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F94B4 802D4B04 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F94B8 802D4B08 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F94BC 802D4B0C 03E00008 */  jr    $ra
/* 0F94C0 802D4B10 27BD0020 */   addiu $sp, $sp, 0x20

