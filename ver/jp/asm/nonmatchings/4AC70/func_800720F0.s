.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800720F0
/* 4D4F0 800720F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D4F4 800720F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D4F8 800720F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D4FC 800720FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D500 80072100 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D504 80072104 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D508 80072108 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D50C 8007210C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D510 80072110 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D514 80072114 0C016885 */  jal       func_8005A214
/* 4D518 80072118 2404006C */   addiu    $a0, $zero, 0x6c
/* 4D51C 8007211C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D520 80072120 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D524 80072124 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D528 80072128 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D52C 8007212C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D530 80072130 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D534 80072134 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D538 80072138 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D53C 8007213C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D540 80072140 3C018008 */  lui       $at, %hi(D_8007FC00)
/* 4D544 80072144 8C21FC00 */  lw        $at, %lo(D_8007FC00)($at)
/* 4D548 80072148 00200008 */  jr        $at
/* 4D54C 8007214C 00000000 */   nop
