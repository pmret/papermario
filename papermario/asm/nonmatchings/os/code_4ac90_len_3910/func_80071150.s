.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80071150
/* 04C550 80071150 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C554 80071154 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C558 80071158 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C55C 8007115C AFA60018 */  sw    $a2, 0x18($sp)
/* 04C560 80071160 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C564 80071164 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C568 80071168 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C56C 8007116C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C570 80071170 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C574 80071174 0C016959 */  jal   play_effect
/* 04C578 80071178 24040042 */   addiu $a0, $zero, 0x42
/* 04C57C 8007117C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C580 80071180 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C584 80071184 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C588 80071188 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C58C 8007118C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C590 80071190 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C594 80071194 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C598 80071198 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C59C 8007119C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C5A0 800711A0 3C018008 */  lui   $at, 0x8008
/* 04C5A4 800711A4 8C21F840 */  lw    $at, -0x7c0($at)
/* 04C5A8 800711A8 00200008 */  jr    $at
/* 04C5AC 800711AC 00000000 */   nop   
