.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_timescale
/* 0EB288 802C68D8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB28C 802C68DC AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB290 802C68E0 0080802D */  daddu $s0, $a0, $zero
/* 0EB294 802C68E4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB298 802C68E8 8E02000C */  lw    $v0, 0xc($s0)
/* 0EB29C 802C68EC 0C0B210B */  jal   get_float_variable
/* 0EB2A0 802C68F0 8C450000 */   lw    $a1, ($v0)
/* 0EB2A4 802C68F4 44050000 */  mfc1  $a1, $f0
/* 0EB2A8 802C68F8 0C0B1078 */  jal   set_script_timescale
/* 0EB2AC 802C68FC 0200202D */   daddu $a0, $s0, $zero
/* 0EB2B0 802C6900 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB2B4 802C6904 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB2B8 802C6908 24020002 */  addiu $v0, $zero, 2
/* 0EB2BC 802C690C 03E00008 */  jr    $ra
/* 0EB2C0 802C6910 27BD0018 */   addiu $sp, $sp, 0x18

