.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F28_8B2F98
/* 8B2F98 80242F28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2F9C 80242F2C 2404009C */  addiu     $a0, $zero, 0x9c
/* 8B2FA0 80242F30 2405FFFF */  addiu     $a1, $zero, -1
/* 8B2FA4 80242F34 24060001 */  addiu     $a2, $zero, 1
/* 8B2FA8 80242F38 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B2FAC 80242F3C 0C046E54 */  jal       func_8011B950
/* 8B2FB0 80242F40 00C0382D */   daddu    $a3, $a2, $zero
/* 8B2FB4 80242F44 0000202D */  daddu     $a0, $zero, $zero
/* 8B2FB8 80242F48 0080282D */  daddu     $a1, $a0, $zero
/* 8B2FBC 80242F4C 0080302D */  daddu     $a2, $a0, $zero
/* 8B2FC0 80242F50 0C046F97 */  jal       set_background_color_blend
/* 8B2FC4 80242F54 240700FF */   addiu    $a3, $zero, 0xff
/* 8B2FC8 80242F58 3C02800B */  lui       $v0, %hi(gCameras)
/* 8B2FCC 80242F5C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 8B2FD0 80242F60 A440002C */  sh        $zero, 0x2c($v0)
/* 8B2FD4 80242F64 A440002E */  sh        $zero, 0x2e($v0)
/* 8B2FD8 80242F68 A4400030 */  sh        $zero, 0x30($v0)
/* 8B2FDC 80242F6C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2FE0 80242F70 24020002 */  addiu     $v0, $zero, 2
/* 8B2FE4 80242F74 03E00008 */  jr        $ra
/* 8B2FE8 80242F78 27BD0018 */   addiu    $sp, $sp, 0x18
