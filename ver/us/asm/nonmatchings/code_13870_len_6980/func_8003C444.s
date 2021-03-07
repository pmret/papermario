.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_800984E0
.word 0x8003C490, 0x8003C4A4, 0x8003C4B8, 0x8003C4CC, 0x8003C4E0, 0x8003C4F4, 0x8003C508, 0x00000000

.section .text

glabel func_8003C444
/* 17844 8003C444 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17848 8003C448 AFB10014 */  sw        $s1, 0x14($sp)
/* 1784C 8003C44C 0080882D */  daddu     $s1, $a0, $zero
/* 17850 8003C450 AFB00010 */  sw        $s0, 0x10($sp)
/* 17854 8003C454 0000802D */  daddu     $s0, $zero, $zero
/* 17858 8003C458 AFB20018 */  sw        $s2, 0x18($sp)
/* 1785C 8003C45C 3C12800A */  lui       $s2, %hi(D_800984E0)
/* 17860 8003C460 265284E0 */  addiu     $s2, $s2, %lo(D_800984E0)
/* 17864 8003C464 AFBF001C */  sw        $ra, 0x1c($sp)
/* 17868 8003C468 02301021 */  addu      $v0, $s1, $s0
.L8003C46C:
/* 1786C 8003C46C 8043032C */  lb        $v1, 0x32c($v0)
/* 17870 8003C470 2C620007 */  sltiu     $v0, $v1, 7
/* 17874 8003C474 50400028 */  beql      $v0, $zero, .L8003C518
/* 17878 8003C478 26100001 */   addiu    $s0, $s0, 1
/* 1787C 8003C47C 00031080 */  sll       $v0, $v1, 2
/* 17880 8003C480 00521021 */  addu      $v0, $v0, $s2
/* 17884 8003C484 8C420000 */  lw        $v0, ($v0)
/* 17888 8003C488 00400008 */  jr        $v0
/* 1788C 8003C48C 00000000 */   nop
/* 17890 8003C490 0220202D */  daddu     $a0, $s1, $zero
/* 17894 8003C494 0C00F196 */  jal       func_8003C658
/* 17898 8003C498 0200282D */   daddu    $a1, $s0, $zero
/* 1789C 8003C49C 0800F146 */  j         .L8003C518
/* 178A0 8003C4A0 26100001 */   addiu    $s0, $s0, 1
/* 178A4 8003C4A4 0220202D */  daddu     $a0, $s1, $zero
/* 178A8 8003C4A8 0C00F19A */  jal       func_8003C668
/* 178AC 8003C4AC 0200282D */   daddu    $a1, $s0, $zero
/* 178B0 8003C4B0 0800F146 */  j         .L8003C518
/* 178B4 8003C4B4 26100001 */   addiu    $s0, $s0, 1
/* 178B8 8003C4B8 0220202D */  daddu     $a0, $s1, $zero
/* 178BC 8003C4BC 0C00F1EA */  jal       func_8003C7A8
/* 178C0 8003C4C0 0200282D */   daddu    $a1, $s0, $zero
/* 178C4 8003C4C4 0800F146 */  j         .L8003C518
/* 178C8 8003C4C8 26100001 */   addiu    $s0, $s0, 1
/* 178CC 8003C4CC 0220202D */  daddu     $a0, $s1, $zero
/* 178D0 8003C4D0 0C00F22D */  jal       func_8003C8B4
/* 178D4 8003C4D4 0200282D */   daddu    $a1, $s0, $zero
/* 178D8 8003C4D8 0800F146 */  j         .L8003C518
/* 178DC 8003C4DC 26100001 */   addiu    $s0, $s0, 1
/* 178E0 8003C4E0 0220202D */  daddu     $a0, $s1, $zero
/* 178E4 8003C4E4 0C00F26A */  jal       func_8003C9A8
/* 178E8 8003C4E8 0200282D */   daddu    $a1, $s0, $zero
/* 178EC 8003C4EC 0800F146 */  j         .L8003C518
/* 178F0 8003C4F0 26100001 */   addiu    $s0, $s0, 1
/* 178F4 8003C4F4 0220202D */  daddu     $a0, $s1, $zero
/* 178F8 8003C4F8 0C00F2D1 */  jal       func_8003CB44
/* 178FC 8003C4FC 0200282D */   daddu    $a1, $s0, $zero
/* 17900 8003C500 0800F146 */  j         .L8003C518
/* 17904 8003C504 26100001 */   addiu    $s0, $s0, 1
/* 17908 8003C508 0220202D */  daddu     $a0, $s1, $zero
/* 1790C 8003C50C 0C00F32C */  jal       func_8003CCB0
/* 17910 8003C510 0200282D */   daddu    $a1, $s0, $zero
/* 17914 8003C514 26100001 */  addiu     $s0, $s0, 1
.L8003C518:
/* 17918 8003C518 2A020002 */  slti      $v0, $s0, 2
/* 1791C 8003C51C 5440FFD3 */  bnel      $v0, $zero, .L8003C46C
/* 17920 8003C520 02301021 */   addu     $v0, $s1, $s0
/* 17924 8003C524 8FBF001C */  lw        $ra, 0x1c($sp)
/* 17928 8003C528 8FB20018 */  lw        $s2, 0x18($sp)
/* 1792C 8003C52C 8FB10014 */  lw        $s1, 0x14($sp)
/* 17930 8003C530 8FB00010 */  lw        $s0, 0x10($sp)
/* 17934 8003C534 03E00008 */  jr        $ra
/* 17938 8003C538 27BD0020 */   addiu    $sp, $sp, 0x20
