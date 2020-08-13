.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CheckButtonPress
/* 19C978 8026E098 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19C97C 8026E09C AFBF0010 */  sw    $ra, 0x10($sp)
/* 19C980 8026E0A0 8C82000C */  lw    $v0, 0xc($a0)
/* 19C984 8026E0A4 3C06800E */  lui   $a2, 0x800e
/* 19C988 8026E0A8 8CC6C284 */  lw    $a2, -0x3d7c($a2)
/* 19C98C 8026E0AC 8C430000 */  lw    $v1, ($v0)
/* 19C990 8026E0B0 8C450004 */  lw    $a1, 4($v0)
/* 19C994 8026E0B4 00C33024 */  and   $a2, $a2, $v1
/* 19C998 8026E0B8 0C0B2026 */  jal   set_variable
/* 19C99C 8026E0BC 0006302B */   sltu  $a2, $zero, $a2
/* 19C9A0 8026E0C0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19C9A4 8026E0C4 24020002 */  addiu $v0, $zero, 2
/* 19C9A8 8026E0C8 03E00008 */  jr    $ra
/* 19C9AC 8026E0CC 27BD0018 */   addiu $sp, $sp, 0x18

