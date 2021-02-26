.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800728D0
/* 4DCD0 800728D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DCD4 800728D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DCD8 800728D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DCDC 800728DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DCE0 800728E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DCE4 800728E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DCE8 800728E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DCEC 800728EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DCF0 800728F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DCF4 800728F4 0C016885 */  jal       func_8005A214
/* 4DCF8 800728F8 24040081 */   addiu    $a0, $zero, 0x81
/* 4DCFC 800728FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DD00 80072900 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DD04 80072904 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DD08 80072908 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DD0C 8007290C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DD10 80072910 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DD14 80072914 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DD18 80072918 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DD1C 8007291C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DD20 80072920 3C018008 */  lui       $at, %hi(D_8007FDF8)
/* 4DD24 80072924 8C21FDF8 */  lw        $at, %lo(D_8007FDF8)($at)
/* 4DD28 80072928 00200008 */  jr        $at
/* 4DD2C 8007292C 00000000 */   nop
