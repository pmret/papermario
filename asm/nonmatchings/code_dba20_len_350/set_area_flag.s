.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_area_flag
/* 0DBCA0 801455A0 04810002 */  bgez  $a0, .L801455AC
/* 0DBCA4 801455A4 0080102D */   daddu $v0, $a0, $zero
/* 0DBCA8 801455A8 2482001F */  addiu $v0, $a0, 0x1f
.L801455AC:
/* 0DBCAC 801455AC 00021143 */  sra   $v0, $v0, 5
/* 0DBCB0 801455B0 00021940 */  sll   $v1, $v0, 5
/* 0DBCB4 801455B4 00831823 */  subu  $v1, $a0, $v1
/* 0DBCB8 801455B8 3C04800E */  lui   $a0, 0x800e
/* 0DBCBC 801455BC 2484ACC0 */  addiu $a0, $a0, -0x5340
/* 0DBCC0 801455C0 00021080 */  sll   $v0, $v0, 2
/* 0DBCC4 801455C4 00442821 */  addu  $a1, $v0, $a0
/* 0DBCC8 801455C8 24020001 */  addiu $v0, $zero, 1
/* 0DBCCC 801455CC 8CA412B0 */  lw    $a0, 0x12b0($a1)
/* 0DBCD0 801455D0 00621004 */  sllv  $v0, $v0, $v1
/* 0DBCD4 801455D4 00821824 */  and   $v1, $a0, $v0
/* 0DBCD8 801455D8 54600001 */  bnel  $v1, $zero, .L801455E0
/* 0DBCDC 801455DC 24030001 */   addiu $v1, $zero, 1
.L801455E0:
/* 0DBCE0 801455E0 00821025 */  or    $v0, $a0, $v0
/* 0DBCE4 801455E4 ACA212B0 */  sw    $v0, 0x12b0($a1)
/* 0DBCE8 801455E8 03E00008 */  jr    $ra
/* 0DBCEC 801455EC 0060102D */   daddu $v0, $v1, $zero

