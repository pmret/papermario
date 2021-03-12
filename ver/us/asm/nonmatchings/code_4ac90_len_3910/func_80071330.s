.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071330
/* 4C730 80071330 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C734 80071334 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C738 80071338 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C73C 8007133C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C740 80071340 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C744 80071344 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C748 80071348 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C74C 8007134C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C750 80071350 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C754 80071354 0C016959 */  jal       load_effect
/* 4C758 80071358 24040047 */   addiu    $a0, $zero, 0x47
/* 4C75C 8007135C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C760 80071360 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C764 80071364 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C768 80071368 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C76C 8007136C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C770 80071370 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C774 80071374 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C778 80071378 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C77C 8007137C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C780 80071380 3C018008 */  lui       $at, %hi(gEffectTable+0x6A8)
/* 4C784 80071384 8C21F8B8 */  lw        $at, %lo(gEffectTable+0x6A8)($at)
/* 4C788 80071388 00200008 */  jr        $at
/* 4C78C 8007138C 00000000 */   nop
