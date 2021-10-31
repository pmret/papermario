.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osGetCount
/* 40DD0 800659D0 40024800 */  mfc0      $v0, $9
/* 40DD4 800659D4 03E00008 */  jr        $ra
/* 40DD8 800659D8 00000000 */   nop
/* 40DDC 800659DC 00000000 */  nop
