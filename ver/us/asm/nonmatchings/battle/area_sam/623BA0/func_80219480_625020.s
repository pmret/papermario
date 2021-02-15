.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219480_625020
/* 625020 80219480 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 625024 80219484 AFBF0010 */  sw        $ra, 0x10($sp)
/* 625028 80219488 8C82000C */  lw        $v0, 0xc($a0)
/* 62502C 8021948C 0C0B1EAF */  jal       get_variable
/* 625030 80219490 8C450000 */   lw       $a1, ($v0)
/* 625034 80219494 0000202D */  daddu     $a0, $zero, $zero
/* 625038 80219498 0080282D */  daddu     $a1, $a0, $zero
/* 62503C 8021949C 0080302D */  daddu     $a2, $a0, $zero
/* 625040 802194A0 0C046F97 */  jal       set_background_color_blend
/* 625044 802194A4 304700FF */   andi     $a3, $v0, 0xff
/* 625048 802194A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 62504C 802194AC 24020002 */  addiu     $v0, $zero, 2
/* 625050 802194B0 03E00008 */  jr        $ra
/* 625054 802194B4 27BD0018 */   addiu    $sp, $sp, 0x18
