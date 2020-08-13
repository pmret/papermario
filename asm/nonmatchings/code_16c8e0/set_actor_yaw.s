.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_actor_yaw
/* 192848 80263F68 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19284C 80263F6C AFB00010 */  sw    $s0, 0x10($sp)
/* 192850 80263F70 AFBF0014 */  sw    $ra, 0x14($sp)
/* 192854 80263F74 0C09A75B */  jal   get_actor
/* 192858 80263F78 00A0802D */   daddu $s0, $a1, $zero
/* 19285C 80263F7C 44900000 */  mtc1  $s0, $f0
/* 192860 80263F80 00000000 */  nop   
/* 192864 80263F84 46800020 */  cvt.s.w $f0, $f0
/* 192868 80263F88 E440018C */  swc1  $f0, 0x18c($v0)
/* 19286C 80263F8C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 192870 80263F90 8FB00010 */  lw    $s0, 0x10($sp)
/* 192874 80263F94 03E00008 */  jr    $ra
/* 192878 80263F98 27BD0018 */   addiu $sp, $sp, 0x18

