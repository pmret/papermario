.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel mtx_ident_mirror_y
/* 013878 80038478 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01387C 8003847C AFB00010 */  sw    $s0, 0x10($sp)
/* 013880 80038480 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013884 80038484 0C019D28 */  jal   guMtxIdentF
/* 013888 80038488 0080802D */   daddu $s0, $a0, $zero
/* 01388C 8003848C 3C013F80 */  lui   $at, 0x3f80
/* 013890 80038490 44810000 */  mtc1  $at, $f0
/* 013894 80038494 3C01BF80 */  lui   $at, 0xbf80
/* 013898 80038498 44811000 */  mtc1  $at, $f2
/* 01389C 8003849C E6000000 */  swc1  $f0, ($s0)
/* 0138A0 800384A0 E6020014 */  swc1  $f2, 0x14($s0)
/* 0138A4 800384A4 E6000028 */  swc1  $f0, 0x28($s0)
/* 0138A8 800384A8 E600003C */  swc1  $f0, 0x3c($s0)
/* 0138AC 800384AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0138B0 800384B0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0138B4 800384B4 03E00008 */  jr    $ra
/* 0138B8 800384B8 27BD0018 */   addiu $sp, $sp, 0x18

