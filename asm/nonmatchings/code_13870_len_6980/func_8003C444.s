.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003C444
/* 017844 8003C444 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 017848 8003C448 AFB10014 */  sw    $s1, 0x14($sp)
/* 01784C 8003C44C 0080882D */  daddu $s1, $a0, $zero
/* 017850 8003C450 AFB00010 */  sw    $s0, 0x10($sp)
/* 017854 8003C454 0000802D */  daddu $s0, $zero, $zero
/* 017858 8003C458 AFB20018 */  sw    $s2, 0x18($sp)
/* 01785C 8003C45C 3C12800A */  lui   $s2, 0x800a
/* 017860 8003C460 265284E0 */  addiu $s2, $s2, -0x7b20
/* 017864 8003C464 AFBF001C */  sw    $ra, 0x1c($sp)
/* 017868 8003C468 02301021 */  addu  $v0, $s1, $s0
.L8003C46C:
/* 01786C 8003C46C 8043032C */  lb    $v1, 0x32c($v0)
/* 017870 8003C470 2C620007 */  sltiu $v0, $v1, 7
/* 017874 8003C474 50400028 */  beql  $v0, $zero, .L8003C518
/* 017878 8003C478 26100001 */   addiu $s0, $s0, 1
/* 01787C 8003C47C 00031080 */  sll   $v0, $v1, 2
/* 017880 8003C480 00521021 */  addu  $v0, $v0, $s2
/* 017884 8003C484 8C420000 */  lw    $v0, ($v0)
/* 017888 8003C488 00400008 */  jr    $v0
/* 01788C 8003C48C 00000000 */   nop   
/* 017890 8003C490 0220202D */  daddu $a0, $s1, $zero
/* 017894 8003C494 0C00F196 */  jal   func_8003C658
/* 017898 8003C498 0200282D */   daddu $a1, $s0, $zero
/* 01789C 8003C49C 0800F146 */  j     .L8003C518
/* 0178A0 8003C4A0 26100001 */   addiu $s0, $s0, 1

/* 0178A4 8003C4A4 0220202D */  daddu $a0, $s1, $zero
/* 0178A8 8003C4A8 0C00F19A */  jal   func_8003C668
/* 0178AC 8003C4AC 0200282D */   daddu $a1, $s0, $zero
/* 0178B0 8003C4B0 0800F146 */  j     .L8003C518
/* 0178B4 8003C4B4 26100001 */   addiu $s0, $s0, 1

/* 0178B8 8003C4B8 0220202D */  daddu $a0, $s1, $zero
/* 0178BC 8003C4BC 0C00F1EA */  jal   func_8003C7A8
/* 0178C0 8003C4C0 0200282D */   daddu $a1, $s0, $zero
/* 0178C4 8003C4C4 0800F146 */  j     .L8003C518
/* 0178C8 8003C4C8 26100001 */   addiu $s0, $s0, 1

/* 0178CC 8003C4CC 0220202D */  daddu $a0, $s1, $zero
/* 0178D0 8003C4D0 0C00F22D */  jal   func_8003C8B4
/* 0178D4 8003C4D4 0200282D */   daddu $a1, $s0, $zero
/* 0178D8 8003C4D8 0800F146 */  j     .L8003C518
/* 0178DC 8003C4DC 26100001 */   addiu $s0, $s0, 1

/* 0178E0 8003C4E0 0220202D */  daddu $a0, $s1, $zero
/* 0178E4 8003C4E4 0C00F26A */  jal   func_8003C9A8
/* 0178E8 8003C4E8 0200282D */   daddu $a1, $s0, $zero
/* 0178EC 8003C4EC 0800F146 */  j     .L8003C518
/* 0178F0 8003C4F0 26100001 */   addiu $s0, $s0, 1

/* 0178F4 8003C4F4 0220202D */  daddu $a0, $s1, $zero
/* 0178F8 8003C4F8 0C00F2D1 */  jal   func_8003CB44
/* 0178FC 8003C4FC 0200282D */   daddu $a1, $s0, $zero
/* 017900 8003C500 0800F146 */  j     .L8003C518
/* 017904 8003C504 26100001 */   addiu $s0, $s0, 1

/* 017908 8003C508 0220202D */  daddu $a0, $s1, $zero
/* 01790C 8003C50C 0C00F32C */  jal   func_8003CCB0
/* 017910 8003C510 0200282D */   daddu $a1, $s0, $zero
/* 017914 8003C514 26100001 */  addiu $s0, $s0, 1
.L8003C518:
/* 017918 8003C518 2A020002 */  slti  $v0, $s0, 2
/* 01791C 8003C51C 5440FFD3 */  bnel  $v0, $zero, .L8003C46C
/* 017920 8003C520 02301021 */   addu  $v0, $s1, $s0
/* 017924 8003C524 8FBF001C */  lw    $ra, 0x1c($sp)
/* 017928 8003C528 8FB20018 */  lw    $s2, 0x18($sp)
/* 01792C 8003C52C 8FB10014 */  lw    $s1, 0x14($sp)
/* 017930 8003C530 8FB00010 */  lw    $s0, 0x10($sp)
/* 017934 8003C534 03E00008 */  jr    $ra
/* 017938 8003C538 27BD0020 */   addiu $sp, $sp, 0x20

