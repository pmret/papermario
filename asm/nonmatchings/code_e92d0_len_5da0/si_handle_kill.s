.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_kill
/* 0EB220 802C6870 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB224 802C6874 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB228 802C6878 8C82000C */  lw    $v0, 0xc($a0)
/* 0EB22C 802C687C 0C0B1EAF */  jal   get_variable
/* 0EB230 802C6880 8C450000 */   lw    $a1, ($v0)
/* 0EB234 802C6884 0C0B102B */  jal   kill_script_by_ID
/* 0EB238 802C6888 0040202D */   daddu $a0, $v0, $zero
/* 0EB23C 802C688C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB240 802C6890 24020002 */  addiu $v0, $zero, 2
/* 0EB244 802C6894 03E00008 */  jr    $ra
/* 0EB248 802C6898 27BD0018 */   addiu $sp, $sp, 0x18

