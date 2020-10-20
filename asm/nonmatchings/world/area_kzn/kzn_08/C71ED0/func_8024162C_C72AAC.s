.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024162C_C72AAC
/* C72AAC 8024162C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C72AB0 80241630 AFB20018 */  sw        $s2, 0x18($sp)
/* C72AB4 80241634 0080902D */  daddu     $s2, $a0, $zero
/* C72AB8 80241638 AFBF001C */  sw        $ra, 0x1c($sp)
/* C72ABC 8024163C AFB10014 */  sw        $s1, 0x14($sp)
/* C72AC0 80241640 AFB00010 */  sw        $s0, 0x10($sp)
/* C72AC4 80241644 8E510148 */  lw        $s1, 0x148($s2)
/* C72AC8 80241648 0C00EABB */  jal       get_npc_unsafe
/* C72ACC 8024164C 86240008 */   lh       $a0, 8($s1)
/* C72AD0 80241650 0040802D */  daddu     $s0, $v0, $zero
/* C72AD4 80241654 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C72AD8 80241658 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C72ADC 8024165C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C72AE0 80241660 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C72AE4 80241664 A600008E */  sh        $zero, 0x8e($s0)
/* C72AE8 80241668 8C460028 */  lw        $a2, 0x28($v0)
/* C72AEC 8024166C 0C00A720 */  jal       atan2
/* C72AF0 80241670 8C470030 */   lw       $a3, 0x30($v0)
/* C72AF4 80241674 E600000C */  swc1      $f0, 0xc($s0)
/* C72AF8 80241678 8E2200CC */  lw        $v0, 0xcc($s1)
/* C72AFC 8024167C 8C420020 */  lw        $v0, 0x20($v0)
/* C72B00 80241680 AE020028 */  sw        $v0, 0x28($s0)
/* C72B04 80241684 2402000B */  addiu     $v0, $zero, 0xb
/* C72B08 80241688 AE420070 */  sw        $v0, 0x70($s2)
/* C72B0C 8024168C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C72B10 80241690 8FB20018 */  lw        $s2, 0x18($sp)
/* C72B14 80241694 8FB10014 */  lw        $s1, 0x14($sp)
/* C72B18 80241698 8FB00010 */  lw        $s0, 0x10($sp)
/* C72B1C 8024169C 03E00008 */  jr        $ra
/* C72B20 802416A0 27BD0020 */   addiu    $sp, $sp, 0x20
