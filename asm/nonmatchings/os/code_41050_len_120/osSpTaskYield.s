.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSpTaskYield
/* 041050 80065C50 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 041054 80065C54 AFBF0010 */  sw    $ra, 0x10($sp)
/* 041058 80065C58 0C01B1BC */  jal   osSpSetStatus
/* 04105C 80065C5C 24040400 */   addiu $a0, $zero, 0x400
/* 041060 80065C60 8FBF0010 */  lw    $ra, 0x10($sp)
/* 041064 80065C64 03E00008 */  jr    $ra
/* 041068 80065C68 27BD0018 */   addiu $sp, $sp, 0x18

/* 04106C 80065C6C 00000000 */  nop   
