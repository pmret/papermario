.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_suspend
/* 0EB3D0 802C6A20 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB3D4 802C6A24 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB3D8 802C6A28 8C82000C */  lw    $v0, 0xc($a0)
/* 0EB3DC 802C6A2C 0C0B1EAF */  jal   get_variable
/* 0EB3E0 802C6A30 8C450000 */   lw    $a1, ($v0)
/* 0EB3E4 802C6A34 0C0B1108 */  jal   suspend_all_script
/* 0EB3E8 802C6A38 0040202D */   daddu $a0, $v0, $zero
/* 0EB3EC 802C6A3C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB3F0 802C6A40 24020002 */  addiu $v0, $zero, 2
/* 0EB3F4 802C6A44 03E00008 */  jr    $ra
/* 0EB3F8 802C6A48 27BD0018 */   addiu $sp, $sp, 0x18

