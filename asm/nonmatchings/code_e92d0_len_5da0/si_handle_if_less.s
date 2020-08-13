.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_if_less
/* 0E96B0 802C4D00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E96B4 802C4D04 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E96B8 802C4D08 0080882D */  daddu $s1, $a0, $zero
/* 0E96BC 802C4D0C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E96C0 802C4D10 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E96C4 802C4D14 8E30000C */  lw    $s0, 0xc($s1)
/* 0E96C8 802C4D18 8E050000 */  lw    $a1, ($s0)
/* 0E96CC 802C4D1C 0C0B1EAF */  jal   get_variable
/* 0E96D0 802C4D20 26100004 */   addiu $s0, $s0, 4
/* 0E96D4 802C4D24 0220202D */  daddu $a0, $s1, $zero
/* 0E96D8 802C4D28 8E050000 */  lw    $a1, ($s0)
/* 0E96DC 802C4D2C 0C0B1EAF */  jal   get_variable
/* 0E96E0 802C4D30 0040802D */   daddu $s0, $v0, $zero
/* 0E96E4 802C4D34 0202802A */  slt   $s0, $s0, $v0
/* 0E96E8 802C4D38 16000005 */  bnez  $s0, .L802C4D50
/* 0E96EC 802C4D3C 24020002 */   addiu $v0, $zero, 2
/* 0E96F0 802C4D40 0C0B223F */  jal   si_skip_if
/* 0E96F4 802C4D44 0220202D */   daddu $a0, $s1, $zero
/* 0E96F8 802C4D48 AE220008 */  sw    $v0, 8($s1)
/* 0E96FC 802C4D4C 24020002 */  addiu $v0, $zero, 2
.L802C4D50:
/* 0E9700 802C4D50 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9704 802C4D54 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9708 802C4D58 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E970C 802C4D5C 03E00008 */  jr    $ra
/* 0E9710 802C4D60 27BD0020 */   addiu $sp, $sp, 0x20

