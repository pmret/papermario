.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_area_flag
/* 0DBCF0 801455F0 0080102D */  daddu $v0, $a0, $zero
/* 0DBCF4 801455F4 04410002 */  bgez  $v0, .L80145600
/* 0DBCF8 801455F8 0040182D */   daddu $v1, $v0, $zero
/* 0DBCFC 801455FC 2443001F */  addiu $v1, $v0, 0x1f
.L80145600:
/* 0DBD00 80145600 00031943 */  sra   $v1, $v1, 5
/* 0DBD04 80145604 00032140 */  sll   $a0, $v1, 5
/* 0DBD08 80145608 00442023 */  subu  $a0, $v0, $a0
/* 0DBD0C 8014560C 00031880 */  sll   $v1, $v1, 2
/* 0DBD10 80145610 24020001 */  addiu $v0, $zero, 1
/* 0DBD14 80145614 3C01800E */  lui   $at, 0x800e
/* 0DBD18 80145618 00230821 */  addu  $at, $at, $v1
/* 0DBD1C 8014561C 8C23BF70 */  lw    $v1, -0x4090($at)
/* 0DBD20 80145620 00821004 */  sllv  $v0, $v0, $a0
/* 0DBD24 80145624 00621024 */  and   $v0, $v1, $v0
/* 0DBD28 80145628 54400001 */  bnel  $v0, $zero, .L80145630
/* 0DBD2C 8014562C 24020001 */   addiu $v0, $zero, 1
.L80145630:
/* 0DBD30 80145630 03E00008 */  jr    $ra
/* 0DBD34 80145634 00000000 */   nop   

