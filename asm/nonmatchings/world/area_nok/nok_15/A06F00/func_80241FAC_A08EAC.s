.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FAC_A08EAC
/* A08EAC 80241FAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A08EB0 80241FB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* A08EB4 80241FB4 0080982D */  daddu     $s3, $a0, $zero
/* A08EB8 80241FB8 AFBF0020 */  sw        $ra, 0x20($sp)
/* A08EBC 80241FBC AFB20018 */  sw        $s2, 0x18($sp)
/* A08EC0 80241FC0 AFB10014 */  sw        $s1, 0x14($sp)
/* A08EC4 80241FC4 AFB00010 */  sw        $s0, 0x10($sp)
/* A08EC8 80241FC8 8E710148 */  lw        $s1, 0x148($s3)
/* A08ECC 80241FCC 0C00EABB */  jal       get_npc_unsafe
/* A08ED0 80241FD0 86240008 */   lh       $a0, 8($s1)
/* A08ED4 80241FD4 0040802D */  daddu     $s0, $v0, $zero
/* A08ED8 80241FD8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A08EDC 80241FDC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A08EE0 80241FE0 3C01C0A0 */  lui       $at, 0xc0a0
/* A08EE4 80241FE4 44811000 */  mtc1      $at, $f2
/* A08EE8 80241FE8 3C013E19 */  lui       $at, 0x3e19
/* A08EEC 80241FEC 3421999A */  ori       $at, $at, 0x999a
/* A08EF0 80241FF0 44810000 */  mtc1      $at, $f0
/* A08EF4 80241FF4 8C420024 */  lw        $v0, 0x24($v0)
/* A08EF8 80241FF8 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* A08EFC 80241FFC 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* A08F00 80242000 E602001C */  swc1      $f2, 0x1c($s0)
/* A08F04 80242004 E6000014 */  swc1      $f0, 0x14($s0)
/* A08F08 80242008 AE020028 */  sw        $v0, 0x28($s0)
/* A08F0C 8024200C 8E22008C */  lw        $v0, 0x8c($s1)
/* A08F10 80242010 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A08F14 80242014 00021FC2 */  srl       $v1, $v0, 0x1f
/* A08F18 80242018 00431021 */  addu      $v0, $v0, $v1
/* A08F1C 8024201C 8E430000 */  lw        $v1, ($s2)
/* A08F20 80242020 00021043 */  sra       $v0, $v0, 1
/* A08F24 80242024 A60200A8 */  sh        $v0, 0xa8($s0)
/* A08F28 80242028 8C660028 */  lw        $a2, 0x28($v1)
/* A08F2C 8024202C 0C00A7B5 */  jal       dist2D
/* A08F30 80242030 8C670030 */   lw       $a3, 0x30($v1)
/* A08F34 80242034 0200202D */  daddu     $a0, $s0, $zero
/* A08F38 80242038 0000302D */  daddu     $a2, $zero, $zero
/* A08F3C 8024203C C6020038 */  lwc1      $f2, 0x38($s0)
/* A08F40 80242040 3C0140E0 */  lui       $at, 0x40e0
/* A08F44 80242044 44810000 */  mtc1      $at, $f0
/* A08F48 80242048 4600110D */  trunc.w.s $f4, $f2
/* A08F4C 8024204C 44022000 */  mfc1      $v0, $f4
/* A08F50 80242050 E6000018 */  swc1      $f0, 0x18($s0)
/* A08F54 80242054 A6220010 */  sh        $v0, 0x10($s1)
/* A08F58 80242058 C600003C */  lwc1      $f0, 0x3c($s0)
/* A08F5C 8024205C 240502C1 */  addiu     $a1, $zero, 0x2c1
/* A08F60 80242060 4600010D */  trunc.w.s $f4, $f0
/* A08F64 80242064 44022000 */  mfc1      $v0, $f4
/* A08F68 80242068 00000000 */  nop
/* A08F6C 8024206C A6220012 */  sh        $v0, 0x12($s1)
/* A08F70 80242070 C6000040 */  lwc1      $f0, 0x40($s0)
/* A08F74 80242074 24020001 */  addiu     $v0, $zero, 1
/* A08F78 80242078 A2220007 */  sb        $v0, 7($s1)
/* A08F7C 8024207C 4600010D */  trunc.w.s $f4, $f0
/* A08F80 80242080 44022000 */  mfc1      $v0, $f4
/* A08F84 80242084 0C012530 */  jal       func_800494C0
/* A08F88 80242088 A6220014 */   sh       $v0, 0x14($s1)
/* A08F8C 8024208C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A08F90 80242090 8E420000 */  lw        $v0, ($s2)
/* A08F94 80242094 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A08F98 80242098 8C460028 */  lw        $a2, 0x28($v0)
/* A08F9C 8024209C 0C00A720 */  jal       atan2
/* A08FA0 802420A0 8C470030 */   lw       $a3, 0x30($v0)
/* A08FA4 802420A4 2402000C */  addiu     $v0, $zero, 0xc
/* A08FA8 802420A8 A602008E */  sh        $v0, 0x8e($s0)
/* A08FAC 802420AC 2402000D */  addiu     $v0, $zero, 0xd
/* A08FB0 802420B0 E600000C */  swc1      $f0, 0xc($s0)
/* A08FB4 802420B4 AE620070 */  sw        $v0, 0x70($s3)
/* A08FB8 802420B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* A08FBC 802420BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* A08FC0 802420C0 8FB20018 */  lw        $s2, 0x18($sp)
/* A08FC4 802420C4 8FB10014 */  lw        $s1, 0x14($sp)
/* A08FC8 802420C8 8FB00010 */  lw        $s0, 0x10($sp)
/* A08FCC 802420CC 03E00008 */  jr        $ra
/* A08FD0 802420D0 27BD0028 */   addiu    $sp, $sp, 0x28
