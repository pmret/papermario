.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetActorScale
/* 19B364 8026CA84 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 19B368 8026CA88 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B36C 8026CA8C 0080882D */  daddu $s1, $a0, $zero
/* 19B370 8026CA90 AFBF0018 */  sw    $ra, 0x18($sp)
/* 19B374 8026CA94 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B378 8026CA98 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 19B37C 8026CA9C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 19B380 8026CAA0 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 19B384 8026CAA4 8E30000C */  lw    $s0, 0xc($s1)
/* 19B388 8026CAA8 8E050000 */  lw    $a1, ($s0)
/* 19B38C 8026CAAC 0C0B1EAF */  jal   get_variable
/* 19B390 8026CAB0 26100004 */   addiu $s0, $s0, 4
/* 19B394 8026CAB4 0040202D */  daddu $a0, $v0, $zero
/* 19B398 8026CAB8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B39C 8026CABC 14820002 */  bne   $a0, $v0, .L8026CAC8
/* 19B3A0 8026CAC0 00000000 */   nop   
/* 19B3A4 8026CAC4 8E240148 */  lw    $a0, 0x148($s1)
.L8026CAC8:
/* 19B3A8 8026CAC8 C6140000 */  lwc1  $f20, ($s0)
/* 19B3AC 8026CACC 4680A520 */  cvt.s.w $f20, $f20
/* 19B3B0 8026CAD0 26100004 */  addiu $s0, $s0, 4
/* 19B3B4 8026CAD4 C6160000 */  lwc1  $f22, ($s0)
/* 19B3B8 8026CAD8 4680B5A0 */  cvt.s.w $f22, $f22
/* 19B3BC 8026CADC C6180004 */  lwc1  $f24, 4($s0)
/* 19B3C0 8026CAE0 0C09A75B */  jal   get_actor
/* 19B3C4 8026CAE4 4680C620 */   cvt.s.w $f24, $f24
/* 19B3C8 8026CAE8 0040802D */  daddu $s0, $v0, $zero
/* 19B3CC 8026CAEC 8E060170 */  lw    $a2, 0x170($s0)
/* 19B3D0 8026CAF0 4600A08D */  trunc.w.s $f2, $f20
/* 19B3D4 8026CAF4 44051000 */  mfc1  $a1, $f2
/* 19B3D8 8026CAF8 0C0B2190 */  jal   set_float_variable
/* 19B3DC 8026CAFC 0220202D */   daddu $a0, $s1, $zero
/* 19B3E0 8026CB00 8E060174 */  lw    $a2, 0x174($s0)
/* 19B3E4 8026CB04 4600B08D */  trunc.w.s $f2, $f22
/* 19B3E8 8026CB08 44051000 */  mfc1  $a1, $f2
/* 19B3EC 8026CB0C 0C0B2190 */  jal   set_float_variable
/* 19B3F0 8026CB10 0220202D */   daddu $a0, $s1, $zero
/* 19B3F4 8026CB14 8E060178 */  lw    $a2, 0x178($s0)
/* 19B3F8 8026CB18 4600C08D */  trunc.w.s $f2, $f24
/* 19B3FC 8026CB1C 44051000 */  mfc1  $a1, $f2
/* 19B400 8026CB20 0C0B2190 */  jal   set_float_variable
/* 19B404 8026CB24 0220202D */   daddu $a0, $s1, $zero
/* 19B408 8026CB28 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19B40C 8026CB2C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B410 8026CB30 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B414 8026CB34 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 19B418 8026CB38 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 19B41C 8026CB3C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 19B420 8026CB40 24020002 */  addiu $v0, $zero, 2
/* 19B424 8026CB44 03E00008 */  jr    $ra
/* 19B428 8026CB48 27BD0038 */   addiu $sp, $sp, 0x38

