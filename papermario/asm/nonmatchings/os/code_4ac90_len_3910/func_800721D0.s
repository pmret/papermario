.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800721D0
/* 04D5D0 800721D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D5D4 800721D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D5D8 800721D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D5DC 800721DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04D5E0 800721E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D5E4 800721E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D5E8 800721E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D5EC 800721EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D5F0 800721F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D5F4 800721F4 0C016959 */  jal   play_effect
/* 04D5F8 800721F8 2404006E */   addiu $a0, $zero, 0x6e
/* 04D5FC 800721FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D600 80072200 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D604 80072204 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D608 80072208 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D60C 8007220C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D610 80072210 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D614 80072214 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D618 80072218 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D61C 8007221C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D620 80072220 3C018008 */  lui   $at, 0x8008
/* 04D624 80072224 8C21FC60 */  lw    $at, -0x3a0($at)
/* 04D628 80072228 00200008 */  jr    $at
/* 04D62C 8007222C 00000000 */   nop   
