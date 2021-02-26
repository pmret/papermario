.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071670
/* 4CA70 80071670 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CA74 80071674 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CA78 80071678 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CA7C 8007167C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CA80 80071680 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CA84 80071684 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CA88 80071688 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CA8C 8007168C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CA90 80071690 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CA94 80071694 0C016885 */  jal       func_8005A214
/* 4CA98 80071698 24040050 */   addiu    $a0, $zero, 0x50
/* 4CA9C 8007169C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CAA0 800716A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CAA4 800716A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CAA8 800716A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CAAC 800716AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CAB0 800716B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CAB4 800716B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CAB8 800716B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CABC 800716BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CAC0 800716C0 3C018008 */  lui       $at, %hi(D_8007F960)
/* 4CAC4 800716C4 8C21F960 */  lw        $at, %lo(D_8007F960)($at)
/* 4CAC8 800716C8 00200008 */  jr        $at
/* 4CACC 800716CC 00000000 */   nop
