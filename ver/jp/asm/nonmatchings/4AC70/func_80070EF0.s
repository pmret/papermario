.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070EF0
/* 4C2F0 80070EF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C2F4 80070EF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C2F8 80070EF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C2FC 80070EFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C300 80070F00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C304 80070F04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C308 80070F08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C30C 80070F0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C310 80070F10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C314 80070F14 0C016885 */  jal       func_8005A214
/* 4C318 80070F18 2404003C */   addiu    $a0, $zero, 0x3c
/* 4C31C 80070F1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C320 80070F20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C324 80070F24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C328 80070F28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C32C 80070F2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C330 80070F30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C334 80070F34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C338 80070F38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C33C 80070F3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C340 80070F40 3C018008 */  lui       $at, %hi(D_8007F780)
/* 4C344 80070F44 8C21F780 */  lw        $at, %lo(D_8007F780)($at)
/* 4C348 80070F48 00200008 */  jr        $at
/* 4C34C 80070F4C 00000000 */   nop
