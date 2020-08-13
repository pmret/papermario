.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055718
/* 030B18 80055718 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030B1C 8005571C AFB10014 */  sw    $s1, 0x14($sp)
/* 030B20 80055720 0080882D */  daddu $s1, $a0, $zero
/* 030B24 80055724 AFBF0018 */  sw    $ra, 0x18($sp)
/* 030B28 80055728 0C01430C */  jal   func_80050C30
/* 030B2C 8005572C AFB00010 */   sw    $s0, 0x10($sp)
/* 030B30 80055730 0040802D */  daddu $s0, $v0, $zero
/* 030B34 80055734 16000005 */  bnez  $s0, .L8005574C
/* 030B38 80055738 0200102D */   daddu $v0, $s0, $zero
/* 030B3C 8005573C 0220202D */  daddu $a0, $s1, $zero
/* 030B40 80055740 0C014319 */  jal   func_80050C64
/* 030B44 80055744 0000282D */   daddu $a1, $zero, $zero
/* 030B48 80055748 0200102D */  daddu $v0, $s0, $zero
.L8005574C:
/* 030B4C 8005574C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 030B50 80055750 8FB10014 */  lw    $s1, 0x14($sp)
/* 030B54 80055754 8FB00010 */  lw    $s0, 0x10($sp)
/* 030B58 80055758 03E00008 */  jr    $ra
/* 030B5C 8005575C 27BD0020 */   addiu $sp, $sp, 0x20

/* 030B60 80055760 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030B64 80055764 AFB20018 */  sw    $s2, 0x18($sp)
/* 030B68 80055768 0080902D */  daddu $s2, $a0, $zero
/* 030B6C 8005576C AFB10014 */  sw    $s1, 0x14($sp)
/* 030B70 80055770 24110004 */  addiu $s1, $zero, 4
/* 030B74 80055774 240200FF */  addiu $v0, $zero, 0xff
/* 030B78 80055778 AFB00010 */  sw    $s0, 0x10($sp)
/* 030B7C 8005577C 0000802D */  daddu $s0, $zero, $zero
/* 030B80 80055780 AFBF001C */  sw    $ra, 0x1c($sp)
/* 030B84 80055784 3C018008 */  lui   $at, 0x8008
/* 030B88 80055788 A4228DB6 */  sh    $v0, -0x724a($at)
/* 030B8C 8005578C 0200202D */  daddu $a0, $s0, $zero
.L80055790:
/* 030B90 80055790 0C015519 */  jal   func_80055464
/* 030B94 80055794 0000282D */   daddu $a1, $zero, $zero
/* 030B98 80055798 14400006 */  bnez  $v0, .L800557B4
/* 030B9C 8005579C 26100001 */   addiu $s0, $s0, 1
/* 030BA0 800557A0 0211102B */  sltu  $v0, $s0, $s1
/* 030BA4 800557A4 1440FFFA */  bnez  $v0, .L80055790
/* 030BA8 800557A8 0200202D */   daddu $a0, $s0, $zero
/* 030BAC 800557AC 0C015612 */  jal   func_80055848
/* 030BB0 800557B0 0240202D */   daddu $a0, $s2, $zero
.L800557B4:
/* 030BB4 800557B4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 030BB8 800557B8 8FB20018 */  lw    $s2, 0x18($sp)
/* 030BBC 800557BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 030BC0 800557C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 030BC4 800557C4 03E00008 */  jr    $ra
/* 030BC8 800557C8 27BD0020 */   addiu $sp, $sp, 0x20

/* 030BCC 800557CC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030BD0 800557D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 030BD4 800557D4 0080882D */  daddu $s1, $a0, $zero
/* 030BD8 800557D8 AFB20018 */  sw    $s2, 0x18($sp)
/* 030BDC 800557DC 24120004 */  addiu $s2, $zero, 4
/* 030BE0 800557E0 AFB00010 */  sw    $s0, 0x10($sp)
/* 030BE4 800557E4 0000802D */  daddu $s0, $zero, $zero
/* 030BE8 800557E8 AFBF001C */  sw    $ra, 0x1c($sp)
.L800557EC:
/* 030BEC 800557EC 3C028008 */  lui   $v0, 0x8008
/* 030BF0 800557F0 94428DB6 */  lhu   $v0, -0x724a($v0)
/* 030BF4 800557F4 16020005 */  bne   $s0, $v0, .L8005580C
/* 030BF8 800557F8 0200202D */   daddu $a0, $s0, $zero
/* 030BFC 800557FC 0C01553A */  jal   func_800554E8
/* 030C00 80055800 0220282D */   daddu $a1, $s1, $zero
/* 030C04 80055804 08015606 */  j     .L80055818
/* 030C08 80055808 0040182D */   daddu $v1, $v0, $zero

.L8005580C:
/* 030C0C 8005580C 0C015529 */  jal   func_800554A4
/* 030C10 80055810 0200202D */   daddu $a0, $s0, $zero
/* 030C14 80055814 0040182D */  daddu $v1, $v0, $zero
.L80055818:
/* 030C18 80055818 14600004 */  bnez  $v1, .L8005582C
/* 030C1C 8005581C 26100001 */   addiu $s0, $s0, 1
/* 030C20 80055820 0212102B */  sltu  $v0, $s0, $s2
/* 030C24 80055824 1440FFF1 */  bnez  $v0, .L800557EC
/* 030C28 80055828 00000000 */   nop   
.L8005582C:
/* 030C2C 8005582C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 030C30 80055830 8FB20018 */  lw    $s2, 0x18($sp)
/* 030C34 80055834 8FB10014 */  lw    $s1, 0x14($sp)
/* 030C38 80055838 8FB00010 */  lw    $s0, 0x10($sp)
/* 030C3C 8005583C 0060102D */  daddu $v0, $v1, $zero
/* 030C40 80055840 03E00008 */  jr    $ra
/* 030C44 80055844 27BD0020 */   addiu $sp, $sp, 0x20

