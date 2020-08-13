.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuContRmbMgrRemove
/* 03B0EC 8005FCEC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B0F0 8005FCF0 3C048009 */  lui   $a0, 0x8009
/* 03B0F4 8005FCF4 24843D00 */  addiu $a0, $a0, 0x3d00
/* 03B0F8 8005FCF8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B0FC 8005FCFC 0C018124 */  jal   nuSiCallBackRemove
/* 03B100 8005FD00 00000000 */   nop   
/* 03B104 8005FD04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B108 8005FD08 03E00008 */  jr    $ra
/* 03B10C 8005FD0C 27BD0018 */   addiu $sp, $sp, 0x18

