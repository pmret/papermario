.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FD70
/* 4B170 8006FD70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B174 8006FD74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B178 8006FD78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B17C 8006FD7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B180 8006FD80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B184 8006FD84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B188 8006FD88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B18C 8006FD8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B190 8006FD90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B194 8006FD94 0C016959 */  jal       play_effect
/* 4B198 8006FD98 2404000D */   addiu    $a0, $zero, 0xd
/* 4B19C 8006FD9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B1A0 8006FDA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B1A4 8006FDA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B1A8 8006FDA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B1AC 8006FDAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B1B0 8006FDB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B1B4 8006FDB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B1B8 8006FDB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B1BC 8006FDBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B1C0 8006FDC0 3C018008 */  lui       $at, %hi(D_8007F348)
/* 4B1C4 8006FDC4 8C21F348 */  lw        $at, %lo(D_8007F348)($at)
/* 4B1C8 8006FDC8 00200008 */  jr        $at
/* 4B1CC 8006FDCC 00000000 */   nop
