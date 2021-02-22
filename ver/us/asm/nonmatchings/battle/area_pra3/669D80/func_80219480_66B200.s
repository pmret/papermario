.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219480_66B200
/* 66B200 80219480 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66B204 80219484 AFBF0010 */  sw        $ra, 0x10($sp)
/* 66B208 80219488 8C82000C */  lw        $v0, 0xc($a0)
/* 66B20C 8021948C 0C0B1EAF */  jal       get_variable
/* 66B210 80219490 8C450000 */   lw       $a1, ($v0)
/* 66B214 80219494 0000202D */  daddu     $a0, $zero, $zero
/* 66B218 80219498 0080282D */  daddu     $a1, $a0, $zero
/* 66B21C 8021949C 0080302D */  daddu     $a2, $a0, $zero
/* 66B220 802194A0 0C046F97 */  jal       set_background_color_blend
/* 66B224 802194A4 304700FF */   andi     $a3, $v0, 0xff
/* 66B228 802194A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66B22C 802194AC 24020002 */  addiu     $v0, $zero, 2
/* 66B230 802194B0 03E00008 */  jr        $ra
/* 66B234 802194B4 27BD0018 */   addiu    $sp, $sp, 0x18
