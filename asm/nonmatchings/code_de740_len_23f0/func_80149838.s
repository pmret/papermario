.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80149838
/* 0DFF38 80149838 3C028007 */  lui   $v0, 0x8007
/* 0DFF3C 8014983C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0DFF40 80149840 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DFF44 80149844 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0DFF48 80149848 AFB10014 */  sw    $s1, 0x14($sp)
/* 0DFF4C 8014984C AFB00010 */  sw    $s0, 0x10($sp)
/* 0DFF50 80149850 80420070 */  lb    $v0, 0x70($v0)
/* 0DFF54 80149854 14400005 */  bnez  $v0, .L8014986C
/* 0DFF58 80149858 00000000 */   nop   
/* 0DFF5C 8014985C 3C028016 */  lui   $v0, 0x8016
/* 0DFF60 80149860 244298A0 */  addiu $v0, $v0, -0x6760
/* 0DFF64 80149864 0805261D */  j     .L80149874
/* 0DFF68 80149868 00000000 */   nop   

.L8014986C:
/* 0DFF6C 8014986C 3C028016 */  lui   $v0, 0x8016
/* 0DFF70 80149870 244299B8 */  addiu $v0, $v0, -0x6648
.L80149874:
/* 0DFF74 80149874 3C018016 */  lui   $at, 0x8016
/* 0DFF78 80149878 AC229AD0 */  sw    $v0, -0x6530($at)
/* 0DFF7C 8014987C 3C108016 */  lui   $s0, 0x8016
/* 0DFF80 80149880 8E109AD0 */  lw    $s0, -0x6530($s0)
/* 0DFF84 80149884 0000882D */  daddu $s1, $zero, $zero
.L80149888:
/* 0DFF88 80149888 8E020000 */  lw    $v0, ($s0)
/* 0DFF8C 8014988C 30420001 */  andi  $v0, $v0, 1
/* 0DFF90 80149890 10400004 */  beqz  $v0, .L801498A4
/* 0DFF94 80149894 26310001 */   addiu $s1, $s1, 1
/* 0DFF98 80149898 8E040004 */  lw    $a0, 4($s0)
/* 0DFF9C 8014989C 0C0154F0 */  jal   func_800553C0
/* 0DFFA0 801498A0 00000000 */   nop   
.L801498A4:
/* 0DFFA4 801498A4 2A22000A */  slti  $v0, $s1, 0xa
/* 0DFFA8 801498A8 1440FFF7 */  bnez  $v0, .L80149888
/* 0DFFAC 801498AC 2610001C */   addiu $s0, $s0, 0x1c
/* 0DFFB0 801498B0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0DFFB4 801498B4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0DFFB8 801498B8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DFFBC 801498BC 03E00008 */  jr    $ra
/* 0DFFC0 801498C0 27BD0020 */   addiu $sp, $sp, 0x20

