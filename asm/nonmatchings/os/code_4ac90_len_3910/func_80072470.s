.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072470
/* 04D870 80072470 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D874 80072474 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D878 80072478 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D87C 8007247C AFA60018 */  sw    $a2, 0x18($sp)
/* 04D880 80072480 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D884 80072484 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D888 80072488 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D88C 8007248C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D890 80072490 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D894 80072494 0C016959 */  jal   play_effect
/* 04D898 80072498 24040075 */   addiu $a0, $zero, 0x75
/* 04D89C 8007249C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D8A0 800724A0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D8A4 800724A4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D8A8 800724A8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D8AC 800724AC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D8B0 800724B0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D8B4 800724B4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D8B8 800724B8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D8BC 800724BC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D8C0 800724C0 3C018008 */  lui   $at, 0x8008
/* 04D8C4 800724C4 8C21FD08 */  lw    $at, -0x2f8($at)
/* 04D8C8 800724C8 00200008 */  jr    $at
/* 04D8CC 800724CC 00000000 */   nop   
/* 04D8D0 800724D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D8D4 800724D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D8D8 800724D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D8DC 800724DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04D8E0 800724E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D8E4 800724E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D8E8 800724E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D8EC 800724EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D8F0 800724F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D8F4 800724F4 0C016959 */  jal   play_effect
/* 04D8F8 800724F8 24040076 */   addiu $a0, $zero, 0x76
/* 04D8FC 800724FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D900 80072500 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D904 80072504 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D908 80072508 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D90C 8007250C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D910 80072510 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D914 80072514 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D918 80072518 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D91C 8007251C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D920 80072520 3C018008 */  lui   $at, 0x8008
/* 04D924 80072524 8C21FD20 */  lw    $at, -0x2e0($at)
/* 04D928 80072528 00200008 */  jr    $at
/* 04D92C 8007252C 00000000 */   nop   
