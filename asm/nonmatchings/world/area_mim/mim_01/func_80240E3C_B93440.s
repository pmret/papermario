.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E3C_B9427C
/* B9427C 80240E3C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B94280 80240E40 AFB3003C */  sw        $s3, 0x3c($sp)
/* B94284 80240E44 0080982D */  daddu     $s3, $a0, $zero
/* B94288 80240E48 AFBF0040 */  sw        $ra, 0x40($sp)
/* B9428C 80240E4C AFB20038 */  sw        $s2, 0x38($sp)
/* B94290 80240E50 AFB10034 */  sw        $s1, 0x34($sp)
/* B94294 80240E54 AFB00030 */  sw        $s0, 0x30($sp)
/* B94298 80240E58 8E720148 */  lw        $s2, 0x148($s3)
/* B9429C 80240E5C 00A0882D */  daddu     $s1, $a1, $zero
/* B942A0 80240E60 86440008 */  lh        $a0, 8($s2)
/* B942A4 80240E64 0C00EABB */  jal       get_npc_unsafe
/* B942A8 80240E68 00C0802D */   daddu    $s0, $a2, $zero
/* B942AC 80240E6C 0200202D */  daddu     $a0, $s0, $zero
/* B942B0 80240E70 0240282D */  daddu     $a1, $s2, $zero
/* B942B4 80240E74 AFA00010 */  sw        $zero, 0x10($sp)
/* B942B8 80240E78 8E26000C */  lw        $a2, 0xc($s1)
/* B942BC 80240E7C 8E270010 */  lw        $a3, 0x10($s1)
/* B942C0 80240E80 0C01242D */  jal       func_800490B4
/* B942C4 80240E84 0040882D */   daddu    $s1, $v0, $zero
/* B942C8 80240E88 10400024 */  beqz      $v0, .L80240F1C
/* B942CC 80240E8C 0220202D */   daddu    $a0, $s1, $zero
/* B942D0 80240E90 24050322 */  addiu     $a1, $zero, 0x322
/* B942D4 80240E94 0C012530 */  jal       func_800494C0
/* B942D8 80240E98 0000302D */   daddu    $a2, $zero, $zero
/* B942DC 80240E9C 0000202D */  daddu     $a0, $zero, $zero
/* B942E0 80240EA0 0220282D */  daddu     $a1, $s1, $zero
/* B942E4 80240EA4 0000302D */  daddu     $a2, $zero, $zero
/* B942E8 80240EA8 2410000A */  addiu     $s0, $zero, 0xa
/* B942EC 80240EAC 862300A8 */  lh        $v1, 0xa8($s1)
/* B942F0 80240EB0 3C013F80 */  lui       $at, 0x3f80
/* B942F4 80240EB4 44810000 */  mtc1      $at, $f0
/* B942F8 80240EB8 3C014000 */  lui       $at, 0x4000
/* B942FC 80240EBC 44811000 */  mtc1      $at, $f2
/* B94300 80240EC0 3C01C1A0 */  lui       $at, 0xc1a0
/* B94304 80240EC4 44812000 */  mtc1      $at, $f4
/* B94308 80240EC8 44833000 */  mtc1      $v1, $f6
/* B9430C 80240ECC 00000000 */  nop       
/* B94310 80240ED0 468031A0 */  cvt.s.w   $f6, $f6
/* B94314 80240ED4 44073000 */  mfc1      $a3, $f6
/* B94318 80240ED8 27A20028 */  addiu     $v0, $sp, 0x28
/* B9431C 80240EDC AFB0001C */  sw        $s0, 0x1c($sp)
/* B94320 80240EE0 AFA20020 */  sw        $v0, 0x20($sp)
/* B94324 80240EE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* B94328 80240EE8 E7A20014 */  swc1      $f2, 0x14($sp)
/* B9432C 80240EEC 0C01BFA4 */  jal       fx_emote
/* B94330 80240EF0 E7A40018 */   swc1     $f4, 0x18($sp)
/* B94334 80240EF4 0220202D */  daddu     $a0, $s1, $zero
/* B94338 80240EF8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B9433C 80240EFC 0C012530 */  jal       func_800494C0
/* B94340 80240F00 3C060020 */   lui      $a2, 0x20
/* B94344 80240F04 8E4200CC */  lw        $v0, 0xcc($s2)
/* B94348 80240F08 8C420020 */  lw        $v0, 0x20($v0)
/* B9434C 80240F0C AE220028 */  sw        $v0, 0x28($s1)
/* B94350 80240F10 9642008E */  lhu       $v0, 0x8e($s2)
/* B94354 80240F14 A622008E */  sh        $v0, 0x8e($s1)
/* B94358 80240F18 AE700070 */  sw        $s0, 0x70($s3)
.L80240F1C:
/* B9435C 80240F1C 8FBF0040 */  lw        $ra, 0x40($sp)
/* B94360 80240F20 8FB3003C */  lw        $s3, 0x3c($sp)
/* B94364 80240F24 8FB20038 */  lw        $s2, 0x38($sp)
/* B94368 80240F28 8FB10034 */  lw        $s1, 0x34($sp)
/* B9436C 80240F2C 8FB00030 */  lw        $s0, 0x30($sp)
/* B94370 80240F30 03E00008 */  jr        $ra
/* B94374 80240F34 27BD0048 */   addiu    $sp, $sp, 0x48
