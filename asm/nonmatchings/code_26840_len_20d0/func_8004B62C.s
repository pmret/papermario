.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B62C
/* 26A2C 8004B62C 24080008 */  addiu     $t0, $zero, 8
/* 26A30 8004B630 8C820000 */  lw        $v0, ($a0)
/* 26A34 8004B634 0000382D */  daddu     $a3, $zero, $zero
/* 26A38 8004B638 8C4500A0 */  lw        $a1, 0xa0($v0)
/* 26A3C 8004B63C 0080302D */  daddu     $a2, $a0, $zero
/* 26A40 8004B640 00A0182D */  daddu     $v1, $a1, $zero
/* 26A44 8004B644 AC850008 */  sw        $a1, 8($a0)
.L8004B648:
/* 26A48 8004B648 94620010 */  lhu       $v0, 0x10($v1)
/* 26A4C 8004B64C 50400004 */  beql      $v0, $zero, .L8004B660
/* 26A50 8004B650 24C60004 */   addiu    $a2, $a2, 4
/* 26A54 8004B654 00451021 */  addu      $v0, $v0, $a1
/* 26A58 8004B658 ACC2000C */  sw        $v0, 0xc($a2)
/* 26A5C 8004B65C 24C60004 */  addiu     $a2, $a2, 4
.L8004B660:
/* 26A60 8004B660 24E70001 */  addiu     $a3, $a3, 1
/* 26A64 8004B664 00E8102B */  sltu      $v0, $a3, $t0
/* 26A68 8004B668 1440FFF7 */  bnez      $v0, .L8004B648
/* 26A6C 8004B66C 24630002 */   addiu    $v1, $v1, 2
/* 26A70 8004B670 90A3000E */  lbu       $v1, 0xe($a1)
/* 26A74 8004B674 24020001 */  addiu     $v0, $zero, 1
/* 26A78 8004B678 14620005 */  bne       $v1, $v0, .L8004B690
/* 26A7C 8004B67C 00000000 */   nop      
/* 26A80 8004B680 94A20020 */  lhu       $v0, 0x20($a1)
/* 26A84 8004B684 10400002 */  beqz      $v0, .L8004B690
/* 26A88 8004B688 00451021 */   addu     $v0, $v0, $a1
/* 26A8C 8004B68C AC82002C */  sw        $v0, 0x2c($a0)
.L8004B690:
/* 26A90 8004B690 03E00008 */  jr        $ra
/* 26A94 8004B694 00000000 */   nop      
