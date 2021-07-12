.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_6C
/* 4D510 80072110 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D514 80072114 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D518 80072118 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D51C 8007211C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D520 80072120 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D524 80072124 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D528 80072128 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D52C 8007212C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D530 80072130 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D534 80072134 0C016959 */  jal       load_effect
/* 4D538 80072138 2404006C */   addiu    $a0, $zero, 0x6c
/* 4D53C 8007213C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D540 80072140 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D544 80072144 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D548 80072148 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D54C 8007214C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D550 80072150 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D554 80072154 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D558 80072158 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D55C 8007215C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D560 80072160 3C018008 */  lui       $at, %hi(gEffectTable+0xA20)
/* 4D564 80072164 8C21FC30 */  lw        $at, %lo(gEffectTable+0xA20)($at)
/* 4D568 80072168 00200008 */  jr        $at
/* 4D56C 8007216C 00000000 */   nop
