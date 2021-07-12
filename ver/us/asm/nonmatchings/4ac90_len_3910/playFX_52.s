.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_52
/* 4CB50 80071750 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CB54 80071754 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CB58 80071758 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CB5C 8007175C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CB60 80071760 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CB64 80071764 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CB68 80071768 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CB6C 8007176C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CB70 80071770 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CB74 80071774 0C016959 */  jal       load_effect
/* 4CB78 80071778 24040052 */   addiu    $a0, $zero, 0x52
/* 4CB7C 8007177C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CB80 80071780 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CB84 80071784 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CB88 80071788 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CB8C 8007178C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CB90 80071790 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CB94 80071794 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CB98 80071798 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CB9C 8007179C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CBA0 800717A0 3C018008 */  lui       $at, %hi(gEffectTable+0x7B0)
/* 4CBA4 800717A4 8C21F9C0 */  lw        $at, %lo(gEffectTable+0x7B0)($at)
/* 4CBA8 800717A8 00200008 */  jr        $at
/* 4CBAC 800717AC 00000000 */   nop
