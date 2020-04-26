
.section .text80060350, "ax"

nuGfxSwapCfb:
/* 03B750 80060350 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B754 80060354 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B758 80060358 0C019C08 */  jal   osViSwapBuffer
/* 03B75C 8006035C 8C84000C */   lw    $a0, 0xc($a0)
/* 03B760 80060360 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B764 80060364 03E00008 */  jr    $ra
/* 03B768 80060368 27BD0018 */   addiu $sp, $sp, 0x18

/* 03B76C 8006036C 00000000 */  nop   
