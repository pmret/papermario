.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070350
/* 4B750 80070350 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B754 80070354 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B758 80070358 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B75C 8007035C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B760 80070360 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B764 80070364 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B768 80070368 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B76C 8007036C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B770 80070370 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B774 80070374 0C016885 */  jal       func_8005A214
/* 4B778 80070378 2404001D */   addiu    $a0, $zero, 0x1d
/* 4B77C 8007037C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B780 80070380 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B784 80070384 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B788 80070388 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B78C 8007038C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B790 80070390 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B794 80070394 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B798 80070398 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B79C 8007039C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B7A0 800703A0 3C018008 */  lui       $at, %hi(D_8007F498)
/* 4B7A4 800703A4 8C21F498 */  lw        $at, %lo(D_8007F498)($at)
/* 4B7A8 800703A8 00200008 */  jr        $at
/* 4B7AC 800703AC 00000000 */   nop
