.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070670
/* 04BA70 80070670 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04BA74 80070674 AFA40010 */  sw    $a0, 0x10($sp)
/* 04BA78 80070678 AFA50014 */  sw    $a1, 0x14($sp)
/* 04BA7C 8007067C AFA60018 */  sw    $a2, 0x18($sp)
/* 04BA80 80070680 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04BA84 80070684 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04BA88 80070688 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04BA8C 8007068C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04BA90 80070690 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04BA94 80070694 0C016959 */  jal   play_effect
/* 04BA98 80070698 24040025 */   addiu $a0, $zero, 0x25
/* 04BA9C 8007069C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04BAA0 800706A0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04BAA4 800706A4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04BAA8 800706A8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04BAAC 800706AC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04BAB0 800706B0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04BAB4 800706B4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04BAB8 800706B8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04BABC 800706BC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04BAC0 800706C0 3C018008 */  lui   $at, 0x8008
/* 04BAC4 800706C4 8C21F588 */  lw    $at, -0xa78($at)
/* 04BAC8 800706C8 00200008 */  jr    $at
/* 04BACC 800706CC 00000000 */   nop   
