.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800728F0
/* 4DCF0 800728F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DCF4 800728F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DCF8 800728F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DCFC 800728FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DD00 80072900 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DD04 80072904 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DD08 80072908 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DD0C 8007290C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DD10 80072910 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DD14 80072914 0C016959 */  jal       play_effect
/* 4DD18 80072918 24040081 */   addiu    $a0, $zero, 0x81
/* 4DD1C 8007291C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DD20 80072920 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DD24 80072924 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DD28 80072928 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DD2C 8007292C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DD30 80072930 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DD34 80072934 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DD38 80072938 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DD3C 8007293C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DD40 80072940 3C018008 */  lui       $at, %hi(D_8007FE28)
/* 4DD44 80072944 8C21FE28 */  lw        $at, %lo(D_8007FE28)($at)
/* 4DD48 80072948 00200008 */  jr        $at
/* 4DD4C 8007294C 00000000 */   nop
