.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240770_BCD7D0
/* BCD7D0 80240770 3C018011 */  lui       $at, 0x8011
/* BCD7D4 80240774 C422EFF4 */  lwc1      $f2, -0x100c($at)
/* BCD7D8 80240778 3C01C248 */  lui       $at, 0xc248
/* BCD7DC 8024077C 44810000 */  mtc1      $at, $f0
/* BCD7E0 80240780 00000000 */  nop       
/* BCD7E4 80240784 4600103C */  c.lt.s    $f2, $f0
/* BCD7E8 80240788 00000000 */  nop       
/* BCD7EC 8024078C 45010002 */  bc1t      .L80240798
/* BCD7F0 80240790 24020002 */   addiu    $v0, $zero, 2
/* BCD7F4 80240794 0000102D */  daddu     $v0, $zero, $zero
.L80240798:
/* BCD7F8 80240798 03E00008 */  jr        $ra
/* BCD7FC 8024079C 00000000 */   nop      
