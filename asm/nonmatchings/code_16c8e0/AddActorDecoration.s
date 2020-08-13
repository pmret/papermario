.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddActorDecoration
/* 19D768 8026EE88 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D76C 8026EE8C AFB20018 */  sw    $s2, 0x18($sp)
/* 19D770 8026EE90 0080902D */  daddu $s2, $a0, $zero
/* 19D774 8026EE94 AFBF0024 */  sw    $ra, 0x24($sp)
/* 19D778 8026EE98 AFB40020 */  sw    $s4, 0x20($sp)
/* 19D77C 8026EE9C AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D780 8026EEA0 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D784 8026EEA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D788 8026EEA8 8E50000C */  lw    $s0, 0xc($s2)
/* 19D78C 8026EEAC 8E050000 */  lw    $a1, ($s0)
/* 19D790 8026EEB0 0C0B1EAF */  jal   get_variable
/* 19D794 8026EEB4 26100004 */   addiu $s0, $s0, 4
/* 19D798 8026EEB8 0040882D */  daddu $s1, $v0, $zero
/* 19D79C 8026EEBC 8E050000 */  lw    $a1, ($s0)
/* 19D7A0 8026EEC0 26100004 */  addiu $s0, $s0, 4
/* 19D7A4 8026EEC4 0C0B1EAF */  jal   get_variable
/* 19D7A8 8026EEC8 0240202D */   daddu $a0, $s2, $zero
/* 19D7AC 8026EECC 8E050000 */  lw    $a1, ($s0)
/* 19D7B0 8026EED0 26100004 */  addiu $s0, $s0, 4
/* 19D7B4 8026EED4 0240202D */  daddu $a0, $s2, $zero
/* 19D7B8 8026EED8 0C0B1EAF */  jal   get_variable
/* 19D7BC 8026EEDC 0040A02D */   daddu $s4, $v0, $zero
/* 19D7C0 8026EEE0 0240202D */  daddu $a0, $s2, $zero
/* 19D7C4 8026EEE4 8E050000 */  lw    $a1, ($s0)
/* 19D7C8 8026EEE8 0C0B1EAF */  jal   get_variable
/* 19D7CC 8026EEEC 0040982D */   daddu $s3, $v0, $zero
/* 19D7D0 8026EEF0 0040802D */  daddu $s0, $v0, $zero
/* 19D7D4 8026EEF4 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D7D8 8026EEF8 16220002 */  bne   $s1, $v0, .L8026EF04
/* 19D7DC 8026EEFC 00000000 */   nop   
/* 19D7E0 8026EF00 8E510148 */  lw    $s1, 0x148($s2)
.L8026EF04:
/* 19D7E4 8026EF04 0C09A75B */  jal   get_actor
/* 19D7E8 8026EF08 0220202D */   daddu $a0, $s1, $zero
/* 19D7EC 8026EF0C 0040202D */  daddu $a0, $v0, $zero
/* 19D7F0 8026EF10 0C099117 */  jal   get_actor_part
/* 19D7F4 8026EF14 0280282D */   daddu $a1, $s4, $zero
/* 19D7F8 8026EF18 0040202D */  daddu $a0, $v0, $zero
/* 19D7FC 8026EF1C 0260282D */  daddu $a1, $s3, $zero
/* 19D800 8026EF20 0C099C45 */  jal   add_part_decoration
/* 19D804 8026EF24 0200302D */   daddu $a2, $s0, $zero
/* 19D808 8026EF28 8FBF0024 */  lw    $ra, 0x24($sp)
/* 19D80C 8026EF2C 8FB40020 */  lw    $s4, 0x20($sp)
/* 19D810 8026EF30 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D814 8026EF34 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D818 8026EF38 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D81C 8026EF3C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D820 8026EF40 24020002 */  addiu $v0, $zero, 2
/* 19D824 8026EF44 03E00008 */  jr    $ra
/* 19D828 8026EF48 27BD0028 */   addiu $sp, $sp, 0x28

