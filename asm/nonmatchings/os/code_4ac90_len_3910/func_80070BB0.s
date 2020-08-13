.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070BB0
/* 04BFB0 80070BB0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04BFB4 80070BB4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04BFB8 80070BB8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04BFBC 80070BBC AFA60018 */  sw    $a2, 0x18($sp)
/* 04BFC0 80070BC0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04BFC4 80070BC4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04BFC8 80070BC8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04BFCC 80070BCC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04BFD0 80070BD0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04BFD4 80070BD4 0C016959 */  jal   play_effect
/* 04BFD8 80070BD8 24040033 */   addiu $a0, $zero, 0x33
/* 04BFDC 80070BDC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04BFE0 80070BE0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04BFE4 80070BE4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04BFE8 80070BE8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04BFEC 80070BEC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04BFF0 80070BF0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04BFF4 80070BF4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04BFF8 80070BF8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04BFFC 80070BFC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C000 80070C00 3C018008 */  lui   $at, 0x8008
/* 04C004 80070C04 8C21F6D8 */  lw    $at, -0x928($at)
/* 04C008 80070C08 00200008 */  jr    $at
/* 04C00C 80070C0C 00000000 */   nop   
