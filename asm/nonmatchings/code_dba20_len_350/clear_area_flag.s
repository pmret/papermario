.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel clear_area_flag
/* 0DBC4C 8014554C 04810002 */  bgez  $a0, .L80145558
/* 0DBC50 80145550 0080102D */   daddu $v0, $a0, $zero
/* 0DBC54 80145554 2482001F */  addiu $v0, $a0, 0x1f
.L80145558:
/* 0DBC58 80145558 00021143 */  sra   $v0, $v0, 5
/* 0DBC5C 8014555C 00021940 */  sll   $v1, $v0, 5
/* 0DBC60 80145560 00831823 */  subu  $v1, $a0, $v1
/* 0DBC64 80145564 3C04800E */  lui   $a0, 0x800e
/* 0DBC68 80145568 2484ACC0 */  addiu $a0, $a0, -0x5340
/* 0DBC6C 8014556C 00021080 */  sll   $v0, $v0, 2
/* 0DBC70 80145570 00442821 */  addu  $a1, $v0, $a0
/* 0DBC74 80145574 24020001 */  addiu $v0, $zero, 1
/* 0DBC78 80145578 8CA412B0 */  lw    $a0, 0x12b0($a1)
/* 0DBC7C 8014557C 00621004 */  sllv  $v0, $v0, $v1
/* 0DBC80 80145580 00821824 */  and   $v1, $a0, $v0
/* 0DBC84 80145584 54600001 */  bnel  $v1, $zero, .L8014558C
/* 0DBC88 80145588 24030001 */   addiu $v1, $zero, 1
.L8014558C:
/* 0DBC8C 8014558C 00021027 */  nor   $v0, $zero, $v0
/* 0DBC90 80145590 00821024 */  and   $v0, $a0, $v0
/* 0DBC94 80145594 ACA212B0 */  sw    $v0, 0x12b0($a1)
/* 0DBC98 80145598 03E00008 */  jr    $ra
/* 0DBC9C 8014559C 0060102D */   daddu $v0, $v1, $zero

