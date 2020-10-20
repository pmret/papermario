.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF0_969FB0
/* 969FB0 80240DF0 3C028025 */  lui       $v0, 0x8025
/* 969FB4 80240DF4 8C42EFC8 */  lw        $v0, -0x1038($v0)
/* 969FB8 80240DF8 8C42000C */  lw        $v0, 0xc($v0)
/* 969FBC 80240DFC AC40001C */  sw        $zero, 0x1c($v0)
/* 969FC0 80240E00 03E00008 */  jr        $ra
/* 969FC4 80240E04 24020002 */   addiu    $v0, $zero, 2
