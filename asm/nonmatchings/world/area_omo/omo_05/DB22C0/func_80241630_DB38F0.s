.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241630_DB38F0
/* DB38F0 80241630 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB38F4 80241634 AFB20018 */  sw        $s2, 0x18($sp)
/* DB38F8 80241638 0080902D */  daddu     $s2, $a0, $zero
/* DB38FC 8024163C AFBF001C */  sw        $ra, 0x1c($sp)
/* DB3900 80241640 AFB10014 */  sw        $s1, 0x14($sp)
/* DB3904 80241644 AFB00010 */  sw        $s0, 0x10($sp)
/* DB3908 80241648 8E510148 */  lw        $s1, 0x148($s2)
/* DB390C 8024164C 0C00EABB */  jal       get_npc_unsafe
/* DB3910 80241650 86240008 */   lh       $a0, 8($s1)
/* DB3914 80241654 0040802D */  daddu     $s0, $v0, $zero
/* DB3918 80241658 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DB391C 8024165C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DB3920 80241660 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DB3924 80241664 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DB3928 80241668 A600008E */  sh        $zero, 0x8e($s0)
/* DB392C 8024166C 8C460028 */  lw        $a2, 0x28($v0)
/* DB3930 80241670 0C00A720 */  jal       atan2
/* DB3934 80241674 8C470030 */   lw       $a3, 0x30($v0)
/* DB3938 80241678 E600000C */  swc1      $f0, 0xc($s0)
/* DB393C 8024167C 8E2200CC */  lw        $v0, 0xcc($s1)
/* DB3940 80241680 8C420020 */  lw        $v0, 0x20($v0)
/* DB3944 80241684 AE020028 */  sw        $v0, 0x28($s0)
/* DB3948 80241688 2402000B */  addiu     $v0, $zero, 0xb
/* DB394C 8024168C AE420070 */  sw        $v0, 0x70($s2)
/* DB3950 80241690 8FBF001C */  lw        $ra, 0x1c($sp)
/* DB3954 80241694 8FB20018 */  lw        $s2, 0x18($sp)
/* DB3958 80241698 8FB10014 */  lw        $s1, 0x14($sp)
/* DB395C 8024169C 8FB00010 */  lw        $s0, 0x10($sp)
/* DB3960 802416A0 03E00008 */  jr        $ra
/* DB3964 802416A4 27BD0020 */   addiu    $sp, $sp, 0x20
