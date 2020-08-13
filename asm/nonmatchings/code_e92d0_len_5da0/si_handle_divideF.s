.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_divideF
/* 0EA570 802C5BC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EA574 802C5BC4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA578 802C5BC8 0080802D */  daddu $s0, $a0, $zero
/* 0EA57C 802C5BCC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA580 802C5BD0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA584 802C5BD4 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0EA588 802C5BD8 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA58C 802C5BDC 8C450004 */  lw    $a1, 4($v0)
/* 0EA590 802C5BE0 0C0B210B */  jal   get_float_variable
/* 0EA594 802C5BE4 8C510000 */   lw    $s1, ($v0)
/* 0EA598 802C5BE8 46000506 */  mov.s $f20, $f0
/* 0EA59C 802C5BEC 0200202D */  daddu $a0, $s0, $zero
/* 0EA5A0 802C5BF0 0C0B210B */  jal   get_float_variable
/* 0EA5A4 802C5BF4 0220282D */   daddu $a1, $s1, $zero
/* 0EA5A8 802C5BF8 0200202D */  daddu $a0, $s0, $zero
/* 0EA5AC 802C5BFC 46140003 */  div.s $f0, $f0, $f20
/* 0EA5B0 802C5C00 44060000 */  mfc1  $a2, $f0
/* 0EA5B4 802C5C04 0C0B2190 */  jal   set_float_variable
/* 0EA5B8 802C5C08 0220282D */   daddu $a1, $s1, $zero
/* 0EA5BC 802C5C0C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA5C0 802C5C10 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA5C4 802C5C14 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA5C8 802C5C18 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0EA5CC 802C5C1C 24020002 */  addiu $v0, $zero, 2
/* 0EA5D0 802C5C20 03E00008 */  jr    $ra
/* 0EA5D4 802C5C24 27BD0028 */   addiu $sp, $sp, 0x28

