.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_group
/* 0EB2C4 802C6914 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB2C8 802C6918 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB2CC 802C691C 0080802D */  daddu $s0, $a0, $zero
/* 0EB2D0 802C6920 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB2D4 802C6924 8E02000C */  lw    $v0, 0xc($s0)
/* 0EB2D8 802C6928 0C0B1EAF */  jal   get_variable
/* 0EB2DC 802C692C 8C450000 */   lw    $a1, ($v0)
/* 0EB2E0 802C6930 0200202D */  daddu $a0, $s0, $zero
/* 0EB2E4 802C6934 0C0B1086 */  jal   set_script_group
/* 0EB2E8 802C6938 0040282D */   daddu $a1, $v0, $zero
/* 0EB2EC 802C693C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB2F0 802C6940 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB2F4 802C6944 24020002 */  addiu $v0, $zero, 2
/* 0EB2F8 802C6948 03E00008 */  jr    $ra
/* 0EB2FC 802C694C 27BD0018 */   addiu $sp, $sp, 0x18

