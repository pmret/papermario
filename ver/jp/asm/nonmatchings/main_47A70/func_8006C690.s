.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C690
/* 47A90 8006C690 40849000 */  mtc0      $a0, $18
/* 47A94 8006C694 00000000 */  nop
/* 47A98 8006C698 03E00008 */  jr        $ra
/* 47A9C 8006C69C 00000000 */   nop
