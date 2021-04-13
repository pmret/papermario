.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F9F0
/* 4ADF0 8006F9F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4ADF4 8006F9F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4ADF8 8006F9F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4ADFC 8006F9FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4AE00 8006FA00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AE04 8006FA04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AE08 8006FA08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AE0C 8006FA0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AE10 8006FA10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AE14 8006FA14 0C016885 */  jal       func_8005A214
/* 4AE18 8006FA18 24040004 */   addiu    $a0, $zero, 4
/* 4AE1C 8006FA1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AE20 8006FA20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AE24 8006FA24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AE28 8006FA28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AE2C 8006FA2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AE30 8006FA30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AE34 8006FA34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AE38 8006FA38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AE3C 8006FA3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AE40 8006FA40 3C018008 */  lui       $at, %hi(D_8007F240)
/* 4AE44 8006FA44 8C21F240 */  lw        $at, %lo(D_8007F240)($at)
/* 4AE48 8006FA48 00200008 */  jr        $at
/* 4AE4C 8006FA4C 00000000 */   nop
