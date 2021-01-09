.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006672C
/* 36675C E006672C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 366760 E0066730 3C02E006 */  lui       $v0, %hi(func_E0066770)
/* 366764 E0066734 24426770 */  addiu     $v0, $v0, %lo(func_E0066770)
/* 366768 E0066738 AFA2001C */  sw        $v0, 0x1c($sp)
/* 36676C E006673C 2402002D */  addiu     $v0, $zero, 0x2d
/* 366770 E0066740 AFA40018 */  sw        $a0, 0x18($sp)
/* 366774 E0066744 27A40010 */  addiu     $a0, $sp, 0x10
/* 366778 E0066748 AFBF0020 */  sw        $ra, 0x20($sp)
/* 36677C E006674C AFA00014 */  sw        $zero, 0x14($sp)
/* 366780 E0066750 0C080120 */  jal       func_E0200480
/* 366784 E0066754 AFA20010 */   sw       $v0, 0x10($sp)
/* 366788 E0066758 8C430000 */  lw        $v1, ($v0)
/* 36678C E006675C 34630002 */  ori       $v1, $v1, 2
/* 366790 E0066760 AC430000 */  sw        $v1, ($v0)
/* 366794 E0066764 8FBF0020 */  lw        $ra, 0x20($sp)
/* 366798 E0066768 03E00008 */  jr        $ra
/* 36679C E006676C 27BD0028 */   addiu    $sp, $sp, 0x28
