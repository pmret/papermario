.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_95445C
/* 95445C 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 954460 802404A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 954464 802404A4 8C82000C */  lw        $v0, 0xc($a0)
/* 954468 802404A8 0C0B1EAF */  jal       get_variable
/* 95446C 802404AC 8C450000 */   lw       $a1, ($v0)
/* 954470 802404B0 0C03AC5A */  jal       func_800EB168
/* 954474 802404B4 0040202D */   daddu    $a0, $v0, $zero
/* 954478 802404B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95447C 802404BC 24020002 */  addiu     $v0, $zero, 2
/* 954480 802404C0 03E00008 */  jr        $ra
/* 954484 802404C4 27BD0018 */   addiu    $sp, $sp, 0x18
