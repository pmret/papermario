.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800717F0
/* 4CBF0 800717F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CBF4 800717F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CBF8 800717F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CBFC 800717FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CC00 80071800 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CC04 80071804 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CC08 80071808 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CC0C 8007180C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CC10 80071810 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CC14 80071814 0C016885 */  jal       func_8005A214
/* 4CC18 80071818 24040054 */   addiu    $a0, $zero, 0x54
/* 4CC1C 8007181C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CC20 80071820 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CC24 80071824 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CC28 80071828 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CC2C 8007182C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CC30 80071830 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CC34 80071834 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CC38 80071838 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CC3C 8007183C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CC40 80071840 3C018008 */  lui       $at, %hi(D_8007F9C0)
/* 4CC44 80071844 8C21F9C0 */  lw        $at, %lo(D_8007F9C0)($at)
/* 4CC48 80071848 00200008 */  jr        $at
/* 4CC4C 8007184C 00000000 */   nop
