.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242434
/* 9D9454 80242434 3C028025 */  lui       $v0, 0x8025
/* 9D9458 80242438 8C4249C8 */  lw        $v0, 0x49c8($v0)
/* 9D945C 8024243C 8C43000C */  lw        $v1, 0xc($v0)
/* 9D9460 80242440 24020002 */  addiu     $v0, $zero, 2
/* 9D9464 80242444 03E00008 */  jr        $ra
/* 9D9468 80242448 AC62001C */   sw       $v0, 0x1c($v1)
