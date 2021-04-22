.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072330
/* 4D730 80072330 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D734 80072334 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D738 80072338 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D73C 8007233C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D740 80072340 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D744 80072344 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D748 80072348 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D74C 8007234C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D750 80072350 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D754 80072354 0C016885 */  jal       func_8005A214
/* 4D758 80072358 24040072 */   addiu    $a0, $zero, 0x72
/* 4D75C 8007235C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D760 80072360 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D764 80072364 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D768 80072368 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D76C 8007236C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D770 80072370 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D774 80072374 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D778 80072378 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D77C 8007237C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D780 80072380 3C018008 */  lui       $at, %hi(D_8007FC90)
/* 4D784 80072384 8C21FC90 */  lw        $at, %lo(D_8007FC90)($at)
/* 4D788 80072388 00200008 */  jr        $at
/* 4D78C 8007238C 00000000 */   nop
