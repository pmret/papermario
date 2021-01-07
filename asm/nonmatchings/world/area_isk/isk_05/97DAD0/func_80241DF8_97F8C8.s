.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DF8_97F8C8
/* 97F8C8 80241DF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 97F8CC 80241DFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 97F8D0 80241E00 8C82000C */  lw        $v0, 0xc($a0)
/* 97F8D4 80241E04 0C0B1EAF */  jal       get_variable
/* 97F8D8 80241E08 8C450000 */   lw       $a1, ($v0)
/* 97F8DC 80241E0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 97F8E0 80241E10 3C018024 */  lui       $at, %hi(D_8024264C)
/* 97F8E4 80241E14 AC22264C */  sw        $v0, %lo(D_8024264C)($at)
/* 97F8E8 80241E18 24020002 */  addiu     $v0, $zero, 2
/* 97F8EC 80241E1C 03E00008 */  jr        $ra
/* 97F8F0 80241E20 27BD0018 */   addiu    $sp, $sp, 0x18
