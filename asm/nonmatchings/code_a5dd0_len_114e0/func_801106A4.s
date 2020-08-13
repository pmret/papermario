.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801106A4
/* 0A6DA4 801106A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A6DA8 801106A8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0A6DAC 801106AC 0C04417A */  jal   get_entity_by_index
/* 0A6DB0 801106B0 00000000 */   nop   
/* 0A6DB4 801106B4 50400003 */  beql  $v0, $zero, .L801106C4
/* 0A6DB8 801106B8 2402FFFF */   addiu $v0, $zero, -1
/* 0A6DBC 801106BC 8C420038 */  lw    $v0, 0x38($v0)
/* 0A6DC0 801106C0 90420020 */  lbu   $v0, 0x20($v0)
.L801106C4:
/* 0A6DC4 801106C4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0A6DC8 801106C8 03E00008 */  jr    $ra
/* 0A6DCC 801106CC 27BD0018 */   addiu $sp, $sp, 0x18

