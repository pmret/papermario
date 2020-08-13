.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E26B0
/* 07BB60 800E26B0 3C028011 */  lui   $v0, 0x8011
/* 07BB64 800E26B4 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 07BB68 800E26B8 C440002C */  lwc1  $f0, 0x2c($v0)
/* 07BB6C 800E26BC 03E00008 */  jr    $ra
/* 07BB70 800E26C0 E4400050 */   swc1  $f0, 0x50($v0)

