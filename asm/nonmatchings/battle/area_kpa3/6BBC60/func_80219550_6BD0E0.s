.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219550_6BD0E0
/* 6BD0E0 80219550 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BD0E4 80219554 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6BD0E8 80219558 8C82000C */  lw        $v0, 0xc($a0)
/* 6BD0EC 8021955C 0C0B1EAF */  jal       get_variable
/* 6BD0F0 80219560 8C450000 */   lw       $a1, ($v0)
/* 6BD0F4 80219564 0000202D */  daddu     $a0, $zero, $zero
/* 6BD0F8 80219568 0080282D */  daddu     $a1, $a0, $zero
/* 6BD0FC 8021956C 0080302D */  daddu     $a2, $a0, $zero
/* 6BD100 80219570 0C046F97 */  jal       set_background_color_blend
/* 6BD104 80219574 304700FF */   andi     $a3, $v0, 0xff
/* 6BD108 80219578 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6BD10C 8021957C 24020002 */  addiu     $v0, $zero, 2
/* 6BD110 80219580 03E00008 */  jr        $ra
/* 6BD114 80219584 27BD0018 */   addiu    $sp, $sp, 0x18
