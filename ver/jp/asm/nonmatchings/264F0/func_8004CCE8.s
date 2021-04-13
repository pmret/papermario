.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CCE8
/* 280E8 8004CCE8 8CA20000 */  lw        $v0, ($a1)
/* 280EC 8004CCEC 90430000 */  lbu       $v1, ($v0)
/* 280F0 8004CCF0 24420001 */  addiu     $v0, $v0, 1
/* 280F4 8004CCF4 ACA20000 */  sw        $v0, ($a1)
/* 280F8 8004CCF8 03E00008 */  jr        $ra
/* 280FC 8004CCFC A0A30094 */   sb       $v1, 0x94($a1)
