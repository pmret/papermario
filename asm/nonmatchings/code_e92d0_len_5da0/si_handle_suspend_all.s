.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_suspend_all
/* 0EB300 802C6950 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB304 802C6954 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB308 802C6958 8C82000C */  lw    $v0, 0xc($a0)
/* 0EB30C 802C695C 0C0B1EAF */  jal   get_variable
/* 0EB310 802C6960 8C450000 */   lw    $a1, ($v0)
/* 0EB314 802C6964 0C0B117A */  jal   suspend_all_group
/* 0EB318 802C6968 0040202D */   daddu $a0, $v0, $zero
/* 0EB31C 802C696C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB320 802C6970 24020002 */  addiu $v0, $zero, 2
/* 0EB324 802C6974 03E00008 */  jr    $ra
/* 0EB328 802C6978 27BD0018 */   addiu $sp, $sp, 0x18

