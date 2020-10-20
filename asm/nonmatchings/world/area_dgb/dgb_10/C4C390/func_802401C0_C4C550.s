.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401C0_C4C550
/* C4C550 802401C0 3C018011 */  lui       $at, 0x8011
/* C4C554 802401C4 C422EFF4 */  lwc1      $f2, -0x100c($at)
/* C4C558 802401C8 3C01C270 */  lui       $at, 0xc270
/* C4C55C 802401CC 44810000 */  mtc1      $at, $f0
/* C4C560 802401D0 00000000 */  nop       
/* C4C564 802401D4 4602003C */  c.lt.s    $f0, $f2
/* C4C568 802401D8 00000000 */  nop       
/* C4C56C 802401DC 45010002 */  bc1t      .L802401E8
/* C4C570 802401E0 0000102D */   daddu    $v0, $zero, $zero
/* C4C574 802401E4 24020002 */  addiu     $v0, $zero, 2
.L802401E8:
/* C4C578 802401E8 03E00008 */  jr        $ra
/* C4C57C 802401EC 00000000 */   nop      
