.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021849C_63D67C
/* 63D67C 8021849C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63D680 802184A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63D684 802184A4 8C82000C */  lw        $v0, 0xc($a0)
/* 63D688 802184A8 0C0B1EAF */  jal       get_variable
/* 63D68C 802184AC 8C450000 */   lw       $a1, ($v0)
/* 63D690 802184B0 0000202D */  daddu     $a0, $zero, $zero
/* 63D694 802184B4 0080282D */  daddu     $a1, $a0, $zero
/* 63D698 802184B8 0080302D */  daddu     $a2, $a0, $zero
/* 63D69C 802184BC 0C046F97 */  jal       set_background_color_blend
/* 63D6A0 802184C0 304700FF */   andi     $a3, $v0, 0xff
/* 63D6A4 802184C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63D6A8 802184C8 24020002 */  addiu     $v0, $zero, 2
/* 63D6AC 802184CC 03E00008 */  jr        $ra
/* 63D6B0 802184D0 27BD0018 */   addiu    $sp, $sp, 0x18
