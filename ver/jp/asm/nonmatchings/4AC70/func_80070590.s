.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070590
/* 4B990 80070590 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B994 80070594 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B998 80070598 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B99C 8007059C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B9A0 800705A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B9A4 800705A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B9A8 800705A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B9AC 800705AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B9B0 800705B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B9B4 800705B4 0C016885 */  jal       func_8005A214
/* 4B9B8 800705B8 24040023 */   addiu    $a0, $zero, 0x23
/* 4B9BC 800705BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B9C0 800705C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B9C4 800705C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B9C8 800705C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B9CC 800705CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B9D0 800705D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B9D4 800705D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B9D8 800705D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B9DC 800705DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B9E0 800705E0 3C018008 */  lui       $at, %hi(D_8007F528)
/* 4B9E4 800705E4 8C21F528 */  lw        $at, %lo(D_8007F528)($at)
/* 4B9E8 800705E8 00200008 */  jr        $at
/* 4B9EC 800705EC 00000000 */   nop
