.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800714F0
/* 4C8F0 800714F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C8F4 800714F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C8F8 800714F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C8FC 800714FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C900 80071500 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C904 80071504 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C908 80071508 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C90C 8007150C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C910 80071510 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C914 80071514 0C016885 */  jal       func_8005A214
/* 4C918 80071518 2404004C */   addiu    $a0, $zero, 0x4c
/* 4C91C 8007151C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C920 80071520 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C924 80071524 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C928 80071528 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C92C 8007152C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C930 80071530 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C934 80071534 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C938 80071538 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C93C 8007153C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C940 80071540 3C018008 */  lui       $at, %hi(D_8007F900)
/* 4C944 80071544 8C21F900 */  lw        $at, %lo(D_8007F900)($at)
/* 4C948 80071548 00200008 */  jr        $at
/* 4C94C 8007154C 00000000 */   nop
