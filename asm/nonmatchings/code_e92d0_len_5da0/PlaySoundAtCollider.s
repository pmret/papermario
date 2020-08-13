.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlaySoundAtCollider
/* 0EEFC4 802CA614 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EEFC8 802CA618 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0EEFCC 802CA61C 0080882D */  daddu $s1, $a0, $zero
/* 0EEFD0 802CA620 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0EEFD4 802CA624 AFB20030 */  sw    $s2, 0x30($sp)
/* 0EEFD8 802CA628 AFB00028 */  sw    $s0, 0x28($sp)
/* 0EEFDC 802CA62C 8E30000C */  lw    $s0, 0xc($s1)
/* 0EEFE0 802CA630 8E050000 */  lw    $a1, ($s0)
/* 0EEFE4 802CA634 0C0B1EAF */  jal   get_variable
/* 0EEFE8 802CA638 26100004 */   addiu $s0, $s0, 4
/* 0EEFEC 802CA63C 8E050000 */  lw    $a1, ($s0)
/* 0EEFF0 802CA640 26100004 */  addiu $s0, $s0, 4
/* 0EEFF4 802CA644 0220202D */  daddu $a0, $s1, $zero
/* 0EEFF8 802CA648 0C0B1EAF */  jal   get_variable
/* 0EEFFC 802CA64C 0040902D */   daddu $s2, $v0, $zero
/* 0EF000 802CA650 0220202D */  daddu $a0, $s1, $zero
/* 0EF004 802CA654 8E050000 */  lw    $a1, ($s0)
/* 0EF008 802CA658 0C0B1EAF */  jal   get_variable
/* 0EF00C 802CA65C 0040802D */   daddu $s0, $v0, $zero
/* 0EF010 802CA660 0240202D */  daddu $a0, $s2, $zero
/* 0EF014 802CA664 27A50018 */  addiu $a1, $sp, 0x18
/* 0EF018 802CA668 27A6001C */  addiu $a2, $sp, 0x1c
/* 0EF01C 802CA66C 27A70020 */  addiu $a3, $sp, 0x20
/* 0EF020 802CA670 0C016F84 */  jal   get_collider_center
/* 0EF024 802CA674 0040882D */   daddu $s1, $v0, $zero
/* 0EF028 802CA678 0200202D */  daddu $a0, $s0, $zero
/* 0EF02C 802CA67C C7A00018 */  lwc1  $f0, 0x18($sp)
/* 0EF030 802CA680 C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 0EF034 802CA684 44060000 */  mfc1  $a2, $f0
/* 0EF038 802CA688 44071000 */  mfc1  $a3, $f2
/* 0EF03C 802CA68C C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0EF040 802CA690 0220282D */  daddu $a1, $s1, $zero
/* 0EF044 802CA694 0C052757 */  jal   play_sound_at_position
/* 0EF048 802CA698 E7A00010 */   swc1  $f0, 0x10($sp)
/* 0EF04C 802CA69C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0EF050 802CA6A0 8FB20030 */  lw    $s2, 0x30($sp)
/* 0EF054 802CA6A4 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0EF058 802CA6A8 8FB00028 */  lw    $s0, 0x28($sp)
/* 0EF05C 802CA6AC 24020002 */  addiu $v0, $zero, 2
/* 0EF060 802CA6B0 03E00008 */  jr    $ra
/* 0EF064 802CA6B4 27BD0038 */   addiu $sp, $sp, 0x38

/* 0EF068 802CA6B8 00000000 */  nop   
/* 0EF06C 802CA6BC 00000000 */  nop   


