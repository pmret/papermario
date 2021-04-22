.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CD00
/* 28100 8004CD00 8C820004 */  lw        $v0, 4($a0)
/* 28104 8004CD04 90430045 */  lbu       $v1, 0x45($v0)
/* 28108 8004CD08 908200BC */  lbu       $v0, 0xbc($a0)
/* 2810C 8004CD0C 14620005 */  bne       $v1, $v0, .L8004CD24
/* 28110 8004CD10 24030002 */   addiu    $v1, $zero, 2
/* 28114 8004CD14 8CA20000 */  lw        $v0, ($a1)
/* 28118 8004CD18 A4A3008E */  sh        $v1, 0x8e($a1)
/* 2811C 8004CD1C 2442FFFF */  addiu     $v0, $v0, -1
/* 28120 8004CD20 ACA20000 */  sw        $v0, ($a1)
.L8004CD24:
/* 28124 8004CD24 03E00008 */  jr        $ra
/* 28128 8004CD28 00000000 */   nop
