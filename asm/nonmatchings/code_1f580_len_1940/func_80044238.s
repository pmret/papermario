.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044238
/* 1F638 80044238 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F63C 8004423C AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F640 80044240 8C82000C */  lw        $v0, 0xc($a0)
/* 1F644 80044244 0C0B1EAF */  jal       get_variable
/* 1F648 80044248 8C450000 */   lw       $a1, ($v0)
/* 1F64C 8004424C 0C01CAF3 */  jal       func_80072BCC
/* 1F650 80044250 0040202D */   daddu    $a0, $v0, $zero
/* 1F654 80044254 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F658 80044258 24020002 */  addiu     $v0, $zero, 2
/* 1F65C 8004425C 03E00008 */  jr        $ra
/* 1F660 80044260 27BD0018 */   addiu    $sp, $sp, 0x18
