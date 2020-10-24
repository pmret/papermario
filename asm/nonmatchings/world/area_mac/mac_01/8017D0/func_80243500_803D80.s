.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243500_803D80
/* 803D80 80243500 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803D84 80243504 AFB10014 */  sw        $s1, 0x14($sp)
/* 803D88 80243508 0080882D */  daddu     $s1, $a0, $zero
/* 803D8C 8024350C AFBF001C */  sw        $ra, 0x1c($sp)
/* 803D90 80243510 AFB20018 */  sw        $s2, 0x18($sp)
/* 803D94 80243514 AFB00010 */  sw        $s0, 0x10($sp)
/* 803D98 80243518 8E30000C */  lw        $s0, 0xc($s1)
/* 803D9C 8024351C 8E050000 */  lw        $a1, ($s0)
/* 803DA0 80243520 0C0B210B */  jal       get_float_variable
/* 803DA4 80243524 26100004 */   addiu    $s0, $s0, 4
/* 803DA8 80243528 8E050000 */  lw        $a1, ($s0)
/* 803DAC 8024352C 26100004 */  addiu     $s0, $s0, 4
/* 803DB0 80243530 4600008D */  trunc.w.s $f2, $f0
/* 803DB4 80243534 44121000 */  mfc1      $s2, $f2
/* 803DB8 80243538 0C0B210B */  jal       get_float_variable
/* 803DBC 8024353C 0220202D */   daddu    $a0, $s1, $zero
/* 803DC0 80243540 0220202D */  daddu     $a0, $s1, $zero
/* 803DC4 80243544 8E050000 */  lw        $a1, ($s0)
/* 803DC8 80243548 4600008D */  trunc.w.s $f2, $f0
/* 803DCC 8024354C 44111000 */  mfc1      $s1, $f2
/* 803DD0 80243550 0C0B210B */  jal       get_float_variable
/* 803DD4 80243554 00000000 */   nop      
/* 803DD8 80243558 0000202D */  daddu     $a0, $zero, $zero
/* 803DDC 8024355C 3C05FD05 */  lui       $a1, 0xfd05
/* 803DE0 80243560 4600008D */  trunc.w.s $f2, $f0
/* 803DE4 80243564 44101000 */  mfc1      $s0, $f2
/* 803DE8 80243568 0C0B1EAF */  jal       get_variable
/* 803DEC 8024356C 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 803DF0 80243570 0040182D */  daddu     $v1, $v0, $zero
/* 803DF4 80243574 44920000 */  mtc1      $s2, $f0
/* 803DF8 80243578 00000000 */  nop       
/* 803DFC 8024357C 46800020 */  cvt.s.w   $f0, $f0
/* 803E00 80243580 E4600010 */  swc1      $f0, 0x10($v1)
/* 803E04 80243584 44910000 */  mtc1      $s1, $f0
/* 803E08 80243588 00000000 */  nop       
/* 803E0C 8024358C 46800020 */  cvt.s.w   $f0, $f0
/* 803E10 80243590 E4600014 */  swc1      $f0, 0x14($v1)
/* 803E14 80243594 44900000 */  mtc1      $s0, $f0
/* 803E18 80243598 00000000 */  nop       
/* 803E1C 8024359C 46800020 */  cvt.s.w   $f0, $f0
/* 803E20 802435A0 E4600018 */  swc1      $f0, 0x18($v1)
/* 803E24 802435A4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 803E28 802435A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 803E2C 802435AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 803E30 802435B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 803E34 802435B4 24020002 */  addiu     $v0, $zero, 2
/* 803E38 802435B8 03E00008 */  jr        $ra
/* 803E3C 802435BC 27BD0020 */   addiu    $sp, $sp, 0x20
