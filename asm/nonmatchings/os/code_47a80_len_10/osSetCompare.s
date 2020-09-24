.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSetCompare
/* 47A80 8006C680 40845800 */  mtc0      $a0, $11
/* 47A84 8006C684 03E00008 */  jr        $ra
/* 47A88 8006C688 00000000 */   nop      
/* 47A8C 8006C68C 00000000 */  nop       
