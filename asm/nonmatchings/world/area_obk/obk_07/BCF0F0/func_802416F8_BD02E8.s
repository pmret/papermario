.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F8_BD02E8
/* BD02E8 802416F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD02EC 802416FC AFB00010 */  sw        $s0, 0x10($sp)
/* BD02F0 80241700 0080802D */  daddu     $s0, $a0, $zero
/* BD02F4 80241704 3C05FE36 */  lui       $a1, 0xfe36
/* BD02F8 80241708 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD02FC 8024170C F7B40018 */  sdc1      $f20, 0x18($sp)
/* BD0300 80241710 0C0B210B */  jal       get_float_variable
/* BD0304 80241714 34A53C80 */   ori      $a1, $a1, 0x3c80
/* BD0308 80241718 0200202D */  daddu     $a0, $s0, $zero
/* BD030C 8024171C 3C05FE36 */  lui       $a1, 0xfe36
/* BD0310 80241720 34A53C81 */  ori       $a1, $a1, 0x3c81
/* BD0314 80241724 0C0B210B */  jal       get_float_variable
/* BD0318 80241728 46000506 */   mov.s    $f20, $f0
/* BD031C 8024172C 3C0143B4 */  lui       $at, 0x43b4
/* BD0320 80241730 44811000 */  mtc1      $at, $f2
/* BD0324 80241734 00000000 */  nop       
/* BD0328 80241738 4602003E */  c.le.s    $f0, $f2
/* BD032C 8024173C 00000000 */  nop       
/* BD0330 80241740 4502000B */  bc1fl     .L80241770
/* BD0334 80241744 AE00008C */   sw       $zero, 0x8c($s0)
/* BD0338 80241748 3C0142C8 */  lui       $at, 0x42c8
/* BD033C 8024174C 44810000 */  mtc1      $at, $f0
/* BD0340 80241750 00000000 */  nop       
/* BD0344 80241754 4600A03E */  c.le.s    $f20, $f0
/* BD0348 80241758 00000000 */  nop       
/* BD034C 8024175C 45000003 */  bc1f      .L8024176C
/* BD0350 80241760 24020001 */   addiu    $v0, $zero, 1
/* BD0354 80241764 080905DC */  j         .L80241770
/* BD0358 80241768 AE02008C */   sw       $v0, 0x8c($s0)
.L8024176C:
/* BD035C 8024176C AE00008C */  sw        $zero, 0x8c($s0)
.L80241770:
/* BD0360 80241770 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD0364 80241774 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0368 80241778 D7B40018 */  ldc1      $f20, 0x18($sp)
/* BD036C 8024177C 24020002 */  addiu     $v0, $zero, 2
/* BD0370 80241780 03E00008 */  jr        $ra
/* BD0374 80241784 27BD0020 */   addiu    $sp, $sp, 0x20
