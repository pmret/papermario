.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C670
/* 47A70 8006C670 4442F800 */  cfc1      $v0, $31
/* 47A74 8006C674 44C4F800 */  ctc1      $a0, $31
/* 47A78 8006C678 03E00008 */  jr        $ra
/* 47A7C 8006C67C 00000000 */   nop
