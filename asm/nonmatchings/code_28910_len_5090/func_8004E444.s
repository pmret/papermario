.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004E444
/* 029844 8004E444 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 029848 8004E448 AFB10014 */  sw    $s1, 0x14($sp)
/* 02984C 8004E44C 0080882D */  daddu $s1, $a0, $zero
/* 029850 8004E450 AFBF001C */  sw    $ra, 0x1c($sp)
/* 029854 8004E454 AFB20018 */  sw    $s2, 0x18($sp)
/* 029858 8004E458 AFB00010 */  sw    $s0, 0x10($sp)
/* 02985C 8004E45C 9623002C */  lhu   $v1, 0x2c($s1)
/* 029860 8004E460 9622003C */  lhu   $v0, 0x3c($s1)
/* 029864 8004E464 00620018 */  mult  $v1, $v0
/* 029868 8004E468 0000802D */  daddu $s0, $zero, $zero
/* 02986C 8004E46C 00003812 */  mflo  $a3
/* 029870 8004E470 000793C2 */  srl   $s2, $a3, 0xf
/* 029874 8004E474 02301021 */  addu  $v0, $s1, $s0
.L8004E478:
/* 029878 8004E478 8043004C */  lb    $v1, 0x4c($v0)
/* 02987C 8004E47C 9044004C */  lbu   $a0, 0x4c($v0)
/* 029880 8004E480 04600007 */  bltz  $v1, .L8004E4A0
/* 029884 8004E484 26100001 */   addiu $s0, $s0, 1
/* 029888 8004E488 8E260048 */  lw    $a2, 0x48($s1)
/* 02988C 8004E48C 0C014EA6 */  jal   func_80053A98
/* 029890 8004E490 3245FFFF */   andi  $a1, $s2, 0xffff
/* 029894 8004E494 2A020004 */  slti  $v0, $s0, 4
/* 029898 8004E498 1440FFF7 */  bnez  $v0, .L8004E478
/* 02989C 8004E49C 02301021 */   addu  $v0, $s1, $s0
.L8004E4A0:
/* 0298A0 8004E4A0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0298A4 8004E4A4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0298A8 8004E4A8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0298AC 8004E4AC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0298B0 8004E4B0 03E00008 */  jr    $ra
/* 0298B4 8004E4B4 27BD0020 */   addiu $sp, $sp, 0x20

