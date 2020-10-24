.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426EC_911D9C
/* 911D9C 802426EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 911DA0 802426F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 911DA4 802426F4 0080882D */  daddu     $s1, $a0, $zero
/* 911DA8 802426F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 911DAC 802426FC AFB20018 */  sw        $s2, 0x18($sp)
/* 911DB0 80242700 AFB00010 */  sw        $s0, 0x10($sp)
/* 911DB4 80242704 8E320148 */  lw        $s2, 0x148($s1)
/* 911DB8 80242708 0C00EABB */  jal       get_npc_unsafe
/* 911DBC 8024270C 86440008 */   lh       $a0, 8($s2)
/* 911DC0 80242710 240400B4 */  addiu     $a0, $zero, 0xb4
/* 911DC4 80242714 0C00A67F */  jal       rand_int
/* 911DC8 80242718 0040802D */   daddu    $s0, $v0, $zero
/* 911DCC 8024271C C60C000C */  lwc1      $f12, 0xc($s0)
/* 911DD0 80242720 44820000 */  mtc1      $v0, $f0
/* 911DD4 80242724 00000000 */  nop       
/* 911DD8 80242728 46800020 */  cvt.s.w   $f0, $f0
/* 911DDC 8024272C 46006300 */  add.s     $f12, $f12, $f0
/* 911DE0 80242730 3C0142B4 */  lui       $at, 0x42b4
/* 911DE4 80242734 44810000 */  mtc1      $at, $f0
/* 911DE8 80242738 0C00A6C9 */  jal       clamp_angle
/* 911DEC 8024273C 46006301 */   sub.s    $f12, $f12, $f0
/* 911DF0 80242740 E600000C */  swc1      $f0, 0xc($s0)
/* 911DF4 80242744 8E4200CC */  lw        $v0, 0xcc($s2)
/* 911DF8 80242748 8C420000 */  lw        $v0, ($v0)
/* 911DFC 8024274C 240403E8 */  addiu     $a0, $zero, 0x3e8
/* 911E00 80242750 0C00A67F */  jal       rand_int
/* 911E04 80242754 AE020028 */   sw       $v0, 0x28($s0)
/* 911E08 80242758 00021FC2 */  srl       $v1, $v0, 0x1f
/* 911E0C 8024275C 00431821 */  addu      $v1, $v0, $v1
/* 911E10 80242760 00031843 */  sra       $v1, $v1, 1
/* 911E14 80242764 00031840 */  sll       $v1, $v1, 1
/* 911E18 80242768 00431023 */  subu      $v0, $v0, $v1
/* 911E1C 8024276C 24420002 */  addiu     $v0, $v0, 2
/* 911E20 80242770 AE220074 */  sw        $v0, 0x74($s1)
/* 911E24 80242774 24020005 */  addiu     $v0, $zero, 5
/* 911E28 80242778 AE220070 */  sw        $v0, 0x70($s1)
/* 911E2C 8024277C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 911E30 80242780 8FB20018 */  lw        $s2, 0x18($sp)
/* 911E34 80242784 8FB10014 */  lw        $s1, 0x14($sp)
/* 911E38 80242788 8FB00010 */  lw        $s0, 0x10($sp)
/* 911E3C 8024278C 03E00008 */  jr        $ra
/* 911E40 80242790 27BD0020 */   addiu    $sp, $sp, 0x20
