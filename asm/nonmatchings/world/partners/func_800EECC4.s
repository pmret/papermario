.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EECC4
/* 88174 800EECC4 8C830000 */  lw        $v1, ($a0)
/* 88178 800EECC8 3C020001 */  lui       $v0, 1
/* 8817C 800EECCC AC820080 */  sw        $v0, 0x80($a0)
/* 88180 800EECD0 0000102D */  daddu     $v0, $zero, $zero
/* 88184 800EECD4 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 88188 800EECD8 A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 8818C 800EECDC 34630100 */  ori       $v1, $v1, 0x100
/* 88190 800EECE0 03E00008 */  jr        $ra
/* 88194 800EECE4 AC830000 */   sw       $v1, ($a0)
