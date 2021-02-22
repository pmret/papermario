.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024112C_889CFC
/* 889CFC 8024112C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 889D00 80241130 AFBF0010 */  sw        $ra, 0x10($sp)
/* 889D04 80241134 8C82000C */  lw        $v0, 0xc($a0)
/* 889D08 80241138 0C0B1EAF */  jal       get_variable
/* 889D0C 8024113C 8C450000 */   lw       $a1, ($v0)
/* 889D10 80241140 0040202D */  daddu     $a0, $v0, $zero
/* 889D14 80241144 8C830000 */  lw        $v1, ($a0)
/* 889D18 80241148 34630010 */  ori       $v1, $v1, 0x10
/* 889D1C 8024114C AC830000 */  sw        $v1, ($a0)
/* 889D20 80241150 8FBF0010 */  lw        $ra, 0x10($sp)
/* 889D24 80241154 24020002 */  addiu     $v0, $zero, 2
/* 889D28 80241158 03E00008 */  jr        $ra
/* 889D2C 8024115C 27BD0018 */   addiu    $sp, $sp, 0x18
