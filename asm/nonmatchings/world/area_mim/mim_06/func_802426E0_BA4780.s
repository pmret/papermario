.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426E0_BA6E60
/* BA6E60 802426E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA6E64 802426E4 AFB10014 */  sw        $s1, 0x14($sp)
/* BA6E68 802426E8 0080882D */  daddu     $s1, $a0, $zero
/* BA6E6C 802426EC AFBF001C */  sw        $ra, 0x1c($sp)
/* BA6E70 802426F0 AFB20018 */  sw        $s2, 0x18($sp)
/* BA6E74 802426F4 AFB00010 */  sw        $s0, 0x10($sp)
/* BA6E78 802426F8 8E220148 */  lw        $v0, 0x148($s1)
/* BA6E7C 802426FC 00A0902D */  daddu     $s2, $a1, $zero
/* BA6E80 80242700 84440008 */  lh        $a0, 8($v0)
/* BA6E84 80242704 0C00EABB */  jal       get_npc_unsafe
/* BA6E88 80242708 00C0802D */   daddu    $s0, $a2, $zero
/* BA6E8C 8024270C 0220202D */  daddu     $a0, $s1, $zero
/* BA6E90 80242710 0240282D */  daddu     $a1, $s2, $zero
/* BA6E94 80242714 0200302D */  daddu     $a2, $s0, $zero
/* BA6E98 80242718 0C0127DF */  jal       func_80049F7C
/* BA6E9C 8024271C 0040802D */   daddu    $s0, $v0, $zero
/* BA6EA0 80242720 8E020000 */  lw        $v0, ($s0)
/* BA6EA4 80242724 24040005 */  addiu     $a0, $zero, 5
/* BA6EA8 80242728 34420800 */  ori       $v0, $v0, 0x800
/* BA6EAC 8024272C 0C00A67F */  jal       rand_int
/* BA6EB0 80242730 AE020000 */   sw       $v0, ($s0)
/* BA6EB4 80242734 44820000 */  mtc1      $v0, $f0
/* BA6EB8 80242738 00000000 */  nop       
/* BA6EBC 8024273C 46800021 */  cvt.d.w   $f0, $f0
/* BA6EC0 80242740 3C014024 */  lui       $at, 0x4024
/* BA6EC4 80242744 44811800 */  mtc1      $at, $f3
/* BA6EC8 80242748 44801000 */  mtc1      $zero, $f2
/* BA6ECC 8024274C 3C013FC0 */  lui       $at, 0x3fc0
/* BA6ED0 80242750 44812000 */  mtc1      $at, $f4
/* BA6ED4 80242754 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA6ED8 80242758 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA6EDC 8024275C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA6EE0 80242760 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA6EE4 80242764 46220000 */  add.d     $f0, $f0, $f2
/* BA6EE8 80242768 E6040014 */  swc1      $f4, 0x14($s0)
/* BA6EEC 8024276C 46200020 */  cvt.s.d   $f0, $f0
/* BA6EF0 80242770 E600001C */  swc1      $f0, 0x1c($s0)
/* BA6EF4 80242774 8C460028 */  lw        $a2, 0x28($v0)
/* BA6EF8 80242778 0C00A720 */  jal       atan2
/* BA6EFC 8024277C 8C470030 */   lw       $a3, 0x30($v0)
/* BA6F00 80242780 0200202D */  daddu     $a0, $s0, $zero
/* BA6F04 80242784 3C05B000 */  lui       $a1, 0xb000
/* BA6F08 80242788 34A50017 */  ori       $a1, $a1, 0x17
/* BA6F0C 8024278C 0000302D */  daddu     $a2, $zero, $zero
/* BA6F10 80242790 E480000C */  swc1      $f0, 0xc($a0)
/* BA6F14 80242794 C6400018 */  lwc1      $f0, 0x18($s2)
/* BA6F18 80242798 2402000D */  addiu     $v0, $zero, 0xd
/* BA6F1C 8024279C E4800018 */  swc1      $f0, 0x18($a0)
/* BA6F20 802427A0 0C012530 */  jal       func_800494C0
/* BA6F24 802427A4 AE220070 */   sw       $v0, 0x70($s1)
/* BA6F28 802427A8 8FBF001C */  lw        $ra, 0x1c($sp)
/* BA6F2C 802427AC 8FB20018 */  lw        $s2, 0x18($sp)
/* BA6F30 802427B0 8FB10014 */  lw        $s1, 0x14($sp)
/* BA6F34 802427B4 8FB00010 */  lw        $s0, 0x10($sp)
/* BA6F38 802427B8 03E00008 */  jr        $ra
/* BA6F3C 802427BC 27BD0020 */   addiu    $sp, $sp, 0x20
