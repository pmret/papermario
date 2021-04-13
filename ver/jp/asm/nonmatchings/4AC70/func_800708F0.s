.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800708F0
/* 4BCF0 800708F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BCF4 800708F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BCF8 800708F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BCFC 800708FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BD00 80070900 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BD04 80070904 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BD08 80070908 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BD0C 8007090C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BD10 80070910 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BD14 80070914 0C016885 */  jal       func_8005A214
/* 4BD18 80070918 2404002C */   addiu    $a0, $zero, 0x2c
/* 4BD1C 8007091C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BD20 80070920 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BD24 80070924 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BD28 80070928 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BD2C 8007092C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BD30 80070930 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BD34 80070934 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BD38 80070938 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BD3C 8007093C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BD40 80070940 3C018008 */  lui       $at, %hi(D_8007F600)
/* 4BD44 80070944 8C21F600 */  lw        $at, %lo(D_8007F600)($at)
/* 4BD48 80070948 00200008 */  jr        $at
/* 4BD4C 8007094C 00000000 */   nop
