.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269600
/* 197EE0 80269600 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197EE4 80269604 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197EE8 80269608 8C82000C */  lw        $v0, 0xc($a0)
/* 197EEC 8026960C 3C06800E */  lui       $a2, 0x800e
/* 197EF0 80269610 80C6C0F5 */  lb        $a2, -0x3f0b($a2)
/* 197EF4 80269614 0C0B2026 */  jal       set_variable
/* 197EF8 80269618 8C450000 */   lw       $a1, ($v0)
/* 197EFC 8026961C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197F00 80269620 24020002 */  addiu     $v0, $zero, 2
/* 197F04 80269624 03E00008 */  jr        $ra
/* 197F08 80269628 27BD0018 */   addiu    $sp, $sp, 0x18
