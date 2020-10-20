.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410BC_C5B7FC
/* C5B7FC 802410BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5B800 802410C0 AFB20018 */  sw        $s2, 0x18($sp)
/* C5B804 802410C4 0080902D */  daddu     $s2, $a0, $zero
/* C5B808 802410C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* C5B80C 802410CC AFB10014 */  sw        $s1, 0x14($sp)
/* C5B810 802410D0 AFB00010 */  sw        $s0, 0x10($sp)
/* C5B814 802410D4 8E510148 */  lw        $s1, 0x148($s2)
/* C5B818 802410D8 0C00EABB */  jal       get_npc_unsafe
/* C5B81C 802410DC 86240008 */   lh       $a0, 8($s1)
/* C5B820 802410E0 0040802D */  daddu     $s0, $v0, $zero
/* C5B824 802410E4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5B828 802410E8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5B82C 802410EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C5B830 802410F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C5B834 802410F4 A600008E */  sh        $zero, 0x8e($s0)
/* C5B838 802410F8 8C460028 */  lw        $a2, 0x28($v0)
/* C5B83C 802410FC 0C00A720 */  jal       atan2
/* C5B840 80241100 8C470030 */   lw       $a3, 0x30($v0)
/* C5B844 80241104 E600000C */  swc1      $f0, 0xc($s0)
/* C5B848 80241108 8E2200CC */  lw        $v0, 0xcc($s1)
/* C5B84C 8024110C 8C420020 */  lw        $v0, 0x20($v0)
/* C5B850 80241110 AE020028 */  sw        $v0, 0x28($s0)
/* C5B854 80241114 2402000B */  addiu     $v0, $zero, 0xb
/* C5B858 80241118 AE420070 */  sw        $v0, 0x70($s2)
/* C5B85C 8024111C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C5B860 80241120 8FB20018 */  lw        $s2, 0x18($sp)
/* C5B864 80241124 8FB10014 */  lw        $s1, 0x14($sp)
/* C5B868 80241128 8FB00010 */  lw        $s0, 0x10($sp)
/* C5B86C 8024112C 03E00008 */  jr        $ra
/* C5B870 80241130 27BD0020 */   addiu    $sp, $sp, 0x20
