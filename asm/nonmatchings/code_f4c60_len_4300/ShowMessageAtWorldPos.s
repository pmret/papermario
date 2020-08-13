.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ShowMessageAtWorldPos
/* 0F530C 802D095C 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0F5310 802D0960 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0F5314 802D0964 0080982D */  daddu $s3, $a0, $zero
/* 0F5318 802D0968 AFBF0040 */  sw    $ra, 0x40($sp)
/* 0F531C 802D096C AFB20038 */  sw    $s2, 0x38($sp)
/* 0F5320 802D0970 AFB10034 */  sw    $s1, 0x34($sp)
/* 0F5324 802D0974 AFB00030 */  sw    $s0, 0x30($sp)
/* 0F5328 802D0978 10A00034 */  beqz  $a1, .L802D0A4C
/* 0F532C 802D097C 8E70000C */   lw    $s0, 0xc($s3)
/* 0F5330 802D0980 8E050000 */  lw    $a1, ($s0)
/* 0F5334 802D0984 0C0B1EAF */  jal   get_variable
/* 0F5338 802D0988 26100004 */   addiu $s0, $s0, 4
/* 0F533C 802D098C 8E050000 */  lw    $a1, ($s0)
/* 0F5340 802D0990 26100004 */  addiu $s0, $s0, 4
/* 0F5344 802D0994 0260202D */  daddu $a0, $s3, $zero
/* 0F5348 802D0998 0C0B1EAF */  jal   get_variable
/* 0F534C 802D099C 0040882D */   daddu $s1, $v0, $zero
/* 0F5350 802D09A0 8E050000 */  lw    $a1, ($s0)
/* 0F5354 802D09A4 26100004 */  addiu $s0, $s0, 4
/* 0F5358 802D09A8 0260202D */  daddu $a0, $s3, $zero
/* 0F535C 802D09AC 0C0B1EAF */  jal   get_variable
/* 0F5360 802D09B0 0040902D */   daddu $s2, $v0, $zero
/* 0F5364 802D09B4 0260202D */  daddu $a0, $s3, $zero
/* 0F5368 802D09B8 8E050000 */  lw    $a1, ($s0)
/* 0F536C 802D09BC 0C0B1EAF */  jal   get_variable
/* 0F5370 802D09C0 0040802D */   daddu $s0, $v0, $zero
/* 0F5374 802D09C4 0220202D */  daddu $a0, $s1, $zero
/* 0F5378 802D09C8 3C05802E */  lui   $a1, 0x802e
/* 0F537C 802D09CC 24A5B264 */  addiu $a1, $a1, -0x4d9c
/* 0F5380 802D09D0 0040882D */  daddu $s1, $v0, $zero
/* 0F5384 802D09D4 0C049640 */  jal   load_string
/* 0F5388 802D09D8 ACA00000 */   sw    $zero, ($a1)
/* 0F538C 802D09DC 44920000 */  mtc1  $s2, $f0
/* 0F5390 802D09E0 00000000 */  nop   
/* 0F5394 802D09E4 46800020 */  cvt.s.w $f0, $f0
/* 0F5398 802D09E8 44050000 */  mfc1  $a1, $f0
/* 0F539C 802D09EC 44900000 */  mtc1  $s0, $f0
/* 0F53A0 802D09F0 00000000 */  nop   
/* 0F53A4 802D09F4 46800020 */  cvt.s.w $f0, $f0
/* 0F53A8 802D09F8 44060000 */  mfc1  $a2, $f0
/* 0F53AC 802D09FC 44910000 */  mtc1  $s1, $f0
/* 0F53B0 802D0A00 00000000 */  nop   
/* 0F53B4 802D0A04 46800020 */  cvt.s.w $f0, $f0
/* 0F53B8 802D0A08 3C048007 */  lui   $a0, 0x8007
/* 0F53BC 802D0A0C 8C847410 */  lw    $a0, 0x7410($a0)
/* 0F53C0 802D0A10 44070000 */  mfc1  $a3, $f0
/* 0F53C4 802D0A14 3C10802E */  lui   $s0, 0x802e
/* 0F53C8 802D0A18 2610B260 */  addiu $s0, $s0, -0x4da0
/* 0F53CC 802D0A1C AE020000 */  sw    $v0, ($s0)
/* 0F53D0 802D0A20 27A20020 */  addiu $v0, $sp, 0x20
/* 0F53D4 802D0A24 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F53D8 802D0A28 27A20024 */  addiu $v0, $sp, 0x24
/* 0F53DC 802D0A2C AFA20014 */  sw    $v0, 0x14($sp)
/* 0F53E0 802D0A30 27A20028 */  addiu $v0, $sp, 0x28
/* 0F53E4 802D0A34 0C00B94E */  jal   get_screen_coords
/* 0F53E8 802D0A38 AFA20018 */   sw    $v0, 0x18($sp)
/* 0F53EC 802D0A3C 8E040000 */  lw    $a0, ($s0)
/* 0F53F0 802D0A40 8FA50020 */  lw    $a1, 0x20($sp)
/* 0F53F4 802D0A44 0C0496AE */  jal   clamp_printer_coords
/* 0F53F8 802D0A48 8FA60024 */   lw    $a2, 0x24($sp)
.L802D0A4C:
/* 0F53FC 802D0A4C 3C04802E */  lui   $a0, 0x802e
/* 0F5400 802D0A50 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F5404 802D0A54 8C8204FC */  lw    $v0, 0x4fc($a0)
/* 0F5408 802D0A58 30420040 */  andi  $v0, $v0, 0x40
/* 0F540C 802D0A5C 14400007 */  bnez  $v0, .L802D0A7C
/* 0F5410 802D0A60 24020001 */   addiu $v0, $zero, 1
/* 0F5414 802D0A64 3C03802E */  lui   $v1, 0x802e
/* 0F5418 802D0A68 8C63B264 */  lw    $v1, -0x4d9c($v1)
/* 0F541C 802D0A6C 54620003 */  bnel  $v1, $v0, .L802D0A7C
/* 0F5420 802D0A70 0000102D */   daddu $v0, $zero, $zero
/* 0F5424 802D0A74 908304E8 */  lbu   $v1, 0x4e8($a0)
/* 0F5428 802D0A78 AE630084 */  sw    $v1, 0x84($s3)
.L802D0A7C:
/* 0F542C 802D0A7C 8FBF0040 */  lw    $ra, 0x40($sp)
/* 0F5430 802D0A80 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0F5434 802D0A84 8FB20038 */  lw    $s2, 0x38($sp)
/* 0F5438 802D0A88 8FB10034 */  lw    $s1, 0x34($sp)
/* 0F543C 802D0A8C 8FB00030 */  lw    $s0, 0x30($sp)
/* 0F5440 802D0A90 03E00008 */  jr    $ra
/* 0F5444 802D0A94 27BD0048 */   addiu $sp, $sp, 0x48

