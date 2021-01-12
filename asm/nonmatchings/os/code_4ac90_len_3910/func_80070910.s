.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070910
/* 4BD10 80070910 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BD14 80070914 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BD18 80070918 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BD1C 8007091C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BD20 80070920 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BD24 80070924 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BD28 80070928 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BD2C 8007092C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BD30 80070930 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BD34 80070934 0C016959 */  jal       play_effect
/* 4BD38 80070938 2404002C */   addiu    $a0, $zero, 0x2c
/* 4BD3C 8007093C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BD40 80070940 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BD44 80070944 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BD48 80070948 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BD4C 8007094C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BD50 80070950 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BD54 80070954 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BD58 80070958 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BD5C 8007095C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BD60 80070960 3C018008 */  lui       $at, %hi(D_8007F630)
/* 4BD64 80070964 8C21F630 */  lw        $at, %lo(D_8007F630)($at)
/* 4BD68 80070968 00200008 */  jr        $at
/* 4BD6C 8007096C 00000000 */   nop
