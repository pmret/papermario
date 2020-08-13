.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E6904
/* 07FDB4 800E6904 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 07FDB8 800E6908 AFB10014 */  sw    $s1, 0x14($sp)
/* 07FDBC 800E690C 3C118011 */  lui   $s1, 0x8011
/* 07FDC0 800E6910 2631EBB0 */  addiu $s1, $s1, -0x1450
/* 07FDC4 800E6914 3C028011 */  lui   $v0, 0x8011
/* 07FDC8 800E6918 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 07FDCC 800E691C 0040202D */  daddu $a0, $v0, $zero
/* 07FDD0 800E6920 3C030010 */  lui   $v1, 0x10
/* 07FDD4 800E6924 AFBF0018 */  sw    $ra, 0x18($sp)
/* 07FDD8 800E6928 AFB00010 */  sw    $s0, 0x10($sp)
/* 07FDDC 800E692C 8C820004 */  lw    $v0, 4($a0)
/* 07FDE0 800E6930 809000B4 */  lb    $s0, 0xb4($a0)
/* 07FDE4 800E6934 00431024 */  and   $v0, $v0, $v1
/* 07FDE8 800E6938 14400023 */  bnez  $v0, .L800E69C8
/* 07FDEC 800E693C 0000102D */   daddu $v0, $zero, $zero
/* 07FDF0 800E6940 82220000 */  lb    $v0, ($s1)
/* 07FDF4 800E6944 1440000A */  bnez  $v0, .L800E6970
/* 07FDF8 800E6948 00000000 */   nop   
/* 07FDFC 800E694C 8C820000 */  lw    $v0, ($a0)
/* 07FE00 800E6950 30421000 */  andi  $v0, $v0, 0x1000
/* 07FE04 800E6954 1440001C */  bnez  $v0, .L800E69C8
/* 07FE08 800E6958 0000102D */   daddu $v0, $zero, $zero
/* 07FE0C 800E695C 2E020003 */  sltiu $v0, $s0, 3
/* 07FE10 800E6960 10400019 */  beqz  $v0, .L800E69C8
/* 07FE14 800E6964 0000102D */   daddu $v0, $zero, $zero
.L800E6968:
/* 07FE18 800E6968 08039A72 */  j     .L800E69C8
/* 07FE1C 800E696C 24020001 */   addiu $v0, $zero, 1

.L800E6970:
/* 07FE20 800E6970 0C03ACF8 */  jal   func_800EB3E0
/* 07FE24 800E6974 00000000 */   nop   
/* 07FE28 800E6978 10400012 */  beqz  $v0, .L800E69C4
/* 07FE2C 800E697C 24020006 */   addiu $v0, $zero, 6
/* 07FE30 800E6980 82230003 */  lb    $v1, 3($s1)
/* 07FE34 800E6984 1062FFF8 */  beq   $v1, $v0, .L800E6968
/* 07FE38 800E6988 24020009 */   addiu $v0, $zero, 9
/* 07FE3C 800E698C 14620006 */  bne   $v1, $v0, .L800E69A8
/* 07FE40 800E6990 24020008 */   addiu $v0, $zero, 8
/* 07FE44 800E6994 24020021 */  addiu $v0, $zero, 0x21
/* 07FE48 800E6998 1602000B */  bne   $s0, $v0, .L800E69C8
/* 07FE4C 800E699C 0000102D */   daddu $v0, $zero, $zero
/* 07FE50 800E69A0 08039A72 */  j     .L800E69C8
/* 07FE54 800E69A4 24020001 */   addiu $v0, $zero, 1

.L800E69A8:
/* 07FE58 800E69A8 14620007 */  bne   $v1, $v0, .L800E69C8
/* 07FE5C 800E69AC 0000102D */   daddu $v0, $zero, $zero
/* 07FE60 800E69B0 24020021 */  addiu $v0, $zero, 0x21
/* 07FE64 800E69B4 12020004 */  beq   $s0, $v0, .L800E69C8
/* 07FE68 800E69B8 24020001 */   addiu $v0, $zero, 1
/* 07FE6C 800E69BC 0C05272D */  jal   play_sound
/* 07FE70 800E69C0 2404021D */   addiu $a0, $zero, 0x21d
.L800E69C4:
/* 07FE74 800E69C4 0000102D */  daddu $v0, $zero, $zero
.L800E69C8:
/* 07FE78 800E69C8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 07FE7C 800E69CC 8FB10014 */  lw    $s1, 0x14($sp)
/* 07FE80 800E69D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 07FE84 800E69D4 03E00008 */  jr    $ra
/* 07FE88 800E69D8 27BD0020 */   addiu $sp, $sp, 0x20

