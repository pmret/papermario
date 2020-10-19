.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024036C_C9A56C
/* C9A56C 8024036C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9A570 80240370 0000202D */  daddu     $a0, $zero, $zero
/* C9A574 80240374 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9A578 80240378 0C015586 */  jal       func_80055618
/* C9A57C 8024037C 24050001 */   addiu    $a1, $zero, 1
/* C9A580 80240380 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9A584 80240384 24020002 */  addiu     $v0, $zero, 2
/* C9A588 80240388 03E00008 */  jr        $ra
/* C9A58C 8024038C 27BD0018 */   addiu    $sp, $sp, 0x18
