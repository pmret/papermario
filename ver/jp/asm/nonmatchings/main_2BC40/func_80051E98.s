.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80051E98
/* 2D298 80051E98 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2D29C 80051E9C AFB3001C */  sw        $s3, 0x1c($sp)
/* 2D2A0 80051EA0 00A0982D */  daddu     $s3, $a1, $zero
/* 2D2A4 80051EA4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 2D2A8 80051EA8 AFB40020 */  sw        $s4, 0x20($sp)
/* 2D2AC 80051EAC AFB20018 */  sw        $s2, 0x18($sp)
/* 2D2B0 80051EB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 2D2B4 80051EB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 2D2B8 80051EB8 8E700030 */  lw        $s0, 0x30($s3)
/* 2D2BC 80051EBC 8E620034 */  lw        $v0, 0x34($s3)
/* 2D2C0 80051EC0 0202102B */  sltu      $v0, $s0, $v0
/* 2D2C4 80051EC4 1040001C */  beqz      $v0, .L80051F38
/* 2D2C8 80051EC8 0080A02D */   daddu    $s4, $a0, $zero
/* 2D2CC 80051ECC 001010C0 */  sll       $v0, $s0, 3
/* 2D2D0 80051ED0 00501021 */  addu      $v0, $v0, $s0
/* 2D2D4 80051ED4 000210C0 */  sll       $v0, $v0, 3
/* 2D2D8 80051ED8 24521320 */  addiu     $s2, $v0, 0x1320
.L80051EDC:
/* 2D2DC 80051EDC 8E620030 */  lw        $v0, 0x30($s3)
/* 2D2E0 80051EE0 02021023 */  subu      $v0, $s0, $v0
/* 2D2E4 80051EE4 000210C0 */  sll       $v0, $v0, 3
/* 2D2E8 80051EE8 244207B4 */  addiu     $v0, $v0, 0x7b4
/* 2D2EC 80051EEC 02828821 */  addu      $s1, $s4, $v0
/* 2D2F0 80051EF0 92230000 */  lbu       $v1, ($s1)
/* 2D2F4 80051EF4 92620014 */  lbu       $v0, 0x14($s3)
/* 2D2F8 80051EF8 1462000A */  bne       $v1, $v0, .L80051F24
/* 2D2FC 80051EFC 00000000 */   nop
/* 2D300 80051F00 8E820000 */  lw        $v0, ($s4)
/* 2D304 80051F04 00522021 */  addu      $a0, $v0, $s2
/* 2D308 80051F08 90830045 */  lbu       $v1, 0x45($a0)
/* 2D30C 80051F0C 92820022 */  lbu       $v0, 0x22($s4)
/* 2D310 80051F10 54620004 */  bnel      $v1, $v0, .L80051F24
/* 2D314 80051F14 AE200000 */   sw       $zero, ($s1)
/* 2D318 80051F18 0C014D5D */  jal       func_80053574
/* 2D31C 80051F1C 320500FF */   andi     $a1, $s0, 0xff
/* 2D320 80051F20 AE200000 */  sw        $zero, ($s1)
.L80051F24:
/* 2D324 80051F24 8E620034 */  lw        $v0, 0x34($s3)
/* 2D328 80051F28 26100001 */  addiu     $s0, $s0, 1
/* 2D32C 80051F2C 0202102B */  sltu      $v0, $s0, $v0
/* 2D330 80051F30 1440FFEA */  bnez      $v0, .L80051EDC
/* 2D334 80051F34 26520048 */   addiu    $s2, $s2, 0x48
.L80051F38:
/* 2D338 80051F38 8FBF0024 */  lw        $ra, 0x24($sp)
/* 2D33C 80051F3C 8FB40020 */  lw        $s4, 0x20($sp)
/* 2D340 80051F40 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2D344 80051F44 8FB20018 */  lw        $s2, 0x18($sp)
/* 2D348 80051F48 8FB10014 */  lw        $s1, 0x14($sp)
/* 2D34C 80051F4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 2D350 80051F50 03E00008 */  jr        $ra
/* 2D354 80051F54 27BD0028 */   addiu    $sp, $sp, 0x28
