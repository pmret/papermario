.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070610
/* 4BA10 80070610 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BA14 80070614 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BA18 80070618 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BA1C 8007061C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BA20 80070620 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BA24 80070624 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BA28 80070628 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BA2C 8007062C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BA30 80070630 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BA34 80070634 0C016959 */  jal       load_effect
/* 4BA38 80070638 24040024 */   addiu    $a0, $zero, 0x24
/* 4BA3C 8007063C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BA40 80070640 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BA44 80070644 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BA48 80070648 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BA4C 8007064C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BA50 80070650 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BA54 80070654 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BA58 80070658 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BA5C 8007065C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BA60 80070660 3C018008 */  lui       $at, %hi(gEffectTable+0x360)
/* 4BA64 80070664 8C21F570 */  lw        $at, %lo(gEffectTable+0x360)($at)
/* 4BA68 80070668 00200008 */  jr        $at
/* 4BA6C 8007066C 00000000 */   nop
