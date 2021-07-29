.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072990
/* 4DD90 80072990 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DD94 80072994 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DD98 80072998 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DD9C 8007299C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DDA0 800729A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DDA4 800729A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DDA8 800729A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DDAC 800729AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DDB0 800729B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DDB4 800729B4 0C016885 */  jal       func_8005A214
/* 4DDB8 800729B8 24040083 */   addiu    $a0, $zero, 0x83
/* 4DDBC 800729BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DDC0 800729C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DDC4 800729C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DDC8 800729C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DDCC 800729CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DDD0 800729D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DDD4 800729D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DDD8 800729D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DDDC 800729DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DDE0 800729E0 3C018008 */  lui       $at, %hi(D_8007FE28)
/* 4DDE4 800729E4 8C21FE28 */  lw        $at, %lo(D_8007FE28)($at)
/* 4DDE8 800729E8 00200008 */  jr        $at
/* 4DDEC 800729EC 00000000 */   nop
