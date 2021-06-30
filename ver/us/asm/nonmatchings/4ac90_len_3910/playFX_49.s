.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_49
/* 4C7F0 800713F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C7F4 800713F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C7F8 800713F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C7FC 800713FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C800 80071400 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C804 80071404 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C808 80071408 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C80C 8007140C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C810 80071410 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C814 80071414 0C016959 */  jal       load_effect
/* 4C818 80071418 24040049 */   addiu    $a0, $zero, 0x49
/* 4C81C 8007141C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C820 80071420 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C824 80071424 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C828 80071428 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C82C 8007142C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C830 80071430 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C834 80071434 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C838 80071438 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C83C 8007143C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C840 80071440 3C018008 */  lui       $at, %hi(gEffectTable+0x6D8)
/* 4C844 80071444 8C21F8E8 */  lw        $at, %lo(gEffectTable+0x6D8)($at)
/* 4C848 80071448 00200008 */  jr        $at
/* 4C84C 8007144C 00000000 */   nop
