.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F9B0
/* 4ADB0 8006F9B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4ADB4 8006F9B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4ADB8 8006F9B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4ADBC 8006F9BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4ADC0 8006F9C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4ADC4 8006F9C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4ADC8 8006F9C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4ADCC 8006F9CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4ADD0 8006F9D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4ADD4 8006F9D4 0C016959 */  jal       play_effect
/* 4ADD8 8006F9D8 24040003 */   addiu    $a0, $zero, 3
/* 4ADDC 8006F9DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4ADE0 8006F9E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4ADE4 8006F9E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4ADE8 8006F9E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4ADEC 8006F9EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4ADF0 8006F9F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4ADF4 8006F9F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4ADF8 8006F9F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4ADFC 8006F9FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AE00 8006FA00 3C018008 */  lui       $at, %hi(D_8007F258)
/* 4AE04 8006FA04 8C21F258 */  lw        $at, %lo(D_8007F258)($at)
/* 4AE08 8006FA08 00200008 */  jr        $at
/* 4AE0C 8006FA0C 00000000 */   nop      
