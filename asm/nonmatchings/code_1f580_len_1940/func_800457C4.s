.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800457C4
/* 20BC4 800457C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20BC8 800457C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 20BCC 800457CC AFB00010 */  sw        $s0, 0x10($sp)
/* 20BD0 800457D0 8C82000C */  lw        $v0, 0xc($a0)
/* 20BD4 800457D4 8C450000 */  lw        $a1, ($v0)
/* 20BD8 800457D8 0C0B1EAF */  jal       get_variable
/* 20BDC 800457DC 8C900148 */   lw       $s0, 0x148($a0)
/* 20BE0 800457E0 A20200B5 */  sb        $v0, 0xb5($s0)
/* 20BE4 800457E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 20BE8 800457E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 20BEC 800457EC 24020002 */  addiu     $v0, $zero, 2
/* 20BF0 800457F0 03E00008 */  jr        $ra
/* 20BF4 800457F4 27BD0018 */   addiu    $sp, $sp, 0x18
