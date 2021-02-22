.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C34_97F704
/* 97F704 80241C34 3C048024 */  lui       $a0, %hi(D_80242618_9800E8)
/* 97F708 80241C38 8C842618 */  lw        $a0, %lo(D_80242618_9800E8)($a0)
/* 97F70C 80241C3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 97F710 80241C40 AFBF0010 */  sw        $ra, 0x10($sp)
/* 97F714 80241C44 0C048D70 */  jal       func_801235C0
/* 97F718 80241C48 00000000 */   nop
/* 97F71C 80241C4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 97F720 80241C50 24020002 */  addiu     $v0, $zero, 2
/* 97F724 80241C54 03E00008 */  jr        $ra
/* 97F728 80241C58 27BD0018 */   addiu    $sp, $sp, 0x18
