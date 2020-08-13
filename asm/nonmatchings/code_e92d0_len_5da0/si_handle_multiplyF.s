.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_multiplyF
/* 0EA504 802C5B54 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EA508 802C5B58 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA50C 802C5B5C 0080802D */  daddu $s0, $a0, $zero
/* 0EA510 802C5B60 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA514 802C5B64 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA518 802C5B68 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0EA51C 802C5B6C 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA520 802C5B70 8C450004 */  lw    $a1, 4($v0)
/* 0EA524 802C5B74 0C0B210B */  jal   get_float_variable
/* 0EA528 802C5B78 8C510000 */   lw    $s1, ($v0)
/* 0EA52C 802C5B7C 46000506 */  mov.s $f20, $f0
/* 0EA530 802C5B80 0200202D */  daddu $a0, $s0, $zero
/* 0EA534 802C5B84 0C0B210B */  jal   get_float_variable
/* 0EA538 802C5B88 0220282D */   daddu $a1, $s1, $zero
/* 0EA53C 802C5B8C 4600A502 */  mul.s $f20, $f20, $f0
/* 0EA540 802C5B90 00000000 */  nop   
/* 0EA544 802C5B94 0200202D */  daddu $a0, $s0, $zero
/* 0EA548 802C5B98 4406A000 */  mfc1  $a2, $f20
/* 0EA54C 802C5B9C 0C0B2190 */  jal   set_float_variable
/* 0EA550 802C5BA0 0220282D */   daddu $a1, $s1, $zero
/* 0EA554 802C5BA4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA558 802C5BA8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA55C 802C5BAC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA560 802C5BB0 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0EA564 802C5BB4 24020002 */  addiu $v0, $zero, 2
/* 0EA568 802C5BB8 03E00008 */  jr    $ra
/* 0EA56C 802C5BBC 27BD0028 */   addiu $sp, $sp, 0x28

