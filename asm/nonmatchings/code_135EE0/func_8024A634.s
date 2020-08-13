.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024A634
/* 13D974 8024A634 84E20000 */  lh    $v0, ($a3)
/* 13D978 8024A638 04420001 */  bltzl $v0, .L8024A640
/* 13D97C 8024A63C 24420007 */   addiu $v0, $v0, 7
.L8024A640:
/* 13D980 8024A640 000210C3 */  sra   $v0, $v0, 3
/* 13D984 8024A644 0082102A */  slt   $v0, $a0, $v0
/* 13D988 8024A648 1040000B */  beqz  $v0, .L8024A678
/* 13D98C 8024A64C 000410C0 */   sll   $v0, $a0, 3
/* 13D990 8024A650 24840001 */  addiu $a0, $a0, 1
/* 13D994 8024A654 A062FFF9 */  sb    $v0, -7($v1)
/* 13D998 8024A658 A066FFFA */  sb    $a2, -6($v1)
/* 13D99C 8024A65C A069FFFB */  sb    $t1, -5($v1)
/* 13D9A0 8024A660 A0A60000 */  sb    $a2, ($a1)
/* 13D9A4 8024A664 AC62FFFC */  sw    $v0, -4($v1)
/* 13D9A8 8024A668 AC680000 */  sw    $t0, ($v1)
/* 13D9AC 8024A66C 2463000C */  addiu $v1, $v1, 0xc
/* 13D9B0 8024A670 0809298D */  j     func_8024A634
/* 13D9B4 8024A674 24A5000C */   addiu $a1, $a1, 0xc

.L8024A678:
/* 13D9B8 8024A678 94E20000 */  lhu   $v0, ($a3)
/* 13D9BC 8024A67C 30420007 */  andi  $v0, $v0, 7
/* 13D9C0 8024A680 10400016 */  beqz  $v0, .L8024A6DC
/* 13D9C4 8024A684 000418C0 */   sll   $v1, $a0, 3
/* 13D9C8 8024A688 24020001 */  addiu $v0, $zero, 1
/* 13D9CC 8024A68C A0A30001 */  sb    $v1, 1($a1)
/* 13D9D0 8024A690 A0A20002 */  sb    $v0, 2($a1)
/* 13D9D4 8024A694 A0A20000 */  sb    $v0, ($a1)
/* 13D9D8 8024A698 84E60000 */  lh    $a2, ($a3)
/* 13D9DC 8024A69C ACA30004 */  sw    $v1, 4($a1)
/* 13D9E0 8024A6A0 04C10002 */  bgez  $a2, .L8024A6AC
/* 13D9E4 8024A6A4 00C0102D */   daddu $v0, $a2, $zero
/* 13D9E8 8024A6A8 24C20007 */  addiu $v0, $a2, 7
.L8024A6AC:
/* 13D9EC 8024A6AC 000210C3 */  sra   $v0, $v0, 3
/* 13D9F0 8024A6B0 000210C0 */  sll   $v0, $v0, 3
/* 13D9F4 8024A6B4 00C21023 */  subu  $v0, $a2, $v0
/* 13D9F8 8024A6B8 00021400 */  sll   $v0, $v0, 0x10
/* 13D9FC 8024A6BC 00021403 */  sra   $v0, $v0, 0x10
/* 13DA00 8024A6C0 ACA20008 */  sw    $v0, 8($a1)
/* 13DA04 8024A6C4 90A2000B */  lbu   $v0, 0xb($a1)
/* 13DA08 8024A6C8 24840001 */  addiu $a0, $a0, 1
/* 13DA0C 8024A6CC 080929B6 */  j     func_8024A6D8
/* 13DA10 8024A6D0 A0A20003 */   sb    $v0, 3($a1)

.L8024A6D4:
/* 13DA14 8024A6D4 24840001 */  addiu $a0, $a0, 1
