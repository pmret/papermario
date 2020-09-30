.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070F10
/* 4C310 80070F10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C314 80070F14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C318 80070F18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C31C 80070F1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C320 80070F20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C324 80070F24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C328 80070F28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C32C 80070F2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C330 80070F30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C334 80070F34 0C016959 */  jal       play_effect
/* 4C338 80070F38 2404003C */   addiu    $a0, $zero, 0x3c
/* 4C33C 80070F3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C340 80070F40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C344 80070F44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C348 80070F48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C34C 80070F4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C350 80070F50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C354 80070F54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C358 80070F58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C35C 80070F5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C360 80070F60 3C018008 */  lui       $at, 0x8008
/* 4C364 80070F64 8C21F7B0 */  lw        $at, -0x850($at)
/* 4C368 80070F68 00200008 */  jr        $at
/* 4C36C 80070F6C 00000000 */   nop      
