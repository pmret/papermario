.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSpTaskStartGo
/* 04101C 80065C1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 041020 80065C20 AFBF0010 */  sw    $ra, 0x10($sp)
.L80065C24:
/* 041024 80065C24 0C01B1B0 */  jal   osSpDeviceBusy
/* 041028 80065C28 00000000 */   nop   
/* 04102C 80065C2C 1440FFFD */  bnez  $v0, .L80065C24
/* 041030 80065C30 00000000 */   nop   
/* 041034 80065C34 0C01B1BC */  jal   osSpSetStatus
/* 041038 80065C38 24040125 */   addiu $a0, $zero, 0x125
/* 04103C 80065C3C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 041040 80065C40 03E00008 */  jr    $ra
/* 041044 80065C44 27BD0018 */   addiu $sp, $sp, 0x18

/* 041048 80065C48 00000000 */  nop   
/* 04104C 80065C4C 00000000 */  nop   

.set reorder
