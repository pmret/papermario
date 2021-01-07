.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800718D0
/* 4CCD0 800718D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CCD4 800718D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CCD8 800718D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CCDC 800718DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CCE0 800718E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CCE4 800718E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CCE8 800718E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CCEC 800718EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CCF0 800718F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CCF4 800718F4 0C016959 */  jal       play_effect
/* 4CCF8 800718F8 24040056 */   addiu    $a0, $zero, 0x56
/* 4CCFC 800718FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CD00 80071900 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CD04 80071904 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CD08 80071908 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CD0C 8007190C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CD10 80071910 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CD14 80071914 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CD18 80071918 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CD1C 8007191C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CD20 80071920 3C018008 */  lui       $at, %hi(D_8007FA20)
/* 4CD24 80071924 8C21FA20 */  lw        $at, %lo(D_8007FA20)($at)
/* 4CD28 80071928 00200008 */  jr        $at
/* 4CD2C 8007192C 00000000 */   nop      
