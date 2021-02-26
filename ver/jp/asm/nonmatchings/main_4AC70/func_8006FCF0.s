.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FCF0
/* 4B0F0 8006FCF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B0F4 8006FCF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B0F8 8006FCF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B0FC 8006FCFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B100 8006FD00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B104 8006FD04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B108 8006FD08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B10C 8006FD0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B110 8006FD10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B114 8006FD14 0C016885 */  jal       func_8005A214
/* 4B118 8006FD18 2404000C */   addiu    $a0, $zero, 0xc
/* 4B11C 8006FD1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B120 8006FD20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B124 8006FD24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B128 8006FD28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B12C 8006FD2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B130 8006FD30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B134 8006FD34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B138 8006FD38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B13C 8006FD3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B140 8006FD40 3C018008 */  lui       $at, %hi(D_8007F300)
/* 4B144 8006FD44 8C21F300 */  lw        $at, %lo(D_8007F300)($at)
/* 4B148 8006FD48 00200008 */  jr        $at
/* 4B14C 8006FD4C 00000000 */   nop
