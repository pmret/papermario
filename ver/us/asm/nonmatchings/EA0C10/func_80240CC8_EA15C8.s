.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC8_EA15C8
/* EA15C8 80240CC8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EA15CC 80240CCC AFB3003C */  sw        $s3, 0x3c($sp)
/* EA15D0 80240CD0 0080982D */  daddu     $s3, $a0, $zero
/* EA15D4 80240CD4 AFBF0040 */  sw        $ra, 0x40($sp)
/* EA15D8 80240CD8 AFB20038 */  sw        $s2, 0x38($sp)
/* EA15DC 80240CDC AFB10034 */  sw        $s1, 0x34($sp)
/* EA15E0 80240CE0 AFB00030 */  sw        $s0, 0x30($sp)
/* EA15E4 80240CE4 8E720148 */  lw        $s2, 0x148($s3)
/* EA15E8 80240CE8 00A0882D */  daddu     $s1, $a1, $zero
/* EA15EC 80240CEC 86440008 */  lh        $a0, 8($s2)
/* EA15F0 80240CF0 0C00F92F */  jal       dead_get_npc_unsafe
/* EA15F4 80240CF4 00C0802D */   daddu    $s0, $a2, $zero
/* EA15F8 80240CF8 0200202D */  daddu     $a0, $s0, $zero
/* EA15FC 80240CFC 0240282D */  daddu     $a1, $s2, $zero
/* EA1600 80240D00 AFA00010 */  sw        $zero, 0x10($sp)
/* EA1604 80240D04 8E26000C */  lw        $a2, 0xc($s1)
/* EA1608 80240D08 8E270010 */  lw        $a3, 0x10($s1)
/* EA160C 80240D0C 0C013469 */  jal       func_8004D1A4
/* EA1610 80240D10 0040882D */   daddu    $s1, $v0, $zero
/* EA1614 80240D14 10400024 */  beqz      $v0, .L80240DA8
/* EA1618 80240D18 0220202D */   daddu    $a0, $s1, $zero
/* EA161C 80240D1C 24050322 */  addiu     $a1, $zero, 0x322
/* EA1620 80240D20 0C013600 */  jal       func_8004D800
/* EA1624 80240D24 0000302D */   daddu    $a2, $zero, $zero
/* EA1628 80240D28 0000202D */  daddu     $a0, $zero, $zero
/* EA162C 80240D2C 0220282D */  daddu     $a1, $s1, $zero
/* EA1630 80240D30 0000302D */  daddu     $a2, $zero, $zero
/* EA1634 80240D34 2410000A */  addiu     $s0, $zero, 0xa
/* EA1638 80240D38 862300A8 */  lh        $v1, 0xa8($s1)
/* EA163C 80240D3C 3C013F80 */  lui       $at, 0x3f80
/* EA1640 80240D40 44810000 */  mtc1      $at, $f0
/* EA1644 80240D44 3C014000 */  lui       $at, 0x4000
/* EA1648 80240D48 44811000 */  mtc1      $at, $f2
/* EA164C 80240D4C 3C01C1A0 */  lui       $at, 0xc1a0
/* EA1650 80240D50 44812000 */  mtc1      $at, $f4
/* EA1654 80240D54 44833000 */  mtc1      $v1, $f6
/* EA1658 80240D58 00000000 */  nop
/* EA165C 80240D5C 468031A0 */  cvt.s.w   $f6, $f6
/* EA1660 80240D60 44073000 */  mfc1      $a3, $f6
/* EA1664 80240D64 27A20028 */  addiu     $v0, $sp, 0x28
/* EA1668 80240D68 AFB0001C */  sw        $s0, 0x1c($sp)
/* EA166C 80240D6C AFA20020 */  sw        $v0, 0x20($sp)
/* EA1670 80240D70 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA1674 80240D74 E7A20014 */  swc1      $f2, 0x14($sp)
/* EA1678 80240D78 0C01D444 */  jal       func_80075110
/* EA167C 80240D7C E7A40018 */   swc1     $f4, 0x18($sp)
/* EA1680 80240D80 0220202D */  daddu     $a0, $s1, $zero
/* EA1684 80240D84 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EA1688 80240D88 0C013600 */  jal       func_8004D800
/* EA168C 80240D8C 3C060020 */   lui      $a2, 0x20
/* EA1690 80240D90 8E4200CC */  lw        $v0, 0xcc($s2)
/* EA1694 80240D94 8C420020 */  lw        $v0, 0x20($v0)
/* EA1698 80240D98 AE220028 */  sw        $v0, 0x28($s1)
/* EA169C 80240D9C 9642008E */  lhu       $v0, 0x8e($s2)
/* EA16A0 80240DA0 A622008E */  sh        $v0, 0x8e($s1)
/* EA16A4 80240DA4 AE700070 */  sw        $s0, 0x70($s3)
.L80240DA8:
/* EA16A8 80240DA8 8FBF0040 */  lw        $ra, 0x40($sp)
/* EA16AC 80240DAC 8FB3003C */  lw        $s3, 0x3c($sp)
/* EA16B0 80240DB0 8FB20038 */  lw        $s2, 0x38($sp)
/* EA16B4 80240DB4 8FB10034 */  lw        $s1, 0x34($sp)
/* EA16B8 80240DB8 8FB00030 */  lw        $s0, 0x30($sp)
/* EA16BC 80240DBC 03E00008 */  jr        $ra
/* EA16C0 80240DC0 27BD0048 */   addiu    $sp, $sp, 0x48
