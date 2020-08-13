.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_flag_array
/* 0EAB90 802C61E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EAB94 802C61E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAB98 802C61E8 0080802D */  daddu $s0, $a0, $zero
/* 0EAB9C 802C61EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EABA0 802C61F0 8E02000C */  lw    $v0, 0xc($s0)
/* 0EABA4 802C61F4 0C0B1EAF */  jal   get_variable
/* 0EABA8 802C61F8 8C450000 */   lw    $a1, ($v0)
/* 0EABAC 802C61FC AE020140 */  sw    $v0, 0x140($s0)
/* 0EABB0 802C6200 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EABB4 802C6204 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EABB8 802C6208 24020002 */  addiu $v0, $zero, 2
/* 0EABBC 802C620C 03E00008 */  jr    $ra
/* 0EABC0 802C6210 27BD0018 */   addiu $sp, $sp, 0x18

