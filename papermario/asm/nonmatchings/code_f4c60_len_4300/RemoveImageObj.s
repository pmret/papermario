.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemoveImageObj
/* 0F7FD4 802D3624 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F7FD8 802D3628 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F7FDC 802D362C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7FE0 802D3630 8C82000C */  lw    $v0, 0xc($a0)
/* 0F7FE4 802D3634 0C0B1EAF */  jal   get_variable
/* 0F7FE8 802D3638 8C450000 */   lw    $a1, ($v0)
/* 0F7FEC 802D363C 3C03802E */  lui   $v1, 0x802e
/* 0F7FF0 802D3640 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F7FF4 802D3644 00021080 */  sll   $v0, $v0, 2
/* 0F7FF8 802D3648 00431021 */  addu  $v0, $v0, $v1
/* 0F7FFC 802D364C 8C500000 */  lw    $s0, ($v0)
/* 0F8000 802D3650 0C048B7F */  jal   func_80122DFC
/* 0F8004 802D3654 8E040000 */   lw    $a0, ($s0)
/* 0F8008 802D3658 2403FFFF */  addiu $v1, $zero, -1
/* 0F800C 802D365C AE030000 */  sw    $v1, ($s0)
/* 0F8010 802D3660 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F8014 802D3664 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8018 802D3668 24020002 */  addiu $v0, $zero, 2
/* 0F801C 802D366C 03E00008 */  jr    $ra
/* 0F8020 802D3670 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F8024 802D3674 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8028 802D3678 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F802C 802D367C 0080882D */  daddu $s1, $a0, $zero
/* 0F8030 802D3680 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8034 802D3684 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8038 802D3688 8E30000C */  lw    $s0, 0xc($s1)
/* 0F803C 802D368C 8E050000 */  lw    $a1, ($s0)
/* 0F8040 802D3690 0C0B1EAF */  jal   get_variable
/* 0F8044 802D3694 26100004 */   addiu $s0, $s0, 4
/* 0F8048 802D3698 0220202D */  daddu $a0, $s1, $zero
/* 0F804C 802D369C 8E050000 */  lw    $a1, ($s0)
/* 0F8050 802D36A0 0C0B1EAF */  jal   get_variable
/* 0F8054 802D36A4 0040802D */   daddu $s0, $v0, $zero
/* 0F8058 802D36A8 3C03802E */  lui   $v1, 0x802e
/* 0F805C 802D36AC 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F8060 802D36B0 00108080 */  sll   $s0, $s0, 2
/* 0F8064 802D36B4 02038021 */  addu  $s0, $s0, $v1
/* 0F8068 802D36B8 8E030000 */  lw    $v1, ($s0)
/* 0F806C 802D36BC 8C640000 */  lw    $a0, ($v1)
/* 0F8070 802D36C0 0C048B5F */  jal   func_80122D7C
/* 0F8074 802D36C4 0040282D */   daddu $a1, $v0, $zero
/* 0F8078 802D36C8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F807C 802D36CC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8080 802D36D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8084 802D36D4 24020002 */  addiu $v0, $zero, 2
/* 0F8088 802D36D8 03E00008 */  jr    $ra
/* 0F808C 802D36DC 27BD0020 */   addiu $sp, $sp, 0x20

