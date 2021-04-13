.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_sweat
/* 4BB90 80070790 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BB94 80070794 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BB98 80070798 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BB9C 8007079C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BBA0 800707A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BBA4 800707A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BBA8 800707A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BBAC 800707AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BBB0 800707B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BBB4 800707B4 0C016959 */  jal       load_effect
/* 4BBB8 800707B8 24040028 */   addiu    $a0, $zero, 0x28
/* 4BBBC 800707BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BBC0 800707C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BBC4 800707C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BBC8 800707C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BBCC 800707CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BBD0 800707D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BBD4 800707D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BBD8 800707D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BBDC 800707DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BBE0 800707E0 3C018008 */  lui       $at, %hi(gEffectTable+0x3C0)
/* 4BBE4 800707E4 8C21F5D0 */  lw        $at, %lo(gEffectTable+0x3C0)($at)
/* 4BBE8 800707E8 00200008 */  jr        $at
/* 4BBEC 800707EC 00000000 */   nop
