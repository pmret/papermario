.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243D78
/* 855EE8 80243D78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 855EEC 80243D7C AFBF0010 */  sw        $ra, 0x10($sp)
/* 855EF0 80243D80 8C82000C */  lw        $v0, 0xc($a0)
/* 855EF4 80243D84 0C0B1EAF */  jal       get_variable
/* 855EF8 80243D88 8C450000 */   lw       $a1, ($v0)
/* 855EFC 80243D8C 8C44000C */  lw        $a0, 0xc($v0)
/* 855F00 80243D90 24030001 */  addiu     $v1, $zero, 1
/* 855F04 80243D94 AC830004 */  sw        $v1, 4($a0)
/* 855F08 80243D98 8FBF0010 */  lw        $ra, 0x10($sp)
/* 855F0C 80243D9C 24020002 */  addiu     $v0, $zero, 2
/* 855F10 80243DA0 03E00008 */  jr        $ra
/* 855F14 80243DA4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 855F18 80243DA8 00000000 */  nop       
/* 855F1C 80243DAC 00000000 */  nop       
