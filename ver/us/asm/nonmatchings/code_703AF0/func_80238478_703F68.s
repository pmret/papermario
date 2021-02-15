.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238478_703F68
/* 703F68 80238478 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 703F6C 8023847C AFBF0010 */  sw        $ra, 0x10($sp)
/* 703F70 80238480 8C82000C */  lw        $v0, 0xc($a0)
/* 703F74 80238484 0C0B1EAF */  jal       get_variable
/* 703F78 80238488 8C450000 */   lw       $a1, ($v0)
/* 703F7C 8023848C 0000202D */  daddu     $a0, $zero, $zero
/* 703F80 80238490 0080282D */  daddu     $a1, $a0, $zero
/* 703F84 80238494 0080302D */  daddu     $a2, $a0, $zero
/* 703F88 80238498 0C046F97 */  jal       set_background_color_blend
/* 703F8C 8023849C 304700FF */   andi     $a3, $v0, 0xff
/* 703F90 802384A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 703F94 802384A4 24020002 */  addiu     $v0, $zero, 2
/* 703F98 802384A8 03E00008 */  jr        $ra
/* 703F9C 802384AC 27BD0018 */   addiu    $sp, $sp, 0x18
