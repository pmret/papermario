.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_float
/* 0EA168 802C57B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA16C 802C57BC AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA170 802C57C0 0080802D */  daddu $s0, $a0, $zero
/* 0EA174 802C57C4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA178 802C57C8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA17C 802C57CC 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA180 802C57D0 8C450004 */  lw    $a1, 4($v0)
/* 0EA184 802C57D4 0C0B210B */  jal   get_float_variable
/* 0EA188 802C57D8 8C510000 */   lw    $s1, ($v0)
/* 0EA18C 802C57DC 0200202D */  daddu $a0, $s0, $zero
/* 0EA190 802C57E0 44060000 */  mfc1  $a2, $f0
/* 0EA194 802C57E4 0C0B2190 */  jal   set_float_variable
/* 0EA198 802C57E8 0220282D */   daddu $a1, $s1, $zero
/* 0EA19C 802C57EC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA1A0 802C57F0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA1A4 802C57F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA1A8 802C57F8 24020002 */  addiu $v0, $zero, 2
/* 0EA1AC 802C57FC 03E00008 */  jr    $ra
/* 0EA1B0 802C5800 27BD0020 */   addiu $sp, $sp, 0x20

