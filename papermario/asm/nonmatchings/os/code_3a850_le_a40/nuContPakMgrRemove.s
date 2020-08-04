.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuContPakMgrRemove
/* 03AAD4 8005F6D4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03AAD8 8005F6D8 3C048009 */  lui   $a0, 0x8009
/* 03AADC 8005F6DC 24843CD0 */  addiu $a0, $a0, 0x3cd0
/* 03AAE0 8005F6E0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03AAE4 8005F6E4 0C018124 */  jal   nuSiCallBackRemove
/* 03AAE8 8005F6E8 00000000 */   nop   
/* 03AAEC 8005F6EC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03AAF0 8005F6F0 03E00008 */  jr    $ra
/* 03AAF4 8005F6F4 27BD0018 */   addiu $sp, $sp, 0x18

