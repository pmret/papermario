.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071970
/* 4CD70 80071970 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CD74 80071974 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CD78 80071978 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CD7C 8007197C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CD80 80071980 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CD84 80071984 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CD88 80071988 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CD8C 8007198C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CD90 80071990 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CD94 80071994 0C016885 */  jal       func_8005A214
/* 4CD98 80071998 24040058 */   addiu    $a0, $zero, 0x58
/* 4CD9C 8007199C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CDA0 800719A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CDA4 800719A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CDA8 800719A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CDAC 800719AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CDB0 800719B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CDB4 800719B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CDB8 800719B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CDBC 800719BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CDC0 800719C0 3C018008 */  lui       $at, %hi(D_8007FA20)
/* 4CDC4 800719C4 8C21FA20 */  lw        $at, %lo(D_8007FA20)($at)
/* 4CDC8 800719C8 00200008 */  jr        $at
/* 4CDCC 800719CC 00000000 */   nop
