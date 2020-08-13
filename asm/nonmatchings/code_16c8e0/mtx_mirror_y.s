.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel mtx_mirror_y
/* 182B68 80254288 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 182B6C 8025428C AFB00010 */  sw    $s0, 0x10($sp)
/* 182B70 80254290 AFBF0014 */  sw    $ra, 0x14($sp)
/* 182B74 80254294 0C019D28 */  jal   guMtxIdentF
/* 182B78 80254298 0080802D */   daddu $s0, $a0, $zero
/* 182B7C 8025429C 3C013F80 */  lui   $at, 0x3f80
/* 182B80 802542A0 44810000 */  mtc1  $at, $f0
/* 182B84 802542A4 3C01BF80 */  lui   $at, 0xbf80
/* 182B88 802542A8 44811000 */  mtc1  $at, $f2
/* 182B8C 802542AC E6000000 */  swc1  $f0, ($s0)
/* 182B90 802542B0 E6020014 */  swc1  $f2, 0x14($s0)
/* 182B94 802542B4 E6000028 */  swc1  $f0, 0x28($s0)
/* 182B98 802542B8 E600003C */  swc1  $f0, 0x3c($s0)
/* 182B9C 802542BC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 182BA0 802542C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 182BA4 802542C4 03E00008 */  jr    $ra
/* 182BA8 802542C8 27BD0018 */   addiu $sp, $sp, 0x18

