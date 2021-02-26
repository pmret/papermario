.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800718B0
/* 4CCB0 800718B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CCB4 800718B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CCB8 800718B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CCBC 800718BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CCC0 800718C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CCC4 800718C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CCC8 800718C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CCCC 800718CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CCD0 800718D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CCD4 800718D4 0C016885 */  jal       func_8005A214
/* 4CCD8 800718D8 24040056 */   addiu    $a0, $zero, 0x56
/* 4CCDC 800718DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CCE0 800718E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CCE4 800718E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CCE8 800718E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CCEC 800718EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CCF0 800718F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CCF4 800718F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CCF8 800718F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CCFC 800718FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CD00 80071900 3C018008 */  lui       $at, %hi(D_8007F9F0)
/* 4CD04 80071904 8C21F9F0 */  lw        $at, %lo(D_8007F9F0)($at)
/* 4CD08 80071908 00200008 */  jr        $at
/* 4CD0C 8007190C 00000000 */   nop
