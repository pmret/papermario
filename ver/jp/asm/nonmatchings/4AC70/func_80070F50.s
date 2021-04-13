.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070F50
/* 4C350 80070F50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C354 80070F54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C358 80070F58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C35C 80070F5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C360 80070F60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C364 80070F64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C368 80070F68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C36C 80070F6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C370 80070F70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C374 80070F74 0C016885 */  jal       func_8005A214
/* 4C378 80070F78 2404003D */   addiu    $a0, $zero, 0x3d
/* 4C37C 80070F7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C380 80070F80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C384 80070F84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C388 80070F88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C38C 80070F8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C390 80070F90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C394 80070F94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C398 80070F98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C39C 80070F9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C3A0 80070FA0 3C018008 */  lui       $at, %hi(D_8007F798)
/* 4C3A4 80070FA4 8C21F798 */  lw        $at, %lo(D_8007F798)($at)
/* 4C3A8 80070FA8 00200008 */  jr        $at
/* 4C3AC 80070FAC 00000000 */   nop
