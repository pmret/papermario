.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C9C_8EDABC
/* 8EDABC 80241C9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDAC0 80241CA0 2404010D */  addiu     $a0, $zero, 0x10d
/* 8EDAC4 80241CA4 2405FFFF */  addiu     $a1, $zero, -1
/* 8EDAC8 80241CA8 24060001 */  addiu     $a2, $zero, 1
/* 8EDACC 80241CAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EDAD0 80241CB0 0C046E54 */  jal       func_8011B950
/* 8EDAD4 80241CB4 00C0382D */   daddu    $a3, $a2, $zero
/* 8EDAD8 80241CB8 0000202D */  daddu     $a0, $zero, $zero
/* 8EDADC 80241CBC 0080282D */  daddu     $a1, $a0, $zero
/* 8EDAE0 80241CC0 0080302D */  daddu     $a2, $a0, $zero
/* 8EDAE4 80241CC4 0C046F97 */  jal       set_background_color_blend
/* 8EDAE8 80241CC8 240700FF */   addiu    $a3, $zero, 0xff
/* 8EDAEC 80241CCC 3C02800B */  lui       $v0, %hi(gCameras)
/* 8EDAF0 80241CD0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 8EDAF4 80241CD4 A440002C */  sh        $zero, 0x2c($v0)
/* 8EDAF8 80241CD8 A440002E */  sh        $zero, 0x2e($v0)
/* 8EDAFC 80241CDC A4400030 */  sh        $zero, 0x30($v0)
/* 8EDB00 80241CE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDB04 80241CE4 24020002 */  addiu     $v0, $zero, 2
/* 8EDB08 80241CE8 03E00008 */  jr        $ra
/* 8EDB0C 80241CEC 27BD0018 */   addiu    $sp, $sp, 0x18
