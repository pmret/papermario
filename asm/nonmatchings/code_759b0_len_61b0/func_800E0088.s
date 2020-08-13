.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E0088
/* 079538 800E0088 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07953C 800E008C 3C028011 */  lui   $v0, 0x8011
/* 079540 800E0090 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 079544 800E0094 AFBF0010 */  sw    $ra, 0x10($sp)
/* 079548 800E0098 8C460028 */  lw    $a2, 0x28($v0)
/* 07954C 800E009C 0C00A7B5 */  jal   dist2D
/* 079550 800E00A0 8C470030 */   lw    $a3, 0x30($v0)
/* 079554 800E00A4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 079558 800E00A8 03E00008 */  jr    $ra
/* 07955C 800E00AC 27BD0018 */   addiu $sp, $sp, 0x18

