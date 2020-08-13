.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamEnabled
/* 0EF070 802CA6C0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EF074 802CA6C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF078 802CA6C8 0080802D */  daddu $s0, $a0, $zero
/* 0EF07C 802CA6CC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EF080 802CA6D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF084 802CA6D4 8E11000C */  lw    $s1, 0xc($s0)
/* 0EF088 802CA6D8 8E250000 */  lw    $a1, ($s1)
/* 0EF08C 802CA6DC 0C0B1EAF */  jal   get_variable
/* 0EF090 802CA6E0 26310004 */   addiu $s1, $s1, 4
/* 0EF094 802CA6E4 0200202D */  daddu $a0, $s0, $zero
/* 0EF098 802CA6E8 8E250000 */  lw    $a1, ($s1)
/* 0EF09C 802CA6EC 0C0B1EAF */  jal   get_variable
/* 0EF0A0 802CA6F0 0040802D */   daddu $s0, $v0, $zero
/* 0EF0A4 802CA6F4 1440000D */  bnez  $v0, .L802CA72C
/* 0EF0A8 802CA6F8 00101080 */   sll   $v0, $s0, 2
/* 0EF0AC 802CA6FC 3C04800B */  lui   $a0, 0x800b
/* 0EF0B0 802CA700 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0EF0B4 802CA704 00501021 */  addu  $v0, $v0, $s0
/* 0EF0B8 802CA708 00021080 */  sll   $v0, $v0, 2
/* 0EF0BC 802CA70C 00501023 */  subu  $v0, $v0, $s0
/* 0EF0C0 802CA710 000218C0 */  sll   $v1, $v0, 3
/* 0EF0C4 802CA714 00431021 */  addu  $v0, $v0, $v1
/* 0EF0C8 802CA718 000210C0 */  sll   $v0, $v0, 3
/* 0EF0CC 802CA71C 00441021 */  addu  $v0, $v0, $a0
/* 0EF0D0 802CA720 94430000 */  lhu   $v1, ($v0)
/* 0EF0D4 802CA724 080B29D6 */  j     .L802CA758
/* 0EF0D8 802CA728 34630002 */   ori   $v1, $v1, 2

.L802CA72C:
/* 0EF0DC 802CA72C 3C04800B */  lui   $a0, 0x800b
/* 0EF0E0 802CA730 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0EF0E4 802CA734 00501021 */  addu  $v0, $v0, $s0
/* 0EF0E8 802CA738 00021080 */  sll   $v0, $v0, 2
/* 0EF0EC 802CA73C 00501023 */  subu  $v0, $v0, $s0
/* 0EF0F0 802CA740 000218C0 */  sll   $v1, $v0, 3
/* 0EF0F4 802CA744 00431021 */  addu  $v0, $v0, $v1
/* 0EF0F8 802CA748 000210C0 */  sll   $v0, $v0, 3
/* 0EF0FC 802CA74C 00441021 */  addu  $v0, $v0, $a0
/* 0EF100 802CA750 94430000 */  lhu   $v1, ($v0)
/* 0EF104 802CA754 3063FFFD */  andi  $v1, $v1, 0xfffd
.L802CA758:
/* 0EF108 802CA758 A4430000 */  sh    $v1, ($v0)
/* 0EF10C 802CA75C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EF110 802CA760 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF114 802CA764 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF118 802CA768 24020002 */  addiu $v0, $zero, 2
/* 0EF11C 802CA76C 03E00008 */  jr    $ra
/* 0EF120 802CA770 27BD0020 */   addiu $sp, $sp, 0x20

