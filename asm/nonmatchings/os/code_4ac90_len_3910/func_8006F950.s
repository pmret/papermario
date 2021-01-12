.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F950
/* 4AD50 8006F950 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AD54 8006F954 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AD58 8006F958 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AD5C 8006F95C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AD60 8006F960 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AD64 8006F964 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AD68 8006F968 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AD6C 8006F96C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AD70 8006F970 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AD74 8006F974 0C016959 */  jal       play_effect
/* 4AD78 8006F978 24040002 */   addiu    $a0, $zero, 2
/* 4AD7C 8006F97C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AD80 8006F980 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AD84 8006F984 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AD88 8006F988 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AD8C 8006F98C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AD90 8006F990 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AD94 8006F994 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AD98 8006F998 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AD9C 8006F99C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4ADA0 8006F9A0 3C018008 */  lui       $at, %hi(D_8007F240)
/* 4ADA4 8006F9A4 8C21F240 */  lw        $at, %lo(D_8007F240)($at)
/* 4ADA8 8006F9A8 00200008 */  jr        $at
/* 4ADAC 8006F9AC 00000000 */   nop
