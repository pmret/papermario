.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FA10
/* 4AE10 8006FA10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AE14 8006FA14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AE18 8006FA18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AE1C 8006FA1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AE20 8006FA20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AE24 8006FA24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AE28 8006FA28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AE2C 8006FA2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AE30 8006FA30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AE34 8006FA34 0C016959 */  jal       play_effect
/* 4AE38 8006FA38 24040004 */   addiu    $a0, $zero, 4
/* 4AE3C 8006FA3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AE40 8006FA40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AE44 8006FA44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AE48 8006FA48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AE4C 8006FA4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AE50 8006FA50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AE54 8006FA54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AE58 8006FA58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AE5C 8006FA5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AE60 8006FA60 3C018008 */  lui       $at, 0x8008
/* 4AE64 8006FA64 8C21F270 */  lw        $at, -0xd90($at)
/* 4AE68 8006FA68 00200008 */  jr        $at
/* 4AE6C 8006FA6C 00000000 */   nop      
