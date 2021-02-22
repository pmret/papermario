.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072570
/* 4D970 80072570 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D974 80072574 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D978 80072578 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D97C 8007257C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D980 80072580 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D984 80072584 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D988 80072588 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D98C 8007258C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D990 80072590 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D994 80072594 0C016885 */  jal       func_8005A214
/* 4D998 80072598 24040078 */   addiu    $a0, $zero, 0x78
/* 4D99C 8007259C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D9A0 800725A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D9A4 800725A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D9A8 800725A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D9AC 800725AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D9B0 800725B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D9B4 800725B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D9B8 800725B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D9BC 800725BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D9C0 800725C0 3C018008 */  lui       $at, %hi(D_8007FD20)
/* 4D9C4 800725C4 8C21FD20 */  lw        $at, %lo(D_8007FD20)($at)
/* 4D9C8 800725C8 00200008 */  jr        $at
/* 4D9CC 800725CC 00000000 */   nop
