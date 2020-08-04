.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamFlag80
/* 0EF124 802CA774 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EF128 802CA778 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF12C 802CA77C 0080802D */  daddu $s0, $a0, $zero
/* 0EF130 802CA780 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EF134 802CA784 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF138 802CA788 8E11000C */  lw    $s1, 0xc($s0)
/* 0EF13C 802CA78C 8E250000 */  lw    $a1, ($s1)
/* 0EF140 802CA790 0C0B1EAF */  jal   get_variable
/* 0EF144 802CA794 26310004 */   addiu $s1, $s1, 4
/* 0EF148 802CA798 0200202D */  daddu $a0, $s0, $zero
/* 0EF14C 802CA79C 8E250000 */  lw    $a1, ($s1)
/* 0EF150 802CA7A0 0C0B1EAF */  jal   get_variable
/* 0EF154 802CA7A4 0040802D */   daddu $s0, $v0, $zero
/* 0EF158 802CA7A8 1440000D */  bnez  $v0, .L802CA7E0
/* 0EF15C 802CA7AC 00101080 */   sll   $v0, $s0, 2
/* 0EF160 802CA7B0 3C04800B */  lui   $a0, 0x800b
/* 0EF164 802CA7B4 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0EF168 802CA7B8 00501021 */  addu  $v0, $v0, $s0
/* 0EF16C 802CA7BC 00021080 */  sll   $v0, $v0, 2
/* 0EF170 802CA7C0 00501023 */  subu  $v0, $v0, $s0
/* 0EF174 802CA7C4 000218C0 */  sll   $v1, $v0, 3
/* 0EF178 802CA7C8 00431021 */  addu  $v0, $v0, $v1
/* 0EF17C 802CA7CC 000210C0 */  sll   $v0, $v0, 3
/* 0EF180 802CA7D0 00441021 */  addu  $v0, $v0, $a0
/* 0EF184 802CA7D4 94430000 */  lhu   $v1, ($v0)
/* 0EF188 802CA7D8 080B2A03 */  j     .L802CA80C
/* 0EF18C 802CA7DC 34630080 */   ori   $v1, $v1, 0x80

.L802CA7E0:
/* 0EF190 802CA7E0 3C04800B */  lui   $a0, 0x800b
/* 0EF194 802CA7E4 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0EF198 802CA7E8 00501021 */  addu  $v0, $v0, $s0
/* 0EF19C 802CA7EC 00021080 */  sll   $v0, $v0, 2
/* 0EF1A0 802CA7F0 00501023 */  subu  $v0, $v0, $s0
/* 0EF1A4 802CA7F4 000218C0 */  sll   $v1, $v0, 3
/* 0EF1A8 802CA7F8 00431021 */  addu  $v0, $v0, $v1
/* 0EF1AC 802CA7FC 000210C0 */  sll   $v0, $v0, 3
/* 0EF1B0 802CA800 00441021 */  addu  $v0, $v0, $a0
/* 0EF1B4 802CA804 94430000 */  lhu   $v1, ($v0)
/* 0EF1B8 802CA808 3063FF7F */  andi  $v1, $v1, 0xff7f
.L802CA80C:
/* 0EF1BC 802CA80C A4430000 */  sh    $v1, ($v0)
/* 0EF1C0 802CA810 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EF1C4 802CA814 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF1C8 802CA818 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF1CC 802CA81C 24020002 */  addiu $v0, $zero, 2
/* 0EF1D0 802CA820 03E00008 */  jr    $ra
/* 0EF1D4 802CA824 27BD0020 */   addiu $sp, $sp, 0x20

