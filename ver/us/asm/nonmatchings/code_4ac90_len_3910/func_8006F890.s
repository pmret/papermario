.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F890
/* 4AC90 8006F890 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AC94 8006F894 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AC98 8006F898 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AC9C 8006F89C AFA60018 */  sw        $a2, 0x18($sp)
/* 4ACA0 8006F8A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4ACA4 8006F8A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4ACA8 8006F8A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4ACAC 8006F8AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4ACB0 8006F8B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4ACB4 8006F8B4 0C016959 */  jal       load_effect
/* 4ACB8 8006F8B8 24040000 */   addiu    $a0, $zero, 0
/* 4ACBC 8006F8BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4ACC0 8006F8C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4ACC4 8006F8C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4ACC8 8006F8C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4ACCC 8006F8CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4ACD0 8006F8D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4ACD4 8006F8D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4ACD8 8006F8D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4ACDC 8006F8DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4ACE0 8006F8E0 3C018008 */  lui       $at, %hi(gEffectTable)
/* 4ACE4 8006F8E4 8C21F210 */  lw        $at, %lo(gEffectTable)($at)
/* 4ACE8 8006F8E8 00200008 */  jr        $at
/* 4ACEC 8006F8EC 00000000 */   nop
