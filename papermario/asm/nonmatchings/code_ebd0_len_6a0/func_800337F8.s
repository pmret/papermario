.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800337F8
/* 00EBF8 800337F8 3C058007 */  lui   $a1, 0x8007
/* 00EBFC 800337FC 8CA5419C */  lw    $a1, 0x419c($a1)
/* 00EC00 80033800 84A200B6 */  lh    $v0, 0xb6($a1)
/* 00EC04 80033804 94A300B6 */  lhu   $v1, 0xb6($a1)
/* 00EC08 80033808 14400003 */  bnez  $v0, .L80033818
/* 00EC0C 8003380C 00641023 */   subu  $v0, $v1, $a0
/* 00EC10 80033810 03E00008 */  jr    $ra
/* 00EC14 80033814 24020001 */   addiu $v0, $zero, 1

.L80033818:
/* 00EC18 80033818 A4A200B6 */  sh    $v0, 0xb6($a1)
/* 00EC1C 8003381C 00021400 */  sll   $v0, $v0, 0x10
/* 00EC20 80033820 04420001 */  bltzl $v0, .L80033828
/* 00EC24 80033824 A4A000B6 */   sh    $zero, 0xb6($a1)
.L80033828:
/* 00EC28 80033828 03E00008 */  jr    $ra
/* 00EC2C 8003382C 0000102D */   daddu $v0, $zero, $zero

