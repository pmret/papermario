.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CDC4
/* 281C4 8004CDC4 8CA20000 */  lw        $v0, ($a1)
/* 281C8 8004CDC8 90430000 */  lbu       $v1, ($v0)
/* 281CC 8004CDCC 24420001 */  addiu     $v0, $v0, 1
/* 281D0 8004CDD0 ACA20000 */  sw        $v0, ($a1)
/* 281D4 8004CDD4 ACA20088 */  sw        $v0, 0x88($a1)
/* 281D8 8004CDD8 03E00008 */  jr        $ra
/* 281DC 8004CDDC A0A3008C */   sb       $v1, 0x8c($a1)
