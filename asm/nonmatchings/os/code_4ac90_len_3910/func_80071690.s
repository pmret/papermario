.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071690
/* 4CA90 80071690 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CA94 80071694 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CA98 80071698 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CA9C 8007169C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CAA0 800716A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CAA4 800716A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CAA8 800716A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CAAC 800716AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CAB0 800716B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CAB4 800716B4 0C016959 */  jal       play_effect
/* 4CAB8 800716B8 24040050 */   addiu    $a0, $zero, 0x50
/* 4CABC 800716BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CAC0 800716C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CAC4 800716C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CAC8 800716C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CACC 800716CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CAD0 800716D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CAD4 800716D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CAD8 800716D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CADC 800716DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CAE0 800716E0 3C018008 */  lui       $at, 0x8008
/* 4CAE4 800716E4 8C21F990 */  lw        $at, -0x670($at)
/* 4CAE8 800716E8 00200008 */  jr        $at
/* 4CAEC 800716EC 00000000 */   nop      
