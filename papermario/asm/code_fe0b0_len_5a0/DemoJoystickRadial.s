.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "globals.inc"

DemoJoystickRadial:
/* 0FE514 802D9B64 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0FE518 802D9B68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FE51C 802D9B6C 0080882D */  daddu $s1, $a0, $zero
/* 0FE520 802D9B70 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FE524 802D9B74 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FE528 802D9B78 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0FE52C 802D9B7C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0FE530 802D9B80 8E30000C */  lw    $s0, 0xc($s1)
/* 0FE534 802D9B84 8E050000 */  lw    $a1, ($s0)
/* 0FE538 802D9B88 0C0B210B */  jal   get_float_variable
/* 0FE53C 802D9B8C 26100004 */   addiu $s0, $s0, 4
/* 0FE540 802D9B90 0220202D */  daddu $a0, $s1, $zero
/* 0FE544 802D9B94 8E050000 */  lw    $a1, ($s0)
/* 0FE548 802D9B98 0C0B210B */  jal   get_float_variable
/* 0FE54C 802D9B9C 46000586 */   mov.s $f22, $f0
/* 0FE550 802D9BA0 46000506 */  mov.s $f20, $f0
/* 0FE554 802D9BA4 0C00A8BB */  jal   sin_deg
/* 0FE558 802D9BA8 4600A306 */   mov.s $f12, $f20
/* 0FE55C 802D9BAC 4600B002 */  mul.s $f0, $f22, $f0
/* 0FE560 802D9BB0 00000000 */  nop   
/* 0FE564 802D9BB4 4600A306 */  mov.s $f12, $f20
/* 0FE568 802D9BB8 3C108007 */  lui   $s0, 0x8007
/* 0FE56C 802D9BBC 2610419C */  addiu $s0, $s0, 0x419c
/* 0FE570 802D9BC0 8E030000 */  lw    $v1, ($s0)
/* 0FE574 802D9BC4 4600008D */  trunc.w.s $f2, $f0
/* 0FE578 802D9BC8 44021000 */  mfc1  $v0, $f2
/* 0FE57C 802D9BCC 0C00A8D4 */  jal   cos_deg
/* 0FE580 802D9BD0 A062006A */   sb    $v0, 0x6a($v1)
/* 0FE584 802D9BD4 4600B582 */  mul.s $f22, $f22, $f0
/* 0FE588 802D9BD8 00000000 */  nop   
/* 0FE58C 802D9BDC 8E030000 */  lw    $v1, ($s0)
/* 0FE590 802D9BE0 4600B08D */  trunc.w.s $f2, $f22
/* 0FE594 802D9BE4 44021000 */  mfc1  $v0, $f2
/* 0FE598 802D9BE8 00000000 */  nop   
/* 0FE59C 802D9BEC A062006B */  sb    $v0, 0x6b($v1)
/* 0FE5A0 802D9BF0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FE5A4 802D9BF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FE5A8 802D9BF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FE5AC 802D9BFC D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0FE5B0 802D9C00 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0FE5B4 802D9C04 24020002 */  addiu $v0, $zero, 2
/* 0FE5B8 802D9C08 03E00008 */  jr    $ra
/* 0FE5BC 802D9C0C 27BD0030 */   addiu $sp, $sp, 0x30

.set reorder
