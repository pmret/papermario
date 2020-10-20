.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414D8
/* 8B1548 802414D8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8B154C 802414DC AFB40040 */  sw        $s4, 0x40($sp)
/* 8B1550 802414E0 0080A02D */  daddu     $s4, $a0, $zero
/* 8B1554 802414E4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 8B1558 802414E8 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8B155C 802414EC AFB20038 */  sw        $s2, 0x38($sp)
/* 8B1560 802414F0 AFB10034 */  sw        $s1, 0x34($sp)
/* 8B1564 802414F4 AFB00030 */  sw        $s0, 0x30($sp)
/* 8B1568 802414F8 8E920148 */  lw        $s2, 0x148($s4)
/* 8B156C 802414FC 00A0802D */  daddu     $s0, $a1, $zero
/* 8B1570 80241500 86440008 */  lh        $a0, 8($s2)
/* 8B1574 80241504 0C00EABB */  jal       get_npc_unsafe
/* 8B1578 80241508 00C0982D */   daddu    $s3, $a2, $zero
/* 8B157C 8024150C 8E030008 */  lw        $v1, 8($s0)
/* 8B1580 80241510 04600031 */  bltz      $v1, .L802415D8
/* 8B1584 80241514 0040882D */   daddu    $s1, $v0, $zero
/* 8B1588 80241518 0260202D */  daddu     $a0, $s3, $zero
/* 8B158C 8024151C AFA00010 */  sw        $zero, 0x10($sp)
/* 8B1590 80241520 8E060018 */  lw        $a2, 0x18($s0)
/* 8B1594 80241524 8E07001C */  lw        $a3, 0x1c($s0)
/* 8B1598 80241528 0C01242D */  jal       func_800490B4
/* 8B159C 8024152C 0240282D */   daddu    $a1, $s2, $zero
/* 8B15A0 80241530 10400029 */  beqz      $v0, .L802415D8
/* 8B15A4 80241534 0000202D */   daddu    $a0, $zero, $zero
/* 8B15A8 80241538 0220282D */  daddu     $a1, $s1, $zero
/* 8B15AC 8024153C 0000302D */  daddu     $a2, $zero, $zero
/* 8B15B0 80241540 862300A8 */  lh        $v1, 0xa8($s1)
/* 8B15B4 80241544 3C013F80 */  lui       $at, 0x3f80
/* 8B15B8 80241548 44810000 */  mtc1      $at, $f0
/* 8B15BC 8024154C 3C014000 */  lui       $at, 0x4000
/* 8B15C0 80241550 44811000 */  mtc1      $at, $f2
/* 8B15C4 80241554 3C01C1A0 */  lui       $at, 0xc1a0
/* 8B15C8 80241558 44812000 */  mtc1      $at, $f4
/* 8B15CC 8024155C 2402000F */  addiu     $v0, $zero, 0xf
/* 8B15D0 80241560 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8B15D4 80241564 44833000 */  mtc1      $v1, $f6
/* 8B15D8 80241568 00000000 */  nop       
/* 8B15DC 8024156C 468031A0 */  cvt.s.w   $f6, $f6
/* 8B15E0 80241570 44073000 */  mfc1      $a3, $f6
/* 8B15E4 80241574 27A20028 */  addiu     $v0, $sp, 0x28
/* 8B15E8 80241578 AFA20020 */  sw        $v0, 0x20($sp)
/* 8B15EC 8024157C E7A00010 */  swc1      $f0, 0x10($sp)
/* 8B15F0 80241580 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8B15F4 80241584 0C01BFA4 */  jal       fx_emote
/* 8B15F8 80241588 E7A40018 */   swc1     $f4, 0x18($sp)
/* 8B15FC 8024158C 0220202D */  daddu     $a0, $s1, $zero
/* 8B1600 80241590 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 8B1604 80241594 0C012530 */  jal       func_800494C0
/* 8B1608 80241598 3C060020 */   lui      $a2, 0x20
/* 8B160C 8024159C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8B1610 802415A0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8B1614 802415A4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8B1618 802415A8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8B161C 802415AC 8C460028 */  lw        $a2, 0x28($v0)
/* 8B1620 802415B0 0C00A720 */  jal       atan2
/* 8B1624 802415B4 8C470030 */   lw       $a3, 0x30($v0)
/* 8B1628 802415B8 E620000C */  swc1      $f0, 0xc($s1)
/* 8B162C 802415BC 8E420018 */  lw        $v0, 0x18($s2)
/* 8B1630 802415C0 9442002A */  lhu       $v0, 0x2a($v0)
/* 8B1634 802415C4 30420001 */  andi      $v0, $v0, 1
/* 8B1638 802415C8 14400002 */  bnez      $v0, .L802415D4
/* 8B163C 802415CC 2402000A */   addiu    $v0, $zero, 0xa
/* 8B1640 802415D0 2402000C */  addiu     $v0, $zero, 0xc
.L802415D4:
/* 8B1644 802415D4 AE820070 */  sw        $v0, 0x70($s4)
.L802415D8:
/* 8B1648 802415D8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8B164C 802415DC 8FB40040 */  lw        $s4, 0x40($sp)
/* 8B1650 802415E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8B1654 802415E4 8FB20038 */  lw        $s2, 0x38($sp)
/* 8B1658 802415E8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8B165C 802415EC 8FB00030 */  lw        $s0, 0x30($sp)
/* 8B1660 802415F0 03E00008 */  jr        $ra
/* 8B1664 802415F4 27BD0048 */   addiu    $sp, $sp, 0x48
