.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219780_465C10
/* 465C10 80219780 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 465C14 80219784 AFBF0010 */  sw        $ra, 0x10($sp)
/* 465C18 80219788 8C82000C */  lw        $v0, 0xc($a0)
/* 465C1C 8021978C 0C0B1EAF */  jal       get_variable
/* 465C20 80219790 8C450000 */   lw       $a1, ($v0)
/* 465C24 80219794 0000202D */  daddu     $a0, $zero, $zero
/* 465C28 80219798 0080282D */  daddu     $a1, $a0, $zero
/* 465C2C 8021979C 0080302D */  daddu     $a2, $a0, $zero
/* 465C30 802197A0 0C046F97 */  jal       set_background_color_blend
/* 465C34 802197A4 304700FF */   andi     $a3, $v0, 0xff
/* 465C38 802197A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 465C3C 802197AC 24020002 */  addiu     $v0, $zero, 2
/* 465C40 802197B0 03E00008 */  jr        $ra
/* 465C44 802197B4 27BD0018 */   addiu    $sp, $sp, 0x18
