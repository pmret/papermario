.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel gfxPreNMI_Callback
/* 001B0C 8002670C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 001B10 80026710 24020001 */  addiu $v0, $zero, 1
/* 001B14 80026714 AFBF0010 */  sw    $ra, 0x10($sp)
/* 001B18 80026718 3C018007 */  lui   $at, 0x8007
/* 001B1C 8002671C AC223E00 */  sw    $v0, 0x3e00($at)
/* 001B20 80026720 0C018028 */  jal   nuContRmbForceStop
/* 001B24 80026724 00000000 */   nop   
/* 001B28 80026728 8FBF0010 */  lw    $ra, 0x10($sp)
/* 001B2C 8002672C 03E00008 */  jr    $ra
/* 001B30 80026730 27BD0018 */   addiu $sp, $sp, 0x18

/* 001B34 80026734 00000000 */  nop   
/* 001B38 80026738 00000000 */  nop   
/* 001B3C 8002673C 00000000 */  nop   


