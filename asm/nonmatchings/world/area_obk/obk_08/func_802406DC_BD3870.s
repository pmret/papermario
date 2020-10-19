.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406DC_BD3F4C
/* BD3F4C 802406DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD3F50 802406E0 AFB10014 */  sw        $s1, 0x14($sp)
/* BD3F54 802406E4 0080882D */  daddu     $s1, $a0, $zero
/* BD3F58 802406E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* BD3F5C 802406EC AFB20018 */  sw        $s2, 0x18($sp)
/* BD3F60 802406F0 AFB00010 */  sw        $s0, 0x10($sp)
/* BD3F64 802406F4 8E30000C */  lw        $s0, 0xc($s1)
/* BD3F68 802406F8 8E050000 */  lw        $a1, ($s0)
/* BD3F6C 802406FC 0C0B210B */  jal       get_float_variable
/* BD3F70 80240700 26100004 */   addiu    $s0, $s0, 4
/* BD3F74 80240704 8E050000 */  lw        $a1, ($s0)
/* BD3F78 80240708 26100004 */  addiu     $s0, $s0, 4
/* BD3F7C 8024070C 4600008D */  trunc.w.s $f2, $f0
/* BD3F80 80240710 44121000 */  mfc1      $s2, $f2
/* BD3F84 80240714 0C0B210B */  jal       get_float_variable
/* BD3F88 80240718 0220202D */   daddu    $a0, $s1, $zero
/* BD3F8C 8024071C 0220202D */  daddu     $a0, $s1, $zero
/* BD3F90 80240720 8E050000 */  lw        $a1, ($s0)
/* BD3F94 80240724 4600008D */  trunc.w.s $f2, $f0
/* BD3F98 80240728 44111000 */  mfc1      $s1, $f2
/* BD3F9C 8024072C 0C0B210B */  jal       get_float_variable
/* BD3FA0 80240730 00000000 */   nop      
/* BD3FA4 80240734 0000202D */  daddu     $a0, $zero, $zero
/* BD3FA8 80240738 3C05FD05 */  lui       $a1, 0xfd05
/* BD3FAC 8024073C 4600008D */  trunc.w.s $f2, $f0
/* BD3FB0 80240740 44101000 */  mfc1      $s0, $f2
/* BD3FB4 80240744 0C0B1EAF */  jal       get_variable
/* BD3FB8 80240748 34A50F8A */   ori      $a1, $a1, 0xf8a
/* BD3FBC 8024074C 0040182D */  daddu     $v1, $v0, $zero
/* BD3FC0 80240750 44920000 */  mtc1      $s2, $f0
/* BD3FC4 80240754 00000000 */  nop       
/* BD3FC8 80240758 46800020 */  cvt.s.w   $f0, $f0
/* BD3FCC 8024075C E4600028 */  swc1      $f0, 0x28($v1)
/* BD3FD0 80240760 44910000 */  mtc1      $s1, $f0
/* BD3FD4 80240764 00000000 */  nop       
/* BD3FD8 80240768 46800020 */  cvt.s.w   $f0, $f0
/* BD3FDC 8024076C E460002C */  swc1      $f0, 0x2c($v1)
/* BD3FE0 80240770 44900000 */  mtc1      $s0, $f0
/* BD3FE4 80240774 00000000 */  nop       
/* BD3FE8 80240778 46800020 */  cvt.s.w   $f0, $f0
/* BD3FEC 8024077C E4600030 */  swc1      $f0, 0x30($v1)
/* BD3FF0 80240780 8FBF001C */  lw        $ra, 0x1c($sp)
/* BD3FF4 80240784 8FB20018 */  lw        $s2, 0x18($sp)
/* BD3FF8 80240788 8FB10014 */  lw        $s1, 0x14($sp)
/* BD3FFC 8024078C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4000 80240790 24020002 */  addiu     $v0, $zero, 2
/* BD4004 80240794 03E00008 */  jr        $ra
/* BD4008 80240798 27BD0020 */   addiu    $sp, $sp, 0x20
