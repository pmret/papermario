.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282314
/* 7E3194 80282314 8C820088 */  lw        $v0, 0x88($a0)
/* 7E3198 80282318 AC820074 */  sw        $v0, 0x74($a0)
/* 7E319C 8028231C 03E00008 */  jr        $ra
/* 7E31A0 80282320 24020002 */   addiu    $v0, $zero, 2
