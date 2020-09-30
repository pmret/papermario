.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D050
/* 28450 8004D050 8C820004 */  lw        $v0, 4($a0)
/* 28454 8004D054 90430045 */  lbu       $v1, 0x45($v0)
/* 28458 8004D058 908200BC */  lbu       $v0, 0xbc($a0)
/* 2845C 8004D05C 14620005 */  bne       $v1, $v0, .L8004D074
/* 28460 8004D060 24030002 */   addiu    $v1, $zero, 2
/* 28464 8004D064 8CA20000 */  lw        $v0, ($a1)
/* 28468 8004D068 A4A3008E */  sh        $v1, 0x8e($a1)
/* 2846C 8004D06C 2442FFFF */  addiu     $v0, $v0, -1
/* 28470 8004D070 ACA20000 */  sw        $v0, ($a1)
.L8004D074:
/* 28474 8004D074 03E00008 */  jr        $ra
/* 28478 8004D078 00000000 */   nop      
