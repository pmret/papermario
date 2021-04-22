.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045484
/* 20884 80045484 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20888 80045488 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2088C 8004548C AFB00010 */  sw        $s0, 0x10($sp)
/* 20890 80045490 8C82000C */  lw        $v0, 0xc($a0)
/* 20894 80045494 8C450000 */  lw        $a1, ($v0)
/* 20898 80045498 0C0B1EAF */  jal       func_802C7ABC
/* 2089C 8004549C 8C900148 */   lw       $s0, 0x148($a0)
/* 208A0 800454A0 A20200B5 */  sb        $v0, 0xb5($s0)
/* 208A4 800454A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 208A8 800454A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 208AC 800454AC 24020002 */  addiu     $v0, $zero, 2
/* 208B0 800454B0 03E00008 */  jr        $ra
/* 208B4 800454B4 27BD0018 */   addiu    $sp, $sp, 0x18
