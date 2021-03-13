.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070A30
/* 4BE30 80070A30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BE34 80070A34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BE38 80070A38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BE3C 80070A3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BE40 80070A40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BE44 80070A44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BE48 80070A48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BE4C 80070A4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BE50 80070A50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BE54 80070A54 0C016959 */  jal       load_effect
/* 4BE58 80070A58 2404002F */   addiu    $a0, $zero, 0x2f
/* 4BE5C 80070A5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BE60 80070A60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BE64 80070A64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BE68 80070A68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BE6C 80070A6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BE70 80070A70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BE74 80070A74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BE78 80070A78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BE7C 80070A7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BE80 80070A80 3C018008 */  lui       $at, %hi(gEffectTable+0x468)
/* 4BE84 80070A84 8C21F678 */  lw        $at, %lo(gEffectTable+0x468)($at)
/* 4BE88 80070A88 00200008 */  jr        $at
/* 4BE8C 80070A8C 00000000 */   nop
