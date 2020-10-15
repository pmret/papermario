.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026962C
/* 197F0C 8026962C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197F10 80269630 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197F14 80269634 8C82000C */  lw        $v0, 0xc($a0)
/* 197F18 80269638 0C0B1EAF */  jal       get_variable
/* 197F1C 8026963C 8C450000 */   lw       $a1, ($v0)
/* 197F20 80269640 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197F24 80269644 3C01800E */  lui       $at, 0x800e
/* 197F28 80269648 A022C0F5 */  sb        $v0, -0x3f0b($at)
/* 197F2C 8026964C 24020002 */  addiu     $v0, $zero, 2
/* 197F30 80269650 03E00008 */  jr        $ra
/* 197F34 80269654 27BD0018 */   addiu    $sp, $sp, 0x18
/* 197F38 80269658 00000000 */  nop       
/* 197F3C 8026965C 00000000 */  nop       
