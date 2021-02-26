.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B124
/* 16524 8003B124 8FA20010 */  lw        $v0, 0x10($sp)
/* 16528 8003B128 A4850310 */  sh        $a1, 0x310($a0)
/* 1652C 8003B12C A4860312 */  sh        $a2, 0x312($a0)
/* 16530 8003B130 A4870314 */  sh        $a3, 0x314($a0)
/* 16534 8003B134 03E00008 */  jr        $ra
/* 16538 8003B138 A4820316 */   sh       $v0, 0x316($a0)
