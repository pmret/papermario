.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024008C_BF482C
/* BF482C 8024008C 3C018011 */  lui       $at, 0x8011
/* BF4830 80240090 C422EFF4 */  lwc1      $f2, -0x100c($at)
/* BF4834 80240094 3C01C120 */  lui       $at, 0xc120
/* BF4838 80240098 44810000 */  mtc1      $at, $f0
/* BF483C 8024009C 00000000 */  nop       
/* BF4840 802400A0 4600103C */  c.lt.s    $f2, $f0
/* BF4844 802400A4 00000000 */  nop       
/* BF4848 802400A8 45010002 */  bc1t      .L802400B4
/* BF484C 802400AC 24020002 */   addiu    $v0, $zero, 2
/* BF4850 802400B0 0000102D */  daddu     $v0, $zero, $zero
.L802400B4:
/* BF4854 802400B4 03E00008 */  jr        $ra
/* BF4858 802400B8 00000000 */   nop      
/* BF485C 802400BC 00000000 */  nop       
