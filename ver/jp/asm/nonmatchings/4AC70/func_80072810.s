.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072810
/* 4DC10 80072810 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DC14 80072814 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DC18 80072818 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DC1C 8007281C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DC20 80072820 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DC24 80072824 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DC28 80072828 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DC2C 8007282C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DC30 80072830 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DC34 80072834 0C016885 */  jal       func_8005A214
/* 4DC38 80072838 2404007F */   addiu    $a0, $zero, 0x7f
/* 4DC3C 8007283C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DC40 80072840 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DC44 80072844 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DC48 80072848 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DC4C 8007284C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DC50 80072850 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DC54 80072854 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DC58 80072858 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DC5C 8007285C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DC60 80072860 3C018008 */  lui       $at, %hi(D_8007FDC8)
/* 4DC64 80072864 8C21FDC8 */  lw        $at, %lo(D_8007FDC8)($at)
/* 4DC68 80072868 00200008 */  jr        $at
/* 4DC6C 8007286C 00000000 */   nop
