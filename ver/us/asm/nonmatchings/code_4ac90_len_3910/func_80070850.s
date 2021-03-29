.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070850
/* 4BC50 80070850 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BC54 80070854 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BC58 80070858 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BC5C 8007085C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BC60 80070860 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BC64 80070864 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BC68 80070868 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BC6C 8007086C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BC70 80070870 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BC74 80070874 0C016959 */  jal       load_effect
/* 4BC78 80070878 2404002A */   addiu    $a0, $zero, 0x2a
/* 4BC7C 8007087C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BC80 80070880 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BC84 80070884 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BC88 80070888 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BC8C 8007088C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BC90 80070890 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BC94 80070894 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BC98 80070898 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BC9C 8007089C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BCA0 800708A0 3C018008 */  lui       $at, %hi(gEffectTable+0x3F0)
/* 4BCA4 800708A4 8C21F600 */  lw        $at, %lo(gEffectTable+0x3F0)($at)
/* 4BCA8 800708A8 00200008 */  jr        $at
/* 4BCAC 800708AC 00000000 */   nop
