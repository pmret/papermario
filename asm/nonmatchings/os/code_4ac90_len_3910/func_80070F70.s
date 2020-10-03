.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070F70
/* 4C370 80070F70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C374 80070F74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C378 80070F78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C37C 80070F7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C380 80070F80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C384 80070F84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C388 80070F88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C38C 80070F8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C390 80070F90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C394 80070F94 0C016959 */  jal       play_effect
/* 4C398 80070F98 2404003D */   addiu    $a0, $zero, 0x3d
/* 4C39C 80070F9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C3A0 80070FA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C3A4 80070FA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C3A8 80070FA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C3AC 80070FAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C3B0 80070FB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C3B4 80070FB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C3B8 80070FB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C3BC 80070FBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C3C0 80070FC0 3C018008 */  lui       $at, 0x8008
/* 4C3C4 80070FC4 8C21F7C8 */  lw        $at, -0x838($at)
/* 4C3C8 80070FC8 00200008 */  jr        $at
/* 4C3CC 80070FCC 00000000 */   nop      
