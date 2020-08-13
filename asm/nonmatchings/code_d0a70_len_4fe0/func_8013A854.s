.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8013A854
/* 0D0F54 8013A854 2C82005A */  sltiu $v0, $a0, 0x5a
/* 0D0F58 8013A858 10400009 */  beqz  $v0, .L8013A880
/* 0D0F5C 8013A85C 00041140 */   sll   $v0, $a0, 5
/* 0D0F60 8013A860 00441023 */  subu  $v0, $v0, $a0
/* 0D0F64 8013A864 3C038015 */  lui   $v1, 0x8015
/* 0D0F68 8013A868 8C636954 */  lw    $v1, 0x6954($v1)
/* 0D0F6C 8013A86C 00021080 */  sll   $v0, $v0, 2
/* 0D0F70 8013A870 00431021 */  addu  $v0, $v0, $v1
/* 0D0F74 8013A874 2403FFFF */  addiu $v1, $zero, -1
/* 0D0F78 8013A878 AC400014 */  sw    $zero, 0x14($v0)
/* 0D0F7C 8013A87C A4430010 */  sh    $v1, 0x10($v0)
.L8013A880:
/* 0D0F80 8013A880 03E00008 */  jr    $ra
/* 0D0F84 8013A884 00000000 */   nop   

/* 0D0F88 8013A888 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0D0F8C 8013A88C 2C82005A */  sltiu $v0, $a0, 0x5a
/* 0D0F90 8013A890 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0D0F94 8013A894 AFB10014 */  sw    $s1, 0x14($sp)
/* 0D0F98 8013A898 1040000C */  beqz  $v0, .L8013A8CC
/* 0D0F9C 8013A89C AFB00010 */   sw    $s0, 0x10($sp)
/* 0D0FA0 8013A8A0 2411FFFF */  addiu $s1, $zero, -1
.L8013A8A4:
/* 0D0FA4 8013A8A4 00041140 */  sll   $v0, $a0, 5
/* 0D0FA8 8013A8A8 00441023 */  subu  $v0, $v0, $a0
/* 0D0FAC 8013A8AC 3C038015 */  lui   $v1, 0x8015
/* 0D0FB0 8013A8B0 8C636954 */  lw    $v1, 0x6954($v1)
/* 0D0FB4 8013A8B4 00021080 */  sll   $v0, $v0, 2
/* 0D0FB8 8013A8B8 00431021 */  addu  $v0, $v0, $v1
/* 0D0FBC 8013A8BC 0C04EA15 */  jal   func_8013A854
/* 0D0FC0 8013A8C0 84500010 */   lh    $s0, 0x10($v0)
/* 0D0FC4 8013A8C4 1611FFF7 */  bne   $s0, $s1, .L8013A8A4
/* 0D0FC8 8013A8C8 0200202D */   daddu $a0, $s0, $zero
.L8013A8CC:
/* 0D0FCC 8013A8CC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0D0FD0 8013A8D0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0D0FD4 8013A8D4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0D0FD8 8013A8D8 03E00008 */  jr    $ra
/* 0D0FDC 8013A8DC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0D0FE0 8013A8E0 2C82005A */  sltiu $v0, $a0, 0x5a
/* 0D0FE4 8013A8E4 14400003 */  bnez  $v0, .L8013A8F4
/* 0D0FE8 8013A8E8 2882005A */   slti  $v0, $a0, 0x5a
/* 0D0FEC 8013A8EC 03E00008 */  jr    $ra
/* 0D0FF0 8013A8F0 2402FFFF */   addiu $v0, $zero, -1

.L8013A8F4:
/* 0D0FF4 8013A8F4 10400008 */  beqz  $v0, .L8013A918
/* 0D0FF8 8013A8F8 00041140 */   sll   $v0, $a0, 5
/* 0D0FFC 8013A8FC 00441023 */  subu  $v0, $v0, $a0
/* 0D1000 8013A900 3C038015 */  lui   $v1, 0x8015
/* 0D1004 8013A904 8C636954 */  lw    $v1, 0x6954($v1)
/* 0D1008 8013A908 00021080 */  sll   $v0, $v0, 2
/* 0D100C 8013A90C 00431021 */  addu  $v0, $v0, $v1
/* 0D1010 8013A910 03E00008 */  jr    $ra
/* 0D1014 8013A914 84420010 */   lh    $v0, 0x10($v0)

.L8013A918:
/* 0D1018 8013A918 03E00008 */  jr    $ra
/* 0D101C 8013A91C 240200FF */   addiu $v0, $zero, 0xff

/* 0D1020 8013A920 00041940 */  sll   $v1, $a0, 5
/* 0D1024 8013A924 00641823 */  subu  $v1, $v1, $a0
/* 0D1028 8013A928 3C028015 */  lui   $v0, 0x8015
/* 0D102C 8013A92C 8C426954 */  lw    $v0, 0x6954($v0)
/* 0D1030 8013A930 00031880 */  sll   $v1, $v1, 2
/* 0D1034 8013A934 03E00008 */  jr    $ra
/* 0D1038 8013A938 00431021 */   addu  $v0, $v0, $v1

