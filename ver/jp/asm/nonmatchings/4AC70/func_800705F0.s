.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800705F0
/* 4B9F0 800705F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B9F4 800705F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B9F8 800705F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B9FC 800705FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BA00 80070600 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BA04 80070604 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BA08 80070608 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BA0C 8007060C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BA10 80070610 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BA14 80070614 0C016885 */  jal       func_8005A214
/* 4BA18 80070618 24040024 */   addiu    $a0, $zero, 0x24
/* 4BA1C 8007061C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BA20 80070620 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BA24 80070624 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BA28 80070628 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BA2C 8007062C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BA30 80070630 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BA34 80070634 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BA38 80070638 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BA3C 8007063C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BA40 80070640 3C018008 */  lui       $at, %hi(D_8007F540)
/* 4BA44 80070644 8C21F540 */  lw        $at, %lo(D_8007F540)($at)
/* 4BA48 80070648 00200008 */  jr        $at
/* 4BA4C 8007064C 00000000 */   nop
