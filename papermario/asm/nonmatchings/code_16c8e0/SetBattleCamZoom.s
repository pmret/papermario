.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetBattleCamZoom
/* 17D54C 8024EC6C 3C028028 */  lui   $v0, 0x8028
/* 17D550 8024EC70 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D554 8024EC74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17D558 8024EC78 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17D55C 8024EC7C 8C85000C */  lw    $a1, 0xc($a0)
/* 17D560 8024EC80 14400007 */  bnez  $v0, .L8024ECA0
/* 17D564 8024EC84 24020002 */   addiu $v0, $zero, 2
/* 17D568 8024EC88 8CA50000 */  lw    $a1, ($a1)
/* 17D56C 8024EC8C 0C0B1EAF */  jal   get_variable
/* 17D570 8024EC90 00000000 */   nop   
/* 17D574 8024EC94 3C01802A */  lui   $at, 0x802a
/* 17D578 8024EC98 A422F280 */  sh    $v0, -0xd80($at)
/* 17D57C 8024EC9C 24020002 */  addiu $v0, $zero, 2
.L8024ECA0:
/* 17D580 8024ECA0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17D584 8024ECA4 03E00008 */  jr    $ra
/* 17D588 8024ECA8 27BD0018 */   addiu $sp, $sp, 0x18

