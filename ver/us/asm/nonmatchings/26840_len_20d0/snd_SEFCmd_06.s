.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_06
/* 28438 8004D038 8CA20000 */  lw        $v0, ($a1)
/* 2843C 8004D03C 90430000 */  lbu       $v1, ($v0)
/* 28440 8004D040 24420001 */  addiu     $v0, $v0, 1
/* 28444 8004D044 ACA20000 */  sw        $v0, ($a1)
/* 28448 8004D048 03E00008 */  jr        $ra
/* 2844C 8004D04C A0A30094 */   sb       $v1, 0x94($a1)
