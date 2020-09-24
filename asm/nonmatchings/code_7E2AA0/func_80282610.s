.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282610
/* 7E3490 80282610 24020002 */  addiu     $v0, $zero, 2
/* 7E3494 80282614 3C018015 */  lui       $at, 0x8015
/* 7E3498 80282618 AC221310 */  sw        $v0, 0x1310($at)
/* 7E349C 8028261C 03E00008 */  jr        $ra
/* 7E34A0 80282620 00000000 */   nop      
