.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218FA4_4483E4
/* 4483E4 80218FA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4483E8 80218FA8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4483EC 80218FAC 8C82000C */  lw        $v0, 0xc($a0)
/* 4483F0 80218FB0 0C0B1EAF */  jal       get_variable
/* 4483F4 80218FB4 8C450000 */   lw       $a1, ($v0)
/* 4483F8 80218FB8 0000202D */  daddu     $a0, $zero, $zero
/* 4483FC 80218FBC 0080282D */  daddu     $a1, $a0, $zero
/* 448400 80218FC0 0080302D */  daddu     $a2, $a0, $zero
/* 448404 80218FC4 0C046F97 */  jal       set_background_color_blend
/* 448408 80218FC8 304700FF */   andi     $a3, $v0, 0xff
/* 44840C 80218FCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 448410 80218FD0 24020002 */  addiu     $v0, $zero, 2
/* 448414 80218FD4 03E00008 */  jr        $ra
/* 448418 80218FD8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 44841C 80218FDC 00000000 */  nop
