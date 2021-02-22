.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FE70
/* 4B270 8006FE70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B274 8006FE74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B278 8006FE78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B27C 8006FE7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B280 8006FE80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B284 8006FE84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B288 8006FE88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B28C 8006FE8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B290 8006FE90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B294 8006FE94 0C016885 */  jal       func_8005A214
/* 4B298 8006FE98 24040010 */   addiu    $a0, $zero, 0x10
/* 4B29C 8006FE9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B2A0 8006FEA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B2A4 8006FEA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B2A8 8006FEA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B2AC 8006FEAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B2B0 8006FEB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B2B4 8006FEB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B2B8 8006FEB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B2BC 8006FEBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B2C0 8006FEC0 3C018008 */  lui       $at, %hi(D_8007F360)
/* 4B2C4 8006FEC4 8C21F360 */  lw        $at, %lo(D_8007F360)($at)
/* 4B2C8 8006FEC8 00200008 */  jr        $at
/* 4B2CC 8006FECC 00000000 */   nop
