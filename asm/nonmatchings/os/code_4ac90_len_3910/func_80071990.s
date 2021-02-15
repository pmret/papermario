.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071990
/* 4CD90 80071990 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CD94 80071994 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CD98 80071998 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CD9C 8007199C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CDA0 800719A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CDA4 800719A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CDA8 800719A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CDAC 800719AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CDB0 800719B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CDB4 800719B4 0C016959 */  jal       load_effect
/* 4CDB8 800719B8 24040058 */   addiu    $a0, $zero, 0x58
/* 4CDBC 800719BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CDC0 800719C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CDC4 800719C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CDC8 800719C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CDCC 800719CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CDD0 800719D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CDD4 800719D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CDD8 800719D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CDDC 800719DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CDE0 800719E0 3C018008 */  lui       $at, %hi(D_8007FA50)
/* 4CDE4 800719E4 8C21FA50 */  lw        $at, %lo(D_8007FA50)($at)
/* 4CDE8 800719E8 00200008 */  jr        $at
/* 4CDEC 800719EC 00000000 */   nop
