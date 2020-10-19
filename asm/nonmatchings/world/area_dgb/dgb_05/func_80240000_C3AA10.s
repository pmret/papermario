.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C3AA10
/* C3AA10 80240000 3C018011 */  lui       $at, 0x8011
/* C3AA14 80240004 C422EFF4 */  lwc1      $f2, -0x100c($at)
/* C3AA18 80240008 3C01C352 */  lui       $at, 0xc352
/* C3AA1C 8024000C 44810000 */  mtc1      $at, $f0
/* C3AA20 80240010 00000000 */  nop       
/* C3AA24 80240014 4602003E */  c.le.s    $f0, $f2
/* C3AA28 80240018 00000000 */  nop       
/* C3AA2C 8024001C 45010002 */  bc1t      .L80240028
/* C3AA30 80240020 0000102D */   daddu    $v0, $zero, $zero
/* C3AA34 80240024 24020002 */  addiu     $v0, $zero, 2
.L80240028:
/* C3AA38 80240028 03E00008 */  jr        $ra
/* C3AA3C 8024002C 00000000 */   nop      
