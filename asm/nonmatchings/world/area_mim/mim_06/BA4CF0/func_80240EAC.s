.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EAC
/* BA562C 80240EAC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BA5630 80240EB0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA5634 80240EB4 0080982D */  daddu     $s3, $a0, $zero
/* BA5638 80240EB8 AFBF0040 */  sw        $ra, 0x40($sp)
/* BA563C 80240EBC AFB20038 */  sw        $s2, 0x38($sp)
/* BA5640 80240EC0 AFB10034 */  sw        $s1, 0x34($sp)
/* BA5644 80240EC4 AFB00030 */  sw        $s0, 0x30($sp)
/* BA5648 80240EC8 8E720148 */  lw        $s2, 0x148($s3)
/* BA564C 80240ECC 00A0882D */  daddu     $s1, $a1, $zero
/* BA5650 80240ED0 86440008 */  lh        $a0, 8($s2)
/* BA5654 80240ED4 0C00EABB */  jal       get_npc_unsafe
/* BA5658 80240ED8 00C0802D */   daddu    $s0, $a2, $zero
/* BA565C 80240EDC 0200202D */  daddu     $a0, $s0, $zero
/* BA5660 80240EE0 0240282D */  daddu     $a1, $s2, $zero
/* BA5664 80240EE4 AFA00010 */  sw        $zero, 0x10($sp)
/* BA5668 80240EE8 8E26000C */  lw        $a2, 0xc($s1)
/* BA566C 80240EEC 8E270010 */  lw        $a3, 0x10($s1)
/* BA5670 80240EF0 0C01242D */  jal       func_800490B4
/* BA5674 80240EF4 0040882D */   daddu    $s1, $v0, $zero
/* BA5678 80240EF8 10400024 */  beqz      $v0, .L80240F8C
/* BA567C 80240EFC 0220202D */   daddu    $a0, $s1, $zero
/* BA5680 80240F00 24050322 */  addiu     $a1, $zero, 0x322
/* BA5684 80240F04 0C012530 */  jal       func_800494C0
/* BA5688 80240F08 0000302D */   daddu    $a2, $zero, $zero
/* BA568C 80240F0C 0000202D */  daddu     $a0, $zero, $zero
/* BA5690 80240F10 0220282D */  daddu     $a1, $s1, $zero
/* BA5694 80240F14 0000302D */  daddu     $a2, $zero, $zero
/* BA5698 80240F18 2410000A */  addiu     $s0, $zero, 0xa
/* BA569C 80240F1C 862300A8 */  lh        $v1, 0xa8($s1)
/* BA56A0 80240F20 3C013F80 */  lui       $at, 0x3f80
/* BA56A4 80240F24 44810000 */  mtc1      $at, $f0
/* BA56A8 80240F28 3C014000 */  lui       $at, 0x4000
/* BA56AC 80240F2C 44811000 */  mtc1      $at, $f2
/* BA56B0 80240F30 3C01C1A0 */  lui       $at, 0xc1a0
/* BA56B4 80240F34 44812000 */  mtc1      $at, $f4
/* BA56B8 80240F38 44833000 */  mtc1      $v1, $f6
/* BA56BC 80240F3C 00000000 */  nop       
/* BA56C0 80240F40 468031A0 */  cvt.s.w   $f6, $f6
/* BA56C4 80240F44 44073000 */  mfc1      $a3, $f6
/* BA56C8 80240F48 27A20028 */  addiu     $v0, $sp, 0x28
/* BA56CC 80240F4C AFB0001C */  sw        $s0, 0x1c($sp)
/* BA56D0 80240F50 AFA20020 */  sw        $v0, 0x20($sp)
/* BA56D4 80240F54 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA56D8 80240F58 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA56DC 80240F5C 0C01BFA4 */  jal       fx_emote
/* BA56E0 80240F60 E7A40018 */   swc1     $f4, 0x18($sp)
/* BA56E4 80240F64 0220202D */  daddu     $a0, $s1, $zero
/* BA56E8 80240F68 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BA56EC 80240F6C 0C012530 */  jal       func_800494C0
/* BA56F0 80240F70 3C060020 */   lui      $a2, 0x20
/* BA56F4 80240F74 8E4200CC */  lw        $v0, 0xcc($s2)
/* BA56F8 80240F78 8C420020 */  lw        $v0, 0x20($v0)
/* BA56FC 80240F7C AE220028 */  sw        $v0, 0x28($s1)
/* BA5700 80240F80 9642008E */  lhu       $v0, 0x8e($s2)
/* BA5704 80240F84 A622008E */  sh        $v0, 0x8e($s1)
/* BA5708 80240F88 AE700070 */  sw        $s0, 0x70($s3)
.L80240F8C:
/* BA570C 80240F8C 8FBF0040 */  lw        $ra, 0x40($sp)
/* BA5710 80240F90 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA5714 80240F94 8FB20038 */  lw        $s2, 0x38($sp)
/* BA5718 80240F98 8FB10034 */  lw        $s1, 0x34($sp)
/* BA571C 80240F9C 8FB00030 */  lw        $s0, 0x30($sp)
/* BA5720 80240FA0 03E00008 */  jr        $ra
/* BA5724 80240FA4 27BD0048 */   addiu    $sp, $sp, 0x48
