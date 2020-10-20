.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F10
/* AEE320 80240F10 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AEE324 80240F14 AFB3001C */  sw        $s3, 0x1c($sp)
/* AEE328 80240F18 0080982D */  daddu     $s3, $a0, $zero
/* AEE32C 80240F1C AFBF0030 */  sw        $ra, 0x30($sp)
/* AEE330 80240F20 AFB7002C */  sw        $s7, 0x2c($sp)
/* AEE334 80240F24 AFB60028 */  sw        $s6, 0x28($sp)
/* AEE338 80240F28 AFB50024 */  sw        $s5, 0x24($sp)
/* AEE33C 80240F2C AFB40020 */  sw        $s4, 0x20($sp)
/* AEE340 80240F30 AFB20018 */  sw        $s2, 0x18($sp)
/* AEE344 80240F34 AFB10014 */  sw        $s1, 0x14($sp)
/* AEE348 80240F38 AFB00010 */  sw        $s0, 0x10($sp)
/* AEE34C 80240F3C F7B80048 */  sdc1      $f24, 0x48($sp)
/* AEE350 80240F40 F7B60040 */  sdc1      $f22, 0x40($sp)
/* AEE354 80240F44 F7B40038 */  sdc1      $f20, 0x38($sp)
/* AEE358 80240F48 8E70000C */  lw        $s0, 0xc($s3)
/* AEE35C 80240F4C 8E050000 */  lw        $a1, ($s0)
/* AEE360 80240F50 0C0B1EAF */  jal       get_variable
/* AEE364 80240F54 26100004 */   addiu    $s0, $s0, 4
/* AEE368 80240F58 8E150000 */  lw        $s5, ($s0)
/* AEE36C 80240F5C 26100004 */  addiu     $s0, $s0, 4
/* AEE370 80240F60 0260202D */  daddu     $a0, $s3, $zero
/* AEE374 80240F64 8E160000 */  lw        $s6, ($s0)
/* AEE378 80240F68 8E170004 */  lw        $s7, 4($s0)
/* AEE37C 80240F6C 0C0B36B0 */  jal       resolve_npc
/* AEE380 80240F70 0040282D */   daddu    $a1, $v0, $zero
/* AEE384 80240F74 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* AEE388 80240F78 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* AEE38C 80240F7C 0040802D */  daddu     $s0, $v0, $zero
/* AEE390 80240F80 1200002F */  beqz      $s0, .L80241040
/* AEE394 80240F84 0220902D */   daddu    $s2, $s1, $zero
/* AEE398 80240F88 C62C0028 */  lwc1      $f12, 0x28($s1)
/* AEE39C 80240F8C C62E0030 */  lwc1      $f14, 0x30($s1)
/* AEE3A0 80240F90 8E060038 */  lw        $a2, 0x38($s0)
/* AEE3A4 80240F94 8E070040 */  lw        $a3, 0x40($s0)
/* AEE3A8 80240F98 3C014248 */  lui       $at, 0x4248
/* AEE3AC 80240F9C 4481C000 */  mtc1      $at, $f24
/* AEE3B0 80240FA0 0C00A7B5 */  jal       dist2D
/* AEE3B4 80240FA4 24140001 */   addiu    $s4, $zero, 1
/* AEE3B8 80240FA8 4618003C */  c.lt.s    $f0, $f24
/* AEE3BC 80240FAC 00000000 */  nop       
/* AEE3C0 80240FB0 45030001 */  bc1tl     .L80240FB8
/* AEE3C4 80240FB4 0000A02D */   daddu    $s4, $zero, $zero
.L80240FB8:
/* AEE3C8 80240FB8 C64C0028 */  lwc1      $f12, 0x28($s2)
/* AEE3CC 80240FBC C64E0030 */  lwc1      $f14, 0x30($s2)
/* AEE3D0 80240FC0 8E060038 */  lw        $a2, 0x38($s0)
/* AEE3D4 80240FC4 0C00A720 */  jal       atan2
/* AEE3D8 80240FC8 8E070040 */   lw       $a3, 0x40($s0)
/* AEE3DC 80240FCC 0C00A6C9 */  jal       clamp_angle
/* AEE3E0 80240FD0 46000306 */   mov.s    $f12, $f0
/* AEE3E4 80240FD4 46000506 */  mov.s     $f20, $f0
/* AEE3E8 80240FD8 0C00A8BB */  jal       sin_deg
/* AEE3EC 80240FDC 4600A306 */   mov.s    $f12, $f20
/* AEE3F0 80240FE0 46180002 */  mul.s     $f0, $f0, $f24
/* AEE3F4 80240FE4 00000000 */  nop       
/* AEE3F8 80240FE8 C6560028 */  lwc1      $f22, 0x28($s2)
/* AEE3FC 80240FEC 4600B580 */  add.s     $f22, $f22, $f0
/* AEE400 80240FF0 0C00A8D4 */  jal       cos_deg
/* AEE404 80240FF4 4600A306 */   mov.s    $f12, $f20
/* AEE408 80240FF8 46180002 */  mul.s     $f0, $f0, $f24
/* AEE40C 80240FFC 00000000 */  nop       
/* AEE410 80241000 0260202D */  daddu     $a0, $s3, $zero
/* AEE414 80241004 02A0282D */  daddu     $a1, $s5, $zero
/* AEE418 80241008 C6540030 */  lwc1      $f20, 0x30($s2)
/* AEE41C 8024100C 0280302D */  daddu     $a2, $s4, $zero
/* AEE420 80241010 0C0B2026 */  jal       set_variable
/* AEE424 80241014 4600A501 */   sub.s    $f20, $f20, $f0
/* AEE428 80241018 0260202D */  daddu     $a0, $s3, $zero
/* AEE42C 8024101C 4600B08D */  trunc.w.s $f2, $f22
/* AEE430 80241020 44061000 */  mfc1      $a2, $f2
/* AEE434 80241024 0C0B2026 */  jal       set_variable
/* AEE438 80241028 02C0282D */   daddu    $a1, $s6, $zero
/* AEE43C 8024102C 0260202D */  daddu     $a0, $s3, $zero
/* AEE440 80241030 4600A08D */  trunc.w.s $f2, $f20
/* AEE444 80241034 44061000 */  mfc1      $a2, $f2
/* AEE448 80241038 0C0B2026 */  jal       set_variable
/* AEE44C 8024103C 02E0282D */   daddu    $a1, $s7, $zero
.L80241040:
/* AEE450 80241040 24020002 */  addiu     $v0, $zero, 2
/* AEE454 80241044 8FBF0030 */  lw        $ra, 0x30($sp)
/* AEE458 80241048 8FB7002C */  lw        $s7, 0x2c($sp)
/* AEE45C 8024104C 8FB60028 */  lw        $s6, 0x28($sp)
/* AEE460 80241050 8FB50024 */  lw        $s5, 0x24($sp)
/* AEE464 80241054 8FB40020 */  lw        $s4, 0x20($sp)
/* AEE468 80241058 8FB3001C */  lw        $s3, 0x1c($sp)
/* AEE46C 8024105C 8FB20018 */  lw        $s2, 0x18($sp)
/* AEE470 80241060 8FB10014 */  lw        $s1, 0x14($sp)
/* AEE474 80241064 8FB00010 */  lw        $s0, 0x10($sp)
/* AEE478 80241068 D7B80048 */  ldc1      $f24, 0x48($sp)
/* AEE47C 8024106C D7B60040 */  ldc1      $f22, 0x40($sp)
/* AEE480 80241070 D7B40038 */  ldc1      $f20, 0x38($sp)
/* AEE484 80241074 03E00008 */  jr        $ra
/* AEE488 80241078 27BD0050 */   addiu    $sp, $sp, 0x50
/* AEE48C 8024107C 00000000 */  nop       
