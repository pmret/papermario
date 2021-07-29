.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071A30
/* 4CE30 80071A30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CE34 80071A34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CE38 80071A38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CE3C 80071A3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CE40 80071A40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CE44 80071A44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CE48 80071A48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CE4C 80071A4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CE50 80071A50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CE54 80071A54 0C016885 */  jal       func_8005A214
/* 4CE58 80071A58 2404005A */   addiu    $a0, $zero, 0x5a
/* 4CE5C 80071A5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CE60 80071A60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CE64 80071A64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CE68 80071A68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CE6C 80071A6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CE70 80071A70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CE74 80071A74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CE78 80071A78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CE7C 80071A7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CE80 80071A80 3C018008 */  lui       $at, %hi(D_8007FA50)
/* 4CE84 80071A84 8C21FA50 */  lw        $at, %lo(D_8007FA50)($at)
/* 4CE88 80071A88 00200008 */  jr        $at
/* 4CE8C 80071A8C 00000000 */   nop
