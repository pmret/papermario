.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071F70
/* 4D370 80071F70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D374 80071F74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D378 80071F78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D37C 80071F7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D380 80071F80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D384 80071F84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D388 80071F88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D38C 80071F8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D390 80071F90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D394 80071F94 0C016885 */  jal       func_8005A214
/* 4D398 80071F98 24040068 */   addiu    $a0, $zero, 0x68
/* 4D39C 80071F9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D3A0 80071FA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D3A4 80071FA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D3A8 80071FA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D3AC 80071FAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D3B0 80071FB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D3B4 80071FB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D3B8 80071FB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D3BC 80071FBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D3C0 80071FC0 3C018008 */  lui       $at, %hi(D_8007FBA0)
/* 4D3C4 80071FC4 8C21FBA0 */  lw        $at, %lo(D_8007FBA0)($at)
/* 4D3C8 80071FC8 00200008 */  jr        $at
/* 4D3CC 80071FCC 00000000 */   nop
