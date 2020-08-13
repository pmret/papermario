.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel WaitForMessageBoxDone
/* 17FCAC 802513CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17FCB0 802513D0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17FCB4 802513D4 0C093EAD */  jal   is_popup_displayed
/* 17FCB8 802513D8 00000000 */   nop   
/* 17FCBC 802513DC 2C420001 */  sltiu $v0, $v0, 1
/* 17FCC0 802513E0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17FCC4 802513E4 00021040 */  sll   $v0, $v0, 1
/* 17FCC8 802513E8 03E00008 */  jr    $ra
/* 17FCCC 802513EC 27BD0018 */   addiu $sp, $sp, 0x18

