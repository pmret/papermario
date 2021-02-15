.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240910_BC8770
/* BC8770 80240910 3C018011 */  lui       $at, %hi(gPlayerStatus+0x2C)
/* BC8774 80240914 C422EFF4 */  lwc1      $f2, %lo(gPlayerStatus+0x2C)($at)
/* BC8778 80240918 3C01C248 */  lui       $at, 0xc248
/* BC877C 8024091C 44810000 */  mtc1      $at, $f0
/* BC8780 80240920 00000000 */  nop
/* BC8784 80240924 4600103C */  c.lt.s    $f2, $f0
/* BC8788 80240928 00000000 */  nop
/* BC878C 8024092C 45010002 */  bc1t      .L80240938
/* BC8790 80240930 24020002 */   addiu    $v0, $zero, 2
/* BC8794 80240934 0000102D */  daddu     $v0, $zero, $zero
.L80240938:
/* BC8798 80240938 03E00008 */  jr        $ra
/* BC879C 8024093C 00000000 */   nop
