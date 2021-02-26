.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800713D0
/* 4C7D0 800713D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C7D4 800713D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C7D8 800713D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C7DC 800713DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C7E0 800713E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C7E4 800713E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C7E8 800713E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C7EC 800713EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C7F0 800713F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C7F4 800713F4 0C016885 */  jal       func_8005A214
/* 4C7F8 800713F8 24040049 */   addiu    $a0, $zero, 0x49
/* 4C7FC 800713FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C800 80071400 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C804 80071404 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C808 80071408 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C80C 8007140C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C810 80071410 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C814 80071414 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C818 80071418 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C81C 8007141C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C820 80071420 3C018008 */  lui       $at, %hi(D_8007F8B8)
/* 4C824 80071424 8C21F8B8 */  lw        $at, %lo(D_8007F8B8)($at)
/* 4C828 80071428 00200008 */  jr        $at
/* 4C82C 8007142C 00000000 */   nop
