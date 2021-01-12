.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071810
/* 4CC10 80071810 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CC14 80071814 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CC18 80071818 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CC1C 8007181C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CC20 80071820 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CC24 80071824 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CC28 80071828 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CC2C 8007182C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CC30 80071830 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CC34 80071834 0C016959 */  jal       play_effect
/* 4CC38 80071838 24040054 */   addiu    $a0, $zero, 0x54
/* 4CC3C 8007183C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CC40 80071840 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CC44 80071844 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CC48 80071848 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CC4C 8007184C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CC50 80071850 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CC54 80071854 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CC58 80071858 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CC5C 8007185C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CC60 80071860 3C018008 */  lui       $at, %hi(D_8007F9F0)
/* 4CC64 80071864 8C21F9F0 */  lw        $at, %lo(D_8007F9F0)($at)
/* 4CC68 80071868 00200008 */  jr        $at
/* 4CC6C 8007186C 00000000 */   nop
