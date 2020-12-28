.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188EC_5CEF7C
/* 5CEF7C 802188EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5CEF80 802188F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5CEF84 802188F4 8C82000C */  lw        $v0, 0xc($a0)
/* 5CEF88 802188F8 0C0B1EAF */  jal       get_variable
/* 5CEF8C 802188FC 8C450000 */   lw       $a1, ($v0)
/* 5CEF90 80218900 0000202D */  daddu     $a0, $zero, $zero
/* 5CEF94 80218904 0080282D */  daddu     $a1, $a0, $zero
/* 5CEF98 80218908 0080302D */  daddu     $a2, $a0, $zero
/* 5CEF9C 8021890C 0C046F97 */  jal       set_background_color_blend
/* 5CEFA0 80218910 304700FF */   andi     $a3, $v0, 0xff
/* 5CEFA4 80218914 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5CEFA8 80218918 24020002 */  addiu     $v0, $zero, 2
/* 5CEFAC 8021891C 03E00008 */  jr        $ra
/* 5CEFB0 80218920 27BD0018 */   addiu    $sp, $sp, 0x18
