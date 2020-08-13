.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_jump
/* 0EAFF0 802C6640 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EAFF4 802C6644 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAFF8 802C6648 0080802D */  daddu $s0, $a0, $zero
/* 0EAFFC 802C664C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB000 802C6650 8E02000C */  lw    $v0, 0xc($s0)
/* 0EB004 802C6654 0C0B1EAF */  jal   get_variable
/* 0EB008 802C6658 8C450000 */   lw    $a1, ($v0)
/* 0EB00C 802C665C 0200202D */  daddu $a0, $s0, $zero
/* 0EB010 802C6660 0C0B0F41 */  jal   restart_script
/* 0EB014 802C6664 AC82015C */   sw    $v0, 0x15c($a0)
/* 0EB018 802C6668 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB01C 802C666C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB020 802C6670 24020002 */  addiu $v0, $zero, 2
/* 0EB024 802C6674 03E00008 */  jr    $ra
/* 0EB028 802C6678 27BD0018 */   addiu $sp, $sp, 0x18

