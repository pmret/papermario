.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel sign
/* 0048B0 800294B0 04800002 */  bltz  $a0, .L800294BC
/* 0048B4 800294B4 2402FFFF */   addiu $v0, $zero, -1
/* 0048B8 800294B8 0004102A */  slt   $v0, $zero, $a0
.L800294BC:
/* 0048BC 800294BC 03E00008 */  jr    $ra
/* 0048C0 800294C0 00000000 */   nop   

