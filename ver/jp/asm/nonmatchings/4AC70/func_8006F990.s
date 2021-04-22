.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F990
/* 4AD90 8006F990 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AD94 8006F994 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AD98 8006F998 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AD9C 8006F99C AFA60018 */  sw        $a2, 0x18($sp)
/* 4ADA0 8006F9A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4ADA4 8006F9A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4ADA8 8006F9A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4ADAC 8006F9AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4ADB0 8006F9B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4ADB4 8006F9B4 0C016885 */  jal       func_8005A214
/* 4ADB8 8006F9B8 24040003 */   addiu    $a0, $zero, 3
/* 4ADBC 8006F9BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4ADC0 8006F9C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4ADC4 8006F9C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4ADC8 8006F9C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4ADCC 8006F9CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4ADD0 8006F9D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4ADD4 8006F9D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4ADD8 8006F9D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4ADDC 8006F9DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4ADE0 8006F9E0 3C018008 */  lui       $at, %hi(D_8007F228)
/* 4ADE4 8006F9E4 8C21F228 */  lw        $at, %lo(D_8007F228)($at)
/* 4ADE8 8006F9E8 00200008 */  jr        $at
/* 4ADEC 8006F9EC 00000000 */   nop
