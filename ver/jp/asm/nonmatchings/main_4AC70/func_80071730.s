.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071730
/* 4CB30 80071730 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CB34 80071734 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CB38 80071738 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CB3C 8007173C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CB40 80071740 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CB44 80071744 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CB48 80071748 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CB4C 8007174C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CB50 80071750 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CB54 80071754 0C016885 */  jal       func_8005A214
/* 4CB58 80071758 24040052 */   addiu    $a0, $zero, 0x52
/* 4CB5C 8007175C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CB60 80071760 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CB64 80071764 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CB68 80071768 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CB6C 8007176C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CB70 80071770 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CB74 80071774 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CB78 80071778 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CB7C 8007177C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CB80 80071780 3C018008 */  lui       $at, %hi(D_8007F990)
/* 4CB84 80071784 8C21F990 */  lw        $at, %lo(D_8007F990)($at)
/* 4CB88 80071788 00200008 */  jr        $at
/* 4CB8C 8007178C 00000000 */   nop
