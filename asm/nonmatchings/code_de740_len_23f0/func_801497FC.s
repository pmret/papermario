.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801497FC
/* 0DFEFC 801497FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DFF00 80149800 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DFF04 80149804 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DFF08 80149808 0C015879 */  jal   func_800561E4
/* 0DFF0C 8014980C 0080802D */   daddu $s0, $a0, $zero
/* 0DFF10 80149810 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DFF14 80149814 3C018016 */  lui   $at, 0x8016
/* 0DFF18 80149818 AC309AD4 */  sw    $s0, -0x652c($at)
/* 0DFF1C 8014981C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DFF20 80149820 03E00008 */  jr    $ra
/* 0DFF24 80149824 27BD0018 */   addiu $sp, $sp, 0x18

