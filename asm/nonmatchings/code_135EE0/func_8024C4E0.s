.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024C4E0
.L8024C4E0:
/* 13F820 8024C4E0 00031040 */  sll   $v0, $v1, 1
/* 13F824 8024C4E4 00431021 */  addu  $v0, $v0, $v1
/* 13F828 8024C4E8 00021080 */  sll   $v0, $v0, 2
/* 13F82C 8024C4EC 00431021 */  addu  $v0, $v0, $v1
/* 13F830 8024C4F0 3C108027 */  lui   $s0, 0x8027
/* 13F834 8024C4F4 8E1006AC */  lw    $s0, 0x6ac($s0)
/* 13F838 8024C4F8 2442001E */  addiu $v0, $v0, 0x1e
/* 13F83C 8024C4FC 3C018016 */  lui   $at, 0x8016
/* 13F840 8024C500 A422A1E2 */  sh    $v0, -0x5e1e($at)
/* 13F844 8024C504 24020001 */  addiu $v0, $zero, 1
/* 13F848 8024C508 16020043 */  bne   $s0, $v0, .L8024C618
/* 13F84C 8024C50C 00000000 */   nop   
/* 13F850 8024C510 3C118027 */  lui   $s1, 0x8027
/* 13F854 8024C514 8E3106A4 */  lw    $s1, 0x6a4($s1)
/* 13F858 8024C518 0C039D59 */  jal   get_player_data
/* 13F85C 8024C51C 00000000 */   nop   
/* 13F860 8024C520 3C038027 */  lui   $v1, 0x8027
/* 13F864 8024C524 8C6306A0 */  lw    $v1, 0x6a0($v1)
/* 13F868 8024C528 00031880 */  sll   $v1, $v1, 2
/* 13F86C 8024C52C 3C018027 */  lui   $at, 0x8027
/* 13F870 8024C530 00230821 */  addu  $at, $at, $v1
/* 13F874 8024C534 8C230680 */  lw    $v1, 0x680($at)
/* 13F878 8024C538 00031880 */  sll   $v1, $v1, 2
/* 13F87C 8024C53C 3C018025 */  lui   $at, 0x8025
/* 13F880 8024C540 00230821 */  addu  $at, $at, $v1
