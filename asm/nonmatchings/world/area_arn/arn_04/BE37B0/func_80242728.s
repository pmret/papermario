.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242728
/* BE5ED8 80242728 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE5EDC 8024272C AFB10014 */  sw        $s1, 0x14($sp)
/* BE5EE0 80242730 0080882D */  daddu     $s1, $a0, $zero
/* BE5EE4 80242734 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE5EE8 80242738 AFB00010 */  sw        $s0, 0x10($sp)
/* BE5EEC 8024273C 8E220148 */  lw        $v0, 0x148($s1)
/* BE5EF0 80242740 0C00EABB */  jal       get_npc_unsafe
/* BE5EF4 80242744 84440008 */   lh       $a0, 8($v0)
/* BE5EF8 80242748 0040802D */  daddu     $s0, $v0, $zero
/* BE5EFC 8024274C 9602008E */  lhu       $v0, 0x8e($s0)
/* BE5F00 80242750 2442FFFF */  addiu     $v0, $v0, -1
/* BE5F04 80242754 A602008E */  sh        $v0, 0x8e($s0)
/* BE5F08 80242758 00021400 */  sll       $v0, $v0, 0x10
/* BE5F0C 8024275C 1C40000F */  bgtz      $v0, .L8024279C
/* BE5F10 80242760 00000000 */   nop      
/* BE5F14 80242764 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE5F18 80242768 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE5F1C 8024276C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE5F20 80242770 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE5F24 80242774 8C460028 */  lw        $a2, 0x28($v0)
/* BE5F28 80242778 0C00A720 */  jal       atan2
/* BE5F2C 8024277C 8C470030 */   lw       $a3, 0x30($v0)
/* BE5F30 80242780 2402001A */  addiu     $v0, $zero, 0x1a
/* BE5F34 80242784 A60200A8 */  sh        $v0, 0xa8($s0)
/* BE5F38 80242788 24020018 */  addiu     $v0, $zero, 0x18
/* BE5F3C 8024278C A60200A6 */  sh        $v0, 0xa6($s0)
/* BE5F40 80242790 24020004 */  addiu     $v0, $zero, 4
/* BE5F44 80242794 E600000C */  swc1      $f0, 0xc($s0)
/* BE5F48 80242798 AE220070 */  sw        $v0, 0x70($s1)
.L8024279C:
/* BE5F4C 8024279C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE5F50 802427A0 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5F54 802427A4 8FB00010 */  lw        $s0, 0x10($sp)
/* BE5F58 802427A8 03E00008 */  jr        $ra
/* BE5F5C 802427AC 27BD0020 */   addiu    $sp, $sp, 0x20
