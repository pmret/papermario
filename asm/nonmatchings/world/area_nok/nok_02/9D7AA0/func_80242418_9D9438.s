.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242418_9D9438
/* 9D9438 80242418 3C028025 */  lui       $v0, 0x8025
/* 9D943C 8024241C 8C4249C8 */  lw        $v0, 0x49c8($v0)
/* 9D9440 80242420 8C43000C */  lw        $v1, 0xc($v0)
/* 9D9444 80242424 24020001 */  addiu     $v0, $zero, 1
/* 9D9448 80242428 AC62001C */  sw        $v0, 0x1c($v1)
/* 9D944C 8024242C 03E00008 */  jr        $ra
/* 9D9450 80242430 24020002 */   addiu    $v0, $zero, 2
