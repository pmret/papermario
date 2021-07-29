.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CB54
/* 27F54 8004CB54 8CA20000 */  lw        $v0, ($a1)
/* 27F58 8004CB58 90430000 */  lbu       $v1, ($v0)
/* 27F5C 8004CB5C 24420001 */  addiu     $v0, $v0, 1
/* 27F60 8004CB60 ACA20000 */  sw        $v0, ($a1)
/* 27F64 8004CB64 24020001 */  addiu     $v0, $zero, 1
/* 27F68 8004CB68 A0A20056 */  sb        $v0, 0x56($a1)
/* 27F6C 8004CB6C 03E00008 */  jr        $ra
/* 27F70 8004CB70 A0A3009B */   sb       $v1, 0x9b($a1)
